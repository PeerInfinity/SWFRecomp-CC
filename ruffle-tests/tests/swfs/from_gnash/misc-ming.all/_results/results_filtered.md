# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 22:59 UTC

**Git SHA**: `16033a1546`

**Run Duration**: 27m 44s

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
| 1 | `BeginBitmapFill` | 1 | 16.7s |  |
| 2 | `BitmapDataDraw` | 56 | 20.1s |  |
| 3 | `DefineEditTextTest` | 153 | 24.6s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 22.2s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 20.2s |  |
| 6 | `DepthLimitsTest` | 20 | 20.7s |  |
| 7 | `PlaceObject2Test` | 9 | 19.9s |  |
| 8 | `ResolveEventsTest` | 15 | 22.2s |  |
| 9 | `RollOverOutTest` | 5 | 22.7s |  |
| 10 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 11 | `Version4Loader` | 11 | 1.4s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 19.1s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.7s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 1.6s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 24.1s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 2.7s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 18.9s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 19.2s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 1.4s |  |
| 21 | `attachExtImported` | 2 | 20.1s |  |
| 22 | `attachImported` | 2 | 1.5s |  |
| 23 | `attachMovieLoopingTest` | 41 | 19.3s |  |
| 24 | `attachMovieTest` | 12 | 19.7s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 1.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 15.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 23.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.5s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.0s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.4s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 19.0s |  |
| 35 | `event_handler_scope_test` | 16 | 1.9s |  |
| 36 | `frame_label_test` | 17 | 20.7s |  |
| 37 | `getTimer_test` | 8 | 1.6s |  |
| 38 | `get_frame_number_test` | 31 | 21.3s |  |
| 39 | `gotoFrame2Test` | 9 | 1.5s |  |
| 40 | `goto_frame_test` | 15 | 19.6s |  |
| 41 | `init_action/InitActionTest2` | 29 | 20.1s |  |
| 42 | `instanceNameTest` | 5 | 1.4s |  |
| 43 | `loading/LoadVarsTest` | 36 | 20.2s |  |
| 44 | `loop/loop_test` | 21 | 16.9s |  |
| 45 | `loop/loop_test2` | 15 | 17.0s |  |
| 46 | `loop/loop_test3` | 16 | 1.6s |  |
| 47 | `loop/loop_test4` | 22 | 19.6s |  |
| 48 | `loop/loop_test5` | 24 | 2.2s |  |
| 49 | `loop/loop_test8` | 38 | 20.2s |  |
| 50 | `loop/loop_test9` | 15 | 18.7s |  |
| 51 | `loop/simple_loop_test` | 0 | 18.3s |  |
| 52 | `masks_test2` | 10 | 19.1s |  |
| 53 | `morph_test1` | 0 | 19.0s |  |
| 54 | `move_object_test` | 11 | 19.1s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 18.9s |  |
| 56 | `new_child_in_unload_test` | 11 | 1.6s |  |
| 57 | `opcode_guard_test` | 18 | 19.9s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 20.2s |  |
| 59 | `place_and_remove_object_test` | 13 | 19.2s |  |
| 60 | `place_object_test` | 12 | 1.8s |  |
| 61 | `place_object_test2` | 19 | 19.4s |  |
| 62 | `register_class/RegisterClassTest3` | 12 | 2.6s |  |
| 63 | `register_class/registerClassTest` | 51 | 27.6s |  |
| 64 | `replace_shapes1test` | 23 | 2.4s |  |
| 65 | `replace_sprites1test` | 21 | 19.3s |  |
| 66 | `reverse_execute_PlaceObject2_test1` | 8 | 1.4s |  |
| 67 | `reverse_execute_PlaceObject2_test2` | 10 | 19.2s |  |
| 68 | `runtime_vm_stack_test` | 9 | 2.3s |  |
| 69 | `shape_test` | 21 | 23.3s |  |
| 70 | `static_vs_dynamic1` | 17 | 21.2s |  |
| 71 | `static_vs_dynamic2` | 18 | 19.0s |  |
| 72 | `timeline_var_test` | 11 | 1.6s |  |
| 73 | `unload_movieclip_test1` | 6 | 18.6s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 21.9s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.0s |  |
| 3 | `DefineTextTest` | 4 | 4 | 18.8s |  |
| 4 | `DragDropTest` | 4 | 4 | 2.4s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 4.9s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 22.8s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 19.9s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 30.1s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 2.0s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 32.1s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 19.1s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 25.1s |  |
| 13 | `callFunction_test` | 6 | 11 | 20.2s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 25.1s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 15.2s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.5s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 18.5s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 19.5s |  |
| 19 | `key_event_test` | 5 | 6 | 19.9s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 19.2s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 3.1s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 17.8s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 19.7s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 1.8s |  |
| 25 | `masks_test` | 16 | 16 | 25.6s |  |
| 26 | `matrix_test` | 5 | 9 | 80.3s |  |
| 27 | `path_format_test` | 7 | 28 | 22.1s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 23.6s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 21.7s |  |

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
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 7 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 8 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
