# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `b232f7e6facb`  
**Date:** 2026-05-11 04:19 UTC  
**Total duration:** 2h06m30s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 577 | 611 | 94.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 52 | 100 | 52.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 7 | 15 | 46.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 59 | 76 | 77.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 41 | 45 | 91.1% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **885** | **1064** | **83.2%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,294 | 95,887 | 99.4% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 2,937 | 4,517 | 65.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 367 | 492 | 74.6% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 579 | 637 | 90.9% |
| from_shumway/avm1 | 473 | 480 | 98.5% |
| **Total** | **115,303** | **119,252** | **96.7%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault | timeout |
|-------|-----------------:|----------------:|---------------:|----------:|---------:|
| avm1 | 27 | 6 | - | - | 1 |
| from_gnash/actionscript.all | 1 | 61 | 3 | - | - |
| from_gnash/misc-ming.all | 29 | 17 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | 2 | - | - | - |
| from_gnash/misc-swfc.all | 3 | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - | - |
| from_shumway | 14 | 3 | - | - | - |
| from_shumway/avm1 | 4 | - | - | - | - |
| **Total** | **78** | **95** | **3** | **2** | **1** |

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
| avm1 | remove_movie_clip | 90% |
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

- **Pass:** 577/611 (94.4%)
- **Ignored:** 40 tests
- **Duration:** 1h01m09s across 30 shards
- **Lines:** 95,294/95,887 matching (99.4%)
- **Avg test duration:** 5.5s — slowest: `timeout` (47.3s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 13m16s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 4.1s — slowest: `ContextMenu-v8` (19.4s)

### from_gnash/misc-ming.all

- **Pass:** 52/100 (52.0%)
- **Ignored:** 2 tests
- **Duration:** 24m44s across 30 shards
- **Lines:** 2,937/4,517 matching (65.0%)
- **Avg test duration:** 14.4s — slowest: `matrix_test` (22.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.9s — slowest: `implementsOpTest` (19.5s)

### from_gnash/misc-swfc.all

- **Pass:** 7/15 (46.7%)
- **Ignored:** 1 tests
- **Duration:** 4m15s across 30 shards
- **Lines:** 367/492 matching (74.6%)
- **Avg test duration:** 15.7s — slowest: `mouse_drag_test` (19.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m25s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 18.0s — slowest: `dict_override` (19.9s)

### from_shumway

- **Pass:** 59/76 (77.6%)
- **Ignored:** 16 tests
- **Duration:** 13m51s across 30 shards
- **Lines:** 579/637 matching (90.9%)
- **Avg test duration:** 7.1s — slowest: `avm1/label` (20.0s)

### from_shumway/avm1

- **Pass:** 41/45 (91.1%)
- **Ignored:** 2 tests
- **Duration:** 1m42s across 30 shards
- **Lines:** 473/480 matching (98.5%)
- **Avg test duration:** 1.8s — slowest: `label` (18.5s)
