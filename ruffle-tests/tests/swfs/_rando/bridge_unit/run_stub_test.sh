#!/usr/bin/env bash
# run_stub_test.sh — server-free unit test of rando_bridge.js's StubTransport.
# Serves a minimal page (archipelago.js + rando_bridge.js + stub.html) and drives
# window.__randoBridge from headless chromium via Playwright, asserting the
# stub's connect + starting-item + sendLocation-grant contract. NO Archipelago
# server and NO WebSocket — unlike ../livetest/browser/run_browser_livetest.sh,
# this is a pure transport-contract test, so it's fast and dependency-light
# (only needs Playwright + chromium, not Archipelago-CC's server/venv).
#
# Usage: ./run_stub_test.sh        (exit 0 = PASS)
#
# See SWFRecompDocs/plans/archipelago-phase3-substrate-and-item-application.md.
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
RANDO_ASSETS="$(cd "${HERE}/../../../../../SWFRecomp/wasm_wrappers/rando" && pwd)"

# node_modules that contains 'playwright'. Defaults to the AP repo's; override
# with a SWFRecomp-local install when available.
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-$HOME/CC/Archipelago-CC/node_modules}"
HTTP_PORT="${HTTP_PORT:-8078}"

TMP="$(mktemp -d)"
HTTP_PID=""

cleanup() {
    [ -n "$HTTP_PID" ] && kill "$HTTP_PID" >/dev/null 2>&1 || true
    rm -rf "$TMP"
}
trap cleanup EXIT

# --- preflight ---------------------------------------------------------------
if [ ! -d "${PLAYWRIGHT_NODE_MODULES}/playwright" ]; then
    echo "ERROR: 'playwright' not found under ${PLAYWRIGHT_NODE_MODULES}"
    echo "  Set PLAYWRIGHT_NODE_MODULES to a node_modules dir that has playwright installed."
    exit 2
fi
command -v node >/dev/null 2>&1 || { echo "ERROR: node not found"; exit 2; }
command -v python3 >/dev/null 2>&1 || { echo "ERROR: python3 not found"; exit 2; }

# --- assemble the served page ------------------------------------------------
cp "${HERE}/stub.html" "${TMP}/"
cp "${RANDO_ASSETS}/archipelago.js" "${TMP}/"
cp "${RANDO_ASSETS}/rando_bridge.js" "${TMP}/"

# --- serve the page ----------------------------------------------------------
# Clear a stale listener on HTTP_PORT first (an interrupted prior run can orphan
# its backgrounded http.server). Kill by-port only (never -f patterns).
if command -v fuser >/dev/null 2>&1; then
    fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true
    sleep 0.5
fi
echo "--- serving stub harness on http://127.0.0.1:${HTTP_PORT} ---"
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) &
HTTP_PID=$!
for _ in $(seq 1 40); do
    if (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null; then exec 3>&- 3<&- 2>/dev/null || true; break; fi
    sleep 0.25
done

# --- run the Playwright driver ----------------------------------------------
echo "--- running Playwright StubTransport unit test (headless chromium) ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/stub.html" \
    NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
    node "${HERE}/stub_test.js"
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ STUB TRANSPORT UNIT TEST PASSED"
else
    echo "❌ STUB TRANSPORT UNIT TEST FAILED (exit ${rc})"
fi
exit "$rc"
