# Ruffle Test Results (Filtered)

**Date**: 2026-05-08 20:08 UTC

**Git SHA**: `84a147bd4f`

**Run Duration**: 1m 0s

**Filtered**: 1 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 101 |
| Passing | **65** (64.4%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **89** (88.1%) |
| Failing | 12 |
| Total expected lines | 4559 |
| Matching lines | 3726 (81.7%) |
| Mismatched lines | 833 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 12 | 100.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.5s |  |
| 2 | `DefineEditTextTest` | 153 | 1.0s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 0.6s |  |
| 4 | `DepthLimitsTest` | 20 | 0.5s |  |
| 5 | `PlaceObject2Test` | 9 | 0.4s |  |
| 6 | `ResolveEventsTest` | 15 | 0.5s |  |
| 7 | `RollOverOutTest` | 5 | 0.4s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.4s |  |
| 9 | `Version4Loader` | 11 | 0.5s |  |
| 10 | `Video-EmbedSquareTest` | 2 | 0.4s |  |
| 11 | `action_order/action_execution_order_test1` | 10 | 0.4s |  |
| 12 | `action_order/action_execution_order_test2` | 5 | 0.4s |  |
| 13 | `action_order/action_execution_order_test3` | 4 | 0.4s |  |
| 14 | `action_order/action_execution_order_test7` | 7 | 0.4s |  |
| 15 | `action_order/action_execution_order_test8-v5` | 11 | 0.4s |  |
| 16 | `action_order/action_execution_order_test8-v6` | 11 | 0.2s |  |
| 17 | `action_order/action_execution_order_test9` | 4 | 0.4s |  |
| 18 | `attachExtImported` | 2 | 0.5s |  |
| 19 | `attachImported` | 2 | 0.5s |  |
| 20 | `attachMovieLoopingTest` | 41 | 0.4s |  |
| 21 | `attachMovieTest` | 12 | 0.5s |  |
| 22 | `consecutive_goto_frame_test` | 12 | 0.4s |  |
| 23 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.4s |  |
| 24 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.4s |  |
| 26 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.4s |  |
| 28 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test8` | 15 | 0.4s |  |
| 30 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.5s |  |
| 31 | `duplicate_movie_clip_test2` | 21 | 0.5s |  |
| 32 | `event_handler_scope_test` | 16 | 0.4s |  |
| 33 | `frame_label_test` | 17 | 0.5s |  |
| 34 | `getTimer_test` | 8 | 0.4s |  |
| 35 | `get_frame_number_test` | 31 | 0.5s |  |
| 36 | `goto_frame_test` | 15 | 0.4s |  |
| 37 | `instanceNameTest` | 5 | 0.3s |  |
| 38 | `loading/LoadVarsTest` | 36 | 0.6s |  |
| 39 | `loop/loop_test` | 21 | 0.5s |  |
| 40 | `loop/loop_test2` | 15 | 0.4s |  |
| 41 | `loop/loop_test3` | 16 | 0.4s |  |
| 42 | `loop/loop_test4` | 22 | 0.5s |  |
| 43 | `loop/loop_test5` | 24 | 0.5s |  |
| 44 | `loop/loop_test8` | 38 | 0.5s |  |
| 45 | `loop/loop_test9` | 15 | 0.4s |  |
| 46 | `loop/simple_loop_test` | 0 | 0.4s |  |
| 47 | `masks_test2` | 10 | 0.4s |  |
| 48 | `morph_test1` | 0 | 0.4s |  |
| 49 | `move_object_test` | 11 | 0.4s |  |
| 50 | `multi_doactions_and_goto_frame_test` | 6 | 0.4s |  |
| 51 | `new_child_in_unload_test` | 11 | 0.4s |  |
| 52 | `place_and_remove_object_insane_test` | 22 | 0.4s |  |
| 53 | `place_and_remove_object_test` | 13 | 0.4s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 0.8s |  |
| 55 | `register_class/registerClassTest` | 51 | 0.6s |  |
| 56 | `replace_shapes1test` | 23 | 0.4s |  |
| 57 | `replace_sprites1test` | 21 | 0.5s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 0.5s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 0.5s |  |
| 60 | `runtime_vm_stack_test` | 9 | 0.4s |  |
| 61 | `shape_test` | 21 | 0.5s |  |
| 62 | `static_vs_dynamic1` | 17 | 0.4s |  |
| 63 | `static_vs_dynamic2` | 18 | 0.4s |  |
| 64 | `timeline_var_test` | 11 | 0.4s |  |
| 65 | `unload_movieclip_test1` | 6 | 0.4s |  |

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
| 8 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 0.8s |  |
| 9 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.4s |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.4s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 0.5s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 0.4s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 0.4s |  |
| 14 | `key_event_test` | 5 | 6 | 0.5s |  |
| 15 | `loading/loadMovieTest` | 9 | 9 | 0.5s |  |
| 16 | `loop/loop_test10` | 23 | 23 | 0.5s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 0.5s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 0.4s |  |
| 19 | `matrix_test` | 5 | 9 | 5.3s |  |
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
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 2 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |

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
| 1 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 2 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 5 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 6 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 7 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 8 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 9 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 10 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 11 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 12 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
