// Tire screech sound generator for Kee Games Sprint 2 / Atari Super Bug.
// Hand-written Verilog port of source/screech.vhd (James Sweet, 2017),
// originally derived from a Verilog version by Jonas Elofsson.
// Replaces an X-HDL auto-translation that mis-sensitized the always
// block and registered the output that the VHDL exposed combinationally.
//
// A counter ramps up and down between two thresholds; the ramp slope is
// modulated by a 1-bit Noise input from an LFSR. Screech_out is the
// ramp-direction state bit (1 while rising, 0 while falling).

`default_nettype none

module tire_screech #(
    parameter integer Inc1 = 24,
    parameter integer Inc2 = 34,
    parameter integer Dec1 = 23,
    parameter integer Dec2 = 12
) (
    input  wire Clk,        // ~750 kHz from the horizontal line counter
    input  wire Noise,      // LFSR pseudo-random noise bit
    output wire Screech_out
);

    // Range 1000..11000 fits in 14 bits.
    localparam [13:0] INC1 = Inc1[13:0];
    localparam [13:0] INC2 = Inc2[13:0];
    localparam [13:0] DEC1 = Dec1[13:0];
    localparam [13:0] DEC2 = Dec2[13:0];

    reg [13:0] Screech_count;
    reg        Screech_state;

    assign Screech_out = Screech_state;

    always @(posedge Clk) begin
        if (Screech_state) begin
            Screech_count <= Screech_count + (Noise ? INC2 : INC1);
            if (Screech_count > 14'd10000) Screech_state <= 1'b0;
        end else begin
            Screech_count <= Screech_count - (Noise ? DEC2 : DEC1);
            if (Screech_count < 14'd1000)  Screech_state <= 1'b1;
        end
    end

endmodule

`default_nettype wire
