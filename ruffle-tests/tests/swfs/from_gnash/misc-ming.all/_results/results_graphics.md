# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-15 03:20 UTC

**Git SHA**: `45164a5b08`

**Run Duration**: 34m 60s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **62** (56.4%) |
| Ruffle-matched | 22 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **84** (76.4%) |
| Failing | 26 |
| Total expected lines | 5239 |
| Matching lines | 3344 (63.8%) |
| Mismatched lines | 1895 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 24 | 92.3% |
| Runtime Segfault | 2 | 7.7% |

## Passing Tests

**62 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 22.4s |  |
| 2 | `DefineEditTextTest` | 153 | 30.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 28.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.7s |  |
| 5 | `DepthLimitsTest` | 20 | 22.1s |  |
| 6 | `PlaceObject2Test` | 9 | 21.1s |  |
| 7 | `ResolveEventsTest` | 15 | 20.9s |  |
| 8 | `RollOverOutTest` | 5 | 20.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.3s |  |
| 10 | `Version4Loader` | 11 | 2.0s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.3s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.7s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 21.6s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.8s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 20.2s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 20.4s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 2.1s |  |
| 19 | `attachExtImported` | 2 | 21.8s |  |
| 20 | `attachImported` | 2 | 2.3s |  |
| 21 | `attachMovieLoopingTest` | 41 | 20.9s |  |
| 22 | `attachMovieTest` | 12 | 21.2s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 19.5s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.0s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 19.7s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.5s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.0s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 20.9s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 21.0s |  |
| 33 | `event_handler_scope_test` | 16 | 2.6s |  |
| 34 | `frame_label_test` | 17 | 21.9s |  |
| 35 | `getTimer_test` | 8 | 20.4s |  |
| 36 | `get_frame_number_test` | 31 | 23.2s |  |
| 37 | `goto_frame_test` | 15 | 20.9s |  |
| 38 | `instanceNameTest` | 5 | 2.2s |  |
| 39 | `loading/LoadVarsTest` | 36 | 23.6s |  |
| 40 | `loop/loop_test4` | 22 | 21.4s |  |
| 41 | `loop/loop_test5` | 24 | 21.8s |  |
| 42 | `loop/loop_test8` | 38 | 4.7s |  |
| 43 | `loop/loop_test9` | 15 | 20.3s |  |
| 44 | `loop/simple_loop_test` | 0 | 24.8s |  |
| 45 | `masks_test2` | 10 | 18.1s |  |
| 46 | `morph_test1` | 0 | 19.9s |  |
| 47 | `move_object_test` | 11 | 19.6s |  |
| 48 | `multi_doactions_and_goto_frame_test` | 6 | 19.5s |  |
| 49 | `new_child_in_unload_test` | 11 | 19.8s |  |
| 50 | `place_and_remove_object_test` | 13 | 19.6s |  |
| 51 | `register_class/RegisterClassTest3` | 12 | 20.8s |  |
| 52 | `register_class/registerClassTest` | 51 | 23.3s |  |
| 53 | `replace_shapes1test` | 23 | 3.0s |  |
| 54 | `replace_sprites1test` | 21 | 23.1s |  |
| 55 | `reverse_execute_PlaceObject2_test1` | 8 | 22.0s |  |
| 56 | `reverse_execute_PlaceObject2_test2` | 10 | 21.7s |  |
| 57 | `runtime_vm_stack_test` | 9 | 20.6s |  |
| 58 | `shape_test` | 21 | 23.0s |  |
| 59 | `static_vs_dynamic1` | 17 | 19.7s |  |
| 60 | `static_vs_dynamic2` | 18 | 21.3s |  |
| 61 | `timeline_var_test` | 11 | 20.8s |  |
| 62 | `unload_movieclip_test1` | 6 | 20.4s |  |

## Ruffle-Matched Tests

**22 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 23.4s |  |
| 2 | `DefineTextTest` | 4 | 4 | 22.8s |  |
| 3 | `DragDropTest` | 12 | 12 | 3.5s |  |
| 4 | `KeyEventOrder` | 20 | 23 | 21.6s |  |
| 5 | `action_order/action_execution_order_test4` | 7 | 26 | 20.9s |  |
| 6 | `callFunction_test` | 5 | 11 | 20.2s |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.0s |  |
| 8 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.5s |  |
| 9 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.1s |  |
| 10 | `duplicate_movie_clip_test` | 4 | 4 | 21.5s |  |
| 11 | `init_action/InitActionTest` | 6 | 17 | 20.5s |  |
| 12 | `init_action/InitActionTest2` | 24 | 30 | 21.9s |  |
| 13 | `key_event_test` | 5 | 6 | 22.6s |  |
| 14 | `loading/loadMovieTest` | 9 | 9 | 4.8s |  |
| 15 | `loop/loop_test6` | 1 | 12 | 21.5s |  |
| 16 | `loop/loop_test7` | 1 | 8 | 2.8s |  |
| 17 | `matrix_test` | 5 | 9 | 104.0s |  |
| 18 | `path_format_test` | 28 | 28 | 23.8s |  |
| 19 | `place_object_test` | 14 | 14 | 21.8s |  |
| 20 | `place_object_test2` | 22 | 23 | 19.7s |  |
| 21 | `register_class/registerClassTest2` | 8 | 28 | 22.7s |  |
| 22 | `replace_buttons1test` | 3 | 3 | 21.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**8 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16 | 19 | 3 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13 | 17 | 4 |  |
| 5 | `place_and_remove_object_insane_test` | 72.7% | 16 | 22 | 6 |  |
| 6 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 7 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |
| 8 | `loop/loop_test3` | 52.9% | 9 | 17 | 8 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 25.7s |  |
| 2 | `ButtonPropertiesTest` | 21.5s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**24 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16/19 | 19 | 19 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13/17 | 17 | 17 |  |
| 5 | `place_and_remove_object_insane_test` | 72.7% | 16/22 | 22 | 22 |  |
| 6 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 7 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 8 | `loop/loop_test3` | 52.9% | 9/17 | 17 | 16 |  |
| 9 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 10 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 11 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 12 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 13 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 14 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 15 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 16 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 17 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 18 | `loop/loop_test` | 14.8% | 4/27 | 27 | 21 |  |
| 19 | `action_order/ActionOrderTest5` | 11.5% | 7/61 | 61 | 51 |  |
| 20 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 21 | `action_order/ActionOrderTest4` | 9.7% | 7/72 | 72 | 64 |  |
| 22 | `action_order/ActionOrderTest3` | 4.3% | 3/69 | 69 | 62 |  |
| 23 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 24 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
