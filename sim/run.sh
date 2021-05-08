mkdir -p altera_mf
mkdir -p work
GHDL=~/Documents/development/verilog/ghdl-llvm/bin/ghdl
gcc -c ghdl_access.c -o ghdl_access_c.o
${GHDL} -a -g --std=08 --work=altera_mf --workdir=altera_mf --ieee=synopsys altera_*.vhd
${GHDL} -a -g --std=08 --workdir=work -Paltera_mf --ieee=synopsys ../source/Altera/*.vhd ../roms/Altera/*.vhd 
${GHDL} -a -g --std=08 --workdir=work -Paltera_mf --ieee=synopsys ../source/cpu68.vhd \
        ../source/sync_prom.vhd \
	../source/sync.vhd ../source/cpu_mem.vhd ../source/mixer.vhd ../source/alphanumerics.vhd ../source/car.vhd ../source/FF109.vhdl ../source/playfield.vhd ../source/inputs.vhd \
        ../source/deltasigma.vhd ../source/screech.vhd  ../source/*.vhd ghdl_access.vhdl sprint_sim.vhd
${GHDL} -m -g -Pwork -Paltera_mf  --std=08 --ieee=synopsys --workdir=work --ieee=synopsys -Wl,ghdl_access_c.o -Wl,-lSDL2 top 
#${GHDL} -e -g -Pwork -Paltera_mf --std=08 --ieee=synopsys --workdir=work --ieee=synopsys -Wl,ghdl_access_c.o -Wl,-lSDL2 top 
