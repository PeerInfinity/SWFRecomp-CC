# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-10 18:18 UTC

**Git SHA**: `ebaa7506c1`

**Run Duration**: 21m 34s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 102 |
| Passing | **43** (42.2%) |
| Ruffle-matched | 14 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **57** (55.9%) |
| Failing | 45 |
| Total expected lines | 4505 |
| Matching lines | 2786 (61.8%) |
| Mismatched lines | 1719 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 42 | 93.3% |
| Runtime Segfault | 3 | 6.7% |

## Passing Tests

**43 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 0.9s |  |
| 2 | `DefineEditTextTest` | 153 | 1.6s |  |
| 3 | `DefineEditTextVariableNameTest2` | 39 | 23.1s |  |
| 4 | `PlaceObject2Test` | 9 | 2.4s |  |
| 5 | `RollOverOutTest` | 5 | 3.0s |  |
| 6 | `VarAndCharClashTest` | 13 | 2.3s |  |
| 7 | `Video-EmbedSquareTest` | 2 | 19.5s |  |
| 8 | `action_order/action_execution_order_test1` | 10 | 2.7s |  |
| 9 | `action_order/action_execution_order_test3` | 4 | 2.6s |  |
| 10 | `action_order/action_execution_order_test7` | 7 | 2.4s |  |
| 11 | `action_order/action_execution_order_test9` | 4 | 19.7s |  |
| 12 | `attachExtImported` | 2 | 20.9s |  |
| 13 | `attachImported` | 2 | 2.4s |  |
| 14 | `attachMovieLoopingTest` | 41 | 20.0s |  |
| 15 | `attachMovieTest` | 12 | 20.3s |  |
| 16 | `displaylist_depths/displaylist_depths_test10` | 10 | 19.8s |  |
| 17 | `displaylist_depths/displaylist_depths_test11` | 15 | 19.7s |  |
| 18 | `displaylist_depths/displaylist_depths_test4` | 26 | 20.2s |  |
| 19 | `displaylist_depths/displaylist_depths_test5` | 25 | 2.6s |  |
| 20 | `displaylist_depths/displaylist_depths_test6` | 13 | 2.6s |  |
| 21 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.9s |  |
| 22 | `getTimer_test` | 8 | 2.7s |  |
| 23 | `instanceNameTest` | 5 | 2.2s |  |
| 24 | `loading/LoadVarsTest` | 36 | 23.5s |  |
| 25 | `loop/loop_test` | 21 | 2.7s |  |
| 26 | `loop/loop_test2` | 15 | 20.2s |  |
| 27 | `loop/loop_test3` | 16 | 19.3s |  |
| 28 | `loop/loop_test4` | 22 | 20.1s |  |
| 29 | `loop/loop_test5` | 24 | 3.5s |  |
| 30 | `loop/loop_test9` | 15 | 0.9s |  |
| 31 | `loop/simple_loop_test` | 0 | 1.0s |  |
| 32 | `masks_test2` | 10 | 21.3s |  |
| 33 | `morph_test1` | 0 | 21.3s |  |
| 34 | `move_object_test` | 11 | 0.8s |  |
| 35 | `multi_doactions_and_goto_frame_test` | 6 | 0.7s |  |
| 36 | `new_child_in_unload_test` | 11 | 0.7s |  |
| 37 | `register_class/RegisterClassTest3` | 12 | 3.1s |  |
| 38 | `register_class/registerClassTest` | 51 | 22.4s |  |
| 39 | `replace_sprites1test` | 21 | 20.1s |  |
| 40 | `reverse_execute_PlaceObject2_test1` | 8 | 19.4s |  |
| 41 | `reverse_execute_PlaceObject2_test2` | 10 | 19.6s |  |
| 42 | `runtime_vm_stack_test` | 9 | 2.6s |  |
| 43 | `unload_movieclip_test1` | 6 | 19.2s |  |

## Ruffle-Matched Tests

**14 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `DefineTextTest` | 4 | 4 | 2.9s |  |
| 2 | `callFunction_test` | 11 | 11 | 3.4s |  |
| 3 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 2.7s |  |
| 4 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.6s |  |
| 5 | `init_action/InitActionTest` | 6 | 17 | 2.9s |  |
| 6 | `init_action/InitActionTest2` | 24 | 30 | 20.6s |  |
| 7 | `loop/loop_test6` | 1 | 12 | 3.4s |  |
| 8 | `loop/loop_test7` | 1 | 8 | 2.9s |  |
| 9 | `matrix_test` | 5 | 9 | 107.4s |  |
| 10 | `path_format_test` | 27 | 28 | 23.4s |  |
| 11 | `place_object_test` | 14 | 14 | 20.8s |  |
| 12 | `place_object_test2` | 20 | 23 | 20.4s |  |
| 13 | `register_class/registerClassTest2` | 8 | 28 | 21.2s |  |
| 14 | `replace_buttons1test` | 3 | 3 | 20.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**18 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loop/loop_test8` | 92.1% | 35 | 38 | 3 |  |
| 2 | `get_frame_number_test` | 90.3% | 28 | 31 | 3 |  |
| 3 | `action_order/action_execution_order_test8-v5` | 81.8% | 9 | 11 | 2 |  |
| 4 | `action_order/action_execution_order_test8-v6` | 81.8% | 9 | 11 | 2 |  |
| 5 | `DrawingApiTest` | 81.6% | 80 | 98 | 18 |  |
| 6 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 7 | `ResolveEventsTest` | 80.0% | 12 | 15 | 3 |  |
| 8 | `DepthLimitsTest` | 75.0% | 15 | 20 | 5 |  |
| 9 | `place_and_remove_object_test` | 69.2% | 9 | 13 | 4 |  |
| 10 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 11 | `static_vs_dynamic1` | 64.7% | 11 | 17 | 6 |  |
| 12 | `shape_test` | 61.9% | 13 | 21 | 8 |  |
| 13 | `DragDropTest` | 60.0% | 27 | 45 | 18 |  |
| 14 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |
| 15 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9 | 16 | 7 |  |
| 16 | `displaylist_depths/displaylist_depths_test` | 55.0% | 61 | 111 | 50 |  |
| 17 | `timeline_var_test` | 54.5% | 6 | 11 | 5 |  |
| 18 | `opcode_guard_test` | 52.6% | 10 | 19 | 9 |  |

## Segfaults

**3 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 3.2s |  |
| 2 | `ButtonPropertiesTest` | 3.1s |  |
| 3 | `DefineEditTextVariableNameTest` | 28.0s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**42 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loop/loop_test8` | 92.1% | 35/38 | 38 | 38 |  |
| 2 | `get_frame_number_test` | 90.3% | 28/31 | 31 | 31 |  |
| 3 | `action_order/action_execution_order_test8-v5` | 81.8% | 9/11 | 11 | 11 |  |
| 4 | `action_order/action_execution_order_test8-v6` | 81.8% | 9/11 | 11 | 11 |  |
| 5 | `DrawingApiTest` | 81.6% | 80/98 | 98 | 93 |  |
| 6 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 7 | `ResolveEventsTest` | 80.0% | 12/15 | 15 | 15 |  |
| 8 | `DepthLimitsTest` | 75.0% | 15/20 | 20 | 20 |  |
| 9 | `place_and_remove_object_test` | 69.2% | 9/13 | 13 | 13 |  |
| 10 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 11 | `static_vs_dynamic1` | 64.7% | 11/17 | 17 | 17 |  |
| 12 | `shape_test` | 61.9% | 13/21 | 21 | 21 |  |
| 13 | `DragDropTest` | 60.0% | 27/45 | 45 | 44 |  |
| 14 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 15 | `displaylist_depths/displaylist_depths_test8` | 56.2% | 9/16 | 16 | 15 |  |
| 16 | `displaylist_depths/displaylist_depths_test` | 55.0% | 61/111 | 111 | 111 |  |
| 17 | `timeline_var_test` | 54.5% | 6/11 | 10 | 11 |  |
| 18 | `opcode_guard_test` | 52.6% | 10/19 | 19 | 18 |  |
| 19 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 20 | `goto_frame_test` | 46.7% | 7/15 | 15 | 15 |  |
| 21 | `register_class/RegisterClassTest4` | 38.1% | 16/42 | 39 | 42 |  |
| 22 | `loading/loadMovieTest` | 36.8% | 67/182 | 182 | 80 |  |
| 23 | `masks_test` | 34.9% | 61/175 | 69 | 175 |  |
| 24 | `key_event_test` | 34.8% | 23/66 | 51 | 66 |  |
| 25 | `replace_shapes1test` | 34.8% | 8/23 | 23 | 23 |  |
| 26 | `NetStream-SquareTest` | 33.3% | 72/216 | 131 | 216 |  |
| 27 | `static_vs_dynamic2` | 33.3% | 6/18 | 18 | 18 |  |
| 28 | `KeyEventOrder` | 25.0% | 8/32 | 32 | 26 |  |
| 29 | `action_order/action_execution_order_test2` | 20.0% | 1/5 | 1 | 5 |  |
| 30 | `displaylist_depths/displaylist_depths_test9` | 13.0% | 3/23 | 21 | 23 |  |
| 31 | `duplicate_movie_clip_test` | 12.1% | 4/33 | 29 | 33 |  |
| 32 | `event_handler_scope_test` | 12.1% | 11/91 | 91 | 16 |  |
| 33 | `duplicate_movie_clip_test2` | 12.0% | 10/83 | 83 | 21 |  |
| 34 | `action_order/ActionOrderTest5` | 11.5% | 7/61 | 61 | 51 |  |
| 35 | `loop/loop_test10` | 9.3% | 5/54 | 54 | 28 |  |
| 36 | `action_order/action_execution_order_test4` | 7.3% | 13/179 | 179 | 26 |  |
| 37 | `action_order/ActionOrderTest4` | 5.4% | 4/74 | 74 | 64 |  |
| 38 | `action_order/ActionOrderTest3` | 5.3% | 4/75 | 75 | 62 |  |
| 39 | `consecutive_goto_frame_test` | 2.5% | 5/201 | 201 | 12 |  |
| 40 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 41 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
| 42 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
