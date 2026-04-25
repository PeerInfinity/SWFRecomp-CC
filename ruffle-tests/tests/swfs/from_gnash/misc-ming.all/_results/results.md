# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-25 01:45 UTC

**Git SHA**: `3a9cd203ba`

**Run Duration**: 22m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **41** (40.2%) |
| Ruffle-matched | 10 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **51** (50.0%) |
| Failing | 51 |
| Total expected lines | 4541 |
| Matching lines | 2320 (51.1%) |
| Mismatched lines | 2221 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 50 | 98.0% |
| Compile Fail | 1 | 2.0% |

## Passing Tests

**41 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 17.9s |  |
| 2 | `DefineEditTextVariableNameTest2` | 39 | 15.8s |  |
| 3 | `PlaceObject2Test` | 9 | 16.1s |  |
| 4 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 5 | `Video-EmbedSquareTest` | 2 | 17.1s |  |
| 6 | `action_order/action_execution_order_test1` | 10 | 16.4s |  |
| 7 | `action_order/action_execution_order_test7` | 7 | 16.5s |  |
| 8 | `action_order/action_execution_order_test8-v5` | 11 | 16.4s |  |
| 9 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 10 | `action_order/action_execution_order_test9` | 4 | 17.1s |  |
| 11 | `attachMovieTest` | 12 | 16.4s |  |
| 12 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.4s |  |
| 13 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.5s |  |
| 14 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.1s |  |
| 15 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 16 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 17 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 18 | `event_handler_scope_test` | 16 | 16.8s |  |
| 19 | `getTimer_test` | 8 | 16.0s |  |
| 20 | `get_frame_number_test` | 31 | 16.1s |  |
| 21 | `instanceNameTest` | 5 | 0.3s |  |
| 22 | `loop/loop_test2` | 15 | 15.9s |  |
| 23 | `loop/loop_test3` | 16 | 17.0s |  |
| 24 | `loop/loop_test4` | 22 | 16.9s |  |
| 25 | `loop/loop_test5` | 24 | 0.3s |  |
| 26 | `loop/loop_test9` | 15 | 16.5s |  |
| 27 | `loop/simple_loop_test` | 0 | 16.7s |  |
| 28 | `masks_test2` | 10 | 15.9s |  |
| 29 | `morph_test1` | 0 | 16.5s |  |
| 30 | `move_object_test` | 11 | 17.5s |  |
| 31 | `multi_doactions_and_goto_frame_test` | 6 | 17.7s |  |
| 32 | `new_child_in_unload_test` | 11 | 18.3s |  |
| 33 | `place_and_remove_object_test` | 13 | 16.4s |  |
| 34 | `reverse_execute_PlaceObject2_test1` | 8 | 15.7s |  |
| 35 | `reverse_execute_PlaceObject2_test2` | 10 | 15.5s |  |
| 36 | `runtime_vm_stack_test` | 9 | 16.4s |  |
| 37 | `shape_test` | 21 | 16.9s |  |
| 38 | `static_vs_dynamic1` | 17 | 16.5s |  |
| 39 | `static_vs_dynamic2` | 18 | 16.6s |  |
| 40 | `timeline_var_test` | 11 | 16.7s |  |
| 41 | `unload_movieclip_test1` | 6 | 16.7s |  |

## Ruffle-Matched Tests

**10 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 16.6s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.3s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 16.4s |  |
| 4 | `attachExtImported` | 1 | 1 | 17.2s |  |
| 5 | `callFunction_test` | 5 | 11 | 16.6s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 17.0s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 17.1s |  |
| 8 | `path_format_test` | 27 | 28 | 16.3s |  |
| 9 | `place_object_test` | 14 | 14 | 16.6s |  |
| 10 | `place_object_test2` | 16 | 23 | 16.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**16 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loop/loop_test8` | 97.4% | 37 | 38 | 1 |  |
| 2 | `matrix_test` | 84.0% | 912 | 1086 | 174 |  |
| 3 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 4 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 5 | `ResolveEventsTest` | 73.3% | 11 | 15 | 4 |  |
| 6 | `loop/loop_test7` | 73.3% | 11 | 15 | 4 |  |
| 7 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 8 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 9 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 10 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 11 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 12 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 13 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 14 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 15 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 16 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**50 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loop/loop_test8` | 97.4% | 37/38 | 37 | 38 |  |
| 2 | `matrix_test` | 84.0% | 912/1086 | 1086 | 1086 |  |
| 3 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 4 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 5 | `ResolveEventsTest` | 73.3% | 11/15 | 15 | 15 |  |
| 6 | `loop/loop_test7` | 73.3% | 11/15 | 14 | 15 |  |
| 7 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 8 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 9 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 10 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 11 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 12 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 13 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 14 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 15 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 16 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 17 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 18 | `DrawingApiTest` | 45.3% | 43/95 | 95 | 93 |  |
| 19 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 20 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 21 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 22 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 23 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 24 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 25 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 26 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 27 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 28 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 29 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 30 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 31 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 32 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 33 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 34 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 35 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 36 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 37 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 38 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 39 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 40 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 41 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 42 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 43 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 44 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 45 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 46 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 47 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 48 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 49 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 50 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
