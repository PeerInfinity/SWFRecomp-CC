# Ruffle Test Results (Filtered)

**Date**: 2026-05-06 04:11 UTC

**Git SHA**: `b91b7202e8`

**Run Duration**: 28m 52s

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
| Matching lines | 3093 (67.6%) |
| Mismatched lines | 1484 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 20 | 100.0% |

## Passing Tests

**64 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 20.0s |  |
| 2 | `DefineEditTextTest` | 153 | 29.1s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 21.8s |  |
| 4 | `DepthLimitsTest` | 20 | 21.4s |  |
| 5 | `PlaceObject2Test` | 9 | 18.4s |  |
| 6 | `ResolveEventsTest` | 15 | 2.6s |  |
| 7 | `RollOverOutTest` | 5 | 19.4s |  |
| 8 | `VarAndCharClashTest` | 13 | 1.4s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 18.4s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 18.2s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 19.6s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 19.9s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 18.6s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 19.0s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 18.3s |  |
| 17 | `attachExtImported` | 2 | 19.6s |  |
| 18 | `attachImported` | 2 | 1.5s |  |
| 19 | `attachMovieLoopingTest` | 41 | 19.1s |  |
| 20 | `attachMovieTest` | 12 | 19.4s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 18.7s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.2s |  |
| 23 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.3s |  |
| 24 | `displaylist_depths/displaylist_depths_test4` | 26 | 19.0s |  |
| 25 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.6s |  |
| 27 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.0s |  |
| 28 | `displaylist_depths/displaylist_depths_test8` | 15 | 18.4s |  |
| 29 | `displaylist_depths/displaylist_depths_test9` | 23 | 2.2s |  |
| 30 | `duplicate_movie_clip_test2` | 21 | 19.9s |  |
| 31 | `event_handler_scope_test` | 16 | 19.6s |  |
| 32 | `frame_label_test` | 17 | 3.0s |  |
| 33 | `getTimer_test` | 8 | 18.3s |  |
| 34 | `get_frame_number_test` | 31 | 20.6s |  |
| 35 | `goto_frame_test` | 15 | 18.9s |  |
| 36 | `instanceNameTest` | 5 | 1.5s |  |
| 37 | `loading/LoadVarsTest` | 36 | 22.2s |  |
| 38 | `loop/loop_test` | 21 | 18.1s |  |
| 39 | `loop/loop_test2` | 15 | 17.9s |  |
| 40 | `loop/loop_test3` | 16 | 19.0s |  |
| 41 | `loop/loop_test4` | 22 | 19.7s |  |
| 42 | `loop/loop_test5` | 24 | 2.6s |  |
| 43 | `loop/loop_test8` | 38 | 21.1s |  |
| 44 | `loop/loop_test9` | 15 | 18.8s |  |
| 45 | `loop/simple_loop_test` | 0 | 17.9s |  |
| 46 | `masks_test2` | 10 | 18.3s |  |
| 47 | `morph_test1` | 0 | 18.2s |  |
| 48 | `move_object_test` | 11 | 20.7s |  |
| 49 | `multi_doactions_and_goto_frame_test` | 6 | 20.4s |  |
| 50 | `new_child_in_unload_test` | 11 | 19.9s |  |
| 51 | `place_and_remove_object_insane_test` | 22 | 18.5s |  |
| 52 | `place_and_remove_object_test` | 13 | 18.6s |  |
| 53 | `register_class/RegisterClassTest3` | 12 | 19.3s |  |
| 54 | `register_class/registerClassTest` | 51 | 21.6s |  |
| 55 | `replace_shapes1test` | 23 | 2.1s |  |
| 56 | `replace_sprites1test` | 21 | 15.1s |  |
| 57 | `reverse_execute_PlaceObject2_test1` | 8 | 14.7s |  |
| 58 | `reverse_execute_PlaceObject2_test2` | 10 | 14.8s |  |
| 59 | `runtime_vm_stack_test` | 9 | 19.2s |  |
| 60 | `shape_test` | 21 | 20.2s |  |
| 61 | `static_vs_dynamic1` | 17 | 18.7s |  |
| 62 | `static_vs_dynamic2` | 18 | 18.5s |  |
| 63 | `timeline_var_test` | 11 | 18.2s |  |
| 64 | `unload_movieclip_test1` | 6 | 17.9s |  |

## Ruffle-Matched Tests

**18 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 19 | 20 | 19.4s |  |
| 2 | `DefineTextTest` | 4 | 4 | 19.6s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 18.5s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 2.8s |  |
| 5 | `callFunction_test` | 5 | 11 | 19.8s |  |
| 6 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 26.1s |  |
| 7 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 1.7s |  |
| 8 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 1.6s |  |
| 9 | `duplicate_movie_clip_test` | 4 | 4 | 19.6s |  |
| 10 | `init_action/InitActionTest` | 6 | 17 | 19.0s |  |
| 11 | `init_action/InitActionTest2` | 24 | 30 | 20.1s |  |
| 12 | `loading/loadMovieTest` | 9 | 9 | 21.1s |  |
| 13 | `loop/loop_test7` | 1 | 8 | 2.0s |  |
| 14 | `path_format_test` | 28 | 28 | 20.5s |  |
| 15 | `place_object_test` | 14 | 14 | 19.1s |  |
| 16 | `place_object_test2` | 20 | 23 | 18.9s |  |
| 17 | `register_class/registerClassTest2` | 8 | 28 | 20.3s |  |
| 18 | `replace_buttons1test` | 3 | 3 | 19.0s |  |

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
| 13 | `ButtonEventsTest` | 33.3% | 231/694 | 694 | 679 |  |
| 14 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 15 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 16 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 17 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 18 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 19 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 20 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
