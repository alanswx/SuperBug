#!/bin/bash
# Build and run the headless GHDL trace testbench (sb_trace_tb).
# Uses cpu68_traced.vhd (local copy of source/cpu68.vhd with a sim-only
# trace_proc appended) so we don't have to plumb dbg_* ports through the
# whole hierarchy. Outputs the CPU instruction trace to stdout.
# Usage: ./run_trace.sh [stop_time]   default 5ms
set -e
cd "$(dirname "$0")"
mkdir -p altera_mf trace_work

GHDL=ghdl

${GHDL} -a -g --std=08 --work=altera_mf --workdir=altera_mf --ieee=synopsys altera_*.vhd >/dev/null 2>&1
${GHDL} -a -g --std=08 --workdir=trace_work -Paltera_mf --ieee=synopsys \
    ../source/Altera/*.vhd ../roms/Altera/*.vhd >/dev/null 2>&1

# Note: cpu68_traced.vhd MUST be analyzed before any other ../source/*.vhd
# because the wildcard would pull in the original cpu68.vhd otherwise.
${GHDL} -a -g --std=08 --workdir=trace_work -Paltera_mf --ieee=synopsys \
    cpu68_traced.vhd \
    ../source/sync_prom.vhd ../source/sync.vhd ../source/cpu_mem.vhd \
    ../source/mixer.vhd ../source/alphanumerics.vhd ../source/car.vhd \
    ../source/FF109.vhdl ../source/playfield.vhd ../source/inputs.vhd \
    ../source/deltasigma.vhd ../source/screech.vhd ../source/motor.vhd \
    ../source/SuperBug.vhd \
    sb_trace_tb.vhd >/dev/null 2>&1

${GHDL} -m -g -Pwork -Paltera_mf --std=08 --ieee=synopsys --workdir=trace_work sb_trace_tb >/dev/null 2>&1

STOP="${1:-5ms}"
exec ./sb_trace_tb --stop-time="$STOP" --assert-level=none --ieee-asserts=disable
