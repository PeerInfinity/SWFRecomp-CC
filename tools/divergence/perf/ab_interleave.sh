#!/bin/bash
# Interleaved real-GPU A/B: after (seedling, slot-specialized) vs before
# (seedling_before, IC-only). Alternates rounds to cancel machine drift.
# Prereq: docs2 served on $PORT; both demos deployed; driver at C:\playwright.
set -u
PORT="${PORT:-8010}"
ROUNDS="${ROUNDS:-4}"
SETTLE="${SETTLE:-40}"
DRV="$(wslpath -w /mnt/c/playwright/seedling_perf.py)"
run() {  # $1 = demo name
  python.exe "$DRV" ours "http://localhost:$PORT/demo.html?test=avm2/$1&perfhud=1" "$SETTLE" 2>/dev/null \
    | tr -d '\r' | grep -oE '\{.*\}' | tail -1
}
echo "round,build,mean_ms,p95,present,avm_submit,fps,frames,throttled"
for r in $(seq 1 "$ROUNDS"); do
  for name in seedling seedling_before; do
    j=$(run "$name")
    m=$(echo "$j" | python3 -c "import sys,json; d=json.load(sys.stdin); print(f\"{d['mean']},{d['p95']},{d['present']},{d['avm_submit']},{d['fps']},{d['frames']},{d['throttled']}\")" 2>/dev/null || echo "ERR")
    echo "$r,$name,$m"
  done
done
