# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 17:28 UTC

**Git SHA**: `08709f6584`

**Run Duration**: 21m 28s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 32 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **101** (91.0%) |
| Failing | 10 |
| Total expected lines | 5248 |
| Matching lines | 4236 (80.7%) |
| Mismatched lines | 1012 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.6s |  |
| 2 | `DefineEditTextTest` | 153 | 4.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 3.2s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 2.0s |  |
| 5 | `DepthLimitsTest` | 20 | 19.1s |  |
| 6 | `PlaceObject2Test` | 9 | 18.5s |  |
| 7 | `ResolveEventsTest` | 15 | 19.0s |  |
| 8 | `RollOverOutTest` | 5 | 2.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.0s |  |
| 10 | `Version4Loader` | 11 | 1.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.6s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 19.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 19.4s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 2.7s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.4s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 2.0s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 15.8s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.9s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 20 | `attachExtImported` | 2 | 4.2s |  |
| 21 | `attachImported` | 2 | 3.1s |  |
| 22 | `attachMovieLoopingTest` | 41 | 24.7s |  |
| 23 | `attachMovieTest` | 12 | 25.4s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 2.6s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 3.0s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.6s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 26.1s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 4.3s |  |
| 34 | `event_handler_scope_test` | 16 | 3.4s |  |
| 35 | `frame_label_test` | 17 | 2.9s |  |
| 36 | `getTimer_test` | 8 | 17.7s |  |
| 37 | `get_frame_number_test` | 31 | 19.4s |  |
| 38 | `gotoFrame2Test` | 9 | 17.7s |  |
| 39 | `goto_frame_test` | 15 | 18.5s |  |
| 40 | `instanceNameTest` | 5 | 1.9s |  |
| 41 | `loading/LoadVarsTest` | 36 | 20.5s |  |
| 42 | `loop/loop_test` | 21 | 18.0s |  |
| 43 | `loop/loop_test2` | 15 | 2.0s |  |
| 44 | `loop/loop_test3` | 16 | 2.0s |  |
| 45 | `loop/loop_test4` | 22 | 18.5s |  |
| 46 | `loop/loop_test5` | 24 | 2.7s |  |
| 47 | `loop/loop_test8` | 38 | 19.5s |  |
| 48 | `loop/loop_test9` | 15 | 17.9s |  |
| 49 | `loop/simple_loop_test` | 0 | 3.0s |  |
| 50 | `masks_test2` | 10 | 18.2s |  |
| 51 | `morph_test1` | 0 | 19.8s |  |
| 52 | `move_object_test` | 11 | 17.9s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 17.8s |  |
| 54 | `new_child_in_unload_test` | 11 | 2.1s |  |
| 55 | `opcode_guard_test` | 18 | 18.4s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 18.2s |  |
| 57 | `place_and_remove_object_test` | 13 | 2.1s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 2.4s |  |
| 59 | `register_class/registerClassTest` | 51 | 19.7s |  |
| 60 | `replace_shapes1test` | 23 | 3.6s |  |
| 61 | `replace_sprites1test` | 21 | 2.4s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 2.0s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 18.1s |  |
| 64 | `runtime_vm_stack_test` | 9 | 24.3s |  |
| 65 | `shape_test` | 21 | 26.3s |  |
| 66 | `static_vs_dynamic1` | 17 | 3.0s |  |
| 67 | `static_vs_dynamic2` | 18 | 23.8s |  |
| 68 | `timeline_var_test` | 11 | 23.5s |  |
| 69 | `unload_movieclip_test1` | 6 | 2.6s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 4.8s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 21.4s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.0s |  |
| 4 | `DefineTextTest` | 4 | 4 | 1.1s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.9s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 21.4s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 18.7s |  |
| 8 | `PrototypeEventListeners` | 23 | 23 | 18.1s |  |
| 9 | `TextSnapshotTest` | 81 | 90 | 24.9s |  |
| 10 | `action_order/action_execution_order_test` | 12 | 12 | 2.7s |  |
| 11 | `action_order/action_execution_order_test4` | 7 | 26 | 3.7s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 20.9s |  |
| 13 | `callFunction_test` | 6 | 11 | 3.3s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 25.8s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 24.0s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.2s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 27.3s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 18.4s |  |
| 19 | `init_action/InitActionTest2` | 24 | 30 | 3.3s |  |
| 20 | `key_event_test` | 5 | 6 | 20.2s |  |
| 21 | `loading/LoadBitmapTest` | 3 | 3 | 19.2s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 3.6s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 2.7s |  |
| 24 | `loop/loop_test6` | 11 | 12 | 2.6s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 2.2s |  |
| 26 | `masks_test` | 16 | 16 | 24.9s |  |
| 27 | `matrix_test` | 5 | 9 | 77.5s |  |
| 28 | `path_format_test` | 28 | 28 | 3.7s |  |
| 29 | `place_object_test` | 14 | 14 | 2.6s |  |
| 30 | `place_object_test2` | 22 | 23 | 18.6s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 25.8s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 3.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `NetStream-SquareTest` | 56.0% | 121 | 216 | 95 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**10 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `NetStream-SquareTest` | 56.0% | 121/216 | 201 | 216 |  |
| 4 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 5 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 7 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 8 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 9 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 10 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
