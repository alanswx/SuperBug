#!/bin/sh
# Walk a vehicle's rotation register through all thirty-two values in both this
# core and the reference, and report the difference over the sprite for each.
#
# Ordinary play only ever reaches one or two of those values. The truck has to
# be turned a long way before the game picks the transposed sprite layout at
# all, and working the trailer's wheel that far jackknifes and ends the game,
# so a gameplay capture says nothing about the rest.
#
# Both sides have to be forced. On the reference side forcing means blanking
# the store instructions that write the register, because the program rewrites
# it every vertical blank and no frame callback can win that race.
#
#   tools/sprite_sweep.sh firetruck-car      # Fire Truck's cab, 32 rotations
#   tools/sprite_sweep.sh firetruck-trailer  # Fire Truck's trailer, 32 rotations
#   tools/sprite_sweep.sh superbug-car       # Super Bug's car, 32 rotations
set -e
MODE=${1:-firetruck-car}
OUT=${2:-/tmp/sprite_sweep/$MODE}
ROOT=$(cd "$(dirname "$0")/.." && pwd)
mkdir -p "$OUT/ours" "$OUT/ref"

# Region of the saved image to compare, and how each side is driven.
case "$MODE" in
    firetruck-car)
        REGION="140 178 100 140"; GAME=firetrk
        OURS_ARGS="--game 1 --car-rot"; REF_ENV="FR_ROT" ;;
    firetruck-trailer)
        REGION="95 168 52 126"; GAME=firetrk
        OURS_ARGS="--game 1 --drone-x 129 --drone-y 135 --drone-rot"
        REF_ENV="FR_DROT"; REF_EXTRA="FR_DX=129 FR_DY=135" ;;
    superbug-car)
        REGION="140 178 100 140"; GAME=superbug
        OURS_ARGS="--car-rot"; REF_ENV="FR_ROT"; REF_EXTRA="FR_CAR_ADDR=384" ;;
    *) echo "unknown mode: $MODE" >&2; exit 2 ;;
esac

echo "rendering this core..."
cd "$ROOT/verilator"
for r in $(seq 0 31); do
    # shellcheck disable=SC2086
    ./obj_dir/Vemu --headless $OURS_ARGS "$r" \
        --screenshot 200 --screenshot-name "$OUT/ours/rot$(printf %02d "$r").png" \
        --stop-at-frame 210 >/dev/null 2>&1
done

echo "rendering the reference..."
cd "$ROOT/mame"
for r in $(seq 0 31); do
    env FR_OUT="$OUT/ref" FR_NAME="rot$(printf %02d "$r")" FR_SNAP=200 \
        $REF_EXTRA "$REF_ENV=$r" \
        ./mame -window -nothrottle -sound none -video none -seconds_to_run 10 \
               -autoboot_script ../tools/firetrk_force_sprite.lua "$GAME" >/dev/null 2>&1
done

cd "$ROOT"
echo
fail=0
for r in $(seq -w 0 31); do
    # shellcheck disable=SC2086
    d=$(python3 tools/pngdiff.py "$OUT/ref/rot$r.png" "$OUT/ours/rot$r.png" \
            --region $REGION sprite 2>/dev/null | awk '/^sprite/ {print $2}')
    case "$d" in
        0.00%) printf "rot=%s  sprite=%s\n" "$r" "$d" ;;
        *)     printf "rot=%s  sprite=%s   <== differs\n" "$r" "$d"; fail=$((fail + 1)) ;;
    esac
done
echo
if [ "$fail" -eq 0 ]; then echo "PASS ($MODE): all 32 rotations match the reference"
else echo "FAIL ($MODE): $fail of 32 rotations differ"; exit 1; fi
