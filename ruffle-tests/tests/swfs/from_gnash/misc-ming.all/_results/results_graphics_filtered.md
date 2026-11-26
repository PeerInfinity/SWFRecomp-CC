# Ruffle Test Results (Filtered)

**Date**: 2026-11-26 18:40 UTC

**Git SHA**: `ed63ce7c43`

**Run Duration**: 35m 22s

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
| 1 | `BeginBitmapFill` | 1 | 20.3s |  |
| 2 | `BitmapDataDraw` | 56 | 6.4s |  |
| 3 | `DefineEditTextTest` | 153 | 36.6s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 32.5s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 29.2s |  |
| 6 | `DepthLimitsTest` | 20 | 29.6s |  |
| 7 | `PlaceObject2Test` | 9 | 21.9s |  |
| 8 | `ResolveEventsTest` | 15 | 27.1s |  |
| 9 | `RollOverOutTest` | 5 | 26.7s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.1s |  |
| 11 | `Version4Loader` | 11 | 2.0s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 20.1s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 19.5s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 19.4s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 17.1s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 3.0s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 20.0s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 20.5s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 21 | `attachExtImported` | 2 | 28.0s |  |
| 22 | `attachImported` | 2 | 3.0s |  |
| 23 | `attachMovieLoopingTest` | 41 | 27.4s |  |
| 24 | `attachMovieTest` | 12 | 27.8s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 21.2s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.6s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.8s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.3s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.7s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.2s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 20.4s |  |
| 35 | `event_handler_scope_test` | 16 | 2.4s |  |
| 36 | `frame_label_test` | 17 | 27.7s |  |
| 37 | `getTimer_test` | 8 | 26.3s |  |
| 38 | `get_frame_number_test` | 31 | 29.1s |  |
| 39 | `gotoFrame2Test` | 9 | 26.1s |  |
| 40 | `goto_frame_test` | 15 | 21.0s |  |
| 41 | `init_action/InitActionTest2` | 29 | 21.2s |  |
| 42 | `instanceNameTest` | 5 | 2.1s |  |
| 43 | `loading/LoadVarsTest` | 36 | 18.7s |  |
| 44 | `loop/loop_test` | 21 | 28.2s |  |
| 45 | `loop/loop_test2` | 15 | 27.5s |  |
| 46 | `loop/loop_test3` | 16 | 3.4s |  |
| 47 | `loop/loop_test4` | 22 | 20.9s |  |
| 48 | `loop/loop_test5` | 24 | 3.0s |  |
| 49 | `loop/loop_test8` | 38 | 21.7s |  |
| 50 | `loop/loop_test9` | 15 | 20.3s |  |
| 51 | `loop/simple_loop_test` | 0 | 21.3s |  |
| 52 | `masks_test2` | 10 | 19.8s |  |
| 53 | `morph_test1` | 0 | 21.6s |  |
| 54 | `move_object_test` | 11 | 21.3s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 21.3s |  |
| 56 | `new_child_in_unload_test` | 11 | 21.3s |  |
| 57 | `opcode_guard_test` | 18 | 26.8s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 26.6s |  |
| 59 | `place_and_remove_object_test` | 13 | 19.6s |  |
| 60 | `place_object_test` | 12 | 3.0s |  |
| 61 | `place_object_test2` | 19 | 20.1s |  |
| 62 | `register_class/RegisterClassTest3` | 12 | 27.5s |  |
| 63 | `register_class/registerClassTest` | 51 | 30.4s |  |
| 64 | `replace_shapes1test` | 23 | 3.9s |  |
| 65 | `replace_sprites1test` | 21 | 26.5s |  |
| 66 | `reverse_execute_PlaceObject2_test1` | 8 | 25.9s |  |
| 67 | `reverse_execute_PlaceObject2_test2` | 10 | 26.0s |  |
| 68 | `runtime_vm_stack_test` | 9 | 27.1s |  |
| 69 | `shape_test` | 21 | 29.2s |  |
| 70 | `static_vs_dynamic1` | 17 | 26.6s |  |
| 71 | `static_vs_dynamic2` | 18 | 19.2s |  |
| 72 | `timeline_var_test` | 11 | 18.9s |  |
| 73 | `unload_movieclip_test1` | 6 | 2.3s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 24.9s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.7s |  |
| 3 | `DefineTextTest` | 4 | 4 | 28.0s |  |
| 4 | `DragDropTest` | 4 | 4 | 4.5s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 8.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 32.0s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 22.2s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 31.7s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 25.9s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 36.1s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 19.7s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 18.5s |  |
| 13 | `callFunction_test` | 6 | 11 | 21.8s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 28.9s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.1s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.9s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 20.6s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 20.4s |  |
| 19 | `key_event_test` | 5 | 6 | 17.9s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 17.2s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 3.5s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 29.2s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 20.7s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 2.5s |  |
| 25 | `masks_test` | 16 | 16 | 28.2s |  |
| 26 | `matrix_test` | 5 | 9 | 77.7s |  |
| 27 | `path_format_test` | 7 | 28 | 29.0s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 27.4s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 25.9s |  |

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
