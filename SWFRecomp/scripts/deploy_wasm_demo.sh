#!/bin/bash
# Deploy the in-browser SWF recompiler demo
# Packages SWFRecomp.wasm, libswfruntime.a, runtime sources, and headers
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
SWFMODERN_ROOT="${PROJECT_ROOT}/SWFModernRuntime"
SWFMODERN_SRC="${SWFMODERN_ROOT}/src"
SWFMODERN_INC="${SWFMODERN_ROOT}/include"

DEMO_DIR="${PROJECT_ROOT}/docs/recompiler"
BUILD_DIR="${SWFRECOMP_ROOT}/build_wasm"

# Check prerequisites
if [ ! -f "${BUILD_DIR}/SWFRecomp.js" ] || [ ! -f "${BUILD_DIR}/SWFRecomp.wasm" ]; then
    echo "ERROR: SWFRecomp.wasm not found. Run build_wasm_recompiler.sh first."
    exit 1
fi

if [ ! -f "${BUILD_DIR}/libswfruntime.a" ]; then
    echo "ERROR: libswfruntime.a not found. Run build_wasm_runtime_lib.sh first."
    exit 1
fi

DEMO_SRC="${SWFRECOMP_ROOT}/wasm_recompiler_demo"

echo "Deploying in-browser demo to ${DEMO_DIR}..."
mkdir -p "${DEMO_DIR}"

# Copy demo page source files
echo "  Copying demo page files..."
cp "${DEMO_SRC}/index.html" "${DEMO_DIR}/"
cp "${DEMO_SRC}/pipeline.js" "${DEMO_DIR}/"
cp "${DEMO_SRC}/wasi_shim.js" "${DEMO_DIR}/"
cp "${DEMO_SRC}/coi-serviceworker.js" "${DEMO_DIR}/"

# Copy Phase 1 output (SWFRecomp.wasm)
echo "  Copying SWFRecomp.wasm..."
cp "${BUILD_DIR}/SWFRecomp.js" "${DEMO_DIR}/SWFRecomp.js"
cp "${BUILD_DIR}/SWFRecomp.wasm" "${DEMO_DIR}/SWFRecomp.wasm"

# Copy pre-compiled runtime library
echo "  Copying libswfruntime.a..."
cp "${BUILD_DIR}/libswfruntime.a" "${DEMO_DIR}/libswfruntime.a"

# Copy runtime source files (action.c/object.c too large for in-browser Clang)
echo "  Copying runtime sources..."
mkdir -p "${DEMO_DIR}/runtime_src"
cp "${SWFMODERN_SRC}/actionmodern/action.c" "${DEMO_DIR}/runtime_src/"
cp "${SWFMODERN_SRC}/actionmodern/object.c" "${DEMO_DIR}/runtime_src/"
cp "${SWFMODERN_SRC}/actionmodern/unicode_case_tables.h" "${DEMO_DIR}/runtime_src/"
cp "${SWFMODERN_ROOT}/lib/o1heap/o1heap.h" "${DEMO_DIR}/runtime_src/"
cp "${SWFMODERN_ROOT}/lib/c-hashmap/map.h" "${DEMO_DIR}/runtime_src/"
cp "${SWFRECOMP_ROOT}/wasm_wrappers/main.c" "${DEMO_DIR}/runtime_src/"

# Copy runtime headers for the include paths
echo "  Copying runtime headers..."
mkdir -p "${DEMO_DIR}/runtime_headers"

# Build header manifest (maps virtual FS path → local filename)
MANIFEST="["

copy_header() {
    local src="$1"
    local vpath="$2"
    local fname=$(basename "$src")
    # Handle duplicate filenames by prefixing with directory
    local unique_name="${vpath//\//_}"
    unique_name="${unique_name#_}"  # Remove leading underscore
    cp "$src" "${DEMO_DIR}/runtime_headers/${unique_name}"
    MANIFEST="${MANIFEST}{\"path\":\"${vpath}\",\"file\":\"${unique_name}\"},"
}

# Headers are written to include/... inside the Wasmer Directory (mounted at /project)
# so Clang can find them via -I/project/include, -I/project/include/actionmodern, etc.

# Main include directory
copy_header "${SWFMODERN_INC}/common.h" "include/common.h"
copy_header "${SWFMODERN_INC}/utils.h" "include/utils.h"

# actionmodern headers
copy_header "${SWFMODERN_INC}/actionmodern/action.h" "include/actionmodern/action.h"
copy_header "${SWFMODERN_INC}/actionmodern/object.h" "include/actionmodern/object.h"
copy_header "${SWFMODERN_INC}/actionmodern/stackvalue.h" "include/actionmodern/stackvalue.h"
copy_header "${SWFMODERN_INC}/actionmodern/variables.h" "include/actionmodern/variables.h"

# libswf headers
copy_header "${SWFMODERN_INC}/libswf/recomp.h" "include/libswf/recomp.h"
copy_header "${SWFMODERN_INC}/libswf/swf.h" "include/libswf/swf.h"
copy_header "${SWFMODERN_INC}/libswf/tag.h" "include/libswf/tag.h"

# memory headers
copy_header "${SWFMODERN_INC}/memory/heap.h" "include/memory/heap.h"

# Close manifest JSON
MANIFEST="${MANIFEST%,}]"
echo "${MANIFEST}" > "${DEMO_DIR}/runtime_headers/manifest.json"

echo ""
echo "Demo deployed. Files:"
find "${DEMO_DIR}" -type f | sort | while read f; do
    size=$(stat --printf="%s" "$f" 2>/dev/null || stat -f "%z" "$f" 2>/dev/null)
    printf "  %-50s %s\n" "${f#${DEMO_DIR}/}" "$(numfmt --to=iec-i --suffix=B $size 2>/dev/null || echo "${size}B")"
done

echo ""
echo "To serve locally (with COOP/COEP headers for SharedArrayBuffer):"
echo "  python3 ${DEMO_SRC}/serve.py 8080"
echo "  (then open http://localhost:8080/recompiler/)"
echo ""
echo "The demo is deployed to docs/recompiler/ for GitHub Pages hosting."
