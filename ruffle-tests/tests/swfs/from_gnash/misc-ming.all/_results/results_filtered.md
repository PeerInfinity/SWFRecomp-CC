# Ruffle Test Results (Filtered)

**Date**: 2026-05-15 17:55 UTC

**Git SHA**: `b8eef7a3e1`

**Run Duration**: 31m 24s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **63** (58.3%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **87** (80.6%) |
| Failing | 21 |
| Total expected lines | 5179 |
| Matching lines | 3959 (76.4%) |
| Mismatched lines | 1220 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 21 | 100.0% |

## Passing Tests

**63 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.5s |  |
| 2 | `DefineEditTextTest` | 153 | 28.0s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 24.4s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 21.2s |  |
| 5 | `DepthLimitsTest` | 20 | 21.9s |  |
| 6 | `PlaceObject2Test` | 9 | 20.2s |  |
| 7 | `ResolveEventsTest` | 15 | 21.1s |  |
| 8 | `RollOverOutTest` | 5 | 20.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.9s |  |
| 10 | `Version4Loader` | 11 | 1.8s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.0s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.4s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.9s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 19.7s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 20.0s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.8s |  |
| 19 | `attachExtImported` | 2 | 20.4s |  |
| 20 | `attachImported` | 2 | 1.9s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.3s |  |
| 22 | `attachMovieTest` | 12 | 20.2s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 17.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.6s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.0s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.9s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 16.4s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 18.1s |  |
| 33 | `event_handler_scope_test` | 16 | 2.0s |  |
| 34 | `frame_label_test` | 17 | 20.6s |  |
| 35 | `getTimer_test` | 8 | 19.1s |  |
| 36 | `get_frame_number_test` | 31 | 21.5s |  |
| 37 | `goto_frame_test` | 15 | 19.8s |  |
| 38 | `instanceNameTest` | 5 | 1.8s |  |
| 39 | `loading/LoadVarsTest` | 36 | 18.3s |  |
| 40 | `loop/loop_test4` | 22 | 18.0s |  |
| 41 | `loop/loop_test5` | 24 | 21.1s |  |
| 42 | `loop/loop_test8` | 38 | 4.1s |  |
| 43 | `loop/loop_test9` | 15 | 19.5s |  |
| 44 | `loop/simple_loop_test` | 0 | 18.8s |  |
| 45 | `masks_test2` | 10 | 18.0s |  |
| 46 | `morph_test1` | 0 | 18.2s |  |
| 47 | `move_object_test` | 11 | 19.0s |  |
| 48 | `multi_doactions_and_goto_frame_test` | 6 | 19.0s |  |
| 49 | `new_child_in_unload_test` | 11 | 19.1s |  |
| 50 | `place_and_remove_object_insane_test` | 22 | 20.6s |  |
| 51 | `place_and_remove_object_test` | 13 | 19.9s |  |
| 52 | `register_class/RegisterClassTest3` | 12 | 20.2s |  |
| 53 | `register_class/registerClassTest` | 51 | 22.6s |  |
| 54 | `replace_shapes1test` | 23 | 2.5s |  |
| 55 | `replace_sprites1test` | 21 | 20.9s |  |
| 56 | `reverse_execute_PlaceObject2_test1` | 8 | 20.2s |  |
| 57 | `reverse_execute_PlaceObject2_test2` | 10 | 20.2s |  |
| 58 | `runtime_vm_stack_test` | 9 | 20.6s |  |
| 59 | `shape_test` | 21 | 21.4s |  |
| 60 | `static_vs_dynamic1` | 17 | 20.2s |  |
| 61 | `static_vs_dynamic2` | 18 | 19.7s |  |
| 62 | `timeline_var_test` | 11 | 19.6s |  |
| 63 | `unload_movieclip_test1` | 6 | 19.3s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 24.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 24.8s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 19.6s |  |
| 4 | `DefineTextTest` | 4 | 4 | 19.2s |  |
| 5 | `DragDropTest` | 12 | 12 | 2.9s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 20.7s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 20.8s |  |
| 8 | `callFunction_test` | 5 | 11 | 17.8s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 17.9s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.0s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.0s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 17.0s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 19.4s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 20.4s |  |
| 15 | `key_event_test` | 5 | 6 | 20.2s |  |
| 16 | `loading/loadMovieTest` | 9 | 9 | 0.6s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 20.8s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 2.2s |  |
| 19 | `matrix_test` | 5 | 9 | 22.4s |  |
| 20 | `path_format_test` | 28 | 28 | 23.1s |  |
| 21 | `place_object_test` | 14 | 14 | 20.7s |  |
| 22 | `place_object_test2` | 22 | 23 | 20.8s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 21.7s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 20.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16 | 19 | 3 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13 | 17 | 4 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 6 | `loop/loop_test3` | 52.9% | 9 | 17 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**21 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16/19 | 19 | 19 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13/17 | 17 | 17 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 6 | `loop/loop_test3` | 52.9% | 9/17 | 17 | 16 |  |
| 7 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 8 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 9 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 10 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 11 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 12 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 13 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 14 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 15 | `loop/loop_test` | 14.8% | 4/27 | 27 | 21 |  |
| 16 | `action_order/ActionOrderTest5` | 11.5% | 7/61 | 61 | 51 |  |
| 17 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 18 | `action_order/ActionOrderTest4` | 9.7% | 7/72 | 72 | 64 |  |
| 19 | `action_order/ActionOrderTest3` | 4.3% | 3/69 | 69 | 62 |  |
| 20 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 21 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
