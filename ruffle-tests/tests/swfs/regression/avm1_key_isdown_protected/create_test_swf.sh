#!/bin/sh
# Rebuild test.swf (SWF 6, like N) from Test.as with MTASC; expected output.txt
# is the local Ruffle exporter trace: exporter -s -f 2 --trace-log output.txt test.swf
cd "$(dirname "$0")" && ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -main -header 200:150:30 Test.as -swf test.swf -version 6
