# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 23:57 UTC

**Git SHA**: `715a5300c8`

**Run Duration**: 35m 33s

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
| 1 | `BeginBitmapFill` | 1 | 23.1s |  |
| 2 | `BitmapDataDraw` | 56 | 25.7s |  |
| 3 | `DefineEditTextTest` | 153 | 25.5s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 22.2s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 19.3s |  |
| 6 | `DepthLimitsTest` | 20 | 23.7s |  |
| 7 | `PlaceObject2Test` | 9 | 20.6s |  |
| 8 | `ResolveEventsTest` | 15 | 21.2s |  |
| 9 | `RollOverOutTest` | 5 | 21.1s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.2s |  |
| 11 | `Version4Loader` | 11 | 2.1s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 20.7s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 21.6s |  |
| 14 | `action_order/action_execution_order_test11` | 32 | 22.6s |  |
| 15 | `action_order/action_execution_order_test2` | 5 | 21.8s |  |
| 16 | `action_order/action_execution_order_test3` | 4 | 20.1s |  |
| 17 | `action_order/action_execution_order_test4` | 26 | 20.8s |  |
| 18 | `action_order/action_execution_order_test5` | 35 | 2.7s |  |
| 19 | `action_order/action_execution_order_test7` | 7 | 20.7s |  |
| 20 | `action_order/action_execution_order_test8-v5` | 11 | 21.1s |  |
| 21 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 22 | `action_order/action_execution_order_test9` | 4 | 2.2s |  |
| 23 | `attachExtImported` | 2 | 22.0s |  |
| 24 | `attachImported` | 2 | 2.7s |  |
| 25 | `attachMovieLoopingTest` | 41 | 21.3s |  |
| 26 | `attachMovieTest` | 12 | 21.8s |  |
| 27 | `consecutive_goto_frame_test` | 12 | 21.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.7s |  |
| 30 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test5` | 25 | 21.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.5s |  |
| 33 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.0s |  |
| 34 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.4s |  |
| 35 | `displaylist_depths/displaylist_depths_test9` | 23 | 28.0s |  |
| 36 | `duplicate_movie_clip_test2` | 21 | 27.9s |  |
| 37 | `event_handler_scope_test` | 16 | 3.8s |  |
| 38 | `frame_label_test` | 17 | 28.6s |  |
| 39 | `getTimer_test` | 8 | 27.1s |  |
| 40 | `get_frame_number_test` | 31 | 29.2s |  |
| 41 | `gotoFrame2Test` | 9 | 26.5s |  |
| 42 | `goto_frame_test` | 15 | 28.7s |  |
| 43 | `init_action/InitActionTest2` | 29 | 29.4s |  |
| 44 | `instanceNameTest` | 5 | 3.4s |  |
| 45 | `loading/LoadVarsTest` | 36 | 24.4s |  |
| 46 | `loop/loop_test` | 21 | 20.9s |  |
| 47 | `loop/loop_test2` | 15 | 20.7s |  |
| 48 | `loop/loop_test3` | 16 | 2.2s |  |
| 49 | `loop/loop_test4` | 22 | 22.4s |  |
| 50 | `loop/loop_test5` | 24 | 3.7s |  |
| 51 | `loop/loop_test8` | 38 | 25.5s |  |
| 52 | `loop/loop_test9` | 15 | 23.7s |  |
| 53 | `loop/simple_loop_test` | 0 | 24.2s |  |
| 54 | `masks_test2` | 10 | 26.7s |  |
| 55 | `matrix_test` | 1086 | 123.8s |  |
| 56 | `morph_test1` | 0 | 29.9s |  |
| 57 | `move_object_test` | 11 | 21.5s |  |
| 58 | `multi_doactions_and_goto_frame_test` | 6 | 21.5s |  |
| 59 | `new_child_in_unload_test` | 11 | 21.7s |  |
| 60 | `opcode_guard_test` | 18 | 20.5s |  |
| 61 | `place_and_remove_object_insane_test` | 22 | 20.3s |  |
| 62 | `place_and_remove_object_test` | 13 | 21.4s |  |
| 63 | `place_object_test` | 12 | 21.9s |  |
| 64 | `place_object_test2` | 19 | 21.3s |  |
| 65 | `register_class/RegisterClassTest3` | 12 | 22.6s |  |
| 66 | `register_class/registerClassTest` | 51 | 24.9s |  |
| 67 | `replace_shapes1test` | 23 | 2.8s |  |
| 68 | `replace_sprites1test` | 21 | 19.7s |  |
| 69 | `reverse_execute_PlaceObject2_test1` | 8 | 19.6s |  |
| 70 | `reverse_execute_PlaceObject2_test2` | 10 | 19.5s |  |
| 71 | `runtime_vm_stack_test` | 9 | 18.2s |  |
| 72 | `shape_test` | 21 | 19.1s |  |
| 73 | `static_vs_dynamic1` | 17 | 2.7s |  |
| 74 | `static_vs_dynamic2` | 18 | 21.4s |  |
| 75 | `timeline_var_test` | 11 | 21.3s |  |
| 76 | `unload_movieclip_test1` | 6 | 2.2s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 26.6s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 21.8s |  |
| 3 | `DefineTextTest` | 4 | 4 | 17.7s |  |
| 4 | `DragDropTest` | 4 | 4 | 4.2s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 7.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.8s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 27.9s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 20.6s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 27.1s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 22.1s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 20.7s |  |
| 13 | `callFunction_test` | 6 | 11 | 22.0s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 28.2s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.8s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.2s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 28.5s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 28.2s |  |
| 19 | `key_event_test` | 5 | 6 | 23.4s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 22.3s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 4.5s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 21.5s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 22.2s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 3.1s |  |
| 25 | `masks_test` | 16 | 16 | 32.7s |  |
| 26 | `path_format_test` | 7 | 28 | 21.6s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 21.4s |  |
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
