# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-31 02:39 UTC

**Git SHA**: `5d27de9a7d`

**Run Duration**: 36m 3s

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
| 1 | `BeginBitmapFill` | 1 | 24.2s |  |
| 2 | `DefineEditTextTest` | 153 | 28.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.3s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.7s |  |
| 5 | `DepthLimitsTest` | 20 | 22.8s |  |
| 6 | `PlaceObject2Test` | 9 | 17.1s |  |
| 7 | `ResolveEventsTest` | 15 | 24.9s |  |
| 8 | `RollOverOutTest` | 5 | 25.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.4s |  |
| 10 | `Version4Loader` | 11 | 2.2s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.6s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.3s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 21.9s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 20.8s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 21.1s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 2.2s |  |
| 19 | `attachExtImported` | 2 | 22.8s |  |
| 20 | `attachImported` | 2 | 2.4s |  |
| 21 | `attachMovieLoopingTest` | 41 | 21.5s |  |
| 22 | `attachMovieTest` | 12 | 22.5s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 22.0s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 22.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.1s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 21.6s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.8s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.4s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 23.2s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 23.0s |  |
| 33 | `event_handler_scope_test` | 16 | 3.0s |  |
| 34 | `frame_label_test` | 17 | 24.8s |  |
| 35 | `getTimer_test` | 8 | 23.7s |  |
| 36 | `get_frame_number_test` | 31 | 26.9s |  |
| 37 | `goto_frame_test` | 15 | 24.7s |  |
| 38 | `instanceNameTest` | 5 | 2.2s |  |
| 39 | `loading/LoadVarsTest` | 36 | 24.2s |  |
| 40 | `loop/loop_test` | 21 | 20.5s |  |
| 41 | `loop/loop_test2` | 15 | 21.7s |  |
| 42 | `loop/loop_test3` | 16 | 2.5s |  |
| 43 | `loop/loop_test4` | 22 | 23.6s |  |
| 44 | `loop/loop_test5` | 24 | 22.7s |  |
| 45 | `loop/loop_test8` | 38 | 4.9s |  |
| 46 | `loop/loop_test9` | 15 | 20.6s |  |
| 47 | `loop/simple_loop_test` | 0 | 24.9s |  |
| 48 | `masks_test2` | 10 | 20.3s |  |
| 49 | `morph_test1` | 0 | 23.6s |  |
| 50 | `move_object_test` | 11 | 21.3s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 21.2s |  |
| 52 | `new_child_in_unload_test` | 11 | 21.2s |  |
| 53 | `place_and_remove_object_test` | 13 | 21.3s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 21.5s |  |
| 55 | `register_class/registerClassTest` | 51 | 23.9s |  |
| 56 | `replace_shapes1test` | 23 | 2.6s |  |
| 57 | `replace_sprites1test` | 21 | 23.3s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 22.2s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 22.7s |  |
| 60 | `runtime_vm_stack_test` | 9 | 21.0s |  |
| 61 | `shape_test` | 21 | 24.0s |  |
| 62 | `static_vs_dynamic1` | 17 | 20.4s |  |
| 63 | `static_vs_dynamic2` | 18 | 20.9s |  |
| 64 | `timeline_var_test` | 11 | 20.4s |  |
| 65 | `unload_movieclip_test1` | 6 | 20.4s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 25.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 26.3s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.0s |  |
| 4 | `DefineTextTest` | 4 | 4 | 20.5s |  |
| 5 | `DragDropTest` | 12 | 12 | 3.5s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 17.3s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 34.4s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 23.0s |  |
| 10 | `callFunction_test` | 6 | 11 | 22.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 30.1s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 17.4s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.1s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 24.2s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 22.3s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 22.7s |  |
| 17 | `key_event_test` | 5 | 6 | 23.1s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 22.0s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 4.8s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 22.8s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 23.2s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.0s |  |
| 23 | `matrix_test` | 5 | 9 | 101.5s |  |
| 24 | `path_format_test` | 28 | 28 | 22.4s |  |
| 25 | `place_object_test` | 14 | 14 | 23.6s |  |
| 26 | `place_object_test2` | 22 | 23 | 21.6s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 22.9s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 21.9s |  |

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
