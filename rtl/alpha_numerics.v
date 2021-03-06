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
    A_NVideo
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
    
    wire [6:0]   RAM_Addr;
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
    
    assign H256_n = ((~HCount[8]));
    
    //BA10and8 <= (BA(10) and BA(8));
    assign BA10and8 = BA[10] & (~BA[8]);
    assign BA12nor11 = ~(BA[12] | BA[11]);
    assign Sys_en = (BVMA & BA12nor11 & Phi2);
    assign BVMA = VMA;		//((not BA(14)) and VMA);
    
    //Mux_select <= not(BA10and8 and BA12nor11 and BVMA);
    //Mux_select <= not(BA10and8 and BA12nor11 and VMA);
    assign Mux_select = (BVMA == 1'b1 & BA[12:10] == 3'b001 & BA[8] == 1'b1) ? 1'b0 : 
                        1'b1;
    
    assign SysEnBA10_8 = (~(Sys_en & BA10and8));
    
    assign RAMcs_n = (SysEnBA10_8 & VBlank);
    //RAMcs_n <= '0' when VBlank = '0' or (BA(10) and BA(8) and Sys_en) = '1' else '1';
    //RAMcs_n <= '0' when VBlank = '1' or (BA(10)='1' and BA(8)='1'  and Sys_en='1') else '1'; -- AJS
    
    // Altera block RAM has active-high write-enable
    assign RAM_we = (RAMcs_n == 1'b0 & RW_n == 1'b0 & Mux_select == 1'b1) ? 1'b1 : 
                    1'b0;
    
    // Selectors at P2 and P4
    assign RAM_Addr = (Mux_select == 1'b0) ? {2'b00, HCount[5], VCount[7:4]} : 
                      {2'b00, BA[4:0]};
    
    // Alphanumeric character RAM
    // Real hardware has 128 byte RAM but it seems only 32 bytes are used				
    
    ram128 P3_RAM(
        .clock(Clk6),
        .address(RAM_Addr),
        .wren(RAM_we),
        .data(BD),
        .q(RAM_Dout)
    );
    
    //RAM_Dout<="00001000";
    
    assign rom_m3_addr = {RAM_Dout[3:0], VCount[3:0], HCount[3:2]};
    
    ROM_M3 M3_ROM(
        .clock(Clk6),
        .address(rom_m3_addr),
        .q(M3_Dout)
    );
    
    assign rom_n3_addr = {RAM_Dout[3:0], VCount[3:0], HCount[3:2]};
    
    ROM_N3 N3_ROM(
        .clock(Clk6),
        .address(rom_n3_addr),
        .q(N3_Dout)
    );
    
    // Alphanumeric ROMs are selected by RAM_Dout(4)
    assign AlphaROM_Dout = (RAM_Dout[4] == 1'b0) ? M3_Dout : 
                           N3_Dout;
    
    assign ShiftLoad = (HCount[0] & HCount[1]);
    
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
    
    assign AN_Blank = (HBlank_n & (HCount[3] ^ HCount[4]));
    
endmodule
