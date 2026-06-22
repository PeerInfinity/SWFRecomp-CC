# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-22 19:09 UTC

**Git SHA**: `3c5a3c75e1`

**Run Duration**: 35m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **68** (61.3%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **96** (86.5%) |
| Failing | 15 |
| Total expected lines | 5248 |
| Matching lines | 4042 (77.0%) |
| Mismatched lines | 1206 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 15 | 100.0% |

## Passing Tests

**68 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.8s |  |
| 2 | `DefineEditTextTest` | 153 | 30.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 26.2s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.9s |  |
| 5 | `DepthLimitsTest` | 20 | 22.8s |  |
| 6 | `PlaceObject2Test` | 9 | 20.4s |  |
| 7 | `ResolveEventsTest` | 15 | 13.1s |  |
| 8 | `RollOverOutTest` | 5 | 13.0s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.8s |  |
| 10 | `Version4Loader` | 11 | 1.7s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.2s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 21.6s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 21.4s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 21.5s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 21.1s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.7s |  |
| 19 | `attachExtImported` | 2 | 21.7s |  |
| 20 | `attachImported` | 2 | 1.9s |  |
| 21 | `attachMovieLoopingTest` | 41 | 20.5s |  |
| 22 | `attachMovieTest` | 12 | 20.8s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 21.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.0s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.7s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 21.5s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 22.1s |  |
| 33 | `event_handler_scope_test` | 16 | 2.4s |  |
| 34 | `frame_label_test` | 17 | 23.6s |  |
| 35 | `getTimer_test` | 8 | 22.6s |  |
| 36 | `get_frame_number_test` | 31 | 24.7s |  |
| 37 | `gotoFrame2Test` | 9 | 21.5s |  |
| 38 | `goto_frame_test` | 15 | 21.7s |  |
| 39 | `instanceNameTest` | 5 | 1.9s |  |
| 40 | `loading/LoadVarsTest` | 36 | 23.9s |  |
| 41 | `loop/loop_test` | 21 | 21.0s |  |
| 42 | `loop/loop_test2` | 15 | 20.9s |  |
| 43 | `loop/loop_test3` | 16 | 1.9s |  |
| 44 | `loop/loop_test4` | 22 | 20.2s |  |
| 45 | `loop/loop_test5` | 24 | 2.7s |  |
| 46 | `loop/loop_test8` | 38 | 22.9s |  |
| 47 | `loop/loop_test9` | 15 | 20.8s |  |
| 48 | `loop/simple_loop_test` | 0 | 20.7s |  |
| 49 | `masks_test2` | 10 | 17.3s |  |
| 50 | `morph_test1` | 0 | 21.3s |  |
| 51 | `move_object_test` | 11 | 20.8s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 21.1s |  |
| 53 | `new_child_in_unload_test` | 11 | 21.2s |  |
| 54 | `opcode_guard_test` | 18 | 21.6s |  |
| 55 | `place_and_remove_object_insane_test` | 22 | 21.6s |  |
| 56 | `place_and_remove_object_test` | 13 | 21.4s |  |
| 57 | `register_class/RegisterClassTest3` | 12 | 23.6s |  |
| 58 | `register_class/registerClassTest` | 51 | 25.8s |  |
| 59 | `replace_shapes1test` | 23 | 2.4s |  |
| 60 | `replace_sprites1test` | 21 | 23.1s |  |
| 61 | `reverse_execute_PlaceObject2_test1` | 8 | 22.7s |  |
| 62 | `reverse_execute_PlaceObject2_test2` | 10 | 23.0s |  |
| 63 | `runtime_vm_stack_test` | 9 | 21.3s |  |
| 64 | `shape_test` | 21 | 22.3s |  |
| 65 | `static_vs_dynamic1` | 17 | 20.6s |  |
| 66 | `static_vs_dynamic2` | 18 | 21.7s |  |
| 67 | `timeline_var_test` | 11 | 21.1s |  |
| 68 | `unload_movieclip_test1` | 6 | 20.4s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 25.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 26.2s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 20.9s |  |
| 4 | `DefineTextTest` | 4 | 4 | 20.6s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.2s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 25.8s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.6s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 18.2s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 22.4s |  |
| 10 | `callFunction_test` | 6 | 11 | 22.4s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 29.4s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.8s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.1s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.1s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.4s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 22.4s |  |
| 17 | `key_event_test` | 5 | 6 | 19.7s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 19.0s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 3.8s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 21.8s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 19.9s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 2.1s |  |
| 23 | `matrix_test` | 5 | 9 | 97.9s |  |
| 24 | `path_format_test` | 28 | 28 | 23.5s |  |
| 25 | `place_object_test` | 14 | 14 | 22.1s |  |
| 26 | `place_object_test2` | 22 | 23 | 22.2s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 22.0s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 20.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**15 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `action_order/action_execution_order_test5` | 47.3% | 26/55 | 55 | 35 |  |
| 4 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 5 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 6 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 7 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 8 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 9 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 10 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 11 | `action_order/ActionOrderTest4` | 7.0% | 9/129 | 129 | 64 |  |
| 12 | `action_order/ActionOrderTest3` | 4.5% | 4/89 | 89 | 62 |  |
| 13 | `register_class/RegisterClassTest4` | 4.0% | 3/75 | 75 | 42 |  |
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 15 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
