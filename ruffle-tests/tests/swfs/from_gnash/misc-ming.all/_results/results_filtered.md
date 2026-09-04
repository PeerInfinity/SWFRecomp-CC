# Ruffle Test Results (Filtered)

**Date**: 2026-09-04 09:14 UTC

**Git SHA**: `2002bc3ece`

**Run Duration**: 33m 2s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **69** (62.7%) |
| Ruffle-matched | 29 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **98** (89.1%) |
| Failing | 12 |
| Total expected lines | 5206 |
| Matching lines | 4051 (77.8%) |
| Mismatched lines | 1155 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 12 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 17.2s |  |
| 2 | `DefineEditTextTest` | 153 | 31.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.4s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.5s |  |
| 5 | `DepthLimitsTest` | 20 | 22.4s |  |
| 6 | `PlaceObject2Test` | 9 | 15.6s |  |
| 7 | `ResolveEventsTest` | 15 | 22.4s |  |
| 8 | `RollOverOutTest` | 5 | 21.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.6s |  |
| 10 | `Version4Loader` | 11 | 1.6s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.3s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.0s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 21.4s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.9s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 20.9s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 21.8s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.5s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.0s |  |
| 20 | `attachExtImported` | 2 | 21.8s |  |
| 21 | `attachImported` | 2 | 2.0s |  |
| 22 | `attachMovieLoopingTest` | 41 | 20.9s |  |
| 23 | `attachMovieTest` | 12 | 21.7s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 21.6s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.1s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 23.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.6s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.1s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 21.4s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 21.9s |  |
| 34 | `event_handler_scope_test` | 16 | 2.1s |  |
| 35 | `frame_label_test` | 17 | 23.0s |  |
| 36 | `getTimer_test` | 8 | 21.7s |  |
| 37 | `get_frame_number_test` | 31 | 24.3s |  |
| 38 | `gotoFrame2Test` | 9 | 21.3s |  |
| 39 | `goto_frame_test` | 15 | 21.8s |  |
| 40 | `instanceNameTest` | 5 | 1.8s |  |
| 41 | `loading/LoadVarsTest` | 36 | 24.9s |  |
| 42 | `loop/loop_test` | 21 | 21.1s |  |
| 43 | `loop/loop_test2` | 15 | 21.2s |  |
| 44 | `loop/loop_test3` | 16 | 2.0s |  |
| 45 | `loop/loop_test4` | 22 | 23.6s |  |
| 46 | `loop/loop_test5` | 24 | 3.3s |  |
| 47 | `loop/loop_test8` | 38 | 21.6s |  |
| 48 | `loop/loop_test9` | 15 | 19.7s |  |
| 49 | `loop/simple_loop_test` | 0 | 18.9s |  |
| 50 | `masks_test2` | 10 | 22.9s |  |
| 51 | `morph_test1` | 0 | 21.5s |  |
| 52 | `move_object_test` | 11 | 13.5s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 13.6s |  |
| 54 | `new_child_in_unload_test` | 11 | 14.0s |  |
| 55 | `opcode_guard_test` | 18 | 21.1s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 21.1s |  |
| 57 | `place_and_remove_object_test` | 13 | 14.1s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 21.7s |  |
| 59 | `register_class/registerClassTest` | 51 | 24.0s |  |
| 60 | `replace_shapes1test` | 23 | 2.4s |  |
| 61 | `replace_sprites1test` | 21 | 22.4s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 21.7s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 22.0s |  |
| 64 | `runtime_vm_stack_test` | 9 | 18.8s |  |
| 65 | `shape_test` | 21 | 19.3s |  |
| 66 | `static_vs_dynamic1` | 17 | 17.9s |  |
| 67 | `static_vs_dynamic2` | 18 | 21.4s |  |
| 68 | `timeline_var_test` | 11 | 20.9s |  |
| 69 | `unload_movieclip_test1` | 6 | 20.7s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.9s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 20.7s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 1.7s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.4s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.2s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 25.4s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 15.7s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 30.9s |  |
| 9 | `action_order/action_execution_order_test` | 12 | 12 | 22.6s |  |
| 10 | `action_order/action_execution_order_test4` | 7 | 26 | 22.6s |  |
| 11 | `callFunction_test` | 6 | 11 | 22.3s |  |
| 12 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 29.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.4s |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.2s |  |
| 15 | `duplicate_movie_clip_test` | 4 | 4 | 22.2s |  |
| 16 | `init_action/InitActionTest` | 6 | 17 | 21.4s |  |
| 17 | `init_action/InitActionTest2` | 24 | 30 | 22.6s |  |
| 18 | `key_event_test` | 5 | 6 | 22.8s |  |
| 19 | `loading/LoadBitmapTest` | 3 | 3 | 22.6s |  |
| 20 | `loading/loadMovieTest` | 9 | 9 | 4.1s |  |
| 21 | `loop/loop_test10` | 23 | 23 | 22.2s |  |
| 22 | `loop/loop_test6` | 1 | 12 | 22.9s |  |
| 23 | `loop/loop_test7` | 1 | 8 | 2.5s |  |
| 24 | `matrix_test` | 5 | 9 | 108.4s |  |
| 25 | `path_format_test` | 28 | 28 | 23.1s |  |
| 26 | `place_object_test` | 14 | 14 | 1.9s |  |
| 27 | `place_object_test2` | 22 | 23 | 14.5s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 19.4s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 17.6s |  |

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

**12 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 5 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 6 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 7 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 8 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 9 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 10 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
| 11 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 12 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
