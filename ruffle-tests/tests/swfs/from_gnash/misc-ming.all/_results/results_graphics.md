# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-24 20:26 UTC

**Git SHA**: `d36c8da2b2`

**Run Duration**: 29m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **68** (63.0%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **94** (87.0%) |
| Failing | 14 |
| Total expected lines | 5204 |
| Matching lines | 4040 (77.6%) |
| Mismatched lines | 1164 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**68 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 1.7s |  |
| 2 | `DefineEditTextTest` | 153 | 31.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.8s |  |
| 5 | `DepthLimitsTest` | 20 | 22.3s |  |
| 6 | `PlaceObject2Test` | 9 | 3.0s |  |
| 7 | `ResolveEventsTest` | 15 | 4.0s |  |
| 8 | `RollOverOutTest` | 5 | 22.6s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.7s |  |
| 10 | `Version4Loader` | 11 | 2.6s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.4s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 16.6s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 16.6s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 22.0s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.6s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 20.9s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 21.2s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.5s |  |
| 20 | `attachExtImported` | 2 | 22.2s |  |
| 21 | `attachImported` | 2 | 2.8s |  |
| 22 | `attachMovieLoopingTest` | 41 | 21.6s |  |
| 23 | `attachMovieTest` | 12 | 21.6s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 15.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 1.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.8s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.1s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.5s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.7s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 22.0s |  |
| 34 | `event_handler_scope_test` | 16 | 3.1s |  |
| 35 | `frame_label_test` | 17 | 16.4s |  |
| 36 | `getTimer_test` | 8 | 15.3s |  |
| 37 | `get_frame_number_test` | 31 | 3.9s |  |
| 38 | `gotoFrame2Test` | 9 | 15.2s |  |
| 39 | `goto_frame_test` | 15 | 21.8s |  |
| 40 | `instanceNameTest` | 5 | 2.7s |  |
| 41 | `loading/LoadVarsTest` | 36 | 25.4s |  |
| 42 | `loop/loop_test` | 21 | 21.7s |  |
| 43 | `loop/loop_test2` | 15 | 21.5s |  |
| 44 | `loop/loop_test3` | 16 | 2.8s |  |
| 45 | `loop/loop_test4` | 22 | 21.9s |  |
| 46 | `loop/loop_test5` | 24 | 4.0s |  |
| 47 | `loop/loop_test8` | 38 | 24.7s |  |
| 48 | `loop/loop_test9` | 15 | 22.3s |  |
| 49 | `loop/simple_loop_test` | 0 | 25.8s |  |
| 50 | `masks_test2` | 10 | 22.6s |  |
| 51 | `morph_test1` | 0 | 24.8s |  |
| 52 | `move_object_test` | 11 | 2.7s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 20.4s |  |
| 54 | `new_child_in_unload_test` | 11 | 20.6s |  |
| 55 | `opcode_guard_test` | 18 | 21.2s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 21.0s |  |
| 57 | `register_class/RegisterClassTest3` | 12 | 23.6s |  |
| 58 | `register_class/registerClassTest` | 51 | 25.8s |  |
| 59 | `replace_shapes1test` | 23 | 3.2s |  |
| 60 | `replace_sprites1test` | 21 | 21.6s |  |
| 61 | `reverse_execute_PlaceObject2_test1` | 8 | 21.0s |  |
| 62 | `reverse_execute_PlaceObject2_test2` | 10 | 3.1s |  |
| 63 | `runtime_vm_stack_test` | 9 | 22.4s |  |
| 64 | `shape_test` | 21 | 24.4s |  |
| 65 | `static_vs_dynamic1` | 17 | 22.3s |  |
| 66 | `static_vs_dynamic2` | 18 | 24.0s |  |
| 67 | `timeline_var_test` | 11 | 22.5s |  |
| 68 | `unload_movieclip_test1` | 6 | 22.5s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 1.2s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 1.3s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 0.9s |  |
| 4 | `DefineTextTest` | 4 | 4 | 22.2s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.9s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 7.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.3s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 30.4s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 22.4s |  |
| 10 | `callFunction_test` | 6 | 11 | 16.1s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 20.9s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 3.1s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.0s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.4s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.6s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 4.7s |  |
| 17 | `key_event_test` | 5 | 6 | 23.9s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 4.2s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 5.5s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 22.7s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 22.6s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.3s |  |
| 23 | `matrix_test` | 5 | 9 | 110.6s |  |
| 24 | `path_format_test` | 28 | 28 | 23.1s |  |
| 25 | `register_class/registerClassTest2` | 8 | 28 | 22.3s |  |
| 26 | `replace_buttons1test` | 3 | 3 | 20.9s |  |

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
| 9 | `register_class/RegisterClassTest4` | 10.5% | 6/57 | 57 | 42 |  |
| 10 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 11 | `action_order/ActionOrderTest4` | 9.5% | 10/105 | 105 | 64 |  |
| 12 | `action_order/ActionOrderTest3` | 5.5% | 4/73 | 73 | 62 |  |
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
