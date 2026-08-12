# Graphics vs Trace Mode Differences

Trace: 674/718 passing | Graphics: 676/718 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (2 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `watch_recursion_double_swf7` | Output Mismatch | 409/3118 lines match |
| 2 | `watch_recursion_swf7` | Output Mismatch | 1036/1048 lines match |
