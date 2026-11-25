# Graphics vs Trace Mode Differences

Trace: 1298/1346 passing | Graphics: 1293/1346 passing

## Graphics Regressions (6 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `array_access_oob_interpreter` | Ruffle Matched | 0/3 lines match |
| 2 | `edittext_getcharboundaries_missing_embedded_font` | Ruffle Matched | 4/7 lines match |
| 3 | `encode_uri_surrogate_pair_swf10` | Ruffle Matched | 0/15 lines match |
| 4 | `graphics_draw_path` | Ruffle Matched | 51/101 lines match |
| 5 | `groupelement_text` | Ruffle Matched | 154/156 lines match |
| 6 | `vector_indexing_cutoffs` | Ruffle Matched | 17/18 lines match |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `audio_computespectrum` | Output Mismatch | 0/118 lines match |
