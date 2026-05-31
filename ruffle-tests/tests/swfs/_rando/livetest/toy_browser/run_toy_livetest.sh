#!/usr/bin/env bash
# run_toy_livetest.sh — full browser item-application live test (Phase 3 Slice 2b).
# Builds the single-SWF graphics-WASM toy (SWFRecomp/tests/rando_browser_toy),
# starts a local APQuest server, serves the demo assets + harness.html, and drives
# it in REAL headed google-chrome via Playwright — asserting the toy applies the
# Sword + Key items granted by its two live location checks.
#
# Why headed Chrome (not Playwright's headless chromium): WebGPU needs a GPU
# compositor. The bundled headless chromium has no navigator.gpu; headed
# /usr/bin/google-chrome via WSLg/DISPLAY does (on a localhost secure-context
# page). So this REQUIRES an interactive display (DISPLAY set) — it cannot run
# from a headless agent session. See
# SWFRecompDocs/plans/archipelago-phase3-substrate-and-item-application.md and
# SWFRecompDocs/guides/wasm-game-debugging-session-guide.md (headed-Chrome model).
#
# Usage: ./run_toy_livetest.sh [--rebuild]   (exit 0 = PASS)
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
TOY_DIR="${ROOT}/SWFRecomp/tests/rando_browser_toy"
BUILD_WASM="${TOY_DIR}/build/wasm"

AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
AP_PY="${AP_PY:-${AP_REPO}/.venv/bin/python}"
AP_SETUP="${AP_REPO}/scripts/setup/setup_ap_server.py"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
AP_PORT="${AP_PORT:-38281}"
HTTP_PORT="${HTTP_PORT:-8086}"

REBUILD=0
[ "${1:-}" = "--rebuild" ] && REBUILD=1

TMP="$(mktemp -d)"
SERVER_STARTED=0
HTTP_PID=""

cleanup() {
    [ -n "$HTTP_PID" ] && kill "$HTTP_PID" >/dev/null 2>&1 || true
    if [ "$SERVER_STARTED" = "1" ]; then
        echo "--- stopping AP server ---"
        "$AP_PY" "$AP_SETUP" --stop-only --port "$AP_PORT" >/dev/null 2>&1 || true
        "$AP_PY" "$AP_SETUP" --cleanup-only --game apquest --seed 1 >/dev/null 2>&1 || true
    fi
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
[ -x "$AP_PY" ] || { echo "ERROR: Archipelago-CC venv python not found at ${AP_PY}"; exit 2; }
[ -d "${PLAYWRIGHT_NODE_MODULES}/playwright" ] || { echo "ERROR: playwright not under ${PLAYWRIGHT_NODE_MODULES}"; exit 2; }
command -v node >/dev/null 2>&1 || { echo "ERROR: node not found"; exit 2; }
command -v python3 >/dev/null 2>&1 || { echo "ERROR: python3 not found"; exit 2; }

# --- build the graphics-WASM toy (if needed) ---------------------------------
# test.swf is git-ignored (regenerated from the committed Main.as), so compile it
# from source first (matches how the SWFRecomp/tests suite treats SWFs).
MTASC="${MTASC:-$HOME/CC/mtasc/bin/mtasc}"
MTASC_STD="${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}"
if [ "$REBUILD" = "1" ] || [ ! -f "${TOY_DIR}/test.swf" ]; then
    echo "--- compiling test.swf from Main.as (MTASC) ---"
    [ -x "$MTASC" ] || { echo "ERROR: mtasc not found at ${MTASC}"; exit 2; }
    ( cd "$TOY_DIR" && "$MTASC" -cp "$MTASC_STD" -cp . -main -header 200:150:30 \
        Main.as -swf test.swf -version 8 ) || { echo "ERROR: MTASC compile failed"; exit 2; }
fi
if [ "$REBUILD" = "1" ] || [ ! -f "${BUILD_WASM}/rando_browser_toy.wasm" ]; then
    echo "--- building graphics-WASM toy (WITH_AP=1 build_test.sh rando_browser_toy wasm --graphics) ---"
    # shellcheck disable=SC1091
    source "${ROOT}/emsdk/emsdk_env.sh" >/dev/null 2>&1 || { echo "ERROR: emsdk_env.sh failed"; exit 2; }
    ( cd "${ROOT}/SWFRecomp" && WITH_AP=1 ./scripts/build_test.sh rando_browser_toy wasm --graphics ) \
        || { echo "ERROR: graphics WASM build failed"; exit 2; }
fi
[ -f "${BUILD_WASM}/rando_browser_toy.wasm" ] || { echo "ERROR: wasm missing after build"; exit 2; }

# --- assemble the served dir (demo assets + harness) -------------------------
cp "${BUILD_WASM}/rando_browser_toy.wasm" \
   "${BUILD_WASM}/rando_browser_toy.js" \
   "${BUILD_WASM}/rando_bridge.js" \
   "${BUILD_WASM}/archipelago.js" \
   "${TMP}/"
cp "${HERE}/harness.html" "${TMP}/"

# --- start the AP server (APQuest seed 1) ------------------------------------
echo "--- starting AP server (apquest, seed 1, port ${AP_PORT}) ---"
"$AP_PY" "$AP_SETUP" --cleanup-only --game apquest --seed 1 >/dev/null 2>&1 || true
"$AP_PY" "$AP_SETUP" --game apquest --seed 1 --port "$AP_PORT" --no-monitor
SERVER_STARTED=1
for _ in $(seq 1 60); do
    if (exec 3<>"/dev/tcp/127.0.0.1/${AP_PORT}") 2>/dev/null; then exec 3>&- 3<&- 2>/dev/null || true; break; fi
    sleep 0.5
done

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
echo "--- running toy live test (headed google-chrome) ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/harness.html" \
    CHROME="$CHROME" \
    NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
    node "${HERE}/toy_test.js"
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ BROWSER TOY LIVE TEST PASSED"
else
    echo "❌ BROWSER TOY LIVE TEST FAILED (exit ${rc})"
fi
exit "$rc"
