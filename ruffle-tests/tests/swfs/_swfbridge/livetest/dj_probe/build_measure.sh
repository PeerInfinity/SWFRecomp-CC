#!/usr/bin/env bash
# build_measure.sh <experiment> — compile Measure.as with EXP=<experiment>,
# extract its AVM1 bytecode, splice into Doodle Jump -> dj_measure_<exp>.swf
# Experiments: ff_rest ff_launch bounce spring keys catch blue brown jetpack
set -euo pipefail

EXP="${1:?usage: build_measure.sh <experiment>}"
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
MTASC="${MTASC:-$HOME/CC/mtasc/bin/mtasc}"
MTASC_STD="${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}"
MTASC_STD8="${MTASC_STD8:-$HOME/CC/mtasc/ocaml/mtasc/std8}"
DJ_SWF="${DJ_SWF:-${ROOT}/SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf}"

TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT
sed "s/__EXP__/${EXP}/" "${HERE}/Measure.as" > "${TMP}/Measure.as"

echo "--- compiling Measure.as (EXP=${EXP}) ---"
"$MTASC" -cp "$MTASC_STD" -cp "$MTASC_STD8" -cp "$TMP" -main \
	-header 240:400:30 "${TMP}/Measure.as" -swf "${TMP}/measure.swf" -version 8

python3 "${ROOT}/tools/divergence/extract_bytecode.py" "${TMP}/measure.swf" "${TMP}/measure_bytecode.bin"
python3 "${ROOT}/tools/divergence/inject_tracer.py" \
	"$DJ_SWF" "${HERE}/dj_measure_${EXP}.swf" --bytecode "${TMP}/measure_bytecode.bin"
ls -la "${HERE}/dj_measure_${EXP}.swf"
