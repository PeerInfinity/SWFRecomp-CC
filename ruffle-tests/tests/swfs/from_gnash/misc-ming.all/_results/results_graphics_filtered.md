# Ruffle Test Results (Filtered)

**Date**: 2026-05-25 20:45 UTC

**Git SHA**: `e6a7f49230`

**Run Duration**: 29m 9s

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
| Matching lines | 3365 (65.0%) |
| Mismatched lines | 1814 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 15 | 88.2% |
| Segfault | 2 | 11.8% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.2s |  |
| 2 | `DefineEditTextTest` | 153 | 13.5s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 13.2s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 12.9s |  |
| 5 | `DepthLimitsTest` | 20 | 19.2s |  |
| 6 | `PlaceObject2Test` | 9 | 18.8s |  |
| 7 | `ResolveEventsTest` | 15 | 18.9s |  |
| 8 | `RollOverOutTest` | 5 | 18.6s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.0s |  |
| 10 | `Version4Loader` | 11 | 0.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.3s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 19.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 19.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.5s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 21.1s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 22.0s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 2.7s |  |
| 19 | `attachExtImported` | 2 | 19.9s |  |
| 20 | `attachImported` | 2 | 1.0s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.3s |  |
| 22 | `attachMovieTest` | 12 | 19.5s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 19.1s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.1s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.5s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.5s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 19.3s |  |
| 33 | `event_handler_scope_test` | 16 | 1.1s |  |
| 34 | `frame_label_test` | 17 | 19.2s |  |
| 35 | `getTimer_test` | 8 | 18.8s |  |
| 36 | `get_frame_number_test` | 31 | 19.4s |  |
| 37 | `goto_frame_test` | 15 | 18.9s |  |
| 38 | `instanceNameTest` | 5 | 0.8s |  |
| 39 | `loading/LoadVarsTest` | 36 | 20.1s |  |
| 40 | `loop/loop_test` | 21 | 19.7s |  |
| 41 | `loop/loop_test2` | 15 | 19.2s |  |
| 42 | `loop/loop_test3` | 16 | 1.0s |  |
| 43 | `loop/loop_test4` | 22 | 19.3s |  |
| 44 | `loop/loop_test5` | 24 | 22.5s |  |
| 45 | `loop/loop_test8` | 38 | 1.4s |  |
| 46 | `loop/loop_test9` | 15 | 19.4s |  |
| 47 | `loop/simple_loop_test` | 0 | 24.8s |  |
| 48 | `masks_test2` | 10 | 19.5s |  |
| 49 | `morph_test1` | 0 | 23.6s |  |
| 50 | `move_object_test` | 11 | 17.6s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 17.9s |  |
| 52 | `new_child_in_unload_test` | 11 | 18.0s |  |
| 53 | `place_and_remove_object_test` | 13 | 19.7s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 20.3s |  |
| 55 | `register_class/registerClassTest` | 51 | 20.4s |  |
| 56 | `replace_shapes1test` | 23 | 1.0s |  |
| 57 | `replace_sprites1test` | 21 | 19.6s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 19.6s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 19.5s |  |
| 60 | `runtime_vm_stack_test` | 9 | 18.7s |  |
| 61 | `shape_test` | 21 | 21.0s |  |
| 62 | `static_vs_dynamic1` | 17 | 18.8s |  |
| 63 | `static_vs_dynamic2` | 18 | 19.6s |  |
| 64 | `timeline_var_test` | 11 | 20.0s |  |
| 65 | `unload_movieclip_test1` | 6 | 19.5s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 19.3s |  |
| 2 | `DefineTextTest` | 4 | 4 | 12.5s |  |
| 3 | `DragDropTest` | 12 | 12 | 0.8s |  |
| 4 | `EmbeddedFontTest` | 27 | 27 | 19.4s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 19.1s |  |
| 6 | `TextSnapshotTest` | 81 | 90 | 19.1s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 19.6s |  |
| 8 | `callFunction_test` | 6 | 11 | 19.0s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 19.5s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.1s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.2s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 19.5s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 19.3s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 19.8s |  |
| 15 | `key_event_test` | 5 | 6 | 20.3s |  |
| 16 | `loading/LoadBitmapTest` | 3 | 3 | 19.9s |  |
| 17 | `loading/loadMovieTest` | 9 | 9 | 1.5s |  |
| 18 | `loop/loop_test10` | 23 | 23 | 19.4s |  |
| 19 | `loop/loop_test6` | 1 | 12 | 22.2s |  |
| 20 | `loop/loop_test7` | 1 | 8 | 1.2s |  |
| 21 | `matrix_test` | 5 | 9 | 24.9s |  |
| 22 | `path_format_test` | 28 | 28 | 11.6s |  |
| 23 | `place_object_test` | 14 | 14 | 21.6s |  |
| 24 | `place_object_test2` | 22 | 23 | 19.5s |  |
| 25 | `register_class/registerClassTest2` | 8 | 28 | 19.5s |  |
| 26 | `replace_buttons1test` | 3 | 3 | 19.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `place_and_remove_object_insane_test` | 72.7% | 16 | 22 | 6 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 21.8s |  |
| 2 | `ButtonPropertiesTest` | 21.6s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**15 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `place_and_remove_object_insane_test` | 72.7% | 16/22 | 22 | 22 |  |
| 4 | `action_order/action_execution_order_test5` | 47.3% | 26/55 | 55 | 35 |  |
| 5 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 6 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 7 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 8 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 9 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 10 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 11 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 15 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
