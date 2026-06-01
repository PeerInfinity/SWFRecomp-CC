#!/usr/bin/env bash
# run_swfbridge_native_livetest.sh — LIVE native test of the __swfBridge contract
# over APCpp. Proves the native __swfBridge EI handler (swf_bridge_native_external_call
# in action.c) round-trips against a REAL Archipelago server, not just the stub.
#
# Flow: start a local ChecksFinder seed-1 server, then run the swfbridge_native_live
# test under WITH_AP=1 verify_output.py (which builds the runtime + recompiled SWF,
# links APCpp, sets SWF_BRIDGE_CONFIG from the test's swf_bridge_config.json, runs
# the binary, and compares against output.txt). The native handler blocks until
# APCpp authenticates (+ settle) before the first frame, so the frame-based SWF can
# poll the starting item synchronously despite native's flat-out frame loop.
#
# NO_GRAPHICS native → no WebGPU/DISPLAY needed (runs headless, unlike the browser
# livetests). Not in the deterministic CI suite (needs a live server).
#
# Prereqs: APCpp built ($APCPP_BUILD/libAPCpp-static.a); Archipelago-CC venv +
# setup_ap_server.py. Usage: ./run_swfbridge_native_livetest.sh   (exit 0 = PASS)
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../.." && pwd)"
TEST_DIR="${ROOT}/ruffle-tests/tests/swfs/_rando/swfbridge_native_live"

APCPP_ROOT="${APCPP_ROOT:-$HOME/CC/APCpp}"
APCPP_BUILD="${APCPP_BUILD:-${APCPP_ROOT}/build}"
AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
AP_PY="${AP_PY:-${AP_REPO}/.venv/bin/python}"
AP_SETUP="${AP_REPO}/scripts/setup/setup_ap_server.py"
PORT="${AP_PORT:-38281}"

SERVER_STARTED=0
cleanup() {
    if [ "$SERVER_STARTED" = "1" ]; then
        echo "--- stopping AP server ---"
        "$AP_PY" "$AP_SETUP" --stop-only --port "$PORT" >/dev/null 2>&1 || true
        "$AP_PY" "$AP_SETUP" --cleanup-only --game checksfinder --seed 1 >/dev/null 2>&1 || true
    fi
}
trap cleanup EXIT

# --- preflight ---------------------------------------------------------------
[ -f "${APCPP_BUILD}/libAPCpp-static.a" ] || { echo "ERROR: APCpp not built at ${APCPP_BUILD}"; exit 2; }
[ -x "$AP_PY" ] || { echo "ERROR: Archipelago-CC venv python not found at ${AP_PY}"; exit 2; }
[ -f "$AP_SETUP" ] || { echo "ERROR: setup_ap_server.py not found at ${AP_SETUP}"; exit 2; }
command -v python3 >/dev/null 2>&1 || { echo "ERROR: python3 not found"; exit 2; }

# --- compile test.swf from Main.as (MTASC; std8 has ExternalInterface) -------
MTASC="${MTASC:-$HOME/CC/mtasc/bin/mtasc}"
MTASC_STD="${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}"
MTASC_STD8="${MTASC_STD8:-$HOME/CC/mtasc/ocaml/mtasc/std8}"
echo "--- compiling test.swf (MTASC) ---"
[ -x "$MTASC" ] || { echo "ERROR: mtasc not found at ${MTASC}"; exit 2; }
( cd "$TEST_DIR" && "$MTASC" -cp "$MTASC_STD" -cp "$MTASC_STD8" -cp . -main \
    -header 200:150:30 Main.as -swf test.swf -version 8 ) \
    || { echo "ERROR: MTASC compile failed"; exit 2; }

# --- start the AP server (ChecksFinder seed 1) -------------------------------
echo "--- starting AP server (checksfinder, seed 1, port ${PORT}) ---"
"$AP_PY" "$AP_SETUP" --cleanup-only --game checksfinder --seed 1 >/dev/null 2>&1 || true
"$AP_PY" "$AP_SETUP" --game checksfinder --seed 1 --port "$PORT" --no-monitor
SERVER_STARTED=1
for _ in $(seq 1 60); do
    if (exec 3<>"/dev/tcp/127.0.0.1/${PORT}") 2>/dev/null; then exec 3>&- 3<&- 2>/dev/null || true; break; fi
    sleep 0.5
done

# --- run the live test under WITH_AP=1 verify_output.py ----------------------
# Modest settle (the test asserts the outward round-trip, not an inward item, so
# we don't need to wait for inventory; block-until-connected already ensures the
# link is up before the first frame). verify_output.py exits 0 even on a mismatch,
# so parse its summary for the verdict.
echo "--- running swfbridge_native_live under WITH_AP=1 verify_output.py ---"
out="$(WITH_AP=1 SWF_BRIDGE_SETTLE_MS="${SWF_BRIDGE_SETTLE_MS:-1000}" \
    python3 "${ROOT}/ruffle-tests/verify_output.py" \
        --tests-dir "${ROOT}/ruffle-tests/tests/swfs/_rando" \
        --test=swfbridge_native_live --diff --verbose 2>&1)"
echo "$out"

echo ""
if echo "$out" | grep -qE "Pass: +1 \(100"; then
    echo "✅ NATIVE __swfBridge LIVE TEST PASSED (APCpp + real AP server)"
    exit 0
else
    echo "❌ NATIVE __swfBridge LIVE TEST FAILED"
    exit 1
fi
