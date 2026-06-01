# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `f9efc27405a3`  
**Date:** 2026-06-01 01:35 UTC  
**Total duration:** 2h15m46s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 616 | 673 | 91.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 132 | 243 | 54.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 66 | 110 | 60.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **967** | **1213** | **79.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,901 | 116,485 | 91.8% |
| from_gnash/actionscript.all | 29,839 | 38,791 | 76.9% |
| from_gnash/misc-ming.all | 4,019 | 5,239 | 76.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,858** | **163,165** | **87.6%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 46 |
| from_gnash/actionscript.all | 13 |
| from_gnash/misc-ming.all | 16 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **95** |

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
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 1 | - |
| from_gnash/actionscript.all | 1 | - | 8 | - |

*Comparing `0973204c3999` → `f9efc27405a3`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 616/673 (91.5%)
- **Duration:** 1h01m26s across 30 shards
- **Lines:** 106,901/116,485 matching (91.8%)
- **Avg test duration:** 5.4s — slowest: `loadmovie_flashvars` (22.4s)

### from_gnash/actionscript.all

- **Pass:** 132/243 (54.3%)
- **Duration:** 16m43s across 30 shards
- **Lines:** 29,839/38,791 matching (76.9%)
- **Avg test duration:** 4.1s — slowest: `delete-v5` (21.2s)

### from_gnash/misc-ming.all

- **Pass:** 66/110 (60.0%)
- **Duration:** 28m43s across 30 shards
- **Lines:** 4,019/5,239 matching (76.7%)
- **Avg test duration:** 15.6s — slowest: `matrix_test` (23.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m12s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.7s — slowest: `TextFieldTest` (20.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 4m46s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 15.0s — slowest: `registerclass_test3` (21.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m19s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.9s — slowest: `missing_bitmap` (20.2s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m01s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.1s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (21.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m32s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.9s — slowest: `duplicateMovieClip/dontremove` (19.7s)
