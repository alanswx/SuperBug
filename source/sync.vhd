-- Video synchronizer circuit for Super Bug
-- Similar circuit used in many other Atari and Kee Games arcade games
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
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.all;

entity synchronizer is 
port(		
			clk_12		: in	std_logic;
			clk_6			: out	std_logic;
			clk6_n		: out std_logic;
			hcount		: out	std_logic_vector(8 downto 0);
			vcount		: out	std_logic_vector(7 downto 0);
		   hsync			: out	std_logic;
			hblank		: out std_logic;
			vblank		: out	std_logic;
			vsync			: out std_logic;
			vreset		: out	std_logic);
end synchronizer;

architecture rtl of synchronizer is

signal h_counter		: std_logic_vector(9 downto 0) := (others => '0');
signal H256				: std_logic;
signal H256_n			: std_logic;
signal H128				: std_logic;
signal H64				: std_logic;
signal H32				: std_logic;
signal H16				: std_logic;
signal H8				: std_logic;
signal H8_n				: std_logic;
signal H4				: std_logic;
signal H4_n				: std_logic;
signal H2				: std_logic;
signal H1				: std_logic;

signal v_counter		: std_logic_vector(7 downto 0) := (others => '0');
signal V128				: std_logic;
signal V64				: std_logic;
signal V32				: std_logic;
signal V16				: std_logic;
signal V8				: std_logic;
signal V4				: std_logic;
signal V2				: std_logic;
signal V1				: std_logic;

signal sync_bus		: std_logic_vector(3 downto 0) := (others => '0');
signal sync_reg		: std_logic_vector(3 downto 0) := (others => '0');
signal vblank_int		: std_logic := '0';
signal vreset_n		: std_logic := '0';

signal hblank_int		: std_logic := '0';
signal hsync_int		: std_logic := '0';
signal hsync_reset 	: std_logic := '0';

signal prom_address : std_logic_vector(7 downto 0);
signal prev_H32			: std_logic := '0';
signal prev_H8			: std_logic := '0';
signal prev_hsync_int	: std_logic := '0';
signal ce_H32_rise		: std_logic;
signal ce_H8_rise		: std_logic;
signal ce_hsync_rise	: std_logic;
signal ce_line			: std_logic;

begin

-- Horizontal counter is 9 bits long plus additional flip flop. The last 4 bit IC in the chain resets to 0010 so total count resets to 128 
-- using only the last three count states
H_count: process(clk_12)
begin
	if rising_edge(clk_12) then
		if h_counter = "1111111111" then
			h_counter <= "0100000000";
		else
			h_counter <= h_counter + 1;
		end if;
	end if;
end process;

-- Edge detectors keep the simulator in a single clk_12 domain instead of
-- relying on multi-edge sensitivity to internally generated clocks.
edge_detect: process(clk_12)
begin
	if rising_edge(clk_12) then
		prev_H32 <= H32;
		prev_H8 <= H8;
		prev_hsync_int <= hsync_int;
	end if;
end process;
ce_H32_rise <= H32 and (not prev_H32);
ce_H8_rise <= H8 and (not prev_H8);
ce_hsync_rise <= hsync_int and (not prev_hsync_int);

-- Advance the vertical counter once per scanline during the HBlank window,
-- matching the Verilog timing fix that prevents vcount/NMI races.
ce_line <= '1' when h_counter = "0101010000" else '0'; -- 336
V_count: process(clk_12)
begin
	if rising_edge(clk_12) then
		if vreset_n = '0' then
			v_counter <= (others => '0');
		elsif ce_line = '1' then
			v_counter <= v_counter + '1';
		else
			v_counter <= v_counter;
		end if;
	end if;
end process;

-- Many Atari raster games use a 256 x 4 bit prom to decode vertical sync signals
-- This could be replaced by combinatorial logic
--M2: entity work.sync_prom
--port map(
--		clock => clk_12, 
--		address => sync_reg(3) & V128 & V64 & V16 & V8 & V4 & V2 & V1,
--		q => sync_bus
--		);

prom_address <= sync_reg(3) & V128 & V64 & V16 & V8 & V4 & V2 & V1;
M2: entity work.prom
port map(
		address => prom_address,
		data => sync_bus
		);

-- Register fed by the sync PROM, in the original hardware this also creates the complements of these signals
sync_register: process(clk_12)
begin
	if rising_edge(clk_12) then
		if ce_hsync_rise = '1' then
			sync_reg <= sync_bus;
		end if;
	end if;
end process;

-- Outputs of sync PROM
--vblank_s <= sync_reg(3);
--vblank_n_s <= not sync_reg(3);
-- The schematic PROM-address composition above omits V32 (8-bit address
-- is sync_reg(3) & V128 & V64 & V16 & V8 & V4 & V2 & V1), so two
-- distinct vcounts alias to the same PROM entry and VBLANK pulses
-- twice per frame -> nested NMI -> stack corruption -> CPU dies.
-- Both the original VHDL and the X-HDL Verilog port inherited this
-- bug. Until/unless the correct address composition is identified,
-- generate VBLANK/VSYNC/VRESET algorithmically from v_counter, matching
-- MAME's firetrk_state::scanline() callback (256-line frame, vcount
-- wraps naturally on the 8-bit counter):
--   VBLANK active for vcount >= 240
--   VSYNC pulse during vcount 242..244
-- The PROM is still instantiated above to keep the prom_address wire
-- for future debugging; sync_reg outputs below are ignored.
vreset   <= '0';
vreset_n <= '1';
vblank   <= '1' when v_counter >= "11110000" else '0';                   -- vcount >= 240
vsync    <= '1' when v_counter >= "11110010" and v_counter <= "11110100" -- 242..244
            else '0';

-- A pair of D type flip-flops that generate the Hsync signal. Model the
-- H32/H8 clocks as enables on clk_12 to avoid simulator extra edges.
Hsync_1: process(clk_12)
begin	
	if rising_edge(clk_12) then
		if H256_n = '0' then
			hblank_int <= '0';
		elsif ce_H32_rise = '1' then
			hblank_int <= not H64;
		end if;
	end if;
end process;

Hsync_2: process(clk_12) 
begin
	if rising_edge(clk_12) then
		if hblank_int = '0' then
			hsync_int <= '0';
		elsif ce_H8_rise = '1' then
			hsync_int <= H32;
		end if;
	end if;
end process;

-- Assign various signals
clk_6 <= h_counter(0);
clk6_n <= (not h_counter(0));
--clk6_n <= not clk_6;
H1 <= h_counter(1);
H2 <= h_counter(2);
H4 <= h_counter(3);
H8 <= h_counter(4);
H16 <=  h_counter(5);
H32 <= h_counter(6);
H64 <= h_counter(7);
H128 <= h_counter(8);
H256 <= h_counter(9);
H4_n <= not H4;
H8_n <= not H8;
H256_n <= not H256;

V1 <= v_counter(0);
V2 <= v_counter(1);
V4 <= v_counter(2);
V8 <= v_counter(3);
V16 <= v_counter(4);
V32 <= v_counter(5);
V64 <= v_counter(6);
V128 <= v_counter(7);

hcount <= h_counter(9 downto 1);
vcount <= v_counter;
hsync <= hsync_int;
hblank <= hblank_int;

end rtl;
