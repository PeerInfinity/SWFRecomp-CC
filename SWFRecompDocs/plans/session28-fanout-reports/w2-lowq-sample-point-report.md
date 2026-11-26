# s28 w2-lowq-sample-point: Flash quality=LOW sample-point model (report)

Slot `w2-lowq-sample-point`, wave 2 (implementation). Branch `fanout/w2-lowq-sample-point`.
- All measurements are on origin/master `97f9742f4`, which includes n-stroke-snap and w2-glyph-quarter-snap.
- The branch was then merged with `657dac763` (w2-avm1-leads-land, w2-filter-residuals-land), and the patch is
  against `657dac763`. A 14-row re-check on the merged tree reproduced every number: all 6 filter / cacheAsBitmap
  Flash-gate rows, `scroll_rect`, `blend_across_masks`, `edittext_underline`, `focus_highlight_render`, `avm1/color`,
  both fixtures, and `graphics_gradients` 668.

**New files:**
- `session28-fanout-reports/w2-lowq-sample-point-report.md` (this file)
- `session28-fanout-reports/w2-lowq-sample-point.patch` = `git diff origin/master --binary -- SWFModernRuntime ruffle-tests/tests/swfs/regression/lowq_fill_edges ruffle-tests/tests/swfs/regression/lowq_sample_point_probe ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (proved with `git apply --check -R`)
- `ruffle-tests/tests/swfs/regression/lowq_sample_point_probe/` (`create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`, `output.expected.png` = the Flash LOW capture)
- `ruffle-tests/tests/swfs/regression/lowq_fill_edges/` (`README.md`, `test.swf`, `test.toml`, `output.txt`,
  `output.expected.png` = n-stroke-snap's `fill_edges/flash_low.png`)
- Appended (not new): an RvF entry at EOF of `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`, "Unfiltered
  cacheAsBitmap: no pixel snap at quality HIGH".

`render_canary_tests.txt` is unchanged. The canary's 66 LOW members were all run in the gate below; HIGH is
preprocessor-identical (§5).

## Verdict (lead)

**GO on the Flash-golden bar, but net-negative on graded passes. The coordinator decides with the swap table in §4.**

- **All 58 low-quality Flash-golden passing tests still pass (0 losses).** That is 90 comparisons with
  golden-provenance "Flash exact/in tol". The brief's 41 is a narrower count; my set is a superset. It includes
  the 4 the w1 prototype lost: `cache_as_bitmap/scroll_rect`, `blend_across_masks_issue_24549`,
  `filters/displacement_map_through_filters` and `filters/blur_pass_scaling`.
- **No flips.** The headline vector rows move a lot toward their Flash goldens but stay over their limits:
  - `graphics_gradients` 3685 → 668
  - `graphics_draw_path` 704 → 192
  - `graphics_simple_shapes` 158 → 114
- **Cost: 66 low-quality passing tests with non-Flash goldens (72 comparisons) go pass → fail.** Of these:
  - 38 comparisons move TOWARD their archived Flash capture;
  - 14 move away (the gradient-heavy and Drawing-API rows, §4);
  - 17 have no capture;
  - 3 are unchanged.

  The w1 prototype cost was about 68 of 119; this is the same order. It is the inherent cost of the
  Ruffle (GPU-centre) goldens disagreeing with Flash LOW, not of unconverted passes.
- Recommendation: land it only together with flash_fixes swaps for the "toward Flash" rows, or hold it. The
  model itself is measured and Flash-exact on 3 independent oracles (§1).
- If it is held, `lowq_fill_edges` can land alone: it passes before and after, and guards the centre rule.

## 1. The model (fits against the Flash 32 captures)

Oracles:
- the coordinator's `lowq_sample_point.low/.high.png` (AS3 probe, draw() == screen);
- n-stroke-snap's `fill_edges/flash_low.png` (timeline rects at +0..19 twips, both axes);
- every Flash-golden LOW corpus row (the 58-test gate).

There is no archived probe SWF and no AS3 compiler in the cloud. So `regression/lowq_sample_point_probe` re-expresses
the probe as static DefineShapes with identical twips geometry (generator in the fixture). It differs in three ways:
- the scrollRect cell is masked, because AVM1 scrollRect stores whole pixels here;
- the "Bitmap" cells are bitmap-filled shapes;
- the hairline cell is a DefineShape width-0 line, which our runtime does not draw.

| rule | measured | evidence |
|---|---|---|
| Fill coverage, slanted edges | the scanline is crossed at its **TOP**, sample (x+0.5, y) | probe triangle: 17 → 1 px; diamond: 36 → 0 px; w1 drawPath bow-tie |
| Fill coverage, horizontal and vertical edges | **pixel-centre rule, an exact .5 included**. An edge at e covers pixel x iff e ≤ x+0.5, in x and y | fill_edges, all 20 offsets × 2 axes; probe rects at +0 / .25 / .75 |
| GPU form (1 sample) | vector vertices move to `y' = min(y, ceil(y − 0.5)) + 0.5` (device px); x unchanged | integer vertices get the plain +0.5 (top sample); upper-half vertices land on the pixel line, so their horizontal edge keeps the centre-rule row |
| Exceptions to the move | bitmap fills, Bitmap quads, scrollRect crop quads, unfiltered cacheAsBitmap subtrees keep the GPU centre rule | probe row 3: a Bitmap at 200.5 / 124.5 starts on pixel 200 / 124 in Flash. `cache_as_bitmap/scroll_rect` (Flash exact) needs its crop on the centre rule |
| Gradient paint point | the pixel's **top-left corner (x, y)**, in both axes | probe linear H and V: Flash pixel k = exactly 8k on a 32-px ramp; radial fit `(x, y)` + floor LUT has mean error 0.83, against ≥ 3.97 for any ±¼ px offset |
| Gradient ramp lookup | **nearest-below entry `floor(t·256)`**, not the hardware lerp | probe H/V ramps exact (0 px > 0) after; before, every pixel was 1 low |
| Bitmap texel at x.5 | pixel centre, floor (GPU nearest) | probe `beginBitmapFill` (4,0,0,4,.5,.5): Flash == ours before (0 px) |
| cacheAsBitmap snap | HIGH: **not snapped** (half coverage both edges). LOW: undecided (snap ≡ no-snap + the AS3 tie) | probe cell (0,120); RvF entry appended. This settles `avm1_color`'s premise, see New leads |
| scrollRect clip at .5 | not measurable here (AVM1 scrollRect is integer in our runtime) | the corpus row `cache_as_bitmap/scroll_rect` pins crop = centre rule |
| LOW strokes (row 1) | not modelled. Flash 1 px at integer coords covers [c, c+1); 2 / 4 px at integer coords are centred; at x.5 the top band rounds up and the other three round down; round joins are coarse | probe row 1 cells. Hands off to n-stroke-snap's LOW leg, whose rule I did not re-implement |

**One unresolved tie.** In the AS3 Drawing-API probe, a rect at exactly .5 EXCLUDES the tie pixel in x and y
(drawRect at 5.5 → 6..25). The timeline `fill_edges` rect at exactly .5 INCLUDES it. Both are FP32. I follow the
timeline (corpus-dominant; it also passes `edittext_underline` and `focus_highlight_render`). The probe keeps one
40-px row for it (cell (160,0)).

Probe per cell, px off Flash at > 2:

| cell row | origin/master | patch |
|---|---|---|
| 0 fills | 36 / 17 / 0 / 0 / 78 / 0 | 0 / 1 / 0 / 0 / 40 / 0 |
| 1 strokes | 167 / 26 / 30 / 146 / 84 / 72 | 167 / 26 / 30 / 146 / 78 / 4 |
| 2 gradients | 1024 / 1024 / 691 / 802 | **0 / 0 / 1** / 141 |
| 3 bitmaps / cab | 0 / (masked) / 0 / 231 / 0 / 0 | same |
| total | 4428 | **865** |

## 2. Implementation (exact patch scope)

All of it is at `MSAA_SAMPLES == 1` only.

`SWFModernRuntime/src/rendering/render_webgpu.c`:
- `vertex_wgsl` `vs_main`, macros `LOWQ_VS_POSITION` / `LOWQ_POS_DECL` / `LOWQ_VS_COND` / `LOWQ_SNAP_X` / `LOWQ_SNAP_Y`:
  - computes the device position, applies the y rule to non-bitmap, unflagged draws;
  - re-derives `pos` at the displaced point (inverse of the 2×2 device Jacobian), so `v_args` (the paint field)
    stays fixed in screen space.
- The target size W×H rides in the stage matrix's z column (m[8], m[9]). It multiplies z = 0 and the shader resets
  it to (0,0,1,0), so the projection math is untouched.
- `fragment_wgsl`:
  - `LOWQ_SHADE_HEAD` (`shade_main`): gradient `v_args −= ½·dpdx + ½·dpdy`, giving paint at (x, y);
  - `LOWQ_GRADIENT_LOOKUP` (`sample_gradient`): `floor(t·256)` nearest entry.
- New `lowq_put_target`, `lowq_upload_stage`. Callers:
  - `render_webgpu_upload_stage_transform` and `render_webgpu_open_pass` (both stage uploads);
  - `render_webgpu_begin_offscreen_pass` (the padded filter target gets its own W+2P × H+2P). That is what brings
    back `blur_pass_scaling` and `displacement_map_through_filters`.
- Filter-layer passes, masks (stencil shapes go through `vs_main`), strokes (solid triangles) and text glyphs (solid
  fills) all ride the same vertex rule automatically. No per-pass code is needed beyond the pad matrix.

`SWFModernRuntime/src/libswf/tag.c` (`#if defined(MSAA_SAMPLES) && MSAA_SAMPLES == 1`):
- `cab_snap_in_place`: an unfiltered cacheAsBitmap subtree sets `world[11] = 1`, a z-column flag inherited by its
  children; vs_main skips the move for flagged draws. The behaviour for HIGH is unchanged: the snap return is
  merely restructured.
- `compose_children` scrollRect arm: the crop slot is written with the same flag (`crop_m`).

Siblings: no overlap with the SIBLING_FILE_MAP functions. The n-stroke-snap code (`hairline_restage`) is untouched;
its snapped bands sit on integer device edges, which the y rule leaves invariant.

## 3. Gate results (graphics, this box)

**Fidelity.** Pre-rebase, the before render of `graphics_draw_path` was md5-identical to CI's `ruffle-image-results`
actual (`07d7ce1c`), so local grading is CI-grade. The before leg below is clean current origin/master on the same box.

| headline (excess) | before (origin/master) | after | Flash |
|---|---:|---:|---|
| `avm2/graphics_gradients` | 3685 | **668** | golden = Flash |
| `avm2/graphics_simple_shapes` | 158 | **114** | golden = Flash |
| `avm2/graphics_draw_path` | 704 | **192** | golden = Flash (flash_fixes) |
| `avm2/sprite_with_frames` | 6342 | 6333 | golden = Flash; the border is LOW strokes, the rest is text (floor) |
| `from_gnash/.../BeginBitmapFill` | 839 | 851 | golden = Flash; floor = device-font label |
| `from_gnash/.../shape_test` | 15994 | 15877 | vs Flash capture (draw): 8508 (CI before) → 8511 |
| `from_gnash/.../place_object_test` | 38238 | 37758 | vs Flash capture (draw): 15586 → 15532 |
| `regression/lowq_sample_point_probe` (new; tol 2, limit 2000) | fail (4428 px) | **pass** (1990 ch) | Flash |
| `regression/lowq_fill_edges` (new) | pass | pass | Flash |

- **Flash-golden LOW gate: 58/58 tests, every comparison passes.** That covers all of focusrect_*,
  focus_highlight_*, vp6_*, the bitmapdata / pixelbender / filters / cache_as_bitmap rows, `edittext_underline` and
  `winding_rule`.
- **Regression suite near the change:** the canary's regression LOW members `layer_group_overlap_alpha`,
  `layer_group_in_add_alpha` and `avm2_layer_group_overlap_alpha` pass, as do both new fixtures.
- Canary LOW members `avm2/bitmapdata_opaque` (4) and `avm2/bitmapdata_applyfilter_blur` (47515) fail at baseline
  too, with the same numbers.
- **Trace axis:** not graded in these runs. The change is renderer-only (shader text plus two z-column matrix writes
  that multiply z = 0), so no trace movement is expected.

## 4. Ruffle-golden (non-Flash) LOW passes lost: the swap table

Before-vs-Flash is the golden vs the archived Flash PNG. These rows passed before, so before ≈ golden: exact at
tol 0, within tol otherwise. After-vs-Flash is our render vs that PNG. Both are counted at the test's tolerance.
The Flash PNG is `session27-fanout-reports/golden-provenance/<test>__<cmp>*.png`.

**Caveat:** those Flash captures came from the s27 sweep. For rows whose SWF doesn't set quality itself they may be
Flash HIGH. The `gradients/gradients` 6295 → 58167 outlier is the likely case. Recapture at `--quality low` before
swapping (LOCAL ORACLE REQUESTS).

| test | cmp | excess vs golden | golden→Flash px | ours-after→Flash px | direction |
|---|---|---:|---:|---:|---|
| `avm1/movieclip_begin_gradient_fill` | output | 2662 | 18324 | 19923 | away |
| `avm1/movieclip_line_gradient_style` | output | 1128 | 8358 | 8946 | away |
| `avm2/displayobject_mask` | output | 30 | 28 | 19 | **toward Flash** |
| `avm2/displayobject_opaque_background` | output | 280 | 242 | 214 | **toward Flash** |
| `avm2/displayobject_scrollrect` | output | 398 | 178 | 71 | **toward Flash** |
| `avm2/graphics_bad_direct_commands` | output | 327 | 196 | 91 | **toward Flash** |
| `avm2/loader_events` | output | 122 | 300 | 300 | same |
| `avm2/loader_loadbytes_events` | output | 122 | 300 | 300 | same |
| `avm2/mouse_pick_dobj_mask` | output | 120 | - | - | no Flash capture |
| `avm2/mouse_pick_non_interactive_dobj_mask` | output | 96 | - | - | no Flash capture |
| `avm2/stage3d_bitmap` | output | 153 | - | - | no Flash capture |
| `avm2/stage3d_texture` | output | 1743 | - | - | no Flash capture |
| `avm2/symbol_class_conflict` | output | 1140 | 2103 | 1616 | **toward Flash** |
| `from_gnash/misc-ming.all/morph_test1` | frame1 | 200 | 201 | 101 | **toward Flash** |
| `from_gnash/misc-ming.all/morph_test1` | frame2 | 75 | 521 | 510 | **toward Flash** |
| `from_gnash/misc-ming.all/morph_test1` | frame3 | 75 | 521 | 510 | **toward Flash** |
| `from_gnash/misc-ming.all/morph_test1` | frame4 | 75 | 521 | 510 | **toward Flash** |
| `from_gnash/misc-ming.all/morph_test1` | frame5 | 75 | 521 | 510 | **toward Flash** |
| `from_gnash/misc-ming.all/morph_test1` | frame6 | 75 | 320 | 309 | **toward Flash** |
| `visual/avm2_button_scroll_rect` | output | 234 | 18 | 96 | away |
| `visual/blend_modes/add` | output | 410 | 4223 | 3577 | **toward Flash** |
| `visual/blend_modes/alpha_no_layer` | output | 1875 | 4691 | 4058 | **toward Flash** |
| `visual/blend_modes/darken` | output | 656 | 4267 | 3905 | **toward Flash** |
| `visual/blend_modes/difference` | output | 470 | 5289 | 4132 | **toward Flash** |
| `visual/blend_modes/erase_no_layer` | output | 1839 | 4681 | 4047 | **toward Flash** |
| `visual/blend_modes/hardlight` | output | 933 | 4995 | 4382 | **toward Flash** |
| `visual/blend_modes/invert` | output | 1063 | 4367 | 3921 | **toward Flash** |
| `visual/blend_modes/layer_alpha` | output | 1813 | 5455 | 4752 | **toward Flash** |
| `visual/blend_modes/layer_erase` | output | 1731 | 4550 | 3945 | **toward Flash** |
| `visual/blend_modes/lighten` | output | 381 | 4725 | 3832 | **toward Flash** |
| `visual/blend_modes/multiply` | output | 661 | 4272 | 3909 | **toward Flash** |
| `visual/blend_modes/overlay` | output | 863 | 4051 | 3760 | **toward Flash** |
| `visual/blend_modes/screen` | output | 395 | 4772 | 3751 | **toward Flash** |
| `visual/blend_modes/subtract` | output | 420 | 4146 | 3476 | **toward Flash** |
| `visual/cache_as_bitmap/drawing_api` | output | 1195 | 600 | 201 | **toward Flash** |
| `visual/cache_as_bitmap/edittext_scroll` | output.01 | 18 | - | - | no Flash capture |
| `visual/cache_as_bitmap/edittext_scroll` | output.02 | 17 | - | - | no Flash capture |
| `visual/cache_as_bitmap/nested_rotation` | output | 339 | 129 | 32 | **toward Flash** |
| `visual/drawing_api/drawing_order` | output | 2156 | 5933 | 5999 | away |
| `visual/drawing_api/fills_and_lines` | output | 19910 | 20166 | 32654 | away |
| `visual/drawing_api/gradient_focal_point` | output | 4361 | 28805 | 28747 | **toward Flash** |
| `visual/filters/bevel` | output | 60941 | - | - | no Flash capture |
| `visual/filters/bevel_full` | output | 37976 | - | - | no Flash capture |
| `visual/filters/bevel_inner` | output | 28711 | - | - | no Flash capture |
| `visual/filters/bevel_outer` | output | 63007 | - | - | no Flash capture |
| `visual/filters/blur_scales_with_screen` | output | 296 | - | - | no Flash capture |
| `visual/filters/blur_size_grows` | output | 3751 | 36271 | 36289 | away |
| `visual/filters/color_matrix` | output | 54 | 16651 | 16640 | **toward Flash** |
| `visual/filters/displacement_map` | output | 11856 | 17605 | 17495 | **toward Flash** |
| `visual/filters/drop_shadow` | output | 25221 | - | - | no Flash capture |
| `visual/filters/drop_shadow_angles` | output | 42481 | 25038 | 22811 | **toward Flash** |
| `visual/filters/drop_shadow_scales_with_screen` | output | 1200 | - | - | no Flash capture |
| `visual/filters/glow` | output | 17830 | - | - | no Flash capture |
| `visual/filters/glow_with_alpha_strength` | output | 17040 | - | - | no Flash capture |
| `visual/filters/glow_without_composite_source` | output | 18416 | - | - | no Flash capture |
| `visual/fonts/device-font` | output | 708 | 3537 | 3532 | **toward Flash** |
| `visual/fonts/duplicate_font` | output | 39 | 2690 | 2694 | away |
| `visual/fonts/glyph` | output | 744 | 552 | 490 | **toward Flash** |
| `visual/opaque_background` | output | 430 | 3124 | 3125 | away |
| `visual/simple_shapes/gradients/focal_radial` | output | 1347 | 3670 | 3134 | **toward Flash** |
| `visual/simple_shapes/gradients/gradients` | output | 6178 | 6295 | 58167 | away |
| `visual/simple_shapes/gradients/radial` | output | 51435 | 22483 | 1151 | **toward Flash** |
| `visual/simple_shapes/gradients/reflect` | output | 642270 | 214781 | 215176 | away |
| `visual/simple_shapes/gradients/repeat` | output | 644640 | 216361 | 216361 | same |
| `visual/simple_shapes/heavy_tesselation` | output | 35843 | 23229 | 14980 | **toward Flash** |
| `visual/simple_shapes/layers` | output | 27 | 1079 | 1080 | away |
| `visual/simple_shapes/masks` | output | 2621 | 2118 | 2326 | away |
| `visual/simple_shapes/masks_equal_clipdepth` | output | 2621 | 2118 | 2326 | away |
| `visual/simple_shapes/overlaps` | output | 870 | 626 | 380 | **toward Flash** |
| `visual/simple_shapes/scroll_rect_mask` | output | 272 | 5806 | 5708 | **toward Flash** |
| `visual/simple_shapes/text_field_mask` | output | 630 | 1189 | 1202 | away |
| `visual/text/String_path_variable_button` | output | 66 | - | - | no Flash capture |

72 comparisons over 66 tests: toward Flash 38, away 14, no capture 17, same 3.

**Reading it:**
- Most `blend_modes/*` rows, `opaque_background`, and the cacheAsBitmap / `displayobject_*` rows move toward Flash.
  These are flash_fixes swap candidates once recaptured at LOW.
- The filter rows without a capture (`bevel*`, `glow*`, `drop_shadow*`) move by whole-shape half-pixel offsets
  through the blur, by tens of thousands of channels. They need LOW captures before any decision.
- "Away" rows:
  - `gradients/gradients`, `movieclip_begin_gradient_fill`, `movieclip_line_gradient_style`: gradient paint; see the
    HIGH-capture caveat;
  - `drawing_api/fills_and_lines`, `drawing_order`: Drawing-API strokes (LOW stroke rule missing);
  - `simple_shapes/masks*`, `avm2_button_scroll_rect`, `text_field_mask`.

## 5. HIGH identity (md5)

- `gcc -E -P` of `render_webgpu.c` at MSAA 4, origin/master vs patch, differs in only three ways:
  - `"  " "let" " pos"` (the same concatenated WGSL string);
  - an empty `""` literal;
  - a `lowq_upload_stage` wrapper whose HIGH body is the original `wgpuQueueWriteBuffer`.
- `tag.c` at HIGH differs by a semantically identical restatement of `cab_snap_in_place`'s early return.
- A seeded sample of 8 HIGH canary members (`render_canary.py capture/compare`) is IDENTICAL 8/8.

## 6. Expected-flip ledger (for CI)

**Trace axis:** no changes.

**Pixel axis, pass → fail (losses):** the 66 tests / 72 comparisons in §4, exactly. CI also runs the regression
suite: both new fixtures pass.

**Pixel axis, fail → pass:** none in the corpus.

**Band moves (fail → fail, toward the Flash golden):**
- `avm2/graphics_gradients` 3685 → 668
- `avm2/graphics_draw_path` 704 → 192
- `avm2/graphics_simple_shapes` 158 → 114
- `place_object_test` 38238 → 37758
- `shape_test` 15994 → 15877
- `sprite_with_frames` 6342 → 6333
- `BeginBitmapFill` 839 → 851 (+12, its parallelogram edges; the label floor dominates)

The `ruffle-image-results` actuals for these 7 change accordingly.

## 7. Not finished / completion mechanisms

1. **Flash LOW strokes** (probe row 1, `sprite_with_frames` border, `fills_and_lines`): extend n-stroke-snap's
   `hairline_restage` with a LOW leg fitted on probe row 1. The data is in §1.
2. **AS3 Drawing-API .5 tie vs timeline .5 tie.** This needs a Flash capture of the same rect via the AS3 Drawing API
   AND a timeline DefineShape in one SWF (request 2).
3. **Focal/repeat radial** (probe cell (120,80), 141 px) and the Flash radial centre (pixel 8, not 0). Flash's radial
   `t` has a floor near d = 0. Its sqrt model is unfitted.
4. **Rotated bitmap fill texel choice** (probe cell (120,120), 231 px, unchanged by this patch).
5. **LOW recaptures of the §4 rows.** These are the swap decision: the coordinator's `run_image.py --quality low`
   (request 1).

## New unclaimed leads

- **`cache_as_bitmap/avm1_color` (HIGH, Flash golden, 1200):** Flash HIGH does not snap unfiltered cacheAsBitmap
  (probe, RvF appended). The s26 measured no-snap = 230 max 1, and all three blockers are LOW rows. A HIGH-only
  no-snap (`cab_snap_delta` returning 0 for `filter_type == 0` when `MSAA_SAMPLES != 1`) is an S-sized lead that
  touches HIGH cacheAsBitmap rows only. It was not done here because it breaks the HIGH md5 bar of this brief.
- Static DefineShape width-0 (hairline) lines draw nothing in our runtime (probe cell (120,40)). Flash draws a 1-px
  hairline. Check against the corpus before treating it as a bug: the AS3 `lineStyle(0)` path draws.
- AVM1 `scrollRect = new Rectangle(4.5, …)` reads back `(x=4, …)` in our runtime (whole pixels). Flash keeps 4.5
  (AS3; AVM1 unverified).

## LOCAL ORACLE REQUESTS

1. **FLASH, `--quality low` image (draw), recaptures of the §4 rows that have a Flash capture.** At minimum:
   - `visual/simple_shapes/gradients/{gradients,radial,focal_radial,reflect,repeat}`
   - `avm1/movieclip_begin_gradient_fill`, `avm1/movieclip_line_gradient_style`
   - `visual/blend_modes/*` (screen mode for non-LAYER blends)
   - `visual/opaque_background`, `avm2/displayobject_{scrollrect,opaque_background,mask}`
   - `visual/cache_as_bitmap/{drawing_api,nested_rotation}`
   - `visual/simple_shapes/{masks,overlaps,heavy_tesselation}`
   - `visual/filters/{bevel,glow,drop_shadow}*`
   Compare each against the patch's render (this branch) and swap the goldens that match into flash_fixes. Note
   whether the s27 captures of these rows were HIGH.
2. **FLASH, AS3 + timeline .5 tie:** one AS3 SWF with `drawRect(5.5, 5.5, 20, 20)` next to a timeline
   (SymbolClass-placed) DefineShape rect at 110 twips, `--quality low` draw and screen. This decides §7.2.
