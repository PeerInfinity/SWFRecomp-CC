# Ruffle Test Results (Filtered)

**Date**: 2026-04-28 00:50 UTC

**Git SHA**: `fccb7008ab`

**Run Duration**: 1m 5s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **50** (49.0%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **62** (60.8%) |
| Failing | 40 |
| Total expected lines | 4541 |
| Matching lines | 2603 (57.3%) |
| Mismatched lines | 1938 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 39 | 97.5% |
| Compile Fail | 1 | 2.5% |

## Passing Tests

**50 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.4s |  |
| 2 | `DefineEditTextTest` | 153 | 0.9s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 0.5s |  |
| 4 | `PlaceObject2Test` | 9 | 0.5s |  |
| 5 | `ResolveEventsTest` | 15 | 0.6s |  |
| 6 | `RollOverOutTest` | 5 | 0.5s |  |
| 7 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 8 | `Video-EmbedSquareTest` | 2 | 0.3s |  |
| 9 | `action_order/action_execution_order_test1` | 10 | 0.4s |  |
| 10 | `action_order/action_execution_order_test3` | 4 | 0.4s |  |
| 11 | `action_order/action_execution_order_test7` | 7 | 0.4s |  |
| 12 | `action_order/action_execution_order_test8-v5` | 11 | 0.4s |  |
| 13 | `action_order/action_execution_order_test8-v6` | 11 | 0.2s |  |
| 14 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 15 | `attachExtImported` | 2 | 0.4s |  |
| 16 | `attachImported` | 2 | 0.4s |  |
| 17 | `attachMovieLoopingTest` | 41 | 0.3s |  |
| 18 | `attachMovieTest` | 12 | 0.4s |  |
| 19 | `consecutive_goto_frame_test` | 12 | 0.4s |  |
| 20 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.4s |  |
| 21 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.4s |  |
| 22 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.4s |  |
| 23 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.4s |  |
| 24 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.4s |  |
| 26 | `event_handler_scope_test` | 16 | 0.4s |  |
| 27 | `getTimer_test` | 8 | 0.4s |  |
| 28 | `get_frame_number_test` | 31 | 0.6s |  |
| 29 | `goto_frame_test` | 15 | 0.5s |  |
| 30 | `instanceNameTest` | 5 | 0.4s |  |
| 31 | `loop/loop_test2` | 15 | 0.4s |  |
| 32 | `loop/loop_test3` | 16 | 0.4s |  |
| 33 | `loop/loop_test4` | 22 | 0.5s |  |
| 34 | `loop/loop_test5` | 24 | 0.5s |  |
| 35 | `loop/loop_test8` | 38 | 0.5s |  |
| 36 | `loop/loop_test9` | 15 | 0.4s |  |
| 37 | `loop/simple_loop_test` | 0 | 0.4s |  |
| 38 | `masks_test2` | 10 | 0.3s |  |
| 39 | `morph_test1` | 0 | 0.3s |  |
| 40 | `move_object_test` | 11 | 0.4s |  |
| 41 | `multi_doactions_and_goto_frame_test` | 6 | 0.4s |  |
| 42 | `new_child_in_unload_test` | 11 | 0.4s |  |
| 43 | `place_and_remove_object_test` | 13 | 0.4s |  |
| 44 | `reverse_execute_PlaceObject2_test1` | 8 | 0.4s |  |
| 45 | `reverse_execute_PlaceObject2_test2` | 10 | 0.4s |  |
| 46 | `runtime_vm_stack_test` | 9 | 0.4s |  |
| 47 | `shape_test` | 21 | 0.4s |  |
| 48 | `static_vs_dynamic1` | 17 | 0.4s |  |
| 49 | `static_vs_dynamic2` | 18 | 0.4s |  |
| 50 | `unload_movieclip_test1` | 6 | 0.4s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 0.4s |  |
| 2 | `DefineTextTest` | 4 | 4 | 0.4s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 0.3s |  |
| 4 | `action_order/action_execution_order_test4` | 6 | 26 | 0.5s |  |
| 5 | `callFunction_test` | 5 | 11 | 0.4s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 0.4s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 0.5s |  |
| 8 | `loading/loadMovieTest` | 9 | 9 | 0.5s |  |
| 9 | `loop/loop_test7` | 1 | 8 | 0.4s |  |
| 10 | `path_format_test` | 27 | 28 | 0.6s |  |
| 11 | `place_object_test` | 14 | 14 | 0.5s |  |
| 12 | `place_object_test2` | 16 | 23 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**14 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `register_class/RegisterClassTest3` | 91.7% | 11 | 12 | 1 |  |
| 2 | `register_class/registerClassTest` | 90.2% | 46 | 51 | 5 |  |
| 3 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 4 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 5 | `place_and_remove_object_insane_test` | 77.3% | 17 | 22 | 5 |  |
| 6 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 7 | `DrawingApiTest` | 67.4% | 64 | 95 | 31 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 10 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 11 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 12 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 14 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**39 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `register_class/RegisterClassTest3` | 91.7% | 11/12 | 12 | 12 |  |
| 2 | `register_class/registerClassTest` | 90.2% | 46/51 | 51 | 51 |  |
| 3 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99/111 | 111 | 111 |  |
| 4 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 5 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
| 6 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 7 | `DrawingApiTest` | 67.4% | 64/95 | 95 | 93 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 10 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 11 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 12 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 14 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 16 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 17 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 18 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 19 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 20 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 21 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 22 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 23 | `loop/loop_test6` | 37.5% | 9/24 | 24 | 23 |  |
| 24 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 25 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 26 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 27 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 28 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 29 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 30 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 31 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 32 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 33 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 34 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 35 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
| 36 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 37 | `register_class/registerClassTest2` | 0.0% | 0/44 | 42 | 44 |  |
| 38 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 39 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
