# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-22 16:45 UTC

**Git SHA**: `d08236d9c2`

**Run Duration**: 24m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **21** (20.6%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **32** (31.4%) |
| Failing | 70 |
| Total expected lines | 4541 |
| Matching lines | 2195 (48.3%) |
| Mismatched lines | 2346 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 69 | 98.6% |
| Compile Fail | 1 | 1.4% |

## Passing Tests

**21 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 28.1s |  |
| 2 | `PlaceObject2Test` | 9 | 18.2s |  |
| 3 | `VarAndCharClashTest` | 13 | 1.3s |  |
| 4 | `Video-EmbedSquareTest` | 2 | 14.2s |  |
| 5 | `action_order/action_execution_order_test1` | 10 | 16.4s |  |
| 6 | `action_order/action_execution_order_test7` | 7 | 18.0s |  |
| 7 | `action_order/action_execution_order_test9` | 4 | 17.1s |  |
| 8 | `displaylist_depths/displaylist_depths_test10` | 10 | 14.4s |  |
| 9 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.1s |  |
| 10 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 11 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 12 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 13 | `getTimer_test` | 8 | 16.9s |  |
| 14 | `get_frame_number_test` | 31 | 16.9s |  |
| 15 | `loop/simple_loop_test` | 0 | 16.9s |  |
| 16 | `masks_test2` | 10 | 16.2s |  |
| 17 | `morph_test1` | 0 | 16.2s |  |
| 18 | `move_object_test` | 11 | 18.1s |  |
| 19 | `multi_doactions_and_goto_frame_test` | 6 | 18.0s |  |
| 20 | `timeline_var_test` | 11 | 16.3s |  |
| 21 | `unload_movieclip_test1` | 6 | 16.3s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 19.5s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.3s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 19.1s |  |
| 4 | `attachExtImported` | 1 | 1 | 17.4s |  |
| 5 | `callFunction_test` | 5 | 11 | 15.7s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 16.6s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 16.4s |  |
| 8 | `path_format_test` | 27 | 28 | 16.3s |  |
| 9 | `place_object_test` | 14 | 14 | 16.6s |  |
| 10 | `place_object_test2` | 16 | 23 | 16.2s |  |
| 11 | `runtime_vm_stack_test` | 5 | 8 | 16.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**33 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15 | 18 | 3 |  |
| 3 | `loop/loop_test4` | 81.8% | 18 | 22 | 4 |  |
| 4 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 5 | `place_and_remove_object_test` | 76.9% | 10 | 13 | 3 |  |
| 6 | `static_vs_dynamic1` | 76.5% | 13 | 17 | 4 |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 8 | `attachMovieTest` | 75.0% | 9 | 12 | 3 |  |
| 9 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 10 | `loop/loop_test9` | 73.3% | 11 | 15 | 4 |  |
| 11 | `action_order/action_execution_order_test8-v5` | 72.7% | 8 | 11 | 3 |  |
| 12 | `action_order/action_execution_order_test8-v6` | 72.7% | 8 | 11 | 3 |  |
| 13 | `shape_test` | 71.4% | 15 | 21 | 6 |  |
| 14 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 15 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 16 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 17 | `event_handler_scope_test` | 68.8% | 11 | 16 | 5 |  |
| 18 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 19 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 20 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 21 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 22 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 23 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 24 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 25 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 26 | `loop/loop_test7` | 53.3% | 8 | 15 | 7 |  |
| 27 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 28 | `loop/loop_test5` | 52.0% | 13 | 25 | 12 |  |
| 29 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 30 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9 | 18 | 9 |  |
| 31 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |
| 33 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**69 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15/18 | 18 | 18 |  |
| 3 | `loop/loop_test4` | 81.8% | 18/22 | 22 | 22 |  |
| 4 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 5 | `place_and_remove_object_test` | 76.9% | 10/13 | 13 | 13 |  |
| 6 | `static_vs_dynamic1` | 76.5% | 13/17 | 17 | 17 |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 8 | `attachMovieTest` | 75.0% | 9/12 | 12 | 12 |  |
| 9 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 10 | `loop/loop_test9` | 73.3% | 11/15 | 15 | 15 |  |
| 11 | `action_order/action_execution_order_test8-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 12 | `action_order/action_execution_order_test8-v6` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `shape_test` | 71.4% | 15/21 | 21 | 21 |  |
| 14 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 15 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 16 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 17 | `event_handler_scope_test` | 68.8% | 11/16 | 16 | 16 |  |
| 18 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 19 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 20 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 21 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 22 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 23 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 24 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 25 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 26 | `loop/loop_test7` | 53.3% | 8/15 | 14 | 15 |  |
| 27 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 28 | `loop/loop_test5` | 52.0% | 13/25 | 25 | 24 |  |
| 29 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 30 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9/18 | 18 | 15 |  |
| 31 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 32 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 33 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 34 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 35 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 36 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 37 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 38 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 39 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 40 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 41 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 42 | `loop/loop_test` | 33.3% | 7/21 | 21 | 21 |  |
| 43 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 44 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 45 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 46 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 47 | `goto_frame_test` | 20.0% | 3/15 | 13 | 15 |  |
| 48 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 49 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 50 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 51 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 52 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 53 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 54 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 55 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 56 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 57 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 58 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 59 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 60 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 61 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 62 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 63 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 64 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 65 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 66 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 67 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 68 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 69 | `replace_shapes1test` | 0.0% | 0/29 | 29 | 23 |  |
