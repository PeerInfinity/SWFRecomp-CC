# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-15 20:40 UTC

**Git SHA**: `d1d22f9515`

**Run Duration**: 27m 36s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **63** (57.3%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **87** (79.1%) |
| Failing | 23 |
| Total expected lines | 5239 |
| Matching lines | 3987 (76.1%) |
| Mismatched lines | 1252 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 23 | 100.0% |

## Passing Tests

**63 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.5s |  |
| 2 | `DefineEditTextTest` | 153 | 20.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 20.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 20.5s |  |
| 5 | `DepthLimitsTest` | 20 | 17.8s |  |
| 6 | `PlaceObject2Test` | 9 | 19.3s |  |
| 7 | `ResolveEventsTest` | 15 | 17.8s |  |
| 8 | `RollOverOutTest` | 5 | 17.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 10 | `Version4Loader` | 11 | 0.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.4s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 17.9s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 18.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.1s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 14.0s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 14.0s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 0.2s |  |
| 19 | `attachExtImported` | 2 | 17.8s |  |
| 20 | `attachImported` | 2 | 0.3s |  |
| 21 | `attachMovieLoopingTest` | 41 | 17.7s |  |
| 22 | `attachMovieTest` | 12 | 17.8s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 18.2s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.2s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 19.5s |  |
| 33 | `event_handler_scope_test` | 16 | 0.3s |  |
| 34 | `frame_label_test` | 17 | 18.8s |  |
| 35 | `getTimer_test` | 8 | 18.6s |  |
| 36 | `get_frame_number_test` | 31 | 18.6s |  |
| 37 | `goto_frame_test` | 15 | 18.5s |  |
| 38 | `instanceNameTest` | 5 | 0.3s |  |
| 39 | `loading/LoadVarsTest` | 36 | 20.5s |  |
| 40 | `loop/loop_test4` | 22 | 18.3s |  |
| 41 | `loop/loop_test5` | 24 | 18.7s |  |
| 42 | `loop/loop_test8` | 38 | 0.5s |  |
| 43 | `loop/loop_test9` | 15 | 18.9s |  |
| 44 | `loop/simple_loop_test` | 0 | 18.9s |  |
| 45 | `masks_test2` | 10 | 17.2s |  |
| 46 | `morph_test1` | 0 | 17.5s |  |
| 47 | `move_object_test` | 11 | 18.5s |  |
| 48 | `multi_doactions_and_goto_frame_test` | 6 | 18.5s |  |
| 49 | `new_child_in_unload_test` | 11 | 18.4s |  |
| 50 | `place_and_remove_object_insane_test` | 22 | 17.7s |  |
| 51 | `place_and_remove_object_test` | 13 | 18.1s |  |
| 52 | `register_class/RegisterClassTest3` | 12 | 18.7s |  |
| 53 | `register_class/registerClassTest` | 51 | 18.4s |  |
| 54 | `replace_shapes1test` | 23 | 0.3s |  |
| 55 | `replace_sprites1test` | 21 | 18.6s |  |
| 56 | `reverse_execute_PlaceObject2_test1` | 8 | 18.3s |  |
| 57 | `reverse_execute_PlaceObject2_test2` | 10 | 18.8s |  |
| 58 | `runtime_vm_stack_test` | 9 | 18.7s |  |
| 59 | `shape_test` | 21 | 19.0s |  |
| 60 | `static_vs_dynamic1` | 17 | 18.9s |  |
| 61 | `static_vs_dynamic2` | 18 | 17.5s |  |
| 62 | `timeline_var_test` | 11 | 17.5s |  |
| 63 | `unload_movieclip_test1` | 6 | 17.4s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 18.8s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 18.6s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 18.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 20.1s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 19.4s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 18.7s |  |
| 8 | `callFunction_test` | 5 | 11 | 18.2s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 18.4s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.8s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 19.2s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 17.5s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 17.7s |  |
| 15 | `key_event_test` | 5 | 6 | 17.6s |  |
| 16 | `loading/loadMovieTest` | 9 | 9 | 0.7s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 18.8s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 19 | `matrix_test` | 5 | 9 | 21.1s |  |
| 20 | `path_format_test` | 28 | 28 | 17.9s |  |
| 21 | `place_object_test` | 14 | 14 | 18.6s |  |
| 22 | `place_object_test2` | 22 | 23 | 18.4s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 17.8s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 17.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**7 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16 | 19 | 3 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13 | 17 | 4 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 6 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |
| 7 | `loop/loop_test3` | 52.9% | 9 | 17 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**23 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16/19 | 19 | 19 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13/17 | 17 | 17 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 6 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 7 | `loop/loop_test3` | 52.9% | 9/17 | 17 | 16 |  |
| 8 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 9 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 10 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 11 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 12 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 13 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 14 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 15 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 16 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 17 | `loop/loop_test` | 14.8% | 4/27 | 27 | 21 |  |
| 18 | `action_order/ActionOrderTest5` | 11.5% | 7/61 | 61 | 51 |  |
| 19 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 20 | `action_order/ActionOrderTest4` | 9.7% | 7/72 | 72 | 64 |  |
| 21 | `action_order/ActionOrderTest3` | 4.3% | 3/69 | 69 | 62 |  |
| 22 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 23 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
