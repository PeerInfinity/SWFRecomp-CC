# s29 w2-lowq-tsnap: Flash LOW translation snap (TSNAP), landed per-level with ties-to-even

Slot `w2-lowq-tsnap`, wave 2 (implementation). Branch `fanout/w2-lowq-tsnap`, base `origin/master` `4dc8de40`; the runtime
code is the s29 baseline `bfa47037b`.
- Cloud box, Dawn on lavapipe.
- Corpus downloaded 2026-11-27 (`visual avm2 from_shumway avm1 from_gnash text fonts`), 64 flash_fixes applied.
  `download_tests.sh` does not print an upstream SHA.

## New files

- `ruffle-tests/tests/swfs/regression/lowq_tsnap_tie_probe/`: `create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`, `cells.json` and `output.expected.png`.
  - The golden is the **FP32 LOW capture** `w1-local-oracles/w1-lowq-next/tie_probe.lnx.png` (WIN == LNX, `--screen`
    == draw()).
  - The fixture is the w1 request fixture, unchanged; `create_test_swf.py` regenerates a byte-identical `test.swf`.
  - Tolerance 0, `max_outliers = 3152`, the measured value.
- `SWFRecompDocs/plans/session29-fanout-reports/w2-lowq-tsnap-report.md` (this file).
- `SWFRecompDocs/plans/session29-fanout-reports/w2-lowq-tsnap.patch`.
- `SWFRecompDocs/plans/session29-fanout-reports/w2-lowq-tsnap-fixtures/ledger/`:
  - `low_gate_vs_ci_baseline.txt`: every LOW comparison that moved vs CI `45878805896`;
  - `moved_rows_vs_fp32.txt`: each moved row, master → patch, vs its golden and every FP32 capture on master;
  - `low_gate_summary.txt`: all 257 LOW tests, patch leg;
  - `all_low_tests.txt`: the run list.

## Verdicts (lead)

1. **GO: TSNAP lands, PER DISPLAY-LIST LEVEL, ties to EVEN.**
   - **The rule.** Flash LOW rounds every placed object's device translation to a whole pixel at that object's own
     level, and the children compose under the snapped parent.
   - **Probe fit.** It makes the FP32 probe exact on all four placement rows: rows 0–3 go from 120 / 120 / 84 / 356 px
     ≠ Flash on master to **0 / 0 / 0 / 0**. w1's world snap left 234 px on row 3.
   - **Gate fit.** It moves **all 14 `blend_modes/*` rows strongly TOWARD their FP32 flash_fixes goldens**
     (`add` 5347 → 712 outliers). The world-snap prototype moved the same 14 rows away (+11 948 ch).
2. **Scope fitted on row 3: per-level, not world and not root-only.**
   - Per-level predicts 8 of 8 nested cells, world 5 of 8; root-only is refuted by col 7 (child at 0.65).
   - **Ties go to EVEN, not down.** Every .5 placement in the probe sat on an EVEN integer + .5, so the probe cannot tell
     the two apart.
   - Half-even is what fits `drawing_order`'s .5-on-ODD outer sprite at (253.5, 246.5). Its four LOW band edges need
     (254, 246) (§3.3).
   - It is also neutral on `avm2/symbol_class_conflict` (sprite at 411.5). Half-down moved that row away from FP32,
     449 → 1 169 ch, measured on this box.
   - Kill switches: `SWF_LOWQ_TSNAP=0` turns TSNAP off and is byte-identical to master (verified). `SWF_LOWQ_TSNAP=d`
     selects half-down, for A/B only.
3. **The two w1 gate failures are fixed by scope, not by tolerance.**
   - **No snap inside a bitmap-cached or filtered subtree**, and none on the cached / filtered entry itself. Those
     entries keep `cab_snap_delta` / `avm2_render_filtered`'s own snap, so nothing is snapped twice (the sibling
     w2-pixel-gaps-land contract).
   - **Text takes no snap, own or inherited.** It composes under the UNSNAPPED parent.
   - Results:
     - `visual/cache_as_bitmap/scroll_rect` (Flash golden) **stays pass, byte-identical**;
     - 10 of the 11 `filters/*` rows are back to master's outlier counts;
     - `filters/bevel` moves toward FP32 (291 252 → 290 327 ch);
     - `avm2/sprite_with_frames` (Flash golden) is byte-identical to master.
4. **114-test Flash-golden LOW gate.** 17 gate rows move; trace status is unchanged on all 257 LOW tests.
   - **15 move toward FP32:** `blend_modes` ×14 and `simple_shapes/layers`. `opaque_background` is unchanged.
   - **`acid-color`, pass → fail (both comparisons): toward Flash, a golden-swap candidate.** Our render becomes
     byte-equal (0 ch) to its s27 FP32 capture. Its golden is "near Flash" (675 outliers vs the capture).
   - **`acid-stroke-0`, fail → fail: AWAY, +369 outliers. The one priced loss.** It is localised to the two sheared 1-px
     noScale squares (§2.4).
5. **Every pass → fail is TOWARD a real Flash capture.** They are `acid-color` ×2, `acid-gc`, `acid-gradient-1` and
   `acid-large`. With the s27 Flash capture as the golden, at the test's own tolerance:
   - `acid-color` output: master 675 → **0**;
   - `acid-color` frame1: 2 → **0**;
   - `acid-gc`: 3 792 → **0**;
   - `acid-gradient-1`: 384 → **0**.

   All four would PASS. **flash_fixes candidates**, §5. `acid-large` moves toward its capture too, but stays far off:
   178 720 → 138 478.
6. **45° LOW stroke width: HOLD. 3-px band rule: LEAD, fitted 12 of 12 edges, not implemented.** The inset is
   **LOW-only**: our LOW bands equal Flash's HIGH bands exactly, so it is not the N ladder's. Details in §3.
7. **HIGH: md5-identical by construction.** Every added line is inside `#if MSAA_SAMPLES == 1`, or is a macro that
   expands to a no-op. `gcc -E` of both TUs at HIGH, master vs patch with numbers stripped, differs only by:
   - `((void) 0)` statements;
   - `x = (x)` self-assignments;
   - an empty `avm2_lowq_tsnap` body;
   - `cab_snaps()` guards: a pure predicate that only reads flags, so the call has no effect.

   No HIGH pipeline or render path changed.

**Priced pixel flips (CI, `images=false` still grades pixels):**
- **pass → fail: 5 comparisons in 4 tests** (`acid-color` ×2, `acid-gc`, `acid-gradient-1`, `acid-large`). All are
  toward Flash; 4 of the 5 comparisons become passes under the flash_fixes swap of §5.
- **New pass:** `regression/lowq_tsnap_tie_probe`.
- **fail → pass: none.**
- The headline is **distance to Flash**: 14 FP32 flash_fixes goldens and 9 FP32 captures closer, 2 rows away (§2).

## 1. Mechanism and patch scope

**`SWFModernRuntime/src/libswf/tag.c` (AVM1).** Everything new sits in one `#if MSAA_SAMPLES == 1` block after
`cab_snap_root_leaf`.
- **New static functions:**
  - `lowq_tsnap_on`;
  - `lowq_tsnap_delta`: ceil vs half-even on the twip grid; skips text and cached entries;
  - `lowq_tsnap_level`: the per-level rule and its state;
  - `lowq_tsnap_seed`;
  - `lowq_tsnap_attached`;
  - `lowq_tsnap_world`: root sprite / button, the `cab_snap_world` contract;
  - `lowq_tsnap_root_leaf`: root shape / morph, the `cab_snap_root_leaf` contract.
- **New non-static function:** `lowq_tsnap_round` (ties-to-even on the twip grid; also used by AVM2).
- **New statics:** `g_tsnap_depth`, `g_tsnap_off`, `g_tsnap_acc`, `g_tsnap_seed_off`, `g_tsnap_seed_acc`.
- **Macros:** `LOWQ_TSNAP_IN_PLACE`, `LOWQ_TSNAP_ATTACHED`, `LOWQ_TSNAP_SEED_CLEAR`, `LOWQ_TSNAP_WORLD` and
  `LOWQ_TSNAP_ROOT_LEAF`. All are no-ops at MSAA != 1.
- **Touched functions:**
  - **`compose_children`:**
    - per-level state save at entry, reset at the top of each iteration, restore at exit;
    - `LOWQ_TSNAP_IN_PLACE(obj, composed)` right after the twip-rounded composition, BEFORE the scrollRect translate.
      The crop and the content both ride the snap, as on `avm2_button_scroll_rect`.
  - **`tagRerenderFrame` and `tagShowFrame` root loops (both copies):**
    - `LOWQ_TSNAP_SEED_CLEAR()` at the top of each entry;
    - `LOWQ_TSNAP_ROOT_LEAF` for a non-cached root leaf;
    - `LOWQ_TSNAP_WORLD` after `cab_snap_world` in the sprite and button arms.
  - **`render_attached_child`:** `LOWQ_TSNAP_ATTACHED(d, mc_xform)`.
- **Not touched:**
  - the cab functions themselves (`cab_snap_delta` / `cab_snap_world` / `cab_snap_in_place`);
  - `render_webgpu.c`, including the shader's `lq_snap_t` paint snap. On a snapped entry that term becomes 0, so the
    paint follows the geometry.

**`SWFModernRuntime/src/avm2/avm2_display.c` (AVM2).**
- **New function:** `avm2_lowq_tsnap`, defined just before `avm2_render_node`.
- **New statics:** `g_avm2_tsnap_off`, `g_avm2_tsnap_acc`.
- **Touched:** `avm2_render_node`.
  - The snap is applied after `Mat world = mat_mul(parent_world, &local)`.
  - The state is saved there and restored at the function's single exit. There is no `return` after that point.
- **What it skips:**
  - the stage;
  - text nodes (`edittext` / `statictext`), which subtract the ancestors' accumulated snap;
  - anything under `g_avm2_filter_active` or `g_avm2_tsnap_off`;
  - `avm2_is_bitmap_cached` nodes, which open an off-subtree.

**`ruffle-tests/render_canary_tests.txt`:** EOF members `regression/lowq_tsnap_tie_probe` (tier 1) and
`visual/blend_modes/add` (tier 2).

**Not touched:** `swf_core.c`, `tag_stubs.c`, `NO_GRAPHICS` arms, `SWFRecomp/` and `verify_output.py`. No new TU.
No-graphics parity was checked: the probe and `blend_modes/add` trace PASS without `--mode=graphics`.

**Sibling coordination:**
- **w2-pixel-gaps-land:**
  - Cached and filtered entries and their whole subtrees are excluded from TSNAP. A cacheAsBitmap LOW snap they add in
    `cab_snap_*` therefore cannot be snapped twice by TSNAP.
  - Their `tf_glyph_quarter_snap` LOW arm is unaffected: text is excluded, own and inherited.
  - Their `render_webgpu_stroke_snap` Drawing-API centres: AVM1 Drawing-API holders draw through
    `actionRenderMCDrawingsInlineEntryCx`, with their own transform, so TSNAP does not move them.
- **n-seam-caps:** no stroke-builder edits.

## 2. Results

**Fidelity (this box = CI).** Clean-master local renders, from a `git apply -R` leg, are byte-identical to CI
`ruffle-image-results` actuals on `blend_modes/add`, `simple_shapes/masks`, `avm2_button_scroll_rect` and
`sprite_with_frames`. The kill-switch leg is byte-identical to master on `blend_modes/add` and on the probe.

### 2.1 Headline per-test table (same box, clean master vs patch)

| test | master → patch, outliers vs golden | vs FP32 (ch), master → patch | golden provenance |
|---|---:|---:|---|
| `regression/lowq_tsnap_tie_probe` (NEW) | 5 102 → **3 152** (fail → **pass** at the 3 152 budget) | rows 0–3 px: 680 → **0** | FP32 LOW capture |
| `visual/blend_modes/add` | 5 347 → 712 | 15 300 → 5 434 | flash_fixes FP32 |
| `visual/blend_modes/alpha_no_layer` | 9 586 → 2 225 | 136 746 → 133 166 (s28 LOW png) | flash_fixes FP32 |
| `visual/blend_modes/darken` | 6 385 → 1 067 | 15 067 → 9 085 | flash_fixes FP32 |
| `visual/blend_modes/difference` | 8 154 → 818 | 25 440 → 11 351 | flash_fixes FP32 |
| `visual/blend_modes/erase_no_layer` | 9 320 → 2 141 | 135 386 → 131 614 (s28 png) | flash_fixes FP32 |
| `visual/blend_modes/hardlight` | 9 815 → 1 512 | 71 934 → 62 313 | flash_fixes FP32 |
| `visual/blend_modes/invert` | 10 211 → 1 692 | 22 980 → 10 772 | flash_fixes FP32 |
| `visual/blend_modes/layer_alpha` | 11 067 → 4 268 | 124 883 → 120 393 (s28 png) | flash_fixes FP32 |
| `visual/blend_modes/layer_erase` | 9 032 → 2 033 | 123 679 → 119 038 (s28 png) | flash_fixes FP32 |
| `visual/blend_modes/lighten` | 6 915 → 681 | 13 827 → 6 819 | flash_fixes FP32 |
| `visual/blend_modes/multiply` | 6 639 → 1 090 | 20 387 → 14 205 | flash_fixes FP32 |
| `visual/blend_modes/overlay` | 8 791 → 1 424 | 85 697 → 78 666 | flash_fixes FP32 |
| `visual/blend_modes/screen` | 5 695 → 699 | 21 498 → 13 135 | flash_fixes FP32 |
| `visual/blend_modes/subtract` | 6 026 → 722 | 16 891 → 5 919 | flash_fixes FP32 |
| `visual/simple_shapes/layers` | 1 754 → 1 727 | 1 754 → 1 727 | flash_fixes FP32 |
| `visual/opaque_background` | 1 956 → 1 956 (moved, 1 952, only before the cab-subtree exclusion) | unchanged | flash_fixes FP32 |
| `visual/avm2_button_scroll_rect` | 234 → 45 | 288 → **15** | not Flash; s28 LOW capture |
| `visual/simple_shapes/masks` | 2 630 → 3 128 | 4 398 → 3 248 | not Flash; s28 LOW capture |
| `visual/simple_shapes/masks_equal_clipdepth` | 2 630 → 3 128 | 4 398 → 3 248 | not Flash; s28 LOW capture |
| `visual/cache_as_bitmap/scroll_rect` | **pass 0 → pass 0** (render == golden, 0 ch) | — | Flash (s27) |
| `visual/filters/*` ×10 (all but `bevel`) | unchanged counts (`glow` checked byte-identical) | — | — |
| `visual/filters/bevel` | 58 894 → 61 149 | 291 252 → 290 327 (toward) | not Flash; s28 LOW capture |
| `avm2/sprite_with_frames` | 4 944 → 4 944, byte-identical | — | Flash (s27) |
| `avm2/symbol_class_conflict` | unchanged, byte-identical on the half-even leg (half-down: 449 → 1 169 vs FP32) | — | s28 LOW capture |
| `visual/drawing_api/drawing_order` | 6 915 → 3 683 | 12 784 → 12 784 | not Flash; s28 LOW capture |

On `drawing_order` the outer 3-px band moves up by 1 px, with zero net change vs FP32: its top band moves away and its
bottom band moves toward. The remaining gap is the band rule (§3.3).

### 2.2 pass → fail (all on non-Flash or near-Flash goldens; all toward the s27 FP32 capture)

| row | outliers vs golden, master → patch | vs the Flash capture at the test's tolerance, master → patch |
|---|---:|---:|
| `from_shumway/acid/acid-color` output (gate list; "near Flash") | 0 → 675 | 675 → **0** |
| `from_shumway/acid/acid-color` frame1 | 0 → 2 | 2 → **0** |
| `from_shumway/acid/acid-gc` (not Flash) | 0 → 3 792 | 3 792 → **0** |
| `from_shumway/acid/acid-gradient-1` (not Flash) | 0 → 384 | 384 → **0** |
| `from_shumway/acid/acid-large` (not Flash) | 0 → 108 639 | 178 720 → 138 478 |

### 2.3 Other fail → fail moves

All are graded vs an FP32 capture where one exists:
- **Toward:**
  - `acid-child` (774 → 198);
  - `acid-child` frame5 (504 → 381);
  - `acid-blend`;
  - `acid-color-0`;
  - `acid-gradient-2`.
- **Away:**
  - `acid-scale` (2 660 → 2 726 ch vs capture);
  - `avm2/stage3d_texture` (vs golden 2 840 → 4 042 outliers; vs the s28 png 622 542 → 622 542, flat);
  - `regression/avm2_layer_group_alpha` 2 815 → 10 987;
  - `regression/avm2_layer_group_erase` 2 702 → 10 924.

The two `layer_group` rows are this project's own Ruffle-exporter goldens. The exporter renders HIGH only, so those
goldens are not Flash and not LOW. They are unpriceable without a capture: LOCAL ORACLE REQUEST 2.

### 2.4 The priced loss: `from_shumway/acid/acid-stroke-0` (Flash golden, failing), 7 173 → 7 542 outliers

Per-placement breakdown (px ≠ golden, master → patch):
- **The whole net loss is two placements of id 10:**
  - depth 49: (2, 0, −1.41, 1.41, 502.05, 361.3), 33 → 262;
  - depth 59: (2, 0, +1.41, 1.41, 593.75, 361.3), 1 → 261.
  - Shape 9 inside them is a 1-px stroke with BOTH noHScale and noVScale.
- **The same shape and matrix elsewhere moves toward:** at depth 109 (933.55, 375.95), 323 → 262.
- **Every other placement nets toward Flash:** −10 … −144 px per object, e.g. depths 45, 51, 53, 55 and 105.
- After the snap, all three id-10 shear instances land on the same 261–262 px error, i.e. the same integer-position
  render.
- Flash draws the (.05, .3) and (.75, .3) instances where our UNSNAPPED hairline path puts them. So the Flash rule for
  1-px noScale strokes is not "snap the translation, then stroke". The hairline snap (`hairline_restage`) evaluated on
  the unsnapped translation is what matches.
- **Completion mechanism (owner: stroke path, not TSNAP):**
  - **Hand the shader the unsnapped translation.** The ancestors' accumulated snap (`g_tsnap_acc`, twips) can ride the
    free z-column slots `transform[2].x/.y`, which multiply z = 0. Then let the 1-px / noScale hairline draws subtract
    it.
  - **Or exempt hairline-only shapes from inheriting.** That needs one more FP32 cell, a 1-px noScale square under
    shear at several fractions, to fit.

## 3. 45° stroke width and the 3-px band at LOW (brief step 2): measured HOLD, nothing implemented

The golden is the FP32 probe. "Ours" is the TSNAP leg; rows 4–5 do not depend on TSNAP, since every placement there is
an integer or an even + .5.

### 3.1 Static 45° X, row 4 (widths 1–10, integer placement)

The span is the horizontal run per scanline on the "\" diagonal at local y = 12, away from the crossing and the caps.
Ink is the count of non-white px in the 40×40 cell.

| w (px) | 1 | 2 | 3 | 4 | 5 | 6 | 8 | 10 |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| Flash span | 1 | 2 | 3 | 4 | **4** | **8** | 12 | 14 |
| ours span | 1 | 3 | 4 | 5 | 8 | 8 | 12 | 15 |
| w·√2 (perpendicular model) | 1.41 | 2.83 | 4.24 | 5.66 | 7.07 | 8.49 | 11.3 | 14.1 |
| Flash ink | 56 | 110 | 163 | 216 | **216** | **460** | 698 | 918 |
| ours ink | 56 | 172 | 226 | 288 | 450 | 472 | 708 | 896 |
| px ≠ Flash | 108 | 62 | 65 | 72 | 234 | 12 | 14 | 62 |

- **Two regimes.** From w = 1 to 4, Flash's span equals w: a minor-axis pen, at about 54 px of ink per px of width.
- **w = 4 and w = 5 are byte-identical in Flash.**
- **At w ≥ 6, Flash is the polygon model.** Flash w = 6 is row-for-row identical to OUR w = 5, and w = 8 is ours ±1 cap
  pixel.
- The thin regime also sits 1 px left of ours at w = 1 and 3, an x/y tie offset.
- So the LOW stroker switches algorithm between 5 and 6 px of device width, and the thin pen is clamped, or quantised,
  to 4 at w = 5.

### 3.2 Row 5 cells

| cell | Flash | ours | px ≠ |
|---|---|---|---:|
| c0 / c1: 3-px stroke + fill rect 6..34, at +.5 and +0 | bands L [5,8), R [32,35), T [5,8), B [32,35): 30 px/row | L [5,8), R **[33,36)**: 31 px/row | 112 each |
| c2: acid `para41` (2, 0, −1.414, 1.414), 4-px square | rows 12 12 12 22 22 20 | 12 12 12 22 22 21 | 6 |
| c3: acid `para51` (2, 0, +1.414, 1.414) | 31 32 32 32 32 31 | 31 31 29 30 30 30 | 24 |
| c4: acid `rot81` (.707, .707, −1.414, 1.414) | 14 15 16 16 16 15 | 16 16 16 17 17 17 | 19 |
| c5: AVM1 Drawing-API `lineStyle(5)` 45° | **4** px/row | 8 px/row | 147 |
| c6 / c7: drawRect 5.5..25.5, Drawing API / static | 20 px/row, ink 400 | 20 px/row, ink 380 | 58 each |

- c5 (Drawing-API, w = 5) shows the same thin-regime 4-px span as static w = 5 (row 4 c4) and as `drawing_order`'s two
  w = 5 lines. **The Drawing API and the timeline share the LOW stroker.** Both Drawing-API cells draw in Flash, so the
  fixture trap check is clean.
- The acid-matrix cells are close in our build: 6, 24 and 19 px. The large `acid-stroke-0` gaps w1 measured are the
  thin-regime / 45° question again.
- c6 / c7: our 20×20 rect is missing one 20-px row or column, and the Drawing-API and static legs are identical in both
  renderers. It is a vertex-.5 fill tie (`ceil(e − ½)` vs Flash's rule), not an API difference. It is a lead for the
  LOW fill tie rule.

### 3.3 The 3-px rect band: LOW-only (answers the brief's HIGH question)

Bands measured on the scanline y = 300 and on the column x = 200:

| `drawing_order` band | Flash HIGH (`drawing_order.high.png`) | Flash LOW (s28 recapture) | ours LOW, master |
|---|---|---|---|
| outer L / R | [44,47) [461,464) | [45,48) [460,463) | [44,47) [461,464) |
| outer T / B | [75,78) [416,419) | [75,78) [414,417) | [75,78) [416,419) |
| inner L / R | [144,147) [353,356) | [145,148) [352,355) | [144,147) [353,356) |
| inner T / B | [163,166) [334,337) | [164,167) [333,336) | [163,166) [334,337) |

**Our LOW bands are Flash's HIGH bands exactly.** The inset is a LOW-only rule, so it belongs to the LOW ladder, not to
the N ladder's HIGH snap rule (n-seam-caps / n-stroke-snap are not implicated).

**Fitted rule (12 of 12 band edges), "right-of-travel pen".**
- **Pen.** The LOW 3-px pen covers pixels [p − 1, p + 1].
- **Up / right travel:** p = rhe(c), where rhe = round half to even.
- **Down / left travel:** p = rhe(c) − 1.
- **Inputs.** Both rects are clockwise in y-down, and c is the world centreline after TSNAP.
- **Cells fitted:**
  - probe c0 / c1 (c = 6 / 34);
  - all four inner-rect edges (145.75 / 354.25 / 164.75 / 335.25);
  - all four outer-rect edges. TSNAP takes (253.5, 246.5) to (254, 246), so c = 45.5 / 462.5 / 75.5 / 416.5 and p = 46 /
    461 / 76 / 415.
- **What decided it.** The outer rect fits ONLY with half-even ties; half-down misses its left and bottom edges by 1 px.
  This is independent evidence for TSNAP's tie rule.

**Verdict: band rule = LEAD, not implemented here.**
- **Why not here.** It is fitted on one width (3 px) only. Our thin-stroke snap is HIGH-calibrated for u ≤ 4/8/12, so a
  LOW arm needs the other widths first.
- **Ownership conflict.** Its code (`render_webgpu.c` `hairline_restage` / `render_webgpu_stroke_snap`) is being edited
  by w2-pixel-gaps-land (Drawing-API centres) and by the local n-seam-caps session (stroke builders).
- **45° width: HOLD.** No model fits row 4's regime switch and the w = 5 clamp together with the acid cells. Brief step 2
  says to prototype only what fits all cells.
- **Completion mechanism:** LOCAL ORACLE REQUEST 1. Owner when it lands: the `render_webgpu.c` stroke path, LOW arm
  gated `MSAA_SAMPLES == 1`, in coordination with n-seam-caps.

## 4. EXPECTED-FLIP LEDGER (graphics CI; check by name)

**Trace axis: no moves.** All 257 `quality = "low"` image tests keep their CI baseline trace status (251 pass,
6 `ruffle_matched`). Nothing outside quality = low can move, since the HIGH build is
unchanged by construction.

**Pixel axis, status moves:**
- **new pass:** `regression/lowq_tsnap_tie_probe` [output] (3 152 / 3 152);
- **pass → fail:**
  - `from_shumway/acid/acid-color` [output] 675 and [frame1] 2;
  - `from_shumway/acid/acid-gc` [output] 3 792;
  - `from_shumway/acid/acid-gradient-1` [output] 384;
  - `from_shumway/acid/acid-large` [output] 108 639.

  All are toward Flash (§2.2). If the coordinator applies the §5 flash_fixes swaps, the first four become passes.

**Pixel axis, outlier-count moves (fail → fail),** exact local values; CI should match to the outlier:
- `blend_modes/add` 712, `alpha_no_layer` 2 225, `darken` 1 067, `difference` 818, `erase_no_layer` 2 141,
  `hardlight` 1 512, `invert` 1 692, `layer_alpha` 4 268, `layer_erase` 2 033, `lighten` 681, `multiply` 1 090,
  `overlay` 1 424, `screen` 699, `subtract` 722;
- `simple_shapes/layers` 1 727; `simple_shapes/masks` and `masks_equal_clipdepth` 3 128;
  `avm2_button_scroll_rect` 45; `drawing_api/drawing_order` 3 683; `filters/bevel` 61 149;
- `avm2/stage3d_texture` 4 042;
- `from_shumway/acid/`: `acid-blend` 1 105, `acid-child` 660 and frame5 309, `acid-color-0` 19 816, `acid-gradient-2`
  2 947, `acid-scale` 9 482, `acid-stroke-0` 7 542;
- `regression/avm2_layer_group_alpha` 10 987, `regression/avm2_layer_group_erase` 10 924.

Anything else moving on the image axis is NOT this patch.

## 5. flash_fixes candidates (the coordinator adds the entries; I edited no `fixes.json`)

| row | golden → proposed | evidence |
|---|---|---|
| `from_shumway/acid/acid-color` output and frame1 | s27 `golden-provenance/from_shumway__acid__acid-color__{output,frame1}.png` | after TSNAP, ours == capture at **0 channels** |
| `from_shumway/acid/acid-gc` output | s27 `…acid-gc__output.png` | ours == capture, 0 ch (master 3 792) |
| `from_shumway/acid/acid-gradient-1` output | s27 `…acid-gradient-1__output.png` | 0 outliers at the test's tol 1 (1 536 ch at t0) |

**Caveat.** These are s27 "draw" captures, taken before the 2026-11-25 LOW-stub fix: Flash's default quality, frame1
noted "@ quality high". A byte-exact match with our LOW render means the content renders AA-free in Flash, but
confirm it with a LOW recapture before swapping: LOCAL ORACLE REQUEST 3.

No RvF entries: no Ruffle≠Flash difference was newly confirmed beyond these golden candidates.

## 6. Regression suite and canary

- **`regression/` LOW rows, all in the gate run:**
  - unchanged: `lowq_fill_edges`, `lowq_gradient_orient_probe`, `lowq_sample_point_probe`,
    `layer_group_in_add_alpha`, `layer_group_overlap_{alpha,erase}`, `avm2_layer_group_overlap_alpha`;
  - moved: `avm2_layer_group_{alpha,erase}` (§2.3);
  - new: `lowq_tsnap_tie_probe`, which passes.
- **HIGH regression / canary:** unchanged by construction (§Verdict 7). The full 199-test capture/compare was not run: by
  the preprocessor proof it cannot move, and it would cost about 2.5 h of the box.
- **Canary:** two LOW members appended at EOF (§1).

## 7. Refutations / premise attacks

- **"Round half down" (w1) is refuted for .5-on-odd placements.** The probe only had even + .5, and half-even is what
  fits `drawing_order`. Half-down also moved `symbol_class_conflict` away from FP32 (449 → 1 169 ch); half-even leaves
  it byte-identical.
- **"Layers are not the factor" (w1) still holds**, but the real w1 gate killer was SCOPE.
  - World snap shifts each deep child by its own fraction. Per-level gives `blend_modes/add` 5 347 → 712.
  - w1's filters / cab losses came from snapping inside cached subtrees, which is now excluded.
- **"TSNAP does not touch text" was true of the shader prototype only by accident.** A CPU per-level snap moves text
  through its snapped parent. Flash (`sprite_with_frames`) says text composes unsnapped, so it is excluded explicitly.

## New unclaimed leads

- **LOW 3-px band rule:** right-of-travel pen, ties to even, 12 of 12 edges (§3.3). Implement after REQUEST 1 gives the
  other widths. Owner: the stroke path.
- **LOW thin-stroke regime:** w ≤ 5 is a minor-axis pen clamped to 4 at w = 5, and w ≥ 6 is the polygon (§3.1).
  `drawing_order`'s two w = 5 lines (~1.9 k px) and probe c5 live here.
- **1-px noScale hairlines under a TSNAP'd parent** should use the unsnapped translation (`acid-stroke-0`, §2.4).
- **LOW fill .5-vertex tie:** probe c6 / c7 is one row or column short in ours, both through the Drawing API and as a
  static shape.
- **`acid-large`** stays 138 k off its capture after TSNAP. Not investigated.

## LOCAL ORACLE REQUESTS

1. **FLASH: a new LOW stroke probe, image, tick 1, direct pinned. The SWF sets `_quality = "LOW"` itself.** Not built
   here; the generator pattern is `regression/lowq_tsnap_tie_probe/create_test_swf.py`. Cells:
   - static 45° strokes at w = 4.5 / 5 / 5.25 / 5.5 / 5.75 / 6, and the same at 30° and 60°;
   - w = 5 at 0° / 26.6° / 45°;
   - axis-aligned rect bands at W = 1 / 2 / 4 / 5, centrelines at c + {0, .25, .5, .75}, in both travel directions;
   - .5 placements on ODD and on EVEN integers, which confirm ties-to-even for TSNAP;
   - a 1-px noScale square under the `acid-stroke-0` shears at translation fractions (.05, .3), (.55, .95) and
     (.75, .3).
2. **FLASH: `regression/avm2_layer_group_alpha` and `regression/avm2_layer_group_erase`, image, LOW.** Their goldens are
   Ruffle-exporter HIGH. Both move ~8 k outliers under TSNAP; the capture prices the move.
3. **FLASH: `from_shumway/acid/acid-color` (output, frame1), `acid-gc` and `acid-gradient-1`, image, LOW recapture.**
   This confirms the §5 golden swaps; ours is expected to equal the capture at 0 ch.
