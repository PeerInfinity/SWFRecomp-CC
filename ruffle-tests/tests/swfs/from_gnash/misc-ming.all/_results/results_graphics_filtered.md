# Ruffle Test Results (Filtered)

**Date**: 2026-09-11 21:09 UTC

**Git SHA**: `0ccafbc4eb`

**Run Duration**: 24m 48s

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
| 1 | `BeginBitmapFill` | 1 | 19.9s |  |
| 2 | `DefineEditTextTest` | 153 | 25.5s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 23.0s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 20.5s |  |
| 5 | `DepthLimitsTest` | 20 | 24.5s |  |
| 6 | `PlaceObject2Test` | 9 | 2.2s |  |
| 7 | `ResolveEventsTest` | 15 | 3.6s |  |
| 8 | `RollOverOutTest` | 5 | 3.3s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.4s |  |
| 10 | `Version4Loader` | 11 | 2.4s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 17.9s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 23.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.7s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 3.1s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.9s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 22.9s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 3.2s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.6s |  |
| 20 | `attachExtImported` | 2 | 22.5s |  |
| 21 | `attachImported` | 2 | 2.8s |  |
| 22 | `attachMovieLoopingTest` | 41 | 21.5s |  |
| 23 | `attachMovieTest` | 12 | 22.1s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 23.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 2.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 3.1s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 3.2s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 3.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 3.0s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.2s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 3.5s |  |
| 34 | `event_handler_scope_test` | 16 | 2.9s |  |
| 35 | `frame_label_test` | 17 | 3.6s |  |
| 36 | `getTimer_test` | 8 | 21.1s |  |
| 37 | `get_frame_number_test` | 31 | 5.0s |  |
| 38 | `gotoFrame2Test` | 9 | 20.8s |  |
| 39 | `goto_frame_test` | 15 | 24.9s |  |
| 40 | `instanceNameTest` | 5 | 2.8s |  |
| 41 | `loading/LoadVarsTest` | 36 | 22.3s |  |
| 42 | `loop/loop_test` | 21 | 23.3s |  |
| 43 | `loop/loop_test2` | 15 | 3.0s |  |
| 44 | `loop/loop_test3` | 16 | 3.0s |  |
| 45 | `loop/loop_test4` | 22 | 3.1s |  |
| 46 | `loop/loop_test5` | 24 | 3.2s |  |
| 47 | `loop/loop_test8` | 38 | 5.4s |  |
| 48 | `loop/loop_test9` | 15 | 23.5s |  |
| 49 | `loop/simple_loop_test` | 0 | 5.7s |  |
| 50 | `masks_test2` | 10 | 23.6s |  |
| 51 | `morph_test1` | 0 | 28.0s |  |
| 52 | `move_object_test` | 11 | 22.9s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 22.4s |  |
| 54 | `new_child_in_unload_test` | 11 | 22.4s |  |
| 55 | `opcode_guard_test` | 18 | 22.7s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 22.7s |  |
| 57 | `place_and_remove_object_test` | 13 | 20.6s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 22.7s |  |
| 59 | `register_class/registerClassTest` | 51 | 25.1s |  |
| 60 | `replace_shapes1test` | 23 | 3.3s |  |
| 61 | `replace_sprites1test` | 21 | 0.7s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 0.7s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 0.7s |  |
| 64 | `runtime_vm_stack_test` | 9 | 22.9s |  |
| 65 | `shape_test` | 21 | 28.2s |  |
| 66 | `static_vs_dynamic1` | 17 | 2.8s |  |
| 67 | `static_vs_dynamic2` | 18 | 18.1s |  |
| 68 | `timeline_var_test` | 11 | 2.5s |  |
| 69 | `unload_movieclip_test1` | 6 | 2.3s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 22.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 6.3s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.3s |  |
| 4 | `DefineTextTest` | 4 | 4 | 2.4s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.2s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 3.2s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 27.3s |  |
| 9 | `action_order/action_execution_order_test` | 12 | 12 | 3.7s |  |
| 10 | `action_order/action_execution_order_test4` | 7 | 26 | 24.2s |  |
| 11 | `callFunction_test` | 6 | 11 | 3.9s |  |
| 12 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 31.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 3.3s |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.2s |  |
| 15 | `duplicate_movie_clip_test` | 4 | 4 | 3.8s |  |
| 16 | `init_action/InitActionTest` | 6 | 17 | 23.6s |  |
| 17 | `init_action/InitActionTest2` | 24 | 30 | 25.0s |  |
| 18 | `key_event_test` | 5 | 6 | 20.7s |  |
| 19 | `loading/LoadBitmapTest` | 3 | 3 | 20.2s |  |
| 20 | `loading/loadMovieTest` | 9 | 9 | 4.9s |  |
| 21 | `loop/loop_test10` | 23 | 23 | 23.8s |  |
| 22 | `loop/loop_test6` | 1 | 12 | 20.2s |  |
| 23 | `loop/loop_test7` | 1 | 8 | 2.8s |  |
| 24 | `matrix_test` | 5 | 9 | 114.1s |  |
| 25 | `path_format_test` | 28 | 28 | 5.5s |  |
| 26 | `place_object_test` | 14 | 14 | 3.8s |  |
| 27 | `place_object_test2` | 22 | 23 | 3.1s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 20.3s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 2.9s |  |

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
