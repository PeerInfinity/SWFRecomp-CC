# Ruffle Test Results (Filtered)

**Date**: 2026-06-26 18:47 UTC

**Git SHA**: `1af043d3e7`

**Run Duration**: 34m 46s

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
| Matching lines | 4021 (77.5%) |
| Mismatched lines | 1167 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**67 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 22.8s |  |
| 2 | `DefineEditTextTest` | 153 | 31.0s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.4s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.7s |  |
| 5 | `DepthLimitsTest` | 20 | 24.2s |  |
| 6 | `PlaceObject2Test` | 9 | 20.4s |  |
| 7 | `ResolveEventsTest` | 15 | 20.9s |  |
| 8 | `RollOverOutTest` | 5 | 20.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.8s |  |
| 10 | `Version4Loader` | 11 | 1.8s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.8s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.9s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 21.0s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.4s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 20.9s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 20.8s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.5s |  |
| 19 | `attachExtImported` | 2 | 22.3s |  |
| 20 | `attachImported` | 2 | 1.8s |  |
| 21 | `attachMovieLoopingTest` | 41 | 21.8s |  |
| 22 | `attachMovieTest` | 12 | 21.9s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 20.4s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.3s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 22.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.1s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.4s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.4s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 21.6s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 21.7s |  |
| 33 | `event_handler_scope_test` | 16 | 2.3s |  |
| 34 | `frame_label_test` | 17 | 20.2s |  |
| 35 | `getTimer_test` | 8 | 19.1s |  |
| 36 | `get_frame_number_test` | 31 | 21.1s |  |
| 37 | `gotoFrame2Test` | 9 | 18.9s |  |
| 38 | `goto_frame_test` | 15 | 23.6s |  |
| 39 | `instanceNameTest` | 5 | 1.9s |  |
| 40 | `loading/LoadVarsTest` | 36 | 23.7s |  |
| 41 | `loop/loop_test` | 21 | 20.5s |  |
| 42 | `loop/loop_test2` | 15 | 20.4s |  |
| 43 | `loop/loop_test3` | 16 | 1.9s |  |
| 44 | `loop/loop_test4` | 22 | 13.6s |  |
| 45 | `loop/loop_test5` | 24 | 1.9s |  |
| 46 | `loop/loop_test8` | 38 | 23.6s |  |
| 47 | `loop/loop_test9` | 15 | 21.0s |  |
| 48 | `loop/simple_loop_test` | 0 | 20.5s |  |
| 49 | `masks_test2` | 10 | 20.7s |  |
| 50 | `morph_test1` | 0 | 22.3s |  |
| 51 | `move_object_test` | 11 | 20.1s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 20.2s |  |
| 53 | `new_child_in_unload_test` | 11 | 20.3s |  |
| 54 | `place_and_remove_object_insane_test` | 22 | 20.9s |  |
| 55 | `place_and_remove_object_test` | 13 | 21.5s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 21.3s |  |
| 57 | `register_class/registerClassTest` | 51 | 23.5s |  |
| 58 | `replace_shapes1test` | 23 | 2.3s |  |
| 59 | `replace_sprites1test` | 21 | 19.6s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 19.1s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 19.2s |  |
| 62 | `runtime_vm_stack_test` | 9 | 19.8s |  |
| 63 | `shape_test` | 21 | 19.8s |  |
| 64 | `static_vs_dynamic1` | 17 | 20.2s |  |
| 65 | `static_vs_dynamic2` | 18 | 20.9s |  |
| 66 | `timeline_var_test` | 11 | 20.6s |  |
| 67 | `unload_movieclip_test1` | 6 | 20.1s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 26.0s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 26.9s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.7s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.4s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.3s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.4s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.6s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 28.6s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 21.5s |  |
| 10 | `callFunction_test` | 6 | 11 | 21.0s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.6s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 23.5s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.2s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.0s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 22.2s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 23.8s |  |
| 17 | `key_event_test` | 5 | 6 | 21.6s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 21.7s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 4.5s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 21.2s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 13.2s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 1.5s |  |
| 23 | `matrix_test` | 5 | 9 | 101.9s |  |
| 24 | `path_format_test` | 28 | 28 | 22.7s |  |
| 25 | `place_object_test` | 14 | 14 | 22.0s |  |
| 26 | `place_object_test2` | 22 | 23 | 21.9s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 22.8s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 21.8s |  |

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

**14 tests** with output mismatch, sorted by match rate (best first)

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
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
