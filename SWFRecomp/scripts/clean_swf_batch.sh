#!/bin/bash
# Remove everything build_swf_batch.sh produced.
#
# Cleans:
#   - SWFRecomp/tests/local_batch/        (test scratch dirs)
#   - docs/examples/local_batch/          (deployed WASM artifacts)
#   - docs/local_catalog.json             (gitignored local catalog)
#
# Does NOT touch:
#   - docs/catalog.json                   (the upstream catalog is left alone)
#   - local_swf_batch/                    (source SWFs)
#
# Usage: ./scripts/clean_swf_batch.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
REPO_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"

DOCS_DIR="${REPO_ROOT}/docs"
EXAMPLES_DIR="${DOCS_DIR}/examples"
BATCH_NAMESPACE="local_batch"
TESTS_BATCH_ROOT="${SWFRECOMP_ROOT}/tests/${BATCH_NAMESPACE}"
DEPLOY_BATCH_ROOT="${EXAMPLES_DIR}/${BATCH_NAMESPACE}"
LOCAL_CATALOG="${DOCS_DIR}/local_catalog.json"

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
    echo "Nothing to clean — no local_batch artifacts found."
    exit 0
fi

echo ""
echo "✅ Local-batch artifacts removed."
echo "   Source files in ${REPO_ROOT}/local_swf_batch/ were left alone."
echo "   docs/catalog.json was not touched."
