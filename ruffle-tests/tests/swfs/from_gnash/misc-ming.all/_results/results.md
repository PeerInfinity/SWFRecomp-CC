# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-08 20:48 UTC

**Git SHA**: `e0d150896c`

**Run Duration**: 23m 58s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **65** (63.7%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **89** (87.3%) |
| Failing | 13 |
| Total expected lines | 4577 |
| Matching lines | 3737 (81.6%) |
| Mismatched lines | 840 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 17.9s |  |
| 2 | `DefineEditTextTest` | 153 | 18.5s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 17.8s |  |
| 4 | `DepthLimitsTest` | 20 | 17.7s |  |
| 5 | `PlaceObject2Test` | 9 | 17.5s |  |
| 6 | `ResolveEventsTest` | 15 | 0.4s |  |
| 7 | `RollOverOutTest` | 5 | 17.4s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 9 | `Version4Loader` | 11 | 0.3s |  |
| 10 | `Video-EmbedSquareTest` | 2 | 18.4s |  |
| 11 | `action_order/action_execution_order_test1` | 10 | 18.4s |  |
| 12 | `action_order/action_execution_order_test2` | 5 | 18.2s |  |
| 13 | `action_order/action_execution_order_test3` | 4 | 18.1s |  |
| 14 | `action_order/action_execution_order_test7` | 7 | 17.6s |  |
| 15 | `action_order/action_execution_order_test8-v5` | 11 | 18.1s |  |
| 16 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 17 | `action_order/action_execution_order_test9` | 4 | 19.3s |  |
| 18 | `attachExtImported` | 2 | 19.6s |  |
| 19 | `attachImported` | 2 | 0.4s |  |
| 20 | `attachMovieLoopingTest` | 41 | 18.9s |  |
| 21 | `attachMovieTest` | 12 | 17.3s |  |
| 22 | `consecutive_goto_frame_test` | 12 | 17.5s |  |
| 23 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.0s |  |
| 24 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.1s |  |
| 25 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test8` | 15 | 18.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.3s |  |
| 31 | `duplicate_movie_clip_test2` | 21 | 17.6s |  |
| 32 | `event_handler_scope_test` | 16 | 17.4s |  |
| 33 | `frame_label_test` | 17 | 0.4s |  |
| 34 | `getTimer_test` | 8 | 17.8s |  |
| 35 | `get_frame_number_test` | 31 | 18.0s |  |
| 36 | `goto_frame_test` | 15 | 18.6s |  |
| 37 | `instanceNameTest` | 5 | 0.3s |  |
| 38 | `loading/LoadVarsTest` | 36 | 17.4s |  |
| 39 | `loop/loop_test` | 21 | 17.1s |  |
| 40 | `loop/loop_test2` | 15 | 17.0s |  |
| 41 | `loop/loop_test3` | 16 | 17.8s |  |
| 42 | `loop/loop_test4` | 22 | 17.9s |  |
| 43 | `loop/loop_test5` | 24 | 0.4s |  |
| 44 | `loop/loop_test8` | 38 | 18.1s |  |
| 45 | `loop/loop_test9` | 15 | 17.0s |  |
| 46 | `loop/simple_loop_test` | 0 | 17.1s |  |
| 47 | `masks_test2` | 10 | 17.0s |  |
| 48 | `morph_test1` | 0 | 17.1s |  |
| 49 | `move_object_test` | 11 | 14.2s |  |
| 50 | `multi_doactions_and_goto_frame_test` | 6 | 14.1s |  |
| 51 | `new_child_in_unload_test` | 11 | 14.1s |  |
| 52 | `place_and_remove_object_insane_test` | 22 | 18.0s |  |
| 53 | `place_and_remove_object_test` | 13 | 17.9s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 17.3s |  |
| 55 | `register_class/registerClassTest` | 51 | 17.4s |  |
| 56 | `replace_shapes1test` | 23 | 0.2s |  |
| 57 | `replace_sprites1test` | 21 | 17.1s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 17.1s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 17.0s |  |
| 60 | `runtime_vm_stack_test` | 9 | 17.8s |  |
| 61 | `shape_test` | 21 | 18.0s |  |
| 62 | `static_vs_dynamic1` | 17 | 17.8s |  |
| 63 | `static_vs_dynamic2` | 18 | 17.0s |  |
| 64 | `timeline_var_test` | 11 | 17.0s |  |
| 65 | `unload_movieclip_test1` | 6 | 17.1s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 17.9s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 17.6s |  |
| 3 | `DefineTextTest` | 4 | 4 | 17.6s |  |
| 4 | `DragDropTest` | 12 | 12 | 0.3s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 18.0s |  |
| 6 | `action_order/action_execution_order_test4` | 7 | 26 | 0.4s |  |
| 7 | `callFunction_test` | 5 | 11 | 17.3s |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 17.9s |  |
| 9 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.3s |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 18.2s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 18.1s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 18.2s |  |
| 14 | `key_event_test` | 5 | 6 | 17.2s |  |
| 15 | `loading/loadMovieTest` | 9 | 9 | 17.4s |  |
| 16 | `loop/loop_test10` | 23 | 23 | 17.1s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 18.0s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 19 | `matrix_test` | 5 | 9 | 20.8s |  |
| 20 | `path_format_test` | 28 | 28 | 18.1s |  |
| 21 | `place_object_test` | 14 | 14 | 18.2s |  |
| 22 | `place_object_test2` | 20 | 23 | 18.2s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 14.9s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 14.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 2 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 5 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 5 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 6 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 7 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 8 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 9 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 10 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 11 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 12 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 13 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
