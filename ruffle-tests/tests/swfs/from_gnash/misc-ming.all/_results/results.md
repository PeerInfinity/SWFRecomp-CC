# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-04 04:30 UTC

**Git SHA**: `9e3e903e07`

**Run Duration**: 29m 6s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **61** (59.8%) |
| Ruffle-matched | 17 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **78** (76.5%) |
| Failing | 24 |
| Total expected lines | 4493 |
| Matching lines | 2784 (62.0%) |
| Mismatched lines | 1709 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 21 | 87.5% |
| Compile Fail | 3 | 12.5% |

## Passing Tests

**61 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.1s |  |
| 2 | `DefineEditTextTest` | 153 | 28.6s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 21.4s |  |
| 4 | `DepthLimitsTest` | 20 | 21.0s |  |
| 5 | `PlaceObject2Test` | 9 | 16.4s |  |
| 6 | `ResolveEventsTest` | 15 | 2.7s |  |
| 7 | `RollOverOutTest` | 5 | 17.5s |  |
| 8 | `VarAndCharClashTest` | 13 | 1.5s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 19.6s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 19.8s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 19.0s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 18.8s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 18.7s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 19.2s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 14.4s |  |
| 17 | `attachMovieLoopingTest` | 41 | 14.5s |  |
| 18 | `attachMovieTest` | 12 | 19.4s |  |
| 19 | `consecutive_goto_frame_test` | 12 | 19.5s |  |
| 20 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.5s |  |
| 21 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.5s |  |
| 22 | `displaylist_depths/displaylist_depths_test4` | 26 | 19.0s |  |
| 23 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.8s |  |
| 24 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.7s |  |
| 25 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test8` | 15 | 18.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test9` | 23 | 2.5s |  |
| 28 | `duplicate_movie_clip_test2` | 21 | 19.3s |  |
| 29 | `event_handler_scope_test` | 16 | 18.6s |  |
| 30 | `getTimer_test` | 8 | 18.8s |  |
| 31 | `get_frame_number_test` | 31 | 21.2s |  |
| 32 | `goto_frame_test` | 15 | 19.7s |  |
| 33 | `instanceNameTest` | 5 | 1.7s |  |
| 34 | `loading/LoadVarsTest` | 36 | 22.5s |  |
| 35 | `loop/loop_test` | 21 | 18.7s |  |
| 36 | `loop/loop_test2` | 15 | 18.6s |  |
| 37 | `loop/loop_test3` | 16 | 17.9s |  |
| 38 | `loop/loop_test4` | 22 | 18.7s |  |
| 39 | `loop/loop_test5` | 24 | 2.5s |  |
| 40 | `loop/loop_test8` | 38 | 22.2s |  |
| 41 | `loop/loop_test9` | 15 | 18.7s |  |
| 42 | `loop/simple_loop_test` | 0 | 18.6s |  |
| 43 | `masks_test2` | 10 | 18.4s |  |
| 44 | `morph_test1` | 0 | 18.2s |  |
| 45 | `move_object_test` | 11 | 19.8s |  |
| 46 | `multi_doactions_and_goto_frame_test` | 6 | 20.0s |  |
| 47 | `new_child_in_unload_test` | 11 | 20.1s |  |
| 48 | `place_and_remove_object_insane_test` | 22 | 19.5s |  |
| 49 | `place_and_remove_object_test` | 13 | 19.7s |  |
| 50 | `register_class/RegisterClassTest3` | 12 | 19.1s |  |
| 51 | `register_class/registerClassTest` | 51 | 21.3s |  |
| 52 | `replace_shapes1test` | 23 | 2.1s |  |
| 53 | `replace_sprites1test` | 21 | 18.8s |  |
| 54 | `reverse_execute_PlaceObject2_test1` | 8 | 18.2s |  |
| 55 | `reverse_execute_PlaceObject2_test2` | 10 | 18.5s |  |
| 56 | `runtime_vm_stack_test` | 9 | 18.6s |  |
| 57 | `shape_test` | 21 | 19.8s |  |
| 58 | `static_vs_dynamic1` | 17 | 18.1s |  |
| 59 | `static_vs_dynamic2` | 18 | 19.3s |  |
| 60 | `timeline_var_test` | 11 | 19.3s |  |
| 61 | `unload_movieclip_test1` | 6 | 19.1s |  |

## Ruffle-Matched Tests

**17 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 19.1s |  |
| 2 | `DefineTextTest` | 4 | 4 | 19.7s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 18.9s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 2.6s |  |
| 5 | `callFunction_test` | 5 | 11 | 19.7s |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.4s |  |
| 7 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 1.7s |  |
| 8 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.6s |  |
| 9 | `duplicate_movie_clip_test` | 4 | 4 | 19.9s |  |
| 10 | `init_action/InitActionTest` | 6 | 17 | 18.8s |  |
| 11 | `init_action/InitActionTest2` | 24 | 30 | 19.8s |  |
| 12 | `loop/loop_test7` | 1 | 8 | 2.0s |  |
| 13 | `path_format_test` | 27 | 28 | 21.6s |  |
| 14 | `place_object_test` | 14 | 14 | 20.7s |  |
| 15 | `place_object_test2` | 20 | 23 | 19.9s |  |
| 16 | `register_class/registerClassTest2` | 8 | 28 | 21.1s |  |
| 17 | `replace_buttons1test` | 3 | 3 | 19.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 2 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 4 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 6 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**21 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 2 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 4 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 6 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 7 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 8 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 9 | `loop/loop_test6` | 45.8% | 11/24 | 24 | 23 |  |
| 10 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 11 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 12 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 13 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 14 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 15 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 16 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 17 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 18 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 19 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 20 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
| 21 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
