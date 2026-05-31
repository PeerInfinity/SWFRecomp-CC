# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `d5b8dce255c7`  
**Date:** 2026-05-31 17:58 UTC  
**Total duration:** 2h48m46s

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

*No changes since last run.*

*Comparing `24cbf0ff5bc6` → `d5b8dce255c7`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 616/673 (91.5%)
- **Duration:** 1h09m34s across 30 shards
- **Lines:** 106,901/116,485 matching (91.8%)
- **Avg test duration:** 6.1s — slowest: `netstream_play_flv_screen` (35.5s)

### from_gnash/actionscript.all

- **Pass:** 132/243 (54.3%)
- **Duration:** 34m33s across 30 shards
- **Lines:** 29,839/38,791 matching (76.9%)
- **Avg test duration:** 8.5s — slowest: `MovieClip-v8` (66.5s)

### from_gnash/misc-ming.all

- **Pass:** 66/110 (60.0%)
- **Duration:** 33m51s across 30 shards
- **Lines:** 4,019/5,239 matching (76.7%)
- **Avg test duration:** 18.4s — slowest: `matrix_test` (108.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m25s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.1s — slowest: `enum` (20.9s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 5m09s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 16.2s — slowest: `action_execution_order_test12` (21.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m24s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.2s — slowest: `registers` (21.0s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m52s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.6s — slowest: `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` (23.8s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.4s — slowest: `text-bind` (22.0s)
