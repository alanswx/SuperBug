// Portable simulation models for Super Bug ROMs and small RAMs.
// These replace the Altera altsyncram-based modules in ../verilog/ for Verilator.
// All clocked on `clock` rising edge with one cycle of read latency, matching
// the altsyncram CLOCK0 outdata register the original modules used.

`default_nettype none

module ROM_M3 (input wire clock, input wire [9:0] address, output reg [3:0] q);
    reg [3:0] mem [0:1023];
    initial $readmemh("../roms/hex/009124m3.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_N3 (input wire clock, input wire [9:0] address, output reg [3:0] q);
    reg [3:0] mem [0:1023];
    initial $readmemh("../roms/hex/009471n3.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_E5 (input wire clock, input wire [9:0] address, output reg [3:0] q);
    reg [3:0] mem [0:1023];
    initial $readmemh("../roms/hex/009127e5.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_F5 (input wire clock, input wire [9:0] address, output reg [3:0] q);
    reg [3:0] mem [0:1023];
    initial $readmemh("../roms/hex/009126f5.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_H5 (input wire clock, input wire [9:0] address, output reg [3:0] q);
    reg [3:0] mem [0:1023];
    initial $readmemh("../roms/hex/009472h5.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module K6_ROM (input wire clock, input wire [9:0] address, output reg [3:0] q);
    reg [3:0] mem [0:1023];
    initial $readmemh("../roms/hex/009125k6.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_D1 (input wire clock, input wire [10:0] address, output reg [7:0] q);
    reg [7:0] mem [0:2047];
    initial $readmemh("../roms/hex/009121d1.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_C1 (input wire clock, input wire [10:0] address, output reg [7:0] q);
    reg [7:0] mem [0:2047];
    initial $readmemh("../roms/hex/009122c1.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_A1 (input wire clock, input wire [10:0] address, output reg [7:0] q);
    reg [7:0] mem [0:2047];
`ifdef GLYPH_TEST
    initial $readmemh("../roms/hex/glyphtest_a1.hex", mem);
`else
    initial $readmemh("../roms/hex/009123a1.hex", mem);
`endif
    always @(posedge clock) q <= mem[address];
endmodule

module ram256 (
    input wire        clock,
    input wire [7:0]  address,
    input wire        wren,
    input wire [3:0]  data,
    output reg [3:0]  q
);
    reg [3:0] mem [0:255];
    integer init_idx;
    initial begin
        q = 4'h0;
        for (init_idx = 0; init_idx < 256; init_idx = init_idx + 1)
            mem[init_idx] = 4'h0;
    end
    always @(posedge clock) begin
        if (wren) mem[address] <= data;
        q <= mem[address];
    end
endmodule

module ram128 (
    input wire        clock,
    input wire [6:0]  address,
    input wire        wren,
    input wire [7:0]  data,
    output reg [7:0]  q
);
    reg [7:0] mem [0:127];
    integer init_idx;
    initial begin
        q = 8'h00;
        for (init_idx = 0; init_idx < 128; init_idx = init_idx + 1)
            mem[init_idx] = 8'h00;
    end
    always @(posedge clock) begin
        if (wren) mem[address] <= data;
        q <= mem[address];
    end
endmodule

`default_nettype wire

// ---------------------------------------------------------------------------
// Fire Truck ROMs. Built from the MAME set by tools/make_firetrk_hex.py.
// The program image is 8 KB at $2000; its upper half comes from two pairs of
// nibble-wide PROMs which that script recombines.
// ---------------------------------------------------------------------------
module ROM_FT_PROG (input wire clock, input wire [12:0] address, output reg [7:0] q);
    reg [7:0] mem [0:8191];
    initial $readmemh("../roms/hex/firetrk_prog.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_FT_CHARS (input wire clock, input wire [10:0] address, output reg [7:0] q);
    reg [7:0] mem [0:2047];
    initial $readmemh("../roms/hex/firetrk_chars.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_FT_TILES (input wire clock, input wire [10:0] address, output reg [7:0] q);
    reg [7:0] mem [0:2047];
    initial $readmemh("../roms/hex/firetrk_tiles.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_FT_CAR (input wire clock, input wire [9:0] address, output reg [7:0] q);
    reg [7:0] mem [0:1023];
    initial $readmemh("../roms/hex/firetrk_car.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

module ROM_FT_TRAILER (input wire clock, input wire [11:0] address, output reg [7:0] q);
    reg [7:0] mem [0:4095];
    initial $readmemh("../roms/hex/firetrk_trailer.hex", mem);
    always @(posedge clock) q <= mem[address];
endmodule

// 256 x 8 RAM. Super Bug uses 32 bytes of it for the alphanumeric display;
// Fire Truck uses the whole page, which is also the processor's direct page.
module ram256b (
    input wire        clock,
    input wire [7:0]  address,
    input wire        wren,
    input wire [7:0]  data,
    output reg [7:0]  q
);
    reg [7:0] mem [0:255];
    integer i;
    initial begin
        q = 8'h00;
        for (i = 0; i < 256; i = i + 1) mem[i] = 8'h00;
    end
    always @(posedge clock) begin
        if (wren) mem[address] <= data;
        q <= mem[address];
    end
endmodule

// 256 x 8 dual port RAM: one write port for the processor, one read port for
// the display. Fire Truck's alphanumeric RAM is the processor's direct page,
// so it is written constantly and cannot be time-shared with the display the
// way Super Bug's can.
module dpram256b (
    input wire        clock,
    input wire [7:0]  wraddress,
    input wire        wren,
    input wire [7:0]  data,
    input wire [7:0]  rdaddress,
    output reg [7:0]  q
);
    reg [7:0] mem [0:255];
    integer i;
    initial begin
        q = 8'h00;
        for (i = 0; i < 256; i = i + 1) mem[i] = 8'h00;
    end
    always @(posedge clock) begin
        if (wren) mem[wraddress] <= data;
        q <= mem[rdaddress];
    end
endmodule
