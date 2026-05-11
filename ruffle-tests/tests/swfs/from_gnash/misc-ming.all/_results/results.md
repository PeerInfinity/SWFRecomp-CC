# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-11 17:08 UTC

**Git SHA**: `e0568fe7e5`

**Run Duration**: 24m 38s

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
| 1 | `BeginBitmapFill` | 1 | 17.2s |  |
| 2 | `DefineEditTextTest` | 153 | 17.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 19.3s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.3s |  |
| 5 | `DepthLimitsTest` | 20 | 18.5s |  |
| 6 | `PlaceObject2Test` | 9 | 17.9s |  |
| 7 | `ResolveEventsTest` | 15 | 0.3s |  |
| 8 | `RollOverOutTest` | 5 | 17.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 17.4s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 17.1s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 18.3s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 18.5s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 17.6s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 18.0s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 19.3s |  |
| 19 | `attachExtImported` | 2 | 19.9s |  |
| 20 | `attachImported` | 2 | 0.4s |  |
| 21 | `attachMovieLoopingTest` | 41 | 18.7s |  |
| 22 | `attachMovieTest` | 12 | 19.2s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 18.5s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.5s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 15.8s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 17.5s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.3s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 14.1s |  |
| 33 | `event_handler_scope_test` | 16 | 14.0s |  |
| 34 | `frame_label_test` | 17 | 0.3s |  |
| 35 | `getTimer_test` | 8 | 17.9s |  |
| 36 | `get_frame_number_test` | 31 | 17.7s |  |
| 37 | `goto_frame_test` | 15 | 17.8s |  |
| 38 | `instanceNameTest` | 5 | 0.3s |  |
| 39 | `loading/LoadVarsTest` | 36 | 18.6s |  |
| 40 | `loop/loop_test` | 21 | 18.6s |  |
| 41 | `loop/loop_test2` | 15 | 19.2s |  |
| 42 | `loop/loop_test3` | 16 | 17.4s |  |
| 43 | `loop/loop_test4` | 22 | 17.5s |  |
| 44 | `loop/loop_test5` | 24 | 0.3s |  |
| 45 | `loop/loop_test8` | 38 | 17.6s |  |
| 46 | `loop/loop_test9` | 15 | 17.7s |  |
| 47 | `loop/simple_loop_test` | 0 | 18.9s |  |
| 48 | `masks_test2` | 10 | 18.5s |  |
| 49 | `morph_test1` | 0 | 19.2s |  |
| 50 | `move_object_test` | 11 | 17.6s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 17.6s |  |
| 52 | `new_child_in_unload_test` | 11 | 17.4s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 17.9s |  |
| 54 | `place_and_remove_object_test` | 13 | 19.5s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 18.8s |  |
| 56 | `register_class/registerClassTest` | 51 | 18.6s |  |
| 57 | `replace_shapes1test` | 23 | 0.3s |  |
| 58 | `replace_sprites1test` | 21 | 17.8s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 17.7s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 17.7s |  |
| 61 | `runtime_vm_stack_test` | 9 | 18.2s |  |
| 62 | `shape_test` | 21 | 18.4s |  |
| 63 | `static_vs_dynamic1` | 17 | 18.2s |  |
| 64 | `static_vs_dynamic2` | 18 | 18.9s |  |
| 65 | `timeline_var_test` | 11 | 18.3s |  |
| 66 | `unload_movieclip_test1` | 6 | 18.3s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 17.2s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 17.1s |  |
| 3 | `DefineTextTest` | 4 | 4 | 18.2s |  |
| 4 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 17.7s |  |
| 6 | `action_order/action_execution_order_test4` | 7 | 26 | 0.3s |  |
| 7 | `callFunction_test` | 5 | 11 | 18.6s |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 18.8s |  |
| 9 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 17.6s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 18.4s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 18.2s |  |
| 14 | `key_event_test` | 5 | 6 | 18.4s |  |
| 15 | `loading/loadMovieTest` | 9 | 9 | 18.6s |  |
| 16 | `loop/loop_test10` | 23 | 23 | 18.6s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 17.3s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 19 | `matrix_test` | 5 | 9 | 22.7s |  |
| 20 | `path_format_test` | 28 | 28 | 17.8s |  |
| 21 | `place_object_test` | 14 | 14 | 19.3s |  |
| 22 | `place_object_test2` | 20 | 23 | 19.1s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 17.4s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 17.2s |  |

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
