# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-27 02:49 UTC

**Git SHA**: `8fb3a99ec4`

**Run Duration**: 1m 3s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **46** (45.1%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **58** (56.9%) |
| Failing | 44 |
| Total expected lines | 4541 |
| Matching lines | 2473 (54.5%) |
| Mismatched lines | 2068 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 43 | 97.7% |
| Compile Fail | 1 | 2.3% |

## Passing Tests

**46 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 1.0s |  |
| 2 | `DefineEditTextVariableNameTest2` | 39 | 0.6s |  |
| 3 | `PlaceObject2Test` | 9 | 0.5s |  |
| 4 | `ResolveEventsTest` | 15 | 0.5s |  |
| 5 | `RollOverOutTest` | 5 | 0.5s |  |
| 6 | `VarAndCharClashTest` | 13 | 0.4s |  |
| 7 | `Video-EmbedSquareTest` | 2 | 0.5s |  |
| 8 | `action_order/action_execution_order_test1` | 10 | 0.4s |  |
| 9 | `action_order/action_execution_order_test3` | 4 | 0.5s |  |
| 10 | `action_order/action_execution_order_test7` | 7 | 0.5s |  |
| 11 | `action_order/action_execution_order_test8-v5` | 11 | 0.5s |  |
| 12 | `action_order/action_execution_order_test8-v6` | 11 | 0.2s |  |
| 13 | `action_order/action_execution_order_test9` | 4 | 0.4s |  |
| 14 | `attachMovieTest` | 12 | 0.5s |  |
| 15 | `consecutive_goto_frame_test` | 12 | 0.5s |  |
| 16 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.4s |  |
| 17 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.4s |  |
| 18 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.4s |  |
| 19 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.4s |  |
| 20 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.5s |  |
| 21 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.4s |  |
| 22 | `event_handler_scope_test` | 16 | 0.5s |  |
| 23 | `getTimer_test` | 8 | 0.5s |  |
| 24 | `get_frame_number_test` | 31 | 0.6s |  |
| 25 | `goto_frame_test` | 15 | 0.5s |  |
| 26 | `instanceNameTest` | 5 | 0.4s |  |
| 27 | `loop/loop_test2` | 15 | 0.4s |  |
| 28 | `loop/loop_test3` | 16 | 0.4s |  |
| 29 | `loop/loop_test4` | 22 | 0.5s |  |
| 30 | `loop/loop_test5` | 24 | 0.5s |  |
| 31 | `loop/loop_test8` | 38 | 0.5s |  |
| 32 | `loop/loop_test9` | 15 | 0.4s |  |
| 33 | `loop/simple_loop_test` | 0 | 0.4s |  |
| 34 | `masks_test2` | 10 | 0.4s |  |
| 35 | `morph_test1` | 0 | 0.4s |  |
| 36 | `move_object_test` | 11 | 0.4s |  |
| 37 | `multi_doactions_and_goto_frame_test` | 6 | 0.4s |  |
| 38 | `new_child_in_unload_test` | 11 | 0.4s |  |
| 39 | `place_and_remove_object_test` | 13 | 0.4s |  |
| 40 | `reverse_execute_PlaceObject2_test1` | 8 | 0.4s |  |
| 41 | `reverse_execute_PlaceObject2_test2` | 10 | 0.4s |  |
| 42 | `runtime_vm_stack_test` | 9 | 0.5s |  |
| 43 | `shape_test` | 21 | 0.5s |  |
| 44 | `static_vs_dynamic1` | 17 | 0.4s |  |
| 45 | `static_vs_dynamic2` | 18 | 0.4s |  |
| 46 | `unload_movieclip_test1` | 6 | 0.4s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 0.5s |  |
| 2 | `KeyEventOrder` | 20 | 23 | 0.5s |  |
| 3 | `action_order/action_execution_order_test4` | 6 | 26 | 0.5s |  |
| 4 | `action_order/action_execution_order_test6` | 5 | 21 | 0.5s |  |
| 5 | `attachExtImported` | 1 | 1 | 1.6s |  |
| 6 | `callFunction_test` | 5 | 11 | 0.5s |  |
| 7 | `init_action/InitActionTest` | 17 | 17 | 0.4s |  |
| 8 | `init_action/InitActionTest2` | 30 | 30 | 0.5s |  |
| 9 | `loop/loop_test7` | 1 | 8 | 0.5s |  |
| 10 | `path_format_test` | 27 | 28 | 0.6s |  |
| 11 | `place_object_test` | 14 | 14 | 0.5s |  |
| 12 | `place_object_test2` | 16 | 23 | 0.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**15 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 84.0% | 912 | 1086 | 174 |  |
| 2 | `displaylist_depths/displaylist_depths_test` | 82.9% | 92 | 111 | 19 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17 | 22 | 5 |  |
| 4 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 5 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 6 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 7 | `DrawingApiTest` | 67.4% | 64 | 95 | 31 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 10 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 11 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 12 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 13 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 15 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**43 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 84.0% | 912/1086 | 1086 | 1086 |  |
| 2 | `displaylist_depths/displaylist_depths_test` | 82.9% | 92/111 | 111 | 111 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
| 4 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 5 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 6 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 7 | `DrawingApiTest` | 67.4% | 64/95 | 95 | 93 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 10 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 11 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 12 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 13 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 15 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 17 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 18 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 19 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 20 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 21 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 22 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 23 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 24 | `loop/loop_test6` | 37.5% | 9/24 | 24 | 23 |  |
| 25 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 26 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 27 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 28 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 29 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 30 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 31 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 32 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 33 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 34 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 35 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 36 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 37 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 38 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 39 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 40 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 41 | `register_class/registerClassTest2` | 0.0% | 0/44 | 42 | 44 |  |
| 42 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 43 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
