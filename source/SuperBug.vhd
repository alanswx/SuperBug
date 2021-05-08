-- Top level file for Atari/Kee Games Super Bug 
-- (c) 2018 James Sweet
--
-- This is free software: you can redistribute
-- it and/or modify it under the terms of the GNU General
-- Public License as published by the Free Software
-- Foundation, either version 3 of the License, or (at your
-- option) any later version.
--
-- This is distributed in the hope that it will
-- be useful, but WITHOUT ANY WARRANTY; without even the
-- implied warranty of MERCHANTABILITY or FITNESS FOR A
-- PARTICULAR PURPOSE. See the GNU General Public License
-- for more details.

-- Targeted to EP2C5T144C8 mini board but porting to nearly any FPGA should be fairly simple
-- See Super Bug manual for video output details. Resistor values listed here have been scaled 
-- for 3.3V logic. 
-- R58 1k Ohm
-- R59 680R 
-- R60 1k Ohm

library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.all;


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
			Lamp2_O		: out std_logic; 	-- Track Select lamp
			hs_O: out std_logic;
			vs_O: out std_logic;
			hblank_O: out std_logic;
			vblank_O: out std_logic;
			Clk12: in std_logic;
			clk_6_O: out std_logic;
			DIP_Sw	: in std_logic_vector(7 downto 0);
			-- signals that carry the ROM data from the MiSTer disk
			dn_addr        : in  std_logic_vector(15 downto 0);
			dn_data        : in  std_logic_vector(7 downto 0);
			dn_wr          : in  std_logic
		
			);
end superbug;

architecture rtl of superbug is

--signal Clk12			: std_logic;
signal Clk6				: std_logic;
--signal Clk6_n			: std_logic; -- ajs unused
signal Phi2				: std_logic ;
signal HCount			: std_logic_vector(8 downto 0);
signal VCount			: std_logic_vector(7 downto 0); 
signal HSync			: std_logic;
signal VSync			: std_logic;
signal HBlank			: std_logic;
signal HBlank_n		: std_logic;
signal VBlank			: std_logic;
signal VBlank_n		: std_logic;
signal VReset			: std_logic;
signal PCC1				: std_logic;
signal PCC2				: std_logic;
signal PFWndo			: std_logic;
signal Flash 			: std_logic;
signal Pfld				: std_logic;
signal CarVideo		: std_logic;
signal A_NVideo		: std_logic;
signal Crash_n			: std_logic;
signal Skid_n			: std_logic;
signal PVP_Load_n 	: std_logic;
signal PHP_Load_n    : std_logic;

signal ArrowOff_n		: std_logic;

signal CarRot_n		: std_logic;

signal CPU_Adr			: std_logic_vector(15 downto 0);
signal CPU_Din			: std_logic_vector(7 downto 0);
signal CPU_Dout		: std_logic_vector(7 downto 0);

signal RW_n				: std_logic;
signal VMA				: std_logic;
signal BVMA				: std_logic;
--signal R_Wn				: std_logic;
signal Sys_en			: std_logic;

signal In1_n 			: std_logic;
signal Opt_n			: std_logic;
signal CrashIn_n		: std_logic;
signal SkidIn_n		: std_logic;

signal Attract			: std_logic;
Signal SteerReset_n	: std_logic;
Signal CrashReset_n     : std_logic;
Signal SkidReset_n      : std_logic;
signal MotorSnd_n		: std_logic;
signal CrashSnd_n		: std_logic;
signal SkidSnd_n		: std_logic;



--signal DIP_Sw			: std_logic_vector(7 downto 0);


begin


-- Configuration DIP switches, these can be brought out to external switches if desired
-- See Super Bug manual pg.6 for complete information. Active low (0 = On, 1 = Off)
--    8 	7							Game Cost			(10-1 Coin/1 Play, 11-Two Coins/1 Play, 01-Two Plays/1 Coin, 00-Free Play)
--				6	5					Game Length   		(00- 60 sec, 01- 90 sec, 10- 120 sec ,11- 150 sec)
--   					4	3			Extended Play		(00-None, 01-Liberal, 10-Medium, 11-Conservative
--								2	1	Language				(00-English, 01-French, 10-Spanish, 11-German)
--										
--DIP_Sw <= "10100000"; -- Config dip switches

-- PLL to generate 12.09 MHz clock
--PLL: entity work.clk_pll
--port map(
--		inclk0 => Clk_50_I,
--		c0 => clk12
--		);
		
		
Vid_sync: entity work.synchronizer
port map(
		clk_12 => clk12,
		clk_6	=> clk6,
		hcount => hcount,
		vcount => vcount,
		hsync => hsync,
		hblank => hblank,
		vblank => vblank,
		vsync => vsync,
		vreset => vreset
		);

		
CPU: entity work.cpu_mem
port map(
		Clk6 => Clk6,
		Reset_n => Reset_n,
		VBlank => VBlank,
		HBlank => HBlank,
		VCount => VCount,
		HCount=> HCount,
		RW_n => RW_n,
		VMA => VMA,
		PHI2 => Phi2,
		StartLamp => Lamp1_O,
		TrakSelLamp => Lamp2_O,
		Attract => Attract,
		Flash => Flash,
		In1_n => In1_n,
		Opt_n	=> Opt_n,
		PHP_Load_n => PHP_Load_n,
		PVP_Load_n => PVP_Load_n,
		CarRot_n => CarRot_n,
		ArrowOff_n => ArrowOff_n,
		CrashReset_n=>CrashReset_n,
		SkidReset_n=>SkidReset_n,
		SteerReset_n => SteerReset_n,
		MotorSnd_n => MotorSnd_n,
		CrashSnd_n => CrashSnd_n,
		SkidSnd_n => SkidSnd_n,
		Adr => CPU_Adr,
		DBus_in => CPU_Din,
		DBus_out => CPU_Dout	
		);
		
		
		
		
		
Vid_mixer: entity work.mixer
port map(
		Clk6 => Clk6,
		HSync => HSync,
		VSync => VSync,
		HBlank_n => HBlank_n,
		VBlank_n => VBlank_n,
		PCC1 => PCC1,
		PCC2 => PCC2,
		PFWndo => PFWndo,
		Flash => Flash,
		Pfld => Pfld,
		CarVideo => CarVideo,
		A_NVideo => A_NVideo,
		CSync => Sync_O,
		Video1 => Video1_O,
		Video2 => Video2_O
		);
		

Alpha: entity work.alpha_numerics
port map(
		Clk6 => Clk6,
		Phi2 => Phi2,
		RW_n => RW_n,
		BD => CPU_Dout,
		BA => CPU_Adr,
		HCount => HCount,
		VCount => VCount,
		HBlank_n => HBlank_n,
		VBlank => VBlank,
		VMA => VMA,
		BVMA => BVMA,
		Sys_en => Sys_en,
		A_NVideo => A_NVideo
		);

Car: entity work.car
port map(
		Clk6 => Clk6,
		Clk50 => Clk_50_I,
		RW_n => RW_n,
		BD => CPU_Dout,
		BA => CPU_Adr,
		HCount => HCount,
		VCount => VCount,
		CarRot_n => CarRot_n,
		CarVideo => CarVideo
		);

		-- AJS put this back in (playfield)
Playfield: entity work.playfield
port map(
		Clk6 => Clk6,
		RW_n => RW_n,
		BD => CPU_Dout,
		BA => CPU_Adr,
		HCount => HCount,
		Sys_En => Sys_En,
		HSync => HSync,
		VBlank => VBlank,
		ArrowOff_n => ArrowOff_n,
		CarVideo => CarVideo,
		PVP_Load_n => PVP_Load_n,
		PHP_Load_n => PHP_Load_n,
		Crash_n => Crash_n,
		Skid_n => Skid_n,
		CrashIn_n => CrashIn_n,
		SkidIn_n => SkidIn_n,
		CrashReset_n=>CrashReset_n,
		SkidReset_n=>SkidReset_n,
		PfWndo => PFWndo,
		PCC1 => PCC1,
		PCC2 => PCC2,
		Pfld => Pfld
		);
		
ControlInputs: entity work.input
port map(		
		DIP_Sw => DIP_Sw,
		Coin1_n => Coin1_I,
		Coin2_n => Coin2_I,
		Start_n => Start_I,
		TrackSel_n => Trak_Sel_I,
		Gas_n => Gas_I,
		Gear1_n => Gear1_I,
		Gear2_n => Gear2_I,
		Gear3_n => Gear3_I,
		Test_n => Test_I,
		HScoreRes_n => HSRes_I,
		Slam_n => Slam_I,
		Steering1A_n => Steer_1A_I,
		Steering1B_n => Steer_1B_I,
		SteerReset_n => SteerReset_n,
		In1_n => In1_n,
		Opt_n => Opt_n,
		SkidIn_n => SkidIn_n,
		CrashIn_n => CrashIn_n,
		Adr => CPU_Adr(2 downto 0),
		DBus => CPU_Din
		);
		
--Sound: entity work.sound
		
HBlank_n <= (not HBlank);
VBlank_n <= (not VBlank);


hs_O<= hsync;
hblank_O <= HBlank;
vblank_O <= VBlank;
vs_O <=vsync;
clk_6_O<=Clk6;
end rtl;
