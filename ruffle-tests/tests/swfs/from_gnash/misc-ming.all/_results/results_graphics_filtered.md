# Ruffle Test Results (Filtered)

**Date**: 2026-06-29 20:58 UTC

**Git SHA**: `ddf6a589f7`

**Run Duration**: 28m 37s

**Filtered**: 2 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 109 |
| Passing | **65** (59.6%) |
| Ruffle-matched | 28 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **93** (85.3%) |
| Failing | 16 |
| Total expected lines | 5179 |
| Matching lines | 4007 (77.4%) |
| Mismatched lines | 1172 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 15 | 93.8% |
| Timeout | 1 | 6.2% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 23.7s |  |
| 2 | `DefineEditTextTest` | 153 | 12.3s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.8s |  |
| 5 | `DepthLimitsTest` | 20 | 24.6s |  |
| 6 | `PlaceObject2Test` | 9 | 21.0s |  |
| 7 | `ResolveEventsTest` | 15 | 22.9s |  |
| 8 | `RollOverOutTest` | 5 | 3.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.8s |  |
| 10 | `Version4Loader` | 11 | 2.6s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.9s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 3.1s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 2.9s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 2.5s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 22.2s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.2s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 2.3s |  |
| 19 | `attachExtImported` | 2 | 22.9s |  |
| 20 | `attachImported` | 2 | 2.8s |  |
| 21 | `attachMovieLoopingTest` | 41 | 22.3s |  |
| 22 | `attachMovieTest` | 12 | 23.0s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 2.8s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 21.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.6s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 22.4s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 3.7s |  |
| 33 | `event_handler_scope_test` | 16 | 3.0s |  |
| 34 | `frame_label_test` | 17 | 3.8s |  |
| 35 | `getTimer_test` | 8 | 2.6s |  |
| 36 | `get_frame_number_test` | 31 | 24.6s |  |
| 37 | `goto_frame_test` | 15 | 22.4s |  |
| 38 | `instanceNameTest` | 5 | 2.5s |  |
| 39 | `loading/LoadVarsTest` | 36 | 25.5s |  |
| 40 | `loop/loop_test` | 21 | 22.8s |  |
| 41 | `loop/loop_test2` | 15 | 2.9s |  |
| 42 | `loop/loop_test3` | 16 | 2.9s |  |
| 43 | `loop/loop_test4` | 22 | 22.8s |  |
| 44 | `loop/loop_test5` | 24 | 3.8s |  |
| 45 | `loop/loop_test8` | 38 | 24.5s |  |
| 46 | `loop/loop_test9` | 15 | 21.8s |  |
| 47 | `loop/simple_loop_test` | 0 | 25.9s |  |
| 48 | `masks_test2` | 10 | 22.6s |  |
| 49 | `morph_test1` | 0 | 27.0s |  |
| 50 | `move_object_test` | 11 | 21.6s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 21.6s |  |
| 52 | `new_child_in_unload_test` | 11 | 3.0s |  |
| 53 | `place_and_remove_object_test` | 13 | 21.8s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 3.3s |  |
| 55 | `register_class/registerClassTest` | 51 | 23.9s |  |
| 56 | `replace_shapes1test` | 23 | 3.5s |  |
| 57 | `replace_sprites1test` | 21 | 2.9s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 18.1s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 18.2s |  |
| 60 | `runtime_vm_stack_test` | 9 | 0.9s |  |
| 61 | `shape_test` | 21 | 1.6s |  |
| 62 | `static_vs_dynamic1` | 17 | 0.9s |  |
| 63 | `static_vs_dynamic2` | 18 | 22.7s |  |
| 64 | `timeline_var_test` | 11 | 22.3s |  |
| 65 | `unload_movieclip_test1` | 6 | 2.6s |  |

## Ruffle-Matched Tests

**28 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 26.2s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 27.2s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.8s |  |
| 4 | `DefineTextTest` | 4 | 4 | 3.0s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 28.0s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.2s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 11.8s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 4.0s |  |
| 10 | `callFunction_test` | 6 | 11 | 3.5s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 28.4s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 22.1s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.7s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.5s |  |
| 15 | `init_action/InitActionTest` | 6 | 17 | 22.0s |  |
| 16 | `init_action/InitActionTest2` | 24 | 30 | 23.5s |  |
| 17 | `key_event_test` | 5 | 6 | 25.5s |  |
| 18 | `loading/LoadBitmapTest` | 3 | 3 | 23.3s |  |
| 19 | `loading/loadMovieTest` | 9 | 9 | 5.4s |  |
| 20 | `loop/loop_test10` | 23 | 23 | 23.7s |  |
| 21 | `loop/loop_test6` | 1 | 12 | 3.7s |  |
| 22 | `loop/loop_test7` | 1 | 8 | 3.2s |  |
| 23 | `matrix_test` | 5 | 9 | 110.5s |  |
| 24 | `path_format_test` | 28 | 28 | 5.5s |  |
| 25 | `place_object_test` | 14 | 14 | 3.4s |  |
| 26 | `place_object_test2` | 22 | 23 | 22.1s |  |
| 27 | `register_class/registerClassTest2` | 8 | 28 | 24.2s |  |
| 28 | `replace_buttons1test` | 3 | 3 | 3.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17 | 22 | 5 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `gotoFrame2Test` | runtime timeout (>10s) | 57.5s |  |

## All Output Mismatches

**15 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `place_and_remove_object_insane_test` | 77.3% | 17/22 | 22 | 22 |  |
| 4 | `action_order/action_execution_order_test5` | 47.3% | 26/55 | 55 | 35 |  |
| 5 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 6 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 7 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 8 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 9 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 10 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 11 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 7.6% | 9/118 | 118 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 5.1% | 4/78 | 78 | 62 |  |
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 15 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
