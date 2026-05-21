# Ruffle Test Results (Filtered)

**Date**: 2026-05-21 00:20 UTC

**Git SHA**: `4cd8df042c`

**Run Duration**: 32m 56s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **64** (59.3%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **90** (83.3%) |
| Failing | 18 |
| Total expected lines | 5179 |
| Matching lines | 3985 (76.9%) |
| Mismatched lines | 1194 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 18 | 100.0% |

## Passing Tests

**64 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.6s |  |
| 2 | `DefineEditTextTest` | 153 | 32.8s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 25.2s |  |
| 5 | `DepthLimitsTest` | 20 | 22.1s |  |
| 6 | `PlaceObject2Test` | 9 | 19.8s |  |
| 7 | `ResolveEventsTest` | 15 | 20.9s |  |
| 8 | `RollOverOutTest` | 5 | 20.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.3s |  |
| 10 | `Version4Loader` | 11 | 1.1s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 14.2s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 20.6s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 20.3s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 21.0s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 23.7s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 20.0s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 20.2s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.7s |  |
| 20 | `attachExtImported` | 2 | 20.6s |  |
| 21 | `attachImported` | 2 | 1.7s |  |
| 22 | `attachMovieLoopingTest` | 41 | 19.7s |  |
| 23 | `attachMovieTest` | 12 | 20.5s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 19.5s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.2s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.6s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.8s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.8s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 21.4s |  |
| 33 | `event_handler_scope_test` | 16 | 2.1s |  |
| 34 | `frame_label_test` | 17 | 19.9s |  |
| 35 | `getTimer_test` | 8 | 18.8s |  |
| 36 | `get_frame_number_test` | 31 | 20.7s |  |
| 37 | `goto_frame_test` | 15 | 19.1s |  |
| 38 | `instanceNameTest` | 5 | 1.6s |  |
| 39 | `loading/LoadVarsTest` | 36 | 22.5s |  |
| 40 | `loop/loop_test` | 21 | 19.6s |  |
| 41 | `loop/loop_test4` | 22 | 22.8s |  |
| 42 | `loop/loop_test5` | 24 | 20.6s |  |
| 43 | `loop/loop_test8` | 38 | 3.8s |  |
| 44 | `loop/loop_test9` | 15 | 19.6s |  |
| 45 | `loop/simple_loop_test` | 0 | 19.0s |  |
| 46 | `masks_test2` | 10 | 15.7s |  |
| 47 | `morph_test1` | 0 | 15.3s |  |
| 48 | `move_object_test` | 11 | 19.2s |  |
| 49 | `multi_doactions_and_goto_frame_test` | 6 | 19.1s |  |
| 50 | `new_child_in_unload_test` | 11 | 19.2s |  |
| 51 | `place_and_remove_object_insane_test` | 22 | 20.9s |  |
| 52 | `place_and_remove_object_test` | 13 | 11.7s |  |
| 53 | `register_class/RegisterClassTest3` | 12 | 19.9s |  |
| 54 | `register_class/registerClassTest` | 51 | 22.3s |  |
| 55 | `replace_shapes1test` | 23 | 2.3s |  |
| 56 | `replace_sprites1test` | 21 | 20.8s |  |
| 57 | `reverse_execute_PlaceObject2_test1` | 8 | 20.2s |  |
| 58 | `reverse_execute_PlaceObject2_test2` | 10 | 20.5s |  |
| 59 | `runtime_vm_stack_test` | 9 | 20.1s |  |
| 60 | `shape_test` | 21 | 21.4s |  |
| 61 | `static_vs_dynamic1` | 17 | 20.0s |  |
| 62 | `static_vs_dynamic2` | 18 | 20.4s |  |
| 63 | `timeline_var_test` | 11 | 20.3s |  |
| 64 | `unload_movieclip_test1` | 6 | 19.9s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 24.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 25.0s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 20.0s |  |
| 4 | `DefineTextTest` | 4 | 4 | 22.9s |  |
| 5 | `DragDropTest` | 12 | 12 | 2.8s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 20.1s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 23.9s |  |
| 8 | `callFunction_test` | 6 | 11 | 20.2s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 26.0s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.9s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.8s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 21.9s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 20.1s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 21.2s |  |
| 15 | `key_event_test` | 5 | 6 | 21.2s |  |
| 16 | `loading/LoadBitmapTest` | 3 | 3 | 20.4s |  |
| 17 | `loading/loadMovieTest` | 9 | 9 | 3.9s |  |
| 18 | `loop/loop_test10` | 23 | 23 | 21.2s |  |
| 19 | `loop/loop_test6` | 1 | 12 | 20.3s |  |
| 20 | `loop/loop_test7` | 1 | 8 | 2.1s |  |
| 21 | `matrix_test` | 5 | 9 | 81.2s |  |
| 22 | `path_format_test` | 28 | 28 | 23.2s |  |
| 23 | `place_object_test` | 14 | 14 | 11.9s |  |
| 24 | `place_object_test2` | 22 | 23 | 11.8s |  |
| 25 | `register_class/registerClassTest2` | 8 | 28 | 21.3s |  |
| 26 | `replace_buttons1test` | 3 | 3 | 20.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test9` | 87.0% | 20 | 23 | 3 |  |
| 2 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 5 | `loop/loop_test3` | 52.9% | 9 | 17 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**18 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displaylist_depths/displaylist_depths_test9` | 87.0% | 20/23 | 23 | 23 |  |
| 2 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 5 | `loop/loop_test3` | 52.9% | 9/17 | 17 | 16 |  |
| 6 | `action_order/action_execution_order_test5` | 44.1% | 26/59 | 59 | 35 |  |
| 7 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 8 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 9 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 10 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 11 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 12 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 13 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 14 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 15 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 16 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 17 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 18 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
