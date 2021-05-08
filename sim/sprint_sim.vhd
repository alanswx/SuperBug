  LIBRARY ieee;
    USE ieee.std_logic_1164.ALL;
--use IEEE.STD_LOGIC_ARITH.all;
--use IEEE.STD_LOGIC_UNSIGNED.all;
use ieee.numeric_std.all;
use ieee.numeric_std_unsigned.all ;

    use std.textio.all;
use work.ghdl_access.all;


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
      --signal  hcnt_o      : std_logic_vector(8 downto 0);
      --signal  vcnt_o      : std_logic_vector(8 downto 0);
      signal lamp1:std_logic;
      signal lamp2:std_logic;
      signal clk6:std_logic;
      signal vid_mono:std_logic_vector(7 downto 0);
      signal vid:std_logic_vector(1 downto 0);
      signal color:std_logic_vector(23 downto 0);
      --signal color:unsigned(31 downto 0);
      signal CINT: integer;
      signal vsi: integer;
      signal hsi: integer;
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
        Test_I=> '0',
        --Test_I=> '1',
        Slam_I=> '1',
        HSRes_I=> '1',
        Lamp1_O=> lamp1,
        Lamp2_O=> lamp2,
        hs_O=>hsync,
        vs_O=>vsync,
        hblank_O=>hblank,
        vblank_O=>vblank,
        clk_6_O => clk6,
        DIP_Sw  => "10100000",
        -- signals that carry the ROM data from the MiSTer disk
        dn_addr  =>"0000000000000000",
        dn_data => "00000000",
        dn_wr => '0'

);
    

vid<=video1&video2;

process(vid)
begin 
 case vid  is 
    when "01"  => vid_mono <= "01110000";
    when "10"  => vid_mono <= "10000110";
    when "11"  => vid_mono <= "11111111";
    when "00"  => vid_mono <= "00000000";
    when others  => vid_mono <= "00000000";
 end case;
end process;

color<=vid_mono&vid_mono&vid_mono;
CINT<=to_integer(color);

--process(vsync,hsync)
--begin
  --if (vsync='1') then
   --  vsi <= 1;
  --else 
   --  vsi <=0;
  --end if;
  --if (hsync='1') then
   --  hsi <= 1;
  --else 
    -- hsi <=0;
  --end if;
--end process;
process
begin
    wait until rising_edge(clk6);

  if (vsync='1') then
     vsi <= 1;
  else 
     vsi <=0;
  end if;
  if (hsync='1') then
     hsi <= 1;
  else 
     hsi <=0;
  end if;
  --dpi_vga_display(vsync,hsync,color);
  dpi_vga_display(vsi,hsi,CINT);
  --dpi_vga_display(vsync,hsync,integer(unsigned(color)));
  --dpi_vga_display(vsync,hsync, "00000000000000000000000010101010" );--"11111111"&vid_mono&vid_mono&vid_mono);
end process;



process(clk_in)
variable l: line;
begin
 --write(l,String'("reset:"));
 --write(l,reset);
 --writeline(output,l);
 --write(l,String'("clk"));
 --write(l,clk_in);
 --writeline(output,l);
 --write(l,String'("csync"));
 --write(l,csync);
 --writeline(output,l);
 --write(l,String'("VideoW"));
 --write(l,video1);
 --writeline(output,l);
 --write(l,String'("vid_mono"));
 --write(l,vid_mono);
 --writeline(output,l);
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
        --dpi_vga_init(320,240);
        dpi_vga_init(640,400);
            wait;
      end process;
    END;

