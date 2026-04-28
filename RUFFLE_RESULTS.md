# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `cdc61ecbd34e`  
**Date:** 2026-04-28 04:21 UTC  
**Total duration:** 11m04s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 641 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 52 | 102 | 51.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **898** | **1115** | **80.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,852 | 114,749 | 92.2% |
| from_gnash/actionscript.all | 14,758 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,678 | 4,541 | 59.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 281 | 499 | 56.3% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **124,974** | **138,795** | **90.0%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 35 |
| from_gnash/actionscript.all | - | 22 |
| from_gnash/misc-ming.all | 1 | 36 |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | - | 8 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 26 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **130** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | HitTest-v8 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v7 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 1 | - | 50 | - |
| from_gnash/misc-swfc.all | - | - | 19 | - |
| from_gnash/misc-swfmill.all | - | - | 1 | - |

**from_gnash/misc-ming.all — newly passing:** `register_class/RegisterClassTest3`

*Comparing `c958a5b628ef` → `cdc61ecbd34e`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/641 (93.1%)
- **Duration:** 5m50s across 30 shards
- **Lines:** 105,852/114,749 matching (92.2%)
- **Avg test duration:** 0.5s — slowest: `movieclip_invalid_get_bounds_6` (24.6s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 14,758/16,957 matching (87.0%)
- **Avg test duration:** 0.7s — slowest: `Point-v8` (7.2s)

### from_gnash/misc-ming.all

- **Pass:** 52/102 (51.0%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 2,678/4,541 matching (59.0%)
- **Avg test duration:** 0.6s — slowest: `init_action/InitActionTest2` (16.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 5s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.5s — slowest: `levels` (2.3s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 21s across 30 shards
- **Lines:** 281/499 matching (56.3%)
- **Avg test duration:** 1.2s — slowest: `swf4opcode` (15.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 19s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 1.0s — slowest: `trace-as2/super` (14.2s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 48s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 0.5s — slowest: `avm1timeline1` (14.2s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 15s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 0.3s — slowest: `propertycase/propertycase-preserving-6` (1.0s)
