# Ruffle Test Results (Filtered)

**Date**: 2026-05-11 03:59 UTC

**Git SHA**: `be795aae22`

**Run Duration**: 24m 41s

**Filtered**: 2 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **52** (52.0%) |
| Ruffle-matched | 17 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **69** (69.0%) |
| Failing | 31 |
| Total expected lines | 4517 |
| Matching lines | 2937 (65.0%) |
| Mismatched lines | 1580 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 29 | 93.5% |
| Segfault | 2 | 6.5% |

## Passing Tests

**52 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 18.8s |  |
| 2 | `DefineEditTextTest` | 153 | 19.5s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 18.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 18.7s |  |
| 5 | `PlaceObject2Test` | 9 | 17.6s |  |
| 6 | `RollOverOutTest` | 5 | 17.7s |  |
| 7 | `VarAndCharClashTest` | 13 | 0.9s |  |
| 8 | `Version4Loader` | 11 | 0.9s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 17.8s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 19.4s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 14.5s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 14.6s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 14.4s |  |
| 14 | `action_order/action_execution_order_test9` | 4 | 18.1s |  |
| 15 | `attachExtImported` | 2 | 18.1s |  |
| 16 | `attachImported` | 2 | 0.9s |  |
| 17 | `attachMovieLoopingTest` | 41 | 18.1s |  |
| 18 | `attachMovieTest` | 12 | 17.5s |  |
| 19 | `consecutive_goto_frame_test` | 12 | 17.6s |  |
| 20 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.4s |  |
| 21 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.3s |  |
| 22 | `displaylist_depths/displaylist_depths_test4` | 26 | 18.5s |  |
| 23 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.0s |  |
| 24 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 26 | `event_handler_scope_test` | 16 | 19.4s |  |
| 27 | `frame_label_test` | 17 | 0.8s |  |
| 28 | `getTimer_test` | 8 | 14.6s |  |
| 29 | `instanceNameTest` | 5 | 0.9s |  |
| 30 | `loading/LoadVarsTest` | 36 | 18.7s |  |
| 31 | `loop/loop_test` | 21 | 17.8s |  |
| 32 | `loop/loop_test2` | 15 | 17.7s |  |
| 33 | `loop/loop_test3` | 16 | 18.7s |  |
| 34 | `loop/loop_test4` | 22 | 18.8s |  |
| 35 | `loop/loop_test5` | 24 | 1.1s |  |
| 36 | `loop/loop_test8` | 38 | 17.6s |  |
| 37 | `loop/loop_test9` | 15 | 18.6s |  |
| 38 | `loop/simple_loop_test` | 0 | 18.5s |  |
| 39 | `masks_test2` | 10 | 17.8s |  |
| 40 | `morph_test1` | 0 | 17.9s |  |
| 41 | `move_object_test` | 11 | 19.7s |  |
| 42 | `multi_doactions_and_goto_frame_test` | 6 | 20.0s |  |
| 43 | `new_child_in_unload_test` | 11 | 19.4s |  |
| 44 | `register_class/RegisterClassTest3` | 12 | 14.3s |  |
| 45 | `register_class/registerClassTest` | 51 | 14.4s |  |
| 46 | `replace_shapes1test` | 23 | 0.9s |  |
| 47 | `replace_sprites1test` | 21 | 17.8s |  |
| 48 | `reverse_execute_PlaceObject2_test1` | 8 | 17.6s |  |
| 49 | `reverse_execute_PlaceObject2_test2` | 10 | 17.8s |  |
| 50 | `runtime_vm_stack_test` | 9 | 18.1s |  |
| 51 | `shape_test` | 21 | 18.1s |  |
| 52 | `unload_movieclip_test1` | 6 | 17.8s |  |

## Ruffle-Matched Tests

**17 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `DefineTextTest` | 4 | 4 | 18.7s |  |
| 2 | `DragDropTest` | 12 | 12 | 1.0s |  |
| 3 | `action_order/action_execution_order_test4` | 7 | 26 | 0.8s |  |
| 4 | `callFunction_test` | 5 | 11 | 17.6s |  |
| 5 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 1.0s |  |
| 6 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.0s |  |
| 7 | `init_action/InitActionTest` | 6 | 17 | 20.6s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 20.9s |  |
| 9 | `loop/loop_test10` | 23 | 23 | 17.8s |  |
| 10 | `loop/loop_test6` | 1 | 12 | 17.5s |  |
| 11 | `loop/loop_test7` | 1 | 8 | 0.9s |  |
| 12 | `matrix_test` | 5 | 9 | 21.7s |  |
| 13 | `path_format_test` | 28 | 28 | 18.3s |  |
| 14 | `place_object_test` | 14 | 14 | 18.2s |  |
| 15 | `place_object_test2` | 20 | 23 | 18.0s |  |
| 16 | `register_class/registerClassTest2` | 8 | 28 | 17.8s |  |
| 17 | `replace_buttons1test` | 3 | 3 | 17.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**15 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `get_frame_number_test` | 90.3% | 28 | 31 | 3 |  |
| 2 | `ResolveEventsTest` | 86.7% | 13 | 15 | 2 |  |
| 3 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 4 | `action_order/action_execution_order_test8-v5` | 81.8% | 9 | 11 | 2 |  |
| 5 | `action_order/action_execution_order_test8-v6` | 81.8% | 9 | 11 | 2 |  |
| 6 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 7 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 8 | `place_and_remove_object_test` | 69.2% | 9 | 13 | 4 |  |
| 9 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 10 | `static_vs_dynamic1` | 64.7% | 11 | 17 | 6 |  |
| 11 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 12 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9 | 16 | 7 |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 55.0% | 61 | 111 | 50 |  |
| 14 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 15 | `duplicate_movie_clip_test2` | 52.4% | 11 | 21 | 10 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 20.9s |  |
| 2 | `ButtonPropertiesTest` | 21.0s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**29 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `get_frame_number_test` | 90.3% | 28/31 | 31 | 31 |  |
| 2 | `ResolveEventsTest` | 86.7% | 13/15 | 15 | 15 |  |
| 3 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 4 | `action_order/action_execution_order_test8-v5` | 81.8% | 9/11 | 11 | 11 |  |
| 5 | `action_order/action_execution_order_test8-v6` | 81.8% | 9/11 | 11 | 11 |  |
| 6 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 7 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 8 | `place_and_remove_object_test` | 69.2% | 9/13 | 13 | 13 |  |
| 9 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 10 | `static_vs_dynamic1` | 64.7% | 11/17 | 17 | 17 |  |
| 11 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 12 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9/16 | 16 | 15 |  |
| 13 | `displaylist_depths/displaylist_depths_test` | 55.0% | 61/111 | 111 | 111 |  |
| 14 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 15 | `duplicate_movie_clip_test2` | 52.4% | 11/21 | 21 | 21 |  |
| 16 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 17 | `goto_frame_test` | 46.7% | 7/15 | 15 | 15 |  |
| 18 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 19 | `loading/loadMovieTest` | 39.0% | 71/182 | 182 | 80 |  |
| 20 | `masks_test` | 34.9% | 61/175 | 69 | 175 |  |
| 21 | `key_event_test` | 34.8% | 23/66 | 51 | 66 |  |
| 22 | `static_vs_dynamic2` | 33.3% | 6/18 | 18 | 18 |  |
| 23 | `KeyEventOrder` | 25.0% | 8/32 | 32 | 26 |  |
| 24 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 25 | `action_order/ActionOrderTest5` | 11.5% | 7/61 | 61 | 51 |  |
| 26 | `action_order/ActionOrderTest4` | 5.4% | 4/74 | 74 | 64 |  |
| 27 | `action_order/ActionOrderTest3` | 5.3% | 4/75 | 75 | 62 |  |
| 28 | `duplicate_movie_clip_test` | 3.0% | 1/33 | 29 | 33 |  |
| 29 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
