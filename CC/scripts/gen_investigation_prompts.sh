#!/usr/bin/env bash
# Generates a text file with one prompt block per incomplete/blocked investigation document.
# Covers all test suites: avm1, from_gnash, from_shumway.
#
# Each suite uses the same directory structure:
#   _investigation/incomplete/  — plans with remaining work, no known blockers
#   _investigation/blocked/     — plans with known blockers preventing progress
#   _investigation/complete/    — finished plans (not included in prompts)
#
# Output per suite:
#   ruffle-tests/tests/swfs/{suite}/_investigation/investigation_prompts.txt
#
# Usage:
#   ./CC/scripts/gen_investigation_prompts.sh

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
SWFS_DIR="$REPO_ROOT/ruffle-tests/tests/swfs"
SEPARATOR=$(printf '=%.0s' {1..80})

emit_prompt() {
    local suite="$1"
    local subdir="$2"
    local filepath="$3"
    local output_file="$4"
    local results_hint="$5"
    local filename
    filename=$(basename "$filepath")

    if [ "$first" -eq 1 ]; then
        first=0
    else
        printf '\n\n\n%s\n\n\n' "$SEPARATOR" >> "$output_file"
    fi

    cat >> "$output_file" <<EOF
Please read these files:
- ruffle-tests/tests/swfs/_investigation/ENVIRONMENT_SETUP.md
- ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md
- ruffle-tests/tests/swfs/${suite}/_investigation/CURRENT_STATUS.md
- ruffle-tests/tests/swfs/${suite}/_investigation/${subdir}/${filename}

Then follow these steps in order:

1. **Environment check:** Verify \`SWFRecomp/build/SWFRecomp\` exists. If not, build it per ENVIRONMENT_SETUP.md before doing anything else.

2. **Check latest results:** Read the results file(s) below to see which tests are currently passing/failing — this avoids running every test manually:
${results_hint}
3. **Baseline:** Run the specific tests named in the plan that are still failing to confirm current status:
   \`\`\`
   python3 ruffle-tests/verify_output.py --test=TEST_NAME --diff --verbose
   \`\`\`

EOF

    if [ "$subdir" = "blocked" ]; then
        cat >> "$output_file" <<EOF
> **Note:** This plan was previously blocked. The primary goals below are to bring the
> document up to date and investigate whether the blocker can be overcome.

4. **Update the document:** Based on the test results and current codebase state, check whether the planning document is still accurate. Update any stale information (e.g., tests that now pass, analysis that is outdated, status sections that no longer reflect reality).

5. **Investigate unblocking:** Look into whether the blocker (described in the plan) has been resolved or can now be worked around. Consider:
   - Has relevant code changed since the plan was blocked?
   - Are there alternative approaches that avoid the blocker entirely?
   - Can the blocker be partially resolved to make progress on some tests?

6. **If unblockable:** If you find a way forward, implement fixes and move the plan to \`incomplete/\` (or \`complete/\` if fully passing). If the way forward requires a substantially different approach, create a new planning document in \`incomplete/\` that describes the new strategy, and note in the blocked plan that it has been superseded.

7. **If still blocked:** Update the plan with any new findings and leave it in \`blocked/\`. Document what you investigated and why it remains blocked.

**IMPORTANT: Do NOT run the full test suite.** Only run individual tests with \`--test=TEST_NAME\`.
EOF
    else
        cat >> "$output_file" <<EOF
4. **Assess and update:** Based on the test results (not just code reading), determine which parts of the plan are done. Update the planning document to reflect current status.

5. **Implement:** Work through the remaining items one at a time. After each change, run the affected tests to verify progress. Commit working changes.

6. **Stop when:** the plan is fully passing, or you hit a blocker.
   - **All tests pass:** move the plan to \`ruffle-tests/tests/swfs/${suite}/_investigation/complete/\`
   - **Blocker hit:** document the blocker in the plan file, then move it to \`ruffle-tests/tests/swfs/${suite}/_investigation/blocked/\`
   - **Progress but not done:** leave the plan in \`incomplete/\` with updated status notes.

**IMPORTANT: Do NOT run the full test suite.** Only run individual tests with \`--test=TEST_NAME\`.
EOF
    fi

    cat >> "$output_file" <<'EOF'

**When you're done — whether finished, stopped at a blocker, or pausing with progress — hand off to the pipeline:**

1. Commit your changes.
2. Read `.pipeline-state` at the repo root (create it as `{"stage":"idle","auto":false,"run_id":null,"branch":null}` if missing). Set `stage` to `committed` and save.
3. **If `auto` is `true`:** drive the remaining stages yourself by following the instructions in `.claude/commands/pipeline.md` — push, trigger the workflow, watch it to completion, fetch and merge `ruffle-test-results`, then diff and summarize regressions. Update `.pipeline-state` between stages exactly as that file describes. Stop only on error, merge conflict, or after the `analyzing` stage completes.
4. **If `auto` is `false`:** stop and tell the user: `Ready — run /pipeline next to push, trigger the ruffle-tests workflow, merge results, and analyze regressions. (Or /pipeline auto on first to chain them.)`
EOF
}

for suite in avm1 from_gnash from_shumway; do
    SUITE_DIR="$SWFS_DIR/${suite}/_investigation"
    [ -d "$SUITE_DIR" ] || continue

    # Build results hint for this suite
    results_hint=""
    while IFS= read -r rpath; do
        rel="${rpath#"$REPO_ROOT/"}"
        results_hint="${results_hint}   - ${rel}
"
    done < <(find "$SWFS_DIR/$suite" -path '*/_results/results.json' 2>/dev/null | sort)
    # Fallback if no _results dirs found
    if [ -z "$results_hint" ]; then
        results_hint="   (no results files found yet for this suite)
"
    fi

    SUITE_OUTPUT="$SUITE_DIR/investigation_prompts.txt"
    > "$SUITE_OUTPUT"
    first=1

    for subdir in incomplete blocked; do
        for filepath in "$SUITE_DIR/$subdir"/*.md; do
            [ -e "$filepath" ] || continue
            emit_prompt "$suite" "$subdir" "$filepath" "$SUITE_OUTPUT" "$results_hint"
        done
    done

    if [ "$first" -eq 0 ]; then
        echo "Written $SUITE_OUTPUT"
    else
        rm -f "$SUITE_OUTPUT"
        echo "No plans found for $suite — skipped"
    fi
done
