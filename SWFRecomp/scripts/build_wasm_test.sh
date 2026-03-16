#!/bin/bash
# Build a single Ruffle test as a wasm32-wasi binary
# Usage: build_wasm_test.sh TEST_NAME
# Requires: WASI-SDK, libswfruntime.a (from build_wasm_runtime_lib.sh)
set -e

if [ -z "$1" ]; then
    echo "Usage: $0 TEST_NAME"
    echo "Example: $0 add"
    exit 1
fi

TEST_NAME="$1"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
SWFMODERN_ROOT="${PROJECT_ROOT}/SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"
TEST_DIR="${PROJECT_ROOT}/ruffle-tests/tests/swfs/avm1/${TEST_NAME}"

# Verify test exists
if [ ! -d "${TEST_DIR}" ]; then
    echo "ERROR: Test directory not found: ${TEST_DIR}"
    exit 1
fi

# Find WASI-SDK
WASI_SDK="${PROJECT_ROOT}/wasi-sdk"
if [ ! -d "${WASI_SDK}" ]; then
    echo "ERROR: WASI-SDK not found at ${WASI_SDK}"
    exit 1
fi

WASI_CC="${WASI_SDK}/bin/clang"
WASI_SYSROOT="${WASI_SDK}/share/wasi-sysroot"

# Check for pre-built runtime library
RUNTIME_LIB="${SWFRECOMP_ROOT}/build_wasm/libswfruntime.a"
if [ ! -f "${RUNTIME_LIB}" ]; then
    echo "ERROR: libswfruntime.a not found. Run build_wasm_runtime_lib.sh first."
    exit 1
fi

# Build directory
BUILD_DIR="${SWFRECOMP_ROOT}/build_wasm/tests/${TEST_NAME}"
rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"

# Copy generated files
cp "${TEST_DIR}/RecompiledScripts"/*.c "${BUILD_DIR}/" 2>/dev/null || true
cp "${TEST_DIR}/RecompiledScripts"/*.h "${BUILD_DIR}/" 2>/dev/null || true
cp "${TEST_DIR}/RecompiledTags"/*.c "${BUILD_DIR}/" 2>/dev/null || true
cp "${TEST_DIR}/RecompiledTags"/*.h "${BUILD_DIR}/" 2>/dev/null || true

# Copy main.c wrapper
cp "${SWFRECOMP_ROOT}/wasm_wrappers/main.c" "${BUILD_DIR}/"

# Copy runtime source files (action.c/object.c compiled from source per-SWF)
cp "${SWFMODERN_SRC}/actionmodern/action.c" "${BUILD_DIR}/"
cp "${SWFMODERN_SRC}/actionmodern/object.c" "${BUILD_DIR}/"

# Copy unicode_case_tables.h (included by action.c)
cp "${SWFMODERN_SRC}/actionmodern/unicode_case_tables.h" "${BUILD_DIR}/"

# Copy o1heap.h (needed by heap.h)
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "${BUILD_DIR}/"

# Copy map.h (needed by variables.c/action.c)
cp "${SWFMODERN_ROOT}/lib/c-hashmap/map.h" "${BUILD_DIR}/"

echo "Building WASI test: ${TEST_NAME}"
echo ""

CFLAGS=(
    --target=wasm32-wasi
    --sysroot="${WASI_SYSROOT}"
    -DNO_GRAPHICS
    -mllvm -wasm-enable-sjlj
    -I"${BUILD_DIR}"
    -I"${SWFMODERN_INC}"
    -I"${SWFMODERN_INC}/actionmodern"
    -I"${SWFMODERN_INC}/libswf"
    -I"${SWFMODERN_INC}/memory"
    -I"${SWFMODERN_ROOT}/lib/c-hashmap"
    -I"${SWFMODERN_ROOT}/lib/o1heap"
    -I"${SWFMODERN_SRC}/actionmodern"
    -include string.h
    -std=c17
    -O2
    -Wall
    -Wno-unused-variable
    -Wno-unused-but-set-variable
    -Wno-tautological-constant-out-of-range-compare
    -Wno-null-dereference
    -Wno-incompatible-pointer-types-discards-qualifiers
)

# Compile all .c files in the build directory
OBJ_FILES=()
for src in "${BUILD_DIR}"/*.c; do
    base=$(basename "${src}" .c)
    obj="${BUILD_DIR}/${base}.o"
    echo "  Compiling: $(basename ${src})"
    "${WASI_CC}" "${CFLAGS[@]}" -c "${src}" -o "${obj}"
    OBJ_FILES+=("${obj}")
done

# Link
echo ""
echo "  Linking: test.wasm"
"${WASI_CC}" --target=wasm32-wasi --sysroot="${WASI_SYSROOT}" \
    -mllvm -wasm-enable-sjlj \
    "${OBJ_FILES[@]}" \
    "${RUNTIME_LIB}" \
    -lm \
    -o "${BUILD_DIR}/test.wasm"

echo ""
echo "Built successfully:"
ls -lh "${BUILD_DIR}/test.wasm"
