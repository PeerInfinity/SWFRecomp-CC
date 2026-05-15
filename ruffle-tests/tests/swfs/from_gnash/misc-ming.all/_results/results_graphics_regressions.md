# Graphics vs Trace Mode Differences

Trace: 66/110 passing | Graphics: 62/110 passing

## Graphics Regressions (4 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `loop/loop_test` | Output Mismatch | 4/27 lines match |
| 2 | `loop/loop_test2` | Output Mismatch | 6/17 lines match |
| 3 | `loop/loop_test3` | Output Mismatch | 9/17 lines match |
| 4 | `place_and_remove_object_insane_test` | Output Mismatch | 16/22 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
