#!/usr/bin/env bash
# build_probe.sh — compile Probe.as, extract its AVM1 bytecode, and splice it
# into the Doodle Jump SWF (before the first ShowFrame) via inject_tracer.py.
#
# This is the AS-INJECTION pipeline the flashSubstrate feasibility probe uses:
# the injected AS gets full access to DJ's live object graph and reports via
# trace() (which reaches stdout natively and the console under Ruffle/WASM).
#
# Output: <this dir>/dj_probed.swf  (feed to run_native.py, or recompile for WASM)
set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
MTASC="${MTASC:-$HOME/CC/mtasc/bin/mtasc}"
MTASC_STD="${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}"
MTASC_STD8="${MTASC_STD8:-$HOME/CC/mtasc/ocaml/mtasc/std8}"
DJ_SWF="${DJ_SWF:-${ROOT}/SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf}"

cd "$HERE"
echo "--- compiling Probe.as -> probe.swf (MTASC, v8) ---"
"$MTASC" -cp "$MTASC_STD" -cp "$MTASC_STD8" -cp . -main \
	-header 240:400:30 Probe.as -swf probe.swf -version 8

echo "--- extracting bytecode -> probe_bytecode.bin ---"
python3 "${ROOT}/tools/divergence/extract_bytecode.py" probe.swf probe_bytecode.bin

echo "--- injecting into Doodle Jump -> dj_probed.swf ---"
python3 "${ROOT}/tools/divergence/inject_tracer.py" \
	"$DJ_SWF" "$HERE/dj_probed.swf" --bytecode "$HERE/probe_bytecode.bin"

ls -la "$HERE/dj_probed.swf"
