**Transparency-group alpha for the other Flash grouping triggers** (follow-up to `w2-layer-alpha-group`, landed `fb6fe4ba4`). Categories: `visual`, `avm2`, `avm1`, `from_shumway`, `from_gnash`, `regression`.

`fb6fe4ba4` made a LAYER clip's alpha (and its ancestors' alpha) apply once to the group composite (`tag.c lga_*`, `render_webgpu_set_group_alpha`, AVM2 twin). Read `session27-fanout-reports/w2-layer-alpha-group-report.md`. **Flash Player 32 verdicts on its probes** (`SWFRecompDocs/plans/session27-fanout-reports/w2-local-oracles/w2-layer-alpha-group/README.md`, PNGs alongside; pixel (80,50); grouped = (128,128,255)):
- `n3g_filter_cm` (identity ColorMatrixFilter + 50 % alpha): **GROUPED** in Flash. Ours is per child.
- `n3g_multiply` (MULTIPLY + 50 % on white): **GROUPED** in Flash (screen == draw). Ours is per child.
- `n3g_layer_aadd` (LAYER, alpha mult 1, offset −128): **GROUPED** (128,128,254). Ours (128,64,191).
- `n3g_cab` (cacheAsBitmap + 50 %): **per child** in Flash (128,65,192). Keep it per child.
- `n3g_layer_inner`: grouped, as the landed patch assumes.

1. Extend the group-alpha model to filtered clips (the filter offscreen is already a group: apply the alpha at its composite, not per leaf), to every non-NORMAL blend mode (the blend layer is a group), and to alpha OFFSETS on a grouping clip (the alpha row becomes `a' = a·m + o` at the group composite; derive Flash's exact arithmetic from the aadd probe: (128,128,254)).
2. Turn each probe into a `regression/` fixture (AVM1; plus AVM2 twins where cheap), golden = the Flash PNG. The probe SWFs are in `session27-fanout-reports/w2-layer-alpha-group-fixtures/probes/`. Use `--screen`-equivalent captures; screen == draw() for all of them.
3. **This WILL move corpus rows** (filters + alpha and blend modes + alpha are common). Sweep every filter / blend-mode image row plus the canary (md5). Per moved row, say whether it moves toward or away from its golden and who made that golden (Ruffle-made goldens moving away = priced Flash-over-Ruffle losses: disposition them; a Flash golden moving away = your bug).

Siblings: `w2-flash-filter-kernels` (CPU kernels in `avm2_bitmap.c`), `w2-applyfilter-cm` (`tag.c render_filtered_core` CM arms: coordinate by keeping your change at the composite call sites), `w2-holder-drawing-full` (attached render pass).
