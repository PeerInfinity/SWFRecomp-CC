# Graphics vs Trace Mode Differences

Trace: 69/111 passing | Graphics: 0/111 passing

## Graphics Regressions (69 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `BeginBitmapFill` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 2 | `DefineEditTextTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 3 | `DefineEditTextVariableNameTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 4 | `DefineEditTextVariableNameTest2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 5 | `DepthLimitsTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 6 | `PlaceObject2Test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 7 | `ResolveEventsTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 8 | `RollOverOutTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 9 | `VarAndCharClashTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 10 | `Version4Loader` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 11 | `Video-EmbedSquareTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 12 | `action_order/action_execution_order_test1` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 13 | `action_order/action_execution_order_test2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 14 | `action_order/action_execution_order_test3` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 15 | `action_order/action_execution_order_test5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 16 | `action_order/action_execution_order_test7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 17 | `action_order/action_execution_order_test8-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 18 | `action_order/action_execution_order_test8-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 19 | `action_order/action_execution_order_test9` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 20 | `attachExtImported` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 21 | `attachImported` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 22 | `attachMovieLoopingTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 23 | `attachMovieTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 24 | `consecutive_goto_frame_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 25 | `displaylist_depths/displaylist_depths_test10` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 26 | `displaylist_depths/displaylist_depths_test11` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 27 | `displaylist_depths/displaylist_depths_test4` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 28 | `displaylist_depths/displaylist_depths_test5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 29 | `displaylist_depths/displaylist_depths_test6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 30 | `displaylist_depths/displaylist_depths_test7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 31 | `displaylist_depths/displaylist_depths_test8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 32 | `displaylist_depths/displaylist_depths_test9` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 33 | `duplicate_movie_clip_test2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 34 | `event_handler_scope_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 35 | `frame_label_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 36 | `getTimer_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 37 | `get_frame_number_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 38 | `gotoFrame2Test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 39 | `goto_frame_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 40 | `instanceNameTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 41 | `loading/LoadVarsTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 42 | `loop/loop_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 43 | `loop/loop_test2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 44 | `loop/loop_test3` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 45 | `loop/loop_test4` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 46 | `loop/loop_test5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 47 | `loop/loop_test8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 48 | `loop/loop_test9` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 49 | `loop/simple_loop_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 50 | `masks_test2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 51 | `morph_test1` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 52 | `move_object_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 53 | `multi_doactions_and_goto_frame_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 54 | `new_child_in_unload_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 55 | `opcode_guard_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 56 | `place_and_remove_object_insane_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 57 | `place_and_remove_object_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 58 | `register_class/RegisterClassTest3` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 59 | `register_class/registerClassTest` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 60 | `replace_shapes1test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 61 | `replace_sprites1test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 62 | `reverse_execute_PlaceObject2_test1` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 63 | `reverse_execute_PlaceObject2_test2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 64 | `runtime_vm_stack_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 65 | `shape_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 66 | `static_vs_dynamic1` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 67 | `static_vs_dynamic2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 68 | `timeline_var_test` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 69 | `unload_movieclip_test1` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
