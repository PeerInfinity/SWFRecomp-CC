# Ruffle Test Results (Filtered)

**Date**: 2026-04-24 17:11 UTC

**Git SHA**: `d4c3b8d81d`

**Run Duration**: 22m 41s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **37** (36.3%) |
| Ruffle-matched | 10 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **47** (46.1%) |
| Failing | 55 |
| Total expected lines | 4541 |
| Matching lines | 2277 (50.1%) |
| Mismatched lines | 2264 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 54 | 98.2% |
| Compile Fail | 1 | 1.8% |

## Passing Tests

**37 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 16.9s |  |
| 2 | `DefineEditTextVariableNameTest2` | 39 | 17.4s |  |
| 3 | `PlaceObject2Test` | 9 | 16.9s |  |
| 4 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 5 | `Video-EmbedSquareTest` | 2 | 16.4s |  |
| 6 | `action_order/action_execution_order_test1` | 10 | 12.8s |  |
| 7 | `action_order/action_execution_order_test7` | 7 | 16.2s |  |
| 8 | `action_order/action_execution_order_test8-v5` | 11 | 16.3s |  |
| 9 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 10 | `action_order/action_execution_order_test9` | 4 | 16.8s |  |
| 11 | `attachMovieTest` | 12 | 17.2s |  |
| 12 | `displaylist_depths/displaylist_depths_test10` | 10 | 16.4s |  |
| 13 | `displaylist_depths/displaylist_depths_test11` | 15 | 16.6s |  |
| 14 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.4s |  |
| 15 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 16 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 17 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 18 | `getTimer_test` | 8 | 15.8s |  |
| 19 | `get_frame_number_test` | 31 | 15.9s |  |
| 20 | `instanceNameTest` | 5 | 0.3s |  |
| 21 | `loop/loop_test4` | 22 | 13.5s |  |
| 22 | `loop/loop_test5` | 24 | 0.3s |  |
| 23 | `loop/loop_test9` | 15 | 16.0s |  |
| 24 | `loop/simple_loop_test` | 0 | 16.4s |  |
| 25 | `masks_test2` | 10 | 16.0s |  |
| 26 | `morph_test1` | 0 | 16.3s |  |
| 27 | `move_object_test` | 11 | 16.4s |  |
| 28 | `multi_doactions_and_goto_frame_test` | 6 | 16.4s |  |
| 29 | `place_and_remove_object_test` | 13 | 16.9s |  |
| 30 | `reverse_execute_PlaceObject2_test1` | 8 | 16.4s |  |
| 31 | `reverse_execute_PlaceObject2_test2` | 10 | 16.4s |  |
| 32 | `runtime_vm_stack_test` | 9 | 17.3s |  |
| 33 | `shape_test` | 21 | 17.3s |  |
| 34 | `static_vs_dynamic1` | 17 | 17.2s |  |
| 35 | `static_vs_dynamic2` | 18 | 17.7s |  |
| 36 | `timeline_var_test` | 11 | 17.6s |  |
| 37 | `unload_movieclip_test1` | 6 | 17.7s |  |

## Ruffle-Matched Tests

**10 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 16.0s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 0.4s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 16.3s |  |
| 4 | `attachExtImported` | 1 | 1 | 17.6s |  |
| 5 | `callFunction_test` | 5 | 11 | 17.5s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 16.5s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 16.6s |  |
| 8 | `path_format_test` | 27 | 28 | 16.8s |  |
| 9 | `place_object_test` | 14 | 14 | 17.2s |  |
| 10 | `place_object_test2` | 16 | 23 | 16.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**19 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 84.0% | 912 | 1086 | 174 |  |
| 2 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 3 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84 | 111 | 27 |  |
| 4 | `loop/loop_test7` | 73.3% | 11 | 15 | 4 |  |
| 5 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 6 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 7 | `event_handler_scope_test` | 68.8% | 11 | 16 | 5 |  |
| 8 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 9 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 10 | `DepthLimitsTest` | 65.0% | 13 | 20 | 7 |  |
| 11 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 12 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 13 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 14 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 15 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 16 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 17 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 18 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 19 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**54 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 84.0% | 912/1086 | 1086 | 1086 |  |
| 2 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 3 | `displaylist_depths/displaylist_depths_test` | 75.7% | 84/111 | 111 | 111 |  |
| 4 | `loop/loop_test7` | 73.3% | 11/15 | 14 | 15 |  |
| 5 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 6 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 7 | `event_handler_scope_test` | 68.8% | 11/16 | 16 | 16 |  |
| 8 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 9 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 10 | `DepthLimitsTest` | 65.0% | 13/20 | 20 | 20 |  |
| 11 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 12 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 13 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 14 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 15 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 16 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 17 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 18 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 19 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 20 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 21 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 22 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 23 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 24 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 25 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 26 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 27 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 28 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 29 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 30 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 31 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 32 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 33 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 34 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 35 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 36 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 37 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 38 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 39 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 40 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 41 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 42 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 43 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 44 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 45 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 46 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 47 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 48 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 49 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 50 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 51 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 52 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 53 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 54 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
