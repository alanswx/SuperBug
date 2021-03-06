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
    output reg   PCC1;
    output reg   PCC2;
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
    
    reg          CrashCode;
    reg          SkidCode_n;
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
    
    // CE lines are labeled strangely on schematic
    
    always @(*)
    begin: PF_ROM_mux
        Vid <= {4{1'b0}};
        case (PD[5:4])
            2'b00 :
                Vid <= F5_Dout;
            2'b01 :
                Vid <= E5_Dout;
            2'b10 :
                Vid <= H5_Dout;
            2'b11 :
                Vid <= E5_Dout;
            default :
                ;
        endcase
    end
    
    //Playfield RAM
    
    ram256 E6(
        .clock(Clk6),
        .address(PF_RAM_Adr),
        .wren(PF_Wren),
        .data(PFRAM_Din[7:4]),
        .q(PD[3:0])
    );
    
    
    ram256 F6(
        .clock(Clk6),
        .address(PF_RAM_Adr),
        .wren(PF_Wren),
        .data(PFRAM_Din[3:0]),
        .q(PD[7:4])
    );
    
    // Wren is active-low on real hardware so this is a NAND gate	
    assign PF_Wren = (VBlank & RnW & Sys_En);
    assign PfldRAM = (Sys_En & BA[10] & BA[8]);
    assign PF_RAMce_n = (~(((~VBlank)) | PfldRAM));
    
    assign BD_en = (~(VBlank & PfldRAM & RnW));
    
    assign PF_RAM_Adr = (VBlank == 1'b0) ? {PVP[7:4], PHP[7:4]} : 
                        BA[7:0];
    
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
    
    // 74191 counters at C5 and E8
    
    always @(posedge Clk6)
    begin: PHP_count
        if (PHP_Load_n == 1'b0)
            PHP <= BD;
        else 
        begin
            if ((~(((~H256)) & VBlank)) == 1'b0)
                PHP <= PHP + 1;
        end
    end
    
    // 74191 counters at D5 and F8
    
    always @(posedge Clk6)
    begin: PVP_count
        if (PVP_Load_n == 1'b0)
            PVP <= BD;
        else 
        begin
            if (VBlank == 1'b0)
                PVP <= PVP + 1;
        end
    end
    
    //N9 and L10
    assign CrashSkid = (((~CrashCode)) & SkidCode_n);
    
    //L9
    
    always @(posedge Clk6)
    begin: ArrowLatch
        if (ArrowOff_n == 1'b0)
            Arrow_n <= 1'b1;
        else 
            Arrow_n <= 1'b0;
    end
    
    //M9		
    assign CrashArrow = (~(Arrow_n & CrashSkid));
    
    //N9
    assign Pfld = CrashArrow & Pf;
    
    // 74LS95 shift register uses falling edge of Clk6_n, using rising edge of Clk6 
    // accomplishes the same thing
    
    always @(posedge Clk6)
    begin: A5
        
        begin
            if (LoadPd == 1'b1)
                VidShift <= Vid;
            else
                VidShift <= {1'b0, VidShift[3:1]};
        end
    end
    assign Pf = (~(VidShift[0] | PfWndo_n));
    assign LoadPd = (PHP[0] & PHP[1]);
    
    //L9
    // Real hardware uses VBlank_n, no need to create a separate inverted signal
    
    always @(posedge Clk6)
    begin: WindowLatch
        if (VBlank == 1'b1)
        begin
            PfWndo <= 1'b0;
            PfWndo_n <= 1'b1;
        end
        else 
        begin
            PfWndo <= Window_en;
            PfWndo_n <= ((~Window_en));
        end
    end
    
    assign Window_en = H256 & ((~(H128 & H64 & H32 & H16)));
    
    // 9316 counter has CEP and CET tied low, used as a synchronous latch
    
    always @(posedge Clk6)
    begin: H7
        
        begin
            if (LoadPd == 1'b1)
            begin
                PCC2 <= PD[7];
                PCC1 <= PD[6];
                CrashCode <= PD[4];
                SkidCode_n <= PD[3];
            end
        end
    end
    
endmodule



