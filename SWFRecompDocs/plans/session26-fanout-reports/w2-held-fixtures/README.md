# s26 wave-2 fixtures HELD out of `regression/` (no outside-oracle golden yet)

- `avm2_applyfilter_glow_kernels` (w2-avm2-applyfilter-kernels): the Ruffle exporter `0ddd12b6a` trace
  (`output.ruffle-0ddd12b6a.txt`) differs from our output by ±1–2 on single channels in 6 of 23 lines (glow quality3,
  bevel default/outer/full-knockout). Lead: f32 uv / rounding at texel boundaries in `bd_glowlike_source_region`. Land
  the fixture with Ruffle's trace once those match (or a Flash capture says otherwise).
- `avm2_bitmapdata_draw_filtered` (same slot): Flash model (Ruffle's draw() ignores filters by design); needs a FLASH
  capture.
