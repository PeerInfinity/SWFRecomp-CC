# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-24 23:52 UTC

**Git SHA**: `6fe6fb1a2f`

**Run Duration**: 3m 23s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **66** (60.0%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **92** (83.6%) |
| Failing | 18 |
| Total expected lines | 5239 |
| Matching lines | 3392 (64.7%) |
| Mismatched lines | 1847 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 16 | 88.9% |
| Runtime Segfault | 2 | 11.1% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 1.8s |  |
| 2 | `DefineEditTextTest` | 153 | 1.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 1.2s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 1.1s |  |
| 5 | `DepthLimitsTest` | 20 | 0.9s |  |
| 6 | `PlaceObject2Test` | 9 | 0.9s |  |
| 7 | `ResolveEventsTest` | 15 | 0.9s |  |
| 8 | `RollOverOutTest` | 5 | 1.0s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.0s |  |
| 10 | `Version4Loader` | 11 | 0.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 1.1s |  |
| 12 | `action_order/action_execution_order_test` | 19 | 0.9s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 0.8s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 0.8s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 0.9s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 1.0s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 0.9s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.9s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 0.8s |  |
| 20 | `attachExtImported` | 2 | 0.9s |  |
| 21 | `attachImported` | 2 | 0.9s |  |
| 22 | `attachMovieLoopingTest` | 41 | 0.8s |  |
| 23 | `attachMovieTest` | 12 | 0.8s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 0.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 1.0s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.8s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.9s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.8s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.8s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.9s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 0.9s |  |
| 34 | `event_handler_scope_test` | 16 | 0.9s |  |
| 35 | `frame_label_test` | 17 | 0.8s |  |
| 36 | `getTimer_test` | 8 | 0.7s |  |
| 37 | `get_frame_number_test` | 31 | 1.4s |  |
| 38 | `goto_frame_test` | 15 | 0.8s |  |
| 39 | `instanceNameTest` | 5 | 0.8s |  |
| 40 | `loading/LoadVarsTest` | 36 | 1.0s |  |
| 41 | `loop/loop_test` | 21 | 0.9s |  |
| 42 | `loop/loop_test2` | 15 | 0.7s |  |
| 43 | `loop/loop_test3` | 16 | 0.7s |  |
| 44 | `loop/loop_test4` | 22 | 0.8s |  |
| 45 | `loop/loop_test5` | 24 | 1.0s |  |
| 46 | `loop/loop_test8` | 38 | 1.1s |  |
| 47 | `loop/loop_test9` | 15 | 1.0s |  |
| 48 | `loop/simple_loop_test` | 0 | 7.7s |  |
| 49 | `masks_test2` | 10 | 0.7s |  |
| 50 | `morph_test1` | 0 | 4.0s |  |
| 51 | `move_object_test` | 11 | 0.8s |  |
| 52 | `multi_doactions_and_goto_frame_test` | 6 | 0.8s |  |
| 53 | `new_child_in_unload_test` | 11 | 0.8s |  |
| 54 | `place_and_remove_object_test` | 13 | 1.1s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 22.4s |  |
| 56 | `register_class/registerClassTest` | 51 | 24.6s |  |
| 57 | `replace_shapes1test` | 23 | 0.9s |  |
| 58 | `replace_sprites1test` | 21 | 1.1s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 0.9s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 1.0s |  |
| 61 | `runtime_vm_stack_test` | 9 | 1.0s |  |
| 62 | `shape_test` | 21 | 1.7s |  |
| 63 | `static_vs_dynamic1` | 17 | 0.9s |  |
| 64 | `static_vs_dynamic2` | 18 | 1.1s |  |
| 65 | `timeline_var_test` | 11 | 0.9s |  |
| 66 | `unload_movieclip_test1` | 6 | 0.8s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 1.2s |  |
| 2 | `DefineTextTest` | 4 | 4 | 0.8s |  |
| 3 | `DragDropTest` | 12 | 12 | 0.8s |  |
| 4 | `EmbeddedFontTest` | 27 | 27 | 1.2s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 1.1s |  |
| 6 | `TextSnapshotTest` | 81 | 90 | 1.4s |  |
| 7 | `action_order/action_execution_order_test4` | 7 | 26 | 1.0s |  |
| 8 | `callFunction_test` | 6 | 11 | 0.9s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 1.7s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.9s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.9s |  |
| 12 | `duplicate_movie_clip_test` | 4 | 4 | 0.9s |  |
| 13 | `init_action/InitActionTest` | 6 | 17 | 0.8s |  |
| 14 | `init_action/InitActionTest2` | 24 | 30 | 1.3s |  |
| 15 | `key_event_test` | 5 | 6 | 1.8s |  |
| 16 | `loading/LoadBitmapTest` | 3 | 3 | 1.0s |  |
| 17 | `loading/loadMovieTest` | 9 | 9 | 1.3s |  |
| 18 | `loop/loop_test10` | 23 | 23 | 1.0s |  |
| 19 | `loop/loop_test6` | 1 | 12 | 1.0s |  |
| 20 | `loop/loop_test7` | 1 | 8 | 1.0s |  |
| 21 | `matrix_test` | 5 | 9 | 5.2s |  |
| 22 | `path_format_test` | 28 | 28 | 1.1s |  |
| 23 | `place_object_test` | 14 | 14 | 1.6s |  |
| 24 | `place_object_test2` | 22 | 23 | 0.9s |  |
| 25 | `register_class/registerClassTest2` | 8 | 28 | 1.0s |  |
| 26 | `replace_buttons1test` | 3 | 3 | 0.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `place_and_remove_object_insane_test` | 72.7% | 16 | 22 | 6 |  |
| 4 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 3.2s |  |
| 2 | `ButtonPropertiesTest` | 2.9s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**16 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `place_and_remove_object_insane_test` | 72.7% | 16/22 | 22 | 22 |  |
| 4 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 5 | `action_order/action_execution_order_test5` | 44.1% | 26/59 | 59 | 35 |  |
| 6 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 7 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 8 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 9 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 10 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 11 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 8.3% | 9/108 | 108 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 8.2% | 7/85 | 85 | 62 |  |
| 14 | `register_class/RegisterClassTest4` | 5.2% | 3/58 | 58 | 42 |  |
| 15 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 16 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
