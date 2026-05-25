# Ruffle Test Results (Filtered)

**Date**: 2026-05-25 02:45 UTC

**Git SHA**: `fd99759a05`

**Run Duration**: 35m 52s

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
| 1 | `BeginBitmapFill` | 1 | 24.5s |  |
| 2 | `DefineEditTextTest` | 153 | 29.3s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.2s |  |
| 5 | `DepthLimitsTest` | 20 | 22.0s |  |
| 6 | `PlaceObject2Test` | 9 | 21.1s |  |
| 7 | `ResolveEventsTest` | 15 | 21.5s |  |
| 8 | `RollOverOutTest` | 5 | 21.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.7s |  |
| 10 | `Version4Loader` | 11 | 2.5s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.9s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.9s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 16.8s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 20.8s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 21.1s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 2.4s |  |
| 19 | `attachExtImported` | 2 | 21.4s |  |
| 20 | `attachImported` | 2 | 2.5s |  |
| 21 | `attachMovieLoopingTest` | 41 | 20.5s |  |
| 22 | `attachMovieTest` | 12 | 21.0s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 19.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 22.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.7s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 22.1s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 22.5s |  |
| 33 | `event_handler_scope_test` | 16 | 2.9s |  |
| 34 | `frame_label_test` | 17 | 21.9s |  |
| 35 | `getTimer_test` | 8 | 20.5s |  |
| 36 | `get_frame_number_test` | 31 | 23.0s |  |
| 37 | `goto_frame_test` | 15 | 21.0s |  |
| 38 | `instanceNameTest` | 5 | 2.5s |  |
| 39 | `loading/LoadVarsTest` | 36 | 23.1s |  |
| 40 | `loop/loop_test` | 21 | 20.2s |  |
| 41 | `loop/loop_test2` | 15 | 20.6s |  |
| 42 | `loop/loop_test3` | 16 | 2.5s |  |
| 43 | `loop/loop_test4` | 22 | 21.6s |  |
| 44 | `loop/loop_test5` | 24 | 22.2s |  |
| 45 | `loop/loop_test8` | 38 | 4.9s |  |
| 46 | `loop/loop_test9` | 15 | 20.9s |  |
| 47 | `loop/simple_loop_test` | 0 | 25.9s |  |
| 48 | `masks_test2` | 10 | 20.7s |  |
| 49 | `morph_test1` | 0 | 24.3s |  |
| 50 | `move_object_test` | 11 | 20.8s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 21.1s |  |
| 52 | `new_child_in_unload_test` | 11 | 20.9s |  |
| 53 | `place_and_remove_object_test` | 13 | 25.4s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 20.8s |  |
| 55 | `register_class/registerClassTest` | 51 | 23.6s |  |
| 56 | `replace_shapes1test` | 23 | 3.2s |  |
| 57 | `replace_sprites1test` | 21 | 20.9s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 20.2s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 20.6s |  |
| 60 | `runtime_vm_stack_test` | 9 | 20.6s |  |
| 61 | `shape_test` | 21 | 23.9s |  |
| 62 | `static_vs_dynamic1` | 17 | 20.8s |  |
| 63 | `static_vs_dynamic2` | 18 | 21.7s |  |
| 64 | `timeline_var_test` | 11 | 21.3s |  |
| 65 | `unload_movieclip_test1` | 6 | 20.9s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 25.6s |  |
| 2 | `DefineTextTest` | 4 | 4 | 20.9s |  |
| 3 | `DragDropTest` | 12 | 12 | 3.6s |  |
| 4 | `EmbeddedFontTest` | 27 | 27 | 25.1s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 21.5s |  |
| 6 | `TextSnapshotTest` | 81 | 90 | 29.3s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 18.4s |  |
| 8 | `callFunction_test` | 6 | 11 | 20.3s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 26.9s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.8s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.6s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 22.7s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 21.5s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 23.0s |  |
| 15 | `key_event_test` | 5 | 6 | 23.7s |  |
| 16 | `loading/LoadBitmapTest` | 3 | 3 | 21.5s |  |
| 17 | `loading/loadMovieTest` | 9 | 9 | 4.6s |  |
| 18 | `loop/loop_test10` | 23 | 23 | 21.9s |  |
| 19 | `loop/loop_test6` | 1 | 12 | 22.0s |  |
| 20 | `loop/loop_test7` | 1 | 8 | 3.0s |  |
| 21 | `matrix_test` | 5 | 9 | 103.2s |  |
| 22 | `path_format_test` | 28 | 28 | 24.4s |  |
| 23 | `place_object_test` | 14 | 14 | 27.6s |  |
| 24 | `place_object_test2` | 22 | 23 | 25.4s |  |
| 25 | `register_class/registerClassTest2` | 8 | 28 | 22.7s |  |
| 26 | `replace_buttons1test` | 3 | 3 | 21.5s |  |

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
| 1 | `ButtonEventsTest` | 28.9s |  |
| 2 | `ButtonPropertiesTest` | 23.5s |  |

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
| 10 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 15 | 96 |  |
| 11 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 14 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 15 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
