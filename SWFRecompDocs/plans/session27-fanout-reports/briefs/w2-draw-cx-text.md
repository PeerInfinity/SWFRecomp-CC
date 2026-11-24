**`BitmapData.draw()` fidelity: descendant colour transforms and TextFields, AVM1 + AVM2, against FLASH** (w1-text-glyph-fidelity §4, leads 3–4). Categories: `avm2`, `avm1`, `visual`, `from_shumway`, `regression`.

Measured gaps (`session27-fanout-reports/w1-text-glyph-fidelity-report.md` §4):
- **AVM1** `rasterizeMovieClipToBitmap` (`action.c`) paints nothing for a TextField (box and glyphs), and never composes a child clip's `Color`.
- **AVM2** `draw(tf)` paints glyphs only (no box; `bd_draw_textfield` → `text_raster_core`). `bd_draw_shape_walk` threads only alpha, so every descendant colorTransform (shapes, bitmaps, text) is dropped.

**FLASH verdicts (coordinator-run, Flash Player 32; `SWFRecompDocs/plans/session27-fanout-reports/w1-local-oracles/w1-text-glyph-fidelity/*/flash.txt`, README `SWFRecompDocs/plans/session27-fanout-reports/w1-local-oracles/README.md`):**
- `avm1_bitmapdata_draw_edittext`: Flash prints `16711680` on all three lines. **In `draw()`, neither the draw colorTransform nor a parent `Color` tints a TextField's background.** The by-construction golden (and Ruffle) expected 65280 on lines 2–3, which is wrong.
- `avm2_bitmapdata_draw_edittext_box`: `A draw(tf) = ff0000`, `A draw(tf, ct) = ff0000`, `B draw(holder>tinted tf) = ff0000`, `B draw(holder>tinted shape) = ff00`, `C tf.background(timeline-less) = true`. **Shapes ARE tinted by a descendant cx; the text box is NOT.**
- Characterize the glyph colour too. Build fixtures that read glyph pixels under draw ct / parent tint, and put them under LOCAL ORACLE REQUESTS (FLASH trace) so the coordinator can run them; until then implement the box rule above and leave glyph tint as today (AVM2 applies the draw ct to glyphs, pinned by `regression/avm2_bitmapdata_draw_textfield`).

1. AVM2: add a running `Avm2Cx` through `bd_draw_shape_walk`, applied per leaf (shapes, morphs, bitmaps, static text, text glyphs per the Flash characterization). Draw the TextField box in `text_raster_core`, untinted per Flash.
2. AVM1: a TextField arm in `rasterizeMovieClipToBitmap` (box from the props `actionIterateTextFields` reads, untinted; glyphs via the AVM2 CPU glyph raster: `glyph_raster_core` is `static` in `avm2_bitmap.c`, so expose a wrapper), and compose the child clip's cx in the child recursion.
3. Land the two fixtures with **Flash's trace as `output.txt`** (the generators are in `session27-fanout-reports/w1-text-glyph-fidelity-fixtures/`; the AVM2 one is built by mxmlc (`~/CC/flex-sdk` does not exist in the cloud), so its `test.swf` is archived at `SWFRecompDocs/plans/session27-fanout-reports/w1-local-oracles/w1-text-glyph-fidelity/avm2_bitmapdata_draw_edittext_box/test.swf`).
4. Sweep: every corpus row that calls `draw` (pixel and trace), the s26 draw fixtures (`avm1_*draw*`, `avm2_bitmapdata_draw_*`), and the canary.

Siblings: `w2-flash-filter-kernels` (kernel functions in `avm2_bitmap.c`; don't touch `bd_apply_filter` or `bd_draw_cm_filtered`), `w2-avm1-text-layout` (AVM1 EditText layout in `tag.c`/`action.c` glyph iterators). Name every `action.c` function you touch.
