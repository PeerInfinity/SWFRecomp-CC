# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-09 00:00 UTC

**Git SHA**: `2a4adfc3fd`

**Run Duration**: 20m 41s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 58 |
| Passing | **8** (13.8%) |
| Failing | 50 |
| Total expected lines | 3388 |
| Matching lines | 1662 (49.1%) |
| Mismatched lines | 1726 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 50 | 100.0% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `PlaceObject2Test` | 9 | 21.2s |  |
| 2 | `VarAndCharClashTest` | 13 | 19.2s |  |
| 3 | `Video-EmbedSquareTest` | 2 | 19.8s |  |
| 4 | `masks_test2` | 10 | 19.3s |  |
| 5 | `morph_test1` | 0 | 20.4s |  |
| 6 | `move_object_test` | 11 | 19.7s |  |
| 7 | `multi_doactions_and_goto_frame_test` | 6 | 19.4s |  |
| 8 | `unload_movieclip_test1` | 6 | 19.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**27 tests** within reach

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
| 18 | `getTimer_test` | 62.5% | 5 | 8 | 3 |  |
| 19 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 20 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 21 | `DepthLimitsTest` | 60.0% | 12 | 20 | 8 |  |
| 22 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 23 | `callFunction_test` | 54.5% | 6 | 11 | 5 |  |
| 24 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 25 | `attachExtImported` | 50.0% | 1 | 2 | 1 |  |
| 26 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 27 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**50 tests** with output mismatch, sorted by match rate (best first)

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
| 18 | `getTimer_test` | 62.5% | 5/8 | 8 | 8 |  |
| 19 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 20 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 21 | `DepthLimitsTest` | 60.0% | 12/20 | 20 | 20 |  |
| 22 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 23 | `callFunction_test` | 54.5% | 6/11 | 11 | 11 |  |
| 24 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 25 | `attachExtImported` | 50.0% | 1/2 | 2 | 2 |  |
| 26 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 27 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 28 | `runtime_vm_stack_test` | 44.4% | 4/9 | 9 | 9 |  |
| 29 | `DragDropTest` | 40.0% | 18/45 | 45 | 44 |  |
| 30 | `NetStream-SquareTest` | 38.0% | 82/216 | 201 | 216 |  |
| 31 | `consecutive_goto_frame_test` | 30.8% | 4/13 | 13 | 12 |  |
| 32 | `KeyEventOrder` | 23.1% | 6/26 | 25 | 26 |  |
| 33 | `DrawingApiTest` | 21.5% | 20/93 | 93 | 93 |  |
| 34 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 35 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 36 | `place_object_test2` | 20.0% | 4/20 | 20 | 19 |  |
| 37 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 38 | `goto_frame_test` | 13.3% | 2/15 | 13 | 15 |  |
| 39 | `masks_test` | 11.4% | 20/175 | 28 | 175 |  |
| 40 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 41 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 42 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 43 | `opcode_guard_test` | 2.1% | 3/142 | 142 | 18 |  |
| 44 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 45 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 46 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 47 | `path_format_test` | 0.0% | 0/28 | 28 | 27 |  |
| 48 | `place_object_test` | 0.0% | 0/14 | 14 | 12 |  |
| 49 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 50 | `replace_shapes1test` | 0.0% | 0/26 | 26 | 23 |  |
