# Ruffle Test Results (Filtered)

**Date**: 2026-06-26 18:53 UTC

**Git SHA**: `1af043d3e7`

**Run Duration**: 31m 16s

**Filtered**: 2 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 105 |
| Passing | **62** (59.0%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **90** (85.7%) |
| Failing | 15 |
| Total expected lines | 5123 |
| Matching lines | 3951 (77.1%) |
| Mismatched lines | 1172 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 15 | 100.0% |

## Passing Tests

**62 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 25.3s |  |
| 2 | `DefineEditTextTest` | 153 | 12.3s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.2s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.3s |  |
| 5 | `DepthLimitsTest` | 20 | 22.6s |  |
| 6 | `PlaceObject2Test` | 9 | 17.1s |  |
| 7 | `ResolveEventsTest` | 15 | 22.2s |  |
| 8 | `RollOverOutTest` | 5 | 22.2s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.6s |  |
| 10 | `Version4Loader` | 11 | 2.5s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.8s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 18.1s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 2.6s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 22.3s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 19.7s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 20.2s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.1s |  |
| 19 | `attachExtImported` | 2 | 22.3s |  |
| 20 | `attachImported` | 2 | 2.7s |  |
| 21 | `attachMovieLoopingTest` | 41 | 21.5s |  |
| 22 | `attachMovieTest` | 12 | 22.4s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 3.0s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 23.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 21.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.8s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 22.6s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 22.9s |  |
| 33 | `event_handler_scope_test` | 16 | 3.2s |  |
| 34 | `goto_frame_test` | 15 | 21.9s |  |
| 35 | `instanceNameTest` | 5 | 2.3s |  |
| 36 | `loading/LoadVarsTest` | 36 | 25.7s |  |
| 37 | `loop/loop_test` | 21 | 21.1s |  |
| 38 | `loop/loop_test2` | 15 | 20.9s |  |
| 39 | `loop/loop_test3` | 16 | 2.6s |  |
| 40 | `loop/loop_test4` | 22 | 3.7s |  |
| 41 | `loop/loop_test5` | 24 | 3.7s |  |
| 42 | `loop/loop_test8` | 38 | 5.3s |  |
| 43 | `loop/loop_test9` | 15 | 23.1s |  |
| 44 | `loop/simple_loop_test` | 0 | 28.1s |  |
| 45 | `masks_test2` | 10 | 21.8s |  |
| 46 | `morph_test1` | 0 | 25.3s |  |
| 47 | `move_object_test` | 11 | 22.1s |  |
| 48 | `multi_doactions_and_goto_frame_test` | 6 | 22.0s |  |
| 49 | `new_child_in_unload_test` | 11 | 2.8s |  |
| 50 | `place_and_remove_object_test` | 13 | 21.4s |  |
| 51 | `register_class/RegisterClassTest3` | 12 | 3.2s |  |
| 52 | `register_class/registerClassTest` | 51 | 25.5s |  |
| 53 | `replace_shapes1test` | 23 | 3.1s |  |
| 54 | `replace_sprites1test` | 21 | 22.9s |  |
| 55 | `reverse_execute_PlaceObject2_test1` | 8 | 2.9s |  |
| 56 | `reverse_execute_PlaceObject2_test2` | 10 | 22.4s |  |
| 57 | `runtime_vm_stack_test` | 9 | 20.0s |  |
| 58 | `shape_test` | 21 | 22.4s |  |
| 59 | `static_vs_dynamic1` | 17 | 19.8s |  |
| 60 | `static_vs_dynamic2` | 18 | 23.0s |  |
| 61 | `timeline_var_test` | 11 | 22.3s |  |
| 62 | `unload_movieclip_test1` | 6 | 21.9s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 26.0s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 26.7s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.7s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.6s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.9s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 25.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 2.5s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 30.4s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 4.0s |  |
| 10 | `callFunction_test` | 6 | 11 | 23.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 31.2s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.9s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.9s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 4.5s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 21.5s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 23.0s |  |
| 17 | `key_event_test` | 5 | 6 | 24.9s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 23.6s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 5.5s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 21.9s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 3.5s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.0s |  |
| 23 | `matrix_test` | 5 | 9 | 103.8s |  |
| 24 | `path_format_test` | 28 | 28 | 24.0s |  |
| 25 | `place_object_test` | 14 | 14 | 24.2s |  |
| 26 | `place_object_test2` | 22 | 23 | 21.8s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 22.7s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 21.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17 | 22 | 5 |  |

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
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
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
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 15 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
