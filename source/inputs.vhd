-- Switch and steering input circuitry for Atari Super Bug
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

entity input is 
port(		
			DIP_Sw			: in  std_logic_vector(7 downto 0); -- DIP switches
			Coin1_n			: in  std_logic; -- Coin switches
			Coin2_n			: in 	std_logic;
			Start_n			: in	std_logic; -- Start switch
			TrackSel_n		: in	std_logic; -- Track Select switch
			Gas_n				: in	std_logic;
			Gear1_n			: in	std_logic;
			Gear2_n			: in	std_logic;
			Gear3_n			: in	std_logic;
			Test_n			: in	std_logic; -- Self test switch
			HScoreRes_n		: in	std_logic; -- High score reset switch
			Slam_n			: in  std_logic; -- Slam switch
			Steering1A_n	: in  std_logic; -- Steering wheel signals
			Steering1B_n	: in  std_logic;
			SteerReset_n	: in	std_logic;
			In1_n				: in	std_logic;
			Opt_n				: in	std_logic;
			SkidIn_n			: in	std_logic;
			CrashIn_n		: in  std_logic;
			Adr				: in  std_logic_vector(2 downto 0); -- Adress bus, only the lower 3 bits used by IO circuitry
			DBus				: out std_logic_vector(7 downto 0)  -- Out to data bus, only bits 7, 1, and 0 are actually used
			);
end input;

architecture rtl of input is		


signal Coin1			: std_logic;
signal Coin2			: std_logic;

signal SteerDir		: std_logic;
signal SteerFlag		: std_logic;
signal Steering1A : std_logic;

signal InputMux1			: std_logic;
signal InputMux2			: std_logic;
signal DIP_Mux				: std_logic_vector(1 downto 0);
			
			
			
begin			

Coin1 <= (not Coin1_n); -- Coin inputs are inverted by gates in H11
Coin2 <= (not Coin2_n);
Steering1A<= not Steering1A_n ;

-- Steering inputs, handled by 7474's at H10 and J10 
SteeringA: process(Steering1A_n, Steering1B_n, SteerReset_n)
begin
	if SteerReset_n = '0' then -- Asynchronous clear
		SteerFlag <= '0';
		SteerDir <= '0';
	elsif rising_edge(Steering1B_n) then 
		SteerFlag <= '1';
		SteerDir <= Steering1A; -- Steering encoders are active low but inverted on board
	end if;
end process;
	



-- 74153 data selector/multiplexer at F9, inverting since active-low output is used
F9: process(Adr, Gear3_n, Gear1_n, SteerFlag, Coin1_n, Coin2_n, Start_n, CrashIn_n, TrackSel_n)
begin
	case Adr(2 downto 0) is
		when "000" => InputMux1 <= (not TrackSel_n);
		when "001" => InputMux1 <= (not CrashIn_n);
		when "010" => InputMux1 <= (not Start_n);
		when "011" => InputMux1 <= (not Coin2_n);
		when "100" => InputMux1 <= (not Coin1_n);
		when "101" => InputMux1 <= (not SteerFlag);
		when "110" => InputMux1 <= (not Gear1_n);
		when "111" => InputMux1 <= (not Gear3_n);
		when others => InputMux1 <= '1';
	end case;
end process;


-- 74153 data selector/multiplexer at E9, inverting since active-low output is used 
-- Note the flipped ordering of address bus inputs
E9: process(Adr, Gear2_n, Gas_n, SteerDir, HScoreRes_n, Test_n, SkidIn_n, Slam_n)
begin
	case Adr(2 downto 0) is
		when "000" => InputMux2 <= not Gear2_n;
		when "100" => InputMux2 <= not Gas_n;
		when "010" => InputMux2 <= not SteerDir;
		when "110" => InputMux2 <= not HScoreRes_n;
		when "001" => InputMux2 <= '0';
		when "101" => InputMux2 <= not Test_n;
		when "011" => InputMux2 <= not SkidIn_n;
		when "111" => InputMux2 <= not Slam_n;
		when others => InputMux2 <= '1';
	end case;
end process;


-- 74153 dual selector/multiplexer at C6
C6: process(Adr, DIP_Sw)
begin
	case Adr(1 downto 0) is
		when "00" => DIP_Mux <= DIP_Sw(7) & DIP_Sw(6); 
		when "01" => DIP_Mux <= DIP_Sw(5) & DIP_Sw(4);
		when "10" => DIP_Mux <= DIP_Sw(3) & DIP_Sw(2);
		when "11" => DIP_Mux <= DIP_Sw(1) & DIP_Sw(0);
		when others => DIP_Mux <= "11";
		end case;
end process;


-- Input data mux
DBus <= 	InputMux1 & "111111" & InputMux2 when In1_n = '0' else
			"111111" & DIP_Mux  when Opt_n = '0' else
			x"FF";

end rtl;
