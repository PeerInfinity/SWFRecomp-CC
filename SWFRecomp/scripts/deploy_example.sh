#!/bin/bash
# Deploy a test's WASM build to docs examples
# Usage: ./scripts/deploy_example.sh <test_name> [docs_dir] [--no-index] [--graphics]

set -e

TEST_NAME=$1
EXAMPLES_DIR=${2:-../SWFRecompDocs/docs/examples}
NO_INDEX=false
DEMO_TYPE="trace"

# Check for flags in any position
for arg in "$@"; do
    if [ "$arg" = "--no-index" ]; then
        NO_INDEX=true
    fi
    if [ "$arg" = "--graphics" ]; then
        DEMO_TYPE="graphics"
    fi
done

# Handle flags passed as positional arg 2
if [ "$EXAMPLES_DIR" = "--no-index" ] || [ "$EXAMPLES_DIR" = "--graphics" ]; then
    EXAMPLES_DIR="../SWFRecompDocs/docs/examples"
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${SWFRECOMP_ROOT}/tests/${TEST_NAME}/build/wasm"
DEPLOY_DIR="${EXAMPLES_DIR}/${TEST_NAME}"
DOCS_DIR="$(dirname "${EXAMPLES_DIR}")"

# Validate inputs
if [ -z "$TEST_NAME" ]; then
    echo "Error: Test name required"
    echo "Usage: $0 <test_name> [docs_dir] [--no-index] [--graphics]"
    exit 1
fi

if [ ! -d "$BUILD_DIR" ]; then
    echo "Error: Build directory not found: $BUILD_DIR"
    echo "Run ./scripts/build_test.sh ${TEST_NAME} wasm first"
    exit 1
fi

# Create deployment directory
mkdir -p "${DEPLOY_DIR}"

# Copy WASM artifacts
echo "Deploying ${TEST_NAME} to ${DEPLOY_DIR}..."
cp "${BUILD_DIR}"/*.wasm "${DEPLOY_DIR}/" 2>/dev/null || true
cp "${BUILD_DIR}"/*.js "${DEPLOY_DIR}/" 2>/dev/null || true
cp "${BUILD_DIR}"/index.html "${DEPLOY_DIR}/" 2>/dev/null || true

# Write demo type marker
echo "${DEMO_TYPE}" > "${DEPLOY_DIR}/.demo_type"

echo "✅ Deployed ${TEST_NAME} (${DEMO_TYPE}) to ${DEPLOY_DIR}"
echo ""
echo "Files deployed:"
ls -lh "${DEPLOY_DIR}"

# Regenerate the examples index (unless --no-index)
if [ "$NO_INDEX" = false ]; then
    echo ""
    echo "Regenerating examples index..."
    "${SCRIPT_DIR}/generate_examples_index.sh" "${DOCS_DIR}"
fi
