# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `6beabb40c149`  
**Date:** 2026-05-11 21:26 UTC  
**Total duration:** 17m31s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 651 | 92.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 102 | 63.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **943** | **1125** | **83.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,037 | 114,995 | 92.2% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,131 | 4,577 | 68.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 387 | 499 | 77.6% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **126,579** | **139,077** | **91.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 36 | - | 1 | 1 |
| from_gnash/actionscript.all | 1 | 3 | - | - |
| from_gnash/misc-ming.all | 13 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 2 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| **Total** | **68** | **3** | **3** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | netstream_seek_flv | 100% |
| avm1 | sound | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-swfc.all | sound | 86% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | 105 | - |
| from_gnash/misc-ming.all | 2 | - | 11 | - |
| from_shumway | 1 | - | - | - |

**from_gnash/misc-ming.all — newly passing:** `displaylist_depths/displaylist_depths_test8`, `timeline_var_test`

**from_shumway — newly passing:** `timeline/timeline_as2_1`

*Comparing `ce31587cf186` → `6beabb40c149`*

## Per-Suite Details

### avm1

- **Pass:** 602/651 (92.5%)
- **Duration:** 10m26s across 30 shards
- **Lines:** 106,037/114,995 matching (92.2%)
- **Avg test duration:** 0.9s — slowest: `timeout` (30.6s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 2m51s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 0.8s — slowest: `Inheritance-v6` (1.5s)

### from_gnash/misc-ming.all

- **Pass:** 65/102 (63.7%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 3,131/4,577 matching (68.4%)
- **Avg test duration:** 1.0s — slowest: `matrix_test` (5.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 14s across 30 shards
- **Lines:** 387/499 matching (77.6%)
- **Avg test duration:** 0.8s — slowest: `action_execution_order_test10` (0.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 15s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.8s — slowest: `missing_bitmap` (0.9s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 0.8s — slowest: `timeline/timeline_as2_3` (1.1s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 38s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 0.8s — slowest: `rollover` (0.9s)
