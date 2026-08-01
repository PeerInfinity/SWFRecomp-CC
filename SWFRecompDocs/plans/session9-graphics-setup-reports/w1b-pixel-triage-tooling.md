# w1b — Pixel-triage instruments: spec + working prototype

Session 9 (graphics setup), wave-1 agent B. Read-only on the repo apart from this
file; all code and data live in the session scratchpad (paths below).

**What this delivers:** the graphics analog of the trace corpus's two standing
instruments — `scripts/corpus_status_diff.py` (session regression accounting) and
the near-pass ranking. Both are specified here; the ranking half is *prototyped
and run over the full failing set*, so the numbers below are measurements, not
estimates.

Data: run
[30680942974](https://github.com/PeerInfinity/SWFRecomp-CC/actions/runs/30680942974)
at `375373786` — 159/567 comparisons pass, 403 fail (excluding the
`from_shumway/avm1` nested duplicate), 4 skip.

Prototype code and outputs:

| path (under the session scratchpad) | what |
|---|---|
| `image_triage_proto.py` | feature extraction + mechanism classifier |
| `image_rank_proto.py` | banding, families, dispositioned cross-check, ranking |
| `features.json` | 403 rows, every feature, one per failing comparison |
| `ranked.json` | the same rows + band/family/fanout/score/dispositioned |
| `rank_report.txt` | the full printed output the tables below are cut from |
| `montage1.png`, `montage_focus.png` | the visual spot-checks cited below |

Scratchpad root:
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/cb374bf0-0d85-4523-9681-fcf8428c75c3/scratchpad/`

---

## 1. SPEC — `scripts/image_status_diff.py`

The instrument every future graphics session runs after CI. Deliberately styled
after `scripts/corpus_status_diff.py`: same argument shape, same
intersection-only discipline, same "print the whole histogram, not just the
transitions" rule, same exit code.

### CLI

```
scripts/image_status_diff.py <old_ref> <new_ref> [options]

  <old_ref>    git ref, or a directory containing a tree of per-suite JSONs
  <new_ref>    git ref, the literal WORKTREE, or a directory
  --stem       image results stem (default: image_results_graphics)
  --per-suite  also print a per-suite pass table (only suites that moved)
  --band-floor FLOAT   suppress band/excess moves smaller than this relative
                       change (default 0.05) — lavapipe is deterministic, so
                       any move is real, but tiny ones are noise to a reader
  --features OLD.json,NEW.json   optional: also diff mechanism clusters, using
                       two image_triage.py outputs (see §5)
```

`<new_ref>` = `WORKTREE` reads the working tree, which is the normal case right
after merging `ruffle-test-results`. Directory inputs exist because the image
JSONs are also obtainable from a downloaded CI artifact without a merge.

### Inputs

Every `ruffle-tests/tests/swfs/*/_results/<stem>.json` at each side, read with
`git ls-tree -r --name-only <ref>` + `git show <ref>:<path>` (lifted verbatim
from `corpus_status_diff.py`). Skip `from_shumway/avm1` — it is physically
inside `from_shumway`, whose own run already graded it, and summing both
double-counts (the pixel-side version of the 4414-vs-4463 trace denominator;
`build_image_report.NESTED_SUITES` already names it).

**The key is `(suite, test, comparison)`, not `test`.** 567 keys, not 379 —
`avm2/focusrect` alone carries 12, six failing and six passing. A
test-level diff would hide exactly the moves this tool exists to show.

### The provenance trap — this is the part that must not be skipped

The per-suite image JSONs **only change when an `images=true` run is merged**.
`images=false` is the per-change default, so on master these files sit unchanged
across dozens of commits. Consequence: `image_status_diff.py A B` where A and B
are ordinary commits can silently compare a file to *itself*, or compare a
result produced long before B's code to B.

The JSONs do carry what is needed to detect this. `metadata` is:

```json
{"timestamp": "2026-08-01T03:29:53Z", "suite": "avm1",
 "stem": "results_graphics", "git_sha": "375373786d2d…",
 "source": "results_graphics.json", "incomplete": false}
```

Required behaviour:

1. Print a **PROVENANCE** banner naming, for each side, the ref asked for, the
   `metadata.git_sha` actually found, and the `timestamp`.
2. If `metadata.git_sha` does not start with (or contain) the resolved
   `<ref>` SHA, print `!! STALE SIDE` loudly and say the verdicts describe the
   run at `git_sha`, not the code at `<ref>`. This is the images analog of the
   `ci-baseline-commit-must-postdate-its-run` lesson.
3. If both sides resolve to the *same* `git_sha`, exit early with
   `!! BOTH SIDES ARE THE SAME IMAGE RUN — nothing to diff` rather than printing
   a zero-delta report that reads like "no regressions".
4. Honour `metadata.incomplete` exactly as `corpus_status_diff.py` does.

**Gap to close in the same PR:** `metadata` has no run id or URL, so a stale side
can be named but not linked. `RUN_URL` is already in the workflow environment at
the step that invokes `build_image_report.py`
(`.github/workflows/ruffle-tests.yml` ~L1131) but currently only reaches
`index.md`. Add `run_url`, `run_id`, `run_attempt` to the `metadata` block in
`build_image_report.build_suite()` — three lines, and every future diff can cite
its source run.

### Output format

```
=== intersection: 566 comparisons (c146dc66e -> WORKTREE, image_results_graphics) ===

PROVENANCE
  old  c146dc66e   json built at c146dc66e  2026-07-31T…  (run 30604886586)
  new  WORKTREE    json built at 375373786  2026-08-01T…  (run 30680942974)

STATUS HISTOGRAM
  pass               159 ->   159 (+0)
  fail               403 ->   403 (+0)
  skip                 4 ->     4 (+0)

BAND HISTOGRAM (failures, binned on excess_outliers)
  a_epsilon           22 ->    22 (+0)
  …
  size_mismatch       12 ->     0 (-12)   <-- 12 comparisons now reach a real compare
  no_render            5 ->     5 (+0)    <-- FLAG: any rise here is a capture failure

FAIL-REASON HISTOGRAM     pixel_mismatch / size_mismatch / no_render / …
SKIP-REASON HISTOGRAM     no_expected_image / test_recomp_fail / test_segfault / …
                          <-- FLAG: any rise in test_segfault/test_timeout/
                              test_recomp_fail is a crash the pixel verdict
                              cannot see (the trace-side `transition-diff-hides-
                              new-crashes` lesson, restated for pixels)

GAINS (fail -> pass): N          [list]
REGRESSIONS (pass -> fail): N    [list]   <-- exit 1

BAND MOVES (failing on both sides): improved N / worsened N
  suite/test [cmp]  c_small -> a_epsilon   excess 4761 -> 88  (-98%)
  … top 40 by |relative change in excess_outliers|, then "… and K more"

SKIP/REASON CHANGES: fail -> skip, skip -> fail, reason string changes

NEW (absent from baseline): N        — a newly-downloaded upstream test
GONE (present in baseline, absent now): N
UNGRADED — suites present at one side only (a categories=avm1 dispatch, or a
  lost shard). NOT regressions; named explicitly.
```

Two rules carried over from the trace tool and one new one:

- **Everything is on `set(old) & set(new)`.** A `categories=`-restricted or
  shard-dropped run leaves suites absent, not failing; they must never read as
  gains.
- **Print the whole histogram, not only the transitions.** On pixels this
  matters more than on trace: a comparison that goes from `c_small` to
  `f_catastrophic` crosses no pass/fail line at all, and a transitions-only
  report would call that "zero regressions". `BAND MOVES` is the pixel analog of
  `OTHER STATUS MOVES`.
- **`excess_outliers`, never raw `outliers`.** Every tolerance in the corpus was
  recorded against real Flash output by upstream and they differ wildly; only
  the excess past a test's own budget is comparable across tests. Same reason
  `build_image_report.near_miss_band` bins on it.

Exit code: 1 if any pass→fail, else 0.

---

## 2. MECHANISM CLUSTERING — prototyped and run

`image_triage_proto.py` joins each failing comparison to its rendered
`<cmp>.actual.png` (from the extracted `ruffle-image-results` payload) and its
in-repo `<cmp>.expected.png`, and classifies it by *what the difference looks
like*, independent of the test's name.

**It does not use the published `<cmp>.difference.png`.** That file is
alpha-mangled and RGB-brightened ×4 (`verify_output.py` L459-471) — a viewer
aid, not data. The difference is recomputed from actual+expected.

### Features (all in `features.json`, per comparison)

| feature | what it separates |
|---|---|
| `ink_frac_actual/expected` | pixels ≥24 from each image's *own* modal colour — "did we draw anything" |
| `ink_iou`, `missing_ink_frac`, `extra_ink_frac` | is the geometry the same, absent, extra, or elsewhere |
| `erode_survival` | fraction of the diff mask surviving a 3×3 erosion — 1px hairline ≈ 0, a displaced or repainted region ≫ 0 |
| `edge_containment` (r=2) / `halo_containment` (r=8) | diff *on* edges vs *ringing* edges — the latter is a blur/glow/shadow radius error |
| `signed_mean` / `signed_std` per channel | a uniform tint has near-zero variance |
| `shift_dy/dx`, `shift_gain` | ±8px translation probe on a 2× downsampled luminance plane |
| `n_bands`, `median_band`, `diff_row_frac` | glyph-height horizontal banding |
| `bbox_frac`, `bbox_density` | compact blob vs whole-frame |

Runtime: **24 s for all 403** at `--jobs 4` (numpy + Pillow, no rendering).

### Measured clusters

| cluster | cmps | tests | near-pass (band a/b) | example tests |
|---|---:|---:|---:|---|
| `same_geometry_wrong_fill` | 79 | 54 | 2 | `visual/blend_modes/*`, `avm2/focusrect`, `from_shumway/acid/acid`, `visual/filters/color_matrix` |
| `hairline_edge_drift` | 70 | 43 | 35 | `from_shumway/timeline/timeline_loop`, `visual/edittext/edittext_caret_empty`, `avm1/edittext_stylesheet`, `visual/simple_shapes/gradients/focal_radial` |
| `blank_render` | 67 | 62 | 0 | `avm2/stage3d_*` (26), `visual/video/*`, `from_shumway/gradientTransform`, `fonts/device_font_kerning` |
| `missing_element` | 32 | 21 | 1 | `visual/edittext/edittext_selection_leading`, `from_shumway/stylesheet`, `fonts/embed_matching/fallback_preferences`, `visual/filters/blur_pass_scaling` |
| `diffuse_mixed` (fallback) | 30 | 28 | 2 | `visual/filters/drop_shadow_angles`, `from_shumway/acid/acid-stroke-0`, `avm1/define_font_glyph_table_order` |
| `content_displaced` | 30 | 24 | 1 | `avm2/stage_scale_factor`, `visual/simple_shapes/text_field_mask`, `visual/opaque_background`, `from_shumway/avm1/text-bind` |
| `extra_element` | 29 | 24 | 1 | `visual/simple_shapes/masks`, `visual/simple_shapes/scroll_rect_mask`, `visual/filters/blur_quality`, `from_shumway/MaskTest-2` |
| `unrelated_content` | 19 | 9 | 0 | `avm2/away3d_advanced_shallow_water_demo`, `avm2/stage3d_texture`, `avm2/displayobject_scrollrect` |
| `halo_penumbra` | 16 | 15 | 0 | `visual/filters/bevel*`, `avm2/pixelbender_effect_glassDisplace`, `from_shumway/acid/acid-blend-2` |
| `row_banded` | 13 | 13 | 2 | `from_shumway/acid/acid-text-4`, `fonts/embed_matching/match_style`, `avm2/bitmap_pixelsnapping` |
| `global_color_shift` | 6 | 4 | 0 | `avm2/displayobject_colortransform_nested`, `visual/cache_as_bitmap/color_transform` |
| `no_render` | 5 | 3 | — | `from_shumway/acid/{acid,acid-large,acid-video}` |
| `offset_translation` | 4 | 4 | 0 | `text/br_at_start`, `visual/cache_as_bitmap/text`, `from_shumway/acid/acid-text-x` |
| `whole_frame_wrong` | 2 | 2 | 0 | `avm2/bitmapdata_applyfilter_blur`, `visual/gradient_nonsequential_ratios` |
| `localized_region` | 1 | 1 | 0 | `from_shumway/captions` |
| **total** | **403** | | **44** | |

### Cluster × band (the useful cross-tab)

```
cluster                     a_eps b_tiny c_small d_mod e_large f_cat
same_geometry_wrong_fill        0     2     29     32     16      0
hairline_edge_drift            22    13     26      9      0      0
blank_render                    0     0      1     10     29     27
missing_element                 0     1      4      7     18      2
diffuse_mixed                   0     2      6     19      3      0
content_displaced               0     1      2     19      6      2
extra_element                   0     1      3     10     15      0
unrelated_content               0     0      0      1      9      9
halo_penumbra                   0     0      0      7      8      1
row_banded                      0     2      5      6      0      0
global_color_shift              0     0      0      0      2      4
offset_translation              0     0      1      2      1      0
```

**This is the payoff, and it settles a question the baseline doc left open.**
`hairline_edge_drift` owns 35 of the 44 near-pass failures and *zero* of the
moderate-or-worse ones; `blank_render` owns 56 of the 72 catastrophic/large ones
and zero near-passes. Mechanism and magnitude are close to collinear at the
extremes, which means the epsilon band really is (mostly) the lavapipe AA gap
the baseline predicted — and it means near-pass ranking *alone* would send a fix
session straight at the least fixable cluster in the corpus. The clustering key
is what makes the middle of the board readable.

### Why the clusters beat name-keyword families

Name families answer "which subsystem owns this test", which is a good question
once you already know what is wrong. Two concrete cases where the name is
actively misleading:

- **`focus_highlight` splits into two mechanisms.** `focus_highlight_render`
  (6 cmps) is `hairline_edge_drift` with signed means of 0.1/6/2 — AA noise.
  `focusrect` + `focus_highlight_avm1_button` + `focus_highlight_move`
  (10 cmps) are `same_geometry_wrong_fill` with an *exactly constant*
  `[0, ±153, ∓204]` signature. One family, two entirely different work items.
- **`filters` splits three ways**: `halo_penumbra` (bevel/glow radius),
  `same_geometry_wrong_fill` (`color_matrix`), and `extra_element`
  (`blur_quality`, `blur_fractional` — we draw blur where Flash draws none).

### Validated visually, not just numerically

Spot-checks (`montage1.png`, `montage_focus.png`) confirmed the labels on four
sampled cases: `blend_modes/add` is a tile grid with identical geometry and
several wrong tile colours (`same_geometry_wrong_fill` ✓); `filters/bevel` shows
our bevel missing its blue/red rim, the diff a ring around every edge
(`halo_penumbra` ✓); `simple_loop_test frame3` is a blank frame against
three coloured squares (`blank_render` ✓) and `frame4` the exact inverse
(`extra_element` ✓).

### Side finding — a dispositioned test whose disposition covers only 2 of its 7 frames

`from_gnash/misc-ming.all/loop/simple_loop_test` is accepted in
`from_gnash/_investigation/ACCEPTED_DIFFS.md` as "hairline-stroke pixel-snapping,
121–724 image px/frame". That holds for `frame1` (242) and `frame2` (483). It
does not hold for frames 3–7: excess 7442–21600, and the mechanisms are
`blank_render` / `extra_element` / `missing_element` — we render an empty frame
where Flash shows three squares, and a red square where Flash shows none. That
is a **timeline loop phase off-by-one**, not antialiasing. The accepted-diff
entry should be narrowed to frames 1–2; the rest is live work. (The classifier
flags this shape automatically — see `FRAME-PHASE SUSPECTS` in `rank_report.txt`;
the only other hit is `visual/edittext/edittext_border_transform`.)

---

## 3. RANKING — the graphics near-pass-list analog

`image_rank_proto.py`. The composite is deliberately explicit rather than a
tuned black box, because every weight in it is a hypothesis a later session
should be able to move with evidence:

```
score(comparison) = CLUSTER_PRIOR[cluster]          # tractability of the mechanism
                  * log2(1 + fanout)                # fanout = comparisons sharing
                                                    #   (cluster, family)
                  * (0.40 + 0.60 * BAND_PROX[band]) # proximity to the budget
```

then rolled up **per (test, cluster)** — a fix lands on a test, not on a frame,
and without the roll-up `from_shumway/acid`'s 16 frames own the top of the board.
The group score adds `× (1 + 0.25·log2(cmps))` to credit the extra comparisons a
single fix would flip.

`BAND_PROX`: a_epsilon 1.00, b_tiny 0.85, c_small 0.60, d_moderate 0.35,
e_large 0.15, f_catastrophic 0.05.
`CLUSTER_PRIOR`: global_color_shift / offset_translation 1.00, alpha_only /
halo_penumbra 0.90, same_geometry_wrong_fill 0.80, missing/extra_element 0.60,
row_banded / localized 0.55, content_displaced 0.50, diffuse_mixed 0.40,
whole_frame_wrong 0.35, blank_render 0.30, hairline_edge_drift 0.25,
unrelated_content 0.15, no_render 0.

Hard exclusions before ranking: dispositioned (§3.2), Ruffle `known_failure`,
`no_render`, `size_mismatch`. That removes 39 comparisons, leaving 364 live
across 274 (test × cluster) rows.

### 3.1 Top 20

| # | score | cmps | fan(tests) | suite/test | cluster | band | excess |
|---:|---:|---:|---:|---|---|---|---:|
| 1 | 5.26 | 16 | 4 | `from_shumway/acid/acid` | same_geometry_wrong_fill | c_small | 4761 |
| 2 | 3.27 | 4 | 3 | `visual/focus_highlight/focus_highlight_avm1_button` | same_geometry_wrong_fill | d_moderate | 168 |
| 3 | 2.88 | 6 | 3 | `avm2/focusrect` | same_geometry_wrong_fill | d_moderate | 408 |
| 4 | 2.63 | 1 | 4 | `from_shumway/acid/acid-color-0` | same_geometry_wrong_fill | c_small | 37867 |
| 5 | 2.37 | 12 | 7 | `visual/edittext/edittext_selection_leading` | missing_element | e_large | 18179 |
| 6 | 2.18 | 1 | 7 | `visual/filters/color_matrix` | same_geometry_wrong_fill | b_tiny | 339 |
| 7 | 2.11 | 1 | 19 | `visual/blend_modes/add` | same_geometry_wrong_fill | d_moderate | 13405 |
| 8 | 2.11 | 1 | 19 | `from_shumway/acid/acid-blend-2` | same_geometry_wrong_fill | d_moderate | 14912 |
| 9 | 2.11 | 1 | 19 | `avm2/blend_transform` | same_geometry_wrong_fill | d_moderate | 15000 |
| 10 | 2.11 | 1 | 19 | `visual/blend_modes/lighten` | same_geometry_wrong_fill | d_moderate | 18823 |
| 11 | 2.11 | 1 | 4 | `from_shumway/acid/acid-child` | same_geometry_wrong_fill | d_moderate | 20544 |
| 12 | 2.11 | 1 | 19 | `visual/blend_modes/hardlight` | same_geometry_wrong_fill | d_moderate | 30408 |
| 13 | 2.11 | 1 | 19 | `visual/blend_modes/overlay_onto_stage` | same_geometry_wrong_fill | d_moderate | 41293 |
| 14 | 2.11 | 1 | 19 | `visual/blend_modes/darken` | same_geometry_wrong_fill | d_moderate | 42847 |
| 15 | 2.11 | 1 | 4 | `from_shumway/acid/acid-bitmapData-copyPixels` | same_geometry_wrong_fill | d_moderate | 53760 |
| 16 | 2.11 | 1 | 19 | `visual/blend_modes/subtract` | same_geometry_wrong_fill | d_moderate | 65601 |
| 17 | 2.11 | 1 | 19 | `visual/blend_modes/multiply` | same_geometry_wrong_fill | d_moderate | 66608 |
| 18 | 2.11 | 1 | 19 | `from_shumway/acid/acid-blend` | same_geometry_wrong_fill | d_moderate | 77416 |
| 19 | 2.11 | 1 | 19 | `visual/blend_modes/overlay` | same_geometry_wrong_fill | d_moderate | 84068 |
| 20 | 1.98 | 12 | 5 | `visual/edittext/edittext_caret_empty` | hairline_edge_drift | a_epsilon | 21 |

Top groups by summed score (the arc view, live comparisons only):

| cmps | near-pass | cluster × family |
|---:|---:|---|
| 19 | 17 | `same_geometry_wrong_fill` × Shumway acid |
| 19 | 0 | `same_geometry_wrong_fill` × **Blend modes** |
| 11 | 1 | `same_geometry_wrong_fill` × Focus highlight |
| 26 | 0 | `blank_render` × Stage3D (backend, flagged) |
| 17 | 15 | `hairline_edge_drift` × Text/EditText (AA — deprioritised by prior) |
| 15 | 0 | `missing_element` × Text/EditText |
| 11 | 1 | `content_displaced` × Text/EditText |

### 3.2 Dispositioned targets flagged (11 comparisons)

Checked against `avm1/_investigation/ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `from_gnash/_investigation/ACCEPTED_DIFFS.md`
and `ruffle-tests/ignored_tests.txt`:

| comparison | cluster | disposition |
|---|---|---|
| `avm1/netstream_play_flv [output]` | hairline_edge_drift | ACCEPTED §9 H.263 decoder parity |
| `avm1/netstream_play_flv_screen [output]` | blank_render | RUFFLE_VS_FLASH + ignored_tests |
| `avm2/netstream_play_flv [output]` | blank_render | matched via ignored_tests **by basename — verify** |
| `from_gnash/…/loop/simple_loop_test [frame1..7]` | 5 different clusters | from_gnash ACCEPTED — **valid for frames 1–2 only**, see §2 |
| `from_shumway/avm1/text-bind [output]` | content_displaced | ACCEPTED §8 device-font metrics |

Two caveats the wave-2 tool must carry: `ignored_tests.txt` is applied by
`filter_results.py` per suite (global list + a per-suite list), so a basename
match across suites is a *heuristic* — print it as "matched by basename" rather
than as a fact. And `avm1/display_object_properties` and
`avm1/bitmap_data_thorough/pixelDissolve` are dispositioned but do not appear in
this run's failing set: `display_object_properties` now **passes** its image
comparison, and `bitmap_data_thorough/pixelDissolve` has no `[image_comparisons]`
block at all. Both ACCEPTED_DIFFS entries are stale on the image axis — worth a
one-line note there, and a reason the tool should report "dispositioned but
currently passing" rather than silently dropping the row.

Ruffle `known_failure` (23 comparisons, excluded from ranking) are listed in
`rank_report.txt`. Reminder from the trace side: on a `known_failure` test
Ruffle is not the oracle, and matching its expected PNG is not a goal.

### 3.3 What the ranking says, in one line

The head of the board is **not** the near-pass band. It is
`same_geometry_wrong_fill` — geometry correct, pixel values wrong — which is
79 comparisons across 54 tests, sits mostly in c_small/d_moderate, and
decomposes into three coherent arcs: blend-mode math (19), Shumway acid
composites (19), and focus highlight (11).

---

## 4. RIDER CANDIDATE — focus-rect highlight state (10–11 comparisons)

Named with evidence, and with its risk stated. This is a rider, not an arc.

**Mechanism.** Across `avm2/focusrect` (6 cmps), `visual/focus_highlight/
focus_highlight_avm1_button` (3), and `focus_highlight_move` (1), the *only*
differing pixels are a 3px-thick rectangular ring, geometry pixel-identical
(`ink_iou = 1.00`), and the signed per-channel difference is an exact constant
`[0, −153, +204, 0]` — or its exact negation. Decoding the pixels directly:

```
avm2/focusrect [output.01a]     204 px differ, bbox (10,10)-(29,29)  = a 20x20 3px ring
   ours  #FF66CC (the content square, unhighlighted)
   exp   #FFFF00 (Flash's yellow focus rect)
focus_highlight_avm1_button [output.04]   444 px, bbox (30,30)-(69,69)
   ours  #FFFF00   exp  #FF66CC          <-- the exact inverse
```

The montage confirms it: Flash draws a yellow focus ring around a square; in
`output.01a`/`output.02`/`output.05` we draw none, and in `output.04` we draw one
where Flash has already cleared it. **We are not drawing the wrong colour — we
are highlighting at the wrong point in the focus sequence** (one step out of
phase, or on the wrong target). One behaviour, 10 comparisons, and every one is
in the 168–1056 excess range, so a correct fix flips them outright.
`visual/focus_highlight/focus_highlight_avm2_button_bounds` (`blank_render`,
excess 800 — we draw no highlight at all) is plausibly the same bug, making 11.

**The risk, stated up front.** In the immediate neighbourhood, 21 comparisons
already *pass*: `avm2/focusrect` 6 of 12, `focus_highlight_basic` 9 of 9,
`focus_highlight_move` 4 of 5, `focus_highlight_avm1_button` 2 of 6. A focus-state
change is aimed at those 21 green comparisons — the exact shape of the
`rider-already-passing-is-regression-risk` lesson. Whoever takes this must check
the passing siblings in the same CI run, not just the failing ones. And note
`focus_highlight_render` (6 cmps) is a *different* mechanism (hairline AA); it
will not move and should not be counted as this rider's yield.

**Not the rider, but the top arc for a real fix session:** blend-mode
compositing. 19 comparisons in `same_geometry_wrong_fill × Blend modes` plus 4
more in acid, covering add / multiply / screen / overlay / hardlight / darken /
lighten / subtract / difference / invert / alpha / erase / layer. Geometry is
right everywhere (`ink_iou` 0.95–1.00); the signed means are large and
mode-specific (screen `[−81,−69,−63]`, multiply `[+42,+40,+39]`, subtract
`[−8,−8,−1,−223]` — that last one is an *alpha*-channel error). Nearly every
mode being wrong in a different direction points at the compositing space
(straight vs premultiplied alpha, or blending against the wrong backdrop) rather
than at thirteen independent formula bugs. Bigger than one wave-2 slot; the
right first arc for a dedicated graphics fix session.

---

## 5. WAVE-2 SPEC — files to create

### 5.1 `scripts/image_status_diff.py` (new, ~250 lines)

Per §1. Standalone rather than a mode of `corpus_status_diff.py`: the key is a
triple not a test, the verdict vocabulary is different (bands, fail reasons,
skip reasons), and the provenance trap is unique to images. Copy verbatim from
`corpus_status_diff.py`: `git()`, `result_paths()`, `load()`, `suite_of()`, the
`NESTED` exclusion, the incomplete-metadata banner, the intersection discipline,
and the exit-code convention.

Also in the same change, three lines in `scripts/build_image_report.py`
`build_suite()`: add `run_url` / `run_id` / `run_attempt` (from env, already
present at that workflow step) to the emitted `metadata`.

### 5.2 `scripts/image_triage.py` (new, ~450 lines)

**Not** an extension of `build_image_report.py`, and the justification matters:
`build_image_report.py` runs *inside CI on every images run*, before the failing
PNGs are collected into one tree, and must stay dependency-light. `image_triage.py`
runs *after* a baseline lands, needs numpy + the `ruffle-image-results` checkout +
the in-repo expected PNGs, and runs once per baseline rather than once per run.
Different inputs, different cadence, different dependencies — separate files.

```
python3 scripts/image_triage.py
    --images-dir DIR          # checkout/extract of ruffle-image-results (its
                              #   images/<suite>/<test>/<cmp>.actual.png tree)
    [--stem graphics]         # which image_results_<stem>.json to read
    [--jobs 4]
    [--out FILE]              # default: SWFRecompDocs/plans/<session>/image_triage.json
    [--markdown FILE]         # cluster tables + top-N, ready to paste
    [--top 25]
    [--cluster CLUSTER]       # print only one cluster's members
    [--test SUITE/TEST]       # explain one comparison: dump every feature
```

Output row schema (one per failing comparison):

```json
{"suite":"avm2","test":"focusrect","comparison":"output.01a",
 "trace_status":"pass","known_failure":false,"reason":"pixel_mismatch",
 "excess_outliers":408,"outliers":408,"max_outliers":0,"max_diff":204,
 "band":"d_moderate (1-10%)","family":"Focus highlight / focus rect",
 "cluster":"same_geometry_wrong_fill",
 "why":"ink IoU 1.00, 8.2% of pixels repainted",
 "dispositioned":null,"fanout":11,"fanout_tests":3,"score":2.88,
 "features":{ …every feature from §2… }}
```

Liftable **verbatim** from the prototypes:

| from `image_triage_proto.py` | |
|---|---|
| `modal`, `key_of`, `dilate` (separable), `erode`, `edges_of`, `best_shift`, `bands_of` | primitives |
| `features()` | the whole extractor |
| `classify()` | the 15-way decision tree, thresholds as written |
| `load_rows`, `paths_for`, `work`, the ProcessPoolExecutor driver | |

| from `image_rank_proto.py` | |
|---|---|
| `BAND_PROX`, `CLUSTER_PRIOR`, `DISPOSITIONED`, `BACKEND_FAMILIES` | tables |
| `score()`, the per-(test,cluster) roll-up, the frame-phase detector | ranking |
| the cross-tab / top-N / dispositioned / known_failure printers | reporting |

It should `from build_image_report import near_miss_band` and
`from image_baseline_report import family_of` rather than re-deriving either —
one definition of the bands, one of the families.

### 5.3 `ruffle-tests/triage_image_tests.py` — keep, demote, re-point

It has **not** been superseded. It answers a question neither new tool can:
*is this difference fixable?* — by rendering Ruffle itself at 4× and asking
whether Ruffle is closer to Flash than we are (A-INHERENT vs B-FIXABLE). That
verdict is what `ACCEPTED_DIFFS.md` §11 is built on, and the clustering here
cannot substitute for it: `hairline_edge_drift` says "the diff is a 1px edge",
which is *consistent with* the MSAA gap but does not prove it.

Two changes, neither urgent:

1. Add `--from-ranked ranked.json --top N` so it runs on the ranked head instead
   of a full sweep (it needs a `cargo build -p exporter` and is far too slow to
   sweep 403).
2. Its `discover()` goes through `run_image_tests.py`; point it at the
   `image_results_<stem>.json` census instead, so it sees the same corpus the
   other two tools do.

The intended funnel is: **`image_status_diff.py` (did anything move?) →
`image_triage.py` (what kind of wrong is it, and what should I fix first?) →
`triage_image_tests.py` (is this one actually fixable, or is it the MSAA gap?)**.

### 5.4 What NOT to build

- No image-side `filter_results.py`. Image comparisons do not gate pass/fail and
  never should; a "filtered image pass rate" would invite exactly the averaging
  the baseline doc warns against.
- No cluster diffing across CI runs in v1. The `ruffle-image-results` branch is
  force-pushed with no history, so the previous run's actual PNGs are gone by the
  time the next one lands. `--features OLD,NEW` in `image_status_diff.py` works
  only when a session archived the earlier payload; the band-move report covers
  the same ground from JSON alone and always works.
