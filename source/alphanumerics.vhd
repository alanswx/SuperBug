-- Alpha-Numerics block for Atari/Kee Games Super Bug 
-- This generates all alpha-numeric characters
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


entity alpha_numerics is 
port(		
			Clk6			: in		std_logic;
			Phi2			: in		std_logic;
			RW_n			: in		std_logic;
		   BD				: in		std_logic_vector(7 downto 0);
			BA				: in  	std_logic_vector(15 downto 0);
			HCount		: in		std_logic_vector(8 downto 0);
			VCount		: in  	std_logic_vector(7 downto 0);
			HBlank_n		: in		std_logic;
			VBlank		: in		std_logic;
			VMA			: in		std_logic;
			BVMA			: buffer std_logic;
			Sys_en		: buffer std_logic;
			A_NVideo		: out		std_logic
			);
end alpha_numerics;

architecture rtl of alpha_numerics is

--signal H4				: std_logic;
--signal H8				: std_logic;
--
--signal V1				: std_logic;
--signal V2				: std_logic;
--signal V4				: std_logic;
--signal V8				: std_logic;
--signal V16				: std_logic;
--signal V32				: std_logic;
--signal V64				: std_logic;
--signal V128				: std_logic;
--
signal H256_n			: std_logic;

signal RAM_Addr		: std_logic_vector(6 downto 0);
signal RAM_Dout2		: std_logic_vector(7 downto 0);
signal RAM_Dout		: std_logic_vector(7 downto 0);
signal RAM_we			: std_logic;

signal Mux_select		: std_logic;

signal BA10and8		: std_logic;
signal BA12nor11		: std_logic;

signal SysEnBA10_8    : std_logic;

signal RAMcs_n			: std_logic;


signal M3_Dout			: std_logic_vector(3 downto 0);
signal N3_Dout			: std_logic_vector(3 downto 0);
signal AlphaROM_Dout	: std_logic_vector(3 downto 0);

signal ShiftLoad  	: std_logic;
signal ShiftData		: std_logic_vector(3 downto 0);

signal AN_Blank		: std_logic;
signal rom_m3_addr : std_logic_vector(9 downto 0);
signal rom_n3_addr : std_logic_vector(9 downto 0);

begin

--H4 <= HCount(2);
--H8 <= HCount(3);
-- H16 <= HCount(4);
-- H32 <= HCount(5);
-- H64 6
-- H128 7
-- H256 8

--V1 <= VCount(0);
--V2 <= VCount(1);
--V4 <= VCount(2);
--V8 <= VCount(3);
--V16 <= VCount(4);
--V32 <= VCount(5);
--V64 <= VCount(6);
--V128 <= VCount(7);

H256_n <= (not HCount(8));

--BA10and8 <= (BA(10) and BA(8));
BA10and8 <= BA(10) and not BA(8);
BA12nor11 <= BA(12) nor BA(11);
Sys_en <= (BVMA and BA12nor11 and Phi2);
BVMA <= VMA; --((not BA(14)) and VMA);



--Mux_select <= not(BA10and8 and BA12nor11 and BVMA);
--Mux_select <= not(BA10and8 and BA12nor11 and VMA);
Mux_select <= '0' when BVMA = '1' and BA(12 downto 10) = "001" and BA(8) = '1' else '1';




SysEnBA10_8 <= (Sys_en nand BA10and8);

RAMcs_n <= (SysEnBA10_8 and VBlank);
--RAMcs_n <= '0' when VBlank = '0' or (BA(10) and BA(8) and Sys_en) = '1' else '1';
--RAMcs_n <= '0' when VBlank = '1' or (BA(10)='1' and BA(8)='1'  and Sys_en='1') else '1'; -- AJS

-- Altera block RAM has active-high write-enable
RAM_we <= '1' when RAMcs_n = '0' and RW_n = '0' and Mux_select = '1' else '0';



-- Selectors at P2 and P4
RAM_Addr <= "00" & HCount(5) & VCount(7 downto 4) when Mux_select = '0' else
				"00" & BA(4 downto 0);				
				
-- Alphanumeric character RAM
-- Real hardware has 128 byte RAM but it seems only 32 bytes are used				
P3_RAM: entity work.ram128
port map(
	clock => clk6,
	address => RAM_Addr,
	wren => RAM_we,
	data => BD,
	q => RAM_Dout
	);

--RAM_Dout<="00001000";

rom_m3_addr <= RAM_Dout(3 downto 0) & VCount(3 downto 0) & HCount(3 downto 2);
M3_ROM: entity work.ROM_M3
port map(
	clock => Clk6,
	address => rom_m3_addr,
	q => M3_dout
	);

rom_n3_addr <= RAM_Dout(3 downto 0) & VCount(3 downto 0) & HCount(3 downto 2);
N3_ROM: entity work.ROM_N3
port map(
	clock => Clk6,
	address => rom_n3_addr,
	q => N3_Dout
	);

-- Alphanumeric ROMs are selected by RAM_Dout(4)
AlphaROM_Dout <= M3_dout when RAM_Dout(4) = '0' else N3_Dout;

ShiftLoad <= (HCount(0) and HCount(1));

-- Real hardware 74LS95 uses falling edge of Clk6_n, this is the same as rising edge of Clk6
L3: process(Clk6, ShiftLoad, AlphaROM_Dout)
begin
	if rising_edge(Clk6) then
		if ShiftLoad = '1' then 
			ShiftData <= AlphaROM_Dout;
		else
			ShiftData <= ShiftData(2 downto 0) & '0';
		end if;
	end if;
end process;
-- Alphanumeric data is shifted out on ShiftData(3)
A_NVideo <= (ShiftData(3) and H256_n and AN_Blank);

AN_Blank <= (HBlank_n and (HCount(3) xor HCount(4)));


end rtl;
