# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-21 23:49 UTC

**Git SHA**: `63ca22e398`

**Run Duration**: 33m 3s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 107 |
| Passing | **66** (61.7%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **93** (86.9%) |
| Failing | 14 |
| Total expected lines | 5159 |
| Matching lines | 3990 (77.3%) |
| Mismatched lines | 1169 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.6s |  |
| 2 | `DefineEditTextTest` | 153 | 20.2s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 19.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.7s |  |
| 5 | `DepthLimitsTest` | 20 | 23.2s |  |
| 6 | `PlaceObject2Test` | 9 | 21.7s |  |
| 7 | `ResolveEventsTest` | 15 | 13.6s |  |
| 8 | `RollOverOutTest` | 5 | 13.3s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.7s |  |
| 10 | `Version4Loader` | 11 | 2.6s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.2s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 21.4s |  |
| 14 | `action_order/action_execution_order_test7` | 7 | 19.9s |  |
| 15 | `action_order/action_execution_order_test8-v5` | 11 | 20.2s |  |
| 16 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 17 | `action_order/action_execution_order_test9` | 4 | 1.3s |  |
| 18 | `attachExtImported` | 2 | 22.1s |  |
| 19 | `attachImported` | 2 | 2.6s |  |
| 20 | `attachMovieLoopingTest` | 41 | 20.8s |  |
| 21 | `attachMovieTest` | 12 | 22.9s |  |
| 22 | `consecutive_goto_frame_test` | 12 | 20.6s |  |
| 23 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.4s |  |
| 24 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.7s |  |
| 31 | `duplicate_movie_clip_test2` | 21 | 18.2s |  |
| 32 | `event_handler_scope_test` | 16 | 2.3s |  |
| 33 | `frame_label_test` | 17 | 21.9s |  |
| 34 | `getTimer_test` | 8 | 20.7s |  |
| 35 | `get_frame_number_test` | 31 | 23.1s |  |
| 36 | `gotoFrame2Test` | 9 | 20.6s |  |
| 37 | `goto_frame_test` | 15 | 21.7s |  |
| 38 | `instanceNameTest` | 5 | 2.6s |  |
| 39 | `loading/LoadVarsTest` | 36 | 26.1s |  |
| 40 | `loop/loop_test` | 21 | 17.7s |  |
| 41 | `loop/loop_test2` | 15 | 17.5s |  |
| 42 | `loop/loop_test3` | 16 | 2.1s |  |
| 43 | `loop/loop_test4` | 22 | 22.1s |  |
| 44 | `loop/loop_test5` | 24 | 3.8s |  |
| 45 | `loop/loop_test8` | 38 | 24.1s |  |
| 46 | `loop/loop_test9` | 15 | 21.6s |  |
| 47 | `loop/simple_loop_test` | 0 | 25.1s |  |
| 48 | `masks_test2` | 10 | 21.5s |  |
| 49 | `morph_test1` | 0 | 25.4s |  |
| 50 | `move_object_test` | 11 | 14.5s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 14.8s |  |
| 52 | `new_child_in_unload_test` | 11 | 15.8s |  |
| 53 | `opcode_guard_test` | 18 | 17.7s |  |
| 54 | `place_and_remove_object_test` | 13 | 22.4s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 20.4s |  |
| 56 | `register_class/registerClassTest` | 51 | 20.7s |  |
| 57 | `replace_shapes1test` | 23 | 3.2s |  |
| 58 | `replace_sprites1test` | 21 | 21.9s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 21.1s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 21.0s |  |
| 61 | `runtime_vm_stack_test` | 9 | 21.3s |  |
| 62 | `shape_test` | 21 | 24.1s |  |
| 63 | `static_vs_dynamic1` | 17 | 20.8s |  |
| 64 | `static_vs_dynamic2` | 18 | 17.7s |  |
| 65 | `timeline_var_test` | 11 | 17.4s |  |
| 66 | `unload_movieclip_test1` | 6 | 17.1s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 19.2s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 18.9s |  |
| 4 | `DefineTextTest` | 4 | 4 | 19.5s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.9s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 22.2s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 18.9s |  |
| 9 | `callFunction_test` | 6 | 11 | 21.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 28.1s |  |
| 11 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.6s |  |
| 12 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.9s |  |
| 13 | `duplicate_movie_clip_test` | 4 | 4 | 18.9s |  |
| 14 | `init_action/InitActionTest` | 6 | 17 | 21.3s |  |
| 15 | `init_action/InitActionTest2` | 24 | 30 | 22.6s |  |
| 16 | `key_event_test` | 5 | 6 | 24.6s |  |
| 17 | `loading/LoadBitmapTest` | 3 | 3 | 23.9s |  |
| 18 | `loading/loadMovieTest` | 9 | 9 | 5.5s |  |
| 19 | `loop/loop_test10` | 23 | 23 | 18.5s |  |
| 20 | `loop/loop_test6` | 1 | 12 | 21.8s |  |
| 21 | `loop/loop_test7` | 1 | 8 | 3.1s |  |
| 22 | `matrix_test` | 5 | 9 | 108.5s |  |
| 23 | `path_format_test` | 28 | 28 | 19.7s |  |
| 24 | `place_object_test` | 14 | 14 | 22.9s |  |
| 25 | `place_object_test2` | 22 | 23 | 22.6s |  |
| 26 | `register_class/registerClassTest2` | 8 | 28 | 22.5s |  |
| 27 | `replace_buttons1test` | 3 | 3 | 21.2s |  |

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

**14 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
| 4 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 5 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 6 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 7 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 8 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 9 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 10 | `register_class/RegisterClassTest4` | 10.5% | 6/57 | 57 | 42 |  |
| 11 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 9.5% | 10/105 | 105 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 5.5% | 4/73 | 73 | 62 |  |
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
