**Land Flash's HIGH coverage rule for skewed AVM1 text (from w1-text-pixels; S–M).**

Read `session29-fanout-reports/w1-text-pixels-report.md` (§2 rule + prototype, §2.4 completion mechanism) and
`w1-text-pixels-prototype.patch` (tag.c: `tf_cpu_cov_fill`, skewed `tf_border_skewed_line_rect` arm, skewed
`textfield_glyph_render_cb` matrix arm). Rule: 4 sub-scanlines per row at y + j/4, exact x coverage, n = round(16·cov),
written as 255 − 16n for black on white; ¼-px vertices after an unrounded composition; skewed box NOT size-snapped.
1. **Batched emit** (the blocker): one coverage texture per field drawn as a textured quad through the bitmap path, OR
   one dynamic vertex batch of run quads with per-vertex alpha. Must not hit `MAX_DYNAMIC_RECTS` for a rotated
   paragraph: add a stress fixture (a rotated multi-line field, ~200 glyphs) and prove nothing drops.
2. **Colour formula**: FP32 capture `w1-local-oracles/w1-text-pixels/W1_color/flash.png` (text `0xCC3300`, a grey rect
   behind the rot30 field: see that dir's README). Fit how Flash writes a coloured glyph / border pixel at coverage n/16
   over white and over grey (premultiplied blend of colour·16n/255? per-channel rounding?) and implement it. Add W1 as a
   `regression/` fixture with that golden (budget it from the measured residual, like `avm1_edittext_rotated_glyphs`).
3. Gate as in the w1 report §2.3 (22 tests / 43 comparisons, md5 identity outside the 4 expected movers), plus the new
   fixtures; graphics only (renderer code). Kill switch `SWF_TF_CPU_COV=0`.
4. RvF entry: Ruffle's `rint(s − 0.35)` size snap on a sheared box is not Flash (w1 report lead 5).
5. Optional, only if 1–4 are done: fit the same model to `W2_shapes/flash.png` (slanted 1 px stroke, hairline, filled
   triangle: all edge pixels are on the 255 − 16n ladder) with `w1-text-pixels-evidence/scan.py` and report the px>2 of
   the model vs our MSAA render — numbers only, no shape-renderer change (w1-aa-sizing owns that question).
Ledger: `regression/avm1_edittext_rotated_glyphs`, `_rotated_borders` (Flash-ward bands, stay pass),
`visual/edittext/edittext_border_transform` .04/.06 (toward goldens, stay pass); new fixtures pass. 0 status moves else.
Siblings: w1-aa-sizing (diagnosis), w1-lowq-next (LOW, MSAA_SAMPLES==1 paths), local n-seam-caps (stroke builders in
`render_webgpu.c`). Name every function you touch in `render_webgpu.c`; MSAA_SAMPLES never literal.
