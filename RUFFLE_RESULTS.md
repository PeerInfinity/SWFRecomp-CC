# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `48a97e0b07bf`  
**Date:** 2026-05-01 20:42 UTC  
**Total duration:** 2h12m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 643 | 93.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 122 | 190 | 64.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 16 | 18 | 88.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **922** | **1117** | **82.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,887 | 114,774 | 92.3% |
| from_gnash/actionscript.all | 15,243 | 16,957 | 89.9% |
| from_gnash/misc-ming.all | 2,815 | 4,577 | 61.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,661** | **138,856** | **90.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 34 |
| from_gnash/actionscript.all | 5 |
| from_gnash/misc-ming.all | 27 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 7 |
| from_gnash/misc-swfmill.all | 1 |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **100** |

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
| avm1 | 1 | - | 2 | - |

**avm1 — newly passing:** `loadvars_tostring`

*Comparing `900ae800db6b` → `48a97e0b07bf`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 600/643 (93.3%)
- **Duration:** 1h00m38s across 30 shards
- **Lines:** 105,887/114,774 matching (92.3%)
- **Avg test duration:** 5.6s — slowest: `movieclip_invalid_get_bounds_7` (31.0s)

### from_gnash/actionscript.all

- **Pass:** 122/190 (64.2%)
- **Duration:** 18m45s across 30 shards
- **Lines:** 15,243/16,957 matching (89.9%)
- **Avg test duration:** 5.9s — slowest: `Math-v5` (31.8s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 26m03s across 30 shards
- **Lines:** 2,815/4,577 matching (61.5%)
- **Avg test duration:** 15.3s — slowest: `NetStream-SquareTest` (28.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.1s — slowest: `TextFieldTest` (18.8s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 4m14s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 15.8s — slowest: `swf4opcode` (20.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 16/18 (88.9%)
- **Duration:** 5m12s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 17.3s — slowest: `missing_bitmap` (18.7s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 13m12s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.6s — slowest: `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` (21.1s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 2m12s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.8s — slowest: `label` (18.2s)
