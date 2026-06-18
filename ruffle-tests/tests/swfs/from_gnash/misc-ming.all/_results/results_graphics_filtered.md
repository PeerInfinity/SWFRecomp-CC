# Ruffle Test Results (Filtered)

**Date**: 2026-06-18 21:40 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 23m 3s

**Filtered**: 2 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 90 |
| Passing | **54** (60.0%) |
| Ruffle-matched | 22 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **76** (84.4%) |
| Failing | 14 |
| Total expected lines | 4711 |
| Matching lines | 3732 (79.2%) |
| Mismatched lines | 979 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**54 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 22.7s |  |
| 2 | `DefineEditTextTest` | 153 | 9.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 17.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 15.3s |  |
| 5 | `DepthLimitsTest` | 20 | 24.3s |  |
| 6 | `PlaceObject2Test` | 9 | 21.9s |  |
| 7 | `VarAndCharClashTest` | 13 | 2.6s |  |
| 8 | `Version4Loader` | 11 | 2.4s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 21.3s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 21.0s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 2.9s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 3.0s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 2.0s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 16.9s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.9s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 1.9s |  |
| 17 | `attachExtImported` | 2 | 23.2s |  |
| 18 | `attachImported` | 2 | 2.8s |  |
| 19 | `attachMovieLoopingTest` | 41 | 22.6s |  |
| 20 | `attachMovieTest` | 12 | 22.6s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 3.0s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.7s |  |
| 23 | `displaylist_depths/displaylist_depths_test5` | 25 | 20.8s |  |
| 24 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.7s |  |
| 25 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test9` | 23 | 21.9s |  |
| 28 | `duplicate_movie_clip_test2` | 21 | 3.4s |  |
| 29 | `event_handler_scope_test` | 16 | 2.8s |  |
| 30 | `goto_frame_test` | 15 | 22.5s |  |
| 31 | `instanceNameTest` | 5 | 2.7s |  |
| 32 | `loading/LoadVarsTest` | 36 | 26.0s |  |
| 33 | `loop/loop_test4` | 22 | 23.4s |  |
| 34 | `loop/loop_test5` | 24 | 4.0s |  |
| 35 | `loop/loop_test8` | 38 | 23.9s |  |
| 36 | `loop/loop_test9` | 15 | 21.4s |  |
| 37 | `loop/simple_loop_test` | 0 | 25.1s |  |
| 38 | `masks_test2` | 10 | 21.3s |  |
| 39 | `morph_test1` | 0 | 24.9s |  |
| 40 | `move_object_test` | 11 | 16.6s |  |
| 41 | `multi_doactions_and_goto_frame_test` | 6 | 16.5s |  |
| 42 | `new_child_in_unload_test` | 11 | 2.3s |  |
| 43 | `register_class/RegisterClassTest3` | 12 | 3.3s |  |
| 44 | `register_class/registerClassTest` | 51 | 24.6s |  |
| 45 | `replace_shapes1test` | 23 | 3.2s |  |
| 46 | `replace_sprites1test` | 21 | 3.5s |  |
| 47 | `reverse_execute_PlaceObject2_test1` | 8 | 22.2s |  |
| 48 | `reverse_execute_PlaceObject2_test2` | 10 | 22.4s |  |
| 49 | `runtime_vm_stack_test` | 9 | 0.9s |  |
| 50 | `shape_test` | 21 | 1.7s |  |
| 51 | `static_vs_dynamic1` | 17 | 0.9s |  |
| 52 | `static_vs_dynamic2` | 18 | 17.6s |  |
| 53 | `timeline_var_test` | 11 | 17.4s |  |
| 54 | `unload_movieclip_test1` | 6 | 2.0s |  |

## Ruffle-Matched Tests

**22 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 25.0s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 25.8s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.1s |  |
| 4 | `DefineTextTest` | 4 | 4 | 2.1s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.3s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 29.4s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 22.3s |  |
| 8 | `action_order/action_execution_order_test4` | 7 | 26 | 4.1s |  |
| 9 | `callFunction_test` | 6 | 11 | 3.7s |  |
| 10 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 29.8s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 22.6s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 22.2s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 24.4s |  |
| 14 | `key_event_test` | 5 | 6 | 24.7s |  |
| 15 | `loading/LoadBitmapTest` | 3 | 3 | 23.5s |  |
| 16 | `loading/loadMovieTest` | 9 | 9 | 5.6s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 3.9s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 3.4s |  |
| 19 | `matrix_test` | 5 | 9 | 103.6s |  |
| 20 | `path_format_test` | 28 | 28 | 5.4s |  |
| 21 | `register_class/registerClassTest2` | 8 | 28 | 23.6s |  |
| 22 | `replace_buttons1test` | 3 | 3 | 3.1s |  |

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

No timeouts.

## All Output Mismatches

**14 tests** with output mismatch, sorted by match rate (best first)

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
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
