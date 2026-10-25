# Graphics vs Trace Mode Differences

Trace: 0/111 passing | Graphics: 69/111 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (69 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `BeginBitmapFill` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 2 | `DefineEditTextTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 3 | `DefineEditTextVariableNameTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 4 | `DefineEditTextVariableNameTest2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 5 | `DepthLimitsTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 6 | `PlaceObject2Test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 7 | `ResolveEventsTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 8 | `RollOverOutTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 9 | `VarAndCharClashTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 10 | `Version4Loader` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 11 | `Video-EmbedSquareTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 12 | `action_order/action_execution_order_test1` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 13 | `action_order/action_execution_order_test2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 14 | `action_order/action_execution_order_test3` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 15 | `action_order/action_execution_order_test5` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 16 | `action_order/action_execution_order_test7` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 17 | `action_order/action_execution_order_test8-v5` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 18 | `action_order/action_execution_order_test8-v6` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 19 | `action_order/action_execution_order_test9` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 20 | `attachExtImported` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 21 | `attachImported` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 22 | `attachMovieLoopingTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 23 | `attachMovieTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 24 | `consecutive_goto_frame_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 25 | `displaylist_depths/displaylist_depths_test10` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 26 | `displaylist_depths/displaylist_depths_test11` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 27 | `displaylist_depths/displaylist_depths_test4` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 28 | `displaylist_depths/displaylist_depths_test5` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 29 | `displaylist_depths/displaylist_depths_test6` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 30 | `displaylist_depths/displaylist_depths_test7` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 31 | `displaylist_depths/displaylist_depths_test8` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 32 | `displaylist_depths/displaylist_depths_test9` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 33 | `duplicate_movie_clip_test2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 34 | `event_handler_scope_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 35 | `frame_label_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 36 | `getTimer_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 37 | `get_frame_number_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 38 | `gotoFrame2Test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 39 | `goto_frame_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 40 | `instanceNameTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 41 | `loading/LoadVarsTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 42 | `loop/loop_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 43 | `loop/loop_test2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 44 | `loop/loop_test3` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 45 | `loop/loop_test4` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 46 | `loop/loop_test5` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 47 | `loop/loop_test8` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 48 | `loop/loop_test9` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 49 | `loop/simple_loop_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 50 | `masks_test2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 51 | `morph_test1` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 52 | `move_object_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 53 | `multi_doactions_and_goto_frame_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 54 | `new_child_in_unload_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 55 | `opcode_guard_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 56 | `place_and_remove_object_insane_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 57 | `place_and_remove_object_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 58 | `register_class/RegisterClassTest3` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 59 | `register_class/registerClassTest` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 60 | `replace_shapes1test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 61 | `replace_sprites1test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 62 | `reverse_execute_PlaceObject2_test1` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 63 | `reverse_execute_PlaceObject2_test2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 64 | `runtime_vm_stack_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 65 | `shape_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 66 | `static_vs_dynamic1` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 67 | `static_vs_dynamic2` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 68 | `timeline_var_test` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 69 | `unload_movieclip_test1` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
