#!/bin/sh
# Rebuild test.swf (SWF 6, like N) from Test.as with MTASC. Expected output.txt
# is the local Ruffle exporter trace (it never fires timers; this test uses
# onEnterFrame only): exporter -s -f 202 --trace-log output.txt test.swf <tmpdir>
cd "$(dirname "$0")" && ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -main -header 200:150:30 Test.as -swf test.swf -version 6
