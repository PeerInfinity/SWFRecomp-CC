# Ruffle Test Results (Filtered)

**Date**: 2026-05-24 02:04 UTC

**Git SHA**: `637d28c031`

**Run Duration**: 28m 12s

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
| 1 | `BeginBitmapFill` | 1 | 18.9s |  |
| 2 | `DefineEditTextTest` | 153 | 20.0s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 19.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.4s |  |
| 5 | `DepthLimitsTest` | 20 | 19.5s |  |
| 6 | `PlaceObject2Test` | 9 | 18.4s |  |
| 7 | `ResolveEventsTest` | 15 | 18.8s |  |
| 8 | `RollOverOutTest` | 5 | 18.5s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.4s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.1s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 18.8s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.6s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 18.8s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 18.2s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 18.9s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 18.9s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 20 | `attachExtImported` | 2 | 19.3s |  |
| 21 | `attachImported` | 2 | 0.4s |  |
| 22 | `attachMovieLoopingTest` | 41 | 19.0s |  |
| 23 | `attachMovieTest` | 12 | 19.1s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 18.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.3s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.4s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 19.4s |  |
| 34 | `event_handler_scope_test` | 16 | 0.3s |  |
| 35 | `frame_label_test` | 17 | 18.5s |  |
| 36 | `getTimer_test` | 8 | 18.3s |  |
| 37 | `get_frame_number_test` | 31 | 18.4s |  |
| 38 | `goto_frame_test` | 15 | 18.2s |  |
| 39 | `instanceNameTest` | 5 | 0.7s |  |
| 40 | `loading/LoadVarsTest` | 36 | 20.6s |  |
| 41 | `loop/loop_test` | 21 | 20.1s |  |
| 42 | `loop/loop_test2` | 15 | 18.4s |  |
| 43 | `loop/loop_test3` | 16 | 0.5s |  |
| 44 | `loop/loop_test4` | 22 | 18.2s |  |
| 45 | `loop/loop_test5` | 24 | 20.0s |  |
| 46 | `loop/loop_test8` | 38 | 0.9s |  |
| 47 | `loop/loop_test9` | 15 | 18.6s |  |
| 48 | `loop/simple_loop_test` | 0 | 19.0s |  |
| 49 | `masks_test2` | 10 | 18.9s |  |
| 50 | `morph_test1` | 0 | 19.0s |  |
| 51 | `move_object_test` | 11 | 19.3s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 19.3s |  |
| 53 | `new_child_in_unload_test` | 11 | 19.3s |  |
| 54 | `place_and_remove_object_insane_test` | 22 | 18.6s |  |
| 55 | `place_and_remove_object_test` | 13 | 18.9s |  |
| 56 | `register_class/RegisterClassTest3` | 12 | 18.5s |  |
| 57 | `register_class/registerClassTest` | 51 | 18.9s |  |
| 58 | `replace_shapes1test` | 23 | 0.3s |  |
| 59 | `replace_sprites1test` | 21 | 18.1s |  |
| 60 | `reverse_execute_PlaceObject2_test1` | 8 | 17.8s |  |
| 61 | `reverse_execute_PlaceObject2_test2` | 10 | 18.1s |  |
| 62 | `runtime_vm_stack_test` | 9 | 18.8s |  |
| 63 | `shape_test` | 21 | 19.0s |  |
| 64 | `static_vs_dynamic1` | 17 | 18.6s |  |
| 65 | `static_vs_dynamic2` | 18 | 18.6s |  |
| 66 | `timeline_var_test` | 11 | 18.7s |  |
| 67 | `unload_movieclip_test1` | 6 | 18.8s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 18.9s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 18.6s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 18.1s |  |
| 4 | `DefineTextTest` | 4 | 4 | 19.0s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 19.0s |  |
| 7 | `TextSnapshotTest` | 81 | 90 | 19.7s |  |
| 8 | `action_order/action_execution_order_test4` | 7 | 26 | 18.1s |  |
| 9 | `callFunction_test` | 6 | 11 | 19.2s |  |
| 10 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 19.3s |  |
| 11 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 17.8s |  |
| 12 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.4s |  |
| 13 | `duplicate_movie_clip_test` | 4 | 4 | 19.6s |  |
| 14 | `init_action/InitActionTest` | 6 | 17 | 18.6s |  |
| 15 | `init_action/InitActionTest2` | 24 | 30 | 18.7s |  |
| 16 | `key_event_test` | 5 | 6 | 18.9s |  |
| 17 | `loading/LoadBitmapTest` | 3 | 3 | 21.1s |  |
| 18 | `loading/loadMovieTest` | 9 | 9 | 0.9s |  |
| 19 | `loop/loop_test10` | 23 | 23 | 18.5s |  |
| 20 | `loop/loop_test6` | 1 | 12 | 19.9s |  |
| 21 | `loop/loop_test7` | 1 | 8 | 0.5s |  |
| 22 | `matrix_test` | 5 | 9 | 26.7s |  |
| 23 | `path_format_test` | 28 | 28 | 18.8s |  |
| 24 | `place_object_test` | 14 | 14 | 19.3s |  |
| 25 | `place_object_test2` | 22 | 23 | 19.3s |  |
| 26 | `register_class/registerClassTest2` | 8 | 28 | 11.9s |  |
| 27 | `replace_buttons1test` | 3 | 3 | 11.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
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
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 4 | `action_order/action_execution_order_test5` | 44.1% | 26/59 | 59 | 35 |  |
| 5 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 6 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 7 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 8 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 9 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 10 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 11 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 12 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 13 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
