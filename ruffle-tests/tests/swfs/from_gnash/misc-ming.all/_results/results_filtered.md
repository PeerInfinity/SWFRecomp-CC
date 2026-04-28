# Ruffle Test Results (Filtered)

**Date**: 2026-04-28 20:29 UTC

**Git SHA**: `3c8bd2266c`

**Run Duration**: 23m 8s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **53** (52.0%) |
| Ruffle-matched | 13 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **66** (64.7%) |
| Failing | 36 |
| Total expected lines | 4541 |
| Matching lines | 2683 (59.1%) |
| Mismatched lines | 1858 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 35 | 97.2% |
| Compile Fail | 1 | 2.8% |

## Passing Tests

**53 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 16.9s |  |
| 2 | `DefineEditTextTest` | 153 | 17.7s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 17.6s |  |
| 4 | `PlaceObject2Test` | 9 | 18.6s |  |
| 5 | `ResolveEventsTest` | 15 | 0.4s |  |
| 6 | `RollOverOutTest` | 5 | 18.9s |  |
| 7 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 8 | `Video-EmbedSquareTest` | 2 | 16.9s |  |
| 9 | `action_order/action_execution_order_test1` | 10 | 16.7s |  |
| 10 | `action_order/action_execution_order_test3` | 4 | 16.6s |  |
| 11 | `action_order/action_execution_order_test7` | 7 | 13.0s |  |
| 12 | `action_order/action_execution_order_test8-v5` | 11 | 13.0s |  |
| 13 | `action_order/action_execution_order_test8-v6` | 11 | 0.2s |  |
| 14 | `action_order/action_execution_order_test9` | 4 | 16.4s |  |
| 15 | `attachExtImported` | 2 | 17.2s |  |
| 16 | `attachImported` | 2 | 0.3s |  |
| 17 | `attachMovieLoopingTest` | 41 | 17.7s |  |
| 18 | `attachMovieTest` | 12 | 17.3s |  |
| 19 | `consecutive_goto_frame_test` | 12 | 17.4s |  |
| 20 | `displaylist_depths/displaylist_depths_test10` | 10 | 16.6s |  |
| 21 | `displaylist_depths/displaylist_depths_test11` | 15 | 16.6s |  |
| 22 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.0s |  |
| 23 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 24 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 25 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 26 | `event_handler_scope_test` | 16 | 17.3s |  |
| 27 | `getTimer_test` | 8 | 16.9s |  |
| 28 | `get_frame_number_test` | 31 | 17.1s |  |
| 29 | `goto_frame_test` | 15 | 16.7s |  |
| 30 | `instanceNameTest` | 5 | 0.2s |  |
| 31 | `loop/loop_test2` | 15 | 17.0s |  |
| 32 | `loop/loop_test3` | 16 | 17.0s |  |
| 33 | `loop/loop_test4` | 22 | 17.2s |  |
| 34 | `loop/loop_test5` | 24 | 0.3s |  |
| 35 | `loop/loop_test8` | 38 | 16.9s |  |
| 36 | `loop/loop_test9` | 15 | 17.0s |  |
| 37 | `loop/simple_loop_test` | 0 | 17.0s |  |
| 38 | `masks_test2` | 10 | 16.7s |  |
| 39 | `morph_test1` | 0 | 17.0s |  |
| 40 | `move_object_test` | 11 | 16.0s |  |
| 41 | `multi_doactions_and_goto_frame_test` | 6 | 16.0s |  |
| 42 | `new_child_in_unload_test` | 11 | 16.0s |  |
| 43 | `place_and_remove_object_insane_test` | 22 | 17.2s |  |
| 44 | `place_and_remove_object_test` | 13 | 16.4s |  |
| 45 | `register_class/RegisterClassTest3` | 12 | 16.4s |  |
| 46 | `register_class/registerClassTest` | 51 | 16.8s |  |
| 47 | `reverse_execute_PlaceObject2_test1` | 8 | 17.1s |  |
| 48 | `reverse_execute_PlaceObject2_test2` | 10 | 17.8s |  |
| 49 | `runtime_vm_stack_test` | 9 | 17.2s |  |
| 50 | `shape_test` | 21 | 17.1s |  |
| 51 | `static_vs_dynamic1` | 17 | 16.9s |  |
| 52 | `static_vs_dynamic2` | 18 | 18.6s |  |
| 53 | `unload_movieclip_test1` | 6 | 17.6s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 16.8s |  |
| 2 | `DefineTextTest` | 4 | 4 | 17.5s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 16.6s |  |
| 4 | `action_order/action_execution_order_test4` | 6 | 26 | 0.3s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 13.0s |  |
| 6 | `callFunction_test` | 5 | 11 | 17.5s |  |
| 7 | `init_action/InitActionTest` | 8 | 17 | 17.2s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 17.0s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 17.0s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 11 | `path_format_test` | 27 | 28 | 17.2s |  |
| 12 | `place_object_test` | 14 | 14 | 16.4s |  |
| 13 | `place_object_test2` | 16 | 23 | 16.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

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
| 10 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**35 tests** with output mismatch, sorted by match rate (best first)

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
| 10 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 12 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 13 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 14 | `displaylist_depths/displaylist_depths_test8` | 43.8% | 7/16 | 16 | 15 |  |
| 15 | `action_order/action_execution_order_test5` | 42.6% | 26/61 | 61 | 35 |  |
| 16 | `loop/loop_test6` | 41.7% | 10/24 | 24 | 23 |  |
| 17 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 18 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 19 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 20 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 21 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 22 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 23 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 24 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 25 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 26 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 27 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 28 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 29 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 30 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 31 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 32 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 33 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 34 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 35 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
