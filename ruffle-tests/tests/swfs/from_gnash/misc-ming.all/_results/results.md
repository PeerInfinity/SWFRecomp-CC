# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-11 04:23 UTC

**Git SHA**: `b232f7e6fa`

**Run Duration**: 26m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **66** (64.7%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **90** (88.2%) |
| Failing | 12 |
| Total expected lines | 4577 |
| Matching lines | 3774 (82.5%) |
| Mismatched lines | 803 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 12 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.4s |  |
| 2 | `DefineEditTextTest` | 153 | 18.7s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.7s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.5s |  |
| 5 | `DepthLimitsTest` | 20 | 21.2s |  |
| 6 | `PlaceObject2Test` | 9 | 16.8s |  |
| 7 | `ResolveEventsTest` | 15 | 0.3s |  |
| 8 | `RollOverOutTest` | 5 | 16.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.2s |  |
| 10 | `Version4Loader` | 11 | 0.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.0s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 19.5s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 19.3s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.2s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 17.3s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 17.4s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 17.5s |  |
| 19 | `attachExtImported` | 2 | 17.6s |  |
| 20 | `attachImported` | 2 | 0.3s |  |
| 21 | `attachMovieLoopingTest` | 41 | 17.4s |  |
| 22 | `attachMovieTest` | 12 | 14.0s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 14.1s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.5s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 18.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 20.1s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 2.8s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 21.1s |  |
| 33 | `event_handler_scope_test` | 16 | 20.2s |  |
| 34 | `frame_label_test` | 17 | 3.1s |  |
| 35 | `getTimer_test` | 8 | 20.1s |  |
| 36 | `get_frame_number_test` | 31 | 21.8s |  |
| 37 | `goto_frame_test` | 15 | 20.2s |  |
| 38 | `instanceNameTest` | 5 | 1.4s |  |
| 39 | `loading/LoadVarsTest` | 36 | 18.6s |  |
| 40 | `loop/loop_test` | 21 | 17.8s |  |
| 41 | `loop/loop_test2` | 15 | 17.6s |  |
| 42 | `loop/loop_test3` | 16 | 18.6s |  |
| 43 | `loop/loop_test4` | 22 | 19.5s |  |
| 44 | `loop/loop_test5` | 24 | 2.8s |  |
| 45 | `loop/loop_test8` | 38 | 17.3s |  |
| 46 | `loop/loop_test9` | 15 | 17.1s |  |
| 47 | `loop/simple_loop_test` | 0 | 17.6s |  |
| 48 | `masks_test2` | 10 | 17.6s |  |
| 49 | `morph_test1` | 0 | 17.9s |  |
| 50 | `move_object_test` | 11 | 17.1s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 17.2s |  |
| 52 | `new_child_in_unload_test` | 11 | 17.1s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 19.6s |  |
| 54 | `place_and_remove_object_test` | 13 | 18.9s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 19.7s |  |
| 56 | `register_class/registerClassTest` | 51 | 21.4s |  |
| 57 | `replace_shapes1test` | 23 | 2.5s |  |
| 58 | `replace_sprites1test` | 21 | 20.0s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 20.0s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 20.3s |  |
| 61 | `runtime_vm_stack_test` | 9 | 20.5s |  |
| 62 | `shape_test` | 21 | 21.8s |  |
| 63 | `static_vs_dynamic1` | 17 | 19.5s |  |
| 64 | `static_vs_dynamic2` | 18 | 20.7s |  |
| 65 | `timeline_var_test` | 11 | 20.0s |  |
| 66 | `unload_movieclip_test1` | 6 | 19.4s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 18.3s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 17.9s |  |
| 3 | `DefineTextTest` | 4 | 4 | 20.0s |  |
| 4 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 17.1s |  |
| 6 | `action_order/action_execution_order_test4` | 7 | 26 | 3.0s |  |
| 7 | `callFunction_test` | 5 | 11 | 14.1s |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 14.6s |  |
| 9 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.0s |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.9s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 21.7s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 15.5s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 16.3s |  |
| 14 | `key_event_test` | 5 | 6 | 18.3s |  |
| 15 | `loading/loadMovieTest` | 9 | 9 | 18.6s |  |
| 16 | `loop/loop_test10` | 23 | 23 | 17.6s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 17.2s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 19 | `matrix_test` | 5 | 9 | 21.7s |  |
| 20 | `path_format_test` | 28 | 28 | 21.8s |  |
| 21 | `place_object_test` | 14 | 14 | 19.6s |  |
| 22 | `place_object_test2` | 20 | 23 | 19.2s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 21.9s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 20.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 4 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**12 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 4 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 5 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 6 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 7 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 8 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 9 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 10 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 11 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 12 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
