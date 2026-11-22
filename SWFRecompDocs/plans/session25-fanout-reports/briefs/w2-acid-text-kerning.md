**DefineFont2/3 kerning on the AVM1/timeline EditText path → `from_shumway/acid/acid-text` (likely +1, M).** From `w1-pixel-text` §C (report on master).

The recompiler skips the DefineFont3 kerning table (`SWFRecomp/src/swf.cpp` ~2776, ~3056), and the AVM1 advance loop never applies kerning for `kerning="1"` HTML / `TextFormat.kerning`. Measure first, then implement:
1. Emit the kerning pairs (a sorted table per font, trailing struct fields) and apply them in the AVM1 EditText layout AND render advance (both must agree, or `textWidth`/`getCharBoundaries` traces diverge from the pixels). Ruffle: `core/src/font.rs` kerning lookup and where `edit_text`/`html` layout applies it.
2. `acid-text` runs at `quality = "low"`, tol 0, 3429 outliers. The coordinator's exporter render can't settle it: the exporter has no quality option, so it rendered at high (7572 channels vs the golden). Prove fidelity on your box first (before md5 == CI actual), then measure.
3. Risks to sweep (trace and pixel): every graded AVM1 EditText row with `kerning` set, every `textWidth`/`textHeight`/`getCharBoundaries`/`getLineMetrics` trace row (`avm1`, gnash `TextField*`, shumway), the s24 text canary set, and zero-headroom rows `text-bind`, `fallback_preferences`, `edittext_border_filters` (must stay md5-identical). `--recompile` throughout.

Sibling `w1-textfield-vn` is pricing gnash TextField-v6/7/8 (AVM1 EditText prototype/properties; may touch `action.c` TextField code). Keep your hunks to font tables and the advance loop, and list every function you touch.
