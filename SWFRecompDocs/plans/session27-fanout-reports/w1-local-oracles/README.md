# s27 coordinator-run oracles

`oracle.png` / `ruffle.txt` / `out.*` = Ruffle exporter `0ddd12b6a` (`WGPU_BACKEND=vulkan`). `flash.png` / `flash*.txt` =
real Flash Player 32 (LNX 32,0,0,465) via `tools/flash-oracle/` (`run_image.py --screen`, the draw() capture is the PNG;
`run_trace.py --wrapped` unless named `flash.direct.txt`). **Flash overrules Ruffle.**

Notable Flash-vs-Ruffle verdicts:
- `w1-text-glyph-fidelity/avm1_bitmapdata_draw_edittext`, `avm2_bitmapdata_draw_edittext_box`: in Flash, `BitmapData.draw()`
  does NOT apply a colorTransform (the draw() argument or a parent's) to a TextField's BACKGROUND (stays ff0000), while
  a tinted shape IS tinted. Ruffle tints both. On screen, Flash does tint a placed field's box (see
  `regression/avm1_edittext_placed_cxform`, Flash == golden except the 4 border-corner pixels per box).
- `w1-text-glyph-fidelity/avm1_edittext_scaled_glyphs`: Flash ≈ Ruffle (corners + edge AA).
- `w1-text-glyph-fidelity/avm2_definetext_matrix`: Flash draw() == the analytic golden at 0 px.
- `avm1_edittext_wordwrap_render`: Flash-invalid font (see its README).
- `w1-applyfilter-tail/avm1_po3_cm_*`: `folded_clear` Flash == Ruffle; `live_under_cxform` Flash vs Ruffle max 1;
  `alpha_bias_edge`: Flash anti-aliases the rect's edge pixels at half coverage (x=110, y=80: (255,127,127)); Ruffle's
  is crisp. The interior is identical.
- `w1-render-bitmap-leads/*`: Flash == the hand goldens at 0 px (both fixtures).
- `w1-exec-order/*`: Flash == Ruffle for both fixtures (traces); ours differs on the nested `inner` frame order.
