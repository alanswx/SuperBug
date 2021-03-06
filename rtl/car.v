// Car picture generator block for Atari/Kee Games Super Bug 
// This generates the car sprite that rotates in the 
// center of the screen.
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

module car(
    Clk6,
    Clk50,
    RW_n,
    BD,
    BA,
    HCount,
    VCount,
    CarRot_n,
    CarVideo
);
    input        Clk6;
    input        Clk50;
    input        RW_n;
    input [7:0]  BD;
    input [15:0] BA;
    input [8:0]  HCount;
    input [7:0]  VCount;
    input        CarRot_n;
    output reg   CarVideo;
    
    
    wire         H1;
    wire         H2;
    wire         H4;
    wire         H8;
    wire         H16;
    wire         H32;
    wire         H64;
    wire         H128;
    wire         H128n;
    wire         H256;
    
    wire         V1;
    wire         V2;
    wire         V4;
    wire         V8;
    wire         V16;
    wire         V32;
    wire         V64;
    wire         V128;
    wire         V128n;
    
    wire [9:0]   CarROM_Adr;
    wire [3:0]   CarROM_Dout;
    wire         CarEna_n;
    reg          R1;
    reg          R0;
    
    wire         CV16;
    wire         CV8;
    wire         CV4;
    wire         CV2;
    wire         CV1;
    
    wire         CH16;
    wire         CH8;
    wire         CH4;
    wire         CH2;
    wire         CH1;
    
    wire         V16g;
    wire         V8g;
    wire         V4g;
    wire         V2g;
    wire         V1g;
    
    wire         H16g;
    wire         H8g;
    wire         H4g;
    wire         H2g;
    wire         H1g;
    
    reg          M7Qa;
    reg          M7Qb;
    
    reg          BD2_Sel;
    reg          BD3_Sel;
    reg          BD4_Sel;
    
    wire [1:0]   R_Sel;
    
    assign H1 = HCount[0];
    assign H2 = HCount[1];
    assign H4 = HCount[2];
    assign H8 = HCount[3];
    assign H16 = HCount[4];
    assign H32 = HCount[5];
    assign H64 = HCount[6];
    assign H128 = HCount[7];
    assign H128n = (~H128);
    assign H256 = HCount[8];
    
    assign V1 = VCount[0];
    assign V2 = VCount[1];
    assign V4 = VCount[2];
    assign V8 = VCount[3];
    assign V16 = VCount[4];
    assign V32 = VCount[5];
    assign V64 = VCount[6];
    assign V128 = VCount[7];
    assign V128n = (~V128);
    
    assign CarROM_Adr = {CV16, CV8, CV4, CV2, CV1, CH16, CH8, CH4, CH2, CH1};
    
    
    K6_ROM K6(
        .clock(Clk50),
        .address(CarROM_Adr),
        .q(CarROM_Dout)
    );
    
    assign R_Sel = ({R1, R0});
    
    always @(CarROM_Dout or R_Sel or CarEna_n)
    begin: K7
        if (CarEna_n == 1'b0)
            case (R_Sel)
                2'b00 :
                    CarVideo <= CarROM_Dout[0];
                2'b01 :
                    CarVideo <= CarROM_Dout[1];
                2'b10 :
                    CarVideo <= CarROM_Dout[2];
                2'b11 :
                    CarVideo <= CarROM_Dout[3];
                default :
                    CarVideo <= 1'b0;
            endcase
        else
            CarVideo <= 1'b0;
    end
    
    //M7a: process(HCount)
    
    always @(posedge H16)
    begin: M7a
        
            // Real hardware uses nand then Q_, same result 
            M7Qa <= H256 & H128n & H64 & H32;
    end
    
    //M7b: process(VCount)
    
    always @(posedge V8)
    begin: M7b
        		// Clocked by 8H
            // Real hardware uses nand then Q_, same result 
            M7Qb <= V128n & V64 & V32;
    end
    assign CarEna_n = ~(M7Qa & M7Qb);
    
    // Latch at L4
    
    always @(posedge CarRot_n)
    begin: L4
        
        begin
            R0 <= BD[0];
            R1 <= BD[1];
            BD2_Sel <= BD[2];
            BD3_Sel <= BD[3];
            BD4_Sel <= BD[4];
        end
    end
    
    // Selectors at K5, L6 and J6
    // These swap H and V signals to flip the car image stored in ROM
    assign CV16 = (BD4_Sel == 1'b0) ? H16g : 
                  V16g;
    assign CH16 = (BD4_Sel == 1'b0) ? V16g : 
                  H16g;
    assign CV8 = (BD4_Sel == 1'b0) ? H8g : 
                 V8g;
    assign CH8 = (BD4_Sel == 1'b0) ? V8g : 
                 H8g;
    assign CV4 = (BD4_Sel == 1'b0) ? H4g : 
                 V4g;
    assign CH4 = (BD4_Sel == 1'b0) ? V4g : 
                 H4g;
    assign CV2 = (BD4_Sel == 1'b0) ? H2g : 
                 V2g;
    assign CH2 = (BD4_Sel == 1'b0) ? V2g : 
                 H2g;
    assign CV1 = (BD4_Sel == 1'b0) ? H1g : 
                 V1g;
    assign CH1 = (BD4_Sel == 1'b0) ? V1g : 
                 H1g;
    
    // Gated H and V signals from XOR gates in K4 and L5
    assign V16g = (BD3_Sel ^ (V16 ^ ((~V8))));
    assign V8g = (BD3_Sel ^ ((~V8)));
    assign V4g = (BD3_Sel ^ V4);
    assign V2g = (BD3_Sel ^ V2);
    assign V1g = (BD3_Sel ^ V1);
    
    assign H16g = (BD2_Sel ^ ((~H16)));
    assign H8g = (BD2_Sel ^ H8);
    assign H4g = (BD2_Sel ^ H4);
    assign H2g = (BD2_Sel ^ H2);
    assign H1g = (BD2_Sel ^ H1);
    
endmodule
