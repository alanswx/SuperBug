#!/usr/bin/env python3
"""Build a .rom from an MRA, the way the MiSTer main does before handing it to
the core.

This exists so the simulator is fed exactly what hardware will be fed, and so
the MRA is the only place the ROM layout is written down. It covers the subset
of the format these two games use: named parts taken from a zip, literal parts
given as hex, and byte interleaving.

    tools/mra.py "releases/Super Bug.mra" --zipdir roms --out roms/superbug.rom
    tools/mra.py "releases/Fire Truck.mra" --zipdir roms --verify

Note on the sebdel mra tool: this produces the same bytes for these MRAs, and
the layout it prints can be checked against it. It is not a replacement for the
real tool, only enough of it to build and test with.
"""
import argparse
import binascii
import os
import sys
import xml.etree.ElementTree as ET
import zipfile


def load_zip(zipdir, name):
    path = os.path.join(zipdir, name)
    if not os.path.exists(path):
        raise SystemExit(f"missing {path}")
    return zipfile.ZipFile(path)


def part_bytes(el, zf, zip_name):
    """One <part>: either a named file from the zip or literal hex."""
    name = el.get("name")
    if name is None:
        text = "".join(el.itertext()).split()
        return bytes(int(t, 16) for t in text)
    try:
        data = zf.read(name)
    except KeyError:
        raise SystemExit(f"{zip_name}: no part named {name}")
    want = el.get("crc")
    if want:
        got = "%08x" % (binascii.crc32(data) & 0xFFFFFFFF)
        if got.lower() != want.lower():
            raise SystemExit(f"{name}: crc {got} does not match the {want} in the MRA")
    return data


def interleave(el, zf, zip_name):
    """<interleave output="N">: take one byte at a time from each part."""
    width = int(el.get("output", "16")) // 8
    chunks = [part_bytes(p, zf, zip_name) for p in el.findall("part")]
    if not chunks:
        return b""
    n = len(chunks[0])
    if any(len(c) != n for c in chunks):
        raise SystemExit("interleave: parts differ in length")
    out = bytearray()
    for i in range(n):
        for c in chunks:
            out.append(c[i])
    return bytes(out)


def build(mra_path, zipdir):
    root = ET.parse(mra_path).getroot()
    images = {}
    layout = []
    for rom in root.findall("rom"):
        index = int(rom.get("index", "0"))
        zip_name = rom.get("zip")
        zf = load_zip(zipdir, zip_name) if zip_name else None
        blob = bytearray()
        for el in rom:
            if el.tag == "part":
                data = part_bytes(el, zf, zip_name or "(literal)")
            elif el.tag == "interleave":
                data = interleave(el, zf, zip_name or "(literal)")
            else:
                continue
            if index == 0:
                layout.append((len(blob), len(data), el.get("name") or "literal"))
            blob += data
        images[index] = bytes(blob)
    return images, layout


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("mra")
    ap.add_argument("--zipdir", default="roms")
    ap.add_argument("--out")
    ap.add_argument("--verify", action="store_true",
                    help="check regions against the simulator's hex images")
    args = ap.parse_args()

    images, layout = build(args.mra, args.zipdir)
    rom = images.get(0, b"")
    print(f"{args.mra}")
    for idx in sorted(images):
        print(f"  index {idx}: {len(images[idx])} bytes")
    print("  layout of index 0:")
    for off, size, name in layout:
        print(f"    0x{off:04X} +0x{size:04X}  {name}")

    out = args.out
    if out is None:
        name = ET.parse(args.mra).getroot().findtext("setname") or "out"
        out = os.path.join(os.path.dirname(args.mra) or ".", name + ".rom")
    with open(out, "wb") as f:
        f.write(rom)
    print(f"  wrote {out}")

    if args.verify:
        hexes = {
            "superbug": [(0x0000, "roms/hex/009121d1.hex"), (0x0800, "roms/hex/009122c1.hex"),
                         (0x1000, "roms/hex/009123a1.hex"), (0x1800, "roms/hex/009124m3.hex"),
                         (0x1C00, "roms/hex/009471n3.hex"), (0x2000, "roms/hex/009126f5.hex"),
                         (0x2400, "roms/hex/009472h5.hex"), (0x2800, "roms/hex/009127e5.hex"),
                         (0x2C00, "roms/hex/009125k6.hex")],
            "firetrka": [(0x0000, "roms/hex/firetrk_prog.hex"), (0x2000, "roms/hex/firetrk_chars.hex"),
                         (0x2800, "roms/hex/firetrk_tiles.hex"), (0x3000, "roms/hex/firetrk_car.hex"),
                         (0x3400, "roms/hex/firetrk_trailer.hex")],
        }
        setname = ET.parse(args.mra).getroot().findtext("setname")
        print("  verifying against the simulator's hex images:")
        ok = True
        for off, path in hexes.get(setname, []):
            ref = bytes(int(t, 16) for line in open(path) for t in line.split())
            got = rom[off:off + len(ref)]
            # nibble-wide ROMs are stored one nibble per byte in the hex
            if max(ref) < 0x10:
                got = bytes(b & 0x0F for b in got)
            same = got == ref
            ok &= same
            print(f"    0x{off:04X} {os.path.basename(path):24s} {'matches' if same else 'DIFFERS'}")
        print("  all regions match" if ok else "  SOME REGIONS DIFFER")
        return 0 if ok else 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
