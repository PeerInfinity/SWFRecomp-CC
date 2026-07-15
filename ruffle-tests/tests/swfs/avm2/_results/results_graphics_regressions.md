# Graphics vs Trace Mode Differences

Trace: 821/1206 passing | Graphics: 829/1205 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (8 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `bitmapdata_zero_size` | Output Mismatch | 5/8 lines match |
| 2 | `coerce_property` | Ruffle Matched | 33/36 lines match |
| 3 | `event_handler_exception` | Output Mismatch | 1/11 lines match |
| 4 | `parse_float` | Output Mismatch | 80/81 lines match |
| 5 | `string_concat_fromcharcode` | Output Mismatch | 36/37 lines match |
| 6 | `string_slice_substr_substring` | Output Mismatch | 169/170 lines match |
| 7 | `uncaught_errors_stringified` | Output Mismatch | 1/18 lines match |
| 8 | `xml_basic` | Output Mismatch | 32/33 lines match |
