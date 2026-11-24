# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-24 07:25 UTC

**Git SHA**: `cceb5133a1`

**Run Duration**: 28m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **71** (64.0%) |
| Ruffle-matched | 32 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **103** (92.8%) |
| Failing | 8 |
| Total expected lines | 5248 |
| Matching lines | 4313 (82.2%) |
| Mismatched lines | 935 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**71 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.3s |  |
| 2 | `BitmapDataDraw` | 56 | 22.0s |  |
| 3 | `DefineEditTextTest` | 153 | 26.4s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 24.0s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 21.5s |  |
| 6 | `DepthLimitsTest` | 20 | 24.4s |  |
| 7 | `PlaceObject2Test` | 9 | 18.8s |  |
| 8 | `ResolveEventsTest` | 15 | 2.9s |  |
| 9 | `RollOverOutTest` | 5 | 2.7s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.1s |  |
| 11 | `Version4Loader` | 11 | 2.0s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 19.2s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 19.5s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 19.6s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 18.8s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 2.6s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 19.3s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 2.4s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 21 | `attachExtImported` | 2 | 19.8s |  |
| 22 | `attachImported` | 2 | 2.1s |  |
| 23 | `attachMovieLoopingTest` | 41 | 19.1s |  |
| 24 | `attachMovieTest` | 12 | 19.6s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 26.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 3.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.6s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.2s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.8s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.3s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.1s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 21.9s |  |
| 35 | `event_handler_scope_test` | 16 | 3.0s |  |
| 36 | `frame_label_test` | 17 | 3.1s |  |
| 37 | `getTimer_test` | 8 | 19.0s |  |
| 38 | `get_frame_number_test` | 31 | 3.9s |  |
| 39 | `gotoFrame2Test` | 9 | 18.9s |  |
| 40 | `goto_frame_test` | 15 | 25.2s |  |
| 41 | `init_action/InitActionTest2` | 29 | 26.2s |  |
| 42 | `instanceNameTest` | 5 | 2.8s |  |
| 43 | `loading/LoadVarsTest` | 36 | 28.9s |  |
| 44 | `loop/loop_test` | 21 | 19.4s |  |
| 45 | `loop/loop_test2` | 15 | 19.2s |  |
| 46 | `loop/loop_test3` | 16 | 2.1s |  |
| 47 | `loop/loop_test4` | 22 | 2.8s |  |
| 48 | `loop/loop_test5` | 24 | 2.9s |  |
| 49 | `loop/loop_test8` | 38 | 27.5s |  |
| 50 | `loop/loop_test9` | 15 | 25.1s |  |
| 51 | `loop/simple_loop_test` | 0 | 26.5s |  |
| 52 | `masks_test2` | 10 | 19.8s |  |
| 53 | `morph_test1` | 0 | 21.1s |  |
| 54 | `move_object_test` | 11 | 19.2s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 19.1s |  |
| 56 | `new_child_in_unload_test` | 11 | 19.2s |  |
| 57 | `opcode_guard_test` | 18 | 19.8s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 20.0s |  |
| 59 | `place_and_remove_object_test` | 13 | 20.4s |  |
| 60 | `register_class/RegisterClassTest3` | 12 | 19.1s |  |
| 61 | `register_class/registerClassTest` | 51 | 20.6s |  |
| 62 | `replace_shapes1test` | 23 | 2.8s |  |
| 63 | `replace_sprites1test` | 21 | 19.5s |  |
| 64 | `reverse_execute_PlaceObject2_test1` | 8 | 19.1s |  |
| 65 | `reverse_execute_PlaceObject2_test2` | 10 | 19.6s |  |
| 66 | `runtime_vm_stack_test` | 9 | 26.8s |  |
| 67 | `shape_test` | 21 | 28.6s |  |
| 68 | `static_vs_dynamic1` | 17 | 3.3s |  |
| 69 | `static_vs_dynamic2` | 18 | 16.9s |  |
| 70 | `timeline_var_test` | 11 | 2.5s |  |
| 71 | `unload_movieclip_test1` | 6 | 2.2s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 22.7s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.2s |  |
| 3 | `DefineTextTest` | 4 | 4 | 2.5s |  |
| 4 | `DragDropTest` | 4 | 4 | 3.9s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 7.5s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.4s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 19.0s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 25.5s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 19.3s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.4s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 19.8s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 19.3s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 19.4s |  |
| 14 | `callFunction_test` | 6 | 11 | 4.4s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 35.2s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.8s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.2s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 21.8s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 25.4s |  |
| 20 | `key_event_test` | 5 | 6 | 27.5s |  |
| 21 | `loading/LoadBitmapTest` | 3 | 3 | 26.5s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 5.5s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 20.1s |  |
| 24 | `loop/loop_test6` | 11 | 12 | 19.6s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 2.4s |  |
| 26 | `masks_test` | 16 | 16 | 35.4s |  |
| 27 | `matrix_test` | 5 | 9 | 82.0s |  |
| 28 | `path_format_test` | 28 | 28 | 4.1s |  |
| 29 | `place_object_test` | 14 | 14 | 3.1s |  |
| 30 | `place_object_test2` | 22 | 23 | 2.7s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 22.1s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 2.8s |  |

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
| 3 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 4 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 5 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 6 | `action_order/ActionOrderTest4` | 11.7% | 11/94 | 94 | 64 |  |
| 7 | `action_order/ActionOrderTest5` | 8.6% | 5/58 | 58 | 51 |  |
| 8 | `action_order/ActionOrderTest3` | 6.0% | 5/83 | 83 | 62 |  |
