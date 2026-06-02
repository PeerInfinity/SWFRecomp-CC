#!/usr/bin/env bash
# run_wasm.sh — serve the graphics-WASM DJ probe build + wasm_harness.html and
# drive it in headed google-chrome (WebGPU via WSLg) via Playwright, capturing
# the probe's trace() output. Tier 3 (production runtime) of the DJ probe.
#
# Prereq: build the WASM first:
#   cp dj_probed.swf SWFRecomp/tests/flasharchive/Doodle_Jump_probe/test.swf
#   source emsdk/emsdk_env.sh
#   SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump_probe wasm --graphics
#
# Usage: ./run_wasm.sh [capture_seconds]   (STEER_KEYS=1 to drive Right/Left keys)
set -u
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
WASM_DIR="${ROOT}/SWFRecomp/tests/flasharchive/Doodle_Jump_probe/build/wasm"
AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8090}"
SECS="${1:-14}"

[ -z "${DISPLAY:-}" ] && { echo "ERROR: DISPLAY unset (need headed Chrome + WebGPU)"; exit 2; }
[ -f "${WASM_DIR}/Doodle_Jump_probe.wasm" ] || { echo "ERROR: build the WASM first (see header)"; exit 2; }

OUT="${HERE}/wasm_run"; mkdir -p "$OUT"
TMP="$(mktemp -d)"; HTTP_PID=""
cleanup() { [ -n "$HTTP_PID" ] && kill "$HTTP_PID" 2>/dev/null || true; rm -rf "$TMP"; }
trap cleanup EXIT

cp "${WASM_DIR}/Doodle_Jump_probe.wasm" "${WASM_DIR}/Doodle_Jump_probe.js" \
   "${WASM_DIR}/swf_bridge.js" "${TMP}/"
cp "${HERE}/wasm_harness.html" "${TMP}/"
if command -v fuser >/dev/null 2>&1; then fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true; sleep 0.3; fi
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) & HTTP_PID=$!
for _ in $(seq 1 40); do (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null && { exec 3>&- 3<&- 2>/dev/null; break; }; sleep 0.25; done

echo "--- driving WASM (${SECS}s)${STEER_KEYS:+ STEER_KEYS=$STEER_KEYS} ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/wasm_harness.html" \
  CHROME="$CHROME" CAPTURE_SECONDS="$SECS" STEER_KEYS="${STEER_KEYS:-0}" \
  SCREENSHOT_DIR="${OUT}" \
  NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
  node "${HERE}/run_browser.js" | tee "${OUT}/console.txt"
echo "--- captured $(wc -l < "${OUT}/console.txt") lines -> ${OUT}/console.txt ---"
