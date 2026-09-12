#!/usr/bin/env python3
"""Compare two screenshots as binary lit/unlit pixel maps.

Written for comparing this core's Verilator output against MAME's `superbug`
driver. Super Bug's video is 1-bit-per-layer black and white, so thresholding
to lit/unlit removes MAME's colour-overlay artwork and our own greyscale
mapping from the comparison and leaves only the shapes.

Pure standard library on purpose: this tree's dev machine has neither NumPy
nor Pillow.

    tools/pngdiff.py MAME.png OURS.png
    tools/pngdiff.py MAME.png OURS.png --sweep          # vertical offset sweep
    tools/pngdiff.py MAME.png OURS.png --region 40 120 20 220 "pf upper"

A per-layer note, measured 2026-09-11: the alphanumeric layer and the car
sprite each reach an exact match at their own small vertical offset, and the
offsets differ per layer. Always check the sweep before concluding that a
layer's content is wrong.
"""

import argparse
import struct
import sys
import zlib


def read_png(path):
    """Return (width, height, rows) where rows[y][x] is 1 for a lit pixel."""
    data = open(path, "rb").read()
    if data[:8] != b"\x89PNG\r\n\x1a\n":
        raise ValueError(f"{path}: not a PNG")

    pos, idat, palette = 8, b"", None
    width = height = depth = colour = 0
    while pos < len(data):
        length, kind = struct.unpack(">I4s", data[pos:pos + 8])
        pos += 8
        chunk = data[pos:pos + length]
        pos += length + 4
        if kind == b"IHDR":
            width, height, depth, colour = struct.unpack(">IIBB", chunk[:10])
        elif kind == b"PLTE":
            palette = chunk
        elif kind == b"IDAT":
            idat += chunk
        elif kind == b"IEND":
            break

    if depth != 8:
        raise ValueError(f"{path}: only 8-bit channels supported, got {depth}")
    channels = {0: 1, 2: 3, 3: 1, 4: 2, 6: 4}[colour]

    raw = zlib.decompress(idat)
    stride = width * channels
    bpp = channels
    out = bytearray(height * stride)
    prev = bytearray(stride)
    p = 0
    for y in range(height):
        filt = raw[p]
        p += 1
        line = bytearray(raw[p:p + stride])
        p += stride
        if filt == 1:
            for i in range(bpp, stride):
                line[i] = (line[i] + line[i - bpp]) & 0xFF
        elif filt == 2:
            for i in range(stride):
                line[i] = (line[i] + prev[i]) & 0xFF
        elif filt == 3:
            for i in range(stride):
                left = line[i - bpp] if i >= bpp else 0
                line[i] = (line[i] + ((left + prev[i]) >> 1)) & 0xFF
        elif filt == 4:
            for i in range(stride):
                a = line[i - bpp] if i >= bpp else 0
                b = prev[i]
                c = prev[i - bpp] if i >= bpp else 0
                est = a + b - c
                da, db, dc = abs(est - a), abs(est - b), abs(est - c)
                pred = a if (da <= db and da <= dc) else (b if db <= dc else c)
                line[i] = (line[i] + pred) & 0xFF
        elif filt != 0:
            raise ValueError(f"{path}: bad row filter {filt}")
        out[y * stride:(y + 1) * stride] = line
        prev = line

    rows = []
    for y in range(height):
        row = []
        base = y * stride
        for x in range(width):
            i = base + x * channels
            if colour == 3:
                idx = out[i]
                r, g, b = palette[idx * 3], palette[idx * 3 + 1], palette[idx * 3 + 2]
            elif colour in (0, 4):
                r = g = b = out[i]
            else:
                r, g, b = out[i], out[i + 1], out[i + 2]
            row.append(1 if (r + g + b) > 120 else 0)
        rows.append(row)
    return width, height, rows


def diff(a, b, y0, y1, x0, x1, dy=0, dx=0):
    h, w = len(b), len(b[0])
    bad = 0
    for y in range(y0, y1):
        yy = y + dy
        for x in range(x0, x1):
            xx = x + dx
            if not (0 <= yy < h and 0 <= xx < w):
                bad += 1
            elif a[y][x] != b[yy][xx]:
                bad += 1
    return bad


def pct(n, y0, y1, x0, x1):
    return 100.0 * n / ((y1 - y0) * (x1 - x0))


# Default bands for Super Bug's 240x320 rotated output: the two text rows top
# and bottom, and the scrolling playfield between them.
DEFAULT_REGIONS = [
    ("top text", 2, 30, 10, 230),
    ("playfield upper", 40, 120, 20, 220),
    ("playfield middle", 120, 200, 20, 220),
    ("playfield lower", 200, 280, 20, 220),
    ("bottom text", 292, 318, 10, 230),
]


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("reference", help="MAME screenshot")
    ap.add_argument("candidate", help="our screenshot")
    ap.add_argument("--sweep", action="store_true",
                    help="also sweep vertical offsets and report the best")
    ap.add_argument("--range", type=int, default=5, metavar="N",
                    help="offset sweep half-width (default 5)")
    ap.add_argument("--region", nargs=5, action="append", metavar=("Y0", "Y1", "X0", "X1", "NAME"),
                    help="extra region to report; repeatable")
    args = ap.parse_args()

    w1, h1, ref = read_png(args.reference)
    w2, h2, cand = read_png(args.candidate)
    print(f"reference {args.reference}  {w1}x{h1}")
    print(f"candidate {args.candidate}  {w2}x{h2}")
    if (w1, h1) != (w2, h2):
        print("warning: sizes differ, comparing the overlapping area")

    w, h = min(w1, w2), min(h1, h2)
    whole = diff(ref, cand, 0, h, 0, w)
    lit_ref = sum(sum(r[:w]) for r in ref[:h])
    lit_cand = sum(sum(r[:w]) for r in cand[:h])
    print(f"\nwhole frame: {whole} mismatched, {pct(whole, 0, h, 0, w):.2f}%"
          f"   lit reference {lit_ref}, lit candidate {lit_cand}")

    regions = list(DEFAULT_REGIONS)
    for y0, y1, x0, x1, name in args.region or []:
        regions.append((name, int(y0), int(y1), int(x0), int(x1)))

    print(f"\n{'region':18s} {'as-is':>8s}" + ("   best offset" if args.sweep else ""))
    for name, y0, y1, x0, x1 in regions:
        if y1 > h or x1 > w:
            continue
        base = diff(ref, cand, y0, y1, x0, x1)
        line = f"{name:18s} {pct(base, y0, y1, x0, x1):7.2f}%"
        if args.sweep:
            best = None
            for dy in range(-args.range, args.range + 1):
                d = diff(ref, cand, y0, y1, x0, x1, dy=dy)
                if best is None or d < best[0]:
                    best = (d, dy)
            line += f"   dy={best[1]:+d} -> {pct(best[0], y0, y1, x0, x1):6.2f}%"
        print(line)
    return 0


if __name__ == "__main__":
    sys.exit(main())
