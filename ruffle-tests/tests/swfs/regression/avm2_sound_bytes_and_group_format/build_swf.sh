#!/bin/bash
# Rebuild test.swf from Test.as (AS3 — mxmlc, not MTASC). Expected output
# (output.txt) is the Ruffle exporter oracle's trace, never ours:
#   ~/CC/ruffle/target/release/exporter test.swf /tmp/x.png --trace-log /tmp/t.txt
# sound.mp3 is the asset of Ruffle's avm2/sound_load_multiple (embedded).
set -euo pipefail
cd "$(dirname "$0")"
MXMLC="${MXMLC:-$HOME/CC/flex-sdk/bin/mxmlc}"
"${MXMLC}" -omit-trace-statements=false \
    -target-player=11.1 -static-link-runtime-shared-libraries=true \
    -default-size 550 400 -default-frame-rate 30 \
    -output test.swf Test.as
