#!/bin/bash
# Build the SWFRecomp recompiler as a WASM module
# Output: build_wasm/SWFRecomp.js + SWFRecomp.wasm
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
BUILD_DIR="${SWFRECOMP_ROOT}/build_wasm"

# Source Emscripten
source "${PROJECT_ROOT}/emsdk/emsdk_env.sh"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

emcmake cmake "${SWFRECOMP_ROOT}" \
    -DCMAKE_BUILD_TYPE=Release

emmake make -j$(nproc)

echo ""
echo "Built successfully:"
ls -lh "${BUILD_DIR}/SWFRecomp.js" "${BUILD_DIR}/SWFRecomp.wasm"
