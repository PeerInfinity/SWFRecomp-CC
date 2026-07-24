# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-24 23:01 UTC

**Git SHA**: `17c19040c9`

**Run Duration**: 22m 21s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **66** (61.1%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **94** (87.0%) |
| Failing | 14 |
| Total expected lines | 5201 |
| Matching lines | 4006 (77.0%) |
| Mismatched lines | 1195 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 1.7s |  |
| 2 | `DefineEditTextTest` | 153 | 30.8s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 26.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.6s |  |
| 5 | `DepthLimitsTest` | 20 | 16.1s |  |
| 6 | `PlaceObject2Test` | 9 | 2.9s |  |
| 7 | `ResolveEventsTest` | 15 | 3.8s |  |
| 8 | `RollOverOutTest` | 5 | 3.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.8s |  |
| 10 | `Version4Loader` | 11 | 2.8s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.7s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.0s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 3.0s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.8s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 17.9s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 2.4s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.8s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.0s |  |
| 20 | `attachExtImported` | 2 | 22.0s |  |
| 21 | `attachImported` | 2 | 2.8s |  |
| 22 | `attachMovieLoopingTest` | 41 | 21.1s |  |
| 23 | `attachMovieTest` | 12 | 21.8s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 20.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 2.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.8s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.7s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.6s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.9s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.5s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.9s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 4.0s |  |
| 34 | `event_handler_scope_test` | 16 | 3.2s |  |
| 35 | `frame_label_test` | 17 | 4.0s |  |
| 36 | `getTimer_test` | 8 | 15.8s |  |
| 37 | `get_frame_number_test` | 31 | 4.5s |  |
| 38 | `gotoFrame2Test` | 9 | 16.0s |  |
| 39 | `goto_frame_test` | 15 | 17.8s |  |
| 40 | `instanceNameTest` | 5 | 2.2s |  |
| 41 | `loading/LoadVarsTest` | 36 | 23.7s |  |
| 42 | `loop/loop_test` | 21 | 18.6s |  |
| 43 | `loop/loop_test2` | 15 | 2.2s |  |
| 44 | `loop/loop_test3` | 16 | 2.2s |  |
| 45 | `loop/loop_test4` | 22 | 3.7s |  |
| 46 | `loop/loop_test5` | 24 | 3.8s |  |
| 47 | `loop/loop_test8` | 38 | 5.2s |  |
| 48 | `loop/loop_test9` | 15 | 21.0s |  |
| 49 | `loop/simple_loop_test` | 0 | 25.0s |  |
| 50 | `masks_test2` | 10 | 21.3s |  |
| 51 | `morph_test1` | 0 | 24.8s |  |
| 52 | `move_object_test` | 11 | 2.9s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 21.2s |  |
| 54 | `new_child_in_unload_test` | 11 | 21.3s |  |
| 55 | `opcode_guard_test` | 18 | 21.6s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 21.6s |  |
| 57 | `place_and_remove_object_test` | 13 | 21.5s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 21.6s |  |
| 59 | `register_class/registerClassTest` | 51 | 23.9s |  |
| 60 | `replace_shapes1test` | 23 | 2.7s |  |
| 61 | `replace_sprites1test` | 21 | 0.7s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 0.8s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 0.8s |  |
| 64 | `static_vs_dynamic2` | 18 | 21.9s |  |
| 65 | `timeline_var_test` | 11 | 3.1s |  |
| 66 | `unload_movieclip_test1` | 6 | 2.8s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 1.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 1.2s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 0.9s |  |
| 4 | `DefineTextTest` | 4 | 4 | 3.1s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.5s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 4.8s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 3.2s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 29.5s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 22.5s |  |
| 10 | `callFunction_test` | 6 | 11 | 3.6s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 29.0s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.9s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.8s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 4.4s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 17.4s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 3.9s |  |
| 17 | `key_event_test` | 5 | 6 | 22.2s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 3.9s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 5.2s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 19.4s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 21.7s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.1s |  |
| 23 | `matrix_test` | 5 | 9 | 105.4s |  |
| 24 | `path_format_test` | 28 | 28 | 5.5s |  |
| 25 | `place_object_test` | 14 | 14 | 22.4s |  |
| 26 | `place_object_test2` | 22 | 23 | 3.4s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 19.0s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 2.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**14 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 4 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 5 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 6 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 7 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 8 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 9 | `register_class/RegisterClassTest4` | 10.5% | 6/57 | 57 | 42 |  |
| 10 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 11 | `action_order/ActionOrderTest4` | 9.5% | 10/105 | 105 | 64 |  |
| 12 | `action_order/ActionOrderTest3` | 5.5% | 4/73 | 73 | 62 |  |
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
