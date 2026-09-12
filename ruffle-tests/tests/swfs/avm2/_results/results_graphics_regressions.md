# Graphics vs Trace Mode Differences

Trace: 1200/1270 passing | Graphics: 1205/1274 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (5 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `bitmap_filter_abstract` | Output Mismatch | 0/6 lines match |
| 2 | `bytearray_bad_symbol_class` | Output Mismatch | 1/3 lines match |
| 3 | `bytearray_bad_symbol_class_other_movie` | Output Mismatch | 4/6 lines match |
| 4 | `json_parse_errors` | Output Mismatch | 4/84 lines match |
| 5 | `matrix3d_append_rotation` | Ruffle Matched | 22/23 lines match |
