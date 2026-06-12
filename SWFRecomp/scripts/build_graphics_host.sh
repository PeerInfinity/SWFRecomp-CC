#!/bin/bash
# Build the graphics host module with Emscripten.
# This is the pre-built runtime for the in-browser recompiler's graphics mode.
# Contains: WebGPU renderer, frame loop, action VM, tag system, audio.
# Per-SWF generated code is compiled separately in-browser and linked via JS bridge.
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
SWFMODERN_ROOT="${PROJECT_ROOT}/SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"

BUILD_DIR="${SWFRECOMP_ROOT}/build_graphics_host"

# Source Emscripten
source "${PROJECT_ROOT}/emsdk/emsdk_env.sh"

mkdir -p "${BUILD_DIR}"

# Copy runtime sources to build dir
echo "Copying runtime sources..."
cp "${SWFMODERN_SRC}/actionmodern/action.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/object.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/variables.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/unicode_case_tables.h" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/utils.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/libswf/swf.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/libswf/tag.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/libswf/hit_test.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/rendering/render_webgpu.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/audio/audio.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/audio/audio_output_web.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/memory/heap.c" "${BUILD_DIR}/"
cp "${SWFMODERN_ROOT}/lib/c-hashmap/map.c" "${BUILD_DIR}/"
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.c" "${BUILD_DIR}/"
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "${BUILD_DIR}/"

# Copy host main
cp "${SWFRECOMP_ROOT}/wasm_wrappers/host_main_graphics.c" "${BUILD_DIR}/"

echo "Building graphics host module..."
cd "${BUILD_DIR}"


# First compile all .c to .o so we can extract defined symbols
echo "  Compiling sources to extract symbols..."
EMCC_FLAGS=(
    -DUSE_WEBGPU
    --use-port=emdawnwebgpu
    -I.
    -I"${SWFMODERN_INC}"
    -I"${SWFMODERN_INC}/actionmodern"
    -I"${SWFMODERN_INC}/libswf"
    -I"${SWFMODERN_INC}/memory"
    -I"${SWFMODERN_INC}/rendering"
    -I"${SWFMODERN_INC}/audio"
    -I"${SWFMODERN_ROOT}/lib/c-hashmap"
    -O2
)
ALL_C_FILES=(host_main_graphics.c swf.c tag.c hit_test.c render_webgpu.c
    audio.c audio_output_web.c action.c object.c variables.c utils.c
    heap.c map.c o1heap.c)
ALL_O_FILES=()
for src in "${ALL_C_FILES[@]}"; do
    obj="${src%.c}.o"
    emcc -c "${src}" "${EMCC_FLAGS[@]}" -o "${obj}"
    ALL_O_FILES+=("${obj}")
done

# Extract defined global function symbols from all .o files
echo "  Building export list from defined symbols..."
{
    for obj in "${ALL_O_FILES[@]}"; do
        "${PROJECT_ROOT}/emsdk/upstream/bin/llvm-nm" "${obj}" 2>/dev/null | grep " T " | awk '{print "\"_" $3 "\""}'
        "${PROJECT_ROOT}/emsdk/upstream/bin/llvm-nm" "${obj}" 2>/dev/null | grep " D " | awk '{print "\"_" $3 "\""}'
    done
} | sort -u > "${BUILD_DIR}/exports_raw.txt"

# Always include essential exports
cat >> "${BUILD_DIR}/exports_raw.txt" << 'EXTRA'
"_main"
"_malloc"
"_free"
EXTRA

# Format as JSON array
echo "[$(sort -u "${BUILD_DIR}/exports_raw.txt" | tr '\n' ',' | sed 's/,$//' )]" > "${BUILD_DIR}/exports_final.json"
EXPORT_COUNT=$(sort -u "${BUILD_DIR}/exports_raw.txt" | wc -l)
echo "  ${EXPORT_COUNT} symbols in export list"

emcc \
    "${ALL_C_FILES[@]}" \
    "${EMCC_FLAGS[@]}" \
    -o graphics_host.js \
    -s WASM=1 \
    -s EXPORTED_FUNCTIONS=@"${BUILD_DIR}/exports_final.json" \
    -s ALLOW_TABLE_GROWTH=1 \
    -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","addFunction","removeFunction","HEAPF32","wasmMemory","wasmTable"]' \
    -s SHARED_MEMORY=1 \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s MAXIMUM_MEMORY=2147483648 \
    -s INITIAL_MEMORY=209715200 \
    -s STACK_SIZE=8MB \
    -sASYNCIFY \
    -sASYNCIFY_STACK_SIZE=65536 \
    -O2

echo ""
echo "Built successfully:"
ls -lh "${BUILD_DIR}/graphics_host.js" "${BUILD_DIR}/graphics_host.wasm"
