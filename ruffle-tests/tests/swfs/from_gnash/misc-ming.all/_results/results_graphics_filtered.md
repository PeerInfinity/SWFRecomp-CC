# Ruffle Test Results (Filtered)

**Date**: 2026-09-22 21:18 UTC

**Git SHA**: `19ba533729`

**Run Duration**: 36m 12s

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
| 2 | `DefineEditTextTest` | 153 | 33.2s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 29.4s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 25.9s |  |
| 5 | `DepthLimitsTest` | 20 | 22.2s |  |
| 6 | `PlaceObject2Test` | 9 | 23.3s |  |
| 7 | `ResolveEventsTest` | 15 | 24.1s |  |
| 8 | `RollOverOutTest` | 5 | 23.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.5s |  |
| 10 | `Version4Loader` | 11 | 2.4s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.9s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.7s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 22.7s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.8s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 23.0s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 23.6s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.9s |  |
| 20 | `attachExtImported` | 2 | 21.1s |  |
| 21 | `attachImported` | 2 | 2.6s |  |
| 22 | `attachMovieLoopingTest` | 41 | 20.2s |  |
| 23 | `attachMovieTest` | 12 | 20.8s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 22.7s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 23.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 23.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 22.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 3.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.4s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.7s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 20.6s |  |
| 34 | `event_handler_scope_test` | 16 | 2.5s |  |
| 35 | `frame_label_test` | 17 | 24.2s |  |
| 36 | `getTimer_test` | 8 | 23.2s |  |
| 37 | `get_frame_number_test` | 31 | 25.5s |  |
| 38 | `gotoFrame2Test` | 9 | 22.5s |  |
| 39 | `goto_frame_test` | 15 | 19.3s |  |
| 40 | `instanceNameTest` | 5 | 2.5s |  |
| 41 | `loading/LoadVarsTest` | 36 | 27.9s |  |
| 42 | `loop/loop_test` | 21 | 31.9s |  |
| 43 | `loop/loop_test2` | 15 | 31.6s |  |
| 44 | `loop/loop_test3` | 16 | 3.1s |  |
| 45 | `loop/loop_test4` | 22 | 23.4s |  |
| 46 | `loop/loop_test5` | 24 | 4.0s |  |
| 47 | `loop/loop_test8` | 38 | 20.4s |  |
| 48 | `loop/loop_test9` | 15 | 18.3s |  |
| 49 | `loop/simple_loop_test` | 0 | 20.1s |  |
| 50 | `masks_test2` | 10 | 18.7s |  |
| 51 | `morph_test1` | 0 | 21.2s |  |
| 52 | `move_object_test` | 11 | 23.4s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 23.4s |  |
| 54 | `new_child_in_unload_test` | 11 | 23.4s |  |
| 55 | `opcode_guard_test` | 18 | 24.6s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 24.3s |  |
| 57 | `place_and_remove_object_test` | 13 | 22.5s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 24.5s |  |
| 59 | `register_class/registerClassTest` | 51 | 26.8s |  |
| 60 | `replace_shapes1test` | 23 | 1.9s |  |
| 61 | `replace_sprites1test` | 21 | 18.1s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 17.8s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 18.2s |  |
| 64 | `runtime_vm_stack_test` | 9 | 18.8s |  |
| 65 | `shape_test` | 21 | 19.7s |  |
| 66 | `static_vs_dynamic1` | 17 | 17.8s |  |
| 67 | `static_vs_dynamic2` | 18 | 23.8s |  |
| 68 | `timeline_var_test` | 11 | 22.8s |  |
| 69 | `unload_movieclip_test1` | 6 | 22.9s |  |

## Ruffle-Matched Tests

**31 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 27.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 28.5s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 3.1s |  |
| 4 | `DefineTextTest` | 4 | 4 | 23.3s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.5s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 24.3s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 23.6s |  |
| 8 | `PrototypeEventListeners` | 23 | 23 | 23.4s |  |
| 9 | `TextSnapshotTest` | 81 | 90 | 33.1s |  |
| 10 | `action_order/action_execution_order_test` | 12 | 12 | 23.0s |  |
| 11 | `action_order/action_execution_order_test4` | 7 | 26 | 23.7s |  |
| 12 | `callFunction_test` | 6 | 11 | 23.5s |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 30.7s |  |
| 14 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 24.3s |  |
| 15 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.1s |  |
| 16 | `duplicate_movie_clip_test` | 4 | 4 | 20.3s |  |
| 17 | `init_action/InitActionTest` | 6 | 17 | 18.8s |  |
| 18 | `init_action/InitActionTest2` | 24 | 30 | 19.9s |  |
| 19 | `key_event_test` | 5 | 6 | 25.4s |  |
| 20 | `loading/LoadBitmapTest` | 3 | 3 | 23.5s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 5.1s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 33.8s |  |
| 23 | `loop/loop_test6` | 1 | 12 | 23.3s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 3.4s |  |
| 25 | `masks_test` | 16 | 16 | 28.7s |  |
| 26 | `matrix_test` | 5 | 9 | 97.8s |  |
| 27 | `path_format_test` | 28 | 28 | 26.8s |  |
| 28 | `place_object_test` | 14 | 14 | 4.1s |  |
| 29 | `place_object_test2` | 22 | 23 | 22.8s |  |
| 30 | `register_class/registerClassTest2` | 8 | 28 | 18.6s |  |
| 31 | `replace_buttons1test` | 3 | 3 | 18.7s |  |

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
