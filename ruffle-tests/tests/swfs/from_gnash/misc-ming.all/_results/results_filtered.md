# Ruffle Test Results (Filtered)

**Date**: 2026-06-17 20:12 UTC

**Git SHA**: `e86241173c`

**Run Duration**: 34m 45s

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
| Matching lines | 4012 (77.5%) |
| Mismatched lines | 1167 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 19.1s |  |
| 2 | `DefineEditTextTest` | 153 | 31.1s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.8s |  |
| 5 | `DepthLimitsTest` | 20 | 22.9s |  |
| 6 | `PlaceObject2Test` | 9 | 20.8s |  |
| 7 | `ResolveEventsTest` | 15 | 21.8s |  |
| 8 | `RollOverOutTest` | 5 | 21.6s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.9s |  |
| 10 | `Version4Loader` | 11 | 1.8s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.6s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.4s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.8s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 21.4s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 18.3s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 18.3s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 0.4s |  |
| 19 | `attachExtImported` | 2 | 22.6s |  |
| 20 | `attachImported` | 2 | 2.0s |  |
| 21 | `attachMovieLoopingTest` | 41 | 21.8s |  |
| 22 | `attachMovieTest` | 12 | 22.5s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 20.8s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 21.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.4s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.9s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 22.0s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 21.7s |  |
| 33 | `event_handler_scope_test` | 16 | 2.3s |  |
| 34 | `frame_label_test` | 17 | 21.5s |  |
| 35 | `getTimer_test` | 8 | 20.2s |  |
| 36 | `get_frame_number_test` | 31 | 22.5s |  |
| 37 | `goto_frame_test` | 15 | 20.7s |  |
| 38 | `instanceNameTest` | 5 | 1.9s |  |
| 39 | `loading/LoadVarsTest` | 36 | 24.6s |  |
| 40 | `loop/loop_test` | 21 | 21.0s |  |
| 41 | `loop/loop_test2` | 15 | 19.7s |  |
| 42 | `loop/loop_test3` | 16 | 1.9s |  |
| 43 | `loop/loop_test4` | 22 | 21.0s |  |
| 44 | `loop/loop_test5` | 24 | 20.6s |  |
| 45 | `loop/loop_test8` | 38 | 3.8s |  |
| 46 | `loop/loop_test9` | 15 | 20.6s |  |
| 47 | `loop/simple_loop_test` | 0 | 20.5s |  |
| 48 | `masks_test2` | 10 | 20.9s |  |
| 49 | `morph_test1` | 0 | 21.1s |  |
| 50 | `move_object_test` | 11 | 16.7s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 16.9s |  |
| 52 | `new_child_in_unload_test` | 11 | 16.9s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 22.1s |  |
| 54 | `place_and_remove_object_test` | 13 | 21.1s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 21.8s |  |
| 56 | `register_class/registerClassTest` | 51 | 25.0s |  |
| 57 | `replace_shapes1test` | 23 | 2.5s |  |
| 58 | `replace_sprites1test` | 21 | 21.3s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 20.8s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 20.9s |  |
| 61 | `runtime_vm_stack_test` | 9 | 21.4s |  |
| 62 | `shape_test` | 21 | 21.8s |  |
| 63 | `static_vs_dynamic1` | 17 | 20.4s |  |
| 64 | `static_vs_dynamic2` | 18 | 21.1s |  |
| 65 | `timeline_var_test` | 11 | 20.7s |  |
| 66 | `unload_movieclip_test1` | 6 | 20.2s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 19.2s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 19.1s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.6s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.2s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.1s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 30.3s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 22.6s |  |
| 10 | `callFunction_test` | 6 | 11 | 21.6s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 28.8s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.8s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.0s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.2s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.9s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 22.9s |  |
| 17 | `key_event_test` | 5 | 6 | 23.5s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 22.4s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 4.6s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 20.8s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 20.5s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 2.2s |  |
| 23 | `matrix_test` | 5 | 9 | 104.7s |  |
| 24 | `path_format_test` | 28 | 28 | 23.6s |  |
| 25 | `place_object_test` | 14 | 14 | 20.8s |  |
| 26 | `place_object_test2` | 22 | 23 | 20.8s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 22.4s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 21.1s |  |

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
