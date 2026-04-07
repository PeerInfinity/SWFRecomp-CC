# Ruffle Test Results (Filtered)

**Date**: 2026-04-07 01:45 UTC

**Git SHA**: `b737c2e02e`

**Run Duration**: 20m 8s

**Filtered**: 0 tests ignored out of 58 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 58 |
| Passing | **9** (15.5%) |
| Failing | 49 |
| Total expected lines | 3388 |
| Matching lines | 1665 (49.1%) |
| Mismatched lines | 1723 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 49 | 100.0% |

## Passing Tests

**9 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `PlaceObject2Test` | 9 | 19.1s |  |
| 2 | `VarAndCharClashTest` | 13 | 18.8s |  |
| 3 | `Video-EmbedSquareTest` | 2 | 15.7s |  |
| 4 | `getTimer_test` | 8 | 19.1s |  |
| 5 | `masks_test2` | 10 | 19.3s |  |
| 6 | `morph_test1` | 0 | 18.7s |  |
| 7 | `move_object_test` | 11 | 19.3s |  |
| 8 | `multi_doactions_and_goto_frame_test` | 6 | 19.3s |  |
| 9 | `unload_movieclip_test1` | 6 | 19.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**26 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `DefineEditTextTest` | 95.4% | 146 | 153 | 7 |  |
| 2 | `matrix_test` | 83.6% | 908 | 1086 | 178 |  |
| 3 | `shape_test` | 81.0% | 17 | 21 | 4 |  |
| 4 | `RollOverOutTest` | 80.0% | 4 | 5 | 1 |  |
| 5 | `place_and_remove_object_test` | 76.9% | 10 | 13 | 3 |  |
| 6 | `attachMovieTest` | 75.0% | 9 | 12 | 3 |  |
| 7 | `DefineEditTextVariableNameTest2` | 74.4% | 29 | 39 | 10 |  |
| 8 | `new_child_in_unload_test` | 72.7% | 8 | 11 | 3 |  |
| 9 | `timeline_var_test` | 72.7% | 8 | 11 | 3 |  |
| 10 | `static_vs_dynamic2` | 72.2% | 13 | 18 | 5 |  |
| 11 | `get_frame_number_test` | 71.0% | 22 | 31 | 9 |  |
| 12 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 13 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 14 | `DefineTextTest` | 68.8% | 11 | 16 | 5 |  |
| 15 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 16 | `static_vs_dynamic1` | 64.7% | 11 | 17 | 6 |  |
| 17 | `event_handler_scope_test` | 62.5% | 10 | 16 | 6 |  |
| 18 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 19 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 20 | `DepthLimitsTest` | 60.0% | 12 | 20 | 8 |  |
| 21 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 22 | `callFunction_test` | 54.5% | 6 | 11 | 5 |  |
| 23 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 24 | `attachExtImported` | 50.0% | 1 | 2 | 1 |  |
| 25 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 26 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**49 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `DefineEditTextTest` | 95.4% | 146/153 | 153 | 153 |  |
| 2 | `matrix_test` | 83.6% | 908/1086 | 1086 | 1086 |  |
| 3 | `shape_test` | 81.0% | 17/21 | 21 | 21 |  |
| 4 | `RollOverOutTest` | 80.0% | 4/5 | 5 | 5 |  |
| 5 | `place_and_remove_object_test` | 76.9% | 10/13 | 13 | 13 |  |
| 6 | `attachMovieTest` | 75.0% | 9/12 | 12 | 12 |  |
| 7 | `DefineEditTextVariableNameTest2` | 74.4% | 29/39 | 39 | 39 |  |
| 8 | `new_child_in_unload_test` | 72.7% | 8/11 | 11 | 11 |  |
| 9 | `timeline_var_test` | 72.7% | 8/11 | 11 | 11 |  |
| 10 | `static_vs_dynamic2` | 72.2% | 13/18 | 18 | 18 |  |
| 11 | `get_frame_number_test` | 71.0% | 22/31 | 31 | 31 |  |
| 12 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 13 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 14 | `DefineTextTest` | 68.8% | 11/16 | 16 | 16 |  |
| 15 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 16 | `static_vs_dynamic1` | 64.7% | 11/17 | 17 | 17 |  |
| 17 | `event_handler_scope_test` | 62.5% | 10/16 | 16 | 16 |  |
| 18 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 19 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 20 | `DepthLimitsTest` | 60.0% | 12/20 | 20 | 20 |  |
| 21 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 22 | `callFunction_test` | 54.5% | 6/11 | 11 | 11 |  |
| 23 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 24 | `attachExtImported` | 50.0% | 1/2 | 2 | 2 |  |
| 25 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 26 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 27 | `runtime_vm_stack_test` | 44.4% | 4/9 | 9 | 9 |  |
| 28 | `DragDropTest` | 40.0% | 18/45 | 45 | 44 |  |
| 29 | `NetStream-SquareTest` | 38.0% | 82/216 | 201 | 216 |  |
| 30 | `consecutive_goto_frame_test` | 30.8% | 4/13 | 13 | 12 |  |
| 31 | `KeyEventOrder` | 23.1% | 6/26 | 25 | 26 |  |
| 32 | `DrawingApiTest` | 21.5% | 20/93 | 93 | 93 |  |
| 33 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 34 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 35 | `place_object_test2` | 20.0% | 4/20 | 20 | 19 |  |
| 36 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 37 | `goto_frame_test` | 13.3% | 2/15 | 13 | 15 |  |
| 38 | `masks_test` | 11.4% | 20/175 | 28 | 175 |  |
| 39 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 40 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 41 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 42 | `opcode_guard_test` | 2.1% | 3/142 | 142 | 18 |  |
| 43 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 44 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 45 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 46 | `path_format_test` | 0.0% | 0/28 | 28 | 27 |  |
| 47 | `place_object_test` | 0.0% | 0/14 | 14 | 12 |  |
| 48 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 49 | `replace_shapes1test` | 0.0% | 0/26 | 26 | 23 |  |
