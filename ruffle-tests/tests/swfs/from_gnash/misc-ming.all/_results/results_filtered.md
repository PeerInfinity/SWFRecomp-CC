# Ruffle Test Results (Filtered)

**Date**: 2026-04-27 22:39 UTC

**Git SHA**: `01012b3d1f`

**Run Duration**: 22m 53s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **50** (49.0%) |
| Ruffle-matched | 13 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **63** (61.8%) |
| Failing | 39 |
| Total expected lines | 4541 |
| Matching lines | 2569 (56.6%) |
| Mismatched lines | 1972 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 38 | 97.4% |
| Compile Fail | 1 | 2.6% |

## Passing Tests

**50 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 16.8s |  |
| 2 | `DefineEditTextTest` | 153 | 17.0s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 17.5s |  |
| 4 | `PlaceObject2Test` | 9 | 16.6s |  |
| 5 | `ResolveEventsTest` | 15 | 0.3s |  |
| 6 | `RollOverOutTest` | 5 | 16.7s |  |
| 7 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 8 | `Video-EmbedSquareTest` | 2 | 16.8s |  |
| 9 | `action_order/action_execution_order_test1` | 10 | 18.1s |  |
| 10 | `action_order/action_execution_order_test3` | 4 | 16.4s |  |
| 11 | `action_order/action_execution_order_test7` | 7 | 16.7s |  |
| 12 | `action_order/action_execution_order_test8-v5` | 11 | 17.1s |  |
| 13 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 14 | `action_order/action_execution_order_test9` | 4 | 16.7s |  |
| 15 | `attachExtImported` | 2 | 16.8s |  |
| 16 | `attachImported` | 2 | 0.3s |  |
| 17 | `attachMovieLoopingTest` | 41 | 16.7s |  |
| 18 | `attachMovieTest` | 12 | 16.3s |  |
| 19 | `consecutive_goto_frame_test` | 12 | 16.3s |  |
| 20 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.5s |  |
| 21 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.4s |  |
| 22 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.6s |  |
| 23 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 24 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 25 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 26 | `event_handler_scope_test` | 16 | 16.1s |  |
| 27 | `getTimer_test` | 8 | 16.8s |  |
| 28 | `get_frame_number_test` | 31 | 18.3s |  |
| 29 | `goto_frame_test` | 15 | 19.2s |  |
| 30 | `instanceNameTest` | 5 | 0.3s |  |
| 31 | `loop/loop_test2` | 15 | 16.9s |  |
| 32 | `loop/loop_test3` | 16 | 17.1s |  |
| 33 | `loop/loop_test4` | 22 | 16.8s |  |
| 34 | `loop/loop_test5` | 24 | 0.3s |  |
| 35 | `loop/loop_test8` | 38 | 16.7s |  |
| 36 | `loop/loop_test9` | 15 | 16.4s |  |
| 37 | `loop/simple_loop_test` | 0 | 16.6s |  |
| 38 | `masks_test2` | 10 | 16.4s |  |
| 39 | `morph_test1` | 0 | 16.5s |  |
| 40 | `move_object_test` | 11 | 13.7s |  |
| 41 | `multi_doactions_and_goto_frame_test` | 6 | 13.7s |  |
| 42 | `new_child_in_unload_test` | 11 | 13.7s |  |
| 43 | `place_and_remove_object_test` | 13 | 16.1s |  |
| 44 | `reverse_execute_PlaceObject2_test1` | 8 | 17.3s |  |
| 45 | `reverse_execute_PlaceObject2_test2` | 10 | 17.9s |  |
| 46 | `runtime_vm_stack_test` | 9 | 16.7s |  |
| 47 | `shape_test` | 21 | 17.0s |  |
| 48 | `static_vs_dynamic1` | 17 | 16.5s |  |
| 49 | `static_vs_dynamic2` | 18 | 16.1s |  |
| 50 | `unload_movieclip_test1` | 6 | 16.0s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 16.7s |  |
| 2 | `DefineTextTest` | 4 | 4 | 17.4s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 16.8s |  |
| 4 | `action_order/action_execution_order_test4` | 6 | 26 | 0.3s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 16.9s |  |
| 6 | `callFunction_test` | 5 | 11 | 16.4s |  |
| 7 | `init_action/InitActionTest` | 17 | 17 | 16.6s |  |
| 8 | `init_action/InitActionTest2` | 30 | 30 | 16.7s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 17.0s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 11 | `path_format_test` | 27 | 28 | 17.1s |  |
| 12 | `place_object_test` | 14 | 14 | 16.3s |  |
| 13 | `place_object_test2` | 16 | 23 | 16.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**12 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 2 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17 | 22 | 5 |  |
| 4 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 5 | `DrawingApiTest` | 67.4% | 64 | 95 | 31 |  |
| 6 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 7 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 8 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 9 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 10 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 12 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**38 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99/111 | 111 | 111 |  |
| 2 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
| 4 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 5 | `DrawingApiTest` | 67.4% | 64/95 | 95 | 93 |  |
| 6 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 7 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 8 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 9 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 10 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 12 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 13 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 14 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 15 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 16 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 17 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 18 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 19 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 20 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 21 | `loop/loop_test6` | 37.5% | 9/24 | 24 | 23 |  |
| 22 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 23 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 24 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 25 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 26 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 27 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 28 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 29 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 30 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 31 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 32 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 33 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 34 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 35 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 36 | `register_class/registerClassTest2` | 0.0% | 0/44 | 42 | 44 |  |
| 37 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 38 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
