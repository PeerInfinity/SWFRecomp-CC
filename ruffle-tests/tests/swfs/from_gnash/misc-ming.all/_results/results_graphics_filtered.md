# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 23:56 UTC

**Git SHA**: `005bea42a2`

**Run Duration**: 31m 13s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 106 |
| Passing | **68** (64.2%) |
| Ruffle-matched | 32 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **100** (94.3%) |
| Failing | 6 |
| Total expected lines | 5140 |
| Matching lines | 4234 (82.4%) |
| Mismatched lines | 906 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**68 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.0s |  |
| 2 | `BitmapDataDraw` | 56 | 21.5s |  |
| 3 | `DefineEditTextTest` | 153 | 26.3s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 23.3s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 21.0s |  |
| 6 | `DepthLimitsTest` | 20 | 27.3s |  |
| 7 | `PlaceObject2Test` | 9 | 19.1s |  |
| 8 | `ResolveEventsTest` | 15 | 20.4s |  |
| 9 | `RollOverOutTest` | 5 | 19.9s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.7s |  |
| 11 | `Version4Loader` | 11 | 2.6s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 24.6s |  |
| 13 | `action_order/action_execution_order_test3` | 4 | 24.6s |  |
| 14 | `action_order/action_execution_order_test5` | 35 | 3.9s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 19.1s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 19.5s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.9s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 2.0s |  |
| 19 | `attachExtImported` | 2 | 19.9s |  |
| 20 | `attachImported` | 2 | 2.1s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.3s |  |
| 22 | `attachMovieTest` | 12 | 19.6s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 19.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.2s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.7s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.1s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 20.5s |  |
| 33 | `event_handler_scope_test` | 16 | 2.4s |  |
| 34 | `frame_label_test` | 17 | 19.9s |  |
| 35 | `getTimer_test` | 8 | 19.0s |  |
| 36 | `get_frame_number_test` | 31 | 20.7s |  |
| 37 | `gotoFrame2Test` | 9 | 18.9s |  |
| 38 | `goto_frame_test` | 15 | 19.1s |  |
| 39 | `instanceNameTest` | 5 | 1.9s |  |
| 40 | `loading/LoadVarsTest` | 36 | 21.1s |  |
| 41 | `loop/loop_test` | 21 | 26.1s |  |
| 42 | `loop/loop_test2` | 15 | 25.7s |  |
| 43 | `loop/loop_test3` | 16 | 2.9s |  |
| 44 | `loop/loop_test4` | 22 | 19.9s |  |
| 45 | `loop/loop_test5` | 24 | 2.9s |  |
| 46 | `loop/loop_test8` | 38 | 20.4s |  |
| 47 | `loop/loop_test9` | 15 | 18.7s |  |
| 48 | `loop/simple_loop_test` | 0 | 19.8s |  |
| 49 | `masks_test2` | 10 | 19.1s |  |
| 50 | `morph_test1` | 0 | 20.7s |  |
| 51 | `move_object_test` | 11 | 23.6s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 23.6s |  |
| 53 | `new_child_in_unload_test` | 11 | 24.0s |  |
| 54 | `opcode_guard_test` | 18 | 19.6s |  |
| 55 | `place_and_remove_object_insane_test` | 22 | 19.7s |  |
| 56 | `place_and_remove_object_test` | 13 | 19.2s |  |
| 57 | `register_class/RegisterClassTest3` | 12 | 19.3s |  |
| 58 | `register_class/registerClassTest` | 51 | 21.0s |  |
| 59 | `replace_shapes1test` | 23 | 4.0s |  |
| 60 | `replace_sprites1test` | 21 | 20.1s |  |
| 61 | `reverse_execute_PlaceObject2_test1` | 8 | 19.5s |  |
| 62 | `reverse_execute_PlaceObject2_test2` | 10 | 19.9s |  |
| 63 | `runtime_vm_stack_test` | 9 | 19.3s |  |
| 64 | `shape_test` | 21 | 20.5s |  |
| 65 | `static_vs_dynamic1` | 17 | 19.1s |  |
| 66 | `static_vs_dynamic2` | 18 | 20.2s |  |
| 67 | `timeline_var_test` | 11 | 20.0s |  |
| 68 | `unload_movieclip_test1` | 6 | 19.7s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 22.4s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.1s |  |
| 3 | `DefineTextTest` | 4 | 4 | 19.4s |  |
| 4 | `DragDropTest` | 4 | 4 | 4.5s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 8.2s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 30.8s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 19.2s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 25.9s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 19.4s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.7s |  |
| 11 | `action_order/action_execution_order_test4` | 7 | 26 | 25.6s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 25.6s |  |
| 13 | `callFunction_test` | 6 | 11 | 20.2s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.8s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.9s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.2s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 20.7s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 19.1s |  |
| 19 | `init_action/InitActionTest2` | 24 | 30 | 20.1s |  |
| 20 | `key_event_test` | 5 | 6 | 20.5s |  |
| 21 | `loading/LoadBitmapTest` | 3 | 3 | 19.6s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 3.5s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 27.2s |  |
| 24 | `loop/loop_test6` | 11 | 12 | 19.8s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 2.4s |  |
| 26 | `masks_test` | 16 | 16 | 25.9s |  |
| 27 | `matrix_test` | 5 | 9 | 81.2s |  |
| 28 | `path_format_test` | 28 | 28 | 21.2s |  |
| 29 | `place_object_test` | 14 | 14 | 2.9s |  |
| 30 | `place_object_test2` | 22 | 23 | 19.4s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 27.9s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 26.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 2 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 3 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 4 | `action_order/ActionOrderTest4` | 11.7% | 11/94 | 94 | 64 |  |
| 5 | `action_order/ActionOrderTest5` | 8.6% | 5/58 | 58 | 51 |  |
| 6 | `action_order/ActionOrderTest3` | 6.0% | 5/83 | 83 | 62 |  |
