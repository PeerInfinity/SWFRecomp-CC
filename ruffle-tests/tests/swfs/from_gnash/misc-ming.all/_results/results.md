# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-01 01:42 UTC

**Git SHA**: `88cfa5ac26`

**Run Duration**: 25m 19s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **59** (57.8%) |
| Ruffle-matched | 14 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **73** (71.6%) |
| Failing | 29 |
| Total expected lines | 4577 |
| Matching lines | 2805 (61.3%) |
| Mismatched lines | 1772 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 29 | 100.0% |

## Passing Tests

**59 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 17.1s |  |
| 2 | `DefineEditTextTest` | 153 | 17.5s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 21.4s |  |
| 4 | `DepthLimitsTest` | 20 | 20.8s |  |
| 5 | `PlaceObject2Test` | 9 | 17.1s |  |
| 6 | `ResolveEventsTest` | 15 | 0.6s |  |
| 7 | `RollOverOutTest` | 5 | 17.1s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.5s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 17.3s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 18.2s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 18.6s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 18.5s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 14.8s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 15.5s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 17.6s |  |
| 17 | `attachExtImported` | 2 | 17.9s |  |
| 18 | `attachImported` | 2 | 0.6s |  |
| 19 | `attachMovieLoopingTest` | 41 | 17.8s |  |
| 20 | `attachMovieTest` | 12 | 17.2s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 17.0s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.4s |  |
| 23 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.4s |  |
| 24 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.5s |  |
| 27 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.5s |  |
| 28 | `event_handler_scope_test` | 16 | 18.5s |  |
| 29 | `getTimer_test` | 8 | 17.6s |  |
| 30 | `get_frame_number_test` | 31 | 17.4s |  |
| 31 | `goto_frame_test` | 15 | 17.6s |  |
| 32 | `instanceNameTest` | 5 | 1.5s |  |
| 33 | `loop/loop_test` | 21 | 18.5s |  |
| 34 | `loop/loop_test2` | 15 | 18.0s |  |
| 35 | `loop/loop_test3` | 16 | 18.4s |  |
| 36 | `loop/loop_test4` | 22 | 19.3s |  |
| 37 | `loop/loop_test5` | 24 | 2.5s |  |
| 38 | `loop/loop_test8` | 38 | 20.3s |  |
| 39 | `loop/loop_test9` | 15 | 17.8s |  |
| 40 | `loop/simple_loop_test` | 0 | 17.5s |  |
| 41 | `masks_test2` | 10 | 15.7s |  |
| 42 | `morph_test1` | 0 | 15.8s |  |
| 43 | `move_object_test` | 11 | 18.1s |  |
| 44 | `multi_doactions_and_goto_frame_test` | 6 | 18.4s |  |
| 45 | `new_child_in_unload_test` | 11 | 18.3s |  |
| 46 | `place_and_remove_object_insane_test` | 22 | 18.9s |  |
| 47 | `place_and_remove_object_test` | 13 | 17.2s |  |
| 48 | `register_class/RegisterClassTest3` | 12 | 18.4s |  |
| 49 | `register_class/registerClassTest` | 51 | 20.5s |  |
| 50 | `replace_shapes1test` | 23 | 2.3s |  |
| 51 | `replace_sprites1test` | 21 | 18.9s |  |
| 52 | `reverse_execute_PlaceObject2_test1` | 8 | 18.2s |  |
| 53 | `reverse_execute_PlaceObject2_test2` | 10 | 18.3s |  |
| 54 | `runtime_vm_stack_test` | 9 | 18.4s |  |
| 55 | `shape_test` | 21 | 19.6s |  |
| 56 | `static_vs_dynamic1` | 17 | 18.3s |  |
| 57 | `static_vs_dynamic2` | 18 | 17.3s |  |
| 58 | `timeline_var_test` | 11 | 17.1s |  |
| 59 | `unload_movieclip_test1` | 6 | 17.2s |  |

## Ruffle-Matched Tests

**14 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 17.2s |  |
| 2 | `DefineTextTest` | 4 | 4 | 19.1s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 17.6s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 2.9s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 15.8s |  |
| 6 | `callFunction_test` | 5 | 11 | 17.0s |  |
| 7 | `init_action/InitActionTest` | 6 | 17 | 17.9s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 19.5s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 21.0s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 2.1s |  |
| 11 | `path_format_test` | 27 | 28 | 20.5s |  |
| 12 | `place_object_test` | 14 | 14 | 17.4s |  |
| 13 | `place_object_test2` | 20 | 23 | 17.2s |  |
| 14 | `replace_buttons1test` | 3 | 3 | 18.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 2 | `loading/LoadVarsTest` | 86.1% | 31 | 36 | 5 |  |
| 3 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 4 | `register_class/registerClassTest2` | 79.5% | 35 | 44 | 9 |  |
| 5 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 6 | `displaylist_depths/displaylist_depths_test8` | 66.7% | 10 | 15 | 5 |  |
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

**29 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99/111 | 111 | 111 |  |
| 2 | `loading/LoadVarsTest` | 86.1% | 31/36 | 36 | 36 |  |
| 3 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 4 | `register_class/registerClassTest2` | 79.5% | 35/44 | 44 | 44 |  |
| 5 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 6 | `displaylist_depths/displaylist_depths_test8` | 66.7% | 10/15 | 15 | 15 |  |
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
| 17 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 18 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 19 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 20 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 21 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 22 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 23 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 24 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 25 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 26 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 27 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 28 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 29 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
