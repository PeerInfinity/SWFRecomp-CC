# Ruffle Test Results (Filtered)

**Date**: 2026-05-11 01:17 UTC

**Git SHA**: `0fcfe324ea`

**Run Duration**: 1m 44s

**Filtered**: 2 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **48** (48.0%) |
| Ruffle-matched | 17 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **65** (65.0%) |
| Failing | 35 |
| Total expected lines | 4445 |
| Matching lines | 2834 (63.8%) |
| Mismatched lines | 1611 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 32 | 91.4% |
| Segfault | 3 | 8.6% |

## Passing Tests

**48 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.9s |  |
| 2 | `DefineEditTextTest` | 153 | 1.5s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 1.0s |  |
| 4 | `PlaceObject2Test` | 9 | 0.8s |  |
| 5 | `RollOverOutTest` | 5 | 0.8s |  |
| 6 | `VarAndCharClashTest` | 13 | 0.8s |  |
| 7 | `Version4Loader` | 11 | 0.9s |  |
| 8 | `Video-EmbedSquareTest` | 2 | 0.9s |  |
| 9 | `action_order/action_execution_order_test1` | 10 | 0.7s |  |
| 10 | `action_order/action_execution_order_test2` | 5 | 0.8s |  |
| 11 | `action_order/action_execution_order_test3` | 4 | 0.8s |  |
| 12 | `action_order/action_execution_order_test7` | 7 | 0.7s |  |
| 13 | `action_order/action_execution_order_test9` | 4 | 0.6s |  |
| 14 | `attachExtImported` | 2 | 0.6s |  |
| 15 | `attachImported` | 2 | 0.6s |  |
| 16 | `attachMovieLoopingTest` | 41 | 0.6s |  |
| 17 | `attachMovieTest` | 12 | 0.8s |  |
| 18 | `consecutive_goto_frame_test` | 12 | 0.7s |  |
| 19 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.8s |  |
| 20 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.8s |  |
| 21 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.7s |  |
| 22 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.7s |  |
| 23 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.7s |  |
| 24 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.8s |  |
| 25 | `event_handler_scope_test` | 16 | 0.7s |  |
| 26 | `frame_label_test` | 17 | 0.7s |  |
| 27 | `getTimer_test` | 8 | 0.6s |  |
| 28 | `instanceNameTest` | 5 | 0.7s |  |
| 29 | `loading/LoadVarsTest` | 36 | 1.1s |  |
| 30 | `loop/loop_test` | 21 | 0.8s |  |
| 31 | `loop/loop_test2` | 15 | 0.7s |  |
| 32 | `loop/loop_test3` | 16 | 0.8s |  |
| 33 | `loop/loop_test4` | 22 | 0.7s |  |
| 34 | `loop/loop_test5` | 24 | 0.7s |  |
| 35 | `loop/loop_test9` | 15 | 1.0s |  |
| 36 | `loop/simple_loop_test` | 0 | 0.9s |  |
| 37 | `masks_test2` | 10 | 1.0s |  |
| 38 | `morph_test1` | 0 | 0.9s |  |
| 39 | `move_object_test` | 11 | 0.9s |  |
| 40 | `multi_doactions_and_goto_frame_test` | 6 | 1.2s |  |
| 41 | `new_child_in_unload_test` | 11 | 0.8s |  |
| 42 | `register_class/RegisterClassTest3` | 12 | 1.0s |  |
| 43 | `register_class/registerClassTest` | 51 | 0.9s |  |
| 44 | `replace_sprites1test` | 21 | 0.9s |  |
| 45 | `reverse_execute_PlaceObject2_test1` | 8 | 0.8s |  |
| 46 | `reverse_execute_PlaceObject2_test2` | 10 | 0.8s |  |
| 47 | `runtime_vm_stack_test` | 9 | 1.0s |  |
| 48 | `unload_movieclip_test1` | 6 | 0.8s |  |

## Ruffle-Matched Tests

**17 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `DefineTextTest` | 4 | 4 | 0.8s |  |
| 2 | `DragDropTest` | 12 | 12 | 0.8s |  |
| 3 | `action_order/action_execution_order_test4` | 7 | 26 | 0.9s |  |
| 4 | `callFunction_test` | 5 | 11 | 0.7s |  |
| 5 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.7s |  |
| 6 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.8s |  |
| 7 | `init_action/InitActionTest` | 6 | 17 | 0.7s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 0.8s |  |
| 9 | `loop/loop_test10` | 23 | 23 | 0.8s |  |
| 10 | `loop/loop_test6` | 1 | 12 | 0.8s |  |
| 11 | `loop/loop_test7` | 1 | 8 | 0.7s |  |
| 12 | `matrix_test` | 5 | 9 | 5.4s |  |
| 13 | `path_format_test` | 28 | 28 | 0.9s |  |
| 14 | `place_object_test` | 14 | 14 | 0.8s |  |
| 15 | `place_object_test2` | 20 | 23 | 0.8s |  |
| 16 | `register_class/registerClassTest2` | 8 | 28 | 0.9s |  |
| 17 | `replace_buttons1test` | 3 | 3 | 0.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**17 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loop/loop_test8` | 92.1% | 35 | 38 | 3 |  |
| 2 | `get_frame_number_test` | 90.3% | 28 | 31 | 3 |  |
| 3 | `ResolveEventsTest` | 86.7% | 13 | 15 | 2 |  |
| 4 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 5 | `action_order/action_execution_order_test8-v5` | 81.8% | 9 | 11 | 2 |  |
| 6 | `action_order/action_execution_order_test8-v6` | 81.8% | 9 | 11 | 2 |  |
| 7 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 8 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 9 | `place_and_remove_object_test` | 69.2% | 9 | 13 | 4 |  |
| 10 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 11 | `static_vs_dynamic1` | 64.7% | 11 | 17 | 6 |  |
| 12 | `shape_test` | 61.9% | 13 | 21 | 8 |  |
| 13 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 14 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9 | 16 | 7 |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 55.0% | 61 | 111 | 50 |  |
| 16 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 17 | `duplicate_movie_clip_test2` | 52.4% | 11 | 21 | 10 |  |

## Segfaults

**3 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 2.9s |  |
| 2 | `ButtonPropertiesTest` | 2.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 3.0s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**32 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loop/loop_test8` | 92.1% | 35/38 | 38 | 38 |  |
| 2 | `get_frame_number_test` | 90.3% | 28/31 | 31 | 31 |  |
| 3 | `ResolveEventsTest` | 86.7% | 13/15 | 15 | 15 |  |
| 4 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 5 | `action_order/action_execution_order_test8-v5` | 81.8% | 9/11 | 11 | 11 |  |
| 6 | `action_order/action_execution_order_test8-v6` | 81.8% | 9/11 | 11 | 11 |  |
| 7 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 8 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 9 | `place_and_remove_object_test` | 69.2% | 9/13 | 13 | 13 |  |
| 10 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 11 | `static_vs_dynamic1` | 64.7% | 11/17 | 17 | 17 |  |
| 12 | `shape_test` | 61.9% | 13/21 | 21 | 21 |  |
| 13 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 14 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9/16 | 16 | 15 |  |
| 15 | `displaylist_depths/displaylist_depths_test` | 55.0% | 61/111 | 111 | 111 |  |
| 16 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 17 | `duplicate_movie_clip_test2` | 52.4% | 11/21 | 21 | 21 |  |
| 18 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 19 | `goto_frame_test` | 40.0% | 6/15 | 15 | 15 |  |
| 20 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 21 | `loading/loadMovieTest` | 36.8% | 67/182 | 182 | 80 |  |
| 22 | `masks_test` | 34.9% | 61/175 | 69 | 175 |  |
| 23 | `key_event_test` | 34.8% | 23/66 | 51 | 66 |  |
| 24 | `replace_shapes1test` | 34.8% | 8/23 | 23 | 23 |  |
| 25 | `static_vs_dynamic2` | 33.3% | 6/18 | 18 | 18 |  |
| 26 | `KeyEventOrder` | 25.0% | 8/32 | 32 | 26 |  |
| 27 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 28 | `action_order/ActionOrderTest5` | 11.5% | 7/61 | 61 | 51 |  |
| 29 | `action_order/ActionOrderTest4` | 5.4% | 4/74 | 74 | 64 |  |
| 30 | `action_order/ActionOrderTest3` | 5.3% | 4/75 | 75 | 62 |  |
| 31 | `duplicate_movie_clip_test` | 3.0% | 1/33 | 29 | 33 |  |
| 32 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
