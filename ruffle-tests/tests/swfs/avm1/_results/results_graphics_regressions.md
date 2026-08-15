# Graphics vs Trace Mode Differences

Trace: 674/718 passing | Graphics: 681/725 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (4 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `textfield_asbroadcaster` | Output Mismatch | 0/14 lines match |
| 2 | `watch_recursion_double_swf7` | Output Mismatch | 409/3118 lines match |
| 3 | `watch_recursion_swf7` | Output Mismatch | 1036/1048 lines match |
| 4 | `watch_virtual_property` | Output Mismatch | 9/60 lines match |
