// Trailer picture generator for Atari Fire Truck.
//
// The only picture generator Super Bug has no counterpart for. Sixty-four
// pixels square against the car's thirty-two, eight rotation frames against
// four, and its own position on screen, where the car sits at a fixed place.
//
// The ROM holds each frame in its own 512 bytes: sixty-four lines of eight
// bytes, eight pixels to a byte with the leftmost in the most significant bit.
//
// Placement follows the reference's draw_car for the drone. The rotation
// register carries the frame in its low three bits, flip in X in bit 3 and
// flip in Y in bit 4, and each flip mirrors the origin as well as the picture.

`default_nettype none

module trailer(
    input  wire        Clk6,
    input  wire [8:0]  HCount,
    input  wire [7:0]  VCount,
    input  wire [7:0]  BD,
    input  wire        DroneX_n,
    input  wire        DroneY_n,
    input  wire        DroneRot_n,
    input  wire [1:0]  Game,
    output reg         TrailerVideo
);

    localparam GAME_FIRETRK = 2'd1;
    wire firetrk = (Game == GAME_FIRETRK);

    reg [7:0] drone_x, drone_y;
    reg [4:0] drone_rot;

    reg prev_x_n, prev_y_n, prev_rot_n;
    always @(posedge Clk6) begin
        prev_x_n   <= DroneX_n;
        prev_y_n   <= DroneY_n;
        prev_rot_n <= DroneRot_n;
        if (prev_x_n   & ~DroneX_n)   drone_x   <= BD;
        if (prev_y_n   & ~DroneY_n)   drone_y   <= BD;
        if (prev_rot_n & ~DroneRot_n) drone_rot <= BD[4:0];
    end

    wire       flip_x = drone_rot[3];
    wire       flip_y = drone_rot[4];
    wire [2:0] frame  = drone_rot[2:0];

    // Visible raster position. The horizontal counter runs 224 to 511 and then
    // 128 to 159 across a line, so the first stretch is the left 288 pixels and
    // the wrapped stretch the remaining 32.
    // Two pixels of pipeline between the picture generators and the displayed
    // pixel, the same compensation the car carries. Swept against the
    // reference: zero leaves the vehicle 5.3% wrong, one and three 3.2%, and
    // two renders it exactly.
    wire [8:0] hc = HCount + 9'd2;
    wire [8:0] pos_x = (hc >= 9'd224) ? (hc - 9'd224) : (hc + 9'd160);
    wire [8:0] pos_y = {1'b0, VCount};

    // Origin, mirrored when the matching flip bit is set.
    wire [8:0] org_x = (flip_x ? ({1'b0, drone_x} - 9'd63) : (9'd192 - {1'b0, drone_x})) + 9'd36;
    wire [8:0] org_y =  flip_y ? ({1'b0, drone_y} - 9'd63) : (9'd192 - {1'b0, drone_y});

    wire [8:0] off_x = pos_x - org_x;
    wire [8:0] off_y = pos_y - org_y;
    wire       in_box = (off_x < 9'd64) && (off_y < 9'd64);

    wire [5:0] rom_x = flip_x ? (6'd63 - off_x[5:0]) : off_x[5:0];
    wire [5:0] rom_y = flip_y ? (6'd63 - off_y[5:0]) : off_y[5:0];

    wire [7:0] rom_dout;
    ROM_FT_TRAILER TRAILER_ROM(
        .clock(Clk6),
        .address({frame, rom_y, rom_x[5:3]}),
        .q(rom_dout)
    );

    // The ROM output is a cycle behind the address, so hold the pixel select
    // and the window by the same cycle.
    reg [2:0] rom_x_lo_d;
    reg       in_box_d;
    always @(posedge Clk6) begin
        rom_x_lo_d <= rom_x[2:0];
        in_box_d   <= in_box;
    end

    // Super Bug has no trailer. Its strobes never fire, so the position
    // registers would sit at their power-on value, which happens to place a
    // sixty-four pixel box of Fire Truck's trailer ROM on screen.
    always @(*) TrailerVideo = firetrk & in_box_d & rom_dout[3'd7 - rom_x_lo_d];

endmodule

`default_nettype wire
