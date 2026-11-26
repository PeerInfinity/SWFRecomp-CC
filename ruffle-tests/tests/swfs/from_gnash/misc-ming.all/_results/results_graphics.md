# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-26 23:43 UTC

**Git SHA**: `4989a9dfb5`

**Run Duration**: 24m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **73** (65.8%) |
| Ruffle-matched | 29 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (91.9%) |
| Failing | 9 |
| Total expected lines | 5248 |
| Matching lines | 4359 (83.1%) |
| Mismatched lines | 889 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**73 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 22.8s |  |
| 2 | `BitmapDataDraw` | 56 | 25.2s |  |
| 3 | `DefineEditTextTest` | 153 | 26.9s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 24.9s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 23.7s |  |
| 6 | `DepthLimitsTest` | 20 | 21.2s |  |
| 7 | `PlaceObject2Test` | 9 | 20.2s |  |
| 8 | `ResolveEventsTest` | 15 | 29.3s |  |
| 9 | `RollOverOutTest` | 5 | 4.5s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.1s |  |
| 11 | `Version4Loader` | 11 | 2.0s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 19.7s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 2.4s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 20.3s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 3.3s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 4.1s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 26.4s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 3.5s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 1.4s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.9s |  |
| 21 | `attachExtImported` | 2 | 20.9s |  |
| 22 | `attachImported` | 2 | 2.2s |  |
| 23 | `attachMovieLoopingTest` | 41 | 20.0s |  |
| 24 | `attachMovieTest` | 12 | 20.4s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 19.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.6s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.5s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.4s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.7s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 3.0s |  |
| 35 | `event_handler_scope_test` | 16 | 2.5s |  |
| 36 | `frame_label_test` | 17 | 3.1s |  |
| 37 | `getTimer_test` | 8 | 19.8s |  |
| 38 | `get_frame_number_test` | 31 | 21.3s |  |
| 39 | `gotoFrame2Test` | 9 | 19.3s |  |
| 40 | `goto_frame_test` | 15 | 20.4s |  |
| 41 | `init_action/InitActionTest2` | 29 | 21.0s |  |
| 42 | `instanceNameTest` | 5 | 2.1s |  |
| 43 | `loading/LoadVarsTest` | 36 | 21.6s |  |
| 44 | `loop/loop_test` | 21 | 3.1s |  |
| 45 | `loop/loop_test2` | 15 | 2.7s |  |
| 46 | `loop/loop_test3` | 16 | 2.7s |  |
| 47 | `loop/loop_test4` | 22 | 20.3s |  |
| 48 | `loop/loop_test5` | 24 | 2.9s |  |
| 49 | `loop/loop_test8` | 38 | 21.1s |  |
| 50 | `loop/loop_test9` | 15 | 2.2s |  |
| 51 | `loop/simple_loop_test` | 0 | 3.2s |  |
| 52 | `masks_test2` | 10 | 2.4s |  |
| 53 | `morph_test1` | 0 | 22.1s |  |
| 54 | `move_object_test` | 11 | 20.8s |  |
| 55 | `multi_doactions_and_goto_frame_test` | 6 | 2.4s |  |
| 56 | `new_child_in_unload_test` | 11 | 21.0s |  |
| 57 | `opcode_guard_test` | 18 | 0.9s |  |
| 58 | `place_and_remove_object_insane_test` | 22 | 0.9s |  |
| 59 | `place_and_remove_object_test` | 13 | 3.0s |  |
| 60 | `place_object_test` | 12 | 4.5s |  |
| 61 | `place_object_test2` | 19 | 22.6s |  |
| 62 | `register_class/RegisterClassTest3` | 12 | 27.7s |  |
| 63 | `register_class/registerClassTest` | 51 | 30.2s |  |
| 64 | `replace_shapes1test` | 23 | 3.2s |  |
| 65 | `replace_sprites1test` | 21 | 2.6s |  |
| 66 | `reverse_execute_PlaceObject2_test1` | 8 | 19.8s |  |
| 67 | `reverse_execute_PlaceObject2_test2` | 10 | 20.0s |  |
| 68 | `runtime_vm_stack_test` | 9 | 20.7s |  |
| 69 | `shape_test` | 21 | 3.7s |  |
| 70 | `static_vs_dynamic1` | 17 | 2.2s |  |
| 71 | `static_vs_dynamic2` | 18 | 20.0s |  |
| 72 | `timeline_var_test` | 11 | 19.9s |  |
| 73 | `unload_movieclip_test1` | 6 | 2.1s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 26.4s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 2.9s |  |
| 3 | `DefineTextTest` | 4 | 4 | 2.7s |  |
| 4 | `DragDropTest` | 4 | 4 | 3.2s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 5.6s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 23.5s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 20.6s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 9.9s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 27.3s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 14.2s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 2.7s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 4.5s |  |
| 13 | `callFunction_test` | 6 | 11 | 2.7s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.5s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.8s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.6s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 21.1s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 2.5s |  |
| 19 | `key_event_test` | 5 | 6 | 21.2s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 20.1s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 3.6s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 21.9s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 20.4s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 2.5s |  |
| 25 | `masks_test` | 16 | 16 | 26.8s |  |
| 26 | `matrix_test` | 5 | 9 | 82.1s |  |
| 27 | `path_format_test` | 7 | 28 | 1.0s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 22.3s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 3.2s |  |

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

**9 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `action_order/action_execution_order_test4` | 73.1% | 19/26 | 26 | 26 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 30 | 32 |  |
| 5 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 15 | 96 |  |
| 7 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 8 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 9 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
