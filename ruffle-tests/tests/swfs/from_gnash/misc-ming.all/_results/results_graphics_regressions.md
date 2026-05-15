# Graphics vs Trace Mode Differences

Trace: 64/110 passing | Graphics: 62/110 passing

## Graphics Regressions (2 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `action_order/action_execution_order_test` | Output Mismatch | 16/19 lines match |
| 2 | `place_and_remove_object_insane_test` | Output Mismatch | 16/22 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
