# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-22 22:48 UTC

**Git SHA**: `e0ddd339fb`

**Run Duration**: 1m 23s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **25** (24.5%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **36** (35.3%) |
| Failing | 66 |
| Total expected lines | 4541 |
| Matching lines | 2211 (48.7%) |
| Mismatched lines | 2330 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 65 | 98.5% |
| Compile Fail | 1 | 1.5% |

## Passing Tests

**25 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 0.7s |  |
| 2 | `PlaceObject2Test` | 9 | 0.2s |  |
| 3 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 4 | `Video-EmbedSquareTest` | 2 | 0.2s |  |
| 5 | `action_order/action_execution_order_test1` | 10 | 0.2s |  |
| 6 | `action_order/action_execution_order_test7` | 7 | 0.1s |  |
| 7 | `action_order/action_execution_order_test9` | 4 | 0.2s |  |
| 8 | `attachMovieTest` | 12 | 0.2s |  |
| 9 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.1s |  |
| 10 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.2s |  |
| 11 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.2s |  |
| 12 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.2s |  |
| 13 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 14 | `getTimer_test` | 8 | 0.2s |  |
| 15 | `get_frame_number_test` | 31 | 0.3s |  |
| 16 | `loop/loop_test9` | 15 | 0.2s |  |
| 17 | `loop/simple_loop_test` | 0 | 0.2s |  |
| 18 | `masks_test2` | 10 | 0.2s |  |
| 19 | `morph_test1` | 0 | 0.2s |  |
| 20 | `move_object_test` | 11 | 0.2s |  |
| 21 | `multi_doactions_and_goto_frame_test` | 6 | 0.2s |  |
| 22 | `place_and_remove_object_test` | 13 | 0.2s |  |
| 23 | `shape_test` | 21 | 0.3s |  |
| 24 | `timeline_var_test` | 11 | 0.2s |  |
| 25 | `unload_movieclip_test1` | 6 | 0.2s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 0.2s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.2s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 0.2s |  |
| 4 | `attachExtImported` | 1 | 1 | 0.3s |  |
| 5 | `callFunction_test` | 5 | 11 | 0.2s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 0.2s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 0.3s |  |
| 8 | `path_format_test` | 27 | 28 | 0.4s |  |
| 9 | `place_object_test` | 14 | 14 | 0.2s |  |
| 10 | `place_object_test2` | 16 | 23 | 0.2s |  |
| 11 | `runtime_vm_stack_test` | 5 | 8 | 0.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**29 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15 | 18 | 3 |  |
| 3 | `static_vs_dynamic1` | 82.4% | 14 | 17 | 3 |  |
| 4 | `loop/loop_test4` | 81.8% | 18 | 22 | 4 |  |
| 5 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 7 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 8 | `action_order/action_execution_order_test8-v5` | 72.7% | 8 | 11 | 3 |  |
| 9 | `action_order/action_execution_order_test8-v6` | 72.7% | 8 | 11 | 3 |  |
| 10 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 11 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 12 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 13 | `event_handler_scope_test` | 68.8% | 11 | 16 | 5 |  |
| 14 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 15 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 16 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 17 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 18 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 19 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 20 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 21 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 22 | `loop/loop_test7` | 53.3% | 8 | 15 | 7 |  |
| 23 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 24 | `loop/loop_test5` | 52.0% | 13 | 25 | 12 |  |
| 25 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9 | 18 | 9 |  |
| 27 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 28 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |
| 29 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**65 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 2 | `static_vs_dynamic2` | 83.3% | 15/18 | 18 | 18 |  |
| 3 | `static_vs_dynamic1` | 82.4% | 14/17 | 17 | 17 |  |
| 4 | `loop/loop_test4` | 81.8% | 18/22 | 22 | 22 |  |
| 5 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 7 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 8 | `action_order/action_execution_order_test8-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 9 | `action_order/action_execution_order_test8-v6` | 72.7% | 8/11 | 11 | 11 |  |
| 10 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 11 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 12 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 13 | `event_handler_scope_test` | 68.8% | 11/16 | 16 | 16 |  |
| 14 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 15 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 16 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 17 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 18 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 19 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 20 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 21 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 22 | `loop/loop_test7` | 53.3% | 8/15 | 14 | 15 |  |
| 23 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 24 | `loop/loop_test5` | 52.0% | 13/25 | 25 | 24 |  |
| 25 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 26 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9/18 | 18 | 15 |  |
| 27 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 28 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 29 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 30 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 31 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 32 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 33 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 34 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 35 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 36 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 37 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 38 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 39 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 40 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 41 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 42 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 43 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 44 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 45 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 46 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 47 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 48 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 49 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 50 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 51 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 52 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 53 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 54 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 55 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 56 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 57 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 58 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 59 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 60 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 61 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 62 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 63 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 64 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 65 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
