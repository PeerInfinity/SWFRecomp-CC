# Graphics vs Trace Mode Differences

Trace: 1316/1352 passing | Graphics: 1322/1353 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (5 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `audio_computespectrum` | Output Mismatch | 0/118 lines match |
| 2 | `html_text_img_parsing` | Ruffle Matched | 505/600 lines match |
| 3 | `swf_9_goto_in_construct_frame` | Ruffle Matched | 8/20 lines match |
| 4 | `textblock_releaselines` | Ruffle Matched | 748/752 lines match |
| 5 | `textline_atom_index_at_char_index` | Ruffle Matched | 37/40 lines match |
