-- Video mixer for Atari/Kee Games Super Bug 
-- This combines the various video signals from the playfield, car generator and sync
-- circuits into a composite video signal.
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


entity mixer is 
port(		
			Clk6			: in	std_logic;
		   HSync			: in	std_logic;
			VSync			: in	std_logic;
			HBlank_n		: in 	std_logic;
			VBlank_n		: in	std_logic;
			PCC1			: in 	std_logic;
			PCC2			: in	std_logic;
			PFWndo		: in	std_logic; -- Playfield Window
			Flash			: in	std_logic; 
			Pfld			: in	std_logic; -- Playfield video
			CarVideo		: in	std_logic; -- Player car video 
			A_NVideo		: in	std_logic; -- Alpha-Numerics video
			CSync			: out std_logic;
			Video1		: out std_logic;
			Video2		: out std_logic
			);
end mixer;

architecture rtl of mixer is

signal CompSync 		: std_logic;
signal CompBlank		: std_logic;

signal FlashWndo		: std_logic;
signal PCC1Pfld		: std_logic;
signal PCC2Pfld		: std_logic;
signal CarPfld1 		: std_logic;
signal CarPfld2		: std_logic;
signal CarPfWndo1		: std_logic;
signal CarPfWndo2		: std_logic;
signal CarPfAN1		: std_logic;
signal CarPfAN2		: std_logic;
signal CompVid1   	: std_logic;
signal CompVid2		: std_logic;
signal VideoLatch		: std_logic_vector(2 downto 0);

begin

--K8
CompSync <= (HSync nor VSync);
--L8
CompBlank <= (HBlank_n nand VBlank_n);
--B9
FlashWndo <= (PFWndo nand Flash);
--H8
PCC1Pfld <= (PCC1 and Pfld);
PCC2Pfld <= (PCC2 and Pfld);
--J8(1)
CarPfld1 <= (CarVideo nor PCC1Pfld);
CarPfld2 <= (CarVideo nor PCC2Pfld);
--J9
CarPfWndo1 <= (CarPfld1 xor FlashWndo);
CarPFWndo2 <= (CarPfld2 xor FlashWndo);
--J8(2)
CarPfAN1 <= (CarPfWndo1 nor A_NVideo);
CarPfAN2 <= (CarPfWndo2 nor A_NVideo);
--K8
CompVid1 <= (CarPfAN1 nor CompBlank);
CompVid2 <= (CarPfAN2 nor CompBlank);

--74LS175 DFF registers video output signals to 6MHz clock
K9: process(Clk6, CompSync, CompVid1, CompVid2)
begin
	if rising_edge(Clk6) then
		VideoLatch <= (CompVid1 & CompVid2 & CompSync);
	end if;
end process;
Video1 <= VideoLatch(2);
Video2 <= VideoLatch(1);
CSync <= VideoLatch(0);

end rtl;