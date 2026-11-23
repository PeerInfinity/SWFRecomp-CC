#!/bin/sh
# Rebuild every fixture SWF from its generator (stdlib Python 3 only).
# s26 w1-avm1-dispatch-scope. Run from anywhere.
set -e
cd "$(dirname "$0")"
for d in avm1_*/; do
  d=${d%/}
  if [ "$d" = avm1_wrap_giveup_mixed_runs ]; then
    python3 "$d/create_test_swf.py" "$d/test.swf" 7
  else
    python3 "$d/create_test_swf.py" "$d/test.swf"
  fi
  echo "built $d/test.swf"
done
