#!/usr/bin/env bash
# record_demo.sh - run a test level + playback demo through real N (Ruffle) and
# record rich PER-FRAME telemetry to a JSON file (not just pass/fail).
#
# The test case (JSON: {levelId, level, demo}) is fed to the SWF via __swfBridge
# (injected as window.__N_CONFIG, which n_host_mock.js forwards through
# __swfConfig). NLoader plays the demo deterministically (1 game-tick/frame) and
# emits an "NF ..." telemetry line per frame + "NEV ..." events; n_record.mjs
# parses the captured console into record.json.
#
# Usage: ./record_demo.sh <testcase.json> [seconds]   (default 15)
#   -> record_run/console.txt (raw) and record_run/record.json (structured)
set -u
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROBE="${HERE}/../dj_probe"
AP_REPO="${AP_REPO:-$HOME/CC/Archipelago-CC}"
PLAYWRIGHT_NODE_MODULES="${PLAYWRIGHT_NODE_MODULES:-${AP_REPO}/node_modules}"
CHROME="${CHROME:-/usr/bin/google-chrome}"
HTTP_PORT="${HTTP_PORT:-8094}"
TESTCASE="${1:-}"
SECS="${2:-15}"

[ -z "${DISPLAY:-}" ] && { echo "ERROR: DISPLAY unset (need headed Chrome)"; exit 2; }
[ -z "$TESTCASE" ] && { echo "usage: ./record_demo.sh <testcase.json> [seconds]"; exit 2; }
[ -f "$TESTCASE" ] || { echo "ERROR: testcase not found: $TESTCASE"; exit 2; }
[ -f "${HERE}/n_loader.swf" ] || { echo "ERROR: run build_nloader.sh first"; exit 2; }

OUT="${HERE}/record_run"; mkdir -p "$OUT"
TMP="$(mktemp -d)"; HTTP_PID=""
cleanup() { [ -n "$HTTP_PID" ] && kill "$HTTP_PID" 2>/dev/null || true; rm -rf "$TMP"; }
trap cleanup EXIT

cp "${HERE}/n_loader.swf" "${HERE}/n_swf_bridge.js" "${HERE}/n_host_mock.js" "${TMP}/"
cp "${HERE}/n_ruffle_ei_harness.html" "${TMP}/ruffle_harness.html"
# Inject the test case as window.__N_CONFIG BEFORE n_host_mock.js runs (the mock
# reads window.__N_CONFIG || default), so the SWF receives this exact level+demo.
CFG_JSON="$(cat "$TESTCASE")"
python3 - "$TMP/ruffle_harness.html" "$CFG_JSON" <<'PY'
import sys
path, cfg = sys.argv[1], sys.argv[2]
html = open(path).read()
tag = '<script src="n_host_mock.js"></script>'
html = html.replace(tag, '<script>window.__N_CONFIG=' + cfg + ';</script>\n' + tag, 1)
open(path, 'w').write(html)
PY

if command -v fuser >/dev/null 2>&1; then fuser -k "${HTTP_PORT}/tcp" >/dev/null 2>&1 || true; sleep 0.3; fi
( cd "$TMP" && python3 -m http.server "$HTTP_PORT" >/dev/null 2>&1 ) & HTTP_PID=$!
for _ in $(seq 1 40); do (exec 3<>"/dev/tcp/127.0.0.1/${HTTP_PORT}") 2>/dev/null && { exec 3>&- 3<&- 2>/dev/null; break; }; sleep 0.25; done

echo "--- recording $(basename "$TESTCASE") under Ruffle (${SECS}s) ---"
HARNESS_URL="http://127.0.0.1:${HTTP_PORT}/ruffle_harness.html" \
  CHROME="$CHROME" CAPTURE_SECONDS="$SECS" \
  NODE_PATH="$PLAYWRIGHT_NODE_MODULES" \
  node "${PROBE}/run_browser.js" > "${OUT}/console.txt" 2>&1

node "${HERE}/n_record.mjs" "${OUT}/console.txt" "${OUT}/record.json"
echo "--- record.json summary ---"
node -e '
const r = JSON.parse(require("fs").readFileSync(process.argv[1]));
console.log("levelId:", r.meta.levelId, "result:", r.meta.result,
            "frames:", r.meta.frames, "completedTick:", r.meta.completedTick);
console.log("events:", JSON.stringify(r.events));
if (r.frames.length) { console.log("first frame:", JSON.stringify(r.frames[0]));
  console.log("last  frame:", JSON.stringify(r.frames[r.frames.length-1])); }
' "${OUT}/record.json"
