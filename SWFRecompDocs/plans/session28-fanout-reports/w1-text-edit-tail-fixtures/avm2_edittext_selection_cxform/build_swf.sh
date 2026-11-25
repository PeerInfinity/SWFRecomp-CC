#!/bin/bash
# The fixture SWF is create_test_swf.py's (no mxmlc needed):
#   python3 create_test_swf.py test.swf
# Optional mxmlc build of the AS3 twin (coordinator box; -omit-trace-statements=false is mandatory):
#   ./build_swf.sh mxmlc   -> test.mxmlc.swf
set -euo pipefail
cd "$(dirname "$0")"
if [ "${1:-}" = mxmlc ]; then
  MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"
  "${MXMLC}" -omit-trace-statements=false -target-player=11.1 -static-link-runtime-shared-libraries=true \
      -default-size 120 150 -default-frame-rate 30 -output test.mxmlc.swf Test.as
else
  python3 create_test_swf.py test.swf
fi
