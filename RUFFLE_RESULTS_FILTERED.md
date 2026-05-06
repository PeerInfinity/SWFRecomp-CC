# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `94cda9947684`  
**Date:** 2026-05-06 03:29 UTC  
**Total duration:** 57m58s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 603 | 608 | 99.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 64 | 102 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 15 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 68 | 92 | 73.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **938** | **1079** | **86.9%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,695 | 95,875 | 99.8% |
| from_gnash/actionscript.all | 15,370 | 16,957 | 90.6% |
| from_gnash/misc-ming.all | 3,090 | 4,577 | 67.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 364 | 492 | 74.0% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 687 | 1,276 | 53.8% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **115,946** | **119,939** | **96.7%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 1 | 4 |
| from_gnash/actionscript.all | 2 | 62 |
| from_gnash/misc-ming.all | 20 | 18 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 21 | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **46** | **95** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 92% |
| avm1 | try_catch_stack | 88% |
| from_gnash/misc-ming.all | matrix_test | 87% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 603/608 (99.2%)
- **Ignored:** 40 tests
- **Duration:** 19m14s across 30 shards
- **Lines:** 95,695/95,875 matching (99.8%)
- **Avg test duration:** 1.7s — slowest: `string_methods_negative_args` (19.6s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 7m46s across 30 shards
- **Lines:** 15,370/16,957 matching (90.6%)
- **Avg test duration:** 2.4s — slowest: `array-v5` (26.8s)

### from_gnash/misc-ming.all

- **Pass:** 64/102 (62.7%)
- **Duration:** 17m43s across 30 shards
- **Lines:** 3,090/4,577 matching (67.5%)
- **Avg test duration:** 10.4s — slowest: `NetStream-SquareTest` (29.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 27s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 3.0s — slowest: `TextFieldTest` (18.7s)

### from_gnash/misc-swfc.all

- **Pass:** 8/15 (53.3%)
- **Ignored:** 1 tests
- **Duration:** 1m43s across 30 shards
- **Lines:** 364/492 matching (74.0%)
- **Avg test duration:** 6.8s — slowest: `opcode_guard_test2` (20.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 2m47s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 9.3s — slowest: `initaction_in_definesprite` (19.5s)

### from_shumway

- **Pass:** 68/92 (73.9%)
- **Duration:** 7m24s across 30 shards
- **Lines:** 687/1,276 matching (53.8%)
- **Avg test duration:** 4.8s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (20.0s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 52s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.7s — slowest: `undefined/undefined-swf7` (1.7s)
