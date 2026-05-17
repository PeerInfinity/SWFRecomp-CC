# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `568b76d17ca0`  
**Date:** 2026-05-17 17:57 UTC  
**Total duration:** 2h06m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 614 | 98.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 128 | 243 | 52.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 64 | 108 | 59.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 18 | 44.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **946** | **1133** | **83.5%** | |

*62 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,052 | 96,458 | 99.6% |
| from_gnash/actionscript.all | 27,767 | 38,787 | 71.6% |
| from_gnash/misc-ming.all | 3,962 | 5,179 | 76.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 405 | 550 | 73.6% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **129,591** | **142,417** | **91.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 6 | 6 |
| from_gnash/actionscript.all | 40 | 75 |
| from_gnash/misc-ming.all | 20 | 24 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 4 | 6 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **70** | **117** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | getvariable-v7 | 92% |
| from_gnash/actionscript.all | getvariable-v8 | 92% |
| from_gnash/actionscript.all | getvariable-v6 | 91% |
| from_gnash/actionscript.all | Object-v7 | 90% |
| from_gnash/actionscript.all | Object-v8 | 90% |
| from_gnash/actionscript.all | getvariable-v5 | 90% |
| from_gnash/actionscript.all | array-v7 | 89% |
| from_gnash/actionscript.all | array-v8 | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Object-v6 | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| from_gnash/actionscript.all | Transform-v8 | 85% |
| from_gnash/actionscript.all | XMLNode-v5 | 84% |
| from_gnash/actionscript.all | XMLNode-v6 | 84% |
| from_gnash/actionscript.all | XMLNode-v7 | 84% |
| from_gnash/actionscript.all | XMLNode-v8 | 84% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 82% |
| from_gnash/actionscript.all | MovieClip-v8 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 602/614 (98.0%)
- **Ignored:** 41 tests
- **Duration:** 56m14s across 30 shards
- **Lines:** 96,052/96,458 matching (99.6%)
- **Avg test duration:** 5.1s — slowest: `timeout` (23.7s)

### from_gnash/actionscript.all

- **Pass:** 128/243 (52.7%)
- **Duration:** 15m45s across 30 shards
- **Lines:** 27,767/38,787 matching (71.6%)
- **Avg test duration:** 3.8s — slowest: `array-v6` (20.1s)

### from_gnash/misc-ming.all

- **Pass:** 64/108 (59.3%)
- **Ignored:** 2 tests
- **Duration:** 26m37s across 30 shards
- **Lines:** 3,962/5,179 matching (76.5%)
- **Avg test duration:** 14.4s — slowest: `matrix_test` (23.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m04s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.8s — slowest: `exception` (18.2s)

### from_gnash/misc-swfc.all

- **Pass:** 8/18 (44.4%)
- **Ignored:** 1 tests
- **Duration:** 4m24s across 30 shards
- **Lines:** 405/550 matching (73.6%)
- **Avg test duration:** 13.6s — slowest: `movieclip_destruction_test3` (19.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m51s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 17.5s — slowest: `missing_bitmap` (19.8s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 13m33s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 6.9s — slowest: `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` (19.2s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m47s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.9s — slowest: `text-bind` (19.6s)
