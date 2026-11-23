# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 02:55 UTC

**Git SHA**: `876e667041`

**Run Duration**: 24m 32s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **69** (62.7%) |
| Ruffle-matched | 34 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **103** (93.6%) |
| Failing | 7 |
| Total expected lines | 5206 |
| Matching lines | 4256 (81.8%) |
| Mismatched lines | 950 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.0s |  |
| 2 | `DefineEditTextTest` | 153 | 24.1s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 21.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.7s |  |
| 5 | `DepthLimitsTest` | 20 | 19.1s |  |
| 6 | `PlaceObject2Test` | 9 | 15.3s |  |
| 7 | `ResolveEventsTest` | 15 | 18.8s |  |
| 8 | `RollOverOutTest` | 5 | 18.5s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 10 | `Version4Loader` | 11 | 1.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.3s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 18.3s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 18.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 16.1s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.2s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 1.4s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 1.7s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.3s |  |
| 20 | `attachExtImported` | 2 | 19.0s |  |
| 21 | `attachImported` | 2 | 1.4s |  |
| 22 | `attachMovieLoopingTest` | 41 | 18.5s |  |
| 23 | `attachMovieTest` | 12 | 18.6s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 1.5s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.7s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.9s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.8s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.7s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 2.1s |  |
| 34 | `event_handler_scope_test` | 16 | 1.6s |  |
| 35 | `frame_label_test` | 17 | 22.2s |  |
| 36 | `getTimer_test` | 8 | 22.3s |  |
| 37 | `get_frame_number_test` | 31 | 24.3s |  |
| 38 | `gotoFrame2Test` | 9 | 19.9s |  |
| 39 | `goto_frame_test` | 15 | 23.9s |  |
| 40 | `instanceNameTest` | 5 | 1.9s |  |
| 41 | `loading/LoadVarsTest` | 36 | 22.2s |  |
| 42 | `loop/loop_test` | 21 | 18.2s |  |
| 43 | `loop/loop_test2` | 15 | 17.9s |  |
| 44 | `loop/loop_test3` | 16 | 1.4s |  |
| 45 | `loop/loop_test4` | 22 | 2.9s |  |
| 46 | `loop/loop_test5` | 24 | 3.0s |  |
| 47 | `loop/loop_test8` | 38 | 4.5s |  |
| 48 | `loop/loop_test9` | 15 | 23.6s |  |
| 49 | `loop/simple_loop_test` | 0 | 1.7s |  |
| 50 | `masks_test2` | 10 | 17.0s |  |
| 51 | `morph_test1` | 0 | 16.0s |  |
| 52 | `move_object_test` | 11 | 18.2s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 18.2s |  |
| 54 | `new_child_in_unload_test` | 11 | 1.5s |  |
| 55 | `opcode_guard_test` | 18 | 20.2s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 19.6s |  |
| 57 | `place_and_remove_object_test` | 13 | 22.9s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 19.1s |  |
| 59 | `register_class/registerClassTest` | 51 | 20.9s |  |
| 60 | `replace_shapes1test` | 23 | 1.8s |  |
| 61 | `replace_sprites1test` | 21 | 2.1s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 1.5s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 15.8s |  |
| 64 | `runtime_vm_stack_test` | 9 | 0.7s |  |
| 65 | `shape_test` | 21 | 17.5s |  |
| 66 | `static_vs_dynamic1` | 17 | 0.6s |  |
| 67 | `static_vs_dynamic2` | 18 | 17.7s |  |
| 68 | `timeline_var_test` | 11 | 1.5s |  |
| 69 | `unload_movieclip_test1` | 6 | 1.3s |  |

## Ruffle-Matched Tests

**34 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 4.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 21.0s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 1.4s |  |
| 4 | `DefineTextTest` | 4 | 4 | 18.4s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.3s |  |
| 6 | `DrawingApiTest` | 1 | 14 | 4.5s |  |
| 7 | `EmbeddedFontTest` | 27 | 27 | 21.3s |  |
| 8 | `KeyEventOrder` | 20 | 23 | 15.8s |  |
| 9 | `NetStream-SquareTest` | 79 | 92 | 23.1s |  |
| 10 | `PrototypeEventListeners` | 23 | 23 | 17.9s |  |
| 11 | `TextSnapshotTest` | 81 | 90 | 24.2s |  |
| 12 | `action_order/action_execution_order_test` | 12 | 12 | 18.5s |  |
| 13 | `action_order/action_execution_order_test4` | 7 | 26 | 16.7s |  |
| 14 | `action_order/action_execution_order_test6` | 5 | 21 | 16.9s |  |
| 15 | `callFunction_test` | 6 | 11 | 2.0s |  |
| 16 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.0s |  |
| 17 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 17.9s |  |
| 18 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.7s |  |
| 19 | `duplicate_movie_clip_test` | 4 | 4 | 2.4s |  |
| 20 | `init_action/InitActionTest` | 6 | 17 | 23.8s |  |
| 21 | `init_action/InitActionTest2` | 24 | 30 | 24.9s |  |
| 22 | `key_event_test` | 5 | 6 | 20.1s |  |
| 23 | `loading/LoadBitmapTest` | 3 | 3 | 19.5s |  |
| 24 | `loading/loadMovieTest` | 9 | 9 | 3.5s |  |
| 25 | `loop/loop_test10` | 23 | 23 | 18.5s |  |
| 26 | `loop/loop_test6` | 11 | 12 | 2.8s |  |
| 27 | `loop/loop_test7` | 1 | 8 | 2.4s |  |
| 28 | `masks_test` | 16 | 16 | 34.8s |  |
| 29 | `matrix_test` | 5 | 9 | 85.8s |  |
| 30 | `path_format_test` | 28 | 28 | 22.1s |  |
| 31 | `place_object_test` | 14 | 14 | 2.4s |  |
| 32 | `place_object_test2` | 22 | 23 | 23.3s |  |
| 33 | `register_class/registerClassTest2` | 8 | 28 | 19.4s |  |
| 34 | `replace_buttons1test` | 3 | 3 | 1.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 3 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 4 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 5 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 6 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 7 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
