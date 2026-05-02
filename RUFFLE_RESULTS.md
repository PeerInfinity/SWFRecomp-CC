# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b2070f86f917`  
**Date:** 2026-05-02 16:20 UTC  
**Total duration:** 1h52m10s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 647 | 92.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 62 | 102 | 60.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **926** | **1121** | **82.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,001 | 114,967 | 92.2% |
| from_gnash/actionscript.all | 15,347 | 16,957 | 90.5% |
| from_gnash/misc-ming.all | 2,828 | 4,577 | 61.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 331 | 499 | 66.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,916** | **139,049** | **90.6%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 38 |
| from_gnash/actionscript.all | 6 |
| from_gnash/misc-ming.all | 25 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 7 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **102** |

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
| from_gnash/misc-swfc.all | swf4opcode | 95% |
| from_gnash/actionscript.all | Global-v6 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/actionscript.all | MovieClip-v5 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | - | 1 |
| from_gnash/actionscript.all | - | - | 34 | - |

*Comparing `80ead5236b26` → `b2070f86f917`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 600/647 (92.7%)
- **Duration:** 53m07s across 30 shards
- **Lines:** 106,001/114,967 matching (92.2%)
- **Avg test duration:** 4.9s — slowest: `lessthan` (20.8s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 11m19s across 30 shards
- **Lines:** 15,347/16,957 matching (90.5%)
- **Avg test duration:** 3.5s — slowest: `NetStream-v7` (19.8s)

### from_gnash/misc-ming.all

- **Pass:** 62/102 (60.8%)
- **Duration:** 22m51s across 30 shards
- **Lines:** 2,828/4,577 matching (61.8%)
- **Avg test duration:** 13.4s — slowest: `matrix_test` (21.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m53s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.5s — slowest: `hello` (17.5s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 3m57s across 30 shards
- **Lines:** 331/499 matching (66.3%)
- **Avg test duration:** 14.8s — slowest: `submoviegetvar` (20.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m04s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 16.8s — slowest: `trace-as2/shortstack` (20.0s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 12m31s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.1s — slowest: `avm1/mouse-transparency` (18.8s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 1.7s — slowest: `hitarea` (18.9s)
