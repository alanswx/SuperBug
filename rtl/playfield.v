// Playfield generator for Atari/Kee Games Super Bug 
// This generates the scrolling track
// (c) 2018 James Sweet
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

module playfield(
    Clk6,
    RW_n,
    BD,
    BA,
    HCount,
    Sys_En,
    HSync,
    HBlank,
    VBlank,
    ArrowOff_n,
    CarVideo,
    PVP_Load_n,
    PHP_Load_n,
    Crash_n,
    Skid_n,
    CrashIn_n,
    SkidIn_n,
    CrashReset_n,
    SkidReset_n,
    PfWndo,
    PCC1,
    PCC2,
    Pfld
);
    input        Clk6;
    input        RW_n;
    input [7:0]  BD;
    input [15:0] BA;
    input [8:0]  HCount;
    input        Sys_En;
    input        HSync;
    input        HBlank;
    input        VBlank;
    input        ArrowOff_n;
    input        CarVideo;
    input        PVP_Load_n;
    input        PHP_Load_n;
    output       Crash_n;
    output       Skid_n;
    output       CrashIn_n;
    output       SkidIn_n;
    input        CrashReset_n;
    input        SkidReset_n;
    output reg   PfWndo;
    output       PCC1;
    output       PCC2;
    output       Pfld;
    
    
    wire         H1;
    wire         H2;
    wire         H4;
    wire         H8;
    wire         H16;
    wire         H32;
    wire         H64;
    wire         H128;
    wire         H256;
    
    //signal V1					: std_logic;
    //signal V2					: std_logic;
    //signal V4					: std_logic;
    //signal V8					: std_logic;
    //signal V16					: std_logic;
    //signal V32					: std_logic;
    //signal V64					: std_logic;
    //signal V128					: std_logic;
    
    wire [9:0]   PFROM_Adr;
    wire [3:0]   E5_Dout;
    wire [3:0]   F5_Dout;
    wire [3:0]   H5_Dout;
    reg [3:0]    Vid;
    
    wire [7:0]   PD;
    reg [7:0]    PVP;
    reg [7:0]    PHP;
    
    wire [7:0]   PF_RAM_Adr;
    wire [7:0]   PFRAM_Din;
    wire         PF_Wren;
    wire         PF_RAMce_n;
    wire         PfldRAM;
    
    wire         BD_en;
    wire         PD_en;
    wire         RnW;
    
    wire         CrashCode;
    wire         SkidCode_n;
    wire         CrashSkid;
    wire         CrashArrow;
    wire         PfCarVid;
    
    reg          Arrow_n;
    
    reg [3:0]    VidShift;
    wire         LoadPd;
    
    reg          PfWndo_n;
    wire         Window_en;
    wire         Pf;
    
    assign H1 = HCount[0];
    assign H2 = HCount[1];
    assign H4 = HCount[2];
    assign H8 = HCount[3];
    assign H16 = HCount[4];
    assign H32 = HCount[5];
    assign H64 = HCount[6];
    assign H128 = HCount[7];
    assign H256 = HCount[8];
    
    //V1 <= VCount(0);
    //V2 <= VCount(1);
    //V4 <= VCount(2);
    //V8 <= VCount(3);
    //V16 <= VCount(4);
    //V32 <= VCount(5);
    //V64 <= VCount(6);
    //V128 <= VCount(7);
    
    assign RnW = ((~RW_n));
    
    assign PFROM_Adr = {PD[3:0], PVP[3:0], PHP[3:2]};
    
    // Playfield ROM
    
    ROM_E5 E5(
        .clock(Clk6),
        .address(PFROM_Adr),
        .q(E5_Dout)
    );
    
    
    ROM_F5 F5(
        .clock(Clk6),
        .address(PFROM_Adr),
        .q(F5_Dout)
    );
    
    
    ROM_H5 H5(
        .clock(Clk6),
        .address(PFROM_Adr),
        .q(H5_Dout)
    );
    
    // CE lines are labeled strangely on schematic — original VHDL was
    // uncertain about the mapping. Per MAME's ROM region layout for the
    // `tiles` set (F5 at $000, H5 at $400, E5 at $800, E5-reload at $C00),
    // the natural mapping for PD[5:4] is 00->F5, 01->H5, 10->E5, 11->E5.
    // Original VHDL had 01->E5 and 10->H5 (swapped), which made the
    // playfield render the wrong tiles for half the codes.
    always @(*)
    begin: PF_ROM_mux
        Vid <= {4{1'b0}};
        case (PD[5:4])
            2'b00 : Vid <= F5_Dout;
            2'b01 : Vid <= H5_Dout;
            2'b10 : Vid <= E5_Dout;
            2'b11 : Vid <= E5_Dout;
            default : ;
        endcase
    end
    
    //Playfield RAM
    
    // E6/F6: original VHDL had E6 storing Din[7:4] but reading as PD[3:0]
    // (and F6 the inverse), giving display PD = nibble_swap(written_byte).
    // MAME's superbug_state::get_tile_info1 decodes the byte directly
    // (`code = ram[i] & 0x3F`, `color = ram[i] >> 6`) — no swap. With the
    // swap in place, byte $08 (MAME-invisible "tile 8 / palette 0") was
    // appearing as PD=$80 (visible "tile 0 / palette 2") and filling the
    // road area with tile-0 noise instead of staying black. Same schematic
    // mislabel kind as the PD[5:4] mux fix in commit a6cc504. Wire each
    // RAM half straight through so display PD = byte the CPU wrote.
    ram256 E6(
        .clock(Clk6),
        .address(PF_RAM_Adr),
        .wren(PF_Wren),
        .data(PFRAM_Din[3:0]),
        .q(PD[3:0])
    );


    ram256 F6(
        .clock(Clk6),
        .address(PF_RAM_Adr),
        .wren(PF_Wren),
        .data(PFRAM_Din[7:4]),
        .q(PD[7:4])
    );
    
    // Wren is active-low on real hardware so this is a NAND gate.
    // Schematic gates writes by VBlank to avoid mid-scanline display
    // glitches. Our cpu68 is several x slower per scanline than the real
    // 6800, so the NMI handler doesn't fit inside the 16-line VBlank
    // window — most playfield writes would otherwise be discarded.
    // Allow writes any time the CPU is at the playfield-RAM range; the
    // mux at PF_RAM_Adr already routes the right address.
    assign PF_Wren = (RnW & Sys_En & PfldRAM);
    assign PfldRAM = (Sys_En & BA[10] & BA[8]);
    assign PF_RAMce_n = (~(((~VBlank)) | PfldRAM));
    
    // Same VBlank-gate issue as PF_Wren above: with the slow cpu68 most
    // playfield writes land outside VBlank. Drop the VBlank gate so the
    // CPU's BD reaches PFRAM_Din whenever the CPU is writing the
    // playfield address range, not just during retrace.
    assign BD_en = (~(PfldRAM & RnW));
    
    // Route CPU's BA[7:0] when the CPU is accessing the playfield range;
    // otherwise the display H/V counters drive the RAM address. Original
    // gate was on VBlank only, which assumed the program writes finish
    // inside the vertical retrace — true on the real 6800 (~750 kHz)
    // but not in our cpu68 sim (much higher cycles/instr).
    //
    // Original schematic order: PVP[7:4] in the high nibble, PHP[7:4] in
    // the low nibble. The CPU (per MAME) writes scroll_y to PVP_Load
    // ($0100) and scroll_x to PHP_Load ($0120) and lays out the tilemap
    // as mem[(row<<4) | col] where row = un-rotated y direction, col =
    // un-rotated x direction. After our VGA_ROTATE=-1 (90° CCW), the
    // un-rotated horizontal road rotates into a vertical road. Keeping
    // this order also keeps the scroll direction correct: PHP (scroll_x)
    // updates per-frame become vertical motion in the rotated view —
    // which is what "moving forward along the road" looks like in the
    // vertical-cabinet orientation.
    assign PF_RAM_Adr = PfldRAM ? BA[7:0] : {PVP[7:4], PHP[7:4]};
    
    // Check data bus paths carefully
    assign PFRAM_Din = (BD_en == 1'b0) ? BD : 
                       {8{1'b1}};
    
    // B7 LS109
    //B7_CRASH: entity work.JK_FF_VHDL 
    //port map( 
    //	Clock=>Clk6,
    //	J=>'0',
    //	K=>Crash_n,
    //	Reset=>'0',
    //	Clock_enable=>CrashReset_n,
    //	Output=>CrashIn_n
    //    );
    //B7_SKID: entity work.JK_FF_VHDL 
    //port map( 
    //	Clock=>Clk6,
    //	J=>'0',
    //	K=>Skid_n,
    //	Reset=>'0',
    //	Clock_enable=>SkidReset_n,
    //	Output=>SkidIn_n
    //    );
    
    assign Crash_n = (~(CrashCode & PfCarVid));
    assign PfCarVid = (Pfld & CarVideo);
    assign Skid_n = (~(PfCarVid & (~(CrashCode | SkidCode_n))));
    
`ifdef SIMULATION
    // Sim-only: count writes that actually fire so we can tell from the
    // outside whether the CPU is reaching the playfield RAM.
    integer pf_write_count = 0;
    always @(posedge Clk6) begin
        if (PF_Wren) begin
            pf_write_count <= pf_write_count + 1;
        end
    end
`endif

    // 74191 counters at C5 and E8. Sheet 4 gates the counter enable with
    // VBLANK/256H; in this synchronizer polarity that is H256 while not
    // in retrace. That gives exactly 256 Clk6 increments per scanline, so
    // the 8-bit PHP counter wraps back to the same scroll_x phase every
    // line. Advancing PHP for the whole 320-pixel nonblank interval adds
    // 64 counts per line and makes the rotated playfield collapse into
    // bands.
    //
    // The simulated CPU currently writes the scroll registers later than
    // real hardware would inside VBlank, so latch the CPU's write and
    // apply it on the VBlank falling edge. Bias PHP to the rotated/cropped
    // output origin so partially-written playfield rows enter from the top
    // like the MAME reference capture.
    reg [7:0] PHP_load_value;
    reg       prev_VBlank_php;
    always @(posedge Clk6)
    begin: PHP_count
        prev_VBlank_php <= VBlank;
        if (PHP_Load_n == 1'b0)
            PHP_load_value <= BD;

        if (prev_VBlank_php & ~VBlank)
            PHP <= PHP_load_value + 8'd16;
        else if (H256 & ~VBlank)
            PHP <= PHP + 1;
    end
    
    // 74191 counters at D5 and F8.
    // Clock is HSync (one increment per scanline), NOT Clk6 — original VHDL
    // says `rising_edge(HSync)`. Model it as a Clk6-domain HSync edge
    // detector so the Verilator schedule stays single-clocked. Like PHP,
    // defer CPU writes to the VBlank falling edge so late simulated CPU
    // writes do not reload PVP halfway through the displayed frame.
    reg [7:0] PVP_load_value;
    reg       prev_HSync_pvp;
    reg       prev_VBlank_pvp;
    always @(posedge Clk6)
    begin: PVP_count
        prev_HSync_pvp  <= HSync;
        prev_VBlank_pvp <= VBlank;
        if (PVP_Load_n == 1'b0)
            PVP_load_value <= BD;

        if (prev_VBlank_pvp & ~VBlank)
            PVP <= PVP_load_value;
        else if (HSync & ~prev_HSync_pvp & ~VBlank)
            PVP <= PVP + 1;
    end
    
    //N9 and L10
    assign CrashSkid = (((~CrashCode)) & SkidCode_n);
    
    //L9
    
    // L9 — Arrow_n latch.
    // Original VHDL:
    //   if ArrowOff_n = '0' then Arrow_n <= '1';   -- async preset
    //   elsif rising_edge(VBlank) then Arrow_n <= '0';
    // i.e. the CPU's ArrowOff strobe ($01E0) sets Arrow_n=1 ("arrows
    // off"), and the next VBlank rising edge clears it back to 0
    // ("arrows on") at the start of the following frame. The X-HDL
    // port collapsed this into a level mux that just drives
    // Arrow_n = ~ArrowOff_n every Clk6 — that throws the CPU strobe
    // away after one cycle, so arrows are always on. In MAME's
    // attract sequence the program asserts ArrowOff almost every
    // frame, so the arrow-overlay tiles should be hidden.
    reg prev_VBlank_arrow;
    always @(posedge Clk6) begin
        prev_VBlank_arrow <= VBlank;
        if (~ArrowOff_n)                            Arrow_n <= 1'b1;
        else if (VBlank & ~prev_VBlank_arrow)       Arrow_n <= 1'b0;
    end
    
    //M9		
    assign CrashArrow = (~(Arrow_n & CrashSkid));
    
    //N9
    assign Pfld = CrashArrow & Pf;
    
    // 74LS95 shift register uses falling edge of Clk6_n, using rising edge of Clk6
    // accomplishes the same thing. The FPGA/Verilator ROM models have a
    // registered output, so delay LOAD_PD one Clk6 edge before reloading
    // the shift register. Otherwise the boundary cycle can load the previous
    // ROM nibble and leave stray pixels at scrolling tile edges.
    
    reg LoadPd_d;
    always @(posedge Clk6)
    begin: A5
        LoadPd_d <= LoadPd;
        if (LoadPd_d == 1'b1)
            VidShift <= Vid;
        else
            VidShift <= {1'b0, VidShift[3:1]};
    end
    // Schematic NOR: Pf = ~(VidShift[0] | PfWndo_n).
    //
    // Combined with the mixer's `PCC1Pfld = PCC1 & Pfld` /
    // `PCC2Pfld = PCC2 & Pfld` gates, this implements MAME's palette
    // interpretation: color0 (= ROM bit=0) is the *foreground* color
    // chosen by PCC1/PCC2, and color1 (= ROM bit=1) is always BLACK.
    //
    // For palette 0 (PCC1=PCC2=0) every pixel is BLACK regardless of
    // bit — that's the empty-road tile. For palette 3 (PCC1=PCC2=1)
    // bit=0 gives WHITE (lane markers), bit=1 stays BLACK. Matches
    // firetrk_state::palette()'s colortable_source for tilemap[0].
    assign Pf = ~(VidShift[0] | PfWndo_n);
    assign LoadPd = (PHP[0] & PHP[1]);
    
    // L9 — PfWndo D-FF.
    // Schematic clocks this on rising edge of H8 with VBlank=1 as async
    // clear. Updating PfWndo every Clk6 (as the X-HDL port did) makes
    // the window edge slide by up to one Clk6 cycle and clips the
    // leftmost playfield column. Use H8 edge detection on Clk6 instead.
    reg prev_H8_pfwndo;
    always @(posedge Clk6) begin: WindowLatch
        prev_H8_pfwndo <= H8;
        if (VBlank) begin
            PfWndo   <= 1'b0;
            PfWndo_n <= 1'b1;
        end else if (H8 & ~prev_H8_pfwndo) begin
            PfWndo   <= Window_en;
            PfWndo_n <= ~Window_en;
        end
    end
    
    // MAME clips the unrotated playfield to x=0x02a..0x115. In the
    // rotated Verilator image, the old trailing edge allowed one extra
    // 8-pixel slice to wrap into the top of the screen. Tighten that
    // edge by also blanking when H8 is high in the final H32 group.
    assign Window_en = H256 & ((~(H128 & H64 & H32 & (H16 | H8))));
    
    // 9316 H7 on the schematic latches PCC1/PCC2/CrashCode/SkidCode
    // synchronously on Clk6 when PE = ~LOAD_PD goes low (LOAD_PD =
    // PHP[0] & PHP[1] fires every 4 pixels at PHP%4==3). That gives a
    // 4-pixel lag at cell boundaries: the first ~4 pixels of each new
    // cell still display with the PREVIOUS cell's palette bits, which
    // shows up as "ghost scenery" leaking into the road area at every
    // $98→$08 boundary. MAME's tilemap renderer doesn't model the lag.
    //
    // We drive PCC1/PCC2/CrashCode/SkidCode_n combinationally from PD
    // instead. PD is held within a cell by PF_RAM_Adr (= {PVP[7:4],
    // PHP[7:4]} during display), so combinationally these signals are
    // also held within a cell and only change at cell boundaries with
    // exactly the RAM read latency (~1 pixel). This still doesn't
    // match a tilemap renderer's perfect cell-aligned colors, but it
    // drops the visible boundary leak from 4 pixels to ~1.
    assign PCC1       = PD[6];
    assign PCC2       = PD[7];
    assign CrashCode  = PD[4];
    assign SkidCode_n = PD[3];
    
endmodule
