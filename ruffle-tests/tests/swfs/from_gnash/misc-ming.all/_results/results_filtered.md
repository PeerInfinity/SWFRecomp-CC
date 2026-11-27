# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 03:57 UTC

**Git SHA**: `dbc43c1573`

**Run Duration**: 28m 16s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **74** (67.3%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (92.7%) |
| Failing | 8 |
| Total expected lines | 5206 |
| Matching lines | 4357 (83.7%) |
| Mismatched lines | 849 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**74 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.3s |  |
| 2 | `BitmapDataDraw` | 56 | 5.9s |  |
| 3 | `DefineEditTextTest` | 153 | 25.7s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 22.9s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 20.8s |  |
| 6 | `DepthLimitsTest` | 20 | 21.1s |  |
| 7 | `PlaceObject2Test` | 9 | 19.9s |  |
| 8 | `ResolveEventsTest` | 15 | 19.8s |  |
| 9 | `RollOverOutTest` | 5 | 19.6s |  |
| 10 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 11 | `Version4Loader` | 11 | 1.4s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 19.1s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 21.8s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 21.9s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 19.5s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 2.0s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 21.7s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 21.9s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 0.5s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 21 | `attachExtImported` | 2 | 21.8s |  |
| 22 | `attachImported` | 2 | 1.8s |  |
| 23 | `attachMovieLoopingTest` | 41 | 20.3s |  |
| 24 | `attachMovieTest` | 12 | 20.5s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 18.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.8s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.7s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.4s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.4s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 20.5s |  |
| 35 | `event_handler_scope_test` | 16 | 1.7s |  |
| 36 | `frame_label_test` | 17 | 21.1s |  |
| 37 | `getTimer_test` | 8 | 2.0s |  |
| 38 | `get_frame_number_test` | 31 | 22.0s |  |
| 39 | `gotoFrame2Test` | 9 | 19.8s |  |
| 40 | `goto_frame_test` | 15 | 21.4s |  |
| 41 | `init_action/InitActionTest2` | 29 | 23.7s |  |
| 42 | `instanceNameTest` | 5 | 1.9s |  |
| 43 | `loading/LoadVarsTest` | 36 | 21.3s |  |
| 44 | `loop/loop_test` | 21 | 21.0s |  |
| 45 | `loop/loop_test2` | 15 | 21.1s |  |
| 46 | `loop/loop_test3` | 16 | 1.8s |  |
| 47 | `loop/loop_test4` | 22 | 2.6s |  |
| 48 | `loop/loop_test5` | 24 | 2.8s |  |
| 49 | `loop/loop_test8` | 38 | 20.6s |  |
| 50 | `loop/loop_test9` | 15 | 19.2s |  |
| 51 | `loop/simple_loop_test` | 0 | 19.0s |  |
| 52 | `masks_test2` | 10 | 19.8s |  |
| 53 | `matrix_test` | 1086 | 84.0s |  |
| 54 | `morph_test1` | 0 | 19.6s |  |
| 55 | `move_object_test` | 11 | 19.1s |  |
| 56 | `multi_doactions_and_goto_frame_test` | 6 | 19.1s |  |
| 57 | `new_child_in_unload_test` | 11 | 1.5s |  |
| 58 | `opcode_guard_test` | 18 | 22.6s |  |
| 59 | `place_and_remove_object_insane_test` | 22 | 22.9s |  |
| 60 | `place_and_remove_object_test` | 13 | 18.9s |  |
| 61 | `place_object_test` | 12 | 2.1s |  |
| 62 | `place_object_test2` | 19 | 18.8s |  |
| 63 | `register_class/RegisterClassTest3` | 12 | 1.9s |  |
| 64 | `register_class/registerClassTest` | 51 | 21.6s |  |
| 65 | `replace_shapes1test` | 23 | 2.0s |  |
| 66 | `replace_sprites1test` | 21 | 21.5s |  |
| 67 | `reverse_execute_PlaceObject2_test1` | 8 | 1.9s |  |
| 68 | `reverse_execute_PlaceObject2_test2` | 10 | 21.5s |  |
| 69 | `runtime_vm_stack_test` | 9 | 1.8s |  |
| 70 | `shape_test` | 21 | 20.4s |  |
| 71 | `static_vs_dynamic1` | 17 | 19.2s |  |
| 72 | `static_vs_dynamic2` | 18 | 20.3s |  |
| 73 | `timeline_var_test` | 11 | 1.7s |  |
| 74 | `unload_movieclip_test1` | 6 | 19.9s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 25.9s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.0s |  |
| 3 | `DefineTextTest` | 4 | 4 | 19.1s |  |
| 4 | `DragDropTest` | 4 | 4 | 2.5s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 5.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 23.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 1.8s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 27.4s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 19.2s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.3s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 22.2s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 19.9s |  |
| 13 | `callFunction_test` | 6 | 11 | 19.4s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.8s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.0s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.5s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 2.6s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 21.5s |  |
| 19 | `key_event_test` | 5 | 6 | 20.3s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 19.8s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 2.9s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 21.6s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 2.6s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 2.2s |  |
| 25 | `masks_test` | 16 | 16 | 26.2s |  |
| 26 | `path_format_test` | 7 | 28 | 24.4s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 19.5s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 18.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 2 | `action_order/action_execution_order_test4` | 73.1% | 19 | 26 | 7 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `action_order/action_execution_order_test4` | 73.1% | 19/26 | 26 | 26 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 30 | 32 |  |
| 5 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 7 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 8 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
