# Ruffle Test Results (Filtered)

**Date**: 2026-05-01 20:01 UTC

**Git SHA**: `900ae800db`

**Run Duration**: 23m 33s

**Filtered**: 0 tests ignored out of 102 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **61** (59.8%) |
| Ruffle-matched | 14 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **75** (73.5%) |
| Failing | 27 |
| Total expected lines | 4577 |
| Matching lines | 2815 (61.5%) |
| Mismatched lines | 1762 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 27 | 100.0% |

## Passing Tests

**61 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 17.5s |  |
| 2 | `DefineEditTextTest` | 153 | 17.9s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 17.5s |  |
| 4 | `DepthLimitsTest` | 20 | 17.5s |  |
| 5 | `PlaceObject2Test` | 9 | 17.6s |  |
| 6 | `ResolveEventsTest` | 15 | 0.3s |  |
| 7 | `RollOverOutTest` | 5 | 17.8s |  |
| 8 | `VarAndCharClashTest` | 13 | 0.3s |  |
| 9 | `Video-EmbedSquareTest` | 2 | 16.9s |  |
| 10 | `action_order/action_execution_order_test1` | 10 | 16.7s |  |
| 11 | `action_order/action_execution_order_test2` | 5 | 17.7s |  |
| 12 | `action_order/action_execution_order_test3` | 4 | 18.0s |  |
| 13 | `action_order/action_execution_order_test7` | 7 | 17.7s |  |
| 14 | `action_order/action_execution_order_test8-v5` | 11 | 17.5s |  |
| 15 | `action_order/action_execution_order_test8-v6` | 11 | 0.3s |  |
| 16 | `action_order/action_execution_order_test9` | 4 | 16.6s |  |
| 17 | `attachExtImported` | 2 | 16.8s |  |
| 18 | `attachImported` | 2 | 0.3s |  |
| 19 | `attachMovieLoopingTest` | 41 | 17.0s |  |
| 20 | `attachMovieTest` | 12 | 17.8s |  |
| 21 | `consecutive_goto_frame_test` | 12 | 17.6s |  |
| 22 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.0s |  |
| 23 | `displaylist_depths/displaylist_depths_test11` | 15 | 17.1s |  |
| 24 | `displaylist_depths/displaylist_depths_test4` | 26 | 17.4s |  |
| 25 | `displaylist_depths/displaylist_depths_test5` | 25 | 0.3s |  |
| 26 | `displaylist_depths/displaylist_depths_test6` | 13 | 0.3s |  |
| 27 | `displaylist_depths/displaylist_depths_test7` | 14 | 0.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test8` | 15 | 16.4s |  |
| 29 | `event_handler_scope_test` | 16 | 17.1s |  |
| 30 | `getTimer_test` | 8 | 16.8s |  |
| 31 | `get_frame_number_test` | 31 | 17.0s |  |
| 32 | `goto_frame_test` | 15 | 17.1s |  |
| 33 | `instanceNameTest` | 5 | 0.2s |  |
| 34 | `loading/LoadVarsTest` | 36 | 18.0s |  |
| 35 | `loop/loop_test` | 21 | 17.4s |  |
| 36 | `loop/loop_test2` | 15 | 17.3s |  |
| 37 | `loop/loop_test3` | 16 | 16.7s |  |
| 38 | `loop/loop_test4` | 22 | 16.7s |  |
| 39 | `loop/loop_test5` | 24 | 0.3s |  |
| 40 | `loop/loop_test8` | 38 | 16.6s |  |
| 41 | `loop/loop_test9` | 15 | 17.1s |  |
| 42 | `loop/simple_loop_test` | 0 | 17.0s |  |
| 43 | `masks_test2` | 10 | 16.8s |  |
| 44 | `morph_test1` | 0 | 17.0s |  |
| 45 | `move_object_test` | 11 | 16.6s |  |
| 46 | `multi_doactions_and_goto_frame_test` | 6 | 16.6s |  |
| 47 | `new_child_in_unload_test` | 11 | 16.6s |  |
| 48 | `place_and_remove_object_insane_test` | 22 | 17.6s |  |
| 49 | `place_and_remove_object_test` | 13 | 17.4s |  |
| 50 | `register_class/RegisterClassTest3` | 12 | 17.6s |  |
| 51 | `register_class/registerClassTest` | 51 | 17.9s |  |
| 52 | `replace_shapes1test` | 23 | 0.3s |  |
| 53 | `replace_sprites1test` | 21 | 17.2s |  |
| 54 | `reverse_execute_PlaceObject2_test1` | 8 | 17.0s |  |
| 55 | `reverse_execute_PlaceObject2_test2` | 10 | 17.1s |  |
| 56 | `runtime_vm_stack_test` | 9 | 16.8s |  |
| 57 | `shape_test` | 21 | 17.2s |  |
| 58 | `static_vs_dynamic1` | 17 | 16.8s |  |
| 59 | `static_vs_dynamic2` | 18 | 17.1s |  |
| 60 | `timeline_var_test` | 11 | 17.1s |  |
| 61 | `unload_movieclip_test1` | 6 | 17.0s |  |

## Ruffle-Matched Tests

**14 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ButtonPropertiesTest` | 20 | 20 | 17.4s |  |
| 2 | `DefineTextTest` | 4 | 4 | 17.4s |  |
| 3 | `KeyEventOrder` | 20 | 23 | 16.8s |  |
| 4 | `action_order/action_execution_order_test4` | 7 | 26 | 0.4s |  |
| 5 | `action_order/action_execution_order_test6` | 5 | 21 | 17.7s |  |
| 6 | `callFunction_test` | 5 | 11 | 17.5s |  |
| 7 | `init_action/InitActionTest` | 6 | 17 | 17.7s |  |
| 8 | `init_action/InitActionTest2` | 24 | 30 | 17.6s |  |
| 9 | `loading/loadMovieTest` | 9 | 9 | 17.1s |  |
| 10 | `loop/loop_test7` | 1 | 8 | 0.3s |  |
| 11 | `path_format_test` | 27 | 28 | 17.8s |  |
| 12 | `place_object_test` | 14 | 14 | 17.4s |  |
| 13 | `place_object_test2` | 20 | 23 | 17.2s |  |
| 14 | `replace_buttons1test` | 3 | 3 | 17.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99 | 111 | 12 |  |
| 2 | `matrix_test` | 84.5% | 918 | 1086 | 168 |  |
| 3 | `register_class/registerClassTest2` | 79.5% | 35 | 44 | 9 |  |
| 4 | `DrawingApiTest` | 69.5% | 66 | 95 | 29 |  |
| 5 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 6 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 7 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 8 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 9 | `action_order/action_execution_order_test11` | 53.1% | 17 | 32 | 15 |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17 | 32 | 15 |  |
| 11 | `loop/loop_test6` | 50.0% | 12 | 24 | 12 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**27 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `displaylist_depths/displaylist_depths_test` | 89.2% | 99/111 | 111 | 111 |  |
| 2 | `matrix_test` | 84.5% | 918/1086 | 1086 | 1086 |  |
| 3 | `register_class/registerClassTest2` | 79.5% | 35/44 | 44 | 44 |  |
| 4 | `DrawingApiTest` | 69.5% | 66/95 | 95 | 93 |  |
| 5 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 6 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 7 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 8 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 9 | `action_order/action_execution_order_test11` | 53.1% | 17/32 | 32 | 32 |  |
| 10 | `displaylist_depths/displaylist_depths_test3` | 53.1% | 17/32 | 29 | 32 |  |
| 11 | `loop/loop_test6` | 50.0% | 12/24 | 24 | 23 |  |
| 12 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 13 | `displaylist_depths/displaylist_depths_test2` | 48.4% | 15/31 | 28 | 31 |  |
| 14 | `opcode_guard_test` | 47.6% | 10/21 | 21 | 18 |  |
| 15 | `register_class/RegisterClassTest4` | 40.5% | 17/42 | 39 | 42 |  |
| 16 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 17 | `key_event_test` | 38.8% | 33/85 | 85 | 66 |  |
| 18 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 19 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 20 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 21 | `loop/loop_test10` | 10.7% | 3/28 | 23 | 28 |  |
| 22 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 23 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 24 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 25 | `ButtonEventsTest` | 6.9% | 47/679 | 81 | 679 |  |
| 26 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 27 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
