#!/bin/bash
# Build and deploy every wasm probe under SWFRecomp/tests/wasm_probes/.
#
# Per probe directory <slug>/:
#   1. swfmill xml2swf test.xml -> test.swf (if test.xml newer than test.swf)
#   2. SWFRecomp config.toml    -> RecompiledScripts/, RecompiledTags/
#   3. build_test.sh wasm_probes/<slug> wasm --graphics
#   4. deploy_example.sh wasm_probes/<slug> docs2/examples --no-index --graphics
#
# Idempotent: skips a probe whose test.swf and build/wasm/<slug>.wasm are both
# newer than their inputs. Pass --force or a probe slug arg to override.
#
# Usage:
#   ./scripts/build_wasm_probes.sh                 # build all probes (idempotent)
#   ./scripts/build_wasm_probes.sh --force         # rebuild everything
#   ./scripts/build_wasm_probes.sh leaf_shared_slot # build a single probe

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
REPO_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
PROBES_DIR="${SWFRECOMP_ROOT}/tests/wasm_probes"
DEPLOY_ROOT="${REPO_ROOT}/docs2/examples"

if ! command -v swfmill &> /dev/null; then
    echo "Error: swfmill not found in PATH" >&2
    exit 1
fi

if [ ! -x "${SWFRECOMP_ROOT}/build/SWFRecomp" ]; then
    echo "Error: SWFRecomp binary not found at ${SWFRECOMP_ROOT}/build/SWFRecomp" >&2
    echo "Build it first via the project's normal build workflow." >&2
    exit 1
fi

FORCE=false
SINGLE_SLUG=""
for arg in "$@"; do
    if [ "$arg" = "--force" ]; then
        FORCE=true
    elif [[ "$arg" != --* ]]; then
        SINGLE_SLUG="$arg"
    fi
done

# Pick which probe dirs to process.
PROBE_DIRS=()
if [ -n "$SINGLE_SLUG" ]; then
    if [ ! -d "${PROBES_DIR}/${SINGLE_SLUG}" ]; then
        echo "Error: probe '${SINGLE_SLUG}' not found at ${PROBES_DIR}/${SINGLE_SLUG}" >&2
        exit 1
    fi
    PROBE_DIRS=("${PROBES_DIR}/${SINGLE_SLUG}")
else
    for d in "${PROBES_DIR}"/*/; do
        [ -d "$d" ] || continue
        PROBE_DIRS+=("${d%/}")
    done
fi

if [ ${#PROBE_DIRS[@]} -eq 0 ]; then
    echo "No probes found under ${PROBES_DIR}"
    exit 0
fi

PROCESSED=0
SKIPPED=0
FAILED=0

newer_than() {
    # Returns true (0) if $1 is newer than $2, false otherwise. Accepts both
    # files and directories. If $2 does not exist, $1 is considered newer.
    [ -e "$1" ] || return 1
    [ -e "$2" ] || return 0
    [ "$1" -nt "$2" ]
}

for probe_dir in "${PROBE_DIRS[@]}"; do
    slug="$(basename "$probe_dir")"
    xml="${probe_dir}/test.xml"
    swf="${probe_dir}/test.swf"
    wasm="${probe_dir}/build/wasm/${slug}.wasm"

    if [ ! -f "$xml" ]; then
        echo "[skip ] ${slug}: no test.xml"
        SKIPPED=$((SKIPPED + 1))
        continue
    fi

    needs_xml2swf=false
    needs_recompile=false
    needs_wasm=false
    if [ "$FORCE" = true ]; then
        needs_xml2swf=true
        needs_recompile=true
        needs_wasm=true
    else
        if newer_than "$xml" "$swf"; then
            needs_xml2swf=true
            needs_recompile=true
            needs_wasm=true
        fi
        if [ ! -d "${probe_dir}/RecompiledScripts" ] \
           || [ ! -d "${probe_dir}/RecompiledTags" ]; then
            needs_recompile=true
            needs_wasm=true
        elif newer_than "$swf" "${probe_dir}/RecompiledScripts"; then
            needs_recompile=true
            needs_wasm=true
        fi
        if [ ! -f "$wasm" ] || newer_than "$swf" "$wasm"; then
            needs_wasm=true
        fi
    fi

    if [ "$needs_xml2swf" = false ] \
       && [ "$needs_recompile" = false ] \
       && [ "$needs_wasm" = false ]; then
        echo "[skip ] ${slug}: up-to-date"
        SKIPPED=$((SKIPPED + 1))
        continue
    fi

    echo "[build] ${slug}"

    if [ "$needs_xml2swf" = true ]; then
        echo "  swfmill xml2swf"
        ( cd "$probe_dir" && swfmill xml2swf test.xml test.swf )
    fi

    if [ "$needs_recompile" = true ]; then
        echo "  recompile"
        rm -rf "${probe_dir}/RecompiledScripts" "${probe_dir}/RecompiledTags"
        ( cd "$probe_dir" \
          && bash -c 'ulimit -v 4194304; ulimit -s unlimited; exec "$@"' \
                -- "${SWFRECOMP_ROOT}/build/SWFRecomp" config.toml )
    fi

    if [ "$needs_wasm" = true ]; then
        echo "  wasm build"
        rm -rf "${probe_dir}/build/wasm"
        # build_test.sh re-runs SWFRecomp only when RecompiledScripts/ is
        # missing, so the recompile step above is preserved.
        "${SCRIPT_DIR}/build_test.sh" "wasm_probes/${slug}" wasm --graphics
    fi

    echo "  deploy"
    "${SCRIPT_DIR}/deploy_example.sh" \
        "wasm_probes/${slug}" "${DEPLOY_ROOT}" --no-index --graphics \
        > /dev/null

    PROCESSED=$((PROCESSED + 1))
done

echo ""
echo "Probes: ${PROCESSED} built, ${SKIPPED} skipped, ${FAILED} failed"
