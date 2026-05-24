#!/usr/bin/env bash
# Build the wasm-mp3-loading demo. Outputs demo.js, demo.wasm, demo.data.
# index.html is hand-written and references demo.js directly.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Source emsdk if emcc not already on PATH.
if ! command -v emcc >/dev/null 2>&1; then
    EMSDK_ENV="$SCRIPT_DIR/../../emsdk/emsdk_env.sh"
    if [[ -f "$EMSDK_ENV" ]]; then
        # shellcheck disable=SC1090
        source "$EMSDK_ENV"
    else
        echo "error: emcc not found and $EMSDK_ENV missing" >&2
        exit 1
    fi
fi

emcc demo.c \
    -O2 \
    -o demo.js \
    --preload-file assets@/assets \
    --js-library library_audio.js \
    -s FETCH=1 \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","FS","UTF8ToString","HEAPF32"]' \
    -s EXPORTED_FUNCTIONS='["_main","_play_bundled","_play_uploaded","_play_url","_malloc","_free"]' \
    -s MODULARIZE=0 \
    -s ENVIRONMENT=web

echo "built: demo.js, demo.wasm, demo.data"
ls -lh demo.js demo.wasm demo.data 2>/dev/null || true
