#!/usr/bin/env bash
# run_wasm.sh — serve the graphics-WASM build of the loader-injected DJ plus
# the bridge/mock pages, drive in headed google-chrome (WebGPU via WSLg).
# Tier 3 = the production runtime; this run is ALSO the browser-WASM
# sustained-physics verification (zero-input bounce soak).
#
# Prereq:
#   cp dj_loader.swf ../../../../../../SWFRecomp/tests/flasharchive/Doodle_Jump_loader/test.swf
#   source ../../../../../../emsdk/emsdk_env.sh
#   ../../../../../../SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump_loader wasm --graphics
#
# Usage: ./run_wasm.sh [capture_seconds]
#   FIXTURE=1  — serve wasm_harness_fixture.html (NO bridge scripts: EI handler
#                never installs, the loader runs its baked FixtureData level
#                with the G|tick grant schedule). A/B diagnostic for EI-vs-
#                runtime issues; also the offline browser demo.
set -u
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
PROBE="${HERE}/../dj_probe"
WASM_DIR="${ROOT}/SWFRecomp/tests/flasharchive/Doodle_Jump_loader/build/wasm"
AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8092}"
SECS="${1:-30}"

[ -z "${DISPLAY:-}" ] && { echo "ERROR: DISPLAY unset (need headed Chrome + WebGPU)"; exit 2; }
[ -f "${WASM_DIR}/Doodle_Jump_loader.wasm" ] || { echo "ERROR: build the WASM first (see header)"; exit 2; }

OUT="${HERE}/wasm_run"; mkdir -p "$OUT"
TMP="$(mktemp -d)"; HTTP_PID=""
cleanup() { [ -n "$HTTP_PID" ] && kill "$HTTP_PID" 2>/dev/null || true; rm -rf "$TMP"; }
trap cleanup EXIT

cp "${WASM_DIR}/Doodle_Jump_loader.wasm" "${WASM_DIR}/Doodle_Jump_loader.js" "${TMP}/"
if [ -n "${FIXTURE:-}" ]; then
  cp "${HERE}/wasm_harness_fixture.html" "${TMP}/wasm_harness.html"
else
  cp "${HERE}/wasm_harness.html" \
     "${HERE}/region_4_4.js" "${HERE}/dj_swf_bridge.js" "${HERE}/dj_host_mock.js" "${TMP}/"
fi
if [ -n "${GRANT_AT_MS:-}" ]; then
  sed -i "s|<script src=\"dj_host_mock.js\">|<script>window.__DJ_GRANT_AT_MS=${GRANT_AT_MS};</script><script src=\"dj_host_mock.js\">|" "${TMP}/wasm_harness.html"
fi
if command -v fuser >/dev/null 2>&1; then fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true; sleep 0.3; fi
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) & HTTP_PID=$!
for _ in $(seq 1 40); do (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null && { exec 3>&- 3<&- 2>/dev/null; break; }; sleep 0.25; done

echo "--- driving WASM (${SECS}s) ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/wasm_harness.html" \
  CHROME="$CHROME" CAPTURE_SECONDS="$SECS" \
  SCREENSHOT_DIR="${OUT}" \
  NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
  node "${PROBE}/run_browser.js" | tee "${OUT}/console.txt"
echo "--- captured $(wc -l < "${OUT}/console.txt") lines -> ${OUT}/console.txt ---"
