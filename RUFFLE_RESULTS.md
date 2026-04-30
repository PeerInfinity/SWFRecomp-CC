# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `c42eb4d68255`  
**Date:** 2026-04-30 18:25 UTC  
**Total duration:** 1h52m48s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 598 | 642 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 116 | 190 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 57 | 102 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **907** | **1116** | **81.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,873 | 114,769 | 92.2% |
| from_gnash/actionscript.all | 15,019 | 16,957 | 88.6% |
| from_gnash/misc-ming.all | 2,776 | 4,577 | 60.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 302 | 499 | 60.5% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,375** | **138,851** | **90.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 35 |
| from_gnash/actionscript.all | 14 |
| from_gnash/misc-ming.all | 32 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 8 |
| from_gnash/misc-swfmill.all | 2 |
| from_shumway | 26 |
| from_shumway/avm1 | 1 |
| **Total** | **118** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/misc-ming.all | loading/LoadVarsTest | 86% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 1 | - | 12 | - |
| from_gnash/misc-swfc.all | - | - | - | 2 |

*Comparing `6476ad2f24bf` → `c42eb4d68255`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 598/642 (93.1%)
- **Duration:** 53m16s across 30 shards
- **Lines:** 105,873/114,769 matching (92.2%)
- **Avg test duration:** 4.9s — slowest: `bitmap_data_perlinnoise` (19.1s)

### from_gnash/actionscript.all

- **Pass:** 116/190 (61.1%)
- **Duration:** 11m27s across 30 shards
- **Lines:** 15,019/16,957 matching (88.6%)
- **Avg test duration:** 3.6s — slowest: `String-v8` (18.0s)

### from_gnash/misc-ming.all

- **Pass:** 57/102 (55.9%)
- **Duration:** 23m04s across 30 shards
- **Lines:** 2,776/4,577 matching (60.7%)
- **Avg test duration:** 13.5s — slowest: `matrix_test` (19.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.3s — slowest: `exception` (17.4s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 3m53s across 30 shards
- **Lines:** 302/499 matching (60.5%)
- **Avg test duration:** 14.6s — slowest: `gotoFrameLabelAsFunction` (17.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m03s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 16.8s — slowest: `jump_to_prev_block` (17.6s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 12m25s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 8.0s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (18.8s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m56s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.4s — slowest: `label` (17.6s)
