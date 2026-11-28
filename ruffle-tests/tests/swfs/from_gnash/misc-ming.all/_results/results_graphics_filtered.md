# Ruffle Test Results (Filtered)

**Date**: 2026-11-28 00:52 UTC

**Git SHA**: `9498e80c12`

**Run Duration**: 36m 9s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **76** (69.1%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **104** (94.5%) |
| Failing | 6 |
| Total expected lines | 5206 |
| Matching lines | 4369 (83.9%) |
| Mismatched lines | 837 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**76 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.8s |  |
| 2 | `BitmapDataDraw` | 56 | 21.1s |  |
| 3 | `DefineEditTextTest` | 153 | 26.9s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 24.5s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 22.1s |  |
| 6 | `DepthLimitsTest` | 20 | 22.9s |  |
| 7 | `PlaceObject2Test` | 9 | 21.4s |  |
| 8 | `ResolveEventsTest` | 15 | 22.4s |  |
| 9 | `RollOverOutTest` | 5 | 22.3s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.1s |  |
| 11 | `Version4Loader` | 11 | 2.1s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 20.5s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 20.4s |  |
| 14 | `action_order/action_execution_order_test11` | 32 | 21.1s |  |
| 15 | `action_order/action_execution_order_test2` | 5 | 20.4s |  |
| 16 | `action_order/action_execution_order_test3` | 4 | 20.7s |  |
| 17 | `action_order/action_execution_order_test4` | 26 | 21.9s |  |
| 18 | `action_order/action_execution_order_test5` | 35 | 2.9s |  |
| 19 | `action_order/action_execution_order_test7` | 7 | 22.9s |  |
| 20 | `action_order/action_execution_order_test8-v5` | 11 | 22.8s |  |
| 21 | `action_order/action_execution_order_test8-v6` | 11 | 1.3s |  |
| 22 | `action_order/action_execution_order_test9` | 4 | 2.8s |  |
| 23 | `attachExtImported` | 2 | 22.0s |  |
| 24 | `attachImported` | 2 | 2.7s |  |
| 25 | `attachMovieLoopingTest` | 41 | 21.3s |  |
| 26 | `attachMovieTest` | 12 | 21.8s |  |
| 27 | `consecutive_goto_frame_test` | 12 | 20.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test11` | 15 | 22.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.5s |  |
| 32 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.2s |  |
| 33 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.8s |  |
| 34 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.2s |  |
| 35 | `displaylist_depths/displaylist_depths_test9` | 23 | 27.4s |  |
| 36 | `duplicate_movie_clip_test2` | 21 | 27.8s |  |
| 37 | `event_handler_scope_test` | 16 | 3.7s |  |
| 38 | `frame_label_test` | 17 | 19.5s |  |
| 39 | `getTimer_test` | 8 | 18.6s |  |
| 40 | `get_frame_number_test` | 31 | 20.2s |  |
| 41 | `gotoFrame2Test` | 9 | 18.5s |  |
| 42 | `goto_frame_test` | 15 | 27.0s |  |
| 43 | `init_action/InitActionTest2` | 29 | 28.0s |  |
| 44 | `instanceNameTest` | 5 | 3.1s |  |
| 45 | `loading/LoadVarsTest` | 36 | 22.3s |  |
| 46 | `loop/loop_test` | 21 | 17.1s |  |
| 47 | `loop/loop_test2` | 15 | 17.5s |  |
| 48 | `loop/loop_test3` | 16 | 2.0s |  |
| 49 | `loop/loop_test4` | 22 | 21.2s |  |
| 50 | `loop/loop_test5` | 24 | 3.0s |  |
| 51 | `loop/loop_test8` | 38 | 22.2s |  |
| 52 | `loop/loop_test9` | 15 | 20.8s |  |
| 53 | `loop/simple_loop_test` | 0 | 21.8s |  |
| 54 | `masks_test2` | 10 | 26.9s |  |
| 55 | `matrix_test` | 1086 | 124.8s |  |
| 56 | `morph_test1` | 0 | 30.1s |  |
| 57 | `move_object_test` | 11 | 27.1s |  |
| 58 | `multi_doactions_and_goto_frame_test` | 6 | 27.1s |  |
| 59 | `new_child_in_unload_test` | 11 | 27.2s |  |
| 60 | `opcode_guard_test` | 18 | 22.6s |  |
| 61 | `place_and_remove_object_insane_test` | 22 | 22.6s |  |
| 62 | `place_and_remove_object_test` | 13 | 25.9s |  |
| 63 | `place_object_test` | 12 | 27.1s |  |
| 64 | `place_object_test2` | 19 | 26.4s |  |
| 65 | `register_class/RegisterClassTest3` | 12 | 27.0s |  |
| 66 | `register_class/registerClassTest` | 51 | 29.5s |  |
| 67 | `replace_shapes1test` | 23 | 2.6s |  |
| 68 | `replace_sprites1test` | 21 | 17.4s |  |
| 69 | `reverse_execute_PlaceObject2_test1` | 8 | 17.1s |  |
| 70 | `reverse_execute_PlaceObject2_test2` | 10 | 17.2s |  |
| 71 | `runtime_vm_stack_test` | 9 | 27.4s |  |
| 72 | `shape_test` | 21 | 29.6s |  |
| 73 | `static_vs_dynamic1` | 17 | 26.8s |  |
| 74 | `static_vs_dynamic2` | 18 | 20.7s |  |
| 75 | `timeline_var_test` | 11 | 20.5s |  |
| 76 | `unload_movieclip_test1` | 6 | 20.2s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 21.4s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 17.4s |  |
| 3 | `DefineTextTest` | 4 | 4 | 20.5s |  |
| 4 | `DragDropTest` | 4 | 4 | 3.7s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 6.6s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 25.8s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.6s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 30.7s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 21.2s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 30.1s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 20.8s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 21.8s |  |
| 13 | `callFunction_test` | 6 | 11 | 20.7s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 25.6s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 22.5s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.0s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 28.1s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 26.7s |  |
| 19 | `key_event_test` | 5 | 6 | 21.7s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 20.8s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 3.7s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 17.9s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 21.3s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 2.5s |  |
| 25 | `masks_test` | 16 | 16 | 28.6s |  |
| 26 | `path_format_test` | 7 | 28 | 24.2s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 21.2s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 20.4s |  |

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
| 2 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 30 | 32 |  |
| 3 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 4 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 15 | 96 |  |
| 5 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 6 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
