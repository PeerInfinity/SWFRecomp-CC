# Ruffle Test Results (Filtered)

**Date**: 2026-05-29 19:16 UTC

**Git SHA**: `b53e09d3d7`

**Run Duration**: 28m 56s

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
| Matching lines | 4008 (77.4%) |
| Mismatched lines | 1171 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.0s |  |
| 2 | `DefineEditTextTest` | 153 | 20.2s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 19.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.4s |  |
| 5 | `DepthLimitsTest` | 20 | 18.3s |  |
| 6 | `PlaceObject2Test` | 9 | 18.6s |  |
| 7 | `ResolveEventsTest` | 15 | 18.6s |  |
| 8 | `RollOverOutTest` | 5 | 18.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.4s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 19.9s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.2s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 18.7s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 18.9s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 19 | `attachExtImported` | 2 | 19.6s |  |
| 20 | `attachImported` | 2 | 0.4s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.4s |  |
| 22 | `attachMovieTest` | 12 | 19.4s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 18.8s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.5s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 19.3s |  |
| 33 | `event_handler_scope_test` | 16 | 0.3s |  |
| 34 | `frame_label_test` | 17 | 19.1s |  |
| 35 | `getTimer_test` | 8 | 19.3s |  |
| 36 | `get_frame_number_test` | 31 | 19.0s |  |
| 37 | `goto_frame_test` | 15 | 19.0s |  |
| 38 | `instanceNameTest` | 5 | 0.3s |  |
| 39 | `loading/LoadVarsTest` | 36 | 21.0s |  |
| 40 | `loop/loop_test` | 21 | 20.4s |  |
| 41 | `loop/loop_test2` | 15 | 18.7s |  |
| 42 | `loop/loop_test3` | 16 | 0.3s |  |
| 43 | `loop/loop_test4` | 22 | 18.8s |  |
| 44 | `loop/loop_test5` | 24 | 19.4s |  |
| 45 | `loop/loop_test8` | 38 | 0.4s |  |
| 46 | `loop/loop_test9` | 15 | 18.6s |  |
| 47 | `loop/simple_loop_test` | 0 | 18.8s |  |
| 48 | `masks_test2` | 10 | 19.2s |  |
| 49 | `morph_test1` | 0 | 18.9s |  |
| 50 | `move_object_test` | 11 | 18.6s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 18.6s |  |
| 52 | `new_child_in_unload_test` | 11 | 18.6s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 20.7s |  |
| 54 | `place_and_remove_object_test` | 13 | 18.6s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 18.8s |  |
| 56 | `register_class/registerClassTest` | 51 | 18.9s |  |
| 57 | `replace_shapes1test` | 23 | 0.4s |  |
| 58 | `replace_sprites1test` | 21 | 18.4s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 18.3s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 18.3s |  |
| 61 | `runtime_vm_stack_test` | 9 | 19.3s |  |
| 62 | `shape_test` | 21 | 19.4s |  |
| 63 | `static_vs_dynamic1` | 17 | 19.6s |  |
| 64 | `static_vs_dynamic2` | 18 | 19.2s |  |
| 65 | `timeline_var_test` | 11 | 18.9s |  |
| 66 | `unload_movieclip_test1` | 6 | 19.2s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 20.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 19.9s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 19.7s |  |
| 4 | `DefineTextTest` | 4 | 4 | 18.4s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.4s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 18.5s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 18.6s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 19.4s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 19.3s |  |
| 10 | `callFunction_test` | 6 | 11 | 18.8s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 19.5s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.9s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 19.5s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 19.8s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 19.8s |  |
| 17 | `key_event_test` | 5 | 6 | 20.0s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 20.0s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 0.6s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 18.8s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 19.6s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 23 | `matrix_test` | 5 | 9 | 23.8s |  |
| 24 | `path_format_test` | 28 | 28 | 20.2s |  |
| 25 | `place_object_test` | 14 | 14 | 19.1s |  |
| 26 | `place_object_test2` | 22 | 23 | 18.6s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 19.9s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 19.9s |  |

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
| 11 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 12 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
