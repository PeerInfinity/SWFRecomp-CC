# w1-gfx-fill — wave 1 diagnosis: pixel cluster `same_geometry_wrong_fill` (+ non-video `unrelated_content`, `global_color_shift`)

Read `BRIEFS_COMMON.md` first. Read-only: no source edits. Deliverable:
`SWFRecompDocs/plans/session18-fanout-reports/w1-gfx-fill-report.md`. Scratch dir: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-gfx-fill/`.

Board: `wave0-image-board.md` + `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/image_triage.json` (rows carry `actual_png` /
`expected_png` paths under `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/image-results/`; use
`python3 scripts/image_triage.py --from-json /tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/image_triage.json --test <suite/test>`
to dump every feature of one test). Method doc: `SWFRecompDocs/plans/graphics-fanout-playbook.md`
§2–§7 and §16 (last board). Prior gfx reports: `session17-fanout-reports/w2-gfx-*-report.md`.

## Your comparisons (outliers = failing channels; max_out = allowed; a flip needs outliers <= max_out)
Head (cheapest, same geometry, wrong colour — usually ONE rule per test):
- `visual/filters/color_matrix` 237 (b_tiny, max_out 0)
- `avm2/graphics_simple_shapes` 240 (b_tiny)
- `avm1/define_font_glyph_table_order` 180 (max_out 4)
- `avm2/graphics_draw_path` 204
- `avm2/edittext_always_show_selection` 432 (max_diff 43 — selection colour?)
- `avm2/blend_shader_luma_lighten` 1237 (max_diff 204)
- `from_shumway/acid/acid-morph` 4311 (max_out 2600 — 1711 over)
- `visual/cache_as_bitmap/avm2_button` 4432
- `visual/drawing_api/drawing_order` 6664
- `avm2/bitmapdata_draw_self_via_graphic` 7500 (max_diff 23!)
- `avm2/bitmapdata_draw_masks` 5850 (unrelated_content)
Middle:
- `from_shumway/acid/acid-filter-2` 16764 (max_diff 122)
- `avm2/edittext_get_line_index_at_point` 18403, `avm2/edittext_get_char_index_at_point` 22849
- `avm2/bitmapdata_copypixels` 25200 (max_diff 187)
- `visual/cache_as_bitmap/nested_rotation` 25665
- `visual/filters/blur_scales_with_screen` 30810 (max_diff 40) — §16: AVM1 sprite-tag filter route needs a real offscreen cache pass
- `from_shumway/acid/acid-color-0` 44819 (max_out 3) — §16: the s17 REGRESSION band (20014 → 44817 after the EditText per-depth interleave); attribute first
- `from_shumway/acid/acid-bitmapData-copyPixels` 53760
- `avm2/displayobject_blendmode` 62400 (max_diff 114)
- `visual/blend_modes/layer_alpha` 66762, `visual/blend_modes/layer_erase` 66967 — NOTE the plain blend_modes a_epsilon rows are CAPPED (sub-pixel ties; do not scope); these two `layer_*` are moderate and NOT part of the cap — check whether they are a layer-blend compositing mechanism
Tail (price, likely arc-sized):
- `avm2/pixelbender_effect_glassDisplace_shaderfilter` 879464, `avm2/away3d_advanced_shallow_water_demo` 1.33M
- known_failure (Ruffle also fails; price only): `avm2/bitmapdata_draw_filters`, `visual/blend_modes/shader_as_mask`, `avm2/bitmapdata_applyfilter_destpoint_edges`

## Method
For each: open expected vs actual vs diff PNG (Read tool renders PNGs), name the mechanism
(which element, which colour rule, which stage of the pipeline: fill style parse / gradient
ramp / cxform / blend / bitmap sampling / premultiply / MSAA resolve). Where a local render
helps, `verify_output.py --mode=graphics --images --image-out-dir <your scratch>` on ONE test
at a time (local Dawn ≠ CI lavapipe; only an A/B is a verdict). Cluster by mechanism, price
flips (outliers must reach <= max_out — say which rows will only move bands), check the
image-axis dispositions in the playbook, verdict GO/HOLD/NO-GO with files (`render_webgpu.c`,
`avm2_display.c`, `action.c`, `tag.c`, `SWFRecomp/src/swf.cpp`…) + LOC + a canary list
from `ruffle-tests/render_canary_tests.txt`. Attack the brief. Siblings: w1-gfx-filters,
w1-gfx-text, w1-gfx-smalls.
