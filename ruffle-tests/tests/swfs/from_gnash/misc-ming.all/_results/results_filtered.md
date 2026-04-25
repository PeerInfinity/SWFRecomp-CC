# Ruffle Test Results (Filtered)

**Date**: 2026-04-25 16:17 UTC

**Git SHA**: `a815e18bbb`

**Run Duration**: 0m 34s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **42** (41.2%) |
| Ruffle-matched | 10 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **52** (51.0%) |
| Failing | 50 |
| Total expected lines | 4541 |
| Matching lines | 2324 (51.2%) |
| Mismatched lines | 2217 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 49 | 98.0% |
| Compile Fail | 1 | 2.0% |

## Passing Tests

**42 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 0.7s |  |
| 2 | `DefineEditTextVariableNameTest2` | 39 | 0.2s |  |
| 3 | `PlaceObject2Test` | 9 | 0.2s |  |
| 4 | `ResolveEventsTest` | 15 | 0.2s |  |
| 5 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 6 | `Video-EmbedSquareTest` | 2 | 0.2s |  |
| 7 | `action_order/action_execution_order_test1` | 10 | 0.2s |  |
| 8 | `action_order/action_execution_order_test7` | 7 | 0.2s |  |
| 9 | `action_order/action_execution_order_test8-v5` | 11 | 0.2s |  |
| 10 | `action_order/action_execution_order_test8-v6` | 11 | 0.2s |  |
| 11 | `action_order/action_execution_order_test9` | 4 | 0.2s |  |
| 12 | `attachMovieTest` | 12 | 0.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.2s |  |
| 14 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.2s |  |
| 15 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.2s |  |
| 16 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.2s |  |
| 17 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.2s |  |
| 18 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 19 | `event_handler_scope_test` | 16 | 0.2s |  |
| 20 | `getTimer_test` | 8 | 0.2s |  |
| 21 | `get_frame_number_test` | 31 | 0.3s |  |
| 22 | `instanceNameTest` | 5 | 0.2s |  |
| 23 | `loop/loop_test2` | 15 | 0.2s |  |
| 24 | `loop/loop_test3` | 16 | 0.1s |  |
| 25 | `loop/loop_test4` | 22 | 0.2s |  |
| 26 | `loop/loop_test5` | 24 | 0.2s |  |
| 27 | `loop/loop_test9` | 15 | 0.2s |  |
| 28 | `loop/simple_loop_test` | 0 | 0.2s |  |
| 29 | `masks_test2` | 10 | 0.2s |  |
| 30 | `morph_test1` | 0 | 0.2s |  |
| 31 | `move_object_test` | 11 | 0.2s |  |
| 32 | `multi_doactions_and_goto_frame_test` | 6 | 0.2s |  |
| 33 | `new_child_in_unload_test` | 11 | 0.2s |  |
| 34 | `place_and_remove_object_test` | 13 | 0.1s |  |
| 35 | `reverse_execute_PlaceObject2_test1` | 8 | 0.2s |  |
| 36 | `reverse_execute_PlaceObject2_test2` | 10 | 0.2s |  |
| 37 | `runtime_vm_stack_test` | 9 | 0.2s |  |
| 38 | `shape_test` | 21 | 0.2s |  |
| 39 | `static_vs_dynamic1` | 17 | 0.2s |  |
| 40 | `static_vs_dynamic2` | 18 | 0.2s |  |
| 41 | `timeline_var_test` | 11 | 0.2s |  |
| 42 | `unload_movieclip_test1` | 6 | 0.2s |  |

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
| 10 | `place_object_test2` | 16 | 23 | 0.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**15 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loop/loop_test8` | 97.4% | 37 | 38 | 1 |  |
| 2 | `matrix_test` | 84.0% | 912 | 1086 | 174 |  |
| 3 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 4 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 5 | `loop/loop_test7` | 73.3% | 11 | 15 | 4 |  |
| 6 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 7 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 8 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 9 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 10 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 11 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 12 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 13 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 15 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**49 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loop/loop_test8` | 97.4% | 37/38 | 37 | 38 |  |
| 2 | `matrix_test` | 84.0% | 912/1086 | 1086 | 1086 |  |
| 3 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 4 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 5 | `loop/loop_test7` | 73.3% | 11/15 | 14 | 15 |  |
| 6 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 7 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 8 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 9 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 10 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 11 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 12 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 13 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 14 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 15 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 17 | `DrawingApiTest` | 45.3% | 43/95 | 95 | 93 |  |
| 18 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 19 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 20 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 21 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 22 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 23 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 24 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 25 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 26 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 27 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 28 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 29 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 30 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 31 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 32 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 33 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 34 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 35 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 36 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 37 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 38 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 39 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 40 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 41 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 42 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 43 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 44 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 45 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 46 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 47 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 48 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 49 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
