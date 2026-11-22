# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-22 04:05 UTC

**Git SHA**: `10b5dff69c`

**Run Duration**: 29m 13s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 33 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (91.9%) |
| Failing | 9 |
| Total expected lines | 5248 |
| Matching lines | 4252 (81.0%) |
| Mismatched lines | 996 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.0s |  |
| 2 | `DefineEditTextTest` | 153 | 28.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.0s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 21.6s |  |
| 5 | `DepthLimitsTest` | 20 | 19.0s |  |
| 6 | `PlaceObject2Test` | 9 | 17.4s |  |
| 7 | `ResolveEventsTest` | 15 | 18.6s |  |
| 8 | `RollOverOutTest` | 5 | 17.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 10 | `Version4Loader` | 11 | 1.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.6s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 18.1s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 18.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 17.3s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 1.9s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 17.4s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 17.7s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.3s |  |
| 20 | `attachExtImported` | 2 | 18.4s |  |
| 21 | `attachImported` | 2 | 1.3s |  |
| 22 | `attachMovieLoopingTest` | 41 | 17.6s |  |
| 23 | `attachMovieTest` | 12 | 17.8s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 18.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.5s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 17.6s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.4s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.4s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.2s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 18.6s |  |
| 34 | `event_handler_scope_test` | 16 | 1.7s |  |
| 35 | `frame_label_test` | 17 | 24.0s |  |
| 36 | `getTimer_test` | 8 | 22.5s |  |
| 37 | `get_frame_number_test` | 31 | 25.1s |  |
| 38 | `gotoFrame2Test` | 9 | 23.1s |  |
| 39 | `goto_frame_test` | 15 | 18.1s |  |
| 40 | `instanceNameTest` | 5 | 1.4s |  |
| 41 | `loading/LoadVarsTest` | 36 | 20.2s |  |
| 42 | `loop/loop_test` | 21 | 17.9s |  |
| 43 | `loop/loop_test2` | 15 | 17.4s |  |
| 44 | `loop/loop_test3` | 16 | 1.4s |  |
| 45 | `loop/loop_test4` | 22 | 17.7s |  |
| 46 | `loop/loop_test5` | 24 | 2.1s |  |
| 47 | `loop/loop_test8` | 38 | 19.6s |  |
| 48 | `loop/loop_test9` | 15 | 18.0s |  |
| 49 | `loop/simple_loop_test` | 0 | 17.8s |  |
| 50 | `masks_test2` | 10 | 18.5s |  |
| 51 | `morph_test1` | 0 | 17.8s |  |
| 52 | `move_object_test` | 11 | 17.9s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 17.8s |  |
| 54 | `new_child_in_unload_test` | 11 | 17.9s |  |
| 55 | `opcode_guard_test` | 18 | 17.7s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 17.6s |  |
| 57 | `place_and_remove_object_test` | 13 | 15.0s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 19.1s |  |
| 59 | `register_class/registerClassTest` | 51 | 21.3s |  |
| 60 | `replace_shapes1test` | 23 | 1.8s |  |
| 61 | `replace_sprites1test` | 21 | 17.6s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 17.4s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 17.8s |  |
| 64 | `runtime_vm_stack_test` | 9 | 18.9s |  |
| 65 | `shape_test` | 21 | 19.2s |  |
| 66 | `static_vs_dynamic1` | 17 | 17.8s |  |
| 67 | `static_vs_dynamic2` | 18 | 18.4s |  |
| 68 | `timeline_var_test` | 11 | 18.2s |  |
| 69 | `unload_movieclip_test1` | 6 | 17.8s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 20.5s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 21.6s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 1.5s |  |
| 4 | `DefineTextTest` | 4 | 4 | 19.6s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.4s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 20.9s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 17.3s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 24.1s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 17.9s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 23.6s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 18.6s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 18.0s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 17.9s |  |
| 14 | `callFunction_test` | 6 | 11 | 18.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.7s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 17.6s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.5s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 18.5s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 18.2s |  |
| 20 | `init_action/InitActionTest2` | 24 | 30 | 19.1s |  |
| 21 | `key_event_test` | 5 | 6 | 18.6s |  |
| 22 | `loading/LoadBitmapTest` | 3 | 3 | 18.4s |  |
| 23 | `loading/loadMovieTest` | 9 | 9 | 3.0s |  |
| 24 | `loop/loop_test10` | 23 | 23 | 18.2s |  |
| 25 | `loop/loop_test6` | 11 | 12 | 17.8s |  |
| 26 | `loop/loop_test7` | 1 | 8 | 1.6s |  |
| 27 | `masks_test` | 16 | 16 | 24.8s |  |
| 28 | `matrix_test` | 5 | 9 | 103.7s |  |
| 29 | `path_format_test` | 28 | 28 | 19.1s |  |
| 30 | `place_object_test` | 14 | 14 | 1.8s |  |
| 31 | `place_object_test2` | 22 | 23 | 14.5s |  |
| 32 | `register_class/registerClassTest2` | 8 | 28 | 18.4s |  |
| 33 | `replace_buttons1test` | 3 | 3 | 17.6s |  |

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
