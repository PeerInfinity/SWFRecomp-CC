# Ruffle Test Results (Filtered)

**Date**: 2026-05-03 20:48 UTC

**Git SHA**: `712885df0e`

**Run Duration**: 23m 16s

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
| 1 | `BeginBitmapFill` | 1 | 17.1s |  |
| 2 | `DefineEditTextTest` | 153 | 17.4s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 17.1s |  |
| 4 | `DepthLimitsTest` | 20 | 17.2s |  |
| 5 | `PlaceObject2Test` | 9 | 16.9s |  |
| 6 | `ResolveEventsTest` | 15 | 0.3s |  |
| 7 | `RollOverOutTest` | 5 | 17.0s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 18.8s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 17.6s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 17.2s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 17.0s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 17.5s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 17.5s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 16.8s |  |
| 17 | `attachExtImported` | 2 | 16.8s |  |
| 18 | `attachImported` | 2 | 0.3s |  |
| 19 | `attachMovieLoopingTest` | 41 | 16.9s |  |
| 20 | `attachMovieTest` | 12 | 16.7s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 16.6s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 18.0s |  |
| 23 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test4` | 26 | 16.9s |  |
| 25 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.2s |  |
| 26 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.2s |  |
| 27 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.2s |  |
| 28 | `displaylist_depths/displaylist_depths_test8` | 15 | 17.6s |  |
| 29 | `displaylist_depths/displaylist_depths_test9` | 23 | 0.4s |  |
| 30 | `duplicate_movie_clip_test2` | 21 | 17.9s |  |
| 31 | `event_handler_scope_test` | 16 | 18.2s |  |
| 32 | `getTimer_test` | 8 | 16.6s |  |
| 33 | `get_frame_number_test` | 31 | 17.0s |  |
| 34 | `goto_frame_test` | 15 | 16.9s |  |
| 35 | `instanceNameTest` | 5 | 0.3s |  |
| 36 | `loading/LoadVarsTest` | 36 | 18.9s |  |
| 37 | `loop/loop_test` | 21 | 17.3s |  |
| 38 | `loop/loop_test2` | 15 | 16.9s |  |
| 39 | `loop/loop_test3` | 16 | 16.7s |  |
| 40 | `loop/loop_test4` | 22 | 16.8s |  |
| 41 | `loop/loop_test5` | 24 | 0.3s |  |
| 42 | `loop/loop_test8` | 38 | 17.2s |  |
| 43 | `loop/loop_test9` | 15 | 17.0s |  |
| 44 | `loop/simple_loop_test` | 0 | 17.1s |  |
| 45 | `masks_test2` | 10 | 14.3s |  |
| 46 | `morph_test1` | 0 | 14.3s |  |
| 47 | `move_object_test` | 11 | 17.1s |  |
| 48 | `multi_doactions_and_goto_frame_test` | 6 | 16.9s |  |
| 49 | `new_child_in_unload_test` | 11 | 17.0s |  |
| 50 | `place_and_remove_object_insane_test` | 22 | 17.0s |  |
| 51 | `place_and_remove_object_test` | 13 | 14.1s |  |
| 52 | `register_class/RegisterClassTest3` | 12 | 16.7s |  |
| 53 | `register_class/registerClassTest` | 51 | 16.8s |  |
| 54 | `replace_shapes1test` | 23 | 0.3s |  |
| 55 | `replace_sprites1test` | 21 | 16.8s |  |
| 56 | `reverse_execute_PlaceObject2_test1` | 8 | 16.6s |  |
| 57 | `reverse_execute_PlaceObject2_test2` | 10 | 16.7s |  |
| 58 | `runtime_vm_stack_test` | 9 | 17.7s |  |
| 59 | `shape_test` | 21 | 17.8s |  |
| 60 | `static_vs_dynamic1` | 17 | 17.7s |  |
| 61 | `static_vs_dynamic2` | 18 | 17.2s |  |
| 62 | `timeline_var_test` | 11 | 17.2s |  |
| 63 | `unload_movieclip_test1` | 6 | 17.2s |  |

## Ruffle-Matched Tests

**17 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 16.9s |  |
| 2 | `DefineTextTest` | 4 | 4 | 16.9s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 17.8s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 0.3s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 17.5s |  |
| 6 | `callFunction_test` | 5 | 11 | 16.8s |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 17.0s |  |
| 8 | `duplicate_movie_clip_test` | 4 | 4 | 17.6s |  |
| 9 | `init_action/InitActionTest` | 6 | 17 | 17.0s |  |
| 10 | `init_action/InitActionTest2` | 24 | 30 | 17.1s |  |
| 11 | `loading/loadMovieTest` | 9 | 9 | 18.0s |  |
| 12 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 13 | `path_format_test` | 27 | 28 | 17.2s |  |
| 14 | `place_object_test` | 14 | 14 | 14.5s |  |
| 15 | `place_object_test2` | 20 | 23 | 14.0s |  |
| 16 | `register_class/registerClassTest2` | 8 | 28 | 16.9s |  |
| 17 | `replace_buttons1test` | 3 | 3 | 16.8s |  |

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
