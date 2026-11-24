# s27 wave-2 oracles (coordinator-run; Flash Player 32 LNX via tools/flash-oracle unless named ruffle*)

- `w2-jpeg-flash-decode/`: Flash 32 `BitmapDataDraw` trace (82944, stb's flat value, contradicts the IJG model);
  `acid-color-0` Flash PNG (quality low); the on-stage nearest-tie probe (draw() == ties-up; screen capture misaligned).
- `w2-layer-alpha-group/`: grouping probes, see README there.
- `w2-avm1-text-layout/avm1_edittext_wordwrap_render`: with the REBUILT (ascending code table) font Flash draws the
  glyphs, and its trace == the fixture's `output.txt`. Flash's PNG vs ours (and Ruffle's): ~590 channels of glyph-edge AA, max 63,
  so the landed fixture keeps the INTERIM Ruffle golden (ours passes it); the Flash glyph-AA delta is a HOLD.
- `w2-avm1-text-layout/avm1_edittext_rotated_glyphs`: Flash PNG; ours-after differs on 1111 px (max 255): HOLD (not landed).
- `w2-holder-drawing-full/avm1_textfield_attached_depth_order`: Flash == hand golden at 0 px → landed with the Flash PNG.
- `w2-avm2-text-tail/avm2_edittext_selection_cxform`: mxmlc-built `test.swf`; direct-mode trace `focus=true / sel=1,4`;
  the image wrapper loads the SWF as a child so `Test()` hits a null stage (#1009): the AS must wait for ADDED_TO_STAGE
  before an image capture is possible. HOLD.
- `w2-applyfilter-cm/avm1_applyfilter_*`: Flash PNG + trace per kind. Only `convolution` matches the cloud `ours`;
  blur/glow/dropshadow/bevel/gradient* differ heavily (renders and traces) — follow-up.
- `w2-flash-filter-kernels/avm2_applyfilter_gradient_opaque_probe`: Flash trace (30 lines differ from the provisional).
