-- Playfield generator for Atari/Kee Games Super Bug 
-- This generates the scrolling track
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



library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.all;


entity playfield is 
port(		
			Clk6			: in		std_logic;
			RW_n			: in		std_logic;
		   BD				: in		std_logic_vector(7 downto 0);
			BA				: in  	std_logic_vector(15 downto 0);
			HCount		: in		std_logic_vector(8 downto 0);
			Sys_En		: in 		std_logic;
			HSync			: in		std_logic;
			VBlank		: in		std_logic;
			ArrowOff_n	: in		std_logic;
			CarVideo		: in		std_logic;
			PVP_Load_n	: in		std_logic;
			PHP_Load_n	: in		std_logic;
			Crash_n		: out		std_logic;
			Skid_n		: out		std_logic;
			CrashIn_n : out		std_logic;
			SkidIn_n: out		std_logic;
			CrashReset_n: in		std_logic;
			SkidReset_n: in		std_logic;
			PfWndo		: buffer	std_logic;
			PCC1			: out 	std_logic;
			PCC2			: out		std_logic;
			Pfld			: buffer	std_logic
			);
end playfield;

architecture rtl of playfield is

signal H1					: std_logic;
signal H2					: std_logic;
signal H4					: std_logic;
signal H8					: std_logic;
signal H16					: std_logic;
signal H32					: std_logic;
signal H64					: std_logic;
signal H128					: std_logic;
signal H256					: std_logic;

--signal V1					: std_logic;
--signal V2					: std_logic;
--signal V4					: std_logic;
--signal V8					: std_logic;
--signal V16					: std_logic;
--signal V32					: std_logic;
--signal V64					: std_logic;
--signal V128					: std_logic;


signal PFROM_Adr		: std_logic_vector(9 downto 0);
signal E5_Dout			: std_logic_vector(3 downto 0);
signal F5_Dout			: std_logic_vector(3 downto 0);
signal H5_Dout			: std_logic_vector(3 downto 0);
signal Vid				: std_logic_vector(3 downto 0);

signal PD				: std_logic_vector(7 downto 0);
signal PVP				: std_logic_vector(7 downto 0);
signal PHP				: std_logic_vector(7 downto 0);

signal PF_RAM_Adr		: std_logic_vector(7 downto 0);
signal PFRAM_Din		: std_logic_vector(7 downto 0);
signal PF_Wren			: std_logic;
signal PF_RAMce_n		: std_logic;
signal PfldRAM			: std_logic;


signal BD_en			: std_logic;
signal PD_en			: std_logic;
signal RnW				: std_logic;


signal CrashCode		: std_logic; 
signal SkidCode_n		: std_logic;
signal CrashSkid		: std_logic;
signal CrashArrow		: std_logic;
signal PfCarVid		: std_logic;

signal Arrow_n			: std_logic;

signal VidShift 		: std_logic_vector(3 downto 0);
signal LoadPd			: std_logic;

signal PfWndo_n		: std_logic;
signal Window_en		: std_logic;
signal Pf				: std_logic;
signal PHP_load_value	: std_logic_vector(7 downto 0) := (others => '0');
signal PVP_load_value	: std_logic_vector(7 downto 0) := (others => '0');
signal prev_VBlank_php	: std_logic := '0';
signal prev_VBlank_pvp	: std_logic := '0';
signal prev_HSync_pvp	: std_logic := '0';
signal prev_VBlank_arrow: std_logic := '0';
signal prev_H8_pfwndo	: std_logic := '0';


begin

H1 <= HCount(0); 
H2	<= HCount(1);		
H4 <= HCount(2);
H8 <= HCount(3);
H16 <= HCount(4);
H32 <= HCount(5);
H64 <= HCount(6);
H128 <= HCount(7);
H256 <= HCount(8);

--V1 <= VCount(0);
--V2 <= VCount(1);
--V4 <= VCount(2);
--V8 <= VCount(3);
--V16 <= VCount(4);
--V32 <= VCount(5);
--V64 <= VCount(6);
--V128 <= VCount(7);




RnW <= (not RW_n);


PFROM_Adr <= PD(3 downto 0) & PVP(3 downto 0) & PHP(3 downto 2);

-- Playfield ROM
E5: entity work.ROM_E5
port map(
	clock => Clk6,
	address => PFROM_Adr,
	q => E5_Dout
	);


F5: entity work.ROM_F5
port map(
	clock => Clk6,
	address => PFROM_Adr,
	q => F5_Dout
	);


H5: entity work.ROM_H5
port map(
	clock => Clk6,
	address => PFROM_Adr,
	q => H5_Dout
	);

	
-- CE lines are labeled strangely on schematic.
-- Per MAME's tiles ROM region layout (F5 at $000, H5 at $400, E5 at
-- $800/$C00) the mapping is 00->F5, 01->H5, 10->E5, 11->E5. The
-- original VHDL had 01 and 10 swapped so half the playfield codes
-- pulled the wrong tile ROM.
PF_ROM_mux: process(PD, E5_Dout, F5_Dout, H5_Dout)
begin
   Vid <= (others => '0');
   case PD(5 downto 4) is
		when "00" => Vid <= F5_Dout;
		when "01" => Vid <= H5_Dout;
      when "10" => Vid <= E5_Dout;
      when "11" => Vid <= E5_Dout;
      when others => null;
   end case;
end process;
	
	

--Playfield RAM
E6: entity work.ram256
port map(
	clock => Clk6,
	address => PF_RAM_Adr,
	wren => PF_Wren,
	data => PFRAM_Din(3 downto 0),
	q => PD(3 downto 0)
	);



F6: entity work.ram256
port map(
	clock => Clk6,
	address => PF_RAM_Adr,
	wren => PF_Wren,
	data => PFRAM_Din(7 downto 4),
	q => PD(7 downto 4)
	);
	
-- Allow writes whenever the CPU is in the playfield RAM range. The
-- simulated CPU is too slow for every playfield write to land in VBlank.
PfldRAM <= (Sys_En and BA(10) and BA(8));
PF_Wren <= (RnW and Sys_En and PfldRAM);
PF_RAMce_n <= ((not VBlank) nor PfldRAM);
	
BD_en <= not(PfldRAM and RnW);	

PF_RAM_Adr <= BA(7 downto 0) when PfldRAM = '1' else
              PVP(7 downto 4) & PHP(7 downto 4);

-- Check data bus paths carefully
PFRAM_Din <= BD when BD_en = '0' else (others => '1'); 

-- B7 LS109
--B7_CRASH: entity work.JK_FF_VHDL 
--port map( 
--	Clock=>Clk6,
--	J=>'0',
--	K=>Crash_n,
--	Reset=>'0',
--	Clock_enable=>CrashReset_n,
--	Output=>CrashIn_n
--    );
--B7_SKID: entity work.JK_FF_VHDL 
--port map( 
--	Clock=>Clk6,
--	J=>'0',
--	K=>Skid_n,
--	Reset=>'0',
--	Clock_enable=>SkidReset_n,
--	Output=>SkidIn_n
--    );




Crash_n <= (CrashCode nand PfCarVid);
PfCarVid <= (Pfld and CarVideo);
Skid_n <= (PfCarVid nand (CrashCode nor SkidCode_n));

-- 74191 counters at C5 and E8. Latch simulated CPU writes and apply the
-- frame-level scroll value at the end of VBlank. Bias PHP to the rotated
-- output origin so partially-written playfield rows enter from the top
-- like the MAME reference capture.
PHP_count: process(Clk6)
begin
	if rising_edge(Clk6) then
		prev_VBlank_php <= VBlank;
		if PHP_Load_n = '0' then
			PHP_load_value <= BD;
		end if;

		if prev_VBlank_php = '1' and VBlank = '0' then
			PHP <= PHP_load_value + "00010000";
		elsif H256 = '1' and VBlank = '0' then
			PHP <= PHP + 1;
		end if;
	end if;
end process;

-- 74191 counters at D5 and F8. Model the HSync edge on Clk6 so this
-- module stays in one simulation clock domain.
PVP_count: process(Clk6)
begin
	if rising_edge(Clk6) then
		prev_HSync_pvp <= HSync;
		prev_VBlank_pvp <= VBlank;
		if PVP_Load_n = '0' then
			PVP_load_value <= BD;
		end if;

		if prev_VBlank_pvp = '1' and VBlank = '0' then
			PVP <= PVP_load_value;
		elsif HSync = '1' and prev_HSync_pvp = '0' and VBlank = '0' then
			PVP <= PVP + 1;
		end if;
	end if;
end process;

--N9 and L10
CrashSkid <= ((not CrashCode) and SkidCode_n);

--L9
ArrowLatch: process(Clk6)
begin
	if rising_edge(Clk6) then
		prev_VBlank_arrow <= VBlank;
		if ArrowOff_n = '0' then
			Arrow_n <= '1';
		elsif VBlank = '1' and prev_VBlank_arrow = '0' then
			Arrow_n <= '0';
		end if;
	end if;
end process;

--M9		
CrashArrow <= (Arrow_n nand CrashSkid);


--N9
Pfld <= CrashArrow and PF;

-- 74LS95 shift register uses falling edge of Clk6_n, using rising edge of Clk6 
-- accomplishes the same thing
A5: process(Clk6, LoadPd)
begin	
	if rising_edge(Clk6) then
		if LoadPd = '1' then
			VidShift <= Vid;
		else
			VidShift <= '0' & VidShift(3 downto 1);
		end if;
	end if;
end process;
Pf <= (VidShift(0) nor PfWndo_n);
LoadPd <= (PHP(0) and PHP(1));

--L9
-- Real hardware clocks this on H8 with VBlank as an async clear. Model the
-- H8 edge on Clk6 to avoid simulator multi-edge scheduling races.
WindowLatch: process(Clk6)
begin
	if rising_edge(Clk6) then
		prev_H8_pfwndo <= H8;
		if VBlank = '1' then
			PfWndo <= '0';
			PfWndo_n <= '1';
		elsif H8 = '1' and prev_H8_pfwndo = '0' then
			PfWndo <= Window_en;
			PFWndo_n <= (not Window_en);
		end if;
	end if;
end process;

Window_en <= H256 and (not (H128 and H64 and H32 and H16));
	

-- Avoid the four-pixel color/code lag from the hardware latch in this
-- tilemap-style renderer by driving these from the current RAM byte.
PCC2 <= PD(7);
PCC1 <= PD(6);
CrashCode <= PD(4);
SkidCode_n <= PD(3);
		
		

	
end rtl;
