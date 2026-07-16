#!/usr/bin/env bash
# run_seedling_livetest.sh — verify the INJECTED Seedling (flash-ap-api
# BridgeGeneric spliced into the original 598977_Seedling.swf by inject.py)
# against the AVM2 ExternalInterface subset, both behaviors:
#
#   A. WITHOUT the page shim: BridgeGeneric no-ops silently (EI
#      available=false) — zero bridge output, no errors, game boots.
#   B. WITH swf_bridge_avm2.js: full BridgeGeneric round-trip against a mock
#      host (wireCheck/configure/readState, Main resolution, stateChanged,
#      getItemQueue property write hasSword=true).
#
# Prereqs (this script does NOT regenerate them — they are multi-minute
# builds; see SWFRecompDocs/prompts/avm2-external-interface.md session log):
#   ~/CC/seedling_ap_build/Seedling_ap.swf      inject.py output (verified
#                                               clean via SWFRecomp --check-abc)
#   ~/CC/seedling_ap_build/recompiled/          SWFRecomp output for it
#   SWFRecomp/build_wasm_avm2/seedling_ap/      build_wasm_avm2.sh output
#
# Headed Chrome + WSLg/DISPLAY required (WebGPU), like the toy livetests.
#
# Usage: ./run_seedling_livetest.sh [name]   (exit 0 = PASS)
#   name = seedling_teleport_ap (default) — injected TELEPORT build: boots
#          straight into gameplay, so ALL probes run (incl. the hasSword
#          write round-trip).
#        = seedling_ap — injected ORIGINAL: state monitoring is gated on the
#          player starting the game (Main.SAVE_FILE is set in Main's
#          constructor, behind the NG preloader), so only the boot-time
#          probes run (FULL_B=0).
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
NAME="${1:-seedling_teleport_ap}"
FULL_B=1
[ "$NAME" = "seedling_ap" ] && FULL_B=0
BUILD_DIR="${ROOT}/SWFRecomp/build_wasm_avm2/${NAME}"

AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8089}"

TMP="$(mktemp -d)"
HTTP_PID=""
cleanup() {
    [ -n "$HTTP_PID" ] && kill "$HTTP_PID" >/dev/null 2>&1 || true
    rm -rf "$TMP"
}
trap cleanup EXIT

# --- preflight ---------------------------------------------------------------
if [ -z "${DISPLAY:-}" ]; then
    echo "ERROR: DISPLAY is unset (headed Chrome + WebGPU needs WSLg/X)."
    exit 2
fi
[ -x "$CHROME" ] || { echo "ERROR: google-chrome not found at ${CHROME}"; exit 2; }
[ -d "${PLAYWRIGHT_NODE_MODULES}/playwright" ] || { echo "ERROR: playwright not under ${PLAYWRIGHT_NODE_MODULES}"; exit 2; }
[ -f "${BUILD_DIR}/${NAME}.wasm" ] || { echo "ERROR: ${BUILD_DIR}/${NAME}.wasm missing — build it first:"; echo "  SWFRecomp/scripts/build_wasm_avm2.sh ${NAME} ~/CC/seedling_ap_build/<recompiled dir>"; exit 2; }

# --- assemble the served dir --------------------------------------------------
cp "${BUILD_DIR}/${NAME}.wasm" "${BUILD_DIR}/${NAME}.js" \
   "${ROOT}/SWFRecomp/wasm_wrappers/swf_bridge_avm2.js" \
   "${TMP}/"
# The harness templates reference seedling_ap.js; point them at this build.
sed "s/seedling_ap\.js/${NAME}.js/" "${HERE}/harness_noshim.html" > "${TMP}/harness_noshim.html"
sed "s/seedling_ap\.js/${NAME}.js/" "${HERE}/harness_shim.html" > "${TMP}/harness_shim.html"

# --- serve --------------------------------------------------------------------
if command -v fuser >/dev/null 2>&1; then fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true; sleep 0.5; fi
echo "--- serving injected Seedling on http://127.0.0.1:${HTTP_PORT} ---"
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) &
HTTP_PID=$!
for _ in $(seq 1 40); do
    if (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null; then exec 3>&- 3<&- 2>/dev/null || true; break; fi
    sleep 0.25
done

# --- drive --------------------------------------------------------------------
echo "--- running injected-Seedling EI live test (headed google-chrome) ---"
HARNESS_BASE="http://127.0.0.1:${HTTP_PORT}" \
    CHROME="$CHROME" \
    FULL_B="$FULL_B" \
    NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
    node "${HERE}/seedling_test.js"
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ INJECTED-SEEDLING EI LIVE TEST PASSED"
else
    echo "❌ INJECTED-SEEDLING EI LIVE TEST FAILED (exit ${rc})"
fi
exit "$rc"
