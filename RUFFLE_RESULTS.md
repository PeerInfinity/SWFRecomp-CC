# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `49b5c83fbf03`  
**Date:** 2026-05-22 20:32 UTC  
**Total duration:** 2h09m23s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 661 | 91.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 128 | 243 | 52.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 65 | 110 | 59.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **950** | **1201** | **79.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,684 | 115,804 | 92.1% |
| from_gnash/actionscript.all | 29,292 | 38,787 | 75.5% |
| from_gnash/misc-ming.all | 4,004 | 5,239 | 76.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,079** | **162,480** | **87.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 46 |
| from_gnash/actionscript.all | 20 |
| from_gnash/misc-ming.all | 18 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **104** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | getvariable-v7 | 95% |
| from_gnash/actionscript.all | getvariable-v8 | 95% |
| from_gnash/actionscript.all | Function-v6 | 95% |
| from_gnash/actionscript.all | getvariable-v5 | 95% |
| from_gnash/actionscript.all | array-v6 | 94% |
| avm1 | sound_getters | 93% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | Function-v5 | 89% |
| from_gnash/actionscript.all | MovieClip-v6 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | MovieClip-v7 | 86% |
| from_gnash/actionscript.all | Function-v7 | 86% |
| from_gnash/actionscript.all | Function-v8 | 86% |
| from_gnash/actionscript.all | MovieClip-v8 | 85% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| from_gnash/actionscript.all | TextField-v6 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | - | 12 | - |

*Comparing `493a8d85d952` → `49b5c83fbf03`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/661 (91.4%)
- **Duration:** 58m01s across 30 shards
- **Lines:** 106,684/115,804 matching (92.1%)
- **Avg test duration:** 5.2s — slowest: `movieclip_hittest_shapeflag` (22.1s)

### from_gnash/actionscript.all

- **Pass:** 128/243 (52.7%)
- **Duration:** 16m11s across 30 shards
- **Lines:** 29,292/38,787 matching (75.5%)
- **Avg test duration:** 3.9s — slowest: `MovieClip-v5` (20.8s)

### from_gnash/misc-ming.all

- **Pass:** 65/110 (59.1%)
- **Duration:** 27m16s across 30 shards
- **Lines:** 4,004/5,239 matching (76.4%)
- **Avg test duration:** 14.8s — slowest: `matrix_test` (23.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m12s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.6s — slowest: `enum` (20.3s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 4m33s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 14.3s — slowest: `action_execution_order_test12` (20.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m05s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.2s — slowest: `background` (19.8s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m33s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.8s — slowest: `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` (20.4s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.8s — slowest: `duplicateMovieClip/dontremove` (20.0s)
