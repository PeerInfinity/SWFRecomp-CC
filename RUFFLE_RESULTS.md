# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `ee3b89e5260e`  
**Date:** 2026-05-24 02:45 UTC  
**Total duration:** 2h13m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 611 | 662 | 92.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 128 | 243 | 52.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 67 | 110 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **959** | **1202** | **79.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,724 | 115,820 | 92.1% |
| from_gnash/actionscript.all | 29,518 | 38,787 | 76.1% |
| from_gnash/misc-ming.all | 4,026 | 5,239 | 76.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,367** | **162,496** | **87.6%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 40 |
| from_gnash/actionscript.all | 16 |
| from_gnash/misc-ming.all | 16 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **92** |

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
| from_gnash/actionscript.all | getvariable-v5 | 95% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 90% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | MovieClip-v7 | 89% |
| from_gnash/actionscript.all | MovieClip-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v6 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | - | 12 | - |

*Comparing `637d28c03165` → `ee3b89e5260e`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 611/662 (92.3%)
- **Duration:** 59m19s across 30 shards
- **Lines:** 106,724/115,820 matching (92.1%)
- **Avg test duration:** 5.3s — slowest: `movieclip_hittest_shapeflag` (22.2s)

### from_gnash/actionscript.all

- **Pass:** 128/243 (52.7%)
- **Duration:** 17m17s across 30 shards
- **Lines:** 29,518/38,787 matching (76.1%)
- **Avg test duration:** 4.2s — slowest: `Global-v6` (24.4s)

### from_gnash/misc-ming.all

- **Pass:** 67/110 (60.9%)
- **Duration:** 28m05s across 30 shards
- **Lines:** 4,026/5,239 matching (76.8%)
- **Avg test duration:** 15.3s — slowest: `matrix_test` (27.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m11s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.5s — slowest: `TextFieldTest` (19.5s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 4m38s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 14.6s — slowest: `soft_reference_test1` (20.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m10s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.5s — slowest: `dict_override` (20.3s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m06s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.1s — slowest: `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` (20.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m31s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.9s — slowest: `text-bind` (19.1s)
