# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 19:23 UTC

**Git SHA**: `1396f1e10b`

**Run Duration**: 34m 22s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **70** (63.6%) |
| Ruffle-matched | 32 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **102** (92.7%) |
| Failing | 8 |
| Total expected lines | 5195 |
| Matching lines | 4277 (82.3%) |
| Mismatched lines | 918 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 87.5% |
| Segfault | 1 | 12.5% |

## Passing Tests

**70 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 19.7s |  |
| 2 | `BitmapDataDraw` | 56 | 21.7s |  |
| 3 | `DefineEditTextTest` | 153 | 35.0s |  |
| 4 | `DefineEditTextVariableNameTest` | 72 | 31.0s |  |
| 5 | `DefineEditTextVariableNameTest2` | 39 | 27.3s |  |
| 6 | `DepthLimitsTest` | 20 | 29.1s |  |
| 7 | `PlaceObject2Test` | 9 | 18.1s |  |
| 8 | `ResolveEventsTest` | 15 | 19.5s |  |
| 9 | `RollOverOutTest` | 5 | 19.2s |  |
| 10 | `VarAndCharClashTest` | 13 | 1.9s |  |
| 11 | `Version4Loader` | 11 | 1.9s |  |
| 12 | `Video-EmbedSquareTest` | 2 | 24.1s |  |
| 13 | `action_order/action_execution_order_test1` | 10 | 18.8s |  |
| 14 | `action_order/action_execution_order_test2` | 5 | 16.7s |  |
| 15 | `action_order/action_execution_order_test3` | 4 | 17.0s |  |
| 16 | `action_order/action_execution_order_test5` | 35 | 2.3s |  |
| 17 | `action_order/action_execution_order_test7` | 7 | 18.4s |  |
| 18 | `action_order/action_execution_order_test8-v5` | 11 | 18.7s |  |
| 19 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 20 | `action_order/action_execution_order_test9` | 4 | 1.4s |  |
| 21 | `attachExtImported` | 2 | 20.2s |  |
| 22 | `attachImported` | 2 | 1.9s |  |
| 23 | `attachMovieLoopingTest` | 41 | 19.9s |  |
| 24 | `attachMovieTest` | 12 | 20.9s |  |
| 25 | `consecutive_goto_frame_test` | 12 | 24.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test10` | 10 | 24.0s |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test5` | 25 | 25.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.3s |  |
| 31 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.7s |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.3s |  |
| 33 | `displaylist_depths/displaylist_depths_test9` | 23 | 19.0s |  |
| 34 | `duplicate_movie_clip_test2` | 21 | 19.4s |  |
| 35 | `event_handler_scope_test` | 16 | 1.7s |  |
| 36 | `frame_label_test` | 17 | 24.8s |  |
| 37 | `getTimer_test` | 8 | 23.7s |  |
| 38 | `get_frame_number_test` | 31 | 26.2s |  |
| 39 | `gotoFrame2Test` | 9 | 23.5s |  |
| 40 | `goto_frame_test` | 15 | 19.9s |  |
| 41 | `instanceNameTest` | 5 | 1.7s |  |
| 42 | `loading/LoadVarsTest` | 36 | 27.9s |  |
| 43 | `loop/loop_test` | 21 | 18.9s |  |
| 44 | `loop/loop_test2` | 15 | 18.8s |  |
| 45 | `loop/loop_test3` | 16 | 1.5s |  |
| 46 | `loop/loop_test4` | 22 | 18.8s |  |
| 47 | `loop/loop_test5` | 24 | 2.1s |  |
| 48 | `loop/loop_test8` | 38 | 27.2s |  |
| 49 | `loop/loop_test9` | 15 | 24.6s |  |
| 50 | `loop/simple_loop_test` | 0 | 24.3s |  |
| 51 | `masks_test2` | 10 | 24.2s |  |
| 52 | `morph_test1` | 0 | 24.0s |  |
| 53 | `move_object_test` | 11 | 26.1s |  |
| 54 | `multi_doactions_and_goto_frame_test` | 6 | 26.1s |  |
| 55 | `new_child_in_unload_test` | 11 | 26.2s |  |
| 56 | `opcode_guard_test` | 18 | 18.3s |  |
| 57 | `place_and_remove_object_insane_test` | 22 | 18.8s |  |
| 58 | `place_and_remove_object_test` | 13 | 18.4s |  |
| 59 | `register_class/RegisterClassTest3` | 12 | 19.1s |  |
| 60 | `register_class/registerClassTest` | 51 | 20.5s |  |
| 61 | `replace_shapes1test` | 23 | 2.4s |  |
| 62 | `replace_sprites1test` | 21 | 18.8s |  |
| 63 | `reverse_execute_PlaceObject2_test1` | 8 | 18.3s |  |
| 64 | `reverse_execute_PlaceObject2_test2` | 10 | 18.6s |  |
| 65 | `runtime_vm_stack_test` | 9 | 19.1s |  |
| 66 | `shape_test` | 21 | 20.0s |  |
| 67 | `static_vs_dynamic1` | 17 | 18.6s |  |
| 68 | `static_vs_dynamic2` | 18 | 23.8s |  |
| 69 | `timeline_var_test` | 11 | 23.5s |  |
| 70 | `unload_movieclip_test1` | 6 | 23.4s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 22.4s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 1.5s |  |
| 3 | `DefineTextTest` | 4 | 4 | 24.7s |  |
| 4 | `DragDropTest` | 4 | 4 | 3.7s |  |
| 5 | `DrawingApiTest` | 1 | 14 | 7.7s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 31.2s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 18.4s |  |
| 8 | `NetStream-SquareTest` | 79 | 92 | 24.8s |  |
| 9 | `PrototypeEventListeners` | 23 | 23 | 18.8s |  |
| 10 | `TextSnapshotTest` | 81 | 90 | 25.4s |  |
| 11 | `action_order/action_execution_order_test` | 12 | 12 | 17.3s |  |
| 12 | `action_order/action_execution_order_test4` | 7 | 26 | 18.3s |  |
| 13 | `action_order/action_execution_order_test6` | 5 | 21 | 18.1s |  |
| 14 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 31.7s |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 19.1s |  |
| 16 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.0s |  |
| 17 | `duplicate_movie_clip_test` | 4 | 4 | 19.6s |  |
| 18 | `init_action/InitActionTest` | 6 | 17 | 19.8s |  |
| 19 | `init_action/InitActionTest2` | 24 | 30 | 20.9s |  |
| 20 | `key_event_test` | 5 | 6 | 25.7s |  |
| 21 | `loading/LoadBitmapTest` | 3 | 3 | 25.4s |  |
| 22 | `loading/loadMovieTest` | 9 | 9 | 4.4s |  |
| 23 | `loop/loop_test10` | 23 | 23 | 19.4s |  |
| 24 | `loop/loop_test6` | 11 | 12 | 18.6s |  |
| 25 | `loop/loop_test7` | 1 | 8 | 1.7s |  |
| 26 | `masks_test` | 16 | 16 | 36.4s |  |
| 27 | `matrix_test` | 5 | 9 | 119.7s |  |
| 28 | `path_format_test` | 28 | 28 | 20.1s |  |
| 29 | `place_object_test` | 14 | 14 | 1.7s |  |
| 30 | `place_object_test2` | 22 | 23 | 18.7s |  |
| 31 | `register_class/registerClassTest2` | 8 | 28 | 20.5s |  |
| 32 | `replace_buttons1test` | 3 | 3 | 19.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `callFunction_test` | 41.5s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 3 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 4 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 5 | `action_order/ActionOrderTest4` | 11.7% | 11/94 | 94 | 64 |  |
| 6 | `action_order/ActionOrderTest5` | 8.6% | 5/58 | 58 | 51 |  |
| 7 | `action_order/ActionOrderTest3` | 6.0% | 5/83 | 83 | 62 |  |
