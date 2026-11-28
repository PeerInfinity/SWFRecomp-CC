# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 02:31 UTC

**Git SHA**: `b8671fd2f5`

**Run Duration**: 32m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **77** (69.4%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **104** (93.7%) |
| Failing | 7 |
| Total expected lines | 5248 |
| Matching lines | 4403 (83.9%) |
| Mismatched lines | 845 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**77 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.3s |  |
| 2 | `BitmapDataDraw` | 56 | 22.6s |  |
| 3 | `DefineEditTextTest` | 153 | 27.4s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 24.6s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 22.2s |  |
| 6 | `DepthLimitsTest` | 20 | 21.8s |  |
| 7 | `EmbeddedFontTest` | 87 | 23.8s |  |
| 8 | `PlaceObject2Test` | 9 | 20.9s |  |
| 9 | `ResolveEventsTest` | 15 | 20.7s |  |
| 10 | `RollOverOutTest` | 5 | 20.5s |  |
| 11 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 12 | `Version4Loader` | 11 | 1.3s |  |
| 13 | `Video-EmbedSquareTest` | 2 | 19.1s |  |
| 14 | `action_order/action_execution_order_test1` | 10 | 19.8s |  |
| 15 | `action_order/action_execution_order_test11` | 32 | 20.7s |  |
| 16 | `action_order/action_execution_order_test2` | 5 | 20.0s |  |
| 17 | `action_order/action_execution_order_test3` | 4 | 21.8s |  |
| 18 | `action_order/action_execution_order_test4` | 26 | 23.1s |  |
| 19 | `action_order/action_execution_order_test5` | 35 | 3.1s |  |
| 20 | `action_order/action_execution_order_test7` | 7 | 25.2s |  |
| 21 | `action_order/action_execution_order_test8-v5` | 11 | 25.6s |  |
| 22 | `action_order/action_execution_order_test8-v6` | 11 | 0.5s |  |
| 23 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 24 | `attachExtImported` | 2 | 20.7s |  |
| 25 | `attachImported` | 2 | 1.5s |  |
| 26 | `attachMovieLoopingTest` | 41 | 19.9s |  |
| 27 | `attachMovieTest` | 12 | 20.3s |  |
| 28 | `consecutive_goto_frame_test` | 12 | 19.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.6s |  |
| 30 | `displaylist_depths/displaylist_depths_test11` | 15 | 26.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.4s |  |
| 32 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.5s |  |
| 33 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.6s |  |
| 34 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 35 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.5s |  |
| 36 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.4s |  |
| 37 | `duplicate_movie_clip_test2` | 21 | 20.8s |  |
| 38 | `event_handler_scope_test` | 16 | 1.8s |  |
| 39 | `frame_label_test` | 17 | 21.5s |  |
| 40 | `getTimer_test` | 8 | 20.4s |  |
| 41 | `get_frame_number_test` | 31 | 22.0s |  |
| 42 | `gotoFrame2Test` | 9 | 20.4s |  |
| 43 | `goto_frame_test` | 15 | 20.4s |  |
| 44 | `init_action/InitActionTest2` | 29 | 20.9s |  |
| 45 | `instanceNameTest` | 5 | 1.4s |  |
| 46 | `loading/LoadVarsTest` | 36 | 23.0s |  |
| 47 | `loop/loop_test` | 21 | 22.0s |  |
| 48 | `loop/loop_test2` | 15 | 21.7s |  |
| 49 | `loop/loop_test3` | 16 | 1.9s |  |
| 50 | `loop/loop_test4` | 22 | 20.1s |  |
| 51 | `loop/loop_test5` | 24 | 2.2s |  |
| 52 | `loop/loop_test8` | 38 | 27.1s |  |
| 53 | `loop/loop_test9` | 15 | 25.0s |  |
| 54 | `loop/simple_loop_test` | 0 | 24.3s |  |
| 55 | `masks_test2` | 10 | 19.6s |  |
| 56 | `matrix_test` | 1086 | 78.1s |  |
| 57 | `morph_test1` | 0 | 19.6s |  |
| 58 | `move_object_test` | 11 | 19.8s |  |
| 59 | `multi_doactions_and_goto_frame_test` | 6 | 19.9s |  |
| 60 | `new_child_in_unload_test` | 11 | 19.9s |  |
| 61 | `opcode_guard_test` | 18 | 20.4s |  |
| 62 | `place_and_remove_object_insane_test` | 22 | 20.4s |  |
| 63 | `place_and_remove_object_test` | 13 | 19.4s |  |
| 64 | `place_object_test` | 12 | 1.7s |  |
| 65 | `place_object_test2` | 19 | 19.6s |  |
| 66 | `register_class/RegisterClassTest3` | 12 | 20.3s |  |
| 67 | `register_class/registerClassTest` | 51 | 21.7s |  |
| 68 | `replace_shapes1test` | 23 | 3.0s |  |
| 69 | `replace_sprites1test` | 21 | 15.9s |  |
| 70 | `reverse_execute_PlaceObject2_test1` | 8 | 15.7s |  |
| 71 | `reverse_execute_PlaceObject2_test2` | 10 | 15.5s |  |
| 72 | `runtime_vm_stack_test` | 9 | 20.1s |  |
| 73 | `shape_test` | 21 | 20.7s |  |
| 74 | `static_vs_dynamic1` | 17 | 19.9s |  |
| 75 | `static_vs_dynamic2` | 18 | 20.8s |  |
| 76 | `timeline_var_test` | 11 | 20.5s |  |
| 77 | `unload_movieclip_test1` | 6 | 20.1s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 23.7s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 1.6s |  |
| 3 | `DefineTextTest` | 4 | 4 | 20.5s |  |
| 4 | `DragDropTest` | 4 | 4 | 2.5s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 5.2s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 20.9s |  |
| 7 | `NetStream-SquareTest` | 79 | 92 | 28.2s |  |
| 8 | `PrototypeEventListeners` | 23 | 23 | 19.9s |  |
| 9 | `TextSnapshotTest` | 81 | 90 | 25.6s |  |
| 10 | `action_order/action_execution_order_test` | 12 | 12 | 20.2s |  |
| 11 | `action_order/action_execution_order_test6` | 5 | 21 | 23.2s |  |
| 12 | `callFunction_test` | 6 | 11 | 20.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 25.0s |  |
| 14 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 26.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.5s |  |
| 16 | `duplicate_movie_clip_test` | 4 | 4 | 21.1s |  |
| 17 | `init_action/InitActionTest` | 6 | 17 | 20.2s |  |
| 18 | `key_event_test` | 5 | 6 | 21.6s |  |
| 19 | `loading/LoadBitmapTest` | 2 | 3 | 21.4s |  |
| 20 | `loading/loadMovieTest` | 9 | 9 | 3.1s |  |
| 21 | `loop/loop_test10` | 23 | 23 | 22.6s |  |
| 22 | `loop/loop_test6` | 11 | 12 | 20.0s |  |
| 23 | `loop/loop_test7` | 1 | 8 | 1.7s |  |
| 24 | `masks_test` | 16 | 16 | 35.8s |  |
| 25 | `path_format_test` | 7 | 28 | 21.9s |  |
| 26 | `register_class/registerClassTest2` | 8 | 28 | 27.9s |  |
| 27 | `replace_buttons1test` | 3 | 3 | 27.3s |  |

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

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 2 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 30 | 32 |  |
| 3 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 4 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 15 | 96 |  |
| 5 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 6 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 7 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
