# Super Bug PCB — Operation Summary

Distilled from the Super Bug operation/maintenance manual (`docs/SuperBug.pdf`,
section "B. SUPER BUG PCB OPERATION", printed pages 18–21 / PDF pages 22–25).
Notes here focus on the bits that matter for the Verilog/VHDL ports — clocking,
interrupt generation, and address decoding. Full text is in the PDF; this file
records the parts that translate directly into RTL invariants we should match.

## Block-level layout (printed p.18, Fig. 16)

```
ENABLE ┐
       ├──→ PROGRAM PROMS ──┐
       │                     │
       ├──→ PAGE ZERO ───────┤   address bus
       │                     │
       └──→ INPUT PORTS ─────┤
                             │
                ADDRESS DECODE
                             │
                       PLAYFIELD
                             │  ┐
                       HORIZONTAL/VERTICAL TIMING
                             │  ├──→ VIDEO OUTPUT → TV
                       ALPHA NUMERICS
                             │  ┘
                             │
                OUTPUT PORTS ─┤   to lamps, attract, etc.
                             │
                       SCREECH ┐
                       BANG    ├──→ AUDIO OUTPUT → Speaker
                       MOTOR   ┘
```

The CPU (M6800-class) is a "microcomputer" with 16-bit address bus and 8-bit
bidirectional data bus, talking to ROM, scratchpad RAM, the playfield/alpha
logic, the audio circuits, and the input/output ports. A watchdog timer is
inline.

## Watchdog (p.20)

> The watchdog circuit is a shift register, a 5-bit twisted-ring counter. In
> normal operation, the circuit is pulsed once each TV picture frame by the
> processor, resetting the counter. If five frames occur without a pulse, the
> counter resets the microprocessor to restart. This prevents random electronic
> static from upsetting game operation. The power-on hardware, or the PCB
> reset pushbutton, presets the counter, which in turn initializes the
> microprocessor and starts the attract sequence.

Implementation note for the port: the watchdog is **kicked once per frame**
(not on a timer-counter or scanline). It must therefore be tied to the same
edge the program writes `$01C0` on; if five consecutive frames pass without a
write, the watchdog must assert reset.

In `rtl/cpu_mem.v` we currently decode `WdogReset_n` from `Adr` but don't
actually drive the timer. If the boot path stalls for ≥5 frames before the
program reaches the kick instruction, real hardware would reset and try again
— and our sim would just sit there. Worth knowing when chasing "boot freeze"
symptoms.

## Clocking (p.20, "Circuitry Timing")

> Clocks for the PCB originate from a 12-MHz crystal-controlled oscillator.
> The oscillator is divided by two to develop two 6-MHz clocks, designated on
> the schematic as 6 MHz and 6̄ MHz. The horizontal counters are driven by
> 6 MHz, which provide the horizontal synchronizing pulses 1H through 256H.
> The signals HBLANK and HSYNC are developed in flip-flops L7. HSYNC is the
> clock input for the vertical counters which provide the vertical
> synchronizing pulses 1V through 128V. **VBLANK and VSYNC are developed by a
> special coded ROM, M6.**
>
> Microprocessor clocks φ1 and φ2 are developed by dividing 2H by two in
> flip-flop F4. Inverters E4 provide the necessary voltage levels.

So:

| Signal | Source | Period |
| --- | --- | --- |
| 12 MHz | Crystal | master clock |
| 6 MHz / 6̄ MHz | ÷2 of 12 MHz | drive horiz counters |
| 1H..256H | horiz counter | 9-bit counter |
| HBLANK, HSYNC | FF L7 (decoded from H counter) | once per scanline |
| 1V..128V | vert counter, clocked by HSYNC | 7 outputs published, but the counter is 8-bit (256 lines/frame) |
| **VBLANK, VSYNC** | **PROM M6** | once per frame, decoded from V counter + state |
| φ1, φ2 | ÷2 of 2H by FF F4 | CPU clock — well below 6 MHz, exact rate depends on H counter feed |

The fact that the manual lists "1V through 128V" as the vertical sync pulses
explicitly enumerates: 1V, 2V, 4V, 8V, 16V, 32V, 64V, 128V — all eight bits of
the 8-bit V counter are exposed as named signals. **M6 sees all of them**
(plus its own one-bit feedback to make the sequencer work).

This contradicts our current `verilog/prom.v`, whose 8-bit address is
`{sync_reg[3], V128, V64, V16, V8, V4, V2, V1}` — i.e., **V32 is missing**.
The original VHDL has the same address composition (`source/sync.vhd:109`),
so this is a bug both ports inherited from somewhere upstream (port author
mis-translated a schematic, or a stale schematic was used).

The practical consequence has bitten us in the Verilator boot trace:

- VBLANK pulses *twice* per frame (once when V32=0, once when V32=1, because
  the PROM treats the two halves identically).
- Our `cpu_mem.v` ties NMI to `~VBlank`, so NMI fires twice per frame.
- The two NMIs are spaced about 32 lines apart — close enough that the
  second can fire while the first NMI handler is still mid-execution.
- 6800 NMI is non-maskable; the nested NMI pushes a second frame onto the
  stack; the eventual `RTI` at `$18B1` pops garbage, PC walks into RAM, the
  CPU dies executing zeros at `$0000+`.

Disabling NMI prevents the crash; the trace then matches MAME's first 543
instructions exactly. So the cpu68 core itself is fine; the M6 sync-PROM
data (or its address composition) is what's wrong.

## Microcomputer addressing (p.20)

> The address lines (BA0 through BA15) are buffered to eliminate signal
> loading. The lower-numbered lines (BA0 through BA9) address the program
> memory ROMs (E1, E2, H1, H2, and K1, K2). The scratchpad memory (RAM N1
> and M1) are addressed by address lines BA0 through BA8.
>
> The higher-numbered address lines (BA10 through BA15) address the address
> decoders. The address decoder output enables the appropriate memory or
> logic device.
>
> The **LEGIT** signal is developed from the phase 2 clock and occurs
> one-half clock period after the phase 2 clock rises. This signal is used
> to strobe the TTL and is delayed from the clock to allow the data lines
> to settle. The VMA signal is an output of the microprocessor which only
> exists when the microprocessor wants a data transfer. ROM enables the
> ROM address decoder and is part of the input to develop the System
> Enable signal.

Key invariants:

- **BA0..BA9** address program ROM (10 bits → 1 KB pages, three 2KB chips
  span the program region).
- **BA0..BA8** address scratchpad RAM (9 bits → 512 nibbles, since RAM is
  two 256×4 chips paired).
- **BA10..BA15** drive the address decoders.
- **LEGIT** is a strobe, delayed half a φ2 period after φ2 rises, used to
  give the I/O bus time to settle before TTL latches it.
- **VMA** asserts only when the CPU wants a transfer. The ROM-enable signal
  feeds into System Enable along with VMA.

This matches our `rtl/cpu_mem.v`:

```
assign Legit = (~(H2 | Phi1));               // phase-2-derived strobe
assign SysEn = (BVMA & BA12nor11 & PHI2);    // VMA + addr-decode + φ2
assign IO_Wr = (SysEn & Legit & ~RW_n);
```

so the SysEn/Legit gating is correct in spirit. The race we hit on
`Opt_n`/`In1_n` (PHI2 going low before cpu68 latches data) is purely a
Verilator event-ordering artifact, not an architectural mistake — see the
fix in `rtl/cpu_mem.v` that uses `SysEn_rd = BVMA & BA12nor11` (no PHI2
gate) for read-side decoders.

## Alphanumerics (p.20)

> Alpha characters and numerics are stored in ROM M3, N3. Each character is
> traced in a block 16 lines square, at the top of the display on the TV
> monitor. The PROM inputs are **vertical functions 1V, 2V, 4V, 8V**,
> horizontal functions 4H and 8H, and the output of alphanumeric RAM P3.
> Address lines BA0 through BA4 address the desired character. Lines BA8
> and BA10 with SYS EN (System Enable) enable the RAM for writing.
>
> Chip P3 is a 128 × 8 RAM which operates with the microprocessor,
> accepting data through tri-state buffers M2 and N2. The output of M3 is
> converted from 4-bit parallel to serial output and clocked out to the
> video summing gates through shift register L3.

So alphanumeric tile lookup uses `{P3_dout[3:0], V[3:0], H[3:2]}` — that's
the 10-bit `rom_m3_addr` we already have in `rtl/alpha_numerics.v`. ✓

## Playfield (p.20–21)

> The playfield logic is similar to the alphanumeric, although more
> complicated. The ROM consists of three ICs E5, F5, and H5. To permit
> rotating the playfield, separate horizontal and vertical counters (C5 and
> E8, D5 and F8, respectively) are used. These counters can be offset by
> the processor to create field rotation.
>
> ICs E6 and F6 are the playfield RAM. They are loaded through tri-state
> devices D6 and H6, which are connected to all eight lines of the data
> bus.
>
> There are 48 playfield objects; objects 0 through 7 are things you slide
> on (oil and sand), objects 16 through 47 are things you crash into (trees,
> pylons, cars, and CRUNCH graphics), and objects 8 through 15 (arrows) do
> not interfere with game progress at all.
>
> Playfield RAM addresses come through multiplexers E7 and F7, allowing
> **the microprocessor to load during V Blanking**.

Two important points:

- The playfield RAM is **dual-mapped**: during active display the address
  comes from the H/V counters; during VBLANK the CPU bus addresses it. The
  multiplexer is gated on VBLANK. Our `rtl/playfield.v` instantiates two
  `ram256` blocks for E6/F6; the muxing logic must be present and gated
  correctly for the program to load tiles. (Worth re-checking when the
  visible playfield is missing.)
- "48 playfield objects" with the listed semantics is just game-logic
  trivia, not RTL — but useful when reading code that masks/compares tile
  IDs.

## Super Bug Car Picture (p.21)

> The CAR VIDEO output (sheet 3) comes, one bit at a time, from the output
> of multiplexer K7. This output results in a TV monitor display of the
> Super Bug car turned in one of 24 possible directions of rotation.
> However, car picture ROM K6 contains only **four** rotational pictures
> of the Super Bug car.
>
> By exchanging the horizontal and vertical sync address inputs (J6, K5,
> L6) to car picture ROM K6, the four rotational pictures from the ROM
> are increased to eight pictures. By inverting the horizontal and vertical
> sync inputs (J5, K5, L5) to multiplexers J6, K5, and L6, the eight
> rotational pictures from ROM K6 are increased to 24 pictures.
>
> Select inputs R0 and R1 of multiplexer K7 determine the data bit output
> of car picture ROM K6.
>
> Flip-flops M7 and associated gates produce the timing necessary to enable
> the car picture to be displayed in the center of the TV monitor.

So the car ROM is only 4 stored pictures × {H-swap, V-swap, both} → 8 ×
{further H/V invert} → 24 total rotation views. Our `rtl/car.v` already does
this; useful when validating that the rendered car points the right
direction.

## Audio (p.21)

> The microprocessor puts sound data on the data bus. IC B5 latches data
> for the frequency of the motor sound. IC D8 latches data for the
> frequency of the crash sound.
>
> Latch C9 uses address bits BA0 through BA3 to select, on command, the
> start lamp, the track select and the FLASH signal which inverts the
> video. C9 also permits the microprocessor to select the ATTRACT signal,
> which turns the sound on and off.

C9 is the output latch addressed by `Adr[3:0]`. It drives:
- start lamp
- track select
- FLASH (video invert — used for the "GAME OVER" / score flash effect we
  want to see in attract mode)
- ATTRACT (gates audio on/off)

Our `rtl/cpu_mem.v` has these as `StartLamp`, `TrakSelLamp`, `Flash`,
`Attract` outputs. The FLASH signal is what produces the flashing
"GAME OVER" text, so a working attract loop must reach C9 writes — meaning
the boot path must complete enough to enter attract mode. Currently
disabling NMI prevents that because the game-state update lives in the NMI
handler.

## Implications for current debugging

Concrete things this manual reading confirms or sharpens:

1. **The PROM M6 should see V32.** Our `verilog/prom.v` and
   `source/sync.vhd` both have a 7-bit V-side address that omits V32. The
   manual says the vertical counter exposes **all eight** bits (1V through
   128V). Without V32 the PROM aliases two halves of the frame, producing
   double-pulse VBLANK — the proximate cause of our nested-NMI crash.
2. **VBLANK and VSYNC come from PROM M6, not from a specific scanline
   threshold.** So MAME's "NMI at scanline 240" is an emulation
   simplification. The schematic-faithful fix is to correct M6's address
   composition (and likely add the missing PROM data), not to bypass it.
3. **The watchdog is a 5-frame deadman.** If the boot path stalls before
   reaching the kick, real hardware silently restarts every ~83 ms. Our
   sim does not implement this, so a stall just hangs.
4. **CPU clock is φ2 ÷ 2 of 2H ÷ 2 of 6 MHz.** That's ~750 kHz nominal
   for the 6800. The synchronizer must produce 6 MHz from a 12 MHz input,
   then derive H/V counters from there. Our Verilator harness aliases
   `clk_sys` to the 12 MHz input, which is fine for relative timing but
   gives wrong absolute rate.
5. **Playfield RAM is dual-ported via VBLANK-gated mux.** When chasing
   missing-playfield symptoms after fixing the NMI issue, verify the
   `rtl/playfield.v` mux gating still lets the CPU write during VBLANK.

## Files referenced

- `verilog/prom.v` — sync-decode PROM M6 (Verilog port)
- `source/sync.vhd` — sync logic, line 109 builds prom_address (missing V32)
- `rtl/cpu_mem.v` — `NMI_n = ~VBlank`, `IRQ_DFF` (V16-driven IRQ flop)
- `rtl/synchronizer.v` — H/V counters and PROM instantiation
- `rtl/playfield.v` — playfield ROMs E5/F5/H5 and RAM E6/F6
- `rtl/car.v` — car ROM K6 with the rotation muxes (J6/K5/L6)
- `rtl/alpha_numerics.v` — alpha ROMs M3/N3 and RAM P3
- `mame/src/mame/atari/firetrk.cpp` — MAME's superbug driver, contains the
  reference for IRQ/NMI generation (`scanline` callback) and DIP/input maps
