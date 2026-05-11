# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `a48ecfae33b6`  
**Date:** 2026-05-11 22:57 UTC  
**Total duration:** 2h10m07s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 605 | 651 | 92.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 102 | 63.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **946** | **1125** | **84.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,041 | 114,995 | 92.2% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,131 | 4,577 | 68.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 388 | 499 | 77.8% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **126,584** | **139,077** | **91.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 34 | - | 1 |
| from_gnash/actionscript.all | 1 | 3 | - |
| from_gnash/misc-ming.all | 13 | - | 2 |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 2 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **66** | **3** | **3** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 3 | - | 4 | - |
| from_gnash/misc-swfc.all | - | - | 1 | - |

**avm1 — newly passing:** `netstream_seek_flv`, `sound`, `timeout`

*Comparing `6beabb40c149` → `a48ecfae33b6`*

## Per-Suite Details

### avm1

- **Pass:** 605/651 (92.9%)
- **Duration:** 1h02m58s across 30 shards
- **Lines:** 106,041/114,995 matching (92.2%)
- **Avg test duration:** 5.7s — slowest: `form_loader_encoding_1` (25.0s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 13m56s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 4.3s — slowest: `Sound-v7` (20.8s)

### from_gnash/misc-ming.all

- **Pass:** 65/102 (63.7%)
- **Duration:** 25m19s across 30 shards
- **Lines:** 3,131/4,577 matching (68.4%)
- **Avg test duration:** 14.8s — slowest: `matrix_test` (23.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.0s — slowest: `implementsOpTest` (19.2s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4m12s across 30 shards
- **Lines:** 388/499 matching (77.8%)
- **Avg test duration:** 15.7s — slowest: `registerclass_test3` (19.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m22s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.8s — slowest: `missing_bitmap` (21.1s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m17s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.3s — slowest: `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` (20.7s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.4s — slowest: `text-bind` (18.6s)
