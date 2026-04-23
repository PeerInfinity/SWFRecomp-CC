# Ruffle Test Results (Filtered)

**Date**: 2026-04-23 01:30 UTC

**Git SHA**: `ac84d98fed`

**Run Duration**: 22m 21s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **31** (30.4%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **42** (41.2%) |
| Failing | 60 |
| Total expected lines | 4541 |
| Matching lines | 2245 (49.4%) |
| Mismatched lines | 2296 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 59 | 98.3% |
| Compile Fail | 1 | 1.7% |

## Passing Tests

**31 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 16.6s |  |
| 2 | `PlaceObject2Test` | 9 | 16.2s |  |
| 3 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 4 | `Video-EmbedSquareTest` | 2 | 16.6s |  |
| 5 | `action_order/action_execution_order_test1` | 10 | 16.2s |  |
| 6 | `action_order/action_execution_order_test7` | 7 | 16.0s |  |
| 7 | `action_order/action_execution_order_test9` | 4 | 15.8s |  |
| 8 | `attachMovieTest` | 12 | 16.5s |  |
| 9 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.4s |  |
| 11 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.2s |  |
| 12 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 13 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 14 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 15 | `getTimer_test` | 8 | 16.7s |  |
| 16 | `get_frame_number_test` | 31 | 16.9s |  |
| 17 | `loop/loop_test4` | 22 | 13.2s |  |
| 18 | `loop/loop_test5` | 24 | 0.3s |  |
| 19 | `loop/loop_test9` | 15 | 16.3s |  |
| 20 | `loop/simple_loop_test` | 0 | 16.4s |  |
| 21 | `masks_test2` | 10 | 17.4s |  |
| 22 | `morph_test1` | 0 | 17.2s |  |
| 23 | `move_object_test` | 11 | 16.4s |  |
| 24 | `multi_doactions_and_goto_frame_test` | 6 | 16.6s |  |
| 25 | `place_and_remove_object_test` | 13 | 16.1s |  |
| 26 | `reverse_execute_PlaceObject2_test1` | 8 | 16.9s |  |
| 27 | `reverse_execute_PlaceObject2_test2` | 10 | 16.5s |  |
| 28 | `shape_test` | 21 | 16.2s |  |
| 29 | `static_vs_dynamic2` | 18 | 16.2s |  |
| 30 | `timeline_var_test` | 11 | 16.1s |  |
| 31 | `unload_movieclip_test1` | 6 | 16.1s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 16.1s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.4s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 16.2s |  |
| 4 | `attachExtImported` | 1 | 1 | 15.9s |  |
| 5 | `callFunction_test` | 5 | 11 | 17.1s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 16.2s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 16.4s |  |
| 8 | `path_format_test` | 27 | 28 | 17.5s |  |
| 9 | `place_object_test` | 14 | 14 | 16.4s |  |
| 10 | `place_object_test2` | 16 | 23 | 16.1s |  |
| 11 | `runtime_vm_stack_test` | 5 | 8 | 16.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**23 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 2 | `static_vs_dynamic1` | 82.4% | 14 | 17 | 3 |  |
| 3 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 4 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 5 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 6 | `loop/loop_test7` | 73.3% | 11 | 15 | 4 |  |
| 7 | `action_order/action_execution_order_test8-v5` | 72.7% | 8 | 11 | 3 |  |
| 8 | `action_order/action_execution_order_test8-v6` | 72.7% | 8 | 11 | 3 |  |
| 9 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 10 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 11 | `event_handler_scope_test` | 68.8% | 11 | 16 | 5 |  |
| 12 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 13 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 14 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 15 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 16 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 17 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 18 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 19 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 20 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 21 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 22 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 23 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**59 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 2 | `static_vs_dynamic1` | 82.4% | 14/17 | 17 | 17 |  |
| 3 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 4 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 5 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 6 | `loop/loop_test7` | 73.3% | 11/15 | 14 | 15 |  |
| 7 | `action_order/action_execution_order_test8-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 8 | `action_order/action_execution_order_test8-v6` | 72.7% | 8/11 | 11 | 11 |  |
| 9 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 10 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 11 | `event_handler_scope_test` | 68.8% | 11/16 | 16 | 16 |  |
| 12 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 13 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 14 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 15 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 16 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 17 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 18 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 19 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 20 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 21 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 22 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 23 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 24 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 25 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 26 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 27 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 28 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 29 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 30 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 31 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 32 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 33 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 34 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 35 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 36 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 37 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 38 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 39 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 40 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 41 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 42 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 43 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 44 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 45 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 46 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 47 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 48 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 49 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 50 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 51 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 52 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 53 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 54 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 55 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 56 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 57 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 58 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 59 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
