#!/bin/bash
# Rebuild test.swf: compile Test.as with mxmlc, then hex-patch decoyBody's
# first opcode to the undefined 0xf4 via create_test_swf.py.
set -euo pipefail
cd "$(dirname "$0")"
MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"
"${MXMLC}" -omit-trace-statements=false \
    -target-player=11.1 -static-link-runtime-shared-libraries=true \
    -default-size 550 400 -default-frame-rate 30 \
    -output test.clean.swf Test.as
python3 create_test_swf.py test.clean.swf test.swf
rm -f test.clean.swf
