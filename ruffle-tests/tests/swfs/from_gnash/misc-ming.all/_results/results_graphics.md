# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-12 23:31 UTC

**Git SHA**: `6dae4def39`

**Run Duration**: 30m 6s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **66** (60.0%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **94** (85.5%) |
| Failing | 16 |
| Total expected lines | 5239 |
| Matching lines | 4028 (76.9%) |
| Mismatched lines | 1211 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 16 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 23.2s |  |
| 2 | `DefineEditTextTest` | 153 | 20.8s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 20.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 20.1s |  |
| 5 | `DepthLimitsTest` | 20 | 19.0s |  |
| 6 | `PlaceObject2Test` | 9 | 19.9s |  |
| 7 | `ResolveEventsTest` | 15 | 20.4s |  |
| 8 | `RollOverOutTest` | 5 | 19.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.1s |  |
| 10 | `Version4Loader` | 11 | 1.0s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.0s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.4s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.9s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 20.0s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 19.9s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.0s |  |
| 19 | `attachExtImported` | 2 | 19.8s |  |
| 20 | `attachImported` | 2 | 1.1s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.6s |  |
| 22 | `attachMovieTest` | 12 | 19.8s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 19.3s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.5s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.2s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.5s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 20.5s |  |
| 33 | `event_handler_scope_test` | 16 | 1.1s |  |
| 34 | `frame_label_test` | 17 | 19.9s |  |
| 35 | `getTimer_test` | 8 | 19.7s |  |
| 36 | `get_frame_number_test` | 31 | 20.3s |  |
| 37 | `goto_frame_test` | 15 | 19.7s |  |
| 38 | `instanceNameTest` | 5 | 1.0s |  |
| 39 | `loading/LoadVarsTest` | 36 | 20.1s |  |
| 40 | `loop/loop_test` | 21 | 19.8s |  |
| 41 | `loop/loop_test2` | 15 | 19.0s |  |
| 42 | `loop/loop_test3` | 16 | 1.0s |  |
| 43 | `loop/loop_test4` | 22 | 19.1s |  |
| 44 | `loop/loop_test5` | 24 | 21.7s |  |
| 45 | `loop/loop_test8` | 38 | 1.4s |  |
| 46 | `loop/loop_test9` | 15 | 19.6s |  |
| 47 | `loop/simple_loop_test` | 0 | 24.3s |  |
| 48 | `masks_test2` | 10 | 19.9s |  |
| 49 | `morph_test1` | 0 | 24.0s |  |
| 50 | `move_object_test` | 11 | 19.4s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 19.5s |  |
| 52 | `new_child_in_unload_test` | 11 | 19.3s |  |
| 53 | `opcode_guard_test` | 18 | 19.2s |  |
| 54 | `place_and_remove_object_test` | 13 | 15.5s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 19.8s |  |
| 56 | `register_class/registerClassTest` | 51 | 19.9s |  |
| 57 | `replace_shapes1test` | 23 | 1.0s |  |
| 58 | `replace_sprites1test` | 21 | 20.0s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 19.8s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 20.3s |  |
| 61 | `runtime_vm_stack_test` | 9 | 20.1s |  |
| 62 | `shape_test` | 21 | 22.1s |  |
| 63 | `static_vs_dynamic1` | 17 | 20.0s |  |
| 64 | `static_vs_dynamic2` | 18 | 19.6s |  |
| 65 | `timeline_var_test` | 11 | 19.7s |  |
| 66 | `unload_movieclip_test1` | 6 | 19.6s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 21.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 21.4s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.3s |  |
| 4 | `DefineTextTest` | 4 | 4 | 19.7s |  |
| 5 | `DragDropTest` | 4 | 4 | 1.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 19.3s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.2s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 20.6s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 19.8s |  |
| 10 | `callFunction_test` | 6 | 11 | 20.1s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 20.0s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.4s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.2s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 20.5s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 20.0s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 20.4s |  |
| 17 | `key_event_test` | 5 | 6 | 21.0s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 20.4s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 1.4s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 19.4s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 20.9s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 1.2s |  |
| 23 | `matrix_test` | 5 | 9 | 24.8s |  |
| 24 | `path_format_test` | 28 | 28 | 19.2s |  |
| 25 | `place_object_test` | 14 | 14 | 17.2s |  |
| 26 | `place_object_test2` | 22 | 23 | 15.4s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 19.0s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 18.9s |  |

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

**16 tests** with output mismatch, sorted by match rate (best first)

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
| 14 | `register_class/RegisterClassTest4` | 4.7% | 3/64 | 64 | 42 |  |
| 15 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 16 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
