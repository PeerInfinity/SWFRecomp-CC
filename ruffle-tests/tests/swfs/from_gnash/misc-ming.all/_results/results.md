# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 22:24 UTC

**Git SHA**: `0224aaf256`

**Run Duration**: 30m 32s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **76** (68.5%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **103** (92.8%) |
| Failing | 8 |
| Total expected lines | 5248 |
| Matching lines | 4168 (79.4%) |
| Mismatched lines | 1080 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**76 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 28.2s |  |
| 2 | `BitmapDataDraw` | 56 | 31.9s |  |
| 3 | `DefineEditTextTest` | 153 | 33.2s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 29.8s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 26.9s |  |
| 6 | `DepthLimitsTest` | 20 | 21.8s |  |
| 7 | `PlaceObject2Test` | 9 | 2.4s |  |
| 8 | `ResolveEventsTest` | 15 | 2.2s |  |
| 9 | `RollOverOutTest` | 5 | 2.0s |  |
| 10 | `VarAndCharClashTest` | 13 | 2.2s |  |
| 11 | `Version4Loader` | 11 | 2.1s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 25.6s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 20.0s |  |
| 14 | `action_order/action_execution_order_test11` | 32 | 20.9s |  |
| 15 | `action_order/action_execution_order_test2` | 5 | 20.2s |  |
| 16 | `action_order/action_execution_order_test3` | 4 | 18.8s |  |
| 17 | `action_order/action_execution_order_test4` | 26 | 19.4s |  |
| 18 | `action_order/action_execution_order_test5` | 35 | 1.7s |  |
| 19 | `action_order/action_execution_order_test7` | 7 | 24.8s |  |
| 20 | `action_order/action_execution_order_test8-v5` | 11 | 25.4s |  |
| 21 | `action_order/action_execution_order_test8-v6` | 11 | 0.5s |  |
| 22 | `action_order/action_execution_order_test9` | 4 | 1.9s |  |
| 23 | `attachExtImported` | 2 | 20.8s |  |
| 24 | `attachImported` | 2 | 1.5s |  |
| 25 | `attachMovieLoopingTest` | 41 | 20.0s |  |
| 26 | `attachMovieTest` | 12 | 20.7s |  |
| 27 | `consecutive_goto_frame_test` | 12 | 21.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.0s |  |
| 32 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.0s |  |
| 33 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.4s |  |
| 34 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.8s |  |
| 35 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.1s |  |
| 36 | `duplicate_movie_clip_test2` | 21 | 20.5s |  |
| 37 | `event_handler_scope_test` | 16 | 1.7s |  |
| 38 | `frame_label_test` | 17 | 20.8s |  |
| 39 | `getTimer_test` | 8 | 19.8s |  |
| 40 | `get_frame_number_test` | 31 | 21.7s |  |
| 41 | `gotoFrame2Test` | 9 | 19.8s |  |
| 42 | `goto_frame_test` | 15 | 20.5s |  |
| 43 | `init_action/InitActionTest2` | 29 | 21.5s |  |
| 44 | `instanceNameTest` | 5 | 1.5s |  |
| 45 | `loading/LoadVarsTest` | 36 | 23.7s |  |
| 46 | `loop/loop_test` | 21 | 24.9s |  |
| 47 | `loop/loop_test2` | 15 | 2.1s |  |
| 48 | `loop/loop_test3` | 16 | 2.2s |  |
| 49 | `loop/loop_test4` | 22 | 20.0s |  |
| 50 | `loop/loop_test5` | 24 | 2.2s |  |
| 51 | `loop/loop_test8` | 38 | 22.8s |  |
| 52 | `loop/loop_test9` | 15 | 20.8s |  |
| 53 | `loop/simple_loop_test` | 0 | 20.5s |  |
| 54 | `masks_test2` | 10 | 21.2s |  |
| 55 | `matrix_test` | 1086 | 103.6s |  |
| 56 | `morph_test1` | 0 | 21.9s |  |
| 57 | `move_object_test` | 11 | 19.6s |  |
| 58 | `multi_doactions_and_goto_frame_test` | 6 | 19.7s |  |
| 59 | `new_child_in_unload_test` | 11 | 19.7s |  |
| 60 | `opcode_guard_test` | 18 | 21.0s |  |
| 61 | `place_and_remove_object_insane_test` | 22 | 20.9s |  |
| 62 | `place_and_remove_object_test` | 13 | 19.8s |  |
| 63 | `place_object_test` | 12 | 1.8s |  |
| 64 | `place_object_test2` | 19 | 19.7s |  |
| 65 | `register_class/RegisterClassTest3` | 12 | 20.0s |  |
| 66 | `register_class/registerClassTest` | 51 | 21.2s |  |
| 67 | `replace_shapes1test` | 23 | 1.9s |  |
| 68 | `replace_sprites1test` | 21 | 20.0s |  |
| 69 | `reverse_execute_PlaceObject2_test1` | 8 | 19.4s |  |
| 70 | `reverse_execute_PlaceObject2_test2` | 10 | 19.6s |  |
| 71 | `runtime_vm_stack_test` | 9 | 20.7s |  |
| 72 | `shape_test` | 21 | 21.6s |  |
| 73 | `static_vs_dynamic1` | 17 | 20.2s |  |
| 74 | `static_vs_dynamic2` | 18 | 21.5s |  |
| 75 | `timeline_var_test` | 11 | 2.1s |  |
| 76 | `unload_movieclip_test1` | 6 | 1.8s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 19 | 20 | 2.4s |  |
| 2 | `DefineTextTest` | 4 | 4 | 24.8s |  |
| 3 | `DragDropTest` | 4 | 4 | 2.8s |  |
| 4 | `DrawingApiTest` | 1 | 14 | 5.7s |  |
| 5 | `EmbeddedFontTest` | 27 | 27 | 24.4s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 2.7s |  |
| 7 | `NetStream-SquareTest` | 79 | 92 | 35.8s |  |
| 8 | `PrototypeEventListeners` | 23 | 23 | 15.5s |  |
| 9 | `TextSnapshotTest` | 81 | 90 | 21.8s |  |
| 10 | `action_order/action_execution_order_test` | 12 | 12 | 20.1s |  |
| 11 | `action_order/action_execution_order_test6` | 5 | 21 | 19.4s |  |
| 12 | `callFunction_test` | 6 | 11 | 21.7s |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.8s |  |
| 14 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.1s |  |
| 15 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.5s |  |
| 16 | `duplicate_movie_clip_test` | 4 | 4 | 20.3s |  |
| 17 | `init_action/InitActionTest` | 6 | 17 | 20.3s |  |
| 18 | `key_event_test` | 5 | 6 | 21.9s |  |
| 19 | `loading/LoadBitmapTest` | 2 | 3 | 21.6s |  |
| 20 | `loading/loadMovieTest` | 9 | 9 | 3.6s |  |
| 21 | `loop/loop_test10` | 23 | 23 | 25.7s |  |
| 22 | `loop/loop_test6` | 11 | 12 | 20.0s |  |
| 23 | `loop/loop_test7` | 1 | 8 | 1.7s |  |
| 24 | `masks_test` | 16 | 16 | 30.7s |  |
| 25 | `path_format_test` | 7 | 28 | 3.6s |  |
| 26 | `register_class/registerClassTest2` | 8 | 28 | 21.5s |  |
| 27 | `replace_buttons1test` | 3 | 3 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `ButtonEventsTest` | 67.5% | 458 | 679 | 221 |  |

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
| 1 | `ButtonEventsTest` | 67.5% | 458/679 | 679 | 679 |  |
| 2 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 3 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 30 | 32 |  |
| 4 | `action_order/ActionOrderTest4` | 16.7% | 14/84 | 84 | 64 |  |
| 5 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 15 | 96 |  |
| 6 | `action_order/ActionOrderTest5` | 13.7% | 7/51 | 48 | 51 |  |
| 7 | `register_class/RegisterClassTest4` | 13.0% | 7/54 | 54 | 42 |  |
| 8 | `action_order/ActionOrderTest3` | 4.1% | 3/73 | 73 | 62 |  |
