# Ruffle Test Results (Filtered)

**Date**: 2026-04-24 18:47 UTC

**Git SHA**: `d9038a2e66`

**Run Duration**: 27m 59s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **38** (37.3%) |
| Ruffle-matched | 10 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **48** (47.1%) |
| Failing | 54 |
| Total expected lines | 4541 |
| Matching lines | 2281 (50.2%) |
| Mismatched lines | 2260 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 53 | 98.1% |
| Compile Fail | 1 | 1.9% |

## Passing Tests

**38 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `DefineEditTextTest` | 153 | 26.5s |  |
| 2 | `DefineEditTextVariableNameTest2` | 39 | 21.1s |  |
| 3 | `PlaceObject2Test` | 9 | 19.1s |  |
| 4 | `VarAndCharClashTest` | 13 | 1.6s |  |
| 5 | `Video-EmbedSquareTest` | 2 | 18.4s |  |
| 6 | `action_order/action_execution_order_test1` | 10 | 18.3s |  |
| 7 | `action_order/action_execution_order_test7` | 7 | 17.6s |  |
| 8 | `action_order/action_execution_order_test8-v5` | 11 | 18.0s |  |
| 9 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 10 | `action_order/action_execution_order_test9` | 4 | 17.7s |  |
| 11 | `attachMovieTest` | 12 | 19.0s |  |
| 12 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.7s |  |
| 13 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.8s |  |
| 14 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.6s |  |
| 15 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.7s |  |
| 16 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.6s |  |
| 17 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 18 | `getTimer_test` | 8 | 14.2s |  |
| 19 | `get_frame_number_test` | 31 | 15.9s |  |
| 20 | `instanceNameTest` | 5 | 1.5s |  |
| 21 | `loop/loop_test4` | 22 | 18.7s |  |
| 22 | `loop/loop_test5` | 24 | 2.6s |  |
| 23 | `loop/loop_test9` | 15 | 17.4s |  |
| 24 | `loop/simple_loop_test` | 0 | 17.0s |  |
| 25 | `masks_test2` | 10 | 19.3s |  |
| 26 | `morph_test1` | 0 | 18.4s |  |
| 27 | `move_object_test` | 11 | 17.7s |  |
| 28 | `multi_doactions_and_goto_frame_test` | 6 | 17.6s |  |
| 29 | `new_child_in_unload_test` | 11 | 17.8s |  |
| 30 | `place_and_remove_object_test` | 13 | 17.9s |  |
| 31 | `reverse_execute_PlaceObject2_test1` | 8 | 18.1s |  |
| 32 | `reverse_execute_PlaceObject2_test2` | 10 | 18.1s |  |
| 33 | `runtime_vm_stack_test` | 9 | 18.6s |  |
| 34 | `shape_test` | 21 | 19.7s |  |
| 35 | `static_vs_dynamic1` | 17 | 18.2s |  |
| 36 | `static_vs_dynamic2` | 18 | 18.1s |  |
| 37 | `timeline_var_test` | 11 | 17.9s |  |
| 38 | `unload_movieclip_test1` | 6 | 17.6s |  |

## Ruffle-Matched Tests

**10 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 18.5s |  |
| 2 | `action_order/action_execution_order_test4` | 8 | 26 | 2.7s |  |
| 3 | `action_order/action_execution_order_test6` | 19 | 21 | 18.7s |  |
| 4 | `attachExtImported` | 1 | 1 | 18.9s |  |
| 5 | `callFunction_test` | 5 | 11 | 19.0s |  |
| 6 | `init_action/InitActionTest` | 17 | 17 | 17.7s |  |
| 7 | `init_action/InitActionTest2` | 30 | 30 | 18.7s |  |
| 8 | `path_format_test` | 27 | 28 | 20.4s |  |
| 9 | `place_object_test` | 14 | 14 | 18.4s |  |
| 10 | `place_object_test2` | 16 | 23 | 18.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**18 tests** within reach

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
| 11 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 12 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 13 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 14 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 15 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 16 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 18 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**53 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 12 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 13 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 14 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 15 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 16 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 17 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 18 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 19 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 20 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 21 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 22 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 23 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 24 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 25 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 26 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 27 | `goto_frame_test` | 26.7% | 4/15 | 13 | 15 |  |
| 28 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 29 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 30 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 31 | `consecutive_goto_frame_test` | 21.4% | 3/14 | 14 | 12 |  |
| 32 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 33 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 34 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 35 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 36 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 37 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 38 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 39 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 40 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 41 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 42 | `action_order/ActionOrderTest4` | 8.2% | 10/122 | 122 | 64 |  |
| 43 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 44 | `action_order/ActionOrderTest3` | 4.8% | 5/104 | 104 | 62 |  |
| 45 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 46 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 47 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 48 | `opcode_guard_test` | 2.0% | 3/152 | 152 | 18 |  |
| 49 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 50 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 51 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 52 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 53 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
