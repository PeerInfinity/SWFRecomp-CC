# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-19 23:31 UTC

**Git SHA**: `65fb43cd11`

**Run Duration**: 0m 43s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **64** (58.2%) |
| Ruffle-matched | 25 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **89** (80.9%) |
| Failing | 21 |
| Total expected lines | 5239 |
| Matching lines | 3985 (76.1%) |
| Mismatched lines | 1254 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 21 | 100.0% |

## Passing Tests

**64 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.2s |  |
| 2 | `DefineEditTextTest` | 153 | 0.9s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 0.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 0.4s |  |
| 5 | `DepthLimitsTest` | 20 | 0.3s |  |
| 6 | `PlaceObject2Test` | 9 | 0.2s |  |
| 7 | `ResolveEventsTest` | 15 | 0.3s |  |
| 8 | `RollOverOutTest` | 5 | 0.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.2s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 0.2s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 0.3s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 0.3s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 0.3s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 0.3s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 0.2s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 0.3s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.2s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.2s |  |
| 20 | `attachExtImported` | 2 | 0.3s |  |
| 21 | `attachImported` | 2 | 0.3s |  |
| 22 | `attachMovieLoopingTest` | 41 | 0.2s |  |
| 23 | `attachMovieTest` | 12 | 0.3s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 0.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.2s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.2s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.2s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.3s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 0.3s |  |
| 34 | `event_handler_scope_test` | 16 | 0.2s |  |
| 35 | `frame_label_test` | 17 | 0.3s |  |
| 36 | `getTimer_test` | 8 | 0.2s |  |
| 37 | `get_frame_number_test` | 31 | 0.4s |  |
| 38 | `goto_frame_test` | 15 | 0.2s |  |
| 39 | `instanceNameTest` | 5 | 0.2s |  |
| 40 | `loading/LoadVarsTest` | 36 | 0.5s |  |
| 41 | `loop/loop_test4` | 22 | 0.3s |  |
| 42 | `loop/loop_test5` | 24 | 0.3s |  |
| 43 | `loop/loop_test8` | 38 | 0.3s |  |
| 44 | `loop/loop_test9` | 15 | 0.2s |  |
| 45 | `loop/simple_loop_test` | 0 | 0.2s |  |
| 46 | `masks_test2` | 10 | 0.2s |  |
| 47 | `morph_test1` | 0 | 0.2s |  |
| 48 | `move_object_test` | 11 | 0.2s |  |
| 49 | `multi_doactions_and_goto_frame_test` | 6 | 0.2s |  |
| 50 | `new_child_in_unload_test` | 11 | 0.2s |  |
| 51 | `place_and_remove_object_insane_test` | 22 | 0.3s |  |
| 52 | `place_and_remove_object_test` | 13 | 0.2s |  |
| 53 | `register_class/RegisterClassTest3` | 12 | 0.3s |  |
| 54 | `register_class/registerClassTest` | 51 | 0.4s |  |
| 55 | `replace_shapes1test` | 23 | 0.2s |  |
| 56 | `replace_sprites1test` | 21 | 0.2s |  |
| 57 | `reverse_execute_PlaceObject2_test1` | 8 | 0.2s |  |
| 58 | `reverse_execute_PlaceObject2_test2` | 10 | 0.2s |  |
| 59 | `runtime_vm_stack_test` | 9 | 0.2s |  |
| 60 | `shape_test` | 21 | 0.3s |  |
| 61 | `static_vs_dynamic1` | 17 | 0.2s |  |
| 62 | `static_vs_dynamic2` | 18 | 0.2s |  |
| 63 | `timeline_var_test` | 11 | 0.2s |  |
| 64 | `unload_movieclip_test1` | 6 | 0.2s |  |

## Ruffle-Matched Tests

**25 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 0.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 0.5s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 0.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 0.2s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.2s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 0.2s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 0.3s |  |
| 8 | `callFunction_test` | 5 | 11 | 0.2s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 0.6s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.5s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 0.3s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 0.2s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 0.3s |  |
| 15 | `key_event_test` | 5 | 6 | 0.3s |  |
| 16 | `loading/loadMovieTest` | 9 | 9 | 0.6s |  |
| 17 | `loop/loop_test10` | 23 | 23 | 0.3s |  |
| 18 | `loop/loop_test6` | 1 | 12 | 0.3s |  |
| 19 | `loop/loop_test7` | 1 | 8 | 0.2s |  |
| 20 | `matrix_test` | 5 | 9 | 3.3s |  |
| 21 | `path_format_test` | 28 | 28 | 0.8s |  |
| 22 | `place_object_test` | 14 | 14 | 0.2s |  |
| 23 | `place_object_test2` | 22 | 23 | 0.2s |  |
| 24 | `register_class/registerClassTest2` | 8 | 28 | 0.3s |  |
| 25 | `replace_buttons1test` | 3 | 3 | 0.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `loading/LoadBitmapTest` | 76.5% | 13 | 17 | 4 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 5 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |
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
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `loading/LoadBitmapTest` | 76.5% | 13/17 | 17 | 17 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 5 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 6 | `loop/loop_test3` | 52.9% | 9/17 | 17 | 16 |  |
| 7 | `action_order/action_execution_order_test5` | 44.1% | 26/59 | 59 | 35 |  |
| 8 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 9 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 10 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 11 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 12 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 13 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 14 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 15 | `loop/loop_test` | 14.8% | 4/27 | 27 | 21 |  |
| 16 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 17 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 18 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 19 | `register_class/RegisterClassTest4` | 5.2% | 3/58 | 58 | 42 |  |
| 20 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 21 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
