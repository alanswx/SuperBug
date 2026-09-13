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
    CarVideo,
    CarEna_dbg,
    CarRot_dbg,
    Game,
    dn_addr,
    dn_data,
    dn_wr,
    dn_clk
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
    output       CarEna_dbg;   // sprite window enable, for raster-position debugging
    output [4:0] CarRot_dbg;   // latched rotation register, write-only to the CPU
    input [1:0]  Game;		// 0 = Super Bug, 1 = Fire Truck
    input [16:0] dn_addr;	// ROM loader, from the MRA download
    input [7:0]  dn_data;
    input        dn_wr;
    input        dn_clk;	// the download runs at the system clock rate
    
    
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
    // The rotation register, exposed so the simulation harness can force it.
    // The game reaches only one of its thirty-two values in ordinary play, so
    // the rest are otherwise impossible to exercise. The attribute is a
    // comment to every other tool.
    reg          R1 /*verilator public_flat*/;
    reg          R0 /*verilator public_flat*/;
    
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
    
    reg          BD2_Sel /*verilator public_flat*/;
    reg          BD3_Sel /*verilator public_flat*/;
    reg          BD4_Sel /*verilator public_flat*/;
    
    wire [1:0]   R_Sel;
    
    // The car's horizontal decode runs two pixels ahead of the raw H counter.
    // The sprite window signal itself lines up with MAME exactly — measured
    // with `--raster-probe`, both put it at visible-raster x=144..175 — but
    // there are two pixels of pipeline between the video generators and the
    // displayed pixel, so without compensation the sprite is drawn at
    // x=147..177 and spills past its own window. Advancing the whole
    // horizontal decode by two moves window and sprite together and lands the
    // drawn car on MAME's pixels exactly.
    wire [8:0] HCountC = HCount + 9'd2;

    assign H1 = HCountC[0];
    assign H2 = HCountC[1];
    assign H4 = HCountC[2];
    assign H8 = HCountC[3];
    assign H16 = HCountC[4];
    assign H32 = HCountC[5];
    assign H64 = HCountC[6];
    assign H128 = HCountC[7];
    assign H128n = (~H128);
    assign H256 = HCountC[8];
    
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
        .q(CarROM_Dout),
        .dn_addr(dn_addr), .dn_data(dn_data), .dn_wr(dn_wr), .dn_clk(dn_clk), .dn_base(17'h2C00)
    );
    
    localparam GAME_FIRETRK = 2'd1;
    wire firetrk = (Game == GAME_FIRETRK);

    // Fire Truck's truck ROM is laid out nothing like Super Bug's. Super Bug
    // packs its four frames into the four bits of every nibble, one pixel per
    // byte along one axis. Fire Truck gives each frame its own 256 bytes:
    // thirty-two lines of eight bytes, four pixels in the low nibble of each,
    // leftmost pixel in the most significant bit of that nibble. It also takes
    // the frame straight from the rotation register rather than inverting it.
    wire [4:0] CV = {CV16, CV8, CV4, CV2, CV1};
    wire [4:0] CH = {CH16, CH8, CH4, CH2, CH1};
    wire [7:0] ft_car_dout;
    ROM_FT_CAR FT_CAR(
        .clock(Clk6),
        .address({R1, R0, CV, CH[4:2]}),
        .q(ft_car_dout),
        .dn_addr(dn_addr), .dn_data(dn_data), .dn_wr(dn_wr), .dn_clk(dn_clk), .dn_base(17'h3000)
    );
    // The ROM output is a cycle behind its address, so the nibble index has to
    // be held by the same cycle or it indexes the previous byte.
    //
    // With the transpose bit clear CH comes from the vertical counter and does
    // not change across a scanline, so using it live looks right and every one
    // of those sixteen rotations matches the reference exactly. With the
    // transpose bit set CH comes from the horizontal counter and steps every
    // pixel, so the index ran a pixel ahead of the byte it was indexing and
    // one pixel in four came from the wrong nibble. That is the garbled cab
    // seen whenever the truck turns far enough to select the transposed
    // layout, and it cost about ten percent of the sprite.
    reg [1:0] ft_nibble_d;
    always @(posedge Clk6) ft_nibble_d <= CH[1:0];
    wire ft_pixel = ft_car_dout[3 - ft_nibble_d];

    // Frame-select index.
    //
    // MAME's superbug_state::draw_car computes `code = ~car_rot & 0x03` and
    // then draws gfx element `code`. That looks like an inversion, but the
    // element number is not the ROM nibble bit: superbug_car_layout1 has a
    // character increment of one BIT, so element N starts at bit offset
    // (4 + N) inside each byte. MAME numbers bit offsets MSB-first, so offset
    // 4 is value bit 3 and offset 7 is value bit 0 — element N lives in
    // nibble bit (3 - N).
    //
    // Composing the two: nibble bit = 3 - code = 3 - (3 - car_rot[1:0])
    //                              = car_rot[1:0] = {R1, R0}.
    //
    // So the register's low two bits index the ROM nibble directly and no
    // inversion belongs here. Verified against the ROM image: at car_rot=0x0C
    // MAME selects nibble bit 0, which decodes to the symmetric upright car
    // it draws in attract mode. Selecting bit 3 instead yields the frame
    // rotated by about thirty degrees, which is what this core drew before
    // this fix.
    assign R_Sel = ({R1, R0});
    
    // Keep the sensitivity list explicit. Widening it to a wildcard moved
    // Super Bug's car by enough to cost a fifth of a percent of the frame:
    // the Super Bug ROM below is clocked from the 50 MHz input rather than the
    // pixel clock like everything else in the core, and the simulator orders
    // that against a wildcard-sensitive block differently. Worth cleaning up
    // by moving that ROM onto the pixel clock, but not while it is the only
    // thing standing between this and a known-good reference match.
    always @(CarROM_Dout or R_Sel or CarEna_n or ft_pixel or firetrk)
    begin: K7
        if (CarEna_n == 1'b0 && firetrk)
            CarVideo <= ft_pixel;
        else if (CarEna_n == 1'b0)
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
    
    // M7a/M7b — sprite-window latches. Schematic clocks them on the
    // rising edge of H16 / V8 respectively, but in Verilator that
    // produces multi-edge sensitivity that can fire at clk_sys edges
    // unrelated to the H/V counter — we were seeing the latched window
    // hold past its real geometry, painting a ghost copy of the car
    // sprite in the upper-right of the screen. Re-clock both on Clk6
    // with explicit edge detection of H16 / V8.
    reg prev_H16, prev_V8;
    always @(posedge Clk6) begin
        prev_H16 <= H16;
        prev_V8  <= V8;
        if (H16 & ~prev_H16) M7Qa <= H256 & H128n & H64 & H32;
        if (V8  & ~prev_V8 ) M7Qb <= V128n & V64 & V32;
    end
    assign CarEna_n = ~(M7Qa & M7Qb);
    assign CarEna_dbg = ~CarEna_n;
    assign CarRot_dbg = {BD4_Sel, BD3_Sel, BD2_Sel, R1, R0};
    
    // L4 — car rotation register (CPU writes to \$0180).
    // Schematic uses rising edge of CarRot_n; Verilator's multi-edge
    // semantics can re-fire this at unrelated clk_sys edges. Use a
    // proper edge detector on Clk6 instead.
    reg prev_CarRot_n;
    always @(posedge Clk6) begin: L4
        prev_CarRot_n <= CarRot_n;
        if (CarRot_n & ~prev_CarRot_n) begin
            R0       <= BD[0];
            R1       <= BD[1];
            BD2_Sel  <= BD[2];
            BD3_Sel  <= BD[3];
            BD4_Sel  <= BD[4];
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
