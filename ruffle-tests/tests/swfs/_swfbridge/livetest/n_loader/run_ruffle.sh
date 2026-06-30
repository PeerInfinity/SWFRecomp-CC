#!/usr/bin/env bash
# run_ruffle.sh - serve n_loader.swf + harness and drive it in headed
# google-chrome via Playwright (reuses ../dj_probe/run_browser.js for console
# capture), capturing NLoader's trace() output. Ruffle = ground-truth tier.
#
# Why Ruffle: the SAME injected n_loader.swf runs directly (NO recompile - the
# SWFRecomp native path needs a ~4-min C build per change), so fixture iteration
# is seconds, and it validates the load+detect logic on real Flash independent of
# SWFRecomp. Look for "N_COMPLETE" in ruffle_run/console.txt.
#
# Usage: ./run_ruffle.sh [capture_seconds]   (output -> ruffle_run/console.txt)
set -u
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROBE="${HERE}/../dj_probe"
AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8093}"
SECS="${1:-15}"

[ -z "${DISPLAY:-}" ] && { echo "ERROR: DISPLAY unset (need headed Chrome)"; exit 2; }
[ -f "${HERE}/n_loader.swf" ] || { echo "ERROR: run build_nloader.sh first"; exit 2; }

OUT="${HERE}/ruffle_run"; mkdir -p "$OUT"
TMP="$(mktemp -d)"; HTTP_PID=""
cleanup() { [ -n "$HTTP_PID" ] && kill "$HTTP_PID" 2>/dev/null || true; rm -rf "$TMP"; }
trap cleanup EXIT

cp "${HERE}/n_loader.swf" "${TMP}/"
if [ -n "${QUEUE:-}" ]; then
  # QUEUE tier: host serves a BATCH of levels; SWF re-loads each after the prior
  # one completes (batch-verify throughput). __N_QUEUE from n_queue_testcases.js.
  cp "${HERE}/n_swf_bridge.js" "${HERE}/n_queue_host.js" "${HERE}/n_queue_testcases.js" "${TMP}/"
  cp "${HERE}/n_ruffle_queue_harness.html" "${TMP}/ruffle_harness.html"
  echo "(QUEUE mode: batch of levels fed via __swfConfig; re-load on each __swfSendExit)"
elif [ -n "${EI:-}" ]; then
  # EI tier: feed the level via ExternalInterface (__swfBridge) + host mock.
  cp "${HERE}/n_swf_bridge.js" "${HERE}/n_host_mock.js" "${TMP}/"
  cp "${HERE}/n_ruffle_ei_harness.html" "${TMP}/ruffle_harness.html"
  echo "(EI mode: level fed via __swfConfig, completion via __swfSendExit)"
else
  cp "${HERE}/n_ruffle_harness.html" "${TMP}/ruffle_harness.html"
fi
if command -v fuser >/dev/null 2>&1; then fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true; sleep 0.3; fi
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) & HTTP_PID=$!
for _ in $(seq 1 40); do (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null && { exec 3>&- 3<&- 2>/dev/null; break; }; sleep 0.25; done

echo "--- driving Ruffle (${SECS}s) ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/ruffle_harness.html" \
  CHROME="$CHROME" CAPTURE_SECONDS="$SECS" \
  SCREENSHOT_DIR="${OUT}" \
  NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
  node "${PROBE}/run_browser.js" | tee "${OUT}/console.txt"
echo "--- captured $(wc -l < "${OUT}/console.txt") lines -> ${OUT}/console.txt ---"
echo "=== NLoader + bridge trace (Ruffle console formatting stripped) ==="
# Ruffle wraps AVM trace() as "%cINFO%c web/src/log_adapter.rs:18%c <msg> color:..."
grep -E 'nloader|N_COMPLETE|NT[0-9]+ |\[bridge\]|\[host\]' "${OUT}/console.txt" \
  | sed -E 's/.*log_adapter\.rs:[0-9]+%c //; s/ color: whitesmoke.*$//' \
  || echo "(no loader trace captured)"
