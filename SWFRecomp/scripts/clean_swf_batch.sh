#!/bin/bash
# Remove everything build_swf_batch.sh produced for a given (docs-dir, namespace).
#
# Cleans:
#   - SWFRecomp/tests/<namespace>/             (test scratch dirs)
#   - <docs-dir>/examples/<namespace>/         (deployed WASM artifacts)
#   - <docs-dir>/<catalog-name>                (gitignored local catalog)
#
# Does NOT touch:
#   - <docs-dir>/catalog.json                  (the upstream catalog is left alone)
#   - source SWF directory (defaults to local_swf_batch/)
#
# Usage:
#   ./scripts/clean_swf_batch.sh [--docs-dir <relpath>]
#                                [--namespace <name>]
#                                [--catalog-name <file>]
#
# Defaults match build_swf_batch.sh: docs / local_batch / local_catalog.json.

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
REPO_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"

DOCS_DIR_REL="docs"
BATCH_NAMESPACE="local_batch"
CATALOG_NAME="local_catalog.json"
EXPECT_VALUE=""
for arg in "$@"; do
    if [ -n "$EXPECT_VALUE" ]; then
        case "$EXPECT_VALUE" in
            docs-dir) DOCS_DIR_REL="$arg" ;;
            namespace) BATCH_NAMESPACE="$arg" ;;
            catalog-name) CATALOG_NAME="$arg" ;;
        esac
        EXPECT_VALUE=""
        continue
    fi
    case "$arg" in
        --docs-dir) EXPECT_VALUE=docs-dir ;;
        --namespace) EXPECT_VALUE=namespace ;;
        --catalog-name) EXPECT_VALUE=catalog-name ;;
        *) echo "Error: unknown arg: $arg"; exit 1 ;;
    esac
done
if [ -n "$EXPECT_VALUE" ]; then
    echo "Error: --${EXPECT_VALUE} requires a value"
    exit 1
fi

DOCS_DIR="${REPO_ROOT}/${DOCS_DIR_REL}"
EXAMPLES_DIR="${DOCS_DIR}/examples"
TESTS_BATCH_ROOT="${SWFRECOMP_ROOT}/tests/${BATCH_NAMESPACE}"
DEPLOY_BATCH_ROOT="${EXAMPLES_DIR}/${BATCH_NAMESPACE}"
LOCAL_CATALOG="${DOCS_DIR}/${CATALOG_NAME}"

REMOVED=0

if [ -d "${TESTS_BATCH_ROOT}" ]; then
    echo "Removing test scratch dir: ${TESTS_BATCH_ROOT}"
    rm -rf "${TESTS_BATCH_ROOT}"
    REMOVED=1
fi

if [ -d "${DEPLOY_BATCH_ROOT}" ]; then
    echo "Removing deploy dir:       ${DEPLOY_BATCH_ROOT}"
    rm -rf "${DEPLOY_BATCH_ROOT}"
    REMOVED=1
fi

if [ -f "${LOCAL_CATALOG}" ]; then
    echo "Removing local catalog:    ${LOCAL_CATALOG}"
    rm -f "${LOCAL_CATALOG}"
    REMOVED=1
fi

if [ ${REMOVED} -eq 0 ]; then
    echo "Nothing to clean — no ${BATCH_NAMESPACE} artifacts found under ${DOCS_DIR_REL}/."
    exit 0
fi

echo ""
echo "✅ ${BATCH_NAMESPACE} artifacts removed."
echo "   Source SWF directory was left alone."
echo "   ${DOCS_DIR_REL}/catalog.json was not touched."
