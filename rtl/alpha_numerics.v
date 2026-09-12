// Alpha-Numerics block for Atari/Kee Games Super Bug 
// This generates all alpha-numeric characters
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

module alpha_numerics(
    Clk6,
    Phi2,
    RW_n,
    BD,
    BA,
    HCount,
    VCount,
    HBlank_n,
    VBlank,
    VMA,
    BVMA,
    Sys_en,
    A_NVideo,
    Game,
    dn_addr,
    dn_data,
    dn_wr,
    dn_clk
);
    input        Clk6;
    input        Phi2;
    input        RW_n;
    input [7:0]  BD;
    input [15:0] BA;
    input [8:0]  HCount;
    input [7:0]  VCount;
    input        HBlank_n;
    input        VBlank;
    input        VMA;
    output       BVMA;
    output       Sys_en;
    output       A_NVideo;
    input [1:0]  Game;		// 0 = Super Bug, 1 = Fire Truck
    input [16:0] dn_addr;	// ROM loader, from the MRA download
    input [7:0]  dn_data;
    input        dn_wr;
    input        dn_clk;	// the download runs at the system clock rate
    
    
    //signal H4				: std_logic;
    //signal H8				: std_logic;
    //
    //signal V1				: std_logic;
    //signal V2				: std_logic;
    //signal V4				: std_logic;
    //signal V8				: std_logic;
    //signal V16				: std_logic;
    //signal V32				: std_logic;
    //signal V64				: std_logic;
    //signal V128				: std_logic;
    //
    wire         H256_n;
    
    wire [7:0]   RAM_Addr;
    wire [7:0]   RAM_RdAddr;
    wire [7:0]   RAM_Dout2;
    wire [7:0]   RAM_Dout;
    wire         RAM_we;
    
    wire         Mux_select;
    
    wire         BA10and8;
    wire         BA12nor11;
    
    wire         SysEnBA10_8;
    
    wire         RAMcs_n;
    
    wire [3:0]   M3_Dout;
    wire [3:0]   N3_Dout;
    wire [3:0]   AlphaROM_Dout;
    
    wire         ShiftLoad;
    reg [3:0]    ShiftData;
    
    wire         AN_Blank;
    wire [9:0]   rom_m3_addr;
    wire [9:0]   rom_n3_addr;
    
    //H4 <= HCount(2);
    //H8 <= HCount(3);
    // H16 <= HCount(4);
    // H32 <= HCount(5);
    // H64 6
    // H128 7
    // H256 8
    
    //V1 <= VCount(0);
    //V2 <= VCount(1);
    //V4 <= VCount(2);
    //V8 <= VCount(3);
    //V16 <= VCount(4);
    //V32 <= VCount(5);
    //V64 <= VCount(6);
    //V128 <= VCount(7);
    
    // The whole alphanumeric datapath runs one pixel ahead of the raw H
    // counter. Measured against MAME at frame 400, the glyphs were shape-exact
    // but sat one pixel further right than the reference; advancing every
    // consumer of HCount by one keeps the layer internally consistent while
    // moving it back into place. Advancing only the shift-register load
    // instead fixes the position but re-cuts the glyph across its nibble
    // boundaries, which measured worse.
    wire [8:0] HCountA = HCount + 9'd1;

    assign H256_n = ((~HCountA[8]));
    
    //BA10and8 <= (BA(10) and BA(8));
    assign BA10and8 = BA[10] & (~BA[8]);
    assign BA12nor11 = ~(BA[12] | BA[11]);
    // Drop the Phi2 gate. In the schematic Sys_en is gated by Phi2 so
    // that the strobe only fires while phase 2 is high; in Verilator the
    // CPU samples its data_in / drives its data_out at the negedge of
    // Phi2, by which point Phi2 has already fallen and the gate is off.
    // Same race as the SysEn_rd fix in cpu_mem.v. Sys_en here feeds the
    // alpha-RAM Mux_select decode and is also exported to the playfield
    // module for its PfldRAM/PF_Wren decode; both want the address
    // window to be visible across the whole CPU access cycle, not just
    // its phase-2-high half.
    // For Fire Truck this has to reach the playfield page at $0800 as well as
    // the alphanumeric page at $0000, so it covers everything below the
    // program ROM.
    assign Sys_en = firetrk ? (BVMA & ~BA[13]) : (BVMA & BA12nor11);
    assign BVMA = VMA;		//((not BA(14)) and VMA);
    
    // Mux_select=1 when CPU is at the alphanumeric RAM ($0400-$041F per MAME):
    // BA[12:10]=001, BA[10]=1, BA[8]=0. Below, RAM_Addr = BA[4:0] when
    // Mux_select=1 (CPU side), else display_addr. The original VHDL/Verilog
    // had this inverted (BA[8]==1 which matches playfield range instead of
    // alpha) AND with the Mux_select=0 polarity, so the display ended up
    // reading whatever address the CPU bus happened to hold at the time —
    // making every alpha cell appear identical (single character repeated
    // at every screen position).
    localparam GAME_FIRETRK = 2'd1;
    wire firetrk = (Game == GAME_FIRETRK);

    // Fire Truck's alphanumeric RAM is a whole page at $0000 and doubles as
    // the processor's direct page and stack; only its first thirty-two bytes
    // are displayed. Super Bug keeps a separate thirty-two byte RAM at $0400.
    assign Mux_select = firetrk ? (BVMA & BA[13:11] == 3'b000)
                                : ((BVMA == 1'b1 & BA[12:10] == 3'b001 & BA[8] == 1'b0) ? 1'b1 :
                                   1'b0);
    
    assign SysEnBA10_8 = (~(Sys_en & BA10and8));
    
    // Super Bug gates the alphanumeric RAM's chip select with vertical blank,
    // because the display and the processor share it and the processor only
    // gets in during retrace. Fire Truck's is the direct page: the processor
    // writes it all the time and cannot be held off.
    assign RAMcs_n = firetrk ? ~Mux_select : (SysEnBA10_8 & VBlank);
    //RAMcs_n <= '0' when VBlank = '0' or (BA(10) and BA(8) and Sys_en) = '1' else '1';
    //RAMcs_n <= '0' when VBlank = '1' or (BA(10)='1' and BA(8)='1'  and Sys_en='1') else '1'; -- AJS
    
    // Altera block RAM has active-high write-enable
    assign RAM_we = (RAMcs_n == 1'b0 & RW_n == 1'b0 & Mux_select == 1'b1) ? 1'b1 : 
                    1'b0;
    
    // Selectors at P2 and P4
    // Separate addresses now that the RAM is dual ported: the display always
    // reads its thirty-two cells, the processor always writes wherever it is.
    assign RAM_RdAddr = {3'b000, HCount[5], VCount[7:4]};
    assign RAM_Addr   = firetrk ? BA[7:0] : {3'b000, BA[4:0]};
    
    // Alphanumeric character RAM
    // Real hardware has 128 byte RAM but it seems only 32 bytes are used				
    
    dpram256b P3_RAM(
        .clock(Clk6),
        .wraddress(RAM_Addr),
        .wren(RAM_we),
        .data(BD),
        .rdaddress(RAM_RdAddr),
        .q(RAM_Dout)
    );
    
    //RAM_Dout<="00001000";
    
    // Fire Truck's character generator is one byte-wide ROM holding all
    // thirty-two glyphs, sixteen rows of four bytes each, of which only the
    // low nibble carries pixels. The four column groups are taken from bytes
    // 3, 0, 1, 2 across the glyph, two steps round from where the nibble
    // counter starts. Swept against the reference: the other three offsets
    // leave the text about nine percent wrong, this one renders it exactly.
    wire [7:0] ft_char_dout;
    ROM_FT_CHARS FT_CHARS(
        .clock(Clk6),
        .address({RAM_Dout[4:0], VCount[3:0], HCountA[3:2] + 2'd2}),
        .q(ft_char_dout),
        .dn_addr(dn_addr), .dn_data(dn_data), .dn_wr(dn_wr), .dn_clk(dn_clk), .dn_base(17'h2000)
    );

    assign rom_m3_addr = {RAM_Dout[3:0], VCount[3:0], HCountA[3:2]};

    ROM_M3 M3_ROM(
        .clock(Clk6),
        .address(rom_m3_addr),
        .q(M3_Dout),
        .dn_addr(dn_addr), .dn_data(dn_data), .dn_wr(dn_wr), .dn_clk(dn_clk), .dn_base(17'h1800)
    );

    assign rom_n3_addr = {RAM_Dout[3:0], VCount[3:0], HCountA[3:2]};
    
    ROM_N3 N3_ROM(
        .clock(Clk6),
        .address(rom_n3_addr),
        .q(N3_Dout),
        .dn_addr(dn_addr), .dn_data(dn_data), .dn_wr(dn_wr), .dn_clk(dn_clk), .dn_base(17'h1C00)
    );
    
    // Alphanumeric ROMs are selected by RAM_Dout(4)
    assign AlphaROM_Dout = firetrk      ? ft_char_dout[3:0] :
                           (RAM_Dout[4] == 1'b0) ? M3_Dout : 
                           N3_Dout;
    
    assign ShiftLoad = (HCountA[0] & HCountA[1]);
    
    // Real hardware 74LS95 uses falling edge of Clk6_n, this is the same as rising edge of Clk6
    
    always @(posedge Clk6 )
    begin: L3
        
        begin
            if (ShiftLoad == 1'b1)
                ShiftData <= AlphaROM_Dout;
            else
                ShiftData <= {ShiftData[2:0], 1'b0};
        end
    end
    // Alphanumeric data is shifted out on ShiftData(3)
    assign A_NVideo = (ShiftData[3] & H256_n & AN_Blank);
    
    assign AN_Blank = (HBlank_n & (HCountA[3] ^ HCountA[4]));
    
endmodule
