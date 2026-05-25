# Graphics vs Trace Mode Differences

Trace: 66/110 passing | Graphics: 66/110 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `place_and_remove_object_insane_test` | Output Mismatch | 16/22 lines match |

## Graphics Improvements (1 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `action_order/action_execution_order_test` | Output Mismatch | 7/19 lines match |
