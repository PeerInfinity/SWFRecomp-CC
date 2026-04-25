# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `017e71a9c308`  
**Date:** 2026-04-25 20:11 UTC  
**Total duration:** 2h19m15s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 641 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 43 | 102 | 42.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **888** | **1115** | **79.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,735 | 114,749 | 92.1% |
| from_gnash/actionscript.all | 14,754 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,332 | 4,541 | 51.4% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 250 | 499 | 50.1% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **124,468** | **138,795** | **89.7%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 35 |
| from_gnash/actionscript.all | - | 22 |
| from_gnash/misc-ming.all | 1 | 47 |
| from_gnash/misc-mtasc.all | - | 1 |
| from_gnash/misc-swfc.all | - | 8 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 27 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **143** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/misc-ming.all | loop/loop_test8 | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 91% |
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
| from_gnash/misc-ming.all | 2 | - | 23 | 15 |

**from_gnash/misc-ming.all — newly passing:** `action_order/action_execution_order_test3`

*Comparing `8365e99266c8` → `017e71a9c308`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/641 (93.1%)
- **Duration:** 1h02m46s across 30 shards
- **Lines:** 105,735/114,749 matching (92.1%)
- **Avg test duration:** 5.8s — slowest: `netstream_play_flv_screen` (32.6s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 21m13s across 30 shards
- **Lines:** 14,754/16,957 matching (87.0%)
- **Avg test duration:** 6.6s — slowest: `String-v8` (31.9s)

### from_gnash/misc-ming.all

- **Pass:** 43/102 (42.2%)
- **Duration:** 27m58s across 30 shards
- **Lines:** 2,332/4,541 matching (51.4%)
- **Avg test duration:** 16.4s — slowest: `matrix_test` (98.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 12.8s — slowest: `implementsOpTest` (18.8s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 4m15s across 30 shards
- **Lines:** 250/499 matching (50.1%)
- **Avg test duration:** 15.9s — slowest: `movieclip_destruction_test1` (19.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m09s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 17.1s — slowest: `background` (18.0s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 13m49s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 9.0s — slowest: `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` (20.3s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 2m07s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.6s — slowest: `text-bind` (18.6s)
