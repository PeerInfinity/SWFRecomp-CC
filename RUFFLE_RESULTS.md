# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `71eb98ea5b54`  
**Date:** 2026-05-04 18:24 UTC  
**Total duration:** 2h12m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 647 | 93.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 63 | 102 | 61.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 7 | 16 | 43.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **932** | **1121** | **83.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,034 | 114,967 | 92.2% |
| from_gnash/actionscript.all | 15,370 | 16,957 | 90.6% |
| from_gnash/misc-ming.all | 2,859 | 4,577 | 62.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 339 | 499 | 67.9% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **126,011** | **139,049** | **90.6%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 36 |
| from_gnash/actionscript.all | 2 |
| from_gnash/misc-ming.all | 21 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 5 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **90** |

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
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 9 | - |

**avm1 — newly passing:** `assetnative`

*Comparing `cf88749e4c09` → `71eb98ea5b54`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 602/647 (93.0%)
- **Duration:** 1h00m28s across 30 shards
- **Lines:** 106,034/114,967 matching (92.2%)
- **Avg test duration:** 5.5s — slowest: `netstream_play_flv_screen` (37.0s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 17m41s across 30 shards
- **Lines:** 15,370/16,957 matching (90.6%)
- **Avg test duration:** 5.5s — slowest: `String-v8` (36.6s)

### from_gnash/misc-ming.all

- **Pass:** 63/102 (61.8%)
- **Duration:** 26m42s across 30 shards
- **Lines:** 2,859/4,577 matching (62.5%)
- **Avg test duration:** 15.7s — slowest: `NetStream-SquareTest` (30.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.4s — slowest: `function_test` (19.2s)

### from_gnash/misc-swfc.all

- **Pass:** 7/16 (43.8%)
- **Duration:** 4m15s across 30 shards
- **Lines:** 339/499 matching (67.9%)
- **Avg test duration:** 15.9s — slowest: `movieclip_destruction_test1` (19.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m17s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.6s — slowest: `dict_cross` (19.7s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 14m01s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 9.1s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (21.4s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m44s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.2s — slowest: `duplicateMovieClip/dontremove` (19.0s)
