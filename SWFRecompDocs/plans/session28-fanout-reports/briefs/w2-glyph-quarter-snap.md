**Flash's ¼-px glyph outline snap + rotated border pen weight (M).**

Inputs: `w1-text-glyph-aa-report.md` (on master), `w1-text-glyph-aa-prototype.patch` (`tag.c`
`textfield_glyph_render_cb` identity arm), and the coordinator's Flash 32 captures in
`w1-local-oracles/w1-text-glyph-aa/` (README): direct captures of every row the snap moved pass → fail (request 1;
note the static-grab caveats for `edittext_scroll` and `morph_test1`), and the new fixture
`avm1_edittext_rotated_borders/` (SWF + generator) with Flash `draw()` and direct captures (request 2).

Task:
1. For each pass → fail row of the w1 gate, render ours before and after the snap and grade the TEXT-GLYPH regions vs
   the Flash capture. Classify each loss: Flash-ward (snap right; the row's Ruffle golden is the problem → name it as a
   flash_fixes/RvF candidate with numbers) or Ruffle-ward (snap wrong for that case → refine the rule, e.g. device-px
   grid, filter/cacheAsBitmap layers, morph). The bar to land: no Flash-golden row moves away, and every Ruffle-golden
   loss is either Flash-ward by measurement or fixed.
2. Complete the snap: the matrix arm (`tf_mm`), the device-px grid (stage scale), and — only if a Flash capture
   supports it (write FLASH requests with built SWFs) — AVM2 `avm2_render_glyphs` and DefineText.
3. Border pen weight: fit Flash's rotated/sheared hairline from `avm1_edittext_rotated_borders` (summed coverage across
   each edge at 15/30/45/60° and shear) and implement it in `tf_border_line_segment`'s skewed arm (+ the AVM2 twin in
   `avm2_render_textbox` if the same). Price `visual/edittext/edittext_border_transform` (Ruffle goldens) as a priced
   RvF loss if it moves away. Land `avm1_edittext_rotated_borders` as a `regression/` row with the Flash golden, and
   the HELD `avm1_edittext_rotated_glyphs` too if it gets within a stated budget of its Flash PNG.
4. With the snap landed, swap `regression/avm1_edittext_wordwrap_render`'s golden to its Flash capture
   (`tolerance = 1, max_outliers = 69` per the w1 report; re-measure).
Gate: render canary + every AVM1 text image row (the w1 report's 60-test / 92-comparison set) + `regression` text rows.
Graphics only (no NG arm).
