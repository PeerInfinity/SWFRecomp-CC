# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-15 02:10 UTC

**Git SHA**: `eb8206f8aa`

**Run Duration**: 33m 14s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **66** (60.0%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **90** (81.8%) |
| Failing | 20 |
| Total expected lines | 5239 |
| Matching lines | 4049 (77.3%) |
| Mismatched lines | 1190 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 20 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.5s |  |
| 2 | `DefineEditTextTest` | 153 | 29.0s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.6s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.3s |  |
| 5 | `DepthLimitsTest` | 20 | 20.8s |  |
| 6 | `PlaceObject2Test` | 9 | 19.5s |  |
| 7 | `ResolveEventsTest` | 15 | 21.4s |  |
| 8 | `RollOverOutTest` | 5 | 21.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.8s |  |
| 10 | `Version4Loader` | 11 | 1.7s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.4s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.8s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.5s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.4s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 20.6s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 20.7s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.9s |  |
| 19 | `attachExtImported` | 2 | 20.6s |  |
| 20 | `attachImported` | 2 | 1.9s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.5s |  |
| 22 | `attachMovieTest` | 12 | 20.0s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 19.2s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.7s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.6s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.6s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 21.1s |  |
| 33 | `event_handler_scope_test` | 16 | 2.4s |  |
| 34 | `frame_label_test` | 17 | 21.0s |  |
| 35 | `getTimer_test` | 8 | 19.6s |  |
| 36 | `get_frame_number_test` | 31 | 21.8s |  |
| 37 | `goto_frame_test` | 15 | 20.0s |  |
| 38 | `instanceNameTest` | 5 | 1.8s |  |
| 39 | `loading/LoadVarsTest` | 36 | 22.4s |  |
| 40 | `loop/loop_test` | 21 | 19.2s |  |
| 41 | `loop/loop_test2` | 15 | 19.2s |  |
| 42 | `loop/loop_test3` | 16 | 1.7s |  |
| 43 | `loop/loop_test4` | 22 | 19.9s |  |
| 44 | `loop/loop_test5` | 24 | 19.4s |  |
| 45 | `loop/loop_test8` | 38 | 3.3s |  |
| 46 | `loop/loop_test9` | 15 | 19.4s |  |
| 47 | `loop/simple_loop_test` | 0 | 18.9s |  |
| 48 | `masks_test2` | 10 | 19.3s |  |
| 49 | `morph_test1` | 0 | 19.1s |  |
| 50 | `move_object_test` | 11 | 19.8s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 19.4s |  |
| 52 | `new_child_in_unload_test` | 11 | 19.1s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 19.2s |  |
| 54 | `place_and_remove_object_test` | 13 | 18.9s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 19.8s |  |
| 56 | `register_class/registerClassTest` | 51 | 22.6s |  |
| 57 | `replace_shapes1test` | 23 | 2.5s |  |
| 58 | `replace_sprites1test` | 21 | 20.0s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 19.6s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 19.7s |  |
| 61 | `runtime_vm_stack_test` | 9 | 19.9s |  |
| 62 | `shape_test` | 21 | 21.0s |  |
| 63 | `static_vs_dynamic1` | 17 | 19.4s |  |
| 64 | `static_vs_dynamic2` | 18 | 20.6s |  |
| 65 | `timeline_var_test` | 11 | 19.8s |  |
| 66 | `unload_movieclip_test1` | 6 | 19.9s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 24.0s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 24.8s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 19.7s |  |
| 4 | `DefineTextTest` | 4 | 4 | 20.0s |  |
| 5 | `DragDropTest` | 12 | 12 | 2.9s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 19.9s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 20.0s |  |
| 8 | `callFunction_test` | 5 | 11 | 20.1s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 26.4s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.3s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.8s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 21.3s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 19.9s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 21.0s |  |
| 15 | `key_event_test` | 5 | 6 | 21.0s |  |
| 16 | `loading/loadMovieTest` | 9 | 9 | 4.2s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 19.1s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 1.9s |  |
| 19 | `matrix_test` | 5 | 9 | 98.2s |  |
| 20 | `path_format_test` | 11 | 28 | 21.3s |  |
| 21 | `place_object_test` | 6 | 14 | 19.3s |  |
| 22 | `place_object_test2` | 5 | 23 | 19.4s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 21.4s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 20.1s |  |

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
| 6 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |

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
| 2 | `action_order/action_execution_order_test` | 84.2% | 16/19 | 19 | 19 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13/17 | 17 | 17 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 6 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 7 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 8 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 9 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 10 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 11 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 12 | `register_class/RegisterClassTest4` | 16.7% | 7/42 | 37 | 42 |  |
| 13 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 14 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 15 | `action_order/ActionOrderTest5` | 13.6% | 8/59 | 59 | 51 |  |
| 16 | `action_order/ActionOrderTest3` | 11.1% | 7/63 | 63 | 62 |  |
| 17 | `action_order/ActionOrderTest4` | 10.0% | 7/70 | 70 | 64 |  |
| 18 | `loop/loop_test10` | 3.6% | 1/28 | 22 | 28 |  |
| 19 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 20 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
