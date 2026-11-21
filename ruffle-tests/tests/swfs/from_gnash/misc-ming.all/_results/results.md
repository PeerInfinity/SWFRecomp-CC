# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 19:49 UTC

**Git SHA**: `c489b84d99`

**Run Duration**: 22m 28s

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
| 1 | `BeginBitmapFill` | 1 | 17.8s |  |
| 2 | `DefineEditTextTest` | 153 | 23.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 20.6s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 18.7s |  |
| 5 | `DepthLimitsTest` | 20 | 18.1s |  |
| 6 | `PlaceObject2Test` | 9 | 23.1s |  |
| 7 | `ResolveEventsTest` | 15 | 24.3s |  |
| 8 | `RollOverOutTest` | 5 | 3.2s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 10 | `Version4Loader` | 11 | 1.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 17.1s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.6s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 1.5s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 1.5s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.0s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 2.2s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 23.1s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.5s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 20 | `attachExtImported` | 2 | 2.2s |  |
| 21 | `attachImported` | 2 | 1.5s |  |
| 22 | `attachMovieLoopingTest` | 41 | 14.5s |  |
| 23 | `attachMovieTest` | 12 | 15.2s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 17.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 16.6s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.4s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.9s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.3s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 17.4s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 2.1s |  |
| 34 | `event_handler_scope_test` | 16 | 1.6s |  |
| 35 | `frame_label_test` | 17 | 2.5s |  |
| 36 | `getTimer_test` | 8 | 1.6s |  |
| 37 | `get_frame_number_test` | 31 | 19.1s |  |
| 38 | `gotoFrame2Test` | 9 | 1.4s |  |
| 39 | `goto_frame_test` | 15 | 15.0s |  |
| 40 | `instanceNameTest` | 5 | 1.4s |  |
| 41 | `loading/LoadVarsTest` | 36 | 19.7s |  |
| 42 | `loop/loop_test` | 21 | 17.3s |  |
| 43 | `loop/loop_test2` | 15 | 1.4s |  |
| 44 | `loop/loop_test3` | 16 | 1.4s |  |
| 45 | `loop/loop_test4` | 22 | 17.5s |  |
| 46 | `loop/loop_test5` | 24 | 2.1s |  |
| 47 | `loop/loop_test8` | 38 | 24.5s |  |
| 48 | `loop/loop_test9` | 15 | 22.1s |  |
| 49 | `loop/simple_loop_test` | 0 | 1.6s |  |
| 50 | `masks_test2` | 10 | 19.5s |  |
| 51 | `morph_test1` | 0 | 18.4s |  |
| 52 | `move_object_test` | 11 | 15.0s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 14.7s |  |
| 54 | `new_child_in_unload_test` | 11 | 1.5s |  |
| 55 | `opcode_guard_test` | 18 | 17.4s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 17.2s |  |
| 57 | `place_and_remove_object_test` | 13 | 17.1s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 1.9s |  |
| 59 | `register_class/registerClassTest` | 51 | 19.6s |  |
| 60 | `replace_shapes1test` | 23 | 2.1s |  |
| 61 | `replace_sprites1test` | 21 | 1.9s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 17.6s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 17.7s |  |
| 64 | `runtime_vm_stack_test` | 9 | 2.6s |  |
| 65 | `shape_test` | 21 | 19.0s |  |
| 66 | `static_vs_dynamic1` | 17 | 1.7s |  |
| 67 | `static_vs_dynamic2` | 18 | 14.7s |  |
| 68 | `timeline_var_test` | 11 | 15.2s |  |
| 69 | `unload_movieclip_test1` | 6 | 1.4s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.9s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 20.8s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 1.5s |  |
| 4 | `DefineTextTest` | 4 | 4 | 17.2s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.3s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 20.2s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 23.4s |  |
| 8 | `PrototypeEventListeners` | 23 | 23 | 2.3s |  |
| 9 | `TextSnapshotTest` | 81 | 90 | 33.2s |  |
| 10 | `action_order/action_execution_order_test` | 12 | 12 | 1.1s |  |
| 11 | `action_order/action_execution_order_test4` | 7 | 26 | 2.2s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 18.0s |  |
| 13 | `callFunction_test` | 6 | 11 | 18.3s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.1s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 17.8s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.8s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 17.8s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 15.2s |  |
| 19 | `init_action/InitActionTest2` | 24 | 30 | 15.8s |  |
| 20 | `key_event_test` | 5 | 6 | 18.4s |  |
| 21 | `loading/LoadBitmapTest` | 3 | 3 | 18.1s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 2.9s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 2.0s |  |
| 24 | `loop/loop_test6` | 11 | 12 | 2.0s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 1.6s |  |
| 26 | `masks_test` | 16 | 16 | 33.1s |  |
| 27 | `matrix_test` | 5 | 9 | 105.0s |  |
| 28 | `path_format_test` | 28 | 28 | 3.1s |  |
| 29 | `place_object_test` | 14 | 14 | 1.7s |  |
| 30 | `place_object_test2` | 22 | 23 | 17.2s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 19.5s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 2.2s |  |

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
