# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-22 21:35 UTC

**Git SHA**: `ca42bde6a1`

**Run Duration**: 22m 41s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **23** (22.5%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **34** (33.3%) |
| Failing | 68 |
| Total expected lines | 4541 |
| Matching lines | 2204 (48.5%) |
| Mismatched lines | 2337 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 67 | 98.5% |
| Compile Fail | 1 | 1.5% |

## Passing Tests

**23 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 16.9s |  |
| 2 | `PlaceObject2Test` | 9 | 17.0s |  |
| 3 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 4 | `Video-EmbedSquareTest` | 2 | 16.5s |  |
| 5 | `action_order/action_execution_order_test1` | 10 | 16.5s |  |
| 6 | `action_order/action_execution_order_test7` | 7 | 16.5s |  |
| 7 | `action_order/action_execution_order_test9` | 4 | 16.9s |  |
| 8 | `attachMovieTest` | 12 | 16.7s |  |
| 9 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.2s |  |
| 10 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.9s |  |
| 11 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 12 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 13 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 14 | `getTimer_test` | 8 | 13.7s |  |
| 15 | `get_frame_number_test` | 31 | 13.5s |  |
| 16 | `loop/simple_loop_test` | 0 | 16.0s |  |
| 17 | `masks_test2` | 10 | 16.0s |  |
| 18 | `morph_test1` | 0 | 16.1s |  |
| 19 | `move_object_test` | 11 | 17.1s |  |
| 20 | `multi_doactions_and_goto_frame_test` | 6 | 17.1s |  |
| 21 | `shape_test` | 21 | 16.6s |  |
| 22 | `timeline_var_test` | 11 | 16.2s |  |
| 23 | `unload_movieclip_test1` | 6 | 16.4s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 16.2s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.4s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 16.7s |  |
| 4 | `attachExtImported` | 1 | 1 | 17.1s |  |
| 5 | `callFunction_test` | 5 | 11 | 16.8s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 16.0s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 16.1s |  |
| 8 | `path_format_test` | 27 | 28 | 16.9s |  |
| 9 | `place_object_test` | 14 | 14 | 16.7s |  |
| 10 | `place_object_test2` | 16 | 23 | 16.6s |  |
| 11 | `runtime_vm_stack_test` | 5 | 8 | 16.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**31 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15 | 18 | 3 |  |
| 3 | `loop/loop_test4` | 81.8% | 18 | 22 | 4 |  |
| 4 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 5 | `place_and_remove_object_test` | 76.9% | 10 | 13 | 3 |  |
| 6 | `static_vs_dynamic1` | 76.5% | 13 | 17 | 4 |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 8 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 9 | `loop/loop_test9` | 73.3% | 11 | 15 | 4 |  |
| 10 | `action_order/action_execution_order_test8-v5` | 72.7% | 8 | 11 | 3 |  |
| 11 | `action_order/action_execution_order_test8-v6` | 72.7% | 8 | 11 | 3 |  |
| 12 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 13 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 14 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 15 | `event_handler_scope_test` | 68.8% | 11 | 16 | 5 |  |
| 16 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 17 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 18 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 19 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 20 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 21 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 22 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 23 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 24 | `loop/loop_test7` | 53.3% | 8 | 15 | 7 |  |
| 25 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 26 | `loop/loop_test5` | 52.0% | 13 | 25 | 12 |  |
| 27 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 28 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9 | 18 | 9 |  |
| 29 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |
| 31 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**67 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15/18 | 18 | 18 |  |
| 3 | `loop/loop_test4` | 81.8% | 18/22 | 22 | 22 |  |
| 4 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 5 | `place_and_remove_object_test` | 76.9% | 10/13 | 13 | 13 |  |
| 6 | `static_vs_dynamic1` | 76.5% | 13/17 | 17 | 17 |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 8 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 9 | `loop/loop_test9` | 73.3% | 11/15 | 15 | 15 |  |
| 10 | `action_order/action_execution_order_test8-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 11 | `action_order/action_execution_order_test8-v6` | 72.7% | 8/11 | 11 | 11 |  |
| 12 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 13 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 14 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 15 | `event_handler_scope_test` | 68.8% | 11/16 | 16 | 16 |  |
| 16 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 17 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 18 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 19 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 20 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 21 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 22 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 23 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 24 | `loop/loop_test7` | 53.3% | 8/15 | 14 | 15 |  |
| 25 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 26 | `loop/loop_test5` | 52.0% | 13/25 | 25 | 24 |  |
| 27 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 28 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9/18 | 18 | 15 |  |
| 29 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 31 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 32 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 33 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 34 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 35 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 36 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 37 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 38 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 39 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 40 | `loop/loop_test` | 33.3% | 7/21 | 21 | 21 |  |
| 41 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 42 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 43 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 44 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 45 | `goto_frame_test` | 20.0% | 3/15 | 13 | 15 |  |
| 46 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 47 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 48 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 49 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 50 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 51 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 52 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 53 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 54 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 55 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 56 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 57 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 58 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 59 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 60 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 61 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 62 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 63 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 64 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 65 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 66 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 67 | `replace_shapes1test` | 0.0% | 0/29 | 29 | 23 |  |
