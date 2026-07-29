# Ruffle Test Results (Filtered)

**Date**: 2026-07-29 01:25 UTC

**Git SHA**: `767a301d2b`

**Run Duration**: 36m 42s

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
| 1 | `BeginBitmapFill` | 1 | 22.9s |  |
| 2 | `DefineEditTextTest` | 153 | 32.1s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.4s |  |
| 5 | `DepthLimitsTest` | 20 | 23.1s |  |
| 6 | `PlaceObject2Test` | 9 | 21.2s |  |
| 7 | `ResolveEventsTest` | 15 | 22.6s |  |
| 8 | `RollOverOutTest` | 5 | 22.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.6s |  |
| 10 | `Version4Loader` | 11 | 2.5s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.0s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 23.5s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.4s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 21.4s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.3s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 21.8s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 24.3s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.2s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 3.0s |  |
| 20 | `attachExtImported` | 2 | 22.7s |  |
| 21 | `attachImported` | 2 | 2.9s |  |
| 22 | `attachMovieLoopingTest` | 41 | 21.9s |  |
| 23 | `attachMovieTest` | 12 | 22.1s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 22.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 22.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 3.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.4s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 24.9s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 24.2s |  |
| 34 | `event_handler_scope_test` | 16 | 3.4s |  |
| 35 | `frame_label_test` | 17 | 22.9s |  |
| 36 | `getTimer_test` | 8 | 21.8s |  |
| 37 | `get_frame_number_test` | 31 | 24.3s |  |
| 38 | `gotoFrame2Test` | 9 | 21.4s |  |
| 39 | `goto_frame_test` | 15 | 21.6s |  |
| 40 | `instanceNameTest` | 5 | 2.3s |  |
| 41 | `loading/LoadVarsTest` | 36 | 25.4s |  |
| 42 | `loop/loop_test` | 21 | 17.0s |  |
| 43 | `loop/loop_test2` | 15 | 16.7s |  |
| 44 | `loop/loop_test3` | 16 | 2.2s |  |
| 45 | `loop/loop_test4` | 22 | 23.1s |  |
| 46 | `loop/loop_test5` | 24 | 4.0s |  |
| 47 | `loop/loop_test8` | 38 | 23.7s |  |
| 48 | `loop/loop_test9` | 15 | 21.3s |  |
| 49 | `loop/simple_loop_test` | 0 | 25.0s |  |
| 50 | `masks_test2` | 10 | 16.9s |  |
| 51 | `morph_test1` | 0 | 19.8s |  |
| 52 | `move_object_test` | 11 | 21.5s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 21.4s |  |
| 54 | `new_child_in_unload_test` | 11 | 21.4s |  |
| 55 | `place_and_remove_object_insane_test` | 22 | 22.1s |  |
| 56 | `place_and_remove_object_test` | 13 | 21.4s |  |
| 57 | `register_class/RegisterClassTest3` | 12 | 22.1s |  |
| 58 | `register_class/registerClassTest` | 51 | 23.7s |  |
| 59 | `replace_shapes1test` | 23 | 3.4s |  |
| 60 | `replace_sprites1test` | 21 | 19.7s |  |
| 61 | `reverse_execute_PlaceObject2_test1` | 8 | 19.8s |  |
| 62 | `reverse_execute_PlaceObject2_test2` | 10 | 19.8s |  |
| 63 | `runtime_vm_stack_test` | 9 | 21.5s |  |
| 64 | `shape_test` | 21 | 23.3s |  |
| 65 | `static_vs_dynamic1` | 17 | 21.0s |  |
| 66 | `static_vs_dynamic2` | 18 | 22.0s |  |
| 67 | `timeline_var_test` | 11 | 21.5s |  |
| 68 | `unload_movieclip_test1` | 6 | 21.2s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 25.6s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 26.5s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.3s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.8s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.7s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.4s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.4s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 31.1s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 22.3s |  |
| 10 | `callFunction_test` | 6 | 11 | 22.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 29.7s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.8s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.9s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 25.6s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.2s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 22.3s |  |
| 17 | `key_event_test` | 5 | 6 | 23.7s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 23.0s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 5.5s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 17.5s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 23.0s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.4s |  |
| 23 | `matrix_test` | 5 | 9 | 93.7s |  |
| 24 | `path_format_test` | 28 | 28 | 24.3s |  |
| 25 | `place_object_test` | 14 | 14 | 22.4s |  |
| 26 | `place_object_test2` | 22 | 23 | 21.8s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 23.8s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 22.8s |  |

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
| 9 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 10 | `action_order/ActionOrderTest4` | 9.5% | 10/105 | 105 | 64 |  |
| 11 | `action_order/ActionOrderTest3` | 5.5% | 4/73 | 73 | 62 |  |
| 12 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 13 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
