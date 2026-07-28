# Graphics vs Trace Mode Differences

Trace: 5/11 passing | Graphics: 9/11 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (4 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `text_caret_placement_align` | Output Mismatch | 189/248 lines match |
| 2 | `text_caret_placement_leading` | Output Mismatch | 183/244 lines match |
| 3 | `text_caret_placement_scroll` | Output Mismatch | 81/108 lines match |
| 4 | `text_caret_placement_translated_bounds` | Output Mismatch | 134/140 lines match |
