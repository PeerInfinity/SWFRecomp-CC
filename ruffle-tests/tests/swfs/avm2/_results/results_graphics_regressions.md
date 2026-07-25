# Graphics vs Trace Mode Differences

Trace: 829/1217 passing | Graphics: 835/1217 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (6 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `date` | Output Mismatch | 15/30 lines match |
| 2 | `date_parse` | Output Mismatch | 2/36 lines match |
| 3 | `parse_float` | Output Mismatch | 80/81 lines match |
| 4 | `string_concat_fromcharcode` | Output Mismatch | 36/37 lines match |
| 5 | `string_slice_substr_substring` | Output Mismatch | 169/170 lines match |
| 6 | `xml_basic` | Output Mismatch | 32/33 lines match |
