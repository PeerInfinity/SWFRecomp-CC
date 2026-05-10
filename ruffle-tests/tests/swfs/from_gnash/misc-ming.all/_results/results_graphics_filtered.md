# Ruffle Test Results (Filtered)

**Date**: 2026-05-10 21:29 UTC

**Git SHA**: `7767c2657e`

**Run Duration**: 1m 52s

**Filtered**: 2 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **43** (43.0%) |
| Ruffle-matched | 14 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **57** (57.0%) |
| Failing | 43 |
| Total expected lines | 4445 |
| Matching lines | 2760 (62.1%) |
| Mismatched lines | 1685 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 40 | 93.0% |
| Segfault | 3 | 7.0% |

## Passing Tests

**43 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.8s |  |
| 2 | `DefineEditTextTest` | 153 | 1.4s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 1.0s |  |
| 4 | `PlaceObject2Test` | 9 | 0.9s |  |
| 5 | `RollOverOutTest` | 5 | 0.9s |  |
| 6 | `VarAndCharClashTest` | 13 | 1.6s |  |
| 7 | `Video-EmbedSquareTest` | 2 | 1.7s |  |
| 8 | `action_order/action_execution_order_test1` | 10 | 0.9s |  |
| 9 | `action_order/action_execution_order_test3` | 4 | 0.8s |  |
| 10 | `action_order/action_execution_order_test7` | 7 | 0.8s |  |
| 11 | `action_order/action_execution_order_test9` | 4 | 0.8s |  |
| 12 | `attachExtImported` | 2 | 0.9s |  |
| 13 | `attachImported` | 2 | 0.8s |  |
| 14 | `attachMovieLoopingTest` | 41 | 0.7s |  |
| 15 | `attachMovieTest` | 12 | 0.8s |  |
| 16 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.8s |  |
| 17 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.8s |  |
| 18 | `displaylist_depths/displaylist_depths_test4` | 26 | 1.0s |  |
| 19 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.9s |  |
| 20 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.9s |  |
| 21 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.9s |  |
| 22 | `getTimer_test` | 8 | 0.8s |  |
| 23 | `instanceNameTest` | 5 | 0.7s |  |
| 24 | `loading/LoadVarsTest` | 36 | 0.9s |  |
| 25 | `loop/loop_test` | 21 | 0.9s |  |
| 26 | `loop/loop_test2` | 15 | 0.7s |  |
| 27 | `loop/loop_test3` | 16 | 0.8s |  |
| 28 | `loop/loop_test4` | 22 | 0.8s |  |
| 29 | `loop/loop_test5` | 24 | 0.8s |  |
| 30 | `loop/loop_test9` | 15 | 0.8s |  |
| 31 | `loop/simple_loop_test` | 0 | 0.9s |  |
| 32 | `masks_test2` | 10 | 0.9s |  |
| 33 | `morph_test1` | 0 | 0.9s |  |
| 34 | `move_object_test` | 11 | 0.8s |  |
| 35 | `multi_doactions_and_goto_frame_test` | 6 | 0.8s |  |
| 36 | `new_child_in_unload_test` | 11 | 0.8s |  |
| 37 | `register_class/RegisterClassTest3` | 12 | 1.3s |  |
| 38 | `register_class/registerClassTest` | 51 | 1.0s |  |
| 39 | `replace_sprites1test` | 21 | 0.9s |  |
| 40 | `reverse_execute_PlaceObject2_test1` | 8 | 0.9s |  |
| 41 | `reverse_execute_PlaceObject2_test2` | 10 | 0.9s |  |
| 42 | `runtime_vm_stack_test` | 9 | 0.8s |  |
| 43 | `unload_movieclip_test1` | 6 | 0.8s |  |

## Ruffle-Matched Tests

**14 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `DefineTextTest` | 4 | 4 | 0.9s |  |
| 2 | `callFunction_test` | 11 | 11 | 0.8s |  |
| 3 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.8s |  |
| 4 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.8s |  |
| 5 | `init_action/InitActionTest` | 6 | 17 | 0.8s |  |
| 6 | `init_action/InitActionTest2` | 24 | 30 | 0.9s |  |
| 7 | `loop/loop_test6` | 1 | 12 | 0.9s |  |
| 8 | `loop/loop_test7` | 1 | 8 | 0.9s |  |
| 9 | `matrix_test` | 5 | 9 | 4.4s |  |
| 10 | `path_format_test` | 27 | 28 | 1.0s |  |
| 11 | `place_object_test` | 14 | 14 | 0.9s |  |
| 12 | `place_object_test2` | 20 | 23 | 0.9s |  |
| 13 | `register_class/registerClassTest2` | 8 | 28 | 0.8s |  |
| 14 | `replace_buttons1test` | 3 | 3 | 0.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**17 tests** within reach

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

## Segfaults

**3 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 3.2s |  |
| 2 | `ButtonPropertiesTest` | 3.0s |  |
| 3 | `DefineEditTextVariableNameTest` | 2.9s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**40 tests** with output mismatch, sorted by match rate (best first)

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
| 18 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 19 | `goto_frame_test` | 46.7% | 7/15 | 15 | 15 |  |
| 20 | `loading/loadMovieTest` | 36.8% | 67/182 | 182 | 80 |  |
| 21 | `masks_test` | 34.9% | 61/175 | 69 | 175 |  |
| 22 | `key_event_test` | 34.8% | 23/66 | 51 | 66 |  |
| 23 | `replace_shapes1test` | 34.8% | 8/23 | 23 | 23 |  |
| 24 | `NetStream-SquareTest` | 33.3% | 72/216 | 131 | 216 |  |
| 25 | `static_vs_dynamic2` | 33.3% | 6/18 | 18 | 18 |  |
| 26 | `KeyEventOrder` | 25.0% | 8/32 | 32 | 26 |  |
| 27 | `action_order/action_execution_order_test2` | 20.0% | 1/5 | 1 | 5 |  |
| 28 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 29 | `duplicate_movie_clip_test` | 12.1% | 4/33 | 29 | 33 |  |
| 30 | `event_handler_scope_test` | 12.1% | 11/91 | 91 | 16 |  |
| 31 | `duplicate_movie_clip_test2` | 12.0% | 10/83 | 83 | 21 |  |
| 32 | `action_order/ActionOrderTest5` | 11.5% | 7/61 | 61 | 51 |  |
| 33 | `loop/loop_test10` | 9.3% | 5/54 | 54 | 28 |  |
| 34 | `action_order/action_execution_order_test4` | 7.3% | 13/179 | 179 | 26 |  |
| 35 | `action_order/ActionOrderTest4` | 5.4% | 4/74 | 74 | 64 |  |
| 36 | `action_order/ActionOrderTest3` | 5.3% | 4/75 | 75 | 62 |  |
| 37 | `consecutive_goto_frame_test` | 2.5% | 5/201 | 201 | 12 |  |
| 38 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 39 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
| 40 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
