# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8e02f3d3f007`  
**Date:** 2026-04-26 02:17 UTC  
**Total duration:** 26m17s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 641 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 44 | 102 | 43.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **889** | **1115** | **79.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,851 | 114,749 | 92.2% |
| from_gnash/actionscript.all | 14,757 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,428 | 4,541 | 53.5% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 262 | 499 | 52.5% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **124,695** | **138,795** | **89.8%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 35 |
| from_gnash/actionscript.all | - | 22 |
| from_gnash/misc-ming.all | 1 | 45 |
| from_gnash/misc-mtasc.all | - | 1 |
| from_gnash/misc-swfc.all | - | 8 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 27 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **141** |

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
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | HitTest-v8 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v7 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 1 | 1 | 1 | 5 |

**from_gnash/misc-ming.all — newly passing:** `loop/loop_test8`

**from_gnash/misc-ming.all — newly failing:** `reverse_execute_PlaceObject2_test2`

*Comparing `5e68e309518f` → `8e02f3d3f007`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/641 (93.1%)
- **Duration:** 11m22s across 30 shards
- **Lines:** 105,851/114,749 matching (92.2%)
- **Avg test duration:** 1.0s — slowest: `netstream_play_flv_screen` (34.9s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 3m24s across 30 shards
- **Lines:** 14,757/16,957 matching (87.0%)
- **Avg test duration:** 1.0s — slowest: `String-v8` (16.4s)

### from_gnash/misc-ming.all

- **Pass:** 44/102 (43.1%)
- **Duration:** 4m23s across 30 shards
- **Lines:** 2,428/4,541 matching (53.5%)
- **Avg test duration:** 2.5s — slowest: `action_order/ActionOrderTest4` (20.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 7s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 0.7s — slowest: `implementsOpTest` (2.1s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 43s across 30 shards
- **Lines:** 262/499 matching (52.5%)
- **Avg test duration:** 2.6s — slowest: `movieclip_destruction_test4` (19.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 56s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 3.0s — slowest: `dict_override` (17.8s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 4m45s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 3.0s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (19.4s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 35s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 0.7s — slowest: `label` (17.9s)
