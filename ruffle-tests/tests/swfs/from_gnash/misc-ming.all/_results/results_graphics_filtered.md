# Ruffle Test Results (Filtered)

**Date**: 2026-11-26 20:41 UTC

**Git SHA**: `bfa47037b1`

**Run Duration**: 32m 27s

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
| 1 | `BeginBitmapFill` | 1 | 28.4s |  |
| 2 | `BitmapDataDraw` | 56 | 30.9s |  |
| 3 | `DefineEditTextTest` | 153 | 27.3s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 24.6s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 22.3s |  |
| 6 | `DepthLimitsTest` | 20 | 24.9s |  |
| 7 | `PlaceObject2Test` | 9 | 20.4s |  |
| 8 | `ResolveEventsTest` | 15 | 20.8s |  |
| 9 | `RollOverOutTest` | 5 | 20.6s |  |
| 10 | `VarAndCharClashTest` | 13 | 3.3s |  |
| 11 | `Version4Loader` | 11 | 3.2s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 26.6s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 26.1s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 26.1s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 3.2s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 4.0s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 19.1s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 19.6s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 21 | `attachExtImported` | 2 | 21.8s |  |
| 22 | `attachImported` | 2 | 2.7s |  |
| 23 | `attachMovieLoopingTest` | 41 | 20.8s |  |
| 24 | `attachMovieTest` | 12 | 21.3s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 19.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.2s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.6s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.6s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.2s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.6s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 25.4s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 24.5s |  |
| 35 | `event_handler_scope_test` | 16 | 3.4s |  |
| 36 | `frame_label_test` | 17 | 4.8s |  |
| 37 | `getTimer_test` | 8 | 25.7s |  |
| 38 | `get_frame_number_test` | 31 | 28.6s |  |
| 39 | `gotoFrame2Test` | 9 | 25.6s |  |
| 40 | `goto_frame_test` | 15 | 28.2s |  |
| 41 | `init_action/InitActionTest2` | 29 | 28.6s |  |
| 42 | `instanceNameTest` | 5 | 3.2s |  |
| 43 | `loading/LoadVarsTest` | 36 | 24.4s |  |
| 44 | `loop/loop_test` | 21 | 19.7s |  |
| 45 | `loop/loop_test2` | 15 | 19.8s |  |
| 46 | `loop/loop_test3` | 16 | 2.1s |  |
| 47 | `loop/loop_test4` | 22 | 20.9s |  |
| 48 | `loop/loop_test5` | 24 | 3.0s |  |
| 49 | `loop/loop_test8` | 38 | 28.2s |  |
| 50 | `loop/loop_test9` | 15 | 25.8s |  |
| 51 | `loop/simple_loop_test` | 0 | 27.8s |  |
| 52 | `masks_test2` | 10 | 20.1s |  |
| 53 | `morph_test1` | 0 | 21.7s |  |
| 54 | `move_object_test` | 11 | 16.5s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 2.3s |  |
| 56 | `new_child_in_unload_test` | 11 | 16.7s |  |
| 57 | `opcode_guard_test` | 18 | 22.3s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 22.2s |  |
| 59 | `place_and_remove_object_test` | 13 | 3.4s |  |
| 60 | `place_object_test` | 12 | 4.6s |  |
| 61 | `place_object_test2` | 19 | 26.5s |  |
| 62 | `register_class/RegisterClassTest3` | 12 | 26.8s |  |
| 63 | `register_class/registerClassTest` | 51 | 29.2s |  |
| 64 | `replace_shapes1test` | 23 | 2.5s |  |
| 65 | `replace_sprites1test` | 21 | 2.5s |  |
| 66 | `reverse_execute_PlaceObject2_test1` | 8 | 19.2s |  |
| 67 | `reverse_execute_PlaceObject2_test2` | 10 | 19.5s |  |
| 68 | `runtime_vm_stack_test` | 9 | 22.5s |  |
| 69 | `shape_test` | 21 | 5.2s |  |
| 70 | `static_vs_dynamic1` | 17 | 2.8s |  |
| 71 | `static_vs_dynamic2` | 18 | 19.8s |  |
| 72 | `timeline_var_test` | 11 | 19.7s |  |
| 73 | `unload_movieclip_test1` | 6 | 2.1s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 32.0s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 3.2s |  |
| 3 | `DefineTextTest` | 4 | 4 | 20.7s |  |
| 4 | `DragDropTest` | 4 | 4 | 4.0s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 7.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.8s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 28.0s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 20.1s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 26.5s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 26.6s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 4.4s |  |
| 13 | `callFunction_test` | 6 | 11 | 19.6s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.3s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.4s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.5s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 26.3s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 28.2s |  |
| 19 | `key_event_test` | 5 | 6 | 22.9s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 22.1s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 4.3s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 20.2s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 20.7s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 2.5s |  |
| 25 | `masks_test` | 16 | 16 | 36.7s |  |
| 26 | `matrix_test` | 5 | 9 | 80.3s |  |
| 27 | `path_format_test` | 7 | 28 | 24.4s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 17.2s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 2.5s |  |

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
