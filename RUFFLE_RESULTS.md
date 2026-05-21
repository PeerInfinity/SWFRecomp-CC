# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `4cd8df042cbd`  
**Date:** 2026-05-21 00:20 UTC  
**Total duration:** 2h45m54s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 661 | 91.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 128 | 243 | 52.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 64 | 110 | 58.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **947** | **1201** | **78.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,631 | 115,804 | 92.1% |
| from_gnash/actionscript.all | 28,794 | 38,787 | 74.2% |
| from_gnash/misc-ming.all | 3,999 | 5,239 | 76.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **141,523** | **162,480** | **87.1%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 48 |
| from_gnash/actionscript.all | 28 |
| from_gnash/misc-ming.all | 20 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **116** |

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
| from_gnash/actionscript.all | Object-v7 | 90% |
| from_gnash/actionscript.all | Object-v8 | 90% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| avm1 | string_paths_other | 89% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test9 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Object-v6 | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| avm1 | sound_getters | 84% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | MovieClip-v8 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 2 | - | 10 |
| from_gnash/actionscript.all | 1 | - | 18 | - |
| from_gnash/misc-ming.all | - | 1 | - | 3 |

**avm1 — newly failing:** `global_swf6_7_8`, `string_paths_other`

**from_gnash/misc-ming.all — newly failing:** `displaylist_depths/displaylist_depths_test9`

*Comparing `4dc761afed4b` → `4cd8df042cbd`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 602/661 (91.1%)
- **Duration:** 1h08m33s across 30 shards
- **Lines:** 106,631/115,804 matching (92.1%)
- **Avg test duration:** 6.2s — slowest: `netstream_play_flv_screen` (35.1s)

### from_gnash/actionscript.all

- **Pass:** 128/243 (52.7%)
- **Duration:** 33m47s across 30 shards
- **Lines:** 28,794/38,787 matching (74.2%)
- **Avg test duration:** 8.3s — slowest: `MovieClip-v8` (55.1s)

### from_gnash/misc-ming.all

- **Pass:** 64/110 (58.2%)
- **Duration:** 32m56s across 30 shards
- **Lines:** 3,999/5,239 matching (76.3%)
- **Avg test duration:** 17.9s — slowest: `matrix_test` (81.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m22s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.8s — slowest: `enum` (22.7s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 5m07s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 16.1s — slowest: `movieclip_destruction_test1` (23.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m27s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.3s — slowest: `background` (22.2s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m40s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.5s — slowest: `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` (23.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m59s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.5s — slowest: `label` (21.7s)
