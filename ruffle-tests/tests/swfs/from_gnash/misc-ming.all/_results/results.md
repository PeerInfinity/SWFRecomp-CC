# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-10 17:22 UTC

**Git SHA**: `704a9cbbf2`

**Run Duration**: 33m 26s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **97** (87.4%) |
| Failing | 14 |
| Total expected lines | 5248 |
| Matching lines | 4054 (77.2%) |
| Mismatched lines | 1194 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.3s |  |
| 2 | `DefineEditTextTest` | 153 | 29.3s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.4s |  |
| 5 | `DepthLimitsTest` | 20 | 19.7s |  |
| 6 | `PlaceObject2Test` | 9 | 21.9s |  |
| 7 | `ResolveEventsTest` | 15 | 21.2s |  |
| 8 | `RollOverOutTest` | 5 | 21.3s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.6s |  |
| 10 | `Version4Loader` | 11 | 1.6s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.2s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 14.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 14.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.6s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.8s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 20.5s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 20.9s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.7s |  |
| 20 | `attachExtImported` | 2 | 21.9s |  |
| 21 | `attachImported` | 2 | 1.9s |  |
| 22 | `attachMovieLoopingTest` | 41 | 21.0s |  |
| 23 | `attachMovieTest` | 12 | 21.8s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 12.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 13.0s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.8s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.8s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.7s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 21.1s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 21.1s |  |
| 34 | `event_handler_scope_test` | 16 | 2.3s |  |
| 35 | `frame_label_test` | 17 | 22.2s |  |
| 36 | `getTimer_test` | 8 | 21.1s |  |
| 37 | `get_frame_number_test` | 31 | 23.5s |  |
| 38 | `gotoFrame2Test` | 9 | 20.9s |  |
| 39 | `goto_frame_test` | 15 | 21.6s |  |
| 40 | `instanceNameTest` | 5 | 1.8s |  |
| 41 | `loading/LoadVarsTest` | 36 | 24.5s |  |
| 42 | `loop/loop_test` | 21 | 20.3s |  |
| 43 | `loop/loop_test2` | 15 | 20.2s |  |
| 44 | `loop/loop_test3` | 16 | 1.9s |  |
| 45 | `loop/loop_test4` | 22 | 21.6s |  |
| 46 | `loop/loop_test5` | 24 | 3.1s |  |
| 47 | `loop/loop_test8` | 38 | 22.0s |  |
| 48 | `loop/loop_test9` | 15 | 20.1s |  |
| 49 | `loop/simple_loop_test` | 0 | 19.6s |  |
| 50 | `masks_test2` | 10 | 20.8s |  |
| 51 | `morph_test1` | 0 | 20.7s |  |
| 52 | `move_object_test` | 11 | 20.4s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 20.4s |  |
| 54 | `new_child_in_unload_test` | 11 | 20.6s |  |
| 55 | `opcode_guard_test` | 18 | 19.0s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 19.1s |  |
| 57 | `place_and_remove_object_test` | 13 | 21.2s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 16.6s |  |
| 59 | `register_class/registerClassTest` | 51 | 18.9s |  |
| 60 | `replace_shapes1test` | 23 | 2.5s |  |
| 61 | `replace_sprites1test` | 21 | 21.1s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 20.6s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 21.1s |  |
| 64 | `runtime_vm_stack_test` | 9 | 18.8s |  |
| 65 | `shape_test` | 21 | 19.2s |  |
| 66 | `static_vs_dynamic1` | 17 | 19.1s |  |
| 67 | `static_vs_dynamic2` | 18 | 17.5s |  |
| 68 | `timeline_var_test` | 11 | 17.1s |  |
| 69 | `unload_movieclip_test1` | 6 | 16.9s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 24.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 25.4s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 20.4s |  |
| 4 | `DefineTextTest` | 4 | 4 | 20.1s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.6s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 21.4s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.6s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 29.1s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 21.6s |  |
| 10 | `callFunction_test` | 6 | 11 | 13.6s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 17.9s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.1s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.0s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 21.6s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.3s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 22.2s |  |
| 17 | `key_event_test` | 5 | 6 | 22.5s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 22.3s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 4.6s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 21.2s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 21.5s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 2.4s |  |
| 23 | `matrix_test` | 5 | 9 | 102.8s |  |
| 24 | `path_format_test` | 28 | 28 | 19.3s |  |
| 25 | `place_object_test` | 14 | 14 | 21.7s |  |
| 26 | `place_object_test2` | 22 | 23 | 21.5s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 22.0s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 20.7s |  |

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

**14 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 4 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 5 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 6 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 7 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 8 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 9 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 10 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 11 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 12 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
