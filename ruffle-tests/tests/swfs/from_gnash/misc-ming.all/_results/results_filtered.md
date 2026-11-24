# Ruffle Test Results (Filtered)

**Date**: 2026-11-24 00:12 UTC

**Git SHA**: `005bea42a2`

**Run Duration**: 29m 15s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **70** (63.6%) |
| Ruffle-matched | 33 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **103** (93.6%) |
| Failing | 7 |
| Total expected lines | 5206 |
| Matching lines | 4282 (82.3%) |
| Mismatched lines | 924 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**70 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.8s |  |
| 2 | `BitmapDataDraw` | 56 | 20.9s |  |
| 3 | `DefineEditTextTest` | 153 | 37.0s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 32.0s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 28.0s |  |
| 6 | `DepthLimitsTest` | 20 | 19.8s |  |
| 7 | `PlaceObject2Test` | 9 | 18.8s |  |
| 8 | `ResolveEventsTest` | 15 | 19.6s |  |
| 9 | `RollOverOutTest` | 5 | 19.5s |  |
| 10 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 11 | `Version4Loader` | 11 | 1.4s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 18.7s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.1s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 18.1s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 17.9s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 1.9s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 14.5s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 14.6s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 1.3s |  |
| 21 | `attachExtImported` | 2 | 19.4s |  |
| 22 | `attachImported` | 2 | 1.5s |  |
| 23 | `attachMovieLoopingTest` | 41 | 18.9s |  |
| 24 | `attachMovieTest` | 12 | 19.2s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 18.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.6s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.4s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.6s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.5s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.4s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 18.6s |  |
| 35 | `event_handler_scope_test` | 16 | 1.6s |  |
| 36 | `frame_label_test` | 17 | 19.4s |  |
| 37 | `getTimer_test` | 8 | 18.3s |  |
| 38 | `get_frame_number_test` | 31 | 20.1s |  |
| 39 | `gotoFrame2Test` | 9 | 18.5s |  |
| 40 | `goto_frame_test` | 15 | 19.0s |  |
| 41 | `instanceNameTest` | 5 | 1.4s |  |
| 42 | `loading/LoadVarsTest` | 36 | 27.7s |  |
| 43 | `loop/loop_test` | 21 | 18.6s |  |
| 44 | `loop/loop_test2` | 15 | 18.6s |  |
| 45 | `loop/loop_test3` | 16 | 1.4s |  |
| 46 | `loop/loop_test4` | 22 | 16.4s |  |
| 47 | `loop/loop_test5` | 24 | 2.3s |  |
| 48 | `loop/loop_test8` | 38 | 27.8s |  |
| 49 | `loop/loop_test9` | 15 | 25.1s |  |
| 50 | `loop/simple_loop_test` | 0 | 24.6s |  |
| 51 | `masks_test2` | 10 | 1.6s |  |
| 52 | `morph_test1` | 0 | 18.8s |  |
| 53 | `move_object_test` | 11 | 16.9s |  |
| 54 | `multi_doactions_and_goto_frame_test` | 6 | 17.2s |  |
| 55 | `new_child_in_unload_test` | 11 | 17.9s |  |
| 56 | `opcode_guard_test` | 18 | 23.5s |  |
| 57 | `place_and_remove_object_insane_test` | 22 | 23.3s |  |
| 58 | `place_and_remove_object_test` | 13 | 1.4s |  |
| 59 | `register_class/RegisterClassTest3` | 12 | 18.6s |  |
| 60 | `register_class/registerClassTest` | 51 | 20.2s |  |
| 61 | `replace_shapes1test` | 23 | 2.3s |  |
| 62 | `replace_sprites1test` | 21 | 18.4s |  |
| 63 | `reverse_execute_PlaceObject2_test1` | 8 | 18.3s |  |
| 64 | `reverse_execute_PlaceObject2_test2` | 10 | 18.5s |  |
| 65 | `runtime_vm_stack_test` | 9 | 19.5s |  |
| 66 | `shape_test` | 21 | 3.0s |  |
| 67 | `static_vs_dynamic1` | 17 | 18.9s |  |
| 68 | `static_vs_dynamic2` | 18 | 19.2s |  |
| 69 | `timeline_var_test` | 11 | 19.0s |  |
| 70 | `unload_movieclip_test1` | 6 | 18.6s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 21.6s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 1.5s |  |
| 3 | `DefineTextTest` | 4 | 4 | 26.1s |  |
| 4 | `DragDropTest` | 4 | 4 | 2.4s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 4.7s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 22.4s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 19.0s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 26.2s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 18.9s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.1s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 18.4s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 18.8s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 18.9s |  |
| 14 | `callFunction_test` | 6 | 11 | 19.3s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.7s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.9s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.5s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 19.1s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 1.8s |  |
| 20 | `init_action/InitActionTest2` | 24 | 30 | 2.5s |  |
| 21 | `key_event_test` | 5 | 6 | 25.6s |  |
| 22 | `loading/LoadBitmapTest` | 3 | 3 | 25.2s |  |
| 23 | `loading/loadMovieTest` | 9 | 9 | 4.4s |  |
| 24 | `loop/loop_test10` | 23 | 23 | 19.0s |  |
| 25 | `loop/loop_test6` | 11 | 12 | 16.3s |  |
| 26 | `loop/loop_test7` | 1 | 8 | 1.7s |  |
| 27 | `masks_test` | 16 | 16 | 36.5s |  |
| 28 | `matrix_test` | 5 | 9 | 80.2s |  |
| 29 | `path_format_test` | 28 | 28 | 25.1s |  |
| 30 | `place_object_test` | 14 | 14 | 1.6s |  |
| 31 | `place_object_test2` | 22 | 23 | 1.7s |  |
| 32 | `register_class/registerClassTest2` | 8 | 28 | 20.5s |  |
| 33 | `replace_buttons1test` | 3 | 3 | 19.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 3 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 4 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 5 | `action_order/ActionOrderTest4` | 11.7% | 11/94 | 94 | 64 |  |
| 6 | `action_order/ActionOrderTest5` | 8.6% | 5/58 | 58 | 51 |  |
| 7 | `action_order/ActionOrderTest3` | 6.0% | 5/83 | 83 | 62 |  |
