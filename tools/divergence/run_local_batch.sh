#!/bin/bash
# Driver: for each local_batch demo, rebuild the docs2 WASM demo from its
# flasharchive source SWF, then run the divergence test (--frames 16).
# Emits a structured, parseable block per demo to stdout.
#
# Usage: tools/divergence/run_local_batch.sh
set -u

REPO=~/CC/SWFRecomp-CC
cd "$REPO"
source emsdk/emsdk_env.sh 2>/dev/null
export GRAPHICS_BUILD_TIMEOUT=1800   # generous for big SWFs (Castle Hero 13MB)
FRAMES=16
TMPB=/tmp/divbatch

# flasharchive basenames (no extension). docs2 dir name is derived by
# build_swf_batch (spaces -> underscores). Divergence stem == basename.
DEMOS=(
  "Achievement Unlocked"
  "Age of War"
  "Art of War"
  "Avalanche"
  "Bloons"
  "Bloons TD"
  "Bloons TD 2"
  "Bloxorz"
  "Castle Hero"
  "Checkers"
  "Doodle Jump"
  "Duck Life 1"
  "Duck Life 2 - World Champion"
)

for name in "${DEMOS[@]}"; do
  swf=~/CC/flasharchive/"$name.swf"
  echo "########## DEMO: $name ##########"
  if [ ! -f "$swf" ]; then echo "STATUS: SOURCE_MISSING"; echo "########## END: $name ##########"; continue; fi

  # ---- 1. Rebuild docs2 WASM demo (one-at-a-time batch) ----
  rm -f "$TMPB"/*.swf 2>/dev/null
  mkdir -p "$TMPB"
  cp "$swf" "$TMPB/"
  wasm_out=$(SWFRecomp/scripts/build_swf_batch.sh "$TMPB" --docs-dir docs2 2>&1)
  if echo "$wasm_out" | grep -q "Built:   1"; then
    echo "WASM_BUILD: OK"
  else
    echo "WASM_BUILD: FAIL"
    echo "$wasm_out" | grep -iE "fail|error" | head -3
  fi

  # ---- 2. Divergence test ----
  div_out=$(python3 tools/divergence/divergence_test.py "$swf" --frames "$FRAMES" 2>&1)
  echo "$div_out" | grep -E "compile:|run:|outputs|version" | sed 's/^/  /'
  stem="$name"
  echo "----- divergence.txt -----"
  if [ -f "tools/divergence/runs/$stem/divergence.txt" ]; then
    cat "tools/divergence/runs/$stem/divergence.txt"
  else
    echo "(no divergence.txt)"
    echo "$div_out" | tail -8
  fi
  echo "----- F-line counts (binary-safe) -----"
  sf="tools/divergence/runs/$stem/swfrecomp/trace.txt"
  rf="tools/divergence/runs/$stem/ruffle/trace.txt"
  echo "  swfrecomp F-lines: $(grep -acE '^F[0-9]' "$sf" 2>/dev/null)  total: $(wc -l < "$sf" 2>/dev/null)"
  echo "  ruffle    F-lines: $(grep -acE '^F[0-9]' "$rf" 2>/dev/null)  total: $(wc -l < "$rf" 2>/dev/null)"
  echo "########## END: $name ##########"
  echo ""
done
echo "ALL_DEMOS_DONE"
