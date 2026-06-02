#!/usr/bin/env bash
# run_ruffle.sh — serve dj_probed.swf + ruffle_harness.html and drive it in
# headed google-chrome via Playwright, capturing the probe's trace() output.
# Tier 1 (ground truth) of the DJ flashSubstrate feasibility probe.
#
# Usage: ./run_ruffle.sh [capture_seconds]   (output -> ruffle_run/console.txt)
set -u
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8089}"
SECS="${1:-12}"

[ -z "${DISPLAY:-}" ] && { echo "ERROR: DISPLAY unset (need headed Chrome)"; exit 2; }
[ -f "${HERE}/dj_probed.swf" ] || { echo "ERROR: run build_probe.sh first"; exit 2; }

OUT="${HERE}/ruffle_run"; mkdir -p "$OUT"
TMP="$(mktemp -d)"; HTTP_PID=""
cleanup() { [ -n "$HTTP_PID" ] && kill "$HTTP_PID" 2>/dev/null || true; rm -rf "$TMP"; }
trap cleanup EXIT

cp "${HERE}/dj_probed.swf" "${HERE}/ruffle_harness.html" "${TMP}/"
if command -v fuser >/dev/null 2>&1; then fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true; sleep 0.3; fi
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) & HTTP_PID=$!
for _ in $(seq 1 40); do (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null && { exec 3>&- 3<&- 2>/dev/null; break; }; sleep 0.25; done

echo "--- driving Ruffle (${SECS}s)${CLICK_XY:+ click=$CLICK_XY} ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/ruffle_harness.html" \
  CHROME="$CHROME" CAPTURE_SECONDS="$SECS" \
  CLICK_XY="${CLICK_XY:-}" CLICK_DELAY="${CLICK_DELAY:-3000}" \
  SCREENSHOT_DIR="${OUT}" \
  NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
  node "${HERE}/run_browser.js" | tee "${OUT}/console.txt"
echo "--- captured $(wc -l < "${OUT}/console.txt") lines -> ${OUT}/console.txt ---"
