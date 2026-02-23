#!/usr/bin/env bash
# Sets up a git worktree for one (or all) incomplete investigation plans.
#
# Usage:
#   ./CC/scripts/setup_investigation_worktree.sh PLAN_NAME
#   ./CC/scripts/setup_investigation_worktree.sh all
#   ./CC/scripts/setup_investigation_worktree.sh --first N
#
# PLAN_NAME is the basename of the .md file without extension, e.g.:
#   ARRAY_METHODS_PLAN  or  array_methods_plan  (case-insensitive)
#
# --first N sets up the first N plans in alphabetical order.
#
# Worktrees are created at:  CC/SWFRecomp-CC-<plan-slug>/
# Branches are named:        investigation/<plan-slug>
# A PROMPT.txt is written to the worktree root with the Claude prompt.

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
INCOMPLETE_DIR="$REPO_ROOT/ruffle-tests/_investigation/incomplete"
WORKTREE_PARENT="$(dirname "$REPO_ROOT")"

if [[ $# -lt 1 ]]; then
    echo "Usage: $0 PLAN_NAME | all | --first N"
    echo ""
    echo "Available plans:"
    for f in "$INCOMPLETE_DIR"/*.md; do
        echo "  $(basename "${f%.md}")"
    done
    exit 1
fi

ARG="${1:-}"

# Collect plan files to process
declare -a PLAN_FILES=()
if [[ "$ARG" == "all" ]]; then
    for f in "$INCOMPLETE_DIR"/*.md; do
        PLAN_FILES+=("$f")
    done
elif [[ "$ARG" == "--first" ]]; then
    if [[ $# -lt 2 || ! "${2:-}" =~ ^[0-9]+$ ]]; then
        echo "Error: --first requires a numeric argument"
        exit 1
    fi
    N="$2"
    count=0
    for f in "$INCOMPLETE_DIR"/*.md; do
        PLAN_FILES+=("$f")
        count=$(( count + 1 ))
        [[ "$count" -ge "$N" ]] && break
    done
else
    # Normalise to uppercase for lookup
    UPPER="${ARG^^}"
    MATCH=""
    for f in "$INCOMPLETE_DIR"/*.md; do
        basename_upper="$(basename "${f%.md}" | tr '[:lower:]' '[:upper:]')"
        if [[ "$basename_upper" == "$UPPER" ]]; then
            MATCH="$f"
            break
        fi
    done
    if [[ -z "$MATCH" ]]; then
        echo "Error: no plan found matching '$ARG' in $INCOMPLETE_DIR"
        echo ""
        echo "Available plans:"
        for f in "$INCOMPLETE_DIR"/*.md; do
            echo "  $(basename "${f%.md}")"
        done
        exit 1
    fi
    PLAN_FILES=("$MATCH")
fi

CD_COMMANDS_FILE="$WORKTREE_PARENT/worktree_cd_commands.txt"
declare -a WORKTREE_DIRS=()

setup_worktree() {
    local filepath="$1"
    local filename
    filename="$(basename "$filepath")"
    local docname="${filename%.md}"

    # slug: lowercase, underscores to hyphens
    local slug
    slug="$(echo "$docname" | tr '[:upper:]' '[:lower:]' | tr '_' '-')"

    local branch="investigation/$slug"
    local worktree_dir="$WORKTREE_PARENT/SWFRecomp-CC-$slug"

    echo "=== Setting up worktree for $docname ==="
    echo "  Branch:   $branch"
    echo "  Path:     $worktree_dir"

    # Check if worktree already exists
    if git -C "$REPO_ROOT" worktree list | grep -qF "$worktree_dir"; then
        echo "  [skip] Worktree already exists at $worktree_dir"
    else
        # Create branch if it doesn't exist
        if git -C "$REPO_ROOT" show-ref --quiet "refs/heads/$branch"; then
            echo "  Branch already exists, reusing."
            git -C "$REPO_ROOT" worktree add "$worktree_dir" "$branch"
        else
            git -C "$REPO_ROOT" worktree add -b "$branch" "$worktree_dir"
        fi
        echo "  Worktree created."
    fi

    # Write PROMPT.txt into the worktree
    local prompt_file="$worktree_dir/PROMPT.txt"
    cat > "$prompt_file" <<EOF
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

    echo "  PROMPT.txt written."
    echo ""

    WORKTREE_DIRS+=("$worktree_dir")
}

for plan_file in "${PLAN_FILES[@]}"; do
    setup_worktree "$plan_file"
done

# Write cd commands file
> "$CD_COMMANDS_FILE"
for wt in "${WORKTREE_DIRS[@]}"; do
    echo "cd $wt" >> "$CD_COMMANDS_FILE"
done
echo "cd commands written to: $CD_COMMANDS_FILE"
echo ""

if [[ "${#PLAN_FILES[@]}" -gt 1 ]]; then
    echo "All worktrees ready. Active worktrees:"
    git -C "$REPO_ROOT" worktree list
fi
