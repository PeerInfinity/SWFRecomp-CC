# w2-1 — `scripts/image_status_diff.py`: the graphics regression-accounting instrument

Session 9 (graphics setup), wave-2 agent 1. Implements §1 and §5.1 of
`w1b-pixel-triage-tooling.md`. Work done in an isolated worktree; **no commits**.

**Patch:**
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/cb374bf0-0d85-4523-9681-fcf8428c75c3/scratchpad/patches/w2-1-image-status-diff.patch`
(533 lines; new `scripts/image_status_diff.py` mode 100755 + a 25-line addition
to `scripts/build_image_report.py`). No workflow change — see §4.

---

## 1. What was built

### `scripts/image_status_diff.py` (new, ~400 lines, stdlib-only)

The pixel-side analog of `scripts/corpus_status_diff.py`, and deliberately
styled after it: same argument shape, same intersection-only discipline, same
"print the whole histogram, not just the transitions" rule, same exit-code
convention. `git()`, `result_paths()`, `load()`, `suite_of()`, the `NESTED`
exclusion, the `metadata.incomplete` banner and the `WORKTREE` new-side
convention are lifted from it.

Key is **`(suite, test, comparison)`** — 566 keys against 379 tests. A
test-level diff would hide exactly the moves the tool exists to show
(`avm2/focusrect` alone carries 12 comparisons, six failing and six passing).
`from_shumway/avm1` is excluded as a nested duplicate, so the denominator is 566
not 578 — the pixel-side version of the 4414-vs-4463 trace denominator.

Sections printed, in order:

| section | notes |
|---|---|
| `PROVENANCE` | per side: ref, resolved SHA, `metadata.git_sha`, timestamp, run id + URL; `!! STALE SIDE` and `!! MIXED PROVENANCE` warnings; hard stop on same-run |
| `!! INCOMPLETE RUN` | honours `metadata.incomplete` exactly as the trace tool does |
| `STATUS HISTOGRAM` | pass / fail / skip, full histogram |
| `BAND HISTOGRAM` | failures binned by `build_image_report.near_miss_band` — **imported, not re-derived**, so there is one definition of the bins. Bins on `excess_outliers`, never raw `outliers`. `no_render` flagged on a rise |
| `FAIL-REASON HISTOGRAM` | `pixel_mismatch` / `size_mismatch` / `no_render`; `no_render` flagged on a rise |
| `SKIP-REASON HISTOGRAM` | flags a rise in `test_segfault` / `test_timeout` / `test_runtime_error` / `test_compile_fail` / `test_recomp_fail` / `test_not_run` — a crash the pixel verdict *cannot* see, because the test produced no render so nothing fails, it just vanishes into `skip`. The trace-side `transition-diff-hides-new-crashes` lesson restated for pixels |
| `PER-SUITE PASSES` | `--per-suite`, only suites that moved |
| `GAINS` / `REGRESSIONS` | `-> pass` and `pass -> not pass`. Regressions printed in full, never truncated; drive exit 1 |
| `BAND MOVES` | the common case: failing on both sides, band and/or excess moved. Split improved / worsened / band-only, sorted by `abs` relative change, `--band-floor` (default 5%) suppresses same-band noise |
| `STATUS/REASON CHANGES` | fail↔skip and reason-string changes |
| `NEW` / `GONE` | comparisons absent from one side (a newly downloaded upstream test, or a deleted one) |
| `UNGRADED` | suites present at one side only — a `categories=`-restricted dispatch or a lost shard. Named explicitly, never counted as gains |

### CLI

```
scripts/image_status_diff.py <old_ref> <new_ref> [options]

  <old_ref>   git ref, or a directory containing a tree of per-suite JSONs
  <new_ref>   git ref, the literal WORKTREE, or a directory
  --stem STEM         image results stem (default: image_results_graphics)
  --per-suite         also print a per-suite pass table (only suites that moved)
  --band-floor FLOAT  suppress same-band excess moves below this relative
                      change (default 0.05)
  --features OLD.json,NEW.json   also diff mechanism clusters, from two
                      image_triage.py outputs
  --max-list N        cap on each printed list (default 40)
```

Exit codes: **0** clean, **1** at least one `pass -> not pass`, **2** both sides
are the same image run (nothing was diffed).

Typical uses:

```bash
# right after merging ruffle-test-results from an images=true run
scripts/image_status_diff.py d211b6feb WORKTREE --per-suite

# against a downloaded CI artifact, no merge needed
scripts/image_status_diff.py d211b6feb /tmp/imgrun

# find the refs that straddle two images=true merges
git log --follow -- ruffle-tests/tests/swfs/visual/_results/image_results_graphics.json
```

### `scripts/build_image_report.py` — run provenance in `metadata`

New `run_provenance()` helper, spread into the `metadata` block of
`build_suite()`. Emits `run_id`, `run_url`, `run_attempt` when running under
Actions, `{}` when run locally (so local runs produce byte-identical metadata to
before apart from the timestamp). `image_status_diff.py` prints them, so a stale
side can now be *linked*, not just named by SHA.

---

## 2. The provenance trap, and how the tool refuses to fall into it

This is the part of the spec that must not be skipped, so it is stated here too.
The per-suite image JSONs **only change when an `images=true` run is merged**,
and `images=false` is the per-change default — so on master these files sit
unchanged across dozens of commits. `image_status_diff.py A B` for two ordinary
commits therefore compares a file to *itself*, and a naive tool would print a
clean zero-delta report that reads like "no regressions".

Three behaviours close it:

1. The `PROVENANCE` banner names, for each side, the ref asked for, the SHA it
   resolved to, and the `metadata.git_sha` the JSON was **actually** built at.
2. `!! STALE SIDE` when those differ, plus whether the run's code is an ancestor
   of the ref. Both variants occur in practice and mean different things, so the
   tool says which: *ancestor* is normal for a results-merge commit; *not an
   ancestor* is normal for a raw `ruffle-test-results` commit (that branch
   forks off itself, not off master) and is a real problem otherwise.
3. Both sides resolving to the same `git_sha` → hard stop, exit 2, with the
   `git log --follow` command that finds usable refs. Demonstrated in §3.3.

`!! MIXED PROVENANCE` covers the fourth case the spec did not name: a side whose
suites came from *different* runs, which is what a partial re-merge looks like.

---

## 3. Validation — real output

The two published image runs found via
`git log --follow -- ruffle-tests/tests/swfs/visual/_results/image_results_graphics.json`:

| commit | run | `metadata.git_sha` | timestamp |
|---|---|---|---|
| `d211b6feb` | 30604886586 | `c146dc66e` | 2026-07-31T05:17:48 |
| `ec5078371` (in HEAD) | 30680942974 | `375373786` | 2026-08-01T03:29:53 |

### 3.1 The real diff — `d211b6feb -> WORKTREE`, exit 0

Matches the spec's prediction exactly: **passes 159 → 159**, **size_mismatch
12 → 0**, zero regressions.

```
=== intersection: 566 comparisons (d211b6feb -> WORKTREE, image_results_graphics) ===

PROVENANCE
  old  d211b6feb              json built at c146dc66e  2026-07-31T05:17:48   [11 suite(s)]
                              !! STALE SIDE: old ref d211b6feb resolves to d211b6feb but the JSON was built at c146dc66e
                                 run's code is NOT an ancestor of the ref (normal if the ref is a raw
                                 ruffle-test-results commit, which branches off the results branch; a real
                                 problem if you believed your change was in this run). Verdicts below describe the run at c146dc66e, NOT the code at d211b6feb.
  new  WORKTREE               json built at 375373786  2026-08-01T03:29:53   [11 suite(s)]
                              !! STALE SIDE: new ref WORKTREE resolves to f56b898d9 but the JSON was built at 375373786
                                 run's code IS an ancestor of the ref (normal for a results-merge commit). Verdicts below describe the run at 375373786, NOT the code at WORKTREE.

STATUS HISTOGRAM
  fail                                 403 ->   403 (+0)
  pass                                 159 ->   159 (+0)
  skip                                   4 ->     4 (+0)

BAND HISTOGRAM (failures, binned on excess_outliers)
  a_epsilon (<=100 channels over)       22 ->    22 (+0)
  b_tiny (<0.1% of channels)            22 ->    22 (+0)
  c_small (0.1-1%)                      75 ->    78 (+3)
  d_moderate (1-10%)                   117 ->   122 (+5)
  e_large (10-50%)                     104 ->   109 (+5)
  f_catastrophic (>=50%)                45 ->    45 (+0)
  no_render                              5 ->     5 (+0)
  size_mismatch                         12 ->     0 (-12)
  unknown                                1 ->     0 (-1)

FAIL-REASON HISTOGRAM
  no_render                              5 ->     5 (+0)
  pixel_mismatch                       386 ->   398 (+12)
  size_mismatch                         12 ->     0 (-12)

SKIP-REASON HISTOGRAM
  (a rise in test_segfault/test_timeout/test_recomp_fail is a crash the pixel verdict cannot see)
  no_expected_image                      3 ->     3 (+0)
  test_recomp_fail                       1 ->     1 (+0)

GAINS (-> pass): 0

REGRESSIONS (pass -> not pass): 0

BAND MOVES (failing on both sides): improved 1 / worsened 0 / band-only 13   [floor 5%]
  avm2/edittext_get_char_index_at_point [output]  size_mismatch -> d_moderate   excess — -> 59137  (n/a)
  avm2/pixelbender_effect_BlurredFocus [output]  size_mismatch -> c_small   excess — -> 4022  (n/a)
  avm2/pixelbender_effect_glassDisplace [output]  size_mismatch -> e_large   excess — -> 786543  (n/a)
  avm2/pixelbender_effect_twirl [output]  size_mismatch -> e_large   excess — -> 753197  (n/a)
  avm2/stage_scale_factor [output]  size_mismatch -> f_catastrophic   excess — -> 1912924  (n/a)
  from_shumway/avm1/text-bind [output]  unknown -> c_small   excess — -> 1834  (n/a)
  visual/edittext/edittext_background_basic_scale2 [output]  size_mismatch -> d_moderate   excess — -> 8652  (n/a)
  visual/edittext/edittext_border_basic_scale2 [output]  size_mismatch -> d_moderate   excess — -> 6858  (n/a)
  visual/edittext/edittext_underline_scale2 [output]  size_mismatch -> c_small   excess — -> 27648  (n/a)
  visual/filters/any_blur_scales_with_screen [output]  size_mismatch -> e_large   excess — -> 11776  (n/a)
  visual/filters/blur_scales_with_screen [output]  size_mismatch -> e_large   excess — -> 69231  (n/a)
  visual/filters/displacement_map_scales_with_screen [output]  size_mismatch -> d_moderate   excess — -> 99353  (n/a)
  visual/filters/drop_shadow_scales_with_screen [output]  size_mismatch -> d_moderate   excess — -> 44270  (n/a)
  avm2/away3d_advanced_shallow_water_demo [output]  f_catastrophic -> e_large   excess 1619125 -> 1333437  (-18%)

STATUS/REASON CHANGES (fail<->skip, reason strings): 12
  avm2/edittext_get_char_index_at_point [output]: reason size_mismatch -> pixel_mismatch
  … 11 more, all size_mismatch -> pixel_mismatch

NEW (absent from baseline): 0
GONE (present in baseline, absent now): 0
```

**Reading it.** The 12 `size_mismatch` comparisons now reach a real compare, and
that is the entire delta: they land in c_small (+3), d_moderate (+5) and
e_large (+5) — 3+5+5 = 13, the 12 plus `from_shumway/avm1/text-bind` moving out
of `unknown`. Zero passes moved in either direction. One genuine improvement
outside that group (`away3d_advanced_shallow_water_demo`, −18%). This is exactly
the accounting the graphics baseline needed and could not previously produce:
"size_mismatch 12 → 0" is *not* a wash — those 12 went from "we couldn't even
compare" to being measurable failures, which is progress no pass-rate number
shows.

### 3.2 Directory input

Byte-identical body when the old side is an extracted tree instead of a ref:

```
  old  …5c3/scratchpad/imgold json built at c146dc66e  2026-07-31T05:17:48   [11 suite(s)]
```
(no `STALE SIDE` on that side — a directory names no ref, so there is nothing to
be stale against.)

### 3.3 The self-compare guard — `HEAD~2 -> HEAD`, exit 2

Two ordinary master commits. The naive report would have been all zeroes:

```
!! BOTH SIDES ARE THE SAME IMAGE RUN — nothing to diff.
   The per-suite image JSONs only change when an `images=true` CI
   run is merged; `images=false` is the per-change default, so on
   master these files sit unchanged across dozens of commits.
   A zero-delta report here would NOT mean 'no regressions' — it
   would mean the two refs point at the same published run.
   Pick refs that straddle two images=true merges:
     git log --follow -- ruffle-tests/tests/swfs/visual/_results/image_results_graphics.json
```

Same for `ec5078371 -> WORKTREE` (the images commit vs the tree that contains it).

### 3.4 Synthetic-regression fixture — exit 1, every flag path

Real run 30604886586 mutated in a scratch copy: 2 passes → fail, 1 fail → skip
with `test_segfault`, 3 excess values ×20, 1 new comparison, one suite's
`git_sha` changed.

```
PROVENANCE
  new  …5c3/scratchpad/imgnew json built at c146dc66e  2026-07-31T05:17:48   [10 suite(s)]
                              json built at deadbeefc  2026-07-31T05:17:49  (run 31000000001)   [1 suite(s)]
                              https://github.com/PeerInfinity/SWFRecomp-CC/actions/runs/31000000001
                              !! MIXED PROVENANCE — this side's suites come from 2 different runs

SKIP-REASON HISTOGRAM
  test_segfault                          0 ->     1 (+1)   <-- FLAG: a rise here is a capture/crash regression

PER-SUITE PASSES (only suites that moved)
  visual                                32 ->    30 (-2)

REGRESSIONS (pass -> not pass): 2
  visual/bitmapdata_copypixels_with_alpha_oob [output]: pass -> fail (pixel_mismatch, excess 264000)
  visual/blend_modes/shader_without_shader [output]: pass -> fail (pixel_mismatch, excess 480)

BAND MOVES (failing on both sides): improved 0 / worsened 3 / band-only 0   [floor 5%]
  visual/blend_modes/add [output]  d_moderate -> e_large   excess 13405 -> 268100  (+1900%)
  visual/blend_modes/alpha_no_layer [output]  e_large -> f_catastrophic   excess 172259 -> 3445180  (+1900%)
  visual/blend_modes/darken [output]  d_moderate -> f_catastrophic   excess 42847 -> 856940  (+1900%)

STATUS/REASON CHANGES (fail<->skip, reason strings): 1
  visual/avm2_button_scroll_rect [output]: fail -> skip (pixel_mismatch -> test_segfault)

NEW (absent from baseline): 1
  visual/brand_new_test [output]  fail
```
exit code 1.

### 3.5 `--features`

Exercised against two hand-built `image_triage`-shaped files (accepts either a
bare list or `{"results": [...]}`), on the shared key set only:

```
CLUSTER HISTOGRAM (image_triage features, 3 shared comparisons)
  blank_render                     1 ->     1 (+0)
  hairline_edge_drift              0 ->     1 (+1)
  same_geometry_wrong_fill         2 ->     1 (-1)

CLUSTER MOVES: 1
  avm2/focusrect [output.01a]: same_geometry_wrong_fill -> hairline_edge_drift
```

### 3.6 `build_image_report.py` unchanged behaviour

```
$ GITHUB_RUN_ID=99 GITHUB_REPOSITORY=a/b python3 scripts/build_image_report.py \
      --stem=results_graphics --no-write-per-suite --suites-file=…
Restricted to 1 suite(s) written by this run.
regression: 2/5 image comparisons pass (0 fail, 3 skip, 0 no-render)
TOTAL: 2/5 pass, 0 fail, 3 skip, 0 no-render

$ run_provenance() under Actions env
{'run_id': '30680942974', 'run_url': 'https://github.com/PeerInfinity/SWFRecomp-CC/actions/runs/30680942974', 'run_attempt': '1'}
$ run_provenance() locally
{}
```

---

## 4. Deviations from the spec, and why

**No workflow edit — the spec's premise was slightly off.** w1b says `RUN_URL` is
already in the environment of the step that invokes `build_image_report.py`
(`.github/workflows/ruffle-tests.yml` ~L1131). It is not: `RUN_URL` is exported
by the *next* step ("Publish failing images to ruffle-image-results"); the
"Build per-suite image results" step's `env:` block contains only `MODE`. That
would have implied a workflow edit. It does not, because `GITHUB_RUN_ID`,
`GITHUB_RUN_ATTEMPT`, `GITHUB_REPOSITORY` and `GITHUB_SERVER_URL` are automatic
Actions variables present in **every** step. `run_provenance()` builds the URL
from those and falls back to an explicit `RUN_URL` if one is exported, so it
works from either step and needs no `.yml` change. One fewer file to keep in
sync, and it also works from the weekly canary and any future caller.

**`--stem` default is `image_results_graphics`, not `graphics`.** The spec's CLI
block says "image results stem (default: `image_results_graphics`)", which is the
full filename stem, and that is what is implemented — you pass exactly what
appears in `_results/<stem>.json`. Note the trace tool's `--stem results_graphics`
and this tool's `--stem image_results_graphics` are *not* the same string;
`build_image_report.py` derives one from the other.

**Exit 2, not exit 0, for the same-run stop.** The spec says "exit early"
without naming a code. 0 would be indistinguishable from a clean diff to a
script or a CI step, which is the exact failure mode the guard exists to
prevent. 1 is reserved for regressions. So: 2.

**`STALE SIDE` reports ancestry, not just mismatch.** Implementing the spec
literally makes *every* invocation print `!! STALE SIDE`, because the JSON is
always built at the code commit while the ref is always the results-merge commit
that carries it — the warning would be pure noise within one session. The
ancestry line (`IS an ancestor` / `is NOT an ancestor`) is what separates the
benign case from the real one, and it costs one `git merge-base --is-ancestor`.

**Added `!! MIXED PROVENANCE`.** Not in the spec. A side whose suites carry
different `git_sha`s is a partial merge or a `categories=`-restricted republish,
and it is undetectable once per-suite metadata is collapsed to one line.

**Bands are imported from `build_image_report`, not copied.** The spec asks
`image_triage.py` to do this; the same argument applies here and the import is
stdlib-safe (`build_image_report` imports `verify_output`, whose only non-stdlib
import — Pillow — is already optional and guarded). One definition of the bins.

**`--features` is implemented but untestable end-to-end**, since
`scripts/image_triage.py` (w1b §5.2) does not exist yet. It reads `cluster` off
either shape an implementer is likely to emit and is tolerant of the rest of the
row schema, so it should work unmodified against the triage tool; if that tool
names the field differently, this is a one-line change.

---

## 5. Follow-ups for the next graphics session

- Once `scripts/image_triage.py` lands, confirm `--features` against its real
  output and add the cluster histogram to the standard post-CI read.
- `from_shumway/avm1/text-bind` was `unknown`-banded on the older run (a row with
  no `excess_outliers`). Rows written before 2026-07-30 lack machine-readable
  stats; if a much older baseline is ever diffed, expect a larger `unknown`
  bucket and read it as "no data", not as a band.
- The natural home for this in the pipeline is right after the
  `ruffle-test-results` merge of an `images=true` run, alongside
  `corpus_status_diff.py`, in `.claude/pipeline-handoff.md`. Not edited here —
  that file is outside this agent's slot.
