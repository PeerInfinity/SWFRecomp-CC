# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 19:43 UTC

**Git SHA**: `1396f1e10b`

**Run Duration**: 34m 31s

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
| Matching lines | 4277 (82.2%) |
| Mismatched lines | 929 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**70 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 28.4s |  |
| 2 | `BitmapDataDraw` | 56 | 30.9s |  |
| 3 | `DefineEditTextTest` | 153 | 38.0s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 33.8s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 30.1s |  |
| 6 | `DepthLimitsTest` | 20 | 19.8s |  |
| 7 | `PlaceObject2Test` | 9 | 21.8s |  |
| 8 | `ResolveEventsTest` | 15 | 20.9s |  |
| 9 | `RollOverOutTest` | 5 | 20.3s |  |
| 10 | `VarAndCharClashTest` | 13 | 3.1s |  |
| 11 | `Version4Loader` | 11 | 3.0s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 26.2s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 25.4s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 25.6s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 21.3s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 3.5s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 25.7s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 26.3s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.4s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 3.1s |  |
| 21 | `attachExtImported` | 2 | 25.8s |  |
| 22 | `attachImported` | 2 | 3.1s |  |
| 23 | `attachMovieLoopingTest` | 41 | 24.9s |  |
| 24 | `attachMovieTest` | 12 | 25.4s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 19.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 24.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.6s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.0s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.3s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 19.4s |  |
| 35 | `event_handler_scope_test` | 16 | 2.2s |  |
| 36 | `frame_label_test` | 17 | 20.4s |  |
| 37 | `getTimer_test` | 8 | 19.4s |  |
| 38 | `get_frame_number_test` | 31 | 21.3s |  |
| 39 | `gotoFrame2Test` | 9 | 19.4s |  |
| 40 | `goto_frame_test` | 15 | 20.6s |  |
| 41 | `instanceNameTest` | 5 | 2.1s |  |
| 42 | `loading/LoadVarsTest` | 36 | 29.9s |  |
| 43 | `loop/loop_test` | 21 | 19.5s |  |
| 44 | `loop/loop_test2` | 15 | 19.4s |  |
| 45 | `loop/loop_test3` | 16 | 2.0s |  |
| 46 | `loop/loop_test4` | 22 | 17.8s |  |
| 47 | `loop/loop_test5` | 24 | 3.0s |  |
| 48 | `loop/loop_test8` | 38 | 21.6s |  |
| 49 | `loop/loop_test9` | 15 | 19.7s |  |
| 50 | `loop/simple_loop_test` | 0 | 20.8s |  |
| 51 | `masks_test2` | 10 | 20.2s |  |
| 52 | `morph_test1` | 0 | 20.8s |  |
| 53 | `move_object_test` | 11 | 20.1s |  |
| 54 | `multi_doactions_and_goto_frame_test` | 6 | 19.8s |  |
| 55 | `new_child_in_unload_test` | 11 | 19.8s |  |
| 56 | `opcode_guard_test` | 18 | 20.0s |  |
| 57 | `place_and_remove_object_insane_test` | 22 | 19.7s |  |
| 58 | `place_and_remove_object_test` | 13 | 24.9s |  |
| 59 | `register_class/RegisterClassTest3` | 12 | 19.4s |  |
| 60 | `register_class/registerClassTest` | 51 | 21.1s |  |
| 61 | `replace_shapes1test` | 23 | 2.7s |  |
| 62 | `replace_sprites1test` | 21 | 16.5s |  |
| 63 | `reverse_execute_PlaceObject2_test1` | 8 | 16.4s |  |
| 64 | `reverse_execute_PlaceObject2_test2` | 10 | 16.2s |  |
| 65 | `runtime_vm_stack_test` | 9 | 19.5s |  |
| 66 | `shape_test` | 21 | 20.7s |  |
| 67 | `static_vs_dynamic1` | 17 | 19.3s |  |
| 68 | `static_vs_dynamic2` | 18 | 19.8s |  |
| 69 | `timeline_var_test` | 11 | 19.6s |  |
| 70 | `unload_movieclip_test1` | 6 | 19.5s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 31.8s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 3.3s |  |
| 3 | `DefineTextTest` | 4 | 4 | 27.4s |  |
| 4 | `DragDropTest` | 4 | 4 | 3.0s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 5.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 22.2s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.4s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 31.3s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 19.8s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 26.7s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 25.9s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 22.8s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 22.5s |  |
| 14 | `callFunction_test` | 11 | 11 | 32.9s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.4s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 25.0s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.0s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 19.6s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 20.5s |  |
| 20 | `init_action/InitActionTest2` | 24 | 30 | 21.4s |  |
| 21 | `key_event_test` | 5 | 6 | 28.7s |  |
| 22 | `loading/LoadBitmapTest` | 3 | 3 | 27.1s |  |
| 23 | `loading/loadMovieTest` | 9 | 9 | 5.8s |  |
| 24 | `loop/loop_test10` | 23 | 23 | 20.3s |  |
| 25 | `loop/loop_test6` | 11 | 12 | 17.4s |  |
| 26 | `loop/loop_test7` | 1 | 8 | 2.6s |  |
| 27 | `masks_test` | 16 | 16 | 27.8s |  |
| 28 | `matrix_test` | 5 | 9 | 83.0s |  |
| 29 | `path_format_test` | 28 | 28 | 21.2s |  |
| 30 | `place_object_test` | 14 | 14 | 4.3s |  |
| 31 | `place_object_test2` | 22 | 23 | 25.3s |  |
| 32 | `register_class/registerClassTest2` | 8 | 28 | 21.4s |  |
| 33 | `replace_buttons1test` | 3 | 3 | 20.6s |  |

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
