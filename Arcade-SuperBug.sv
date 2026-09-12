//============================================================================
//  SuperBug port to MiSTer
//  Copyright (c) 2019 Alan Steremberg - alanswx
//
//   
//============================================================================
module emu
(
	//Master input clock
	input         CLK_50M,

	//Async reset from top-level module.
	//Can be used as initial reset.
	input         RESET,

	//Must be passed to hps_io module
	inout  [48:0] HPS_BUS,

	//Base video clock. Usually equals to CLK_SYS.
	output        CLK_VIDEO,

	//Multiple resolutions are supported using different CE_PIXEL rates.
	//Must be based on CLK_VIDEO
	output        CE_PIXEL,

	//Video aspect ratio for HDMI. Most retro systems have ratio 4:3.
	//if VIDEO_ARX[12] or VIDEO_ARY[12] is set then [11:0] contains scaled size instead of aspect ratio.
	output [12:0] VIDEO_ARX,
	output [12:0] VIDEO_ARY,

	output  [7:0] VGA_R,
	output  [7:0] VGA_G,
	output  [7:0] VGA_B,
	output        VGA_HS,
	output        VGA_VS,
	output        VGA_DE,    // = ~(VBlank | HBlank)
	output        VGA_F1,
	output [1:0]  VGA_SL,
	output        VGA_SCALER, // Force VGA scaler

	input  [11:0] HDMI_WIDTH,
	input  [11:0] HDMI_HEIGHT,
	output        HDMI_FREEZE,

`ifdef MISTER_FB
	// Use framebuffer in DDRAM (USE_FB=1 in qsf)
	// FB_FORMAT:
	//    [2:0] : 011=8bpp(palette) 100=16bpp 101=24bpp 110=32bpp
	//    [3]   : 0=16bits 565 1=16bits 1555
	//    [4]   : 0=RGB  1=BGR (for 16/24/32 modes)
	//
	// FB_STRIDE either 0 (rounded to 256 bytes) or multiple of pixel size (in bytes)
	output        FB_EN,
	output  [4:0] FB_FORMAT,
	output [11:0] FB_WIDTH,
	output [11:0] FB_HEIGHT,
	output [31:0] FB_BASE,
	output [13:0] FB_STRIDE,
	input         FB_VBL,
	input         FB_LL,
	output        FB_FORCE_BLANK,

`ifdef MISTER_FB_PALETTE
	// Palette control for 8bit modes.
	// Ignored for other video modes.
	output        FB_PAL_CLK,
	output  [7:0] FB_PAL_ADDR,
	output [23:0] FB_PAL_DOUT,
	input  [23:0] FB_PAL_DIN,
	output        FB_PAL_WR,
`endif
`endif

	output        LED_USER,  // 1 - ON, 0 - OFF.

	// b[1]: 0 - LED status is system status OR'd with b[0]
	//       1 - LED status is controled solely by b[0]
	// hint: supply 2'b00 to let the system control the LED.
	output  [1:0] LED_POWER,
	output  [1:0] LED_DISK,

	// I/O board button press simulation (active high)
	// b[1]: user button
	// b[0]: osd button
	output  [1:0] BUTTONS,

	input         CLK_AUDIO, // 24.576 MHz
	output [15:0] AUDIO_L,
	output [15:0] AUDIO_R,
	output        AUDIO_S,   // 1 - signed audio samples, 0 - unsigned
	output  [1:0] AUDIO_MIX, // 0 - no mix, 1 - 25%, 2 - 50%, 3 - 100% (mono)

	//ADC
	inout   [3:0] ADC_BUS,

	//SD-SPI
	output        SD_SCK,
	output        SD_MOSI,
	input         SD_MISO,
	output        SD_CS,
	input         SD_CD,

	//High latency DDR3 RAM interface
	//Use for non-critical time purposes
	output        DDRAM_CLK,
	input         DDRAM_BUSY,
	output  [7:0] DDRAM_BURSTCNT,
	output [28:0] DDRAM_ADDR,
	input  [63:0] DDRAM_DOUT,
	input         DDRAM_DOUT_READY,
	output        DDRAM_RD,
	output [63:0] DDRAM_DIN,
	output  [7:0] DDRAM_BE,
	output        DDRAM_WE,

	//SDRAM interface with lower latency
	output        SDRAM_CLK,
	output        SDRAM_CKE,
	output [12:0] SDRAM_A,
	output  [1:0] SDRAM_BA,
	inout  [15:0] SDRAM_DQ,
	output        SDRAM_DQML,
	output        SDRAM_DQMH,
	output        SDRAM_nCS,
	output        SDRAM_nCAS,
	output        SDRAM_nRAS,
	output        SDRAM_nWE,

`ifdef MISTER_DUAL_SDRAM
	//Secondary SDRAM
	//Set all output SDRAM_* signals to Z ASAP if SDRAM2_EN is 0
	input         SDRAM2_EN,
	output        SDRAM2_CLK,
	output [12:0] SDRAM2_A,
	output  [1:0] SDRAM2_BA,
	inout  [15:0] SDRAM2_DQ,
	output        SDRAM2_nCS,
	output        SDRAM2_nCAS,
	output        SDRAM2_nRAS,
	output        SDRAM2_nWE,
`endif

	input         UART_CTS,
	output        UART_RTS,
	input         UART_RXD,
	output        UART_TXD,
	output        UART_DTR,
	input         UART_DSR,

	// Open-drain User port.
	// 0 - D+/RX
	// 1 - D-/TX
	// 2..6 - USR2..USR6
	// Set USER_OUT to 1 to read from USER_IN.
	input   [6:0] USER_IN,
	output  [6:0] USER_OUT,

	input         OSD_STATUS
);

assign ADC_BUS  = 'Z;
assign {UART_RTS, UART_TXD, UART_DTR} = 0;
assign {SD_SCK, SD_MOSI, SD_CS} = 'Z;
assign {SDRAM_DQ, SDRAM_A, SDRAM_BA, SDRAM_CLK, SDRAM_CKE, SDRAM_DQML, SDRAM_DQMH, SDRAM_nWE, SDRAM_nCAS, SDRAM_nRAS, SDRAM_nCS} = 'Z;
assign {DDRAM_CLK, DDRAM_BURSTCNT, DDRAM_ADDR, DDRAM_DIN, DDRAM_BE, DDRAM_RD, DDRAM_WE} = '0;  


assign VGA_F1    = 0;
assign VGA_SCALER= 0;
assign USER_OUT  = '1;

assign LED_USER  = ioctl_download;
assign LED_DISK  = lamp2;
assign LED_POWER = lamp;
assign {FB_PAL_CLK, FB_FORCE_BLANK, FB_PAL_ADDR, FB_PAL_DOUT, FB_PAL_WR} = '0;
assign HDMI_FREEZE = 0;

wire [1:0] ar = status[15:14];

assign VIDEO_ARX =  (!ar) ? ( 8'd4) : (ar - 1'd1);
assign VIDEO_ARY =  (!ar) ? ( 8'd3) : 12'd0;

`include "build_id.v"
localparam CONF_STR = {
	"A.SUPERBUG;;",
	"-;",
	"O1,Aspect Ratio,Original,Wide;",
	"O2,Orientation,Vert,Horz;",
	"O35,Scandoubler Fx,None,HQ2x,CRT 25%,CRT 50%,CRT 75%;",  
	"-;",
	"DIP;",
	"-;",
	"O8,Test,Off,On;",
	"-;",
	"R0,Reset;",
	"J1,Gas,GearUp,GearDown,NextTrack,Start 1P,Start 2P,Coin;",
	"V,v",`BUILD_DATE
};

/*
-- Configuration DIP switches, these can be brought out to external switches if desired
-- See Super Bug manual pg.6 for complete information. Active low (0 = On, 1 = Off)
--    8 	7							Game Cost			(10-1 Coin/1 Play, 11-Two Coins/1 Play, 01-Two Plays/1 Coin, 00-Free Play)
--				6	5					Game Length   		(00- 60 sec, 01- 90 sec, 10- 120 sec ,11- 150 sec)
--   					4	3			Extended Play		(00-None, 01-Liberal, 10-Medium, 11-Conservative
--								2	1	Language				(00-English, 01-French, 10-Spanish, 11-German)
--										
--DIP_Sw <= "10100000"; -- Config dip switches
*/


// DIP switches arrive from the MRA, not from hand-written menu entries. The
// MiSTer main sends them as an ioctl download with index 254, one byte per
// switch bank, and builds the DIP page in the menu from the MRA's <switches>
// block. Super Bug has one bank.
//
// Bit layout within that byte follows what Input.v's 74153 at C6 hands to the
// program, a pair at a time: [7:6] coinage at offset 0, [5:4] game time at 1,
// [3:2] extended play at 2, [1:0] language at 3. Super Bug.mra spells out the
// same pairs, so the two stay in step.

wire [31:0] status;
wire  [1:0] buttons;
wire        forced_scandoubler;
wire        direct_video;

wire        ioctl_download;
wire        ioctl_wr;
wire [24:0] ioctl_addr;
wire [7:0] ioctl_data;
wire [15:0] ioctl_index;

wire [10:0] ps2_key;

wire [15:0] joystick_0, joystick_1;
wire [15:0] joy = joystick_0 | joystick_1;
wire [21:0] gamma_bus;

hps_io #(.CONF_STR(CONF_STR)) hps_io
(
	.clk_sys(clk_sys),
	.HPS_BUS(HPS_BUS),

	.buttons(buttons),
	.status(status),
	.status_menumask(direct_video),
	.forced_scandoubler(forced_scandoubler),
	.gamma_bus(gamma_bus),
	.direct_video(direct_video),

	.ioctl_download(ioctl_download),
	.ioctl_wr(ioctl_wr),
	.ioctl_addr(ioctl_addr),
	.ioctl_dout(ioctl_data),
	.ioctl_index(ioctl_index),

	.joystick_0(joystick_0),
	.joystick_1(joystick_1),
	.ps2_key(ps2_key)
);



wire       pressed = ps2_key[9];
wire [8:0] code    = ps2_key[8:0];
always @(posedge clk_sys) begin
	reg old_state;
	old_state <= ps2_key[10];
	
	if(old_state != ps2_key[10]) begin
		casex(code)
//			'hX75: btn_up          <= pressed; // up
//			'hX72: btn_down        <= pressed; // down
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


//wire m_up     =  btn_up    | joy[3];
//wire m_down   =  btn_down  | joy[2];
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
// Coin must be its own button. Wiring start into the coin line looks like a
// coin held down for as long as start is held, and the interrupt handler
// checks the coin switch before the start switch and exits as soon as it sees
// one, so the start check was never reached and a game could never begin.
wire m_coin   = joy[10];




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



wire videowht,videoblk,compositesync,lamp;

			
wire [15:0] audio;
wire [1:0] video;

///////////////////////////////////////////////////
wire clk_48,clk_12,clk_6;
wire clk_sys,locked;
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

assign r=vid_mono[7:5];
assign g=vid_mono[7:5];
assign b=vid_mono[7:5];

assign AUDIO_L = audio;
assign AUDIO_R=AUDIO_L;
assign AUDIO_S = 0;

wire hblank, vblank;
wire hs, vs;
wire [2:0] r,g;
wire [2:0] b;


reg ce_pix;
always @(posedge clk_48) begin
        reg [2:0] div;

        div <= div + 1'd1;
        ce_pix <= !div;
end

arcade_video #(320,9) arcade_video
(
        .*,

        .clk_video(clk_48),

        .RGB_in({r,g,b}),
        .HBlank(hblank),
        .VBlank(vblank),
        .HSync(hs),
        .VSync(vs),
        .fx(status[5:3])
);

pll pll (
	.refclk ( CLK_50M   ),
	.rst(0),
	.locked 		( locked    ),        // PLL is running stable
	.outclk_0	( clk_48	),        // 48 MHz
	.outclk_1	( clk_12	)        // 12 MHz
	 );

assign clk_sys=clk_12;
/*
entity superbug is 
port(		
			Clk_50_I		: in	std_logic;	-- 50MHz input clock
			Reset_n		: in	std_logic;	-- Reset button (Active low)
			Video1_O		: out std_logic;  -- Video output 1 (1k Ohm)
			Video2_O		: out std_logic;  -- Video output 2 (680 Ohm)
			Sync_O		: out std_logic;  -- Composite sync output (1.2k)
			Audio_O		: out std_logic;  -- Ideally this should have a simple low pass filter
			Coin1_I		: in  std_logic;  -- Coin switches (Active low)
			Coin2_I		: in  std_logic;
			Start_I		: in  std_logic;  -- Start button
			Trak_Sel_I	: in  std_logic;  -- Track select button 
			Gas_I			: in  std_logic;	-- Gas pedal, this is a simple momentary switch
			Gear1_I		: in  std_logic;  -- Gear shifter, 4th gear = no other gear selected
			Gear2_I		: in  std_logic;
			Gear3_I		: in  std_logic;
			Steer_1A_I	: in  std_logic;	-- Steering wheel inputs, quadrature encoder
			Steer_1B_I	: in	std_logic;			
			Test_I		: in  std_logic;  -- Self-test switch
			Slam_I		: in  std_logic;  -- Slam switch
			HSRes_I		: in	std_logic;  -- High score reset
			Lamp1_O		: out std_logic;	-- Start button lamp
			Lamp2_O		: out std_logic 	-- Track Select lamp
			);
end superbug;
*/
	reg [7:0] sw[8];
	always @(posedge clk_sys) begin
		if (ioctl_wr && ioctl_index == 16'd254 && !ioctl_addr[24:3])
			sw[ioctl_addr[2:0]] <= ioctl_data;
	end
	wire [7:0] DIP_Sw = sw[0];

superbug superbug(
	.Clk_50_I(CLK_50M),
	.Clk12(clk_12),
	.Reset_n(~(RESET | status[0] | buttons[1] | ioctl_download)),

	.dn_addr(ioctl_addr[16:0]),
	.dn_data(ioctl_data),
	.dn_wr(ioctl_wr),
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
	.Test_I	(~status[8]),
	.Steer_1A_I(steer[1]),
	.Steer_1B_I(steer[0]),
	.Lamp1_O(lamp),
	.Lamp2_O(lamp2),
	.hs_O(hs),
	.vs_O(vs),
	.hblank_O(hblank),
	.vblank_O(vblank),
	.clk_6_O(clk_6),
	.DIP_Sw(DIP_Sw),
	.Slam_I(1'b1),
	// Active low, and it was left unconnected before, which synthesises to a
	// permanently asserted high-score reset.
	.HSRes_I(1'b1),
	.Trak_Sel_I(~m_next_track)


	);
			
endmodule
