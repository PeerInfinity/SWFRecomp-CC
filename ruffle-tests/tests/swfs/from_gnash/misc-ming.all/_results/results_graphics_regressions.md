# Graphics vs Trace Mode Differences

Trace: 66/102 passing | Graphics: 52/102 passing

## Graphics Regressions (14 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `DepthLimitsTest` | Output Mismatch | 15/20 lines match |
| 2 | `ResolveEventsTest` | Output Mismatch | 13/15 lines match |
| 3 | `action_order/action_execution_order_test8-v5` | Output Mismatch | 9/11 lines match |
| 4 | `action_order/action_execution_order_test8-v6` | Output Mismatch | 9/11 lines match |
| 5 | `displaylist_depths/displaylist_depths_test8` | Output Mismatch | 9/16 lines match |
| 6 | `displaylist_depths/displaylist_depths_test9` | Output Mismatch | 3/23 lines match |
| 7 | `duplicate_movie_clip_test2` | Output Mismatch | 11/21 lines match |
| 8 | `get_frame_number_test` | Output Mismatch | 28/31 lines match |
| 9 | `goto_frame_test` | Output Mismatch | 7/15 lines match |
| 10 | `place_and_remove_object_insane_test` | Output Mismatch | 15/22 lines match |
| 11 | `place_and_remove_object_test` | Output Mismatch | 9/13 lines match |
| 12 | `static_vs_dynamic1` | Output Mismatch | 11/17 lines match |
| 13 | `static_vs_dynamic2` | Output Mismatch | 6/18 lines match |
| 14 | `timeline_var_test` | Output Mismatch | 6/11 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
