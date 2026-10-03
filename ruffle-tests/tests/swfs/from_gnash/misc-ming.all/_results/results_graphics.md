# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-03 20:48 UTC

**Git SHA**: `4c450f076e`

**Run Duration**: 26m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 32 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **101** (91.0%) |
| Failing | 10 |
| Total expected lines | 5248 |
| Matching lines | 4227 (80.5%) |
| Mismatched lines | 1021 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 23.8s |  |
| 2 | `DefineEditTextTest` | 153 | 32.9s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 29.1s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 25.5s |  |
| 5 | `DepthLimitsTest` | 20 | 24.2s |  |
| 6 | `PlaceObject2Test` | 9 | 22.7s |  |
| 7 | `ResolveEventsTest` | 15 | 24.1s |  |
| 8 | `RollOverOutTest` | 5 | 3.5s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.9s |  |
| 10 | `Version4Loader` | 11 | 2.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 23.4s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 23.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 23.5s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 3.1s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.8s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 22.2s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 3.4s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.8s |  |
| 20 | `attachExtImported` | 2 | 15.1s |  |
| 21 | `attachImported` | 2 | 1.9s |  |
| 22 | `attachMovieLoopingTest` | 41 | 14.7s |  |
| 23 | `attachMovieTest` | 12 | 15.3s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 22.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 22.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.5s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.4s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 23.7s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 4.2s |  |
| 34 | `event_handler_scope_test` | 16 | 3.3s |  |
| 35 | `frame_label_test` | 17 | 4.1s |  |
| 36 | `getTimer_test` | 8 | 20.6s |  |
| 37 | `get_frame_number_test` | 31 | 22.9s |  |
| 38 | `gotoFrame2Test` | 9 | 19.8s |  |
| 39 | `goto_frame_test` | 15 | 19.8s |  |
| 40 | `instanceNameTest` | 5 | 2.4s |  |
| 41 | `loading/LoadVarsTest` | 36 | 20.8s |  |
| 42 | `loop/loop_test` | 21 | 22.2s |  |
| 43 | `loop/loop_test2` | 15 | 2.8s |  |
| 44 | `loop/loop_test3` | 16 | 2.8s |  |
| 45 | `loop/loop_test4` | 22 | 4.1s |  |
| 46 | `loop/loop_test5` | 24 | 4.2s |  |
| 47 | `loop/loop_test8` | 38 | 5.2s |  |
| 48 | `loop/loop_test9` | 15 | 22.4s |  |
| 49 | `loop/simple_loop_test` | 0 | 4.6s |  |
| 50 | `masks_test2` | 10 | 22.7s |  |
| 51 | `morph_test1` | 0 | 5.9s |  |
| 52 | `move_object_test` | 11 | 18.2s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 18.2s |  |
| 54 | `new_child_in_unload_test` | 11 | 18.0s |  |
| 55 | `opcode_guard_test` | 18 | 14.8s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 15.1s |  |
| 57 | `place_and_remove_object_test` | 13 | 22.9s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 24.1s |  |
| 59 | `register_class/registerClassTest` | 51 | 25.9s |  |
| 60 | `replace_shapes1test` | 23 | 0.9s |  |
| 61 | `replace_sprites1test` | 21 | 3.5s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 2.9s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 23.1s |  |
| 64 | `runtime_vm_stack_test` | 9 | 23.3s |  |
| 65 | `shape_test` | 21 | 24.9s |  |
| 66 | `static_vs_dynamic1` | 17 | 2.8s |  |
| 67 | `static_vs_dynamic2` | 18 | 0.8s |  |
| 68 | `timeline_var_test` | 11 | 0.8s |  |
| 69 | `unload_movieclip_test1` | 6 | 0.8s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 26.9s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 28.1s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 3.0s |  |
| 4 | `DefineTextTest` | 4 | 4 | 3.3s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.8s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 3.4s |  |
| 8 | `NetStream-SquareTest` | 95 | 108 | 33.0s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 23.3s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 32.0s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 3.8s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 24.4s |  |
| 13 | `callFunction_test` | 6 | 11 | 3.8s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 30.4s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.7s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.6s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 4.5s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 19.9s |  |
| 19 | `init_action/InitActionTest2` | 24 | 30 | 19.8s |  |
| 20 | `key_event_test` | 5 | 6 | 19.9s |  |
| 21 | `loading/LoadBitmapTest` | 3 | 3 | 19.2s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 4.0s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 23.2s |  |
| 24 | `loop/loop_test6` | 1 | 12 | 24.3s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 3.5s |  |
| 26 | `masks_test` | 16 | 16 | 33.2s |  |
| 27 | `matrix_test` | 5 | 9 | 111.3s |  |
| 28 | `path_format_test` | 28 | 28 | 3.8s |  |
| 29 | `place_object_test` | 14 | 14 | 3.9s |  |
| 30 | `place_object_test2` | 22 | 23 | 23.3s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 0.9s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 0.9s |  |

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

**10 tests** with output mismatch, sorted by match rate (best first)

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
| 10 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
