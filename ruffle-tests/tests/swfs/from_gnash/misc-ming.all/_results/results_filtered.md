# Ruffle Test Results (Filtered)

**Date**: 2026-04-22 21:57 UTC

**Git SHA**: `7f5dd0f68f`

**Run Duration**: 0m 35s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **24** (23.5%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **35** (34.3%) |
| Failing | 67 |
| Total expected lines | 4541 |
| Matching lines | 2206 (48.6%) |
| Mismatched lines | 2335 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 66 | 98.5% |
| Compile Fail | 1 | 1.5% |

## Passing Tests

**24 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 0.7s |  |
| 2 | `PlaceObject2Test` | 9 | 0.2s |  |
| 3 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 4 | `Video-EmbedSquareTest` | 2 | 0.2s |  |
| 5 | `action_order/action_execution_order_test1` | 10 | 0.2s |  |
| 6 | `action_order/action_execution_order_test7` | 7 | 0.2s |  |
| 7 | `action_order/action_execution_order_test9` | 4 | 0.2s |  |
| 8 | `attachMovieTest` | 12 | 0.2s |  |
| 9 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.2s |  |
| 10 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.2s |  |
| 11 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.2s |  |
| 12 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 14 | `getTimer_test` | 8 | 0.2s |  |
| 15 | `get_frame_number_test` | 31 | 0.4s |  |
| 16 | `loop/simple_loop_test` | 0 | 0.2s |  |
| 17 | `masks_test2` | 10 | 0.2s |  |
| 18 | `morph_test1` | 0 | 0.2s |  |
| 19 | `move_object_test` | 11 | 0.2s |  |
| 20 | `multi_doactions_and_goto_frame_test` | 6 | 0.2s |  |
| 21 | `place_and_remove_object_test` | 13 | 0.2s |  |
| 22 | `shape_test` | 21 | 0.3s |  |
| 23 | `timeline_var_test` | 11 | 0.2s |  |
| 24 | `unload_movieclip_test1` | 6 | 0.2s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 0.2s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.3s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 0.2s |  |
| 4 | `attachExtImported` | 1 | 1 | 0.3s |  |
| 5 | `callFunction_test` | 5 | 11 | 0.2s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 0.2s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 0.3s |  |
| 8 | `path_format_test` | 27 | 28 | 0.3s |  |
| 9 | `place_object_test` | 14 | 14 | 0.2s |  |
| 10 | `place_object_test2` | 16 | 23 | 0.2s |  |
| 11 | `runtime_vm_stack_test` | 5 | 8 | 0.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**30 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15 | 18 | 3 |  |
| 3 | `loop/loop_test4` | 81.8% | 18 | 22 | 4 |  |
| 4 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 5 | `static_vs_dynamic1` | 76.5% | 13 | 17 | 4 |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 7 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 8 | `loop/loop_test9` | 73.3% | 11 | 15 | 4 |  |
| 9 | `action_order/action_execution_order_test8-v5` | 72.7% | 8 | 11 | 3 |  |
| 10 | `action_order/action_execution_order_test8-v6` | 72.7% | 8 | 11 | 3 |  |
| 11 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 12 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 13 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 14 | `event_handler_scope_test` | 68.8% | 11 | 16 | 5 |  |
| 15 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 16 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 17 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 18 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 19 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 20 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 21 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 22 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 23 | `loop/loop_test7` | 53.3% | 8 | 15 | 7 |  |
| 24 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 25 | `loop/loop_test5` | 52.0% | 13 | 25 | 12 |  |
| 26 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9 | 18 | 9 |  |
| 28 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 29 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |
| 30 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**66 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15/18 | 18 | 18 |  |
| 3 | `loop/loop_test4` | 81.8% | 18/22 | 22 | 22 |  |
| 4 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 5 | `static_vs_dynamic1` | 76.5% | 13/17 | 17 | 17 |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 7 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 8 | `loop/loop_test9` | 73.3% | 11/15 | 15 | 15 |  |
| 9 | `action_order/action_execution_order_test8-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 10 | `action_order/action_execution_order_test8-v6` | 72.7% | 8/11 | 11 | 11 |  |
| 11 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 12 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 13 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 14 | `event_handler_scope_test` | 68.8% | 11/16 | 16 | 16 |  |
| 15 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 16 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 17 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 18 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 19 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 20 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 21 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 22 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 23 | `loop/loop_test7` | 53.3% | 8/15 | 14 | 15 |  |
| 24 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 25 | `loop/loop_test5` | 52.0% | 13/25 | 25 | 24 |  |
| 26 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 27 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9/18 | 18 | 15 |  |
| 28 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 29 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 30 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 31 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 32 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 33 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 34 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 35 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 36 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 37 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 38 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 39 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 40 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 41 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 42 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 43 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 44 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 45 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 46 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 47 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 48 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 49 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 50 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 51 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 52 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 53 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 54 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 55 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 56 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 57 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 58 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 59 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 60 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 61 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 62 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 63 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 64 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 65 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 66 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
