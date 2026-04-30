# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-30 16:23 UTC

**Git SHA**: `603d663c71`

**Run Duration**: 23m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **57** (55.9%) |
| Ruffle-matched | 13 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **70** (68.6%) |
| Failing | 32 |
| Total expected lines | 4577 |
| Matching lines | 2776 (60.7%) |
| Mismatched lines | 1801 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 32 | 100.0% |

## Passing Tests

**57 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 16.6s |  |
| 2 | `DefineEditTextTest` | 153 | 17.1s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 16.5s |  |
| 4 | `PlaceObject2Test` | 9 | 17.9s |  |
| 5 | `ResolveEventsTest` | 15 | 0.3s |  |
| 6 | `RollOverOutTest` | 5 | 18.0s |  |
| 7 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 8 | `Video-EmbedSquareTest` | 2 | 17.6s |  |
| 9 | `action_order/action_execution_order_test1` | 10 | 18.6s |  |
| 10 | `action_order/action_execution_order_test2` | 5 | 16.5s |  |
| 11 | `action_order/action_execution_order_test3` | 4 | 16.3s |  |
| 12 | `action_order/action_execution_order_test7` | 7 | 18.1s |  |
| 13 | `action_order/action_execution_order_test8-v5` | 11 | 17.5s |  |
| 14 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 15 | `action_order/action_execution_order_test9` | 4 | 17.7s |  |
| 16 | `attachExtImported` | 2 | 17.6s |  |
| 17 | `attachImported` | 2 | 0.3s |  |
| 18 | `attachMovieLoopingTest` | 41 | 17.6s |  |
| 19 | `attachMovieTest` | 12 | 17.8s |  |
| 20 | `consecutive_goto_frame_test` | 12 | 18.0s |  |
| 21 | `displaylist_depths/displaylist_depths_test10` | 10 | 16.8s |  |
| 22 | `displaylist_depths/displaylist_depths_test11` | 15 | 16.8s |  |
| 23 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.5s |  |
| 24 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 25 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 27 | `event_handler_scope_test` | 16 | 17.4s |  |
| 28 | `getTimer_test` | 8 | 17.2s |  |
| 29 | `get_frame_number_test` | 31 | 17.3s |  |
| 30 | `goto_frame_test` | 15 | 17.2s |  |
| 31 | `instanceNameTest` | 5 | 0.3s |  |
| 32 | `loop/loop_test` | 21 | 16.7s |  |
| 33 | `loop/loop_test2` | 15 | 16.3s |  |
| 34 | `loop/loop_test3` | 16 | 17.2s |  |
| 35 | `loop/loop_test4` | 22 | 16.8s |  |
| 36 | `loop/loop_test5` | 24 | 0.3s |  |
| 37 | `loop/loop_test8` | 38 | 17.1s |  |
| 38 | `loop/loop_test9` | 15 | 16.5s |  |
| 39 | `loop/simple_loop_test` | 0 | 16.7s |  |
| 40 | `masks_test2` | 10 | 16.8s |  |
| 41 | `morph_test1` | 0 | 17.2s |  |
| 42 | `move_object_test` | 11 | 17.3s |  |
| 43 | `multi_doactions_and_goto_frame_test` | 6 | 17.1s |  |
| 44 | `new_child_in_unload_test` | 11 | 17.4s |  |
| 45 | `place_and_remove_object_insane_test` | 22 | 16.7s |  |
| 46 | `place_and_remove_object_test` | 13 | 17.4s |  |
| 47 | `register_class/RegisterClassTest3` | 12 | 17.4s |  |
| 48 | `register_class/registerClassTest` | 51 | 17.3s |  |
| 49 | `replace_sprites1test` | 21 | 16.9s |  |
| 50 | `reverse_execute_PlaceObject2_test1` | 8 | 16.9s |  |
| 51 | `reverse_execute_PlaceObject2_test2` | 10 | 16.8s |  |
| 52 | `runtime_vm_stack_test` | 9 | 16.6s |  |
| 53 | `shape_test` | 21 | 16.8s |  |
| 54 | `static_vs_dynamic1` | 17 | 16.5s |  |
| 55 | `static_vs_dynamic2` | 18 | 17.4s |  |
| 56 | `timeline_var_test` | 11 | 17.4s |  |
| 57 | `unload_movieclip_test1` | 6 | 17.7s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 16.4s |  |
| 2 | `DefineTextTest` | 4 | 4 | 16.4s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 17.4s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 0.3s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 18.4s |  |
| 6 | `callFunction_test` | 5 | 11 | 17.9s |  |
| 7 | `init_action/InitActionTest` | 6 | 17 | 17.4s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 17.4s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 17.1s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 11 | `path_format_test` | 27 | 28 | 16.9s |  |
| 12 | `place_object_test` | 14 | 14 | 17.7s |  |
| 13 | `place_object_test2` | 20 | 23 | 17.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**14 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 2 | `loading/LoadVarsTest` | 86.1% | 31 | 36 | 5 |  |
| 3 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 4 | `register_class/registerClassTest2` | 79.5% | 35 | 44 | 9 |  |
| 5 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 6 | `replace_shapes1test` | 73.9% | 17 | 23 | 6 |  |
| 7 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 10 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 11 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 12 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |
| 14 | `loop/loop_test6` | 50.0% | 12 | 24 | 12 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**32 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99/111 | 111 | 111 |  |
| 2 | `loading/LoadVarsTest` | 86.1% | 31/36 | 36 | 36 |  |
| 3 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 4 | `register_class/registerClassTest2` | 79.5% | 35/44 | 44 | 44 |  |
| 5 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 6 | `replace_shapes1test` | 73.9% | 17/23 | 23 | 23 |  |
| 7 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 10 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 11 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 12 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 14 | `loop/loop_test6` | 50.0% | 12/24 | 24 | 23 |  |
| 15 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 17 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 18 | `displaylist_depths/displaylist_depths_test8` | 43.8% | 7/16 | 16 | 15 |  |
| 19 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 20 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 21 | `replace_buttons1test` | 33.3% | 6/18 | 18 | 18 |  |
| 22 | `key_event_test` | 31.8% | 27/85 | 85 | 66 |  |
| 23 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 24 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 25 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 26 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 27 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 28 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 29 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 30 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 31 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 32 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
