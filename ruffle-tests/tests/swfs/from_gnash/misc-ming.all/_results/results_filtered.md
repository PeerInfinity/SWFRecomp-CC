# Ruffle Test Results (Filtered)

**Date**: 2026-04-17 16:55 UTC

**Git SHA**: `b3deda13c6`

**Run Duration**: 21m 27s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **18** (17.6%) |
| Ruffle-matched | 10 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **28** (27.5%) |
| Failing | 74 |
| Total expected lines | 4541 |
| Matching lines | 2120 (46.7%) |
| Mismatched lines | 2421 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 73 | 98.6% |
| Compile Fail | 1 | 1.4% |

## Passing Tests

**18 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `PlaceObject2Test` | 9 | 15.2s |  |
| 2 | `VarAndCharClashTest` | 13 | 0.5s |  |
| 3 | `Video-EmbedSquareTest` | 2 | 15.6s |  |
| 4 | `action_order/action_execution_order_test1` | 10 | 15.1s |  |
| 5 | `action_order/action_execution_order_test7` | 7 | 15.6s |  |
| 6 | `action_order/action_execution_order_test9` | 4 | 15.6s |  |
| 7 | `displaylist_depths/displaylist_depths_test10` | 10 | 15.9s |  |
| 8 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.8s |  |
| 9 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.5s |  |
| 10 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.5s |  |
| 11 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.5s |  |
| 12 | `getTimer_test` | 8 | 15.4s |  |
| 13 | `loop/simple_loop_test` | 0 | 16.3s |  |
| 14 | `masks_test2` | 10 | 16.4s |  |
| 15 | `morph_test1` | 0 | 16.6s |  |
| 16 | `move_object_test` | 11 | 15.7s |  |
| 17 | `multi_doactions_and_goto_frame_test` | 6 | 15.7s |  |
| 18 | `unload_movieclip_test1` | 6 | 15.3s |  |

## Ruffle-Matched Tests

**10 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 16.4s |  |
| 2 | `action_order/action_execution_order_test4` | 14 | 26 | 0.5s |  |
| 3 | `attachExtImported` | 1 | 1 | 15.5s |  |
| 4 | `callFunction_test` | 5 | 11 | 15.7s |  |
| 5 | `init_action/InitActionTest` | 17 | 17 | 16.3s |  |
| 6 | `init_action/InitActionTest2` | 30 | 30 | 16.5s |  |
| 7 | `path_format_test` | 28 | 28 | 15.8s |  |
| 8 | `place_object_test` | 14 | 14 | 15.8s |  |
| 9 | `place_object_test2` | 16 | 23 | 15.7s |  |
| 10 | `runtime_vm_stack_test` | 5 | 8 | 16.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**35 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DefineEditTextTest` | 95.4% | 146 | 153 | 7 |  |
| 2 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 3 | `get_frame_number_test` | 80.6% | 25 | 31 | 6 |  |
| 4 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 5 | `displaylist_depths/displaylist_depths_test11` | 80.0% | 12 | 15 | 3 |  |
| 6 | `place_and_remove_object_test` | 76.9% | 10 | 13 | 3 |  |
| 7 | `attachMovieTest` | 75.0% | 9 | 12 | 3 |  |
| 8 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 9 | `loop/loop_test9` | 73.3% | 11 | 15 | 4 |  |
| 10 | `action_order/action_execution_order_test8-v5` | 72.7% | 8 | 11 | 3 |  |
| 11 | `action_order/action_execution_order_test8-v6` | 72.7% | 8 | 11 | 3 |  |
| 12 | `new_child_in_unload_test` | 72.7% | 8 | 11 | 3 |  |
| 13 | `timeline_var_test` | 72.7% | 8 | 11 | 3 |  |
| 14 | `static_vs_dynamic2` | 72.2% | 13 | 18 | 5 |  |
| 15 | `shape_test` | 71.4% | 15 | 21 | 6 |  |
| 16 | `displaylist_depths/displaylist_depths_test` | 71.2% | 79 | 111 | 32 |  |
| 17 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 18 | `static_vs_dynamic1` | 70.6% | 12 | 17 | 5 |  |
| 19 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 20 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 21 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 22 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 23 | `event_handler_scope_test` | 62.5% | 10 | 16 | 6 |  |
| 24 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 25 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 26 | `DepthLimitsTest` | 60.0% | 12 | 20 | 8 |  |
| 27 | `loop/loop_test2` | 60.0% | 9 | 15 | 6 |  |
| 28 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 29 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 30 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 31 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 32 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 33 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |
| 34 | `loop/loop_test5` | 50.0% | 12 | 24 | 12 |  |
| 35 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**73 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DefineEditTextTest` | 95.4% | 146/153 | 153 | 153 |  |
| 2 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 3 | `get_frame_number_test` | 80.6% | 25/31 | 31 | 31 |  |
| 4 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 5 | `displaylist_depths/displaylist_depths_test11` | 80.0% | 12/15 | 15 | 15 |  |
| 6 | `place_and_remove_object_test` | 76.9% | 10/13 | 13 | 13 |  |
| 7 | `attachMovieTest` | 75.0% | 9/12 | 12 | 12 |  |
| 8 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 9 | `loop/loop_test9` | 73.3% | 11/15 | 15 | 15 |  |
| 10 | `action_order/action_execution_order_test8-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 11 | `action_order/action_execution_order_test8-v6` | 72.7% | 8/11 | 11 | 11 |  |
| 12 | `new_child_in_unload_test` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `timeline_var_test` | 72.7% | 8/11 | 11 | 11 |  |
| 14 | `static_vs_dynamic2` | 72.2% | 13/18 | 18 | 18 |  |
| 15 | `shape_test` | 71.4% | 15/21 | 21 | 21 |  |
| 16 | `displaylist_depths/displaylist_depths_test` | 71.2% | 79/111 | 111 | 111 |  |
| 17 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 18 | `static_vs_dynamic1` | 70.6% | 12/17 | 17 | 17 |  |
| 19 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 20 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 21 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 22 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 23 | `event_handler_scope_test` | 62.5% | 10/16 | 16 | 16 |  |
| 24 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 25 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 26 | `DepthLimitsTest` | 60.0% | 12/20 | 20 | 20 |  |
| 27 | `loop/loop_test2` | 60.0% | 9/15 | 15 | 15 |  |
| 28 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 29 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 30 | `loop/loop_test8` | 52.6% | 20/38 | 36 | 38 |  |
| 31 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 32 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 33 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 34 | `loop/loop_test5` | 50.0% | 12/24 | 23 | 24 |  |
| 35 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 36 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 37 | `loop/loop_test4` | 45.5% | 10/22 | 20 | 22 |  |
| 38 | `loop/loop_test6` | 43.5% | 10/23 | 22 | 23 |  |
| 39 | `DragDropTest` | 40.0% | 18/45 | 45 | 44 |  |
| 40 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 41 | `action_order/action_execution_order_test11` | 37.5% | 12/32 | 32 | 32 |  |
| 42 | `loop/loop_test` | 33.3% | 7/21 | 21 | 21 |  |
| 43 | `action_order/action_execution_order_test5` | 32.8% | 20/61 | 61 | 35 |  |
| 44 | `consecutive_goto_frame_test` | 30.8% | 4/13 | 13 | 12 |  |
| 45 | `loop/loop_test7` | 26.7% | 4/15 | 13 | 15 |  |
| 46 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 47 | `DrawingApiTest` | 21.5% | 20/93 | 93 | 93 |  |
| 48 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 49 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 50 | `action_order/action_execution_order_test2` | 20.0% | 1/5 | 5 | 5 |  |
| 51 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 52 | `register_class/RegisterClassTest3` | 15.4% | 2/13 | 13 | 12 |  |
| 53 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 54 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 55 | `goto_frame_test` | 13.3% | 2/15 | 13 | 15 |  |
| 56 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 57 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 58 | `masks_test` | 11.4% | 20/175 | 28 | 175 |  |
| 59 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 60 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 61 | `action_order/ActionOrderTest4` | 7.4% | 9/122 | 122 | 64 |  |
| 62 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 63 | `action_order/ActionOrderTest3` | 5.7% | 6/105 | 105 | 62 |  |
| 64 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 65 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 66 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 67 | `opcode_guard_test` | 2.1% | 3/142 | 142 | 18 |  |
| 68 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 69 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 70 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 15 | 24 |  |
| 71 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 72 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 73 | `replace_shapes1test` | 0.0% | 0/26 | 26 | 23 |  |
