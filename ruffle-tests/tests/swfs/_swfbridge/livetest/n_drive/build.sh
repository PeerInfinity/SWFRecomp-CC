#!/usr/bin/env bash
# build.sh SCRIPT [out.swf] - MTASC NDrive.as with SCRIPT baked in -> splice into N (v6!).
# SCRIPT: attempts joined by '/', each "ticks:KEYS|ticks:KEYS..." (KEYS from L,R,J; '-' = none).
set -euo pipefail
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
N_SWF="${N_SWF:-${ROOT}/SWFRecomp/tests/flasharchive/N/test.swf}"
OUT="${2:-${HERE}/n_drive.swf}"
W="$(mktemp -d)"; trap 'rm -rf "$W"' EXIT
sed -e "s#static var SCRIPT:String = \"\";#static var SCRIPT:String = \"$1\";#" \
    -e "s|static var AUTOKILL:Boolean = false;|static var AUTOKILL:Boolean = ${AUTOKILL:-false};|" \
    -e "s|static var START_LEVEL:Number = 0;|static var START_LEVEL:Number = ${START_LEVEL:-0};|" \
    -e "s|static var OBJHASH:Boolean = false;|static var OBJHASH:Boolean = ${OBJHASH:-false};|" \
    -e "s|static var CLIPDIFF:Boolean = false;|static var CLIPDIFF:Boolean = ${CLIPDIFF:-false};|" \
    -e "s|static var OBJDUMP:Boolean = false;|static var OBJDUMP:Boolean = ${OBJDUMP:-false};|" \
    -e "s|static var FREEZE:String = \"[^\"]*\";|static var FREEZE:String = \"${FREEZE-0:250,0:330,1:200,1:409,1:520,1:663,2:60}\";|" "$HERE/NDrive.as" > "$W/NDrive.as"
( cd "$W" && "$HOME/CC/mtasc/bin/mtasc" -cp "$HOME/CC/mtasc/ocaml/mtasc/std" -cp "$HOME/CC/mtasc/ocaml/mtasc/std8" -cp . -main \
	-header 640:480:30 NDrive.as -swf nd.swf -version 8 )
python3 "${ROOT}/tools/divergence/extract_bytecode.py" "$W/nd.swf" "$W/nd.bin" >/dev/null
python3 "${ROOT}/tools/divergence/inject_tracer.py" "$N_SWF" "$OUT" --bytecode "$W/nd.bin" --min-version 6 >/dev/null
echo "built $OUT"
