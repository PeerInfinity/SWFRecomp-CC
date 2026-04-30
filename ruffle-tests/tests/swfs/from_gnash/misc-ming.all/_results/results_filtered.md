# Ruffle Test Results (Filtered)

**Date**: 2026-04-30 03:16 UTC

**Git SHA**: `348a02b2ff`

**Run Duration**: 22m 32s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **55** (53.9%) |
| Ruffle-matched | 13 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **68** (66.7%) |
| Failing | 34 |
| Total expected lines | 4577 |
| Matching lines | 2744 (60.0%) |
| Mismatched lines | 1833 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 34 | 100.0% |

## Passing Tests

**55 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 16.8s |  |
| 2 | `DefineEditTextTest` | 153 | 17.0s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 16.4s |  |
| 4 | `PlaceObject2Test` | 9 | 14.8s |  |
| 5 | `ResolveEventsTest` | 15 | 0.3s |  |
| 6 | `RollOverOutTest` | 5 | 14.4s |  |
| 7 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 8 | `Video-EmbedSquareTest` | 2 | 16.8s |  |
| 9 | `action_order/action_execution_order_test1` | 10 | 18.1s |  |
| 10 | `action_order/action_execution_order_test2` | 5 | 14.3s |  |
| 11 | `action_order/action_execution_order_test3` | 4 | 14.4s |  |
| 12 | `action_order/action_execution_order_test7` | 7 | 16.3s |  |
| 13 | `action_order/action_execution_order_test8-v5` | 11 | 16.3s |  |
| 14 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 15 | `action_order/action_execution_order_test9` | 4 | 16.8s |  |
| 16 | `attachExtImported` | 2 | 16.9s |  |
| 17 | `attachImported` | 2 | 0.3s |  |
| 18 | `attachMovieLoopingTest` | 41 | 16.8s |  |
| 19 | `attachMovieTest` | 12 | 16.4s |  |
| 20 | `consecutive_goto_frame_test` | 12 | 16.4s |  |
| 21 | `displaylist_depths/displaylist_depths_test10` | 10 | 16.1s |  |
| 22 | `displaylist_depths/displaylist_depths_test11` | 15 | 16.1s |  |
| 23 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.5s |  |
| 24 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.2s |  |
| 26 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 27 | `event_handler_scope_test` | 16 | 17.2s |  |
| 28 | `getTimer_test` | 8 | 13.4s |  |
| 29 | `get_frame_number_test` | 31 | 13.4s |  |
| 30 | `goto_frame_test` | 15 | 13.5s |  |
| 31 | `instanceNameTest` | 5 | 0.3s |  |
| 32 | `loop/loop_test2` | 15 | 17.0s |  |
| 33 | `loop/loop_test3` | 16 | 18.3s |  |
| 34 | `loop/loop_test4` | 22 | 18.3s |  |
| 35 | `loop/loop_test5` | 24 | 0.4s |  |
| 36 | `loop/loop_test8` | 38 | 17.0s |  |
| 37 | `loop/loop_test9` | 15 | 17.8s |  |
| 38 | `loop/simple_loop_test` | 0 | 18.1s |  |
| 39 | `masks_test2` | 10 | 17.3s |  |
| 40 | `morph_test1` | 0 | 17.4s |  |
| 41 | `move_object_test` | 11 | 13.1s |  |
| 42 | `multi_doactions_and_goto_frame_test` | 6 | 13.1s |  |
| 43 | `new_child_in_unload_test` | 11 | 13.1s |  |
| 44 | `place_and_remove_object_insane_test` | 22 | 16.7s |  |
| 45 | `place_and_remove_object_test` | 13 | 16.9s |  |
| 46 | `register_class/RegisterClassTest3` | 12 | 16.6s |  |
| 47 | `register_class/registerClassTest` | 51 | 16.5s |  |
| 48 | `reverse_execute_PlaceObject2_test1` | 8 | 16.7s |  |
| 49 | `reverse_execute_PlaceObject2_test2` | 10 | 16.8s |  |
| 50 | `runtime_vm_stack_test` | 9 | 16.7s |  |
| 51 | `shape_test` | 21 | 17.0s |  |
| 52 | `static_vs_dynamic1` | 17 | 16.9s |  |
| 53 | `static_vs_dynamic2` | 18 | 16.6s |  |
| 54 | `timeline_var_test` | 11 | 16.7s |  |
| 55 | `unload_movieclip_test1` | 6 | 16.6s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 16.5s |  |
| 2 | `DefineTextTest` | 4 | 4 | 16.3s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 16.3s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 0.3s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 16.4s |  |
| 6 | `callFunction_test` | 5 | 11 | 16.5s |  |
| 7 | `init_action/InitActionTest` | 6 | 17 | 17.1s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 17.1s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 16.6s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 11 | `path_format_test` | 27 | 28 | 16.8s |  |
| 12 | `place_object_test` | 14 | 14 | 17.1s |  |
| 13 | `place_object_test2` | 20 | 23 | 16.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**14 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 2 | `loading/LoadVarsTest` | 86.1% | 31 | 36 | 5 |  |
| 3 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 4 | `register_class/registerClassTest2` | 79.5% | 35 | 44 | 9 |  |
| 5 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 6 | `replace_shapes1test` | 73.9% | 17 | 23 | 6 |  |
| 7 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 10 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 11 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 12 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |
| 14 | `loop/loop_test6` | 50.0% | 12 | 24 | 12 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**34 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99/111 | 111 | 111 |  |
| 2 | `loading/LoadVarsTest` | 86.1% | 31/36 | 36 | 36 |  |
| 3 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 4 | `register_class/registerClassTest2` | 79.5% | 35/44 | 44 | 44 |  |
| 5 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 6 | `replace_shapes1test` | 73.9% | 17/23 | 23 | 23 |  |
| 7 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 8 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 9 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 10 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 11 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 12 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 13 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 14 | `loop/loop_test6` | 50.0% | 12/24 | 24 | 23 |  |
| 15 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 16 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 17 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 18 | `displaylist_depths/displaylist_depths_test8` | 43.8% | 7/16 | 16 | 15 |  |
| 19 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 20 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 21 | `replace_buttons1test` | 33.3% | 6/18 | 18 | 18 |  |
| 22 | `key_event_test` | 31.8% | 27/85 | 85 | 66 |  |
| 23 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 24 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 25 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 26 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 27 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 28 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 29 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 30 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 31 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 32 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 33 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 34 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
