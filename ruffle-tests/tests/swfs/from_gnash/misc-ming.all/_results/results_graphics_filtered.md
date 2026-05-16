# Ruffle Test Results (Filtered)

**Date**: 2026-05-16 21:06 UTC

**Git SHA**: `be9aafd78e`

**Run Duration**: 2m 10s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **63** (58.3%) |
| Ruffle-matched | 22 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **85** (78.7%) |
| Failing | 23 |
| Total expected lines | 5179 |
| Matching lines | 3319 (64.1%) |
| Mismatched lines | 1860 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 21 | 91.3% |
| Segfault | 2 | 8.7% |

## Passing Tests

**63 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 1.7s |  |
| 2 | `DefineEditTextTest` | 153 | 1.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 1.4s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 1.2s |  |
| 5 | `DepthLimitsTest` | 20 | 1.0s |  |
| 6 | `PlaceObject2Test` | 9 | 0.8s |  |
| 7 | `ResolveEventsTest` | 15 | 0.8s |  |
| 8 | `RollOverOutTest` | 5 | 0.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.7s |  |
| 10 | `Version4Loader` | 11 | 0.7s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 0.8s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 1.0s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 0.9s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 0.9s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 0.7s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 1.0s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 1.0s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.9s |  |
| 20 | `attachExtImported` | 2 | 1.0s |  |
| 21 | `attachImported` | 2 | 0.9s |  |
| 22 | `attachMovieLoopingTest` | 41 | 0.9s |  |
| 23 | `attachMovieTest` | 12 | 0.9s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 0.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.9s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.9s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 1.0s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 0.9s |  |
| 34 | `event_handler_scope_test` | 16 | 0.9s |  |
| 35 | `frame_label_test` | 17 | 1.0s |  |
| 36 | `getTimer_test` | 8 | 0.8s |  |
| 37 | `get_frame_number_test` | 31 | 1.4s |  |
| 38 | `goto_frame_test` | 15 | 0.9s |  |
| 39 | `instanceNameTest` | 5 | 0.8s |  |
| 40 | `loading/LoadVarsTest` | 36 | 1.1s |  |
| 41 | `loop/loop_test4` | 22 | 0.8s |  |
| 42 | `loop/loop_test5` | 24 | 0.9s |  |
| 43 | `loop/loop_test8` | 38 | 1.0s |  |
| 44 | `loop/loop_test9` | 15 | 1.0s |  |
| 45 | `loop/simple_loop_test` | 0 | 4.9s |  |
| 46 | `masks_test2` | 10 | 0.7s |  |
| 47 | `morph_test1` | 0 | 4.0s |  |
| 48 | `move_object_test` | 11 | 0.9s |  |
| 49 | `multi_doactions_and_goto_frame_test` | 6 | 0.9s |  |
| 50 | `new_child_in_unload_test` | 11 | 0.9s |  |
| 51 | `place_and_remove_object_test` | 13 | 1.1s |  |
| 52 | `register_class/RegisterClassTest3` | 12 | 0.8s |  |
| 53 | `register_class/registerClassTest` | 51 | 0.9s |  |
| 54 | `replace_shapes1test` | 23 | 0.9s |  |
| 55 | `replace_sprites1test` | 21 | 1.1s |  |
| 56 | `reverse_execute_PlaceObject2_test1` | 8 | 0.9s |  |
| 57 | `reverse_execute_PlaceObject2_test2` | 10 | 0.9s |  |
| 58 | `runtime_vm_stack_test` | 9 | 0.7s |  |
| 59 | `shape_test` | 21 | 1.3s |  |
| 60 | `static_vs_dynamic1` | 17 | 0.7s |  |
| 61 | `static_vs_dynamic2` | 18 | 1.1s |  |
| 62 | `timeline_var_test` | 11 | 1.0s |  |
| 63 | `unload_movieclip_test1` | 6 | 0.9s |  |

## Ruffle-Matched Tests

**22 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 1.1s |  |
| 2 | `DefineTextTest` | 4 | 4 | 0.9s |  |
| 3 | `DragDropTest` | 12 | 12 | 0.9s |  |
| 4 | `KeyEventOrder` | 20 | 23 | 1.0s |  |
| 5 | `action_order/action_execution_order_test4` | 7 | 26 | 0.8s |  |
| 6 | `callFunction_test` | 5 | 11 | 0.9s |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 1.5s |  |
| 8 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.9s |  |
| 9 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.9s |  |
| 10 | `duplicate_movie_clip_test` | 4 | 4 | 1.0s |  |
| 11 | `init_action/InitActionTest` | 6 | 17 | 0.8s |  |
| 12 | `init_action/InitActionTest2` | 24 | 30 | 1.4s |  |
| 13 | `key_event_test` | 5 | 6 | 2.0s |  |
| 14 | `loading/loadMovieTest` | 9 | 9 | 1.4s |  |
| 15 | `loop/loop_test6` | 1 | 12 | 0.9s |  |
| 16 | `loop/loop_test7` | 1 | 8 | 0.9s |  |
| 17 | `matrix_test` | 5 | 9 | 4.5s |  |
| 18 | `path_format_test` | 28 | 28 | 0.8s |  |
| 19 | `place_object_test` | 14 | 14 | 1.6s |  |
| 20 | `place_object_test2` | 22 | 23 | 1.0s |  |
| 21 | `register_class/registerClassTest2` | 8 | 28 | 0.9s |  |
| 22 | `replace_buttons1test` | 3 | 3 | 0.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `loading/LoadBitmapTest` | 76.5% | 13 | 17 | 4 |  |
| 4 | `place_and_remove_object_insane_test` | 72.7% | 16 | 22 | 6 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 6 | `loop/loop_test3` | 52.9% | 9 | 17 | 8 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 3.4s |  |
| 2 | `ButtonPropertiesTest` | 3.5s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**21 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `loading/LoadBitmapTest` | 76.5% | 13/17 | 17 | 17 |  |
| 4 | `place_and_remove_object_insane_test` | 72.7% | 16/22 | 22 | 22 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 6 | `loop/loop_test3` | 52.9% | 9/17 | 17 | 16 |  |
| 7 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 8 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 9 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 10 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 11 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 12 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 13 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 14 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 15 | `loop/loop_test` | 14.8% | 4/27 | 27 | 21 |  |
| 16 | `action_order/ActionOrderTest5` | 11.9% | 7/59 | 59 | 51 |  |
| 17 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 18 | `action_order/ActionOrderTest4` | 6.2% | 6/96 | 96 | 64 |  |
| 19 | `action_order/ActionOrderTest3` | 5.3% | 4/75 | 75 | 62 |  |
| 20 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 21 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
