**AVM1 ColorMatrix leftovers and AVM1 `applyFilter` beyond ColorMatrix, against FLASH** (w1-applyfilter-tail items 3 and 5). Categories: `avm1`, `visual`, `regression`.

Fixtures (generators + SWFs): `session27-fanout-reports/w1-applyfilter-tail-fixtures/`. Oracles: `SWFRecompDocs/plans/session27-fanout-reports/w1-local-oracles/w1-applyfilter-tail/<fixture>/{flash.png,oracle.png,ruffle.txt}` (Flash Player 32 and Ruffle exporter).
- `avm1_po3_cm_folded_clear` (a folded CM survives `filters=[]`): Flash == Ruffle exactly. Fix ours and land with the Flash PNG.
- `avm1_po3_cm_live_under_cxform` (live CM under a placement cxform): Flash vs Ruffle max 1. Fix ours and land with the Flash PNG.
- `avm1_po3_cm_alpha_bias_edge` (alpha-bias >0 CM stays folded): Flash's interior equals Ruffle's (255,63,63), but **Flash anti-aliases the rect's edge pixels at half coverage** (x=110 and y=80 read (255,127,127)), where Ruffle is crisp. Find out why (is Flash rendering the filtered clip at a half-pixel offset, or filtering bounds AA?) and match Flash if the mechanism is clear. Otherwise land with the interior-only comparison documented.
- `avm1_applyfilter_convolution_not_cm` already landed (`456fef1bf`).

Also implement AVM1 `BitmapData.applyFilter` for Blur/Glow/DropShadow/Bevel/Convolution/Gradient* by bridging to the AVM2 CPU kernels (`avm2_bitmap.c` `bd_apply_filter` via a wrapper; `action.c bitmapDataApplyFilter` dispatches on `avm1FilterTypeOf` since `456fef1bf`). Priced S–M, 0 corpus rows (game fidelity). Build one fixture per kind and request FLASH images (LOCAL ORACLE REQUESTS); don't block on them.

Siblings: `w2-flash-filter-kernels` is changing the AVM2 kernels themselves (call them, don't edit them); `w2-draw-cx-text` edits `rasterizeMovieClipToBitmap`.
