#!/usr/bin/env bash
# run_toy_livetest.sh — headed-Chrome live test of the AVM2 ExternalInterface
# subset (avm2_external.c) over the __swfBridge page shim. The AS3/AVM2
# counterpart of ../toy_browser/run_toy_livetest.sh: compiles the AS3 toy
# (SWFRecomp/tests/swfbridge_toy_as3) with mxmlc, recompiles it with SWFRecomp,
# builds the AVM2 browser wasm (build_wasm_avm2.sh), serves it with the
# production swf_bridge_avm2.js shim + a mock-host harness, and drives REAL
# headed google-chrome via Playwright — asserting the 8-probe round-trip
# (available / wireCheck / configure / readState / stateChanged×2 /
# getItemQueue item application / DONE).
#
# Needs NO AP server: the harness's mock host plays the adapter role.
#
# Why headed Chrome (not headless): WebGPU needs a GPU compositor. Headless
# chromium has no navigator.gpu; headed /usr/bin/google-chrome via WSLg/DISPLAY
# does (on a localhost secure-context page). REQUIRES DISPLAY set.
#
# Usage: ./run_toy_livetest.sh [--rebuild]   (exit 0 = PASS)
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
TOY_DIR="${ROOT}/SWFRecomp/tests/swfbridge_toy_as3"
RECOMP_DIR="${TOY_DIR}/recompiled"
BUILD_DIR="${ROOT}/SWFRecomp/build_wasm_avm2/swfbridge_toy_as3"

AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8088}"
MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"

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
    echo "  compositor (WSLg/X). Run it from a session where WebGPU works."
    exit 2
fi
[ -x "$CHROME" ] || { echo "ERROR: google-chrome not found at ${CHROME}"; exit 2; }
[ -d "${PLAYWRIGHT_NODE_MODULES}/playwright" ] || { echo "ERROR: playwright not under ${PLAYWRIGHT_NODE_MODULES}"; exit 2; }
command -v node >/dev/null 2>&1 || { echo "ERROR: node not found"; exit 2; }
command -v python3 >/dev/null 2>&1 || { echo "ERROR: python3 not found"; exit 2; }

# --- compile test.swf from Main.as (AS3 — mxmlc, traces kept) -----------------
if [ "$REBUILD" = "1" ] || [ ! -f "${TOY_DIR}/test.swf" ]; then
    echo "--- compiling test.swf from Main.as (mxmlc) ---"
    [ -x "$MXMLC" ] || { echo "ERROR: mxmlc not found at ${MXMLC}"; exit 2; }
    ( cd "$TOY_DIR" && "$MXMLC" -omit-trace-statements=false \
        -target-player=11.1 -static-link-runtime-shared-libraries=true \
        -default-size 200 150 -default-frame-rate 30 \
        -output test.swf Main.as ) \
        || { echo "ERROR: mxmlc compile failed"; exit 2; }
fi

# --- recompile the SWF (SWFRecomp -> RecompiledABC/Scripts/Tags) --------------
if [ "$REBUILD" = "1" ] || [ ! -d "${RECOMP_DIR}/RecompiledABC" ]; then
    echo "--- recompiling test.swf (SWFRecomp) ---"
    [ -x "${ROOT}/SWFRecomp/build/SWFRecomp" ] || { echo "ERROR: SWFRecomp binary missing (build SWFRecomp first)"; exit 2; }
    rm -rf "$RECOMP_DIR"
    mkdir -p "$RECOMP_DIR"
    cp "${TOY_DIR}/test.swf" "${RECOMP_DIR}/"
    cp "${ROOT}/ruffle-tests/_shared/config.toml" "${RECOMP_DIR}/"
    ( cd "$RECOMP_DIR" && "${ROOT}/SWFRecomp/build/SWFRecomp" config.toml ) \
        || { echo "ERROR: recompile failed"; exit 2; }
fi

# --- build the AVM2 browser wasm ----------------------------------------------
if [ "$REBUILD" = "1" ] || [ ! -f "${BUILD_DIR}/swfbridge_toy_as3.wasm" ]; then
    echo "--- building AVM2 wasm (build_wasm_avm2.sh) ---"
    # shellcheck disable=SC1091
    source "${ROOT}/emsdk/emsdk_env.sh" >/dev/null 2>&1 || { echo "ERROR: emsdk_env.sh failed"; exit 2; }
    "${ROOT}/SWFRecomp/scripts/build_wasm_avm2.sh" swfbridge_toy_as3 "$RECOMP_DIR" \
        || { echo "ERROR: AVM2 wasm build failed"; exit 2; }
fi
[ -f "${BUILD_DIR}/swfbridge_toy_as3.wasm" ] || { echo "ERROR: wasm missing after build"; exit 2; }

# --- assemble the served dir (WASM + shim + harness) -------------------------
cp "${BUILD_DIR}/swfbridge_toy_as3.wasm" \
   "${BUILD_DIR}/swfbridge_toy_as3.js" \
   "${ROOT}/SWFRecomp/wasm_wrappers/swf_bridge_avm2.js" \
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
echo "--- running AVM2 ExternalInterface live test (headed google-chrome) ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/harness.html" \
    CHROME="$CHROME" \
    NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
    node "${HERE}/toy_test.js"
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ AVM2 ExternalInterface LIVE TEST PASSED"
else
    echo "❌ AVM2 ExternalInterface LIVE TEST FAILED (exit ${rc})"
fi
exit "$rc"
