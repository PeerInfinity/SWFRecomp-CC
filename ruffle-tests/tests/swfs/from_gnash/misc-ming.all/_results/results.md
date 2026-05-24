# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-24 01:03 UTC

**Git SHA**: `897b026fac`

**Run Duration**: 28m 37s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **67** (60.9%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **94** (85.5%) |
| Failing | 16 |
| Total expected lines | 5239 |
| Matching lines | 4026 (76.8%) |
| Mismatched lines | 1213 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 16 | 100.0% |

## Passing Tests

**67 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.7s |  |
| 2 | `DefineEditTextTest` | 153 | 19.9s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 19.6s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.3s |  |
| 5 | `DepthLimitsTest` | 20 | 18.6s |  |
| 6 | `PlaceObject2Test` | 9 | 19.9s |  |
| 7 | `ResolveEventsTest` | 15 | 19.1s |  |
| 8 | `RollOverOutTest` | 5 | 19.3s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.5s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 18.6s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.3s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 18.4s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 19.3s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 19.3s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 19.3s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 20 | `attachExtImported` | 2 | 18.7s |  |
| 21 | `attachImported` | 2 | 0.4s |  |
| 22 | `attachMovieLoopingTest` | 41 | 18.7s |  |
| 23 | `attachMovieTest` | 12 | 18.7s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 18.3s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.2s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.3s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.6s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 18.2s |  |
| 34 | `event_handler_scope_test` | 16 | 0.3s |  |
| 35 | `frame_label_test` | 17 | 18.9s |  |
| 36 | `getTimer_test` | 8 | 18.8s |  |
| 37 | `get_frame_number_test` | 31 | 18.9s |  |
| 38 | `goto_frame_test` | 15 | 18.6s |  |
| 39 | `instanceNameTest` | 5 | 0.6s |  |
| 40 | `loading/LoadVarsTest` | 36 | 20.1s |  |
| 41 | `loop/loop_test` | 21 | 19.2s |  |
| 42 | `loop/loop_test2` | 15 | 19.4s |  |
| 43 | `loop/loop_test3` | 16 | 0.5s |  |
| 44 | `loop/loop_test4` | 22 | 19.7s |  |
| 45 | `loop/loop_test5` | 24 | 18.1s |  |
| 46 | `loop/loop_test8` | 38 | 0.8s |  |
| 47 | `loop/loop_test9` | 15 | 18.6s |  |
| 48 | `loop/simple_loop_test` | 0 | 18.8s |  |
| 49 | `masks_test2` | 10 | 19.0s |  |
| 50 | `morph_test1` | 0 | 19.0s |  |
| 51 | `move_object_test` | 11 | 18.9s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 19.2s |  |
| 53 | `new_child_in_unload_test` | 11 | 19.5s |  |
| 54 | `place_and_remove_object_insane_test` | 22 | 19.1s |  |
| 55 | `place_and_remove_object_test` | 13 | 19.1s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 19.1s |  |
| 57 | `register_class/registerClassTest` | 51 | 19.5s |  |
| 58 | `replace_shapes1test` | 23 | 0.4s |  |
| 59 | `replace_sprites1test` | 21 | 18.7s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 18.8s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 18.7s |  |
| 62 | `runtime_vm_stack_test` | 9 | 20.1s |  |
| 63 | `shape_test` | 21 | 19.9s |  |
| 64 | `static_vs_dynamic1` | 17 | 19.4s |  |
| 65 | `static_vs_dynamic2` | 18 | 18.5s |  |
| 66 | `timeline_var_test` | 11 | 18.4s |  |
| 67 | `unload_movieclip_test1` | 6 | 18.5s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.0s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 19.0s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 18.6s |  |
| 4 | `DefineTextTest` | 4 | 4 | 19.0s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 20.0s |  |
| 7 | `TextSnapshotTest` | 81 | 90 | 20.0s |  |
| 8 | `action_order/action_execution_order_test4` | 7 | 26 | 19.1s |  |
| 9 | `callFunction_test` | 6 | 11 | 18.4s |  |
| 10 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 18.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.2s |  |
| 12 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.5s |  |
| 13 | `duplicate_movie_clip_test` | 4 | 4 | 18.2s |  |
| 14 | `init_action/InitActionTest` | 6 | 17 | 18.7s |  |
| 15 | `init_action/InitActionTest2` | 24 | 30 | 18.5s |  |
| 16 | `key_event_test` | 5 | 6 | 18.7s |  |
| 17 | `loading/LoadBitmapTest` | 3 | 3 | 19.9s |  |
| 18 | `loading/loadMovieTest` | 9 | 9 | 0.9s |  |
| 19 | `loop/loop_test10` | 23 | 23 | 19.8s |  |
| 20 | `loop/loop_test6` | 1 | 12 | 18.0s |  |
| 21 | `loop/loop_test7` | 1 | 8 | 0.4s |  |
| 22 | `matrix_test` | 5 | 9 | 27.3s |  |
| 23 | `path_format_test` | 28 | 28 | 19.0s |  |
| 24 | `place_object_test` | 14 | 14 | 19.7s |  |
| 25 | `place_object_test2` | 22 | 23 | 19.3s |  |
| 26 | `register_class/registerClassTest2` | 8 | 28 | 18.4s |  |
| 27 | `replace_buttons1test` | 3 | 3 | 18.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 4 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**16 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 4 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 5 | `action_order/action_execution_order_test5` | 44.1% | 26/59 | 59 | 35 |  |
| 6 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 7 | `NetStream-SquareTest` | 42.6% | 92/216 | 201 | 216 |  |
| 8 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 9 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 10 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 11 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 14 | `register_class/RegisterClassTest4` | 5.2% | 3/58 | 58 | 42 |  |
| 15 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 16 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
