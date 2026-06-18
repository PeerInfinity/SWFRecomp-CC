# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 05:42 UTC

**Git SHA**: `5f25304460`

**Run Duration**: 35m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 106 |
| Passing | **65** (61.3%) |
| Ruffle-matched | 25 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **90** (84.9%) |
| Failing | 16 |
| Total expected lines | 5122 |
| Matching lines | 3946 (77.0%) |
| Mismatched lines | 1176 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 16 | 100.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 23.5s |  |
| 2 | `DefineEditTextTest` | 153 | 31.9s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 24.3s |  |
| 5 | `DepthLimitsTest` | 20 | 18.4s |  |
| 6 | `PlaceObject2Test` | 9 | 21.2s |  |
| 7 | `ResolveEventsTest` | 15 | 22.6s |  |
| 8 | `RollOverOutTest` | 5 | 22.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.7s |  |
| 10 | `Version4Loader` | 11 | 2.5s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.7s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 23.1s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 23.4s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 21.5s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 21.1s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 21.5s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.2s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 2.5s |  |
| 19 | `attachExtImported` | 2 | 22.5s |  |
| 20 | `attachImported` | 2 | 2.8s |  |
| 21 | `attachMovieLoopingTest` | 41 | 21.5s |  |
| 22 | `attachMovieTest` | 12 | 22.1s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 20.7s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.8s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 21.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.7s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.6s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 21.9s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 21.9s |  |
| 33 | `event_handler_scope_test` | 16 | 3.0s |  |
| 34 | `frame_label_test` | 17 | 22.8s |  |
| 35 | `getTimer_test` | 8 | 21.4s |  |
| 36 | `get_frame_number_test` | 31 | 24.3s |  |
| 37 | `goto_frame_test` | 15 | 22.1s |  |
| 38 | `loading/LoadVarsTest` | 36 | 26.0s |  |
| 39 | `loop/loop_test` | 21 | 22.4s |  |
| 40 | `loop/loop_test2` | 15 | 22.5s |  |
| 41 | `loop/loop_test3` | 16 | 2.9s |  |
| 42 | `loop/loop_test4` | 22 | 23.1s |  |
| 43 | `loop/loop_test5` | 24 | 21.7s |  |
| 44 | `loop/loop_test8` | 38 | 4.2s |  |
| 45 | `loop/loop_test9` | 15 | 21.4s |  |
| 46 | `loop/simple_loop_test` | 0 | 26.5s |  |
| 47 | `masks_test2` | 10 | 20.9s |  |
| 48 | `morph_test1` | 0 | 24.4s |  |
| 49 | `move_object_test` | 11 | 20.8s |  |
| 50 | `multi_doactions_and_goto_frame_test` | 6 | 21.2s |  |
| 51 | `new_child_in_unload_test` | 11 | 21.5s |  |
| 52 | `opcode_guard_test` | 18 | 21.5s |  |
| 53 | `place_and_remove_object_test` | 13 | 23.4s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 21.8s |  |
| 55 | `register_class/registerClassTest` | 51 | 24.2s |  |
| 56 | `replace_shapes1test` | 23 | 3.1s |  |
| 57 | `replace_sprites1test` | 21 | 22.1s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 21.8s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 22.0s |  |
| 60 | `runtime_vm_stack_test` | 9 | 21.4s |  |
| 61 | `shape_test` | 21 | 24.7s |  |
| 62 | `static_vs_dynamic1` | 17 | 20.8s |  |
| 63 | `static_vs_dynamic2` | 18 | 22.4s |  |
| 64 | `timeline_var_test` | 11 | 22.1s |  |
| 65 | `unload_movieclip_test1` | 6 | 21.2s |  |

## Ruffle-Matched Tests

**25 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 25.9s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 27.0s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.7s |  |
| 4 | `DefineTextTest` | 4 | 4 | 21.7s |  |
| 5 | `DragDropTest` | 4 | 4 | 3.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 21.0s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 22.2s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 30.9s |  |
| 9 | `action_order/action_execution_order_test4` | 7 | 26 | 22.6s |  |
| 10 | `callFunction_test` | 6 | 11 | 21.7s |  |
| 11 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 28.3s |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 21.1s |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.8s |  |
| 14 | `duplicate_movie_clip_test` | 4 | 4 | 22.4s |  |
| 15 | `loading/LoadBitmapTest` | 3 | 3 | 23.5s |  |
| 16 | `loading/loadMovieTest` | 9 | 9 | 5.6s |  |
| 17 | `loop/loop_test10` | 23 | 23 | 23.6s |  |
| 18 | `loop/loop_test6` | 1 | 12 | 21.3s |  |
| 19 | `loop/loop_test7` | 1 | 8 | 2.7s |  |
| 20 | `matrix_test` | 5 | 9 | 101.4s |  |
| 21 | `path_format_test` | 28 | 28 | 23.6s |  |
| 22 | `place_object_test` | 14 | 14 | 26.1s |  |
| 23 | `place_object_test2` | 22 | 23 | 23.5s |  |
| 24 | `register_class/registerClassTest2` | 8 | 28 | 23.2s |  |
| 25 | `replace_buttons1test` | 3 | 3 | 21.8s |  |

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

**16 tests** with output mismatch, sorted by match rate (best first)

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
| 14 | `register_class/RegisterClassTest4` | 4.7% | 3/64 | 64 | 42 |  |
| 15 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 16 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
