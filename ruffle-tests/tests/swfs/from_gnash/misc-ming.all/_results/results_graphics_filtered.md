# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 18:08 UTC

**Git SHA**: `f4edebdcec`

**Run Duration**: 27m 54s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **74** (67.3%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (92.7%) |
| Failing | 8 |
| Total expected lines | 5206 |
| Matching lines | 4358 (83.7%) |
| Mismatched lines | 848 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**74 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.1s |  |
| 2 | `BitmapDataDraw` | 56 | 21.6s |  |
| 3 | `DefineEditTextTest` | 153 | 27.0s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 24.6s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 22.2s |  |
| 6 | `DepthLimitsTest` | 20 | 23.1s |  |
| 7 | `PlaceObject2Test` | 9 | 19.9s |  |
| 8 | `ResolveEventsTest` | 15 | 21.1s |  |
| 9 | `RollOverOutTest` | 5 | 2.8s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.2s |  |
| 11 | `Version4Loader` | 11 | 2.1s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 20.4s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 19.9s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 20.1s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 2.5s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 3.1s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 21.2s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 21.5s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.3s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.7s |  |
| 21 | `attachExtImported` | 2 | 17.6s |  |
| 22 | `attachImported` | 2 | 2.2s |  |
| 23 | `attachMovieLoopingTest` | 41 | 16.7s |  |
| 24 | `attachMovieTest` | 12 | 17.1s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 24.0s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 22.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.8s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.2s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.6s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 3.0s |  |
| 35 | `event_handler_scope_test` | 16 | 2.4s |  |
| 36 | `frame_label_test` | 17 | 4.8s |  |
| 37 | `getTimer_test` | 8 | 21.9s |  |
| 38 | `get_frame_number_test` | 31 | 24.1s |  |
| 39 | `gotoFrame2Test` | 9 | 22.3s |  |
| 40 | `goto_frame_test` | 15 | 20.3s |  |
| 41 | `init_action/InitActionTest2` | 29 | 20.8s |  |
| 42 | `instanceNameTest` | 5 | 2.1s |  |
| 43 | `loading/LoadVarsTest` | 36 | 23.1s |  |
| 44 | `loop/loop_test` | 21 | 19.5s |  |
| 45 | `loop/loop_test2` | 15 | 2.1s |  |
| 46 | `loop/loop_test3` | 16 | 2.2s |  |
| 47 | `loop/loop_test4` | 22 | 20.7s |  |
| 48 | `loop/loop_test5` | 24 | 2.9s |  |
| 49 | `loop/loop_test8` | 38 | 22.1s |  |
| 50 | `loop/loop_test9` | 15 | 20.4s |  |
| 51 | `loop/simple_loop_test` | 0 | 3.3s |  |
| 52 | `masks_test2` | 10 | 20.6s |  |
| 53 | `matrix_test` | 1086 | 83.1s |  |
| 54 | `morph_test1` | 0 | 22.8s |  |
| 55 | `move_object_test` | 11 | 27.4s |  |
| 56 | `multi_doactions_and_goto_frame_test` | 6 | 26.5s |  |
| 57 | `new_child_in_unload_test` | 11 | 26.4s |  |
| 58 | `opcode_guard_test` | 18 | 20.3s |  |
| 59 | `place_and_remove_object_insane_test` | 22 | 20.1s |  |
| 60 | `place_and_remove_object_test` | 13 | 19.7s |  |
| 61 | `place_object_test` | 12 | 2.9s |  |
| 62 | `place_object_test2` | 19 | 20.0s |  |
| 63 | `register_class/RegisterClassTest3` | 12 | 21.0s |  |
| 64 | `register_class/registerClassTest` | 51 | 22.4s |  |
| 65 | `replace_shapes1test` | 23 | 0.8s |  |
| 66 | `replace_sprites1test` | 21 | 2.3s |  |
| 67 | `reverse_execute_PlaceObject2_test1` | 8 | 20.0s |  |
| 68 | `reverse_execute_PlaceObject2_test2` | 10 | 20.0s |  |
| 69 | `runtime_vm_stack_test` | 9 | 20.6s |  |
| 70 | `shape_test` | 21 | 21.7s |  |
| 71 | `static_vs_dynamic1` | 17 | 2.1s |  |
| 72 | `static_vs_dynamic2` | 18 | 20.7s |  |
| 73 | `timeline_var_test` | 11 | 20.5s |  |
| 74 | `unload_movieclip_test1` | 6 | 2.2s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 23.1s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.2s |  |
| 3 | `DefineTextTest` | 4 | 4 | 2.5s |  |
| 4 | `DragDropTest` | 4 | 4 | 4.0s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 7.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.1s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 27.0s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 20.4s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 27.1s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 2.6s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 18.9s |  |
| 13 | `callFunction_test` | 6 | 11 | 3.9s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 30.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.8s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.0s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 20.9s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 20.2s |  |
| 19 | `key_event_test` | 5 | 6 | 22.3s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 21.6s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 3.9s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 19.9s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 20.5s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 2.5s |  |
| 25 | `masks_test` | 16 | 16 | 28.1s |  |
| 26 | `path_format_test` | 7 | 28 | 3.9s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 0.9s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 0.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_order/action_execution_order_test11` | 84.4% | 27 | 32 | 5 |  |
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
| 1 | `action_order/action_execution_order_test11` | 84.4% | 27/32 | 32 | 32 |  |
| 2 | `action_order/action_execution_order_test4` | 73.1% | 19/26 | 26 | 26 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 30 | 32 |  |
| 5 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 15 | 96 |  |
| 7 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 8 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
