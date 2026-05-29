# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `55d725fb0c25`  
**Date:** 2026-05-29 22:31 UTC  
**Total duration:** 7m28s

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
| from_gnash/misc-ming.all | 4,022 | 5,239 | 76.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,861** | **163,165** | **87.6%** |

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

*No changes since last run.*

*Comparing `dfd7d618896d` → `55d725fb0c25`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 616/673 (91.5%)
- **Duration:** 4m04s across 30 shards
- **Lines:** 106,901/116,485 matching (91.8%)
- **Avg test duration:** 0.3s — slowest: `timeout` (5.2s)

### from_gnash/actionscript.all

- **Pass:** 132/243 (54.3%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 29,839/38,791 matching (76.9%)
- **Avg test duration:** 0.4s — slowest: `MovieClip-v8` (2.2s)

### from_gnash/misc-ming.all

- **Pass:** 66/110 (60.0%)
- **Duration:** 44s across 30 shards
- **Lines:** 4,022/5,239 matching (76.8%)
- **Avg test duration:** 0.3s — slowest: `matrix_test` (4.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.2s — slowest: `inheritance` (0.2s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 5s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 0.2s — slowest: `movieclip_destruction_test1` (0.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 0.2s — slowest: `tags_after_last_showframe` (0.2s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 28s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 0.2s — slowest: `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` (1.3s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 13s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 0.2s — slowest: `depth` (0.3s)
