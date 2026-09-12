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

	output	[15:0]	dbg_pc,
	output	[7:0]	dbg_opcode,
	output	[15:0]	dbg_addr,
	output	[7:0]	dbg_din,
	output		dbg_op_fetch,
	output	[7:0]	dbg_acca,
	output	[7:0]	dbg_accb,
	output	[7:0]	dbg_cc,
	output	[8:0]	dbg_hcount,
	output		dbg_pfwndo,
	output		dbg_carena,
	output	[4:0]	dbg_car_rot,
	output	[9:0]	dbg_sound,
	output	[31:0]	dbg_snd_strobes,
	output	[15:0]	dbg_inputs,
	output	[15:0]	dbg_in_count,
	
	input			service_mode,	// 1 = self-test (Test_I active-low low)
	input	[1:0]	game_select,	// 0 = Super Bug, 1 = Fire Truck
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
wire [15:0] joy  = joystick_0 | joystick_1;
wire [15:0] joy2 = joystick_1;      // back player, for Fire Truck's second wheel

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
wire m_next_track	=  btn_nexttrack | joy[7];

// The menu string above assigns joystick bits in order: 4 Gas, 5 GearUp,
// 6 GearDown, 7 NextTrack, 8 Start 1P, 9 Start 2P, 10 Coin. Start used to read
// bit 7, which is Next Track, so one button did both jobs and Start 2P read the
// Start 1P button.
wire m_start1 = btn_one_player  | joy[8];
wire m_start2 = btn_two_players | joy[9];
wire m_start3 = joy[11];
wire btn_right2 = 1'b0;
wire btn_left2  = 1'b0;
// Coin must be its own button. Wiring start into the coin line looks like a
// coin held down for as long as start is held, and the interrupt handler
// checks the coin switch before the start switch and exits as soon as it sees
// one, so the start check was never reached and a game could never begin.
wire m_coin   = joy[10];




wire [1:0] steer;
wire [1:0] steer2;

joy2quad steer2gen
(
        .CLK(clk_6),
        .clkdiv('d22500),
        .right(btn_right2 | joy2[0]),
        .left(btn_left2 | joy2[1]),
        .steer(steer2)
);

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


        // The FPGA build takes this byte from the MRA's <switches> block; the
        // harness has no MRA, so it holds the same default the MRA declares.
        // Layout, in the order Input.v's 74153 at C6 presents the pairs:
        //   [7:6] Coinage      = 10  (1 coin 1 play)
        //   [5:4] Game Time    = 01  (90 seconds)
        //   [3:2] Extended     = 10  (medium)
        //   [1:0] Language     = 00  (English)
        // Matches MAME's superbug defaults.
        wire [7:0] DIP_Sw = 8'b10011000;

// Sim-only: superbug expects a separate 12 MHz clock for the video synchronizer.
// In the FPGA build a PLL produces this from CLK_50M; for Verilator we just
// alias clk_sys (virtual timescale) so the video pipeline ticks at all.
wire clk_12_sim = clk_sys;

wire videowht;
wire videoblk;
wire compositesync;
wire hsync;
wire vsync;
wire hblank;
wire vblank;
wire [15:0] audio;
assign AUDIO_L = audio;
assign AUDIO_R = audio;
wire lamp;
wire lamp2;

superbug superbug(
        .Clk_50_I(clk_sys),
        .Clk12(clk_12_sim),
        .Reset_n(~(reset | ioctl_download)),

        .dn_addr(ioctl_addr[16:0]),
        .dn_data(ioctl_dout),
        // Index 0 is the packed ROM image the MRA produces; index 1 is the
        // one byte game select, which the harness takes from --game instead.
        .dn_wr(ioctl_wr && ioctl_index == 8'd0),
        .Audio_O(audio),

        .Video1_O(videowht),
        .Video2_O(videoblk),
        .Sync_O(compositesync),

        .Coin1_I(~(m_coin|btn_coin_1)),
        // Coin 2 is its own switch. Driving both from one button looks like a
        // tampered coin mech to the program and the credit is thrown away.
        .Coin2_I(~btn_coin_2),
        .Start_I(~(m_start1|btn_start_1)),
        .Gas_I(~m_gas),
        .Gear1_I(gear1),
        .Gear2_I(gear2),
        .Gear3_I(gear3),
        .Test_I (~service_mode),     // active-low: 0 = self-test, 1 = normal
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
        .Game(game_select),
        .Slam_I(1'b1),
        .HSRes_I(1'b1),   // active low; unconnected reads as a held reset
        // Fire Truck's panel. It has no gears, so those two buttons carry the
        // horn and the bell instead.
        .Start2_I(~m_start2),
        .Start3_I(~m_start3),
        .Bell_I(~m_geardown),
        .Horn_I(~m_gearup),
        .Cabinet_I(1'b1),      // two player Fire Truck cabinet
        .DiagHold_I(1'b1),
        .DiagStep_I(1'b1),
        .Steer_2A_I(steer2[1]),
        .Steer_2B_I(steer2[0]),
        .Trak_Sel_I(~m_next_track),

        .dbg_pc(dbg_pc),
        .dbg_opcode(dbg_opcode),
        .dbg_addr(dbg_addr),
        .dbg_din(dbg_din),
        .dbg_op_fetch(dbg_op_fetch),
        .dbg_acca(dbg_acca),
        .dbg_accb(dbg_accb),
        .dbg_cc(dbg_cc),
        .dbg_hcount(dbg_hcount),
        .dbg_pfwndo(dbg_pfwndo),
        .dbg_carena(dbg_carena),
        .dbg_car_rot(dbg_car_rot),
        .dbg_sound(dbg_sound),
        .dbg_snd_strobes(dbg_snd_strobes),
        .dbg_inputs(dbg_inputs),
        .dbg_in_count(dbg_in_count)
        );

	wire clk_6;
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
