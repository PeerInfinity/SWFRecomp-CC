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

### Image-axis dispositions of record

Every entry below lives in
`ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` and carries the
`<!-- image-axis: ... -->` marker `image_triage.py` reads. Keep this list in
sync when a session adds or narrows one — the board's "hard" exclusion set is
exactly these markers plus the global `ignored_tests.txt`.

| comparison(s) | mechanism | scope / standing invariant |
|---|---|---|
| `visual/video/colorconversion/h263 output` | Spark IDCT precision | 10 808 channels, max 2 |
| `visual/video/deblocking output` | Spark IDCT precision, one Cb level | 104 channels, max 4 |
| `avm1/netstream_play_flv output` | Sorenson Spark pixel parity | 44 channels, max 3 |
| `visual/simple_shapes/masks output` + `…/masks_equal_clipdepth output` | **NARROWED s16** — was "1-sample rasteriser tie" for all 1738 channels; 1474 of them were our mask stencil rasterising the masker's STROKE (fixed s16). | now scoped to the **359 interior** channels measured after the fix (1738 → 359, mean 0.4927 → 0.0940; curve flattening / AA). A residual materially above ~359 is NOT covered. |
| `avm2/bitmapdata_applyfilter_blur output` | **NEW s16** — the residual is the `with_default_font = true` TextField the fixture draws into the source bitmap, replicated across six cells; the blur itself contributes none of it. | 30 844 channels, mean 1.21, confined to four glyph bands. Above ~31 k, or excess outside the bands ⇒ re-triage the blur path. |

**Explicitly NOT dispositioned (do not add):**

- `visual/filters/blur_quality` — **NO-GO on a disposition (s16).** The premise
  "goldens disagree by 1 LSB → band ceiling" does not survive: the baseline is
  166 986 outliers at **max diff 9 against tolerance 6**, a 3-level overshoot
  compounded over 9 passes, not a tie. The 1-LSB fact
  (`session15-fanout-reports/wave1-gfx-blur-morphratio.md` §2.6) is about
  `blur_quality` and `blur_fractional`'s goldens disagreeing *with each other*;
  it bounds the achievable precision, it does not explain a 9-unit gap. And
  **neither test is `known_failure` upstream**, so current Ruffle clears both at
  these tolerances — an achievable answer exists, and dispositioning it would
  freeze a solvable bug (the inverse of the `avm2-net-tranche2` trap).
  **Completion mechanism to flip this to GO-for-a-fix:** build the Ruffle
  exporter at `~/CC/ruffle`, dump an intermediate blur pass for one
  `quality ≥ 7` tile, and fit our per-pass rounding to it (the
  `triage_image_tests.py` oracle route) — measured, our per-pass response is
  `0.9951·v + 1.02` against the golden's `0.9980·v − 0.5`; or move
  `bd_apply_filter` onto the GPU shader that produced the golden's sampling
  path. Until then it is a large band move already banked (821 415 → 166 986 in
  s15), not a ceiling.
- `visual/cache_as_bitmap/morph` — **NO-GO on a disposition (s16), twice
  recommended for one in s14/s15 and refuted both times.** All 2832 outliers are
  the red channel of one flat interior fill, expected 84 vs ours 85: Ruffle's
  `lerp_color` truncates on the u8 scale and we rounded. Fixed in s16
  (`tag.c::morph_lerp_color_u8`). Any future disposition request here must first
  explain why 84-vs-85 is not the truncation rule our own AVM2 path already
  implements.

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

## 9. Session-10 state of the board (2026-08-01)

**Closeout run `30713776612` at `c4496a4c8`: 217/566 (38.3%), +45, zero
regressions on either axis** (from 172/566 at `feb8882b0`). Full ledger:
`polish-sweep-arc.md` §11; reports `session10-fanout-reports/`.

Corrections to §8's leads, measured this session:

- **Blend**: F0–F4/F6/F7-AVM1 landed. Only 2 flips (`max_outliers=0` needs
  zero residual) but 15 band moves of 56–96%. The residual on ~all
  `visual/blend_modes` tests is ONE pre-existing extra element inside the
  blend group (golden 217 / before 227 / after 255 on `add`) — single
  mechanism, the top pixel lead going forward. F5 (layer groups) and
  F7-AVM2 remain.
- **SimpleButton**: walk arm + state machine + `resolve_shape_geom` landed
  (+5). `cache_as_bitmap/avm2_button` was NOT AVM2 (AVM1 libswf path —
  wave-1's DoABC gate over-matched). Remaining: `button2` ×3 (state repro),
  `avm2_button_scroll_rect` (needs AVM2 clipping, excess GREW now that the
  button draws), `bitmapbuttons` (bitmap fills).
- **Text**: `edittext_selection_leading` ×12 + riders all landed (+14).
  T3 device-font outlines still the deferred arc. New: CPU-raster
  box/selection port unblocks `cache_as_bitmap/edittext_selection` ×3.
- **Masks**: wave-1 diagnosis says the §8 "gating bug" framing was wrong —
  FOUR defects (stencil accumulates per-pass so mask N tests the union;
  every EditText ORs its rect in; setMask unread by tag.c loops; scrollRect
  is a stub; AVM2 render walk reads none of clip_depth/mask/scroll_rect).
  Defect A alone = 2 flips at HIGH text-family risk; the full 8–15 needs
  the AVM2 T7 arc (3–4 sessions). `wave1-gfx-masks.md` has the plan; the
  regression suite still has NO mask test.
- **cacheAsBitmap = CARRIER** (wave1-gfx-cab-misc): 25 of 32 cmps route to
  mask/EditText/scrollRect/button/cxform owners; only 7 need a real cache
  (Ruffle's alpha-mask path + the swf-version size gates — land gates and
  cache together or `swf_9/10_too_big` regress). Pair with a Filters arc.
- **Frame phase**: `simple_loop_test` period now Ruffle-exact (+1 flip,
  frames 3–7 demoted to the hairline class). `timeline_loop` is a DIFFERENT
  mechanism (byte-identical A/B under the phase fix). `offset_translation`
  should be retired as a cluster (the ±8px shift probe saturates on small
  images — cab-misc report §8).
- Worsened-band watchlist for the next board: `edittext_caret_empty` ×12
  (48→84, the device-box corner trade), `place_object_test` (+73%),
  `cache_as_bitmap/masks [.03/.04]` (~+70%).
- New playbook rule (w2-button trap): worktree test-dir copies need
  `--recompile` on FIRST use — a `RecompiledABC` copied mid-write from the
  main tree reads as `compile_fail` even sequentially.

## 10. Session-11 state of the board (2026-08-05)

**Closeout run `31075033086` at `6de650432`: 257/566 (45.4%), +40, zero
regressions, bands improved 73 / worsened 0** (from 217/566 at
`c4496a4c8`). Ledger: `polish-sweep-arc.md` §12; reports
`session11-fanout-reports/`.

- **quality-aware MSAA is the headline mechanism** (24 flips): goldens
  exported at `quality="low"` are 1-sample; `MSAA_SAMPLES` macro (default
  4) + `verify_output.py` passes `-DMSAA_SAMPLES=1` for low. STANDING
  INVARIANT: any new pipeline in `render_webgpu.c` must use `MSAA_SAMPLES`,
  never a literal 4, or pipeline creation fails loudly at count 1. It also
  retired s9/s10's "blend extra-element" lead — that was the AA fringe.
- **blend_modes is now CAPPED at a_epsilon** (18-60 channels, sub-pixel
  rasterisation ties at `max_outliers=0`) — do not scope; F5 layer groups
  (`layer_alpha`/`layer_erase`) and F7-AVM2 are the only live blend items.
- **Masks**: defect A (per-mask stencil refs) + clobber fixes landed;
  `masks`/`masks_equal_clipdepth` 248261→1686 (c_small, single-mechanism
  residual). acid-clip FLIPPED via the clobber fix. Defects B/C/D and the
  AVM2 walk (clip_depth/mask/scroll_rect all unread) remain the mask arc.
  First mask regression test exists now (`regression/mask_sibling_union`,
  byte-exact golden, axis-aligned by design). `avm2/mask_reapply` is a NEW
  unowned bucket: a tag.c-path mask that does nothing even solo.
- **caret_empty ×12 flipped** (corner middle-path on the EMBEDDED branch +
  un-gated caret renderer + collapsed-selection caret predicate + caret
  drawn OUTSIDE the field stencil). The s10 worsened-band watchlist is
  fully dispositioned: caret_empty recovered, place_object_test KEEP
  (MAX_DYNAMIC_VERTICES raise exposed pre-existing AVM1 text divergence on
  a double-known_failure test; lesson — A/B any renderer capacity raise on
  the image axis), cab/masks KEEP (correct cxform exposed unplumbed AVM2
  .mask; rows are mask-blocked).
- **button2 ×3 flipped**: buttonMode + `_up/_over/_down` frame labels
  (Ruffle MovieClip mechanism, not SimpleButton). MouseUpInside must not
  reach the arm.
- Remaining leads by size: text/auto_size family band-moved -81..-100%
  under B9 device fonts (near-pass now: height 12, match_style 12, glyph 6,
  duplicate_font 3 — a cheap next slice); masks arc; AVM2 static-bitmap
  upload (bitmapbuttons, whole-stage blank); scrollRect stencil (sketch
  ready, flips blocked); Stage3D/video blank_render backends (arc-sized).

## 11. Session-12 state of the board (2026-08-06)

**Closeout run `31090651530` at `1f8396f57`: 286/567 (50.4%), +28, zero
regressions, bands improved 38 / worsened 0** (from 258/567 at `6de650432`;
note pass-count restated 257→258 and denominator 566→567 by upstream drift).
Ledger: `polish-sweep-arc.md` §13; reports `session12-fanout-reports/`.

- **Headline mechanism: AVM2 clipDepth masking existed nowhere** — the acid
  ×16 "gradient ramp" cluster was actually mask-union-instead-of-intersection.
  `avm2_render_node` now runs the tag.c single-active-range clip loop +
  masker suppression + `DisplayObject.mask` + nested `clip_ref/restore_clip`
  (bitmapmax + masks-v2 superset merge). Riders: pixelbender_effect_twirl,
  acid-textfield-scroll, flash_text_TextField2.
- **Dynamic-bitmap cap** now `max(stage, bitmap_highest)` — oversized-bitmap
  blank_render class closed (+4).
- **Filters: mechanism now correct, family struck from flip leads.** Box-blur
  kernel + inner/knockout/compositeSource composition landed; 12/13
  comparisons improved -17..-93%; residual is a shared low-amplitude render
  error vs 0-18 outlier budgets. Two engine-wide fixes rode along: uniform
  ring buffer (writeBuffer-vs-Submit ordering — every blur had been
  single-axis) and radians-not-degrees filter angles.
- **EditText**: quality-gated pixel snapping (`MSAA_SAMPLES==1` = Low arm) +
  fractional-bottom-edge corner drop flipped auto_size/width at exactly
  18=limit; AVM2 glyph stencil clip wired (auto_size/return → a_epsilon);
  AVM1 line advance now honors TextFormat.leading (leading_define_font).
- **Dispositions to respect**: fonts near-pass family (height/match_style/
  glyph/duplicate_font) = 1-5px AA stair-step ties, capped like blend_modes;
  simple_shapes/masks 1686 = rasterizer tie, NOT mask work; frame-phase
  channel exhausted; quality/MSAA axis closed.
- **Remaining leads**: mask defect C AVM2-scrollRect half (~20 lines, v1
  report §6.1) + defect B redesign (s10 sketch has a UAF); char-id-0 depth
  sentinel (blocks all 5 embedded-video comparisons incl. h263-on-supported-
  codec — cheapest big diagnosis, 21 tag.c sites); acid-blend-2 B-channel
  halving in the blend composite (evidence the capped blend_modes rows hide
  a real bug); AVM2 static-bitmap upload (bitmapbuttons blockers A+B
  confirmed but DEFER — tol 4 / max_out 0 on resampled JPEG unwinnable);
  Stage3D (30 cmps) + video (21) backends arc-sized.

## 12. Session-13 state of the board (2026-08-06)

**Closeout run `31130292354` at `fb36ba110`: 301/567 (53.1%), +15, zero
regressions, bands improved 15 / worsened 5 (all fail→fail).** Ledger:
`polish-sweep-arc.md` §14; reports `session13-fanout-reports/`.

- **Embedded video renders.** Recompiler video-scoped char-id-0 alias
  (id 0→0x4000, gated on video presence) + Ruffle-exact BT.601 fixed-point
  YUV. VP6 family byte-exact ×4; h263 −98% to c_small (IDCT-level,
  dispositioned Cat 9 rewrite); deblocking NOT dispositioned (implementable:
  stream cap + flags byte + deblock port).
- **Adaptive curve subdivision** (num_passes = max(6, ceil(sqrt(d/8tol))))
  replaced the fixed 6-chord flattening: +7 incl. six timeline_loop
  hairline_edge_drift members. hairline_edge_drift is therefore ≥2
  mechanisms — re-triage the cluster; splitter is whether the SWF carries a
  large-deviation quadratic. lroundf REFUTED (costs headroom); morph
  gated out (index-paired vertices). Side effect: simple_shapes/masks tie
  pair worsened 1686→2624 (still c_small, still dispositioned).
- **Masks: defects B and C landed.** B = AVM1 setMask timeline content
  (MovieClip-registry pairing, no DisplayObject* stored; clip_depth=0
  retirement coupling; 0 flips, text_field_mask −100% to 56 excess).
  C = AVM2 scrollRect crop (avm2_button_scroll_rect → a_epsilon 9 excess —
  one lavapipe corner pixel from flipping). cache_as_bitmap/masks family
  moved −75..−95% with output.07 flipping. Remaining mask residuals all
  point at Equal/IncrementClamp stencil intersection (3 named
  beneficiaries) and the AVM1 scrollRect translate.
- **Dispositions**: simple_shapes/masks pair + h263 now resolve HARD via
  ACCEPTED_DIFFS entries (verified through image_triage's resolver — the
  mechanism is doc-driven, no script change). Filters bevel family drifted
  +6-7% (fail→fail) — family remains struck from flip leads.
- **Top remaining leads**: bitmap-fill U-pinning (acid-bitmap-fill 100k,
  acid-bitmap-draw_quality ×194k — biggest cluster); Equal/IncrementClamp;
  vertex-placement at curve joints (acid-blend-2 output.26); AVM1
  scrollRect translate; deblocking; Stage3D (30) + remaining video (16)
  backends arc-sized.

## 13. Session-14 state of the board (2026-08-12)

**Closeout run `31647430265` at `bf585e448`: 310/569 (54.5%), +9, zero
regressions, bands improved 7 / worsened 0.** Ledger:
`polish-sweep-arc.md` §15; reports `session14-fanout-reports/`.

- **Nested-mask stencil model landed** (Ruffle Equal/IncrementClamp +
  DecrementClamp full-screen-quad pop; `mask_ref` = nesting level). The
  cache_as_bitmap/masks family .01–.06 flipped; `regression/
  mask_nested_intersect` finally exists as a built test (tolerance 0).
  `end_clip` now pops ONE level and pairings must be LIFO — any new caller
  of the clip API must push/pop exactly once per path.
- **AVM1 scrollRect implemented end-to-end** (was a fully inert stub);
  nested maskers are DISCARDED per Ruffle commands.rs. scroll_rect_scaled
  flipped; the scroll_rect residual is a separate PixelSnapping::Always
  defect; a latent AVM2 divergence is recorded at avm2_display.c:15547
  (translate gated on mask capture; Ruffle gates only the crop).
- **Bitmap fills tile on content size** (padded-layer tiling refuted the
  U-pinning label). acid-bitmap-fill flipped with 3% headroom on the
  tightest rung; linear-sampler lever documented unused.
- **Deblocking filter ported** (+0 flips as re-priced; visual/video/
  deblocking now b_tiny at 104 excess = dispositioned IDCT residual, entry
  added). Video board hygiene: Video-EmbedSquareTest is NOT a video defect;
  acid-video has no DefineVideoStream — the "remaining video (16)" bucket
  is mis-scoped and should be rebuilt from SWF-level scan.
- **Morph streams are now index-paired** (structural; 9/20 morph tests were
  desynchronised) — unlocks morph adaptive subdivision, but P1's "+7 morph
  family" was refuted (zero quadratics; diffs are text-colour band / AA
  tie). Scale-aware tolerance leg HELD: our 0.05 px screen tolerance is
  half lyon's 0.1 px and crosses over the reference (acid-scale 302→342);
  re-measure at 2 twips.
- **Top remaining leads**: simple_shapes/masks pair re-baseline (now 1738,
  entry amended); displacement-map trio (content_displaced, one mechanism,
  3 rows); blur_fractional/blur_quality structural extra ink (774k/821k);
  blend-layer alpha (output.26, one-dump bisect); Stage3D (25) + h264 (12)
  arcs parked; define_bits_lossless2_rgb15 arrived passing (new upstream).

## 14. Session-15 state of the board (2026-08-13)

**Closeout run `31748059158` at `3db858cbc`: 324/569 (56.9%), +14, zero
regressions, bands improved 13 / worsened 0, drift 0/0.** Ledger:
`polish-sweep-arc.md` §16; reports `session15-fanout-reports/`.

- **s16→s32 shape deltas landed** (17-bit SB fields; both acid-blend flips).
  §13's "blend-layer alpha" row and §11's "B-channel halving" row are
  SUPERSEDED. The four held acid-blend-2 comparisons passed CI.
- **Blur is no longer a no-op for BitmapData**: bd_apply_filter routes to a
  corrected box kernel (normalize by quantized weight sum + round-nearest —
  the literal blur.wgsl port FAILS by 48 channels; keep the correction).
  MAX_DYNAMIC_BITMAPS is now budgeted (64 floor → 128 under 384MB); a flat
  raise is REFUTED (acid-color would hit 1.73GB). applyfilter_blur residual
  is device-font text.
- **Runtime drawing-API flattening is lyon/Levien** (leg R). The four-bucket
  ladder (1/4/8/16) is gone. P2's recompiler framing was WRONG for 9/13
  census rows (they have zero recompiler geometry) and the 0.6px magnitude
  was 10× overstated. Leg C (recompiler port) is HELD for a solo dispatch —
  never bundle (bounds shrink ~1 twip = trace effect corpus-wide).
- **render_canary_tests.txt gained acid-blend-2** — the prior 11 canary
  members contain ZERO quadratics (a canary caveat discovered s15; curve
  changes were previously invisible to the canary).
- **Morph OOB closed** (stroke vertices + end colors reach the end tables;
  morph_test1 −76% ×5). Known-remaining: per-character end-color offset
  (tag.c:6966 / avm2 :3197) needs a tagDefineMorphShape signature change.
- **no_render bucket 5→1** (capture cap + sprite recursion + lossless2 fmt4).
- **Top remaining leads**: AVM2 filters Route 2 offscreen/composite arc
  (owns much of the 15-row filters family; five traps in
  wave1-gfx-displace-blend.md + w2-gfx-blur-report.md §6); flattening leg C
  solo run (masks 1738→1497 + 6 band moves, −25-38% vertices);
  simple_shapes/masks = scale/transform defect (slope, not flattening);
  acid-large VRAM budgeting; blur_quality residual per-pass rounding
  (the "goldens disagree by 1 LSB — band ceiling" framing is REFUTED in s16;
  max diff 9 vs tolerance 6 and Ruffle clears the test upstream — see §3); Stage3D (25) + h264 (12
  → really 11 + FLV seek) parked; displacement Route 2 merged into the
  filters arc.

## 15. Session-15→16 state of the board (2026-08-14/15)

**Closeout run `31874872388` at `86434112a`: 324 → 337/569 (59.2%; +13 = 14 gains − 1 regression fixed post-run), 2 real regressions both fixed in the follow-up commit (avm2/verify_method_info_oob: load-rejected ABC must ignore DoABC2 LAZY_INITIALIZE; visual/define_bits_lossless2_rgb15: bitmap smoothing only exists from SWF 8 — Ruffle read.rs) and re-graded by run {{RERUN}},
bands 32 improved / 2 worsened (acid-scale 302→320, strokes/scale 66243→70119, both <7%), drift 0 new / 0 gone in the graded intersection; upstream master has since added avm1/sound_load_* ×7 + avm2/matrix3d_* ×3 and rewritten from_gnash Sound-v6/7/8 output.ruffle.txt (loadSound/onSoundComplete — new AVM1 Sound lead).** Baseline into the session was 324/569
(56.9 %) at `3db858cbc`; **predicted +12**. Ledger:
`polish-sweep-arc.md` §17; reports `session16-fanout-reports/`.

- **Gradient ramps are now Ruffle's texel walk** (`gradient_ramp.h`, shared by
  the recompiler and both VMs): one cursor step per texel, `alpha = 0` pinned on
  equal ratios, never sorts, **always exactly 256 rows**. The old segment walk
  emitted 336 rows into a 256-row slot on non-monotonic ratios — a live
  over-run of the gradient's own texture allocation. +4
  (`gradient_nonsequential_ratios`, `gradient_same_ratios`,
  `gradient_radial_same_ratios`, `gradient_issue_9892`; the last needs the
  linearRGB leg, which stores the ramp in linear space and ORs
  `interpolation_mode << 10` into the style word). LINESTYLE2 `HasFillFlag`
  gradient **strokes** and AVM2 `beginGradientFill` null alphas/ratios are both
  fixed as mechanisms but **refuted as flips** — `acid-gradient-2` 12 555 → 79
  and `graphics_gradients_nulls` 117 600 → 600, both blocked by
  `max_outliers = 0`.
- **AVM2 `DisplayObject.filters` renders** (cut 1, ~140 substantive lines,
  `avm2_display.c` only, no new pipeline, no `render_stub.c` twin). §14's
  "Route 2 owns much of the 15-row filters family" is **SUPERSEDED**: the family
  is **27** live comparisons and Route 2 owns **7** of them; 17 are AVM1-tag-path
  rows that already had a renderer and 3 are CPU `applyFilter`. §14's "five
  traps incl. object-sized FilterSource" is **SUPERSEDED for
  blur/glow/dropShadow/bevel** — Ruffle scales filters by the *stage view
  matrix only*, so our stage-sized machinery is the same computation, proven by
  `glow_pass_scaling` landing byte-identical to its golden. Trap 1 binds only
  for **displacement** (cut 2). Non-obvious rules that cost real measurement:
  BlurFilter `strength` must be forced to 1 or the object vanishes;
  `Filter::impotent()` is **blur-only** (widening it costs `acid-filter` 34×);
  and our `quality == 0` skip is **ours, not Ruffle's** (Ruffle composites the
  unblurred source) — exact only when `composite_source` is set and distance
  is 0.
- **§14's `blur_quality` "band ceiling / goldens disagree by 1 LSB" row is
  SUPERSEDED — it was a 2-line rounding port.** Ruffle divides by `full_size`
  while its quantized weight sum is up to 2/255 smaller, so a uniform field
  decays per pass, and the per-pass `floor` costs another half level. s15's
  energy-preserving correction was the divergence. `blur_quality` and
  `blur_pass_scaling` both flip; the feared `blur_fractional` regression does
  not occur. The s15 comment table in `blur_axis_pass` is replaced by the
  derivation.
- **Flattening leg C landed, bundled — §14's "never bundle" is SUPERSEDED.**
  AS-visible bounds come from the SWF tag's declared `ShapeBounds` RECT in our
  recompiler *and* in Ruffle; `processShape()`'s vertex extremes never leave the
  recompiler. Corpus-wide proof, not a sample: 4492 SWFs recompiled on both
  binaries, 418 differ, **0 bounds-argument changes, 0 structural changes**, and
  138/138 trace probes byte-unchanged. Free win: **−39.2 % emitted shape
  vertices**. Pixel value is 7 band moves (`masks` −241, `drop_shadow` −436,
  `scroll_rect_mask` 42→20, `blend_modes/multiply` 37→19, `doubleAndRegister`,
  `avm2_button_scroll_rect`) and it costs `acid-blend-2` a little slack.
- **Mask stencils omit strokes for timeline-character maskers** (Ruffle's
  tessellator rule, one `static` helper in `render_webgpu.c`): `masks` and
  `masks_equal_clipdepth` 1738 → 359 each, **181 stacked with leg C**. §14's
  "`simple_shapes/masks` = scale/transform defect (slope, not flattening)" is
  **SUPERSEDED and refuted** — centres agree to 0.02 px, the deltas are a
  uniform +0.52 px *dilation*, and the "slope" came from fitting straight lines
  to an elliptical arc. The ACCEPTED_DIFFS entry is narrowed to the measured
  residual. Standing lesson: **a masker census over root `tagPlaceObject` rows
  is a lower bound** — sprite maskers need the subtree walked (two unpredicted
  band moves came from there), and `tagPlaceObject2`'s **first** numeric
  argument is `depth`, not `char_id`.
- **AVM1 morph colour lerp truncates** like `lerp_color` (our AVM2 twin already
  did): `cache_as_bitmap/morph` 2832 → **0**, +1. §14's "cache_as_bitmap/morph
  (2832, max diff 1) → disposition" is **SUPERSEDED** — it was one flat fill,
  one channel, 84 vs 85, and the docs now carry a standing "never disposition
  this" note. The per-character morph end-colour offset (§14's open item) is
  **closed as hygiene**: the emitter now writes the correct base, and it moves
  **zero** comparisons and zero trace lines (the only multi-morph pixel test is
  AVM2, which already used the absolute index; the only multi-morph AVM1 test
  has no image comparison). Note it changes `tagDefineMorphShape`'s arity, so
  the deployed `docs/recompiler/runtime_headers/include_libswf_tag.h` was synced
  in the same patch — **the WASM demo still needs a full `deploy_wasm_demo.sh`
  redeploy** before its in-browser recompiler emits 16-argument calls.
- **`no_render` is empty.** §14's "acid-large VRAM budgeting" is **DONE**:
  `BITMAP_ARRAY_HARD_LIMIT` = 1.5 GiB in `plan_dynamic_bitmaps` (lavapipe's
  2 GiB `maxMemoryAllocationSize`) **plus** per-fill bitmap smoothing. The clamp
  **alone is a ledger trap** — it converts the `no_render` into a
  139 500-outlier visible failure and flips nothing; ship both or neither. The
  brief's "plumb the smoothing bit from the recompiler" is refuted: the raw SWF
  fill-type byte (`0x40/0x41` smoothed, `0x42/0x43` not) was already in the
  vertex buffer, so it is a pure runtime change —
  `render_webgpu_bitmap_fill_style_word(repeat, smooth)` is now the single
  sampler-selection point.
- **`opaqueBackground` is implemented on all three paths** (PlaceObject3
  BackgroundColor kept by the recompiler under Ruffle's `version >= 11` +
  `alpha > 0` rules, AVM1 property, AVM2 accessors; world-bounds rect painted
  **before** the mask/scrollRect push, cxform slot 0 — Ruffle's
  `render_base` order). Priced +2, **delivered 0**: −99.2 % excess and both
  residuals are other, named defects. AVM2 `beginBitmapFill` routes to the
  existing `renderer_draw_bitmap_tris` (136 030 → 76 870, 185 430 → 43 013, no
  flip) — pixels are **snapshotted, not referenced**, because
  `Avm2GraphicsExt.paths` is outside the region `avm2_gc.c` scans.
- **Two pixel flips arrived from the trace axis** (`bitmapdata_draw_alpha_erase`,
  `edittext_tag_indent`): the image comparison failed *for the same reason* the
  trace did. Standing follow-up: sweep the remaining soft `[trace-ign]` rows
  whose trace also fails — the image diff may come free once the trace is right.

**Canary changes.** `render_canary_tests.txt` gains **`visual/filters/glow_pass_scaling`**
(tier 1 — the set's first AVM2 `.filters` member, byte-exact against its golden)
and **`visual/cache_as_bitmap/masks`** (7 comparisons, the nearest passing AVM2
neighbour of the new filter arm). The header note is corrected: "filters proper"
is no longer a family with no CI-passing representative on the AVM2 route (the
AVM1 *tag* route still is).

**Canary blind spots, stated (s15 rule).** Outside `visual/simple_shapes/masks`
itself, **no member carries a stroke-bearing masker**; **no member is an AVM1
morph with colours**; and **no member has a smoothed (`0x40`/`0x41`) bitmap
fill** — `acid-blend-2`'s fill is `0x43`, so the standing set could never have
seen a smoothed-fill regression. Recommended addition:
**`from_shumway/acid/acid-bitmap-fill`**, the only CI-passing test with a `0x40`
repeating smoothed fill. Also uncovered: `BitmapData.draw` blend modes and
DefineEditText layout fields (both graded by hand-picked sibling sets this
session).

**Top remaining leads.** cacheAsBitmap **`PixelSnapping::Always`** (+1 to +4;
named mechanism, closed arithmetic, owns the `offset_translation` cluster,
`visual/opaque_background`'s residual and part of `extra_element`);
**`drawGraphicsData` is validation-only** — a blank-render owner for *every*
fill kind, plus its sibling `lineBitmapStyle` (bitmap strokes); filters **cut 2**
(the displacement trio, the only place trap 1 binds); the **EditText
background/border family** (31 live comparisons, **at least two mechanisms** —
missing background/border elements vs device-font glyph placement under a matrix
— do not brief as one); `acid-filter`'s 482 and `simple_shapes/masks`'s 181, both
now in `hairline_edge_drift`/tessellation-tie territory; and the **`blank_render`
bucket (41 live) is the board's new multi-mechanism trap** — five unrelated
causes, exactly the mis-scoping shape s15's `no_render` brief had. Stage3D (29
family-wide) + h264 (11 + FLV seek) remain parked.

**Two method notes worth standing rules.** (1) A **full-corpus recompiler A/B**
— run both binaries over all 4492 `test.swf` in temp dirs and diff the generated
C, ~25 min at `-P 2` — turns "which tests might this touch?" into an exact
affected-test list, and it found two pixel rows (`filters/drop_shadow`,
`blend_modes/multiply`) that a hand census had missed entirely; the gradient
agent's variant over the 411 image-bearing tests corrected a board blast radius
from 4 to 9. Promote the script into `ruffle-tests/`. (2) Under fan-out load the
300 s per-file gcc cap manufactures `compile_fail`s **and** plausible-looking
`output_mismatch`es (stale `Recompiled*` caches in `cp -r`'d dirs) — export
`SWFRECOMP_COMPILE_TIMEOUT=2400` and pass `--recompile` on first use of every
copied directory, canaries included.
