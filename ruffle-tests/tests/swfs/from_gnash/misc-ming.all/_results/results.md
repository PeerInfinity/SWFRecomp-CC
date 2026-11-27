# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 07:04 UTC

**Git SHA**: `2d40d37996`

**Run Duration**: 30m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **72** (66.7%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **99** (91.7%) |
| Failing | 9 |
| Total expected lines | 5181 |
| Matching lines | 4305 (83.1%) |
| Mismatched lines | 876 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**72 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.5s |  |
| 2 | `BitmapDataDraw` | 56 | 22.7s |  |
| 3 | `DefineEditTextTest` | 153 | 7.9s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 23.2s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 21.0s |  |
| 6 | `DepthLimitsTest` | 20 | 20.9s |  |
| 7 | `PlaceObject2Test` | 9 | 19.3s |  |
| 8 | `ResolveEventsTest` | 15 | 24.9s |  |
| 9 | `RollOverOutTest` | 5 | 24.5s |  |
| 10 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 11 | `Version4Loader` | 11 | 1.4s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 20.0s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 21.2s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 21.3s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 18.8s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 1.9s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 25.0s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 25.5s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 0.5s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 2.2s |  |
| 21 | `attachExtImported` | 2 | 22.8s |  |
| 22 | `attachImported` | 2 | 2.0s |  |
| 23 | `attachMovieLoopingTest` | 41 | 22.0s |  |
| 24 | `attachMovieTest` | 12 | 22.5s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 19.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 26.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.6s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.4s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.4s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 20.4s |  |
| 35 | `event_handler_scope_test` | 16 | 1.7s |  |
| 36 | `frame_label_test` | 17 | 2.4s |  |
| 37 | `getTimer_test` | 8 | 1.5s |  |
| 38 | `get_frame_number_test` | 31 | 21.0s |  |
| 39 | `gotoFrame2Test` | 9 | 19.4s |  |
| 40 | `goto_frame_test` | 15 | 19.8s |  |
| 41 | `init_action/InitActionTest2` | 29 | 20.3s |  |
| 42 | `instanceNameTest` | 5 | 1.4s |  |
| 43 | `loading/LoadVarsTest` | 36 | 23.4s |  |
| 44 | `loop/loop_test` | 21 | 25.9s |  |
| 45 | `loop/loop_test2` | 15 | 2.3s |  |
| 46 | `loop/loop_test3` | 16 | 2.3s |  |
| 47 | `loop/loop_test4` | 22 | 22.0s |  |
| 48 | `loop/loop_test5` | 24 | 2.9s |  |
| 49 | `loop/loop_test8` | 38 | 21.2s |  |
| 50 | `loop/loop_test9` | 15 | 19.8s |  |
| 51 | `loop/simple_loop_test` | 0 | 1.2s |  |
| 52 | `masks_test2` | 10 | 25.7s |  |
| 53 | `matrix_test` | 1086 | 122.2s |  |
| 54 | `morph_test1` | 0 | 25.5s |  |
| 55 | `move_object_test` | 11 | 19.3s |  |
| 56 | `multi_doactions_and_goto_frame_test` | 6 | 19.2s |  |
| 57 | `new_child_in_unload_test` | 11 | 19.4s |  |
| 58 | `place_and_remove_object_test` | 13 | 18.8s |  |
| 59 | `place_object_test` | 12 | 1.7s |  |
| 60 | `place_object_test2` | 19 | 19.2s |  |
| 61 | `register_class/RegisterClassTest3` | 12 | 19.5s |  |
| 62 | `register_class/registerClassTest` | 51 | 21.1s |  |
| 63 | `replace_shapes1test` | 23 | 2.6s |  |
| 64 | `replace_sprites1test` | 21 | 1.8s |  |
| 65 | `reverse_execute_PlaceObject2_test1` | 8 | 19.3s |  |
| 66 | `reverse_execute_PlaceObject2_test2` | 10 | 19.6s |  |
| 67 | `runtime_vm_stack_test` | 9 | 27.8s |  |
| 68 | `shape_test` | 21 | 28.2s |  |
| 69 | `static_vs_dynamic1` | 17 | 26.0s |  |
| 70 | `static_vs_dynamic2` | 18 | 25.8s |  |
| 71 | `timeline_var_test` | 11 | 25.6s |  |
| 72 | `unload_movieclip_test1` | 6 | 25.3s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 13 | 642 | 23.5s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 1.6s |  |
| 3 | `DefineTextTest` | 4 | 4 | 1.7s |  |
| 4 | `DragDropTest` | 4 | 4 | 2.5s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 5.0s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 23.1s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 19.5s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 26.2s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 23.9s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 32.3s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 21.6s |  |
| 12 | `action_order/action_execution_order_test6` | 5 | 21 | 19.3s |  |
| 13 | `callFunction_test` | 6 | 11 | 19.9s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.5s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 26.3s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.4s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 20.9s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 19.6s |  |
| 19 | `key_event_test` | 5 | 6 | 22.2s |  |
| 20 | `loading/LoadBitmapTest` | 2 | 3 | 21.7s |  |
| 21 | `loading/loadMovieTest` | 9 | 9 | 3.3s |  |
| 22 | `loop/loop_test10` | 23 | 23 | 27.8s |  |
| 23 | `loop/loop_test6` | 11 | 12 | 21.6s |  |
| 24 | `loop/loop_test7` | 1 | 8 | 2.2s |  |
| 25 | `masks_test` | 16 | 16 | 27.1s |  |
| 26 | `register_class/registerClassTest2` | 8 | 28 | 27.6s |  |
| 27 | `replace_buttons1test` | 3 | 3 | 2.6s |  |

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

**9 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 84.4% | 27/32 | 32 | 32 |  |
| 2 | `action_order/action_execution_order_test4` | 73.1% | 19/26 | 26 | 26 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 30 | 32 |  |
| 5 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 6 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 7 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 8 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 9 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
