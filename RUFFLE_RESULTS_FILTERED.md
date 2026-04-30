# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `63fcb28a8bc4`  
**Date:** 2026-04-30 04:26 UTC  
**Total duration:** 8m11s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 600 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 57 | 102 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **902** | **1072** | **84.1%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,915 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 14,803 | 16,957 | 87.3% |
| from_gnash/misc-ming.all | 2,776 | 4,577 | 60.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 281 | 499 | 56.3% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **114,177** | **119,164** | **95.8%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | - | 4 |
| from_gnash/actionscript.all | 18 | 59 |
| from_gnash/misc-ming.all | 32 | 13 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 8 | 3 |
| from_gnash/misc-swfmill.all | 2 | 1 |
| from_shumway | 26 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **86** | **84** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 88% |
| from_gnash/misc-ming.all | loading/LoadVarsTest | 86% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/600 (99.3%)
- **Ignored:** 41 tests
- **Duration:** 4m07s across 30 shards
- **Lines:** 94,915/95,093 matching (99.8%)
- **Avg test duration:** 0.3s — slowest: `target_clip_removed` (16.1s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 14,803/16,957 matching (87.3%)
- **Avg test duration:** 0.3s — slowest: `case-v7` (2.9s)

### from_gnash/misc-ming.all

- **Pass:** 57/102 (55.9%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 2,776/4,577 matching (60.7%)
- **Avg test duration:** 0.8s — slowest: `register_class/registerClassTest` (17.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.2s — slowest: `levels` (0.3s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 4s across 30 shards
- **Lines:** 281/499 matching (56.3%)
- **Avg test duration:** 0.2s — slowest: `movieclip_destruction_test1` (0.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 4s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 0.2s — slowest: `tags_after_last_showframe` (0.2s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 0.7s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (16.7s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 12s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.2s — slowest: `undefined/undefined-swf7` (0.8s)
