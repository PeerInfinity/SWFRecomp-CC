#!/bin/bash
# Build all tests and deploy to docs
# Usage: ./scripts/build_all_examples.sh [docs_dir]

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
DOCS_DIR=${1:-"${SWFRECOMP_ROOT}/../docs/examples"}

# ---------------------------------------------------------------
# Preflight checks — fail BEFORE deleting anything
# ---------------------------------------------------------------
if ! command -v emcc &>/dev/null; then
    echo "Error: Emscripten (emcc) not found in PATH!"
    echo ""
    echo "Run:  source scripts/setup_build_env.sh"
    echo "  or: source emsdk/emsdk_env.sh"
    exit 1
fi

if [ ! -x "${SWFRECOMP_ROOT}/build/SWFRecomp" ]; then
    echo "Error: SWFRecomp binary not found at: ${SWFRECOMP_ROOT}/build/SWFRecomp"
    echo "Build it first:  cd SWFRecomp/build && cmake .. && make"
    exit 1
fi

echo "Using emcc: $(command -v emcc)"
echo "  Version: $(emcc --version | head -1)"
echo ""

# Load exclude list from config file
EXCLUDE_CONFIG="${SCRIPT_DIR}/excluded_tests.conf"
EXCLUDE_TESTS=()

if [ -f "$EXCLUDE_CONFIG" ]; then
    # Read exclude list (skip comments and empty lines, extract test name before colon)
    while IFS=':' read -r test_name reason || [ -n "$test_name" ]; do
        # Skip comments and empty lines
        [[ "$test_name" =~ ^#.*$ ]] && continue
        [[ -z "$test_name" ]] && continue
        EXCLUDE_TESTS+=("$test_name")
    done < "$EXCLUDE_CONFIG"
else
    echo "Warning: Exclude config not found: $EXCLUDE_CONFIG"
fi

# Auto-discover all trace tests with config.toml
TESTS=()
for test_dir in "${SWFRECOMP_ROOT}/tests"/*/; do
    test_name=$(basename "$test_dir")
    if [ -f "${test_dir}/config.toml" ]; then
        # Check if test is in exclude list
        skip=0
        for exclude in "${EXCLUDE_TESTS[@]}"; do
            if [ "$test_name" = "$exclude" ]; then
                skip=1
                break
            fi
        done

        if [ $skip -eq 0 ]; then
            TESTS+=("$test_name")
        fi
    fi
done

# Auto-discover graphics tests with config.toml and test.swf
GRAPHICS_TESTS=()
for test_dir in "${SWFRECOMP_ROOT}/tests/graphics"/*/; do
    test_name=$(basename "$test_dir")
    if [ -f "${test_dir}/config.toml" ] && [ -f "${test_dir}/test.swf" ]; then
        # Check if test is in exclude list
        skip=0
        for exclude in "${EXCLUDE_TESTS[@]}"; do
            if [ "$test_name" = "$exclude" ]; then
                skip=1
                break
            fi
        done

        if [ $skip -eq 0 ]; then
            GRAPHICS_TESTS+=("$test_name")
        fi
    fi
done

# Sort tests alphabetically
IFS=$'\n' TESTS=($(sort <<<"${TESTS[*]}"))
unset IFS

if [ ${#GRAPHICS_TESTS[@]} -gt 0 ]; then
    IFS=$'\n' GRAPHICS_TESTS=($(sort <<<"${GRAPHICS_TESTS[*]}"))
    unset IFS
fi

TOTAL_COUNT=$(( ${#TESTS[@]} + ${#GRAPHICS_TESTS[@]} ))

echo "Auto-discovered ${#TESTS[@]} trace tests and ${#GRAPHICS_TESTS[@]} graphics tests"
echo "Excluded ${#EXCLUDE_TESTS[@]} tests: ${EXCLUDE_TESTS[*]}"
echo "Building ${TOTAL_COUNT} tests for WASM deployment..."
echo ""

# ---------------------------------------------------------------
# Build into a staging directory, then swap on success
# ---------------------------------------------------------------
STAGING_DIR="${DOCS_DIR}.staging"
rm -rf "${STAGING_DIR}"
mkdir -p "${STAGING_DIR}"

SUCCESS_COUNT=0
FAIL_COUNT=0
TIMEOUT_COUNT=0
FAILED_TESTS=()
TIMEOUT_TESTS=()

# Build timeout per test (in seconds)
BUILD_TIMEOUT=60
# Graphics builds take longer due to emdawnwebgpu/asyncify
GRAPHICS_BUILD_TIMEOUT=180

BUILD_NUM=0

# Build trace tests
for test_name in "${TESTS[@]}"; do
    BUILD_NUM=$((BUILD_NUM + 1))
    echo "========================================="
    echo "Building: $test_name (${BUILD_NUM}/${TOTAL_COUNT}) [trace]"
    echo "========================================="

    # Force regeneration of recompiled output (ensures out.h is up-to-date)
    rm -rf "${SWFRECOMP_ROOT}/tests/${test_name}/RecompiledScripts" "${SWFRECOMP_ROOT}/tests/${test_name}/RecompiledTags"

    # Build with timeout, capture output to check for success
    BUILD_OUTPUT=$(timeout "$BUILD_TIMEOUT" "${SCRIPT_DIR}/build_test.sh" "$test_name" wasm 2>&1) || true
    BUILD_EXIT=$?

    if echo "$BUILD_OUTPUT" | grep -q "WASM build complete"; then
        # Deploy with --no-index (index generated once at end)
        if "${SCRIPT_DIR}/deploy_example.sh" "$test_name" "$STAGING_DIR" --no-index >/dev/null 2>&1; then
            echo "  $test_name - built and deployed"
            SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
        else
            echo "  $test_name - build succeeded but deploy failed"
            FAIL_COUNT=$((FAIL_COUNT + 1))
            FAILED_TESTS+=("$test_name")
        fi
    elif [ $BUILD_EXIT -eq 124 ]; then
        echo "  $test_name - build timeout (>${BUILD_TIMEOUT}s)"
        TIMEOUT_COUNT=$((TIMEOUT_COUNT + 1))
        TIMEOUT_TESTS+=("$test_name")
    else
        echo "  $test_name - build failed"
        FAIL_COUNT=$((FAIL_COUNT + 1))
        FAILED_TESTS+=("$test_name")
    fi

    echo ""
done

# Build graphics tests
for test_name in "${GRAPHICS_TESTS[@]}"; do
    BUILD_NUM=$((BUILD_NUM + 1))
    echo "========================================="
    echo "Building: graphics/$test_name (${BUILD_NUM}/${TOTAL_COUNT}) [graphics/WebGPU]"
    echo "========================================="

    # Force regeneration of recompiled output (ensures out.h is up-to-date)
    rm -rf "${SWFRECOMP_ROOT}/tests/graphics/${test_name}/RecompiledScripts" "${SWFRECOMP_ROOT}/tests/graphics/${test_name}/RecompiledTags"

    # Build with --graphics flag and longer timeout
    BUILD_OUTPUT=$(timeout "$GRAPHICS_BUILD_TIMEOUT" "${SCRIPT_DIR}/build_test.sh" "graphics/$test_name" wasm --graphics 2>&1) || true
    BUILD_EXIT=$?

    if echo "$BUILD_OUTPUT" | grep -q "WASM build complete"; then
        # Deploy with --no-index and --graphics
        if "${SCRIPT_DIR}/deploy_example.sh" "graphics/$test_name" "$STAGING_DIR" --no-index --graphics >/dev/null 2>&1; then
            echo "  graphics/$test_name - built and deployed"
            SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
        else
            echo "  graphics/$test_name - build succeeded but deploy failed"
            FAIL_COUNT=$((FAIL_COUNT + 1))
            FAILED_TESTS+=("graphics/$test_name")
        fi
    elif [ $BUILD_EXIT -eq 124 ]; then
        echo "  graphics/$test_name - build timeout (>${GRAPHICS_BUILD_TIMEOUT}s)"
        TIMEOUT_COUNT=$((TIMEOUT_COUNT + 1))
        TIMEOUT_TESTS+=("graphics/$test_name")
    else
        echo "  graphics/$test_name - build failed"
        FAIL_COUNT=$((FAIL_COUNT + 1))
        FAILED_TESTS+=("graphics/$test_name")
    fi

    echo ""
done

# ---------------------------------------------------------------
# Only replace docs if we had some successes
# ---------------------------------------------------------------
if [ $SUCCESS_COUNT -eq 0 ]; then
    echo "========================================="
    echo "ERROR: All builds failed! Keeping existing docs intact."
    echo "========================================="
    rm -rf "${STAGING_DIR}"
    echo ""
    echo "Failed tests:"
    for failed in "${FAILED_TESTS[@]}"; do
        echo "  - $failed"
    done
    exit 1
fi

echo "Replacing docs/examples with ${SUCCESS_COUNT} successfully built tests..."
rm -rf "${DOCS_DIR:?}"
mv "${STAGING_DIR}" "${DOCS_DIR}"

# Generate the examples index once at the end
EXAMPLES_PARENT="$(dirname "$DOCS_DIR")"
echo "Generating examples index..."
"${SCRIPT_DIR}/generate_examples_index.sh" "${EXAMPLES_PARENT}"

echo ""
echo "========================================="
echo "Build Summary"
echo "========================================="
echo "Successful: $SUCCESS_COUNT"
echo "Failed: $FAIL_COUNT"
echo "Timeout: $TIMEOUT_COUNT"
echo "Total: ${TOTAL_COUNT}"

if [ $FAIL_COUNT -gt 0 ]; then
    echo ""
    echo "Failed tests:"
    for failed in "${FAILED_TESTS[@]}"; do
        echo "  - $failed"
    done
fi

if [ $TIMEOUT_COUNT -gt 0 ]; then
    echo ""
    echo "Timed out tests (may be too complex for quick WASM builds):"
    for timeout_test in "${TIMEOUT_TESTS[@]}"; do
        echo "  - $timeout_test"
    done
fi

echo ""
echo "Documentation examples location: $DOCS_DIR"
