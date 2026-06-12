#!/bin/bash
# build_wasm_memval.sh — rebuild the browser-WASM graphics build of
# flasharchive/Doodle_Jump_loader with in-wasm AddressSanitizer and
#  (HALLOC/FREE = dlmalloc so ASAN sees every allocation).
#
# Prereq: a normal `build_test.sh flasharchive/Doodle_Jump_loader wasm
# --graphics` run (its build/wasm dir provides the staged sources), and
# emsdk env sourced.
#
# Output: build/wasm_memval/Doodle_Jump_loader.{js,wasm}
set -e

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "${HERE}/../../../../../.." && pwd)"
SWFMODERN_INC="${ROOT}/SWFModernRuntime/include"
SWFMODERN_ROOT="${ROOT}/SWFModernRuntime"
TEST_DIR="${ROOT}/SWFRecomp/tests/flasharchive/Doodle_Jump_loader"
SRC_DIR="${TEST_DIR}/build/wasm"
BUILD_DIR="${TEST_DIR}/build/wasm_memval"

command -v emcc >/dev/null || { echo "source emsdk env first"; exit 1; }
[ -f "${SRC_DIR}/main.c" ] || { echo "run build_test.sh wasm --graphics first"; exit 1; }

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"
cp "${SRC_DIR}"/*.c "${SRC_DIR}"/*.h "$BUILD_DIR/" 2>/dev/null || true
mkdir -p "$BUILD_DIR/memory"
cp "${SRC_DIR}/memory/heap.h" "$BUILD_DIR/memory/"

cd "$BUILD_DIR"

EXPORTED_FUNCS='["_main","_runSWF","_audio_fill_buffer","_swf_ei_call_internal","_ng_ime_compose_set","_ng_ime_commit_set"]'
if [ -f display_bridge.c ]; then
    EXPORTED_FUNCS='["_main","_runSWF","_audio_fill_buffer","_getDisplayListJSON","_getSpriteChildrenJSON","_setObjectTransform","_swf_ei_call_internal","_ng_ime_compose_set","_ng_ime_commit_set"]'
    EXTRA_DEFINES="-DHAS_DISPLAY_BRIDGE"
fi

emcc \
    *.c \
    -DUSE_WEBGPU \
     \
    ${EXTRA_DEFINES:-} \
    -sMALLOC=emmalloc-memvalidate \
    --use-port=emdawnwebgpu \
    -Wno-error=implicit-function-declaration \
    -I. \
    -I"${SWFMODERN_INC}" \
    -I"${SWFMODERN_INC}/actionmodern" \
    -I"${SWFMODERN_INC}/libswf" \
    -I"${SWFMODERN_INC}/memory" \
    -I"${SWFMODERN_INC}/rendering" \
    -I"${SWFMODERN_INC}/audio" \
    -I"${SWFMODERN_ROOT}/lib/c-hashmap" \
    -o Doodle_Jump_loader.js \
    -s WASM=1 \
    -s EXPORTED_FUNCTIONS="${EXPORTED_FUNCS}" \
    -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","HEAPF32"]' \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s INITIAL_MEMORY=256MB \
    -s MAXIMUM_MEMORY=4096MB \
    -sASYNCIFY \
    -sASYNCIFY_STACK_SIZE=1048576 \
    -s ASSERTIONS=1 \
    -s NO_EXIT_RUNTIME=1 \
    -s STACK_OVERFLOW_CHECK=2 \
    -s STACK_SIZE=8MB \
    --profiling-funcs \
    -O1

echo "OK: ${BUILD_DIR}/Doodle_Jump_loader.wasm"
