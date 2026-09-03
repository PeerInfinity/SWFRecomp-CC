#!/bin/bash
# Rebuild test.swf (AVM2 parent) and child.swf (AVM2 child) from source.
# See README.md for what this test pins down.
set -euo pipefail
cd "$(dirname "$0")"
MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"
COMMON=(-omit-trace-statements=false -target-player=11.1
        -static-link-runtime-shared-libraries=true
        -default-size 200 150 -default-frame-rate 30)

# The child is built with -frames.frame so it has MORE THAN ONE frame: the
# child root's `totalFrames` is read out of its timeline table by character
# id, and the "no timeline row found" fallback is 1 (avm2_display.c
# total_frames), so a 1-frame child could not tell a hit from a miss.
"${MXMLC}" "${COMMON[@]}" \
    -frames.frame one Child -frames.frame two Second \
    -source-path . -output child.swf Child.as

"${MXMLC}" "${COMMON[@]}" -output test.swf Test.as
