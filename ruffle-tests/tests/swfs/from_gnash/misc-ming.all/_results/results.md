# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-31 17:58 UTC

**Git SHA**: `d5b8dce255`

**Run Duration**: 33m 52s

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
| 1 | `BeginBitmapFill` | 1 | 20.4s |  |
| 2 | `DefineEditTextTest` | 153 | 31.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.4s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.2s |  |
| 5 | `DepthLimitsTest` | 20 | 21.3s |  |
| 6 | `PlaceObject2Test` | 9 | 20.1s |  |
| 7 | `ResolveEventsTest` | 15 | 21.5s |  |
| 8 | `RollOverOutTest` | 5 | 21.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 10 | `Version4Loader` | 11 | 1.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.3s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 19.6s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 19.5s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.5s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 12.2s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 12.5s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 0.9s |  |
| 19 | `attachExtImported` | 2 | 20.5s |  |
| 20 | `attachImported` | 2 | 1.4s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.5s |  |
| 22 | `attachMovieTest` | 12 | 20.1s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 20.1s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.0s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.8s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.4s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.3s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 20.7s |  |
| 33 | `event_handler_scope_test` | 16 | 2.1s |  |
| 34 | `frame_label_test` | 17 | 21.9s |  |
| 35 | `getTimer_test` | 8 | 20.5s |  |
| 36 | `get_frame_number_test` | 31 | 23.0s |  |
| 37 | `goto_frame_test` | 15 | 20.6s |  |
| 38 | `instanceNameTest` | 5 | 1.4s |  |
| 39 | `loading/LoadVarsTest` | 36 | 24.0s |  |
| 40 | `loop/loop_test` | 21 | 20.4s |  |
| 41 | `loop/loop_test2` | 15 | 19.9s |  |
| 42 | `loop/loop_test3` | 16 | 1.4s |  |
| 43 | `loop/loop_test4` | 22 | 20.7s |  |
| 44 | `loop/loop_test5` | 24 | 21.3s |  |
| 45 | `loop/loop_test8` | 38 | 3.6s |  |
| 46 | `loop/loop_test9` | 15 | 19.8s |  |
| 47 | `loop/simple_loop_test` | 0 | 19.6s |  |
| 48 | `masks_test2` | 10 | 22.6s |  |
| 49 | `morph_test1` | 0 | 21.9s |  |
| 50 | `move_object_test` | 11 | 20.1s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 20.2s |  |
| 52 | `new_child_in_unload_test` | 11 | 20.2s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 19.1s |  |
| 54 | `place_and_remove_object_test` | 13 | 21.5s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 20.7s |  |
| 56 | `register_class/registerClassTest` | 51 | 22.8s |  |
| 57 | `replace_shapes1test` | 23 | 1.9s |  |
| 58 | `replace_sprites1test` | 21 | 20.9s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 20.1s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 20.6s |  |
| 61 | `runtime_vm_stack_test` | 9 | 20.2s |  |
| 62 | `shape_test` | 21 | 21.3s |  |
| 63 | `static_vs_dynamic1` | 17 | 19.9s |  |
| 64 | `static_vs_dynamic2` | 18 | 20.7s |  |
| 65 | `timeline_var_test` | 11 | 20.6s |  |
| 66 | `unload_movieclip_test1` | 6 | 19.8s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 23.6s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 24.7s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 19.4s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.4s |  |
| 5 | `DragDropTest` | 12 | 12 | 2.5s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 24.3s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.6s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 30.3s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 21.5s |  |
| 10 | `callFunction_test` | 6 | 11 | 20.8s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.3s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.4s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.6s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 20.9s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 20.6s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 21.8s |  |
| 17 | `key_event_test` | 5 | 6 | 22.1s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 21.6s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 4.2s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 20.9s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 21.1s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 1.9s |  |
| 23 | `matrix_test` | 5 | 9 | 108.8s |  |
| 24 | `path_format_test` | 28 | 28 | 20.8s |  |
| 25 | `place_object_test` | 14 | 14 | 22.2s |  |
| 26 | `place_object_test2` | 22 | 23 | 22.4s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 17.9s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 16.4s |  |

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
