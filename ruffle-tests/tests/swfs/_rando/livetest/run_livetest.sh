#!/usr/bin/env bash
# run_livetest.sh — fully automated native round-trip test for the Archipelago
# Rando backend. Builds the rando_ap.cpp shim + a C harness, starts a local
# Archipelago server via Archipelago-CC's setup_ap_server.py, runs the harness,
# and tears the server down.
#
# Usage: ./run_livetest.sh [game]   (game = checksfinder | apquest; default checksfinder)
#                                    (exit 0 = PASS, non-zero = FAIL)
#   checksfinder — rando_ap_livetest.c (starting item + 1 location round-trip)
#   apquest      — rando_ap_livetest_apquest.c (no starting item; 2 location
#                  round-trips; own-location items filtered by APCpp). APQuest is
#                  the Phase 3 fixture; see
#                  SWFRecompDocs/plans/archipelago-phase3-substrate-and-item-application.md.
#
# Requires:
#   - APCpp built at $APCPP_BUILD  (cmake -S ~/CC/APCpp -B ~/CC/APCpp/build -DCMAKE_BUILD_TYPE=Release && cmake --build …)
#   - Archipelago-CC at $AP_REPO with its .venv set up (requirements installed)
#     and the seed generated (the setup script regenerates if needed).
#
# See SWFRecompDocs/plans/archipelago-randomizer-integration.md.
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFMODERN="$(cd "${HERE}/../../../../../SWFModernRuntime" && pwd)"
INC="${SWFMODERN}/include"

# --- select the game / harness ----------------------------------------------
GAME="${1:-checksfinder}"
case "$GAME" in
    checksfinder) HARNESS_SRC="rando_ap_livetest.c" ;;
    apquest)      HARNESS_SRC="rando_ap_livetest_apquest.c" ;;
    *) echo "ERROR: unknown game '$GAME' (expected checksfinder | apquest)"; exit 2 ;;
esac

APCPP_ROOT="${APCPP_ROOT:-$HOME/CC/APCpp}"
APCPP_BUILD="${APCPP_BUILD:-${APCPP_ROOT}/build}"
AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
AP_PY="${AP_PY:-${AP_REPO}/.venv/bin/python}"
AP_SETUP="${AP_REPO}/scripts/setup/setup_ap_server.py"
PORT="${PORT:-38281}"

TMP="$(mktemp -d)"
SERVER_STARTED=0

cleanup() {
    if [ "$SERVER_STARTED" = "1" ]; then
        echo "--- stopping AP server ---"
        "$AP_PY" "$AP_SETUP" --stop-only --port "$PORT" >/dev/null 2>&1 || true
        "$AP_PY" "$AP_SETUP" --cleanup-only --game "$GAME" --seed 1 >/dev/null 2>&1 || true
    fi
    rm -rf "$TMP"
}
trap cleanup EXIT

# --- preflight ---------------------------------------------------------------
if [ ! -f "${APCPP_BUILD}/libAPCpp-static.a" ]; then
    echo "ERROR: APCpp not built at ${APCPP_BUILD}"
    echo "  cmake -S ${APCPP_ROOT} -B ${APCPP_BUILD} -DCMAKE_BUILD_TYPE=Release && cmake --build ${APCPP_BUILD} -j"
    exit 2
fi
if [ ! -x "$AP_PY" ]; then
    echo "ERROR: Archipelago-CC venv python not found at ${AP_PY}"
    exit 2
fi

# --- build the shim + harness ------------------------------------------------
echo "--- building shim + harness ---"
g++ -c "${SWFMODERN}/src/actionmodern/rando_ap.cpp" \
    -std=c++11 -DWITH_AP \
    -I"${APCPP_ROOT}" -I"${APCPP_ROOT}/jsoncpp/include" \
    -I"${INC}" -I"${INC}/actionmodern" -I"${INC}/memory" \
    -o "${TMP}/rando_ap.o" || { echo "shim compile failed"; exit 2; }

gcc "${HERE}/${HARNESS_SRC}" "${TMP}/rando_ap.o" \
    -std=c17 -D_POSIX_C_SOURCE=200809L -I"${INC}" \
    "${APCPP_BUILD}/libAPCpp-static.a" \
    "${APCPP_BUILD}/IXWebSocket/libixwebsocket.a" \
    "${APCPP_BUILD}/lib/libjsoncpp.a" \
    -lssl -lcrypto -lz -lpthread -lstdc++ -lm \
    -o "${TMP}/livetest" || { echo "harness link failed"; exit 2; }

# --- start the AP server -----------------------------------------------------
echo "--- starting AP server (${GAME}, seed 1, port ${PORT}) ---"
"$AP_PY" "$AP_SETUP" --cleanup-only --game "$GAME" --seed 1 >/dev/null 2>&1 || true
"$AP_PY" "$AP_SETUP" --game "$GAME" --seed 1 --port "$PORT" --no-monitor
SERVER_STARTED=1

# Wait for the port to accept connections (max ~30s).
echo "--- waiting for server on 127.0.0.1:${PORT} ---"
ready=0
for _ in $(seq 1 60); do
    if (exec 3<>"/dev/tcp/127.0.0.1/${PORT}") 2>/dev/null; then
        exec 3>&- 3<&- 2>/dev/null || true
        ready=1
        break
    fi
    sleep 0.5
done
if [ "$ready" != "1" ]; then
    echo "ERROR: server did not start listening on ${PORT}"
    exit 2
fi

# --- run the harness ---------------------------------------------------------
# Run from $TMP so APCpp's datapackage cache (APCpp_datapkg.cache) lands in the
# temp dir (cleaned up on exit), not in the caller's working directory.
echo "--- running round-trip harness ---"
( cd "$TMP" && ./livetest )
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ LIVE TEST PASSED"
else
    echo "❌ LIVE TEST FAILED (exit ${rc})"
fi
exit "$rc"
