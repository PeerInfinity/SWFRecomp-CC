# Graphics fan-out playbook

**The graphics analog of the polish-sweep method** (`polish-sweep-arc.md` §0 +
`parallel-fanout-wave-pattern`): how to run a corpus session on the PIXEL axis
with the same one-line kickoff the trace sessions use. Built by session 9
(2026-08-01, the graphics *setup* session — wave reports in
`session9-graphics-setup-reports/`), which shipped the three instruments this
doc orchestrates:

- `scripts/image_triage.py` — mechanism clustering + the ranked board
- `scripts/image_status_diff.py` — image-axis regression accounting
- `ruffle-tests/render_canary.py` + `render_canary_tests.txt` — local A/B canary

Standing facts that override intuition imported from the trace side:

1. **Image comparisons never gate trace pass/fail.** The two axes are
   independent instruments; do not average them or read a rise in one as
   progress on the other (`graphics-image-baseline.md` §"What this instrument
   can and can't tell us").
2. **The unique-comparison denominator is 566**, not 567 —
   `from_shumway/avm1/*` double-counts one nested comparison (w1a §6).
3. **The pixel gap is structural, not AA** — and mechanism/magnitude are
   near-collinear at the extremes: `hairline_edge_drift` owns almost all
   near-passes (the lavapipe-AA gap, mostly unfixable), `blank_render` owns the
   catastrophic band. **A near-pass ranking alone aims the session at the least
   fixable cluster.** Rank by mechanism first (w1b).
4. **CI's lavapipe is the grade; local Dawn is not pixel-identical to it.**
   Local renders answer "did my change move the pixels"; only CI answers "are
   the pixels right".
5. Renders are byte-deterministic locally AND on CI — two runs at one SHA are
   identical. A "fluctuating" image result is a bug, not noise.

## 1. Session shape (two-wave, one CI run)

Same as the trace fan-out (`parallel-fanout-wave-pattern`), with these
graphics-specific substitutions:

**Kickoff (coordinator, ~15 min).** Regenerate the board — it goes stale the
same way the near-pass list does:

```bash
git fetch origin ruffle-image-results
mkdir -p <scratch>/image-results
git archive origin/ruffle-image-results | tar -x -C <scratch>/image-results
python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 4 \
    --out <scratch>/board.json --markdown <scratch>/board.md
```

22–25 s. The board gives cluster totals, cluster×band cross-tab, per-test
roll-up, disposition flags, and frame-phase suspects. Check the PROVENANCE
line: the board is only as fresh as the last merged `images=true` run.

**Wave 1 — diagnosis, parallel, read-only.** Briefs assign *clusters* (the
mechanism key), not bands. Per standing rule, every brief checks its targets
against ACCEPTED_DIFFS.md / RUFFLE_VS_FLASH_DIFFERENCES.md /
`ignored_tests.txt` — but note the **hard/soft disposition split** (§3): a
trace-axis disposition does NOT excuse a pixel failure. The fixability oracle
for a cluster is `ruffle-tests/triage_image_tests.py` (us-vs-Ruffle-vs-Flash
three-way; needs the Ruffle exporter built at `~/CC/ruffle`): B-FIXABLE means
the correct output is demonstrably achievable, A-INHERENT means Ruffle can't
match Flash either → ACCEPTED_DIFFS candidate.

**Wave 2 — implementation, parallel, isolated worktrees.** Each agent follows
the worktree recipe (§5), captures a `before` canary leg FIRST, implements,
then delivers `git diff` → patch + report + an expected-flip ledger naming
each comparison it should flip on CI. Nothing commits.

**Merge + closeout (coordinator).** Apply patches serially; after each
runtime-touching patch, `render_canary.py compare` against the pre-merge leg
(only the patch's own ledger entries may DIFFER). Then ONE CI run:

```bash
gh workflow run ruffle-tests.yml --ref master \
  -f mode=graphics -f categories=full -f images=true
```

After it completes: merge `origin/ruffle-test-results`, then run the
accounting (§4), then dispatch a `deploy-pages.yml` run — the dashboard does
NOT refresh itself when results merge.

## 2. The board: regeneration + clustering keys

- **Regenerate every session.** Both inputs move: the per-suite
  `_results/image_results_graphics.json` stems update on every merged
  `images=true` run, and `ruffle-image-results` is force-pushed (one commit,
  no history) so the PNG set is always exactly the last run's failures.
- **The clustering key is the 15-way mechanism classifier** (w1b §2,
  implemented in `image_triage.py`): same_geometry_wrong_fill,
  hairline_edge_drift, blank_render, missing_element, content_displaced,
  extra_element, diffuse_mixed, halo_penumbra, row_banded, unrelated_content,
  global_color_shift, no_render, offset_translation, whole_frame_wrong,
  localized_region. Expect the productive key to CHANGE between sessions the
  way trace clustering keys did (polish-sweep lesson) — the classifier's
  feature dump (`--test suite/name`) is the raw material for inventing the
  next key.
- **Never trust the published `.difference.png`** — it is ×4-brightened and
  alpha-mangled. `image_triage.py` recomputes diffs from actual+expected;
  anything else must too. And on Pillow ≥9.2, RGBA `getbbox()` defaults to
  alpha-only — pass `alpha_only=False` or you'll miss every RGB-only change
  (w2-3 trap).
- **Frame-phase suspects outrank their cluster.** A test whose own frames
  disagree about the mechanism is usually a timeline phase bug wearing several
  costumes (the gnash `simple_loop_test` lesson — its ACCEPTED_DIFFS entry
  covered frames 1–2 only, and the entry now carries an
  `<!-- image-axis: ... -->` scope marker; the board prints these tests even
  when dispositioned).

## 3. Dispositions: hard vs soft

Applying `ignored_tests.txt` the way trace filtering does would delete 113 of
403 failing comparisons from the board — including whole families
(Stage3D, bitmapdata, focusrect) whose ignore entries are *trace-axis* triage
written before any implementation existed. So `image_triage.py` splits:

- **Hard (excluded):** an image-axis doc entry (ACCEPTED_DIFFS et al. whose
  scope covers the comparison) or the GLOBAL `ruffle-tests/ignored_tests.txt`.
- **Soft (kept, flagged `[trace-ign]`):** suite-local ignore lists and
  trace-axis doc entries.

When a session dispositions a pixel failure permanently, write the doc entry
with an explicit `<!-- image-axis: ... -->` scope marker so the board can
enforce it per comparison and per frame.

## 4. Regression accounting

After merging a new `images=true` run:

```bash
python3 scripts/image_status_diff.py <prev-results-merge-sha> master
```

- READ THE PROVENANCE BANNER first. The stems only change when an images run
  merges; exit 2 means both sides are the same run and the diff is vacuous.
  Each side names the run's `git_sha`/`run_url` — verdicts describe the RUN,
  not the ref you passed.
- **pass→fail on the intersection = regression**, same bar as the trace side.
- **BAND MOVES are the graphics-only extra**: fail→fail is the common case, so
  a fix or regression usually shows as a band move, not a status move. A
  worsening band on a test an agent touched needs an explanation in the
  closeout even though no status flipped.
- The expected-flip ledgers from wave 2 give per-patch attribution, exactly
  like the trace sessions' ledgers.
- An `images=true` closeout run also refreshes the baseline doc:
  `python3 scripts/image_baseline_report.py --stem=graphics`.

## 5. Worktree recipe (w1a, verbatim rules)

A fresh `git worktree` has no test data (all suites gitignored except
`regression`) and no `SWFRecomp/build`. **Do not run `download_tests.sh` in a
worktree, and do not point `--tests-dir` at the main tree in a fan-out**:
`verify_output.py`'s `recompile_swf()` rmtrees and regenerates
`Recompiled*` caches *inside the shared test directory* with an mtime-reuse
heuristic — an agent carrying a `SWFRecomp/` change poisons the cache for
every other agent (silent false results), and two agents on the same test can
rmtree each other mid-build. Instead:

```bash
MAIN=/home/robert/CC/SWFRecomp-CC
WT=$(git rev-parse --show-toplevel)
mkdir -p "$WT/ruffle-tests/tests/swfs/visual/filters"
cp -r "$MAIN/ruffle-tests/tests/swfs/visual/filters/blur_quality" \
      "$WT/ruffle-tests/tests/swfs/visual/filters/"
python3 "$WT/ruffle-tests/verify_output.py" \
    --tests-dir="$WT/ruffle-tests/tests/swfs/visual" \
    --test=filters/blur_quality --mode=graphics --images --diff
```

Copy whole test directories (~100 KB each; the entire graded corpus is
~212 MB), keep them at the canonical in-worktree suite path (an out-of-corpus
path mislabels `suite_tag()`), and copy `SWFRecomp/build` from the main tree
ONLY for runtime-only patches — a `SWFRecomp/` change needs a cmake rebuild in
the worktree AND `--recompile`. In a worktree, `DAWN_INSTALL` mis-resolves;
`render_canary.py` auto-falls back to `~/CC/dawn-install`, raw verify runs
need it exported. Main-tree `--tests-dir` is acceptable for exactly one case:
a single agent working alone whose diff does not touch `SWFRecomp/`.

## 6. Canary rules

- **Tool:** `ruffle-tests/render_canary.py capture --label X` / `compare A B`,
  standing set `ruffle-tests/render_canary_tests.txt` (20 tests / 37
  comparisons; tier 1 = CI-passing, tier 2 = A/B-only; `regression/` 3×, per
  the standing rule that every canary includes that suite). Warm ~3 s/test at
  `-P 2`; a full double-leg check is ~10 min cold, ~2 min warm.
- **Bar: md5 equality.** Local Dawn is byte-deterministic (validated cold/warm,
  sequential and `-P 2`). Channel stats appear only for DIFFERS rows, computed
  by `verify_output.compare_images` so they are definitionally CI's numbers.
  A DIFFERS with `diff_channels 0` is a PNG re-encode, not a pixel change.
- **Never grade a local render against an expected PNG** — that is CI's job
  (lavapipe ≠ local Dawn; `bitmapdata_copypixels` shows ~25k phantom outliers
  locally while passing CI).
- Trace diffs ride along in every capture, so the render canary IS a trace
  canary for its test set; wave-2 agents still run the trace-side stash-diff
  sweep on any test their patch's mechanism touches beyond the canary set.
- The 11 false-positive/false-negative modes are in the `render_canary.py`
  module docstring (verbatim from w1c §6) — headline: **a `SWFRecomp/` change
  with a stale recompiler binary/cache reports IDENTICAL everywhere** (false
  negative). Read them before believing any surprising result.

## 7. Provenance rules (goldens)

Abridged from w1a (full text: w1a §"Playbook paragraphs"):

- Goldens reach dev machines and CI shards identically: `download_tests.sh`
  mirrors `<cmp>.expected.png` into the gitignored test dir. They are in NO
  ref of this repo; the only tracked goldens are the two hand-made
  `regression` ones. Never add `*.png` to `install_test_dir()`'s exclusions.
- The `~/CC/ruffle` fallback serves only the avm1 suite and does not exist on
  CI. Guard: `build_image_report.py --audit` runs on every `images=true`
  dispatch; zero comparisons currently resolve through the fallback. If it
  warns, fix the mirror — never hand-add a golden.
- **A `regression` test may carry a golden only from an oracle outside
  SWFRecomp** (Ruffle export, real Flash capture). Never capture one from our
  own renderer; with no oracle, ship without and let it record
  `skip/no_expected_image`.
- Nothing is pinned: goldens track upstream master at fetch time, and the
  Pages dashboard fetches them a second time at deploy. A pixel baseline is
  reproducible only as commit + date; a dashboard thumbnail disagreeing with
  its numbers is usually the double fetch.
- A `single_test` CI dispatch produces no graded pixel number (no `--images`
  on that job); use the sharded workflow with `images=true`.

## 8. Session-9 state of the board (2026-08-01)

Baseline going in: 159/566 unique comparisons pass (run `30680942974` at
`375373786`). **Session 9 closeout (run `30701749687` at `feb8882b0`):
172/566 (30.4%), +13, zero regressions on either axis** — the +11 focus-rect
ledger landed in full plus two unpredicted riders (`bitmapdata_draw_stage`,
`displayobject_set_matrix_nested`) and 17 band improvements.
Cluster totals at session start (comparisons / tests / near-passes):
same_geometry_wrong_fill 79/54/2 · hairline_edge_drift 70/43/35 ·
blank_render 67/62/0 · missing_element 32/21/1 · diffuse_mixed 30/28/2 ·
content_displaced 30/24/1 · extra_element 29/24/1 · unrelated_content 19/9 ·
halo_penumbra 16/15 · row_banded 13/13 · rest ≤6 each.

- **Taken by session 9's rider (DONE, +13 measured):** the focus-highlight
  slice of same_geometry_wrong_fill (`avm2/focusrect` ×6,
  `focus_highlight_avm1_button` ×4, `focus_highlight_move` ×1, + 2 riders) —
  three bugs, runtime-only (w2-4 report).
- **Named leads left on the board:** same_geometry_wrong_fill's blend-mode
  slice (19+4) and Shumway-acid slice (19); missing_element's text slice (18);
  extra_element's masks (9) + filters (7); `focus_highlight_avm2_button_bounds`
  blocked on AVM2 SimpleButton state-children never entering `render_list`
  (likely shared with `cache_as_bitmap/avm2_button*`, `avm2_button_scroll_rect`);
  frame-phase suspects `from_gnash .../simple_loop_test` (timeline phase bug,
  5 comparisons) and `visual/edittext/edittext_border_transform`.
- `hairline_edge_drift` is presumed lavapipe-AA until `triage_image_tests.py`
  says otherwise for a specific test; `blank_render` is dominated by
  unimplemented backends (Stage3D 26, video 9) — arc-sized, not sweep-sized.
