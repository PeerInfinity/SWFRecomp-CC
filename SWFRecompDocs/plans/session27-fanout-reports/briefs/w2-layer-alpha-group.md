**Layer-group alpha as a transparency group** (Flash oracle settled s26's N3 hold). Categories: `visual`, `avm2`, `avm1`, `regression`.

**Evidence (Flash Player 32):** `SWFRecompDocs/plans/flash-oracle-captures/n3_layer_alpha/flash.{high,low}.png` are captures of `SWFRecompDocs/plans/session26-fanout-reports/w1-pixel-layer-colour-fixtures/probes/n3_layer_alpha.swf` (`num_ticks = 1`, screen == draw() at both qualities). At the overlap pixel (80,50) Flash gives **(128,128,255)**. That is, a `blendMode = LAYER` clip with alpha composites its children opaquely into an offscreen group and then applies the alpha ONCE. Ours and Ruffle's per-child model give (127,63,191). Ruffle is wrong here, so its exporter golden is invalid (s26 `w1-pixel-layer-colour-report.md` N3).

1. Implement transparency-group alpha for LAYER (and check which other cases Flash groups: alpha on a clip with blendMode != NORMAL, filters, cacheAsBitmap; read the s25 layer-groups work, AVM1 + AVM2, `tag.c` layer-group render and `avm2_display.c`). Where we already render a layer group into an offscreen target, the fix may be "apply group alpha at composite instead of per child".
2. Fixture `regression/layer_group_alpha_transparency` (AVM1) plus an AVM2 twin, built from the probe. The golden is the **Flash PNG** (tolerance per the Flash-vs-our-AA band: measure it and justify it; quality high).
3. Price corpus rows with LAYER + alpha (static scan) and run a render-canary md5 sweep. Ruffle-golden rows that move away from Ruffle toward Flash are priced losses: disposition them (RvF + `<!-- image-axis -->`).

The s26 layer-group fixtures (`layer_group_filtered_child`, `avm2_layer_group_filtered_child`, `avm2_layer_group_alpha`) must stay green, or move with a Flash justification.
