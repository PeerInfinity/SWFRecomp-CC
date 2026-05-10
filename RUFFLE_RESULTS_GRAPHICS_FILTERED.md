# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `7767c2657e47`  
**Date:** 2026-05-10 21:29 UTC  
**Total duration:** 16m12s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 509 | 611 | 83.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 43 | 100 | 43.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 6 | 15 | 40.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 52 | 76 | 68.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 37 | 45 | 82.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **796** | **1064** | **74.8%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 93,292 | 95,887 | 97.3% |
| from_gnash/actionscript.all | 15,374 | 16,957 | 90.7% |
| from_gnash/misc-ming.all | 2,760 | 4,445 | 62.1% |
| from_gnash/misc-mtasc.all | 165 | 231 | 71.4% |
| from_gnash/misc-swfc.all | 326 | 492 | 66.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 558 | 637 | 87.6% |
| from_shumway/avm1 | 456 | 480 | 95.0% |
| **Total** | **112,980** | **119,180** | **94.8%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault | timeout |
|-------|-----------------:|----------------:|---------------:|----------:|---------:|
| avm1 | 95 | 6 | - | - | 1 |
| from_gnash/actionscript.all | 1 | 61 | 3 | - | - |
| from_gnash/misc-ming.all | 40 | 14 | - | 3 | - |
| from_gnash/misc-mtasc.all | 1 | 1 | - | - | - |
| from_gnash/misc-swfc.all | 4 | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - | - |
| from_shumway | 19 | 5 | - | - | - |
| from_shumway/avm1 | 8 | - | - | - | - |
| **Total** | **168** | **93** | **3** | **3** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | button_order | 100% |
| avm1 | click_block | 100% |
| avm1 | execution_order2 | 100% |
| avm1 | execution_order4 | 100% |
| avm1 | movieclip_in_removed_button | 100% |
| avm1 | target_clip_removed | 100% |
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
| avm1 | transform | 89% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_shumway | avm1/moviecliploader | 86% |
| avm1 | movieclip_getbounds | 85% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 84% |
| avm1 | local_to_global | 84% |
| avm1 | tell_target_invalid | 83% |
| from_shumway | avm1/settimeout | 82% |
| from_shumway/avm1 | settimeout | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |
| avm1 | execution_order1 | 80% |
| avm1 | tell_target_invalid_swf6 | 80% |
| from_gnash/misc-ming.all | ResolveEventsTest | 80% |

## Per-Suite Details

### avm1

- **Pass:** 509/611 (83.3%)
- **Ignored:** 40 tests
- **Duration:** 9m23s across 30 shards
- **Lines:** 93,292/95,887 matching (97.3%)
- **Avg test duration:** 0.8s — slowest: `timeout` (30.5s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 2m41s across 30 shards
- **Lines:** 15,374/16,957 matching (90.7%)
- **Avg test duration:** 0.8s — slowest: `Inheritance-v6` (1.4s)

### from_gnash/misc-ming.all

- **Pass:** 43/100 (43.0%)
- **Ignored:** 2 tests
- **Duration:** 1m51s across 30 shards
- **Lines:** 2,760/4,445 matching (62.1%)
- **Avg test duration:** 1.0s — slowest: `matrix_test` (4.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 165/231 matching (71.4%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.0s)

### from_gnash/misc-swfc.all

- **Pass:** 6/15 (40.0%)
- **Ignored:** 1 tests
- **Duration:** 14s across 30 shards
- **Lines:** 326/492 matching (66.3%)
- **Avg test duration:** 0.8s — slowest: `movieclip_destruction_test2` (0.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 14s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.7s — slowest: `missing_bitmap` (0.8s)

### from_shumway

- **Pass:** 52/76 (68.4%)
- **Ignored:** 16 tests
- **Duration:** 1m07s across 30 shards
- **Lines:** 558/637 matching (87.6%)
- **Avg test duration:** 0.7s — slowest: `timeline/timeline_as2_3` (0.9s)

### from_shumway/avm1

- **Pass:** 37/45 (82.2%)
- **Ignored:** 2 tests
- **Duration:** 34s across 30 shards
- **Lines:** 456/480 matching (95.0%)
- **Avg test duration:** 0.7s — slowest: `mouse-transparency` (0.8s)
