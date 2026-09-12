# Plan: finish Super Bug, add sound, then add Fire Truck

Working plan for taking this tree from "Super Bug video mostly right, no audio"
to "two shipping MiSTer cores from one bitstream". Written 2026-09-11.

Ordering rationale: Super Bug's remaining correctness bugs are cheap and they
gate everything downstream. Sound comes second because Fire Truck needs a
superset of the same generators and building them twice is waste. Fire Truck
comes last and mostly reuses parameterised versions of modules that already
exist.

---

## Progress log

Updated 2026-09-12. Phase 0 is done, most of Phase 1 is done, Phase 2 has its
first working implementation. One blocker was found along the way that was not
in the original plan and now sits at the top of the list.

**Done**

- Phase 0 in full. `tools/pngdiff.py`, `tools/frame_compare.sh`, scripted input
  through `--input`, WAV capture through `--audio-wav`, the raster probe, the
  code-coverage trace, the switch-read trace, and a scratchpad RAM dump that
  lines up with a matching MAME dump.
- 1.1 Sprite verification. The car frame-select inversion was wrong and is
  fixed. Verified across seven rotation values covering both ROM banks, all
  four frame indices and every flip combination; each draws 100% of its
  expected pixels with nothing extra.
- 1.2 Layer alignment. The playfield window NAND, the horizontal position
  counter preload, and the alpha and car pipeline offsets were all wrong.
  Whole-frame mismatch against MAME went from 4.53% to about 0.5%, holding
  across frames 100 to 700.
- 1.4 Watchdog and the extended-play strobe both exist now.
- 1.5 Partly. The joystick bit collision and the unconnected high score reset
  are fixed, and a coin button was added to the menu.
- 2.1 to 2.6. `rtl/sound.v` implements all four channels and the board's own
  mixer weights. The core emits sixteen-bit PCM.
- 2.7 Audio capture.
- **Input multiplexer**, not in the original plan. Both 74153 select orders
  were scrambled, so the gas pedal was answered at the wrong offset and never
  reached the CPU at all.

**Blocker: resolved**

A game could never be started on purpose. The start button was wired into the
coin line, which holds the coin switch closed for as long as start is held, and
the interrupt handler checks the coin switch first and exits as soon as it sees
one. The start check was never reached. Coin is now its own button.

With that fixed the game reaches play, the sound registers carry real values,
and the motor register matches the reference exactly.

The frame length was also wrong: the vertical counter wrapped at 256 lines
where the board runs 262, which is 240 visible plus 22 blanked. Fixed. The
scratchpad differences that remain during attract are transient values sampled
at different points in the program, not a divergence: the stable game state
matches.

**Still open**

- 1.3 Playfield cell-edge residual, now 0.04% to 0.67% per band.
- 1.5 The DIP switches are still hardcoded, so the four game-configuration
  options in the menu do nothing. The coinage switch also has no path to the
  data bus at all: the option read forces bits 2 and 3 low, where the board
  puts coinage.
- 1.6 Vertical orientation on MiSTer. Still no rotation module, so on real
  hardware the game comes out sideways.
- 1.7 ROM loading and the MRA. The download signals still go nowhere.
- 1.8 Remove the debug-only scroll latches from the CPU memory module.
- Phase 2 needs tuning against a reference recording. The screech oscillator
  currently runs near 1825 Hz where the original is nearer 1200 Hz, and the
  engine has not been compared against a recording at all.
- Phase 3 has not been started.

---

## Baseline measurement

Captured 2026-09-11 by diffing our Verilator output against the MAME
`superbug` driver at the same frame number, thresholded to binary lit/unlit
pixels. Both images 240x320 after rotation.

| Region | Mismatch as built | Mismatch at best vertical alignment |
|---|---|---|
| Top text row | 7.69% | 0.00% at one line up |
| Bottom text row | 5.91% | 0.00% at one line up |
| Playfield upper band | 4.98% | 3.28% |
| Playfield middle band | 2.24% | 2.10% |
| Playfield lower band | 2.77% | 2.52% |

Reading: the alphanumeric layer is already pixel-exact and off by exactly one
scanline. The playfield sits in roughly the right place but carries a residual
that does not flatten at any offset, consistent with the per-cell-edge pipeline
lag. Nothing here is a gross structural error.

Reproduce with `tools/pngdiff.py` once Phase 0 lands.

---

## Phase 0 — verification harness

Nothing in this phase changes game behaviour. It exists so every later phase
has a pass/fail signal instead of an eyeball.

- **0.1 Land the image diff tool.** Move the throwaway pure-Python PNG
  comparator used for the baseline into `tools/pngdiff.py`. No NumPy or Pillow
  dependency; this machine has neither. Supports whole-frame diff, per-band
  diff, and an offset sweep.
- **0.2 Frame-pair capture script.** One script that runs MAME and the
  Verilator build at the same frame numbers and reports the diff table above.
  Wraps the existing `tools/superbug_snap_frames.lua`.
- **0.3 Headless input injection.** The harness has no way to press coin,
  start, gas, or steer. Add a scripted input option so gameplay past attract
  mode can be exercised in batch. Without this, everything below attract mode
  is unverified.
- **0.4 Debug readout for write-only registers.** `car_rot` is write-only, so
  it never appears in a RAM dump and cannot be compared against MAME. Expose it
  and the other output-latch bits through the existing `dbg_*` port chain.

**Acceptance:** `tools/frame_compare.sh` prints a per-band diff table for an
arbitrary frame list, and a scripted coin-and-start run reaches gameplay.

---

## Phase 1 — Super Bug correctness

### 1.1 Sprite verification (do first)

The car frame-select inversion needs an independent check. MAME picks the
sprite frame with `code = ~car_rot & 3` and then reads that element out of a
layout whose character increment is one bit, which puts element N at a
different ROM bit than N. Our RTL inverts the two rotation bits and indexes
the ROM nibble directly. Those two inversions may cancel, or may compound into
a sprite that rotates the wrong way.

At the moment the strongest evidence is circumstantial: at frame 400 the MAME
reference draws the car pointing straight up while our build draws it rotated
about thirty degrees, with the rest of the frame matching closely.

Method: compare the latched rotation register against MAME's at the same
frame, then decode all four frames straight out of the ROM image and render
them as text to confirm which nibble bit holds which heading. Confirm flip X,
flip Y, and the transposed bank select the same way.

### 1.2 One-scanline vertical offset

Alpha text is exact at one line up. Find whether the offset lives in the
vertical counter reset, the vertical blank start, or the playfield window
latch, and fix it at the source rather than by biasing one layer.

### 1.3 Playfield cell-edge residual

The known pipeline depth between the horizontal position counter and the
displayed pixel leaves roughly a pixel of the previous cell at every cell
boundary. The earlier retiming attempt was reverted because it was tried
before the larger scroll bugs were fixed. Retry it now that the layer is
otherwise correct, and gate acceptance on the diff table, not on a screenshot.

### 1.4 Missing hardware

- **Watchdog.** The reset strobe is decoded and thrown away. Real hardware
  resets after five frames without a kick.
- **Extended play strobe.** Not decoded at all. It drives the extended-play
  tone, so Phase 2 depends on this.

### 1.5 MiSTer top-level wiring

Four separate defects in the top level, none of which show up under Verilator
because the harness drives the core directly.

- High score reset is left off the core instance entirely, so it synthesises
  tied low and sits permanently asserted.
- One joystick button is bound to both Next Track and Start 1P.
- Start 2P reads the button the menu string assigns to Start 1P.
- The DIP switch byte is hardcoded, so all four game-configuration options in
  the on-screen menu do nothing.

### 1.6 Vertical orientation

This is a vertical cabinet and the MiSTer path has no rotation, so on real
hardware the game comes out sideways. The Verilator harness rotates in
software, which is why this has stayed invisible. Add the standard rotation
module and wire the existing orientation menu option to it.

### 1.7 ROM loading and packaging

The ROM download signals are routed into the core and then ignored; ROMs are
baked into Altera memory initialisation files. Decide between shipping baked
ROMs or wiring the download path, then write the MRA. Wiring the download path
is the right answer if Fire Truck is going to share the bitstream, because
game select then comes from the MRA.

### 1.8 Cleanup

Remove the debug-only scroll latches and write counters from the CPU memory
module, or put them behind a simulation-only guard so they do not cost
registers in the real build.

**Acceptance:** playfield bands under one percent against MAME, alpha bands at
zero, sprite headings confirmed frame by frame, and a scripted gameplay run
that survives a lap.

---

## Phase 2 — Sound

There is currently no audio anywhere. Neither the Verilog top nor the VHDL top
instantiates a sound block, and the audio output is declared and never driven.
The MiSTer top connects a seven-bit wire to a one-bit port.

What exists: engine and tire screech generators ported from the Sprint 2 core,
and a delta-sigma encoder. What is missing: the crash generator, the noise
source that feeds both crash and screech, the extended-play tone, the mixer,
and any instantiation at all.

The MAME discrete netlist for Super Bug is the specification. Four channels.

- **2.1 Noise source.** Linear feedback shift register clocked from the
  horizontal counter chain, gated by attract. Shared by crash and screech.
- **2.2 Crash generator.** Noise gated into a resistor ladder driven by the
  four-bit crash value the CPU writes.
- **2.3 Engine.** Already ported. Needs instantiating and tuning against a
  recording, since the original is an analogue oscillator whose frequency the
  CPU sets with a four-bit value.
- **2.4 Screech.** Already ported. Needs the noise input wired and the enable
  gated from the skid strobe.
- **2.5 Extended play tone.** Square wave gated by the strobe decoded in 1.4.
- **2.6 Mixer and output.** Weighted sum matching the discrete mixer, then
  delta-sigma out. Fix the port width mismatch at the top level.
- **2.7 Verilator audio capture.** The harness discards audio. Add WAV capture
  so channels can be compared against MAME recordings instead of judged by ear.

**Acceptance:** each channel audible in isolation under scripted input, engine
pitch tracks the written speed value, and the mix does not clip.

---

## Phase 3 — Fire Truck

MAME implements Super Bug, Fire Truck, and Monte Carlo from one driver because
they are the same board family. Both ROM sets contain the identical sync PROM.
Same processor, same master clock, same raster geometry.

Carries over unchanged: the processor core, the whole timing chain, the
scrolling tilemap architecture, the rotating car sprite, collision detection by
re-render, quadrature steering, the gearshift, and the MiSTer framework wiring.

### 3.1 Restructure for two games

Parameterise rather than fork. A game-select input threaded through the shared
modules, driven from the MRA. Forking the tree doubles every future fix.

### 3.2 Memory map

Sixteen kilobytes of address space against eight. Eight kilobytes of program
ROM. Alphanumeric RAM grows from thirty-two bytes to a full page. A second
bank of hardware registers that Super Bug does not have, including the trailer
position registers and a separate output latch.

### 3.3 Graphics ROM organisation

Fire Truck uses one character ROM and one tile ROM with straightforward bit
ordering. Super Bug splits its tiles across three PROMs with reversed nibbles.
The tile and alpha modules need ROM addressing and bit order parameterised
instead of hardcoded.

### 3.4 Trailer sprite

Genuinely new RTL. Sixty-four pixels square against the car's thirty-two,
eight rotation frames against four, and its own position registers. Super Bug's
car sits at a fixed screen position; the trailer moves.

### 3.5 Second collision channel

Trailer against playfield, alongside the existing car channel.

### 3.6 Inputs

Two steering wheels, one for the driver and one for the back player. Horn and
bell buttons. The single-player Smokey Joe cabinet variant selected by a DIP.

### 3.7 Sound

A larger set than Super Bug: motor, horn, siren, bell, crash, screech, and
extended play. The noise source, crash generator, screech, and mixer all come
from Phase 2.

### 3.8 Packaging

One bitstream, two MRA files, game select from the ROM header.

**Acceptance:** Fire Truck reaches attract mode and matches the MAME reference
to the same tolerance Super Bug reaches in Phase 1, with both games selectable
from separate MRAs on one bitstream.

---

## Assets and gaps

- The original Fire Truck 6800 assembly source is checked out under
  `fire-truck/`, and the Super Bug listings under `superbug/`. Both are a real
  advantage when a behaviour is ambiguous.
- MAME is built in-tree and its driver is the reference for all three games.
- **Missing:** Fire Truck schematics. The documentation folder holds only the
  Super Bug manual and crops from its schematic sheets. Source these before
  starting Phase 3.
- Monte Carlo is the third member of the family and is a natural follow-on once
  the parameterised structure from Phase 3 exists.
