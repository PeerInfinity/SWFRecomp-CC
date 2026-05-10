# Graphics vs Trace Mode Differences

Trace: 66/102 passing | Graphics: 43/102 passing

## Graphics Regressions (23 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `DefineEditTextVariableNameTest` | Segfault | SIGSEGV |
| 2 | `DepthLimitsTest` | Output Mismatch | 15/20 lines match |
| 3 | `ResolveEventsTest` | Output Mismatch | 12/15 lines match |
| 4 | `Version4Loader` | Output Mismatch | 0/11 lines match |
| 5 | `action_order/action_execution_order_test2` | Output Mismatch | 1/5 lines match |
| 6 | `action_order/action_execution_order_test8-v5` | Output Mismatch | 9/11 lines match |
| 7 | `action_order/action_execution_order_test8-v6` | Output Mismatch | 9/11 lines match |
| 8 | `consecutive_goto_frame_test` | Output Mismatch | 5/201 lines match |
| 9 | `displaylist_depths/displaylist_depths_test8` | Output Mismatch | 9/16 lines match |
| 10 | `displaylist_depths/displaylist_depths_test9` | Output Mismatch | 3/23 lines match |
| 11 | `duplicate_movie_clip_test2` | Output Mismatch | 10/83 lines match |
| 12 | `event_handler_scope_test` | Output Mismatch | 11/91 lines match |
| 13 | `frame_label_test` | Output Mismatch | 0/17 lines match |
| 14 | `get_frame_number_test` | Output Mismatch | 28/31 lines match |
| 15 | `goto_frame_test` | Output Mismatch | 7/15 lines match |
| 16 | `loop/loop_test8` | Output Mismatch | 35/38 lines match |
| 17 | `place_and_remove_object_insane_test` | Output Mismatch | 15/22 lines match |
| 18 | `place_and_remove_object_test` | Output Mismatch | 9/13 lines match |
| 19 | `replace_shapes1test` | Output Mismatch | 8/23 lines match |
| 20 | `shape_test` | Output Mismatch | 13/21 lines match |
| 21 | `static_vs_dynamic1` | Output Mismatch | 11/17 lines match |
| 22 | `static_vs_dynamic2` | Output Mismatch | 6/18 lines match |
| 23 | `timeline_var_test` | Output Mismatch | 6/11 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
