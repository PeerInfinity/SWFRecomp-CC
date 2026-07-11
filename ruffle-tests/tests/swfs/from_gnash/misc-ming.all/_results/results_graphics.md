# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-11 03:06 UTC

**Git SHA**: `83bef14d7e`

**Run Duration**: 34m 38s

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
| 1 | `BeginBitmapFill` | 1 | 16.2s |  |
| 2 | `DefineEditTextTest` | 153 | 32.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 28.1s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.9s |  |
| 5 | `DepthLimitsTest` | 20 | 22.3s |  |
| 6 | `PlaceObject2Test` | 9 | 21.2s |  |
| 7 | `ResolveEventsTest` | 15 | 19.2s |  |
| 8 | `RollOverOutTest` | 5 | 18.3s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.6s |  |
| 10 | `Version4Loader` | 11 | 2.5s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.2s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.9s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.6s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 15.2s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 15.2s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.9s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.9s |  |
| 20 | `attachExtImported` | 2 | 23.5s |  |
| 21 | `attachImported` | 2 | 2.9s |  |
| 22 | `attachMovieLoopingTest` | 41 | 22.1s |  |
| 23 | `attachMovieTest` | 12 | 23.0s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 20.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.2s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 22.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.9s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.8s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 22.1s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 22.2s |  |
| 34 | `event_handler_scope_test` | 16 | 3.1s |  |
| 35 | `frame_label_test` | 17 | 23.0s |  |
| 36 | `getTimer_test` | 8 | 21.6s |  |
| 37 | `get_frame_number_test` | 31 | 24.2s |  |
| 38 | `gotoFrame2Test` | 9 | 21.6s |  |
| 39 | `goto_frame_test` | 15 | 21.6s |  |
| 40 | `instanceNameTest` | 5 | 2.6s |  |
| 41 | `loading/LoadVarsTest` | 36 | 25.3s |  |
| 42 | `loop/loop_test` | 21 | 22.2s |  |
| 43 | `loop/loop_test2` | 15 | 22.1s |  |
| 44 | `loop/loop_test3` | 16 | 2.8s |  |
| 45 | `loop/loop_test4` | 22 | 22.9s |  |
| 46 | `loop/loop_test5` | 24 | 4.0s |  |
| 47 | `loop/loop_test8` | 38 | 19.9s |  |
| 48 | `loop/loop_test9` | 15 | 18.2s |  |
| 49 | `loop/simple_loop_test` | 0 | 21.1s |  |
| 50 | `masks_test2` | 10 | 20.5s |  |
| 51 | `morph_test1` | 0 | 23.5s |  |
| 52 | `move_object_test` | 11 | 21.1s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 21.0s |  |
| 54 | `new_child_in_unload_test` | 11 | 21.0s |  |
| 55 | `opcode_guard_test` | 18 | 19.3s |  |
| 56 | `place_and_remove_object_test` | 13 | 21.8s |  |
| 57 | `register_class/RegisterClassTest3` | 12 | 18.8s |  |
| 58 | `register_class/registerClassTest` | 51 | 19.0s |  |
| 59 | `replace_shapes1test` | 23 | 3.3s |  |
| 60 | `replace_sprites1test` | 21 | 21.7s |  |
| 61 | `reverse_execute_PlaceObject2_test1` | 8 | 20.6s |  |
| 62 | `reverse_execute_PlaceObject2_test2` | 10 | 20.9s |  |
| 63 | `runtime_vm_stack_test` | 9 | 17.2s |  |
| 64 | `shape_test` | 21 | 17.7s |  |
| 65 | `static_vs_dynamic1` | 17 | 16.9s |  |
| 66 | `static_vs_dynamic2` | 18 | 19.8s |  |
| 67 | `timeline_var_test` | 11 | 19.3s |  |
| 68 | `unload_movieclip_test1` | 6 | 19.2s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 15.8s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 15.6s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 15.5s |  |
| 4 | `DefineTextTest` | 4 | 4 | 22.3s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 25.9s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.7s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 26.0s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 21.9s |  |
| 10 | `callFunction_test` | 6 | 11 | 21.6s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.9s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.6s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.8s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.2s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.5s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 22.7s |  |
| 17 | `key_event_test` | 5 | 6 | 23.9s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 23.0s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 5.5s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 23.3s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 22.5s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.3s |  |
| 23 | `matrix_test` | 5 | 9 | 89.7s |  |
| 24 | `path_format_test` | 28 | 28 | 19.3s |  |
| 25 | `place_object_test` | 14 | 14 | 22.4s |  |
| 26 | `place_object_test2` | 22 | 23 | 21.7s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 22.4s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 21.2s |  |

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
