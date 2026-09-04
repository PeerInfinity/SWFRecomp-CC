#!/bin/bash
# Rebuild test.swf (AVM2 parent) and child.swf (AVM2 child) from source. mxmlc
# compiles each root class into a base SWF, then build_statictext.py splices a
# hand-authored DefineFont3 + DefineText + PlaceObject2 into frame 1 of each —
# a placed static DefineText is not readily emitted by mxmlc. The two splices
# differ in glyph code, colour and pen x, which is what makes the child's run
# distinguishable from the parent's. See README.md.
set -euo pipefail
cd "$(dirname "$0")"
MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"
COMMON=(-omit-trace-statements=false -target-player=11.1
        -static-link-runtime-shared-libraries=true
        -default-size 400 400 -default-frame-rate 30)

"${MXMLC}" "${COMMON[@]}" -source-path . -output child_base.swf Child.as
python3 build_statictext.py child_base.swf child.swf \
    --code 66 --color 0000ff --penx 4200
rm -f child_base.swf

"${MXMLC}" "${COMMON[@]}" -source-path . -output base.swf Test.as
python3 build_statictext.py base.swf test.swf \
    --code 65 --color ff0000 --penx 200
rm -f base.swf
echo "wrote test.swf + child.swf"
