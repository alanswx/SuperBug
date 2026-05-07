library ieee;
use ieee.std_logic_1164.all;

entity inner is
end inner;
architecture a of inner is
    signal probe : std_logic_vector(7 downto 0) := x"5A";
begin
end a;

library ieee;
use ieee.std_logic_1164.all;
use std.textio.all;
use ieee.std_logic_textio.all;

entity extname_test is
end extname_test;

architecture behavior of extname_test is
begin
    sub: entity work.inner;
    p: process
        variable l : line;
    begin
        wait for 5 ns;
        write(l, string'("inner.probe = "));
        hwrite(l, << signal .extname_test.sub.probe : std_logic_vector(7 downto 0) >>);
        writeline(output, l);
        wait;
    end process;
end behavior;
