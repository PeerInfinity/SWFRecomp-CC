# Ruffle Test Results Diff

**Previous:** `16314e63feaa` (2026-08-13T21:54:57.612282+00:00)
**Current:** `3db858cbc157` (2026-08-13T22:38:36.766928+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 69 | +69 |
| Total | 111 | 111 | 0 |
| Pass rate | 0.0% | 62.2% | +62.2% |
| Mismatched lines | 0 | 1195 | +1195 |
|   Increased | | | +1195 |

## Newly Passing (69)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `BeginBitmapFill` | compile_fail | - | 1/1 |
| `DefineEditTextTest` | compile_fail | - | 153/153 |
| `DefineEditTextVariableNameTest` | compile_fail | - | 72/72 |
| `DefineEditTextVariableNameTest2` | compile_fail | - | 39/39 |
| `DepthLimitsTest` | compile_fail | - | 20/20 |
| `PlaceObject2Test` | compile_fail | - | 9/9 |
| `ResolveEventsTest` | compile_fail | - | 15/15 |
| `RollOverOutTest` | compile_fail | - | 5/5 |
| `VarAndCharClashTest` | compile_fail | - | 13/13 |
| `Version4Loader` | compile_fail | - | 11/11 |
| `Video-EmbedSquareTest` | compile_fail | - | 2/2 |
| `action_order/action_execution_order_test1` | compile_fail | - | 10/10 |
| `action_order/action_execution_order_test2` | compile_fail | - | 5/5 |
| `action_order/action_execution_order_test3` | compile_fail | - | 4/4 |
| `action_order/action_execution_order_test5` | compile_fail | - | 35/35 |
| `action_order/action_execution_order_test7` | compile_fail | - | 7/7 |
| `action_order/action_execution_order_test8-v5` | compile_fail | - | 11/11 |
| `action_order/action_execution_order_test8-v6` | compile_fail | - | 11/11 |
| `action_order/action_execution_order_test9` | compile_fail | - | 4/4 |
| `attachExtImported` | compile_fail | - | 2/2 |
| `attachImported` | compile_fail | - | 2/2 |
| `attachMovieLoopingTest` | compile_fail | - | 41/41 |
| `attachMovieTest` | compile_fail | - | 12/12 |
| `consecutive_goto_frame_test` | compile_fail | - | 12/12 |
| `displaylist_depths/displaylist_depths_test10` | compile_fail | - | 10/10 |
| `displaylist_depths/displaylist_depths_test11` | compile_fail | - | 15/15 |
| `displaylist_depths/displaylist_depths_test4` | compile_fail | - | 26/26 |
| `displaylist_depths/displaylist_depths_test5` | compile_fail | - | 25/25 |
| `displaylist_depths/displaylist_depths_test6` | compile_fail | - | 13/13 |
| `displaylist_depths/displaylist_depths_test7` | compile_fail | - | 14/14 |
| `displaylist_depths/displaylist_depths_test8` | compile_fail | - | 15/15 |
| `displaylist_depths/displaylist_depths_test9` | compile_fail | - | 23/23 |
| `duplicate_movie_clip_test2` | compile_fail | - | 21/21 |
| `event_handler_scope_test` | compile_fail | - | 16/16 |
| `frame_label_test` | compile_fail | - | 17/17 |
| `getTimer_test` | compile_fail | - | 8/8 |
| `get_frame_number_test` | compile_fail | - | 31/31 |
| `gotoFrame2Test` | compile_fail | - | 9/9 |
| `goto_frame_test` | compile_fail | - | 15/15 |
| `instanceNameTest` | compile_fail | - | 5/5 |
| `loading/LoadVarsTest` | compile_fail | - | 36/36 |
| `loop/loop_test` | compile_fail | - | 21/21 |
| `loop/loop_test2` | compile_fail | - | 15/15 |
| `loop/loop_test3` | compile_fail | - | 16/16 |
| `loop/loop_test4` | compile_fail | - | 22/22 |
| `loop/loop_test5` | compile_fail | - | 24/24 |
| `loop/loop_test8` | compile_fail | - | 38/38 |
| `loop/loop_test9` | compile_fail | - | 15/15 |
| `loop/simple_loop_test` | compile_fail | - | 0/0 |
| `masks_test2` | compile_fail | - | 10/10 |
| `morph_test1` | compile_fail | - | 0/0 |
| `move_object_test` | compile_fail | - | 11/11 |
| `multi_doactions_and_goto_frame_test` | compile_fail | - | 6/6 |
| `new_child_in_unload_test` | compile_fail | - | 11/11 |
| `opcode_guard_test` | compile_fail | - | 18/18 |
| `place_and_remove_object_insane_test` | compile_fail | - | 22/22 |
| `place_and_remove_object_test` | compile_fail | - | 13/13 |
| `register_class/RegisterClassTest3` | compile_fail | - | 12/12 |
| `register_class/registerClassTest` | compile_fail | - | 51/51 |
| `replace_shapes1test` | compile_fail | - | 23/23 |
| `replace_sprites1test` | compile_fail | - | 21/21 |
| `reverse_execute_PlaceObject2_test1` | compile_fail | - | 8/8 |
| `reverse_execute_PlaceObject2_test2` | compile_fail | - | 10/10 |
| `runtime_vm_stack_test` | compile_fail | - | 9/9 |
| `shape_test` | compile_fail | - | 21/21 |
| `static_vs_dynamic1` | compile_fail | - | 17/17 |
| `static_vs_dynamic2` | compile_fail | - | 18/18 |
| `timeline_var_test` | compile_fail | - | 11/11 |
| `unload_movieclip_test1` | compile_fail | - | 6/6 |

## Status Changed (42)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `BitmapDataDraw` | compile_fail | ruffle_matched | - | 31/56 |
| `ButtonEventsTest` | compile_fail | ruffle_matched | - | 676/679 |
| `ButtonPropertiesTest` | compile_fail | ruffle_matched | - | 4/23 |
| `DefineTextTest` | compile_fail | ruffle_matched | - | 12/16 |
| `DragDropTest` | compile_fail | ruffle_matched | - | 40/44 |
| `DrawingApiTest` | compile_fail | output_mismatch | - | 81/93 |
| `EmbeddedFontTest` | compile_fail | ruffle_matched | - | 60/87 |
| `GradientFillTest` | compile_fail | output_mismatch | - | 119/278 |
| `KeyEventOrder` | compile_fail | ruffle_matched | - | 6/26 |
| `NetStream-SquareTest` | compile_fail | output_mismatch | - | 91/216 |
| `PrototypeEventListeners` | compile_fail | output_mismatch | - | 1/32 |
| `TextSnapshotTest` | compile_fail | ruffle_matched | - | 51/132 |
| `action_order/ActionOrderTest3` | compile_fail | output_mismatch | - | 4/62 |
| `action_order/ActionOrderTest4` | compile_fail | output_mismatch | - | 10/64 |
| `action_order/ActionOrderTest5` | compile_fail | output_mismatch | - | 6/51 |
| `action_order/PlaceAndRemove` | compile_fail | output_mismatch | - | 15/96 |
| `action_order/action_execution_order_extend_test` | compile_fail | output_mismatch | - | 7/32 |
| `action_order/action_execution_order_test` | compile_fail | ruffle_matched | - | 7/19 |
| `action_order/action_execution_order_test11` | compile_fail | output_mismatch | - | 26/32 |
| `action_order/action_execution_order_test4` | compile_fail | ruffle_matched | - | 19/26 |
| `action_order/action_execution_order_test6` | compile_fail | output_mismatch | - | 0/24 |
| `callFunction_test` | compile_fail | ruffle_matched | - | 5/11 |
| `displaylist_depths/displaylist_depths_test` | compile_fail | ruffle_matched | - | 104/111 |
| `displaylist_depths/displaylist_depths_test2` | compile_fail | ruffle_matched | - | 17/31 |
| `displaylist_depths/displaylist_depths_test3` | compile_fail | ruffle_matched | - | 19/32 |
| `duplicate_movie_clip_test` | compile_fail | ruffle_matched | - | 29/33 |
| `init_action/InitActionTest` | compile_fail | ruffle_matched | - | 11/17 |
| `init_action/InitActionTest2` | compile_fail | ruffle_matched | - | 5/29 |
| `key_event_test` | compile_fail | ruffle_matched | - | 61/66 |
| `loading/LoadBitmapTest` | compile_fail | ruffle_matched | - | 14/17 |
| `loading/loadMovieTest` | compile_fail | ruffle_matched | - | 71/80 |
| `loop/loop_test10` | compile_fail | ruffle_matched | - | 5/28 |
| `loop/loop_test6` | compile_fail | ruffle_matched | - | 22/23 |
| `loop/loop_test7` | compile_fail | ruffle_matched | - | 14/15 |
| `masks_test` | compile_fail | output_mismatch | - | 28/175 |
| `matrix_test` | compile_fail | ruffle_matched | - | 1081/1086 |
| `path_format_test` | compile_fail | ruffle_matched | - | 0/27 |
| `place_object_test` | compile_fail | ruffle_matched | - | 0/12 |
| `place_object_test2` | compile_fail | ruffle_matched | - | 0/19 |
| `register_class/RegisterClassTest4` | compile_fail | output_mismatch | - | 6/42 |
| `register_class/registerClassTest2` | compile_fail | ruffle_matched | - | 36/44 |
| `replace_buttons1test` | compile_fail | ruffle_matched | - | 15/18 |
