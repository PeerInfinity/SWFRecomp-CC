# Ruffle Test Results (Filtered)

**Date**: 2026-05-13 00:24 UTC

**Git SHA**: `7bef032ea2`

**Run Duration**: 31m 9s

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
| 1 | `BeginBitmapFill` | 1 | 22.4s |  |
| 2 | `DefineEditTextTest` | 153 | 28.6s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 25.6s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.6s |  |
| 5 | `DepthLimitsTest` | 20 | 21.5s |  |
| 6 | `PlaceObject2Test` | 9 | 19.2s |  |
| 7 | `ResolveEventsTest` | 15 | 3.1s |  |
| 8 | `RollOverOutTest` | 5 | 19.8s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.1s |  |
| 10 | `Version4Loader` | 11 | 2.0s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 22.0s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 19.0s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 19.6s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 19.3s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 19.4s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 20.0s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 0.9s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 21.0s |  |
| 19 | `attachExtImported` | 2 | 22.3s |  |
| 20 | `attachImported` | 2 | 2.2s |  |
| 21 | `attachMovieLoopingTest` | 41 | 20.6s |  |
| 22 | `attachMovieTest` | 12 | 20.8s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 19.9s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 21.2s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 21.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 19.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.3s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.7s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 19.8s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 3.1s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 20.7s |  |
| 33 | `event_handler_scope_test` | 16 | 20.1s |  |
| 34 | `frame_label_test` | 17 | 3.5s |  |
| 35 | `getTimer_test` | 8 | 19.6s |  |
| 36 | `get_frame_number_test` | 31 | 22.3s |  |
| 37 | `goto_frame_test` | 15 | 20.3s |  |
| 38 | `instanceNameTest` | 5 | 2.0s |  |
| 39 | `loading/LoadVarsTest` | 36 | 23.4s |  |
| 40 | `loop/loop_test` | 21 | 20.1s |  |
| 41 | `loop/loop_test2` | 15 | 20.0s |  |
| 42 | `loop/loop_test3` | 16 | 19.8s |  |
| 43 | `loop/loop_test4` | 22 | 20.5s |  |
| 44 | `loop/loop_test5` | 24 | 3.2s |  |
| 45 | `loop/loop_test8` | 38 | 17.6s |  |
| 46 | `loop/loop_test9` | 15 | 19.8s |  |
| 47 | `loop/simple_loop_test` | 0 | 25.2s |  |
| 48 | `masks_test2` | 10 | 20.0s |  |
| 49 | `morph_test1` | 0 | 23.4s |  |
| 50 | `move_object_test` | 11 | 19.2s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 19.2s |  |
| 52 | `new_child_in_unload_test` | 11 | 19.4s |  |
| 53 | `place_and_remove_object_test` | 13 | 20.2s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 20.4s |  |
| 55 | `register_class/registerClassTest` | 51 | 22.7s |  |
| 56 | `replace_shapes1test` | 23 | 2.8s |  |
| 57 | `replace_sprites1test` | 21 | 20.2s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 19.8s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 20.4s |  |
| 60 | `runtime_vm_stack_test` | 9 | 20.4s |  |
| 61 | `shape_test` | 21 | 23.5s |  |
| 62 | `static_vs_dynamic1` | 17 | 19.6s |  |
| 63 | `static_vs_dynamic2` | 18 | 20.6s |  |
| 64 | `timeline_var_test` | 11 | 20.2s |  |
| 65 | `unload_movieclip_test1` | 6 | 19.6s |  |

## Ruffle-Matched Tests

**22 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `DefineTextTest` | 4 | 4 | 20.1s |  |
| 2 | `DragDropTest` | 12 | 12 | 3.4s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 19.7s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 2.8s |  |
| 5 | `callFunction_test` | 5 | 11 | 20.8s |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 27.9s |  |
| 7 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.5s |  |
| 8 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.3s |  |
| 9 | `duplicate_movie_clip_test` | 4 | 4 | 21.3s |  |
| 10 | `init_action/InitActionTest` | 6 | 17 | 21.4s |  |
| 11 | `init_action/InitActionTest2` | 24 | 30 | 22.3s |  |
| 12 | `key_event_test` | 5 | 6 | 21.6s |  |
| 13 | `loading/loadMovieTest` | 9 | 9 | 22.3s |  |
| 14 | `loop/loop_test10` | 23 | 23 | 21.0s |  |
| 15 | `loop/loop_test6` | 1 | 12 | 16.5s |  |
| 16 | `loop/loop_test7` | 1 | 8 | 2.1s |  |
| 17 | `matrix_test` | 5 | 9 | 103.1s |  |
| 18 | `path_format_test` | 28 | 28 | 22.9s |  |
| 19 | `place_object_test` | 14 | 14 | 23.1s |  |
| 20 | `place_object_test2` | 20 | 23 | 20.5s |  |
| 21 | `register_class/registerClassTest2` | 8 | 28 | 21.7s |  |
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
| 1 | `ButtonEventsTest` | 26.4s |  |
| 2 | `ButtonPropertiesTest` | 21.7s |  |

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
