# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 21:08 UTC

**Git SHA**: `f0fd711c71`

**Run Duration**: 33m 34s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 29 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **98** (88.3%) |
| Failing | 13 |
| Total expected lines | 5248 |
| Matching lines | 4058 (77.3%) |
| Mismatched lines | 1190 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.9s |  |
| 2 | `DefineEditTextTest` | 153 | 30.3s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 26.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.3s |  |
| 5 | `DepthLimitsTest` | 20 | 22.9s |  |
| 6 | `PlaceObject2Test` | 9 | 20.9s |  |
| 7 | `ResolveEventsTest` | 15 | 22.3s |  |
| 8 | `RollOverOutTest` | 5 | 22.1s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.9s |  |
| 10 | `Version4Loader` | 11 | 1.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.8s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.5s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 24.0s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.0s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 15.9s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 15.9s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.3s |  |
| 20 | `attachExtImported` | 2 | 19.3s |  |
| 21 | `attachImported` | 2 | 1.6s |  |
| 22 | `attachMovieLoopingTest` | 41 | 18.0s |  |
| 23 | `attachMovieTest` | 12 | 18.6s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 15.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 14.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.6s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.5s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 23.3s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 23.1s |  |
| 34 | `event_handler_scope_test` | 16 | 2.5s |  |
| 35 | `frame_label_test` | 17 | 23.1s |  |
| 36 | `getTimer_test` | 8 | 21.7s |  |
| 37 | `get_frame_number_test` | 31 | 24.1s |  |
| 38 | `gotoFrame2Test` | 9 | 21.5s |  |
| 39 | `goto_frame_test` | 15 | 21.2s |  |
| 40 | `instanceNameTest` | 5 | 1.9s |  |
| 41 | `loading/LoadVarsTest` | 36 | 20.0s |  |
| 42 | `loop/loop_test` | 21 | 21.5s |  |
| 43 | `loop/loop_test2` | 15 | 21.7s |  |
| 44 | `loop/loop_test3` | 16 | 2.1s |  |
| 45 | `loop/loop_test4` | 22 | 16.7s |  |
| 46 | `loop/loop_test5` | 24 | 2.1s |  |
| 47 | `loop/loop_test8` | 38 | 24.6s |  |
| 48 | `loop/loop_test9` | 15 | 22.3s |  |
| 49 | `loop/simple_loop_test` | 0 | 22.2s |  |
| 50 | `masks_test2` | 10 | 22.1s |  |
| 51 | `morph_test1` | 0 | 21.9s |  |
| 52 | `move_object_test` | 11 | 20.8s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 20.6s |  |
| 54 | `new_child_in_unload_test` | 11 | 20.7s |  |
| 55 | `opcode_guard_test` | 18 | 22.2s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 21.8s |  |
| 57 | `place_and_remove_object_test` | 13 | 20.9s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 22.9s |  |
| 59 | `register_class/registerClassTest` | 51 | 25.2s |  |
| 60 | `replace_shapes1test` | 23 | 0.3s |  |
| 61 | `replace_sprites1test` | 21 | 21.5s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 21.0s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 21.2s |  |
| 64 | `runtime_vm_stack_test` | 9 | 21.9s |  |
| 65 | `shape_test` | 21 | 23.4s |  |
| 66 | `static_vs_dynamic1` | 17 | 22.2s |  |
| 67 | `static_vs_dynamic2` | 18 | 20.9s |  |
| 68 | `timeline_var_test` | 11 | 20.6s |  |
| 69 | `unload_movieclip_test1` | 6 | 20.4s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 25.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 26.4s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.2s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.3s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.4s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.3s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 29.7s |  |
| 9 | `action_order/action_execution_order_test` | 12 | 12 | 21.7s |  |
| 10 | `action_order/action_execution_order_test4` | 7 | 26 | 23.6s |  |
| 11 | `callFunction_test` | 6 | 11 | 16.6s |  |
| 12 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 21.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.9s |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.2s |  |
| 15 | `duplicate_movie_clip_test` | 4 | 4 | 24.5s |  |
| 16 | `init_action/InitActionTest` | 6 | 17 | 21.0s |  |
| 17 | `init_action/InitActionTest2` | 24 | 30 | 22.0s |  |
| 18 | `key_event_test` | 5 | 6 | 18.7s |  |
| 19 | `loading/LoadBitmapTest` | 3 | 3 | 18.4s |  |
| 20 | `loading/loadMovieTest` | 9 | 9 | 3.1s |  |
| 21 | `loop/loop_test10` | 23 | 23 | 22.6s |  |
| 22 | `loop/loop_test6` | 1 | 12 | 16.0s |  |
| 23 | `loop/loop_test7` | 1 | 8 | 1.6s |  |
| 24 | `matrix_test` | 5 | 9 | 111.6s |  |
| 25 | `path_format_test` | 28 | 28 | 23.9s |  |
| 26 | `place_object_test` | 14 | 14 | 2.2s |  |
| 27 | `place_object_test2` | 22 | 23 | 21.2s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 19.3s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 19.4s |  |

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

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 5 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 6 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 7 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 8 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 9 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 10 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 11 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
| 12 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 13 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
