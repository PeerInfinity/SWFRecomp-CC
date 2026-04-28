# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-28 17:26 UTC

**Git SHA**: `431a14a0d2`

**Run Duration**: 28m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **54** (52.9%) |
| Ruffle-matched | 13 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **67** (65.7%) |
| Failing | 35 |
| Total expected lines | 4541 |
| Matching lines | 2699 (59.4%) |
| Mismatched lines | 1842 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 34 | 97.1% |
| Compile Fail | 1 | 2.9% |

## Passing Tests

**54 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 19.2s |  |
| 2 | `DefineEditTextTest` | 153 | 26.2s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 16.8s |  |
| 4 | `PlaceObject2Test` | 9 | 19.6s |  |
| 5 | `ResolveEventsTest` | 15 | 2.9s |  |
| 6 | `RollOverOutTest` | 5 | 19.7s |  |
| 7 | `VarAndCharClashTest` | 13 | 1.6s |  |
| 8 | `Video-EmbedSquareTest` | 2 | 18.1s |  |
| 9 | `action_order/action_execution_order_test1` | 10 | 18.7s |  |
| 10 | `action_order/action_execution_order_test3` | 4 | 18.0s |  |
| 11 | `action_order/action_execution_order_test7` | 7 | 19.2s |  |
| 12 | `action_order/action_execution_order_test8-v5` | 11 | 19.3s |  |
| 13 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 14 | `action_order/action_execution_order_test9` | 4 | 19.2s |  |
| 15 | `attachExtImported` | 2 | 20.0s |  |
| 16 | `attachImported` | 2 | 1.8s |  |
| 17 | `attachMovieLoopingTest` | 41 | 19.4s |  |
| 18 | `attachMovieTest` | 12 | 19.0s |  |
| 19 | `consecutive_goto_frame_test` | 12 | 18.3s |  |
| 20 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.1s |  |
| 21 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.1s |  |
| 22 | `displaylist_depths/displaylist_depths_test4` | 26 | 18.2s |  |
| 23 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.8s |  |
| 24 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.7s |  |
| 25 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 26 | `event_handler_scope_test` | 16 | 18.2s |  |
| 27 | `getTimer_test` | 8 | 18.5s |  |
| 28 | `get_frame_number_test` | 31 | 20.8s |  |
| 29 | `goto_frame_test` | 15 | 19.1s |  |
| 30 | `instanceNameTest` | 5 | 1.5s |  |
| 31 | `loop/loop_test` | 21 | 18.9s |  |
| 32 | `loop/loop_test2` | 15 | 18.6s |  |
| 33 | `loop/loop_test3` | 16 | 17.9s |  |
| 34 | `loop/loop_test4` | 22 | 19.0s |  |
| 35 | `loop/loop_test5` | 24 | 2.7s |  |
| 36 | `loop/loop_test8` | 38 | 20.5s |  |
| 37 | `loop/loop_test9` | 15 | 18.4s |  |
| 38 | `loop/simple_loop_test` | 0 | 18.9s |  |
| 39 | `masks_test2` | 10 | 18.7s |  |
| 40 | `morph_test1` | 0 | 18.7s |  |
| 41 | `move_object_test` | 11 | 18.3s |  |
| 42 | `multi_doactions_and_goto_frame_test` | 6 | 18.2s |  |
| 43 | `new_child_in_unload_test` | 11 | 18.5s |  |
| 44 | `place_and_remove_object_insane_test` | 22 | 18.5s |  |
| 45 | `place_and_remove_object_test` | 13 | 17.9s |  |
| 46 | `register_class/RegisterClassTest3` | 12 | 20.1s |  |
| 47 | `register_class/registerClassTest` | 51 | 23.6s |  |
| 48 | `reverse_execute_PlaceObject2_test1` | 8 | 17.9s |  |
| 49 | `reverse_execute_PlaceObject2_test2` | 10 | 18.4s |  |
| 50 | `runtime_vm_stack_test` | 9 | 18.1s |  |
| 51 | `shape_test` | 21 | 19.2s |  |
| 52 | `static_vs_dynamic1` | 17 | 17.6s |  |
| 53 | `static_vs_dynamic2` | 18 | 18.1s |  |
| 54 | `unload_movieclip_test1` | 6 | 17.4s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 18.3s |  |
| 2 | `DefineTextTest` | 4 | 4 | 14.7s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 19.1s |  |
| 4 | `action_order/action_execution_order_test4` | 6 | 26 | 2.9s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 20.1s |  |
| 6 | `callFunction_test` | 5 | 11 | 19.2s |  |
| 7 | `init_action/InitActionTest` | 8 | 17 | 18.0s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 19.0s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 20.6s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 2.1s |  |
| 11 | `path_format_test` | 27 | 28 | 20.8s |  |
| 12 | `place_object_test` | 14 | 14 | 18.6s |  |
| 13 | `place_object_test2` | 16 | 23 | 18.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 2 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 3 | `register_class/registerClassTest2` | 79.5% | 35 | 44 | 9 |  |
| 4 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 5 | `DrawingApiTest` | 67.4% | 64 | 95 | 31 |  |
| 6 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 7 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 8 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 9 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 10 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**34 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99/111 | 111 | 111 |  |
| 2 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 3 | `register_class/registerClassTest2` | 79.5% | 35/44 | 44 | 44 |  |
| 4 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 5 | `DrawingApiTest` | 67.4% | 64/95 | 95 | 93 |  |
| 6 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 7 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 8 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 9 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 10 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 13 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 14 | `displaylist_depths/displaylist_depths_test8` | 43.8% | 7/16 | 16 | 15 |  |
| 15 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 16 | `loop/loop_test6` | 41.7% | 10/24 | 24 | 23 |  |
| 17 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 18 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 19 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 20 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 21 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 22 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 23 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 24 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 25 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 26 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 27 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 28 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 29 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 30 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 31 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 32 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 33 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 34 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
