# Ruffle Test Results (Filtered)

**Date**: 2026-07-22 19:47 UTC

**Git SHA**: `9ab376ded1`

**Run Duration**: 27m 48s

**Filtered**: 2 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 109 |
| Passing | **68** (62.4%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **96** (88.1%) |
| Failing | 13 |
| Total expected lines | 5188 |
| Matching lines | 4029 (77.7%) |
| Mismatched lines | 1159 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**68 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.2s |  |
| 2 | `DefineEditTextTest` | 153 | 30.7s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 25.0s |  |
| 5 | `DepthLimitsTest` | 20 | 22.6s |  |
| 6 | `PlaceObject2Test` | 9 | 1.9s |  |
| 7 | `ResolveEventsTest` | 15 | 3.1s |  |
| 8 | `RollOverOutTest` | 5 | 21.1s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.9s |  |
| 10 | `Version4Loader` | 11 | 1.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.0s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 16.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 16.4s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.7s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.7s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 15.8s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 16.2s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.7s |  |
| 20 | `attachExtImported` | 2 | 22.2s |  |
| 21 | `attachImported` | 2 | 2.0s |  |
| 22 | `attachMovieLoopingTest` | 41 | 21.6s |  |
| 23 | `attachMovieTest` | 12 | 22.1s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 20.3s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 2.0s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.7s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.8s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.7s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 2.8s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 20.6s |  |
| 34 | `event_handler_scope_test` | 16 | 2.2s |  |
| 35 | `frame_label_test` | 17 | 21.2s |  |
| 36 | `getTimer_test` | 8 | 20.0s |  |
| 37 | `get_frame_number_test` | 31 | 4.4s |  |
| 38 | `gotoFrame2Test` | 9 | 19.9s |  |
| 39 | `goto_frame_test` | 15 | 21.3s |  |
| 40 | `instanceNameTest` | 5 | 1.8s |  |
| 41 | `loading/LoadVarsTest` | 36 | 24.0s |  |
| 42 | `loop/loop_test` | 21 | 20.1s |  |
| 43 | `loop/loop_test2` | 15 | 20.0s |  |
| 44 | `loop/loop_test3` | 16 | 1.9s |  |
| 45 | `loop/loop_test4` | 22 | 21.4s |  |
| 46 | `loop/loop_test5` | 24 | 3.1s |  |
| 47 | `loop/loop_test8` | 38 | 26.0s |  |
| 48 | `loop/loop_test9` | 15 | 23.6s |  |
| 49 | `loop/simple_loop_test` | 0 | 21.7s |  |
| 50 | `masks_test2` | 10 | 18.8s |  |
| 51 | `morph_test1` | 0 | 18.5s |  |
| 52 | `move_object_test` | 11 | 1.3s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 15.3s |  |
| 54 | `new_child_in_unload_test` | 11 | 14.5s |  |
| 55 | `place_and_remove_object_insane_test` | 22 | 21.0s |  |
| 56 | `place_and_remove_object_test` | 13 | 20.0s |  |
| 57 | `register_class/RegisterClassTest3` | 12 | 19.6s |  |
| 58 | `register_class/registerClassTest` | 51 | 21.0s |  |
| 59 | `replace_shapes1test` | 23 | 2.5s |  |
| 60 | `replace_sprites1test` | 21 | 20.6s |  |
| 61 | `reverse_execute_PlaceObject2_test1` | 8 | 20.1s |  |
| 62 | `reverse_execute_PlaceObject2_test2` | 10 | 2.2s |  |
| 63 | `runtime_vm_stack_test` | 9 | 19.0s |  |
| 64 | `shape_test` | 21 | 19.2s |  |
| 65 | `static_vs_dynamic1` | 17 | 19.0s |  |
| 66 | `static_vs_dynamic2` | 18 | 20.4s |  |
| 67 | `timeline_var_test` | 11 | 20.7s |  |
| 68 | `unload_movieclip_test1` | 6 | 20.5s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 0.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 0.5s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 0.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 22.1s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.3s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 7.5s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.4s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 29.5s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 20.7s |  |
| 10 | `callFunction_test` | 6 | 11 | 20.6s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.4s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 1.7s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.8s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 21.1s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.0s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 3.5s |  |
| 17 | `key_event_test` | 5 | 6 | 21.6s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 3.1s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 4.6s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 20.9s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 21.1s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 2.4s |  |
| 23 | `matrix_test` | 5 | 9 | 84.3s |  |
| 24 | `path_format_test` | 28 | 28 | 23.0s |  |
| 25 | `place_object_test` | 14 | 14 | 20.7s |  |
| 26 | `place_object_test2` | 22 | 23 | 2.4s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 22.6s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 21.1s |  |

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

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 4 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 5 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 6 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 7 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 8 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 9 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 10 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 11 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
| 12 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 13 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
