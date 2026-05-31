#!/usr/bin/env bash
# run_browser_livetest.sh — fully automated WASM/browser transport test for the
# Archipelago Rando bridge. Serves a minimal page (archipelago.js +
# rando_bridge.js), starts a local AP server, and drives the bridge from headless
# chromium via Playwright, asserting the connect + item + location round-trip.
#
# Transport-level: tests rando_bridge.js + archipelago.js + the browser
# WebSocket against a real server. No WASM/SWF/WebGPU. (The native APCpp path is
# covered by ../run_livetest.sh; the AVM1→C thunks by the rando_smoke unit test.)
#
# Requires:
#   - Archipelago-CC at $AP_REPO with its .venv (server) AND Playwright +
#     chromium installed (currently only the AP repo has Playwright; see
#     PLAYWRIGHT_NODE_MODULES below — point it at a SWFRecomp-local install once
#     this repo gets its own).
#   - python3 (for the static file server).
#
# Usage: ./run_browser_livetest.sh        (exit 0 = PASS)
#
# See SWFRecompDocs/plans/archipelago-phase2-wasm-bridge.md.
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
RANDO_ASSETS="$(cd "${HERE}/../../../../../../SWFRecomp/wasm_wrappers/rando" && pwd)"

AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
AP_PY="${AP_PY:-${AP_REPO}/.venv/bin/python}"
AP_SETUP="${AP_REPO}/scripts/setup/setup_ap_server.py"
# node_modules that contains 'playwright'. Defaults to the AP repo's; override
# with a SWFRecomp-local install when available.
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
AP_PORT="${AP_PORT:-38281}"
HTTP_PORT="${HTTP_PORT:-8076}"

TMP="$(mktemp -d)"
SERVER_STARTED=0
HTTP_PID=""

cleanup() {
    [ -n "$HTTP_PID" ] && kill "$HTTP_PID" >/dev/null 2>&1 || true
    if [ "$SERVER_STARTED" = "1" ]; then
        echo "--- stopping AP server ---"
        "$AP_PY" "$AP_SETUP" --stop-only --port "$AP_PORT" >/dev/null 2>&1 || true
        "$AP_PY" "$AP_SETUP" --cleanup-only --game checksfinder --seed 1 >/dev/null 2>&1 || true
    fi
    rm -rf "$TMP"
}
trap cleanup EXIT

# --- preflight ---------------------------------------------------------------
if [ ! -x "$AP_PY" ]; then
    echo "ERROR: Archipelago-CC venv python not found at ${AP_PY}"; exit 2
fi
if [ ! -d "${PLAYWRIGHT_NODE_MODULES}/playwright" ]; then
    echo "ERROR: 'playwright' not found under ${PLAYWRIGHT_NODE_MODULES}"
    echo "  Set PLAYWRIGHT_NODE_MODULES to a node_modules dir that has playwright installed."
    exit 2
fi
command -v node >/dev/null 2>&1 || { echo "ERROR: node not found"; exit 2; }
command -v python3 >/dev/null 2>&1 || { echo "ERROR: python3 not found"; exit 2; }

# --- assemble the served page ------------------------------------------------
cp "${HERE}/harness.html" "${TMP}/"
cp "${RANDO_ASSETS}/archipelago.js" "${TMP}/"
cp "${RANDO_ASSETS}/rando_bridge.js" "${TMP}/"

# --- start the AP server -----------------------------------------------------
echo "--- starting AP server (ChecksFinder, seed 1, port ${AP_PORT}) ---"
"$AP_PY" "$AP_SETUP" --cleanup-only --game checksfinder --seed 1 >/dev/null 2>&1 || true
"$AP_PY" "$AP_SETUP" --game checksfinder --seed 1 --port "$AP_PORT" --no-monitor
SERVER_STARTED=1

wait_port() {  # $1=host $2=port $3=label
    for _ in $(seq 1 60); do
        if (exec 3<>"/dev/tcp/$1/$2") 2>/dev/null; then exec 3>&- 3<&- 2>/dev/null || true; return 0; fi
        sleep 0.5
    done
    echo "ERROR: $3 did not come up on $1:$2"; return 1
}
wait_port 127.0.0.1 "$AP_PORT" "AP server" || exit 2

# --- serve the page ----------------------------------------------------------
# Clear a stale listener on HTTP_PORT first: an interrupted previous run can
# orphan its backgrounded http.server (the EXIT trap doesn't fire on hard kill),
# and the leftover would 404 this run's harness. Kill by-port only (never -f
# patterns, which can self-match this script's own command line).
if command -v fuser >/dev/null 2>&1; then
    fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true
    sleep 0.5
fi
echo "--- serving harness on http://localhost:${HTTP_PORT} ---"
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) &
HTTP_PID=$!
wait_port 127.0.0.1 "$HTTP_PORT" "http server" || exit 2

# --- run the Playwright driver ----------------------------------------------
echo "--- running Playwright transport test (headless chromium) ---"
HARNESS_URL="http://localhost:${HTTP_PORT}/harness.html" \
    NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
    node "${HERE}/browser_livetest.js"
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ BROWSER LIVE TEST PASSED"
else
    echo "❌ BROWSER LIVE TEST FAILED (exit ${rc})"
fi
exit "$rc"
