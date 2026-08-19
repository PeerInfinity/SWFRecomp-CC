# Ruffle Test Results (Filtered)

**Date**: 2026-08-19 13:54 UTC

**Git SHA**: `9d038c750e`

**Run Duration**: 36m 3s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 106 |
| Passing | **65** (61.3%) |
| Ruffle-matched | 29 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **94** (88.7%) |
| Failing | 12 |
| Total expected lines | 5141 |
| Matching lines | 3986 (77.5%) |
| Mismatched lines | 1155 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 12 | 100.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 24.5s |  |
| 2 | `DefineEditTextTest` | 153 | 32.8s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 28.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 25.4s |  |
| 5 | `DepthLimitsTest` | 20 | 24.1s |  |
| 6 | `PlaceObject2Test` | 9 | 24.1s |  |
| 7 | `ResolveEventsTest` | 15 | 23.7s |  |
| 8 | `RollOverOutTest` | 5 | 23.6s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.7s |  |
| 10 | `Version4Loader` | 11 | 2.7s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.6s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.4s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 21.3s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 17.3s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 3.0s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 21.6s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 22.1s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 1.2s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.8s |  |
| 20 | `attachExtImported` | 2 | 22.8s |  |
| 21 | `attachImported` | 2 | 2.8s |  |
| 22 | `attachMovieLoopingTest` | 41 | 22.1s |  |
| 23 | `attachMovieTest` | 12 | 22.5s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 22.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 22.0s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 22.1s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 3.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 22.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 3.1s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 24.3s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 24.4s |  |
| 34 | `event_handler_scope_test` | 16 | 3.5s |  |
| 35 | `goto_frame_test` | 15 | 19.6s |  |
| 36 | `instanceNameTest` | 5 | 2.3s |  |
| 37 | `loading/LoadVarsTest` | 36 | 25.9s |  |
| 38 | `loop/loop_test` | 21 | 22.3s |  |
| 39 | `loop/loop_test2` | 15 | 21.9s |  |
| 40 | `loop/loop_test3` | 16 | 2.5s |  |
| 41 | `loop/loop_test4` | 22 | 22.6s |  |
| 42 | `loop/loop_test5` | 24 | 3.8s |  |
| 43 | `loop/loop_test8` | 38 | 25.0s |  |
| 44 | `loop/loop_test9` | 15 | 23.0s |  |
| 45 | `loop/simple_loop_test` | 0 | 25.6s |  |
| 46 | `masks_test2` | 10 | 22.4s |  |
| 47 | `morph_test1` | 0 | 25.8s |  |
| 48 | `move_object_test` | 11 | 23.3s |  |
| 49 | `multi_doactions_and_goto_frame_test` | 6 | 23.2s |  |
| 50 | `new_child_in_unload_test` | 11 | 23.6s |  |
| 51 | `opcode_guard_test` | 18 | 21.7s |  |
| 52 | `place_and_remove_object_insane_test` | 22 | 21.8s |  |
| 53 | `place_and_remove_object_test` | 13 | 21.8s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 3.5s |  |
| 55 | `register_class/registerClassTest` | 51 | 24.8s |  |
| 56 | `replace_shapes1test` | 23 | 3.2s |  |
| 57 | `replace_sprites1test` | 21 | 22.7s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 21.9s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 22.5s |  |
| 60 | `runtime_vm_stack_test` | 9 | 23.3s |  |
| 61 | `shape_test` | 21 | 25.2s |  |
| 62 | `static_vs_dynamic1` | 17 | 22.6s |  |
| 63 | `static_vs_dynamic2` | 18 | 24.1s |  |
| 64 | `timeline_var_test` | 11 | 23.4s |  |
| 65 | `unload_movieclip_test1` | 6 | 22.7s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 27.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 29.1s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 23.8s |  |
| 4 | `DefineTextTest` | 4 | 4 | 22.7s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 26.9s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 23.4s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 32.2s |  |
| 9 | `action_order/action_execution_order_test` | 12 | 12 | 21.9s |  |
| 10 | `action_order/action_execution_order_test4` | 7 | 26 | 18.3s |  |
| 11 | `callFunction_test` | 6 | 11 | 23.0s |  |
| 12 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 30.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 22.7s |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 3.1s |  |
| 15 | `duplicate_movie_clip_test` | 4 | 4 | 24.7s |  |
| 16 | `init_action/InitActionTest` | 6 | 17 | 19.0s |  |
| 17 | `init_action/InitActionTest2` | 24 | 30 | 20.7s |  |
| 18 | `key_event_test` | 5 | 6 | 24.7s |  |
| 19 | `loading/LoadBitmapTest` | 3 | 3 | 23.7s |  |
| 20 | `loading/loadMovieTest` | 9 | 9 | 5.1s |  |
| 21 | `loop/loop_test10` | 23 | 23 | 23.1s |  |
| 22 | `loop/loop_test6` | 1 | 12 | 22.2s |  |
| 23 | `loop/loop_test7` | 1 | 8 | 3.2s |  |
| 24 | `matrix_test` | 5 | 9 | 111.9s |  |
| 25 | `path_format_test` | 28 | 28 | 23.8s |  |
| 26 | `place_object_test` | 14 | 14 | 23.5s |  |
| 27 | `place_object_test2` | 22 | 23 | 22.6s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 23.0s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 21.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**12 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 44.2% | 123/278 | 278 | 278 |  |
| 4 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 5 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 6 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 7 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 8 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 9 | `action_order/ActionOrderTest4` | 9.5% | 10/105 | 105 | 64 |  |
| 10 | `action_order/ActionOrderTest3` | 5.5% | 4/73 | 73 | 62 |  |
| 11 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 12 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
