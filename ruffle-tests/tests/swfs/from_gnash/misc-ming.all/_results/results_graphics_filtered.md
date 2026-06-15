# Ruffle Test Results (Filtered)

**Date**: 2026-06-15 00:30 UTC

**Git SHA**: `22a981318b`

**Run Duration**: 36m 1s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **65** (60.2%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **93** (86.1%) |
| Failing | 15 |
| Total expected lines | 5179 |
| Matching lines | 4007 (77.4%) |
| Mismatched lines | 1172 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 15 | 100.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 24.8s |  |
| 2 | `DefineEditTextTest` | 153 | 31.5s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.3s |  |
| 5 | `DepthLimitsTest` | 20 | 23.0s |  |
| 6 | `PlaceObject2Test` | 9 | 21.9s |  |
| 7 | `ResolveEventsTest` | 15 | 21.9s |  |
| 8 | `RollOverOutTest` | 5 | 21.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.6s |  |
| 10 | `Version4Loader` | 11 | 2.4s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.3s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.7s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 21.7s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 21.4s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 19.2s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 19.2s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 0.9s |  |
| 19 | `attachExtImported` | 2 | 22.1s |  |
| 20 | `attachImported` | 2 | 2.7s |  |
| 21 | `attachMovieLoopingTest` | 41 | 21.5s |  |
| 22 | `attachMovieTest` | 12 | 22.3s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 21.9s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 22.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 22.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.0s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.7s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.7s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.6s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 22.8s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 22.8s |  |
| 33 | `event_handler_scope_test` | 16 | 3.2s |  |
| 34 | `frame_label_test` | 17 | 25.4s |  |
| 35 | `getTimer_test` | 8 | 24.1s |  |
| 36 | `get_frame_number_test` | 31 | 27.0s |  |
| 37 | `goto_frame_test` | 15 | 24.5s |  |
| 38 | `instanceNameTest` | 5 | 2.7s |  |
| 39 | `loading/LoadVarsTest` | 36 | 25.7s |  |
| 40 | `loop/loop_test` | 21 | 21.7s |  |
| 41 | `loop/loop_test2` | 15 | 21.8s |  |
| 42 | `loop/loop_test3` | 16 | 2.7s |  |
| 43 | `loop/loop_test4` | 22 | 22.5s |  |
| 44 | `loop/loop_test5` | 24 | 20.1s |  |
| 45 | `loop/loop_test8` | 38 | 4.6s |  |
| 46 | `loop/loop_test9` | 15 | 22.1s |  |
| 47 | `loop/simple_loop_test` | 0 | 27.1s |  |
| 48 | `masks_test2` | 10 | 21.9s |  |
| 49 | `morph_test1` | 0 | 25.7s |  |
| 50 | `move_object_test` | 11 | 21.6s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 21.5s |  |
| 52 | `new_child_in_unload_test` | 11 | 21.9s |  |
| 53 | `place_and_remove_object_test` | 13 | 21.0s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 22.1s |  |
| 55 | `register_class/registerClassTest` | 51 | 24.8s |  |
| 56 | `replace_shapes1test` | 23 | 3.1s |  |
| 57 | `replace_sprites1test` | 21 | 22.1s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 2.7s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 22.4s |  |
| 60 | `runtime_vm_stack_test` | 9 | 22.6s |  |
| 61 | `shape_test` | 21 | 26.2s |  |
| 62 | `static_vs_dynamic1` | 17 | 22.0s |  |
| 63 | `static_vs_dynamic2` | 18 | 21.8s |  |
| 64 | `timeline_var_test` | 11 | 2.8s |  |
| 65 | `unload_movieclip_test1` | 6 | 20.9s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 25.8s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 26.7s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.6s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.7s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.9s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 22.2s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 29.8s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 22.4s |  |
| 10 | `callFunction_test` | 6 | 11 | 22.6s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 30.1s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 22.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.0s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 23.3s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 22.4s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 24.4s |  |
| 17 | `key_event_test` | 5 | 6 | 24.5s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 23.5s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 5.5s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 22.7s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 19.7s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.0s |  |
| 23 | `matrix_test` | 5 | 9 | 108.2s |  |
| 24 | `path_format_test` | 28 | 28 | 20.7s |  |
| 25 | `place_object_test` | 14 | 14 | 23.5s |  |
| 26 | `place_object_test2` | 22 | 23 | 21.4s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 23.4s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 22.1s |  |

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
| 4 | `action_order/action_execution_order_test5` | 47.3% | 26/55 | 55 | 35 |  |
| 5 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 6 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 7 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 8 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 9 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 10 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 11 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 7.6% | 9/118 | 118 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 5.1% | 4/78 | 78 | 62 |  |
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 15 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
