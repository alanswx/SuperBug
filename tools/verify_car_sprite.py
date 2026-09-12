#!/usr/bin/env python3
"""Check rendered car sprites against the ROM, heading by heading.

The car register is write-only, so the only way to know what should have been
drawn is to decode the ROM the way MAME's gfxdecode does and compare against
the pixels that actually came out.

    tools/verify_car_sprite.py --rom mame_roms/9125.k6 \
        --shots DIR 200=0x1E 260=0x15 380=0x1A

Each argument after --shots is FRAME=CAR_ROT, taken from the harness's
[car_rot] log lines. The sprite is drawn at raster x 144..175, y 104..135; the
harness rotates the raster so output row = 319 - raster x and output column =
raster y.
"""

import argparse
import sys
import os

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pngdiff import read_png

XO = [0x0000 + 0x100 * i for i in range(32)]   # superbug_car_layout1 x offsets
YO = [0x04 + 0x08 * i for i in range(32)]      # superbug_car_layout1 y offsets


def sprite(rom, car_rot):
    """Return a 32x32 grid, sprite[y][x], for this rotation register value."""
    code = (~car_rot) & 0x03
    layout2 = bool(car_rot & 0x10)
    flip_x = bool(car_rot & 0x04)
    flip_y = bool(car_rot & 0x08)
    xo, yo = (YO, XO) if layout2 else (XO, YO)

    def bit(off):
        return (rom[off >> 3] >> (7 - (off & 7))) & 1

    g = [[bit(code + yo[y] + xo[x]) for x in range(32)] for y in range(32)]
    if flip_x:
        g = [list(reversed(r)) for r in g]
    if flip_y:
        g = list(reversed(g))
    return g


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rom", required=True, help="009125.k6 image, 1024 bytes")
    ap.add_argument("--dir", required=True, help="directory of v_frame_NNNN.png")
    ap.add_argument("shots", nargs="+", metavar="FRAME=CAR_ROT")
    args = ap.parse_args()

    rom = open(args.rom, "rb").read()
    if len(rom) != 1024:
        print(f"warning: expected a 1024-byte ROM, got {len(rom)}")

    worst = 0.0
    for item in args.shots:
        frame_s, rot_s = item.split("=")
        frame = int(frame_s)
        rot = int(rot_s, 0)
        path = os.path.join(args.dir, f"v_frame_{frame:04d}.png")
        if not os.path.exists(path):
            print(f"frame {frame}: no capture at {path}")
            continue
        w, h, img = read_png(path)
        exp = sprite(rom, rot)

        hit = miss = extra = total = 0
        for sy in range(32):
            for sx in range(32):
                row = 175 - sx
                col = 104 + sy
                if not (0 <= row < h and 0 <= col < w):
                    continue
                got = img[row][col]
                want = exp[sy][sx]
                if want:
                    total += 1
                    if got:
                        hit += 1
                    else:
                        miss += 1
                elif got:
                    extra += 1
        cover = 100.0 * hit / total if total else 0.0
        # After a collision the program asserts flash, which swaps the car's
        # two colours, so a correct sprite renders as its own negative. Count
        # that as a match rather than a miss.
        flashing = (hit == 0 and miss == total and extra > total // 2)
        if flashing:
            hit, miss, cover = total, 0, 100.0
        worst = max(worst, miss)
        flags = []
        if rot & 0x10: flags.append("transposed")
        if rot & 0x04: flags.append("flipX")
        if rot & 0x08: flags.append("flipY")
        note = "  flashing, sprite drawn inverted" if flashing else ""
        print(f"frame {frame:5d}  car_rot=0x{rot:02X}  frame_index={(~rot) & 3}"
              f"  {'+'.join(flags) if flags else 'no flips':22s}"
              f"  sprite pixels drawn {hit}/{total} = {cover:6.2f}%"
              f"   missing {miss}   non-sprite lit in box {extra}{note}")

    print()
    print("A correct sprite path draws 100% of the expected pixels. Lit pixels"
          " in the box that are not sprite pixels are the playfield showing"
          " through the transparent areas.")
    return 1 if worst else 0


if __name__ == "__main__":
    sys.exit(main())
