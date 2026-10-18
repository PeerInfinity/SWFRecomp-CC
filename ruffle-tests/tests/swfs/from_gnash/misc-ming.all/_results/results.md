# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-18 08:49 UTC

**Git SHA**: `f555113796`

**Run Duration**: 23m 52s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **69** (62.2%) |
| Ruffle-matched | 33 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (91.9%) |
| Failing | 9 |
| Total expected lines | 5248 |
| Matching lines | 4236 (80.7%) |
| Mismatched lines | 1012 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 22.6s |  |
| 2 | `DefineEditTextTest` | 153 | 32.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 28.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.9s |  |
| 5 | `DepthLimitsTest` | 20 | 24.1s |  |
| 6 | `PlaceObject2Test` | 9 | 2.5s |  |
| 7 | `ResolveEventsTest` | 15 | 3.2s |  |
| 8 | `RollOverOutTest` | 5 | 2.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.0s |  |
| 10 | `Version4Loader` | 11 | 1.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.3s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 1.5s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.1s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 21.6s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 2.5s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.5s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 1.9s |  |
| 20 | `attachExtImported` | 2 | 18.9s |  |
| 21 | `attachImported` | 2 | 1.7s |  |
| 22 | `attachMovieLoopingTest` | 41 | 18.4s |  |
| 23 | `attachMovieTest` | 12 | 19.3s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 22.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 1.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 1.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.2s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.0s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.0s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 3.3s |  |
| 34 | `event_handler_scope_test` | 16 | 2.5s |  |
| 35 | `frame_label_test` | 17 | 2.2s |  |
| 36 | `getTimer_test` | 8 | 13.2s |  |
| 37 | `get_frame_number_test` | 31 | 2.9s |  |
| 38 | `gotoFrame2Test` | 9 | 13.3s |  |
| 39 | `goto_frame_test` | 15 | 22.9s |  |
| 40 | `instanceNameTest` | 5 | 2.0s |  |
| 41 | `loading/LoadVarsTest` | 36 | 25.9s |  |
| 42 | `loop/loop_test` | 21 | 22.2s |  |
| 43 | `loop/loop_test2` | 15 | 2.0s |  |
| 44 | `loop/loop_test3` | 16 | 2.0s |  |
| 45 | `loop/loop_test4` | 22 | 2.4s |  |
| 46 | `loop/loop_test5` | 24 | 2.5s |  |
| 47 | `loop/loop_test8` | 38 | 3.7s |  |
| 48 | `loop/loop_test9` | 15 | 21.3s |  |
| 49 | `loop/simple_loop_test` | 0 | 1.4s |  |
| 50 | `masks_test2` | 10 | 22.5s |  |
| 51 | `morph_test1` | 0 | 22.6s |  |
| 52 | `move_object_test` | 11 | 21.8s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 21.8s |  |
| 54 | `new_child_in_unload_test` | 11 | 22.2s |  |
| 55 | `opcode_guard_test` | 18 | 19.3s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 19.2s |  |
| 57 | `place_and_remove_object_test` | 13 | 22.0s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 22.4s |  |
| 59 | `register_class/registerClassTest` | 51 | 24.9s |  |
| 60 | `replace_shapes1test` | 23 | 2.8s |  |
| 61 | `replace_sprites1test` | 21 | 0.2s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 0.2s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 0.2s |  |
| 64 | `runtime_vm_stack_test` | 9 | 21.1s |  |
| 65 | `shape_test` | 21 | 21.9s |  |
| 66 | `static_vs_dynamic1` | 17 | 1.7s |  |
| 67 | `static_vs_dynamic2` | 18 | 21.7s |  |
| 68 | `timeline_var_test` | 11 | 2.2s |  |
| 69 | `unload_movieclip_test1` | 6 | 1.9s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 25.9s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 7.4s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 2.4s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.3s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.2s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 2.8s |  |
| 8 | `NetStream-SquareTest` | 95 | 108 | 37.8s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 21.8s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 30.9s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 2.8s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 15.2s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 14.7s |  |
| 14 | `callFunction_test` | 6 | 11 | 2.8s |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 29.9s |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.2s |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.2s |  |
| 18 | `duplicate_movie_clip_test` | 4 | 4 | 3.7s |  |
| 19 | `init_action/InitActionTest` | 6 | 17 | 23.1s |  |
| 20 | `init_action/InitActionTest2` | 24 | 30 | 24.1s |  |
| 21 | `key_event_test` | 5 | 6 | 23.9s |  |
| 22 | `loading/LoadBitmapTest` | 3 | 3 | 23.7s |  |
| 23 | `loading/loadMovieTest` | 9 | 9 | 4.2s |  |
| 24 | `loop/loop_test10` | 23 | 23 | 22.8s |  |
| 25 | `loop/loop_test6` | 11 | 12 | 17.9s |  |
| 26 | `loop/loop_test7` | 1 | 8 | 2.0s |  |
| 27 | `masks_test` | 16 | 16 | 30.5s |  |
| 28 | `matrix_test` | 5 | 9 | 109.1s |  |
| 29 | `path_format_test` | 28 | 28 | 3.5s |  |
| 30 | `place_object_test` | 14 | 14 | 2.6s |  |
| 31 | `place_object_test2` | 22 | 23 | 2.5s |  |
| 32 | `register_class/registerClassTest2` | 8 | 28 | 25.1s |  |
| 33 | `replace_buttons1test` | 3 | 3 | 2.7s |  |

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
