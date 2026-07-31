#!/usr/bin/env bash
#
# Publish this run's Ruffle test results to the `ruffle-test-results` branch.
#
# Extracted verbatim from the "Commit results to ruffle-test-results branch"
# step of .github/workflows/ruffle-tests.yml, which carried a byte-identical
# 190-line copy in BOTH the serial and combine-results jobs. Keeping two
# copies is how a one-line omission in the backup loop went unnoticed for two
# and a half months (see the results_flash.json comment below): the fix had to
# be applied twice, and the bug only had to be introduced once.
#
# Invoked from a workflow step as:
#     env:
#       MODE:    ${{ inputs.mode }}
#       LIMIT:   ${{ inputs.limit }}
#       RUN_URL: ${{ github.server_url }}/${{ github.repository }}/actions/runs/${{ github.run_id }}
#     run: bash scripts/ci/publish_results.sh
#
# The caller is responsible for NOT invoking this on runs whose numbers must
# never become a baseline (extra_defines builds, single_test runs) — see the
# step's `if:` guard.
#
# `set -e` matches the GitHub default shell (`bash -e {0}`) the inline step ran
# under. Deliberately no `pipefail`: the original step did not set it, and the
# `find | while` / `find | xargs` pipelines here tolerate a failing left side.
set -e

MODE="${MODE:?MODE (inputs.mode) must be set}"
LIMIT="${LIMIT:-0}"
RUN_URL="${RUN_URL:-}"
# "true" when this run built image_results_graphics.json; see the backup loop.
IMAGES="${IMAGES:-false}"

# Return the working tree to the commit we started on, whatever happens below.
#
# Without this the job ends with the checkout sitting on ruffle-test-results,
# which does not carry `.github/actions/`. The runner then executes the POST
# steps of any local composite action (e.g. ./.github/actions/graphics-apt-deps)
# by re-reading its action.yml from the working tree, fails with "Can't find
# 'action.yml' ... Did you forget to run actions/checkout", and marks the whole
# job failed after every real step succeeded. That is exactly how run
# 30186909756 went red on 2026-07-26.
ORIGINAL_HEAD="$(git rev-parse HEAD)"
restore_checkout() {
  local rc=$?
  git checkout --force "$ORIGINAL_HEAD" >/dev/null 2>&1 || true
  return $rc
}
trap restore_checkout EXIT

# Per-mode result-JSON stem. Each CI run produces a fresh {STEM}.json plus a
# fetched {STEM}_previous.json; everything else (filter / diff / markdown /
# index) is regenerated below against the merged ruffle-test-results state so
# the committed reports cover ALL modes consistently — not just the one we
# just ran.
case "$MODE" in
  graphics) STEM="results_graphics" ;;
  *)        STEM="results" ;;
esac

if ! find ruffle-tests/tests/swfs -path "*/_results/${STEM}.json" 2>/dev/null | grep -q .; then
  echo "No ${STEM}.json files to commit (mode=${MODE})"
  exit 0
fi

# Save this run's JSON outputs to /tmp before the branch switch (the JSONs are
# this run's only unique contribution — everything else gets regenerated from
# the merged state).
#
# results_flash.json must ride along for the same reason, and it is easy to
# miss because its stem is not derived from `mode`: it is TRACKED on
# ruffle-test-results, so the `git checkout -B` below overwrites the freshly
# generated file with the branch's copy and the `git add` at the end
# re-commits that stale copy. Left out of this loop between 2026-05-09 and
# 2026-07-26, which froze the "Flash-Spec Results" table in RUFFLE_RESULTS.md
# at a 2.5-month-old snapshot. Any future non-mode-derived result stem needs
# adding here too.
#
# image_results_graphics.json is the second such stem (2026-07-30). It is
# CONDITIONAL, which results_flash.json is not, and the condition matters in
# both directions:
#   * images=true  — this run regenerated it, so it must ride to /tmp or the
#     checkout below replaces it with the branch's copy and the freshly
#     measured image baseline is lost (the classic trap).
#   * images=false — this run did NOT regenerate it, and the copy sitting in
#     the work tree came from the MASTER checkout, which lags the branch
#     between results merges. Backing that up would push a stale image
#     baseline over a newer one. Leaving it out lets the checkout inherit the
#     branch's copy untouched, which is exactly right.
EXTRA_STEMS="results_flash.json"
if [ "${IMAGES:-false}" = "true" ]; then
  EXTRA_STEMS="$EXTRA_STEMS image_results_graphics.json"
fi
find ruffle-tests/tests/swfs -path '*/_results' -type d | while read -r dir; do
  for name in "${STEM}.json" "${STEM}_previous.json" $EXTRA_STEMS; do
    if [ -f "$dir/$name" ]; then
      mkdir -p "/tmp/results_backup/$dir"
      cp "$dir/$name" "/tmp/results_backup/$dir/"
    fi
  done
done

# Also stash the post-processing scripts so they survive the branch switch even
# if origin/ruffle-test-results lags master.
mkdir -p /tmp/scripts_backup
cp -r scripts /tmp/scripts_backup/ 2>/dev/null || true
mkdir -p /tmp/scripts_backup/ruffle-tests
cp ruffle-tests/filter_results.py /tmp/scripts_backup/ruffle-tests/ 2>/dev/null || true
cp ruffle-tests/ignored_tests.txt /tmp/scripts_backup/ruffle-tests/ 2>/dev/null || true
# Per-suite ignore lists live alongside each suite directory. Back them up so
# the filter step sees master's versions instead of the (stale) copies
# inherited from the ruffle-test-results branch — otherwise per-suite
# ignored_tests.txt edits on master never reach filter_results.py.
find ruffle-tests/tests/swfs -name ignored_tests.txt -print0 2>/dev/null | \
  while IFS= read -r -d '' f; do
    mkdir -p "/tmp/scripts_backup/$(dirname "$f")"
    cp "$f" "/tmp/scripts_backup/$f"
  done

git config user.name "github-actions[bot]"
git config user.email "github-actions[bot]@users.noreply.github.com"
git fetch origin

# Discard working tree so we can switch branches cleanly. Files we need are
# already in /tmp.
git reset --hard HEAD
# Also delete untracked `*_previous.json` files written by the "Fetch previous
# results" step. They're untracked on master but tracked on
# ruffle-test-results, so the checkout below would refuse with "untracked
# working tree files would be overwritten". The ones we need are already saved
# to /tmp/results_backup.
find ruffle-tests/tests/swfs -path '*/_results/*_previous.json' -delete 2>/dev/null || true
# Same treatment for `*_current.json`, and this one is a self-perpetuating
# trap rather than a one-off: the "Verify Flash-spec expected output" step
# writes results_flash_current.json into the master checkout on EVERY run
# (verify_output.py's incremental save), and the `git add -f '*/_results/*.json'`
# sweep at the end of this script re-commits it to ruffle-test-results. Once
# the branch tracks it, every later run's `git checkout -B ruffle-test-results`
# below aborts with "untracked working tree files would be overwritten" — so
# publishing stays broken until someone removes it by hand. Killed run
# 30317408743's publish (the tests themselves were fine). The `git rm` further
# down cannot help: it runs AFTER the checkout that fails.
find ruffle-tests/tests/swfs -path '*/_results/*_current.json' -delete 2>/dev/null || true

# Inherit from existing ruffle-test-results so prior runs' results (in any
# mode) are preserved. Falls back to current HEAD if the branch doesn't exist
# yet (first-ever push).
if git show-ref --verify --quiet refs/remotes/origin/ruffle-test-results; then
  git checkout -B ruffle-test-results origin/ruffle-test-results
else
  git checkout -B ruffle-test-results
fi

# Remove stale files from old workflow layout
for f in ruffle-results.md ruffle-results-diff.md ruffle-results-filtered.md \
         ruffle-results-headless.md ruffle-image-results.md \
         ruffle-tests/results.json ruffle-tests/results_diff.json \
         ruffle-tests/results_filtered.json ruffle-tests/image_results.json \
         ruffle-tests/results-index.md test_results.json; do
  git rm -f "$f" 2>/dev/null || true
done

# The graphics-headless-legacy mode was deleted (Phase 1 of
# mode-consolidation-plan.md). Drop its stale result files from the inherited
# branch state — otherwise every merge of ruffle-test-results back into master
# would re-add them.
git ls-files -z '*/_results/results_headless*' 'RUFFLE_RESULTS_HEADLESS*' \
  | xargs -0 -r git rm -q -f --ignore-unmatch || true

# *_current.json is a per-run intermediate that verify_output.py writes only
# for a partial/interrupted run; nothing reads it after the process exits. One
# (results_flash_current.json) was captured by the `git add` glob during a May
# 2026 run and has been carried forward on the branch ever since. Drop the
# whole class.
git ls-files -z '*/_results/*_current.json' \
  | xargs -0 -r git rm -q -f --ignore-unmatch || true

# Restore this mode's JSON outputs onto the inherited branch state.
find /tmp/results_backup/ruffle-tests/tests/swfs -path '*/_results' -type d 2>/dev/null | while read -r dir; do
  real_dir="${dir#/tmp/results_backup/}"
  mkdir -p "$real_dir"
  cp "$dir"/* "$real_dir/" 2>/dev/null || true
done

# Restore scripts in case origin/ruffle-test-results lacks newer versions (the
# user merges results back periodically; in between, ruffle-test-results may
# lag master on script changes).
if [ -d /tmp/scripts_backup/scripts ]; then
  cp -r /tmp/scripts_backup/scripts/* scripts/ 2>/dev/null || true
fi
if [ -f /tmp/scripts_backup/ruffle-tests/filter_results.py ]; then
  cp /tmp/scripts_backup/ruffle-tests/filter_results.py ruffle-tests/
fi
if [ -f /tmp/scripts_backup/ruffle-tests/ignored_tests.txt ]; then
  cp /tmp/scripts_backup/ruffle-tests/ignored_tests.txt ruffle-tests/
fi
# Restore per-suite ignore lists onto the ruffle-test-results working tree (see
# the backup step above) so filter_results.py reads master's versions and the
# commit carries them forward.
if [ -d /tmp/scripts_backup/ruffle-tests/tests/swfs ]; then
  find /tmp/scripts_backup/ruffle-tests/tests/swfs -name ignored_tests.txt -print0 2>/dev/null | \
    while IFS= read -r -d '' f; do
      dest="${f#/tmp/scripts_backup/}"
      mkdir -p "$(dirname "$dest")"
      cp "$f" "$dest"
    done
fi

# Regenerate filtered results for every mode JSON we now have.
# filter_results.py derives the output name from the input stem
# (results.json → results_filtered.json,
#  results_graphics.json → results_graphics_filtered.json, etc.).
for stem in results results_graphics; do
  find ruffle-tests/tests/swfs -path "*/_results/${stem}.json" | while read -r f; do
    python3 ruffle-tests/filter_results.py "$f" || true
  done
done

# Regenerate the per-mode diff report against this run's previous baseline
# (fetched into ${STEM}_previous.json before tests ran and carried over from
# /tmp).
find ruffle-tests/tests/swfs -path "*/_results/${STEM}.json" | while read -r f; do
  dir=$(dirname "$f")
  if [ -f "$dir/${STEM}_previous.json" ]; then
    python3 scripts/diff_ruffle_results.py "$dir/${STEM}_previous.json" "$f" \
      --json="$dir/${STEM}_diff.json" --markdown="$dir/${STEM}_diff.md" || true
  fi
done

# Regenerate markdown reports + cross-suite index for every mode.
python3 scripts/generate_ruffle_results_markdown.py --scan || true
python3 scripts/generate_results_index.py || true

# Drop per-run intermediates from the working tree before the sweep below —
# `git add -f '*/_results/*.json'` is indiscriminate, and re-adding a
# *_current.json is what breaks the NEXT run's branch checkout (see the
# matching note above the branch switch). Nothing reads these after the
# process that wrote them exits.
find ruffle-tests/tests/swfs -path '*/_results/*_current.json' -delete 2>/dev/null || true

find ruffle-tests/tests/swfs -path '*/_results/*.json' -o -path '*/_results/*.md' | xargs git add -f 2>/dev/null || true
git add -f RUFFLE_RESULTS*.md 2>/dev/null || true

if git diff --staged --quiet; then
  echo "No changes to commit"
  exit 0
fi

LIMIT_MSG=""
if [ "$LIMIT" != "0" ] && [ -n "$LIMIT" ]; then
  LIMIT_MSG=" (limit=${LIMIT})"
fi
MODE_MSG=""
if [ "$MODE" != "no-graphics" ]; then
  MODE_MSG=" (mode=${MODE})"
fi

git commit -m "Update Ruffle test results${MODE_MSG}${LIMIT_MSG}" \
  -m "Workflow run: ${RUN_URL}"

git push -f origin ruffle-test-results
