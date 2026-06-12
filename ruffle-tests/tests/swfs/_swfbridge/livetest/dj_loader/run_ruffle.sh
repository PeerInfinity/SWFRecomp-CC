#!/usr/bin/env bash
# run_ruffle.sh — serve the loader-injected DJ + harness + bridge/mock JS and
# drive it in headed google-chrome via Playwright (reuses ../dj_probe/
# run_browser.js for console capture). Ruffle = ground-truth tier.
#
# Usage: ./run_ruffle.sh [capture_seconds]   (output -> ruffle_run/console.txt)
#   GRANT_AT_MS=15000 (mock host grants "Brown platforms" at this wall-clock ms)
set -u
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROBE="${HERE}/../dj_probe"
AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8091}"
SECS="${1:-30}"

[ -z "${DISPLAY:-}" ] && { echo "ERROR: DISPLAY unset (need headed Chrome)"; exit 2; }
[ -f "${HERE}/dj_loader.swf" ] || { echo "ERROR: run build_loader.sh first"; exit 2; }

OUT="${HERE}/ruffle_run"; mkdir -p "$OUT"
TMP="$(mktemp -d)"; HTTP_PID=""
cleanup() { [ -n "$HTTP_PID" ] && kill "$HTTP_PID" 2>/dev/null || true; rm -rf "$TMP"; }
trap cleanup EXIT

cp "${HERE}/dj_loader.swf" \
   "${HERE}/regions.js" "${HERE}/dj_swf_bridge.js" "${HERE}/dj_host_mock.js" "${TMP}/"
if [ -n "${WIDE:-}" ]; then
  cp "${HERE}/ruffle_harness_wide.html" "${TMP}/ruffle_harness.html"
else
  cp "${HERE}/ruffle_harness.html" "${TMP}/"
fi
# INJECT_JS: arbitrary pre-mock window config (grant schedules, start
# region, etc.), e.g. INJECT_JS='window.__DJ_GRANTS=[{at:5000,item:"Left arrow"}]'
INJECT="${INJECT_JS:-}"
[ -n "${GRANT_AT_MS:-}" ] && INJECT="window.__DJ_GRANT_AT_MS=${GRANT_AT_MS};${INJECT}"
if [ -n "$INJECT" ]; then
  sed -i "s|<script src=\"dj_host_mock.js\">|<script>${INJECT}</script><script src=\"dj_host_mock.js\">|" "${TMP}/ruffle_harness.html"
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
