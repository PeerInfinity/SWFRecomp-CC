# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-21 23:56 UTC

**Git SHA**: `63ca22e398`

**Run Duration**: 27m 19s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **97** (87.4%) |
| Failing | 14 |
| Total expected lines | 5248 |
| Matching lines | 4054 (77.2%) |
| Mismatched lines | 1194 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.2s |  |
| 2 | `DefineEditTextTest` | 153 | 29.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.6s |  |
| 5 | `DepthLimitsTest` | 20 | 21.6s |  |
| 6 | `PlaceObject2Test` | 9 | 1.8s |  |
| 7 | `ResolveEventsTest` | 15 | 3.1s |  |
| 8 | `RollOverOutTest` | 5 | 20.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.8s |  |
| 10 | `Version4Loader` | 11 | 1.7s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 15.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 15.4s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.7s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.7s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 16.0s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 17.2s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.6s |  |
| 20 | `attachExtImported` | 2 | 21.0s |  |
| 21 | `attachImported` | 2 | 1.9s |  |
| 22 | `attachMovieLoopingTest` | 41 | 19.9s |  |
| 23 | `attachMovieTest` | 12 | 20.5s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 19.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 1.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.4s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.0s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.0s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 21.3s |  |
| 34 | `event_handler_scope_test` | 16 | 2.4s |  |
| 35 | `frame_label_test` | 17 | 21.8s |  |
| 36 | `getTimer_test` | 8 | 20.8s |  |
| 37 | `get_frame_number_test` | 31 | 4.5s |  |
| 38 | `gotoFrame2Test` | 9 | 20.3s |  |
| 39 | `goto_frame_test` | 15 | 21.2s |  |
| 40 | `instanceNameTest` | 5 | 1.9s |  |
| 41 | `loading/LoadVarsTest` | 36 | 24.5s |  |
| 42 | `loop/loop_test` | 21 | 19.8s |  |
| 43 | `loop/loop_test2` | 15 | 19.6s |  |
| 44 | `loop/loop_test3` | 16 | 1.9s |  |
| 45 | `loop/loop_test4` | 22 | 20.7s |  |
| 46 | `loop/loop_test5` | 24 | 2.9s |  |
| 47 | `loop/loop_test8` | 38 | 21.9s |  |
| 48 | `loop/loop_test9` | 15 | 20.5s |  |
| 49 | `loop/simple_loop_test` | 0 | 20.2s |  |
| 50 | `masks_test2` | 10 | 21.0s |  |
| 51 | `morph_test1` | 0 | 20.6s |  |
| 52 | `move_object_test` | 11 | 2.1s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 20.1s |  |
| 54 | `new_child_in_unload_test` | 11 | 20.2s |  |
| 55 | `opcode_guard_test` | 18 | 19.9s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 20.5s |  |
| 57 | `place_and_remove_object_test` | 13 | 19.9s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 21.5s |  |
| 59 | `register_class/registerClassTest` | 51 | 22.6s |  |
| 60 | `replace_shapes1test` | 23 | 2.6s |  |
| 61 | `replace_sprites1test` | 21 | 20.2s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 19.2s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 2.2s |  |
| 64 | `runtime_vm_stack_test` | 9 | 15.1s |  |
| 65 | `shape_test` | 21 | 15.8s |  |
| 66 | `static_vs_dynamic1` | 17 | 15.5s |  |
| 67 | `static_vs_dynamic2` | 18 | 14.7s |  |
| 68 | `timeline_var_test` | 11 | 14.7s |  |
| 69 | `unload_movieclip_test1` | 6 | 14.6s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 0.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 0.5s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 0.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 20.5s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.2s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 6.9s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 16.3s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 29.1s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 20.8s |  |
| 10 | `callFunction_test` | 6 | 11 | 20.6s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 26.8s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.1s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.1s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 20.9s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 3.5s |  |
| 17 | `key_event_test` | 5 | 6 | 22.2s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 3.3s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 4.6s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 20.4s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 20.6s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 2.3s |  |
| 23 | `matrix_test` | 5 | 9 | 106.5s |  |
| 24 | `path_format_test` | 28 | 28 | 22.1s |  |
| 25 | `place_object_test` | 14 | 14 | 20.4s |  |
| 26 | `place_object_test2` | 22 | 23 | 2.4s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 21.8s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 20.7s |  |

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

**14 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 4 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 5 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 6 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 7 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 8 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 9 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 10 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 11 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 12 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
