#!/bin/bash
# Remove everything build_swf_batch.sh produced and regenerate the index.
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

if [ ${REMOVED} -eq 0 ]; then
    echo "Nothing to clean — no local_batch artifacts found."
    exit 0
fi

# Regenerate the index + catalog so the page no longer references the batch.
if [ -d "${EXAMPLES_DIR}" ] && [ -x "${SCRIPT_DIR}/generate_examples_index.sh" ]; then
    echo "Regenerating examples index..."
    "${SCRIPT_DIR}/generate_examples_index.sh" "${DOCS_DIR}"
fi

echo ""
echo "✅ Local-batch artifacts removed."
echo "   Source files in ${REPO_ROOT}/local_swf_batch/ were left alone."
