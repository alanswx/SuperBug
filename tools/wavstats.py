#!/usr/bin/env python3
"""Summarise a captured WAV: level and dominant pitch over time.

Used to check the sound channels without listening to them. Reports, per
window, the peak-to-peak level and the strongest frequency found by counting
zero crossings, which is enough to tell whether the engine pitch tracks the
speed value and whether a channel is silent when it should be.
"""
import struct
import sys
import wave


def main():
    path = sys.argv[1]
    window_ms = float(sys.argv[2]) if len(sys.argv) > 2 else 250.0
    w = wave.open(path, "rb")
    rate = w.getframerate()
    n = w.getnframes()
    raw = w.readframes(n)
    data = struct.unpack("<%dh" % (len(raw) // 2), raw)
    print(f"{path}: {n} frames at {rate} Hz, {n / rate:.2f} s, "
          f"{w.getnchannels()} channel(s)")

    step = int(rate * window_ms / 1000.0)
    print(f"\n{'time':>8s} {'min':>7s} {'max':>7s} {'p-p':>7s} {'zero-x Hz':>10s}")
    for start in range(0, len(data) - step, step):
        chunk = data[start:start + step]
        lo, hi = min(chunk), max(chunk)
        mid = (lo + hi) // 2
        crossings = 0
        for i in range(1, len(chunk)):
            if (chunk[i - 1] <= mid) != (chunk[i] <= mid):
                crossings += 1
        freq = crossings * rate / (2.0 * len(chunk))
        flag = "  silent" if hi - lo < 64 else ""
        print(f"{start / rate:8.2f} {lo:7d} {hi:7d} {hi - lo:7d} {freq:10.1f}{flag}")


if __name__ == "__main__":
    main()
