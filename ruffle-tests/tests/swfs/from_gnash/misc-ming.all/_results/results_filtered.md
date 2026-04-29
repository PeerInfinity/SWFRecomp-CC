# Ruffle Test Results (Filtered)

**Date**: 2026-04-29 21:38 UTC

**Git SHA**: `4212ab6b8c`

**Run Duration**: 12m 45s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **55** (53.9%) |
| Ruffle-matched | 13 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **68** (66.7%) |
| Failing | 34 |
| Total expected lines | 4541 |
| Matching lines | 2694 (59.3%) |
| Mismatched lines | 1847 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 33 | 97.1% |
| Compile Fail | 1 | 2.9% |

## Passing Tests

**55 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 19.4s |  |
| 2 | `DefineEditTextTest` | 153 | 27.2s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 21.1s |  |
| 4 | `PlaceObject2Test` | 9 | 0.4s |  |
| 5 | `ResolveEventsTest` | 15 | 0.4s |  |
| 6 | `RollOverOutTest` | 5 | 0.4s |  |
| 7 | `VarAndCharClashTest` | 13 | 0.4s |  |
| 8 | `Video-EmbedSquareTest` | 2 | 0.4s |  |
| 9 | `action_order/action_execution_order_test1` | 10 | 0.4s |  |
| 10 | `action_order/action_execution_order_test2` | 5 | 0.4s |  |
| 11 | `action_order/action_execution_order_test3` | 4 | 0.4s |  |
| 12 | `action_order/action_execution_order_test7` | 7 | 0.4s |  |
| 13 | `action_order/action_execution_order_test8-v5` | 11 | 0.4s |  |
| 14 | `action_order/action_execution_order_test8-v6` | 11 | 0.2s |  |
| 15 | `action_order/action_execution_order_test9` | 4 | 0.4s |  |
| 16 | `attachExtImported` | 2 | 0.5s |  |
| 17 | `attachImported` | 2 | 0.4s |  |
| 18 | `attachMovieLoopingTest` | 41 | 0.4s |  |
| 19 | `attachMovieTest` | 12 | 0.4s |  |
| 20 | `consecutive_goto_frame_test` | 12 | 0.4s |  |
| 21 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.6s |  |
| 22 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.7s |  |
| 23 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.4s |  |
| 24 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.4s |  |
| 27 | `event_handler_scope_test` | 16 | 18.6s |  |
| 28 | `getTimer_test` | 8 | 19.1s |  |
| 29 | `get_frame_number_test` | 31 | 21.4s |  |
| 30 | `goto_frame_test` | 15 | 19.4s |  |
| 31 | `instanceNameTest` | 5 | 1.7s |  |
| 32 | `loop/loop_test2` | 15 | 0.3s |  |
| 33 | `loop/loop_test3` | 16 | 0.4s |  |
| 34 | `loop/loop_test4` | 22 | 0.4s |  |
| 35 | `loop/loop_test5` | 24 | 0.4s |  |
| 36 | `loop/loop_test8` | 38 | 0.4s |  |
| 37 | `loop/loop_test9` | 15 | 0.4s |  |
| 38 | `loop/simple_loop_test` | 0 | 0.4s |  |
| 39 | `masks_test2` | 10 | 0.4s |  |
| 40 | `morph_test1` | 0 | 0.4s |  |
| 41 | `move_object_test` | 11 | 17.8s |  |
| 42 | `multi_doactions_and_goto_frame_test` | 6 | 1.8s |  |
| 43 | `new_child_in_unload_test` | 11 | 17.6s |  |
| 44 | `place_and_remove_object_insane_test` | 22 | 2.2s |  |
| 45 | `place_and_remove_object_test` | 13 | 1.9s |  |
| 46 | `register_class/RegisterClassTest3` | 12 | 18.6s |  |
| 47 | `register_class/registerClassTest` | 51 | 20.6s |  |
| 48 | `reverse_execute_PlaceObject2_test1` | 8 | 18.9s |  |
| 49 | `reverse_execute_PlaceObject2_test2` | 10 | 19.3s |  |
| 50 | `runtime_vm_stack_test` | 9 | 18.7s |  |
| 51 | `shape_test` | 21 | 19.9s |  |
| 52 | `static_vs_dynamic1` | 17 | 18.2s |  |
| 53 | `static_vs_dynamic2` | 18 | 19.5s |  |
| 54 | `timeline_var_test` | 11 | 19.2s |  |
| 55 | `unload_movieclip_test1` | 6 | 19.1s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 18.3s |  |
| 2 | `DefineTextTest` | 4 | 4 | 18.9s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 0.4s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 0.5s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 0.4s |  |
| 6 | `callFunction_test` | 5 | 11 | 0.4s |  |
| 7 | `init_action/InitActionTest` | 6 | 17 | 2.3s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 19.7s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 0.5s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 11 | `path_format_test` | 27 | 28 | 20.6s |  |
| 12 | `place_object_test` | 14 | 14 | 19.3s |  |
| 13 | `place_object_test2` | 20 | 23 | 19.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**12 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 2 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 3 | `register_class/registerClassTest2` | 79.5% | 35 | 44 | 9 |  |
| 4 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 5 | `DrawingApiTest` | 67.4% | 64 | 95 | 31 |  |
| 6 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 7 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 8 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 9 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 10 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |
| 12 | `loop/loop_test6` | 50.0% | 12 | 24 | 12 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**33 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99/111 | 111 | 111 |  |
| 2 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 3 | `register_class/registerClassTest2` | 79.5% | 35/44 | 44 | 44 |  |
| 4 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 5 | `DrawingApiTest` | 67.4% | 64/95 | 95 | 93 |  |
| 6 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 7 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 8 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 9 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 10 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 12 | `loop/loop_test6` | 50.0% | 12/24 | 24 | 23 |  |
| 13 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 14 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 15 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 16 | `displaylist_depths/displaylist_depths_test8` | 43.8% | 7/16 | 16 | 15 |  |
| 17 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 18 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 19 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 20 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 21 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 22 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 23 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 24 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 25 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 26 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 27 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 28 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 29 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 30 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 31 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 32 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 33 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
