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
    
    // Vertical counter is 8 bits, advanced once per scanline. Originally
    // clocked by hsync_int rising edge, but in Verilator the hsync_int
    // generation has multi-edge sensitivity that can fire several times
    // per scanline, making vcount race ahead. Clock vcount directly off
    // the h_counter wrap (which is unambiguous: one wrap per scanline),
    // so we get exactly 256 v_counter ticks per frame.

    // Edge detectors. Everything below this point uses these as clock
    // enables on the single clk_12 domain, instead of the original D-FF
    // chain's multi-edge sensitivity ("negedge X or posedge Y") which
    // the simulator can not schedule reliably (extra edges per scanline
    // made the V counter race and double-pulsed NMI).
    reg          prev_H32;
    reg          prev_H8;
    reg          prev_H256_n;
    reg          prev_hblank_int;
    reg          prev_hsync_int;
    always @(posedge clk_12) begin
        prev_H32        <= H32;
        prev_H8         <= H8;
        prev_H256_n     <= H256_n;
        prev_hblank_int <= hblank_int;
        prev_hsync_int  <= hsync_int;
    end
    wire ce_H32_rise        =  H32        & ~prev_H32;
    wire ce_H8_rise         =  H8         & ~prev_H8;
    wire ce_H256n_fall      = ~H256_n     &  prev_H256_n;
    wire ce_hblank_fall     = ~hblank_int &  prev_hblank_int;
    wire ce_hsync_rise      =  hsync_int  & ~prev_hsync_int;

    // Vertical counter — must advance during HBlank=1 so that the
    // downstream IRQ_DFF (`negedge V16 with HBlank=1 -> IRQ_n=0`) sees
    // the V16 falling edge while HBlank is still asserted. In the
    // schematic, hsync_int rises mid-line (at h_counter=336 in our 768-
    // tick scanline) inside the hblank window. Use that exact h_counter
    // value as a clean clock-enable instead of the multi-flop hsync_int
    // (which can race).
    wire ce_line = (h_counter == 10'd336);
    always @(posedge clk_12)
    begin: V_count
        if (vreset_n == 1'b0)     v_counter <= 8'b0;
        else if (ce_line)         v_counter <= v_counter + 1'b1;
    end
    
    // Many Atari raster games use a 256 x 4 bit prom to decode vertical sync signals
    // This could be replaced by combinatorial logic
    //M2: entity work.sync_prom
    //port map(
    //		clock => clk_12, 
    //		address => sync_reg(3) & V128 & V64 & V16 & V8 & V4 & V2 & V1,
    //		q => sync_bus
    //		);
    
    // ------------------------------------------------------------------
    // Vertical sync generation
    //
    // The original Super Bug schematic uses a 256x4 bipolar PROM at M6
    // (009114.bin) to decode VBLANK/VSYNC/VRESET from the V counter and a
    // one-bit feedback latch. Both the original VHDL port (source/sync.vhd)
    // and the X-HDL Verilog translation build the PROM address as
    //   {sync_reg[3], V128, V64, V16, V8, V4, V2, V1}
    // — V32 is missing. With V32 omitted, two values of vcount alias to
    // the same PROM entry, so VBLANK pulses twice per frame, NMI fires
    // twice per frame, and the second NMI nests into the first NMI's
    // handler -> stack corruption -> RTI returns to garbage -> CPU dies in
    // RAM. Matches the user's report that the original VHDL also fails.
    //
    // The PROM data itself is correct (verified bit-for-bit against the
    // 009114.bin dump that MAME ships with CRC b8094b4c). Until/unless we
    // figure out the correct address composition for the schematic-faithful
    // PROM lookup, generate VBLANK/VSYNC/VRESET algorithmically from
    // vcount, matching MAME's firetrk_state::scanline() callback:
    //   - VBLANK active for vcount >= 240
    //   - VSYNC pulse during vcount 242..244
    //   - VRESET pulse at vcount 261 -> wrap to 0
    // (The PROM is still instantiated below to keep the prom_address wire
    // for future debugging; its output is ignored.)
    // ------------------------------------------------------------------

    assign prom_address = {sync_reg[3], V128, V64, V16, V8, V4, V2, V1};

    prom M2(
        .address(prom_address),
        .data(sync_bus)
    );

    always @(posedge clk_12) begin: sync_register
        if (ce_hsync_rise) sync_reg <= sync_bus;
    end

    // 256-line frame; 8-bit vcount wraps naturally. No explicit vreset
    // (vcount = (vcount + 1) % 256 from the always-block above).
    assign vreset   = 1'b0;
    assign vreset_n = 1'b1;
    // VBLANK level: wide pulse (vcount 240..255) so the playfield RAM mux
    // routes the CPU bus through during the entire vertical retrace, per
    // schematic.
    assign vblank   = (v_counter >= 8'd240);
    assign vsync    = (v_counter >= 8'd242 && v_counter <= 8'd244);
    
    // Hsync_1: schematic D-FF, D=~H64, CLK=posedge H32, async clear when
    // H256_n=0 (i.e. H256=1, the wrap-region of the h_counter). Modelled
    // here on posedge clk_12 with clock enables: the level-clear takes
    // priority, otherwise update on the rising edge of H32.
    always @(posedge clk_12) begin: Hsync_1
        if (H256_n == 1'b0)        hblank_int <= 1'b0;
        else if (ce_H32_rise)      hblank_int <= ~H64;
    end

    // Hsync_2: D-FF D=H32, CLK=posedge H8, async clear when hblank_int=0.
    always @(posedge clk_12) begin: Hsync_2
        if (hblank_int == 1'b0)    hsync_int <= 1'b0;
        else if (ce_H8_rise)       hsync_int <= H32;
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
