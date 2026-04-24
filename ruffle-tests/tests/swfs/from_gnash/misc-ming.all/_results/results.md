# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-24 02:43 UTC

**Git SHA**: `1dc344c147`

**Run Duration**: 24m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **36** (35.3%) |
| Ruffle-matched | 10 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **46** (45.1%) |
| Failing | 56 |
| Total expected lines | 4541 |
| Matching lines | 2270 (50.0%) |
| Mismatched lines | 2271 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 55 | 98.2% |
| Compile Fail | 1 | 1.8% |

## Passing Tests

**36 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 26.1s |  |
| 2 | `PlaceObject2Test` | 9 | 18.0s |  |
| 3 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 4 | `Video-EmbedSquareTest` | 2 | 16.3s |  |
| 5 | `action_order/action_execution_order_test1` | 10 | 16.4s |  |
| 6 | `action_order/action_execution_order_test7` | 7 | 18.0s |  |
| 7 | `action_order/action_execution_order_test8-v5` | 11 | 18.3s |  |
| 8 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 9 | `action_order/action_execution_order_test9` | 4 | 17.1s |  |
| 10 | `attachMovieTest` | 12 | 12.8s |  |
| 11 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.1s |  |
| 12 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.3s |  |
| 14 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 15 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 16 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 17 | `getTimer_test` | 8 | 16.2s |  |
| 18 | `get_frame_number_test` | 31 | 16.3s |  |
| 19 | `instanceNameTest` | 5 | 1.7s |  |
| 20 | `loop/loop_test4` | 22 | 14.9s |  |
| 21 | `loop/loop_test5` | 24 | 2.3s |  |
| 22 | `loop/loop_test9` | 15 | 17.6s |  |
| 23 | `loop/simple_loop_test` | 0 | 17.6s |  |
| 24 | `masks_test2` | 10 | 16.3s |  |
| 25 | `morph_test1` | 0 | 16.8s |  |
| 26 | `move_object_test` | 11 | 17.2s |  |
| 27 | `multi_doactions_and_goto_frame_test` | 6 | 17.4s |  |
| 28 | `place_and_remove_object_test` | 13 | 16.2s |  |
| 29 | `reverse_execute_PlaceObject2_test1` | 8 | 17.7s |  |
| 30 | `reverse_execute_PlaceObject2_test2` | 10 | 18.1s |  |
| 31 | `runtime_vm_stack_test` | 9 | 18.4s |  |
| 32 | `shape_test` | 21 | 19.7s |  |
| 33 | `static_vs_dynamic1` | 17 | 17.9s |  |
| 34 | `static_vs_dynamic2` | 18 | 19.9s |  |
| 35 | `timeline_var_test` | 11 | 19.5s |  |
| 36 | `unload_movieclip_test1` | 6 | 18.9s |  |

## Ruffle-Matched Tests

**10 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 16.0s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 2.8s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 19.0s |  |
| 4 | `attachExtImported` | 1 | 1 | 17.1s |  |
| 5 | `callFunction_test` | 5 | 11 | 12.9s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 18.3s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 19.3s |  |
| 8 | `path_format_test` | 27 | 28 | 16.1s |  |
| 9 | `place_object_test` | 14 | 14 | 16.5s |  |
| 10 | `place_object_test2` | 16 | 23 | 16.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**20 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DefineEditTextVariableNameTest2` | 92.3% | 36 | 39 | 3 |  |
| 2 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 3 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 4 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 5 | `loop/loop_test7` | 73.3% | 11 | 15 | 4 |  |
| 6 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 7 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 8 | `event_handler_scope_test` | 68.8% | 11 | 16 | 5 |  |
| 9 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 10 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 11 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 12 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 13 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 14 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 15 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 16 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 17 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 18 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 19 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 20 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**55 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DefineEditTextVariableNameTest2` | 92.3% | 36/39 | 39 | 39 |  |
| 2 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 3 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 4 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 5 | `loop/loop_test7` | 73.3% | 11/15 | 14 | 15 |  |
| 6 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 7 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 8 | `event_handler_scope_test` | 68.8% | 11/16 | 16 | 16 |  |
| 9 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 10 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 11 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 12 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 13 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 14 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 15 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 16 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 17 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 18 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 19 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 20 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 21 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 22 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 23 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 24 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 25 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 26 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 27 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 28 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 29 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 30 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 31 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 32 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 33 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 34 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 35 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 36 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 37 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 38 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 39 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 40 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 41 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 42 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 43 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 44 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 45 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 46 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 47 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 48 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 49 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 50 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 51 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 52 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 53 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 54 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 55 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
