#!/usr/bin/env bash
# run_nloader.sh — recompile the injected n_loader.swf to the SWFRecomp
# graphics-native (OFFSCREEN_RENDER) build and run it HEADLESS, capturing the
# injected trace() output to native_run/trace.txt.
#
# Usage: ./run_nloader.sh [frames]   (default 300)
# Look for "N_COMPLETE" in native_run/trace.txt — that is the level-completion
# signal fired by NLoader's App_LevelPassedEvent wrapper.
set -euo pipefail
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
FRAMES="${1:-300}"
cd "$HERE"
python3 ../dj_probe/run_native.py n_loader.swf native_run --frames "$FRAMES"
echo "--- completion / heartbeat lines ---"
grep -E 'nloader|N_COMPLETE|NT[0-9]+ ' native_run/trace.txt | head -40 || true
