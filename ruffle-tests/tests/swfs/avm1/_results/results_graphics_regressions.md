# Graphics vs Trace Mode Differences

Trace: 631/705 passing | Graphics: 634/705 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `bitmapdata_hittest_threshold` | Output Mismatch | 5/6 lines match |
| 2 | `virtual_property_recursion_double_swf7` | Output Mismatch | 129/523 lines match |
| 3 | `virtual_property_recursion_scope` | Output Mismatch | 6/14 lines match |
