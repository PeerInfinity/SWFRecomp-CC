#!/usr/bin/env bash
#
# Publish this run's FAILING image comparisons to the `ruffle-image-results`
# branch as a single force-pushed commit.
#
# Design constraints, all deliberate:
#
#   * FAILING ONLY. verify_output.py --image-out-dir exports nothing for a
#     passing comparison, so what arrives here is already review-sized.
#   * SINGLE COMMIT, FORCE-PUSHED. The branch is built from scratch in a temp
#     git repo every run and replaces the remote outright — no history, so PNG
#     blobs from old runs become unreachable instead of accumulating forever.
#     Never merge this branch into master.
#   * NO SHARED WORKTREE. It builds in $RUNNER_TEMP with its own `git init`,
#     so it cannot interact with publish_results.sh's branch switching in the
#     checkout (that script's own comment explains what branch juggling in the
#     work tree costs).
#
# Invoked from a workflow step as:
#     env:
#       IMAGE_SRC: <dir of collected per-shard PNG exports>
#       RUN_URL:   ${{ github.server_url }}/.../runs/${{ github.run_id }}
#       GH_TOKEN:  ${{ secrets.GITHUB_TOKEN }}
#     run: bash scripts/ci/publish_images.sh
#
set -eu

IMAGE_SRC="${IMAGE_SRC:?IMAGE_SRC must be set}"
BRANCH="${IMAGE_BRANCH:-ruffle-image-results}"
RUN_URL="${RUN_URL:-}"
STEM="${STEM:-results_graphics}"

if [ ! -d "$IMAGE_SRC" ] || [ -z "$(find "$IMAGE_SRC" -name '*.png' -print -quit)" ]; then
  echo "No failing image PNGs collected — nothing to publish to $BRANCH."
  echo "(A run where every comparison passed lands here too; that is correct.)"
  exit 0
fi

WORK="$(mktemp -d "${RUNNER_TEMP:-/tmp}/imgbranch.XXXXXX")"
mkdir -p "$WORK/images"
cp -r "$IMAGE_SRC"/. "$WORK/images/"

echo "Collected $(find "$WORK/images" -name '*.png' | wc -l) PNGs across "\
"$(find "$WORK/images" -mindepth 2 -maxdepth 2 -type d | wc -l) tests."

# index.md / index.json: test -> files -> outliers/max_diff. Built from the
# merged per-suite results, so the index covers every failing comparison even
# if a shard's PNG upload was lost (the row is there with no file links).
SUITES_ARG=""
[ -f image_suites.txt ] && SUITES_ARG="--suites-file=image_suites.txt"
python3 scripts/build_image_report.py --stem="$STEM" --no-write-per-suite \
  $SUITES_ARG --index-dir="$WORK" --png-dir="$WORK/images"

cat > "$WORK/README.md" <<EOF
# ruffle-image-results

Failing image comparisons from the most recent \`ruffle-tests.yml\` run
dispatched with \`images=true\`.

**This branch is rebuilt from scratch and force-pushed on every image run.**
It has no history and must never be merged into \`master\`. Passing renders are
not published.

- \`index.md\` — human-readable table: test, comparison, outliers vs budget,
  max channel difference, magnitude band, links to the PNGs.
- \`index.json\` — the same data, machine-readable.
- \`images/<suite>/<test>/<cmp>.actual.png\` — what we rendered.
- \`images/<suite>/<test>/<cmp>.difference.png\` — per-channel absolute
  difference, RGB brightened x4, alpha 0 where every channel matched.

The expected PNGs are not copied here; they live in the test directories on
\`master\` as \`<cmp>.expected.png\`.

Renders are graded on CI's lavapipe software Vulkan. Local Dawn/WSL2 renders
are not pixel-identical to it and are advisory only.

Run: ${RUN_URL}
EOF

cd "$WORK"
git init -q -b "$BRANCH"
git config user.name "github-actions[bot]"
git config user.email "github-actions[bot]@users.noreply.github.com"
git add -A
git commit -q -m "Ruffle image comparison failures" -m "Workflow run: ${RUN_URL}"

REMOTE="https://x-access-token:${GH_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"
git push -f "$REMOTE" "$BRANCH"
echo "Force-pushed $(git rev-parse --short HEAD) to $BRANCH"
