# Ruffle Test Results (Filtered)

**Date**: 2026-05-11 19:20 UTC

**Git SHA**: `3589c6bcc8`

**Run Duration**: 6m 30s

**Filtered**: 2 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **62** (62.0%) |
| Ruffle-matched | 22 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **84** (84.0%) |
| Failing | 16 |
| Total expected lines | 4517 |
| Matching lines | 3087 (68.3%) |
| Mismatched lines | 1430 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 87.5% |
| Segfault | 2 | 12.5% |

## Passing Tests

**62 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.8s |  |
| 2 | `DefineEditTextTest` | 153 | 1.3s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 0.9s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 0.8s |  |
| 5 | `DepthLimitsTest` | 20 | 0.7s |  |
| 6 | `PlaceObject2Test` | 9 | 0.8s |  |
| 7 | `ResolveEventsTest` | 15 | 0.8s |  |
| 8 | `RollOverOutTest` | 5 | 0.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 0.9s |  |
| 10 | `Version4Loader` | 11 | 0.9s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 18.6s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 0.9s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 0.8s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 0.8s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 0.9s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 0.9s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.8s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 18.8s |  |
| 19 | `attachExtImported` | 2 | 18.8s |  |
| 20 | `attachImported` | 2 | 1.0s |  |
| 21 | `attachMovieLoopingTest` | 41 | 18.9s |  |
| 22 | `attachMovieTest` | 12 | 0.8s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 0.8s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.9s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.9s |  |
| 30 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.9s |  |
| 31 | `duplicate_movie_clip_test2` | 21 | 0.8s |  |
| 32 | `event_handler_scope_test` | 16 | 0.8s |  |
| 33 | `frame_label_test` | 17 | 0.9s |  |
| 34 | `getTimer_test` | 8 | 0.8s |  |
| 35 | `get_frame_number_test` | 31 | 1.2s |  |
| 36 | `goto_frame_test` | 15 | 0.9s |  |
| 37 | `instanceNameTest` | 5 | 0.9s |  |
| 38 | `loading/LoadVarsTest` | 36 | 18.4s |  |
| 39 | `loop/loop_test` | 21 | 19.4s |  |
| 40 | `loop/loop_test2` | 15 | 19.3s |  |
| 41 | `loop/loop_test3` | 16 | 0.8s |  |
| 42 | `loop/loop_test4` | 22 | 1.1s |  |
| 43 | `loop/loop_test5` | 24 | 0.8s |  |
| 44 | `loop/loop_test8` | 38 | 0.8s |  |
| 45 | `loop/loop_test9` | 15 | 0.8s |  |
| 46 | `loop/simple_loop_test` | 0 | 0.8s |  |
| 47 | `masks_test2` | 10 | 1.0s |  |
| 48 | `morph_test1` | 0 | 0.8s |  |
| 49 | `move_object_test` | 11 | 0.9s |  |
| 50 | `multi_doactions_and_goto_frame_test` | 6 | 0.8s |  |
| 51 | `new_child_in_unload_test` | 11 | 0.9s |  |
| 52 | `register_class/RegisterClassTest3` | 12 | 0.9s |  |
| 53 | `register_class/registerClassTest` | 51 | 1.0s |  |
| 54 | `replace_shapes1test` | 23 | 0.9s |  |
| 55 | `replace_sprites1test` | 21 | 0.8s |  |
| 56 | `reverse_execute_PlaceObject2_test1` | 8 | 0.8s |  |
| 57 | `reverse_execute_PlaceObject2_test2` | 10 | 0.8s |  |
| 58 | `runtime_vm_stack_test` | 9 | 1.2s |  |
| 59 | `shape_test` | 21 | 0.9s |  |
| 60 | `static_vs_dynamic1` | 17 | 0.8s |  |
| 61 | `static_vs_dynamic2` | 18 | 0.9s |  |
| 62 | `unload_movieclip_test1` | 6 | 0.8s |  |

## Ruffle-Matched Tests

**22 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `DefineTextTest` | 4 | 4 | 0.7s |  |
| 2 | `DragDropTest` | 12 | 12 | 0.7s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 0.7s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 0.8s |  |
| 5 | `callFunction_test` | 5 | 11 | 0.8s |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 1.2s |  |
| 7 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 1.0s |  |
| 8 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.9s |  |
| 9 | `duplicate_movie_clip_test` | 4 | 4 | 0.9s |  |
| 10 | `init_action/InitActionTest` | 6 | 17 | 18.3s |  |
| 11 | `init_action/InitActionTest2` | 24 | 30 | 18.3s |  |
| 12 | `key_event_test` | 5 | 6 | 18.5s |  |
| 13 | `loading/loadMovieTest` | 9 | 9 | 18.3s |  |
| 14 | `loop/loop_test10` | 23 | 23 | 19.1s |  |
| 15 | `loop/loop_test6` | 1 | 12 | 0.7s |  |
| 16 | `loop/loop_test7` | 1 | 8 | 0.7s |  |
| 17 | `matrix_test` | 5 | 9 | 4.9s |  |
| 18 | `path_format_test` | 28 | 28 | 0.9s |  |
| 19 | `place_object_test` | 14 | 14 | 0.8s |  |
| 20 | `place_object_test2` | 20 | 23 | 0.8s |  |
| 21 | `register_class/registerClassTest2` | 8 | 28 | 0.9s |  |
| 22 | `replace_buttons1test` | 3 | 3 | 0.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**7 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `place_and_remove_object_test` | 69.2% | 9 | 13 | 4 |  |
| 4 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 6 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9 | 16 | 7 |  |
| 7 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 3.2s |  |
| 2 | `ButtonPropertiesTest` | 3.0s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**14 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `place_and_remove_object_test` | 69.2% | 9/13 | 13 | 13 |  |
| 4 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 6 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9/16 | 16 | 15 |  |
| 7 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 8 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 9 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 10 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 11 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 12 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 13 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 14 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
