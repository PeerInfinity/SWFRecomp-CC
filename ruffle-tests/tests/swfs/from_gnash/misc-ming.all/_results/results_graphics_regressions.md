# Graphics vs Trace Mode Differences

Trace: 66/102 passing | Graphics: 57/102 passing

## Graphics Regressions (9 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `ResolveEventsTest` | Output Mismatch | 13/15 lines match |
| 2 | `action_order/action_execution_order_test8-v5` | Output Mismatch | 9/11 lines match |
| 3 | `action_order/action_execution_order_test8-v6` | Output Mismatch | 9/11 lines match |
| 4 | `displaylist_depths/displaylist_depths_test8` | Output Mismatch | 9/16 lines match |
| 5 | `get_frame_number_test` | Output Mismatch | 28/31 lines match |
| 6 | `goto_frame_test` | Output Mismatch | 7/15 lines match |
| 7 | `place_and_remove_object_insane_test` | Output Mismatch | 15/22 lines match |
| 8 | `place_and_remove_object_test` | Output Mismatch | 9/13 lines match |
| 9 | `timeline_var_test` | Output Mismatch | 6/11 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
