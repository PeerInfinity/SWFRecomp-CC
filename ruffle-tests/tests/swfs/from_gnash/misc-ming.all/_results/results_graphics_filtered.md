# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 07:07 UTC

**Git SHA**: `da9b49b17a`

**Run Duration**: 26m 37s

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
| Matching lines | 4276 (82.1%) |
| Mismatched lines | 930 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**70 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 19.9s |  |
| 2 | `BitmapDataDraw` | 56 | 21.5s |  |
| 3 | `DefineEditTextTest` | 153 | 26.4s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 23.7s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 20.9s |  |
| 6 | `DepthLimitsTest` | 20 | 27.2s |  |
| 7 | `PlaceObject2Test` | 9 | 3.3s |  |
| 8 | `ResolveEventsTest` | 15 | 3.8s |  |
| 9 | `RollOverOutTest` | 5 | 3.6s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.7s |  |
| 11 | `Version4Loader` | 11 | 2.6s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 24.6s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 24.9s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 25.1s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 2.9s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 3.6s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 26.4s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 26.8s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.4s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 3.2s |  |
| 21 | `attachExtImported` | 2 | 19.8s |  |
| 22 | `attachImported` | 2 | 2.1s |  |
| 23 | `attachMovieLoopingTest` | 41 | 19.1s |  |
| 24 | `attachMovieTest` | 12 | 19.6s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 25.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 3.2s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.2s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.1s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.6s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.0s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 2.8s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 2.9s |  |
| 35 | `event_handler_scope_test` | 16 | 2.3s |  |
| 36 | `frame_label_test` | 17 | 4.7s |  |
| 37 | `getTimer_test` | 8 | 25.4s |  |
| 38 | `get_frame_number_test` | 31 | 6.2s |  |
| 39 | `gotoFrame2Test` | 9 | 25.3s |  |
| 40 | `goto_frame_test` | 15 | 16.7s |  |
| 41 | `instanceNameTest` | 5 | 2.1s |  |
| 42 | `loading/LoadVarsTest` | 36 | 23.6s |  |
| 43 | `loop/loop_test` | 21 | 19.6s |  |
| 44 | `loop/loop_test2` | 15 | 2.0s |  |
| 45 | `loop/loop_test3` | 16 | 2.1s |  |
| 46 | `loop/loop_test4` | 22 | 4.2s |  |
| 47 | `loop/loop_test5` | 24 | 4.4s |  |
| 48 | `loop/loop_test8` | 38 | 3.5s |  |
| 49 | `loop/loop_test9` | 15 | 19.0s |  |
| 50 | `loop/simple_loop_test` | 0 | 3.0s |  |
| 51 | `masks_test2` | 10 | 25.4s |  |
| 52 | `morph_test1` | 0 | 27.7s |  |
| 53 | `move_object_test` | 11 | 25.2s |  |
| 54 | `multi_doactions_and_goto_frame_test` | 6 | 25.0s |  |
| 55 | `new_child_in_unload_test` | 11 | 25.5s |  |
| 56 | `opcode_guard_test` | 18 | 19.6s |  |
| 57 | `place_and_remove_object_insane_test` | 22 | 19.6s |  |
| 58 | `place_and_remove_object_test` | 13 | 19.6s |  |
| 59 | `register_class/RegisterClassTest3` | 12 | 19.3s |  |
| 60 | `register_class/registerClassTest` | 51 | 20.9s |  |
| 61 | `replace_shapes1test` | 23 | 3.3s |  |
| 62 | `replace_sprites1test` | 21 | 19.3s |  |
| 63 | `reverse_execute_PlaceObject2_test1` | 8 | 18.9s |  |
| 64 | `reverse_execute_PlaceObject2_test2` | 10 | 19.1s |  |
| 65 | `runtime_vm_stack_test` | 9 | 19.7s |  |
| 66 | `shape_test` | 21 | 21.0s |  |
| 67 | `static_vs_dynamic1` | 17 | 2.1s |  |
| 68 | `static_vs_dynamic2` | 18 | 18.8s |  |
| 69 | `timeline_var_test` | 11 | 2.1s |  |
| 70 | `unload_movieclip_test1` | 6 | 1.9s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 22.6s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.1s |  |
| 3 | `DefineTextTest` | 4 | 4 | 2.3s |  |
| 4 | `DragDropTest` | 4 | 4 | 4.5s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 7.7s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 30.2s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 3.2s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 31.5s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 20.0s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 29.6s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 3.6s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 23.0s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 22.3s |  |
| 14 | `callFunction_test` | 11 | 11 | 20.2s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 35.2s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.2s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.2s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 3.2s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 17.0s |  |
| 20 | `init_action/InitActionTest2` | 24 | 30 | 17.7s |  |
| 21 | `key_event_test` | 5 | 6 | 22.8s |  |
| 22 | `loading/LoadBitmapTest` | 3 | 3 | 21.9s |  |
| 23 | `loading/loadMovieTest` | 9 | 9 | 4.0s |  |
| 24 | `loop/loop_test10` | 23 | 23 | 20.2s |  |
| 25 | `loop/loop_test6` | 11 | 12 | 25.8s |  |
| 26 | `loop/loop_test7` | 1 | 8 | 3.5s |  |
| 27 | `masks_test` | 16 | 16 | 26.2s |  |
| 28 | `matrix_test` | 5 | 9 | 122.7s |  |
| 29 | `path_format_test` | 28 | 28 | 3.8s |  |
| 30 | `place_object_test` | 14 | 14 | 3.0s |  |
| 31 | `place_object_test2` | 22 | 23 | 2.5s |  |
| 32 | `register_class/registerClassTest2` | 8 | 28 | 23.9s |  |
| 33 | `replace_buttons1test` | 3 | 3 | 3.3s |  |

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
| 5 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 6 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 7 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
