#!/bin/bash
# Build libswfruntime.a (wasm32-wasi) for in-browser linking
# Requires: WASI-SDK installed at PROJECT_ROOT/wasi-sdk
#
# Note: action.c and object.c are NOT included because they are too large
# for in-browser Clang — they are pre-compiled as .o files instead.
# SWF_VERSION is now a runtime variable (g_swf_version), set in main().
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
SWFMODERN_ROOT="${PROJECT_ROOT}/SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"

# Find WASI-SDK
WASI_SDK="${PROJECT_ROOT}/wasi-sdk"
if [ ! -d "${WASI_SDK}" ]; then
    echo "ERROR: WASI-SDK not found at ${WASI_SDK}"
    echo "Install WASI-SDK and create a symlink: ln -s wasi-sdk-VERSION wasi-sdk"
    exit 1
fi

WASI_CC="${WASI_SDK}/bin/clang"
WASI_AR="${WASI_SDK}/bin/llvm-ar"
WASI_SYSROOT="${WASI_SDK}/share/wasi-sysroot"

BUILD_DIR="${SWFRECOMP_ROOT}/build_wasm"
mkdir -p "${BUILD_DIR}"

# Create a stub constants.h for swf_core.c (the real one is generated per-SWF;
# the only values it needs — FRAME_X_MIN_TWIPS/FRAME_Y_MIN_TWIPS — have defaults)
echo "/* stub for library build */" > "${BUILD_DIR}/constants.h"

CFLAGS=(
    --target=wasm32-wasi
    --sysroot="${WASI_SYSROOT}"
    -DNO_GRAPHICS
    -I"${SWFMODERN_INC}"
    -I"${SWFMODERN_INC}/actionmodern"
    -I"${SWFMODERN_INC}/libswf"
    -I"${SWFMODERN_INC}/memory"
    -I"${SWFMODERN_ROOT}/lib/c-hashmap"
    -I"${SWFMODERN_ROOT}/lib/o1heap"
    -I"${SWFMODERN_SRC}/actionmodern"
    -I"${BUILD_DIR}"
    -mllvm -wasm-enable-sjlj
    -matomics -mbulk-memory
    -std=gnu17
    -O2
    -Wall
    -Wno-unused-variable
)

# Source files for NO_GRAPHICS runtime
# action.c and object.c are excluded — too large for in-browser compilation
SOURCES=(
    "${SWFMODERN_SRC}/actionmodern/variables.c"
    "${SWFMODERN_SRC}/utils.c"
    "${SWFMODERN_SRC}/libswf/swf_core.c"
    "${SWFMODERN_SRC}/libswf/tag.c"
    "${SWFMODERN_SRC}/libswf/tag_stubs.c"
    "${SWFMODERN_SRC}/libswf/hit_test.c"
    "${SWFMODERN_SRC}/memory/heap.c"
    "${SWFMODERN_ROOT}/lib/c-hashmap/map.c"
    "${SWFMODERN_ROOT}/lib/o1heap/o1heap.c"
)

echo "Building libswfruntime.a (wasm32-wasi)..."
echo "WASI-SDK: ${WASI_SDK}"
echo ""

OBJ_FILES=()
for src in "${SOURCES[@]}"; do
    base=$(basename "${src}" .c)
    obj="${BUILD_DIR}/${base}.o"
    echo "  Compiling: $(basename ${src})"
    "${WASI_CC}" "${CFLAGS[@]}" -c "${src}" -o "${obj}"
    OBJ_FILES+=("${obj}")
done

echo ""
echo "  Archiving: libswfruntime.a"
"${WASI_AR}" rcs "${BUILD_DIR}/libswfruntime.a" "${OBJ_FILES[@]}"

echo ""
echo "Built successfully:"
ls -lh "${BUILD_DIR}/libswfruntime.a"
