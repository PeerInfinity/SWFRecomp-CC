# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-25 21:32 UTC

**Git SHA**: `d6bada59e5`

**Run Duration**: 22m 19s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **44** (43.1%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **55** (53.9%) |
| Failing | 47 |
| Total expected lines | 4541 |
| Matching lines | 2357 (51.9%) |
| Mismatched lines | 2184 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 46 | 97.9% |
| Compile Fail | 1 | 2.1% |

## Passing Tests

**44 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 17.1s |  |
| 2 | `DefineEditTextVariableNameTest2` | 39 | 13.1s |  |
| 3 | `PlaceObject2Test` | 9 | 16.9s |  |
| 4 | `ResolveEventsTest` | 15 | 0.3s |  |
| 5 | `RollOverOutTest` | 5 | 17.0s |  |
| 6 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 7 | `Video-EmbedSquareTest` | 2 | 17.2s |  |
| 8 | `action_order/action_execution_order_test1` | 10 | 17.3s |  |
| 9 | `action_order/action_execution_order_test3` | 4 | 16.7s |  |
| 10 | `action_order/action_execution_order_test7` | 7 | 16.6s |  |
| 11 | `action_order/action_execution_order_test8-v5` | 11 | 16.6s |  |
| 12 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 13 | `action_order/action_execution_order_test9` | 4 | 16.0s |  |
| 14 | `attachMovieTest` | 12 | 16.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test10` | 10 | 16.5s |  |
| 16 | `displaylist_depths/displaylist_depths_test11` | 15 | 16.9s |  |
| 17 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.8s |  |
| 18 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 19 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 20 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 21 | `event_handler_scope_test` | 16 | 17.5s |  |
| 22 | `getTimer_test` | 8 | 18.0s |  |
| 23 | `get_frame_number_test` | 31 | 17.2s |  |
| 24 | `instanceNameTest` | 5 | 0.2s |  |
| 25 | `loop/loop_test2` | 15 | 16.4s |  |
| 26 | `loop/loop_test3` | 16 | 17.0s |  |
| 27 | `loop/loop_test4` | 22 | 16.8s |  |
| 28 | `loop/loop_test5` | 24 | 0.3s |  |
| 29 | `loop/loop_test9` | 15 | 16.5s |  |
| 30 | `loop/simple_loop_test` | 0 | 16.7s |  |
| 31 | `masks_test2` | 10 | 13.0s |  |
| 32 | `morph_test1` | 0 | 13.2s |  |
| 33 | `move_object_test` | 11 | 17.0s |  |
| 34 | `multi_doactions_and_goto_frame_test` | 6 | 16.9s |  |
| 35 | `new_child_in_unload_test` | 11 | 16.8s |  |
| 36 | `place_and_remove_object_test` | 13 | 16.0s |  |
| 37 | `reverse_execute_PlaceObject2_test1` | 8 | 16.1s |  |
| 38 | `reverse_execute_PlaceObject2_test2` | 10 | 16.1s |  |
| 39 | `runtime_vm_stack_test` | 9 | 17.0s |  |
| 40 | `shape_test` | 21 | 17.0s |  |
| 41 | `static_vs_dynamic1` | 17 | 16.6s |  |
| 42 | `static_vs_dynamic2` | 18 | 16.2s |  |
| 43 | `timeline_var_test` | 11 | 16.4s |  |
| 44 | `unload_movieclip_test1` | 6 | 16.8s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 16.9s |  |
| 2 | `action_order/action_execution_order_test4` | 6 | 26 | 0.3s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 16.9s |  |
| 4 | `attachExtImported` | 1 | 1 | 16.1s |  |
| 5 | `callFunction_test` | 5 | 11 | 16.7s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 13.0s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 13.1s |  |
| 8 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 9 | `path_format_test` | 27 | 28 | 16.3s |  |
| 10 | `place_object_test` | 14 | 14 | 16.3s |  |
| 11 | `place_object_test2` | 16 | 23 | 16.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**14 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loop/loop_test8` | 97.4% | 37 | 38 | 1 |  |
| 2 | `matrix_test` | 84.0% | 912 | 1086 | 174 |  |
| 3 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 4 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 5 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 6 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 7 | `DrawingApiTest` | 67.4% | 64 | 95 | 31 |  |
| 8 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 9 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 10 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
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

**46 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loop/loop_test8` | 97.4% | 37/38 | 37 | 38 |  |
| 2 | `matrix_test` | 84.0% | 912/1086 | 1086 | 1086 |  |
| 3 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 4 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 5 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 6 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 7 | `DrawingApiTest` | 67.4% | 64/95 | 95 | 93 |  |
| 8 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 9 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 10 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
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
| 21 | `loop/loop_test6` | 37.5% | 9/24 | 24 | 23 |  |
| 22 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 23 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 24 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 25 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 26 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 27 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 28 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 29 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 30 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 31 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 32 | `action_order/ActionOrderTest5` | 9.8% | 6/61 | 61 | 51 |  |
| 33 | `opcode_guard_test` | 9.7% | 3/31 | 31 | 18 |  |
| 34 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 35 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 36 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 37 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 38 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 39 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 40 | `ButtonEventsTest` | 2.8% | 19/679 | 77 | 679 |  |
| 41 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 42 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 43 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 44 | `register_class/registerClassTest2` | 0.0% | 0/44 | 42 | 44 |  |
| 45 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 46 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
