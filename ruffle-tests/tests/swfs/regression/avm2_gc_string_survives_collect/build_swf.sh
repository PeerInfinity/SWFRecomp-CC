#!/bin/bash
# Rebuild test.swf from Test.as (AS3 — mxmlc, not MTASC).
set -euo pipefail
cd "$(dirname "$0")"
MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"
"${MXMLC}" -omit-trace-statements=false \
    -target-player=11.1 -static-link-runtime-shared-libraries=true \
    -default-size 550 400 -default-frame-rate 30 \
    -output test.swf Test.as
