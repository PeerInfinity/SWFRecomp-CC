**Pixels, the applyFilter / draw / ColorMatrix tail** (playbook §25 "applyFilter tail" and "ColorMatrix leftovers"). Categories: `avm2`, `visual`, `avm1`, `from_shumway`, `regression`.

1. **GPU display-filter blur vs the Flash model.** s26 `6a6699c55` gave `bd_apply_filter` the Flash blur model (whole-source taps, output grown by the reach, 6-bit size). The GPU display-filter path (`render_webgpu.c` / `tag.c` filter passes, `blur_box_kernel`) was never checked against it. Measure where they differ (`filters/blur_quality` 205332, `blur_fractional`, other `filters/*` rows) and price it. Note: `filters/blur_quality`'s golden was judged inconsistent with `blur_fractional` in s26; re-test that claim.
2. `bitmapdata_drawwithquality` (3152 vs its 3197 limit, so it passes with 45 px headroom; watch it, and find what owns the 3152).
3. **AVM1 `applyFilter`/`draw()` beyond ColorMatrix**: AVM1 `BitmapData.applyFilter` handles CM only. Price wiring the AVM2 `bd_apply_filter` kernels (blur/glow/dropshadow/bevel/convolution) into the AVM1 arm; find corpus rows that reach it (grep `applyFilter` in avm1 / gnash / shumway SWFs' sources or `output.txt`).
4. **XS:** a ConvolutionFilter with ≥20 matrix entries is misread as a ColorMatrix (find the discriminator, fix, fixture).
5. **ColorMatrix leftovers:** a live CM under a placement cxform; CMs with alpha-bias >0 stay folded; a folded CM survives `filters=[]`. Fixture each with an exporter golden request.
6. `cache_as_bitmap/avm1_color` NO-GO: write the RvF entry draft (the Flash no-snap rule costs 3 passes with Ruffle-made goldens: `avm2_button`, `drawing_api`, `scroll_rect`).

Prototype any GO, measured, with a render-canary md5 sweep. Siblings: `w1-render-bitmap-leads` (shader_as_mask, draw() Drawing-API paths), `w1-text-glyph-fidelity` (draw() of a tinted EditText).
