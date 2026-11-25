**Flash quality=LOW sample-point model, as a complete arc (L).**

Inputs: `w1-avm2-vector-flash-report.md` §2 (on master), `w1-avm2-vector-flash-prototype.patch` (the LOWQ shift +
`LOWQ_PAINT_FIX` in `render_webgpu.c`), and the coordinator's NEW Flash 32 captures in
`w1-local-oracles/w1-avm2-vector-flash/` (README): `lowq_sample_point.low.png` / `.high.png` (built from the slot's
`Test.as`; the SWF is archived as `lowq_sample_point.test.swf`, so you can render ours), a `--screen` LOW capture
(== draw(), so draw() is the real screen at LOW), and `graphics_draw_triangles.low.png` (a second LOW fit on triangles).
The w1 measured: Flash LOW coverage samples at (x+0.5, y), gradient paint at (x, y+0.5); the prototype nets −70 graded
passes because clips/masks/filters/text weren't converted, while moving most vector rows toward Flash.

Task:
1. Fit every row of the probe against the captures: fill sample point (row 0), the LOW stroke rule (row 1: width
   rounding and offset, hairline, circle, polyline), gradient paint point x and y (row 2), bitmap texel choice at x.5,
   unfiltered cacheAsBitmap snap at LOW vs HIGH (this settles `cache_as_bitmap/avm1_color`'s rule — §4 of the w1
   report), scrollRect clip edge at .5 (row 3).
2. Implement the model for EVERY low-quality pass, not just main-pass fills: scissor/stencil clips and masks,
   filter-layer passes, text glyph quads, strokes. `MSAA_SAMPLES == 1` gates it; HIGH rows must stay md5-identical
   (preprocessor-dead or provably identical).
3. Gate (graphics, CI-identical box — prove fidelity first): the 41 low-quality Flash-golden passes (golden-provenance
   "Flash exact/in tol") must ALL still pass (the w1 prototype lost 4: `cache_as_bitmap/scroll_rect`,
   `blend_across_masks_issue_24549`, `filters/displacement_map_through_filters`, `filters/blur_pass_scaling`); every
   low-quality Ruffle-golden pass you lose must be listed by name with its excess vs the golden AND vs its archived
   Flash capture (`session27-fanout-reports/golden-provenance/*.png`) where one exists, so the coordinator can decide
   flash_fixes swaps. Render canary at md5 identity for HIGH members.
4. Ledger: `graphics_gradients`, `graphics_simple_shapes`, `graphics_draw_path`, `sprite_with_frames` border,
   `BeginBitmapFill`, gnash `shape_test`/`place_object_test` vs their Flash root captures. A NO-GO is fine if the net
   graded cost can't be brought to ≤ 0 Flash-golden losses; then deliver the measured model + the exact remaining
   pass-by-pass mechanism.
Coordinate-by-report with the local `n-stroke-snap` session (thin-stroke snapping; it may land first): read
`SWFRecompDocs/plans/n-stroke-snap-report.md` if it exists, and do not re-implement its rule.
