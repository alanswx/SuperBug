`timescale 1ns / 1ps
/*============================================================================
===========================================================================*/

module emu (

	input clk_sys,
	input reset,
	input soft_reset,
	input menu,
	input adam,
	
	input [31:0] joystick_0,
	input [31:0] joystick_1,
	input [31:0] joystick_2,
	input [31:0] joystick_3,
	input [31:0] joystick_4,
	input [31:0] joystick_5,
	
	input [15:0] joystick_l_analog_0,
	input [15:0] joystick_l_analog_1,
	input [15:0] joystick_l_analog_2,
	input [15:0] joystick_l_analog_3,
	input [15:0] joystick_l_analog_4,
	input [15:0] joystick_l_analog_5,
	
	input [15:0] joystick_r_analog_0,
	input [15:0] joystick_r_analog_1,
	input [15:0] joystick_r_analog_2,
	input [15:0] joystick_r_analog_3,
	input [15:0] joystick_r_analog_4,
	input [15:0] joystick_r_analog_5,

	input [7:0] paddle_0,
	input [7:0] paddle_1,
	input [7:0] paddle_2,
	input [7:0] paddle_3,
	input [7:0] paddle_4,
	input [7:0] paddle_5,

	input [8:0] spinner_0,
	input [8:0] spinner_1,
	input [8:0] spinner_2,
	input [8:0] spinner_3,
	input [8:0] spinner_4,
	input [8:0] spinner_5,

	// ps2 alternative interface.
	// [8] - extended, [9] - pressed, [10] - toggles with every press/release
	input [10:0] ps2_key,

	// [24] - toggles with every event
	input [24:0] ps2_mouse,
	input [15:0] ps2_mouse_ext, // 15:8 - reserved(additional buttons), 7:0 - wheel movements

	// [31:0] - seconds since 1970-01-01 00:00:00, [32] - toggle with every change
	input [32:0] timestamp,

	output [7:0] VGA_R,
	output [7:0] VGA_G,
	output [7:0] VGA_B,
	
	output VGA_HS,
	output VGA_VS,
	output VGA_HB,
	output VGA_VB,

	output CE_PIXEL,
	
	output	[15:0]	AUDIO_L,
	output	[15:0]	AUDIO_R,
	
	input			ioctl_download,
	input			ioctl_wr,
	input [24:0]		ioctl_addr,
	input [7:0]		ioctl_dout,
	input [7:0]		ioctl_index,
	output reg		ioctl_wait=1'b0,

	output [31:0] 		sd_lba[2],
	output [9:0] 		sd_rd,
	output [9:0] 		sd_wr,
	input [9:0] 		sd_ack,
	input [8:0] 		sd_buff_addr,
	input [7:0] 		sd_buff_dout,
	output [7:0] 		sd_buff_din[2],
	input 			sd_buff_wr,
	input [9:0] 		img_mounted,
	input 			img_readonly,

	input [63:0] 		img_size



);
wire [15:0] joystick_a0 =  joystick_l_analog_0;
wire [15:0] joy = joystick_0 | joystick_1;

wire UART_CTS;
wire UART_RTS;
wire UART_RXD;
wire UART_TXD;
wire UART_DTR;
wire UART_DSR;

wire       pressed = ps2_key[9];
wire [8:0] code    = ps2_key[8:0];
always @(posedge clk_sys) begin
        reg old_state;
        old_state <= ps2_key[10];

        if(old_state != ps2_key[10]) begin
                casex(code)
//                      'hX75: btn_up          <= pressed; // up
//                      'hX72: btn_down        <= pressed; // down
                        'hX6B: btn_left        <= pressed; // left
                        'hX74: btn_right       <= pressed; // right
                        'h014: btn_gas         <= pressed; // ctrl
                        'h011: btn_gearup      <= pressed; // Lalt
                        'h029: btn_geardown    <= pressed; // space
                        'h012: btn_nexttrack   <= pressed; // Lshft

                        'h005: btn_one_player  <= pressed; // F1
                        'h006: btn_two_players <= pressed; // F2
                        // JPAC/IPAC/MAME Style Codes
                        'h016: btn_start_1     <= pressed; // 1
                        'h02E: btn_coin_1      <= pressed; // 5
                        'h036: btn_coin_2      <= pressed; // 6
                endcase
        end
end

//reg btn_up    = 0;
//reg btn_down  = 0;
reg btn_right = 0;
reg btn_left  = 0;
reg btn_gas  = 0;
reg btn_gearup  = 0;
reg btn_geardown  = 0;
reg btn_nexttrack=0;

reg btn_one_player  = 0;
reg btn_two_players = 0;

reg btn_start_1=0;
reg btn_coin_1=0;
reg btn_coin_2=0;

wire m_left     =  btn_left   | joy[1];
wire m_right    =  btn_right  | joy[0];
wire m_gas      =  btn_gas    | joy[4];
wire m_gearup   =  btn_gearup |joy[5];
wire m_geardown =  btn_geardown | joy[6];
wire m_next_track       =  joy[7]|btn_nexttrack;

wire m_start1 = btn_one_player  | joy[7];
wire m_start2 = btn_two_players | joy[8];
wire m_coin   = m_start1 | m_start2;




wire [1:0] steer;

joy2quad steer1
(
        .CLK(clk_6),
        .clkdiv('d22500),

        .right(m_right),
        .left(m_left),

        .steer(steer)
);

wire gear1,gear2,gear3;

gearshift gearshift1
(
        .CLK(clk_6),
        .reset(m_start1|m_start2),

        .gearup(m_gearup),
        .geardown(m_geardown),

        .gear1(gear1),
        .gear2(gear2),
        .gear3(gear3)

);


        wire [7:0] DIP_Sw = 8'b10100000; //-- Config dip switches

superbug superbug(
        .Clk_50_I(clk_sys),
        .Clk12(clk_12),
        .Reset_n(~(RESET | ioctl_download)),

        .dn_addr(ioctl_addr[16:0]),
        .dn_data(ioctl_data),
        .dn_wr(ioctl_wr),
        .Audio_O(audio),

        .Video1_O(videowht),
        .Video2_O(videoblk),
        .Sync_O(compositesync),

        .Coin1_I(~(m_coin|btn_coin_1)),
        .Coin2_I(~(m_coin|btn_coin_2)),
        .Start_I(~(m_start1|btn_start_1)),
        .Gas_I(~m_gas),
        .Gear1_I(gear1),
        .Gear2_I(gear2),
        .Gear3_I(gear3),
        .Test_I (1'b1),
        .Steer_1A_I(steer[1]),
        .Steer_1B_I(steer[0]),
        .Lamp1_O(lamp),
        .Lamp2_O(lamp2),
        .hs_O(hsync),
        .vs_O(vsync),
        .hblank_O(hblank),
        .vblank_O(vblank),
        .clk_6_O(clk_6),
        .DIP_Sw(DIP_Sw),
        .Slam_I(1'b1),
        .Trak_Sel_I(~m_next_track)


        );

	wire clk_48,clk_12,clk_6;
wire locked;
reg [7:0] vid_mono;
wire[1:0] sprint_vid;

always @(posedge clk_sys) begin
                casex({videowht,videoblk})
                        //2'b01: vid_mono<=8'b01010000;
                        2'b01: vid_mono<=8'b01110000;
                        2'b10: vid_mono<=8'b10000110;
                        2'b11: vid_mono<=8'b11111111;
                        2'b00: vid_mono<=8'b00000000;
                endcase
end

assign VGA_R=vid_mono;
assign VGA_G=vid_mono;
assign VGA_B=vid_mono;
assign VGA_HS=hsync;
assign VGA_VS=vsync;
assign VGA_HB=hblank;
assign VGA_VB=vblank;

assign CE_PIXEL=clk_6;





endmodule
