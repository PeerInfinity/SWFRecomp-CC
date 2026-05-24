# Ruffle Test Results (Filtered)

**Date**: 2026-05-24 21:21 UTC

**Git SHA**: `3a04009d40`

**Run Duration**: 27m 42s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **67** (62.0%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **95** (88.0%) |
| Failing | 13 |
| Total expected lines | 5179 |
| Matching lines | 4021 (77.6%) |
| Mismatched lines | 1158 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**67 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 11.8s |  |
| 2 | `DefineEditTextTest` | 153 | 19.3s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 18.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 18.6s |  |
| 5 | `DepthLimitsTest` | 20 | 18.2s |  |
| 6 | `PlaceObject2Test` | 9 | 14.6s |  |
| 7 | `ResolveEventsTest` | 15 | 19.8s |  |
| 8 | `RollOverOutTest` | 5 | 19.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.4s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.9s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 18.7s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.4s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 18.6s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 18.5s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 19.7s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 19.4s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 20 | `attachExtImported` | 2 | 18.9s |  |
| 21 | `attachImported` | 2 | 0.4s |  |
| 22 | `attachMovieLoopingTest` | 41 | 18.7s |  |
| 23 | `attachMovieTest` | 12 | 18.9s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 18.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.2s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.5s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.4s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.5s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 18.3s |  |
| 34 | `event_handler_scope_test` | 16 | 0.3s |  |
| 35 | `frame_label_test` | 17 | 19.6s |  |
| 36 | `getTimer_test` | 8 | 19.5s |  |
| 37 | `get_frame_number_test` | 31 | 19.0s |  |
| 38 | `goto_frame_test` | 15 | 18.8s |  |
| 39 | `instanceNameTest` | 5 | 0.7s |  |
| 40 | `loading/LoadVarsTest` | 36 | 19.7s |  |
| 41 | `loop/loop_test` | 21 | 18.6s |  |
| 42 | `loop/loop_test2` | 15 | 18.8s |  |
| 43 | `loop/loop_test3` | 16 | 0.4s |  |
| 44 | `loop/loop_test4` | 22 | 18.4s |  |
| 45 | `loop/loop_test5` | 24 | 18.6s |  |
| 46 | `loop/loop_test8` | 38 | 0.6s |  |
| 47 | `loop/loop_test9` | 15 | 19.1s |  |
| 48 | `loop/simple_loop_test` | 0 | 19.1s |  |
| 49 | `masks_test2` | 10 | 19.4s |  |
| 50 | `morph_test1` | 0 | 19.0s |  |
| 51 | `move_object_test` | 11 | 19.2s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 19.2s |  |
| 53 | `new_child_in_unload_test` | 11 | 19.1s |  |
| 54 | `place_and_remove_object_insane_test` | 22 | 18.2s |  |
| 55 | `place_and_remove_object_test` | 13 | 18.2s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 19.5s |  |
| 57 | `register_class/registerClassTest` | 51 | 19.0s |  |
| 58 | `replace_shapes1test` | 23 | 0.4s |  |
| 59 | `replace_sprites1test` | 21 | 18.3s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 18.2s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 18.3s |  |
| 62 | `runtime_vm_stack_test` | 9 | 18.0s |  |
| 63 | `shape_test` | 21 | 18.2s |  |
| 64 | `static_vs_dynamic1` | 17 | 17.9s |  |
| 65 | `static_vs_dynamic2` | 18 | 18.7s |  |
| 66 | `timeline_var_test` | 11 | 18.7s |  |
| 67 | `unload_movieclip_test1` | 6 | 18.5s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 12.2s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 12.0s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 11.8s |  |
| 4 | `DefineTextTest` | 4 | 4 | 18.7s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.4s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 18.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 14.7s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 21.2s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 18.6s |  |
| 10 | `callFunction_test` | 6 | 11 | 18.9s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 19.9s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.5s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.4s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 18.6s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 18.9s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 19.1s |  |
| 17 | `key_event_test` | 5 | 6 | 19.0s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 19.6s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 1.2s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 19.1s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 18.5s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 0.4s |  |
| 23 | `matrix_test` | 5 | 9 | 28.2s |  |
| 24 | `path_format_test` | 28 | 28 | 18.4s |  |
| 25 | `place_object_test` | 14 | 14 | 18.4s |  |
| 26 | `place_object_test2` | 22 | 23 | 18.1s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 18.6s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 18.5s |  |

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

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `action_order/action_execution_order_test5` | 44.1% | 26/59 | 59 | 35 |  |
| 4 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 5 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 6 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 7 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 8 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 9 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 10 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 11 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 12 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 13 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
