# Graphics vs Trace Mode Differences

Trace: 625/701 passing | Graphics: 450/514 passing

## Graphics Regressions (3 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `array_shift` | Output Mismatch | 149/216 lines match |
| 2 | `set_target_2_swf6` | Output Mismatch | 12/13 lines match |
| 3 | `set_target_2_swf7` | Output Mismatch | 12/13 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
