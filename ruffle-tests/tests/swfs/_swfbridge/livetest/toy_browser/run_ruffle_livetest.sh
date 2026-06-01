#!/usr/bin/env bash
# run_ruffle_livetest.sh — empirically confirm the __swfBridge contract is
# runtime-neutral by running the SAME AVM1 minigame (swfbridge_toy/test.swf) and
# the SAME bridge shim (swf_bridge.js) + mock host under Ruffle web instead of
# the SWFRecomp WASM runtime. No WASM build, no AP server: only MTASC (for the
# SWF) + the official @ruffle-rs/ruffle CDN bundle (loaded by the harness).
#
# Drives headed /usr/bin/google-chrome via Playwright (needs DISPLAY + network
# for the CDN). Asserts the same 8 conditions as run_toy_livetest.sh.
#
# Usage: ./run_ruffle_livetest.sh [--rebuild]   (exit 0 = PASS)
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
TOY_DIR="${ROOT}/SWFRecomp/tests/swfbridge_toy"

AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8088}"

REBUILD=0
[ "${1:-}" = "--rebuild" ] && REBUILD=1

TMP="$(mktemp -d)"
HTTP_PID=""
cleanup() { [ -n "$HTTP_PID" ] && kill "$HTTP_PID" >/dev/null 2>&1 || true; rm -rf "$TMP"; }
trap cleanup EXIT

# --- preflight ---------------------------------------------------------------
if [ -z "${DISPLAY:-}" ]; then
    echo "ERROR: DISPLAY is unset. Run from an interactive terminal (headed Chrome)."
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
[ -f "${TOY_DIR}/test.swf" ] || { echo "ERROR: test.swf missing"; exit 2; }

# --- assemble the served dir (SWF + shim + ruffle harness) -------------------
cp "${TOY_DIR}/test.swf" "${TMP}/"
cp "${ROOT}/SWFRecomp/wasm_wrappers/swf_bridge.js" "${TMP}/"
cp "${HERE}/ruffle_harness.html" "${TMP}/"

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
echo "--- running __swfBridge-under-Ruffle live test (headed google-chrome) ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/ruffle_harness.html" \
    CHROME="$CHROME" \
    NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
    node "${HERE}/ruffle_test.js"
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ __swfBridge-UNDER-RUFFLE LIVE TEST PASSED (runtime-neutral)"
else
    echo "❌ __swfBridge-UNDER-RUFFLE LIVE TEST FAILED (exit ${rc})"
fi
exit "$rc"
