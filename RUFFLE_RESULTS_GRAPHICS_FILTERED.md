# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `e0568fe7e53f`  
**Date:** 2026-05-11 17:30 UTC  
**Total duration:** 2h08m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 586 | 611 | 95.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 57 | 100 | 57.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 7 | 15 | 46.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 61 | 76 | 80.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 43 | 45 | 95.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **903** | **1064** | **84.9%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,518 | 95,887 | 99.6% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,061 | 4,517 | 67.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 370 | 492 | 75.2% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 584 | 637 | 91.7% |
| from_shumway/avm1 | 478 | 480 | 99.6% |
| **Total** | **115,664** | **119,252** | **97.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault | timeout |
|-------|-----------------:|----------------:|---------------:|----------:|---------:|
| avm1 | 18 | 6 | - | - | 1 |
| from_gnash/actionscript.all | 1 | 61 | 3 | - | - |
| from_gnash/misc-ming.all | 22 | 19 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | 2 | - | - | - |
| from_gnash/misc-swfc.all | 2 | 6 | - | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - | - |
| from_shumway | 12 | 3 | - | - | - |
| from_shumway/avm1 | 2 | - | - | - | - |
| **Total** | **57** | **98** | **3** | **2** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | click_block | 100% |
| avm1 | netstream_seek_flv | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | sound | 99% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | get_frame_number_test | 90% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 89% |
| avm1 | goto_frame2 | 89% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | ResolveEventsTest | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |
| avm1 | unload_nested_child | 80% |

## Per-Suite Details

### avm1

- **Pass:** 586/611 (95.9%)
- **Ignored:** 40 tests
- **Duration:** 1h01m33s across 30 shards
- **Lines:** 95,518/95,887 matching (99.6%)
- **Avg test duration:** 5.6s — slowest: `timeout` (47.8s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 13m35s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 4.2s — slowest: `NetStream-v7` (19.9s)

### from_gnash/misc-ming.all

- **Pass:** 57/100 (57.0%)
- **Ignored:** 2 tests
- **Duration:** 25m23s across 30 shards
- **Lines:** 3,061/4,517 matching (67.8%)
- **Avg test duration:** 14.8s — slowest: `displaylist_depths/displaylist_depths_test8` (27.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.4s — slowest: `enum` (19.0s)

### from_gnash/misc-swfc.all

- **Pass:** 7/15 (46.7%)
- **Ignored:** 1 tests
- **Duration:** 4m27s across 30 shards
- **Lines:** 370/492 matching (75.2%)
- **Avg test duration:** 16.1s — slowest: `registerclass_test3` (20.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m33s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 18.5s — slowest: `missing_bitmap` (20.1s)

### from_shumway

- **Pass:** 61/76 (80.3%)
- **Ignored:** 16 tests
- **Duration:** 13m51s across 30 shards
- **Lines:** 584/637 matching (91.7%)
- **Avg test duration:** 7.1s — slowest: `avm1/rollover` (19.4s)

### from_shumway/avm1

- **Pass:** 43/45 (95.6%)
- **Ignored:** 2 tests
- **Duration:** 1m45s across 30 shards
- **Lines:** 478/480 matching (99.6%)
- **Avg test duration:** 1.9s — slowest: `label` (18.7s)
