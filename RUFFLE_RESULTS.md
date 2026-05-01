# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `d48ebaec6db3`  
**Date:** 2026-05-01 21:45 UTC  
**Total duration:** 1h02m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 647 | 92.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 122 | 190 | 64.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **923** | **1121** | **82.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,002 | 114,967 | 92.2% |
| from_gnash/actionscript.all | 15,243 | 16,957 | 89.9% |
| from_gnash/misc-ming.all | 2,815 | 4,577 | 61.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,777** | **139,049** | **90.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 38 |
| from_gnash/actionscript.all | 8 |
| from_gnash/misc-ming.all | 27 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 7 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **106** |

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
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | 3 | - | - |
| from_gnash/misc-swfmill.all | 1 | - | 1 | - |

**from_gnash/misc-swfmill.all — newly passing:** `jump_to_prev_block`

*Comparing `48a97e0b07bf` → `d48ebaec6db3`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 600/647 (92.7%)
- **Duration:** 27m13s across 30 shards
- **Lines:** 106,002/114,967 matching (92.2%)
- **Avg test duration:** 2.5s — slowest: `netstream_play_flv_screen` (33.4s)

### from_gnash/actionscript.all

- **Pass:** 122/190 (64.2%)
- **Duration:** 5m58s across 30 shards
- **Lines:** 15,243/16,957 matching (89.9%)
- **Avg test duration:** 1.8s — slowest: `array-v5` (26.6s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 12m51s across 30 shards
- **Lines:** 2,815/4,577 matching (61.5%)
- **Avg test duration:** 7.5s — slowest: `masks_test` (28.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 42s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 4.6s — slowest: `TextFieldTest` (18.1s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 1m57s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 7.3s — slowest: `movieclip_destruction_test4` (19.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 2m43s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 9.0s — slowest: `initaction_in_definesprite` (19.0s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 9m45s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 6.3s — slowest: `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` (20.2s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 1.4s — slowest: `label` (18.6s)
