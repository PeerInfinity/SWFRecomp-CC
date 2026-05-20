# Ruffle Test Results (Filtered)

**Date**: 2026-05-20 03:59 UTC

**Git SHA**: `3fe53f7a73`

**Run Duration**: 26m 37s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **65** (60.2%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **91** (84.3%) |
| Failing | 17 |
| Total expected lines | 5179 |
| Matching lines | 3988 (77.0%) |
| Mismatched lines | 1191 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 17 | 100.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.6s |  |
| 2 | `DefineEditTextTest` | 153 | 18.5s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 18.2s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 17.9s |  |
| 5 | `DepthLimitsTest` | 20 | 18.4s |  |
| 6 | `PlaceObject2Test` | 9 | 17.7s |  |
| 7 | `ResolveEventsTest` | 15 | 19.4s |  |
| 8 | `RollOverOutTest` | 5 | 18.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 17.8s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 18.0s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 17.5s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 18.1s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 18.6s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 16.8s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 16.7s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 20 | `attachExtImported` | 2 | 18.9s |  |
| 21 | `attachImported` | 2 | 0.4s |  |
| 22 | `attachMovieLoopingTest` | 41 | 18.5s |  |
| 23 | `attachMovieTest` | 12 | 18.6s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 14.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 14.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 18.6s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.3s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 14.2s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 14.2s |  |
| 34 | `event_handler_scope_test` | 16 | 0.3s |  |
| 35 | `frame_label_test` | 17 | 17.9s |  |
| 36 | `getTimer_test` | 8 | 17.8s |  |
| 37 | `get_frame_number_test` | 31 | 17.8s |  |
| 38 | `goto_frame_test` | 15 | 17.9s |  |
| 39 | `instanceNameTest` | 5 | 0.3s |  |
| 40 | `loading/LoadVarsTest` | 36 | 18.4s |  |
| 41 | `loop/loop_test` | 21 | 18.3s |  |
| 42 | `loop/loop_test4` | 22 | 17.5s |  |
| 43 | `loop/loop_test5` | 24 | 18.2s |  |
| 44 | `loop/loop_test8` | 38 | 0.5s |  |
| 45 | `loop/loop_test9` | 15 | 17.4s |  |
| 46 | `loop/simple_loop_test` | 0 | 17.5s |  |
| 47 | `masks_test2` | 10 | 18.1s |  |
| 48 | `morph_test1` | 0 | 18.3s |  |
| 49 | `move_object_test` | 11 | 18.6s |  |
| 50 | `multi_doactions_and_goto_frame_test` | 6 | 18.2s |  |
| 51 | `new_child_in_unload_test` | 11 | 18.3s |  |
| 52 | `place_and_remove_object_insane_test` | 22 | 18.5s |  |
| 53 | `place_and_remove_object_test` | 13 | 18.3s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 18.4s |  |
| 55 | `register_class/registerClassTest` | 51 | 18.5s |  |
| 56 | `replace_shapes1test` | 23 | 0.3s |  |
| 57 | `replace_sprites1test` | 21 | 18.4s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 18.1s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 18.0s |  |
| 60 | `runtime_vm_stack_test` | 9 | 17.5s |  |
| 61 | `shape_test` | 21 | 17.7s |  |
| 62 | `static_vs_dynamic1` | 17 | 17.5s |  |
| 63 | `static_vs_dynamic2` | 18 | 14.2s |  |
| 64 | `timeline_var_test` | 11 | 14.2s |  |
| 65 | `unload_movieclip_test1` | 6 | 14.1s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 18.8s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 18.3s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 18.6s |  |
| 4 | `DefineTextTest` | 4 | 4 | 17.7s |  |
| 5 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 6 | `KeyEventOrder` | 20 | 23 | 17.8s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 18.9s |  |
| 8 | `callFunction_test` | 6 | 11 | 14.1s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 14.4s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 18.4s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.4s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 14.2s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 17.7s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 18.1s |  |
| 15 | `key_event_test` | 5 | 6 | 17.9s |  |
| 16 | `loading/LoadBitmapTest` | 3 | 3 | 18.6s |  |
| 17 | `loading/loadMovieTest` | 9 | 9 | 0.6s |  |
| 18 | `loop/loop_test10` | 23 | 23 | 17.7s |  |
| 19 | `loop/loop_test6` | 1 | 12 | 18.2s |  |
| 20 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 21 | `matrix_test` | 5 | 9 | 22.5s |  |
| 22 | `path_format_test` | 28 | 28 | 18.8s |  |
| 23 | `place_object_test` | 14 | 14 | 18.3s |  |
| 24 | `place_object_test2` | 22 | 23 | 18.0s |  |
| 25 | `register_class/registerClassTest2` | 8 | 28 | 18.2s |  |
| 26 | `replace_buttons1test` | 3 | 3 | 18.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 4 | `loop/loop_test3` | 52.9% | 9 | 17 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**17 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 4 | `loop/loop_test3` | 52.9% | 9/17 | 17 | 16 |  |
| 5 | `action_order/action_execution_order_test5` | 44.1% | 26/59 | 59 | 35 |  |
| 6 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 7 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 8 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 9 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 10 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 11 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 12 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 13 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 14 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 15 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 16 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 17 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
