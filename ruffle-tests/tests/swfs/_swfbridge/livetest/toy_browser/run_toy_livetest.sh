#!/usr/bin/env bash
# run_toy_livetest.sh — headed-Chrome live test of the converged Archipelago
# "swfrecomp" substrate, Mode 1 (opaque fixed AVM1 minigame). Builds the
# graphics-WASM minigame (SWFRecomp/tests/swfbridge_toy), serves it with the
# production __swfBridge shim + a mock-host harness, and drives it in REAL headed
# google-chrome via Playwright — asserting the full window.__swfBridge contract
# round-trip (configure / pollItems pull / sendLocation outward).
#
# Unlike the rando toy livetest this needs NO AP server and NO WITH_AP: the
# bridge is plain ExternalInterface (core runtime), and the harness's mock host
# plays Archipelago-CC's iframe-bridge role.
#
# Why headed Chrome (not Playwright's headless chromium): WebGPU needs a GPU
# compositor. The bundled headless chromium has no navigator.gpu; headed
# /usr/bin/google-chrome via WSLg/DISPLAY does (on a localhost secure-context
# page). So this REQUIRES an interactive display (DISPLAY set).
#
# Usage: ./run_toy_livetest.sh [--rebuild]   (exit 0 = PASS)
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
TOY_DIR="${ROOT}/SWFRecomp/tests/swfbridge_toy"
BUILD_WASM="${TOY_DIR}/build/wasm"

AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8087}"

REBUILD=0
[ "${1:-}" = "--rebuild" ] && REBUILD=1

TMP="$(mktemp -d)"
HTTP_PID=""

cleanup() {
    [ -n "$HTTP_PID" ] && kill "$HTTP_PID" >/dev/null 2>&1 || true
    rm -rf "$TMP"
}
trap cleanup EXIT

# --- preflight ---------------------------------------------------------------
if [ -z "${DISPLAY:-}" ]; then
    echo "ERROR: DISPLAY is unset. This test needs headed Chrome with a GPU"
    echo "  compositor (WSLg/X). Run it from an interactive terminal where WebGPU"
    echo "  works; it cannot run from a headless agent session."
    exit 2
fi
[ -x "$CHROME" ] || { echo "ERROR: google-chrome not found at ${CHROME}"; exit 2; }
[ -d "${PLAYWRIGHT_NODE_MODULES}/playwright" ] || { echo "ERROR: playwright not under ${PLAYWRIGHT_NODE_MODULES}"; exit 2; }
command -v node >/dev/null 2>&1 || { echo "ERROR: node not found"; exit 2; }
command -v python3 >/dev/null 2>&1 || { echo "ERROR: python3 not found"; exit 2; }

# --- compile test.swf from Main.as (MTASC; std8 has ExternalInterface) -------
MTASC="${MTASC:-$HOME/CC/mtasc/bin/mtasc}"
MTASC_STD="${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}"
MTASC_STD8="${MTASC_STD8:-$HOME/CC/mtasc/ocaml/mtasc/std8}"
if [ "$REBUILD" = "1" ] || [ ! -f "${TOY_DIR}/test.swf" ]; then
    echo "--- compiling test.swf from Main.as (MTASC) ---"
    [ -x "$MTASC" ] || { echo "ERROR: mtasc not found at ${MTASC}"; exit 2; }
    ( cd "$TOY_DIR" && "$MTASC" -cp "$MTASC_STD" -cp "$MTASC_STD8" -cp . -main \
        -header 200:150:30 Main.as -swf test.swf -version 8 ) \
        || { echo "ERROR: MTASC compile failed"; exit 2; }
fi

# --- build the graphics-WASM minigame (if needed) ----------------------------
if [ "$REBUILD" = "1" ] || [ ! -f "${BUILD_WASM}/swfbridge_toy.wasm" ]; then
    echo "--- building graphics-WASM toy (build_test.sh swfbridge_toy wasm --graphics) ---"
    # shellcheck disable=SC1091
    source "${ROOT}/emsdk/emsdk_env.sh" >/dev/null 2>&1 || { echo "ERROR: emsdk_env.sh failed"; exit 2; }
    ( cd "${ROOT}/SWFRecomp" && ./scripts/build_test.sh swfbridge_toy wasm --graphics ) \
        || { echo "ERROR: graphics WASM build failed"; exit 2; }
fi
[ -f "${BUILD_WASM}/swfbridge_toy.wasm" ] || { echo "ERROR: wasm missing after build"; exit 2; }

# --- assemble the served dir (WASM + shim + harness) -------------------------
cp "${BUILD_WASM}/swfbridge_toy.wasm" \
   "${BUILD_WASM}/swfbridge_toy.js" \
   "${BUILD_WASM}/swf_bridge.js" \
   "${TMP}/"
cp "${HERE}/harness.html" "${TMP}/"

# --- serve the assets --------------------------------------------------------
if command -v fuser >/dev/null 2>&1; then fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true; sleep 0.5; fi
echo "--- serving toy on http://127.0.0.1:${HTTP_PORT} ---"
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) &
HTTP_PID=$!
for _ in $(seq 1 40); do
    if (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null; then exec 3>&- 3<&- 2>/dev/null || true; break; fi
    sleep 0.25
done

# --- drive headed Chrome -----------------------------------------------------
echo "--- running __swfBridge live test (headed google-chrome) ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/harness.html" \
    CHROME="$CHROME" \
    NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
    node "${HERE}/toy_test.js"
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ __swfBridge SUBSTRATE LIVE TEST PASSED"
else
    echo "❌ __swfBridge SUBSTRATE LIVE TEST FAILED (exit ${rc})"
fi
exit "$rc"
