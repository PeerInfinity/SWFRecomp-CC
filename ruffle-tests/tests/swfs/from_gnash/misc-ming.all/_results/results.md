# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-23 21:53 UTC

**Git SHA**: `1456eccd16`

**Run Duration**: 0m 37s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **33** (32.4%) |
| Ruffle-matched | 10 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **43** (42.2%) |
| Failing | 59 |
| Total expected lines | 4541 |
| Matching lines | 2254 (49.6%) |
| Mismatched lines | 2287 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 58 | 98.3% |
| Compile Fail | 1 | 1.7% |

## Passing Tests

**33 tests passing**

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
| 10 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.2s |  |
| 11 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.2s |  |
| 12 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.2s |  |
| 14 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 15 | `getTimer_test` | 8 | 0.2s |  |
| 16 | `get_frame_number_test` | 31 | 0.3s |  |
| 17 | `instanceNameTest` | 5 | 0.2s |  |
| 18 | `loop/loop_test4` | 22 | 0.3s |  |
| 19 | `loop/loop_test5` | 24 | 0.2s |  |
| 20 | `loop/loop_test9` | 15 | 0.2s |  |
| 21 | `loop/simple_loop_test` | 0 | 0.2s |  |
| 22 | `masks_test2` | 10 | 0.2s |  |
| 23 | `morph_test1` | 0 | 0.2s |  |
| 24 | `move_object_test` | 11 | 0.2s |  |
| 25 | `multi_doactions_and_goto_frame_test` | 6 | 0.2s |  |
| 26 | `place_and_remove_object_test` | 13 | 0.2s |  |
| 27 | `reverse_execute_PlaceObject2_test1` | 8 | 0.2s |  |
| 28 | `reverse_execute_PlaceObject2_test2` | 10 | 0.2s |  |
| 29 | `runtime_vm_stack_test` | 9 | 0.2s |  |
| 30 | `shape_test` | 21 | 0.2s |  |
| 31 | `static_vs_dynamic2` | 18 | 1.2s |  |
| 32 | `timeline_var_test` | 11 | 1.3s |  |
| 33 | `unload_movieclip_test1` | 6 | 0.7s |  |

## Ruffle-Matched Tests

**10 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 0.2s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.2s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 0.2s |  |
| 4 | `attachExtImported` | 1 | 1 | 0.3s |  |
| 5 | `callFunction_test` | 5 | 11 | 0.2s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 0.2s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 0.3s |  |
| 8 | `path_format_test` | 27 | 28 | 0.3s |  |
| 9 | `place_object_test` | 14 | 14 | 0.2s |  |
| 10 | `place_object_test2` | 16 | 23 | 0.2s |  |

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

**58 tests** with output mismatch, sorted by match rate (best first)

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
| 38 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 39 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 40 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 41 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 42 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 43 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 44 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 45 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 46 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 47 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 48 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 49 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 50 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 51 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 52 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 53 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 54 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 55 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 56 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 57 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 58 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
