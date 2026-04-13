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
# Usage: ./download_tests.sh [--clean] [--clean-cache] [CATEGORY...]
#   --clean       Remove existing test directories before downloading
#   --clean-cache Remove cached RecompiledScripts/RecompiledTags only (no download)
#   CATEGORY...   One or more test categories to download (default: avm1)
#
# Available categories:
#   avm1              tests/tests/swfs/avm1 (~644 AVM1 tests)
#   from_shumway      tests/tests/swfs/from_shumway (~92 AVM1 tests, ~137 AVM2 skipped)
#   from_gnash        tests/tests/swfs/from_gnash (~404 AVM1 tests)
#
# The installer walks each category tree recursively and detects AVM1 vs AVM2
# from the SWF file header (swf_is_avm2.py). AVM2 / ActionScript 3 tests are
# skipped because the SWFRecomp pipeline is AVM1-only; running them would
# just produce compile_fail noise.
#
# Examples:
#   ./download_tests.sh                          # download avm1 only
#   ./download_tests.sh from_shumway             # download from_shumway only
#   ./download_tests.sh avm1 from_shumway        # download both
#   ./download_tests.sh --clean avm1             # clean and re-download avm1
#   ./download_tests.sh --clean-cache            # remove stale recompiler caches for all categories
#   ./download_tests.sh --clean-cache from_gnash # remove caches for from_gnash only

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
CLEAN_CACHE=false
CATEGORIES=()
for arg in "$@"; do
    case "${arg}" in
        --clean) CLEAN=true ;;
        --clean-cache) CLEAN_CACHE=true ;;
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

# Default categories
if [[ ${#CATEGORIES[@]} -eq 0 ]]; then
    if ${CLEAN_CACHE}; then
        # --clean-cache with no categories: clean all
        CATEGORIES=("${ALL_CATEGORIES[@]}")
    else
        CATEGORIES=(avm1)
    fi
fi

# Handle --clean-cache: remove RecompiledScripts/RecompiledTags and exit
if ${CLEAN_CACHE}; then
    total_cleaned=0
    for cat in "${CATEGORIES[@]}"; do
        dest_base="${CATEGORY_LOCAL_PATH[${cat}]}"
        if [[ ! -d "${dest_base}" ]]; then
            echo "${cat}: no test directory found, skipping"
            continue
        fi
        count=0
        while IFS= read -r -d '' dir; do
            rm -rf "${dir}"
            count=$((count + 1))
        done < <(find "${dest_base}" -type d \( -name "RecompiledScripts" -o -name "RecompiledTags" \) -print0)
        echo "${cat}: cleaned ${count} cached directories"
        total_cleaned=$((total_cleaned + count))
    done
    echo "Done! Cleaned ${total_cleaned} cached directories."
    exit 0
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
                # Preserve infrastructure / CI-managed directories outright.
                case "${dirname}" in
                    __framework__|_investigation|_image-test-output|_results) continue ;;
                esac
                rm -rf "${dir}"
            done
        fi
        # rm -rf above drops everything inside the category, including files we
        # hand-manage in git (output.flash.txt, test_harness.c, custom test.toml).
        # Restore any git-tracked content under ${dest_base} so the subsequent
        # install only has to populate the .gitignored artifacts (test.swf,
        # output.txt, output.ruffle.txt, etc.).
        local git_top rel_path
        git_top="$(git -C "${SCRIPT_DIR}" rev-parse --show-toplevel 2>/dev/null || echo "")"
        if [[ -n "${git_top}" ]]; then
            rel_path="$(realpath --relative-to="${git_top}" "${dest_base}" 2>/dev/null || echo "")"
            if [[ -n "${rel_path}" && "${rel_path}" != /* && "${rel_path}" != ..* ]]; then
                # Run git from the worktree root so the pathspec resolves correctly.
                git -C "${git_top}" checkout HEAD -- "${rel_path}" 2>/dev/null || true
            fi
        fi
    fi

    mkdir -p "${dest_base}"

    # Discover all test.swf files anywhere under the category, at any nesting
    # depth (handles flat tests like from_shumway/add/, single-nested tests
    # like from_gnash/actionscript.all/Inheritance-v7/, and triply-nested tests
    # like from_gnash/misc-ming.all/action_order/ActionOrderTest3/).
    local all_swfs=()
    while IFS= read -r -d '' swf; do
        all_swfs+=("${swf}")
    done < <(find "${src_dir}" -mindepth 2 -name test.swf -print0)

    # Filter to AVM1 tests only — our recompiler is AVM1 only, and running
    # AVM2 tests would just produce compile_fail noise. Uses swf_is_avm2.py
    # in --filter-avm1 batch mode: feeds all paths on stdin, reads back the
    # ones whose SWF headers indicate AVM1 (no FileAttributes HasActionScript3
    # bit and no DoABC tag).
    local avm1_swfs=()
    if [[ ${#all_swfs[@]} -gt 0 ]]; then
        local filtered
        filtered="$(printf '%s\n' "${all_swfs[@]}" | python3 "${SCRIPT_DIR}/swf_is_avm2.py" --filter-avm1)"
        if [[ -n "${filtered}" ]]; then
            while IFS= read -r line; do
                [[ -n "${line}" ]] && avm1_swfs+=("${line}")
            done <<< "${filtered}"
        fi
    fi

    local avm2_skipped=$(( ${#all_swfs[@]} - ${#avm1_swfs[@]} ))

    # Install each AVM1 test, preserving its path relative to the category root.
    for swf in "${avm1_swfs[@]}"; do
        local test_src rel_path
        test_src="$(dirname "${swf}")"
        rel_path="${test_src#"${src_dir}"/}"
        install_test_dir "${test_src}" "${dest_base}/${rel_path}"
        installed=$((installed + 1))
    done

    # Install __framework__ directory if present
    if [[ -d "${src_dir}/__framework__" ]]; then
        mkdir -p "${dest_base}/__framework__"
        cp -r "${src_dir}/__framework__/"* "${dest_base}/__framework__/"
    fi

    echo "Installed ${installed} tests (skipped ${avm2_skipped} AVM2/non-AVM1)."
    TOTAL_INSTALLED=$((TOTAL_INSTALLED + installed))
    TOTAL_SKIPPED=$((TOTAL_SKIPPED + avm2_skipped))
}

for cat in "${CATEGORIES[@]}"; do
    install_category "${cat}"
done

echo ""
echo "Done! Total: ${TOTAL_INSTALLED} tests installed, ${TOTAL_SKIPPED} skipped."
