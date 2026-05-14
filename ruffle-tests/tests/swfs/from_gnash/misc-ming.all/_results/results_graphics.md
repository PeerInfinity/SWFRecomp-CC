# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-14 21:43 UTC

**Git SHA**: `17a60dbb68`

**Run Duration**: 2m 51s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **65** (59.1%) |
| Ruffle-matched | 23 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **88** (80.0%) |
| Failing | 22 |
| Total expected lines | 5239 |
| Matching lines | 3383 (64.6%) |
| Mismatched lines | 1856 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 20 | 90.9% |
| Runtime Segfault | 2 | 9.1% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 3.4s |  |
| 2 | `DefineEditTextTest` | 153 | 1.7s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 1.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 1.5s |  |
| 5 | `DepthLimitsTest` | 20 | 1.3s |  |
| 6 | `PlaceObject2Test` | 9 | 1.2s |  |
| 7 | `ResolveEventsTest` | 15 | 1.1s |  |
| 8 | `RollOverOutTest` | 5 | 1.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 10 | `Version4Loader` | 11 | 1.4s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 1.2s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 1.2s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 1.3s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 1.0s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 1.3s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 1.2s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.0s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 1.1s |  |
| 19 | `attachExtImported` | 2 | 2.5s |  |
| 20 | `attachImported` | 2 | 1.8s |  |
| 21 | `attachMovieLoopingTest` | 41 | 1.2s |  |
| 22 | `attachMovieTest` | 12 | 1.2s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 0.9s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 1.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.0s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.2s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.1s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 1.5s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 1.3s |  |
| 33 | `event_handler_scope_test` | 16 | 1.3s |  |
| 34 | `frame_label_test` | 17 | 1.4s |  |
| 35 | `getTimer_test` | 8 | 1.2s |  |
| 36 | `get_frame_number_test` | 31 | 1.7s |  |
| 37 | `goto_frame_test` | 15 | 1.3s |  |
| 38 | `instanceNameTest` | 5 | 1.0s |  |
| 39 | `loading/LoadVarsTest` | 36 | 1.3s |  |
| 40 | `loop/loop_test` | 21 | 1.2s |  |
| 41 | `loop/loop_test2` | 15 | 1.2s |  |
| 42 | `loop/loop_test3` | 16 | 1.2s |  |
| 43 | `loop/loop_test4` | 22 | 1.3s |  |
| 44 | `loop/loop_test5` | 24 | 1.3s |  |
| 45 | `loop/loop_test8` | 38 | 1.3s |  |
| 46 | `loop/loop_test9` | 15 | 1.3s |  |
| 47 | `loop/simple_loop_test` | 0 | 6.2s |  |
| 48 | `masks_test2` | 10 | 1.2s |  |
| 49 | `morph_test1` | 0 | 4.6s |  |
| 50 | `move_object_test` | 11 | 1.2s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 1.0s |  |
| 52 | `new_child_in_unload_test` | 11 | 1.1s |  |
| 53 | `place_and_remove_object_test` | 13 | 1.3s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 1.1s |  |
| 55 | `register_class/registerClassTest` | 51 | 1.2s |  |
| 56 | `replace_shapes1test` | 23 | 1.1s |  |
| 57 | `replace_sprites1test` | 21 | 1.4s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 1.2s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 1.2s |  |
| 60 | `runtime_vm_stack_test` | 9 | 1.3s |  |
| 61 | `shape_test` | 21 | 3.1s |  |
| 62 | `static_vs_dynamic1` | 17 | 1.1s |  |
| 63 | `static_vs_dynamic2` | 18 | 1.3s |  |
| 64 | `timeline_var_test` | 11 | 1.2s |  |
| 65 | `unload_movieclip_test1` | 6 | 1.1s |  |

## Ruffle-Matched Tests

**23 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 1.6s |  |
| 2 | `DefineTextTest` | 4 | 4 | 1.0s |  |
| 3 | `DragDropTest` | 12 | 12 | 1.0s |  |
| 4 | `KeyEventOrder` | 20 | 23 | 1.4s |  |
| 5 | `action_order/action_execution_order_test4` | 7 | 26 | 1.2s |  |
| 6 | `callFunction_test` | 5 | 11 | 1.0s |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 1.6s |  |
| 8 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 1.1s |  |
| 9 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.0s |  |
| 10 | `duplicate_movie_clip_test` | 4 | 4 | 1.4s |  |
| 11 | `init_action/InitActionTest` | 6 | 17 | 1.1s |  |
| 12 | `init_action/InitActionTest2` | 24 | 30 | 1.5s |  |
| 13 | `key_event_test` | 5 | 6 | 2.3s |  |
| 14 | `loading/loadMovieTest` | 9 | 9 | 2.5s |  |
| 15 | `loop/loop_test10` | 23 | 23 | 1.5s |  |
| 16 | `loop/loop_test6` | 1 | 12 | 1.2s |  |
| 17 | `loop/loop_test7` | 1 | 8 | 1.1s |  |
| 18 | `matrix_test` | 5 | 9 | 6.4s |  |
| 19 | `path_format_test` | 28 | 28 | 1.1s |  |
| 20 | `place_object_test` | 14 | 14 | 3.2s |  |
| 21 | `place_object_test2` | 20 | 23 | 1.2s |  |
| 22 | `register_class/registerClassTest2` | 8 | 28 | 1.2s |  |
| 23 | `replace_buttons1test` | 3 | 3 | 1.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**7 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16 | 19 | 3 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13 | 17 | 4 |  |
| 5 | `place_and_remove_object_insane_test` | 72.7% | 16 | 22 | 6 |  |
| 6 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 7 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 3.4s |  |
| 2 | `ButtonPropertiesTest` | 3.1s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**20 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16/19 | 19 | 19 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13/17 | 17 | 17 |  |
| 5 | `place_and_remove_object_insane_test` | 72.7% | 16/22 | 22 | 22 |  |
| 6 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 7 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 8 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 9 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 10 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 11 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 12 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 13 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 14 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 15 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 16 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 17 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 18 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 19 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 20 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
