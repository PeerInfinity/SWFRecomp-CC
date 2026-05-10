# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `784bb3ae7abd`  
**Date:** 2026-05-10 19:12 UTC  
**Total duration:** 2h20m39s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 605 | 651 | 92.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 66 | 102 | 64.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **948** | **1125** | **84.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,105 | 114,995 | 92.3% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,774 | 4,577 | 82.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 388 | 499 | 77.8% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **127,291** | **139,077** | **91.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 35 |
| from_gnash/actionscript.all | 1 |
| from_gnash/misc-ming.all | 12 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **66** |

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

*No changes since last run.*

*Comparing `b1237cc26e00` → `784bb3ae7abd`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 605/651 (92.9%)
- **Duration:** 1h04m09s across 30 shards
- **Lines:** 106,105/114,995 matching (92.3%)
- **Avg test duration:** 5.9s — slowest: `netstream_play_flv_screen` (34.2s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 20m36s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 6.4s — slowest: `String-v8` (33.1s)

### from_gnash/misc-ming.all

- **Pass:** 66/102 (64.7%)
- **Duration:** 27m24s across 30 shards
- **Lines:** 3,774/4,577 matching (82.5%)
- **Avg test duration:** 16.1s — slowest: `NetStream-SquareTest` (29.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `implementsOpTest` (20.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4m26s across 30 shards
- **Lines:** 388/499 matching (77.8%)
- **Avg test duration:** 16.6s — slowest: `soft_reference_test1` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m23s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.9s — slowest: `mixed-bytecode-as2` (20.9s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m33s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.4s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (20.4s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.3s — slowest: `hitarea` (18.4s)
