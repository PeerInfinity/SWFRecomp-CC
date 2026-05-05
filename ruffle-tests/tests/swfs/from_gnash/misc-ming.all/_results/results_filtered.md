# Ruffle Test Results (Filtered)

**Date**: 2026-05-05 22:45 UTC

**Git SHA**: `c4cc4ccf1a`

**Run Duration**: 23m 35s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **64** (62.7%) |
| Ruffle-matched | 18 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **82** (80.4%) |
| Failing | 20 |
| Total expected lines | 4577 |
| Matching lines | 2923 (63.9%) |
| Mismatched lines | 1654 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 20 | 100.0% |

## Passing Tests

**64 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 15.2s |  |
| 2 | `DefineEditTextTest` | 153 | 15.6s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 17.3s |  |
| 4 | `DepthLimitsTest` | 20 | 17.2s |  |
| 5 | `PlaceObject2Test` | 9 | 17.9s |  |
| 6 | `ResolveEventsTest` | 15 | 0.3s |  |
| 7 | `RollOverOutTest` | 5 | 17.7s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 17.6s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 17.2s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 17.4s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 17.5s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 16.9s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 17.1s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 17.4s |  |
| 17 | `attachExtImported` | 2 | 17.7s |  |
| 18 | `attachImported` | 2 | 0.4s |  |
| 19 | `attachMovieLoopingTest` | 41 | 17.5s |  |
| 20 | `attachMovieTest` | 12 | 17.1s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 17.1s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.6s |  |
| 23 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test4` | 26 | 18.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test8` | 15 | 17.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.4s |  |
| 30 | `duplicate_movie_clip_test2` | 21 | 18.1s |  |
| 31 | `event_handler_scope_test` | 16 | 18.4s |  |
| 32 | `frame_label_test` | 17 | 0.4s |  |
| 33 | `getTimer_test` | 8 | 17.2s |  |
| 34 | `get_frame_number_test` | 31 | 17.3s |  |
| 35 | `goto_frame_test` | 15 | 17.2s |  |
| 36 | `instanceNameTest` | 5 | 0.3s |  |
| 37 | `loading/LoadVarsTest` | 36 | 17.7s |  |
| 38 | `loop/loop_test` | 21 | 18.7s |  |
| 39 | `loop/loop_test2` | 15 | 18.4s |  |
| 40 | `loop/loop_test3` | 16 | 18.7s |  |
| 41 | `loop/loop_test4` | 22 | 18.2s |  |
| 42 | `loop/loop_test5` | 24 | 0.4s |  |
| 43 | `loop/loop_test8` | 38 | 14.3s |  |
| 44 | `loop/loop_test9` | 15 | 16.9s |  |
| 45 | `loop/simple_loop_test` | 0 | 17.1s |  |
| 46 | `masks_test2` | 10 | 18.0s |  |
| 47 | `morph_test1` | 0 | 18.8s |  |
| 48 | `move_object_test` | 11 | 17.4s |  |
| 49 | `multi_doactions_and_goto_frame_test` | 6 | 17.3s |  |
| 50 | `new_child_in_unload_test` | 11 | 17.2s |  |
| 51 | `place_and_remove_object_insane_test` | 22 | 17.1s |  |
| 52 | `place_and_remove_object_test` | 13 | 17.9s |  |
| 53 | `register_class/RegisterClassTest3` | 12 | 17.6s |  |
| 54 | `register_class/registerClassTest` | 51 | 17.8s |  |
| 55 | `replace_shapes1test` | 23 | 0.3s |  |
| 56 | `replace_sprites1test` | 21 | 17.3s |  |
| 57 | `reverse_execute_PlaceObject2_test1` | 8 | 17.1s |  |
| 58 | `reverse_execute_PlaceObject2_test2` | 10 | 17.6s |  |
| 59 | `runtime_vm_stack_test` | 9 | 17.3s |  |
| 60 | `shape_test` | 21 | 17.6s |  |
| 61 | `static_vs_dynamic1` | 17 | 17.3s |  |
| 62 | `static_vs_dynamic2` | 18 | 17.4s |  |
| 63 | `timeline_var_test` | 11 | 17.1s |  |
| 64 | `unload_movieclip_test1` | 6 | 17.6s |  |

## Ruffle-Matched Tests

**18 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 14.6s |  |
| 2 | `DefineTextTest` | 4 | 4 | 17.2s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 17.1s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 0.4s |  |
| 5 | `callFunction_test` | 5 | 11 | 17.2s |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 17.4s |  |
| 7 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 0.3s |  |
| 8 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 0.3s |  |
| 9 | `duplicate_movie_clip_test` | 4 | 4 | 17.1s |  |
| 10 | `init_action/InitActionTest` | 6 | 17 | 17.3s |  |
| 11 | `init_action/InitActionTest2` | 24 | 30 | 17.0s |  |
| 12 | `loading/loadMovieTest` | 9 | 9 | 17.8s |  |
| 13 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 14 | `path_format_test` | 28 | 28 | 17.2s |  |
| 15 | `place_object_test` | 14 | 14 | 18.2s |  |
| 16 | `place_object_test2` | 20 | 23 | 18.0s |  |
| 17 | `register_class/registerClassTest2` | 8 | 28 | 13.8s |  |
| 18 | `replace_buttons1test` | 3 | 3 | 13.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**7 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 87.4% | 949 | 1086 | 137 |  |
| 2 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 4 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 6 | `opcode_guard_test` | 57.9% | 11 | 19 | 8 |  |
| 7 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**20 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 87.4% | 949/1086 | 1086 | 1086 |  |
| 2 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 4 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 6 | `opcode_guard_test` | 57.9% | 11/19 | 19 | 18 |  |
| 7 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 8 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 9 | `loop/loop_test6` | 45.8% | 11/24 | 24 | 23 |  |
| 10 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 11 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 12 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 13 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 14 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 15 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 16 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 17 | `ButtonEventsTest` | 9.1% | 62/679 | 236 | 679 |  |
| 18 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 19 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 20 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
