#!/bin/bash
# Regenerates test.swf (SWF 7) with MTASC. Expected output.txt comes from the
# Ruffle exporter (~/CC/ruffle target/release/exporter --trace-log), not from
# SWFRecomp. Pins: closures keep their captured scope when called as object
# methods, array own methods, String.prototype methods, type-2 constructors,
# and as valueOf during == coercion (s22 w2-as-core, 0cea97b3e).
set -euo pipefail
cd "$(dirname "$0")"
~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -main -header 200:150:30 Test.as -swf test.swf -version 7
