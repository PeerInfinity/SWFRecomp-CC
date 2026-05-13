# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-13 17:52 UTC

**Git SHA**: `0a7f72f11e`

**Run Duration**: 24m 31s

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
| 1 | `BeginBitmapFill` | 1 | 17.9s |  |
| 2 | `DefineEditTextTest` | 153 | 18.1s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 18.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 18.7s |  |
| 5 | `DepthLimitsTest` | 20 | 18.4s |  |
| 6 | `PlaceObject2Test` | 9 | 17.4s |  |
| 7 | `ResolveEventsTest` | 15 | 0.4s |  |
| 8 | `RollOverOutTest` | 5 | 17.9s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 10 | `Version4Loader` | 11 | 0.3s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.1s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 21.1s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 14.3s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 14.5s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 18.2s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 18.4s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 18.6s |  |
| 19 | `attachExtImported` | 2 | 18.3s |  |
| 20 | `attachImported` | 2 | 0.3s |  |
| 21 | `attachMovieLoopingTest` | 41 | 18.3s |  |
| 22 | `attachMovieTest` | 12 | 14.2s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 14.3s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.6s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.5s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 18.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 18.8s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.4s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 17.8s |  |
| 33 | `event_handler_scope_test` | 16 | 17.9s |  |
| 34 | `frame_label_test` | 17 | 0.4s |  |
| 35 | `getTimer_test` | 8 | 17.8s |  |
| 36 | `get_frame_number_test` | 31 | 18.0s |  |
| 37 | `goto_frame_test` | 15 | 18.0s |  |
| 38 | `instanceNameTest` | 5 | 0.2s |  |
| 39 | `loading/LoadVarsTest` | 36 | 18.0s |  |
| 40 | `loop/loop_test` | 21 | 17.6s |  |
| 41 | `loop/loop_test2` | 15 | 17.6s |  |
| 42 | `loop/loop_test3` | 16 | 17.9s |  |
| 43 | `loop/loop_test4` | 22 | 17.7s |  |
| 44 | `loop/loop_test5` | 24 | 0.3s |  |
| 45 | `loop/loop_test8` | 38 | 18.9s |  |
| 46 | `loop/loop_test9` | 15 | 18.4s |  |
| 47 | `loop/simple_loop_test` | 0 | 18.4s |  |
| 48 | `masks_test2` | 10 | 18.9s |  |
| 49 | `morph_test1` | 0 | 18.6s |  |
| 50 | `move_object_test` | 11 | 17.6s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 17.5s |  |
| 52 | `new_child_in_unload_test` | 11 | 17.7s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 18.4s |  |
| 54 | `place_and_remove_object_test` | 13 | 18.7s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 18.6s |  |
| 56 | `register_class/registerClassTest` | 51 | 18.5s |  |
| 57 | `replace_shapes1test` | 23 | 0.3s |  |
| 58 | `replace_sprites1test` | 21 | 18.9s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 18.9s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 19.0s |  |
| 61 | `runtime_vm_stack_test` | 9 | 17.3s |  |
| 62 | `shape_test` | 21 | 17.6s |  |
| 63 | `static_vs_dynamic1` | 17 | 17.2s |  |
| 64 | `static_vs_dynamic2` | 18 | 18.1s |  |
| 65 | `timeline_var_test` | 11 | 18.2s |  |
| 66 | `unload_movieclip_test1` | 6 | 18.0s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 17.7s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 17.1s |  |
| 3 | `DefineTextTest` | 4 | 4 | 18.4s |  |
| 4 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 17.9s |  |
| 6 | `action_order/action_execution_order_test4` | 7 | 26 | 0.3s |  |
| 7 | `callFunction_test` | 5 | 11 | 14.1s |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 14.3s |  |
| 9 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 18.5s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 17.1s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 17.1s |  |
| 14 | `key_event_test` | 5 | 6 | 18.0s |  |
| 15 | `loading/loadMovieTest` | 9 | 9 | 17.9s |  |
| 16 | `loop/loop_test10` | 23 | 23 | 17.6s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 18.5s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 19 | `matrix_test` | 5 | 9 | 22.5s |  |
| 20 | `path_format_test` | 28 | 28 | 18.6s |  |
| 21 | `place_object_test` | 14 | 14 | 18.9s |  |
| 22 | `place_object_test2` | 20 | 23 | 19.2s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 18.0s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 17.8s |  |

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
