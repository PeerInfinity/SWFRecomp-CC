# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `f8745996297b`  
**Date:** 2026-05-11 00:07 UTC  
**Total duration:** 2h10m09s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 524 | 651 | 80.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 47 | 102 | 46.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 53 | 92 | 57.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 38 | 47 | 80.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **817** | **1125** | **72.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 104,409 | 114,995 | 90.8% |
| from_gnash/actionscript.all | 15,374 | 16,957 | 90.7% |
| from_gnash/misc-ming.all | 2,828 | 4,505 | 62.8% |
| from_gnash/misc-mtasc.all | 165 | 231 | 71.4% |
| from_gnash/misc-swfc.all | 332 | 499 | 66.5% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 750 | 1,276 | 58.8% |
| from_shumway/avm1 | 467 | 491 | 95.1% |
| **Total** | **124,374** | **139,005** | **89.5%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 116 | - | 1 | 1 |
| from_gnash/actionscript.all | 1 | 3 | - | - |
| from_gnash/misc-ming.all | 36 | - | 3 | - |
| from_gnash/misc-mtasc.all | 1 | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 36 | - | - | - |
| from_shumway/avm1 | 8 | - | - | - |
| **Total** | **203** | **3** | **4** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | button_order | 100% |
| avm1 | click_block | 100% |
| avm1 | create_empty_movie_clip | 100% |
| avm1 | form_loader_encoding_1 | 100% |
| avm1 | issue_2084 | 100% |
| avm1 | loadmovie_replace_root | 100% |
| avm1 | movieclip_in_removed_button | 100% |
| avm1 | textfield_cache_as_bitmap | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | focusrect_property_swf5 | 100% |
| avm1 | focusrect_property_swf7 | 100% |
| avm1 | focusrect_property_swf6 | 100% |
| avm1 | sound | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | string_paths_hidden | 98% |
| avm1 | swf6_case_insensitive | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | loop/loop_test8 | 92% |
| avm1 | unload | 90% |
| from_gnash/misc-ming.all | get_frame_number_test | 90% |
| avm1 | movieclip_library_state_values | 90% |
| avm1 | remove_movie_clip | 90% |
| avm1 | goto_frame2 | 89% |
| avm1 | transform | 89% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-swfc.all | sound | 86% |
| from_shumway | avm1/moviecliploader | 86% |
| from_shumway/avm1 | moviecliploader | 86% |
| avm1 | movieclip_getbounds | 85% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 84% |
| avm1 | local_to_global | 84% |
| avm1 | load_vars | 83% |
| from_shumway | avm1/settimeout | 82% |
| from_shumway/avm1 | settimeout | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |
| from_gnash/misc-ming.all | ResolveEventsTest | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | - | - |

**avm1 — newly passing:** `issue_9885`

*Comparing `e527f410660e` → `f8745996297b`*

## Per-Suite Details

### avm1

- **Pass:** 524/651 (80.5%)
- **Duration:** 1h02m32s across 30 shards
- **Lines:** 104,409/114,995 matching (90.8%)
- **Avg test duration:** 5.7s — slowest: `timeout` (48.3s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 13m57s across 30 shards
- **Lines:** 15,374/16,957 matching (90.7%)
- **Avg test duration:** 4.3s — slowest: `MovieClipLoader-v6` (22.3s)

### from_gnash/misc-ming.all

- **Pass:** 47/102 (46.1%)
- **Duration:** 25m38s across 30 shards
- **Lines:** 2,828/4,505 matching (62.8%)
- **Avg test duration:** 15.0s — slowest: `matrix_test` (23.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 165/231 matching (71.4%)
- **Avg test duration:** 14.4s — slowest: `inheritance` (19.3s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 4m22s across 30 shards
- **Lines:** 332/499 matching (66.5%)
- **Avg test duration:** 16.3s — slowest: `stackscope` (22.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m32s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 18.4s — slowest: `trace-as2/root_onload` (21.8s)

### from_shumway

- **Pass:** 53/92 (57.6%)
- **Duration:** 14m06s across 30 shards
- **Lines:** 750/1,276 matching (58.8%)
- **Avg test duration:** 9.1s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (19.8s)

### from_shumway/avm1

- **Pass:** 38/47 (80.9%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 467/491 matching (95.1%)
- **Avg test duration:** 2.3s — slowest: `text-bind` (18.6s)
