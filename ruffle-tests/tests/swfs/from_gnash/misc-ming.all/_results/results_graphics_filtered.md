# Ruffle Test Results (Filtered)

**Date**: 2026-11-28 19:48 UTC

**Git SHA**: `ab18c4dff1`

**Run Duration**: 37m 39s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **77** (70.0%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **104** (94.5%) |
| Failing | 6 |
| Total expected lines | 5206 |
| Matching lines | 4396 (84.4%) |
| Mismatched lines | 810 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**77 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 27.8s |  |
| 2 | `BitmapDataDraw` | 56 | 30.4s |  |
| 3 | `DefineEditTextTest` | 153 | 38.0s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 34.2s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 30.2s |  |
| 6 | `DepthLimitsTest` | 20 | 29.4s |  |
| 7 | `EmbeddedFontTest` | 87 | 33.5s |  |
| 8 | `PlaceObject2Test` | 9 | 21.5s |  |
| 9 | `ResolveEventsTest` | 15 | 17.9s |  |
| 10 | `RollOverOutTest` | 5 | 17.6s |  |
| 11 | `VarAndCharClashTest` | 13 | 2.3s |  |
| 12 | `Version4Loader` | 11 | 2.2s |  |
| 13 | `Video-EmbedSquareTest` | 2 | 18.7s |  |
| 14 | `action_order/action_execution_order_test1` | 10 | 20.2s |  |
| 15 | `action_order/action_execution_order_test11` | 32 | 20.8s |  |
| 16 | `action_order/action_execution_order_test2` | 5 | 20.3s |  |
| 17 | `action_order/action_execution_order_test3` | 4 | 26.8s |  |
| 18 | `action_order/action_execution_order_test4` | 26 | 27.8s |  |
| 19 | `action_order/action_execution_order_test5` | 35 | 4.2s |  |
| 20 | `action_order/action_execution_order_test7` | 7 | 17.2s |  |
| 21 | `action_order/action_execution_order_test8-v5` | 11 | 17.2s |  |
| 22 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 23 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 24 | `attachExtImported` | 2 | 21.5s |  |
| 25 | `attachImported` | 2 | 2.2s |  |
| 26 | `attachMovieLoopingTest` | 41 | 20.9s |  |
| 27 | `attachMovieTest` | 12 | 21.4s |  |
| 28 | `consecutive_goto_frame_test` | 12 | 27.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test10` | 10 | 26.7s |  |
| 30 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.7s |  |
| 31 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.3s |  |
| 32 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.8s |  |
| 33 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.6s |  |
| 34 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.4s |  |
| 35 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.5s |  |
| 36 | `displaylist_depths/displaylist_depths_test9` | 23 | 23.3s |  |
| 37 | `duplicate_movie_clip_test2` | 21 | 23.4s |  |
| 38 | `event_handler_scope_test` | 16 | 3.3s |  |
| 39 | `frame_label_test` | 17 | 22.1s |  |
| 40 | `getTimer_test` | 8 | 21.2s |  |
| 41 | `get_frame_number_test` | 31 | 23.4s |  |
| 42 | `gotoFrame2Test` | 9 | 21.6s |  |
| 43 | `goto_frame_test` | 15 | 27.3s |  |
| 44 | `init_action/InitActionTest2` | 29 | 28.7s |  |
| 45 | `instanceNameTest` | 5 | 3.0s |  |
| 46 | `loading/LoadVarsTest` | 36 | 23.6s |  |
| 47 | `loop/loop_test` | 21 | 22.2s |  |
| 48 | `loop/loop_test2` | 15 | 21.2s |  |
| 49 | `loop/loop_test3` | 16 | 2.7s |  |
| 50 | `loop/loop_test4` | 22 | 21.0s |  |
| 51 | `loop/loop_test5` | 24 | 2.9s |  |
| 52 | `loop/loop_test8` | 38 | 27.8s |  |
| 53 | `loop/loop_test9` | 15 | 25.4s |  |
| 54 | `loop/simple_loop_test` | 0 | 27.3s |  |
| 55 | `masks_test2` | 10 | 20.7s |  |
| 56 | `matrix_test` | 1086 | 82.5s |  |
| 57 | `morph_test1` | 0 | 22.8s |  |
| 58 | `move_object_test` | 11 | 21.8s |  |
| 59 | `multi_doactions_and_goto_frame_test` | 6 | 21.8s |  |
| 60 | `new_child_in_unload_test` | 11 | 21.8s |  |
| 61 | `opcode_guard_test` | 18 | 21.9s |  |
| 62 | `place_and_remove_object_insane_test` | 22 | 22.2s |  |
| 63 | `place_and_remove_object_test` | 13 | 28.2s |  |
| 64 | `place_object_test` | 12 | 29.3s |  |
| 65 | `place_object_test2` | 19 | 28.5s |  |
| 66 | `register_class/RegisterClassTest3` | 12 | 21.4s |  |
| 67 | `register_class/registerClassTest` | 51 | 23.5s |  |
| 68 | `replace_shapes1test` | 23 | 1.9s |  |
| 69 | `replace_sprites1test` | 21 | 19.6s |  |
| 70 | `reverse_execute_PlaceObject2_test1` | 8 | 19.5s |  |
| 71 | `reverse_execute_PlaceObject2_test2` | 10 | 19.7s |  |
| 72 | `runtime_vm_stack_test` | 9 | 27.0s |  |
| 73 | `shape_test` | 21 | 36.0s |  |
| 74 | `static_vs_dynamic1` | 17 | 26.6s |  |
| 75 | `static_vs_dynamic2` | 18 | 21.3s |  |
| 76 | `timeline_var_test` | 11 | 21.1s |  |
| 77 | `unload_movieclip_test1` | 6 | 20.8s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 31.8s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 26.1s |  |
| 3 | `DefineTextTest` | 4 | 4 | 28.1s |  |
| 4 | `DragDropTest` | 4 | 4 | 4.8s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 8.6s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 21.7s |  |
| 7 | `NetStream-SquareTest` | 79 | 92 | 30.8s |  |
| 8 | `PrototypeEventListeners` | 23 | 23 | 17.3s |  |
| 9 | `TextSnapshotTest` | 81 | 90 | 24.6s |  |
| 10 | `action_order/action_execution_order_test` | 12 | 12 | 20.6s |  |
| 11 | `action_order/action_execution_order_test6` | 5 | 21 | 27.9s |  |
| 12 | `callFunction_test` | 6 | 11 | 28.0s |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 35.7s |  |
| 14 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 17.6s |  |
| 15 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.4s |  |
| 16 | `duplicate_movie_clip_test` | 4 | 4 | 24.7s |  |
| 17 | `init_action/InitActionTest` | 6 | 17 | 27.4s |  |
| 18 | `key_event_test` | 5 | 6 | 22.9s |  |
| 19 | `loading/LoadBitmapTest` | 2 | 3 | 22.1s |  |
| 20 | `loading/loadMovieTest` | 9 | 9 | 3.9s |  |
| 21 | `loop/loop_test10` | 23 | 23 | 22.6s |  |
| 22 | `loop/loop_test6` | 11 | 12 | 21.0s |  |
| 23 | `loop/loop_test7` | 1 | 8 | 2.5s |  |
| 24 | `masks_test` | 16 | 16 | 37.0s |  |
| 25 | `path_format_test` | 7 | 28 | 23.8s |  |
| 26 | `register_class/registerClassTest2` | 8 | 28 | 25.2s |  |
| 27 | `replace_buttons1test` | 3 | 3 | 25.0s |  |

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
