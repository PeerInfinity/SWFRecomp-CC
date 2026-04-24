# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9d48962d4ca3`  
**Date:** 2026-04-24 20:40 UTC  
**Total duration:** 2h07m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 641 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 40 | 102 | 39.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **885** | **1115** | **79.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,735 | 114,749 | 92.1% |
| from_gnash/actionscript.all | 14,751 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,309 | 4,541 | 50.8% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 250 | 499 | 50.1% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **124,442** | **138,795** | **89.7%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 35 |
| from_gnash/actionscript.all | - | 25 |
| from_gnash/misc-ming.all | 1 | 51 |
| from_gnash/misc-mtasc.all | - | 1 |
| from_gnash/misc-swfc.all | - | 8 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 27 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **150** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/actionscript.all | Selection-v6 | 94% |
| from_gnash/actionscript.all | Selection-v7 | 94% |
| from_gnash/actionscript.all | Selection-v8 | 94% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/misc-ming.all | loop/loop_test8 | 89% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-swfc.all | - | - | 11 | - |

*Comparing `d4ea78fc54b8` → `9d48962d4ca3`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/641 (93.1%)
- **Duration:** 59m18s across 30 shards
- **Lines:** 105,735/114,749 matching (92.1%)
- **Avg test duration:** 5.5s — slowest: `netstream_play_flv_screen` (33.1s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 17m03s across 30 shards
- **Lines:** 14,751/16,957 matching (87.0%)
- **Avg test duration:** 5.3s — slowest: `String-v8` (31.6s)

### from_gnash/misc-ming.all

- **Pass:** 40/102 (39.2%)
- **Duration:** 24m48s across 30 shards
- **Lines:** 2,309/4,541 matching (50.8%)
- **Avg test duration:** 14.5s — slowest: `NetStream-SquareTest` (29.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 12.1s — slowest: `function_test` (18.6s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 4m08s across 30 shards
- **Lines:** 250/499 matching (50.1%)
- **Avg test duration:** 15.5s — slowest: `movieclip_destruction_test4` (18.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m09s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 17.2s — slowest: `tags_after_last_showframe` (18.7s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 12m56s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 8.4s — slowest: `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` (19.2s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.5s — slowest: `label` (18.3s)
