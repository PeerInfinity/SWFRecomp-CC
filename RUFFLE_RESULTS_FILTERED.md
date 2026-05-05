# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `ae24a9feba19`  
**Date:** 2026-05-05 20:15 UTC  
**Total duration:** 2h09m43s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 603 | 607 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 64 | 102 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 68 | 92 | 73.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **938** | **1078** | **87.0%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,681 | 95,859 | 99.8% |
| from_gnash/actionscript.all | 15,370 | 16,957 | 90.6% |
| from_gnash/misc-ming.all | 2,919 | 4,577 | 63.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 364 | 492 | 74.0% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 687 | 1,276 | 53.8% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,761** | **119,923** | **96.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | - | 4 |
| from_gnash/actionscript.all | 2 | 62 |
| from_gnash/misc-ming.all | 20 | 18 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 21 | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **45** | **95** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | matrix_test | 87% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 603/607 (99.3%)
- **Ignored:** 40 tests
- **Duration:** 59m21s across 30 shards
- **Lines:** 95,681/95,859 matching (99.8%)
- **Avg test duration:** 5.4s — slowest: `loadvariables2` (21.0s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 16m59s across 30 shards
- **Lines:** 15,370/16,957 matching (90.6%)
- **Avg test duration:** 5.3s — slowest: `array-v5` (27.4s)

### from_gnash/misc-ming.all

- **Pass:** 64/102 (62.7%)
- **Duration:** 26m06s across 30 shards
- **Lines:** 2,919/4,577 matching (63.8%)
- **Avg test duration:** 15.3s — slowest: `DefineEditTextTest` (28.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m11s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.5s — slowest: `hello` (19.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 4m19s across 30 shards
- **Lines:** 364/492 matching (74.0%)
- **Avg test duration:** 16.1s — slowest: `swf4opcode` (22.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m18s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.6s — slowest: `trace-as2/super` (20.2s)

### from_shumway

- **Pass:** 68/92 (73.9%)
- **Duration:** 13m47s across 30 shards
- **Lines:** 687/1,276 matching (53.8%)
- **Avg test duration:** 8.9s — slowest: `avm1timeline1` (20.6s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m40s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.8s — slowest: `duplicateMovieClip/dontremove` (18.0s)
