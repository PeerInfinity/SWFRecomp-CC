# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-17 02:06 UTC

**Git SHA**: `9396522982`

**Run Duration**: 25m 3s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 33 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (91.9%) |
| Failing | 9 |
| Total expected lines | 5248 |
| Matching lines | 4236 (80.7%) |
| Mismatched lines | 1012 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 19.1s |  |
| 2 | `DefineEditTextTest` | 153 | 25.2s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 22.6s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.4s |  |
| 5 | `DepthLimitsTest` | 20 | 24.0s |  |
| 6 | `PlaceObject2Test` | 9 | 22.2s |  |
| 7 | `ResolveEventsTest` | 15 | 20.9s |  |
| 8 | `RollOverOutTest` | 5 | 20.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.9s |  |
| 10 | `Version4Loader` | 11 | 1.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.5s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 2.2s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.0s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 22.8s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 2.6s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.5s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 20 | `attachExtImported` | 2 | 24.6s |  |
| 21 | `attachImported` | 2 | 2.1s |  |
| 22 | `attachMovieLoopingTest` | 41 | 23.1s |  |
| 23 | `attachMovieTest` | 12 | 23.8s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 25.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 1.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 1.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.7s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.7s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.0s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 3.2s |  |
| 34 | `event_handler_scope_test` | 16 | 2.4s |  |
| 35 | `frame_label_test` | 17 | 3.6s |  |
| 36 | `getTimer_test` | 8 | 21.7s |  |
| 37 | `get_frame_number_test` | 31 | 4.5s |  |
| 38 | `gotoFrame2Test` | 9 | 21.5s |  |
| 39 | `goto_frame_test` | 15 | 16.4s |  |
| 40 | `instanceNameTest` | 5 | 1.2s |  |
| 41 | `loading/LoadVarsTest` | 36 | 15.8s |  |
| 42 | `loop/loop_test` | 21 | 14.7s |  |
| 43 | `loop/loop_test2` | 15 | 1.4s |  |
| 44 | `loop/loop_test3` | 16 | 1.5s |  |
| 45 | `loop/loop_test4` | 22 | 3.2s |  |
| 46 | `loop/loop_test5` | 24 | 3.3s |  |
| 47 | `loop/loop_test8` | 38 | 25.1s |  |
| 48 | `loop/loop_test9` | 15 | 22.9s |  |
| 49 | `loop/simple_loop_test` | 0 | 22.1s |  |
| 50 | `masks_test2` | 10 | 15.4s |  |
| 51 | `morph_test1` | 0 | 14.0s |  |
| 52 | `move_object_test` | 11 | 18.3s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 18.2s |  |
| 54 | `new_child_in_unload_test` | 11 | 18.2s |  |
| 55 | `opcode_guard_test` | 18 | 14.1s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 14.6s |  |
| 57 | `place_and_remove_object_test` | 13 | 22.3s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 15.0s |  |
| 59 | `register_class/registerClassTest` | 51 | 16.4s |  |
| 60 | `replace_shapes1test` | 23 | 2.2s |  |
| 61 | `replace_sprites1test` | 21 | 15.8s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 15.2s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 15.9s |  |
| 64 | `runtime_vm_stack_test` | 9 | 23.6s |  |
| 65 | `shape_test` | 21 | 23.7s |  |
| 66 | `static_vs_dynamic1` | 17 | 2.0s |  |
| 67 | `static_vs_dynamic2` | 18 | 14.3s |  |
| 68 | `timeline_var_test` | 11 | 1.6s |  |
| 69 | `unload_movieclip_test1` | 6 | 1.3s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 21.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 5.4s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 1.6s |  |
| 4 | `DefineTextTest` | 4 | 4 | 1.9s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.3s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 22.5s |  |
| 8 | `NetStream-SquareTest` | 95 | 108 | 32.6s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 18.9s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 27.1s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 22.6s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 23.8s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 23.8s |  |
| 14 | `callFunction_test` | 6 | 11 | 3.0s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 34.1s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 1.5s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.4s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 3.5s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 15.9s |  |
| 20 | `init_action/InitActionTest2` | 24 | 30 | 16.6s |  |
| 21 | `key_event_test` | 5 | 6 | 14.5s |  |
| 22 | `loading/LoadBitmapTest` | 3 | 3 | 14.0s |  |
| 23 | `loading/loadMovieTest` | 9 | 9 | 2.6s |  |
| 24 | `loop/loop_test10` | 23 | 23 | 15.8s |  |
| 25 | `loop/loop_test6` | 11 | 12 | 24.0s |  |
| 26 | `loop/loop_test7` | 1 | 8 | 2.6s |  |
| 27 | `masks_test` | 16 | 16 | 33.5s |  |
| 28 | `matrix_test` | 5 | 9 | 75.5s |  |
| 29 | `path_format_test` | 28 | 28 | 15.9s |  |
| 30 | `place_object_test` | 14 | 14 | 2.5s |  |
| 31 | `place_object_test2` | 22 | 23 | 2.5s |  |
| 32 | `register_class/registerClassTest2` | 8 | 28 | 20.1s |  |
| 33 | `replace_buttons1test` | 3 | 3 | 18.6s |  |

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

**9 tests** with output mismatch, sorted by match rate (best first)

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
