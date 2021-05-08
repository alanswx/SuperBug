  LIBRARY ieee;
    USE ieee.std_logic_1164.ALL;
    use std.textio.all;


    ENTITY top IS
    END top;

    ARCHITECTURE behavior OF top IS 
      COMPONENT top  
      PORT(
        clk_in : IN  std_logic;
        reset  : IN  std_logic;
        clk_out: OUT std_logic
      );
      END COMPONENT;

      -- Inputs
      signal clk_in  : std_logic := '0';
      signal reset   : std_logic := '0';
      -- Outputs
      signal clk_out : std_logic;
      constant clk_in_t : time := 20 ns; 

      signal  hsync      : std_logic;
      signal  vsync      : std_logic;
      signal  csync      : std_logic;
      signal audio : std_logic;
      signal  hblank      : std_logic;
      signal  vblank      : std_logic;
      signal  video1 : std_logic;
      signal  video2 : std_logic;
      signal  hcnt_o      : std_logic_vector(8 downto 0);
      signal  vcnt_o      : std_logic_vector(8 downto 0);
      signal lamp1:std_logic;
      signal lamp2:std_logic;
      signal clk6:std_logic;
    BEGIN 

	    
super: entity work.superbug
port map(
        clk_50_i=> clk_in,
        clk12 => clk_in,
        reset_n => reset,
	Video1_O => video1, 
	Video2_O => video2, 
	Sync_O=> csync, 
	Audio_O=> audio, 
	Coin1_I=> '1', 
	Coin2_I=> '1', 
	Start_I=> '1', 
	Trak_Sel_I=> '1', 
	Gas_I=> '1', 
	Gear1_I=> '1', 
	Gear2_I=> '1', 
	Gear3_I=> '1', 
	Steer_1A_I=> '1', 
	Steer_1B_I=> '1', 
	Test_I=> '1', 
	Slam_I=> '1', 
	HSRes_I=> '1', 
	Lamp1_O=> lamp1, 
	Lamp2_O=> lamp2, 
        hs_O=>hsync,
        vs_O=>vsync,
        hblank_O=>hblank,
        vblank_O=>vblank,
        clk_6_O => clk6,
        DIP_Sw  => "11111111",
        -- signals that carry the ROM data from the MiSTer disk
        dn_addr  =>"0000000000000000",
        dn_data => "00000000",
        dn_wr => '0'

);
process(clk_in)
variable l: line;
begin
 write(l,String'("reset:"));
 write(l,reset);
 writeline(output,l);
 --write(l,String'("clk"));
 --write(l,clk_in);
 writeline(output,l);
 write(l,String'("hblank"));
 write(l,hblank);
 writeline(output,l);
end process;



      -- Clock definition.
      entrada_process :process
        begin
        clk_in <= '0';
        wait for clk_in_t / 2;
        clk_in <= '1';
        wait for clk_in_t / 2;
      end process;

      -- Processing.
      stimuli: process
      begin
        reset <= '0'; -- Initial conditions.
        wait for 100 ns;
        reset <= '1'; -- Down to work!
            wait;
      end process;
    END;

