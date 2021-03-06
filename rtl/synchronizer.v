// Video synchronizer circuit for Super Bug
// Similar circuit used in many other Atari and Kee Games arcade games
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

module synchronizer(
    clk_12,
    clk_6,
    clk6_n,
    hcount,
    vcount,
    hsync,
    hblank,
    vblank,
    vsync,
    vreset
);
    input        clk_12;
    output       clk_6;
    output       clk6_n;
    output [8:0] hcount;
    output [7:0] vcount;
    output       hsync;
    output       hblank;
    output       vblank;
    output       vsync;
    output       vreset;
    
    
    reg [9:0]    h_counter;
    wire         H256;
    wire         H256_n;
    wire         H128;
    wire         H64;
    wire         H32;
    wire         H16;
    wire         H8;
    wire         H8_n;
    wire         H4;
    wire         H4_n;
    wire         H2;
    wire         H1;
    
    reg [7:0]    v_counter;
    wire         V128;
    wire         V64;
    wire         V32;
    wire         V16;
    wire         V8;
    wire         V4;
    wire         V2;
    wire         V1;
    
    wire [3:0]   sync_bus;
    reg [3:0]    sync_reg;
    wire         vblank_int;
    wire         vreset_n;
    
    reg          hblank_int;
    reg          hsync_int;
    wire         hsync_reset;
    
    wire [7:0]   prom_address;
    
    // Horizontal counter is 9 bits long plus additional flip flop. The last 4 bit IC in the chain resets to 0010 so total count resets to 128 
    // using only the last three count states
    
    always @(posedge clk_12)
    begin: H_count
        
        begin
            if (h_counter == 10'b1111111111)
                h_counter <= 10'b0100000000;
            else
                h_counter <= h_counter + 1;
        end
    end
    
    // Vertical counter is 8 bits, clocked by the rising edge of H256 at the end of each horizontal line
    
    always @(posedge hsync_int)
    begin: V_count
        
        begin
            if (vreset_n == 1'b0)
                v_counter <= {8{1'b0}};
            else
                v_counter <= v_counter + 1'b1;
        end
    end
    
    // Many Atari raster games use a 256 x 4 bit prom to decode vertical sync signals
    // This could be replaced by combinatorial logic
    //M2: entity work.sync_prom
    //port map(
    //		clock => clk_12, 
    //		address => sync_reg(3) & V128 & V64 & V16 & V8 & V4 & V2 & V1,
    //		q => sync_bus
    //		);
    
    assign prom_address = {sync_reg[3], V128, V64, V16, V8, V4, V2, V1};
    
    prom M2(
        .address(prom_address),
        .data(sync_bus)
    );
    
    // Register fed by the sync PROM, in the original hardware this also creates the complements of these signals
    
    always @(posedge hsync_int)
    begin: sync_register
        
            sync_reg <= sync_bus;
    end
    
    // Outputs of sync PROM
    //vblank_s <= sync_reg(3);
    //vblank_n_s <= not sync_reg(3);
    assign vreset = sync_reg[2];
    assign vreset_n = (~sync_reg[2]);
    assign vblank = sync_reg[1];
    assign vsync = sync_reg[0];
    
    // A pair of D type flip-flops that generate the Hsync signal
    
    always @(negedge H256_n or posedge H32)
    begin: Hsync_1
        if (H256_n == 1'b0)
            hblank_int <= 1'b0;
        else
            
                hblank_int <= (~H64);
    end
    
    
    always @(negedge hblank_int or posedge H8)
    begin: Hsync_2
        if (hblank_int == 1'b0)
            hsync_int <= 1'b0;
        else
            
                hsync_int <= H32;
    end
    
    // Assign various signals
    assign clk_6 = h_counter[0];
    assign clk6_n = ((~h_counter[0]));
    //clk6_n <= not clk_6;
    assign H1 = h_counter[1];
    assign H2 = h_counter[2];
    assign H4 = h_counter[3];
    assign H8 = h_counter[4];
    assign H16 = h_counter[5];
    assign H32 = h_counter[6];
    assign H64 = h_counter[7];
    assign H128 = h_counter[8];
    assign H256 = h_counter[9];
    assign H4_n = (~H4);
    assign H8_n = (~H8);
    assign H256_n = (~H256);
    
    assign V1 = v_counter[0];
    assign V2 = v_counter[1];
    assign V4 = v_counter[2];
    assign V8 = v_counter[3];
    assign V16 = v_counter[4];
    assign V32 = v_counter[5];
    assign V64 = v_counter[6];
    assign V128 = v_counter[7];
    
    assign hcount = h_counter[9:1];
    assign vcount = v_counter;
    assign hsync = hsync_int;
    assign hblank = hblank_int;
    
endmodule
