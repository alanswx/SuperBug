-- CPU, RAM, ROM and address decoder for Atari/Kee Games Super Bug 
-- 2018 James Sweet
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

entity CPU_mem is 
port(	
			Clk6				: in  	std_logic;
			Reset_n			: in  	std_logic;
			VBlank			: in  	std_logic;
			HBlank			: in		std_logic;
			VCount			: in 		std_logic_vector(7 downto 0);
			HCount			: in  	std_logic_vector(8 downto 0);
			RW_n				: buffer std_logic;
			VMA				: buffer std_logic;
			PHI2				: buffer	std_logic;
			StartLamp		: out		std_logic;
			TrakSelLamp		: out		std_logic;
			Attract			: out    std_logic;
			Flash				: out 	std_logic;
			In1_n				: buffer	std_logic;
			Opt_n				: buffer std_logic;
			PHP_Load_n		: out		std_logic;
			PVP_Load_n		: out		std_logic;
			CarRot_n			: out 	std_logic;
			ArrowOff_n		: out		std_logic;
			SteerReset_n	: out		std_logic;
			CrashReset_n    : out		std_logic;
			SkidReset_n     : out		std_logic;
			MotorSnd_n		: out 	std_logic;
			CrashSnd_n		: out		std_logic;
			SkidSnd_n		: out		std_logic;
			Adr				: buffer std_logic_vector(15 downto 0);
			DBus_in			: in 		std_logic_vector(7 downto 0);
			DBus_out			: out 	std_logic_vector(7 downto 0)
			);
end CPU_mem;

architecture rtl of CPU_mem is

signal Reset			: std_logic;

signal H2				: std_logic;
signal V16				: std_logic;

signal Phi1				: std_logic;
signal Legit			: std_logic;

signal CPU_Din			: std_logic_vector(7 downto 0);
signal CPU_Dout		: std_logic_vector(7 downto 0);

signal RAM_Dout 		: std_logic_vector(7 downto 0);
signal RAMce			: std_logic := '0';
signal RAMwe			: std_logic := '0';

signal ROM1_Dout		: std_logic_vector(7 downto 0);
signal ROM2_Dout		: std_logic_vector(7 downto 0);
signal ROM3_Dout		: std_logic_vector(7 downto 0);
signal ROM_Dout		: std_logic_vector(7 downto 0);

signal ROM1ce_n		: std_logic := '1';
signal ROM2ce_n		: std_logic := '1';
signal ROM3ce_n		: std_logic := '1';

signal R_nW				: std_logic;
signal IRQ_n			: std_logic;
signal NMI_n			: std_logic;
signal BVMA				: std_logic;

signal BA12nor11		: std_logic;
signal SysEn			: std_logic;

signal WdogReset_n	: std_logic;
--signal CrashReset_n	: std_logic;
--signal SkidReset_n	: std_logic;

signal rw : std_logic;

signal IO_Wr			: std_logic;
signal Out2_n			: std_logic;

signal nmi:std_logic;
signal irq:std_logic;
begin

Reset <= (not Reset_n);

H2	<= HCount(1);
V16 <= VCount(4);

-- Clock
-- This is a bit ugly, should rewrite
Clock: process(H2)
begin
  if (Reset='1') then
     Phi2 <= '0';
  else
	if rising_edge(H2) then
		Phi2 <= (not Phi2);
	end if;
  end if;
end process;
Phi1 <= (not Phi2);
Legit <= (H2 nor Phi1);


-- IRQ
IRQ_DFF: process(V16, HBlank)
begin
	if HBlank = '0' then
		IRQ_n <= '1';
	elsif falling_edge(V16) then -- Real hardware uses rising edge of inverted 16V
		IRQ_n <= '0';
	end if;
end process;

NMI_n <= (not VBlank);

-- Watchdog

irq <= not IRQ_n;
nmi <= not NMI_n;

CPU: entity work.cpu68
port map(
	clk => Phi2, 				-- E clock input (falling edge)
	rst => Reset,				-- reset input (active high)
	--rw => R_nW,					-- Write active high AJS
	rw => rw, --R_nW,					-- Write active high
	vma => VMA,					-- valid memory address (active high)
	address => Adr,
	data_in => CPU_Din,
	data_out => CPU_Dout,
	hold => '0',				-- hold input (active high) extend bus cycle
	halt => '0',				-- halt input (active high) grants DMA
	irq => IRQ,			-- interrupt request input (active high)
	nmi => NMI			-- non maskable interrupt request input (active high)
	);
	
DBus_out <= CPU_Dout; -- when phi2 = '0' else (others => '1');	-- added phi2 
	
R_nW <= not rw;		
RW_n <= rw;
--RW_n <= (not R_nW);		
	
--CPU RAM
M1: entity work.ram256
port map(
	clock => Clk6,
	address => Adr(7 downto 0),
	wren => RAMwe,
	data => CPU_Dout(3 downto 0),
	q => RAM_Dout(3 downto 0)
	);

N1: entity work.ram256
port map(
	clock => Clk6,
	address => Adr(7 downto 0),
	wren => RAMwe,
	data => CPU_Dout(7 downto 4),
	q => RAM_Dout(7 downto 4)
	);
	


-- Program ROM
D1: entity work.ROM_D1
port map(
	clock => Clk6,
	address => Adr(10 downto 0),
	q => ROM1_Dout
	);


C1: entity work.ROM_C1
port map(
	clock => Clk6,
	address => Adr(10 downto 0),
	q => ROM2_Dout
	);


A1: entity work.ROM_A1
port map(
	clock => Clk6,
	address => Adr(10 downto 0),
	q => ROM3_Dout
	);
	
	
-- Program ROM mux
ROM_Dout <= ROM1_Dout when ROM1ce_n = '0' else
				ROM2_Dout when ROM2ce_n = '0' else
				ROM3_Dout when ROM3ce_n = '0' else
				x"FF";	

-- Address decoding


ROM1ce_n <= '0' when BVMA = '1' and Adr(12 downto 11) = "01" else '1';
ROM2ce_n <= '0' when BVMA = '1' and Adr(12 downto 11) = "10" else '1';
ROM3ce_n <= '0' when BVMA = '1' and Adr(12 downto 11) = "11" else '1';

--	000 010 0000000000
--		 011
-- 000 111 1111111111


--ROM1ce_n <= '0' when VMA = '1' and Adr(12 downto 10) = "001" else '1';
--ROM2ce_n <= '0' when VMA = '1' and Adr(12 downto 10) = "010" else '1';
--ROM3ce_n <= '0' when VMA = '1' and Adr(12 downto 10) = "111" else '1';



BVMA <= VMA; -- and (not Adr(14));
BA12nor11 <= Adr(12) nor Adr(11);
SysEn <= (BVMA and BA12nor11 and Phi2);
RAMce <= '1' when Adr(11 downto 8) = "0000" else '0';
--RAMce <= '1' when SysEn = '1' and Adr(11 downto 8) = "0000" else '0';
--RAMwe <= '1' when RAMce = '1' and RW_n = '0' else '0';  -- AJS
RAMwe <= '1' when RAMce = '1' and RW_n = '0' else '0'; 






--J4_11
IO_Wr <= (SysEn and Legit and (not RW_n));
--IO_Wr <= SysEn and Legit and R_nW ;



-- Memory map from MAME driver
-- FEDCBA9876543210           
--	0000000000000000 - 0000000011111111	(0x0000, 0x00ff) AM_RAM
--	0000000100000000							(0x0100, 0x0100) AM_MIRROR(0x001f) AM_WRITEONLY AM_SHARE("scroll_y")
--	0000000100100000							(0x0120, 0x0120) AM_MIRROR(0x001f) AM_WRITEONLY AM_SHARE("scroll_x")
--	0000000101000000							(0x0140, 0x0140) AM_MIRROR(0x001f) AM_WRITE(crash_reset_w)
--	0000000101100000							(0x0160, 0x0160) AM_MIRROR(0x001f) AM_WRITE(firetrk_skid_reset_w)
--	0000000110000000							(0x0180, 0x0180) AM_MIRROR(0x001f) AM_WRITEONLY AM_SHARE("car_rot")
--	0000000110100000 							(0x01a0, 0x01a0) AM_MIRROR(0x001f) AM_WRITE(steer_reset_w)
--	0000000111000000							(0x01c0, 0x01c0) AM_MIRROR(0x001f) AM_DEVWRITE("watchdog", watchdog_timer_device, reset_w)
--	0000000111100000							(0x01e0, 0x01e0) AM_MIRROR(0x001f) AM_WRITE(blink_on_w) AM_SHARE("blink")
--	0000001000000000 - 0000001000000111 (0x0200, 0x0207) AM_MIRROR(0x0018) AM_READ(firetrk_input_r)
--	0000001000100000							(0x0220, 0x0220) AM_MIRROR(0x001f) AM_WRITE(firetrk_xtndply_w)
--	0000001001000000 - 0000001001000011 (0x0240, 0x0243) AM_MIRROR(0x001c) AM_READ(firetrk_dip_r)
--	0000001001100000 - 0000001001101111 (0x0260, 0x026f) AM_MIRROR(0x0010) AM_WRITE(superbug_output_w)
--	0000001010000000 							(0x0280, 0x0280) AM_MIRROR(0x001f) AM_WRITE(superbug_motor_snd_w)
--	0000001010100000							(0x02a0, 0x02a0) AM_MIRROR(0x001f) AM_WRITE(firetrk_crash_snd_w)
--	0000001011000000							(0x02c0, 0x02c0) AM_MIRROR(0x001f) AM_WRITE(firetrk_skid_snd_w)
--	0000010000000000 - 0000010000011111 (0x0400, 0x041f) AM_RAM AM_SHARE("alpha_num_ram")
--	0000010100000000 - 0000010111111111 (0x0500, 0x05ff) AM_RAM AM_SHARE("playfield_ram")
--	0000100000000000 - 0001111111111111 (0x0800, 0x1fff) AM_ROM
--


--	000 010 0000000000
--		 011
-- 000 111 1111111111






-- Outputs
MotorSnd_n <= '0' when IO_Wr = '1' and Adr(9) = '1' and Adr(7 downto 5) = "100" else '1';
CrashSnd_n <= '0' when IO_Wr = '1' and Adr(9) = '1' and Adr(7 downto 5) = "101" else '1';	
SkidSnd_n  <= '0' when IO_Wr = '1' and Adr(9) = '1' and Adr(7 downto 5) = "110" else '1';

PHP_Load_n 		<= '0' when IO_Wr = '1' and Adr(10) = '0' and Adr(8) = '1' and Adr(7 downto 5) = "000" else '1';
PVP_Load_n		<= '0' when IO_Wr = '1' and Adr(10) = '0' and Adr(8) = '1' and Adr(7 downto 5) = "001" else '1';
CrashReset_n	<= '0' when IO_Wr = '1' and Adr(10) = '0' and Adr(8) = '1' and Adr(7 downto 5) = "010" else '1';
SkidReset_n		<= '0' when IO_Wr = '1' and Adr(10) = '0' and Adr(8) = '1' and Adr(7 downto 5) = "011" else '1';
CarRot_n			<= '0' when IO_Wr = '1' and Adr(10) = '0' and Adr(8) = '1' and Adr(7 downto 5) = "100" else '1';
SteerReset_n	<= '0' when IO_Wr = '1' and Adr(10) = '0' and Adr(8) = '1' and Adr(7 downto 5) = "101" else '1';
WDogReset_n		<= '0' when IO_Wr = '1' and Adr(10) = '0' and Adr(8) = '1' and Adr(7 downto 5) = "110" else '1';
ArrowOff_n		<= '0' when IO_Wr = '1' and Adr(10) = '0' and Adr(8) = '1' and Adr(7 downto 5) = "111" else '1';

In1_n 	<= '0' when SysEn = '1' and Adr(9) = '1' and Adr(7 downto 5) = "000" else '1';
Opt_n 	<= '0' when SysEn = '1' and Adr(9) = '1' and Adr(7 downto 5) = "010" else '1';
Out2_n 	<= '0' when SysEn = '1' and Adr(9) = '1' and Adr(7 downto 5) = "011" else '1';
-- ASR (where does this go?)	-- Audio related

-- 74LS175 at C9
OutputLatch: process(Adr, Out2_n)
begin
       if (Reset='1') then
		StartLamp <= '0';
		TrakSelLamp <= '0';
		Attract <= '0';
		Flash <= '0';
        end if;
	if rising_edge(Out2_n) then
		StartLamp <= Adr(0);
		TrakSelLamp <= Adr(3);
		Attract <= Adr(1);
		Flash <= Adr(2);
	end if;
end process;
			

-- CPU data in mux
CPU_Din <= 
	ROM_Dout when ROM1ce_n = '0' or ROM2ce_n = '0' or ROM3ce_n = '0' else
	RAM_Dout when RAMce = '1' and RW_n = '1' else
	DBus_in when In1_n = '0' or Opt_n = '0' else
	x"FF";


end rtl;
