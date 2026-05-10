# Ruffle Test Results (Filtered)

**Date**: 2026-05-10 23:40 UTC

**Git SHA**: `e527f41066`

**Run Duration**: 25m 11s

**Filtered**: 2 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **47** (47.0%) |
| Ruffle-matched | 16 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **63** (63.0%) |
| Failing | 37 |
| Total expected lines | 4445 |
| Matching lines | 2802 (63.0%) |
| Mismatched lines | 1643 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 34 | 91.9% |
| Segfault | 3 | 8.1% |

## Passing Tests

**47 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.2s |  |
| 2 | `DefineEditTextTest` | 153 | 18.6s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 18.5s |  |
| 4 | `PlaceObject2Test` | 9 | 17.5s |  |
| 5 | `RollOverOutTest` | 5 | 17.5s |  |
| 6 | `VarAndCharClashTest` | 13 | 0.8s |  |
| 7 | `Video-EmbedSquareTest` | 2 | 17.9s |  |
| 8 | `action_order/action_execution_order_test1` | 10 | 18.0s |  |
| 9 | `action_order/action_execution_order_test2` | 5 | 14.3s |  |
| 10 | `action_order/action_execution_order_test3` | 4 | 14.7s |  |
| 11 | `action_order/action_execution_order_test7` | 7 | 19.3s |  |
| 12 | `action_order/action_execution_order_test9` | 4 | 19.3s |  |
| 13 | `attachExtImported` | 2 | 19.6s |  |
| 14 | `attachImported` | 2 | 0.9s |  |
| 15 | `attachMovieLoopingTest` | 41 | 19.4s |  |
| 16 | `attachMovieTest` | 12 | 18.7s |  |
| 17 | `consecutive_goto_frame_test` | 12 | 18.3s |  |
| 18 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.3s |  |
| 19 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.1s |  |
| 20 | `displaylist_depths/displaylist_depths_test4` | 26 | 18.8s |  |
| 21 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.9s |  |
| 22 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.9s |  |
| 23 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.9s |  |
| 24 | `event_handler_scope_test` | 16 | 19.0s |  |
| 25 | `frame_label_test` | 17 | 0.9s |  |
| 26 | `getTimer_test` | 8 | 18.0s |  |
| 27 | `instanceNameTest` | 5 | 0.7s |  |
| 28 | `loading/LoadVarsTest` | 36 | 18.6s |  |
| 29 | `loop/loop_test` | 21 | 18.2s |  |
| 30 | `loop/loop_test2` | 15 | 17.8s |  |
| 31 | `loop/loop_test3` | 16 | 19.0s |  |
| 32 | `loop/loop_test4` | 22 | 18.8s |  |
| 33 | `loop/loop_test5` | 24 | 1.0s |  |
| 34 | `loop/loop_test9` | 15 | 17.6s |  |
| 35 | `loop/simple_loop_test` | 0 | 17.9s |  |
| 36 | `masks_test2` | 10 | 18.5s |  |
| 37 | `morph_test1` | 0 | 18.6s |  |
| 38 | `move_object_test` | 11 | 18.1s |  |
| 39 | `multi_doactions_and_goto_frame_test` | 6 | 18.1s |  |
| 40 | `new_child_in_unload_test` | 11 | 18.2s |  |
| 41 | `register_class/RegisterClassTest3` | 12 | 17.9s |  |
| 42 | `register_class/registerClassTest` | 51 | 17.9s |  |
| 43 | `replace_sprites1test` | 21 | 19.0s |  |
| 44 | `reverse_execute_PlaceObject2_test1` | 8 | 19.7s |  |
| 45 | `reverse_execute_PlaceObject2_test2` | 10 | 19.7s |  |
| 46 | `runtime_vm_stack_test` | 9 | 18.4s |  |
| 47 | `unload_movieclip_test1` | 6 | 18.1s |  |

## Ruffle-Matched Tests

**16 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `DefineTextTest` | 4 | 4 | 17.7s |  |
| 2 | `action_order/action_execution_order_test4` | 7 | 26 | 0.8s |  |
| 3 | `callFunction_test` | 5 | 11 | 18.8s |  |
| 4 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.9s |  |
| 5 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.9s |  |
| 6 | `init_action/InitActionTest` | 6 | 17 | 14.5s |  |
| 7 | `init_action/InitActionTest2` | 24 | 30 | 14.6s |  |
| 8 | `loop/loop_test10` | 23 | 23 | 18.1s |  |
| 9 | `loop/loop_test6` | 1 | 12 | 18.4s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 1.0s |  |
| 11 | `matrix_test` | 5 | 9 | 22.2s |  |
| 12 | `path_format_test` | 28 | 28 | 18.9s |  |
| 13 | `place_object_test` | 14 | 14 | 17.7s |  |
| 14 | `place_object_test2` | 20 | 23 | 17.7s |  |
| 15 | `register_class/registerClassTest2` | 8 | 28 | 18.0s |  |
| 16 | `replace_buttons1test` | 3 | 3 | 18.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**18 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loop/loop_test8` | 92.1% | 35 | 38 | 3 |  |
| 2 | `get_frame_number_test` | 90.3% | 28 | 31 | 3 |  |
| 3 | `action_order/action_execution_order_test8-v5` | 81.8% | 9 | 11 | 2 |  |
| 4 | `action_order/action_execution_order_test8-v6` | 81.8% | 9 | 11 | 2 |  |
| 5 | `DrawingApiTest` | 81.6% | 80 | 98 | 18 |  |
| 6 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 7 | `ResolveEventsTest` | 80.0% | 12 | 15 | 3 |  |
| 8 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 9 | `place_and_remove_object_test` | 69.2% | 9 | 13 | 4 |  |
| 10 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 11 | `static_vs_dynamic1` | 64.7% | 11 | 17 | 6 |  |
| 12 | `shape_test` | 61.9% | 13 | 21 | 8 |  |
| 13 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 14 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 15 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9 | 16 | 7 |  |
| 16 | `displaylist_depths/displaylist_depths_test` | 55.0% | 61 | 111 | 50 |  |
| 17 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 18 | `duplicate_movie_clip_test2` | 52.4% | 11 | 21 | 10 |  |

## Segfaults

**3 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 20.4s |  |
| 2 | `ButtonPropertiesTest` | 20.5s |  |
| 3 | `DefineEditTextVariableNameTest` | 21.0s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**34 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loop/loop_test8` | 92.1% | 35/38 | 38 | 38 |  |
| 2 | `get_frame_number_test` | 90.3% | 28/31 | 31 | 31 |  |
| 3 | `action_order/action_execution_order_test8-v5` | 81.8% | 9/11 | 11 | 11 |  |
| 4 | `action_order/action_execution_order_test8-v6` | 81.8% | 9/11 | 11 | 11 |  |
| 5 | `DrawingApiTest` | 81.6% | 80/98 | 98 | 93 |  |
| 6 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 7 | `ResolveEventsTest` | 80.0% | 12/15 | 15 | 15 |  |
| 8 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 9 | `place_and_remove_object_test` | 69.2% | 9/13 | 13 | 13 |  |
| 10 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 11 | `static_vs_dynamic1` | 64.7% | 11/17 | 17 | 17 |  |
| 12 | `shape_test` | 61.9% | 13/21 | 21 | 21 |  |
| 13 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 14 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 15 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9/16 | 16 | 15 |  |
| 16 | `displaylist_depths/displaylist_depths_test` | 55.0% | 61/111 | 111 | 111 |  |
| 17 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 18 | `duplicate_movie_clip_test2` | 52.4% | 11/21 | 21 | 21 |  |
| 19 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 20 | `goto_frame_test` | 40.0% | 6/15 | 15 | 15 |  |
| 21 | `loading/loadMovieTest` | 36.8% | 67/182 | 182 | 80 |  |
| 22 | `masks_test` | 34.9% | 61/175 | 69 | 175 |  |
| 23 | `key_event_test` | 34.8% | 23/66 | 51 | 66 |  |
| 24 | `replace_shapes1test` | 34.8% | 8/23 | 23 | 23 |  |
| 25 | `NetStream-SquareTest` | 33.3% | 72/216 | 131 | 216 |  |
| 26 | `static_vs_dynamic2` | 33.3% | 6/18 | 18 | 18 |  |
| 27 | `KeyEventOrder` | 25.0% | 8/32 | 32 | 26 |  |
| 28 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 29 | `action_order/ActionOrderTest5` | 11.5% | 7/61 | 61 | 51 |  |
| 30 | `action_order/ActionOrderTest4` | 5.4% | 4/74 | 74 | 64 |  |
| 31 | `action_order/ActionOrderTest3` | 5.3% | 4/75 | 75 | 62 |  |
| 32 | `duplicate_movie_clip_test` | 3.0% | 1/33 | 29 | 33 |  |
| 33 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 34 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
