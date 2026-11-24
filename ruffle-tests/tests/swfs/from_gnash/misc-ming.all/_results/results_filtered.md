# Ruffle Test Results (Filtered)

**Date**: 2026-11-24 07:00 UTC

**Git SHA**: `cceb5133a1`

**Run Duration**: 31m 39s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **71** (64.5%) |
| Ruffle-matched | 32 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **103** (93.6%) |
| Failing | 7 |
| Total expected lines | 5206 |
| Matching lines | 4306 (82.7%) |
| Mismatched lines | 900 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**71 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 24.7s |  |
| 2 | `BitmapDataDraw` | 56 | 28.2s |  |
| 3 | `DefineEditTextTest` | 153 | 21.1s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 18.5s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 16.8s |  |
| 6 | `DepthLimitsTest` | 20 | 20.3s |  |
| 7 | `PlaceObject2Test` | 9 | 19.5s |  |
| 8 | `ResolveEventsTest` | 15 | 19.6s |  |
| 9 | `RollOverOutTest` | 5 | 19.1s |  |
| 10 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 11 | `Version4Loader` | 11 | 1.4s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 15.7s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 24.8s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 24.3s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 19.0s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 2.1s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 18.4s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 18.7s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 1.4s |  |
| 21 | `attachExtImported` | 2 | 18.9s |  |
| 22 | `attachImported` | 2 | 1.4s |  |
| 23 | `attachMovieLoopingTest` | 41 | 18.4s |  |
| 24 | `attachMovieTest` | 12 | 18.8s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 24.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 24.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 26.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.3s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.9s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 20.1s |  |
| 35 | `event_handler_scope_test` | 16 | 2.1s |  |
| 36 | `frame_label_test` | 17 | 17.5s |  |
| 37 | `getTimer_test` | 8 | 16.7s |  |
| 38 | `get_frame_number_test` | 31 | 18.9s |  |
| 39 | `gotoFrame2Test` | 9 | 16.4s |  |
| 40 | `goto_frame_test` | 15 | 24.7s |  |
| 41 | `init_action/InitActionTest2` | 29 | 25.6s |  |
| 42 | `instanceNameTest` | 5 | 2.1s |  |
| 43 | `loading/LoadVarsTest` | 36 | 29.0s |  |
| 44 | `loop/loop_test` | 21 | 18.5s |  |
| 45 | `loop/loop_test2` | 15 | 18.2s |  |
| 46 | `loop/loop_test3` | 16 | 1.4s |  |
| 47 | `loop/loop_test4` | 22 | 25.0s |  |
| 48 | `loop/loop_test5` | 24 | 3.0s |  |
| 49 | `loop/loop_test8` | 38 | 19.7s |  |
| 50 | `loop/loop_test9` | 15 | 18.4s |  |
| 51 | `loop/simple_loop_test` | 0 | 18.2s |  |
| 52 | `masks_test2` | 10 | 18.4s |  |
| 53 | `morph_test1` | 0 | 18.1s |  |
| 54 | `move_object_test` | 11 | 18.5s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 18.5s |  |
| 56 | `new_child_in_unload_test` | 11 | 18.7s |  |
| 57 | `opcode_guard_test` | 18 | 18.5s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 18.8s |  |
| 59 | `place_and_remove_object_test` | 13 | 18.2s |  |
| 60 | `register_class/RegisterClassTest3` | 12 | 18.9s |  |
| 61 | `register_class/registerClassTest` | 51 | 20.6s |  |
| 62 | `replace_shapes1test` | 23 | 1.9s |  |
| 63 | `replace_sprites1test` | 21 | 18.8s |  |
| 64 | `reverse_execute_PlaceObject2_test1` | 8 | 18.4s |  |
| 65 | `reverse_execute_PlaceObject2_test2` | 10 | 18.6s |  |
| 66 | `runtime_vm_stack_test` | 9 | 18.4s |  |
| 67 | `shape_test` | 21 | 19.2s |  |
| 68 | `static_vs_dynamic1` | 17 | 18.3s |  |
| 69 | `static_vs_dynamic2` | 18 | 18.2s |  |
| 70 | `timeline_var_test` | 11 | 18.0s |  |
| 71 | `unload_movieclip_test1` | 6 | 18.0s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 29.4s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.3s |  |
| 3 | `DefineTextTest` | 4 | 4 | 14.9s |  |
| 4 | `DragDropTest` | 4 | 4 | 2.5s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 5.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 22.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 19.7s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 27.2s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 19.1s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 24.9s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 25.1s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 19.6s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 19.4s |  |
| 14 | `callFunction_test` | 6 | 11 | 25.3s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 32.8s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 26.5s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.6s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 20.4s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 24.5s |  |
| 20 | `key_event_test` | 5 | 6 | 26.8s |  |
| 21 | `loading/LoadBitmapTest` | 3 | 3 | 26.5s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 4.6s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 19.0s |  |
| 24 | `loop/loop_test6` | 11 | 12 | 24.9s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 2.4s |  |
| 26 | `masks_test` | 16 | 16 | 25.5s |  |
| 27 | `matrix_test` | 5 | 9 | 75.5s |  |
| 28 | `path_format_test` | 28 | 28 | 20.2s |  |
| 29 | `place_object_test` | 14 | 14 | 1.7s |  |
| 30 | `place_object_test2` | 22 | 23 | 18.5s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 19.4s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 18.9s |  |

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
