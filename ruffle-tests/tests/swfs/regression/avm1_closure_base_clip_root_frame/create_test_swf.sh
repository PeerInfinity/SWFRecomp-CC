#!/bin/bash
# Regenerates test.swf (SWF 6, DefineFunction2 bodies like N) with MTASC.
# Expected output.txt comes from the Ruffle exporter
# (~/CC/ruffle/target/release/exporter -s -f 3 --trace-log output.txt test.swf out),
# not from SWFRecomp. Pins: functions defined in the ROOT frame-1 script
# capture base_clip=_root, so calls from another clip's onEnterFrame read
# _root timeline variables (N "play game" fix, swf.c root context before tagMain).
# The bug was browser-WASM only; the browser-config twin of this test is
# SWFRecomp/tests/wasm_probes/closure_base_clip_root_frame.
set -euo pipefail
cd "$(dirname "$0")"
~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -main -header 200:150:30 Test.as -swf test.swf -version 6
