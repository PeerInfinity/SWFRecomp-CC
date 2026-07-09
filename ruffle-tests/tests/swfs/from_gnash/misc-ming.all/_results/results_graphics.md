# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-09 02:01 UTC

**Git SHA**: `d9814fd9b9`

**Run Duration**: 36m 6s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **68** (61.3%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **96** (86.5%) |
| Failing | 15 |
| Total expected lines | 5248 |
| Matching lines | 4048 (77.1%) |
| Mismatched lines | 1200 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 15 | 100.0% |

## Passing Tests

**68 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.8s |  |
| 2 | `DefineEditTextTest` | 153 | 28.0s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.3s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 21.8s |  |
| 5 | `DepthLimitsTest` | 20 | 23.4s |  |
| 6 | `PlaceObject2Test` | 9 | 21.2s |  |
| 7 | `ResolveEventsTest` | 15 | 24.3s |  |
| 8 | `RollOverOutTest` | 5 | 23.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.7s |  |
| 10 | `Version4Loader` | 11 | 2.6s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.4s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 18.7s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 18.9s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 22.4s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.5s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 21.0s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 21.4s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.4s |  |
| 20 | `attachExtImported` | 2 | 22.7s |  |
| 21 | `attachImported` | 2 | 2.7s |  |
| 22 | `attachMovieLoopingTest` | 41 | 21.8s |  |
| 23 | `attachMovieTest` | 12 | 22.5s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 21.3s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.7s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.2s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 21.9s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 22.0s |  |
| 34 | `event_handler_scope_test` | 16 | 3.0s |  |
| 35 | `frame_label_test` | 17 | 19.2s |  |
| 36 | `getTimer_test` | 8 | 18.5s |  |
| 37 | `get_frame_number_test` | 31 | 20.1s |  |
| 38 | `gotoFrame2Test` | 9 | 18.1s |  |
| 39 | `goto_frame_test` | 15 | 23.4s |  |
| 40 | `instanceNameTest` | 5 | 2.7s |  |
| 41 | `loading/LoadVarsTest` | 36 | 25.3s |  |
| 42 | `loop/loop_test` | 21 | 22.1s |  |
| 43 | `loop/loop_test2` | 15 | 21.8s |  |
| 44 | `loop/loop_test3` | 16 | 2.8s |  |
| 45 | `loop/loop_test4` | 22 | 22.9s |  |
| 46 | `loop/loop_test5` | 24 | 3.8s |  |
| 47 | `loop/loop_test8` | 38 | 19.6s |  |
| 48 | `loop/loop_test9` | 15 | 17.7s |  |
| 49 | `loop/simple_loop_test` | 0 | 20.1s |  |
| 50 | `masks_test2` | 10 | 22.0s |  |
| 51 | `morph_test1` | 0 | 25.2s |  |
| 52 | `move_object_test` | 11 | 21.4s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 21.4s |  |
| 54 | `new_child_in_unload_test` | 11 | 21.4s |  |
| 55 | `opcode_guard_test` | 18 | 21.6s |  |
| 56 | `place_and_remove_object_test` | 13 | 23.2s |  |
| 57 | `register_class/RegisterClassTest3` | 12 | 22.7s |  |
| 58 | `register_class/registerClassTest` | 51 | 24.9s |  |
| 59 | `replace_shapes1test` | 23 | 3.5s |  |
| 60 | `replace_sprites1test` | 21 | 23.1s |  |
| 61 | `reverse_execute_PlaceObject2_test1` | 8 | 22.6s |  |
| 62 | `reverse_execute_PlaceObject2_test2` | 10 | 22.6s |  |
| 63 | `runtime_vm_stack_test` | 9 | 20.8s |  |
| 64 | `shape_test` | 21 | 21.3s |  |
| 65 | `static_vs_dynamic1` | 17 | 20.4s |  |
| 66 | `static_vs_dynamic2` | 18 | 20.2s |  |
| 67 | `timeline_var_test` | 11 | 20.0s |  |
| 68 | `unload_movieclip_test1` | 6 | 20.0s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 20.7s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 20.6s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 20.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 19.4s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.8s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 32.6s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 22.7s |  |
| 10 | `callFunction_test` | 6 | 11 | 22.1s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 28.7s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 22.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.9s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.4s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 22.8s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 24.4s |  |
| 17 | `key_event_test` | 5 | 6 | 23.7s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 23.0s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 5.3s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 23.2s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 22.9s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.2s |  |
| 23 | `matrix_test` | 5 | 9 | 104.6s |  |
| 24 | `path_format_test` | 28 | 28 | 23.9s |  |
| 25 | `place_object_test` | 14 | 14 | 24.4s |  |
| 26 | `place_object_test2` | 22 | 23 | 23.5s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 24.0s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 22.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17 | 22 | 5 |  |

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
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
| 4 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 5 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 6 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 7 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 8 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 9 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 10 | `register_class/RegisterClassTest4` | 10.5% | 6/57 | 57 | 42 |  |
| 11 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 9.5% | 10/105 | 105 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 5.5% | 4/73 | 73 | 62 |  |
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 15 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
