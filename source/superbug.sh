#../../ghdl-llvm/lib/ghdl/vendors/compile-altera.sh --ghdl /Users/alans/Documents/development/verilog/ghdl-llvm/bin/ --all --src ../../sim_lib --out swork
#exit
#../../ghdl-llvm/bin/ghdl -i  altera/*.vhd ../roms/Altera/*.vhd
#../../ghdl-llvm/bin/ghdl -i --work=altera_mf altera/*.vhd ../roms/Altera/*.vhd
../../ghdl-llvm/bin/ghdl -a --work=altera_mf -Pswork --std=08 --ieee=synopsys --workdir=swork --ieee=synopsys altera/*.vhd *.vhd ..//roms/Altera/*.vhd superbug_top.vhd
../../ghdl-llvm/bin/ghdl -m -Pswork --std=08 --ieee=synopsys --workdir=swork --ieee=synopsys top
../../ghdl-llvm/bin/ghdl -r -Pswork --std=08 --ieee=synopsys --workdir=swork --ieee=synopsys top
