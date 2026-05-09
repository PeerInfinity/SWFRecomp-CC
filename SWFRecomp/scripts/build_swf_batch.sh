#!/bin/bash
# Batch-build a directory of SWF files as graphics demos and add them to the
# local "Local Batch" category on the demo page.
#
# Intended for LOCAL testing only. The build artifacts and test-scratch dirs
# can all be removed by clean_swf_batch.sh.
#
# Usage:
#   ./scripts/build_swf_batch.sh [swf_dir] [--skip-existing]
#
# Defaults:
#   swf_dir = <repo_root>/local_swf_batch/
#
# Modes:
#   default        — every SWF in swf_dir is rebuilt from scratch each run.
#                    SWFs from previous runs that are no longer in swf_dir
#                    stay deployed. New SWFs get added.
#   --skip-existing  — SWFs whose deploy dir already has a built WASM are
#                    left alone (no recompile, no rebuild, no overwrite).
#                    Only new SWFs get processed. Useful for incremental
#                    additions to an existing batch.
#
# Each *.swf in swf_dir becomes a test under SWFRecomp/tests/local_batch/<name>/
# and gets deployed to docs/examples/local_batch/<name>/. Ruffle comparison is
# enabled automatically by copying the original test.swf into the deploy dir.

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
REPO_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"

# Parse args: first non-flag is swf_dir; flags can appear in any position.
SKIP_EXISTING=0
SWF_DIR=""
for arg in "$@"; do
    case "$arg" in
        --skip-existing) SKIP_EXISTING=1 ;;
        --*) echo "Error: unknown flag: $arg"; exit 1 ;;
        *)
            if [ -z "$SWF_DIR" ]; then
                SWF_DIR="$arg"
            else
                echo "Error: unexpected argument: $arg (swf_dir already set to $SWF_DIR)"
                exit 1
            fi
            ;;
    esac
done
SWF_DIR=${SWF_DIR:-"${REPO_ROOT}/local_swf_batch"}
DOCS_DIR="${REPO_ROOT}/docs"
EXAMPLES_DIR="${DOCS_DIR}/examples"
BATCH_NAMESPACE="local_batch"
TESTS_BATCH_ROOT="${SWFRECOMP_ROOT}/tests/${BATCH_NAMESPACE}"
DEPLOY_BATCH_ROOT="${EXAMPLES_DIR}/${BATCH_NAMESPACE}"

if [ ! -d "$SWF_DIR" ]; then
    echo "Error: SWF directory not found: $SWF_DIR"
    echo "Either pass a directory as the first argument or create the default:"
    echo "  mkdir -p ${REPO_ROOT}/local_swf_batch && cp *.swf ${REPO_ROOT}/local_swf_batch/"
    exit 1
fi

# Collect SWFs (top-level only; recursion would clash with the basename->test_name mapping)
shopt -s nullglob
SWF_FILES=("${SWF_DIR}"/*.swf "${SWF_DIR}"/*.SWF)
shopt -u nullglob

if [ ${#SWF_FILES[@]} -eq 0 ]; then
    echo "No .swf files found in ${SWF_DIR}"
    exit 0
fi

# ---------------------------------------------------------------
# Preflight — fail before scaffolding anything
# ---------------------------------------------------------------
if ! command -v emcc &>/dev/null; then
    echo "Error: Emscripten (emcc) not found in PATH."
    echo "Run:  source ${REPO_ROOT}/emsdk/emsdk_env.sh"
    exit 1
fi

if [ ! -x "${SWFRECOMP_ROOT}/build/SWFRecomp" ]; then
    echo "Error: SWFRecomp binary not found at ${SWFRECOMP_ROOT}/build/SWFRecomp"
    echo "Build it first:  cd SWFRecomp/build && cmake .. && make"
    exit 1
fi

echo "Found ${#SWF_FILES[@]} SWF file(s) in ${SWF_DIR}"
echo "  Test scratch: ${TESTS_BATCH_ROOT}"
echo "  Deploy dir:   ${DEPLOY_BATCH_ROOT}"
if [ "$SKIP_EXISTING" = 1 ]; then
    echo "  Mode:         --skip-existing (existing builds left alone)"
fi
echo ""

mkdir -p "${TESTS_BATCH_ROOT}"

SUCCESS=0
FAIL=0
SKIPPED=0
FAILED_NAMES=()
GRAPHICS_BUILD_TIMEOUT=180

for swf_path in "${SWF_FILES[@]}"; do
    swf_basename="$(basename "$swf_path")"
    # Sanitize: strip extension, replace any non [A-Za-z0-9_-] with _
    test_name="${swf_basename%.*}"
    test_name="${test_name//[^A-Za-z0-9_-]/_}"
    if [ -z "$test_name" ]; then
        echo "Skipping ${swf_basename}: empty sanitized name"
        continue
    fi

    test_dir="${TESTS_BATCH_ROOT}/${test_name}"
    rel_test_name="${BATCH_NAMESPACE}/${test_name}"
    deploy_dir="${DEPLOY_BATCH_ROOT}/${test_name}"

    # --skip-existing: leave already-built deployments alone. Detect "built"
    # by the presence of a .wasm file in the deploy dir.
    if [ "$SKIP_EXISTING" = 1 ] && compgen -G "${deploy_dir}/*.wasm" > /dev/null; then
        echo "Skipping ${swf_basename}: already deployed at ${deploy_dir}"
        SKIPPED=$((SKIPPED + 1))
        continue
    fi

    echo "========================================="
    echo "Processing: ${swf_basename}  ->  ${rel_test_name}"
    echo "========================================="

    # ----- Scaffold test dir -----
    rm -rf "${test_dir}"
    mkdir -p "${test_dir}"
    cp "${swf_path}" "${test_dir}/test.swf"

    cat > "${test_dir}/config.toml" <<'TOML_EOF'
[input]
path_to_swf = "test.swf"
output_tags_folder = "RecompiledTags"
output_scripts_folder = "RecompiledScripts"
TOML_EOF

    # Extract metadata; tolerate failure (test_info.json is optional).
    META_JSON=""
    if META_JSON=$(python3 "${SCRIPT_DIR}/extract_swf_metadata.py" "${test_dir}/test.swf" 2>/dev/null); then
        # Wrap into the test_info.json shape that demo.html expects.
        python3 - "$test_dir" "$swf_basename" "$META_JSON" <<'PY_EOF'
import json, os, sys
test_dir, swf_basename, meta_json = sys.argv[1], sys.argv[2], sys.argv[3]
meta = json.loads(meta_json)
info = {
    "metadata": {
        "description": f"Local batch SWF: {swf_basename}",
        "swf_version": meta.get("swf_version"),
        "fully_implemented": False,
    },
    "opcodes": {"tested": [], "supporting": []},
}
if "width" in meta:
    info["metadata"]["width"] = meta["width"]
if "height" in meta:
    info["metadata"]["height"] = meta["height"]
with open(os.path.join(test_dir, "test_info.json"), "w") as f:
    json.dump(info, f, indent=2)
PY_EOF
    else
        echo "  (warning) could not extract metadata; continuing without test_info.json"
    fi

    # ----- Build -----
    BUILD_OUTPUT=$(timeout "$GRAPHICS_BUILD_TIMEOUT" \
        "${SCRIPT_DIR}/build_test.sh" "${rel_test_name}" wasm --graphics 2>&1) || true

    if ! echo "$BUILD_OUTPUT" | grep -q "WASM build complete"; then
        echo "  BUILD FAILED for ${rel_test_name}"
        echo "$BUILD_OUTPUT" | tail -30
        FAIL=$((FAIL + 1))
        FAILED_NAMES+=("${rel_test_name}")
        echo ""
        continue
    fi

    # ----- Deploy -----
    if ! "${SCRIPT_DIR}/deploy_example.sh" "${rel_test_name}" "${EXAMPLES_DIR}" --no-index --graphics >/dev/null 2>&1; then
        echo "  DEPLOY FAILED for ${rel_test_name}"
        FAIL=$((FAIL + 1))
        FAILED_NAMES+=("${rel_test_name}")
        echo ""
        continue
    fi

    # Override .demo_type so the index/catalog can group these separately.
    echo "${BATCH_NAMESPACE}" > "${EXAMPLES_DIR}/${rel_test_name}/.demo_type"

    SUCCESS=$((SUCCESS + 1))
    echo "  OK"
    echo ""
done

# ---------------------------------------------------------------
# Regenerate the index + catalog so the new entries show up.
# ---------------------------------------------------------------
echo "Regenerating examples index..."
"${SCRIPT_DIR}/generate_examples_index.sh" "${DOCS_DIR}"

echo ""
echo "========================================="
echo "Local-batch build summary"
echo "========================================="
echo "  Built:   ${SUCCESS}"
echo "  Skipped: ${SKIPPED}"
echo "  Failed:  ${FAIL}"
if [ ${FAIL} -gt 0 ]; then
    echo "  Failures:"
    for f in "${FAILED_NAMES[@]}"; do
        echo "    - $f"
    done
fi
echo ""
echo "Open ${DOCS_DIR}/index.html (or serve docs/) to see the new"
echo "\"Local Batch\" category. Run clean_swf_batch.sh to remove everything."
