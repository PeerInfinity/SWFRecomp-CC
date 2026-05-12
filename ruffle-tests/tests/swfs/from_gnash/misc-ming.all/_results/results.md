# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-12 19:44 UTC

**Git SHA**: `ce10ee674e`

**Run Duration**: 1m 3s

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
| 1 | `BeginBitmapFill` | 1 | 0.4s |  |
| 2 | `DefineEditTextTest` | 153 | 1.2s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 1.0s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 0.9s |  |
| 5 | `DepthLimitsTest` | 20 | 0.5s |  |
| 6 | `PlaceObject2Test` | 9 | 0.4s |  |
| 7 | `ResolveEventsTest` | 15 | 0.4s |  |
| 8 | `RollOverOutTest` | 5 | 0.6s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.5s |  |
| 10 | `Version4Loader` | 11 | 0.8s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 0.4s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 0.4s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 0.5s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 0.4s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 0.4s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 0.5s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 0.4s |  |
| 19 | `attachExtImported` | 2 | 1.6s |  |
| 20 | `attachImported` | 2 | 1.0s |  |
| 21 | `attachMovieLoopingTest` | 41 | 0.4s |  |
| 22 | `attachMovieTest` | 12 | 0.5s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 0.4s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.4s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.5s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 0.6s |  |
| 33 | `event_handler_scope_test` | 16 | 0.8s |  |
| 34 | `frame_label_test` | 17 | 0.6s |  |
| 35 | `getTimer_test` | 8 | 0.4s |  |
| 36 | `get_frame_number_test` | 31 | 0.5s |  |
| 37 | `goto_frame_test` | 15 | 0.5s |  |
| 38 | `instanceNameTest` | 5 | 0.4s |  |
| 39 | `loading/LoadVarsTest` | 36 | 0.6s |  |
| 40 | `loop/loop_test` | 21 | 0.5s |  |
| 41 | `loop/loop_test2` | 15 | 0.4s |  |
| 42 | `loop/loop_test3` | 16 | 0.9s |  |
| 43 | `loop/loop_test4` | 22 | 0.4s |  |
| 44 | `loop/loop_test5` | 24 | 0.4s |  |
| 45 | `loop/loop_test8` | 38 | 0.6s |  |
| 46 | `loop/loop_test9` | 15 | 0.4s |  |
| 47 | `loop/simple_loop_test` | 0 | 0.2s |  |
| 48 | `masks_test2` | 10 | 0.4s |  |
| 49 | `morph_test1` | 0 | 0.4s |  |
| 50 | `move_object_test` | 11 | 0.4s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 0.4s |  |
| 52 | `new_child_in_unload_test` | 11 | 0.4s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 0.4s |  |
| 54 | `place_and_remove_object_test` | 13 | 0.3s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 0.5s |  |
| 56 | `register_class/registerClassTest` | 51 | 0.6s |  |
| 57 | `replace_shapes1test` | 23 | 0.5s |  |
| 58 | `replace_sprites1test` | 21 | 0.4s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 0.4s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 0.4s |  |
| 61 | `runtime_vm_stack_test` | 9 | 0.5s |  |
| 62 | `shape_test` | 21 | 0.5s |  |
| 63 | `static_vs_dynamic1` | 17 | 0.4s |  |
| 64 | `static_vs_dynamic2` | 18 | 0.6s |  |
| 65 | `timeline_var_test` | 11 | 0.4s |  |
| 66 | `unload_movieclip_test1` | 6 | 0.4s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 0.7s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 0.4s |  |
| 3 | `DefineTextTest` | 4 | 4 | 0.4s |  |
| 4 | `DragDropTest` | 12 | 12 | 0.4s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 0.4s |  |
| 6 | `action_order/action_execution_order_test4` | 7 | 26 | 0.5s |  |
| 7 | `callFunction_test` | 5 | 11 | 0.5s |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 0.9s |  |
| 9 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.4s |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 0.6s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 0.4s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 0.5s |  |
| 14 | `key_event_test` | 5 | 6 | 0.5s |  |
| 15 | `loading/loadMovieTest` | 9 | 9 | 1.8s |  |
| 16 | `loop/loop_test10` | 23 | 23 | 0.5s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 0.5s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 0.4s |  |
| 19 | `matrix_test` | 5 | 9 | 4.1s |  |
| 20 | `path_format_test` | 28 | 28 | 0.6s |  |
| 21 | `place_object_test` | 14 | 14 | 0.4s |  |
| 22 | `place_object_test2` | 20 | 23 | 0.4s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 0.5s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 0.4s |  |

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
