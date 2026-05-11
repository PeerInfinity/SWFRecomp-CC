# Ruffle Test Results (Filtered)

**Date**: 2026-05-11 18:15 UTC

**Git SHA**: `65b8068012`

**Run Duration**: 2m 23s

**Filtered**: 2 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **57** (57.0%) |
| Ruffle-matched | 20 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **77** (77.0%) |
| Failing | 23 |
| Total expected lines | 4517 |
| Matching lines | 3063 (67.8%) |
| Mismatched lines | 1454 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 21 | 91.3% |
| Segfault | 2 | 8.7% |

## Passing Tests

**57 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.8s |  |
| 2 | `DefineEditTextTest` | 153 | 1.4s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 1.3s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 1.1s |  |
| 5 | `DepthLimitsTest` | 20 | 1.0s |  |
| 6 | `PlaceObject2Test` | 9 | 0.7s |  |
| 7 | `RollOverOutTest` | 5 | 0.8s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.8s |  |
| 9 | `Version4Loader` | 11 | 0.8s |  |
| 10 | `Video-EmbedSquareTest` | 2 | 0.8s |  |
| 11 | `action_order/action_execution_order_test1` | 10 | 0.9s |  |
| 12 | `action_order/action_execution_order_test2` | 5 | 0.8s |  |
| 13 | `action_order/action_execution_order_test3` | 4 | 0.8s |  |
| 14 | `action_order/action_execution_order_test7` | 7 | 0.8s |  |
| 15 | `action_order/action_execution_order_test9` | 4 | 0.9s |  |
| 16 | `attachExtImported` | 2 | 0.9s |  |
| 17 | `attachImported` | 2 | 0.9s |  |
| 18 | `attachMovieLoopingTest` | 41 | 0.9s |  |
| 19 | `attachMovieTest` | 12 | 0.8s |  |
| 20 | `consecutive_goto_frame_test` | 12 | 0.8s |  |
| 21 | `displaylist_depths/displaylist_depths_test10` | 10 | 0.9s |  |
| 22 | `displaylist_depths/displaylist_depths_test11` | 15 | 0.9s |  |
| 23 | `displaylist_depths/displaylist_depths_test4` | 26 | 0.9s |  |
| 24 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.9s |  |
| 26 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.8s |  |
| 28 | `duplicate_movie_clip_test2` | 21 | 0.9s |  |
| 29 | `event_handler_scope_test` | 16 | 0.9s |  |
| 30 | `frame_label_test` | 17 | 0.9s |  |
| 31 | `getTimer_test` | 8 | 0.9s |  |
| 32 | `instanceNameTest` | 5 | 0.8s |  |
| 33 | `loading/LoadVarsTest` | 36 | 1.1s |  |
| 34 | `loop/loop_test` | 21 | 0.9s |  |
| 35 | `loop/loop_test2` | 15 | 0.9s |  |
| 36 | `loop/loop_test3` | 16 | 1.1s |  |
| 37 | `loop/loop_test4` | 22 | 0.8s |  |
| 38 | `loop/loop_test5` | 24 | 0.7s |  |
| 39 | `loop/loop_test8` | 38 | 0.9s |  |
| 40 | `loop/loop_test9` | 15 | 0.8s |  |
| 41 | `loop/simple_loop_test` | 0 | 0.9s |  |
| 42 | `masks_test2` | 10 | 1.1s |  |
| 43 | `morph_test1` | 0 | 1.0s |  |
| 44 | `move_object_test` | 11 | 0.8s |  |
| 45 | `multi_doactions_and_goto_frame_test` | 6 | 0.8s |  |
| 46 | `new_child_in_unload_test` | 11 | 0.8s |  |
| 47 | `register_class/RegisterClassTest3` | 12 | 0.9s |  |
| 48 | `register_class/registerClassTest` | 51 | 1.1s |  |
| 49 | `replace_shapes1test` | 23 | 0.9s |  |
| 50 | `replace_sprites1test` | 21 | 0.8s |  |
| 51 | `reverse_execute_PlaceObject2_test1` | 8 | 0.8s |  |
| 52 | `reverse_execute_PlaceObject2_test2` | 10 | 0.8s |  |
| 53 | `runtime_vm_stack_test` | 9 | 0.8s |  |
| 54 | `shape_test` | 21 | 0.9s |  |
| 55 | `static_vs_dynamic1` | 17 | 0.8s |  |
| 56 | `static_vs_dynamic2` | 18 | 0.8s |  |
| 57 | `unload_movieclip_test1` | 6 | 0.8s |  |

## Ruffle-Matched Tests

**20 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `DefineTextTest` | 4 | 4 | 0.9s |  |
| 2 | `DragDropTest` | 12 | 12 | 0.7s |  |
| 3 | `action_order/action_execution_order_test4` | 7 | 26 | 0.9s |  |
| 4 | `callFunction_test` | 5 | 11 | 0.8s |  |
| 5 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 1.3s |  |
| 6 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.9s |  |
| 7 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.9s |  |
| 8 | `duplicate_movie_clip_test` | 4 | 4 | 0.8s |  |
| 9 | `goto_frame_test` | 6 | 11 | 0.9s |  |
| 10 | `init_action/InitActionTest` | 6 | 17 | 0.9s |  |
| 11 | `init_action/InitActionTest2` | 24 | 30 | 1.0s |  |
| 12 | `loop/loop_test10` | 23 | 23 | 1.0s |  |
| 13 | `loop/loop_test6` | 1 | 12 | 0.9s |  |
| 14 | `loop/loop_test7` | 1 | 8 | 0.8s |  |
| 15 | `matrix_test` | 5 | 9 | 5.3s |  |
| 16 | `path_format_test` | 28 | 28 | 1.0s |  |
| 17 | `place_object_test` | 14 | 14 | 0.9s |  |
| 18 | `place_object_test2` | 20 | 23 | 0.9s |  |
| 19 | `register_class/registerClassTest2` | 8 | 28 | 18.4s |  |
| 20 | `replace_buttons1test` | 3 | 3 | 18.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `get_frame_number_test` | 90.3% | 28 | 31 | 3 |  |
| 2 | `ResolveEventsTest` | 86.7% | 13 | 15 | 2 |  |
| 3 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 4 | `action_order/action_execution_order_test8-v5` | 81.8% | 9 | 11 | 2 |  |
| 5 | `action_order/action_execution_order_test8-v6` | 81.8% | 9 | 11 | 2 |  |
| 6 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 7 | `place_and_remove_object_test` | 69.2% | 9 | 13 | 4 |  |
| 8 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 9 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 10 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9 | 16 | 7 |  |
| 11 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 3.3s |  |
| 2 | `ButtonPropertiesTest` | 3.2s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**21 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `get_frame_number_test` | 90.3% | 28/31 | 31 | 31 |  |
| 2 | `ResolveEventsTest` | 86.7% | 13/15 | 15 | 15 |  |
| 3 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 4 | `action_order/action_execution_order_test8-v5` | 81.8% | 9/11 | 11 | 11 |  |
| 5 | `action_order/action_execution_order_test8-v6` | 81.8% | 9/11 | 11 | 11 |  |
| 6 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 7 | `place_and_remove_object_test` | 69.2% | 9/13 | 13 | 13 |  |
| 8 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 9 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 10 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9/16 | 16 | 15 |  |
| 11 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 12 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 13 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 14 | `loading/loadMovieTest` | 39.0% | 71/182 | 182 | 80 |  |
| 15 | `masks_test` | 34.9% | 61/175 | 69 | 175 |  |
| 16 | `key_event_test` | 34.8% | 23/66 | 51 | 66 |  |
| 17 | `KeyEventOrder` | 25.0% | 8/32 | 32 | 26 |  |
| 18 | `action_order/ActionOrderTest5` | 11.5% | 7/61 | 61 | 51 |  |
| 19 | `action_order/ActionOrderTest4` | 5.4% | 4/74 | 74 | 64 |  |
| 20 | `action_order/ActionOrderTest3` | 5.3% | 4/75 | 75 | 62 |  |
| 21 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
