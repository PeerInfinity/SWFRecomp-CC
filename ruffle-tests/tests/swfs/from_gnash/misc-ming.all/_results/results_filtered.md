# Ruffle Test Results (Filtered)

**Date**: 2026-04-20 20:43 UTC

**Git SHA**: `a427f5fc2d`

**Run Duration**: 25m 51s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 99 |
| Passing | **17** (17.2%) |
| Ruffle-matched | 10 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **27** (27.3%) |
| Failing | 72 |
| Total expected lines | 4487 |
| Matching lines | 2109 (47.0%) |
| Mismatched lines | 2378 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 71 | 98.6% |
| Compile Fail | 1 | 1.4% |

## Passing Tests

**17 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `PlaceObject2Test` | 9 | 17.1s |  |
| 2 | `VarAndCharClashTest` | 13 | 1.2s |  |
| 3 | `Video-EmbedSquareTest` | 2 | 16.8s |  |
| 4 | `action_order/action_execution_order_test1` | 10 | 17.8s |  |
| 5 | `action_order/action_execution_order_test7` | 7 | 16.9s |  |
| 6 | `action_order/action_execution_order_test9` | 4 | 19.4s |  |
| 7 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.2s |  |
| 8 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.3s |  |
| 9 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.3s |  |
| 11 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.7s |  |
| 12 | `loop/simple_loop_test` | 0 | 16.5s |  |
| 13 | `masks_test2` | 10 | 18.2s |  |
| 14 | `morph_test1` | 0 | 19.7s |  |
| 15 | `move_object_test` | 11 | 17.1s |  |
| 16 | `multi_doactions_and_goto_frame_test` | 6 | 17.0s |  |
| 17 | `unload_movieclip_test1` | 6 | 17.6s |  |

## Ruffle-Matched Tests

**10 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `KeyEventOrder` | 20 | 23 | 17.0s |  |
| 2 | `action_order/action_execution_order_test4` | 14 | 26 | 2.5s |  |
| 3 | `attachExtImported` | 1 | 1 | 20.8s |  |
| 4 | `callFunction_test` | 5 | 11 | 18.1s |  |
| 5 | `init_action/InitActionTest` | 17 | 17 | 17.9s |  |
| 6 | `init_action/InitActionTest2` | 30 | 30 | 18.5s |  |
| 7 | `path_format_test` | 28 | 28 | 19.1s |  |
| 8 | `place_object_test` | 14 | 14 | 17.9s |  |
| 9 | `place_object_test2` | 16 | 23 | 18.1s |  |
| 10 | `runtime_vm_stack_test` | 5 | 8 | 17.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**32 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DefineEditTextTest` | 95.4% | 146 | 153 | 7 |  |
| 2 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 3 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 4 | `place_and_remove_object_test` | 76.9% | 10 | 13 | 3 |  |
| 5 | `attachMovieTest` | 75.0% | 9 | 12 | 3 |  |
| 6 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 7 | `loop/loop_test9` | 73.3% | 11 | 15 | 4 |  |
| 8 | `action_order/action_execution_order_test8-v5` | 72.7% | 8 | 11 | 3 |  |
| 9 | `action_order/action_execution_order_test8-v6` | 72.7% | 8 | 11 | 3 |  |
| 10 | `timeline_var_test` | 72.7% | 8 | 11 | 3 |  |
| 11 | `static_vs_dynamic2` | 72.2% | 13 | 18 | 5 |  |
| 12 | `shape_test` | 71.4% | 15 | 21 | 6 |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 71.2% | 79 | 111 | 32 |  |
| 14 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 15 | `static_vs_dynamic1` | 70.6% | 12 | 17 | 5 |  |
| 16 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 17 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 18 | `loop/loop_test3` | 68.8% | 11 | 16 | 5 |  |
| 19 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 20 | `new_child_in_unload_test` | 63.6% | 7 | 11 | 4 |  |
| 21 | `event_handler_scope_test` | 62.5% | 10 | 16 | 6 |  |
| 22 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 23 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 24 | `DepthLimitsTest` | 60.0% | 12 | 20 | 8 |  |
| 25 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 26 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 27 | `loop/loop_test8` | 52.6% | 20 | 38 | 18 |  |
| 28 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 29 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9 | 18 | 9 |  |
| 30 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16 | 32 | 16 |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8 | 16 | 8 |  |
| 32 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**71 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DefineEditTextTest` | 95.4% | 146/153 | 153 | 153 |  |
| 2 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 3 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 4 | `place_and_remove_object_test` | 76.9% | 10/13 | 13 | 13 |  |
| 5 | `attachMovieTest` | 75.0% | 9/12 | 12 | 12 |  |
| 6 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 7 | `loop/loop_test9` | 73.3% | 11/15 | 15 | 15 |  |
| 8 | `action_order/action_execution_order_test8-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 9 | `action_order/action_execution_order_test8-v6` | 72.7% | 8/11 | 11 | 11 |  |
| 10 | `timeline_var_test` | 72.7% | 8/11 | 11 | 11 |  |
| 11 | `static_vs_dynamic2` | 72.2% | 13/18 | 18 | 18 |  |
| 12 | `shape_test` | 71.4% | 15/21 | 21 | 21 |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 71.2% | 79/111 | 111 | 111 |  |
| 14 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 15 | `static_vs_dynamic1` | 70.6% | 12/17 | 17 | 17 |  |
| 16 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 17 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 18 | `loop/loop_test3` | 68.8% | 11/16 | 16 | 16 |  |
| 19 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 20 | `new_child_in_unload_test` | 63.6% | 7/11 | 11 | 11 |  |
| 21 | `event_handler_scope_test` | 62.5% | 10/16 | 16 | 16 |  |
| 22 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 23 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 24 | `DepthLimitsTest` | 60.0% | 12/20 | 20 | 20 |  |
| 25 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 26 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 27 | `loop/loop_test8` | 52.6% | 20/38 | 38 | 38 |  |
| 28 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 29 | `displaylist_depths/displaylist_depths_test11` | 50.0% | 9/18 | 18 | 15 |  |
| 30 | `displaylist_depths/displaylist_depths_test3` | 50.0% | 16/32 | 29 | 32 |  |
| 31 | `displaylist_depths/displaylist_depths_test8` | 50.0% | 8/16 | 16 | 15 |  |
| 32 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 33 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 34 | `loop/loop_test5` | 48.0% | 12/25 | 25 | 24 |  |
| 35 | `DrawingApiTest` | 46.2% | 43/93 | 93 | 93 |  |
| 36 | `loop/loop_test4` | 45.5% | 10/22 | 22 | 22 |  |
| 37 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 38 | `action_order/action_execution_order_test11` | 37.5% | 12/32 | 32 | 32 |  |
| 39 | `action_order/action_execution_order_test5` | 36.1% | 22/61 | 61 | 35 |  |
| 40 | `loop/loop_test2` | 35.3% | 6/17 | 17 | 15 |  |
| 41 | `DragDropTest` | 33.3% | 15/45 | 45 | 44 |  |
| 42 | `loop/loop_test` | 33.3% | 7/21 | 21 | 21 |  |
| 43 | `consecutive_goto_frame_test` | 30.8% | 4/13 | 13 | 12 |  |
| 44 | `loop/loop_test7` | 26.7% | 4/15 | 14 | 15 |  |
| 45 | `action_order/action_execution_order_test3` | 25.0% | 1/4 | 4 | 4 |  |
| 46 | `loop/loop_test6` | 25.0% | 6/24 | 24 | 23 |  |
| 47 | `action_order/action_execution_order_test6` | 20.8% | 5/24 | 19 | 24 |  |
| 48 | `register_class/registerClassTest2` | 20.5% | 9/44 | 43 | 44 |  |
| 49 | `action_order/action_execution_order_test2` | 20.0% | 1/5 | 5 | 5 |  |
| 50 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 51 | `replace_sprites1test` | 19.2% | 5/26 | 26 | 21 |  |
| 52 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 53 | `action_order/ActionOrderTest5` | 15.0% | 9/60 | 60 | 51 |  |
| 54 | `register_class/RegisterClassTest3` | 14.3% | 2/14 | 14 | 12 |  |
| 55 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 56 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 57 | `register_class/RegisterClassTest4` | 11.8% | 8/68 | 68 | 42 |  |
| 58 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 59 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 60 | `action_order/ActionOrderTest4` | 7.4% | 9/122 | 122 | 64 |  |
| 61 | `loading/loadMovieTest` | 6.2% | 5/80 | 5 | 80 |  |
| 62 | `action_order/ActionOrderTest3` | 5.7% | 6/105 | 105 | 62 |  |
| 63 | `opcode_guard_test` | 4.9% | 3/61 | 61 | 18 |  |
| 64 | `register_class/registerClassTest` | 3.9% | 2/51 | 50 | 51 |  |
| 65 | `loop/loop_test10` | 3.6% | 1/28 | 20 | 28 |  |
| 66 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 67 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 68 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 69 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 70 | `replace_buttons1test` | 0.0% | 0/27 | 27 | 18 |  |
| 71 | `replace_shapes1test` | 0.0% | 0/29 | 29 | 23 |  |
