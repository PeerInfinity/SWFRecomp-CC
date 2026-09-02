#!/bin/bash
# Build the SWFRecomp recompiler as a WASM module
# Output: build_wasm/SWFRecomp.js + SWFRecomp.wasm
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
BUILD_DIR="${SWFRECOMP_ROOT}/build_wasm"

# Source Emscripten (repo-local checkout, or EMSDK, or emcc already on PATH)
if [ -f "${PROJECT_ROOT}/emsdk/emsdk_env.sh" ]; then
    source "${PROJECT_ROOT}/emsdk/emsdk_env.sh"
elif [ -n "${EMSDK:-}" ] && [ -f "${EMSDK}/emsdk_env.sh" ]; then
    source "${EMSDK}/emsdk_env.sh"
fi
command -v emcc >/dev/null 2>&1 || { echo "ERROR: emcc not found (install emsdk at ${PROJECT_ROOT}/emsdk or set EMSDK)"; exit 1; }

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

emcmake cmake "${SWFRECOMP_ROOT}" \
    -DCMAKE_BUILD_TYPE=Release

# Build only the recompiler target: the bundled zlib CMake also defines
# example/minigzip test programs whose libz.a dependency races the static lib
# under -j (seen in CI: "No rule to make target lib/zlib/libz.a").
emmake make -j$(nproc) SWFRecomp

echo ""
echo "Built successfully:"
ls -lh "${BUILD_DIR}/SWFRecomp.js" "${BUILD_DIR}/SWFRecomp.wasm"
