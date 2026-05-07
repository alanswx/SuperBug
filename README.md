# Super Bug — FPGA recreation

An FPGA recreation of Atari/Kee Games **Super Bug** (1977), targeted at the
[MiSTer](https://misterfpga.org/) platform (DE10-Nano / Cyclone V) via the
standard MiSTer `sys/` framework. The original VHDL core is by **James Sweet**;
this tree is mid-migration to Verilog so the same RTL can also be simulated
under Verilator on a host machine for development and debugging.

## Credits

Original VHDL implementation by **James Sweet** —
[github.com/james10952001](https://github.com/james10952001).

This repository builds on James's original work, adding:

- A hand-written Verilog port of the playfield, car, alphanumerics, mixer,
  CPU/memory, and synchronizer modules under `rtl/`, runnable on real
  MiSTer hardware *and* on a host machine via Verilator.
- A Verilator simulation harness (`verilator/`) with ImGui+SDL2 frontend,
  screenshot capture, RAM/scroll dumping, frame-stop and headless modes.
- A glyphtest mode that swaps in a tiny 6800 shim for ROM A1, useful for
  exercising every entry of the F5/H5/E5 playfield PROMs.
- MAME-side tooling (`tools/`) to dump Super Bug's playfield RAM, scroll
  registers, and force-rendered snapshots side-by-side with the verilator
  output for pixel-level comparison.

The MAME superbug driver (used as the comparison reference) is by the MAME
team (Atari `firetrk` family driver, `mame/src/mame/atari/firetrk.cpp`).

## Repository layout

Three parallel implementations of the same hardware live in this tree —
be aware of which one you're touching:

- **`source/`** — original VHDL core. `SuperBug.vhd`, `cpu68.vhd`,
  `playfield.vhd`, `car.vhd`, `alphanumerics.vhd`, `inputs.vhd`,
  `mixer.vhd`, `screech.vhd`, `motor.vhd`, `sync.vhd`, `cpu_mem.vhd`,
  `deltasigma.vhd`, … Used by the GHDL simulation in `sim/` and
  historically by Quartus.
- **`verilog/`** — auto-translated Verilog of selected VHDL modules
  (`cpu68.v`, `deltasigma.v`, `enginesound.v`, `input.v`,
  `tire_screech.v`, `prom.v`, `ram128.v`, `ram256.v`, `k6_rom.v`,
  `jk_ff_vhdl.v`). Translation config lives in `verilog/translate.xop`
  (X-HDL/Verific tool). **Do not hand-edit translated files** — fix the
  underlying VHDL in `source/` and rerun translation, or move the file
  out of the auto-translation set.
- **`rtl/`** — hand-written / curated Verilog that is the live target.
  `rtl/superbug.v` is the system top; submodules are `car.v`,
  `playfield.v`, `alpha_numerics.v`, `cpu_mem.v`, `Input.v`, `mixer.v`,
  `synchronizer.v`, plus `pll.v`. This is what `Arcade-SuperBug.sv` and
  the Verilator harness instantiate.

`Arcade-SuperBug.sv` is the **MiSTer top-level** (`module emu`). It wires
`rtl/superbug.v` to the MiSTer framework (`sys/`, `hps_io`, video mixer,
audio, scandoubler, arcade ROM loader, joystick → `joy2quad.sv` →
quadrature steering, `gearshift.sv`).

ROMs live under `roms/` (binaries + `.hex`) and `roms/Altera/` (Quartus
.mif/.qip wrappers). The MiSTer build expects a packaged `superbug.rom`
loaded via HPS at runtime; the simulators read the `.hex`/`.mif` files
directly.

## Building

### Quartus (FPGA bitstream for MiSTer)

Open `Arcade-SuperBug.qpf` (top = `Arcade-SuperBug.sv`, sources via
`files.qip`) in Quartus and compile. The legacy non-MiSTer project is
`SuperBug.qpf` / `superbug_top.vhd` and is not the active target.

### Verilator simulation (preferred dev loop)

From `verilator/`:

```sh
make            # builds ./obj_dir/Vemu
make fast       # rebuild C++ with aggressive GCC flags
make clean
make glyphtest  # builds with the playfield-glyph test ROM A1 shim
```

The harness compiles `sim.v` + `rtl/*.v` together with `sim_main.cpp` and
the ImGui/SDL2 frontend in `verilator/sim/`. Requires `verilator`, `sdl2`
(`sdl2-config` on PATH), and an OpenGL toolchain. Run `./obj_dir/Vemu` for
the interactive sim, or with options:

```sh
./obj_dir/Vemu --headless                   # batch mode
./obj_dir/Vemu --screenshot 30,60,100       # PNG snapshots at given frames
./obj_dir/Vemu --stop-at-frame 200          # exit at frame N
./obj_dir/Vemu --dump-ram 60                # print playfield/alpha RAM at frame N
./obj_dir/Vemu --service                    # hold the self-test switch
```

`verilate.sh` is an alternate one-shot script (currently using a different
file set — Makefile is the source of truth).

### GHDL simulation (legacy VHDL)

From `sim/`: edit `run.sh` so `GHDL` points at your local GHDL build, then
`./run.sh` to elaborate `top` (uses `sprint_sim.vhd` + `ghdl_access.{c,vhdl}`
+ SDL2). Run with `./top --vcd=out.vcd --assert-level=none --ieee-asserts=disable`
or `./top --trace-signals` for full signal dump. `./clean.sh` wipes build
artifacts.

## Architecture

- **CPU**: Motorola 6800 (`cpu68.vhd` / `verilog/cpu68.v`) clocked from a
  divided 12 MHz domain.
- **Clocks**: 50 MHz in → PLL (`rtl/pll/`, `sys/pll_*`) → 12 MHz pixel/
  system clock → derived `clk_6` for CPU and audio sub-clocks.
  `synchronizer.v` produces hsync/vsync/blank from the pixel counter
  (no external sync ROM in the Verilog path; VHDL uses `sync_prom.vhd`).
- **Video pipeline**: `playfield.v` (scrolling background tilemap from
  PROM ROMs N3/M3), `car.v` (sprite), `alpha_numerics.v` (score/text
  overlay), composed in `mixer.v` → 1‑bit Video1/Video2 → MiSTer scaler
  in `Arcade-SuperBug.sv`.
- **Audio**: engine sound (`enginesound.v` / `motor.vhd`), tire screech
  (`tire_screech.v` / `screech.vhd`), crash, mixed and delta‑sigma
  encoded (`deltasigma.v`).
- **Inputs**: MiSTer joystick → `joy2quad.sv` synthesizes quadrature
  steering pulses (`Steer_1A/1B`); `gearshift.sv` debounces the 3-gear
  paddle into one-hot. Coin/Start/Gas/Test/Slam/HSRes are direct
  active-low lines into `superbug.Input_I`.

## Tools

- `tools/superbug_dump_pf.lua` — MAME plugin that captures playfield/alpha
  RAM and scroll registers at given frame numbers, in the same format as
  our `--dump-ram`. Used to verify byte-level RAM equality with our
  verilator. Run from `mame/`:

  ```sh
  SBDUMP_FRAMES="1,30,60,100" SBDUMP_OUT=/tmp/m.txt \
    ./mame -window -nothrottle -sound none -seconds_to_run 12 \
           -autoboot_script ../tools/superbug_dump_pf.lua superbug
  ```

- `tools/superbug_force_render.lua` — MAME plugin that lets the CPU boot
  for some frames, then overrides playfield_ram/alpha/scroll/blink/car_rot
  from a pattern file and snapshots the screen. Pair with the matching
  verilator glyphtest shim for pixel-level rendering diffs.

- `tools/superbug_snap_frames.lua` — simple per-frame screenshot grabber
  for arbitrary `frame_number` values.

- `tools/patterns/` — pattern files for the force-render harness:
  `uniform_pylon.txt`, `boundary_test.txt`, `mux_edge_test.txt`,
  `single_row.txt`, `like_frame10.txt`, `like_frame70.txt`,
  `zero_scroll.txt`.

## When modifying RTL

- The Verilog under `verilog/` is regenerated from VHDL — changing it in
  place is non-durable. The hand-curated path is `rtl/`. If a fix needs
  to land in both the GHDL and Verilator sims, change the VHDL in
  `source/` AND the corresponding `rtl/*.v`.
- ROM `.qip` / `.mif` references are Quartus-specific; the Verilator sim
  reads `roms/hex/*.hex` via `$readmemh` inside the `rtl/` modules. Keep
  both in sync when adding/replacing a ROM.
- `sys/` is the upstream MiSTer framework — avoid editing; treat it as a
  vendored dependency.

## Status / known issues

See [`STATUS.md`](STATUS.md) for the current punch list and ongoing
investigations (in particular, the playfield rendering fidelity work
that's been the focus of recent debug sessions).
