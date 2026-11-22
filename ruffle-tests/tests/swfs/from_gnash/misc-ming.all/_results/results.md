# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 23:52 UTC

**Git SHA**: `161ecf1240`

**Run Duration**: 29m 2s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 33 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (91.9%) |
| Failing | 9 |
| Total expected lines | 5248 |
| Matching lines | 4252 (81.0%) |
| Mismatched lines | 996 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 17.6s |  |
| 2 | `DefineEditTextTest` | 153 | 27.2s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 24.1s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 21.1s |  |
| 5 | `DepthLimitsTest` | 20 | 22.4s |  |
| 6 | `PlaceObject2Test` | 9 | 17.6s |  |
| 7 | `ResolveEventsTest` | 15 | 17.8s |  |
| 8 | `RollOverOutTest` | 5 | 17.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.5s |  |
| 10 | `Version4Loader` | 11 | 2.4s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 26.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.9s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.9s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 16.8s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 1.9s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 17.4s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 1.8s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.4s |  |
| 20 | `attachExtImported` | 2 | 18.4s |  |
| 21 | `attachImported` | 2 | 1.3s |  |
| 22 | `attachMovieLoopingTest` | 41 | 17.4s |  |
| 23 | `attachMovieTest` | 12 | 17.8s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 16.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 16.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 17.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.4s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.4s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.1s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 18.5s |  |
| 34 | `event_handler_scope_test` | 16 | 1.7s |  |
| 35 | `frame_label_test` | 17 | 31.0s |  |
| 36 | `getTimer_test` | 8 | 29.4s |  |
| 37 | `get_frame_number_test` | 31 | 31.8s |  |
| 38 | `gotoFrame2Test` | 9 | 2.4s |  |
| 39 | `goto_frame_test` | 15 | 18.2s |  |
| 40 | `instanceNameTest` | 5 | 1.4s |  |
| 41 | `loading/LoadVarsTest` | 36 | 19.8s |  |
| 42 | `loop/loop_test` | 21 | 23.9s |  |
| 43 | `loop/loop_test2` | 15 | 23.7s |  |
| 44 | `loop/loop_test3` | 16 | 2.2s |  |
| 45 | `loop/loop_test4` | 22 | 18.0s |  |
| 46 | `loop/loop_test5` | 24 | 2.1s |  |
| 47 | `loop/loop_test8` | 38 | 19.0s |  |
| 48 | `loop/loop_test9` | 15 | 17.5s |  |
| 49 | `loop/simple_loop_test` | 0 | 17.4s |  |
| 50 | `masks_test2` | 10 | 16.8s |  |
| 51 | `morph_test1` | 0 | 16.9s |  |
| 52 | `move_object_test` | 11 | 17.0s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 17.2s |  |
| 54 | `new_child_in_unload_test` | 11 | 17.4s |  |
| 55 | `opcode_guard_test` | 18 | 17.3s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 17.3s |  |
| 57 | `place_and_remove_object_test` | 13 | 17.0s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 17.5s |  |
| 59 | `register_class/registerClassTest` | 51 | 19.0s |  |
| 60 | `replace_shapes1test` | 23 | 2.4s |  |
| 61 | `replace_sprites1test` | 21 | 17.8s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 1.4s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 17.6s |  |
| 64 | `runtime_vm_stack_test` | 9 | 17.3s |  |
| 65 | `shape_test` | 21 | 18.0s |  |
| 66 | `static_vs_dynamic1` | 17 | 17.0s |  |
| 67 | `static_vs_dynamic2` | 18 | 19.0s |  |
| 68 | `timeline_var_test` | 11 | 18.8s |  |
| 69 | `unload_movieclip_test1` | 6 | 18.3s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.6s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 20.4s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 1.4s |  |
| 4 | `DefineTextTest` | 4 | 4 | 18.9s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 25.3s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 18.1s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 25.0s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 17.2s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 23.3s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 23.2s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 17.5s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 17.4s |  |
| 14 | `callFunction_test` | 6 | 11 | 17.5s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 22.0s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 17.6s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.5s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 18.9s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 17.9s |  |
| 20 | `init_action/InitActionTest2` | 24 | 30 | 18.6s |  |
| 21 | `key_event_test` | 5 | 6 | 18.5s |  |
| 22 | `loading/LoadBitmapTest` | 3 | 3 | 18.4s |  |
| 23 | `loading/loadMovieTest` | 9 | 9 | 3.0s |  |
| 24 | `loop/loop_test10` | 23 | 23 | 24.7s |  |
| 25 | `loop/loop_test6` | 11 | 12 | 17.9s |  |
| 26 | `loop/loop_test7` | 1 | 8 | 1.7s |  |
| 27 | `masks_test` | 16 | 16 | 25.6s |  |
| 28 | `matrix_test` | 5 | 9 | 73.2s |  |
| 29 | `path_format_test` | 28 | 28 | 18.7s |  |
| 30 | `place_object_test` | 14 | 14 | 1.6s |  |
| 31 | `place_object_test2` | 22 | 23 | 17.2s |  |
| 32 | `register_class/registerClassTest2` | 8 | 28 | 20.4s |  |
| 33 | `replace_buttons1test` | 3 | 3 | 19.5s |  |

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

**9 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 5 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 6 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 7 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 8 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 9 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
