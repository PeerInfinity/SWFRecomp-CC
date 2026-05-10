# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b3f2cb8e1970`  
**Date:** 2026-05-10 20:17 UTC  
**Total duration:** 59m16s

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

*Comparing `784bb3ae7abd` → `b3f2cb8e1970`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 605/651 (92.9%)
- **Duration:** 22m23s across 30 shards
- **Lines:** 106,105/114,995 matching (92.3%)
- **Avg test duration:** 2.0s — slowest: `netstream_play_flv_screen` (34.0s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 6m30s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 2.0s — slowest: `array-v5` (29.1s)

### from_gnash/misc-ming.all

- **Pass:** 66/102 (64.7%)
- **Duration:** 15m18s across 30 shards
- **Lines:** 3,774/4,577 matching (82.5%)
- **Avg test duration:** 8.9s — slowest: `NetStream-SquareTest` (30.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m22s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 9.1s — slowest: `enum` (20.2s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 388/499 matching (77.8%)
- **Avg test duration:** 6.6s — slowest: `gotoFrameLabelAsFunction` (20.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 2m28s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 8.2s — slowest: `background` (19.9s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 8m18s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 5.4s — slowest: `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` (20.4s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.4s — slowest: `label` (18.4s)
