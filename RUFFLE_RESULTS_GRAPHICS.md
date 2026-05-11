# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `65b80680126b`  
**Date:** 2026-05-11 18:15 UTC  
**Total duration:** 20m38s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 589 | 651 | 90.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 57 | 102 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 7 | 16 | 43.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 61 | 92 | 66.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 44 | 47 | 93.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **907** | **1125** | **80.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,854 | 114,995 | 92.1% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,089 | 4,577 | 67.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 376 | 499 | 75.4% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 773 | 1,276 | 60.6% |
| from_shumway/avm1 | 487 | 491 | 99.2% |
| **Total** | **126,232** | **139,077** | **90.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 49 | - | 1 | 1 |
| from_gnash/actionscript.all | 1 | 3 | - | - |
| from_gnash/misc-ming.all | 23 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 3 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 28 | - | - | - |
| from_shumway/avm1 | 2 | - | - | - |
| **Total** | **106** | **3** | **3** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | click_block | 100% |
| avm1 | netstream_seek_flv | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | sound | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | get_frame_number_test | 90% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 89% |
| avm1 | goto_frame2 | 89% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | ResolveEventsTest | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-swfc.all | sound | 86% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 2 | - | 2 | - |
| from_gnash/misc-ming.all | 1 | - | 2 | - |

**avm1 — newly passing:** `goto_frame_number`, `unload_nested_child`

*Comparing `e0568fe7e53f` → `65b80680126b`*

## Per-Suite Details

### avm1

- **Pass:** 589/651 (90.5%)
- **Duration:** 11m30s across 30 shards
- **Lines:** 105,854/114,995 matching (92.1%)
- **Avg test duration:** 1.0s — slowest: `timeout` (30.6s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 1.0s — slowest: `enumerate-v5` (18.8s)

### from_gnash/misc-ming.all

- **Pass:** 57/102 (55.9%)
- **Duration:** 2m23s across 30 shards
- **Lines:** 3,089/4,577 matching (67.5%)
- **Avg test duration:** 1.3s — slowest: `register_class/registerClassTest2` (18.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.0s)

### from_gnash/misc-swfc.all

- **Pass:** 7/16 (43.8%)
- **Duration:** 14s across 30 shards
- **Lines:** 376/499 matching (75.4%)
- **Avg test duration:** 0.8s — slowest: `action_execution_order_test10` (0.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 15s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.8s — slowest: `missing_bitmap` (1.1s)

### from_shumway

- **Pass:** 61/92 (66.3%)
- **Duration:** 2m12s across 30 shards
- **Lines:** 773/1,276 matching (60.6%)
- **Avg test duration:** 1.4s — slowest: `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` (18.7s)

### from_shumway/avm1

- **Pass:** 44/47 (93.6%)
- **Duration:** 39s across 30 shards
- **Lines:** 487/491 matching (99.2%)
- **Avg test duration:** 0.8s — slowest: `rollover` (0.9s)
