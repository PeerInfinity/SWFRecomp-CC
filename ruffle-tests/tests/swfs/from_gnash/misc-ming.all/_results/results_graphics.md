# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-22 03:10 UTC

**Git SHA**: `6b2054090f`

**Run Duration**: 29m 38s

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
| 1 | `BeginBitmapFill` | 1 | 20.1s |  |
| 2 | `DefineEditTextTest` | 153 | 25.1s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 22.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 20.2s |  |
| 5 | `DepthLimitsTest` | 20 | 19.8s |  |
| 6 | `PlaceObject2Test` | 9 | 17.8s |  |
| 7 | `ResolveEventsTest` | 15 | 19.2s |  |
| 8 | `RollOverOutTest` | 5 | 19.2s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.9s |  |
| 10 | `Version4Loader` | 11 | 1.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.2s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 16.3s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 17.6s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.2s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 4.1s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 18.6s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 18.9s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.9s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.0s |  |
| 20 | `attachExtImported` | 2 | 18.9s |  |
| 21 | `attachImported` | 2 | 2.0s |  |
| 22 | `attachMovieLoopingTest` | 41 | 18.2s |  |
| 23 | `attachMovieTest` | 12 | 18.5s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 17.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.0s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.6s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.6s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.0s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.8s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 19.1s |  |
| 34 | `event_handler_scope_test` | 16 | 2.3s |  |
| 35 | `frame_label_test` | 17 | 20.3s |  |
| 36 | `getTimer_test` | 8 | 18.9s |  |
| 37 | `get_frame_number_test` | 31 | 21.3s |  |
| 38 | `gotoFrame2Test` | 9 | 18.8s |  |
| 39 | `goto_frame_test` | 15 | 19.3s |  |
| 40 | `instanceNameTest` | 5 | 2.0s |  |
| 41 | `loading/LoadVarsTest` | 36 | 20.6s |  |
| 42 | `loop/loop_test` | 21 | 17.8s |  |
| 43 | `loop/loop_test2` | 15 | 17.7s |  |
| 44 | `loop/loop_test3` | 16 | 1.9s |  |
| 45 | `loop/loop_test4` | 22 | 18.4s |  |
| 46 | `loop/loop_test5` | 24 | 2.7s |  |
| 47 | `loop/loop_test8` | 38 | 19.4s |  |
| 48 | `loop/loop_test9` | 15 | 18.1s |  |
| 49 | `loop/simple_loop_test` | 0 | 19.0s |  |
| 50 | `masks_test2` | 10 | 19.1s |  |
| 51 | `morph_test1` | 0 | 21.9s |  |
| 52 | `move_object_test` | 11 | 17.2s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 16.4s |  |
| 54 | `new_child_in_unload_test` | 11 | 16.4s |  |
| 55 | `opcode_guard_test` | 18 | 18.6s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 18.5s |  |
| 57 | `place_and_remove_object_test` | 13 | 18.4s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 18.6s |  |
| 59 | `register_class/registerClassTest` | 51 | 20.4s |  |
| 60 | `replace_shapes1test` | 23 | 2.3s |  |
| 61 | `replace_sprites1test` | 21 | 14.0s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 14.2s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 14.1s |  |
| 64 | `runtime_vm_stack_test` | 9 | 17.9s |  |
| 65 | `shape_test` | 21 | 19.0s |  |
| 66 | `static_vs_dynamic1` | 17 | 17.4s |  |
| 67 | `static_vs_dynamic2` | 18 | 18.3s |  |
| 68 | `timeline_var_test` | 11 | 18.4s |  |
| 69 | `unload_movieclip_test1` | 6 | 18.3s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 22.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 23.4s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.6s |  |
| 4 | `DefineTextTest` | 4 | 4 | 18.6s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 22.3s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 17.9s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 24.6s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 18.4s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.5s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 16.5s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 20.8s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 20.6s |  |
| 14 | `callFunction_test` | 6 | 11 | 18.5s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.2s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.0s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.6s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 19.0s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 19.2s |  |
| 20 | `init_action/InitActionTest2` | 24 | 30 | 20.2s |  |
| 21 | `key_event_test` | 5 | 6 | 19.8s |  |
| 22 | `loading/LoadBitmapTest` | 3 | 3 | 19.0s |  |
| 23 | `loading/loadMovieTest` | 9 | 9 | 3.5s |  |
| 24 | `loop/loop_test10` | 23 | 23 | 18.4s |  |
| 25 | `loop/loop_test6` | 11 | 12 | 18.5s |  |
| 26 | `loop/loop_test7` | 1 | 8 | 2.3s |  |
| 27 | `masks_test` | 16 | 16 | 25.4s |  |
| 28 | `matrix_test` | 5 | 9 | 97.8s |  |
| 29 | `path_format_test` | 28 | 28 | 19.9s |  |
| 30 | `place_object_test` | 14 | 14 | 2.9s |  |
| 31 | `place_object_test2` | 22 | 23 | 18.7s |  |
| 32 | `register_class/registerClassTest2` | 8 | 28 | 18.9s |  |
| 33 | `replace_buttons1test` | 3 | 3 | 18.1s |  |

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
