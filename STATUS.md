# Super Bug — Status & TODO

Snapshot of where the port stands as of the most recent debugging session.
The MiSTer/FPGA build path is functional; the Verilator path is what's
actively used for visual fidelity work.

## What works

- **CPU + memory** — 6800 (`cpu68`) running the original program ROM
  reaches attract mode and steady scrolling animation. Verified that
  `playfield_ram` and scroll registers track MAME's emulation byte-for-
  byte at every checked frame (1, 10, 30, 50, 61, 70, 100, 200, 300).
- **Tile glyph rendering** — the F5/H5/E5 PROM-to-pixel path is
  pixel-perfect for individual tiles. Validated by the `glyphtest` shim
  (`make glyphtest && ./obj_dir/Vemu`) and by force-rendering MAME and
  the verilator with byte-identical inputs and pixel-diffing — single
  pylon zoom matches MAME shape-for-shape.
- **Address decode and memory map** — matches MAME's `superbug` driver
  (`scroll_y` at $0100, `scroll_x` at $0120, alpha RAM at $0400, PF RAM
  at $0500, output latch at $0260, etc.). NMI fires once per VBlank;
  IRQ on V16 fall during HBlank as documented.
- **Sound modules and inputs** — `enginesound.v`, `tire_screech.v`,
  `joy2quad.sv`, `gearshift.sv` all build and route through the MiSTer
  framework; not the focus of this session.
- **Self-test mode** — `./obj_dir/Vemu --service` holds the self-test
  switch and the program enters the diagnostic UI.

## Recently fixed (this session's commits)

- `f7a1293` — drive `PCC1/PCC2/CrashCode/SkidCode` combinationally from
  `PD` instead of through the H7 9316 latch. Reduces the per-cell-edge
  palette-bit lag from ~4 pixels to ~1 pixel. Schematic-accurate behavior
  is the latched form (a deliberate trade-off; see "open issues" below).
- `0d1a299` — subtract MAME's documented 37-pixel constant from
  `PHP_Load` so cell positions land where MAME draws them at any given
  `scroll_x`.
- `6cefac7` — dropped the E6/F6 nibble swap (display PD now equals the
  byte the CPU wrote, matching MAME's `code = ram[i] & 0x3F`); fixed
  `PHP_Load_n`/`PVP_Load_n` address decode so `$0100` loads `PVP` and
  `$0120` loads `PHP` (matches MAME's `scroll_y`/`scroll_x` map).
- `aec38cb` / `f8a96c3` — debug-only latches and counters in `cpu_mem.v`
  that snapshot the CPU's writes to `scroll_x`/`scroll_y` so we can
  diff directly against MAME's stored values. Confirmed the CPU writes
  both registers exactly once per frame.
- `ffa397f` — `glyphtest` Verilator build target and ROM-A1 shim for
  walking through every playfield tile glyph.
- `63500d3` / `870b9c1` / `eab676c` — MAME-side Lua tooling
  (`tools/superbug_dump_pf.lua`, `tools/superbug_force_render.lua`,
  `tools/superbug_snap_frames.lua`) plus pattern files for direct
  byte-level and pixel-level comparison.

## Open issues

### 1. Playfield rendering doesn't visually match MAME's attract scene

**Symptoms** the user has flagged:
- Frame-by-frame screenshots 10–18 show "ghost scenery" filling the road
  area where MAME shows clean black road.
- The car's apparent position relative to the lane markers shifts from
  frame to frame in ways MAME doesn't.
- Visible content concentrated horizontally instead of MAME's symmetric
  spread.

**What's confirmed not the cause:**
- RAM contents — byte-identical at every frame.
- `scroll_x`/`scroll_y` write timing — the CPU writes once per frame in
  both, lockstep at +2/frame after a constant 2-count phase offset.
- Tile decoding — single-tile fills render shape-for-shape correctly.
- `Window_en` formula — exactly matches Sheet 4 of Figure 17 in
  `docs/SuperBug.pdf` (Z6-22 NAND of 16/32/64/128H, AND with 256H in
  N9-08, latched in L9-7474 D-FF on 8H rising with VBLANK as async clear).

**Likely contributors** (in rough order of suspicion, none yet fixed):

a. **Pipeline depth between PHP and displayed pixel.** Three Clk6
   stages: PHP → PF_RAM_Adr → PD; PD → PFROM_Adr → Vid; Vid + LoadPd
   → VidShift load. Net: `VidShift` at PHP=N\*16+0..3 still outputs
   cell (N-1)'s last nibble = 4 pixels of "ghost previous tile" at
   every cell boundary. Real-PCB hardware behaves this way per the
   schematic; MAME's tilemap renderer doesn't model it. Tried
   advancing `PF_RAM_Adr` and `PFROM_Adr` indices by 3 and 2 Clk6
   respectively and 2-stage delaying PD for PCC computation (so the
   advanced fetch matches the displayed pixel) — the diff dropped
   slightly (8% → 6.15%) but the visual still looked wrong, so
   **reverted** pending more careful pipeline analysis.

b. **PVP-vs-`count_line` desync.** A per-`post_x` non-black pixel
   profile at frame 70 (with byte-identical RAM force-rendered in
   both) shows MAME's content distributed across the full 0–236
   `post_x` range while ours clusters at `post_x ~24-136` with the
   right half empty. `stats_yMax` reports `count_line` reaches 240,
   but the playfield only renders for ~half the visible scanlines —
   suggesting `PVP` isn't traversing all 16 row indices despite
   incrementing on `posedge HSync` per scanline. **Highest-priority
   thing to investigate next.**

c. **`PHP` 8-bit wrap inside the 320-clk_6 visible region.** With
   `Window_en` gating to ~240 clk_6 there shouldn't be a duplicate
   cell visible — analysis confirmed 16 distinct cells per scanline —
   but worth re-verifying empirically once (b) is resolved.

### 2. ~2-frame phase offset in scroll animation

MAME's `scroll_x` at frame_number 1 is `$FE`; ours starts at `$00` (the
CPU hasn't written yet by then). Both then advance `+2` per frame in
lockstep. The visual consequence is that our verilator's frame N looks
like MAME's frame N-1. This isn't a hardware bug — it's a count_frame
reset alignment thing — but if you're frame-comparing against
`mame/snap/startup.avi` you'll see a constant 2-frame lead.

### 3. Alphanumeric drift during attract / score updates

Not investigated this session. The `OOOO` border at very early frames
suggests our alpha RAM startup state may differ; MAME shows
`1 COIN 1 PLAY` already at frame 1.

### 4. Watchdog isn't actually wired

`rtl/cpu_mem.v` decodes `WdogReset_n` but doesn't drive the 5-frame
deadman. If the boot path stalls for 5+ frames before the program
reaches the kick instruction, real hardware would reset and try again;
our sim just hangs. Documented in `docs/operation_summary.md`.

## Recommended next concrete debug steps

In priority order:

1. **Probe `PVP` per scanline.** Extend `--dump-ram` to log `PVP` at
   multiple `count_line` values within one frame, or add a per-scanline
   VCD trace of `PVP`/`PVP[7:4]`. Compare to the expected
   `scroll_y + count_line` mapping. Localizes issue 1(b).
2. **Force-render with a single populated row.** Pattern with only row
   8 populated (currently all `$08`) and verify it lands at `post_x
   128..143` after rotation. If it lands somewhere else, the `count_line`
   ↔ `PVP[7:4]` mapping has the bug. If it lands at `post_x 128..143`
   correctly, the bug is in *which* rows the natural-game CPU is writing
   (compare to MAME's RAM dump again for that specific scanline).
3. **Once 1(b) is resolved**, retry the pipeline retiming
   (`PHP+3` in `PF_RAM_Adr`, `PHP+2` in `PFROM_Adr`, 2-stage PD delay
   for PCC) — should now visibly clean up the per-cell-edge ghost.
4. **Compare attract f1 alpha** between MAME and our verilator. Check
   if the `OOOO` border is actually our render of an unwritten alpha
   ROM region or if MAME has cleared it via CPU writes by f1.

## Test infrastructure cheat-sheet

```sh
# Dump MAME's playfield RAM at chosen frames (run from mame/):
SBDUMP_FRAMES="1,30,61,100,200" SBDUMP_OUT=/tmp/mame_pf.txt \
  ./mame -window -nothrottle -sound none -seconds_to_run 12 \
         -autoboot_script ../tools/superbug_dump_pf.lua superbug

# Dump verilator's playfield RAM at the same frames:
cd verilator && for f in 1 30 61 100 200; do
  ./obj_dir/Vemu --headless --dump-ram $f --stop-at-frame $((f+5)) 2>&1 \
    | grep -A 17 "playfield RAM"
done

# Force MAME and verilator to render the same RAM/scroll state:
SBFR_PATTERN=../tools/patterns/like_frame70.txt SBFR_OUT=/tmp/m.png \
  ./mame -window -nothrottle -sound none -seconds_to_run 8 \
         -autoboot_script ../tools/superbug_force_render.lua superbug
# Build matching verilator shim, then run:
cd verilator && make glyphtest && \
  ./obj_dir/Vemu --headless --screenshot 60 --stop-at-frame 65 \
                 --screenshot-name /tmp/v.png

# Walk through every playfield tile (palette 01) for visual check:
cd verilator && make glyphtest && ./obj_dir/Vemu
```
