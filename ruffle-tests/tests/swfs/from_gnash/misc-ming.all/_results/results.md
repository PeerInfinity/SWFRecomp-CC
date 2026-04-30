# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-30 20:27 UTC

**Git SHA**: `61229899ae`

**Run Duration**: 25m 60s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **58** (56.9%) |
| Ruffle-matched | 13 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **71** (69.6%) |
| Failing | 31 |
| Total expected lines | 4577 |
| Matching lines | 2781 (60.8%) |
| Mismatched lines | 1796 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 31 | 100.0% |

## Passing Tests

**58 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.6s |  |
| 2 | `DefineEditTextTest` | 153 | 29.0s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 18.1s |  |
| 4 | `DepthLimitsTest` | 20 | 17.7s |  |
| 5 | `PlaceObject2Test` | 9 | 16.7s |  |
| 6 | `ResolveEventsTest` | 15 | 0.3s |  |
| 7 | `RollOverOutTest` | 5 | 17.0s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 13.5s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 16.9s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 18.8s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 18.6s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 17.0s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 16.9s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 17.7s |  |
| 17 | `attachExtImported` | 2 | 18.8s |  |
| 18 | `attachImported` | 2 | 1.6s |  |
| 19 | `attachMovieLoopingTest` | 41 | 17.9s |  |
| 20 | `attachMovieTest` | 12 | 17.6s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 17.3s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.0s |  |
| 23 | `displaylist_depths/displaylist_depths_test11` | 15 | 16.8s |  |
| 24 | `displaylist_depths/displaylist_depths_test4` | 26 | 18.6s |  |
| 25 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.7s |  |
| 26 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.1s |  |
| 28 | `event_handler_scope_test` | 16 | 18.9s |  |
| 29 | `getTimer_test` | 8 | 17.4s |  |
| 30 | `get_frame_number_test` | 31 | 17.4s |  |
| 31 | `goto_frame_test` | 15 | 17.3s |  |
| 32 | `instanceNameTest` | 5 | 0.3s |  |
| 33 | `loop/loop_test` | 21 | 16.7s |  |
| 34 | `loop/loop_test2` | 15 | 17.0s |  |
| 35 | `loop/loop_test3` | 16 | 17.9s |  |
| 36 | `loop/loop_test4` | 22 | 18.8s |  |
| 37 | `loop/loop_test5` | 24 | 2.6s |  |
| 38 | `loop/loop_test8` | 38 | 16.6s |  |
| 39 | `loop/loop_test9` | 15 | 20.7s |  |
| 40 | `loop/simple_loop_test` | 0 | 20.8s |  |
| 41 | `masks_test2` | 10 | 16.9s |  |
| 42 | `morph_test1` | 0 | 16.9s |  |
| 43 | `move_object_test` | 11 | 18.8s |  |
| 44 | `multi_doactions_and_goto_frame_test` | 6 | 18.5s |  |
| 45 | `new_child_in_unload_test` | 11 | 18.6s |  |
| 46 | `place_and_remove_object_insane_test` | 22 | 18.8s |  |
| 47 | `place_and_remove_object_test` | 13 | 17.8s |  |
| 48 | `register_class/RegisterClassTest3` | 12 | 18.3s |  |
| 49 | `register_class/registerClassTest` | 51 | 20.4s |  |
| 50 | `replace_sprites1test` | 21 | 19.0s |  |
| 51 | `reverse_execute_PlaceObject2_test1` | 8 | 18.1s |  |
| 52 | `reverse_execute_PlaceObject2_test2` | 10 | 18.1s |  |
| 53 | `runtime_vm_stack_test` | 9 | 19.9s |  |
| 54 | `shape_test` | 21 | 21.1s |  |
| 55 | `static_vs_dynamic1` | 17 | 19.2s |  |
| 56 | `static_vs_dynamic2` | 18 | 19.7s |  |
| 57 | `timeline_var_test` | 11 | 19.9s |  |
| 58 | `unload_movieclip_test1` | 6 | 19.6s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 18.9s |  |
| 2 | `DefineTextTest` | 4 | 4 | 17.8s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 18.8s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 2.9s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 17.1s |  |
| 6 | `callFunction_test` | 5 | 11 | 17.6s |  |
| 7 | `init_action/InitActionTest` | 6 | 17 | 17.1s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 17.1s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 21.2s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 11 | `path_format_test` | 27 | 28 | 21.0s |  |
| 12 | `place_object_test` | 14 | 14 | 18.4s |  |
| 13 | `place_object_test2` | 20 | 23 | 18.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 2 | `loading/LoadVarsTest` | 86.1% | 31 | 36 | 5 |  |
| 3 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 4 | `register_class/registerClassTest2` | 79.5% | 35 | 44 | 9 |  |
| 5 | `replace_shapes1test` | 73.9% | 17 | 23 | 6 |  |
| 6 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 7 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 8 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 9 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 10 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 11 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |
| 12 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |
| 13 | `loop/loop_test6` | 50.0% | 12 | 24 | 12 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**31 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99/111 | 111 | 111 |  |
| 2 | `loading/LoadVarsTest` | 86.1% | 31/36 | 36 | 36 |  |
| 3 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 4 | `register_class/registerClassTest2` | 79.5% | 35/44 | 44 | 44 |  |
| 5 | `replace_shapes1test` | 73.9% | 17/23 | 23 | 23 |  |
| 6 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 7 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 8 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 9 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 10 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 11 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 12 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 13 | `loop/loop_test6` | 50.0% | 12/24 | 24 | 23 |  |
| 14 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 15 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 16 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 17 | `displaylist_depths/displaylist_depths_test8` | 43.8% | 7/16 | 16 | 15 |  |
| 18 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 19 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 20 | `replace_buttons1test` | 33.3% | 6/18 | 18 | 18 |  |
| 21 | `key_event_test` | 31.8% | 27/85 | 85 | 66 |  |
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
