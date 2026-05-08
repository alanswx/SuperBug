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
