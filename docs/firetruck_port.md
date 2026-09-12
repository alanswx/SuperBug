# Fire Truck: what differs from Super Bug

Atari Fire Truck (1978) runs on the next revision of the same board. This note
records exactly what the port has to add, taken from MAME's `firetrk` driver
in `mame/src/mame/atari/firetrk.cpp` and its sound netlist in `firetrk_a.cpp`,
cross-checked against the original program source in `fire-truck/`.

Both games are in one driver because they share almost everything. The parts
that carry over need no work; the parts below do.

## Carries over unchanged

- Motorola 6800 at a twelfth of the 12.096 MHz master clock, 1.008 MHz.
- Raster of 384 by 262, 320 by 240 visible, pixel clock at half the master.
- The same sync PROM, 009114, is in both ROM sets.
- Interrupt schedule: periodic interrupt on every scanline whose low five bits
  are zero except line zero, non-maskable interrupt at line 240.
- Watchdog resets after five vertical blanks.
- Playfield: 16 by 16 tiles, 64 codes, two palette bits per cell, horizontal
  scroll offset by the same 37-pixel constant.
- Car sprite: 32 by 32, four frames, flip in X and Y, and a transposed ROM
  bank, drawn at a fixed screen position.
- Collision found by comparing car pixels against playfield pixels.
- Four-level greyscale.

## Address map

Super Bug decodes 8 KB, Fire Truck 16 KB. Nothing sits at the same address.

| | Super Bug | Fire Truck |
|---|---|---|
| Scratchpad | $0000-$00FF | shares the alphanumeric RAM |
| Alphanumeric RAM | $0400-$041F, 32 bytes | $0000-$00FF, 256 bytes |
| Playfield RAM | $0500-$05FF | $0800-$08FF |
| Vertical scroll | $0100 | $1000 |
| Horizontal scroll | $0120 | $1020 |
| Crash reset | $0140 | $1040 |
| Skid reset | $0160 | $1060 |
| Car rotation | $0180 | $1080 |
| Steer reset | $01A0 | $10A0 |
| Watchdog | $01C0 | $10C0 |
| Blink | $01E0 | $10E0 |
| Motor sound | $0280 | $1400 |
| Crash sound | $02A0 | $1420 |
| Skid sound | $02C0 | $1440 |
| Trailer X | none | $1460 |
| Trailer Y | none | $1480 |
| Trailer rotation | none | $14A0 |
| Output latch | $0260-$026F | $14C0 |
| Extended play | $0220 | $14E0 |
| Inputs | $0200-$0207 | $1800-$1807 |
| DIP switches | $0240-$0243 | $1C00-$1C03 |
| Program ROM | $0800-$1FFF, 6 KB | $2000-$3FFF, 8 KB |

Two consequences worth calling out. Fire Truck's alphanumeric RAM is a full
page and doubles as the processor's direct page and stack; only its first 32
bytes are displayed. And Fire Truck's output latch is written as data, where
Super Bug encodes the value in the address.

## Output latch

Super Bug, from the address at $026X: bit 0 start lamp, bit 1 attract,
bit 2 flash, bit 3 track lamp.

Fire Truck, from the data at $14C0: bit 0 start 1 lamp, bit 1 start 2 lamp,
bit 2 flash, bit 3 track lamp, bit 4 attract, bit 5 start 3 lamp, bit 7 bell.
Lamps are active low. Bit 6 unused.

## Inputs

Super Bug answers on two data bus bits, 0 and 7. Fire Truck answers on three,
0, 6 and 7, so the port read is wider.

Fire Truck bit 0 by offset: 0 unused, 1 gas, 2 steer direction front,
3 steer direction back, 4 bell button, 5 tilt, 6 skid flag for the third
collision channel, 7 self-test.

Fire Truck bit 6 by offset: 0 start front, 1 start back, 2 start both,
3 track select, 4 unused, 5 vertical blank, 6 cabinet type, 7 diagnostic hold.

Fire Truck bit 7 by offset: 0 and 1 unused, 2 steer flag front, 3 steer flag
back, 4 coin 1, 5 coin 2, 6 crash flag for the third channel, 7 diagnostic
step.

Gears are not on these ports in Fire Truck the way they are in Super Bug.

The horn is a hardware input that drives the sound directly and never reaches
the processor.

The cabinet type switch selects between the two-player Fire Truck cabinet and
the one-player Smokey Joe.

## DIP switches

Super Bug's first DIP bank is empty, so the byte the program reads is just two
bits selected by the address. Fire Truck puts coinage on bits 2 and 3 of that
bank, so those bits have to reach the data bus as well. The existing input
module drops them.

## Graphics ROMs

| | Super Bug | Fire Truck |
|---|---|---|
| Characters | two 1 KB PROMs, M3 and N3 | one 2 KB ROM, R3 |
| Tiles | three 1 KB PROMs, F5, H5, E5, one reloaded | one 2 KB ROM, F5 |
| Car | one 1 KB PROM, K6 | one 1 KB ROM, P7 |
| Trailer | none | two 2 KB ROMs, J5 and L5 |

The bit orderings differ too. Super Bug's tile layout reverses nibbles within
each byte; Fire Truck's is straightforward. Both character layouts rotate the
nibble order across the glyph, but by different amounts. The tile and character
modules need their ROM addressing and bit order selected by game rather than
hardcoded.

## Trailer

This is the only genuinely new picture generator. Sixty-four pixels square
against the car's thirty-two, eight rotation frames against four, and its own
position registers, where the car sits at a fixed place on screen.

The rotation register holds the frame in bits 0 to 2, flip X in bit 3 and
flip Y in bit 4. Screen position is derived from the two position registers,
mirrored when the corresponding flip bit is set, with a 36-pixel horizontal
offset.

It needs its own collision channel against the playfield, alongside the car's.

## Sound

Super Bug has four channels. Fire Truck has seven: motor, siren, horn, bell,
crash, skid and extended play. Motor and siren share one register, motor in the
low nibble and siren in the high one. Crash data is inverted on the way in, the
same as Super Bug. Bell comes from the output latch, horn straight from the
panel. The noise source, crash ladder, skid oscillator and mixer are the same
circuits already built for Super Bug.

## What is needed before this can be tested

The Fire Truck ROM set. Eleven files; the twelfth, the sync PROM, is already in
this tree because Super Bug uses the same part.

    032823-02.c1  032824-01.d1  032816-01.k1  032820-01.k2
    032815-01.j1  032819-01.j2  032827-01.r3  032828-02.f5
    032831-01.p7  032829-01.j5  032830-01.l5

Until those are present neither the reference nor the simulator can run the
game, so the Fire Truck paths cannot be checked against anything. Work that
does not depend on them can proceed: the game-select plumbing, the address
decode, the trailer generator and the extra sound channels can all be written
and reviewed, and Super Bug can be verified unchanged throughout.
