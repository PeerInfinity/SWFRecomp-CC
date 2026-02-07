#!/bin/bash
# Set up the build environment for SWFRecomp-CC
#
# This installs/activates all dependencies needed to build WASM examples:
#   - swfmill for SWF generation from test scripts
#   - Emscripten SDK (emsdk) for WASM compilation
#   - Rebuilds SWFRecomp if needed
#
# Usage:
#   ./scripts/setup_build_env.sh          # Install and activate emsdk
#   source ./scripts/setup_build_env.sh   # Install, activate, AND set PATH in current shell
#
# After running, you can build examples with:
#   SWFRecomp/scripts/build_all_examples.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
SWFRECOMP_ROOT="${REPO_ROOT}/SWFRecomp"
EMSDK_DIR="${REPO_ROOT}/emsdk"

echo "========================================="
echo "SWFRecomp-CC Build Environment Setup"
echo "========================================="
echo ""

# ---------------------------------------------------------------
# 1. Check basic prerequisites
# ---------------------------------------------------------------
echo "Checking prerequisites..."

missing=()
for cmd in git cmake gcc g++ python3; do
    if ! command -v "$cmd" &>/dev/null; then
        missing+=("$cmd")
    fi
done

if [ ${#missing[@]} -gt 0 ]; then
    echo "Error: Missing required tools: ${missing[*]}"
    echo "Install them with:"
    echo "  sudo apt install git cmake gcc g++ python3"
    exit 1
fi

echo "  All prerequisites found."
echo ""

# ---------------------------------------------------------------
# 1b. Install swfmill (needed by graphics test SWF generators)
# ---------------------------------------------------------------
if command -v swfmill &>/dev/null; then
    echo "swfmill already installed."
else
    echo "Installing swfmill (needed for graphics test SWF generation)..."
    sudo apt install -y swfmill
    if command -v swfmill &>/dev/null; then
        echo "  swfmill installed successfully."
    else
        echo "  Warning: swfmill installation failed. Graphics tests that"
        echo "  need SWF generation (missing test.swf) will be skipped."
    fi
fi
echo ""

# ---------------------------------------------------------------
# 2. Check SWFModernRuntime
# ---------------------------------------------------------------
SWFMODERN_ROOT="${REPO_ROOT}/SWFModernRuntime"
if [ ! -d "$SWFMODERN_ROOT" ]; then
    echo "Error: SWFModernRuntime not found at: $SWFMODERN_ROOT"
    echo "Expected directory structure:"
    echo "  ${REPO_ROOT}/"
    echo "  ├── SWFRecomp/"
    echo "  ├── SWFModernRuntime/"
    echo "  └── scripts/"
    exit 1
fi
echo "SWFModernRuntime found."
echo ""

# ---------------------------------------------------------------
# 3. Build SWFRecomp if needed
# ---------------------------------------------------------------
if [ -x "${SWFRECOMP_ROOT}/build/SWFRecomp" ]; then
    echo "SWFRecomp binary already exists."
else
    echo "Building SWFRecomp..."
    mkdir -p "${SWFRECOMP_ROOT}/build"
    cd "${SWFRECOMP_ROOT}/build"
    cmake ..
    make -j"$(nproc)"
    echo "  SWFRecomp built successfully."
fi
echo ""

# ---------------------------------------------------------------
# 4. Install Emscripten SDK
# ---------------------------------------------------------------
if [ -d "$EMSDK_DIR" ] && [ -f "${EMSDK_DIR}/emsdk" ]; then
    echo "Emscripten SDK already installed at: $EMSDK_DIR"
else
    echo "Installing Emscripten SDK..."
    echo "  Cloning emsdk into: $EMSDK_DIR"
    git clone https://github.com/emscripten-core/emsdk.git "$EMSDK_DIR"
fi

cd "$EMSDK_DIR"

# Install and activate latest version
echo "  Installing latest emsdk..."
./emsdk install latest
echo "  Activating latest emsdk..."
./emsdk activate latest

echo ""

# ---------------------------------------------------------------
# 5. Activate emsdk in current environment
# ---------------------------------------------------------------
echo "Activating emsdk environment..."
source "${EMSDK_DIR}/emsdk_env.sh" 2>/dev/null || true

# Verify emcc is available
if command -v emcc &>/dev/null; then
    echo ""
    echo "========================================="
    echo "Setup complete!"
    echo "========================================="
    echo ""
    echo "  emcc version: $(emcc --version | head -1)"
    echo "  swfmill:      $(command -v swfmill 2>/dev/null || echo 'not installed')"
    echo "  SWFRecomp:    ${SWFRECOMP_ROOT}/build/SWFRecomp"
    echo "  emsdk:        ${EMSDK_DIR}"
    echo ""
    echo "To build all examples:"
    echo "  SWFRecomp/scripts/build_all_examples.sh"
    echo ""
    echo "To build a single test:"
    echo "  SWFRecomp/scripts/build_test.sh <test_name> wasm"
    echo ""
    echo "NOTE: If you ran this script without 'source', emcc won't be in"
    echo "your current shell PATH. Either run:"
    echo "  source ${EMSDK_DIR}/emsdk_env.sh"
    echo "or re-run this script with:"
    echo "  source ${SCRIPT_DIR}/setup_build_env.sh"
else
    echo ""
    echo "========================================="
    echo "emsdk installed but emcc not yet in PATH"
    echo "========================================="
    echo ""
    echo "Run this to activate in your current shell:"
    echo "  source ${EMSDK_DIR}/emsdk_env.sh"
    echo ""
    echo "Then you can build:"
    echo "  SWFRecomp/scripts/build_all_examples.sh"
fi
