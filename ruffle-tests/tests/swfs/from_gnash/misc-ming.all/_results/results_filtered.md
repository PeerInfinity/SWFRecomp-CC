# Ruffle Test Results (Filtered)

**Date**: 2026-05-15 23:13 UTC

**Git SHA**: `116eb4ccf6`

**Run Duration**: 27m 23s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **64** (59.3%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **88** (81.5%) |
| Failing | 20 |
| Total expected lines | 5179 |
| Matching lines | 3962 (76.5%) |
| Mismatched lines | 1217 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 20 | 100.0% |

## Passing Tests

**64 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.2s |  |
| 2 | `DefineEditTextTest` | 153 | 18.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 18.1s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 17.8s |  |
| 5 | `DepthLimitsTest` | 20 | 18.1s |  |
| 6 | `PlaceObject2Test` | 9 | 17.4s |  |
| 7 | `ResolveEventsTest` | 15 | 18.0s |  |
| 8 | `RollOverOutTest` | 5 | 18.0s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.5s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 18.5s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.5s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 18.7s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 18.6s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 17.8s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 17.9s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 20 | `attachExtImported` | 2 | 18.1s |  |
| 21 | `attachImported` | 2 | 0.4s |  |
| 22 | `attachMovieLoopingTest` | 41 | 17.9s |  |
| 23 | `attachMovieTest` | 12 | 18.0s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 17.7s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.2s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.3s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.1s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 19.4s |  |
| 34 | `event_handler_scope_test` | 16 | 0.3s |  |
| 35 | `frame_label_test` | 17 | 18.0s |  |
| 36 | `getTimer_test` | 8 | 18.0s |  |
| 37 | `get_frame_number_test` | 31 | 18.0s |  |
| 38 | `goto_frame_test` | 15 | 17.8s |  |
| 39 | `instanceNameTest` | 5 | 0.3s |  |
| 40 | `loading/LoadVarsTest` | 36 | 18.6s |  |
| 41 | `loop/loop_test4` | 22 | 18.4s |  |
| 42 | `loop/loop_test5` | 24 | 18.1s |  |
| 43 | `loop/loop_test8` | 38 | 0.4s |  |
| 44 | `loop/loop_test9` | 15 | 18.4s |  |
| 45 | `loop/simple_loop_test` | 0 | 18.9s |  |
| 46 | `masks_test2` | 10 | 17.9s |  |
| 47 | `morph_test1` | 0 | 18.1s |  |
| 48 | `move_object_test` | 11 | 19.2s |  |
| 49 | `multi_doactions_and_goto_frame_test` | 6 | 18.9s |  |
| 50 | `new_child_in_unload_test` | 11 | 18.9s |  |
| 51 | `place_and_remove_object_insane_test` | 22 | 18.8s |  |
| 52 | `place_and_remove_object_test` | 13 | 18.7s |  |
| 53 | `register_class/RegisterClassTest3` | 12 | 18.0s |  |
| 54 | `register_class/registerClassTest` | 51 | 18.1s |  |
| 55 | `replace_shapes1test` | 23 | 0.3s |  |
| 56 | `replace_sprites1test` | 21 | 18.5s |  |
| 57 | `reverse_execute_PlaceObject2_test1` | 8 | 18.5s |  |
| 58 | `reverse_execute_PlaceObject2_test2` | 10 | 18.8s |  |
| 59 | `runtime_vm_stack_test` | 9 | 17.8s |  |
| 60 | `shape_test` | 21 | 18.0s |  |
| 61 | `static_vs_dynamic1` | 17 | 17.8s |  |
| 62 | `static_vs_dynamic2` | 18 | 17.5s |  |
| 63 | `timeline_var_test` | 11 | 17.5s |  |
| 64 | `unload_movieclip_test1` | 6 | 17.5s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 18.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 18.3s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 18.0s |  |
| 4 | `DefineTextTest` | 4 | 4 | 17.8s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 17.3s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 19.0s |  |
| 8 | `callFunction_test` | 5 | 11 | 17.7s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 18.1s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 17.9s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 18.7s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 19.0s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 19.2s |  |
| 15 | `key_event_test` | 5 | 6 | 18.8s |  |
| 16 | `loading/loadMovieTest` | 9 | 9 | 0.7s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 17.8s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 19 | `matrix_test` | 5 | 9 | 22.0s |  |
| 20 | `path_format_test` | 28 | 28 | 18.8s |  |
| 21 | `place_object_test` | 14 | 14 | 18.8s |  |
| 22 | `place_object_test2` | 22 | 23 | 18.5s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 18.0s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 18.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `loading/LoadBitmapTest` | 76.5% | 13 | 17 | 4 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 5 | `loop/loop_test3` | 52.9% | 9 | 17 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**20 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `loading/LoadBitmapTest` | 76.5% | 13/17 | 17 | 17 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 5 | `loop/loop_test3` | 52.9% | 9/17 | 17 | 16 |  |
| 6 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 7 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 8 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 9 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 10 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 11 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 12 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 13 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 14 | `loop/loop_test` | 14.8% | 4/27 | 27 | 21 |  |
| 15 | `action_order/ActionOrderTest5` | 11.9% | 7/59 | 59 | 51 |  |
| 16 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 17 | `action_order/ActionOrderTest4` | 6.2% | 6/96 | 96 | 64 |  |
| 18 | `action_order/ActionOrderTest3` | 5.3% | 4/75 | 75 | 62 |  |
| 19 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 20 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
