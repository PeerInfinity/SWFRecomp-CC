**Pixels, glyph and text-render fidelity** (playbook §25 "Text and glyphs" minus wordWrap). Categories: `from_shumway`, `visual`, `avm1`, `avm2`, `fonts`, `regression`.

1. **EditText glyph compose rounding for scaled fields** (the field's matrix scales the glyph run; where do we round, and where does Ruffle/Flash: per glyph advance in twips, per line, or at device pixels?). Find rows (shumway acid-text-*, `visual/text/*`, regression fixtures) and price.
2. **DefineText matrix fidelity in the recompiler (M):** static text record matrices / glyph offsets vs Ruffle's `core/src/display_object/text.rs` (s26 rounded the glyph translation to whole twips in `5f4db0e60`; what still differs?).
3. **AVM2 static-text and `avm2_render_textbox` colour-transform twins**: AVM1 got EditText/static text under a cxform in s26 (`84e4fefc0`, `5f5304072`). Check the AVM2 render paths for the same gaps and build twin fixtures.
4. **`draw()` of a tinted EditText** (AVM1 and AVM2 `BitmapData.draw` with a colorTransform or a tinted source).
5. Re-test the `font_lookup_as3` and `definefont4` NO-GOs (cheap re-run plus mechanism check only).

Prototype any GO, measured, with a render-canary md5 sweep. Siblings: `w1-text-wordwrap` (soft wrap layout), `w1-applyfilter-tail` (draw/filters).
