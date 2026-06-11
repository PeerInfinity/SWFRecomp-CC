#!/usr/bin/env bash
# build_loader.sh — compile Loader.as (+ generated FixtureData.as), extract its
# AVM1 bytecode, and splice it into the Doodle Jump SWF before the first
# ShowFrame. Same pipeline as ../dj_probe/build_probe.sh ("Probe.as grown up").
#
# Output: <this dir>/dj_loader.swf
#   STAGE_WIDTH=600 — also patch the header RECT (wide-stage build; regenerate
#   the fixture first: python3 gen_fixture.py --stage-width 600).
set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
MTASC="${MTASC:-$HOME/CC/mtasc/bin/mtasc}"
MTASC_STD="${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}"
MTASC_STD8="${MTASC_STD8:-$HOME/CC/mtasc/ocaml/mtasc/std8}"
DJ_SWF="${DJ_SWF:-${ROOT}/SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf}"

cd "$HERE"
[ -f FixtureData.as ] || { echo "FixtureData.as missing — run gen_fixture.py first"; exit 2; }

echo "--- compiling Loader.as -> loader.swf (MTASC, v8) ---"
"$MTASC" -cp "$MTASC_STD" -cp "$MTASC_STD8" -cp . -main \
	-header 240:400:30 Loader.as -swf loader.swf -version 8

echo "--- extracting bytecode -> loader_bytecode.bin ---"
python3 "${ROOT}/tools/divergence/extract_bytecode.py" loader.swf loader_bytecode.bin

echo "--- injecting into Doodle Jump -> dj_loader.swf ---"
python3 "${ROOT}/tools/divergence/inject_tracer.py" \
	"$DJ_SWF" "$HERE/dj_loader.swf" --bytecode "$HERE/loader_bytecode.bin" \
	${STAGE_WIDTH:+--stage-width "$STAGE_WIDTH"}

ls -la "$HERE/dj_loader.swf"
