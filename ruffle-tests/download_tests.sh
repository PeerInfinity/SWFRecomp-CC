#!/usr/bin/env bash
# Download Ruffle AVM1 test SWFs from the ruffle-rs GitHub repository.
#
# Each test directory contains test.swf, output.txt, and optionally test.toml.
# These are used by run_tests.py and verify_output.py for regression testing
# against the SWFRecomp pipeline.
#
# Uses git sparse-checkout to download only the AVM1 test subtree instead of
# the entire Ruffle repository (~100x smaller download).
#
# Usage: ./download_tests.sh [--clean]
#   --clean   Remove existing test directories before downloading

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_URL="https://github.com/ruffle-rs/ruffle.git"
BRANCH="master"
# AVM1 test directories live under this path in the Ruffle repo
BASE_PATH="tests/tests/swfs/avm1"

CLEAN=false
if [[ "${1:-}" == "--clean" ]]; then
    CLEAN=true
fi

# Check dependencies
if ! command -v git &>/dev/null; then
    echo "Error: 'git' is required."
    exit 1
fi

echo "Downloading Ruffle AVM1 tests (branch: ${BRANCH})..."

# Create a temporary directory for the checkout
TMPDIR="$(mktemp -d)"
trap 'rm -rf "${TMPDIR}"' EXIT

# Sparse checkout: clone only tree metadata, then fetch blobs for avm1 tests only
echo "Cloning with sparse checkout (only ${BASE_PATH}/)..."
git clone --depth=1 --filter=blob:none --sparse --branch="${BRANCH}" \
    "${REPO_URL}" "${TMPDIR}/ruffle" 2>&1 | tail -3

git -C "${TMPDIR}/ruffle" sparse-checkout set "${BASE_PATH}" 2>&1

SRC_DIR="${TMPDIR}/ruffle/${BASE_PATH}"

# Count what we got
NUM_TESTS=$(find "${SRC_DIR}" -maxdepth 1 -mindepth 1 -type d 2>/dev/null | wc -l)
if [[ "${NUM_TESTS}" -eq 0 ]]; then
    echo "Error: No test directories found. The Ruffle repo structure may have changed."
    echo "Expected tests at: ${BASE_PATH}/"
    exit 1
fi

echo "Found ${NUM_TESTS} test directories."

if ${CLEAN}; then
    echo "Cleaning existing test directories..."
    # Remove all directories except _shared, __framework__, and dotfiles
    for dir in "${SCRIPT_DIR}"/*/; do
        dirname="$(basename "${dir}")"
        case "${dirname}" in
            _shared|__framework__|_investigation) ;;
            *) rm -rf "${dir}" ;;
        esac
    done
fi

# Copy test directories into place
echo "Installing test directories..."
INSTALLED=0
SKIPPED=0
for test_dir in "${SRC_DIR}"/*/; do
    test_name="$(basename "${test_dir}")"

    # Skip if no test.swf exists (some dirs are support/framework dirs)
    if [[ ! -f "${test_dir}/test.swf" ]]; then
        SKIPPED=$((SKIPPED + 1))
        continue
    fi

    dest="${SCRIPT_DIR}/${test_name}"
    mkdir -p "${dest}"

    # Copy the essential files: test.swf, output.txt, test.toml, input.json, and .as/.fla sources
    for file in test.swf output.txt test.toml input.json; do
        if [[ -f "${test_dir}/${file}" ]]; then
            cp "${test_dir}/${file}" "${dest}/"
        fi
    done

    # Copy child/target SWF files (target.swf, child.swf, assets.swf, etc.)
    # These are needed for multi-SWF tests (loadMovie, registerClass, etc.)
    for swf_file in "${test_dir}"/*.swf; do
        [[ -f "${swf_file}" ]] || continue
        [[ "$(basename "${swf_file}")" == "test.swf" ]] && continue
        cp "${swf_file}" "${dest}/"
    done

    # Copy ActionScript source files if present (useful for debugging)
    for ext in as fla; do
        for src_file in "${test_dir}"/*.${ext}; do
            [[ -f "${src_file}" ]] && cp "${src_file}" "${dest}/"
        done
    done

    # Copy data files for loadVariables tests (testvars.txt, variables, etc.)
    # These are non-SWF, non-config files that the test loads at runtime
    for data_file in "${test_dir}"/*; do
        [[ -f "${data_file}" ]] || continue
        local base="$(basename "${data_file}")"
        # Skip files we already copy or that aren't data files
        case "${base}" in
            test.swf|output.txt|test.toml|input.json|*.swf|*.as|*.fla) continue ;;
        esac
        cp "${data_file}" "${dest}/"
    done

    INSTALLED=$((INSTALLED + 1))
done

# Also install the __framework__ directory if present
if [[ -d "${SRC_DIR}/__framework__" ]]; then
    mkdir -p "${SCRIPT_DIR}/__framework__"
    cp -r "${SRC_DIR}/__framework__/"* "${SCRIPT_DIR}/__framework__/"
fi

echo ""
echo "Done! Installed ${INSTALLED} tests (skipped ${SKIPPED} without test.swf)."
echo "Run 'python3 run_tests.py' to test recompilation."
echo "Run 'python3 verify_output.py' to verify runtime output."
