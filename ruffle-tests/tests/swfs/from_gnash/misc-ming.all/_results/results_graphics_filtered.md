# Ruffle Test Results (Filtered)

**Date**: 2026-09-28 21:10 UTC

**Git SHA**: `1b7a987cf4`

**Run Duration**: 33m 19s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **69** (62.7%) |
| Ruffle-matched | 31 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **100** (90.9%) |
| Failing | 10 |
| Total expected lines | 5206 |
| Matching lines | 4190 (80.5%) |
| Mismatched lines | 1016 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 23.8s |  |
| 2 | `DefineEditTextTest` | 153 | 20.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 18.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 15.8s |  |
| 5 | `DepthLimitsTest` | 20 | 19.8s |  |
| 6 | `PlaceObject2Test` | 9 | 22.7s |  |
| 7 | `ResolveEventsTest` | 15 | 23.7s |  |
| 8 | `RollOverOutTest` | 5 | 23.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 3.0s |  |
| 10 | `Version4Loader` | 11 | 3.0s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 25.6s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 17.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 17.7s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.1s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.1s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 22.5s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 22.9s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.6s |  |
| 20 | `attachExtImported` | 2 | 19.1s |  |
| 21 | `attachImported` | 2 | 2.9s |  |
| 22 | `attachMovieLoopingTest` | 41 | 19.8s |  |
| 23 | `attachMovieTest` | 12 | 20.6s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 17.7s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.8s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 21.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.5s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.4s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 17.8s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 17.8s |  |
| 34 | `event_handler_scope_test` | 16 | 2.7s |  |
| 35 | `frame_label_test` | 17 | 24.7s |  |
| 36 | `getTimer_test` | 8 | 23.4s |  |
| 37 | `get_frame_number_test` | 31 | 26.0s |  |
| 38 | `gotoFrame2Test` | 9 | 23.2s |  |
| 39 | `goto_frame_test` | 15 | 23.3s |  |
| 40 | `instanceNameTest` | 5 | 2.8s |  |
| 41 | `loading/LoadVarsTest` | 36 | 27.0s |  |
| 42 | `loop/loop_test` | 21 | 19.5s |  |
| 43 | `loop/loop_test2` | 15 | 19.1s |  |
| 44 | `loop/loop_test3` | 16 | 2.2s |  |
| 45 | `loop/loop_test4` | 22 | 26.4s |  |
| 46 | `loop/loop_test5` | 24 | 4.5s |  |
| 47 | `loop/loop_test8` | 38 | 24.5s |  |
| 48 | `loop/loop_test9` | 15 | 22.2s |  |
| 49 | `loop/simple_loop_test` | 0 | 24.6s |  |
| 50 | `masks_test2` | 10 | 14.2s |  |
| 51 | `morph_test1` | 0 | 16.9s |  |
| 52 | `move_object_test` | 11 | 22.8s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 22.8s |  |
| 54 | `new_child_in_unload_test` | 11 | 22.8s |  |
| 55 | `opcode_guard_test` | 18 | 19.2s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 19.2s |  |
| 57 | `place_and_remove_object_test` | 13 | 17.7s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 19.6s |  |
| 59 | `register_class/registerClassTest` | 51 | 21.3s |  |
| 60 | `replace_shapes1test` | 23 | 1.1s |  |
| 61 | `replace_sprites1test` | 21 | 17.5s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 17.3s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 17.2s |  |
| 64 | `runtime_vm_stack_test` | 9 | 23.3s |  |
| 65 | `shape_test` | 21 | 25.6s |  |
| 66 | `static_vs_dynamic1` | 17 | 23.1s |  |
| 67 | `static_vs_dynamic2` | 18 | 24.8s |  |
| 68 | `timeline_var_test` | 11 | 24.4s |  |
| 69 | `unload_movieclip_test1` | 6 | 24.5s |  |

## Ruffle-Matched Tests

**31 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 27.7s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 28.3s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 3.0s |  |
| 4 | `DefineTextTest` | 4 | 4 | 14.0s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.5s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 22.9s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 23.2s |  |
| 8 | `PrototypeEventListeners` | 23 | 23 | 22.6s |  |
| 9 | `TextSnapshotTest` | 81 | 90 | 32.8s |  |
| 10 | `action_order/action_execution_order_test` | 12 | 12 | 18.1s |  |
| 11 | `action_order/action_execution_order_test4` | 7 | 26 | 21.1s |  |
| 12 | `callFunction_test` | 6 | 11 | 18.3s |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.1s |  |
| 14 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.8s |  |
| 15 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.7s |  |
| 16 | `duplicate_movie_clip_test` | 4 | 4 | 17.9s |  |
| 17 | `init_action/InitActionTest` | 6 | 17 | 22.8s |  |
| 18 | `init_action/InitActionTest2` | 24 | 30 | 24.1s |  |
| 19 | `key_event_test` | 5 | 6 | 25.5s |  |
| 20 | `loading/LoadBitmapTest` | 3 | 3 | 24.4s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 5.2s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 20.1s |  |
| 23 | `loop/loop_test6` | 1 | 12 | 25.1s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 3.7s |  |
| 25 | `masks_test` | 16 | 16 | 33.0s |  |
| 26 | `matrix_test` | 5 | 9 | 73.6s |  |
| 27 | `path_format_test` | 28 | 28 | 21.2s |  |
| 28 | `place_object_test` | 14 | 14 | 3.1s |  |
| 29 | `place_object_test2` | 22 | 23 | 17.2s |  |
| 30 | `register_class/registerClassTest2` | 8 | 28 | 20.7s |  |
| 31 | `replace_buttons1test` | 3 | 3 | 20.6s |  |

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

**10 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 5 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 7 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 8 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 9 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
| 10 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
