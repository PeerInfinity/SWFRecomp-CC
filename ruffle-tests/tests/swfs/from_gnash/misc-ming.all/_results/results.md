# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-25 03:59 UTC

**Git SHA**: `8f4f6e3953`

**Run Duration**: 23m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **71** (64.0%) |
| Ruffle-matched | 32 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **103** (92.8%) |
| Failing | 8 |
| Total expected lines | 5248 |
| Matching lines | 4318 (82.3%) |
| Mismatched lines | 930 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**71 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 19.4s |  |
| 2 | `BitmapDataDraw` | 56 | 4.3s |  |
| 3 | `DefineEditTextTest` | 153 | 10.8s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 25.8s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 23.1s |  |
| 6 | `DepthLimitsTest` | 20 | 19.8s |  |
| 7 | `PlaceObject2Test` | 9 | 20.2s |  |
| 8 | `ResolveEventsTest` | 15 | 16.9s |  |
| 9 | `RollOverOutTest` | 5 | 17.3s |  |
| 10 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 11 | `Version4Loader` | 11 | 1.4s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 18.5s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.7s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 1.6s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 24.0s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 2.7s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 1.5s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 1.8s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 1.5s |  |
| 21 | `attachExtImported` | 2 | 27.6s |  |
| 22 | `attachImported` | 2 | 2.3s |  |
| 23 | `attachMovieLoopingTest` | 41 | 25.5s |  |
| 24 | `attachMovieTest` | 12 | 25.9s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 18.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 1.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 15.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.4s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.3s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 3.6s |  |
| 35 | `event_handler_scope_test` | 16 | 2.7s |  |
| 36 | `frame_label_test` | 17 | 19.0s |  |
| 37 | `getTimer_test` | 8 | 18.2s |  |
| 38 | `get_frame_number_test` | 31 | 19.9s |  |
| 39 | `gotoFrame2Test` | 9 | 18.2s |  |
| 40 | `goto_frame_test` | 15 | 19.1s |  |
| 41 | `init_action/InitActionTest2` | 29 | 19.4s |  |
| 42 | `instanceNameTest` | 5 | 1.4s |  |
| 43 | `loading/LoadVarsTest` | 36 | 21.0s |  |
| 44 | `loop/loop_test` | 21 | 18.8s |  |
| 45 | `loop/loop_test2` | 15 | 1.4s |  |
| 46 | `loop/loop_test3` | 16 | 1.4s |  |
| 47 | `loop/loop_test4` | 22 | 2.1s |  |
| 48 | `loop/loop_test5` | 24 | 2.2s |  |
| 49 | `loop/loop_test8` | 38 | 4.5s |  |
| 50 | `loop/loop_test9` | 15 | 24.1s |  |
| 51 | `loop/simple_loop_test` | 0 | 1.7s |  |
| 52 | `masks_test2` | 10 | 18.8s |  |
| 53 | `morph_test1` | 0 | 18.5s |  |
| 54 | `move_object_test` | 11 | 21.2s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 21.4s |  |
| 56 | `new_child_in_unload_test` | 11 | 2.3s |  |
| 57 | `opcode_guard_test` | 18 | 19.6s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 19.6s |  |
| 59 | `place_and_remove_object_test` | 13 | 24.5s |  |
| 60 | `register_class/RegisterClassTest3` | 12 | 1.9s |  |
| 61 | `register_class/registerClassTest` | 51 | 20.8s |  |
| 62 | `replace_shapes1test` | 23 | 2.3s |  |
| 63 | `replace_sprites1test` | 21 | 24.0s |  |
| 64 | `reverse_execute_PlaceObject2_test1` | 8 | 23.2s |  |
| 65 | `reverse_execute_PlaceObject2_test2` | 10 | 23.6s |  |
| 66 | `runtime_vm_stack_test` | 9 | 2.4s |  |
| 67 | `shape_test` | 21 | 26.1s |  |
| 68 | `static_vs_dynamic1` | 17 | 1.8s |  |
| 69 | `static_vs_dynamic2` | 18 | 19.9s |  |
| 70 | `timeline_var_test` | 11 | 19.1s |  |
| 71 | `unload_movieclip_test1` | 6 | 18.8s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 5.0s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 1.5s |  |
| 3 | `DefineTextTest` | 4 | 4 | 2.2s |  |
| 4 | `DragDropTest` | 4 | 4 | 2.4s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 4.7s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 21.7s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.3s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 29.7s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 16.5s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 24.4s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 1.9s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 25.0s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 24.9s |  |
| 14 | `callFunction_test` | 6 | 11 | 19.1s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.4s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.1s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.1s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 4.0s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 18.9s |  |
| 20 | `key_event_test` | 5 | 6 | 19.9s |  |
| 21 | `loading/LoadBitmapTest` | 2 | 3 | 19.6s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 3.0s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 19.1s |  |
| 24 | `loop/loop_test6` | 11 | 12 | 2.0s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 1.7s |  |
| 26 | `masks_test` | 16 | 16 | 35.2s |  |
| 27 | `matrix_test` | 5 | 9 | 77.0s |  |
| 28 | `path_format_test` | 28 | 28 | 3.5s |  |
| 29 | `place_object_test` | 14 | 14 | 2.4s |  |
| 30 | `place_object_test2` | 22 | 23 | 2.5s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 20.8s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 2.3s |  |

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

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 3 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 4 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 5 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 6 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 7 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 8 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
