# Graphics vs Trace Mode Differences

Trace: 1200/1270 passing | Graphics: 1213/1274 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (11 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `bitmap_filter_abstract` | Output Mismatch | 0/6 lines match |
| 2 | `bitmapdata_copypixels_alpha_merge` | Ruffle Matched | 5/9 lines match |
| 3 | `bytearray_bad_symbol_class` | Output Mismatch | 1/3 lines match |
| 4 | `bytearray_bad_symbol_class_other_movie` | Output Mismatch | 4/6 lines match |
| 5 | `displayobject_getrect` | Output Mismatch | 11/16 lines match |
| 6 | `displayobject_z` | Output Mismatch | 6/38 lines match |
| 7 | `edittext_scroll_event` | Output Mismatch | 2/37 lines match |
| 8 | `geom_transform` | Output Mismatch | 71/74 lines match |
| 9 | `id3_info` | Output Mismatch | 0/8 lines match |
| 10 | `json_parse_errors` | Output Mismatch | 4/84 lines match |
| 11 | `matrix3d_append_rotation` | Ruffle Matched | 22/23 lines match |
