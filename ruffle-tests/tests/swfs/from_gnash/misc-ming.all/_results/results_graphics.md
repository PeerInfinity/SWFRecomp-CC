# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-29 03:41 UTC

**Git SHA**: `02df69d280`

**Run Duration**: 35m 3s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 32 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **101** (91.0%) |
| Failing | 10 |
| Total expected lines | 5248 |
| Matching lines | 4227 (80.5%) |
| Mismatched lines | 1021 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.3s |  |
| 2 | `DefineEditTextTest` | 153 | 25.5s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 22.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 20.4s |  |
| 5 | `DepthLimitsTest` | 20 | 24.6s |  |
| 6 | `PlaceObject2Test` | 9 | 17.6s |  |
| 7 | `ResolveEventsTest` | 15 | 18.7s |  |
| 8 | `RollOverOutTest` | 5 | 18.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.8s |  |
| 10 | `Version4Loader` | 11 | 2.7s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.5s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 19.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 18.8s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 23.1s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.9s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 17.2s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 16.8s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.9s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.2s |  |
| 20 | `attachExtImported` | 2 | 18.6s |  |
| 21 | `attachImported` | 2 | 2.4s |  |
| 22 | `attachMovieLoopingTest` | 41 | 17.9s |  |
| 23 | `attachMovieTest` | 12 | 18.4s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 24.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 24.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 22.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 22.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 3.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 3.0s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 24.4s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 24.2s |  |
| 34 | `event_handler_scope_test` | 16 | 3.3s |  |
| 35 | `frame_label_test` | 17 | 24.5s |  |
| 36 | `getTimer_test` | 8 | 23.1s |  |
| 37 | `get_frame_number_test` | 31 | 25.4s |  |
| 38 | `gotoFrame2Test` | 9 | 22.9s |  |
| 39 | `goto_frame_test` | 15 | 23.6s |  |
| 40 | `instanceNameTest` | 5 | 2.8s |  |
| 41 | `loading/LoadVarsTest` | 36 | 26.1s |  |
| 42 | `loop/loop_test` | 21 | 24.9s |  |
| 43 | `loop/loop_test2` | 15 | 24.6s |  |
| 44 | `loop/loop_test3` | 16 | 3.1s |  |
| 45 | `loop/loop_test4` | 22 | 24.0s |  |
| 46 | `loop/loop_test5` | 24 | 4.2s |  |
| 47 | `loop/loop_test8` | 38 | 21.1s |  |
| 48 | `loop/loop_test9` | 15 | 18.6s |  |
| 49 | `loop/simple_loop_test` | 0 | 20.5s |  |
| 50 | `masks_test2` | 10 | 22.4s |  |
| 51 | `morph_test1` | 0 | 25.2s |  |
| 52 | `move_object_test` | 11 | 24.4s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 24.9s |  |
| 54 | `new_child_in_unload_test` | 11 | 24.1s |  |
| 55 | `opcode_guard_test` | 18 | 24.2s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 24.7s |  |
| 57 | `place_and_remove_object_test` | 13 | 23.4s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 24.8s |  |
| 59 | `register_class/registerClassTest` | 51 | 27.2s |  |
| 60 | `replace_shapes1test` | 23 | 2.1s |  |
| 61 | `replace_sprites1test` | 21 | 22.8s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 22.2s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 22.5s |  |
| 64 | `runtime_vm_stack_test` | 9 | 19.8s |  |
| 65 | `shape_test` | 21 | 21.2s |  |
| 66 | `static_vs_dynamic1` | 17 | 19.5s |  |
| 67 | `static_vs_dynamic2` | 18 | 23.2s |  |
| 68 | `timeline_var_test` | 11 | 22.9s |  |
| 69 | `unload_movieclip_test1` | 6 | 22.7s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 23.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 23.7s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.6s |  |
| 4 | `DefineTextTest` | 4 | 4 | 18.8s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.2s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.9s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 17.1s |  |
| 8 | `NetStream-SquareTest` | 95 | 108 | 25.0s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 17.8s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.5s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 19.2s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 24.3s |  |
| 13 | `callFunction_test` | 6 | 11 | 25.4s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 33.1s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 22.6s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.1s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 24.5s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 22.9s |  |
| 19 | `init_action/InitActionTest2` | 24 | 30 | 24.7s |  |
| 20 | `key_event_test` | 5 | 6 | 24.9s |  |
| 21 | `loading/LoadBitmapTest` | 3 | 3 | 23.6s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 5.0s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 26.1s |  |
| 24 | `loop/loop_test6` | 1 | 12 | 23.8s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 3.5s |  |
| 26 | `masks_test` | 16 | 16 | 28.5s |  |
| 27 | `matrix_test` | 5 | 9 | 110.5s |  |
| 28 | `path_format_test` | 28 | 28 | 27.3s |  |
| 29 | `place_object_test` | 14 | 14 | 4.0s |  |
| 30 | `place_object_test2` | 22 | 23 | 23.4s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 14.8s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 14.1s |  |

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

**10 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 5 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 6 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 7 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 8 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 9 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
| 10 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
