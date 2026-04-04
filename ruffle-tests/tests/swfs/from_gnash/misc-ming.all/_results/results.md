# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-04 01:50 UTC

**Git SHA**: `7a348be46a`

**Run Duration**: 19m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 55 |
| Passing | **8** (14.5%) |
| Failing | 47 |
| Total expected lines | 3321 |
| Matching lines | 1601 (48.2%) |
| Mismatched lines | 1720 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 46 | 97.9% |
| Runtime Segfault | 1 | 2.1% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `VarAndCharClashTest` | 13 | 18.7s |  |
| 2 | `Video-EmbedSquareTest` | 2 | 19.6s |  |
| 3 | `getTimer_test` | 8 | 18.8s |  |
| 4 | `masks_test2` | 10 | 19.8s |  |
| 5 | `morph_test1` | 0 | 18.2s |  |
| 6 | `move_object_test` | 11 | 18.4s |  |
| 7 | `multi_doactions_and_goto_frame_test` | 6 | 18.9s |  |
| 8 | `unload_movieclip_test1` | 6 | 18.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**23 tests** within reach

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
| 11 | `attachMovieLoopingTest` | 70.7% | 29 | 41 | 12 |  |
| 12 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7 | 10 | 3 |  |
| 13 | `place_and_remove_object_insane_test` | 68.2% | 15 | 22 | 7 |  |
| 14 | `static_vs_dynamic1` | 64.7% | 11 | 17 | 6 |  |
| 15 | `event_handler_scope_test` | 62.5% | 10 | 16 | 6 |  |
| 16 | `duplicate_movie_clip_test2` | 61.9% | 13 | 21 | 8 |  |
| 17 | `DefineEditTextVariableNameTest` | 60.5% | 49 | 81 | 32 |  |
| 18 | `EmbeddedFontTest` | 57.5% | 50 | 87 | 37 |  |
| 19 | `callFunction_test` | 54.5% | 6 | 11 | 5 |  |
| 20 | `ResolveEventsTest` | 53.3% | 8 | 15 | 7 |  |
| 21 | `attachExtImported` | 50.0% | 1 | 2 | 1 |  |
| 22 | `attachImported` | 50.0% | 1 | 2 | 1 |  |
| 23 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `PlaceObject2Test` | 20.6s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**46 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `attachMovieLoopingTest` | 70.7% | 29/41 | 41 | 41 |  |
| 12 | `reverse_execute_PlaceObject2_test2` | 70.0% | 7/10 | 10 | 10 |  |
| 13 | `place_and_remove_object_insane_test` | 68.2% | 15/22 | 22 | 22 |  |
| 14 | `static_vs_dynamic1` | 64.7% | 11/17 | 17 | 17 |  |
| 15 | `event_handler_scope_test` | 62.5% | 10/16 | 16 | 16 |  |
| 16 | `duplicate_movie_clip_test2` | 61.9% | 13/21 | 21 | 21 |  |
| 17 | `DefineEditTextVariableNameTest` | 60.5% | 49/81 | 81 | 72 |  |
| 18 | `EmbeddedFontTest` | 57.5% | 50/87 | 87 | 87 |  |
| 19 | `callFunction_test` | 54.5% | 6/11 | 11 | 11 |  |
| 20 | `ResolveEventsTest` | 53.3% | 8/15 | 15 | 15 |  |
| 21 | `attachExtImported` | 50.0% | 1/2 | 2 | 2 |  |
| 22 | `attachImported` | 50.0% | 1/2 | 2 | 2 |  |
| 23 | `reverse_execute_PlaceObject2_test1` | 50.0% | 4/8 | 8 | 8 |  |
| 24 | `runtime_vm_stack_test` | 44.4% | 4/9 | 9 | 9 |  |
| 25 | `DragDropTest` | 40.0% | 18/45 | 45 | 44 |  |
| 26 | `NetStream-SquareTest` | 32.9% | 71/216 | 131 | 216 |  |
| 27 | `consecutive_goto_frame_test` | 30.8% | 4/13 | 13 | 12 |  |
| 28 | `KeyEventOrder` | 23.1% | 6/26 | 25 | 26 |  |
| 29 | `DrawingApiTest` | 21.5% | 20/93 | 93 | 93 |  |
| 30 | `replace_sprites1test` | 20.8% | 5/24 | 24 | 21 |  |
| 31 | `instanceNameTest` | 20.0% | 1/5 | 5 | 5 |  |
| 32 | `place_object_test2` | 20.0% | 4/20 | 20 | 19 |  |
| 33 | `key_event_test` | 13.6% | 9/66 | 29 | 66 |  |
| 34 | `goto_frame_test` | 13.3% | 2/15 | 13 | 15 |  |
| 35 | `masks_test` | 11.4% | 20/175 | 28 | 175 |  |
| 36 | `duplicate_movie_clip_test` | 9.1% | 3/33 | 30 | 33 |  |
| 37 | `ButtonPropertiesTest` | 8.7% | 2/23 | 22 | 23 |  |
| 38 | `ButtonEventsTest` | 2.4% | 16/679 | 77 | 679 |  |
| 39 | `opcode_guard_test` | 2.1% | 3/142 | 142 | 18 |  |
| 40 | `BeginBitmapFill` | 0.0% | 0/1 | 1 | 1 |  |
| 41 | `Version4Loader` | 0.0% | 0/11 | 0 | 11 |  |
| 42 | `frame_label_test` | 0.0% | 0/17 | 0 | 17 |  |
| 43 | `path_format_test` | 0.0% | 0/28 | 28 | 27 |  |
| 44 | `place_object_test` | 0.0% | 0/14 | 14 | 12 |  |
| 45 | `replace_buttons1test` | 0.0% | 0/24 | 24 | 18 |  |
| 46 | `replace_shapes1test` | 0.0% | 0/26 | 26 | 23 |  |
