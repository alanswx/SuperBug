// Top level file for Atari/Kee Games Super Bug 
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

// Targeted to EP2C5T144C8 mini board but porting to nearly any FPGA should be fairly simple
// See Super Bug manual for video output details. Resistor values listed here have been scaled 
// for 3.3V logic. 
// R58 1k Ohm
// R59 680R 
// R60 1k Ohm

module superbug(
    Clk_50_I,
    Reset_n,
    Video1_O,
    Video2_O,
    Sync_O,
    Audio_O,
    Coin1_I,
    Coin2_I,
    Start_I,
    Trak_Sel_I,
    Gas_I,
    Gear1_I,
    Gear2_I,
    Gear3_I,
    Steer_1A_I,
    Steer_1B_I,
    Test_I,
    Slam_I,
    HSRes_I,
    Lamp1_O,
    Lamp2_O,
    hs_O,
    vs_O,
    hblank_O,
    vblank_O,
    Clk12,
    clk_6_O,
    DIP_Sw,
    dn_addr,
    dn_data,
    dn_wr
);
    input        Clk_50_I;		// 50MHz input clock
    input        Reset_n;		// Reset button (Active low)
    output       Video1_O;		// Video output 1 (1k Ohm)
    output       Video2_O;		// Video output 2 (680 Ohm)
    output       Sync_O;		// Composite sync output (1.2k)
    output       Audio_O;		// Ideally this should have a simple low pass filter
    input        Coin1_I;		// Coin switches (Active low)
    input        Coin2_I;
    input        Start_I;		// Start button
    input        Trak_Sel_I;		// Track select button 
    input        Gas_I;		// Gas pedal, this is a simple momentary switch
    input        Gear1_I;		// Gear shifter, 4th gear = no other gear selected
    input        Gear2_I;
    input        Gear3_I;
    input        Steer_1A_I;		// Steering wheel inputs, quadrature encoder
    input        Steer_1B_I;
    input        Test_I;		// Self-test switch
    input        Slam_I;		// Slam switch
    input        HSRes_I;		// High score reset
    output       Lamp1_O;		// Start button lamp
    output       Lamp2_O;		// Track Select lamp
    output       hs_O;
    output       vs_O;
    output       hblank_O;
    output       vblank_O;
    input        Clk12;
    output       clk_6_O;
    input [7:0]  DIP_Sw;
    // signals that carry the ROM data from the MiSTer disk
    input [15:0] dn_addr;
    input [7:0]  dn_data;
    input        dn_wr;
    
    
    //signal Clk12			: std_logic;
    wire         Clk6;
    //signal Clk6_n			: std_logic; -- ajs unused
    wire         Phi2;
    wire [8:0]   HCount;
    wire [7:0]   VCount;
    wire         HSync;
    wire         VSync;
    wire         HBlank;
    wire         HBlank_n;
    wire         VBlank;
    wire         VBlank_n;
    wire         VReset;
    wire         PCC1;
    wire         PCC2;
    wire         PFWndo;
    wire         Flash;
    wire         Pfld;
    wire         CarVideo;
    wire         A_NVideo;
    wire         Crash_n;
    wire         Skid_n;
    wire         PVP_Load_n;
    wire         PHP_Load_n;
    
    wire         ArrowOff_n;
    
    wire         CarRot_n;
    
    wire [15:0]  CPU_Adr;
    wire [7:0]   CPU_Din;
    wire [7:0]   CPU_Dout;
    
    wire         RW_n;
    wire         VMA;
    wire         BVMA;
    //signal R_Wn				: std_logic;
    wire         Sys_en;
    
    wire         In1_n;
    wire         Opt_n;
    wire         CrashIn_n;
    wire         SkidIn_n;
    
    wire         Attract;
    wire         SteerReset_n;
    wire         CrashReset_n;
    wire         SkidReset_n;
    wire         MotorSnd_n;
    wire         CrashSnd_n;
    wire         SkidSnd_n;
    
    //signal DIP_Sw			: std_logic_vector(7 downto 0);
    
    // Configuration DIP switches, these can be brought out to external switches if desired
    // See Super Bug manual pg.6 for complete information. Active low (0 = On, 1 = Off)
    //    8 	7							Game Cost			(10-1 Coin/1 Play, 11-Two Coins/1 Play, 01-Two Plays/1 Coin, 00-Free Play)
    //				6	5					Game Length   		(00- 60 sec, 01- 90 sec, 10- 120 sec ,11- 150 sec)
    //   					4	3			Extended Play		(00-None, 01-Liberal, 10-Medium, 11-Conservative
    //								2	1	Language				(00-English, 01-French, 10-Spanish, 11-German)
    //										
    //DIP_Sw <= "10100000"; -- Config dip switches
    
    synchronizer Vid_sync(
        .clk_12(Clk12),
        .clk_6(Clk6),
        .hcount(HCount),
        .vcount(VCount),
        .hsync(HSync),
        .hblank(HBlank),
        .vblank(VBlank),
        .vsync(VSync),
        .vreset(VReset)
    );
    
    cpu_mem CPU(
        .Clk6(Clk6),
        .Reset_n(Reset_n),
        .VBlank(VBlank),
        .HBlank(HBlank),
        .VCount(VCount),
        .HCount(HCount),
        .RW_n(RW_n),
        .VMA(VMA),
        .PHI2(Phi2),
        .StartLamp(Lamp1_O),
        .TrakSelLamp(Lamp2_O),
        .Attract(Attract),
        .Flash(Flash),
        .In1_n(In1_n),
        .Opt_n(Opt_n),
        .PHP_Load_n(PHP_Load_n),
        .PVP_Load_n(PVP_Load_n),
        .CarRot_n(CarRot_n),
        .ArrowOff_n(ArrowOff_n),
        .CrashReset_n(CrashReset_n),
        .SkidReset_n(SkidReset_n),
        .SteerReset_n(SteerReset_n),
        .MotorSnd_n(MotorSnd_n),
        .CrashSnd_n(CrashSnd_n),
        .SkidSnd_n(SkidSnd_n),
        .Adr(CPU_Adr),
        .DBus_in(CPU_Din),
        .DBus_out(CPU_Dout)
    );
    
    
    mixer Vid_mixer(
        .Clk6(Clk6),
        .HSync(HSync),
        .VSync(VSync),
        .HBlank_n(HBlank_n),
        .VBlank_n(VBlank_n),
        .PCC1(PCC1),
        .PCC2(PCC2),
        .PFWndo(PFWndo),
        .Flash(Flash),
        .Pfld(Pfld),
        .CarVideo(CarVideo),
        .A_NVideo(A_NVideo),
        .CSync(Sync_O),
        .Video1(Video1_O),
        .Video2(Video2_O)
    );
    
 
    alpha_numerics Alpha(
        .Clk6(Clk6),
        .Phi2(Phi2),
        .RW_n(RW_n),
        .BD(CPU_Dout),
        .BA(CPU_Adr),
        .HCount(HCount),
        .VCount(VCount),
        .HBlank_n(HBlank_n),
        .VBlank(VBlank),
        .VMA(VMA),
        .BVMA(BVMA),
        .Sys_en(Sys_en),
        .A_NVideo(A_NVideo)
    );
    
    
    car Car(
        .Clk6(Clk6),
        .Clk50(Clk_50_I),
        .RW_n(RW_n),
        .BD(CPU_Dout),
        .BA(CPU_Adr),
        .HCount(HCount),
        .VCount(VCount),
        .CarRot_n(CarRot_n),
        .CarVideo(CarVideo)
    );
    
    // AJS put this back in (playfield)
    playfield Playfield(
        .Clk6(Clk6),
        .RW_n(RW_n),
        .BD(CPU_Dout),
        .BA(CPU_Adr),
        .HCount(HCount),
        .Sys_En(Sys_en),
        .HSync(HSync),
        .VBlank(VBlank),
        .ArrowOff_n(ArrowOff_n),
        .CarVideo(CarVideo),
        .PVP_Load_n(PVP_Load_n),
        .PHP_Load_n(PHP_Load_n),
        .Crash_n(Crash_n),
        .Skid_n(Skid_n),
        .CrashIn_n(CrashIn_n),
        .SkidIn_n(SkidIn_n),
        .CrashReset_n(CrashReset_n),
        .SkidReset_n(SkidReset_n),
        .PfWndo(PFWndo),
        .PCC1(PCC1),
        .PCC2(PCC2),
        .Pfld(Pfld)
    );
    
    
    Input ControlInputs(
        .DIP_Sw(DIP_Sw),
        .Coin1_n(Coin1_I),
        .Coin2_n(Coin2_I),
        .Start_n(Start_I),
        .TrackSel_n(Trak_Sel_I),
        .Gas_n(Gas_I),
        .Gear1_n(Gear1_I),
        .Gear2_n(Gear2_I),
        .Gear3_n(Gear3_I),
        .Test_n(Test_I),
        .HScoreRes_n(HSRes_I),
        .Slam_n(Slam_I),
        .Steering1A_n(Steer_1A_I),
        .Steering1B_n(Steer_1B_I),
        .SteerReset_n(SteerReset_n),
        .In1_n(In1_n),
        .Opt_n(Opt_n),
        .SkidIn_n(SkidIn_n),
        .CrashIn_n(CrashIn_n),
        .Adr(CPU_Adr[2:0]),
        .DBus(CPU_Din)
    );
    
    //Sound: entity work.sound
    
    assign HBlank_n = ((~HBlank));
    assign VBlank_n = ((~VBlank));
    
    assign hs_O = HSync;
    assign hblank_O = HBlank;
    assign vblank_O = VBlank;
    assign vs_O = VSync;
    assign clk_6_O = Clk6;
    
endmodule
