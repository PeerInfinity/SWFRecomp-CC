# Ruffle Test Results (Filtered)

**Date**: 2026-07-16 03:15 UTC

**Git SHA**: `cd80a6b014`

**Run Duration**: 17m 30s

**Filtered**: 2 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 109 |
| Passing | **67** (61.5%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **95** (87.2%) |
| Failing | 14 |
| Total expected lines | 5188 |
| Matching lines | 4024 (77.6%) |
| Mismatched lines | 1164 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**67 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 2.9s |  |
| 2 | `DefineEditTextTest` | 153 | 12.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.3s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.8s |  |
| 5 | `DepthLimitsTest` | 20 | 22.7s |  |
| 6 | `PlaceObject2Test` | 9 | 2.2s |  |
| 7 | `ResolveEventsTest` | 15 | 4.0s |  |
| 8 | `RollOverOutTest` | 5 | 3.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.6s |  |
| 10 | `Version4Loader` | 11 | 2.5s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 3.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 2.9s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.5s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 0.7s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 0.7s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.7s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.7s |  |
| 20 | `attachExtImported` | 2 | 22.0s |  |
| 21 | `attachImported` | 2 | 2.6s |  |
| 22 | `attachMovieLoopingTest` | 41 | 20.8s |  |
| 23 | `attachMovieTest` | 12 | 3.4s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 3.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 2.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 3.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.9s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.9s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 4.0s |  |
| 34 | `event_handler_scope_test` | 16 | 3.2s |  |
| 35 | `frame_label_test` | 17 | 4.4s |  |
| 36 | `getTimer_test` | 8 | 3.0s |  |
| 37 | `get_frame_number_test` | 31 | 5.7s |  |
| 38 | `gotoFrame2Test` | 9 | 21.2s |  |
| 39 | `goto_frame_test` | 15 | 20.9s |  |
| 40 | `instanceNameTest` | 5 | 2.3s |  |
| 41 | `loading/LoadVarsTest` | 36 | 27.1s |  |
| 42 | `loop/loop_test` | 21 | 16.9s |  |
| 43 | `loop/loop_test2` | 15 | 2.2s |  |
| 44 | `loop/loop_test3` | 16 | 2.2s |  |
| 45 | `loop/loop_test4` | 22 | 3.4s |  |
| 46 | `loop/loop_test5` | 24 | 3.4s |  |
| 47 | `loop/loop_test8` | 38 | 5.2s |  |
| 48 | `loop/loop_test9` | 15 | 21.3s |  |
| 49 | `loop/simple_loop_test` | 0 | 25.1s |  |
| 50 | `masks_test2` | 10 | 22.5s |  |
| 51 | `morph_test1` | 0 | 27.1s |  |
| 52 | `move_object_test` | 11 | 2.8s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 21.1s |  |
| 54 | `new_child_in_unload_test` | 11 | 2.9s |  |
| 55 | `place_and_remove_object_test` | 13 | 20.7s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 0.9s |  |
| 57 | `register_class/registerClassTest` | 51 | 1.0s |  |
| 58 | `replace_shapes1test` | 23 | 3.1s |  |
| 59 | `replace_sprites1test` | 21 | 3.5s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 2.7s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 3.1s |  |
| 62 | `runtime_vm_stack_test` | 9 | 0.8s |  |
| 63 | `shape_test` | 21 | 1.4s |  |
| 64 | `static_vs_dynamic1` | 17 | 0.8s |  |
| 65 | `static_vs_dynamic2` | 18 | 2.1s |  |
| 66 | `timeline_var_test` | 11 | 1.9s |  |
| 67 | `unload_movieclip_test1` | 6 | 1.8s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 3.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 3.6s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 1.9s |  |
| 4 | `DefineTextTest` | 4 | 4 | 3.1s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.7s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 7.7s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 2.5s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 12.1s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 3.9s |  |
| 10 | `callFunction_test` | 6 | 11 | 3.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 29.5s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 3.0s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.9s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 4.5s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 20.6s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 4.0s |  |
| 17 | `key_event_test` | 5 | 6 | 25.8s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 4.4s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 6.0s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 17.6s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 3.2s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 2.8s |  |
| 23 | `matrix_test` | 5 | 9 | 113.0s |  |
| 24 | `path_format_test` | 28 | 28 | 4.5s |  |
| 25 | `place_object_test` | 14 | 14 | 3.7s |  |
| 26 | `place_object_test2` | 22 | 23 | 3.1s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 17.2s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 2.5s |  |

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

**14 tests** with output mismatch, sorted by match rate (best first)

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
| 10 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 11 | `action_order/ActionOrderTest4` | 9.5% | 10/105 | 105 | 64 |  |
| 12 | `action_order/ActionOrderTest3` | 5.5% | 4/73 | 73 | 62 |  |
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
