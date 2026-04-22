# Ruffle Test Results (Filtered)

**Date**: 2026-04-22 05:17 UTC

**Git SHA**: `a232eaf41e`

**Run Duration**: 5m 59s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **20** (19.6%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **31** (30.4%) |
| Failing | 71 |
| Total expected lines | 4541 |
| Matching lines | 2191 (48.2%) |
| Mismatched lines | 2350 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 70 | 98.6% |
| Compile Fail | 1 | 1.4% |

## Passing Tests

**20 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 0.7s |  |
| 2 | `PlaceObject2Test` | 9 | 0.2s |  |
| 3 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 4 | `Video-EmbedSquareTest` | 2 | 0.2s |  |
| 5 | `action_order/action_execution_order_test1` | 10 | 0.2s |  |
| 6 | `action_order/action_execution_order_test7` | 7 | 0.1s |  |
| 7 | `action_order/action_execution_order_test9` | 4 | 0.3s |  |
| 8 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.2s |  |
| 9 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 11 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 12 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 13 | `getTimer_test` | 8 | 0.3s |  |
| 14 | `loop/simple_loop_test` | 0 | 0.2s |  |
| 15 | `masks_test2` | 10 | 0.2s |  |
| 16 | `morph_test1` | 0 | 0.2s |  |
| 17 | `move_object_test` | 11 | 0.2s |  |
| 18 | `multi_doactions_and_goto_frame_test` | 6 | 0.2s |  |
| 19 | `timeline_var_test` | 11 | 18.9s |  |
| 20 | `unload_movieclip_test1` | 6 | 18.2s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 0.2s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.4s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 0.2s |  |
| 4 | `attachExtImported` | 1 | 1 | 16.3s |  |
| 5 | `callFunction_test` | 5 | 11 | 0.3s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 0.3s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 16.2s |  |
| 8 | `path_format_test` | 27 | 28 | 21.3s |  |
| 9 | `place_object_test` | 14 | 14 | 0.2s |  |
| 10 | `place_object_test2` | 16 | 23 | 0.2s |  |
| 11 | `runtime_vm_stack_test` | 5 | 8 | 0.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**34 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `get_frame_number_test` | 87.1% | 27 | 31 | 4 |  |
| 2 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 3 | `static_vs_dynamic2` | 83.3% | 15 | 18 | 3 |  |
| 4 | `loop/loop_test4` | 81.8% | 18 | 22 | 4 |  |
| 5 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 6 | `place_and_remove_object_test` | 76.9% | 10 | 13 | 3 |  |
| 7 | `static_vs_dynamic1` | 76.5% | 13 | 17 | 4 |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 9 | `attachMovieTest` | 75.0% | 9 | 12 | 3 |  |
| 10 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 11 | `loop/loop_test9` | 73.3% | 11 | 15 | 4 |  |
| 12 | `action_order/action_execution_order_test8-v5` | 72.7% | 8 | 11 | 3 |  |
| 13 | `action_order/action_execution_order_test8-v6` | 72.7% | 8 | 11 | 3 |  |
| 14 | `shape_test` | 71.4% | 15 | 21 | 6 |  |
| 15 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 16 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 17 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 18 | `event_handler_scope_test` | 68.8% | 11 | 16 | 5 |  |
| 19 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 20 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 21 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 22 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 23 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 24 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 25 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 26 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 27 | `loop/loop_test7` | 53.3% | 8 | 15 | 7 |  |
| 28 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 29 | `loop/loop_test5` | 52.0% | 13 | 25 | 12 |  |
| 30 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 31 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9 | 18 | 9 |  |
| 32 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 33 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |
| 34 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**70 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `get_frame_number_test` | 87.1% | 27/31 | 31 | 31 |  |
| 2 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 3 | `static_vs_dynamic2` | 83.3% | 15/18 | 18 | 18 |  |
| 4 | `loop/loop_test4` | 81.8% | 18/22 | 22 | 22 |  |
| 5 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 6 | `place_and_remove_object_test` | 76.9% | 10/13 | 13 | 13 |  |
| 7 | `static_vs_dynamic1` | 76.5% | 13/17 | 17 | 17 |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 9 | `attachMovieTest` | 75.0% | 9/12 | 12 | 12 |  |
| 10 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 11 | `loop/loop_test9` | 73.3% | 11/15 | 15 | 15 |  |
| 12 | `action_order/action_execution_order_test8-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 13 | `action_order/action_execution_order_test8-v6` | 72.7% | 8/11 | 11 | 11 |  |
| 14 | `shape_test` | 71.4% | 15/21 | 21 | 21 |  |
| 15 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 16 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 17 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 18 | `event_handler_scope_test` | 68.8% | 11/16 | 16 | 16 |  |
| 19 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 20 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 21 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 22 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 23 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 24 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 25 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 26 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 27 | `loop/loop_test7` | 53.3% | 8/15 | 14 | 15 |  |
| 28 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 29 | `loop/loop_test5` | 52.0% | 13/25 | 25 | 24 |  |
| 30 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 31 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9/18 | 18 | 15 |  |
| 32 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 33 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 34 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 35 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 36 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 37 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 38 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 39 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 40 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 41 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 42 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 43 | `loop/loop_test` | 33.3% | 7/21 | 21 | 21 |  |
| 44 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 45 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 46 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 47 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 48 | `goto_frame_test` | 20.0% | 3/15 | 13 | 15 |  |
| 49 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 50 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 51 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 52 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 53 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 54 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 55 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 56 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 57 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 58 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 59 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 60 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 61 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 62 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 63 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 64 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 65 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 66 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 67 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 68 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 69 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 70 | `replace_shapes1test` | 0.0% | 0/29 | 29 | 23 |  |
