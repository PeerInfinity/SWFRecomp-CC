# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 03:52 UTC

**Git SHA**: `a18a9cc61d`

**Run Duration**: 34m 1s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **69** (62.7%) |
| Ruffle-matched | 34 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **103** (93.6%) |
| Failing | 7 |
| Total expected lines | 5206 |
| Matching lines | 4251 (81.7%) |
| Mismatched lines | 955 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 25.4s |  |
| 2 | `DefineEditTextTest` | 153 | 28.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.8s |  |
| 5 | `DepthLimitsTest` | 20 | 19.6s |  |
| 6 | `PlaceObject2Test` | 9 | 25.3s |  |
| 7 | `ResolveEventsTest` | 15 | 19.6s |  |
| 8 | `RollOverOutTest` | 5 | 19.3s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.1s |  |
| 10 | `Version4Loader` | 11 | 2.0s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.6s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 19.6s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 19.4s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.3s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.7s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 19.2s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 19.4s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.9s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.0s |  |
| 20 | `attachExtImported` | 2 | 20.0s |  |
| 21 | `attachImported` | 2 | 2.1s |  |
| 22 | `attachMovieLoopingTest` | 41 | 19.4s |  |
| 23 | `attachMovieTest` | 12 | 19.8s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 19.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 26.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 17.5s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.4s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.9s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.2s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.1s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 19.4s |  |
| 34 | `event_handler_scope_test` | 16 | 2.3s |  |
| 35 | `frame_label_test` | 17 | 20.1s |  |
| 36 | `getTimer_test` | 8 | 19.1s |  |
| 37 | `get_frame_number_test` | 31 | 20.9s |  |
| 38 | `gotoFrame2Test` | 9 | 19.0s |  |
| 39 | `goto_frame_test` | 15 | 19.4s |  |
| 40 | `instanceNameTest` | 5 | 2.0s |  |
| 41 | `loading/LoadVarsTest` | 36 | 21.8s |  |
| 42 | `loop/loop_test` | 21 | 19.1s |  |
| 43 | `loop/loop_test2` | 15 | 18.8s |  |
| 44 | `loop/loop_test3` | 16 | 2.0s |  |
| 45 | `loop/loop_test4` | 22 | 20.3s |  |
| 46 | `loop/loop_test5` | 24 | 3.0s |  |
| 47 | `loop/loop_test8` | 38 | 20.1s |  |
| 48 | `loop/loop_test9` | 15 | 18.4s |  |
| 49 | `loop/simple_loop_test` | 0 | 19.6s |  |
| 50 | `masks_test2` | 10 | 25.4s |  |
| 51 | `morph_test1` | 0 | 27.7s |  |
| 52 | `move_object_test` | 11 | 18.4s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 18.3s |  |
| 54 | `new_child_in_unload_test` | 11 | 18.3s |  |
| 55 | `opcode_guard_test` | 18 | 19.8s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 19.7s |  |
| 57 | `place_and_remove_object_test` | 13 | 26.2s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 24.5s |  |
| 59 | `register_class/registerClassTest` | 51 | 26.9s |  |
| 60 | `replace_shapes1test` | 23 | 3.9s |  |
| 61 | `replace_sprites1test` | 21 | 19.0s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 18.7s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 19.0s |  |
| 64 | `runtime_vm_stack_test` | 9 | 25.8s |  |
| 65 | `shape_test` | 21 | 27.9s |  |
| 66 | `static_vs_dynamic1` | 17 | 25.3s |  |
| 67 | `static_vs_dynamic2` | 18 | 20.3s |  |
| 68 | `timeline_var_test` | 11 | 19.7s |  |
| 69 | `unload_movieclip_test1` | 6 | 19.6s |  |

## Ruffle-Matched Tests

**34 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 27.9s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 29.0s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.8s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.1s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.9s |  |
| 6 | `DrawingApiTest` | 1 | 14 | 4.9s |  |
| 7 | `EmbeddedFontTest` | 27 | 27 | 21.7s |  |
| 8 | `KeyEventOrder` | 20 | 23 | 25.3s |  |
| 9 | `NetStream-SquareTest` | 79 | 92 | 36.6s |  |
| 10 | `PrototypeEventListeners` | 23 | 23 | 18.8s |  |
| 11 | `TextSnapshotTest` | 81 | 90 | 25.2s |  |
| 12 | `action_order/action_execution_order_test` | 12 | 12 | 20.0s |  |
| 13 | `action_order/action_execution_order_test4` | 7 | 26 | 20.2s |  |
| 14 | `action_order/action_execution_order_test6` | 5 | 21 | 20.3s |  |
| 15 | `callFunction_test` | 11 | 11 | 31.9s |  |
| 16 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.5s |  |
| 17 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 26.3s |  |
| 18 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.4s |  |
| 19 | `duplicate_movie_clip_test` | 4 | 4 | 19.6s |  |
| 20 | `init_action/InitActionTest` | 6 | 17 | 19.2s |  |
| 21 | `init_action/InitActionTest2` | 24 | 30 | 20.4s |  |
| 22 | `key_event_test` | 5 | 6 | 20.7s |  |
| 23 | `loading/LoadBitmapTest` | 3 | 3 | 20.0s |  |
| 24 | `loading/loadMovieTest` | 9 | 9 | 3.7s |  |
| 25 | `loop/loop_test10` | 23 | 23 | 19.7s |  |
| 26 | `loop/loop_test6` | 11 | 12 | 20.1s |  |
| 27 | `loop/loop_test7` | 1 | 8 | 2.5s |  |
| 28 | `masks_test` | 16 | 16 | 25.7s |  |
| 29 | `matrix_test` | 5 | 9 | 123.2s |  |
| 30 | `path_format_test` | 28 | 28 | 21.2s |  |
| 31 | `place_object_test` | 14 | 14 | 4.2s |  |
| 32 | `place_object_test2` | 22 | 23 | 26.6s |  |
| 33 | `register_class/registerClassTest2` | 8 | 28 | 27.1s |  |
| 34 | `replace_buttons1test` | 3 | 3 | 26.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 3 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 4 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 5 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 6 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 7 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
