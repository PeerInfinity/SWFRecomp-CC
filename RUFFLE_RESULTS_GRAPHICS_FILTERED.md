# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `f8745996297b`  
**Date:** 2026-05-11 00:07 UTC  
**Total duration:** 2h10m09s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 523 | 611 | 85.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 47 | 100 | 47.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 6 | 15 | 40.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 53 | 76 | 69.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 38 | 45 | 84.4% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **816** | **1064** | **76.7%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,404 | 95,887 | 98.5% |
| from_gnash/actionscript.all | 15,374 | 16,957 | 90.7% |
| from_gnash/misc-ming.all | 2,802 | 4,445 | 63.0% |
| from_gnash/misc-mtasc.all | 165 | 231 | 71.4% |
| from_gnash/misc-swfc.all | 326 | 492 | 66.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 561 | 637 | 88.1% |
| from_shumway/avm1 | 459 | 480 | 95.6% |
| **Total** | **114,140** | **119,180** | **95.8%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault | timeout |
|-------|-----------------:|----------------:|---------------:|----------:|---------:|
| avm1 | 81 | 6 | - | - | 1 |
| from_gnash/actionscript.all | 1 | 61 | 3 | - | - |
| from_gnash/misc-ming.all | 34 | 16 | - | 3 | - |
| from_gnash/misc-mtasc.all | 1 | 1 | - | - | - |
| from_gnash/misc-swfc.all | 4 | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - | - |
| from_shumway | 20 | 3 | - | - | - |
| from_shumway/avm1 | 7 | - | - | - | - |
| **Total** | **148** | **93** | **3** | **3** | **1** |

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
| avm1 | string_paths_hidden | 98% |
| avm1 | swf6_case_insensitive | 98% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | loop/loop_test8 | 92% |
| avm1 | unload | 90% |
| from_gnash/misc-ming.all | get_frame_number_test | 90% |
| avm1 | remove_movie_clip | 90% |
| avm1 | goto_frame2 | 89% |
| avm1 | transform | 89% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_shumway | avm1/moviecliploader | 86% |
| avm1 | movieclip_getbounds | 85% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 84% |
| avm1 | local_to_global | 84% |
| from_shumway | avm1/settimeout | 82% |
| from_shumway/avm1 | settimeout | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |
| from_gnash/misc-ming.all | ResolveEventsTest | 80% |

## Per-Suite Details

### avm1

- **Pass:** 523/611 (85.6%)
- **Ignored:** 40 tests
- **Duration:** 1h02m32s across 30 shards
- **Lines:** 94,404/95,887 matching (98.5%)
- **Avg test duration:** 5.7s — slowest: `timeout` (48.3s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 13m57s across 30 shards
- **Lines:** 15,374/16,957 matching (90.7%)
- **Avg test duration:** 4.3s — slowest: `MovieClipLoader-v6` (22.3s)

### from_gnash/misc-ming.all

- **Pass:** 47/100 (47.0%)
- **Ignored:** 2 tests
- **Duration:** 25m38s across 30 shards
- **Lines:** 2,802/4,445 matching (63.0%)
- **Avg test duration:** 15.0s — slowest: `matrix_test` (23.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 165/231 matching (71.4%)
- **Avg test duration:** 14.4s — slowest: `inheritance` (19.3s)

### from_gnash/misc-swfc.all

- **Pass:** 6/15 (40.0%)
- **Ignored:** 1 tests
- **Duration:** 4m22s across 30 shards
- **Lines:** 326/492 matching (66.3%)
- **Avg test duration:** 16.2s — slowest: `stackscope` (22.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m32s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 18.4s — slowest: `trace-as2/root_onload` (21.8s)

### from_shumway

- **Pass:** 53/76 (69.7%)
- **Ignored:** 16 tests
- **Duration:** 14m06s across 30 shards
- **Lines:** 561/637 matching (88.1%)
- **Avg test duration:** 7.2s — slowest: `avm1/text-bind` (19.5s)

### from_shumway/avm1

- **Pass:** 38/45 (84.4%)
- **Ignored:** 2 tests
- **Duration:** 1m49s across 30 shards
- **Lines:** 459/480 matching (95.6%)
- **Avg test duration:** 1.9s — slowest: `text-bind` (18.6s)
