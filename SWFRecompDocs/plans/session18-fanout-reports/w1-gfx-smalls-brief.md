# w1-gfx-smalls — wave 1 diagnosis: remaining pixel rows (hairline non-text, row_banded, masks/morphs/gradients, tiling seam, scroll_rect)

Read `BRIEFS_COMMON.md` first. Read-only: no source edits. Deliverable:
`SWFRecompDocs/plans/session18-fanout-reports/w1-gfx-smalls-report.md`. Scratch dir: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-gfx-smalls/`.

Board: `wave0-image-board.md` + `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/image_triage.json` (PNG paths under
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/image-results/`). Method: `graphics-fanout-playbook.md` §2–§7, §16. Prior:
`session17-fanout-reports/w2-gfx-smalls-report.md`, `w2-gfx-drawgraphicsdata-report.md`
(tiling seam + round joins lead), `w2-gfx-cab-pixelsnap-report.md`, `w2-gfx-acid-shapes-aabb-report.md`.

## Your comparisons
**§16 named leads (verify first):**
- `avm2/graphics_bitmap_fill` 64 (max_out 60 — FOUR channels over!) and `avm2/graphics_bitmaps` (now passing at 1058? check the board) — the dynamic-bitmap layer-period tiling seam in `render_webgpu_draw_bitmap_tris` (in-tree comment names the fix) + round stroke joins (AS3 default `joints="round"`; tessellator is miter/bevel only)
- `visual/cache_as_bitmap/scroll_rect` 2 (TWO channels, max_out 0) and `avm2/displayobject_scrollrect` 4, `visual/avm2_button_scroll_rect` 6, `visual/simple_shapes/scroll_rect_mask` 20 — one sub-pixel scrollRect rule?
- `from_shumway/acid/acid-shapes` (image; needs `drawRoundRect` corner radii — check whether it is still failing; not on the live board = passing?)
**a_epsilon non-text (each is a handful of channels; find the shared rule, not per-test fixes):**
- masks: `avm2/mouse_pick_dobj_mask` 6, `mouse_pick_non_interactive_dobj_mask` 6, `visual/blend_across_masks_issue_24549` 6, `from_shumway/MaskTest` 7
- blend (hairline, NOT the capped diffuse set): `visual/blend_modes/subtract` 10, `darken` 19, `multiply` 19, `invert` 27
- gradients: `from_shumway/acid/acid-gradient-2` 56, `visual/drawing_api/gradient_focal_point` 60 (max_diff 39), `from_shumway/gradientTransform` 9 (KF), `visual/drawing_api/fills_and_lines` 104, `avm2/graphics_gradients` 299, `from_shumway/acid/acid-gradient` 6639 (max_diff 189), `avm1/movieclip_begin_gradient_fill` 672
- `from_shumway/doubleAndRegister` 26, `acid-gc` 234, `acid-scale` 320, `avm2/bitmapdata_draw_rotation` 348, `bitmapdata_colortransform` 726 (max_diff 125), `sprite_with_frames` 920, `visual/cache_as_bitmap/drawing_api` 2295, `visual/text/String_path_variable_button` 996 (max_out 12)
**morphs:** `from_gnash/misc-ming.all/morph_test1` frames 1–6, 186–213 each (800x600) — one mechanism across all six frames
**row_banded / structural:** `visual/simple_shapes/layers` 177, `avm2/bitmap_pixelsnapping` 3831, `visual/simple_shapes/heavy_tesselation` 2439 (max_out 3, max_diff 79), `avm2/displayobject_getbounds_shape` 22290 (max_out 3800), `from_gnash/misc-ming.all/Video-EmbedSquareTest` 186
**large / parked (one line each — confirm parked):** `avm2/stage_scale_factor` 1.9M (also a trace failure 6/12 — w1-trace-display owns the trace half; you own the pixel half: is it the SAME cause?), `from_shumway/bitmapbuttons` 618042 (missing_element f_catastrophic — NOT parked, diagnose), `avm2/pixelbender_effect_glassDisplace` 784195, `visual/video/h264` frame5, known_failure rows (`acid-mask` ×3, `MaskTest-2`, `strokes/scale`, `place_object_test`, `BeginBitmapFill`)

Standing invariant: `MSAA_SAMPLES`, never literal 4; quality=low goldens are 1-sample.

## Method
Open expected/actual/diff PNGs, name the mechanism per test, cluster (the a_epsilon rows are
worth it ONLY if several share one rule — a per-test fix for 6 channels is not), price flips
(outliers <= max_out), check the playbook's image-axis dispositions (hairline_edge_drift is
"presumed lavapipe AA" — say which rows are NOT AA), verdict GO/HOLD/NO-GO with files + LOC +
canaries. Local renders one at a time, A/B only. Attack the brief. Siblings: w1-gfx-fill,
w1-gfx-filters, w1-gfx-text.
