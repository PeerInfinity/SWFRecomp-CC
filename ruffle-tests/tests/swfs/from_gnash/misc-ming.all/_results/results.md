# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-22 20:05 UTC

**Git SHA**: `f8cd1b5a24`

**Run Duration**: 25m 21s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **22** (21.6%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **33** (32.4%) |
| Failing | 69 |
| Total expected lines | 4541 |
| Matching lines | 2201 (48.5%) |
| Mismatched lines | 2340 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 68 | 98.6% |
| Compile Fail | 1 | 1.4% |

## Passing Tests

**22 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 28.3s |  |
| 2 | `PlaceObject2Test` | 9 | 18.1s |  |
| 3 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 4 | `Video-EmbedSquareTest` | 2 | 16.0s |  |
| 5 | `action_order/action_execution_order_test1` | 10 | 15.9s |  |
| 6 | `action_order/action_execution_order_test7` | 7 | 15.8s |  |
| 7 | `action_order/action_execution_order_test9` | 4 | 16.9s |  |
| 8 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.2s |  |
| 9 | `displaylist_depths/displaylist_depths_test4` | 26 | 15.9s |  |
| 10 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 11 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 12 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 13 | `getTimer_test` | 8 | 18.2s |  |
| 14 | `get_frame_number_test` | 31 | 20.3s |  |
| 15 | `loop/simple_loop_test` | 0 | 17.5s |  |
| 16 | `masks_test2` | 10 | 16.2s |  |
| 17 | `morph_test1` | 0 | 16.4s |  |
| 18 | `move_object_test` | 11 | 18.2s |  |
| 19 | `multi_doactions_and_goto_frame_test` | 6 | 17.8s |  |
| 20 | `shape_test` | 21 | 19.9s |  |
| 21 | `timeline_var_test` | 11 | 18.3s |  |
| 22 | `unload_movieclip_test1` | 6 | 17.9s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 16.1s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 3.0s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 16.0s |  |
| 4 | `attachExtImported` | 1 | 1 | 17.0s |  |
| 5 | `callFunction_test` | 5 | 11 | 19.8s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 18.6s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 19.4s |  |
| 8 | `path_format_test` | 27 | 28 | 17.5s |  |
| 9 | `place_object_test` | 14 | 14 | 17.5s |  |
| 10 | `place_object_test2` | 16 | 23 | 17.6s |  |
| 11 | `runtime_vm_stack_test` | 5 | 8 | 18.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**32 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15 | 18 | 3 |  |
| 3 | `loop/loop_test4` | 81.8% | 18 | 22 | 4 |  |
| 4 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 5 | `place_and_remove_object_test` | 76.9% | 10 | 13 | 3 |  |
| 6 | `static_vs_dynamic1` | 76.5% | 13 | 17 | 4 |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 8 | `attachMovieTest` | 75.0% | 9 | 12 | 3 |  |
| 9 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 10 | `loop/loop_test9` | 73.3% | 11 | 15 | 4 |  |
| 11 | `action_order/action_execution_order_test8-v5` | 72.7% | 8 | 11 | 3 |  |
| 12 | `action_order/action_execution_order_test8-v6` | 72.7% | 8 | 11 | 3 |  |
| 13 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 14 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 15 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 16 | `event_handler_scope_test` | 68.8% | 11 | 16 | 5 |  |
| 17 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 18 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 19 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 20 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 21 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 22 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 23 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 24 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 25 | `loop/loop_test7` | 53.3% | 8 | 15 | 7 |  |
| 26 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 27 | `loop/loop_test5` | 52.0% | 13 | 25 | 12 |  |
| 28 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 29 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9 | 18 | 9 |  |
| 30 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |
| 32 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**68 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15/18 | 18 | 18 |  |
| 3 | `loop/loop_test4` | 81.8% | 18/22 | 22 | 22 |  |
| 4 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 5 | `place_and_remove_object_test` | 76.9% | 10/13 | 13 | 13 |  |
| 6 | `static_vs_dynamic1` | 76.5% | 13/17 | 17 | 17 |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 8 | `attachMovieTest` | 75.0% | 9/12 | 12 | 12 |  |
| 9 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 10 | `loop/loop_test9` | 73.3% | 11/15 | 15 | 15 |  |
| 11 | `action_order/action_execution_order_test8-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 12 | `action_order/action_execution_order_test8-v6` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 14 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 15 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 16 | `event_handler_scope_test` | 68.8% | 11/16 | 16 | 16 |  |
| 17 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 18 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 19 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 20 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 21 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 22 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 23 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 24 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 25 | `loop/loop_test7` | 53.3% | 8/15 | 14 | 15 |  |
| 26 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 27 | `loop/loop_test5` | 52.0% | 13/25 | 25 | 24 |  |
| 28 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 29 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9/18 | 18 | 15 |  |
| 30 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 32 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 33 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 34 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 35 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 36 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 37 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 38 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 39 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 40 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 41 | `loop/loop_test` | 33.3% | 7/21 | 21 | 21 |  |
| 42 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 43 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 44 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 45 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 46 | `goto_frame_test` | 20.0% | 3/15 | 13 | 15 |  |
| 47 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 48 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 49 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 50 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 51 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 52 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 53 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 54 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 55 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 56 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 57 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 58 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 59 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 60 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 61 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 62 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 63 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 64 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 65 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 66 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 67 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 68 | `replace_shapes1test` | 0.0% | 0/29 | 29 | 23 |  |
