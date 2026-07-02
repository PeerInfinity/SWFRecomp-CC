# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-02 21:58 UTC

**Git SHA**: `98fb875b6b`

**Run Duration**: 33m 38s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **66** (59.5%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **93** (83.8%) |
| Failing | 18 |
| Total expected lines | 5248 |
| Matching lines | 4023 (76.7%) |
| Mismatched lines | 1225 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 18 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 25.8s |  |
| 2 | `DefineEditTextTest` | 153 | 12.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.7s |  |
| 5 | `DepthLimitsTest` | 20 | 24.6s |  |
| 6 | `PlaceObject2Test` | 9 | 21.5s |  |
| 7 | `ResolveEventsTest` | 15 | 22.4s |  |
| 8 | `RollOverOutTest` | 5 | 22.2s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.3s |  |
| 10 | `Version4Loader` | 11 | 2.2s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.3s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.8s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 3.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 23.1s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 21.1s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 20.4s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.0s |  |
| 19 | `attachExtImported` | 2 | 23.4s |  |
| 20 | `attachImported` | 2 | 2.7s |  |
| 21 | `attachMovieLoopingTest` | 41 | 22.4s |  |
| 22 | `attachMovieTest` | 12 | 22.9s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 2.9s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 22.5s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 22.0s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 22.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.7s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 22.7s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 22.6s |  |
| 33 | `event_handler_scope_test` | 16 | 3.1s |  |
| 34 | `frame_label_test` | 17 | 23.7s |  |
| 35 | `getTimer_test` | 8 | 22.2s |  |
| 36 | `get_frame_number_test` | 31 | 24.6s |  |
| 37 | `gotoFrame2Test` | 9 | 22.0s |  |
| 38 | `goto_frame_test` | 15 | 22.0s |  |
| 39 | `instanceNameTest` | 5 | 2.6s |  |
| 40 | `loading/LoadVarsTest` | 36 | 26.4s |  |
| 41 | `loop/loop_test` | 21 | 21.8s |  |
| 42 | `loop/loop_test2` | 15 | 21.3s |  |
| 43 | `loop/loop_test3` | 16 | 2.6s |  |
| 44 | `loop/loop_test4` | 22 | 22.4s |  |
| 45 | `loop/loop_test5` | 24 | 3.8s |  |
| 46 | `loop/loop_test8` | 38 | 5.2s |  |
| 47 | `loop/loop_test9` | 15 | 21.9s |  |
| 48 | `loop/simple_loop_test` | 0 | 27.0s |  |
| 49 | `masks_test2` | 10 | 21.2s |  |
| 50 | `morph_test1` | 0 | 25.1s |  |
| 51 | `move_object_test` | 11 | 21.8s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 21.5s |  |
| 53 | `new_child_in_unload_test` | 11 | 2.8s |  |
| 54 | `opcode_guard_test` | 18 | 22.1s |  |
| 55 | `place_and_remove_object_test` | 13 | 19.5s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 3.5s |  |
| 57 | `register_class/registerClassTest` | 51 | 24.6s |  |
| 58 | `replace_shapes1test` | 23 | 3.2s |  |
| 59 | `replace_sprites1test` | 21 | 22.5s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 2.8s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 22.1s |  |
| 62 | `runtime_vm_stack_test` | 9 | 2.8s |  |
| 63 | `shape_test` | 21 | 24.4s |  |
| 64 | `static_vs_dynamic1` | 17 | 20.6s |  |
| 65 | `timeline_var_test` | 11 | 2.2s |  |
| 66 | `unload_movieclip_test1` | 6 | 16.8s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 27.5s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 28.4s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 22.8s |  |
| 4 | `DefineTextTest` | 4 | 4 | 22.6s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 3.1s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 30.3s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 4.1s |  |
| 10 | `callFunction_test` | 6 | 11 | 22.8s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 30.2s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 22.1s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.0s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 4.2s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.6s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 23.2s |  |
| 17 | `key_event_test` | 5 | 6 | 24.9s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 24.1s |  |
| 19 | `loop/loop_test10` | 23 | 23 | 22.6s |  |
| 20 | `loop/loop_test6` | 1 | 12 | 22.1s |  |
| 21 | `loop/loop_test7` | 1 | 8 | 3.1s |  |
| 22 | `matrix_test` | 5 | 9 | 102.1s |  |
| 23 | `path_format_test` | 28 | 28 | 24.6s |  |
| 24 | `place_object_test` | 14 | 14 | 20.9s |  |
| 25 | `place_object_test2` | 22 | 23 | 18.9s |  |
| 26 | `register_class/registerClassTest2` | 8 | 28 | 22.9s |  |
| 27 | `replace_buttons1test` | 3 | 3 | 21.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15 | 18 | 3 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 4 | `place_and_remove_object_insane_test` | 77.3% | 17 | 22 | 5 |  |
| 5 | `loading/loadMovieTest` | 75.0% | 60 | 80 | 20 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**18 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15/18 | 18 | 18 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 4 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
| 5 | `loading/loadMovieTest` | 75.0% | 60/80 | 80 | 80 |  |
| 6 | `action_order/action_execution_order_test5` | 47.3% | 26/55 | 55 | 35 |  |
| 7 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 8 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 9 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 10 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 11 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 12 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 13 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 14 | `action_order/ActionOrderTest4` | 7.6% | 9/118 | 118 | 64 |  |
| 15 | `action_order/ActionOrderTest3` | 5.1% | 4/78 | 78 | 62 |  |
| 16 | `register_class/RegisterClassTest4` | 4.7% | 3/64 | 64 | 42 |  |
| 17 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 18 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
