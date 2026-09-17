# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-17 00:25 UTC

**Git SHA**: `2973513c45`

**Run Duration**: 29m 14s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 30 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **99** (89.2%) |
| Failing | 12 |
| Total expected lines | 5248 |
| Matching lines | 4163 (79.3%) |
| Mismatched lines | 1085 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 12 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 23.9s |  |
| 2 | `DefineEditTextTest` | 153 | 32.2s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 28.1s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.8s |  |
| 5 | `DepthLimitsTest` | 20 | 24.3s |  |
| 6 | `PlaceObject2Test` | 9 | 24.1s |  |
| 7 | `ResolveEventsTest` | 15 | 19.2s |  |
| 8 | `RollOverOutTest` | 5 | 2.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.8s |  |
| 10 | `Version4Loader` | 11 | 2.7s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.2s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 15.3s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 14.3s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 2.7s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.6s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 19.3s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 19.6s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.2s |  |
| 20 | `attachExtImported` | 2 | 25.0s |  |
| 21 | `attachImported` | 2 | 3.0s |  |
| 22 | `attachMovieLoopingTest` | 41 | 23.4s |  |
| 23 | `attachMovieTest` | 12 | 24.2s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 18.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.8s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 23.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 3.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.6s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 3.1s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.4s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 3.5s |  |
| 34 | `event_handler_scope_test` | 16 | 2.5s |  |
| 35 | `frame_label_test` | 17 | 3.5s |  |
| 36 | `getTimer_test` | 8 | 17.7s |  |
| 37 | `get_frame_number_test` | 31 | 19.8s |  |
| 38 | `gotoFrame2Test` | 9 | 17.5s |  |
| 39 | `goto_frame_test` | 15 | 23.3s |  |
| 40 | `instanceNameTest` | 5 | 2.8s |  |
| 41 | `loading/LoadVarsTest` | 36 | 26.1s |  |
| 42 | `loop/loop_test` | 21 | 15.8s |  |
| 43 | `loop/loop_test2` | 15 | 2.0s |  |
| 44 | `loop/loop_test3` | 16 | 2.0s |  |
| 45 | `loop/loop_test4` | 22 | 19.2s |  |
| 46 | `loop/loop_test5` | 24 | 2.9s |  |
| 47 | `loop/loop_test8` | 38 | 24.8s |  |
| 48 | `loop/loop_test9` | 15 | 22.6s |  |
| 49 | `loop/simple_loop_test` | 0 | 5.1s |  |
| 50 | `masks_test2` | 10 | 22.7s |  |
| 51 | `morph_test1` | 0 | 26.0s |  |
| 52 | `move_object_test` | 11 | 24.0s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 23.8s |  |
| 54 | `new_child_in_unload_test` | 11 | 23.9s |  |
| 55 | `opcode_guard_test` | 18 | 23.8s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 23.6s |  |
| 57 | `place_and_remove_object_test` | 13 | 22.5s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 18.8s |  |
| 59 | `register_class/registerClassTest` | 51 | 20.8s |  |
| 60 | `replace_shapes1test` | 23 | 1.1s |  |
| 61 | `replace_sprites1test` | 21 | 1.3s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 20.9s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 20.8s |  |
| 64 | `runtime_vm_stack_test` | 9 | 23.6s |  |
| 65 | `shape_test` | 21 | 25.7s |  |
| 66 | `static_vs_dynamic1` | 17 | 3.0s |  |
| 67 | `static_vs_dynamic2` | 18 | 21.8s |  |
| 68 | `timeline_var_test` | 11 | 21.6s |  |
| 69 | `unload_movieclip_test1` | 6 | 2.7s |  |

## Ruffle-Matched Tests

**30 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 26.9s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 28.2s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 3.1s |  |
| 4 | `DefineTextTest` | 4 | 4 | 3.2s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.8s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 24.8s |  |
| 8 | `PrototypeEventListeners` | 23 | 23 | 18.3s |  |
| 9 | `TextSnapshotTest` | 81 | 90 | 25.0s |  |
| 10 | `action_order/action_execution_order_test` | 12 | 12 | 2.5s |  |
| 11 | `action_order/action_execution_order_test4` | 7 | 26 | 17.9s |  |
| 12 | `callFunction_test` | 6 | 11 | 2.8s |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.8s |  |
| 14 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 22.3s |  |
| 15 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.0s |  |
| 16 | `duplicate_movie_clip_test` | 4 | 4 | 21.1s |  |
| 17 | `init_action/InitActionTest` | 6 | 17 | 22.9s |  |
| 18 | `init_action/InitActionTest2` | 24 | 30 | 24.5s |  |
| 19 | `key_event_test` | 5 | 6 | 25.1s |  |
| 20 | `loading/LoadBitmapTest` | 3 | 3 | 23.8s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 5.1s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 16.0s |  |
| 23 | `loop/loop_test6` | 1 | 12 | 18.9s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 2.4s |  |
| 25 | `matrix_test` | 5 | 9 | 111.6s |  |
| 26 | `path_format_test` | 28 | 28 | 5.9s |  |
| 27 | `place_object_test` | 14 | 14 | 4.2s |  |
| 28 | `place_object_test2` | 22 | 23 | 23.1s |  |
| 29 | `register_class/registerClassTest2` | 8 | 28 | 1.1s |  |
| 30 | `replace_buttons1test` | 3 | 3 | 1.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `masks_test` | 71.4% | 125 | 175 | 50 |  |

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
| 3 | `masks_test` | 71.4% | 125/175 | 175 | 175 |  |
| 4 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 5 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 6 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 7 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 8 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 9 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 10 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 11 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
| 12 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
