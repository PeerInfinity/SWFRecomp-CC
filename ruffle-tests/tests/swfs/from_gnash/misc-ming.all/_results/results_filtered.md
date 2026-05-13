# Ruffle Test Results (Filtered)

**Date**: 2026-05-13 03:29 UTC

**Git SHA**: `066b68ca2a`

**Run Duration**: 29m 44s

**Filtered**: 2 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **66** (66.0%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **90** (90.0%) |
| Failing | 10 |
| Total expected lines | 4517 |
| Matching lines | 3746 (82.9%) |
| Mismatched lines | 771 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 100.0% |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.2s |  |
| 2 | `DefineEditTextTest` | 153 | 28.1s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 27.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.9s |  |
| 5 | `DepthLimitsTest` | 20 | 22.0s |  |
| 6 | `PlaceObject2Test` | 9 | 15.8s |  |
| 7 | `ResolveEventsTest` | 15 | 2.8s |  |
| 8 | `RollOverOutTest` | 5 | 17.4s |  |
| 9 | `VarAndCharClashTest` | 13 | 1.7s |  |
| 10 | `Version4Loader` | 11 | 1.6s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 19.3s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 19.1s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.8s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.9s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 18.9s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 19.3s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 19.2s |  |
| 19 | `attachExtImported` | 2 | 20.8s |  |
| 20 | `attachImported` | 2 | 1.8s |  |
| 21 | `attachMovieLoopingTest` | 41 | 19.5s |  |
| 22 | `attachMovieTest` | 12 | 20.1s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 19.7s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.8s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.8s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 20.0s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.8s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.2s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 18.7s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 2.6s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 20.6s |  |
| 33 | `event_handler_scope_test` | 16 | 19.6s |  |
| 34 | `frame_label_test` | 17 | 3.2s |  |
| 35 | `getTimer_test` | 8 | 18.6s |  |
| 36 | `get_frame_number_test` | 31 | 20.9s |  |
| 37 | `goto_frame_test` | 15 | 19.1s |  |
| 38 | `instanceNameTest` | 5 | 1.5s |  |
| 39 | `loading/LoadVarsTest` | 36 | 22.6s |  |
| 40 | `loop/loop_test` | 21 | 19.2s |  |
| 41 | `loop/loop_test2` | 15 | 19.1s |  |
| 42 | `loop/loop_test3` | 16 | 19.4s |  |
| 43 | `loop/loop_test4` | 22 | 20.2s |  |
| 44 | `loop/loop_test5` | 24 | 2.9s |  |
| 45 | `loop/loop_test8` | 38 | 21.1s |  |
| 46 | `loop/loop_test9` | 15 | 21.0s |  |
| 47 | `loop/simple_loop_test` | 0 | 20.3s |  |
| 48 | `masks_test2` | 10 | 15.7s |  |
| 49 | `morph_test1` | 0 | 15.7s |  |
| 50 | `move_object_test` | 11 | 18.8s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 18.9s |  |
| 52 | `new_child_in_unload_test` | 11 | 18.9s |  |
| 53 | `place_and_remove_object_insane_test` | 22 | 19.3s |  |
| 54 | `place_and_remove_object_test` | 13 | 20.0s |  |
| 55 | `register_class/RegisterClassTest3` | 12 | 19.4s |  |
| 56 | `register_class/registerClassTest` | 51 | 21.9s |  |
| 57 | `replace_shapes1test` | 23 | 2.3s |  |
| 58 | `replace_sprites1test` | 21 | 19.8s |  |
| 59 | `reverse_execute_PlaceObject2_test1` | 8 | 19.3s |  |
| 60 | `reverse_execute_PlaceObject2_test2` | 10 | 19.6s |  |
| 61 | `runtime_vm_stack_test` | 9 | 19.6s |  |
| 62 | `shape_test` | 21 | 20.8s |  |
| 63 | `static_vs_dynamic1` | 17 | 19.2s |  |
| 64 | `static_vs_dynamic2` | 18 | 19.9s |  |
| 65 | `timeline_var_test` | 11 | 19.8s |  |
| 66 | `unload_movieclip_test1` | 6 | 19.2s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonEventsTest` | 3 | 642 | 24.2s |  |
| 2 | `ButtonPropertiesTest` | 19 | 20 | 19.2s |  |
| 3 | `DefineTextTest` | 4 | 4 | 21.0s |  |
| 4 | `DragDropTest` | 12 | 12 | 2.8s |  |
| 5 | `KeyEventOrder` | 20 | 23 | 18.8s |  |
| 6 | `action_order/action_execution_order_test4` | 7 | 26 | 3.1s |  |
| 7 | `callFunction_test` | 5 | 11 | 20.6s |  |
| 8 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.3s |  |
| 9 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.0s |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.9s |  |
| 11 | `duplicate_movie_clip_test` | 4 | 4 | 20.2s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 20.1s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 20.9s |  |
| 14 | `key_event_test` | 5 | 6 | 20.4s |  |
| 15 | `loading/loadMovieTest` | 9 | 9 | 21.5s |  |
| 16 | `loop/loop_test10` | 23 | 23 | 19.9s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 19.9s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 2.1s |  |
| 19 | `matrix_test` | 5 | 9 | 92.6s |  |
| 20 | `path_format_test` | 28 | 28 | 21.3s |  |
| 21 | `place_object_test` | 14 | 14 | 20.5s |  |
| 22 | `place_object_test2` | 20 | 23 | 20.2s |  |
| 23 | `register_class/registerClassTest2` | 8 | 28 | 20.9s |  |
| 24 | `replace_buttons1test` | 3 | 3 | 19.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**10 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 4 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 5 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 6 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 7 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 8 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 9 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 10 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
