# Graphics vs Trace Mode Differences

Trace: 68/111 passing | Graphics: 66/111 passing

## Graphics Regressions (2 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `place_and_remove_object_insane_test` | Output Mismatch | 17/22 lines match |
| 2 | `static_vs_dynamic2` | Output Mismatch | 15/18 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
