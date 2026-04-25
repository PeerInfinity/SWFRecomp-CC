# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `3a9cd203baf6`  
**Date:** 2026-04-25 01:45 UTC  
**Total duration:** 1h48m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 641 | 93.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 41 | 102 | 40.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
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
| from_gnash/actionscript.all | 14,754 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,320 | 4,541 | 51.1% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 250 | 499 | 50.1% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **124,456** | **138,795** | **89.7%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 37 |
| from_gnash/actionscript.all | - | 22 |
| from_gnash/misc-ming.all | 1 | 50 |
| from_gnash/misc-mtasc.all | - | 1 |
| from_gnash/misc-swfc.all | - | 8 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 27 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **148** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | form_loader_encoding_1 | 100% |
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
| avm1 | - | 2 | - | - |
| from_gnash/misc-ming.all | 1 | - | 8 | - |

**avm1 — newly failing:** `form_loader_encoding_1`

**from_gnash/misc-ming.all — newly passing:** `event_handler_scope_test`

*Comparing `67c780cca1f6` → `3a9cd203baf6`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/641 (93.0%)
- **Duration:** 50m42s across 30 shards
- **Lines:** 105,735/114,749 matching (92.1%)
- **Avg test duration:** 4.7s — slowest: `file_reference_upload_httperror_dns_error` (18.7s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 11m02s across 30 shards
- **Lines:** 14,754/16,957 matching (87.0%)
- **Avg test duration:** 3.4s — slowest: `Math-v5` (18.4s)

### from_gnash/misc-ming.all

- **Pass:** 41/102 (40.2%)
- **Duration:** 22m15s across 30 shards
- **Lines:** 2,320/4,541 matching (51.1%)
- **Avg test duration:** 13.0s — slowest: `matrix_test` (18.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m40s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 11.1s — slowest: `TextFieldTest` (17.2s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 3m50s across 30 shards
- **Lines:** 250/499 matching (50.1%)
- **Avg test duration:** 14.3s — slowest: `registerclass_test3` (17.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 4m51s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 16.1s — slowest: `missing_bitmap` (17.3s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 12m11s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 7.9s — slowest: `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` (18.1s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m35s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.0s — slowest: `label` (17.2s)
