# Graphics vs Trace Mode Differences

Trace: 626/701 passing | Graphics: 450/514 passing

## Graphics Regressions (4 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `array_shift` | Output Mismatch | 149/216 lines match |
| 2 | `set_target_2_swf6` | Output Mismatch | 12/13 lines match |
| 3 | `set_target_2_swf7` | Output Mismatch | 12/13 lines match |
| 4 | `virtual_property_special_recursion_double_swf6` | Output Mismatch | 3/11 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
