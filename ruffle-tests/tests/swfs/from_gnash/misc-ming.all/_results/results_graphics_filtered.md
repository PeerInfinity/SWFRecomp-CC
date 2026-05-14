# Ruffle Test Results (Filtered)

**Date**: 2026-05-14 19:34 UTC

**Git SHA**: `321bbbae51`

**Run Duration**: 35m 16s

**Filtered**: 2 tests ignored out of 110 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 108 |
| Passing | **65** (60.2%) |
| Ruffle-matched | 23 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **88** (81.5%) |
| Failing | 20 |
| Total expected lines | 5179 |
| Matching lines | 3355 (64.8%) |
| Mismatched lines | 1824 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 18 | 90.0% |
| Segfault | 2 | 10.0% |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 27.1s |  |
| 2 | `DefineEditTextTest` | 153 | 29.9s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 26.4s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 22.8s |  |
| 5 | `DepthLimitsTest` | 20 | 21.9s |  |
| 6 | `PlaceObject2Test` | 9 | 20.3s |  |
| 7 | `ResolveEventsTest` | 15 | 23.3s |  |
| 8 | `RollOverOutTest` | 5 | 22.6s |  |
| 9 | `VarAndCharClashTest` | 13 | 2.7s |  |
| 10 | `Version4Loader` | 11 | 2.1s |  |
| 11 | `Video-EmbedSquareTest` | 2 | 17.2s |  |
| 12 | `action_order/action_execution_order_test1` | 10 | 20.6s |  |
| 13 | `action_order/action_execution_order_test2` | 5 | 20.5s |  |
| 14 | `action_order/action_execution_order_test3` | 4 | 20.2s |  |
| 15 | `action_order/action_execution_order_test7` | 7 | 20.1s |  |
| 16 | `action_order/action_execution_order_test8-v5` | 11 | 20.4s |  |
| 17 | `action_order/action_execution_order_test8-v6` | 11 | 1.1s |  |
| 18 | `action_order/action_execution_order_test9` | 4 | 2.5s |  |
| 19 | `attachExtImported` | 2 | 21.5s |  |
| 20 | `attachImported` | 2 | 2.7s |  |
| 21 | `attachMovieLoopingTest` | 41 | 20.8s |  |
| 22 | `attachMovieTest` | 12 | 22.0s |  |
| 23 | `consecutive_goto_frame_test` | 12 | 20.5s |  |
| 24 | `displaylist_depths/displaylist_depths_test10` | 10 | 20.5s |  |
| 25 | `displaylist_depths/displaylist_depths_test11` | 15 | 20.1s |  |
| 26 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.7s |  |
| 27 | `displaylist_depths/displaylist_depths_test5` | 25 | 21.3s |  |
| 28 | `displaylist_depths/displaylist_depths_test6` | 13 | 3.0s |  |
| 29 | `displaylist_depths/displaylist_depths_test7` | 14 | 2.3s |  |
| 30 | `displaylist_depths/displaylist_depths_test8` | 15 | 2.8s |  |
| 31 | `displaylist_depths/displaylist_depths_test9` | 23 | 22.1s |  |
| 32 | `duplicate_movie_clip_test2` | 21 | 22.1s |  |
| 33 | `event_handler_scope_test` | 16 | 3.2s |  |
| 34 | `frame_label_test` | 17 | 22.5s |  |
| 35 | `getTimer_test` | 8 | 20.8s |  |
| 36 | `get_frame_number_test` | 31 | 23.7s |  |
| 37 | `goto_frame_test` | 15 | 22.0s |  |
| 38 | `instanceNameTest` | 5 | 2.4s |  |
| 39 | `loading/LoadVarsTest` | 36 | 23.1s |  |
| 40 | `loop/loop_test` | 21 | 19.5s |  |
| 41 | `loop/loop_test2` | 15 | 20.9s |  |
| 42 | `loop/loop_test3` | 16 | 2.4s |  |
| 43 | `loop/loop_test4` | 22 | 21.6s |  |
| 44 | `loop/loop_test5` | 24 | 22.8s |  |
| 45 | `loop/loop_test8` | 38 | 4.9s |  |
| 46 | `loop/loop_test9` | 15 | 21.1s |  |
| 47 | `loop/simple_loop_test` | 0 | 25.2s |  |
| 48 | `masks_test2` | 10 | 20.3s |  |
| 49 | `morph_test1` | 0 | 23.3s |  |
| 50 | `move_object_test` | 11 | 19.8s |  |
| 51 | `multi_doactions_and_goto_frame_test` | 6 | 19.6s |  |
| 52 | `new_child_in_unload_test` | 11 | 19.8s |  |
| 53 | `place_and_remove_object_test` | 13 | 19.6s |  |
| 54 | `register_class/RegisterClassTest3` | 12 | 20.6s |  |
| 55 | `register_class/registerClassTest` | 51 | 23.5s |  |
| 56 | `replace_shapes1test` | 23 | 3.0s |  |
| 57 | `replace_sprites1test` | 21 | 20.4s |  |
| 58 | `reverse_execute_PlaceObject2_test1` | 8 | 19.7s |  |
| 59 | `reverse_execute_PlaceObject2_test2` | 10 | 20.0s |  |
| 60 | `runtime_vm_stack_test` | 9 | 20.4s |  |
| 61 | `shape_test` | 21 | 23.5s |  |
| 62 | `static_vs_dynamic1` | 17 | 19.8s |  |
| 63 | `static_vs_dynamic2` | 18 | 21.7s |  |
| 64 | `timeline_var_test` | 11 | 21.1s |  |
| 65 | `unload_movieclip_test1` | 6 | 20.9s |  |

## Ruffle-Matched Tests

**23 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 26.4s |  |
| 2 | `DefineTextTest` | 4 | 4 | 20.3s |  |
| 3 | `DragDropTest` | 12 | 12 | 3.5s |  |
| 4 | `KeyEventOrder` | 20 | 23 | 20.9s |  |
| 5 | `action_order/action_execution_order_test4` | 7 | 26 | 21.3s |  |
| 6 | `callFunction_test` | 5 | 11 | 21.8s |  |
| 7 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 28.3s |  |
| 8 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.2s |  |
| 9 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.8s |  |
| 10 | `duplicate_movie_clip_test` | 4 | 4 | 22.5s |  |
| 11 | `init_action/InitActionTest` | 6 | 17 | 17.8s |  |
| 12 | `init_action/InitActionTest2` | 24 | 30 | 18.9s |  |
| 13 | `key_event_test` | 5 | 6 | 20.9s |  |
| 14 | `loading/loadMovieTest` | 9 | 9 | 5.0s |  |
| 15 | `loop/loop_test10` | 23 | 23 | 22.3s |  |
| 16 | `loop/loop_test6` | 1 | 12 | 22.4s |  |
| 17 | `loop/loop_test7` | 1 | 8 | 3.0s |  |
| 18 | `matrix_test` | 5 | 9 | 102.9s |  |
| 19 | `path_format_test` | 28 | 28 | 22.9s |  |
| 20 | `place_object_test` | 14 | 14 | 21.6s |  |
| 21 | `place_object_test2` | 20 | 23 | 19.6s |  |
| 22 | `register_class/registerClassTest2` | 8 | 28 | 22.3s |  |
| 23 | `replace_buttons1test` | 3 | 3 | 20.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80 | 95 | 15 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16 | 19 | 3 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13 | 17 | 4 |  |
| 5 | `place_and_remove_object_insane_test` | 72.7% | 16 | 22 | 6 |  |
| 6 | `EmbeddedFontTest` | 58.6% | 51 | 87 | 36 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `ButtonEventsTest` | 28.5s |  |
| 2 | `ButtonPropertiesTest` | 23.8s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**18 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 84.2% | 80/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test` | 84.2% | 16/19 | 19 | 19 |  |
| 3 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 4 | `loading/LoadBitmapTest` | 76.5% | 13/17 | 17 | 17 |  |
| 5 | `place_and_remove_object_insane_test` | 72.7% | 16/22 | 22 | 22 |  |
| 6 | `EmbeddedFontTest` | 58.6% | 51/87 | 87 | 87 |  |
| 7 | `action_order/action_execution_order_test5` | 49.1% | 26/53 | 53 | 35 |  |
| 8 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 9 | `NetStream-SquareTest` | 39.8% | 86/216 | 201 | 216 |  |
| 10 | `TextSnapshotTest` | 37.1% | 49/132 | 132 | 132 |  |
| 11 | `action_order/action_execution_order_extend_test` | 25.0% | 8/32 | 28 | 32 |  |
| 12 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 13 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 14 | `action_order/ActionOrderTest5` | 13.1% | 8/61 | 61 | 51 |  |
| 15 | `action_order/ActionOrderTest4` | 9.5% | 7/74 | 74 | 64 |  |
| 16 | `action_order/ActionOrderTest3` | 8.0% | 6/75 | 75 | 62 |  |
| 17 | `PrototypeEventListeners` | 3.1% | 1/32 | 12 | 32 |  |
| 18 | `action_order/action_execution_order_test6` | 0.0% | 0/24 | 20 | 24 |  |
