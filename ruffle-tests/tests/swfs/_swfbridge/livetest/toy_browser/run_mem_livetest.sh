#!/usr/bin/env bash
# run_mem_livetest.sh — probe whether flashPanel's memory-poke (host-initiated
# ExternalInterface.addCallback: configure-in / readState-out) survives the iframe
# boundary, under BOTH Ruffle and SWFRecomp. Builds the AVM1 stand-in (memprobe)
# as test.swf (for Ruffle) + graphics WASM (for SWFRecomp), serves both game pages
# + the parent harness, and drives headed google-chrome (the parent calls
# configure/readState across the iframe boundary into each runtime).
#
# Usage: ./run_mem_livetest.sh [--rebuild]   (exit 0 = PASS both runtimes)
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
TOY_DIR="${ROOT}/SWFRecomp/tests/memprobe"
BUILD_WASM="${TOY_DIR}/build/wasm"

AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8089}"

REBUILD=0
[ "${1:-}" = "--rebuild" ] && REBUILD=1

TMP="$(mktemp -d)"
HTTP_PID=""
cleanup() { [ -n "$HTTP_PID" ] && kill "$HTTP_PID" >/dev/null 2>&1 || true; rm -rf "$TMP"; }
trap cleanup EXIT

# --- preflight ---------------------------------------------------------------
[ -n "${DISPLAY:-}" ] || { echo "ERROR: DISPLAY unset — needs headed Chrome (WSLg/X)."; exit 2; }
[ -x "$CHROME" ] || { echo "ERROR: google-chrome not found at ${CHROME}"; exit 2; }
[ -d "${PLAYWRIGHT_NODE_MODULES}/playwright" ] || { echo "ERROR: playwright not under ${PLAYWRIGHT_NODE_MODULES}"; exit 2; }
command -v node >/dev/null 2>&1 || { echo "ERROR: node not found"; exit 2; }
command -v python3 >/dev/null 2>&1 || { echo "ERROR: python3 not found"; exit 2; }

# --- compile test.swf (MTASC; std8 has ExternalInterface) --------------------
MTASC="${MTASC:-$HOME/CC/mtasc/bin/mtasc}"
MTASC_STD="${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}"
MTASC_STD8="${MTASC_STD8:-$HOME/CC/mtasc/ocaml/mtasc/std8}"
if [ "$REBUILD" = "1" ] || [ ! -f "${TOY_DIR}/test.swf" ]; then
    echo "--- compiling memprobe test.swf (MTASC) ---"
    [ -x "$MTASC" ] || { echo "ERROR: mtasc not found at ${MTASC}"; exit 2; }
    ( cd "$TOY_DIR" && "$MTASC" -cp "$MTASC_STD" -cp "$MTASC_STD8" -cp . -main \
        -header 200:150:30 Main.as -swf test.swf -version 8 ) \
        || { echo "ERROR: MTASC compile failed"; exit 2; }
fi

# --- build the memprobe graphics WASM (if needed). Graphics build: the EI inward
#     bridge is exported there, and the graphics swf.c frame loop stays alive
#     (parked at emscripten_sleep) so the host can call readState between frames.
#     The game page provides a user gesture (button) to init WebGPU inside the
#     iframe (build_test.sh's NO_GRAPHICS wasm path is pre-existingly broken). ----
if [ "$REBUILD" = "1" ] || [ ! -f "${BUILD_WASM}/memprobe.wasm" ]; then
    echo "--- building memprobe graphics WASM ---"
    # shellcheck disable=SC1091
    source "${ROOT}/emsdk/emsdk_env.sh" >/dev/null 2>&1 || { echo "ERROR: emsdk_env.sh failed"; exit 2; }
    ( cd "${ROOT}/SWFRecomp" && ./scripts/build_test.sh memprobe wasm --graphics ) \
        || { echo "ERROR: graphics WASM build failed"; exit 2; }
fi
[ -f "${BUILD_WASM}/memprobe.wasm" ] || { echo "ERROR: wasm missing after build"; exit 2; }

# --- assemble served dir -----------------------------------------------------
cp "${BUILD_WASM}/memprobe.wasm" "${BUILD_WASM}/memprobe.js" "${TMP}/"
cp "${TOY_DIR}/test.swf" "${TMP}/"
cp "${HERE}/mem_parent.html" "${HERE}/mem_game_ruffle.html" "${HERE}/mem_game_swfrecomp.html" "${TMP}/"

# --- serve -------------------------------------------------------------------
if command -v fuser >/dev/null 2>&1; then fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true; sleep 0.5; fi
echo "--- serving on http://127.0.0.1:${HTTP_PORT} ---"
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) &
HTTP_PID=$!
for _ in $(seq 1 40); do
    if (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null; then exec 3>&- 3<&- 2>/dev/null || true; break; fi
    sleep 0.25
done

# --- drive headed Chrome -----------------------------------------------------
echo "--- running memory-poke iframe-boundary probe (headed google-chrome) ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/mem_parent.html" \
    CHROME="$CHROME" \
    NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
    node "${HERE}/mem_test.js"
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ MEMORY-POKE IFRAME-BOUNDARY PROBE PASSED (both runtimes)"
else
    echo "❌ MEMORY-POKE IFRAME-BOUNDARY PROBE FAILED (exit ${rc})"
fi
exit "$rc"
