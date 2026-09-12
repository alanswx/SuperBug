#!/usr/bin/env python3
"""Compare two recordings by band energy rather than sample by sample.

Two runs of the same game never line up sample for sample, so comparing
waveforms is useless. This measures how the energy is spread across frequency
in each, which is what tells you whether a channel is at the right pitch and
roughly the right level.

    tools/wavcompare.py reference.wav ours.wav --from 4 --to 8

Prints one row per band with both levels in decibels relative to full scale and
the difference, plus the loudest band in each.
"""

import argparse
import math
import struct
import sys
import wave

# Twenty bands, roughly a third of an octave each, over the range these games
# actually use: engine rumble at the bottom, tyre screech and tones on top.
BANDS = [50, 63, 80, 100, 125, 160, 200, 250, 315, 400, 500, 630,
         800, 1000, 1250, 1600, 2000, 2500, 3150, 4000]


def read_mono(path, t0, t1):
    w = wave.open(path, "rb")
    rate, ch, width = w.getframerate(), w.getnchannels(), w.getsampwidth()
    if width != 2:
        raise SystemExit(f"{path}: expected 16-bit samples, got {width * 8}-bit")
    n = w.getnframes()
    start = min(int(t0 * rate), n)
    count = max(0, min(int((t1 - t0) * rate), n - start))
    w.setpos(start)
    raw = w.readframes(count)
    vals = struct.unpack("<%dh" % (len(raw) // 2), raw)
    if ch > 1:
        vals = vals[::ch]
    # remove the mean so a constant offset does not swamp the low bands
    if not vals:
        return rate, []
    mean = sum(vals) / len(vals)
    return rate, [v - mean for v in vals]


def goertzel(samples, rate, freq):
    """Energy at one frequency, normalised by length."""
    if not samples:
        return 0.0
    k = 2.0 * math.cos(2.0 * math.pi * freq / rate)
    s1 = s2 = 0.0
    for x in samples:
        s0 = x + k * s1 - s2
        s2, s1 = s1, s0
    power = s1 * s1 + s2 * s2 - k * s1 * s2
    return math.sqrt(max(power, 0.0)) / len(samples)


def db(v):
    return -120.0 if v <= 1e-9 else 20.0 * math.log10(v / 32768.0)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("reference")
    ap.add_argument("candidate")
    ap.add_argument("--from", dest="t0", type=float, default=0.0)
    ap.add_argument("--to", dest="t1", type=float, default=2.0)
    args = ap.parse_args()

    ra, a = read_mono(args.reference, args.t0, args.t1)
    rb, b = read_mono(args.candidate, args.t0, args.t1)
    print(f"window {args.t0:.2f}s to {args.t1:.2f}s")
    print(f"  reference {args.reference}  {ra} Hz, {len(a)} samples")
    print(f"  candidate {args.candidate}  {rb} Hz, {len(b)} samples")
    print()
    print(f"{'band Hz':>8} {'reference dB':>13} {'ours dB':>9} {'diff':>7}")
    best_a = best_b = (None, -999.0)
    for f in BANDS:
        va, vb = db(goertzel(a, ra, f)), db(goertzel(b, rb, f))
        if va > best_a[1]:
            best_a = (f, va)
        if vb > best_b[1]:
            best_b = (f, vb)
        print(f"{f:8d} {va:13.1f} {vb:9.1f} {vb - va:7.1f}")
    # Shape score: line the two spectra up at their own peaks, so overall
    # loudness does not dominate, then average the absolute difference per
    # band. Lower is a closer match in timbre.
    sa = [db(goertzel(a, ra, f)) for f in BANDS]
    sb = [db(goertzel(b, rb, f)) for f in BANDS]
    pa, pb = max(sa), max(sb)
    score = sum(abs((x - pa) - (y - pb)) for x, y in zip(sa, sb)) / len(BANDS)
    print()
    print(f"loudest band: reference {best_a[0]} Hz, ours {best_b[0]} Hz")
    print(f"shape score: {score:.1f} dB mean difference per band, lower is closer")


if __name__ == "__main__":
    sys.exit(main())
