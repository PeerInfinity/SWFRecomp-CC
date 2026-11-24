# Ruffle Test Results (Filtered)

**Date**: 2026-11-24 16:56 UTC

**Git SHA**: `78fee9e13f`

**Run Duration**: 33m 20s

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
| Matching lines | 4310 (82.8%) |
| Mismatched lines | 896 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**71 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.4s |  |
| 2 | `BitmapDataDraw` | 56 | 25.1s |  |
| 3 | `DefineEditTextTest` | 153 | 35.2s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 30.9s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 27.3s |  |
| 6 | `DepthLimitsTest` | 20 | 26.5s |  |
| 7 | `PlaceObject2Test` | 9 | 19.0s |  |
| 8 | `ResolveEventsTest` | 15 | 19.5s |  |
| 9 | `RollOverOutTest` | 5 | 19.5s |  |
| 10 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 11 | `Version4Loader` | 11 | 1.4s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 18.9s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 24.4s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 24.6s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 24.7s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 3.3s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 18.9s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 19.2s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 1.4s |  |
| 21 | `attachExtImported` | 2 | 26.1s |  |
| 22 | `attachImported` | 2 | 2.4s |  |
| 23 | `attachMovieLoopingTest` | 41 | 26.1s |  |
| 24 | `attachMovieTest` | 12 | 26.8s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 18.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.6s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 24.4s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.6s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.2s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.3s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 19.2s |  |
| 35 | `event_handler_scope_test` | 16 | 1.7s |  |
| 36 | `frame_label_test` | 17 | 19.7s |  |
| 37 | `getTimer_test` | 8 | 18.7s |  |
| 38 | `get_frame_number_test` | 31 | 20.1s |  |
| 39 | `gotoFrame2Test` | 9 | 18.5s |  |
| 40 | `goto_frame_test` | 15 | 19.1s |  |
| 41 | `init_action/InitActionTest2` | 29 | 19.6s |  |
| 42 | `instanceNameTest` | 5 | 1.4s |  |
| 43 | `loading/LoadVarsTest` | 36 | 29.2s |  |
| 44 | `loop/loop_test` | 21 | 18.7s |  |
| 45 | `loop/loop_test2` | 15 | 18.4s |  |
| 46 | `loop/loop_test3` | 16 | 1.4s |  |
| 47 | `loop/loop_test4` | 22 | 19.9s |  |
| 48 | `loop/loop_test5` | 24 | 2.2s |  |
| 49 | `loop/loop_test8` | 38 | 20.4s |  |
| 50 | `loop/loop_test9` | 15 | 18.8s |  |
| 51 | `loop/simple_loop_test` | 0 | 18.4s |  |
| 52 | `masks_test2` | 10 | 18.5s |  |
| 53 | `morph_test1` | 0 | 18.6s |  |
| 54 | `move_object_test` | 11 | 22.7s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 23.1s |  |
| 56 | `new_child_in_unload_test` | 11 | 23.4s |  |
| 57 | `opcode_guard_test` | 18 | 24.7s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 24.8s |  |
| 59 | `place_and_remove_object_test` | 13 | 24.2s |  |
| 60 | `register_class/RegisterClassTest3` | 12 | 19.4s |  |
| 61 | `register_class/registerClassTest` | 51 | 21.2s |  |
| 62 | `replace_shapes1test` | 23 | 1.8s |  |
| 63 | `replace_sprites1test` | 21 | 24.7s |  |
| 64 | `reverse_execute_PlaceObject2_test1` | 8 | 24.3s |  |
| 65 | `reverse_execute_PlaceObject2_test2` | 10 | 24.4s |  |
| 66 | `runtime_vm_stack_test` | 9 | 16.7s |  |
| 67 | `shape_test` | 21 | 17.7s |  |
| 68 | `static_vs_dynamic1` | 17 | 17.4s |  |
| 69 | `static_vs_dynamic2` | 18 | 20.3s |  |
| 70 | `timeline_var_test` | 11 | 20.0s |  |
| 71 | `unload_movieclip_test1` | 6 | 19.8s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 24.6s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.1s |  |
| 3 | `DefineTextTest` | 4 | 4 | 24.9s |  |
| 4 | `DragDropTest` | 4 | 4 | 3.3s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 6.7s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 29.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 19.5s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 26.9s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 19.0s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.1s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 24.9s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 25.9s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 25.9s |  |
| 14 | `callFunction_test` | 6 | 11 | 19.4s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.4s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.8s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.5s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 19.5s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 18.8s |  |
| 20 | `key_event_test` | 5 | 6 | 27.6s |  |
| 21 | `loading/LoadBitmapTest` | 3 | 3 | 27.1s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 4.6s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 19.3s |  |
| 24 | `loop/loop_test6` | 11 | 12 | 19.7s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 1.8s |  |
| 26 | `masks_test` | 16 | 16 | 26.4s |  |
| 27 | `matrix_test` | 5 | 9 | 77.9s |  |
| 28 | `path_format_test` | 28 | 28 | 27.2s |  |
| 29 | `place_object_test` | 14 | 14 | 2.6s |  |
| 30 | `place_object_test2` | 22 | 23 | 24.4s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 19.7s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 19.0s |  |

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
| 5 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 6 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 7 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
