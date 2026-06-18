# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 22:05 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 22m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 82 |
| Passing | **49** (59.8%) |
| Ruffle-matched | 21 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **70** (85.4%) |
| Failing | 12 |
| Total expected lines | 4525 |
| Matching lines | 3594 (79.4%) |
| Mismatched lines | 931 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 11 | 91.7% |
| Timeout | 1 | 8.3% |

## Passing Tests

**49 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BeginBitmapFill` | 1 | 23.6s |  |
| 2 | `DefineEditTextTest` | 153 | 10.0s |  |
| 3 | `DefineEditTextVariableNameTest` | 72 | 21.5s |  |
| 4 | `DefineEditTextVariableNameTest2` | 39 | 19.0s |  |
| 5 | `DepthLimitsTest` | 20 | 25.1s |  |
| 6 | `PlaceObject2Test` | 9 | 21.3s |  |
| 7 | `action_order/action_execution_order_test1` | 10 | 21.6s |  |
| 8 | `action_order/action_execution_order_test2` | 5 | 3.1s |  |
| 9 | `action_order/action_execution_order_test7` | 7 | 2.8s |  |
| 10 | `action_order/action_execution_order_test8-v5` | 11 | 22.5s |  |
| 11 | `action_order/action_execution_order_test8-v6` | 11 | 1.2s |  |
| 12 | `action_order/action_execution_order_test9` | 4 | 2.6s |  |
| 13 | `attachExtImported` | 2 | 22.6s |  |
| 14 | `attachImported` | 2 | 2.8s |  |
| 15 | `attachMovieLoopingTest` | 41 | 21.6s |  |
| 16 | `attachMovieTest` | 12 | 22.2s |  |
| 17 | `consecutive_goto_frame_test` | 12 | 2.4s |  |
| 18 | `displaylist_depths/displaylist_depths_test10` | 10 | 17.4s |  |
| 19 | `displaylist_depths/displaylist_depths_test11` | 15 | 2.6s |  |
| 20 | `displaylist_depths/displaylist_depths_test4` | 26 | 2.7s |  |
| 21 | `displaylist_depths/displaylist_depths_test5` | 25 | 14.3s |  |
| 22 | `displaylist_depths/displaylist_depths_test6` | 13 | 1.9s |  |
| 23 | `displaylist_depths/displaylist_depths_test7` | 14 | 1.6s |  |
| 24 | `displaylist_depths/displaylist_depths_test8` | 15 | 1.8s |  |
| 25 | `frame_label_test` | 17 | 4.4s |  |
| 26 | `getTimer_test` | 8 | 3.0s |  |
| 27 | `get_frame_number_test` | 31 | 24.9s |  |
| 28 | `goto_frame_test` | 15 | 24.4s |  |
| 29 | `instanceNameTest` | 5 | 2.8s |  |
| 30 | `loading/LoadVarsTest` | 36 | 25.2s |  |
| 31 | `loop/loop_test4` | 22 | 22.5s |  |
| 32 | `loop/loop_test5` | 24 | 3.8s |  |
| 33 | `loop/loop_test8` | 38 | 23.4s |  |
| 34 | `loop/loop_test9` | 15 | 21.1s |  |
| 35 | `loop/simple_loop_test` | 0 | 24.2s |  |
| 36 | `masks_test2` | 10 | 21.9s |  |
| 37 | `morph_test1` | 0 | 26.2s |  |
| 38 | `place_and_remove_object_test` | 13 | 20.9s |  |
| 39 | `register_class/RegisterClassTest3` | 12 | 4.0s |  |
| 40 | `register_class/registerClassTest` | 51 | 31.1s |  |
| 41 | `replace_sprites1test` | 21 | 3.4s |  |
| 42 | `reverse_execute_PlaceObject2_test1` | 8 | 2.7s |  |
| 43 | `reverse_execute_PlaceObject2_test2` | 10 | 21.3s |  |
| 44 | `runtime_vm_stack_test` | 9 | 0.8s |  |
| 45 | `shape_test` | 21 | 1.5s |  |
| 46 | `static_vs_dynamic1` | 17 | 0.8s |  |
| 47 | `static_vs_dynamic2` | 18 | 22.0s |  |
| 48 | `timeline_var_test` | 11 | 21.8s |  |
| 49 | `unload_movieclip_test1` | 6 | 2.6s |  |

## Ruffle-Matched Tests

**21 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapDataDraw` | 25 | 25 | 26.1s |  |
| 2 | `ButtonEventsTest` | 3 | 642 | 27.0s |  |
| 3 | `ButtonPropertiesTest` | 19 | 20 | 21.5s |  |
| 4 | `DefineTextTest` | 4 | 4 | 2.4s |  |
| 5 | `DragDropTest` | 4 | 4 | 4.1s |  |
| 6 | `EmbeddedFontTest` | 27 | 27 | 27.6s |  |
| 7 | `KeyEventOrder` | 20 | 23 | 21.6s |  |
| 8 | `callFunction_test` | 6 | 11 | 3.0s |  |
| 9 | `displaylist_depths/displaylist_depths_test` | 7 | 7 | 24.9s |  |
| 10 | `displaylist_depths/displaylist_depths_test2` | 14 | 14 | 20.9s |  |
| 11 | `displaylist_depths/displaylist_depths_test3` | 13 | 13 | 2.8s |  |
| 12 | `init_action/InitActionTest` | 6 | 17 | 24.1s |  |
| 13 | `init_action/InitActionTest2` | 24 | 30 | 24.8s |  |
| 14 | `key_event_test` | 5 | 6 | 23.4s |  |
| 15 | `loading/LoadBitmapTest` | 3 | 3 | 22.6s |  |
| 16 | `loading/loadMovieTest` | 9 | 9 | 5.4s |  |
| 17 | `loop/loop_test6` | 1 | 12 | 3.6s |  |
| 18 | `loop/loop_test7` | 1 | 8 | 3.1s |  |
| 19 | `matrix_test` | 5 | 9 | 109.2s |  |
| 20 | `place_object_test` | 14 | 14 | 3.7s |  |
| 21 | `place_object_test2` | 22 | 23 | 21.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81 | 95 | 14 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26 | 32 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `gotoFrame2Test` | runtime timeout (>10s) | 67.8s |  |

## All Output Mismatches

**11 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DrawingApiTest` | 85.3% | 81/95 | 95 | 93 |  |
| 2 | `action_order/action_execution_order_test11` | 81.2% | 26/32 | 32 | 32 |  |
| 3 | `GradientFillTest` | 42.8% | 119/278 | 278 | 278 |  |
| 4 | `NetStream-SquareTest` | 42.1% | 91/216 | 201 | 216 |  |
| 5 | `action_order/action_execution_order_test` | 36.8% | 7/19 | 18 | 19 |  |
| 6 | `action_order/action_execution_order_extend_test` | 21.9% | 7/32 | 28 | 32 |  |
| 7 | `masks_test` | 16.0% | 28/175 | 28 | 175 |  |
| 8 | `action_order/PlaceAndRemove` | 15.6% | 15/96 | 45 | 96 |  |
| 9 | `action_order/ActionOrderTest5` | 12.9% | 8/62 | 62 | 51 |  |
| 10 | `action_order/ActionOrderTest4` | 7.6% | 9/118 | 118 | 64 |  |
| 11 | `register_class/RegisterClassTest4` | 4.7% | 3/64 | 64 | 42 |  |
