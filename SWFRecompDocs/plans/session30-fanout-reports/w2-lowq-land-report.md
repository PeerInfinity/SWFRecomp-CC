# s30 w2-lowq-land: LOW tie rules A + C + the x half landed; the "+2 px" glyph-probe offset is EditText layout

Slot `w2-lowq-land`, wave 2 (implementation). Branch `fanout/w2-lowq-land`, base `origin/master` `41b9c2084`
(runtime = s29 FINAL code `2d40d3799` + docs/oracles).

**The box:**
- Cloud, Dawn on lavapipe. `SETUP_STATUS`: apt OK, Pillow OK, Dawn OK.
- Corpus: `download_tests.sh visual from_gnash from_shumway avm2 text fonts avm1` (2026-11-27); flash_fixes APPLIED
  68 + 11. The script prints no upstream SHA.

**Fidelity:**
- **CI fidelity is proven on 4 rows.** Clean-master local renders are md5-identical to the CI actuals on
  `origin/ruffle-image-results`: `morph_test1` frame2, `blend_modes/layer_alpha`, `filters/bevel` and
  `simple_shapes/overlaps`. Local verdicts are CI-grade.
- **Every A/B is a same-binary env-leg A/B.** One build per row, legs via kill switches. The all-off leg M is
  md5-identical to a clean-`origin/master` build on 13 renders: `morph_test1` ×6, both glyph probes, `acid-stroke-0`,
  `layer_alpha`, `bevel`, `overlaps` and `style_changes_in_html`.

## New files

- `SWFRecompDocs/plans/session30-fanout-reports/w2-lowq-land-report.md` (this file).
- `SWFRecompDocs/plans/session30-fanout-reports/w2-lowq-land.patch`: the deliverable, `git diff origin/master -- SWFModernRuntime
  ruffle-tests/render_canary_tests.txt`, plus the two new fixture dirs and the RvF `.md` (binary, 18 files).
  `git apply --check -R` was verified on the branch, and `git apply --check` on a clean `origin/master` worktree.
- **Two new regression fixtures**, FP32 LOW goldens:
  - `ruffle-tests/tests/swfs/regression/lowq_glyph_probe_df2/`: `test.swf`, `test.toml`, `output.txt`,
    `output.expected.png` (= `w1-local-oracles/w1-lowq-residues/df2/fp32.lnx.low.png`) and `create_test_swf.py` (the
    w1 generator; it builds both SWFs byte-identically).
  - `ruffle-tests/tests/swfs/regression/lowq_glyph_probe_df3/`: `test.swf`, `test.toml`, `output.txt`,
    `output.expected.png`, `GENERATOR.txt`.
- `SWFRecompDocs/plans/session30-fanout-reports/w2-lowq-land-fixtures/`:
  - **`lowq_adv_flags_probe/`, for FLASH REQUEST 1:** `create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`,
    and our renders `ours_ceil_off.png` / `ours_ceil_on.png`.
  - **`ledger/`:**
    - `gate_pass1.txt`: all 148 rows, 7 legs;
    - `gate_pass2_final.txt`: 95 rows, FINAL code, 7 legs;
    - `main_only_probe.txt`.
  - **`tools/`:** `gate.py` (the per-row env-leg gate), `rerun.py`, `probemodel.py` (the w1 CPU glyph model re-scored
    on the probe with the corrected layout), `rows.py`, `swfls.py` (a mini SWF tag lister).
- **Edited:** `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`, with the ALPHA painted-0
  entry appended at EOF.
- **Edited:** `ruffle-tests/render_canary_tests.txt`, with `regression/lowq_glyph_probe_df3` appended at EOF (it covers
  the new text-layout class).

## Verdicts (lead)

**Status flips (pixel axis, FP32 goldens):**
- `visual/simple_shapes/gradients/gradients` **fail → PASS** (F3 → P0).
- The `from_gnash/misc-ming.all/morph_test1` **[frame1] comparison fail → PASS** (193 → 0). The test stays FAIL, since
  frames 2–6 remain at 198.

**Rest of the ledger:**
- **0 pass → fail** on 148 + 95 gate rows (the latter including 38 extra LOW canary members) and on the 12-row HIGH md5
  A/B.
- **Trace axis untouched.** Render-only change; the headline rows PASS trace in both modes.

1. **GO: A, the TSNAP tie on the LOCAL offset from the snapped parent** (w1 prototype A, unchanged).
   - Kill switch `SWF_LOWQ_TSNAP_LOCAL=0`.
   - The same 6 rows move toward FP32 as in w1: `layer_alpha` / `layer_erase` / `alpha_no_layer` / `erase_no_layer`
     plus the two regression twins.
2. **GO: C AND the x half land together, as one symmetric vertex-tie rule.** An exact-centre vertex tie is exclusive
   at the top / left edge and inclusive at the bottom / right edge: the vertex is biased by +1/256 px on both axes.
   - **The x half REMOVES C's priced cost.** C alone moved the 14 FP32 `blend_modes/*` rows +397 (all 14 were already
     failing; no Flash PASS was lost). With x as well they sit at master ±16 (§2).
     - Per row: `add` 712 → 725 under C, 710 with x; `invert` 1692 → 1740 → 1698.
   - **Three exemptions**, each measured and with its own kill switch:
     - **(a) Glyph / text soups** (`render_webgpu_draw_text_tris`, style bit 16), now set from the TEXT callers only.
       In w1 every `render_webgpu_draw_tris` soup, including the AVM1 drawing API and AVM2 Graphics, was exempt.
     - **(b) A bitmap-cached subtree whose blit snap moved it** (`cab_tie_exempt`, transform m[10] = 2).
       - It fixes the w1 HOLD row `visual/cache_as_bitmap/scroll_rect`: it stays **PASS** (it was 96 under the x half).
       - Cause: the stroke bounds −0.5 px snap the cached subtree +0.5 px, which puts the fill's right edge on 229.5,
         a tie Flash never sees.
       - Kill switch `SWF_LOWQ_TIE_CAB_EXEMPT=0`.
     - **(c) The x of LOW-rule stroke vertices** (`lowq_stroke_place` output, style bit 17).
       - The x bias moved `acid-stroke-0`'s 1-px "\\" diagonals 1 px right of Flash (+101 channels).
       - Kill switch `SWF_LOWQ_TIE_X_STROKE=1`.
   - **Kill switches:** `SWF_LOWQ_TIE_EPS=0` (the whole rule) and `SWF_LOWQ_TIE_EPS_X=0` (y only = w1's C).
   - **Flash-golden net (pass 2, X vs master):**
     - `morph_test1`: −193 / −1203 ×4 / −400;
     - 14 blend rows + 2 twins: −3224;
     - `acid-stroke-0` −381, `acid-shapes-testing` −36, `graphics_gradients` −7;
     - `nested_rotation` +9 (FP32, already failing);
     - every FP32 regression probe toward FP32.
   - **Priced losses (all on non-Flash / untestable goldens):** `visual/filters/*` (bevel +6184, bevel_inner +4558,
     drop_shadow_angles +2903, displacement_map +2217, glow +1713, drop_shadow +531), `simple_shapes/overlaps` +590,
     `acid-scale` +480, `acid-child` +204, `doubleAndRegister` +54, and 6 AVM2 rows +2…+6. See the ledger, §3.
     **FLASH REQUEST 2** grades them.
3. **The LOW glyph rule: the coordinator's "+2 px" is NOT a glyph-raster offset. It is EditText LAYOUT** (§1).
   - The ink bounding boxes of ours and FP32 are identical. FP32's glyphs drift right along each line because FP32
     lays out the probe's fields differently. Two rules were found:
   - **(i) GO: field-local pen** (`tf_glyph_quarter_snap` LOW arm; kill switch `SWF_TF_LOW_PEN_LOCAL=0`).
     - **The rule:** the field's translation snaps half-even, then each pen rounds half-even on its FIELD-LOCAL offset
       (the A rule one level down).
     - **FP32 df3 evidence:** fields at 2 / 2.25 / 2.5 render identically and 2.75 renders as 3. 'W' pens at local
       61.5 / 180.5 / 299.5 / 418.5 go to 62 / 180 / 300 / 418 under either origin.
     - **Probe:** df3 15 921 → **9 024** channels; df2 56 139 → **52 527**.
     - **0 moves on the five named rows.**
     - **One priced loss:** `text/style_changes_in_html` +1380. Its golden is not Flash; **FLASH REQUEST 2**.
   - **(ii) HOLD (shipped default OFF, `SWF_TF_LOW_ADV_CEIL=1` enables): DefineFont2 advances round UP to a whole px.**
     - **For:** FP32's df2 12 px steps are exactly ceil(adv): 8,7,8,8,7,8,8,12,10,8,4,8,8,8. With it, df2 goes
       56 139 → **12 891** and every ink start matches FP32 on all 10 rows. It also fits `BeginBitmapFill` (Flash
       golden) 894 → **393**.
     - **Against:** **FP32's `morph_test1` xtrace field (same font, 12 px) does NOT ceil.** Its glyph starts match the
       fractional layout exactly, and `ceil` takes frames 2–6 198 → 918.
     - The two field kinds differ in WordWrap / NoSelect / HasTextColor / variable binding. **FLASH REQUEST 1**
       (`lowq_adv_flags_probe`) isolates the switch.
   - **(iii) HOLD: chords vs curves** (§1.3). Re-scored on the correctly laid-out probe:
     - chords win at 12 px (model 36 vs 133 px per row; GPU 99);
     - they are neutral at 18–24 px and lose clearly at ≥ 36 px;
     - a device tolerance of ≈0.25–0.5 px fits.
     - The gain left on the probe is ≈ −300 px (−60 per 12-px row). The recompiler change is not landed; its completion
       mechanism is in §1.3.
   - **Premise refuted:** **`place_object_test` and `shape_test` are NOT FP32 goldens.**
     - s27 `golden-provenance.md` gives "not FP32 on either OS, 5 209 px", with the swap deferred.
     - So w1's chord / pen pricing on them (2604 → 888) was graded against a Ruffle golden. `morph_test1`'s text line is
       the FP32 text oracle among the five rows.
4. **The x half: landed (see 2).**
   - The prize: **`morph_test1` frame1 → PASS**, frames 2–5 1401 → **198**, frame6 598 → **198**.
   - **`scroll_rect`'s 96 is found and fixed** (2b).
5. **RvF entry written** (ALPHA painted-0; `RUFFLE_VS_FLASH_DIFFERENCES.md` EOF). **Implementation: NOT done.** M does
   not fit the remaining budget after the tie work. The completion mechanism is in the entry.

## Per-test before / after (same box; master = clean `origin/master`, md5-proven equal to leg M)

Outliers from `verify_output.compare_images` against each row's golden. P = pass.

| row | golden | master | patch |
|---|---|---:|---:|
| `visual/simple_shapes/gradients/gradients` | FP32 (ff) | F3 | **P0** |
| `from_gnash/misc-ming.all/morph_test1` frame1 | FP32 (ff) | F193 | **P0** |
| `morph_test1` frame2 / 3 / 4 / 5 | FP32 (ff) | F1401 each | **F198** each |
| `morph_test1` frame6 | FP32 (ff) | F598 | **F198** |
| `visual/blend_modes/layer_alpha` | FP32 (ff) | F4268 | F3731 |
| `visual/blend_modes/layer_erase` | FP32 (ff) | F2033 | F1509 |
| `visual/blend_modes/alpha_no_layer` | FP32 (ff) | F2225 | F1660 |
| `visual/blend_modes/erase_no_layer` | FP32 (ff) | F2141 | F1589 |
| `regression/avm2_layer_group_alpha` / `_erase` | FP32 | F4268 / F2033 | F3731 / F1509 |
| `blend_modes/add` / `darken` / `difference` / `hardlight` | FP32 (ff) | 712 / 1067 / 818 / 1512 | 710 / 1069 / 812 / 1521 |
| `blend_modes/invert` / `lighten` / `multiply` / `overlay` | FP32 (ff) | 1692 / 681 / 1090 / 1424 | 1698 / 679 / 1092 / 1440 |
| `blend_modes/screen` / `subtract` | FP32 (ff) | 699 / 722 | 694 / 717 |
| `from_shumway/acid/acid-stroke-0` | Flash | F3413 | F3032 |
| `from_shumway/acid/acid-shapes-testing` | Flash | F9219 | F9183 |
| `avm2/graphics_gradients` | Flash | F296 | F289 |
| `avm2/graphics_simple_shapes` | Flash | F116 | F116 |
| `visual/cache_as_bitmap/scroll_rect` | FP32 | P0 | **P0** (x half without 2b: F96) |
| `visual/cache_as_bitmap/nested_rotation` | FP32 (ff) | F96 | F105 |
| `visual/edittext/edittext_underline` | Flash | P0 | P0 |
| `visual/simple_shapes/text_field_mask` | FP32 (ff) | F1336 | F1336 |
| `from_gnash/misc-ming.all/place_object_test` | **not Flash** | F2604 | F2604 |
| `from_gnash/misc-ming.all/shape_test` | **not Flash** | F9709 | F9709 |
| `from_gnash/misc-ming.all/BeginBitmapFill` | Flash | F894 | F894 (ceil HOLD: 393) |
| `regression/lowq_tsnap_tie_probe` | FP32 | P1250 | P854 |
| `regression/lowq_stroke_probe` | FP32 | P5745 | P5370 |
| `regression/lowq_gradient_orient_probe` | FP32 | P915 | P774 |
| `regression/lowq_sample_point_probe` | FP32 | P1225 | P1111 |
| `regression/lowq_glyph_probe_df2` (new) | FP32 | 56139 | **P52527** (budget = measured) |
| `regression/lowq_glyph_probe_df3` (new) | FP32 | 15921 | **P9024** (budget = measured) |

## EXPECTED-FLIP LEDGER (for the CI grading run)

**Image axis (graphics, `images=true`):**
- **flips:**
  - `visual/simple_shapes/gradients/gradients` F → **P**;
  - the `from_gnash/misc-ming.all/morph_test1` frame1 comparison F → P (row stays F).
- **new rows:** `regression/lowq_glyph_probe_df2` and `regression/lowq_glyph_probe_df3`, both PASS at their budgets.
- **moved, status unchanged:**
  - toward Flash: the rest of the per-test table;
  - **away, priced:**
    - `visual/filters/bevel` / `bevel_inner` / `displacement_map` / `drop_shadow` / `drop_shadow_angles` / `glow`;
    - `visual/simple_shapes/overlaps`, `text/style_changes_in_html`;
    - `from_shumway/acid/acid-scale` / `acid-child` / `acid-text-6`[frame5];
    - `from_shumway/doubleAndRegister`;
    - `avm2/displayobject_scrollrect` / `loader_events` / `loader_loadbytes_events` / `mouse_pick_dobj_mask` /
      `mouse_pick_non_interactive_dobj_mask`;
    - `visual/drawing_api/fills_and_lines`;
    - `visual/cache_as_bitmap/nested_rotation`.
- Everything else at quality LOW is byte-identical in pass 1 or pass 2. Everything at HIGH is preprocessor-dead or a
  proven no-op (12-row md5 A/B identical).

**Trace axis: no expected moves.** The change is render-only, and `place_object_test` / `morph_test1` /
`text_field_mask` PASS trace in no-graphics and graphics before and after.

**Mode:** graphics. The no-graphics build only compiles the new stubs (`render_stub.c`, `renderer.h`); no no-graphics
behaviour changed.

## 1. The glyph probe

### 1.1 The "+2 px" is layout

- **The data** (`tools/rows.py`): our ink bbox = FP32's (x 8..472, y 8..452). Per row, the first glyph matches and the
  drift grows along the line, so a global dx = +2 is just the best average.
- **df2, 12 px, field x = 10:**
  - FP32 ink starts: 13, 21, 28, 36, 44, 51, 59, 67, 79, 89, …
  - ours: 13, 20, 27, 34, 41, 48, 55, 63, …
  - The FP32 steps are ceil of the DefineFont2 advances at 12 px (627 / 563 / 630 / … em-units → 7.35 / 6.60 / 7.38 px
    → 8 / 7 / 8).
- **df3, 64 px 'W'** (advance 59.5 px): FP32 pens are integer and alternate ±0.5, consistent only with half-even
  rounding of the FIELD-LOCAL pen after the field origin snaps.

### 1.2 Per-row score

px > 2 grey vs the FP32 LNX draw() capture; `pen` = field-local pen; `ceil` = DF2 ceil advance (HOLD):

| df2 row | master | pen | ceil | pen + ceil |
|---|---:|---:|---:|---:|
| 12 px +0 / .25 / .5 / .75 | 391 / 387 / 383 / 381 | | 99 / 99 / 139 / 101 | 99 / 99 / 99 / 101 |
| 18 / 24 / 36 px | 874 / 1636 / 2753 | | 220 / 698 / 1119 | 209 / 235 / 517 |
| 48 / 72 / 96 px | 5536 / 4517 / 2365 | | 1954 / 1991 / 653 | 1907 (baseline 1 px high: 562 aligned) / 557 / 653 |
| **total** | **18 713** | **17 509** | **6 803** | **4 297** |

- df3 total: 5 332 master → 3 008 with pen (ceil: no effect, em 20480).
- The **48 px row** keeps its whole baseline 1 px above FP32 under every rule tried (its field y is 187.5, its local
  baseline 46.53). It is not fitted.

### 1.3 Chords vs curves (re-score on the corrected layout; `tools/probemodel.py`)

w1 CPU model, df2, with layout = pen + ceil; px ≠ FP32 per row:

| variant | 12 px ×4 | 18 | 24 | 36 | 48 | 72 | 96 | sum |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| fine (n = 16) | 133 ×4 | 300 | 372 | 732 | 2272 | 1045 | 1060 | 6307 |
| chord (n = 1) | **36** ×4 | 168 | 242 | 605 | 2080 | 1669 | 2303 | 7211 |
| tol 0.25 px | 38 ×4 | 180 | 248 | 528 | 1908 | 867 | 1007 | **4888** |
| tol 0.5 px | 36 ×4 | 173 | 236 | 515 | 1919 | 924 | 1054 | 4965 |
| our GPU render (pen + ceil) | 99 ×4 | 209 | 235 | 517 | 1907 | 557 | 653 | 4297 |

- The model misses our GPU at ≥ 36 px (fine16 vs ours: 523–689 px); our recompiler flattens with Levien. So the model
  only ranks variants within a size.
- **Verdict:** Flash draws small text (max curve deviation ≲ 0.35 px) as chords. Large text is curved.
- **Completion mechanism (L–M):**
  - **Recompiler**, `SWFRecomp/src/swf.cpp`, the font glyph loop at ~:3006 (`font_glyph_entries`, which calls
    `interpretShape`):
    - emit a second, chord-flattened tessellation per glyph;
    - record its (offset, size) and the glyph's max quadratic deviation (em units) in the glyph_data slots 2–3.
    - Those slots hold path data for device-font fallbacks, so add a flag bit or two more slots, not a reuse.
  - **Runtime**, `textfield_glyph_render_cb_impl`, identity arm, LOW, `!device_font && !csm_advanced`: use the chord
    soup when `dev × scale ≤ 0.35–0.5 px`.
  - **Price it:** on the probe and the `morph_test1` text line (FP32), not on `place_object_test` (not Flash).
  - The ceil question (REQUEST 1) should be settled first, since the same rows carry both.

## 2. The tie rule: what each exemption buys (pass 2 legs)

All values are outliers. X = shipped; N = X without the cache exemption; S = X with the x bias on strokes; P = A + C
(y only); M = master.

| row | M | P | X | N | S |
|---|---:|---:|---:|---:|---:|
| `blend_modes/overlay` (the worst C row) | 1424 | 1468 | 1440 | 1440 | 1440 |
| `blend_modes/invert` | 1692 | 1740 | 1698 | 1698 | 1698 |
| `morph_test1` frame2 | 1401 | 804 | **198** | 198 | 198 |
| `cache_as_bitmap/scroll_rect` | P0 | P0 | **P0** | F96 | P0 |
| `acid-stroke-0` | 3413 | 3032 | **3032** | 3032 | 3133 |
| `avm2/graphics_simple_shapes` | 116 | 116 | 116 | 116 | 110 |
| `regression/lowq_tsnap_tie_probe` | 1250 | 1094 | **854** | 854 | 854 |
| `visual/filters/bevel` (not Flash) | 56326 | 62308 | 62510 | 62510 | 61870 |

- **Narrowing the text exemption to the text callers** (wave-2 note of w1) lets the AVM1 drawing API and AVM2
  Graphics take the rule: the tie probe goes 1148 → 1094 under C alone. It costs +2…+3 on 4 AVM2 rows
  (`loader_events`, `loader_loadbytes_events` not Flash; `mouse_pick_*` untestable).
- **The filter costs are NOT a layer-pass effect.** The bias off inside blend / filter layers (`main_only_probe.txt`,
  leg W) leaves `bevel` / `glow` / `bevel_inner` unchanged and `drop_shadow_angles` slightly worse. It comes from the
  main-pass source geometry, so it is an ordinary priced loss on non-Flash goldens.

## 3. Priced losses (not Flash-graded; X vs master)

| row | golden (s27 provenance) | master | patch | owner leg |
|---|---|---:|---:|---|
| `visual/filters/bevel` | untestable | 56326 | 62510 | C (+5982) + x (+202) |
| `visual/filters/bevel_inner` | untestable | 14874 | 19432 | C |
| `visual/filters/drop_shadow_angles` | not Flash | 39929 | 42832 | C |
| `visual/filters/displacement_map` | not Flash | 11357 | 13574 | C |
| `visual/filters/glow` | untestable | 16869 | 18582 | C |
| `visual/filters/drop_shadow` | untestable | 38135 | 38666 | C |
| `text/style_changes_in_html` | not Flash | 3278 | 4658 | field-local pen |
| `visual/simple_shapes/overlaps` | not Flash | 870 | 1460 | C (+138) + x (+452) |
| `from_shumway/acid/acid-scale` | not Flash | 10738 | 11218 | C |
| `from_shumway/acid/acid-child` | not Flash | 660 | 864 | C |
| `from_shumway/doubleAndRegister` | not Flash | 200 | 254 | C |
| `visual/cache_as_bitmap/nested_rotation` | **FP32 (ff)** | 96 | 105 | x |
| 6 AVM2 rows / `fills_and_lines` / `acid-text-6` f5 | not Flash / untestable | | +2…+8 | C |

- The s27 "untestable / not Flash" verdicts on these LOW rows were taken before 2026-11-25. Per the s28 trap they may
  have been HIGH captures, so **REQUEST 2** asks for FP32 LOW captures of the large rows.
- `nested_rotation` is the one FP32 loss: +9 on a failing row. It is a priced loss, not a lost pass.

## 4. Functions touched (all LOW-only unless noted)

- **`SWFModernRuntime/src/rendering/render_webgpu.c`:**
  - WGSL `LOWQ_SNAP_X` / `LOWQ_SNAP_Y` and `LOWQ_VS_POSITION`: `lq_eps` from stage m[10] (sign = x on), `lq_ey`,
    `lq_ex`; bits 16 / 17 and transform m[10] exemptions.
  - `lowq_put_target`: writes m[10].
  - New `lowq_stroke_tie_bit`, `g_lowq_stroke_soup_next` and `g_draw_tris_style_or`.
  - New `render_webgpu_draw_text_tris`.
  - Touched `render_webgpu_draw_tris` (style word), `hairline_restage` (LOW stroke arm tags bit 17),
    `render_webgpu_stroke_snap` (sets the next-soup flag; cache hit too), `StrokeSnapCacheEntry` (new trailing field
    `lq`), `render_webgpu_draw_gradient_tris` / `render_webgpu_draw_bitmap_tris` (clear the flag; a no-op at HIGH).
- **`SWFModernRuntime/src/libswf/tag.c`:**
  - A (as w1): new `lowq_tsnap_local_on`, `lowq_tsnap_delta_px`, `g_tsnap_origin` / `g_tsnap_have_origin`; touched
    `lowq_tsnap_delta` and `compose_children`.
  - New `cab_tie_exempt`, called from `cab_snap_in_place`, `cab_snap_world` and `cab_snap_root_leaf`.
  - `tf_glyph_advance_twips` with new `g_tf_low_adv_ceil_q` (HOLD, default off).
  - `tf_glyph_quarter_snap`, LOW arm: the field-local pen.
  - `textfield_glyph_render_cb` was renamed `textfield_glyph_render_cb_impl` (it sets the ceil quantum after the font
    metrics), and a new wrapper `textfield_glyph_render_cb` resets it around each field.
  - The glyph draw now calls `renderer_draw_text_tris`.
- **`SWFModernRuntime/src/avm2/avm2_display.c`:**
  - A (as w1): `g_avm2_tsnap_origin`, `avm2_lowq_tsnap`, `avm2_render_node`.
  - `avm2_flush_glyph_batch` and `avm2_draw_quad` call `renderer_draw_text_tris`.
- **`SWFModernRuntime/include/rendering/render_webgpu.h`, `renderer.h`, `src/rendering/render_stub.c`:** the
  `render_webgpu_draw_text_tris` declaration / macro / stub (`renderer_draw_text_tris` is `((void)0)` in the flashbang
  arm).
- **Not touched:**
  - `swf_core.c`, `tag_stubs.c`, `NO_GRAPHICS` arms;
  - the recompiler (so no `--recompile` was needed);
  - `gfx_build_stroke` / `drawingUnionTris` / `gfx_flatten_cmds` (the w2-stroke-geometry-land sibling's).
- **Sibling overlap with w2-stroke-geometry-land:** the C / x bias moves LOW stroke vertices on the y axis
  (`lowq_stroke_probe` 5745 → 5370). That slot is HIGH-only, so the two patches touch disjoint arms. Re-gate
  `acid-stroke-0` after both land.
- **No new pipelines:** shader-constant / vertex-word changes only, so `MSAA_SAMPLES` is not involved.
- No new TU. The Emscripten build compiles the same `render_webgpu.c` / `tag.c`. It was not built here (no emsdk run).

## 5. Gates

- **w1 146-row LOW gate + the 2 probes** (`ledger/gate_pass1.txt`, 238 comparisons): 49 rows moved.
- **Pass 2** (`ledger/gate_pass2_final.txt`) re-ran every mover plus all `cache_as_bitmap` / `filters` rows plus the
  **38 LOW canary members not in the gate**, on the final code.
  - Result: **0 pass → fail.**
  - Rows not re-run are byte-identical: no pass-1 leg moved them, and the exemptions only remove bias.
- **Render canary:**
  - The 87 LOW members (49 in the gate + 38 in pass 2) went through the same-binary legs.
  - The HIGH members are preprocessor-dead for every new rule.
  - **HIGH md5 A/B, patch vs clean master, 12 rows: identical.** The rows:
    - `regression/` (9): `avm1_edittext_wordwrap_render`, `avm1_drawapi_stroke_snap`, `avm2_drawapi_stroke_snap`,
      `avm1_stroke_seam_caps`, `avm2_group_alpha_cab`, `group_alpha_cab`, `avm2_edittext_placed_cxform`,
      `avm1_long_text_layout`, `avm2_timeline_stroke_gradient`;
    - `regression/mask_nested_intersect`;
    - `from_shumway/acid/acid-shapes`, `avm2/graphics_draw_triangles`.
  - `render_canary.py capture` over all 208 members was NOT run: 2 × ~208 graphics builds would not fit. Run it on the
    coordinator's merge if wanted.
- **`regression/`:**
  - All 13 LOW image rows are in the gate: 0 status moves, 2 new rows PASS.
  - The 12-row HIGH md5 A/B above.
  - **A full-suite graphics run was started and stopped at 18 tests** (14 + 4, all pass): at ~25 s per build it
    did not fit, and the change is render-only.

## 6. Refutations / premise attacks

- **"FP32 text sits +2 px right; the GPU render beats every chord prediction":** a layout artefact. The ink bboxes are
  equal, the steps are ceil advances, and the pens are field-local (§1). The predictor carried our own wrong layout,
  so neither our renders nor the predictions could be graded there.
- **"`place_object_test` / `shape_test` are FP32 goldens"** (w1): refuted by s27 `golden-provenance.md` ("not FP32 on
  either OS"). w1's B-refutation via `text_field_mask` still holds. `place_object_test`'s 'a' at 10.5 → 11 is now
  explained by local-pen rounding under an unsnapped world pen; the Ruffle golden reflects Ruffle.
- **"C costs +397 on the blend rows, a different tie class (curve edges)?":** no. It is the same tie rule applied on y
  only. The asymmetric version biases a curve's chord vertices up but not right. With both axes the blend rows return
  to master ±16.
- **"scroll_rect's 96 is a cached / crop draw":** the crop and the nested cache path were flagged, but the ROOT cache
  path (`cab_snap_world` / `cab_snap_root_leaf`) never set the flag. Its blit snap moves the subtree onto a
  manufactured .5 tie.
- **The brief's "all 14 blend rows already failing?":** confirmed: all 14 are F at master, so no Flash PASS was lost.

## 7. New unclaimed leads

- **The DF2 ceil advance** (HOLD, code shipped off): −39 636 channels on df2 (52 527 → 12 891) and −501 on `BeginBitmapFill` once REQUEST
  1 names the field property.
- **LOW glyph chords** (§1.3): small text only; a recompiler second tessellation.
- **The 48 px df2 baseline** is 1 px high in ours. It is the only row whose field y is .5 with a local baseline
  fraction > .5. Fit it with a y-phase probe.
- **Child-layer ALPHA coverage** (RvF entry): −2186 on `layer_alpha` and its twin.
- **The ROOT cacheAsBitmap paths never set `world[11]`** (the pixel-centre flag the nested path sets). The
  s28 comment in `cab_snap_in_place` claims `scroll_rect` is flagged; it is not. Setting it there would change the y
  rule for every root cached subtree; price it on the `cache_as_bitmap/*` LOW rows.
- **`nested_rotation` +9 under x:** a rotated cached subtree, not exempt (snap delta 0?). Small; look after REQUEST 2.
- **morph_test1 frames 2–6 at 198:** the text line is the remaining owner (chords / pen).

## LOCAL ORACLE REQUESTS

1. **FLASH: `session30-fanout-reports/w2-lowq-land-fixtures/lowq_adv_flags_probe/test.swf`, image, tick 1, direct
   pinned, LNX.** The SWF sets `_quality = "LOW"`.
   - **Layout:** 8 rows of the 12 px df2 field, each with one EditText flag toggled from the probe field toward the
     gnash xtrace field (WordWrap, NoSelect, HasTextColor, variable name, gnash flags exactly, Multiline,
     WordWrap + Multiline; see the docstring).
   - **Compare** each row's ink starts with `ours_ceil_on.png` (ceil: 13, 21, 28, 36, 44, 51, 59, …) and
     `ours_ceil_off.png` (13, 20, 27, 34, 41, 48, 55, …). The row(s) that switch name the rule's gate.
   - Rebuild with `python3 create_test_swf.py` (it reads the corpus `place_object_test` SWF).
2. **FLASH: LOW `--screen` captures, tick as test.toml**, of:
   - `visual/filters/bevel`, `visual/filters/glow`, `visual/filters/drop_shadow_angles`;
   - `visual/simple_shapes/overlaps`, `from_shumway/acid/acid-scale`;
   - `text/style_changes_in_html`.

   These are the priced losses of the tie rule and of the field-local pen. If their FP32 LOW renders confirm the move,
   they become flash_fixes swaps; if not, the rule needs a scope.
