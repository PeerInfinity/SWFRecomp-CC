# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 19:30 UTC

**Git SHA**: `bc91565cea`

**Run Duration**: 24m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 107 |
| Passing | **67** (62.6%) |
| Ruffle-matched | 30 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **97** (90.7%) |
| Failing | 10 |
| Total expected lines | 5104 |
| Matching lines | 4105 (80.4%) |
| Mismatched lines | 999 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 100.0% |

## Passing Tests

**67 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 17.8s |  |
| 2 | `DefineEditTextTest` | 153 | 7.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 20.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 18.7s |  |
| 5 | `DepthLimitsTest` | 20 | 20.2s |  |
| 6 | `PlaceObject2Test` | 9 | 17.4s |  |
| 7 | `ResolveEventsTest` | 15 | 17.6s |  |
| 8 | `RollOverOutTest` | 5 | 17.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 10 | `Version4Loader` | 11 | 1.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 17.6s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 17.1s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 17.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 1.5s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.0s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 1.4s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 17.2s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.3s |  |
| 20 | `attachExtImported` | 2 | 24.0s |  |
| 21 | `attachImported` | 2 | 2.0s |  |
| 22 | `attachMovieLoopingTest` | 41 | 23.4s |  |
| 23 | `attachMovieTest` | 12 | 22.7s |  |
| 24 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.3s |  |
| 25 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test5` | 25 | 17.1s |  |
| 27 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test9` | 23 | 24.4s |  |
| 31 | `duplicate_movie_clip_test2` | 21 | 24.5s |  |
| 32 | `event_handler_scope_test` | 16 | 2.6s |  |
| 33 | `frame_label_test` | 17 | 24.4s |  |
| 34 | `getTimer_test` | 8 | 22.7s |  |
| 35 | `get_frame_number_test` | 31 | 26.0s |  |
| 36 | `gotoFrame2Test` | 9 | 23.0s |  |
| 37 | `goto_frame_test` | 15 | 19.2s |  |
| 38 | `instanceNameTest` | 5 | 1.4s |  |
| 39 | `loading/LoadVarsTest` | 36 | 20.2s |  |
| 40 | `loop/loop_test` | 21 | 17.5s |  |
| 41 | `loop/loop_test2` | 15 | 17.4s |  |
| 42 | `loop/loop_test3` | 16 | 1.4s |  |
| 43 | `loop/loop_test4` | 22 | 18.3s |  |
| 44 | `loop/loop_test5` | 24 | 2.2s |  |
| 45 | `loop/loop_test8` | 38 | 18.9s |  |
| 46 | `loop/loop_test9` | 15 | 17.4s |  |
| 47 | `loop/simple_loop_test` | 0 | 17.1s |  |
| 48 | `masks_test2` | 10 | 23.1s |  |
| 49 | `morph_test1` | 0 | 23.1s |  |
| 50 | `move_object_test` | 11 | 17.1s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 1.4s |  |
| 52 | `new_child_in_unload_test` | 11 | 1.5s |  |
| 53 | `opcode_guard_test` | 18 | 23.5s |  |
| 54 | `place_and_remove_object_insane_test` | 22 | 2.4s |  |
| 55 | `place_and_remove_object_test` | 13 | 25.2s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 17.8s |  |
| 57 | `register_class/registerClassTest` | 51 | 19.4s |  |
| 58 | `replace_shapes1test` | 23 | 0.5s |  |
| 59 | `replace_sprites1test` | 21 | 17.4s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 16.9s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 17.2s |  |
| 62 | `runtime_vm_stack_test` | 9 | 1.6s |  |
| 63 | `shape_test` | 21 | 2.3s |  |
| 64 | `static_vs_dynamic1` | 17 | 1.3s |  |
| 65 | `static_vs_dynamic2` | 18 | 1.7s |  |
| 66 | `timeline_var_test` | 11 | 17.3s |  |
| 67 | `unload_movieclip_test1` | 6 | 1.3s |  |

## Ruffle-Matched Tests

**30 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 20.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 20.9s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 1.5s |  |
| 4 | `DefineTextTest` | 4 | 4 | 1.6s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.7s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 23.0s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 17.5s |  |
| 8 | `PrototypeEventListeners` | 23 | 23 | 16.9s |  |
| 9 | `TextSnapshotTest` | 81 | 90 | 23.0s |  |
| 10 | `action_order/action_execution_order_test` | 12 | 12 | 17.4s |  |
| 11 | `action_order/action_execution_order_test4` | 7 | 26 | 2.2s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 18.3s |  |
| 13 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 17.6s |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.5s |  |
| 15 | `duplicate_movie_clip_test` | 4 | 4 | 25.0s |  |
| 16 | `init_action/InitActionTest` | 6 | 17 | 18.8s |  |
| 17 | `init_action/InitActionTest2` | 24 | 30 | 19.6s |  |
| 18 | `key_event_test` | 5 | 6 | 18.7s |  |
| 19 | `loading/LoadBitmapTest` | 3 | 3 | 18.4s |  |
| 20 | `loading/loadMovieTest` | 9 | 9 | 3.0s |  |
| 21 | `loop/loop_test10` | 23 | 23 | 18.0s |  |
| 22 | `loop/loop_test6` | 11 | 12 | 18.6s |  |
| 23 | `loop/loop_test7` | 1 | 8 | 1.7s |  |
| 24 | `masks_test` | 16 | 16 | 24.4s |  |
| 25 | `matrix_test` | 5 | 9 | 119.3s |  |
| 26 | `path_format_test` | 28 | 28 | 4.6s |  |
| 27 | `place_object_test` | 14 | 14 | 2.9s |  |
| 28 | `place_object_test2` | 22 | 23 | 24.9s |  |
| 29 | `register_class/registerClassTest2` | 8 | 28 | 20.9s |  |
| 30 | `replace_buttons1test` | 3 | 3 | 21.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `NetStream-SquareTest` | 56.0% | 121 | 216 | 95 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**10 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `NetStream-SquareTest` | 56.0% | 121/216 | 201 | 216 |  |
| 4 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 5 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 7 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 8 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 9 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 10 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
