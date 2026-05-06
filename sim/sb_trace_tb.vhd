-- Headless testbench: drives Super Bug at the Verilator-equivalent stimulus
-- and prints a CPU instruction trace by tapping cpu68 internals via VHDL-2008
-- external names. No SDL/display init, so it can run unattended in CI/diff.
--
-- Output format matches the Verilator side:
--   AAAA: OO   (4-hex address, 2-hex opcode byte)
-- so the two traces can be diff'd directly.

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE std.textio.ALL;

ENTITY sb_trace_tb IS
END sb_trace_tb;

ARCHITECTURE behavior OF sb_trace_tb IS
    signal clk_in  : std_logic := '0';
    signal reset   : std_logic := '0';
    constant clk_in_t : time := 20 ns;

    signal hsync, vsync, csync, audio, hblank, vblank : std_logic;
    signal video1, video2 : std_logic;
    signal lamp1, lamp2 : std_logic;
    signal clk6 : std_logic;
BEGIN

super: entity work.superbug
port map(
    clk_50_i   => clk_in,
    clk12      => clk_in,
    reset_n    => reset,
    Video1_O   => video1,
    Video2_O   => video2,
    Sync_O     => csync,
    Audio_O    => audio,
    Coin1_I    => '1',
    Coin2_I    => '1',
    Start_I    => '1',
    Trak_Sel_I => '1',
    Gas_I      => '1',
    Gear1_I    => '1',
    Gear2_I    => '1',
    Gear3_I    => '1',
    Steer_1A_I => '1',
    Steer_1B_I => '1',
    Test_I     => '0',
    Slam_I     => '1',
    HSRes_I    => '1',
    Lamp1_O    => lamp1,
    Lamp2_O    => lamp2,
    hs_O       => hsync,
    vs_O       => vsync,
    hblank_O   => hblank,
    vblank_O   => vblank,
    clk_6_O    => clk6,
    -- Same DIP byte as the Verilator harness (sim.v).
    -- 10011000 = 1C/1C, 90 sec, Medium, English (matches MAME defaults).
    DIP_Sw     => "10011000",
    dn_addr    => (others => '0'),
    dn_data    => (others => '0'),
    dn_wr      => '0'
);

-- Trace lives inside cpu68_traced.vhd (the sim-only cpu68 copy). No
-- external-name probe here; this GHDL build doesn't support them cleanly.

clk_drive: process
begin
    clk_in <= '0';
    wait for clk_in_t / 2;
    clk_in <= '1';
    wait for clk_in_t / 2;
end process;

stim: process
begin
    reset <= '0';
    wait for 100 ns;
    reset <= '1';
    wait;
end process;

END behavior;
