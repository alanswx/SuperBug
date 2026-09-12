#!/usr/bin/env bash
# Capture the same frames from MAME and from the Verilator build, then report
# how far apart they are, band by band.
#
#   tools/frame_compare.sh 100,200,300,400
#   SERVICE=1 tools/frame_compare.sh 200          # self-test screen
#
# Needs MAME built in mame/ and ./obj_dir/Vemu built in verilator/.
set -euo pipefail

FRAMES="${1:-100,200,300,400}"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="${OUT:-${TMPDIR:-/tmp}/superbug_compare}"
mkdir -p "$OUT/mame"

LAST=$(echo "$FRAMES" | tr ',' '\n' | sort -n | tail -1)
# MAME runs at 60 frames a second; give it the frames it needs plus headroom.
SECONDS_TO_RUN=$(( LAST / 60 + 4 ))

echo "=== MAME reference, frames $FRAMES ==="
( cd "$ROOT/mame" && SBSF_FRAMES="$FRAMES" SBSF_OUT="$OUT/mame" \
    ./mame -window -nothrottle -sound none -video none \
           -seconds_to_run "$SECONDS_TO_RUN" \
           -autoboot_script ../tools/superbug_snap_frames.lua superbug 2>&1 \
  | grep -E '^\[sbsf\]' || true )

echo "=== Verilator, frames $FRAMES ==="
SERVICE_FLAG=""
[ "${SERVICE:-0}" = "1" ] && SERVICE_FLAG="--service"
( cd "$ROOT/verilator" && ./obj_dir/Vemu --headless $SERVICE_FLAG \
    --screenshot "$FRAMES" --stop-at-frame $(( LAST + 2 )) \
    --screenshot-dir "$OUT" 2>&1 | grep -E '^screenshot' || true )

echo
for f in $(echo "$FRAMES" | tr ',' ' '); do
    M=$(printf "%s/mame/f%04d.png" "$OUT" "$f")
    V=$(printf "%s/v_frame_%04d.png" "$OUT" "$f")

    if [ -f "$M" ] && [ -f "$V" ]; then
        echo "----- frame $f -----"
        python3 "$ROOT/tools/pngdiff.py" "$M" "$V" --sweep --range 4
        echo
    else
        echo "frame $f: missing capture (mame=$M verilator=$V)"
    fi
done
