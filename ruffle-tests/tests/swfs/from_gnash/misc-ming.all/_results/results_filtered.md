# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 02:09 UTC

**Git SHA**: `6ee6eded7b`

**Run Duration**: 30m 10s

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
| 1 | `BeginBitmapFill` | 1 | 25.8s |  |
| 2 | `BitmapDataDraw` | 56 | 29.3s |  |
| 3 | `DefineEditTextTest` | 153 | 25.1s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 22.7s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 20.4s |  |
| 6 | `DepthLimitsTest` | 20 | 20.8s |  |
| 7 | `PlaceObject2Test` | 9 | 19.5s |  |
| 8 | `ResolveEventsTest` | 15 | 19.7s |  |
| 9 | `RollOverOutTest` | 5 | 19.5s |  |
| 10 | `VarAndCharClashTest` | 13 | 1.5s |  |
| 11 | `Version4Loader` | 11 | 1.4s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 19.5s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 25.0s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 2.6s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 26.1s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 3.2s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 19.8s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 20.0s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 1.4s |  |
| 21 | `attachExtImported` | 2 | 19.9s |  |
| 22 | `attachImported` | 2 | 1.5s |  |
| 23 | `attachMovieLoopingTest` | 41 | 19.4s |  |
| 24 | `attachMovieTest` | 12 | 19.9s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 1.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 16.6s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.4s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.4s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 19.5s |  |
| 35 | `event_handler_scope_test` | 16 | 1.5s |  |
| 36 | `frame_label_test` | 17 | 26.5s |  |
| 37 | `getTimer_test` | 8 | 25.3s |  |
| 38 | `get_frame_number_test` | 31 | 27.8s |  |
| 39 | `gotoFrame2Test` | 9 | 24.9s |  |
| 40 | `goto_frame_test` | 15 | 25.5s |  |
| 41 | `init_action/InitActionTest2` | 29 | 26.4s |  |
| 42 | `instanceNameTest` | 5 | 2.1s |  |
| 43 | `loading/LoadVarsTest` | 36 | 21.4s |  |
| 44 | `loop/loop_test` | 21 | 25.8s |  |
| 45 | `loop/loop_test2` | 15 | 25.4s |  |
| 46 | `loop/loop_test3` | 16 | 2.2s |  |
| 47 | `loop/loop_test4` | 22 | 2.0s |  |
| 48 | `loop/loop_test5` | 24 | 2.1s |  |
| 49 | `loop/loop_test8` | 38 | 2.9s |  |
| 50 | `loop/loop_test9` | 15 | 19.1s |  |
| 51 | `loop/simple_loop_test` | 0 | 18.7s |  |
| 52 | `masks_test2` | 10 | 19.9s |  |
| 53 | `morph_test1` | 0 | 19.5s |  |
| 54 | `move_object_test` | 11 | 18.9s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 18.9s |  |
| 56 | `new_child_in_unload_test` | 11 | 1.5s |  |
| 57 | `opcode_guard_test` | 18 | 19.1s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 19.3s |  |
| 59 | `place_and_remove_object_test` | 13 | 26.1s |  |
| 60 | `place_object_test` | 12 | 2.8s |  |
| 61 | `place_object_test2` | 19 | 26.4s |  |
| 62 | `register_class/RegisterClassTest3` | 12 | 3.0s |  |
| 63 | `register_class/registerClassTest` | 51 | 28.5s |  |
| 64 | `replace_shapes1test` | 23 | 1.9s |  |
| 65 | `replace_sprites1test` | 21 | 26.4s |  |
| 66 | `reverse_execute_PlaceObject2_test1` | 8 | 2.1s |  |
| 67 | `reverse_execute_PlaceObject2_test2` | 10 | 26.1s |  |
| 68 | `runtime_vm_stack_test` | 9 | 2.4s |  |
| 69 | `shape_test` | 21 | 23.1s |  |
| 70 | `static_vs_dynamic1` | 17 | 21.9s |  |
| 71 | `static_vs_dynamic2` | 18 | 24.7s |  |
| 72 | `timeline_var_test` | 11 | 2.4s |  |
| 73 | `unload_movieclip_test1` | 6 | 24.1s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 30.6s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.4s |  |
| 3 | `DefineTextTest` | 4 | 4 | 19.2s |  |
| 4 | `DragDropTest` | 4 | 4 | 2.5s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 4.9s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 23.0s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 1.9s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 27.4s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 19.2s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.3s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 26.1s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 27.1s |  |
| 13 | `callFunction_test` | 6 | 11 | 19.2s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 23.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 16.9s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.5s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 19.7s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 25.2s |  |
| 19 | `key_event_test` | 5 | 6 | 19.8s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 19.7s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 3.2s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 26.6s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 2.0s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 1.7s |  |
| 25 | `masks_test` | 16 | 16 | 26.2s |  |
| 26 | `matrix_test` | 5 | 9 | 81.7s |  |
| 27 | `path_format_test` | 7 | 28 | 20.6s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 20.6s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 19.7s |  |

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
