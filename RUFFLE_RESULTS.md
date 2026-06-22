# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `96e9660aefe6`  
**Date:** 2026-06-22 17:56 UTC  
**Total duration:** 2h11m07s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 629 | 703 | 89.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 68 | 111 | 61.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 10 | 20 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **987** | **1245** | **79.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,520 | 130,961 | 88.2% |
| from_gnash/actionscript.all | 30,101 | 38,791 | 77.6% |
| from_gnash/misc-ming.all | 4,042 | 5,248 | 77.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **151,776** | **177,673** | **85.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 57 |
| from_gnash/actionscript.all | 13 |
| from_gnash/misc-ming.all | 15 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **105** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 95% |
| from_gnash/actionscript.all | MovieClip-v6 | 95% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 85% |
| avm1 | bitmapdata_hittest_threshold | 83% |
| from_gnash/actionscript.all | TextField-v8 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | 13 | - |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 629/703 (89.5%)
- **Duration:** 46m07s across 30 shards
- **Lines:** 115,520/130,961 matching (88.2%)
- **Avg test duration:** 3.9s — slowest: `netstream_play_flv_screen` (36.6s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 27m00s across 30 shards
- **Lines:** 30,101/38,791 matching (77.6%)
- **Avg test duration:** 6.6s — slowest: `MovieClip-v8` (63.0s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 28m36s across 30 shards
- **Lines:** 4,042/5,248 matching (77.0%)
- **Avg test duration:** 15.4s — slowest: `matrix_test` (102.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `enum` (21.8s)

### from_gnash/misc-swfc.all

- **Pass:** 10/20 (50.0%)
- **Duration:** 4m49s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 14.4s — slowest: `movieclip_destruction_test1` (22.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m48s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.4s — slowest: `missing_bitmap` (23.2s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m34s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.8s — slowest: `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` (23.2s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m57s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.4s — slowest: `label` (21.6s)
