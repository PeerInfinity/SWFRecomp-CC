#!/usr/bin/env bash
# Generates a text file with one prompt block per incomplete investigation document.
# Output: SWFRecomp-CC/ruffle-tests/_investigation/investigation_prompts.txt
#
# Usage:
#   ./CC/scripts/gen_investigation_prompts.sh

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
INCOMPLETE_DIR="$REPO_ROOT/ruffle-tests/_investigation/incomplete"
OUTPUT_FILE="$REPO_ROOT/ruffle-tests/_investigation/investigation_prompts.txt"
SEPARATOR=$(printf '=%.0s' {1..80})

> "$OUTPUT_FILE"

first=1
for filepath in "$INCOMPLETE_DIR"/*.md; do
    filename=$(basename "$filepath")
    docname="${filename%.md}"

    if [ "$first" -eq 1 ]; then
        first=0
    else
        printf '\n\n\n%s\n\n\n' "$SEPARATOR" >> "$OUTPUT_FILE"
    fi

    cat >> "$OUTPUT_FILE" <<EOF
Please read these files:
- ruffle-tests/_investigation/ENVIRONMENT_SETUP.md
- ruffle-tests/_investigation/SESSION_START_GUIDE.md
- ruffle-tests/_investigation/CURRENT_STATUS.md
- ruffle-tests/_investigation/incomplete/${filename}

Then follow these steps in order:

1. **Environment check:** Verify \`SWFRecomp/build/SWFRecomp\` exists. If not, build it per ENVIRONMENT_SETUP.md before doing anything else.

2. **Baseline:** Run the specific tests named in the plan to see which are currently passing and which are failing.

3. **Assess and update:** Based on the test results (not just code reading), determine which parts of the plan are done. Update the planning document to reflect current status.

4. **Implement:** Work through the remaining items one at a time. After each change, run the affected tests to verify progress. Commit working changes.

5. **Stop when:** the plan is fully passing, or you hit a blocker — in which case document the blocker in the plan file before stopping. If there are remaining failures, and the plan to fix them is blocked, then move the document to ruffle-tests/_investigation/blocked/  If the plan is complete and all the tests pass, then move the document to ruffle-tests/_investigation/complete/
EOF
done

echo "Written $OUTPUT_FILE"
