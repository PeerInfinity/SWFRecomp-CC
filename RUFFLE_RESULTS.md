# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `900ae800db6b`  
**Date:** 2026-05-01 20:01 UTC  
**Total duration:** 1h54m27s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 599 | 643 | 93.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 122 | 190 | 64.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 16 | 18 | 88.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **921** | **1117** | **82.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,885 | 114,774 | 92.3% |
| from_gnash/actionscript.all | 15,243 | 16,957 | 89.9% |
| from_gnash/misc-ming.all | 2,815 | 4,577 | 61.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,659** | **138,856** | **90.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 35 |
| from_gnash/actionscript.all | 5 |
| from_gnash/misc-ming.all | 27 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 7 |
| from_gnash/misc-swfmill.all | 1 |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **101** |

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
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 9 | - |

**avm1 — newly passing:** `bitmap_filters`

*Comparing `9020f6640965` → `900ae800db6b`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 599/643 (93.2%)
- **Duration:** 53m54s across 30 shards
- **Lines:** 105,885/114,774 matching (92.3%)
- **Avg test duration:** 5.0s — slowest: `has_own_property` (19.7s)

### from_gnash/actionscript.all

- **Pass:** 122/190 (64.2%)
- **Duration:** 11m37s across 30 shards
- **Lines:** 15,243/16,957 matching (89.9%)
- **Avg test duration:** 3.6s — slowest: `LocalConnection-v5` (18.0s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 23m32s across 30 shards
- **Lines:** 2,815/4,577 matching (61.5%)
- **Avg test duration:** 13.8s — slowest: `matrix_test` (20.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.5s — slowest: `TextFieldTest` (17.6s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 4m02s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 15.1s — slowest: `movieclip_destruction_test1` (17.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 16/18 (88.9%)
- **Duration:** 5m10s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 17.2s — slowest: `initaction_in_definesprite` (17.9s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 12m31s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.1s — slowest: `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` (18.5s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.4s — slowest: `duplicateMovieClip/dontremove` (17.4s)
