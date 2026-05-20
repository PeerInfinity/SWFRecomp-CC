# Ruffle Test Results (Filtered)

**Date**: 2026-05-20 03:45 UTC

**Git SHA**: `13fe9441a4`

**Run Duration**: 27m 21s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **65** (60.2%) |
| Ruffle-matched | 25 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **90** (83.3%) |
| Failing | 18 |
| Total expected lines | 5179 |
| Matching lines | 3985 (76.9%) |
| Mismatched lines | 1194 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 18 | 100.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.1s |  |
| 2 | `DefineEditTextTest` | 153 | 19.2s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 18.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 18.9s |  |
| 5 | `DepthLimitsTest` | 20 | 18.1s |  |
| 6 | `PlaceObject2Test` | 9 | 19.1s |  |
| 7 | `ResolveEventsTest` | 15 | 18.5s |  |
| 8 | `RollOverOutTest` | 5 | 18.6s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.1s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 19.9s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.4s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 18.2s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 18.4s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 18.0s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 18.0s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 20 | `attachExtImported` | 2 | 17.9s |  |
| 21 | `attachImported` | 2 | 0.3s |  |
| 22 | `attachMovieLoopingTest` | 41 | 18.0s |  |
| 23 | `attachMovieTest` | 12 | 17.5s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 18.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.2s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.3s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 18.6s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 18.0s |  |
| 34 | `event_handler_scope_test` | 16 | 0.3s |  |
| 35 | `frame_label_test` | 17 | 17.9s |  |
| 36 | `getTimer_test` | 8 | 17.8s |  |
| 37 | `get_frame_number_test` | 31 | 18.0s |  |
| 38 | `goto_frame_test` | 15 | 17.8s |  |
| 39 | `instanceNameTest` | 5 | 0.3s |  |
| 40 | `loading/LoadVarsTest` | 36 | 18.8s |  |
| 41 | `loop/loop_test` | 21 | 18.0s |  |
| 42 | `loop/loop_test4` | 22 | 17.9s |  |
| 43 | `loop/loop_test5` | 24 | 18.3s |  |
| 44 | `loop/loop_test8` | 38 | 0.4s |  |
| 45 | `loop/loop_test9` | 15 | 17.8s |  |
| 46 | `loop/simple_loop_test` | 0 | 18.0s |  |
| 47 | `masks_test2` | 10 | 18.4s |  |
| 48 | `morph_test1` | 0 | 20.9s |  |
| 49 | `move_object_test` | 11 | 17.8s |  |
| 50 | `multi_doactions_and_goto_frame_test` | 6 | 17.9s |  |
| 51 | `new_child_in_unload_test` | 11 | 17.6s |  |
| 52 | `place_and_remove_object_insane_test` | 22 | 18.3s |  |
| 53 | `place_and_remove_object_test` | 13 | 18.3s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 18.1s |  |
| 55 | `register_class/registerClassTest` | 51 | 18.3s |  |
| 56 | `replace_shapes1test` | 23 | 0.3s |  |
| 57 | `replace_sprites1test` | 21 | 18.0s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 18.6s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 18.2s |  |
| 60 | `runtime_vm_stack_test` | 9 | 14.2s |  |
| 61 | `shape_test` | 21 | 14.3s |  |
| 62 | `static_vs_dynamic1` | 17 | 14.0s |  |
| 63 | `static_vs_dynamic2` | 18 | 17.9s |  |
| 64 | `timeline_var_test` | 11 | 17.9s |  |
| 65 | `unload_movieclip_test1` | 6 | 18.2s |  |

## Ruffle-Matched Tests

**25 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 18.3s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 18.2s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 17.9s |  |
| 4 | `DefineTextTest` | 4 | 4 | 18.3s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 18.6s |  |
| 6 | `action_order/action_execution_order_test4` | 7 | 26 | 18.8s |  |
| 7 | `callFunction_test` | 6 | 11 | 18.3s |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 19.0s |  |
| 9 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.7s |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 17.9s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 18.2s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 18.3s |  |
| 14 | `key_event_test` | 5 | 6 | 18.2s |  |
| 15 | `loading/LoadBitmapTest` | 3 | 3 | 19.0s |  |
| 16 | `loading/loadMovieTest` | 9 | 9 | 0.7s |  |
| 17 | `loop/loop_test10` | 23 | 23 | 17.9s |  |
| 18 | `loop/loop_test6` | 1 | 12 | 18.3s |  |
| 19 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 20 | `matrix_test` | 5 | 9 | 22.5s |  |
| 21 | `path_format_test` | 28 | 28 | 18.4s |  |
| 22 | `place_object_test` | 14 | 14 | 18.6s |  |
| 23 | `place_object_test2` | 22 | 23 | 18.4s |  |
| 24 | `register_class/registerClassTest2` | 8 | 28 | 18.2s |  |
| 25 | `replace_buttons1test` | 3 | 3 | 18.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `DragDropTest` | 66.7% | 30 | 45 | 15 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 5 | `loop/loop_test3` | 52.9% | 9 | 17 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**18 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `DragDropTest` | 66.7% | 30/45 | 45 | 44 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 5 | `loop/loop_test3` | 52.9% | 9/17 | 17 | 16 |  |
| 6 | `action_order/action_execution_order_test5` | 44.1% | 26/59 | 59 | 35 |  |
| 7 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 8 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 9 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 10 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 11 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 12 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 13 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 14 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 15 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 16 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 17 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 18 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
