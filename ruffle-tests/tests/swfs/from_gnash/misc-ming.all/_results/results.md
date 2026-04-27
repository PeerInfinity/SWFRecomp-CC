# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-27 01:54 UTC

**Git SHA**: `df6df0c005`

**Run Duration**: 22m 56s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **43** (42.2%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **55** (53.9%) |
| Failing | 47 |
| Total expected lines | 4541 |
| Matching lines | 2460 (54.2%) |
| Mismatched lines | 2081 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 46 | 97.9% |
| Compile Fail | 1 | 2.1% |

## Passing Tests

**43 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 17.1s |  |
| 2 | `DefineEditTextVariableNameTest2` | 39 | 17.0s |  |
| 3 | `PlaceObject2Test` | 9 | 16.9s |  |
| 4 | `ResolveEventsTest` | 15 | 0.6s |  |
| 5 | `RollOverOutTest` | 5 | 17.0s |  |
| 6 | `VarAndCharClashTest` | 13 | 0.5s |  |
| 7 | `Video-EmbedSquareTest` | 2 | 17.7s |  |
| 8 | `action_order/action_execution_order_test1` | 10 | 16.5s |  |
| 9 | `action_order/action_execution_order_test3` | 4 | 17.0s |  |
| 10 | `action_order/action_execution_order_test9` | 4 | 16.6s |  |
| 11 | `attachMovieTest` | 12 | 17.1s |  |
| 12 | `consecutive_goto_frame_test` | 12 | 17.1s |  |
| 13 | `displaylist_depths/displaylist_depths_test10` | 10 | 16.4s |  |
| 14 | `displaylist_depths/displaylist_depths_test11` | 15 | 16.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.0s |  |
| 16 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.4s |  |
| 17 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.4s |  |
| 18 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.4s |  |
| 19 | `event_handler_scope_test` | 16 | 17.1s |  |
| 20 | `getTimer_test` | 8 | 17.7s |  |
| 21 | `get_frame_number_test` | 31 | 17.4s |  |
| 22 | `goto_frame_test` | 15 | 17.2s |  |
| 23 | `instanceNameTest` | 5 | 0.5s |  |
| 24 | `loop/loop_test2` | 15 | 16.4s |  |
| 25 | `loop/loop_test3` | 16 | 16.3s |  |
| 26 | `loop/loop_test4` | 22 | 16.3s |  |
| 27 | `loop/loop_test5` | 24 | 0.5s |  |
| 28 | `loop/loop_test8` | 38 | 17.1s |  |
| 29 | `loop/loop_test9` | 15 | 13.4s |  |
| 30 | `loop/simple_loop_test` | 0 | 13.7s |  |
| 31 | `masks_test2` | 10 | 16.2s |  |
| 32 | `morph_test1` | 0 | 16.5s |  |
| 33 | `move_object_test` | 11 | 17.0s |  |
| 34 | `multi_doactions_and_goto_frame_test` | 6 | 16.8s |  |
| 35 | `new_child_in_unload_test` | 11 | 16.7s |  |
| 36 | `place_and_remove_object_test` | 13 | 16.8s |  |
| 37 | `reverse_execute_PlaceObject2_test1` | 8 | 17.8s |  |
| 38 | `reverse_execute_PlaceObject2_test2` | 10 | 17.8s |  |
| 39 | `runtime_vm_stack_test` | 9 | 17.1s |  |
| 40 | `shape_test` | 21 | 17.2s |  |
| 41 | `static_vs_dynamic1` | 17 | 16.9s |  |
| 42 | `static_vs_dynamic2` | 18 | 16.5s |  |
| 43 | `unload_movieclip_test1` | 6 | 16.5s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 16.4s |  |
| 2 | `KeyEventOrder` | 20 | 23 | 16.5s |  |
| 3 | `action_order/action_execution_order_test4` | 6 | 26 | 0.6s |  |
| 4 | `action_order/action_execution_order_test6` | 12 | 21 | 17.1s |  |
| 5 | `attachExtImported` | 1 | 1 | 16.5s |  |
| 6 | `callFunction_test` | 5 | 11 | 17.2s |  |
| 7 | `init_action/InitActionTest` | 17 | 17 | 16.3s |  |
| 8 | `init_action/InitActionTest2` | 30 | 30 | 16.4s |  |
| 9 | `loop/loop_test7` | 1 | 8 | 0.5s |  |
| 10 | `path_format_test` | 27 | 28 | 16.5s |  |
| 11 | `place_object_test` | 14 | 14 | 16.9s |  |
| 12 | `place_object_test2` | 16 | 23 | 16.7s |  |

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

**46 tests** with output mismatch, sorted by match rate (best first)

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
| 18 | `action_order/action_execution_order_test8-v5` | 45.5% | 5/11 | 8 | 11 |  |
| 19 | `action_order/action_execution_order_test8-v6` | 45.5% | 5/11 | 8 | 11 |  |
| 20 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 21 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 22 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 23 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 24 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 25 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 26 | `loop/loop_test6` | 37.5% | 9/24 | 24 | 23 |  |
| 27 | `action_order/ActionOrderTest5` | 35.3% | 18/51 | 51 | 51 |  |
| 28 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 29 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 30 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 31 | `action_order/action_execution_order_test7` | 14.3% | 1/7 | 6 | 7 |  |
| 32 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 33 | `action_order/ActionOrderTest4` | 14.1% | 9/64 | 64 | 64 |  |
| 34 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 35 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 36 | `action_order/ActionOrderTest3` | 9.2% | 6/65 | 65 | 62 |  |
| 37 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 38 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 39 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 40 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 41 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 42 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 43 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 44 | `register_class/registerClassTest2` | 0.0% | 0/44 | 42 | 44 |  |
| 45 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 46 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
