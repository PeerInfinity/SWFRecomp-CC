# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-22 02:31 UTC

**Git SHA**: `336749f142`

**Run Duration**: 32m 1s

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
| 1 | `BeginBitmapFill` | 1 | 24.8s |  |
| 2 | `DefineEditTextTest` | 153 | 26.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 23.3s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 21.0s |  |
| 5 | `DepthLimitsTest` | 20 | 18.8s |  |
| 6 | `PlaceObject2Test` | 9 | 19.0s |  |
| 7 | `ResolveEventsTest` | 15 | 18.9s |  |
| 8 | `RollOverOutTest` | 5 | 18.5s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.0s |  |
| 10 | `Version4Loader` | 11 | 1.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.2s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 18.4s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 18.4s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 18.3s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.6s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 24.7s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 25.4s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.4s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 3.1s |  |
| 20 | `attachExtImported` | 2 | 18.3s |  |
| 21 | `attachImported` | 2 | 1.9s |  |
| 22 | `attachMovieLoopingTest` | 41 | 17.7s |  |
| 23 | `attachMovieTest` | 12 | 18.1s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 23.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 24.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 15.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.8s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.1s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 21.3s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 21.5s |  |
| 34 | `event_handler_scope_test` | 16 | 3.0s |  |
| 35 | `frame_label_test` | 17 | 18.8s |  |
| 36 | `getTimer_test` | 8 | 17.9s |  |
| 37 | `get_frame_number_test` | 31 | 19.5s |  |
| 38 | `gotoFrame2Test` | 9 | 17.8s |  |
| 39 | `goto_frame_test` | 15 | 18.7s |  |
| 40 | `instanceNameTest` | 5 | 1.9s |  |
| 41 | `loading/LoadVarsTest` | 36 | 19.8s |  |
| 42 | `loop/loop_test` | 21 | 17.7s |  |
| 43 | `loop/loop_test2` | 15 | 17.6s |  |
| 44 | `loop/loop_test3` | 16 | 1.9s |  |
| 45 | `loop/loop_test4` | 22 | 25.4s |  |
| 46 | `loop/loop_test5` | 24 | 4.5s |  |
| 47 | `loop/loop_test8` | 38 | 19.8s |  |
| 48 | `loop/loop_test9` | 15 | 18.1s |  |
| 49 | `loop/simple_loop_test` | 0 | 19.0s |  |
| 50 | `masks_test2` | 10 | 17.8s |  |
| 51 | `morph_test1` | 0 | 19.3s |  |
| 52 | `move_object_test` | 11 | 26.2s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 26.1s |  |
| 54 | `new_child_in_unload_test` | 11 | 25.8s |  |
| 55 | `opcode_guard_test` | 18 | 24.4s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 24.4s |  |
| 57 | `place_and_remove_object_test` | 13 | 24.0s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 21.1s |  |
| 59 | `register_class/registerClassTest` | 51 | 25.9s |  |
| 60 | `replace_shapes1test` | 23 | 2.5s |  |
| 61 | `replace_sprites1test` | 21 | 15.1s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 15.0s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 15.2s |  |
| 64 | `runtime_vm_stack_test` | 9 | 17.7s |  |
| 65 | `shape_test` | 21 | 18.6s |  |
| 66 | `static_vs_dynamic1` | 17 | 17.2s |  |
| 67 | `static_vs_dynamic2` | 18 | 24.6s |  |
| 68 | `timeline_var_test` | 11 | 24.2s |  |
| 69 | `unload_movieclip_test1` | 6 | 24.0s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 27.6s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 28.6s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.8s |  |
| 4 | `DefineTextTest` | 4 | 4 | 19.6s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.8s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 20.8s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 19.6s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 28.7s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 18.1s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.1s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 18.6s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 19.0s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 18.9s |  |
| 14 | `callFunction_test` | 6 | 11 | 24.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 32.2s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.4s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.1s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 21.7s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 18.4s |  |
| 20 | `init_action/InitActionTest2` | 24 | 30 | 19.3s |  |
| 21 | `key_event_test` | 5 | 6 | 19.4s |  |
| 22 | `loading/LoadBitmapTest` | 3 | 3 | 18.3s |  |
| 23 | `loading/loadMovieTest` | 9 | 9 | 3.4s |  |
| 24 | `loop/loop_test10` | 23 | 23 | 18.4s |  |
| 25 | `loop/loop_test6` | 11 | 12 | 25.3s |  |
| 26 | `loop/loop_test7` | 1 | 8 | 3.7s |  |
| 27 | `masks_test` | 16 | 16 | 25.4s |  |
| 28 | `matrix_test` | 5 | 9 | 77.2s |  |
| 29 | `path_format_test` | 28 | 28 | 26.9s |  |
| 30 | `place_object_test` | 14 | 14 | 3.8s |  |
| 31 | `place_object_test2` | 22 | 23 | 23.9s |  |
| 32 | `register_class/registerClassTest2` | 8 | 28 | 20.0s |  |
| 33 | `replace_buttons1test` | 3 | 3 | 19.1s |  |

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
