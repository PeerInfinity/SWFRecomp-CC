**AVM2 applyFilter kernels and `draw()` of filtered sources, against FLASH** (s26 held fixtures; the Flash captures arrived s27). Categories: `avm2`, `visual`, `regression`.

**Evidence:** `SWFRecompDocs/plans/flash-oracle-captures/avm2_applyfilter_glow_kernels/output.flash.txt` and `SWFRecompDocs/plans/flash-oracle-captures/avm2_bitmapdata_draw_filtered/output.flash.txt` (Flash Player 32, 3/3 runs identical, Linux == Windows). The fixtures are in `SWFRecompDocs/plans/session26-fanout-reports/w2-held-fixtures/` (README there).
- glow_kernels: Flash differs from the provisional output.txt (and from Ruffle) on 22 of 23 rows. Most are a few levels per channel, but some edge pixels flip between 0 and non-zero.
- draw_filtered: Flash's `draw()` DOES apply the source's filters. 10 of 13 rows differ: the dropshadow tail is shorter, and the convolution edge is `ffff0000`, 1 px wider.

1. Fit our `avm2_bitmap.c` Glow/DropShadow/Bevel kernels (`bd_apply_filter`, s26 `18a58261a` + `6a6699c55` edge growth) to the Flash rows: strength/knockout/inner arithmetic, quality passes, rounding, the alpha tail. Report per row before → after vs Flash.
2. Switch `bd_draw_cm_filtered` (draw() of a filtered source) to the `fb_*` Flash model (s26 playbook §25: S), and fit it to the draw_filtered Flash rows.
3. GradientGlow / GradientBevel kernels (S each) if a Flash row covers them; otherwise build fixture SWFs and list them under LOCAL ORACLE REQUESTS (FLASH) for the coordinator.
4. Land both fixtures under `regression/` with **`output.txt` = the Flash capture** (exact). If a row cannot be matched exactly, say which, and why.
5. Sweep: every applyFilter/draw corpus row (pixel + trace), the s26/s27 applyFilter fixtures, and the render canary for GPU-filter rows (md5). `bitmapdata_applyfilter_blur` has a Flash capture too (`SWFRecompDocs/plans/flash-oracle-captures/bitmapdata_applyfilter_blur/flash.png`; text band unusable): use its non-text cells as an extra measure of the blur model.

Siblings: `w2-draw-cx-text` edits the CPU draw walk (`bd_draw_shape_walk`, `text_raster_core`) and `w2-applyfilter-cm` edits the AVM1 applyFilter arm. Keep to the kernel functions.
