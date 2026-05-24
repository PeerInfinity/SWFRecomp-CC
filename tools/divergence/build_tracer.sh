#!/usr/bin/env bash
# Compile Tracer.as via MTASC into tracer.swf, then extract the AVM1 tag bytes
# into tracer_bytecode.bin. Outputs in this directory.
set -euo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
MTASC_BIN="${MTASC_BIN:-$HOME/CC/mtasc/bin/mtasc}"
MTASC_STD="${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}"

if [ ! -x "$MTASC_BIN" ]; then
    echo "MTASC not found at $MTASC_BIN" >&2
    echo "Set MTASC_BIN env var to override." >&2
    exit 1
fi
if [ ! -d "$MTASC_STD" ]; then
    echo "MTASC stdlib not found at $MTASC_STD" >&2
    exit 1
fi

cd "$HERE"
echo "Compiling Tracer.as -> tracer.swf"
"$MTASC_BIN" -cp "$MTASC_STD" \
    -main -header 200:150:30 -version 8 \
    Tracer.as -swf tracer.swf

echo "Extracting bytecode -> tracer_bytecode.bin"
python3 "$HERE/extract_bytecode.py" tracer.swf tracer_bytecode.bin

echo "OK"
ls -la "$HERE/tracer.swf" "$HERE/tracer_bytecode.bin"
