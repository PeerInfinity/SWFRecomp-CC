# Ruffle Test Results (Filtered)

**Date**: 2026-05-03 18:28 UTC

**Git SHA**: `4858cdcdd9`

**Run Duration**: 28m 23s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **63** (61.8%) |
| Ruffle-matched | 17 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **80** (78.4%) |
| Failing | 22 |
| Total expected lines | 4577 |
| Matching lines | 2875 (62.8%) |
| Mismatched lines | 1702 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 22 | 100.0% |

## Passing Tests

**63 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 21.2s |  |
| 2 | `DefineEditTextTest` | 153 | 29.2s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 20.8s |  |
| 4 | `DepthLimitsTest` | 20 | 20.2s |  |
| 5 | `PlaceObject2Test` | 9 | 18.8s |  |
| 6 | `ResolveEventsTest` | 15 | 2.9s |  |
| 7 | `RollOverOutTest` | 5 | 19.6s |  |
| 8 | `VarAndCharClashTest` | 13 | 1.5s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 18.5s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 18.5s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 19.8s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 19.6s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 18.6s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 19.1s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.4s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 19.4s |  |
| 17 | `attachExtImported` | 2 | 20.7s |  |
| 18 | `attachImported` | 2 | 1.7s |  |
| 19 | `attachMovieLoopingTest` | 41 | 19.6s |  |
| 20 | `attachMovieTest` | 12 | 18.7s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 18.0s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.0s |  |
| 23 | `displaylist_depths/displaylist_depths_test11` | 15 | 18.1s |  |
| 24 | `displaylist_depths/displaylist_depths_test4` | 26 | 15.3s |  |
| 25 | `displaylist_depths/displaylist_depths_test5` | 25 | 1.6s |  |
| 26 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.4s |  |
| 27 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.9s |  |
| 28 | `displaylist_depths/displaylist_depths_test8` | 15 | 18.1s |  |
| 29 | `displaylist_depths/displaylist_depths_test9` | 23 | 2.7s |  |
| 30 | `duplicate_movie_clip_test2` | 21 | 19.7s |  |
| 31 | `event_handler_scope_test` | 16 | 19.0s |  |
| 32 | `getTimer_test` | 8 | 18.6s |  |
| 33 | `get_frame_number_test` | 31 | 20.9s |  |
| 34 | `goto_frame_test` | 15 | 19.1s |  |
| 35 | `instanceNameTest` | 5 | 1.7s |  |
| 36 | `loading/LoadVarsTest` | 36 | 22.1s |  |
| 37 | `loop/loop_test` | 21 | 18.9s |  |
| 38 | `loop/loop_test2` | 15 | 18.6s |  |
| 39 | `loop/loop_test3` | 16 | 18.1s |  |
| 40 | `loop/loop_test4` | 22 | 19.1s |  |
| 41 | `loop/loop_test5` | 24 | 2.7s |  |
| 42 | `loop/loop_test8` | 38 | 20.5s |  |
| 43 | `loop/loop_test9` | 15 | 18.4s |  |
| 44 | `loop/simple_loop_test` | 0 | 18.1s |  |
| 45 | `masks_test2` | 10 | 18.6s |  |
| 46 | `morph_test1` | 0 | 19.1s |  |
| 47 | `move_object_test` | 11 | 18.3s |  |
| 48 | `multi_doactions_and_goto_frame_test` | 6 | 18.9s |  |
| 49 | `new_child_in_unload_test` | 11 | 2.0s |  |
| 50 | `place_and_remove_object_insane_test` | 22 | 20.1s |  |
| 51 | `place_and_remove_object_test` | 13 | 14.5s |  |
| 52 | `register_class/RegisterClassTest3` | 12 | 19.2s |  |
| 53 | `register_class/registerClassTest` | 51 | 21.5s |  |
| 54 | `replace_shapes1test` | 23 | 2.4s |  |
| 55 | `replace_sprites1test` | 21 | 20.0s |  |
| 56 | `reverse_execute_PlaceObject2_test1` | 8 | 19.0s |  |
| 57 | `reverse_execute_PlaceObject2_test2` | 10 | 19.2s |  |
| 58 | `runtime_vm_stack_test` | 9 | 18.8s |  |
| 59 | `shape_test` | 21 | 20.4s |  |
| 60 | `static_vs_dynamic1` | 17 | 18.4s |  |
| 61 | `static_vs_dynamic2` | 18 | 19.1s |  |
| 62 | `timeline_var_test` | 11 | 18.5s |  |
| 63 | `unload_movieclip_test1` | 6 | 18.1s |  |

## Ruffle-Matched Tests

**17 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 20.1s |  |
| 2 | `DefineTextTest` | 4 | 4 | 18.4s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 18.3s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 3.0s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 19.5s |  |
| 6 | `callFunction_test` | 5 | 11 | 18.8s |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.9s |  |
| 8 | `duplicate_movie_clip_test` | 4 | 4 | 19.7s |  |
| 9 | `init_action/InitActionTest` | 6 | 17 | 19.7s |  |
| 10 | `init_action/InitActionTest2` | 24 | 30 | 20.4s |  |
| 11 | `loading/loadMovieTest` | 9 | 9 | 21.2s |  |
| 12 | `loop/loop_test7` | 1 | 8 | 2.1s |  |
| 13 | `path_format_test` | 27 | 28 | 22.3s |  |
| 14 | `place_object_test` | 14 | 14 | 15.0s |  |
| 15 | `place_object_test2` | 20 | 23 | 15.0s |  |
| 16 | `register_class/registerClassTest2` | 8 | 28 | 20.5s |  |
| 17 | `replace_buttons1test` | 3 | 3 | 19.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**8 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 2 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 4 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 6 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |
| 7 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |
| 8 | `loop/loop_test6` | 50.0% | 12 | 24 | 12 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**22 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 2 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 3 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 4 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 5 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 6 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 7 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 8 | `loop/loop_test6` | 50.0% | 12/24 | 24 | 23 |  |
| 9 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 11 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 12 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 13 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 14 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 15 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 16 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 17 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 18 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 19 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 20 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 21 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 22 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
