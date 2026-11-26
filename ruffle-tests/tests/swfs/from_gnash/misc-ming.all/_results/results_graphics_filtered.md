# Ruffle Test Results (Filtered)

**Date**: 2026-11-26 00:30 UTC

**Git SHA**: `b030ed745d`

**Run Duration**: 33m 43s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **73** (66.4%) |
| Ruffle-matched | 29 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (92.7%) |
| Failing | 8 |
| Total expected lines | 5206 |
| Matching lines | 4352 (83.6%) |
| Mismatched lines | 854 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**73 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.4s |  |
| 2 | `BitmapDataDraw` | 56 | 23.0s |  |
| 3 | `DefineEditTextTest` | 153 | 26.3s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 23.8s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 21.5s |  |
| 6 | `DepthLimitsTest` | 20 | 21.6s |  |
| 7 | `PlaceObject2Test` | 9 | 21.2s |  |
| 8 | `ResolveEventsTest` | 15 | 20.7s |  |
| 9 | `RollOverOutTest` | 5 | 20.5s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.1s |  |
| 11 | `Version4Loader` | 11 | 2.1s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 19.7s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.2s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 17.6s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 19.9s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 2.7s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 19.7s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 20.1s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 21 | `attachExtImported` | 2 | 17.5s |  |
| 22 | `attachImported` | 2 | 2.2s |  |
| 23 | `attachMovieLoopingTest` | 41 | 16.8s |  |
| 24 | `attachMovieTest` | 12 | 17.2s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 20.0s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.6s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.4s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.3s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.0s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 21.4s |  |
| 35 | `event_handler_scope_test` | 16 | 2.6s |  |
| 36 | `frame_label_test` | 17 | 19.2s |  |
| 37 | `getTimer_test` | 8 | 17.4s |  |
| 38 | `get_frame_number_test` | 31 | 20.0s |  |
| 39 | `gotoFrame2Test` | 9 | 16.8s |  |
| 40 | `goto_frame_test` | 15 | 20.8s |  |
| 41 | `init_action/InitActionTest2` | 29 | 21.6s |  |
| 42 | `instanceNameTest` | 5 | 2.2s |  |
| 43 | `loading/LoadVarsTest` | 36 | 29.2s |  |
| 44 | `loop/loop_test` | 21 | 27.2s |  |
| 45 | `loop/loop_test2` | 15 | 25.9s |  |
| 46 | `loop/loop_test3` | 16 | 3.3s |  |
| 47 | `loop/loop_test4` | 22 | 33.8s |  |
| 48 | `loop/loop_test5` | 24 | 5.5s |  |
| 49 | `loop/loop_test8` | 38 | 21.4s |  |
| 50 | `loop/loop_test9` | 15 | 19.9s |  |
| 51 | `loop/simple_loop_test` | 0 | 21.4s |  |
| 52 | `masks_test2` | 10 | 25.6s |  |
| 53 | `morph_test1` | 0 | 28.2s |  |
| 54 | `move_object_test` | 11 | 20.4s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 20.3s |  |
| 56 | `new_child_in_unload_test` | 11 | 20.5s |  |
| 57 | `opcode_guard_test` | 18 | 19.2s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 18.4s |  |
| 59 | `place_and_remove_object_test` | 13 | 26.1s |  |
| 60 | `place_object_test` | 12 | 4.6s |  |
| 61 | `place_object_test2` | 19 | 26.5s |  |
| 62 | `register_class/RegisterClassTest3` | 12 | 20.1s |  |
| 63 | `register_class/registerClassTest` | 51 | 21.8s |  |
| 64 | `replace_shapes1test` | 23 | 2.6s |  |
| 65 | `replace_sprites1test` | 21 | 21.0s |  |
| 66 | `reverse_execute_PlaceObject2_test1` | 8 | 20.4s |  |
| 67 | `reverse_execute_PlaceObject2_test2` | 10 | 20.3s |  |
| 68 | `runtime_vm_stack_test` | 9 | 18.3s |  |
| 69 | `shape_test` | 21 | 19.6s |  |
| 70 | `static_vs_dynamic1` | 17 | 17.4s |  |
| 71 | `static_vs_dynamic2` | 18 | 20.5s |  |
| 72 | `timeline_var_test` | 11 | 20.3s |  |
| 73 | `unload_movieclip_test1` | 6 | 20.1s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 24.0s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.3s |  |
| 3 | `DefineTextTest` | 4 | 4 | 19.8s |  |
| 4 | `DragDropTest` | 4 | 4 | 3.2s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 5.8s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 23.7s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.9s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 30.0s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 19.9s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 26.2s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 19.0s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 20.3s |  |
| 13 | `callFunction_test` | 6 | 11 | 20.6s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 25.4s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.2s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.3s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 21.6s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 21.8s |  |
| 19 | `key_event_test` | 5 | 6 | 28.3s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 26.9s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 5.0s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 27.1s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 34.2s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 4.5s |  |
| 25 | `masks_test` | 16 | 16 | 27.4s |  |
| 26 | `matrix_test` | 5 | 9 | 119.6s |  |
| 27 | `path_format_test` | 7 | 28 | 20.2s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 20.8s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 19.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 2 | `action_order/action_execution_order_test4` | 73.1% | 19 | 26 | 7 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `action_order/action_execution_order_test4` | 73.1% | 19/26 | 26 | 26 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 30 | 32 |  |
| 5 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 15 | 96 |  |
| 7 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 8 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
