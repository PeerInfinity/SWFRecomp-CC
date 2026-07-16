# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-16 22:53 UTC

**Git SHA**: `a05b56ddf0`

**Run Duration**: 16m 43s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **67** (62.0%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **93** (86.1%) |
| Failing | 15 |
| Total expected lines | 5204 |
| Matching lines | 4035 (77.5%) |
| Mismatched lines | 1169 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 15 | 100.0% |

## Passing Tests

**67 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 3.1s |  |
| 2 | `DefineEditTextTest` | 153 | 13.3s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 28.1s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.7s |  |
| 5 | `DepthLimitsTest` | 20 | 23.1s |  |
| 6 | `PlaceObject2Test` | 9 | 2.1s |  |
| 7 | `ResolveEventsTest` | 15 | 4.1s |  |
| 8 | `RollOverOutTest` | 5 | 3.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.6s |  |
| 10 | `Version4Loader` | 11 | 2.5s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.9s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.3s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 3.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 2.9s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.5s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 1.1s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 1.0s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.9s |  |
| 20 | `attachExtImported` | 2 | 21.6s |  |
| 21 | `attachImported` | 2 | 2.6s |  |
| 22 | `attachMovieLoopingTest` | 41 | 20.5s |  |
| 23 | `attachMovieTest` | 12 | 3.3s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 3.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 2.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.2s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.9s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.7s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.6s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 3.7s |  |
| 34 | `event_handler_scope_test` | 16 | 3.0s |  |
| 35 | `frame_label_test` | 17 | 3.2s |  |
| 36 | `getTimer_test` | 8 | 2.2s |  |
| 37 | `get_frame_number_test` | 31 | 4.2s |  |
| 38 | `gotoFrame2Test` | 9 | 18.6s |  |
| 39 | `goto_frame_test` | 15 | 21.9s |  |
| 40 | `instanceNameTest` | 5 | 2.6s |  |
| 41 | `loading/LoadVarsTest` | 36 | 24.8s |  |
| 42 | `loop/loop_test` | 21 | 20.9s |  |
| 43 | `loop/loop_test2` | 15 | 2.7s |  |
| 44 | `loop/loop_test3` | 16 | 2.6s |  |
| 45 | `loop/loop_test4` | 22 | 3.8s |  |
| 46 | `loop/loop_test5` | 24 | 3.8s |  |
| 47 | `loop/loop_test8` | 38 | 5.2s |  |
| 48 | `loop/loop_test9` | 15 | 21.7s |  |
| 49 | `loop/simple_loop_test` | 0 | 24.9s |  |
| 50 | `masks_test2` | 10 | 20.9s |  |
| 51 | `morph_test1` | 0 | 24.2s |  |
| 52 | `move_object_test` | 11 | 2.7s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 20.7s |  |
| 54 | `new_child_in_unload_test` | 11 | 2.9s |  |
| 55 | `opcode_guard_test` | 18 | 17.6s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 1.1s |  |
| 57 | `register_class/registerClassTest` | 51 | 1.2s |  |
| 58 | `replace_shapes1test` | 23 | 3.5s |  |
| 59 | `replace_sprites1test` | 21 | 3.4s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 2.8s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 3.1s |  |
| 62 | `runtime_vm_stack_test` | 9 | 1.0s |  |
| 63 | `shape_test` | 21 | 1.5s |  |
| 64 | `static_vs_dynamic1` | 17 | 0.9s |  |
| 65 | `static_vs_dynamic2` | 18 | 2.2s |  |
| 66 | `timeline_var_test` | 11 | 2.0s |  |
| 67 | `unload_movieclip_test1` | 6 | 1.9s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 3.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 3.9s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.0s |  |
| 4 | `DefineTextTest` | 4 | 4 | 3.3s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 8.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 2.1s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 12.4s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 3.9s |  |
| 10 | `callFunction_test` | 6 | 11 | 3.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 29.2s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.4s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.3s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 4.1s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.4s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 4.6s |  |
| 17 | `key_event_test` | 5 | 6 | 23.3s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 4.1s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 5.4s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 21.9s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 3.6s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.1s |  |
| 23 | `matrix_test` | 5 | 9 | 103.2s |  |
| 24 | `path_format_test` | 28 | 28 | 3.7s |  |
| 25 | `register_class/registerClassTest2` | 8 | 28 | 23.9s |  |
| 26 | `replace_buttons1test` | 3 | 3 | 3.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17 | 22 | 5 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**15 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
| 4 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 5 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 6 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 7 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 8 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 9 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 10 | `register_class/RegisterClassTest4` | 10.5% | 6/57 | 57 | 42 |  |
| 11 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 9.5% | 10/105 | 105 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 5.5% | 4/73 | 73 | 62 |  |
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 15 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
