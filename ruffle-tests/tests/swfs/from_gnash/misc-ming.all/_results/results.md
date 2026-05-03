# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-03 16:25 UTC

**Git SHA**: `e06c67e456`

**Run Duration**: 16m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **62** (60.8%) |
| Ruffle-matched | 16 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **78** (76.5%) |
| Failing | 24 |
| Total expected lines | 4577 |
| Matching lines | 2829 (61.8%) |
| Mismatched lines | 1748 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 24 | 100.0% |

## Passing Tests

**62 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.6s |  |
| 2 | `DefineEditTextTest` | 153 | 28.7s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 20.6s |  |
| 4 | `DepthLimitsTest` | 20 | 20.1s |  |
| 5 | `PlaceObject2Test` | 9 | 19.0s |  |
| 6 | `ResolveEventsTest` | 15 | 3.0s |  |
| 7 | `RollOverOutTest` | 5 | 19.7s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 0.2s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 0.2s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 0.2s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 0.2s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 19.6s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 19.4s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 0.2s |  |
| 17 | `attachExtImported` | 2 | 0.3s |  |
| 18 | `attachImported` | 2 | 0.2s |  |
| 19 | `attachMovieLoopingTest` | 41 | 0.2s |  |
| 20 | `attachMovieTest` | 12 | 0.2s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 0.1s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.3s |  |
| 23 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test4` | 26 | 18.5s |  |
| 25 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 28 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.2s |  |
| 29 | `duplicate_movie_clip_test2` | 21 | 19.6s |  |
| 30 | `event_handler_scope_test` | 16 | 18.9s |  |
| 31 | `getTimer_test` | 8 | 18.9s |  |
| 32 | `get_frame_number_test` | 31 | 21.3s |  |
| 33 | `goto_frame_test` | 15 | 19.5s |  |
| 34 | `instanceNameTest` | 5 | 1.7s |  |
| 35 | `loading/LoadVarsTest` | 36 | 0.4s |  |
| 36 | `loop/loop_test` | 21 | 0.2s |  |
| 37 | `loop/loop_test2` | 15 | 0.4s |  |
| 38 | `loop/loop_test3` | 16 | 0.1s |  |
| 39 | `loop/loop_test4` | 22 | 0.2s |  |
| 40 | `loop/loop_test5` | 24 | 0.2s |  |
| 41 | `loop/loop_test8` | 38 | 21.0s |  |
| 42 | `loop/loop_test9` | 15 | 1.9s |  |
| 43 | `loop/simple_loop_test` | 0 | 18.6s |  |
| 44 | `masks_test2` | 10 | 0.2s |  |
| 45 | `morph_test1` | 0 | 0.2s |  |
| 46 | `move_object_test` | 11 | 18.7s |  |
| 47 | `multi_doactions_and_goto_frame_test` | 6 | 1.8s |  |
| 48 | `new_child_in_unload_test` | 11 | 18.8s |  |
| 49 | `place_and_remove_object_insane_test` | 22 | 2.0s |  |
| 50 | `place_and_remove_object_test` | 13 | 1.9s |  |
| 51 | `register_class/RegisterClassTest3` | 12 | 16.6s |  |
| 52 | `register_class/registerClassTest` | 51 | 18.6s |  |
| 53 | `replace_shapes1test` | 23 | 2.3s |  |
| 54 | `replace_sprites1test` | 21 | 18.9s |  |
| 55 | `reverse_execute_PlaceObject2_test1` | 8 | 18.3s |  |
| 56 | `reverse_execute_PlaceObject2_test2` | 10 | 18.6s |  |
| 57 | `runtime_vm_stack_test` | 9 | 14.9s |  |
| 58 | `shape_test` | 21 | 15.9s |  |
| 59 | `static_vs_dynamic1` | 17 | 14.6s |  |
| 60 | `static_vs_dynamic2` | 18 | 19.1s |  |
| 61 | `timeline_var_test` | 11 | 19.0s |  |
| 62 | `unload_movieclip_test1` | 6 | 19.2s |  |

## Ruffle-Matched Tests

**16 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 19.6s |  |
| 2 | `DefineTextTest` | 4 | 4 | 18.7s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 0.2s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 0.2s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 20.8s |  |
| 6 | `callFunction_test` | 5 | 11 | 0.2s |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 0.4s |  |
| 8 | `init_action/InitActionTest` | 6 | 17 | 2.2s |  |
| 9 | `init_action/InitActionTest2` | 24 | 30 | 19.6s |  |
| 10 | `loading/loadMovieTest` | 9 | 9 | 0.3s |  |
| 11 | `loop/loop_test7` | 1 | 8 | 2.3s |  |
| 12 | `path_format_test` | 27 | 28 | 20.4s |  |
| 13 | `place_object_test` | 14 | 14 | 18.8s |  |
| 14 | `place_object_test2` | 20 | 23 | 18.5s |  |
| 15 | `register_class/registerClassTest2` | 8 | 28 | 19.6s |  |
| 16 | `replace_buttons1test` | 3 | 3 | 18.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**8 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 2 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 4 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 6 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |
| 7 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |
| 8 | `loop/loop_test6` | 50.0% | 12 | 24 | 12 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**24 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 2 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 4 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 6 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 7 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 8 | `loop/loop_test6` | 50.0% | 12/24 | 24 | 23 |  |
| 9 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 11 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 12 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 13 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 14 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 15 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 16 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 17 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 18 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 19 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 20 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 21 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 22 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 23 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 24 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
