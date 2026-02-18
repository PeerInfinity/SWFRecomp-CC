#!/usr/bin/env bash
# Removes all investigation worktrees and their branches.
#
# Usage:
#   ./scripts/cleanup_investigation_worktrees.sh [--keep-branches]
#
# By default, deletes both the worktree directories and the investigation/*
# branches. Pass --keep-branches to remove only the worktrees.

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
KEEP_BRANCHES=0

for arg in "$@"; do
    case "$arg" in
        --keep-branches) KEEP_BRANCHES=1 ;;
        *) echo "Unknown argument: $arg"; exit 1 ;;
    esac
done

# Collect investigation worktrees (all except the main one)
declare -a WORKTREES=()
while IFS= read -r line; do
    path="$(echo "$line" | awk '{print $1}')"
    if [[ "$path" != "$REPO_ROOT" ]]; then
        WORKTREES+=("$path")
    fi
done < <(git -C "$REPO_ROOT" worktree list | grep "investigation/")

if [[ "${#WORKTREES[@]}" -eq 0 ]]; then
    echo "No investigation worktrees found."
    exit 0
fi

echo "Will remove ${#WORKTREES[@]} worktree(s):"
for wt in "${WORKTREES[@]}"; do
    echo "  $wt"
done
if [[ "$KEEP_BRANCHES" -eq 0 ]]; then
    echo "  (and their investigation/* branches)"
fi
echo ""
read -r -p "Proceed? [y/N] " confirm
if [[ "$confirm" != "y" && "$confirm" != "Y" ]]; then
    echo "Aborted."
    exit 0
fi

for wt in "${WORKTREES[@]}"; do
    # Extract branch name from worktree list
    branch="$(git -C "$REPO_ROOT" worktree list | grep -F "$wt" | grep -oP '\[.*?\]' | tr -d '[]')"

    echo "Removing worktree: $wt"
    git -C "$REPO_ROOT" worktree remove --force "$wt"

    if [[ "$KEEP_BRANCHES" -eq 0 && -n "$branch" ]]; then
        echo "Deleting branch: $branch"
        git -C "$REPO_ROOT" branch -D "$branch"
    fi
done

git -C "$REPO_ROOT" worktree prune
echo ""
echo "Done. Remaining worktrees:"
git -C "$REPO_ROOT" worktree list
