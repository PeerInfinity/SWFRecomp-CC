# Ruffle Test Results (Filtered)

**Date**: 2026-04-28 21:20 UTC

**Git SHA**: `7384509438`

**Run Duration**: 28m 13s

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
| Matching lines | 2666 (58.7%) |
| Mismatched lines | 1875 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 35 | 97.2% |
| Compile Fail | 1 | 2.8% |

## Passing Tests

**53 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.6s |  |
| 2 | `DefineEditTextTest` | 153 | 26.4s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 21.1s |  |
| 4 | `PlaceObject2Test` | 9 | 17.9s |  |
| 5 | `ResolveEventsTest` | 15 | 2.6s |  |
| 6 | `RollOverOutTest` | 5 | 18.7s |  |
| 7 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 8 | `Video-EmbedSquareTest` | 2 | 18.2s |  |
| 9 | `action_order/action_execution_order_test1` | 10 | 15.7s |  |
| 10 | `action_order/action_execution_order_test3` | 4 | 17.7s |  |
| 11 | `action_order/action_execution_order_test7` | 7 | 19.3s |  |
| 12 | `action_order/action_execution_order_test8-v5` | 11 | 19.1s |  |
| 13 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 14 | `action_order/action_execution_order_test9` | 4 | 17.9s |  |
| 15 | `attachExtImported` | 2 | 19.0s |  |
| 16 | `attachImported` | 2 | 1.5s |  |
| 17 | `attachMovieLoopingTest` | 41 | 18.1s |  |
| 18 | `attachMovieTest` | 12 | 18.6s |  |
| 19 | `consecutive_goto_frame_test` | 12 | 18.0s |  |
| 20 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.2s |  |
| 21 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.4s |  |
| 22 | `displaylist_depths/displaylist_depths_test4` | 26 | 18.0s |  |
| 23 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.6s |  |
| 25 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 26 | `event_handler_scope_test` | 16 | 17.4s |  |
| 27 | `getTimer_test` | 8 | 18.3s |  |
| 28 | `get_frame_number_test` | 31 | 20.1s |  |
| 29 | `goto_frame_test` | 15 | 18.5s |  |
| 30 | `instanceNameTest` | 5 | 1.4s |  |
| 31 | `loop/loop_test2` | 15 | 17.9s |  |
| 32 | `loop/loop_test3` | 16 | 17.9s |  |
| 33 | `loop/loop_test4` | 22 | 18.6s |  |
| 34 | `loop/loop_test5` | 24 | 2.5s |  |
| 35 | `loop/loop_test8` | 38 | 20.7s |  |
| 36 | `loop/loop_test9` | 15 | 18.4s |  |
| 37 | `loop/simple_loop_test` | 0 | 18.0s |  |
| 38 | `masks_test2` | 10 | 17.7s |  |
| 39 | `morph_test1` | 0 | 17.5s |  |
| 40 | `move_object_test` | 11 | 18.1s |  |
| 41 | `multi_doactions_and_goto_frame_test` | 6 | 17.8s |  |
| 42 | `new_child_in_unload_test` | 11 | 17.7s |  |
| 43 | `place_and_remove_object_insane_test` | 22 | 18.9s |  |
| 44 | `place_and_remove_object_test` | 13 | 18.6s |  |
| 45 | `register_class/RegisterClassTest3` | 12 | 19.2s |  |
| 46 | `register_class/registerClassTest` | 51 | 22.0s |  |
| 47 | `reverse_execute_PlaceObject2_test1` | 8 | 18.3s |  |
| 48 | `reverse_execute_PlaceObject2_test2` | 10 | 18.7s |  |
| 49 | `runtime_vm_stack_test` | 9 | 18.8s |  |
| 50 | `shape_test` | 21 | 19.7s |  |
| 51 | `static_vs_dynamic1` | 17 | 18.3s |  |
| 52 | `static_vs_dynamic2` | 18 | 18.8s |  |
| 53 | `unload_movieclip_test1` | 6 | 17.9s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 18.3s |  |
| 2 | `DefineTextTest` | 4 | 4 | 18.5s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 18.6s |  |
| 4 | `action_order/action_execution_order_test4` | 6 | 26 | 2.6s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 19.8s |  |
| 6 | `callFunction_test` | 5 | 11 | 18.8s |  |
| 7 | `init_action/InitActionTest` | 6 | 17 | 19.6s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 20.2s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 20.1s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 2.0s |  |
| 11 | `path_format_test` | 27 | 28 | 21.1s |  |
| 12 | `place_object_test` | 14 | 14 | 18.8s |  |
| 13 | `place_object_test2` | 20 | 23 | 19.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 2 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 3 | `register_class/registerClassTest2` | 79.5% | 35 | 44 | 9 |  |
| 4 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 5 | `DrawingApiTest` | 67.4% | 64 | 95 | 31 |  |
| 6 | `action_order/action_execution_order_test5` | 63.4% | 26 | 41 | 15 |  |
| 7 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 8 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 9 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 10 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 11 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 12 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |
| 13 | `loop/loop_test6` | 50.0% | 12 | 24 | 12 |  |

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
| 6 | `action_order/action_execution_order_test5` | 63.4% | 26/41 | 41 | 35 |  |
| 7 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 8 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 9 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 10 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 11 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 12 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 13 | `loop/loop_test6` | 50.0% | 12/24 | 24 | 23 |  |
| 14 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 15 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 16 | `displaylist_depths/displaylist_depths_test8` | 43.8% | 7/16 | 16 | 15 |  |
| 17 | `action_order/action_execution_order_test11` | 40.6% | 13/32 | 32 | 32 |  |
| 18 | `action_order/action_execution_order_test2` | 40.0% | 2/5 | 5 | 5 |  |
| 19 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 20 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 21 | `loop/loop_test` | 23.8% | 5/21 | 21 | 21 |  |
| 22 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 23 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 24 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 25 | `action_order/ActionOrderTest5` | 12.3% | 8/65 | 65 | 51 |  |
| 26 | `action_order/ActionOrderTest4` | 10.3% | 8/78 | 78 | 64 |  |
| 27 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 28 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 29 | `action_order/ActionOrderTest3` | 6.2% | 5/81 | 81 | 62 |  |
| 30 | `register_class/RegisterClassTest4` | 4.7% | 2/43 | 43 | 42 |  |
| 31 | `loop/loop_test10` | 3.6% | 1/28 | 22 | 28 |  |
| 32 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 33 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 34 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 35 | `replace_shapes1test` | 0.0% | 0/32 | 32 | 23 |  |
