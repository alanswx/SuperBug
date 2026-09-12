// CPU, RAM, ROM and address decoder for Atari/Kee Games Super Bug 
// 2018 James Sweet
//
// This is free software: you can redistribute
// it and/or modify it under the terms of the GNU General
// Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your
// option) any later version.
//
// This is distributed in the hope that it will
// be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE. See the GNU General Public License
// for more details.

module cpu_mem(
    Clk6,
    Reset_n,
    VBlank,
    HBlank,
    VCount,
    HCount,
    RW_n,
    VMA,
    PHI2,
    StartLamp,
    TrakSelLamp,
    Attract,
    Flash,
    In1_n,
    Opt_n,
    PHP_Load_n,
    PVP_Load_n,
    CarRot_n,
    ArrowOff_n,
    SteerReset_n,
    CrashReset_n,
    SkidReset_n,
    MotorSnd_n,
    CrashSnd_n,
    SkidSnd_n,
    ASR_n,
    Adr,
    DBus_in,
    DBus_out,
    dbg_pc,
    dbg_opcode,
    dbg_addr,
    dbg_din,
    dbg_op_fetch,
    dbg_acca,
    dbg_accb,
    dbg_cc
);
    output [15:0] dbg_pc;
    output [7:0]  dbg_opcode;
    output [15:0] dbg_addr;
    output [7:0]  dbg_din;
    output        dbg_op_fetch;
    output [7:0]  dbg_acca;
    output [7:0]  dbg_accb;
    output [7:0]  dbg_cc;
    input         Clk6;
    input         Reset_n;
    input         VBlank;
    input         HBlank;
    input [7:0]   VCount;
    input [8:0]   HCount;
    output        RW_n;
    output        VMA;
    output reg    PHI2;
    output reg    StartLamp;
    output reg    TrakSelLamp;
    output reg    Attract;
    output reg    Flash;
    output        In1_n;
    output        Opt_n;
    output        PHP_Load_n;
    output        PVP_Load_n;
    output        CarRot_n;
    output        ArrowOff_n;
    output        SteerReset_n;
    output        CrashReset_n;
    output        SkidReset_n;
    output        MotorSnd_n;
    output        CrashSnd_n;
    output        SkidSnd_n;
    output        ASR_n;       // extended-play tone strobe ($0220)
    output [15:0] Adr;
    input [7:0]   DBus_in;
    output [7:0]  DBus_out;
    
    
    wire          Reset;
    
    wire          H2;
    wire          V16;
    
    wire          Phi1;
    wire          Legit;
    
    wire [7:0]    CPU_Din;
    wire [7:0]    CPU_Dout;
    
    wire [7:0]    RAM_Dout;
    wire          RAMce;
    wire          RAMwe;
    
    wire [7:0]    ROM1_Dout;
    wire [7:0]    ROM2_Dout;
    wire [7:0]    ROM3_Dout;
    wire [7:0]    ROM_Dout;
    
    wire          ROM1ce_n;
    wire          ROM2ce_n;
    wire          ROM3ce_n;
    
    wire          R_nW;
    reg           IRQ_n;
    wire          NMI_n;
    wire          BVMA;
    
    wire          BA12nor11;
    wire          SysEn;
    
    wire          WdogReset_n;
    //signal CrashReset_n	: std_logic;
    //signal SkidReset_n	: std_logic;
    
    wire          rw;
    
    wire          IO_Wr;
    wire          Out2_n;
    
    wire          nmi;
    wire          irq;
    
    // Watchdog. MAME configures this as `set_vblank_count("screen", 5)`: the
    // board resets if the program goes five vertical blanks without writing
    // the kick address. The decode for that write existed already but its
    // output went nowhere, so a boot that stalled would hang instead of
    // retrying the way real hardware does.
    // Firing has to be a pulse, not a level: holding reset would also stop the
    // program from ever reaching the kick instruction, so the board would
    // never come back.
    reg [2:0] wdog_count;
    reg [7:0] wdog_hold;
    reg       prev_VBlank_wdog;
    wire      wdog_reset = (wdog_hold != 8'd0);
    always @(posedge Clk6) begin: Watchdog
        prev_VBlank_wdog <= VBlank;
        if (Reset_n == 1'b0 || WdogReset_n == 1'b0) begin
            wdog_count <= 3'd0;
            wdog_hold  <= 8'd0;
        end else if (VBlank & ~prev_VBlank_wdog) begin
            if (wdog_count >= 3'd4) begin
                wdog_count <= 3'd0;
                wdog_hold  <= 8'hFF;
            end else begin
                wdog_count <= wdog_count + 3'd1;
            end
        end else if (wdog_hold != 8'd0) begin
            wdog_hold <= wdog_hold - 8'd1;
        end
    end

    assign Reset = ((~Reset_n)) | wdog_reset;
    
    assign H2 = HCount[1];
    assign V16 = VCount[4];
    
    // Clock
    // This is a bit ugly, should rewrite
    
    // Processor clock. The VHDL this came from toggled on the rising edge of
    // 2H, which is one eighth of the pixel clock, or 756 kHz, and carried the
    // comment "this is a bit ugly, should rewrite". The board runs the
    // processor at a twelfth of the master clock, 1.008 MHz, which is a sixth
    // of the pixel clock; 756 kHz is the slower rate the service switch
    // selects. Running a third slow left the program short of cycles per
    // frame and its state drifted away from the reference over a few hundred
    // frames.
    reg [1:0] phi_div;
    always @(posedge Clk6)
    begin: Clock
        if (Reset == 1'b1) begin
            phi_div <= 2'd0;
            PHI2    <= 1'b0;
        end else if (phi_div == 2'd2) begin
            phi_div <= 2'd0;
            PHI2    <= ((~PHI2));
        end else begin
            phi_div <= phi_div + 2'd1;
        end
    end
    assign Phi1 = ((~PHI2));
    assign Legit = (~(H2 | Phi1));
    
    // IRQ
   
    // 7474 D-FF: D tied to '0' (so it can only be set to 0), CLK = V16
    // falling edge, async clear (preset) when HBlank=0 sets IRQ_n=1.
    // Original Verilog used "negedge V16 or negedge HBlank" which fires
    // multiple times per scanline in Verilator's event scheduler; rewrite
    // as a clock-enable on the Clk6 domain that drives this block.
    reg prev_V16;
    always @(posedge Clk6) begin
        prev_V16 <= V16;
    end
    wire ce_V16_fall = ~V16 & prev_V16;
    always @(posedge Clk6) begin: IRQ_DFF
        if (HBlank == 1'b0)        IRQ_n <= 1'b1;     // level-sensitive preset
        else if (ce_V16_fall)      IRQ_n <= 1'b0;     // V16 falling edge -> assert
    end
    

    // VBlank is held wide (vcount 240..255) so the playfield-RAM mux
    // routes the CPU bus during the full retrace. For NMI we use only the
    // first scanline of VBlank as a level, so cpu68 sees a clean
    // rise/fall per frame and won't queue a nested NMI when its handler
    // takes longer than one VBlank-wide window.
    assign NMI_n = ~(VBlank & VCount[3:0] == 4'd0);
    
    // Watchdog
    
`ifdef SIMULATION
    // Sim-only: count interrupt assertions so the rate can be compared with
    // the reference. A game that runs fast usually means too many of these.
    reg [15:0] irq_count, nmi_count;
    reg prev_irq_n, prev_nmi_n;
    always @(posedge Clk6) begin
        prev_irq_n <= IRQ_n;
        prev_nmi_n <= NMI_n;
        if (prev_irq_n & ~IRQ_n) irq_count <= irq_count + 16'd1;
        if (prev_nmi_n & ~NMI_n) nmi_count <= nmi_count + 16'd1;
    end
`endif

    assign irq = (~IRQ_n);
    assign nmi = (~NMI_n);
    
    
    cpu68 CPU(
        .clk(PHI2),		// E clock input (falling edge)
        .rst(Reset),		// reset input (active high)
        //rw => R_nW,					-- Write active high AJS
        .rw(rw),		//R_nW,					-- Write active high
        .vma(VMA),		// valid memory address (active high)
        .address(Adr),
        .data_in(CPU_Din),
        .data_out(CPU_Dout),
        .hold(1'b0),		// hold input (active high) extend bus cycle
        .halt(1'b0),		// halt input (active high) grants DMA
        .irq(irq),		// interrupt request input (active high)
        .nmi(nmi),		// non maskable interrupt request input (active high)
        .dbg_pc(dbg_pc),
        .dbg_opcode(dbg_opcode),
        .dbg_addr(dbg_addr),
        .dbg_din(dbg_din),
        .dbg_op_fetch(dbg_op_fetch),
        .dbg_acca(dbg_acca),
        .dbg_accb(dbg_accb),
        .dbg_cc(dbg_cc)
    );
    
    assign DBus_out = CPU_Dout;		// when phi2 = '0' else (others => '1');	-- added phi2 
    
    assign R_nW = (~rw);
    assign RW_n = rw;
    //RW_n <= (not R_nW);		
    
    //CPU RAM
    
    ram256 M1(
        .clock(Clk6),
        .address(Adr[7:0]),
        .wren(RAMwe),
        .data(CPU_Dout[3:0]),
        .q(RAM_Dout[3:0])
    );
    
    
    ram256 N1(
        .clock(Clk6),
        .address(Adr[7:0]),
        .wren(RAMwe),
        .data(CPU_Dout[7:4]),
        .q(RAM_Dout[7:4])
    );
    
    // Program ROM
    
    ROM_D1 D1(
        .clock(Clk6),
        .address(Adr[10:0]),
        .q(ROM1_Dout)
    );
    
    
    ROM_C1 C1(
        .clock(Clk6),
        .address(Adr[10:0]),
        .q(ROM2_Dout)
    );
    
    
    ROM_A1 A1(
        .clock(Clk6),
        .address(Adr[10:0]),
        .q(ROM3_Dout)
    );
    
    // Program ROM mux
    assign ROM_Dout = (ROM1ce_n == 1'b0) ? ROM1_Dout : 
                      (ROM2ce_n == 1'b0) ? ROM2_Dout : 
                      (ROM3ce_n == 1'b0) ? ROM3_Dout : 
                      8'hFF;
    
    // Address decoding
    
    assign ROM1ce_n = (BVMA == 1'b1 & Adr[12:11] == 2'b01) ? 1'b0 : 
                      1'b1;
    assign ROM2ce_n = (BVMA == 1'b1 & Adr[12:11] == 2'b10) ? 1'b0 : 
                      1'b1;
    assign ROM3ce_n = (BVMA == 1'b1 & Adr[12:11] == 2'b11) ? 1'b0 : 
                      1'b1;
    
    //	000 010 0000000000
    //		 011
    // 000 111 1111111111
    
    //ROM1ce_n <= '0' when VMA = '1' and Adr(12 downto 10) = "001" else '1';
    //ROM2ce_n <= '0' when VMA = '1' and Adr(12 downto 10) = "010" else '1';
    //ROM3ce_n <= '0' when VMA = '1' and Adr(12 downto 10) = "111" else '1';
    
    assign BVMA = VMA;		// and (not Adr(14));
    assign BA12nor11 = ~(Adr[12] | Adr[11]);
    assign SysEn = (BVMA & BA12nor11 & PHI2);
    assign RAMce = (Adr[11:8] == 4'b0000) ? 1'b1 : 
                   1'b0;
    //RAMce <= '1' when SysEn = '1' and Adr(11 downto 8) = "0000" else '0';
    //RAMwe <= '1' when RAMce = '1' and RW_n = '0' else '0';  -- AJS
    assign RAMwe = (RAMce == 1'b1 & RW_n == 1'b0) ? 1'b1 : 
                   1'b0;
    
    //J4_11
    assign IO_Wr = (SysEn & Legit & ((~RW_n)));
    //IO_Wr <= SysEn and Legit and R_nW ;
    
    // Memory map from MAME driver
    // FEDCBA9876543210           
    //	0000000000000000 - 0000000011111111	(0x0000, 0x00ff) AM_RAM
    //	0000000100000000							(0x0100, 0x0100) AM_MIRROR(0x001f) AM_WRITEONLY AM_SHARE("scroll_y")
    //	0000000100100000							(0x0120, 0x0120) AM_MIRROR(0x001f) AM_WRITEONLY AM_SHARE("scroll_x")
    //	0000000101000000							(0x0140, 0x0140) AM_MIRROR(0x001f) AM_WRITE(crash_reset_w)
    //	0000000101100000							(0x0160, 0x0160) AM_MIRROR(0x001f) AM_WRITE(firetrk_skid_reset_w)
    //	0000000110000000							(0x0180, 0x0180) AM_MIRROR(0x001f) AM_WRITEONLY AM_SHARE("car_rot")
    //	0000000110100000 							(0x01a0, 0x01a0) AM_MIRROR(0x001f) AM_WRITE(steer_reset_w)
    //	0000000111000000							(0x01c0, 0x01c0) AM_MIRROR(0x001f) AM_DEVWRITE("watchdog", watchdog_timer_device, reset_w)
    //	0000000111100000							(0x01e0, 0x01e0) AM_MIRROR(0x001f) AM_WRITE(blink_on_w) AM_SHARE("blink")
    //	0000001000000000 - 0000001000000111 (0x0200, 0x0207) AM_MIRROR(0x0018) AM_READ(firetrk_input_r)
    //	0000001000100000							(0x0220, 0x0220) AM_MIRROR(0x001f) AM_WRITE(firetrk_xtndply_w)
    //	0000001001000000 - 0000001001000011 (0x0240, 0x0243) AM_MIRROR(0x001c) AM_READ(firetrk_dip_r)
    //	0000001001100000 - 0000001001101111 (0x0260, 0x026f) AM_MIRROR(0x0010) AM_WRITE(superbug_output_w)
    //	0000001010000000 							(0x0280, 0x0280) AM_MIRROR(0x001f) AM_WRITE(superbug_motor_snd_w)
    //	0000001010100000							(0x02a0, 0x02a0) AM_MIRROR(0x001f) AM_WRITE(firetrk_crash_snd_w)
    //	0000001011000000							(0x02c0, 0x02c0) AM_MIRROR(0x001f) AM_WRITE(firetrk_skid_snd_w)
    //	0000010000000000 - 0000010000011111 (0x0400, 0x041f) AM_RAM AM_SHARE("alpha_num_ram")
    //	0000010100000000 - 0000010111111111 (0x0500, 0x05ff) AM_RAM AM_SHARE("playfield_ram")
    //	0000100000000000 - 0001111111111111 (0x0800, 0x1fff) AM_ROM
    //
    
    //	000 010 0000000000
    //		 011
    // 000 111 1111111111
    
    // Outputs
    assign MotorSnd_n = (IO_Wr == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b100) ? 1'b0 : 
                        1'b1;
    assign CrashSnd_n = (IO_Wr == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b101) ? 1'b0 : 
                        1'b1;
    assign SkidSnd_n = (IO_Wr == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b110) ? 1'b0 : 
                       1'b1;
    
    // Per MAME's superbug memory map (firetrk.cpp:998 — `scroll_y` at $0100,
    // `scroll_x` at $0120) the CPU writes vertical scroll to $0100 and
    // horizontal scroll to $0120. Our PVP is the V (per-scanline) counter
    // and PHP is the H (per-pixel) counter, so $0100 must load PVP and
    // $0120 must load PHP. The original mapping had them reversed, which
    // sent scroll_y into the H counter — visible at boot as a missing
    // left-half playfield (the H scroll was effectively scroll_y, putting
    // the populated tilemap rows out of the visible window's H span).
    assign PVP_Load_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b000) ? 1'b0 :
                        1'b1;
    assign PHP_Load_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b001) ? 1'b0 :
                        1'b1;

    // Debug-only: latch the most recent scroll_x / scroll_y the CPU
    // wrote so the harness can compare directly with MAME's stored
    // m_scroll_x/m_scroll_y at any frame. Hardware doesn't keep these —
    // PHP_Load/PVP_Load are write strobes only — so this is purely an
    // observation point and has no functional effect.
    reg [7:0] scroll_x_dbg;
    reg [7:0] scroll_y_dbg;
    // Counts of how many times each strobe has fired since reset.
    // Helps tell the difference between "CPU wrote once at boot" and
    // "CPU writes every frame" — both produce the same latched value
    // when the value never changes (e.g. scroll_y = $08 forever).
    reg [15:0] scroll_x_writes;
    reg [15:0] scroll_y_writes;
    reg PHP_Load_n_prev, PVP_Load_n_prev;
    always @(posedge Clk6) begin
        PHP_Load_n_prev <= PHP_Load_n;
        PVP_Load_n_prev <= PVP_Load_n;
        if (~PHP_Load_n) scroll_x_dbg <= CPU_Dout;
        if (~PVP_Load_n) scroll_y_dbg <= CPU_Dout;
        if (PHP_Load_n_prev && ~PHP_Load_n) scroll_x_writes <= scroll_x_writes + 1;
        if (PVP_Load_n_prev && ~PVP_Load_n) scroll_y_writes <= scroll_y_writes + 1;
    end
    assign CrashReset_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b010) ? 1'b0 : 
                          1'b1;
    assign SkidReset_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b011) ? 1'b0 : 
                         1'b1;
    assign CarRot_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b100) ? 1'b0 : 
                      1'b1;
    assign SteerReset_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b101) ? 1'b0 : 
                          1'b1;
    assign WdogReset_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b110) ? 1'b0 : 
                         1'b1;
    assign ArrowOff_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b111) ? 1'b0 : 
                        1'b1;
    
    // Note: SysEn is gated by PHI2 in the original, which is correct for
    // write-strobe generation but causes a one-event-cycle race in Verilator
    // when the CPU samples data_in on negedge PHI2 (mux returns FF before
    // the CPU latches the I/O byte). Use BVMA & BA12nor11 (= SysEn ungated)
    // for the read-side decoders. Writes still use SysEn for IO_Wr.
    wire SysEn_rd = BVMA & BA12nor11;
    assign In1_n = (SysEn_rd == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b000) ? 1'b0 :
                   1'b1;
    assign Opt_n = (SysEn_rd == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b010) ? 1'b0 :
                   1'b1;
    assign Out2_n = (SysEn == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b011) ? 1'b0 : 
                    1'b1;
    // ASR — the extended-play tone strobe at $0220 (MAME: xtndply_w). This
    // had no decode at all, so the tone could never be triggered.
    assign ASR_n = (IO_Wr == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b001) ? 1'b0 :
                   1'b1;
    
    
    always @(posedge Out2_n)
    begin: OutputLatch
        begin
            StartLamp <= Adr[0];
            TrakSelLamp <= Adr[3];
            Attract <= Adr[1];
            Flash <= Adr[2];
        end
    end
    
    // 74LS175 at C9
    //OutputLatch: process(Adr, Out2_n)
    //begin
    //       if (Reset='1') then
    //		StartLamp <= '0';
    //		TrakSelLamp <= '0';
    //		Attract <= '0';
    //		Flash <= '0';
    //        end if;
    //	if rising_edge(Out2_n) then
    //		StartLamp <= Adr(0);
    //		TrakSelLamp <= Adr(3);
    //		Attract <= Adr(1);
    //		Flash <= Adr(2);
    //	end if;
    //end process;
    
    // CPU data in mux
    assign CPU_Din = (ROM1ce_n == 1'b0 | ROM2ce_n == 1'b0 | ROM3ce_n == 1'b0) ? ROM_Dout : 
                     (RAMce == 1'b1 & RW_n == 1'b1) ? RAM_Dout : 
                     (In1_n == 1'b0 | Opt_n == 1'b0) ? DBus_in : 
                     8'hFF;
    
endmodule
