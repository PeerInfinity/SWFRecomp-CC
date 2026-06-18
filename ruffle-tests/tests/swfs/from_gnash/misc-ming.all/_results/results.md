# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 18:14 UTC

**Git SHA**: `9926de76f4`

**Run Duration**: 29m 1s

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
| 1 | `BeginBitmapFill` | 1 | 0.2s |  |
| 2 | `DefineEditTextTest` | 153 | 29.1s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.8s |  |
| 5 | `DepthLimitsTest` | 20 | 22.3s |  |
| 6 | `PlaceObject2Test` | 9 | 2.1s |  |
| 7 | `ResolveEventsTest` | 15 | 3.0s |  |
| 8 | `RollOverOutTest` | 5 | 20.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.9s |  |
| 10 | `Version4Loader` | 11 | 1.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.0s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.1s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 21.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 21.1s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 20.9s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 21.3s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.7s |  |
| 19 | `attachExtImported` | 2 | 21.3s |  |
| 20 | `attachImported` | 2 | 1.9s |  |
| 21 | `attachMovieLoopingTest` | 41 | 20.5s |  |
| 22 | `attachMovieTest` | 12 | 21.0s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 21.1s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 1.7s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.0s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.8s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 2.9s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 22.1s |  |
| 33 | `event_handler_scope_test` | 16 | 2.3s |  |
| 34 | `frame_label_test` | 17 | 21.9s |  |
| 35 | `getTimer_test` | 8 | 20.9s |  |
| 36 | `get_frame_number_test` | 31 | 4.3s |  |
| 37 | `gotoFrame2Test` | 9 | 20.1s |  |
| 38 | `goto_frame_test` | 15 | 21.1s |  |
| 39 | `instanceNameTest` | 5 | 1.8s |  |
| 40 | `loading/LoadVarsTest` | 36 | 23.5s |  |
| 41 | `loop/loop_test` | 21 | 21.4s |  |
| 42 | `loop/loop_test2` | 15 | 21.0s |  |
| 43 | `loop/loop_test3` | 16 | 1.9s |  |
| 44 | `loop/loop_test4` | 22 | 20.7s |  |
| 45 | `loop/loop_test5` | 24 | 2.9s |  |
| 46 | `loop/loop_test8` | 38 | 22.7s |  |
| 47 | `loop/loop_test9` | 15 | 20.5s |  |
| 48 | `loop/simple_loop_test` | 0 | 20.4s |  |
| 49 | `masks_test2` | 10 | 22.5s |  |
| 50 | `morph_test1` | 0 | 22.0s |  |
| 51 | `move_object_test` | 11 | 2.0s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 20.3s |  |
| 53 | `new_child_in_unload_test` | 11 | 20.7s |  |
| 54 | `opcode_guard_test` | 18 | 22.2s |  |
| 55 | `place_and_remove_object_insane_test` | 22 | 22.5s |  |
| 56 | `place_and_remove_object_test` | 13 | 16.2s |  |
| 57 | `register_class/RegisterClassTest3` | 12 | 21.5s |  |
| 58 | `register_class/registerClassTest` | 51 | 23.5s |  |
| 59 | `replace_shapes1test` | 23 | 2.4s |  |
| 60 | `replace_sprites1test` | 21 | 22.7s |  |
| 61 | `reverse_execute_PlaceObject2_test1` | 8 | 21.6s |  |
| 62 | `reverse_execute_PlaceObject2_test2` | 10 | 2.3s |  |
| 63 | `runtime_vm_stack_test` | 9 | 20.3s |  |
| 64 | `shape_test` | 21 | 21.5s |  |
| 65 | `static_vs_dynamic1` | 17 | 19.9s |  |
| 66 | `static_vs_dynamic2` | 18 | 20.2s |  |
| 67 | `timeline_var_test` | 11 | 19.9s |  |
| 68 | `unload_movieclip_test1` | 6 | 19.6s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 0.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 0.5s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 0.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 20.7s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.2s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 7.3s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.5s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 28.9s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 21.8s |  |
| 10 | `callFunction_test` | 6 | 11 | 21.8s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.7s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.1s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.0s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.4s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 20.8s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 3.4s |  |
| 17 | `key_event_test` | 5 | 6 | 21.4s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 3.1s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 4.5s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 21.9s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 20.6s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 2.3s |  |
| 23 | `matrix_test` | 5 | 9 | 106.3s |  |
| 24 | `path_format_test` | 28 | 28 | 24.1s |  |
| 25 | `place_object_test` | 14 | 14 | 16.7s |  |
| 26 | `place_object_test2` | 22 | 23 | 2.2s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 21.6s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 20.4s |  |

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
