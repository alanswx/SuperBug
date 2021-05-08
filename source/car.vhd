-- Car picture generator block for Atari/Kee Games Super Bug 
-- This generates the car sprite that rotates in the 
-- center of the screen.
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


entity car is 
port(		
			Clk6			: in		std_logic;
			Clk50			: in		std_logic;
			RW_n			: in		std_logic;
		   BD				: in		std_logic_vector(7 downto 0);
			BA				: in  	std_logic_vector(15 downto 0);
			HCount		: in		std_logic_vector(8 downto 0);
			VCount		: in  	std_logic_vector(7 downto 0);
			CarRot_n		: in		std_logic;
			CarVideo		: out		std_logic
			);
end car;

architecture rtl of car is

signal H1					: std_logic;
signal H2					: std_logic;
signal H4					: std_logic;
signal H8					: std_logic;
signal H16					: std_logic;
signal H32					: std_logic;
signal H64					: std_logic;
signal H128					: std_logic;
signal H128n					: std_logic;
signal H256					: std_logic;

signal V1					: std_logic;
signal V2					: std_logic;
signal V4					: std_logic;
signal V8					: std_logic;
signal V16					: std_logic;
signal V32					: std_logic;
signal V64					: std_logic;
signal V128					: std_logic;
signal V128n					: std_logic;

signal CarROM_Adr			: std_logic_vector(9 downto 0);
signal CarROM_Dout		: std_logic_vector(3 downto 0);
signal CarEna_n			: std_logic;
signal R1					: std_logic;
signal R0					: std_logic;

signal CV16					: std_logic;
signal CV8					: std_logic;
signal CV4					: std_logic;
signal CV2					: std_logic;
signal CV1					: std_logic;

signal CH16					: std_logic;
signal CH8					: std_logic;
signal CH4					: std_logic;
signal CH2					: std_logic;
signal CH1					: std_logic;

signal V16g					: std_logic;
signal V8g					: std_logic;
signal V4g					: std_logic;
signal V2g					: std_logic;
signal V1g					: std_logic;

signal H16g					: std_logic;
signal H8g					: std_logic;
signal H4g					: std_logic;
signal H2g					: std_logic;
signal H1g					: std_logic;

signal M7Qa					: std_logic;
signal M7Qb					: std_logic;

signal BD2_Sel				: std_logic;
signal BD3_Sel				: std_logic;
signal BD4_Sel				: std_logic;

signal R_Sel				: std_logic_vector(1 downto 0);

begin

H1 <= HCount(0); 
H2	<= HCount(1);		
H4 <= HCount(2);
H8 <= HCount(3);
H16 <= HCount(4);
H32 <= HCount(5);
H64 <= HCount(6);
H128 <= HCount(7);
H128n  <= not H128;
H256 <= HCount(8);

V1 <= VCount(0);
V2 <= VCount(1);
V4 <= VCount(2);
V8 <= VCount(3);
V16 <= VCount(4);
V32 <= VCount(5);
V64 <= VCount(6);
V128 <= VCount(7);
V128n <= not V128;


CarROM_Adr <= CV16 & CV8 & CV4 & CV2 & CV1 & CH16 & CH8 & CH4 & CH2 & CH1;


K6: entity work.K6_ROM
port map(
	clock => Clk50, 
	Address => CarROM_Adr,
	q => CarROM_Dout
	);


	
R_Sel <= (R1 & R0);
K7: process(CarROM_Dout, R_Sel, CarEna_n)
begin
	if CarEna_n = '0' then
		case R_Sel is
			when "00" =>
				CarVideo <= CarROM_Dout(0);
			when "01" =>
				CarVideo <= CarROM_Dout(1);
			when "10" =>
				CarVideo <= CarROM_Dout(2);
			when "11" =>
				CarVideo <= CarROM_Dout(3);
			when others =>
				CarVideo <= '0';
		end case;
	else
		CarVideo <= '0';
	end if;
end process;


--M7a: process(HCount)
M7a: process(H16)
begin
	if rising_edge(H16) then 
		-- Real hardware uses nand then Q_, same result 
		M7Qa <= H256 and H128n and H64 and H32; 
	end if;
end process;

--M7b: process(VCount)
M7b: process(V8)
begin
	if rising_edge(V8) then -- Clocked by 8H
		-- Real hardware uses nand then Q_, same result 
		M7Qb <= V128n and V64 and V32; 
	end if;
end process;
CarEna_n <= M7Qa nand M7Qb;

-- Latch at L4
L4: process(CarRot_n)
begin
	if rising_edge(CarRot_n) then
		R0 <= BD(0);
		R1 <= BD(1);
		BD2_Sel <= BD(2);
		BD3_Sel <= BD(3);
		BD4_Sel <= BD(4);
	end if;
end process;
	

-- Selectors at K5, L6 and J6
-- These swap H and V signals to flip the car image stored in ROM
CV16 <= H16g when BD4_Sel = '0' else V16g;
CH16 <= V16g when BD4_Sel = '0' else H16g;
CV8  <= H8g  when BD4_Sel = '0' else V8g;
CH8  <= V8g  when BD4_Sel = '0' else H8g;
CV4  <= H4g  when BD4_Sel = '0' else V4g;
CH4  <= V4g  when BD4_Sel = '0' else H4g;
CV2  <= H2g  when BD4_Sel = '0' else V2g;
CH2  <= V2g  when BD4_Sel = '0' else H2g;
CV1  <= H1g  when BD4_Sel = '0' else V1g;
CH1  <= V1g  when BD4_Sel = '0' else H1g;

-- Gated H and V signals from XOR gates in K4 and L5
V16g <= (BD3_Sel xor (V16 xor (not V8)));
V8g <= (BD3_Sel xor (not V8));
V4g <= (BD3_Sel xor V4);
V2g <= (BD3_Sel xor V2);
V1g <= (BD3_Sel xor V1);



H16g <= (BD2_Sel xor (not H16));
H8g <= (BD2_Sel xor H8);
H4g <= (BD2_Sel xor H4);
H2g <= (BD2_Sel xor H2);
H1g <= (BD2_Sel xor H1);


end rtl;
