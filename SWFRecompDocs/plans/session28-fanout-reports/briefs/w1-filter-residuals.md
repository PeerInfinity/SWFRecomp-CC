**Filter residuals vs Flash (M): applyFilter DropShadow residual, applyFilter Bevel sample residual, group-alpha
probe `w2b_shadow_shape_a50` (768 px; root SHAPE + DropShadow + 50% alpha; probe generator
`session27-fanout-reports/w2b-group-alpha-triggers-fixtures/mkprobes_w2b.py`, Flash capture in `w2-local-oracles/`); price the GPU display-filter growth NO-GO.**

Record: `session27-fanout-reports/w2b-filter-kernels-residual-report.md` (Bevel sample residual, GPU growth),
`w2b-avm1-applyfilter-flash-report.md`, `w2-flash-filter-kernels-report.md`, `w2b-group-alpha-triggers-report.md`
(`shadow_shape_a50` 768 px). Flash captures for these fixtures are archived under `session27-fanout-reports/` (grep
`w2-local-oracles/`, `flash-oracle-captures/`). `avm2/bitmapdata_applyfilter_blur` is a priced Ruffle-golden loss
(ACCEPTED Cat 2 + RvF): never move it toward Ruffle.

Task:
1. For each residual, diff our output against the Flash capture per pixel (maps, not totals), and name the mechanism:
   kernel taps, edge growth, quantization/premultiply order, knockout/inner composition, or group-alpha order.
2. Prototype what closes it (`avm2_bitmap.c` `bd_apply_filter` kernels; `tag.c` / `avm2_display.c` group composite;
   `render_webgpu.c` filter passes — `MSAA_SAMPLES`, never a literal 4).
3. GPU display-filter growth: NO-GO of record. Re-price it only from a Flash capture: write one fixture (a glow +
   dropshadow on a display object near the stage edge and under scale) as a FLASH image request, and state what our
   growth model would need to match.
4. Gate: render canary + every image row with `filter` in its path/name + the `regression` filter fixtures.
