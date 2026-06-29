#!/bin/bash
# Rebuild & redeploy the docs2 game demos (flasharchive + glaiel) with the
# CURRENT recompiler + runtime, then regenerate their catalogs.
#
# Use this after a recompiler (swf.cpp) or runtime (SWFModernRuntime/*.c) change
# to refresh the deployed WASM so the demos reflect the latest fixes.
#
# Usage:
#   ./scripts/rebuild_docs2_demos.sh [namespace ...] [flags]
#
#   namespace        One or more of: flasharchive glaiel  (default: both)
#   --only <list>    Comma-separated demo names to rebuild (across the chosen
#                    namespaces), e.g. --only Tetris,Pong. Default: every demo
#                    currently deployed under docs2/examples/<namespace>/.
#   --fast           Runtime-only rebuild: skip the recompiler binary rebuild
#                    AND skip re-running SWFRecomp (no --clean). The WASM runtime
#                    is ALWAYS recompiled from source regardless, so --fast is
#                    correct when you only changed SWFModernRuntime/*.c (e.g. a
#                    render_webgpu.c / action.c fix). It is NOT enough for a
#                    recompiler/swf.cpp change — omit --fast for that.
#   --skip-recompiler-build   Don't `cmake --build` the SWFRecomp binary, but
#                    still re-run it with --clean (use when the binary is already
#                    current but you want fresh recompiled C).
#   --docs-dir <rel> docs root relative to repo root (default: docs2).
#   -h | --help      Show this help.
#
# Env:
#   GRAPHICS_BUILD_TIMEOUT   Per-demo emcc build timeout, seconds (default 900).
#
# What it does, per demo <ns>/<name>:
#   1. (unless --fast) re-run SWFRecomp via build_test.sh --clean to regenerate
#      RecompiledScripts/Tags from the current recompiler.
#   2. build_test.sh <ns>/<name> wasm --graphics   (always: full runtime rebuild)
#   3. deploy_example.sh <ns>/<name> <docs>/examples --no-index --graphics
#   Then per namespace: regenerate <docs>/<ns>_catalog.json with type=<ns>.
#
# NOTE on catalog "type": it MUST equal the namespace (flasharchive / glaiel) or
# the index page's section for that namespace renders empty. This script always
# passes --type <namespace>; do not change it to "graphics". (deploy_example.sh
# writes .demo_type=graphics into each deploy dir — that marker is unused by the
# catalog generator and is harmless.)

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
REPO_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"

# ---- defaults ----
NAMESPACES=()
ONLY_LIST=""
FAST=0
SKIP_RECOMPILER_BUILD=0
DOCS_DIR_REL="docs2"
GRAPHICS_BUILD_TIMEOUT="${GRAPHICS_BUILD_TIMEOUT:-900}"

# ---- arg parse ----
EXPECT=""
for arg in "$@"; do
    if [ -n "$EXPECT" ]; then
        case "$EXPECT" in
            only) ONLY_LIST="$arg" ;;
            docs-dir) DOCS_DIR_REL="$arg" ;;
        esac
        EXPECT=""; continue
    fi
    case "$arg" in
        --fast) FAST=1 ;;
        --skip-recompiler-build) SKIP_RECOMPILER_BUILD=1 ;;
        --only) EXPECT=only ;;
        --docs-dir) EXPECT=docs-dir ;;
        -h|--help) sed -n '2,48p' "${BASH_SOURCE[0]}" | sed 's/^# \{0,1\}//'; exit 0 ;;
        --*) echo "Error: unknown flag: $arg" >&2; exit 1 ;;
        flasharchive|glaiel) NAMESPACES+=("$arg") ;;
        *) echo "Error: unknown namespace '$arg' (expected flasharchive or glaiel)" >&2; exit 1 ;;
    esac
done
[ -n "$EXPECT" ] && { echo "Error: --${EXPECT} requires a value" >&2; exit 1; }
[ ${#NAMESPACES[@]} -eq 0 ] && NAMESPACES=(flasharchive glaiel)

DOCS_DIR="${REPO_ROOT}/${DOCS_DIR_REL}"
EXAMPLES_DIR="${DOCS_DIR}/examples"
[ -d "$EXAMPLES_DIR" ] || { echo "Error: examples dir not found: $EXAMPLES_DIR" >&2; exit 1; }

# ---- ensure emcc ----
if ! command -v emcc >/dev/null 2>&1; then
    if [ -f "${REPO_ROOT}/emsdk/emsdk_env.sh" ]; then
        echo "emcc not on PATH; sourcing ${REPO_ROOT}/emsdk/emsdk_env.sh ..."
        # shellcheck disable=SC1091
        source "${REPO_ROOT}/emsdk/emsdk_env.sh" >/dev/null 2>&1 || true
    fi
fi
command -v emcc >/dev/null 2>&1 || {
    echo "Error: Emscripten (emcc) not found. Run: source ${REPO_ROOT}/emsdk/emsdk_env.sh" >&2
    exit 1
}

# ---- rebuild recompiler from HEAD (unless --fast / --skip-recompiler-build) ----
if [ "$FAST" = 0 ] && [ "$SKIP_RECOMPILER_BUILD" = 0 ]; then
    if [ -f "${SWFRECOMP_ROOT}/build/CMakeCache.txt" ]; then
        echo "Rebuilding SWFRecomp recompiler (cmake --build)..."
        cmake --build "${SWFRECOMP_ROOT}/build" -j 2>&1 | tail -3
    else
        echo "Warning: no cmake build dir at ${SWFRECOMP_ROOT}/build — skipping recompiler rebuild." >&2
        echo "         Configure once with: cmake -S ${SWFRECOMP_ROOT} -B ${SWFRECOMP_ROOT}/build && cmake --build ${SWFRECOMP_ROOT}/build -j" >&2
    fi
fi
[ -x "${SWFRECOMP_ROOT}/build/SWFRecomp" ] || {
    echo "Error: SWFRecomp binary not found at ${SWFRECOMP_ROOT}/build/SWFRecomp" >&2
    exit 1
}

CLEAN_ARG=""
[ "$FAST" = 0 ] && CLEAN_ARG="--clean"

# Build the --only filter set (if any)
declare -A ONLY_SET=()
if [ -n "$ONLY_LIST" ]; then
    IFS=',' read -ra _only <<< "$ONLY_LIST"
    for o in "${_only[@]}"; do ONLY_SET["$o"]=1; done
fi

TOTAL_OK=0; TOTAL_FAIL=0; TOTAL_SKIP=0
FAILED_NAMES=()

for ns in "${NAMESPACES[@]}"; do
    ns_examples="${EXAMPLES_DIR}/${ns}"
    [ -d "$ns_examples" ] || { echo "(skip) no deployed namespace: $ns_examples"; continue; }

    echo ""
    echo "############################################################"
    echo "# Namespace: ${ns}"
    echo "############################################################"

    for d in "${ns_examples}"/*/; do
        name="$(basename "$d")"
        # Only demos that are actually deployed (have a built WASM)
        compgen -G "${d}/*.wasm" >/dev/null || continue
        # --only filter
        if [ -n "$ONLY_LIST" ] && [ -z "${ONLY_SET[$name]:-}" ]; then continue; fi

        rel="${ns}/${name}"
        test_dir="${SWFRECOMP_ROOT}/tests/${rel}"
        if [ ! -f "${test_dir}/test.swf" ]; then
            echo "  (skip) ${rel}: no build input at ${test_dir}/test.swf"
            TOTAL_SKIP=$((TOTAL_SKIP+1)); continue
        fi

        echo ""
        echo "=== ${rel} ==="
        if ! timeout "$GRAPHICS_BUILD_TIMEOUT" \
                "${SCRIPT_DIR}/build_test.sh" "${rel}" wasm --graphics ${CLEAN_ARG} 2>&1 \
                | grep -q "WASM build complete"; then
            echo "  BUILD FAILED: ${rel}"
            TOTAL_FAIL=$((TOTAL_FAIL+1)); FAILED_NAMES+=("$rel"); continue
        fi

        if ! "${SCRIPT_DIR}/deploy_example.sh" "${rel}" "${EXAMPLES_DIR}" --no-index --graphics >/dev/null 2>&1; then
            echo "  DEPLOY FAILED: ${rel}"
            TOTAL_FAIL=$((TOTAL_FAIL+1)); FAILED_NAMES+=("$rel"); continue
        fi
        echo "  OK"
        TOTAL_OK=$((TOTAL_OK+1))
    done

    # Regenerate this namespace's catalog (type MUST be the namespace).
    echo ""
    echo "Regenerating ${ns}_catalog.json (type=${ns})..."
    python3 "${SCRIPT_DIR}/generate_local_catalog.py" "${DOCS_DIR}" \
        --namespace "${ns}" \
        --catalog-name "${ns}_catalog.json" \
        --type "${ns}"
done

echo ""
echo "############################################################"
echo "# Summary"
echo "############################################################"
echo "  Built & deployed: ${TOTAL_OK}"
echo "  Skipped:          ${TOTAL_SKIP}"
echo "  Failed:           ${TOTAL_FAIL}"
if [ ${TOTAL_FAIL} -gt 0 ]; then
    echo "  Failures:"
    for f in "${FAILED_NAMES[@]}"; do echo "    - $f"; done
fi
echo ""
echo "Serve ${DOCS_DIR_REL}/ (e.g. 'cd ${DOCS_DIR_REL} && python3 -m http.server 8000')"
echo "and open index.html to view the refreshed demos."
[ ${TOTAL_FAIL} -eq 0 ]
