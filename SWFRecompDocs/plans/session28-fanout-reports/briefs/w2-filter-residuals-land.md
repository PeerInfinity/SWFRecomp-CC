**Land the filter residuals against Flash (M).**

Inputs: `w1-filter-residuals-report.md` (on master), `w1-filter-residuals-prototype.patch` (`tag.c`
`filter_shadow_offset_px`/`compose_chain_entry_to_layer`/`render_filtered_core` offset block; `avm2_display.c`
chain composer + `avm2_render_filtered`; `avm2_bitmap.c` `fb_glow_amount`), fixtures `w1-filter-residuals-fixtures/`,
and the coordinator's Flash 32 captures in `w1-local-oracles/w1-filter-residuals/` (README).

1. **Item 2 (clean GO):** land the `fb_glow_amount` quantization order + `regression/avm1_applyfilter_dropshadow` with
   its FP32 golden (trace + image). Both modes.
2. **Item 1 part B (fractional display DropShadow offset, bilinear):** Flash == your after-render on
   `avm1_nested_po3_filters` exactly → re-golden it to `avm1_nested_po3_filters.flash.png`. Grade
   `avm1_runtime_filters` per region vs its Flash capture (DropShadow bbox per the w1) and re-golden it to Flash if
   part B is Flash-exact there (state the residual elsewhere and set a budget). The 3 corpus losses
   (`visual/filters/drop_shadow`, `cache_as_bitmap/edittext_scroll` .01/.02) are Ruffle goldens: grade ours
   before/after vs the archived Flash captures (README "also" row) and draft RvF entries for the Flash-ward ones. Land
   the two group-alpha `shadow_shape_a50` rows (AVM1 + AVM2 twin) with the FP32 golden.
3. **Item 3 (bevel sample):** the Flash trace of `avm2_bevel_sample_isolation_probe` is in; fit the B grid and d,
   implement, and close `glow_kernels` / `draw_filtered` / gradient residual lines. Land the probe as a regression row
   with the Flash golden.
4. **Item 4 (GPU growth):** grade the Flash capture of `avm1_display_filter_growth_edge_scale` per case A–F; land the
   model if it's small (tail length/kernel taps), else a priced NO-GO with the measured cases; land the fixture with
   the Flash golden either way (budget the residual).
Gate: render canary + every `filter` image row + `regression` filter fixtures + the w1's 209-test list; both modes for
`fb_glow_amount`.
