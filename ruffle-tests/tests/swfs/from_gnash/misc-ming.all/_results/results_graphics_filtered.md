# Ruffle Test Results (Filtered)

**Date**: 2026-05-14 03:41 UTC

**Git SHA**: `50f5aa00c1`

**Run Duration**: 31m 28s

**Filtered**: 2 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **65** (65.0%) |
| Ruffle-matched | 22 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **87** (87.0%) |
| Failing | 13 |
| Total expected lines | 4517 |
| Matching lines | 3103 (68.7%) |
| Mismatched lines | 1414 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 11 | 84.6% |
| Segfault | 2 | 15.4% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 23.2s |  |
| 2 | `DefineEditTextTest` | 153 | 30.1s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 26.8s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 23.2s |  |
| 5 | `DepthLimitsTest` | 20 | 22.3s |  |
| 6 | `PlaceObject2Test` | 9 | 19.8s |  |
| 7 | `ResolveEventsTest` | 15 | 3.6s |  |
| 8 | `RollOverOutTest` | 5 | 20.7s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.2s |  |
| 10 | `Version4Loader` | 11 | 2.0s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 21.8s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 19.7s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.6s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 22.8s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 21.6s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 20.2s |  |
| 19 | `attachExtImported` | 2 | 21.4s |  |
| 20 | `attachImported` | 2 | 2.3s |  |
| 21 | `attachMovieLoopingTest` | 41 | 20.5s |  |
| 22 | `attachMovieTest` | 12 | 21.2s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 20.4s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 19.9s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.5s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.8s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 20.1s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.4s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 21.5s |  |
| 33 | `event_handler_scope_test` | 16 | 20.7s |  |
| 34 | `frame_label_test` | 17 | 4.0s |  |
| 35 | `getTimer_test` | 8 | 21.1s |  |
| 36 | `get_frame_number_test` | 31 | 23.6s |  |
| 37 | `goto_frame_test` | 15 | 21.5s |  |
| 38 | `instanceNameTest` | 5 | 2.4s |  |
| 39 | `loading/LoadVarsTest` | 36 | 22.5s |  |
| 40 | `loop/loop_test` | 21 | 20.1s |  |
| 41 | `loop/loop_test2` | 15 | 19.5s |  |
| 42 | `loop/loop_test3` | 16 | 15.7s |  |
| 43 | `loop/loop_test4` | 22 | 16.6s |  |
| 44 | `loop/loop_test5` | 24 | 2.9s |  |
| 45 | `loop/loop_test8` | 38 | 22.6s |  |
| 46 | `loop/loop_test9` | 15 | 19.8s |  |
| 47 | `loop/simple_loop_test` | 0 | 23.8s |  |
| 48 | `masks_test2` | 10 | 19.9s |  |
| 49 | `morph_test1` | 0 | 22.8s |  |
| 50 | `move_object_test` | 11 | 20.9s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 20.5s |  |
| 52 | `new_child_in_unload_test` | 11 | 20.8s |  |
| 53 | `place_and_remove_object_test` | 13 | 21.1s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 20.6s |  |
| 55 | `register_class/registerClassTest` | 51 | 23.0s |  |
| 56 | `replace_shapes1test` | 23 | 2.9s |  |
| 57 | `replace_sprites1test` | 21 | 16.6s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 16.0s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 16.4s |  |
| 60 | `runtime_vm_stack_test` | 9 | 20.7s |  |
| 61 | `shape_test` | 21 | 23.2s |  |
| 62 | `static_vs_dynamic1` | 17 | 19.5s |  |
| 63 | `static_vs_dynamic2` | 18 | 21.1s |  |
| 64 | `timeline_var_test` | 11 | 20.2s |  |
| 65 | `unload_movieclip_test1` | 6 | 19.6s |  |

## Ruffle-Matched Tests

**22 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `DefineTextTest` | 4 | 4 | 20.7s |  |
| 2 | `DragDropTest` | 12 | 12 | 3.6s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 20.6s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 3.4s |  |
| 5 | `callFunction_test` | 5 | 11 | 21.2s |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 28.4s |  |
| 7 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.7s |  |
| 8 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.6s |  |
| 9 | `duplicate_movie_clip_test` | 4 | 4 | 21.4s |  |
| 10 | `init_action/InitActionTest` | 6 | 17 | 21.0s |  |
| 11 | `init_action/InitActionTest2` | 24 | 30 | 22.6s |  |
| 12 | `key_event_test` | 5 | 6 | 21.8s |  |
| 13 | `loading/loadMovieTest` | 9 | 9 | 21.5s |  |
| 14 | `loop/loop_test10` | 23 | 23 | 20.6s |  |
| 15 | `loop/loop_test6` | 1 | 12 | 21.6s |  |
| 16 | `loop/loop_test7` | 1 | 8 | 3.0s |  |
| 17 | `matrix_test` | 5 | 9 | 94.2s |  |
| 18 | `path_format_test` | 28 | 28 | 22.5s |  |
| 19 | `place_object_test` | 14 | 14 | 22.7s |  |
| 20 | `place_object_test2` | 20 | 23 | 20.6s |  |
| 21 | `register_class/registerClassTest2` | 8 | 28 | 21.5s |  |
| 22 | `replace_buttons1test` | 3 | 3 | 20.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 3 | `place_and_remove_object_insane_test` | 72.7% | 16 | 22 | 6 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 28.0s |  |
| 2 | `ButtonPropertiesTest` | 23.6s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**11 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `place_and_remove_object_insane_test` | 72.7% | 16/22 | 22 | 22 |  |
| 4 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 5 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 6 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 7 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 8 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 9 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 10 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 11 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
