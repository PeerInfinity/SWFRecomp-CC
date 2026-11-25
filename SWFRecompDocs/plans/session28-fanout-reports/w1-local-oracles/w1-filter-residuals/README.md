# w1-filter-residuals local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX; images draw() wrapper HIGH)

| request | file | result |
|---|---|---|
| 1 `avm1_display_filter_growth_edge_scale` | `…edge_scale.flash.png` | vs our provisional master render: 3317 outliers (1153 px, max 255) at tol 2 — measure cases A–F per region |
| 2 `avm2_bevel_sample_isolation_probe` trace | `…isolation_probe.flash32.txt` | 681 lines; 356 lines differ from our provisional output — read Flash's B grid (`blur3/blur4`) and d (`bevel d… a…`) |
| 3a `regression/avm1_runtime_filters` | `avm1_runtime_filters.flash.png` | vs the Ruffle-exporter golden 2275 px / max 56; vs the prototype after-render 1290 px (>2) — grade the DropShadow region (case D bbox (43,173)–(168,253)) |
| 3b `regression/avm1_nested_po3_filters` | `avm1_nested_po3_filters.flash.png` | vs golden 1006 px / max 9; **vs the prototype after-render: 0 px** → Flash == part B exactly; re-golden to Flash |
| also | `../w1-acid-flash/visual_filters_drop_shadow.png` (draw), `../w1-text-glyph-aa/png/visual__filters__drop_shadow__output.direct.png`, `…edittext_scroll…direct.png` | Flash captures of the 3 corpus losses (Ruffle goldens) for the RvF pricing |
