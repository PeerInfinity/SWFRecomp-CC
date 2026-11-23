# s26 wave 2: `w2-cm-chain-cab-edge` (ColorMatrix chain fidelity + the cacheAsBitmap top/left edge)

**NEW FILES**
- `SWFRecompDocs/plans/session26-fanout-reports/w2-cm-chain-cab-edge-report.md` (this report)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-cm-chain-cab-edge.patch`
  - `git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <3 fixture dirs>`
  - Proven with `git apply --check -R` on the branch tip.
- `ruffle-tests/tests/swfs/regression/avm1_po3_color_matrix_live/`: `create_test_swf.py` (generates all 3 fixtures),
  `test.swf`, `test.toml`, `output.txt`, `output.expected.png`
- `ruffle-tests/tests/swfs/regression/avm1_po3_color_matrix_live_nested/`: `test.swf`, `test.toml`, `output.txt`, `output.expected.png`
- `ruffle-tests/tests/swfs/regression/avm1_po3_color_matrix_live_clear/`: `test.swf`, `test.toml`, `output.txt`, `output.expected.png`

**Source files touched** (named for the sibling map and `n-pixel-pass`):

| file | what changes |
|---|---|
| `SWFRecomp/src/swf.cpp` | `PlaceCmCompose` (new `live()` predicate + bookkeeping in `apply`); the root PlaceObject3 arm's CM emit + filter-list emit; the sprite arm's `sp_cm` emit + `emitSpriteFilterList` call site |
| `SWFModernRuntime/src/libswf/tag.c` | new `obj_filter_routed` + `tagSetColorMatrixLive`; `cab_snaps`; `build_filter_chain`; `render_filtered_core` (type-6 arm in the chain loop); the filter gates in the root, nested and `render_display_list` loops and `tag_root_edittext_is_filtered`; the 2 placement-arm resets next to `filter_chain = NULL` |
| `SWFModernRuntime/src/actionmodern/action.c` | `avm1ApplyRuntimeFiltersToEntry` only (one line) |
| `SWFModernRuntime/include/libswf/swf.h` | trailing `DisplayObject.cm_live` |
| `SWFModernRuntime/include/libswf/tag.h` | 1 prototype |

- I did not touch `render_attached_child` or shape tessellation.
- I touched no `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS`-only arm. `tagSetColorMatrixLive` compiles in both modes.

**Box:**
- Cloud, Dawn on lavapipe, `SETUP_STATUS` all OK.
- Base `origin/master` `91267237`; docs only since the s26 baseline code.
- Tests from `download_tests.sh visual avm1 avm2 from_shumway from_gnash fonts text timeline swf import_assets audio mixed_avm stage3d`.
- Ruffle blobless clone at upstream `3e98d9ba6`.
- **Fidelity:** my render of `visual/cache_as_bitmap/avm1_color` is md5-identical to CI's actual PNG on
  `origin/ruffle-image-results` (`74228586…`). Local absolute verdicts on that row are CI-grade.

## Verdicts and priced flips

| # | Item | Verdict | Graded flips | Evidence |
|---|---|---|---|---|
| 1 | ColorMatrix fold fidelity: (b) per-pass clamp, (c) alpha-from-colour edges | **GO, landed in this patch.** The fold is kept only where it is exact. Otherwise the CMs run as live filter passes (`renderer_run_color_matrix`). | **0 corpus** (no corpus row has an inexact fold; proven by the generated-code diff) | new fixtures: probe `cm_offdiag` vs the Ruffle exporter goes from **FAIL 7592 / max 96 to PASS 0 / max 0** |
| 1a | HOLD (a) "alpha bias fills the filter bounds" | **REFUTED as a Ruffle behaviour, with mechanism.** Ruffle `color_matrix.wgsl` divides by `src.a`, so an a = 0 texel is NaN and the gap stays empty. Alpha-bias CMs therefore stay **folded**, which matches the exporter's white gap. | 0 | exporter (140,30) = white; ours white, before and after |
| 1b | NEW finding: a CM-filtered object is bitmap-cached in Ruffle, so it gets the cAB blit snap | Fixed for live CMs. `cab_snaps` now sees them through `obj_filter_routed`. Folded CMs still do not snap; that is invisible on every corpus row (md5-identical) | 0 | the AFROMR rect at x.5: exporter crisp 111..169, ours now identical |
| 2 | `visual/cache_as_bitmap/avm1_color` (1200, KF) | **NO-GO, priced. Cannot flip; the rule that moves toward Flash costs 3 graded passes.** | 0 (best case 1200 → 230 outliers, still fail at tolerance 0); **−3 passes** if funded | §2 |

**Priced yield:** +0 graded flips, +3 regression rows (new, all PASS), 0 regressions.

## 1. ColorMatrix: when the fold is exact, and the live path when it is not

### Mechanism

- `swf.cpp PlaceCmCompose` composes `cx ∘ CM_n ∘ … ∘ CM_1` into one cxform, which `apply_cxform` clamps once at the end.
- Ruffle runs every CM as its own pass on the cached bitmap (`render/wgpu/shaders/filter/color_matrix.wgsl`).
  - Each pass unpremultiplies, applies the matrix and **clamps to [0,1]**.
  - It then draws the result with the object's colour transform.
- The fold is therefore exact iff none of these holds:
  1. **An intermediate clamp bites.** The cumulative map before CM_k (k ≥ 2) can leave [0,1] on the unit cube,
     checked by interval arithmetic in `cumulative_in_range`. Example: grey 200, ×2 then ×0.5. Ruffle gives 128; the
     fold gives 200.
  2. **A pass reads colour into alpha, or alpha into colour** (`cm[15..17] ≠ 0` or `cm[3]/cm[8]/cm[13] ≠ 0`), or has a
     negative alpha bias.
     - The filter sees an AA edge pixel unpremultiplied, with coverage k in its alpha.
     - The fold applies the matrix to the fragment's straight colour before coverage.
     - So `A' = 0.5·R` gives Ruffle `0.5k` but the fold `0.5k²`: a (255,191,191) rim against Ruffle's (255,127,127).
  3. **An alpha bias above 0.** This case stays FOLDED on purpose:
     - Our CM pass runs on a stage-sized layer, so a live pass would paint the bias over the whole stage.
     - Ruffle's a = 0 texels go to NaN and stay empty (refutes HOLD (a), above).
     - The fold paints only where the shape is, which is what the exporter shows.
- **Live is chosen only when the placement cxform is the identity.** The runtime draws the source WITH its cxform before
  the filter pass, so with a placement cx the fold stays the better approximation.
  `PlaceCmCompose::live` carries this rationale in its comment.

### Patch

- **Recompiler.**
  - When `live()` holds, the folded cxform is not emitted, so `cxform_id` stays the plain placement cx.
  - After the filter list it emits `tagSetColorMatrixLive(app_context, depth)`:
    - root arm: after `tagEndFilterList`;
    - sprite arm: after `emitSpriteFilterList`.
- **Runtime.**
  - `tagSetColorMatrixLive` sets `display_list[depth].cm_live`. It is cleared next to every `filter_chain = NULL`
    placement reset.
  - `obj_filter_routed(obj) = filter_type != 0 || (cm_live && filter_chain)` replaces `filter_type != 0` at every
    render-dispatch gate and in `cab_snaps`.
  - `build_filter_chain` adds type-6 members in list order when `cm_live` is set.
  - `render_filtered_core`'s chain loop gains the AVM2 loop's arm: `if (f->type == 6) { renderer_run_color_matrix(...); continue; }`.
    A CM-last chain composites through the legacy blit, like a blur.
- **`action.c` `avm1ApplyRuntimeFiltersToEntry` clears `cm_live`.**
  - `mc.filters = …` replaces the authored list (Ruffle `set_filters`).
  - Runtime CMs keep their existing fold (`obj_runtime_cm`).
  - Without the clear, `cm_live` would outlive the replaced list and run the authored chain on top. I added the line
    before measuring, so the without-clear render was never captured. Fixture `_clear` locks the cleared behaviour.
- **Inert unless `cm_live` is set.**
  - With `cm_live == 0`, every changed predicate reduces to the old one.
  - `build_filter_chain` never produced a type-6 member before, and the `src != NULL` chain still takes types 1-4 only.

### Generated-code diff (required for recompiler changes)

- I recompiled **all 419 image-row SWFs** downloaded here, plus `regression/`, with the old and new `SWFRecomp`
  binaries and compared the output with `diff -r`.
- All 419 exited 0.
- **416 are byte-identical.** The other 3 are:
  - `regression/avm1_placed_drawing_color`: case G (alpha row `0.5·R`) loses its folded cxform and gains
    `tagSetColorMatrixLive(app_context, 7)`. Its render is **md5-identical** before and after (integer edges), and it
    stays PASS 0 / max 0.
  - my 2 new root fixtures.
- `visual/filters/color_matrix` and `avm1/bitmap_filters` are single CMs without a placement cx, so they stay folded
  (exact: one clamp at the end).
- Consequence: no corpus row in `visual`, `avm1`, `avm2`, `from_*`, `fonts`, `text` or the misc groups reaches the new path.

### Fixtures

Generator: `avm1_po3_color_matrix_live/create_test_swf.py`. It reproduces all three SWFs byte-identically, and the first
equals the w1 probe `cm_offdiag.swf`.

| fixture | content | golden |
|---|---|---|
| `avm1_po3_color_matrix_live` | `cm_offdiag`, SWF 10, root placements: R↔B swap (folded), alpha bias (folded), ×2 then ×0.5 (live), A' = 0.5R at a .5 offset (live) | **Ruffle exporter `0ddd12b6a`**: the archived `cm_offdiag.exporter-0ddd12b6a.png`, copied |
| `avm1_po3_color_matrix_live_nested` | the same 4 placements inside one DefineSprite at the origin (sprite arm) | the same exporter PNG (by construction). Confirmation requested below |
| `avm1_po3_color_matrix_live_clear` | SWF 8; sprites `g` and `h` carry the ×2/×0.5 chain; frame 1 runs `g.filters = []` | analytic: `g` grey 200 (list replaced, unfiltered), `h` 128. Exporter check requested |

## 2. `cache_as_bitmap/avm1_color`: diagnosis and price (NO-GO)

**Geometry.**
- The shape is 0..75 px. Two placements at **tx = 12.5 px** (250 twips), with PlaceObject3 `cacheAsBitmap`.
- The AVM1 `Color.setTransform` tints them.

**Flash's rule, read off the golden.**
- Flash's golden (`045db00b3`, "Correct avm1_color reference against **Flash Player 32** under Wine", 2026-10-23) has a
  half-coverage column at x = 12 **and at x = 87** (and rows 12 and 87).
- Flash draws the cached object at its true sub-pixel position: **no snap, no crop**.
- Ruffle (`display_object.rs` `render_base`) renders the cache with its origin at the bounds minimum. It blits with
  `PixelSnapping::Always`, so 12.5 rounds to 13 and it draws full pixels 13..87.
- We reproduce Ruffle exactly (`tag.c cab_snap_delta`; md5 = `output.ruffle.png` = CI).

**Prototype (env-gated, reverted): no snap for unfiltered cacheAsBitmap.**
- `avm1_color` goes **1200 → 230 outliers, max diff 1**. Every remaining pixel is a half/quarter-coverage edge:
  - Flash (128,145,255) against ours (128,144,255);
  - Flash (255,192,192) against ours (255,191,191).
- That is Flash's 8-bit blend rounding, `dst' = src·a>>8 + dst − dst·a>>8` (a = 128 or 64). It fits all four
  channel values.
- Replicating it means changing every AA edge in the renderer, so **the row cannot flip at `tolerance = 0`**.

**The same probe breaks 3 rows that pass today** (all 29 `cache_as_bitmap/*` rows checked):

| row | before | no-snap |
|---|---|---|
| `avm2_button` | PASS | FAIL 1018 |
| `drawing_api` | PASS | FAIL 604 |
| `scroll_rect` | PASS | FAIL 2056 |

The other 25 rows are unchanged in verdict.

**Why the evidence conflicts.**
- Ruffle commit `289f73c85` ("Add pixel snapping … force it for cacheAsBitmap", 2023-07-05) **re-generated** these
  goldens: `drawing_api/expected.png`, `scroll_rect/expected.png`, `text`, `opaque_background`, plus 14 filter rows.
- `avm2_button`'s golden comes from `f55147d7c` (Ruffle core work).
- So the goldens that "prove" the snap are Ruffle-made, and `avm1_color` is the only real-Flash cacheAsBitmap capture in
  the family. Flash over Ruffle says the snap is wrong, but CI grades against the Ruffle-made goldens.

**Price.** Funding the Flash rule is **−3 graded passes, +0 flips**. Disposition:
- **book it** in `RUFFLE_VS_FLASH_DIFFERENCES.md` (`visual` suite): we match Ruffle; Flash keeps the sub-pixel offset;
  unflippable because of blend rounding.
- **Completion mechanism:**
  - Flash re-captures of `drawing_api`, `scroll_rect` and `avm2_button` (FP32, as upstream did for `avm1_color`).
  - If they show the unsnapped edges, drop the unfiltered-cacheAsBitmap snap (`cab_snap_delta`, `filter_type == 0`
    branch; my prototype was one line) and re-grade.
- The blend-rounding residual has no completion short of a CPU-exact Flash compositor.

## Sweep

- **Render canary.** `render_canary.py capture --recompile --jobs 3 --timeout 5400`.
  - BEFORE = clean `origin/master` (sources reversed with `git apply -R`, recompiler rebuilt; binary `cmp`-equal to the
    old build).
  - AFTER = this patch.
  - List = standing `render_canary_tests.txt` + every `visual/cache_as_bitmap/*` (incl. `oversize/*`) and
    `visual/filters/*` image row + the 3 fixtures = **166 tests / 231 PNGs**.

```
RENDER CANARY  before=before  after=after   166 tests / 231 comparisons
  IDENTICAL   228   DIFFERS 3   APPEARED 0   VANISHED 0   NO_RENDER 0
  DIFFERS: regression/avm1_po3_color_matrix_live{,_nested,_clear}  (all fail -> pass)
  TRACE STATUS CHANGES: (none)
```

- **Regression suite near the change:**
  - In the sweep and md5-identical before and after:
    - `avm1_placed_drawing_color` (its codegen changed);
    - `avm1_runtime_filters`;
    - `layer_group_filtered_child`, `avm2_layer_group_filtered_child`;
    - `avm1_dynclip_color_transform`.
  - Run individually on the patched build only (no before leg): `avm1_nested_po3_filters` and
    `avm1_runtime_filters_cm_bitmap`, both PASS 0 / max 0.
- **Mode parity (no-graphics, `--recompile`):** trace PASS for all 3 fixtures, `avm1_placed_drawing_color` and
  `avm1_nested_po3_filters`.
- **Browser build:** not built (no emsdk). No new `render_webgpu.c` code; the patch uses `renderer_run_color_matrix`, which already exists.
- **Canary list:** the 3 fixtures are appended at EOF (`tier=1`).

## Per-test before/after (same box, graphics, `--recompile`)

| test | clean origin/master | this patch |
|---|---|---|
| `regression/avm1_po3_color_matrix_live` (NEW) | FAIL 7592 outliers, max 96 | **PASS 0 / max 0** |
| `regression/avm1_po3_color_matrix_live_nested` (NEW) | FAIL 7592, max 96 | **PASS 0 / max 0** |
| `regression/avm1_po3_color_matrix_live_clear` (NEW) | FAIL 7200, max 72 | **PASS 0 / max 0** |
| `regression/avm1_placed_drawing_color` | PASS 0 / 0 (`c7e74eb3`) | PASS 0 / 0, md5 identical |
| `visual/filters/color_matrix` | PASS 0 / 0 (`cc91196c`) | identical |
| `visual/cache_as_bitmap/avm1_color` | FAIL 1200, max 192 (`74228586` = CI) | identical (NO-GO, §2) |
| all other `cache_as_bitmap/*` (28) and `visual/filters/*` rows | as CI | md5-identical |

## EXPECTED-FLIP LEDGER

- **Trace axis:** no moves. Three new `regression/` rows; all trace PASS in both modes (`_clear` traces `done`; the
  other two are empty).
- **Pixel axis, graded corpus:** **no moves.** 228/228 non-fixture PNGs are md5-identical, and the generated code of
  416/419 image rows is byte-identical.
- **Pixel axis, new regression rows:** `avm1_po3_color_matrix_live`, `…_nested` and `…_clear` all go PASS (0 / max 0).
  On origin/master they would be FAIL 7592 / 7592 / 7200.
- **`cache_as_bitmap/avm1_color`:** unchanged FAIL 1200 (not funded).

## Not finished / completion mechanisms

1. **A live CM under a placement cxform** keeps the fold, because the source is drawn with its cxform BEFORE the pass.
   - Completion: draw the source of a live-CM entry with an identity cx and apply the entry's cx at the composite.
   - That needs a cxform on `renderer_composite_filtered`, or `filtered_object_cxform` fed into a CM.
   - The same order issue applies to AS-set `Color` / `_alpha` on a live entry: `_alpha` commutes with an
     alpha-linear CM, colour does not. No corpus row has it.
2. **Alpha bias > 0 stays folded.** The edges are approximate (a = k + b versus k(1 + b)), but this matches Ruffle's
   empty gap. Flash presumably fills the filter bounds (unverified).
   - Completion: a filter pass bounded to the object's cache rect, which needs a scissor on the CM pass. Grade it
     against a Flash capture, not the exporter.
3. **A folded CM-only entry does not get the cAB blit snap that Ruffle gives every filtered object.** It is invisible on
   every corpus row. Folding it into `cab_snaps` (`filter_chain` has a type-6 member) is one line, but §2 suggests
   Flash does not snap at all, so I did not fund it.
4. **`avm1_color`:** §2, Flash re-captures of the three Ruffle-made goldens.

## New unclaimed leads

1. **A folded CM survives `mc.filters = []`.**
   - The placement's baked `cxform_id` still carries `cx ∘ CM`, while Ruffle drops the authored filters entirely.
   - It is pre-existing and does not apply to the live entries, which the `_clear` fixture covers.
   - Fix: on `avm1ApplyRuntimeFiltersToEntry`, restore the plain placement cx. It needs the recompiler to emit both slots
     (folded + plain). XS-S, no corpus row.
2. **Bookkeeping:** add `visual/cache_as_bitmap/avm1_color` to `RUFFLE_VS_FLASH_DIFFERENCES.md` (visual) with §2's
   evidence. It is already a KF row, and the board says "matches Ruffle's sidecar".

## LOCAL ORACLE REQUESTS

1. **Ruffle exporter, 1 frame:** `ruffle-tests/tests/swfs/regression/avm1_po3_color_matrix_live_nested/test.swf`
   (200×150). It should equal `cm_offdiag.exporter-0ddd12b6a.png`, which is the golden I shipped. If it differs, replace
   the golden with the exporter PNG.
2. **Ruffle exporter, 1 frame + `--trace-log`:** `…/regression/avm1_po3_color_matrix_live_clear/test.swf` (200×150).
   - Expected: trace `done`; rect (10..70, 10..50) = (200,200,200); rect (110..170, 10..50) = (128,128,128).
   - Replace the analytic golden if Ruffle disagrees beyond tolerance 1.
3. (Optional, Flash) **FP32 captures** of `visual/cache_as_bitmap/{drawing_api,scroll_rect,avm2_button}` decide §2.
