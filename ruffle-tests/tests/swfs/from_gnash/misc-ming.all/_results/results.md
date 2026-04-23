# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-23 00:28 UTC

**Git SHA**: `2234cc5a3d`

**Run Duration**: 0m 57s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **27** (26.5%) |
| Ruffle-matched | 11 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **38** (37.3%) |
| Failing | 64 |
| Total expected lines | 4541 |
| Matching lines | 2228 (49.1%) |
| Mismatched lines | 2313 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 63 | 98.4% |
| Compile Fail | 1 | 1.6% |

## Passing Tests

**27 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 0.9s |  |
| 2 | `PlaceObject2Test` | 9 | 0.4s |  |
| 3 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 4 | `Video-EmbedSquareTest` | 2 | 0.4s |  |
| 5 | `action_order/action_execution_order_test1` | 10 | 0.4s |  |
| 6 | `action_order/action_execution_order_test7` | 7 | 0.4s |  |
| 7 | `action_order/action_execution_order_test9` | 4 | 0.4s |  |
| 8 | `attachMovieTest` | 12 | 0.4s |  |
| 9 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.3s |  |
| 11 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.4s |  |
| 12 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.4s |  |
| 13 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.4s |  |
| 14 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.4s |  |
| 15 | `getTimer_test` | 8 | 0.4s |  |
| 16 | `get_frame_number_test` | 31 | 0.5s |  |
| 17 | `loop/loop_test9` | 15 | 0.4s |  |
| 18 | `loop/simple_loop_test` | 0 | 0.4s |  |
| 19 | `masks_test2` | 10 | 0.4s |  |
| 20 | `morph_test1` | 0 | 0.4s |  |
| 21 | `move_object_test` | 11 | 0.3s |  |
| 22 | `multi_doactions_and_goto_frame_test` | 6 | 0.6s |  |
| 23 | `place_and_remove_object_test` | 13 | 0.4s |  |
| 24 | `shape_test` | 21 | 0.5s |  |
| 25 | `static_vs_dynamic2` | 18 | 0.4s |  |
| 26 | `timeline_var_test` | 11 | 0.4s |  |
| 27 | `unload_movieclip_test1` | 6 | 0.4s |  |

## Ruffle-Matched Tests

**11 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 0.5s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.5s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 0.5s |  |
| 4 | `attachExtImported` | 1 | 1 | 0.5s |  |
| 5 | `callFunction_test` | 5 | 11 | 0.4s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 0.4s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 0.5s |  |
| 8 | `path_format_test` | 27 | 28 | 0.6s |  |
| 9 | `place_object_test` | 14 | 14 | 0.4s |  |
| 10 | `place_object_test2` | 16 | 23 | 0.4s |  |
| 11 | `runtime_vm_stack_test` | 5 | 8 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**27 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loop/loop_test5` | 87.5% | 21 | 24 | 3 |  |
| 2 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
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
| 24 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 25 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 26 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |
| 27 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**63 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loop/loop_test5` | 87.5% | 21/24 | 24 | 24 |  |
| 2 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
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
| 24 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 25 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 26 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 27 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 28 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 29 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 30 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 31 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 32 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 33 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 34 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 35 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 36 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 37 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 38 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 39 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 40 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 41 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 42 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 43 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 44 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 45 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 46 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 47 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 48 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 49 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 50 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 51 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 52 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 53 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 54 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 55 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 56 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 57 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 58 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 59 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 60 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 61 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 62 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 63 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
