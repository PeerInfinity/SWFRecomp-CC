# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 20:23 UTC

**Git SHA**: `13b40eabb0`

**Run Duration**: 25m 15s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **71** (64.5%) |
| Ruffle-matched | 31 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (92.7%) |
| Failing | 8 |
| Total expected lines | 5206 |
| Matching lines | 4311 (82.8%) |
| Mismatched lines | 895 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**71 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.6s |  |
| 2 | `BitmapDataDraw` | 56 | 5.1s |  |
| 3 | `DefineEditTextTest` | 153 | 10.1s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 23.0s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 20.5s |  |
| 6 | `DepthLimitsTest` | 20 | 21.2s |  |
| 7 | `PlaceObject2Test` | 9 | 27.7s |  |
| 8 | `ResolveEventsTest` | 15 | 26.4s |  |
| 9 | `RollOverOutTest` | 5 | 3.9s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.1s |  |
| 11 | `Version4Loader` | 11 | 2.0s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 19.3s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 20.0s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 2.4s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 3.2s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 4.0s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 2.2s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 20.2s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.2s |  |
| 21 | `attachExtImported` | 2 | 20.0s |  |
| 22 | `attachImported` | 2 | 2.1s |  |
| 23 | `attachMovieLoopingTest` | 41 | 19.3s |  |
| 24 | `attachMovieTest` | 12 | 2.6s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 2.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 3.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.8s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.8s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.2s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 26.7s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 4.7s |  |
| 35 | `event_handler_scope_test` | 16 | 3.8s |  |
| 36 | `frame_label_test` | 17 | 5.5s |  |
| 37 | `getTimer_test` | 8 | 3.9s |  |
| 38 | `get_frame_number_test` | 31 | 31.6s |  |
| 39 | `gotoFrame2Test` | 9 | 28.7s |  |
| 40 | `goto_frame_test` | 15 | 28.1s |  |
| 41 | `init_action/InitActionTest2` | 29 | 28.5s |  |
| 42 | `instanceNameTest` | 5 | 3.3s |  |
| 43 | `loading/LoadVarsTest` | 36 | 22.2s |  |
| 44 | `loop/loop_test` | 21 | 19.7s |  |
| 45 | `loop/loop_test2` | 15 | 2.2s |  |
| 46 | `loop/loop_test3` | 16 | 2.2s |  |
| 47 | `loop/loop_test4` | 22 | 30.6s |  |
| 48 | `loop/loop_test5` | 24 | 5.1s |  |
| 49 | `loop/loop_test8` | 38 | 21.4s |  |
| 50 | `loop/loop_test9` | 15 | 19.8s |  |
| 51 | `loop/simple_loop_test` | 0 | 3.2s |  |
| 52 | `masks_test2` | 10 | 19.1s |  |
| 53 | `morph_test1` | 0 | 20.8s |  |
| 54 | `move_object_test` | 11 | 20.0s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 19.6s |  |
| 56 | `new_child_in_unload_test` | 11 | 2.4s |  |
| 57 | `opcode_guard_test` | 18 | 19.8s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 19.8s |  |
| 59 | `place_and_remove_object_test` | 13 | 26.8s |  |
| 60 | `register_class/RegisterClassTest3` | 12 | 1.1s |  |
| 61 | `register_class/registerClassTest` | 51 | 1.2s |  |
| 62 | `replace_shapes1test` | 23 | 2.7s |  |
| 63 | `replace_sprites1test` | 21 | 2.6s |  |
| 64 | `reverse_execute_PlaceObject2_test1` | 8 | 19.2s |  |
| 65 | `reverse_execute_PlaceObject2_test2` | 10 | 19.3s |  |
| 66 | `runtime_vm_stack_test` | 9 | 4.0s |  |
| 67 | `shape_test` | 21 | 28.2s |  |
| 68 | `static_vs_dynamic1` | 17 | 3.4s |  |
| 69 | `static_vs_dynamic2` | 18 | 19.7s |  |
| 70 | `timeline_var_test` | 11 | 19.6s |  |
| 71 | `unload_movieclip_test1` | 6 | 2.1s |  |

## Ruffle-Matched Tests

**31 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 23.5s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.3s |  |
| 3 | `DefineTextTest` | 4 | 4 | 2.5s |  |
| 4 | `DragDropTest` | 4 | 4 | 3.2s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 5.7s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 23.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 27.5s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 39.4s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 25.2s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 34.8s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 2.8s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 28.0s |  |
| 13 | `callFunction_test` | 6 | 11 | 2.8s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.7s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.2s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 27.4s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 27.6s |  |
| 19 | `key_event_test` | 5 | 6 | 21.4s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 20.6s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 3.8s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 20.5s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 4.8s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 4.2s |  |
| 25 | `masks_test` | 16 | 16 | 26.7s |  |
| 26 | `matrix_test` | 5 | 9 | 78.1s |  |
| 27 | `path_format_test` | 28 | 28 | 3.9s |  |
| 28 | `place_object_test` | 14 | 14 | 4.8s |  |
| 29 | `place_object_test2` | 22 | 23 | 27.2s |  |
| 30 | `register_class/registerClassTest2` | 8 | 28 | 21.3s |  |
| 31 | `replace_buttons1test` | 3 | 3 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 2 | `action_order/action_execution_order_test4` | 73.1% | 19 | 26 | 7 |  |

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
| 2 | `action_order/action_execution_order_test4` | 73.1% | 19/26 | 26 | 26 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 5 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 15 | 96 |  |
| 7 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 8 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
