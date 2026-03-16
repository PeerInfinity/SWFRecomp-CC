#!/usr/bin/env bash
# Download Ruffle test SWFs from the ruffle-rs GitHub repository.
#
# Each test directory contains test.swf, output.txt, and optionally test.toml.
# These are used by run_tests.py and verify_output.py for regression testing
# against the SWFRecomp pipeline.
#
# Uses git sparse-checkout to download only the requested test subtrees instead
# of the entire Ruffle repository (~100x smaller download).
#
# Usage: ./download_tests.sh [--clean] [CATEGORY...]
#   --clean       Remove existing test directories before downloading
#   CATEGORY...   One or more test categories to download (default: avm1)
#
# Available categories:
#   avm1              tests/tests/swfs/avm1 (620 tests)
#   from_shumway      tests/tests/swfs/from_shumway (AVM1 subset: ~23 tests)
#
# Examples:
#   ./download_tests.sh                          # download avm1 only
#   ./download_tests.sh from_shumway             # download from_shumway only
#   ./download_tests.sh avm1 from_shumway        # download both
#   ./download_tests.sh --clean avm1             # clean and re-download avm1

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_URL="https://github.com/ruffle-rs/ruffle.git"
BRANCH="master"

# Category definitions: category_name -> (ruffle_repo_path, local_install_path)
# Each category maps a Ruffle repo subtree to a local directory under SCRIPT_DIR/tests/swfs/
declare -A CATEGORY_REPO_PATH
declare -A CATEGORY_LOCAL_PATH

CATEGORY_REPO_PATH[avm1]="tests/tests/swfs/avm1"
CATEGORY_LOCAL_PATH[avm1]="${SCRIPT_DIR}/tests/swfs/avm1"

CATEGORY_REPO_PATH[from_shumway]="tests/tests/swfs/from_shumway"
CATEGORY_LOCAL_PATH[from_shumway]="${SCRIPT_DIR}/tests/swfs/from_shumway"

CATEGORY_REPO_PATH[from_gnash]="tests/tests/swfs/from_gnash"
CATEGORY_LOCAL_PATH[from_gnash]="${SCRIPT_DIR}/tests/swfs/from_gnash"

ALL_CATEGORIES=(avm1 from_shumway from_gnash)

# Parse arguments
CLEAN=false
CATEGORIES=()
for arg in "$@"; do
    case "${arg}" in
        --clean) CLEAN=true ;;
        *)
            if [[ -v "CATEGORY_REPO_PATH[${arg}]" ]]; then
                CATEGORIES+=("${arg}")
            else
                echo "Error: Unknown category '${arg}'"
                echo "Available categories: ${ALL_CATEGORIES[*]}"
                exit 1
            fi
            ;;
    esac
done

# Default to avm1 if no categories specified
if [[ ${#CATEGORIES[@]} -eq 0 ]]; then
    CATEGORIES=(avm1)
fi

# Check dependencies
if ! command -v git &>/dev/null; then
    echo "Error: 'git' is required."
    exit 1
fi

echo "Downloading Ruffle tests (branch: ${BRANCH})..."
echo "Categories: ${CATEGORIES[*]}"

# Create a temporary directory for the checkout
TMPDIR="$(mktemp -d)"
trap 'rm -rf "${TMPDIR}"' EXIT

# Build sparse-checkout paths for all requested categories
SPARSE_PATHS=()
for cat in "${CATEGORIES[@]}"; do
    SPARSE_PATHS+=("${CATEGORY_REPO_PATH[${cat}]}")
done

echo "Cloning with sparse checkout (${SPARSE_PATHS[*]})..."
git clone --depth=1 --filter=blob:none --sparse --branch="${BRANCH}" \
    "${REPO_URL}" "${TMPDIR}/ruffle" 2>&1 | tail -3

git -C "${TMPDIR}/ruffle" sparse-checkout set "${SPARSE_PATHS[@]}" 2>&1

# Install each category
TOTAL_INSTALLED=0
TOTAL_SKIPPED=0

install_test_dir() {
    local test_dir="$1"
    local dest="$2"

    mkdir -p "${dest}"

    # Copy the essential files: test.swf, output.txt, test.toml, input.json
    for file in test.swf output.txt test.toml input.json; do
        if [[ -f "${test_dir}/${file}" ]]; then
            cp "${test_dir}/${file}" "${dest}/"
        fi
    done

    # Copy child/target SWF files (target.swf, child.swf, assets.swf, etc.)
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

    # Copy data files (testvars.txt, variables, etc.)
    for data_file in "${test_dir}"/*; do
        [[ -f "${data_file}" ]] || continue
        base="$(basename "${data_file}")"
        case "${base}" in
            test.swf|output.txt|test.toml|input.json|*.swf|*.as|*.fla) continue ;;
        esac
        cp "${data_file}" "${dest}/"
    done
}

install_category() {
    local cat="$1"
    local src_dir="${TMPDIR}/ruffle/${CATEGORY_REPO_PATH[${cat}]}"
    local dest_base="${CATEGORY_LOCAL_PATH[${cat}]}"
    local installed=0
    local skipped=0

    if [[ ! -d "${src_dir}" ]]; then
        echo "Warning: Source directory not found for ${cat}: ${src_dir}"
        return
    fi

    # Count what we got
    local num_dirs
    num_dirs=$(find "${src_dir}" -maxdepth 1 -mindepth 1 -type d 2>/dev/null | wc -l)
    echo ""
    echo "=== ${cat}: found ${num_dirs} directories ==="

    if ${CLEAN}; then
        echo "Cleaning existing ${cat} test directories..."
        if [[ -d "${dest_base}" ]]; then
            for dir in "${dest_base}"/*/; do
                [[ -d "${dir}" ]] || continue
                dirname="$(basename "${dir}")"
                case "${dirname}" in
                    __framework__|_investigation|_image-test-output) ;;
                    *) rm -rf "${dir}" ;;
                esac
            done
        fi
    fi

    mkdir -p "${dest_base}"

    # Install tests from immediate children (flat tests like from_shumway/add/)
    # AND recurse into subdirectories that contain tests (like from_shumway/avm1/operations/)
    for child_dir in "${src_dir}"/*/; do
        local child_name
        child_name="$(basename "${child_dir}")"

        if [[ -f "${child_dir}/test.swf" ]]; then
            # Flat test: install directly
            install_test_dir "${child_dir}" "${dest_base}/${child_name}"
            installed=$((installed + 1))
        else
            # Check if this is a subcategory with nested tests
            local has_nested=false
            for nested_dir in "${child_dir}"/*/; do
                if [[ -f "${nested_dir}/test.swf" ]]; then
                    has_nested=true
                    break
                fi
            done

            if ${has_nested}; then
                for nested_dir in "${child_dir}"/*/; do
                    local nested_name
                    nested_name="$(basename "${nested_dir}")"

                    if [[ ! -f "${nested_dir}/test.swf" ]]; then
                        skipped=$((skipped + 1))
                        continue
                    fi

                    install_test_dir "${nested_dir}" "${dest_base}/${child_name}/${nested_name}"
                    installed=$((installed + 1))
                done
            else
                skipped=$((skipped + 1))
            fi
        fi
    done

    # Install __framework__ directory if present
    if [[ -d "${src_dir}/__framework__" ]]; then
        mkdir -p "${dest_base}/__framework__"
        cp -r "${src_dir}/__framework__/"* "${dest_base}/__framework__/"
    fi

    echo "Installed ${installed} tests (skipped ${skipped} without test.swf)."
    TOTAL_INSTALLED=$((TOTAL_INSTALLED + installed))
    TOTAL_SKIPPED=$((TOTAL_SKIPPED + skipped))
}

for cat in "${CATEGORIES[@]}"; do
    install_category "${cat}"
done

echo ""
echo "Done! Total: ${TOTAL_INSTALLED} tests installed, ${TOTAL_SKIPPED} skipped."
