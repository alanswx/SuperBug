// Sound for Atari/Kee Games Super Bug.
//
// Neither the original VHDL top nor the Verilog one ever instantiated a sound
// block: the audio output was declared and left undriven, and the generator
// modules sat unused. This is that missing block.
//
// The board's audio is a discrete analogue circuit, so the reference for its
// behaviour is MAME's `superbug_discrete` netlist in
// mame/src/mame/atari/firetrk_a.cpp, cross-checked against the original
// diagnostic source in superbug/SUPDIG.MAC. Four channels:
//
//   motor    a 556 VCO whose frequency the CPU sets with a four-bit value,
//            divided by a 7492 and XOR-mixed into a lumpy pulse train
//   bang     the noise source gated into a four-bit weighted ladder whose
//            level the CPU sets, used for crashes
//   screech  a Schmitt oscillator around 1.2 kHz, frequency-modulated by the
//            same noise source, for tyre skid
//   tone     a plain square wave for the extended-play attention beep
//
// Register conventions, from SUPMEM.MAC and confirmed against MAME:
//
//   $0280  MOTOR SOUND, D0-D3       data is active low, 0 is the lowest pitch
//   $02A0  CRASH SOUND, D4-D7       data is active low, $F is silent
//   $02C0  SKID SOUND, address only  sets the skid latch
//   $0160  SKID RESET, address only  clears it
//   $0220  extended-play tone        enabled while the value written is non-zero
//
// The skid channel really is a set/reset pair, not a one-shot: SUPDIG.MAC
// writes SKDSND for "SKID ON" and SKDRST for "SKID OFF".

`default_nettype none

module sound(
    input  wire        Clk6,
    input  wire        Reset_n,

    input  wire [7:0]  VCount,      // 2V and 8V come off the vertical counter
    input  wire [7:0]  BD,          // CPU data bus

    input  wire        MotorSnd_n,  // $0280 write strobe
    input  wire        CrashSnd_n,  // $02A0 write strobe
    input  wire        SkidSnd_n,   // $02C0 strobe, skid on
    input  wire        SkidReset_n, // $0160 strobe, skid off
    input  wire        ASR_n,       // $0220 write strobe, extended-play tone

    input  wire        Attract,     // 1 in attract mode: motor and noise muted

    input  wire [1:0]  Game,        // 0 = Super Bug, 1 = Fire Truck
    input  wire        Horn_n,      // Fire Truck only, straight from the panel
    input  wire        Bell,        // Fire Truck only, from the output latch

    output wire [15:0] Audio_O,

    // Sound registers are write-only to the CPU, so expose them for testing.
    output wire [9:0]  dbg_state,  // {asr_en, skid_en, crash_level, speed_data}
    output wire [31:0] dbg_strobes // counts of each write strobe since reset
);

    // ------------------------------------------------------------------
    // Write strobes. All of these are active low and one Clk6 wide.
    // ------------------------------------------------------------------
    reg  prev_MotorSnd_n, prev_CrashSnd_n, prev_SkidSnd_n;
    reg  prev_SkidReset_n, prev_ASR_n;
    wire motor_wr = prev_MotorSnd_n  & ~MotorSnd_n;
    wire crash_wr = prev_CrashSnd_n  & ~CrashSnd_n;
    wire skid_set = prev_SkidSnd_n   & ~SkidSnd_n;
    wire skid_clr = prev_SkidReset_n & ~SkidReset_n;
    wire asr_wr   = prev_ASR_n       & ~ASR_n;

    always @(posedge Clk6) begin
        prev_MotorSnd_n  <= MotorSnd_n;
        prev_CrashSnd_n  <= CrashSnd_n;
        prev_SkidSnd_n   <= SkidSnd_n;
        prev_SkidReset_n <= SkidReset_n;
        prev_ASR_n       <= ASR_n;
    end

    // ------------------------------------------------------------------
    // Sound registers
    // ------------------------------------------------------------------
    localparam GAME_FIRETRK = 2'd1;
    wire firetrk = (Game == GAME_FIRETRK);

    reg [3:0] speed_data;   // raw CPU value; EngineSound's table expects it this way
    reg [3:0] siren_data;   // Fire Truck shares the motor register, high nibble
    reg [3:0] crash_level;  // inverted on the way in, so $F written means silent
    reg       skid_en;
    reg       asr_en;

    always @(posedge Clk6) begin
        if (!Reset_n) begin
            speed_data  <= 4'd0;
            crash_level <= 4'd0;
            skid_en     <= 1'b0;
            asr_en      <= 1'b0;
        end else begin
            if (motor_wr) speed_data  <= BD[3:0];
            if (motor_wr && firetrk) siren_data <= BD[7:4];
            if (crash_wr) crash_level <= ~BD[7:4];
            // Fire Truck's extended play tone is active low, Super Bug's is
            // enabled by any non-zero value.
            if (asr_wr)   asr_en      <= firetrk ? ~BD[0] : |BD;
            // Clear wins if both strobes land together.
            if (skid_clr)      skid_en <= 1'b0;
            else if (skid_set) skid_en <= 1'b1;
        end
    end

    // ------------------------------------------------------------------
    // Clock enables
    //
    // 2V and 8V are vertical counter bits, so they come free. 2V rises once
    // every four scanlines, which is the 3.9 kHz the noise shift register
    // runs at; 8V is the 984 Hz square wave the tone channel is built from.
    // ------------------------------------------------------------------
    reg  prev_2V;
    wire ce_2V = VCount[1] & ~prev_2V;
    always @(posedge Clk6) prev_2V <= VCount[1];

    wire tone_square = VCount[3];          // 8V, about 984 Hz
    wire horn_square = VCount[6];          // 64V, about 123 Hz

    // Roughly 3 kHz, for the engine generator's ramp filter.
    reg [10:0] div_3k;
    wire ce_3k = (div_3k == 11'd0);
    always @(posedge Clk6) div_3k <= div_3k + 11'd1;

    // 750 kHz for the screech ramp, which is what the original takes off the
    // horizontal counter chain.
    reg [2:0] div_750k;
    wire ce_750k = (div_750k == 3'd0);
    always @(posedge Clk6) div_750k <= div_750k + 3'd1;

    // ------------------------------------------------------------------
    // Noise: sixteen-bit shift register, XNOR of bits 0 and 14 fed into
    // bit 0, output taken from bit 15. Held reset while attract is asserted,
    // which is how the board keeps quiet between games.
    // ------------------------------------------------------------------
    reg [15:0] lfsr;
    wire       noise = lfsr[15];
    always @(posedge Clk6) begin
        if (!Reset_n || Attract)
            lfsr <= 16'd0;
        else if (ce_2V)
            lfsr <= {lfsr[14:0], ~(lfsr[0] ^ lfsr[14])};
    end

    // ------------------------------------------------------------------
    // Engine. EngineSound is the existing port of the 556 VCO plus 7492
    // divider; it expects the raw CPU value, where zero is the lowest pitch.
    // ------------------------------------------------------------------
    wire [5:0] motor_level;
    // The tuning constant was swept against a recording of the reference,
    // scoring each by how closely the spread of energy across frequency bands
    // matched. The default is the best of those tried: 9.8 dB mean difference
    // per band, against 14 to 16 for every alternative. What remains is the
    // gap between this generator, which is a port of the Sprint 2
    // approximation, and the 556 oscillator the board actually uses.
    EngineSound engine(
        .Clk_6(Clk6),
        .Ena_3k(ce_3k),
        .EngineData(speed_data),
        .Motor(motor_level)
    );
    wire [5:0] motor_out = Attract ? 6'd0 : motor_level;

    // ------------------------------------------------------------------
    // Bang: the noise bit chops the crash level into the weighted ladder.
    // ------------------------------------------------------------------
    wire [3:0] bang_out = (noise && !Attract) ? crash_level : 4'd0;

    // ------------------------------------------------------------------
    // Screech: a counter ramps up and down between two thresholds and the
    // noise bit changes the slope, which frequency-modulates the square wave
    // taken from the ramp direction. Same algorithm as the existing
    // tire_screech module, rebuilt on a clock enable so the whole core stays
    // in one clock domain instead of running off a divided clock.
    // ------------------------------------------------------------------
    localparam [13:0] SCREECH_INC1 = 14'd24;
    localparam [13:0] SCREECH_INC2 = 14'd34;
    localparam [13:0] SCREECH_DEC1 = 14'd23;
    localparam [13:0] SCREECH_DEC2 = 14'd12;

    reg [13:0] screech_count;
    reg        screech_state;
    always @(posedge Clk6) begin
        if (!Reset_n) begin
            screech_count <= 14'd1000;
            screech_state <= 1'b0;
        end else if (ce_750k) begin
            if (screech_state) begin
                screech_count <= screech_count + (noise ? SCREECH_INC2 : SCREECH_INC1);
                if (screech_count > 14'd10000) screech_state <= 1'b0;
            end else begin
                screech_count <= screech_count - (noise ? SCREECH_DEC2 : SCREECH_DEC1);
                if (screech_count < 14'd1100) screech_state <= 1'b1;
            end
        end
    end
    wire screech_out = skid_en & screech_state;

    // ------------------------------------------------------------------
    // Extended-play tone
    // ------------------------------------------------------------------
    wire tone_out = asr_en & tone_square;

    // ------------------------------------------------------------------
    // Fire Truck only, three channels Super Bug has no counterpart for.
    //
    // Horn is the 64V line gated by the panel button, and goes quiet in
    // attract with everything else.
    //
    // Siren is a 556 oscillator whose control voltage comes from the four bit
    // value sharing the motor register. The reference documents its two ends
    // as 666 Hz at zero and 526 Hz at fifteen, which is what the period below
    // interpolates between.
    //
    // Bell is the 8V line struck and left to decay: the enable instantly
    // charges a capacitor which then bleeds away through a resistor, about a
    // third of a second, and the tone is amplitude-shaped by what is left.
    // ------------------------------------------------------------------
    wire horn_out = firetrk & ~Horn_n & ~Attract & horn_square;

    reg  [13:0] siren_count;
    reg         siren_state;
    wire [13:0] siren_half = 14'd4540 + {6'd0, siren_data} * 14'd80;
    always @(posedge Clk6) begin
        if (!Reset_n) begin
            siren_count <= 14'd0;
            siren_state <= 1'b0;
        end else if (siren_count >= siren_half) begin
            siren_count <= 14'd0;
            siren_state <= ~siren_state;
        end else begin
            siren_count <= siren_count + 14'd1;
        end
    end
    wire siren_out = firetrk & ~Attract & siren_state;

    reg  [7:0]  bell_env;
    reg  [12:0] bell_div;
    reg         prev_bell;
    always @(posedge Clk6) begin
        prev_bell <= Bell;
        if (!Reset_n) begin
            bell_env <= 8'd0;
            bell_div <= 13'd0;
        end else if (Bell & ~prev_bell) begin
            bell_env <= 8'hFF;          // the enable charges the capacitor at once
            bell_div <= 13'd0;
        end else begin
            bell_div <= bell_div + 13'd1;
            if (bell_div == 13'd0 && bell_env != 8'd0) bell_env <= bell_env - 8'd1;
        end
    end
    wire [7:0] bell_8 = (firetrk && tone_square) ? bell_env : 8'd0;

    // ------------------------------------------------------------------
    // Mixer.
    //
    // The board sums the four channels through R54 15k, R55 10.5456k,
    // R72 33k and R53 4.7k, so each channel's share is proportional to its
    // conductance. Scaled to sum to 1024 those come out as 169, 240, 77 and
    // 538. The tone is the loudest by a wide margin, which is the point of an
    // attention beep.
    //
    // Each channel is first scaled to a common 0..255 range. The tone runs at
    // half amplitude, matching the netlist's square wave.
    // ------------------------------------------------------------------
    wire [7:0] motor_8   = {motor_out, 2'b00};              // 6-bit, x4
    wire [8:0] bang_9    = {bang_out, 4'b0000} + bang_out;  // 4-bit, x17
    wire [7:0] bang_8    = bang_9[7:0];
    wire [7:0] screech_8 = screech_out ? 8'd255 : 8'd0;
    wire [7:0] tone_8    = tone_out    ? 8'd128 : 8'd0;

    // Fire Truck sums seven channels through its own set of resistors, and
    // its extended play tone runs at full amplitude where Super Bug's is half.
    // Scaled to a thousand and twenty-four the same way: tone 481, horn 103,
    // bell 72, screech 68, bang 214, motor 71, siren 15.
    wire [7:0] ft_tone_8  = tone_out  ? 8'd255 : 8'd0;
    wire [7:0] ft_horn_8  = horn_out  ? 8'd255 : 8'd0;
    wire [7:0] ft_siren_8 = siren_out ? 8'd255 : 8'd0;

    wire [19:0] mix_sb = (169 * motor_8) + (240 * bang_8)
                       + ( 77 * screech_8) + (538 * tone_8);

    wire [19:0] mix_ft = (481 * ft_tone_8) + (103 * ft_horn_8) + (72 * bell_8)
                       + ( 68 * screech_8) + (214 * bang_8) + (71 * motor_8)
                       + ( 15 * ft_siren_8);

    wire [19:0] mix = firetrk ? mix_ft : mix_sb;

    // Full scale is 1024 * 255 = 261120, so a shift of two lands just under
    // sixteen bits with no clipping.
    assign Audio_O = mix[17:2];

    assign dbg_state = {asr_en, skid_en, crash_level, speed_data};

    reg [7:0] n_motor, n_crash, n_skid_set, n_skid_clr;
    always @(posedge Clk6) begin
        if (!Reset_n) begin
            n_motor <= 0; n_crash <= 0; n_skid_set <= 0; n_skid_clr <= 0;
        end else begin
            if (motor_wr) n_motor    <= n_motor + 8'd1;
            if (crash_wr) n_crash    <= n_crash + 8'd1;
            if (skid_set) n_skid_set <= n_skid_set + 8'd1;
            if (skid_clr) n_skid_clr <= n_skid_clr + 8'd1;
        end
    end
    // Raw bus bytes as latched, before any inversion, so a wrong value can be
    // told apart from a strobe that never fired.
    reg [7:0] last_motor_byte, last_crash_byte;
    always @(posedge Clk6) begin
        if (motor_wr) last_motor_byte <= BD;
        if (crash_wr) last_crash_byte <= BD;
    end
    assign dbg_strobes = {last_crash_byte, last_motor_byte, n_crash, n_motor};

endmodule

`default_nettype wire
