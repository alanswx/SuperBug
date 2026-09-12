#!/usr/bin/env python3
"""Build the Fire Truck ROM images the simulator reads with $readmemh.

Takes the MAME set and produces one file per region, laid out the way the
reference driver loads them:

  program   8 KB at $2000. The lower half is two byte-wide ROMs. The upper half
            is two pairs of nibble-wide PROMs, each pair recombined into bytes
            with the K1/J1 part supplying the high nibble.
  chars     2 KB, one ROM
  tiles     2 KB, one ROM
  car       1 KB, one ROM
  trailer   4 KB, two ROMs end to end

    tools/make_firetrk_hex.py roms/firetrk.zip roms/hex
"""
import os
import sys
import zipfile


def hexfile(path, data, width_bits=8):
    with open(path, "w") as f:
        for i in range(0, len(data), 16):
            row = data[i:i + 16]
            if width_bits == 4:
                f.write(" ".join("%01X" % (b & 0x0F) for b in row) + "\n")
            else:
                f.write(" ".join("%02X" % b for b in row) + "\n")
    print(f"  {os.path.basename(path):28s} {len(data):5d} bytes")


def main():
    zip_path = sys.argv[1] if len(sys.argv) > 1 else "roms/firetrk.zip"
    out_dir = sys.argv[2] if len(sys.argv) > 2 else "roms/hex"
    z = zipfile.ZipFile(zip_path)
    r = {n: z.read(n) for n in z.namelist()}

    # Program. Nibble pairs: the K1/J1 part is the high nibble, K2/J2 the low.
    prog = bytearray(0x2000)
    prog[0x0000:0x0800] = r["032823-02.c1"]
    prog[0x0800:0x1000] = r["032824-01.d1"]
    for i in range(0x800):
        prog[0x1000 + i] = ((r["032816-01.k1"][i] & 0x0F) << 4) | (r["032820-01.k2"][i] & 0x0F)
        prog[0x1800 + i] = ((r["032815-01.j1"][i] & 0x0F) << 4) | (r["032819-01.j2"][i] & 0x0F)

    print(f"writing Fire Truck ROM images from {zip_path}")
    hexfile(os.path.join(out_dir, "firetrk_prog.hex"), prog)
    hexfile(os.path.join(out_dir, "firetrk_chars.hex"), r["032827-01.r3"])
    hexfile(os.path.join(out_dir, "firetrk_tiles.hex"), r["032828-02.f5"])
    hexfile(os.path.join(out_dir, "firetrk_car.hex"), r["032831-01.p7"])
    hexfile(os.path.join(out_dir, "firetrk_trailer.hex"),
            r["032829-01.j5"] + r["032830-01.l5"])


if __name__ == "__main__":
    main()
