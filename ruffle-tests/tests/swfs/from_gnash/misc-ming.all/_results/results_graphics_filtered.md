# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 03:46 UTC

**Git SHA**: `8f4f6e3953`

**Run Duration**: 33m 32s

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
| Matching lines | 4311 (82.8%) |
| Mismatched lines | 895 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**71 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.1s |  |
| 2 | `BitmapDataDraw` | 56 | 22.5s |  |
| 3 | `DefineEditTextTest` | 153 | 27.3s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 24.5s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 21.8s |  |
| 6 | `DepthLimitsTest` | 20 | 20.8s |  |
| 7 | `PlaceObject2Test` | 9 | 25.8s |  |
| 8 | `ResolveEventsTest` | 15 | 17.6s |  |
| 9 | `RollOverOutTest` | 5 | 16.9s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.2s |  |
| 11 | `Version4Loader` | 11 | 2.1s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 19.8s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 19.7s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 19.5s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 19.6s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 2.8s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 19.5s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 19.7s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 21 | `attachExtImported` | 2 | 21.5s |  |
| 22 | `attachImported` | 2 | 2.3s |  |
| 23 | `attachMovieLoopingTest` | 41 | 20.6s |  |
| 24 | `attachMovieTest` | 12 | 21.3s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 20.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 25.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.8s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.1s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.7s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 20.9s |  |
| 35 | `event_handler_scope_test` | 16 | 2.6s |  |
| 36 | `frame_label_test` | 17 | 20.8s |  |
| 37 | `getTimer_test` | 8 | 19.9s |  |
| 38 | `get_frame_number_test` | 31 | 21.9s |  |
| 39 | `gotoFrame2Test` | 9 | 19.9s |  |
| 40 | `goto_frame_test` | 15 | 16.1s |  |
| 41 | `init_action/InitActionTest2` | 29 | 16.7s |  |
| 42 | `instanceNameTest` | 5 | 2.1s |  |
| 43 | `loading/LoadVarsTest` | 36 | 22.4s |  |
| 44 | `loop/loop_test` | 21 | 19.2s |  |
| 45 | `loop/loop_test2` | 15 | 19.0s |  |
| 46 | `loop/loop_test3` | 16 | 2.1s |  |
| 47 | `loop/loop_test4` | 22 | 21.5s |  |
| 48 | `loop/loop_test5` | 24 | 3.7s |  |
| 49 | `loop/loop_test8` | 38 | 21.4s |  |
| 50 | `loop/loop_test9` | 15 | 19.9s |  |
| 51 | `loop/simple_loop_test` | 0 | 20.6s |  |
| 52 | `masks_test2` | 10 | 21.5s |  |
| 53 | `morph_test1` | 0 | 24.7s |  |
| 54 | `move_object_test` | 11 | 25.6s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 25.4s |  |
| 56 | `new_child_in_unload_test` | 11 | 25.4s |  |
| 57 | `opcode_guard_test` | 18 | 19.4s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 19.4s |  |
| 59 | `place_and_remove_object_test` | 13 | 19.4s |  |
| 60 | `register_class/RegisterClassTest3` | 12 | 17.8s |  |
| 61 | `register_class/registerClassTest` | 51 | 19.8s |  |
| 62 | `replace_shapes1test` | 23 | 4.0s |  |
| 63 | `replace_sprites1test` | 21 | 26.4s |  |
| 64 | `reverse_execute_PlaceObject2_test1` | 8 | 25.8s |  |
| 65 | `reverse_execute_PlaceObject2_test2` | 10 | 26.3s |  |
| 66 | `runtime_vm_stack_test` | 9 | 26.5s |  |
| 67 | `shape_test` | 21 | 28.3s |  |
| 68 | `static_vs_dynamic1` | 17 | 25.7s |  |
| 69 | `static_vs_dynamic2` | 18 | 19.7s |  |
| 70 | `timeline_var_test` | 11 | 19.6s |  |
| 71 | `unload_movieclip_test1` | 6 | 19.4s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 23.8s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.4s |  |
| 3 | `DefineTextTest` | 4 | 4 | 20.1s |  |
| 4 | `DragDropTest` | 4 | 4 | 3.1s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 5.6s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 23.2s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 25.7s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 37.2s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 17.1s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 23.4s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 19.9s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 20.6s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 20.5s |  |
| 14 | `callFunction_test` | 6 | 11 | 21.2s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 26.4s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 24.9s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.1s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 20.9s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 15.8s |  |
| 20 | `key_event_test` | 5 | 6 | 21.9s |  |
| 21 | `loading/LoadBitmapTest` | 2 | 3 | 20.9s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 3.9s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 19.8s |  |
| 24 | `loop/loop_test6` | 11 | 12 | 21.5s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 3.2s |  |
| 26 | `masks_test` | 16 | 16 | 27.1s |  |
| 27 | `matrix_test` | 5 | 9 | 105.4s |  |
| 28 | `path_format_test` | 28 | 28 | 20.8s |  |
| 29 | `place_object_test` | 14 | 14 | 3.0s |  |
| 30 | `place_object_test2` | 22 | 23 | 19.9s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 27.5s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 26.3s |  |

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
| 3 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 4 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 5 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 15 | 96 |  |
| 6 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 7 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
