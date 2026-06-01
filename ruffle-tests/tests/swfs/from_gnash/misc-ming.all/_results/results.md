# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-01 22:05 UTC

**Git SHA**: `6e7cf24ea5`

**Run Duration**: 28m 44s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **66** (60.0%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **94** (85.5%) |
| Failing | 16 |
| Total expected lines | 5239 |
| Matching lines | 4019 (76.7%) |
| Mismatched lines | 1220 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 16 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.9s |  |
| 2 | `DefineEditTextTest` | 153 | 19.5s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 19.4s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.2s |  |
| 5 | `DepthLimitsTest` | 20 | 19.4s |  |
| 6 | `PlaceObject2Test` | 9 | 18.7s |  |
| 7 | `ResolveEventsTest` | 15 | 19.5s |  |
| 8 | `RollOverOutTest` | 5 | 19.5s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.5s |  |
| 10 | `Version4Loader` | 11 | 0.6s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.8s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 16.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 15.3s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.9s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 19.1s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 19.1s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 0.5s |  |
| 19 | `attachExtImported` | 2 | 21.0s |  |
| 20 | `attachImported` | 2 | 0.5s |  |
| 21 | `attachMovieLoopingTest` | 41 | 20.1s |  |
| 22 | `attachMovieTest` | 12 | 20.4s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 19.0s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.5s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.7s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 20.6s |  |
| 33 | `event_handler_scope_test` | 16 | 0.6s |  |
| 34 | `frame_label_test` | 17 | 18.4s |  |
| 35 | `getTimer_test` | 8 | 18.5s |  |
| 36 | `get_frame_number_test` | 31 | 18.5s |  |
| 37 | `goto_frame_test` | 15 | 18.6s |  |
| 38 | `instanceNameTest` | 5 | 0.5s |  |
| 39 | `loading/LoadVarsTest` | 36 | 19.0s |  |
| 40 | `loop/loop_test` | 21 | 18.5s |  |
| 41 | `loop/loop_test2` | 15 | 19.6s |  |
| 42 | `loop/loop_test3` | 16 | 0.6s |  |
| 43 | `loop/loop_test4` | 22 | 19.6s |  |
| 44 | `loop/loop_test5` | 24 | 19.4s |  |
| 45 | `loop/loop_test8` | 38 | 0.7s |  |
| 46 | `loop/loop_test9` | 15 | 19.0s |  |
| 47 | `loop/simple_loop_test` | 0 | 19.5s |  |
| 48 | `masks_test2` | 10 | 20.1s |  |
| 49 | `morph_test1` | 0 | 20.0s |  |
| 50 | `move_object_test` | 11 | 18.9s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 18.9s |  |
| 52 | `new_child_in_unload_test` | 11 | 18.9s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 18.3s |  |
| 54 | `place_and_remove_object_test` | 13 | 20.1s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 18.7s |  |
| 56 | `register_class/registerClassTest` | 51 | 18.8s |  |
| 57 | `replace_shapes1test` | 23 | 0.5s |  |
| 58 | `replace_sprites1test` | 21 | 19.4s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 19.4s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 19.6s |  |
| 61 | `runtime_vm_stack_test` | 9 | 19.6s |  |
| 62 | `shape_test` | 21 | 19.3s |  |
| 63 | `static_vs_dynamic1` | 17 | 20.3s |  |
| 64 | `static_vs_dynamic2` | 18 | 18.9s |  |
| 65 | `timeline_var_test` | 11 | 19.0s |  |
| 66 | `unload_movieclip_test1` | 6 | 18.9s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 19.0s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 18.9s |  |
| 4 | `DefineTextTest` | 4 | 4 | 18.8s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.6s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 20.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 18.4s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 20.2s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 19.7s |  |
| 10 | `callFunction_test` | 6 | 11 | 19.1s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 19.5s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.7s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.5s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 20.9s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 19.0s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 18.9s |  |
| 17 | `key_event_test` | 5 | 6 | 18.9s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 18.9s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 0.9s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 19.6s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 19.5s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 0.6s |  |
| 23 | `matrix_test` | 5 | 9 | 24.1s |  |
| 24 | `path_format_test` | 28 | 28 | 18.3s |  |
| 25 | `place_object_test` | 14 | 14 | 20.2s |  |
| 26 | `place_object_test2` | 22 | 23 | 20.1s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 19.4s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 19.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**16 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 4 | `action_order/action_execution_order_test5` | 47.3% | 26/55 | 55 | 35 |  |
| 5 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 6 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 7 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 8 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 9 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 10 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 11 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 7.6% | 9/118 | 118 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 5.1% | 4/78 | 78 | 62 |  |
| 14 | `register_class/RegisterClassTest4` | 4.7% | 3/64 | 64 | 42 |  |
| 15 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 16 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
