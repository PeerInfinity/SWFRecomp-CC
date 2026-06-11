# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-11 20:31 UTC

**Git SHA**: `7da45e2900`

**Run Duration**: 28m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **67** (60.9%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **95** (86.4%) |
| Failing | 15 |
| Total expected lines | 5239 |
| Matching lines | 4033 (77.0%) |
| Mismatched lines | 1206 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 15 | 100.0% |

## Passing Tests

**67 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.9s |  |
| 2 | `DefineEditTextTest` | 153 | 19.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 18.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 18.9s |  |
| 5 | `DepthLimitsTest` | 20 | 18.3s |  |
| 6 | `PlaceObject2Test` | 9 | 19.1s |  |
| 7 | `ResolveEventsTest` | 15 | 18.6s |  |
| 8 | `RollOverOutTest` | 5 | 18.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.4s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.5s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.7s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.5s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.4s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 18.5s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 18.4s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 19 | `attachExtImported` | 2 | 19.5s |  |
| 20 | `attachImported` | 2 | 0.4s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.8s |  |
| 22 | `attachMovieTest` | 12 | 19.4s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 17.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 15.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.6s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.2s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 19.3s |  |
| 33 | `event_handler_scope_test` | 16 | 0.3s |  |
| 34 | `frame_label_test` | 17 | 18.2s |  |
| 35 | `getTimer_test` | 8 | 18.1s |  |
| 36 | `get_frame_number_test` | 31 | 18.3s |  |
| 37 | `goto_frame_test` | 15 | 18.3s |  |
| 38 | `instanceNameTest` | 5 | 0.3s |  |
| 39 | `loading/LoadVarsTest` | 36 | 19.6s |  |
| 40 | `loop/loop_test` | 21 | 19.1s |  |
| 41 | `loop/loop_test2` | 15 | 19.5s |  |
| 42 | `loop/loop_test3` | 16 | 0.3s |  |
| 43 | `loop/loop_test4` | 22 | 19.0s |  |
| 44 | `loop/loop_test5` | 24 | 18.9s |  |
| 45 | `loop/loop_test8` | 38 | 0.4s |  |
| 46 | `loop/loop_test9` | 15 | 19.9s |  |
| 47 | `loop/simple_loop_test` | 0 | 19.9s |  |
| 48 | `masks_test2` | 10 | 18.6s |  |
| 49 | `morph_test1` | 0 | 18.6s |  |
| 50 | `move_object_test` | 11 | 19.4s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 19.0s |  |
| 52 | `new_child_in_unload_test` | 11 | 19.0s |  |
| 53 | `opcode_guard_test` | 18 | 20.0s |  |
| 54 | `place_and_remove_object_insane_test` | 22 | 20.2s |  |
| 55 | `place_and_remove_object_test` | 13 | 20.2s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 18.5s |  |
| 57 | `register_class/registerClassTest` | 51 | 18.5s |  |
| 58 | `replace_shapes1test` | 23 | 0.4s |  |
| 59 | `replace_sprites1test` | 21 | 18.9s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 18.9s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 19.2s |  |
| 62 | `runtime_vm_stack_test` | 9 | 21.7s |  |
| 63 | `shape_test` | 21 | 21.4s |  |
| 64 | `static_vs_dynamic1` | 17 | 21.4s |  |
| 65 | `static_vs_dynamic2` | 18 | 19.2s |  |
| 66 | `timeline_var_test` | 11 | 19.4s |  |
| 67 | `unload_movieclip_test1` | 6 | 19.2s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.0s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 18.9s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 18.7s |  |
| 4 | `DefineTextTest` | 4 | 4 | 18.6s |  |
| 5 | `DragDropTest` | 4 | 4 | 0.3s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 18.8s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 19.3s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 19.5s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 19.1s |  |
| 10 | `callFunction_test` | 6 | 11 | 17.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 18.0s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 14.9s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 19.3s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 19.9s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 20.9s |  |
| 17 | `key_event_test` | 5 | 6 | 20.4s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 19.1s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 0.7s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 19.4s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 18.7s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 23 | `matrix_test` | 5 | 9 | 22.6s |  |
| 24 | `path_format_test` | 28 | 28 | 20.5s |  |
| 25 | `place_object_test` | 14 | 14 | 20.5s |  |
| 26 | `place_object_test2` | 22 | 23 | 20.4s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 19.1s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 19.1s |  |

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

**15 tests** with output mismatch, sorted by match rate (best first)

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
| 13 | `register_class/RegisterClassTest4` | 4.7% | 3/64 | 64 | 42 |  |
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 15 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
