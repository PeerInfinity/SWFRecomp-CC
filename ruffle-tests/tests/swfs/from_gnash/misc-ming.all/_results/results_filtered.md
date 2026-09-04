# Ruffle Test Results (Filtered)

**Date**: 2026-09-04 16:45 UTC

**Git SHA**: `646796612e`

**Run Duration**: 27m 44s

**Filtered**: 1 tests ignored out of 111 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 110 |
| Passing | **69** (62.7%) |
| Ruffle-matched | 29 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **98** (89.1%) |
| Failing | 12 |
| Total expected lines | 5206 |
| Matching lines | 4051 (77.8%) |
| Mismatched lines | 1155 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 12 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 22.6s |  |
| 2 | `DefineEditTextTest` | 153 | 28.3s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.1s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.4s |  |
| 5 | `DepthLimitsTest` | 20 | 17.1s |  |
| 6 | `PlaceObject2Test` | 9 | 22.2s |  |
| 7 | `ResolveEventsTest` | 15 | 18.2s |  |
| 8 | `RollOverOutTest` | 5 | 2.0s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.9s |  |
| 10 | `Version4Loader` | 11 | 1.8s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 20.9s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 22.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 22.2s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 2.2s |  |
| 15 | `action_order/action_execution_order_test5` | 35 | 2.8s |  |
| 16 | `action_order/action_execution_order_test7` | 7 | 21.3s |  |
| 17 | `action_order/action_execution_order_test8-v5` | 11 | 21.7s |  |
| 18 | `action_order/action_execution_order_test8-v6` | 11 | 0.5s |  |
| 19 | `action_order/action_execution_order_test9` | 4 | 2.0s |  |
| 20 | `attachExtImported` | 2 | 22.0s |  |
| 21 | `attachImported` | 2 | 2.0s |  |
| 22 | `attachMovieLoopingTest` | 41 | 20.8s |  |
| 23 | `attachMovieTest` | 12 | 21.4s |  |
| 24 | `consecutive_goto_frame_test` | 12 | 18.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.1s |  |
| 27 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test5` | 25 | 21.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.0s |  |
| 30 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.4s |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.9s |  |
| 32 | `displaylist_depths/displaylist_depths_test9` | 23 | 22.5s |  |
| 33 | `duplicate_movie_clip_test2` | 21 | 3.1s |  |
| 34 | `event_handler_scope_test` | 16 | 2.3s |  |
| 35 | `frame_label_test` | 17 | 3.6s |  |
| 36 | `getTimer_test` | 8 | 22.2s |  |
| 37 | `get_frame_number_test` | 31 | 23.8s |  |
| 38 | `gotoFrame2Test` | 9 | 21.4s |  |
| 39 | `goto_frame_test` | 15 | 16.8s |  |
| 40 | `instanceNameTest` | 5 | 1.4s |  |
| 41 | `loading/LoadVarsTest` | 36 | 26.7s |  |
| 42 | `loop/loop_test` | 21 | 15.7s |  |
| 43 | `loop/loop_test2` | 15 | 1.3s |  |
| 44 | `loop/loop_test3` | 16 | 1.5s |  |
| 45 | `loop/loop_test4` | 22 | 21.8s |  |
| 46 | `loop/loop_test5` | 24 | 3.1s |  |
| 47 | `loop/loop_test8` | 38 | 22.8s |  |
| 48 | `loop/loop_test9` | 15 | 20.9s |  |
| 49 | `loop/simple_loop_test` | 0 | 1.4s |  |
| 50 | `masks_test2` | 10 | 17.0s |  |
| 51 | `morph_test1` | 0 | 16.6s |  |
| 52 | `move_object_test` | 11 | 21.6s |  |
| 53 | `multi_doactions_and_goto_frame_test` | 6 | 21.9s |  |
| 54 | `new_child_in_unload_test` | 11 | 21.8s |  |
| 55 | `opcode_guard_test` | 18 | 23.7s |  |
| 56 | `place_and_remove_object_insane_test` | 22 | 23.8s |  |
| 57 | `place_and_remove_object_test` | 13 | 21.4s |  |
| 58 | `register_class/RegisterClassTest3` | 12 | 21.9s |  |
| 59 | `register_class/registerClassTest` | 51 | 24.4s |  |
| 60 | `replace_shapes1test` | 23 | 0.2s |  |
| 61 | `replace_sprites1test` | 21 | 3.2s |  |
| 62 | `reverse_execute_PlaceObject2_test1` | 8 | 25.4s |  |
| 63 | `reverse_execute_PlaceObject2_test2` | 10 | 25.7s |  |
| 64 | `runtime_vm_stack_test` | 9 | 17.1s |  |
| 65 | `shape_test` | 21 | 17.4s |  |
| 66 | `static_vs_dynamic1` | 17 | 1.5s |  |
| 67 | `static_vs_dynamic2` | 18 | 21.4s |  |
| 68 | `timeline_var_test` | 11 | 21.1s |  |
| 69 | `unload_movieclip_test1` | 6 | 1.9s |  |

## Ruffle-Matched Tests

**29 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 26.4s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 28.0s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 2.3s |  |
| 4 | `DefineTextTest` | 4 | 4 | 2.0s |  |
| 5 | `DragDropTest` | 4 | 4 | 2.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 19.0s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 22.2s |  |
| 8 | `TextSnapshotTest` | 81 | 90 | 24.4s |  |
| 9 | `action_order/action_execution_order_test` | 12 | 12 | 2.9s |  |
| 10 | `action_order/action_execution_order_test4` | 7 | 26 | 22.4s |  |
| 11 | `callFunction_test` | 6 | 11 | 2.3s |  |
| 12 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.7s |  |
| 13 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 22.4s |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.3s |  |
| 15 | `duplicate_movie_clip_test` | 4 | 4 | 23.1s |  |
| 16 | `init_action/InitActionTest` | 6 | 17 | 16.2s |  |
| 17 | `init_action/InitActionTest2` | 24 | 30 | 17.0s |  |
| 18 | `key_event_test` | 5 | 6 | 24.7s |  |
| 19 | `loading/LoadBitmapTest` | 3 | 3 | 24.5s |  |
| 20 | `loading/loadMovieTest` | 9 | 9 | 4.5s |  |
| 21 | `loop/loop_test10` | 23 | 23 | 16.0s |  |
| 22 | `loop/loop_test6` | 1 | 12 | 22.0s |  |
| 23 | `loop/loop_test7` | 1 | 8 | 2.4s |  |
| 24 | `matrix_test` | 5 | 9 | 90.0s |  |
| 25 | `path_format_test` | 28 | 28 | 5.2s |  |
| 26 | `place_object_test` | 14 | 14 | 2.5s |  |
| 27 | `place_object_test2` | 22 | 23 | 21.9s |  |
| 28 | `register_class/registerClassTest2` | 8 | 28 | 0.3s |  |
| 29 | `replace_buttons1test` | 3 | 3 | 0.2s |  |

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
| 8 | `action_order/ActionOrderTest4` | 10.6% | 10/94 | 94 | 64 |  |
| 9 | `action_order/ActionOrderTest5` | 10.3% | 6/58 | 58 | 51 |  |
| 10 | `action_order/ActionOrderTest3` | 4.8% | 4/83 | 83 | 62 |  |
| 11 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 12 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
