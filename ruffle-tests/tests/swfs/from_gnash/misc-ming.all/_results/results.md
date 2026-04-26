# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-26 02:55 UTC

**Git SHA**: `55cf612d75`

**Run Duration**: 28m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **45** (44.1%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **57** (55.9%) |
| Failing | 45 |
| Total expected lines | 4541 |
| Matching lines | 2433 (53.6%) |
| Mismatched lines | 2108 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 44 | 97.8% |
| Compile Fail | 1 | 2.2% |

## Passing Tests

**45 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 27.6s |  |
| 2 | `DefineEditTextVariableNameTest2` | 39 | 17.4s |  |
| 3 | `PlaceObject2Test` | 9 | 18.3s |  |
| 4 | `ResolveEventsTest` | 15 | 2.9s |  |
| 5 | `RollOverOutTest` | 5 | 19.1s |  |
| 6 | `VarAndCharClashTest` | 13 | 1.5s |  |
| 7 | `Video-EmbedSquareTest` | 2 | 18.0s |  |
| 8 | `action_order/action_execution_order_test1` | 10 | 18.1s |  |
| 9 | `action_order/action_execution_order_test3` | 4 | 18.4s |  |
| 10 | `action_order/action_execution_order_test7` | 7 | 18.3s |  |
| 11 | `action_order/action_execution_order_test8-v5` | 11 | 19.0s |  |
| 12 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 13 | `action_order/action_execution_order_test9` | 4 | 16.9s |  |
| 14 | `attachMovieTest` | 12 | 19.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.9s |  |
| 16 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.8s |  |
| 17 | `displaylist_depths/displaylist_depths_test4` | 26 | 19.2s |  |
| 18 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.7s |  |
| 19 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.7s |  |
| 20 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 21 | `event_handler_scope_test` | 16 | 19.1s |  |
| 22 | `getTimer_test` | 8 | 17.8s |  |
| 23 | `get_frame_number_test` | 31 | 19.9s |  |
| 24 | `instanceNameTest` | 5 | 1.6s |  |
| 25 | `loop/loop_test2` | 15 | 17.6s |  |
| 26 | `loop/loop_test3` | 16 | 17.7s |  |
| 27 | `loop/loop_test4` | 22 | 18.6s |  |
| 28 | `loop/loop_test5` | 24 | 2.6s |  |
| 29 | `loop/loop_test8` | 38 | 19.2s |  |
| 30 | `loop/loop_test9` | 15 | 18.0s |  |
| 31 | `loop/simple_loop_test` | 0 | 17.4s |  |
| 32 | `masks_test2` | 10 | 18.1s |  |
| 33 | `morph_test1` | 0 | 17.9s |  |
| 34 | `move_object_test` | 11 | 17.8s |  |
| 35 | `multi_doactions_and_goto_frame_test` | 6 | 17.9s |  |
| 36 | `new_child_in_unload_test` | 11 | 18.2s |  |
| 37 | `place_and_remove_object_test` | 13 | 19.6s |  |
| 38 | `reverse_execute_PlaceObject2_test1` | 8 | 18.1s |  |
| 39 | `reverse_execute_PlaceObject2_test2` | 10 | 18.3s |  |
| 40 | `runtime_vm_stack_test` | 9 | 18.4s |  |
| 41 | `shape_test` | 21 | 19.5s |  |
| 42 | `static_vs_dynamic1` | 17 | 18.1s |  |
| 43 | `static_vs_dynamic2` | 18 | 18.4s |  |
| 44 | `timeline_var_test` | 11 | 18.2s |  |
| 45 | `unload_movieclip_test1` | 6 | 17.8s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 18.7s |  |
| 2 | `KeyEventOrder` | 20 | 23 | 18.4s |  |
| 3 | `action_order/action_execution_order_test4` | 6 | 26 | 2.9s |  |
| 4 | `action_order/action_execution_order_test6` | 19 | 21 | 19.4s |  |
| 5 | `attachExtImported` | 1 | 1 | 18.1s |  |
| 6 | `callFunction_test` | 5 | 11 | 19.7s |  |
| 7 | `init_action/InitActionTest` | 17 | 17 | 18.6s |  |
| 8 | `init_action/InitActionTest2` | 30 | 30 | 19.6s |  |
| 9 | `loop/loop_test7` | 1 | 8 | 2.0s |  |
| 10 | `path_format_test` | 27 | 28 | 20.3s |  |
| 11 | `place_object_test` | 14 | 14 | 20.0s |  |
| 12 | `place_object_test2` | 16 | 23 | 19.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**14 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 84.0% | 912 | 1086 | 174 |  |
| 2 | `displaylist_depths/displaylist_depths_test` | 82.9% | 92 | 111 | 19 |  |
| 3 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 4 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 5 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 6 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 7 | `DrawingApiTest` | 67.4% | 64 | 95 | 31 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 10 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 11 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 12 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 14 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**44 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 84.0% | 912/1086 | 1086 | 1086 |  |
| 2 | `displaylist_depths/displaylist_depths_test` | 82.9% | 92/111 | 111 | 111 |  |
| 3 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 4 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 5 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 6 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 7 | `DrawingApiTest` | 67.4% | 64/95 | 95 | 93 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 10 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 11 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 12 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 14 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 16 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 17 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 18 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 19 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 20 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 21 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 22 | `loop/loop_test6` | 37.5% | 9/24 | 24 | 23 |  |
| 23 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 24 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 25 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 26 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 27 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 28 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 29 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 30 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 31 | `action_order/ActionOrderTest5` | 9.8% | 6/61 | 61 | 51 |  |
| 32 | `opcode_guard_test` | 9.7% | 3/31 | 31 | 18 |  |
| 33 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 34 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 35 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 36 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 37 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 38 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 39 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 40 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 41 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 42 | `register_class/registerClassTest2` | 0.0% | 0/44 | 42 | 44 |  |
| 43 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 44 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
