#!/usr/bin/env bash
# build_nloader.sh — compile NLoader.as, extract its AVM1 bytecode, and splice
# it into the "N" SWF (before the first ShowFrame) via inject_tracer.py.
# Mirrors ../dj_probe/build_probe.sh. Output: <this dir>/n_loader.swf
set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
MTASC="${MTASC:-$HOME/CC/mtasc/bin/mtasc}"
MTASC_STD="${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}"
MTASC_STD8="${MTASC_STD8:-$HOME/CC/mtasc/ocaml/mtasc/std8}"
N_SWF="${N_SWF:-${ROOT}/SWFRecomp/tests/flasharchive/N/test.swf}"

cd "$HERE"
echo "--- compiling NLoader.as -> nloader.swf (MTASC, v8) ---"
"$MTASC" -cp "$MTASC_STD" -cp "$MTASC_STD8" -cp . -main \
	-header 640:480:30 NLoader.as -swf nloader.swf -version 8

echo "--- extracting bytecode -> nloader_bytecode.bin ---"
python3 "${ROOT}/tools/divergence/extract_bytecode.py" nloader.swf nloader_bytecode.bin

echo "--- injecting into N -> n_loader.swf ---"
python3 "${ROOT}/tools/divergence/inject_tracer.py" \
	"$N_SWF" "$HERE/n_loader.swf" --bytecode "$HERE/nloader_bytecode.bin"

ls -la "$HERE/n_loader.swf"
