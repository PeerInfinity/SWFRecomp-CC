# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `4858cdcdd92c`  
**Date:** 2026-05-03 18:28 UTC  
**Total duration:** 2h21m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 647 | 92.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 63 | 102 | 61.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 7 | 16 | 43.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **928** | **1121** | **82.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,001 | 114,967 | 92.2% |
| from_gnash/actionscript.all | 15,351 | 16,957 | 90.5% |
| from_gnash/misc-ming.all | 2,875 | 4,577 | 62.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 339 | 499 | 67.9% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,975** | **139,049** | **90.6%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 38 |
| from_gnash/actionscript.all | 5 |
| from_gnash/misc-ming.all | 22 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 5 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **96** |

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
| from_gnash/actionscript.all | Global-v7 | 96% |
| from_gnash/actionscript.all | Global-v8 | 96% |
| from_gnash/actionscript.all | Global-v6 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 2 | - | 46 | - |

**from_gnash/misc-ming.all — newly passing:** `displaylist_depths/displaylist_depths_test9`

*Comparing `e06c67e45668` → `4858cdcdd92c`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 600/647 (92.7%)
- **Duration:** 1h03m49s across 30 shards
- **Lines:** 106,001/114,967 matching (92.2%)
- **Avg test duration:** 5.9s — slowest: `netstream_play_flv_screen` (34.3s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 21m13s across 30 shards
- **Lines:** 15,351/16,957 matching (90.5%)
- **Avg test duration:** 6.6s — slowest: `String-v8` (33.0s)

### from_gnash/misc-ming.all

- **Pass:** 63/102 (61.8%)
- **Duration:** 28m23s across 30 shards
- **Lines:** 2,875/4,577 matching (62.8%)
- **Avg test duration:** 16.6s — slowest: `matrix_test` (100.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m16s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.1s — slowest: `TextFieldTest` (20.0s)

### from_gnash/misc-swfc.all

- **Pass:** 7/16 (43.8%)
- **Duration:** 4m07s across 30 shards
- **Lines:** 339/499 matching (67.9%)
- **Avg test duration:** 15.4s — slowest: `movieclip_destruction_test1` (20.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m19s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.7s — slowest: `trace-as2/super` (19.2s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 14m16s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 9.2s — slowest: `invalidClipDepth` (20.4s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.5s — slowest: `label` (19.1s)
