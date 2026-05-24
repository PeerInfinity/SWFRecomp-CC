# Ruffle Test Results (Filtered)

**Date**: 2026-05-24 00:04 UTC

**Git SHA**: `2d64da6746`

**Run Duration**: 1m 6s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **67** (62.0%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **94** (87.0%) |
| Failing | 14 |
| Total expected lines | 5179 |
| Matching lines | 4012 (77.5%) |
| Mismatched lines | 1167 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**67 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.2s |  |
| 2 | `DefineEditTextTest` | 153 | 0.8s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 0.6s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 0.4s |  |
| 5 | `DepthLimitsTest` | 20 | 0.3s |  |
| 6 | `PlaceObject2Test` | 9 | 0.2s |  |
| 7 | `ResolveEventsTest` | 15 | 0.6s |  |
| 8 | `RollOverOutTest` | 5 | 0.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 10 | `Version4Loader` | 11 | 0.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 0.2s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 0.3s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 0.3s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 0.3s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 0.2s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 0.2s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 0.2s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.2s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.2s |  |
| 20 | `attachExtImported` | 2 | 0.3s |  |
| 21 | `attachImported` | 2 | 0.3s |  |
| 22 | `attachMovieLoopingTest` | 41 | 0.2s |  |
| 23 | `attachMovieTest` | 12 | 0.2s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 0.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.2s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.3s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 0.3s |  |
| 34 | `event_handler_scope_test` | 16 | 0.2s |  |
| 35 | `frame_label_test` | 17 | 0.3s |  |
| 36 | `getTimer_test` | 8 | 0.2s |  |
| 37 | `get_frame_number_test` | 31 | 0.4s |  |
| 38 | `goto_frame_test` | 15 | 0.2s |  |
| 39 | `instanceNameTest` | 5 | 0.2s |  |
| 40 | `loading/LoadVarsTest` | 36 | 0.5s |  |
| 41 | `loop/loop_test` | 21 | 0.4s |  |
| 42 | `loop/loop_test2` | 15 | 0.2s |  |
| 43 | `loop/loop_test3` | 16 | 0.2s |  |
| 44 | `loop/loop_test4` | 22 | 0.2s |  |
| 45 | `loop/loop_test5` | 24 | 0.3s |  |
| 46 | `loop/loop_test8` | 38 | 0.4s |  |
| 47 | `loop/loop_test9` | 15 | 0.2s |  |
| 48 | `loop/simple_loop_test` | 0 | 0.2s |  |
| 49 | `masks_test2` | 10 | 0.2s |  |
| 50 | `morph_test1` | 0 | 0.2s |  |
| 51 | `move_object_test` | 11 | 0.2s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 0.2s |  |
| 53 | `new_child_in_unload_test` | 11 | 0.2s |  |
| 54 | `place_and_remove_object_insane_test` | 22 | 0.3s |  |
| 55 | `place_and_remove_object_test` | 13 | 0.2s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 0.2s |  |
| 57 | `register_class/registerClassTest` | 51 | 0.3s |  |
| 58 | `replace_shapes1test` | 23 | 0.3s |  |
| 59 | `replace_sprites1test` | 21 | 0.2s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 0.2s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 0.2s |  |
| 62 | `runtime_vm_stack_test` | 9 | 0.3s |  |
| 63 | `shape_test` | 21 | 0.3s |  |
| 64 | `static_vs_dynamic1` | 17 | 0.2s |  |
| 65 | `static_vs_dynamic2` | 18 | 0.2s |  |
| 66 | `timeline_var_test` | 11 | 0.2s |  |
| 67 | `unload_movieclip_test1` | 6 | 0.2s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 0.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 0.5s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 0.2s |  |
| 4 | `DefineTextTest` | 4 | 4 | 0.2s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.2s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 0.2s |  |
| 7 | `TextSnapshotTest` | 81 | 90 | 1.2s |  |
| 8 | `action_order/action_execution_order_test4` | 7 | 26 | 0.3s |  |
| 9 | `callFunction_test` | 6 | 11 | 0.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 0.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.3s |  |
| 12 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 13 | `duplicate_movie_clip_test` | 4 | 4 | 0.3s |  |
| 14 | `init_action/InitActionTest` | 6 | 17 | 0.3s |  |
| 15 | `init_action/InitActionTest2` | 24 | 30 | 0.3s |  |
| 16 | `key_event_test` | 5 | 6 | 0.3s |  |
| 17 | `loading/LoadBitmapTest` | 3 | 3 | 0.3s |  |
| 18 | `loading/loadMovieTest` | 9 | 9 | 0.6s |  |
| 19 | `loop/loop_test10` | 23 | 23 | 0.2s |  |
| 20 | `loop/loop_test6` | 1 | 12 | 0.3s |  |
| 21 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 22 | `matrix_test` | 5 | 9 | 4.6s |  |
| 23 | `path_format_test` | 28 | 28 | 0.4s |  |
| 24 | `place_object_test` | 14 | 14 | 0.3s |  |
| 25 | `place_object_test2` | 22 | 23 | 0.3s |  |
| 26 | `register_class/registerClassTest2` | 8 | 28 | 0.2s |  |
| 27 | `replace_buttons1test` | 3 | 3 | 0.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |

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
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 4 | `action_order/action_execution_order_test5` | 44.1% | 26/59 | 59 | 35 |  |
| 5 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 6 | `NetStream-SquareTest` | 42.6% | 92/216 | 201 | 216 |  |
| 7 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 8 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 9 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 10 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 11 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 12 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
