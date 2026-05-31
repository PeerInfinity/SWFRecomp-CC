# Ruffle Test Results (Filtered)

**Date**: 2026-05-31 05:18 UTC

**Git SHA**: `b1bf96efe6`

**Run Duration**: 26m 10s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **66** (61.1%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **94** (87.0%) |
| Failing | 14 |
| Total expected lines | 5179 |
| Matching lines | 4005 (77.3%) |
| Mismatched lines | 1174 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.7s |  |
| 2 | `DefineEditTextTest` | 153 | 30.8s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.6s |  |
| 5 | `DepthLimitsTest` | 20 | 22.1s |  |
| 6 | `PlaceObject2Test` | 9 | 19.7s |  |
| 7 | `ResolveEventsTest` | 15 | 0.3s |  |
| 8 | `RollOverOutTest` | 5 | 0.3s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.8s |  |
| 10 | `Version4Loader` | 11 | 1.6s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.6s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 21.0s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.2s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 0.3s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 0.3s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.2s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 0.2s |  |
| 19 | `attachExtImported` | 2 | 21.3s |  |
| 20 | `attachImported` | 2 | 1.7s |  |
| 21 | `attachMovieLoopingTest` | 41 | 20.4s |  |
| 22 | `attachMovieTest` | 12 | 21.0s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 0.2s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.7s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 21.4s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 21.6s |  |
| 33 | `event_handler_scope_test` | 16 | 2.2s |  |
| 34 | `frame_label_test` | 17 | 21.8s |  |
| 35 | `getTimer_test` | 8 | 20.3s |  |
| 36 | `get_frame_number_test` | 31 | 23.0s |  |
| 37 | `goto_frame_test` | 15 | 21.1s |  |
| 38 | `instanceNameTest` | 5 | 1.5s |  |
| 39 | `loading/LoadVarsTest` | 36 | 0.5s |  |
| 40 | `loop/loop_test` | 21 | 0.2s |  |
| 41 | `loop/loop_test2` | 15 | 15.7s |  |
| 42 | `loop/loop_test3` | 16 | 1.3s |  |
| 43 | `loop/loop_test4` | 22 | 16.5s |  |
| 44 | `loop/loop_test5` | 24 | 22.2s |  |
| 45 | `loop/loop_test8` | 38 | 4.2s |  |
| 46 | `loop/loop_test9` | 15 | 20.2s |  |
| 47 | `loop/simple_loop_test` | 0 | 19.6s |  |
| 48 | `masks_test2` | 10 | 0.2s |  |
| 49 | `morph_test1` | 0 | 0.2s |  |
| 50 | `move_object_test` | 11 | 21.1s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 21.1s |  |
| 52 | `new_child_in_unload_test` | 11 | 21.2s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 20.2s |  |
| 54 | `place_and_remove_object_test` | 13 | 19.8s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 20.7s |  |
| 56 | `register_class/registerClassTest` | 51 | 22.9s |  |
| 57 | `replace_shapes1test` | 23 | 2.4s |  |
| 58 | `replace_sprites1test` | 21 | 22.0s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 20.9s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 21.1s |  |
| 61 | `runtime_vm_stack_test` | 9 | 21.4s |  |
| 62 | `shape_test` | 21 | 22.6s |  |
| 63 | `static_vs_dynamic1` | 17 | 20.9s |  |
| 64 | `static_vs_dynamic2` | 18 | 0.2s |  |
| 65 | `timeline_var_test` | 11 | 0.2s |  |
| 66 | `unload_movieclip_test1` | 6 | 0.2s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 23.8s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 24.8s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 19.9s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.2s |  |
| 5 | `DragDropTest` | 12 | 12 | 2.9s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 25.3s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.1s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 0.7s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 21.1s |  |
| 10 | `callFunction_test` | 6 | 11 | 0.3s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 0.6s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.0s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.9s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.0s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 20.4s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 21.6s |  |
| 17 | `key_event_test` | 5 | 6 | 21.4s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 0.3s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 0.6s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 16.4s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 22.0s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 2.3s |  |
| 23 | `matrix_test` | 5 | 9 | 3.2s |  |
| 24 | `path_format_test` | 28 | 28 | 22.2s |  |
| 25 | `place_object_test` | 14 | 14 | 20.1s |  |
| 26 | `place_object_test2` | 22 | 23 | 20.1s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 21.9s |  |
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
| 3 | `action_order/action_execution_order_test5` | 47.3% | 26/55 | 55 | 35 |  |
| 4 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 5 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 6 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 7 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 8 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 9 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 10 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 11 | `action_order/ActionOrderTest4` | 7.6% | 9/118 | 118 | 64 |  |
| 12 | `action_order/ActionOrderTest3` | 5.1% | 4/78 | 78 | 62 |  |
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
