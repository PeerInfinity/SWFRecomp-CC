# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `f1b087ec6a6b`  
**Date:** 2026-05-11 00:46 UTC  
**Total duration:** 17m30s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 564 | 611 | 92.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 48 | 100 | 48.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 6 | 15 | 40.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 58 | 76 | 76.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 41 | 45 | 91.1% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **866** | **1064** | **81.4%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,235 | 95,887 | 99.3% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 2,833 | 4,445 | 63.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 326 | 492 | 66.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 577 | 637 | 90.6% |
| from_shumway/avm1 | 473 | 480 | 98.5% |
| **Total** | **115,097** | **119,180** | **96.6%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault | timeout |
|-------|-----------------:|----------------:|---------------:|----------:|---------:|
| avm1 | 40 | 6 | - | - | 1 |
| from_gnash/actionscript.all | 1 | 61 | 3 | - | - |
| from_gnash/misc-ming.all | 32 | 17 | - | 3 | - |
| from_gnash/misc-mtasc.all | - | 2 | - | - | - |
| from_gnash/misc-swfc.all | 4 | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - | - |
| from_shumway | 15 | 3 | - | - | - |
| from_shumway/avm1 | 4 | - | - | - | - |
| **Total** | **96** | **95** | **3** | **3** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | button_order | 100% |
| avm1 | click_block | 100% |
| avm1 | create_empty_movie_clip | 100% |
| avm1 | mcl_unloadclip | 100% |
| avm1 | movieclip_in_removed_button | 100% |
| avm1 | netstream_seek_flv | 100% |
| avm1 | unloadmovienum | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
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
| avm1 | movieclip_getbounds | 85% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 84% |
| avm1 | local_to_global | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |
| from_gnash/misc-ming.all | ResolveEventsTest | 80% |

## Per-Suite Details

### avm1

- **Pass:** 564/611 (92.3%)
- **Ignored:** 40 tests
- **Duration:** 10m12s across 30 shards
- **Lines:** 95,235/95,887 matching (99.3%)
- **Avg test duration:** 0.9s — slowest: `timeout` (30.5s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 2m55s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 0.9s — slowest: `Transform-v5` (2.0s)

### from_gnash/misc-ming.all

- **Pass:** 48/100 (48.0%)
- **Ignored:** 2 tests
- **Duration:** 1m52s across 30 shards
- **Lines:** 2,833/4,445 matching (63.7%)
- **Avg test duration:** 1.0s — slowest: `matrix_test` (4.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.9s — slowest: `TextFieldTest` (1.2s)

### from_gnash/misc-swfc.all

- **Pass:** 6/15 (40.0%)
- **Ignored:** 1 tests
- **Duration:** 15s across 30 shards
- **Lines:** 326/492 matching (66.3%)
- **Avg test duration:** 0.9s — slowest: `movieclip_destruction_test2` (1.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 17s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.9s — slowest: `dict_callframe` (1.4s)

### from_shumway

- **Pass:** 58/76 (76.3%)
- **Ignored:** 16 tests
- **Duration:** 1m14s across 30 shards
- **Lines:** 577/637 matching (90.6%)
- **Avg test duration:** 0.7s — slowest: `avm1/duplicateMovieClip/name-coercion` (1.1s)

### from_shumway/avm1

- **Pass:** 41/45 (91.1%)
- **Ignored:** 2 tests
- **Duration:** 36s across 30 shards
- **Lines:** 473/480 matching (98.5%)
- **Avg test duration:** 0.7s — slowest: `setinterval` (1.0s)
