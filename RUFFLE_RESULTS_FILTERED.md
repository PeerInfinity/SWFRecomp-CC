# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `edb600595ba5`  
**Date:** 2026-04-30 01:48 UTC  
**Total duration:** 1h50m39s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 600 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 55 | 102 | 53.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **900** | **1072** | **84.0%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,915 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 14,792 | 16,957 | 87.2% |
| from_gnash/misc-ming.all | 2,696 | 4,541 | 59.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 281 | 499 | 56.3% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **114,086** | **119,128** | **95.8%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched |
|-------|--------------:|-----------------:|----------------:|
| avm1 | - | - | 4 |
| from_gnash/actionscript.all | - | 18 | 59 |
| from_gnash/misc-ming.all | 1 | 33 | 13 |
| from_gnash/misc-mtasc.all | - | - | 2 |
| from_gnash/misc-swfc.all | - | 8 | 3 |
| from_gnash/misc-swfmill.all | - | 2 | 1 |
| from_shumway | - | 26 | 2 |
| from_shumway/avm1 | - | - | - |
| **Total** | **1** | **87** | **84** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/600 (99.3%)
- **Ignored:** 41 tests
- **Duration:** 51m57s across 30 shards
- **Lines:** 94,915/95,093 matching (99.8%)
- **Avg test duration:** 4.8s — slowest: `equals_swf5` (18.6s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 11m18s across 30 shards
- **Lines:** 14,792/16,957 matching (87.2%)
- **Avg test duration:** 3.5s — slowest: `MovieClipLoader-v6` (18.2s)

### from_gnash/misc-ming.all

- **Pass:** 55/102 (53.9%)
- **Duration:** 22m43s across 30 shards
- **Lines:** 2,696/4,541 matching (59.4%)
- **Avg test duration:** 13.3s — slowest: `matrix_test` (20.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.3s — slowest: `hello` (17.5s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 3m54s across 30 shards
- **Lines:** 281/499 matching (56.3%)
- **Avg test duration:** 14.6s — slowest: `stackscope` (18.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 4m58s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 16.5s — slowest: `trace-as2/root_onload` (18.0s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 12m26s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 8.1s — slowest: `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` (18.4s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m39s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.8s — slowest: `text-bind` (18.3s)
