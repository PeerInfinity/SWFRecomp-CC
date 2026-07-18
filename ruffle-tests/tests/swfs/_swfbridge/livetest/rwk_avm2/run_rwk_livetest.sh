#!/usr/bin/env bash
# run_rwk_livetest.sh — verify the INJECTED Robot Wants Kitty (flash-ap-api
# BridgeGeneric spliced into 529817_max_robotkitty.swf by inject.py; the
# canonical artifact lives in Archipelago-CC and is consumed READ-ONLY) against
# the AVM2 ExternalInterface subset, both behaviors:
#
#   A. WITHOUT the page shim: BridgeGeneric no-ops silently (EI
#      available=false) — zero bridge output, no errors, game boots.
#   B. WITH the packaged game page (docs2/examples/avm2/rwk_ap/game.html) in a
#      SAME-ORIGIN iframe: full BridgeGeneric round-trip against the canonical
#      robotkitty.json — wireCheck/configure/readState inbound, stateChanged
#      outbound, and the config-driven TELEPORT (remove_last_child +
#      new_instance xplor.PlayState, then Player.x/y path writes) re-verified
#      through readState.
#
# Unlike Seedling there is no NG-preloader gate, so ONE SWF reaches the full
# write -> apply -> re-report grade (Seedling needed a separate teleport build).
#
# Prereqs (this script does NOT regenerate them — they are multi-minute builds;
# see SWFRecompDocs/prompts/avm2-rwk-ap-handoff.md session log):
#   ~/CC/rwk_ap_build/recompiled/            SWFRecomp output for the injected SWF
#   SWFRecomp/build_wasm_avm2/rwk_ap/        build_wasm_avm2.sh output
#   docs2/examples/avm2/rwk_ap/game.html     deploy_wasm_avm2.sh output
#
# Headed Chrome + WSLg/DISPLAY required (WebGPU), like the toy livetests. RWK
# renders fine under WSL headed Chrome (no Seedling texture-array blowup).
#
# Usage: ./run_rwk_livetest.sh [--gates]   (exit 0 = PASS)
#   --gates  run the perf + memory sanity gates (rwk_gates.js) instead of the
#            contract ladder: the inbound EI round-trip cost, then a SOAK_MS
#            bridge-active gameplay soak asserting no abort/OOM. Slow (~11 min
#            at the default 600s soak).
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
MODE="${1:-ladder}"
DRIVER="rwk_test.js"
[ "$MODE" = "--gates" ] && DRIVER="rwk_gates.js"
NAME="rwk_ap"
BUILD_DIR="${ROOT}/SWFRecomp/build_wasm_avm2/${NAME}"
DEMO_DIR="${ROOT}/docs2/examples/avm2/${NAME}"

AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
RWK_CONFIG="${RWK_CONFIG:-${AP_REPO}/frontend/modules/flashPanel/games/robotkitty.json}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8091}"

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
[ -f "${RWK_CONFIG}" ] || { echo "ERROR: robotkitty.json not at ${RWK_CONFIG} (Archipelago-CC owns it)"; exit 2; }
[ -f "${BUILD_DIR}/${NAME}.wasm" ] || { echo "ERROR: ${BUILD_DIR}/${NAME}.wasm missing — build it first:"; echo "  SWFRecomp/scripts/build_wasm_avm2.sh ${NAME} ~/CC/rwk_ap_build/recompiled"; exit 2; }
[ -f "${DEMO_DIR}/game.html" ] || { echo "ERROR: ${DEMO_DIR}/game.html missing — deploy it first:"; echo "  DEMO_SWF=... SWFRecomp/scripts/deploy_wasm_avm2.sh ${NAME} ~/CC/rwk_ap_build/recompiled"; exit 2; }

# --- assemble the served dir --------------------------------------------------
# Behavior B serves the DEPLOYED page verbatim (game.html + shim + wasm) — the
# artifact Archipelago-CC iframes — so the test grades the real deliverable.
cp "${DEMO_DIR}/game.html" "${DEMO_DIR}/swf_bridge_avm2.js" "${TMP}/"
cp "${BUILD_DIR}/${NAME}.wasm" "${BUILD_DIR}/${NAME}.js" "${TMP}/"
cp "${HERE}/parent.html" "${HERE}/harness_noshim.html" "${TMP}/"

# --- serve --------------------------------------------------------------------
if command -v fuser >/dev/null 2>&1; then fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true; sleep 0.5; fi
echo "--- serving injected RWK on http://127.0.0.1:${HTTP_PORT} ---"
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) &
HTTP_PID=$!
for _ in $(seq 1 40); do
    if (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null; then exec 3>&- 3<&- 2>/dev/null || true; break; fi
    sleep 0.25
done

# --- drive --------------------------------------------------------------------
echo "--- running injected-RWK EI live test (headed google-chrome) ---"
HARNESS_BASE="http://127.0.0.1:${HTTP_PORT}" \
    CHROME="$CHROME" \
    RWK_CONFIG="$RWK_CONFIG" \
    SOAK_MS="${SOAK_MS:-600000}" \
    NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
    node "${HERE}/${DRIVER}"
rc=$?

echo ""
if [ "$rc" = "0" ]; then
    echo "✅ INJECTED-RWK EI LIVE TEST PASSED (${DRIVER})"
else
    echo "❌ INJECTED-RWK EI LIVE TEST FAILED (${DRIVER}, exit ${rc})"
fi
exit "$rc"
