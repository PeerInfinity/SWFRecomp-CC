# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `5e68e309518f`  
**Date:** 2026-04-26 01:47 UTC  
**Total duration:** 8m57s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 600 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 44 | 102 | 43.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **888** | **1072** | **82.8%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,915 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 14,757 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,432 | 4,541 | 53.6% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 262 | 499 | 52.5% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **113,760** | **119,128** | **95.5%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched |
|-------|--------------:|-----------------:|----------------:|
| avm1 | - | - | 4 |
| from_gnash/actionscript.all | - | 22 | 55 |
| from_gnash/misc-ming.all | 1 | 45 | 12 |
| from_gnash/misc-mtasc.all | - | 1 | 1 |
| from_gnash/misc-swfc.all | - | 8 | 3 |
| from_gnash/misc-swfmill.all | - | 2 | 1 |
| from_shumway | - | 27 | 2 |
| from_shumway/avm1 | - | - | - |
| **Total** | **1** | **105** | **78** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-ming.all | loop/loop_test8 | 97% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 83% |
| from_gnash/actionscript.all | HitTest-v8 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v7 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/600 (99.3%)
- **Ignored:** 41 tests
- **Duration:** 5m02s across 30 shards
- **Lines:** 94,915/95,093 matching (99.8%)
- **Avg test duration:** 0.4s — slowest: `movieclip_begin_gradient_fill` (14.9s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 14,757/16,957 matching (87.0%)
- **Avg test duration:** 0.4s — slowest: `Sound-v5` (17.0s)

### from_gnash/misc-ming.all

- **Pass:** 44/102 (43.1%)
- **Duration:** 1m05s across 30 shards
- **Lines:** 2,432/4,541 matching (53.6%)
- **Avg test duration:** 0.6s — slowest: `loop/loop_test10` (14.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 0.2s — slowest: `levels` (0.2s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 4s across 30 shards
- **Lines:** 262/499 matching (52.5%)
- **Avg test duration:** 0.2s — slowest: `movieclip_destruction_test1` (0.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 0.2s — slowest: `zeroframe_definesprite` (1.0s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 1m03s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 0.6s — slowest: `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` (14.9s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 11s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.2s — slowest: `setinterval` (0.8s)
