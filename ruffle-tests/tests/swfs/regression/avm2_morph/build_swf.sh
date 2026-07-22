#!/bin/bash
# Rebuild test.swf: mxmlc compiles Main.as (getPixel gate) into a base SWF, then
# build_morph.py splices a hand-authored DefineMorphShape + 3 PlaceObject2 (ratio
# 0 / 32768 / 65535) into frame 1. Morphs cannot be produced by [Embed]/mxmlc, so
# the morph geometry is emitted as raw SWF tag bytes.
set -euo pipefail
cd "$(dirname "$0")"
MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"
"${MXMLC}" -omit-trace-statements=false \
    -target-player=11.1 -static-link-runtime-shared-libraries=true \
    -default-size 400 400 -default-frame-rate 30 \
    -output base.swf Main.as
python3 build_morph.py base.swf test.swf
rm -f base.swf
echo "wrote test.swf"
