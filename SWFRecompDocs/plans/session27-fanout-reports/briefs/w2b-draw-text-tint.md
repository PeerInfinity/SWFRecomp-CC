**`draw()` TextField tint rules: device vs embedded, against FLASH** (follow-up to `w2-draw-cx-text`, landed `85cca4df6`). Categories: `avm2`, `avm1`, `regression`.

Read `session27-fanout-reports/w2-draw-cx-text-report.md`. Flash Player 32 (`SWFRecompDocs/plans/session27-fanout-reports/w2-local-oracles/w2-draw-cx-text/*/flash.direct.txt`; the AVM2 SWF is mxmlc-built and archived there):
- `avm2_bitmapdata_draw_text_glyph_cx`: **DEVICE field**: glyphs read neither red nor green under every tint (is the device glyph drawn at all in draw()?), and the box stays ff0000. **EMBEDDED field**: glyphs ARE tinted by the draw ct, a descendant cx and holder+ct, and the box IS tinted (ff00) under every tint. So the landed "box never tinted" rule is **device-only**: implement the embedded rule (box and glyphs tinted) in `bd_draw_tf_box` and the glyph layer.
- `avm1_bitmapdata_draw_text_glyph_cx`: device glyphs read neither colour in all 4 variants. AVM1 embedded twin: build one, and request FLASH.
- `avm1_bitmapdata_draw_child_color`: Flash `65280 / 65280 / 8323200 / 65535 / 16711680`. Land it as `regression/avm1_bitmapdata_draw_child_color` with this golden (fix ours where it differs; line 3 is `_alpha` on an opaque target).
Land each fixture with Flash's trace. Sweep every `draw` row plus `regression/avm2_bitmapdata_draw_textfield`.
