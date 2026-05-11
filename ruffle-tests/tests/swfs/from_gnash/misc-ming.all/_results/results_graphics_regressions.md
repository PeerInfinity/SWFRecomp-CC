# Graphics vs Trace Mode Differences

Trace: 66/102 passing | Graphics: 62/102 passing

## Graphics Regressions (4 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `displaylist_depths/displaylist_depths_test8` | Output Mismatch | 9/16 lines match |
| 2 | `place_and_remove_object_insane_test` | Output Mismatch | 15/22 lines match |
| 3 | `place_and_remove_object_test` | Output Mismatch | 9/13 lines match |
| 4 | `timeline_var_test` | Output Mismatch | 6/11 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
