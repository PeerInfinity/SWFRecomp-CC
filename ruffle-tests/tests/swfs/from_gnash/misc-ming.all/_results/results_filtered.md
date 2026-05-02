# Ruffle Test Results (Filtered)

**Date**: 2026-05-02 18:32 UTC

**Git SHA**: `7e96b41a43`

**Run Duration**: 23m 29s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **62** (60.8%) |
| Ruffle-matched | 15 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **77** (75.5%) |
| Failing | 25 |
| Total expected lines | 4577 |
| Matching lines | 2828 (61.8%) |
| Mismatched lines | 1749 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 25 | 100.0% |

## Passing Tests

**62 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 16.8s |  |
| 2 | `DefineEditTextTest` | 153 | 17.2s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 17.6s |  |
| 4 | `DepthLimitsTest` | 20 | 17.5s |  |
| 5 | `PlaceObject2Test` | 9 | 17.4s |  |
| 6 | `ResolveEventsTest` | 15 | 0.4s |  |
| 7 | `RollOverOutTest` | 5 | 17.5s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 17.2s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 17.3s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 16.7s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 16.6s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 16.9s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 16.9s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 18.0s |  |
| 17 | `attachExtImported` | 2 | 17.9s |  |
| 18 | `attachImported` | 2 | 0.3s |  |
| 19 | `attachMovieLoopingTest` | 41 | 17.8s |  |
| 20 | `attachMovieTest` | 12 | 17.5s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 17.5s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 16.7s |  |
| 23 | `displaylist_depths/displaylist_depths_test11` | 15 | 16.7s |  |
| 24 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.6s |  |
| 25 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test8` | 15 | 16.8s |  |
| 29 | `duplicate_movie_clip_test2` | 21 | 16.6s |  |
| 30 | `event_handler_scope_test` | 16 | 16.5s |  |
| 31 | `getTimer_test` | 8 | 16.7s |  |
| 32 | `get_frame_number_test` | 31 | 17.0s |  |
| 33 | `goto_frame_test` | 15 | 16.8s |  |
| 34 | `instanceNameTest` | 5 | 0.3s |  |
| 35 | `loading/LoadVarsTest` | 36 | 17.1s |  |
| 36 | `loop/loop_test` | 21 | 17.4s |  |
| 37 | `loop/loop_test2` | 15 | 17.0s |  |
| 38 | `loop/loop_test3` | 16 | 17.8s |  |
| 39 | `loop/loop_test4` | 22 | 17.4s |  |
| 40 | `loop/loop_test5` | 24 | 0.4s |  |
| 41 | `loop/loop_test8` | 38 | 17.4s |  |
| 42 | `loop/loop_test9` | 15 | 17.5s |  |
| 43 | `loop/simple_loop_test` | 0 | 17.6s |  |
| 44 | `masks_test2` | 10 | 17.4s |  |
| 45 | `morph_test1` | 0 | 17.5s |  |
| 46 | `move_object_test` | 11 | 16.6s |  |
| 47 | `multi_doactions_and_goto_frame_test` | 6 | 16.6s |  |
| 48 | `new_child_in_unload_test` | 11 | 16.6s |  |
| 49 | `place_and_remove_object_insane_test` | 22 | 16.6s |  |
| 50 | `place_and_remove_object_test` | 13 | 16.9s |  |
| 51 | `register_class/RegisterClassTest3` | 12 | 17.4s |  |
| 52 | `register_class/registerClassTest` | 51 | 17.8s |  |
| 53 | `replace_shapes1test` | 23 | 0.3s |  |
| 54 | `replace_sprites1test` | 21 | 16.6s |  |
| 55 | `reverse_execute_PlaceObject2_test1` | 8 | 16.7s |  |
| 56 | `reverse_execute_PlaceObject2_test2` | 10 | 16.9s |  |
| 57 | `runtime_vm_stack_test` | 9 | 16.9s |  |
| 58 | `shape_test` | 21 | 17.1s |  |
| 59 | `static_vs_dynamic1` | 17 | 16.8s |  |
| 60 | `static_vs_dynamic2` | 18 | 17.4s |  |
| 61 | `timeline_var_test` | 11 | 17.8s |  |
| 62 | `unload_movieclip_test1` | 6 | 17.6s |  |

## Ruffle-Matched Tests

**15 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 16.7s |  |
| 2 | `DefineTextTest` | 4 | 4 | 17.6s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 16.9s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 0.3s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 16.9s |  |
| 6 | `callFunction_test` | 5 | 11 | 17.6s |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 17.8s |  |
| 8 | `init_action/InitActionTest` | 6 | 17 | 17.1s |  |
| 9 | `init_action/InitActionTest2` | 24 | 30 | 17.3s |  |
| 10 | `loading/loadMovieTest` | 9 | 9 | 17.3s |  |
| 11 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 12 | `path_format_test` | 27 | 28 | 16.8s |  |
| 13 | `place_object_test` | 14 | 14 | 17.4s |  |
| 14 | `place_object_test2` | 20 | 23 | 16.9s |  |
| 15 | `replace_buttons1test` | 3 | 3 | 17.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**9 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 2 | `register_class/registerClassTest2` | 79.5% | 35 | 44 | 9 |  |
| 3 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 4 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 5 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 6 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 7 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |
| 8 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |
| 9 | `loop/loop_test6` | 50.0% | 12 | 24 | 12 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**25 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 2 | `register_class/registerClassTest2` | 79.5% | 35/44 | 44 | 44 |  |
| 3 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 4 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 5 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 6 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 7 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 8 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 9 | `loop/loop_test6` | 50.0% | 12/24 | 24 | 23 |  |
| 10 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 11 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 12 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 13 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 14 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 15 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 16 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 17 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 18 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 19 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 20 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 21 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 22 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 23 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 24 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 25 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
