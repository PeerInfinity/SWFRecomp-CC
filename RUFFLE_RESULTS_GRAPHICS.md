# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `0fcfe324ea46`  
**Date:** 2026-05-11 01:17 UTC  
**Total duration:** 16m57s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 568 | 651 | 87.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 48 | 102 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 58 | 92 | 63.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 42 | 47 | 89.4% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **870** | **1125** | **77.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,463 | 114,995 | 91.7% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 2,860 | 4,505 | 63.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 332 | 499 | 66.5% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 766 | 1,276 | 60.0% |
| from_shumway/avm1 | 482 | 491 | 98.2% |
| **Total** | **125,556** | **139,005** | **90.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 69 | - | 2 | 1 |
| from_gnash/actionscript.all | 1 | 3 | 1 | - |
| from_gnash/misc-ming.all | 34 | - | 3 | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 31 | - | - | - |
| from_shumway/avm1 | 4 | - | - | - |
| **Total** | **144** | **3** | **6** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | click_block | 100% |
| avm1 | mcl_unloadclip | 100% |
| avm1 | netstream_seek_flv | 100% |
| avm1 | unloadmovienum | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | focusrect_property_swf6 | 100% |
| avm1 | sound | 99% |
| avm1 | date | 99% |
| avm1 | string_paths_hidden | 98% |
| avm1 | swf6_case_insensitive | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | loop/loop_test8 | 92% |
| avm1 | unload | 90% |
| from_gnash/misc-ming.all | get_frame_number_test | 90% |
| avm1 | remove_movie_clip | 90% |
| avm1 | goto_frame2 | 89% |
| avm1 | transform | 89% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | ResolveEventsTest | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-swfc.all | sound | 86% |
| avm1 | movieclip_getbounds | 85% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 84% |
| avm1 | local_to_global | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 3 | - | - | - |
| from_gnash/actionscript.all | - | 1 | - | - |
| from_gnash/misc-ming.all | - | - | 1 | - |

**avm1 — newly passing:** `button_order`, `create_empty_movie_clip`, `movieclip_in_removed_button`

**from_gnash/actionscript.all — newly failing:** `case-v5`

*Comparing `f1b087ec6a6b` → `0fcfe324ea46`*

## Per-Suite Details

### avm1

- **Pass:** 568/651 (87.3%)
- **Duration:** 10m09s across 30 shards
- **Lines:** 105,463/114,995 matching (91.7%)
- **Avg test duration:** 0.9s — slowest: `timeout` (30.7s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 2m40s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 0.8s — slowest: `Inheritance-v6` (1.5s)

### from_gnash/misc-ming.all

- **Pass:** 48/102 (47.1%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 2,860/4,505 matching (63.5%)
- **Avg test duration:** 1.0s — slowest: `matrix_test` (5.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 7s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.1s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 12s across 30 shards
- **Lines:** 332/499 matching (66.5%)
- **Avg test duration:** 0.7s — slowest: `action_execution_order_test10` (0.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 15s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.8s — slowest: `dict_event` (0.9s)

### from_shumway

- **Pass:** 58/92 (63.0%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 766/1,276 matching (60.0%)
- **Avg test duration:** 0.7s — slowest: `timeline/timeline_as2_3` (0.9s)

### from_shumway/avm1

- **Pass:** 42/47 (89.4%)
- **Duration:** 36s across 30 shards
- **Lines:** 482/491 matching (98.2%)
- **Avg test duration:** 0.7s — slowest: `setinterval` (1.1s)
