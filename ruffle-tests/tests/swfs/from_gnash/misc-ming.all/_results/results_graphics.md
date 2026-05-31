# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-31 01:43 UTC

**Git SHA**: `17256ff005`

**Run Duration**: 29m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **65** (59.1%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **93** (84.5%) |
| Failing | 17 |
| Total expected lines | 5239 |
| Matching lines | 4014 (76.6%) |
| Mismatched lines | 1225 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 17 | 100.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.7s |  |
| 2 | `DefineEditTextTest` | 153 | 20.0s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 19.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.5s |  |
| 5 | `DepthLimitsTest` | 20 | 15.4s |  |
| 6 | `PlaceObject2Test` | 9 | 20.0s |  |
| 7 | `ResolveEventsTest` | 15 | 19.6s |  |
| 8 | `RollOverOutTest` | 5 | 19.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.2s |  |
| 10 | `Version4Loader` | 11 | 1.1s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.0s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 18.5s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 19.7s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 19.6s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.1s |  |
| 19 | `attachExtImported` | 2 | 19.7s |  |
| 20 | `attachImported` | 2 | 1.0s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.4s |  |
| 22 | `attachMovieTest` | 12 | 19.4s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 20.0s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.1s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.8s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 19.5s |  |
| 33 | `event_handler_scope_test` | 16 | 1.1s |  |
| 34 | `frame_label_test` | 17 | 19.5s |  |
| 35 | `getTimer_test` | 8 | 19.2s |  |
| 36 | `get_frame_number_test` | 31 | 19.7s |  |
| 37 | `goto_frame_test` | 15 | 19.1s |  |
| 38 | `instanceNameTest` | 5 | 1.0s |  |
| 39 | `loading/LoadVarsTest` | 36 | 19.9s |  |
| 40 | `loop/loop_test` | 21 | 19.6s |  |
| 41 | `loop/loop_test2` | 15 | 18.9s |  |
| 42 | `loop/loop_test3` | 16 | 1.0s |  |
| 43 | `loop/loop_test4` | 22 | 19.0s |  |
| 44 | `loop/loop_test5` | 24 | 20.0s |  |
| 45 | `loop/loop_test8` | 38 | 1.2s |  |
| 46 | `loop/loop_test9` | 15 | 19.6s |  |
| 47 | `loop/simple_loop_test` | 0 | 25.0s |  |
| 48 | `masks_test2` | 10 | 16.2s |  |
| 49 | `morph_test1` | 0 | 20.3s |  |
| 50 | `move_object_test` | 11 | 20.9s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 21.0s |  |
| 52 | `new_child_in_unload_test` | 11 | 21.0s |  |
| 53 | `place_and_remove_object_test` | 13 | 20.7s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 19.4s |  |
| 55 | `register_class/registerClassTest` | 51 | 19.4s |  |
| 56 | `replace_shapes1test` | 23 | 0.9s |  |
| 57 | `replace_sprites1test` | 21 | 15.7s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 15.6s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 15.7s |  |
| 60 | `runtime_vm_stack_test` | 9 | 19.1s |  |
| 61 | `shape_test` | 21 | 21.6s |  |
| 62 | `static_vs_dynamic1` | 17 | 19.1s |  |
| 63 | `static_vs_dynamic2` | 18 | 20.6s |  |
| 64 | `timeline_var_test` | 11 | 20.5s |  |
| 65 | `unload_movieclip_test1` | 6 | 20.4s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.7s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 19.6s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 19.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 19.4s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.8s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 15.7s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.9s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 20.3s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 18.6s |  |
| 10 | `callFunction_test` | 6 | 11 | 19.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 21.4s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.3s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.1s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 19.6s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 19.6s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 20.1s |  |
| 17 | `key_event_test` | 5 | 6 | 20.7s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 19.9s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 1.5s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 19.1s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 20.1s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 1.1s |  |
| 23 | `matrix_test` | 5 | 9 | 20.4s |  |
| 24 | `path_format_test` | 28 | 28 | 21.2s |  |
| 25 | `place_object_test` | 14 | 14 | 23.0s |  |
| 26 | `place_object_test2` | 22 | 23 | 21.3s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 19.4s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 19.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17 | 22 | 5 |  |
| 4 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**17 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
| 4 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 5 | `action_order/action_execution_order_test5` | 47.3% | 26/55 | 55 | 35 |  |
| 6 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 7 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 8 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 9 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 10 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 11 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 12 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 13 | `action_order/ActionOrderTest4` | 7.6% | 9/118 | 118 | 64 |  |
| 14 | `action_order/ActionOrderTest3` | 5.1% | 4/78 | 78 | 62 |  |
| 15 | `register_class/RegisterClassTest4` | 4.7% | 3/64 | 64 | 42 |  |
| 16 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 17 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
