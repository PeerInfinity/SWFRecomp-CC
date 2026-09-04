#!/bin/bash
# Rebuild test.swf (AVM2 parent) and child.swf (AVM2 child) from source.
# See README.md for what this test pins down.
set -euo pipefail
cd "$(dirname "$0")"
MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"
COMMON=(-omit-trace-statements=false -target-player=11.1
        -static-link-runtime-shared-libraries=true
        -default-size 400 400 -default-frame-rate 30)

"${MXMLC}" "${COMMON[@]}" -source-path . -output child.swf Child.as
"${MXMLC}" "${COMMON[@]}" -source-path . -output test.swf Test.as
echo "wrote test.swf + child.swf"
