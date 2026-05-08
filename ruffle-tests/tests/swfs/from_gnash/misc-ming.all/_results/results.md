# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-08 02:38 UTC

**Git SHA**: `1e21fdb6aa`

**Run Duration**: 23m 33s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **65** (63.7%) |
| Ruffle-matched | 23 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **88** (86.3%) |
| Failing | 14 |
| Total expected lines | 4577 |
| Matching lines | 3726 (81.4%) |
| Mismatched lines | 851 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 17.1s |  |
| 2 | `DefineEditTextTest` | 153 | 17.4s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 17.0s |  |
| 4 | `DepthLimitsTest` | 20 | 17.1s |  |
| 5 | `PlaceObject2Test` | 9 | 17.2s |  |
| 6 | `ResolveEventsTest` | 15 | 0.3s |  |
| 7 | `RollOverOutTest` | 5 | 17.4s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 9 | `Version4Loader` | 11 | 0.3s |  |
| 10 | `Video-EmbedSquareTest` | 2 | 17.5s |  |
| 11 | `action_order/action_execution_order_test1` | 10 | 18.0s |  |
| 12 | `action_order/action_execution_order_test2` | 5 | 13.7s |  |
| 13 | `action_order/action_execution_order_test3` | 4 | 13.6s |  |
| 14 | `action_order/action_execution_order_test7` | 7 | 17.4s |  |
| 15 | `action_order/action_execution_order_test8-v5` | 11 | 17.5s |  |
| 16 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 17 | `action_order/action_execution_order_test9` | 4 | 17.1s |  |
| 18 | `attachExtImported` | 2 | 17.1s |  |
| 19 | `attachImported` | 2 | 0.3s |  |
| 20 | `attachMovieLoopingTest` | 41 | 17.0s |  |
| 21 | `attachMovieTest` | 12 | 18.0s |  |
| 22 | `consecutive_goto_frame_test` | 12 | 18.2s |  |
| 23 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.9s |  |
| 24 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.6s |  |
| 25 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.2s |  |
| 27 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 29 | `displaylist_depths/displaylist_depths_test8` | 15 | 21.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.4s |  |
| 31 | `duplicate_movie_clip_test2` | 21 | 17.6s |  |
| 32 | `event_handler_scope_test` | 16 | 17.5s |  |
| 33 | `frame_label_test` | 17 | 0.4s |  |
| 34 | `getTimer_test` | 8 | 17.5s |  |
| 35 | `get_frame_number_test` | 31 | 17.7s |  |
| 36 | `goto_frame_test` | 15 | 17.3s |  |
| 37 | `instanceNameTest` | 5 | 0.2s |  |
| 38 | `loading/LoadVarsTest` | 36 | 14.2s |  |
| 39 | `loop/loop_test` | 21 | 17.5s |  |
| 40 | `loop/loop_test2` | 15 | 17.2s |  |
| 41 | `loop/loop_test3` | 16 | 17.4s |  |
| 42 | `loop/loop_test4` | 22 | 17.5s |  |
| 43 | `loop/loop_test5` | 24 | 0.3s |  |
| 44 | `loop/loop_test8` | 38 | 17.2s |  |
| 45 | `loop/loop_test9` | 15 | 17.7s |  |
| 46 | `loop/simple_loop_test` | 0 | 17.6s |  |
| 47 | `masks_test2` | 10 | 17.6s |  |
| 48 | `morph_test1` | 0 | 17.7s |  |
| 49 | `move_object_test` | 11 | 17.3s |  |
| 50 | `multi_doactions_and_goto_frame_test` | 6 | 16.9s |  |
| 51 | `new_child_in_unload_test` | 11 | 16.9s |  |
| 52 | `place_and_remove_object_insane_test` | 22 | 16.6s |  |
| 53 | `place_and_remove_object_test` | 13 | 17.7s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 17.7s |  |
| 55 | `register_class/registerClassTest` | 51 | 17.8s |  |
| 56 | `replace_shapes1test` | 23 | 0.3s |  |
| 57 | `replace_sprites1test` | 21 | 17.0s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 17.2s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 17.2s |  |
| 60 | `runtime_vm_stack_test` | 9 | 16.9s |  |
| 61 | `shape_test` | 21 | 17.1s |  |
| 62 | `static_vs_dynamic1` | 17 | 16.9s |  |
| 63 | `static_vs_dynamic2` | 18 | 17.3s |  |
| 64 | `timeline_var_test` | 11 | 17.2s |  |
| 65 | `unload_movieclip_test1` | 6 | 17.6s |  |

## Ruffle-Matched Tests

**23 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 17.2s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 16.8s |  |
| 3 | `DefineTextTest` | 4 | 4 | 17.0s |  |
| 4 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 17.1s |  |
| 6 | `action_order/action_execution_order_test4` | 7 | 26 | 0.3s |  |
| 7 | `callFunction_test` | 5 | 11 | 18.2s |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 18.2s |  |
| 9 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 21.3s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 13.6s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 13.7s |  |
| 14 | `key_event_test` | 5 | 6 | 14.0s |  |
| 15 | `loading/loadMovieTest` | 9 | 9 | 14.5s |  |
| 16 | `loop/loop_test6` | 1 | 12 | 17.1s |  |
| 17 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 18 | `matrix_test` | 5 | 9 | 21.4s |  |
| 19 | `path_format_test` | 28 | 28 | 16.8s |  |
| 20 | `place_object_test` | 14 | 14 | 17.7s |  |
| 21 | `place_object_test2` | 20 | 23 | 17.4s |  |
| 22 | `register_class/registerClassTest2` | 8 | 28 | 18.3s |  |
| 23 | `replace_buttons1test` | 3 | 3 | 18.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 2 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 4 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |
| 5 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**14 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 2 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 4 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 5 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 6 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 7 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 8 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 9 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 10 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 11 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 12 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
