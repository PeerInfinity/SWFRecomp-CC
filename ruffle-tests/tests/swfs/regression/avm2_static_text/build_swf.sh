#!/bin/bash
# Rebuild test.swf: mxmlc compiles Main.as (getPixel gate) into a base SWF, then
# build_statictext.py splices a hand-authored DefineFont3 + DefineText +
# PlaceObject2 into frame 1. A placed static DefineText is not readily emitted by
# mxmlc, so the font + text geometry is emitted as raw SWF tag bytes.
set -euo pipefail
cd "$(dirname "$0")"
MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"
"${MXMLC}" -omit-trace-statements=false \
    -target-player=11.1 -static-link-runtime-shared-libraries=true \
    -default-size 200 200 -default-frame-rate 30 \
    -output base.swf Main.as
python3 build_statictext.py base.swf test.swf
rm -f base.swf
echo "wrote test.swf"
