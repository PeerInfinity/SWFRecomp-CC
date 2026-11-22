#!/usr/bin/env bash
# build.sh — MTASC NClick.as -> splice into N -> n_click.swf (like ../n_loader).
set -euo pipefail
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
N_SWF="${N_SWF:-${ROOT}/SWFRecomp/tests/flasharchive/N/test.swf}"
cd "$HERE"
"$HOME/CC/mtasc/bin/mtasc" -cp "$HOME/CC/mtasc/ocaml/mtasc/std" -cp "$HOME/CC/mtasc/ocaml/mtasc/std8" -cp . -main \
	-header 640:480:30 NClick.as -swf nclick.swf -version 8
python3 "${ROOT}/tools/divergence/extract_bytecode.py" nclick.swf nclick_bytecode.bin
python3 "${ROOT}/tools/divergence/inject_tracer.py" "$N_SWF" "$HERE/n_click.swf" --bytecode "$HERE/nclick_bytecode.bin"
