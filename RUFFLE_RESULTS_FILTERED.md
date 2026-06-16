# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `886c8b0e4f7d`  
**Date:** 2026-06-16 19:35 UTC  
**Total duration:** 2h23m50s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 621 | 659 | 94.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 132 | 237 | 55.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 66 | 108 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 9 | 17 | 52.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **971** | **1170** | **83.0%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 104,047 | 111,794 | 93.1% |
| from_gnash/actionscript.all | 29,630 | 31,918 | 92.8% |
| from_gnash/misc-ming.all | 4,012 | 5,179 | 77.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 411 | 532 | 77.3% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **139,505** | **150,866** | **92.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | segfault |
|-------|-----------------:|----------------:|----------:|
| avm1 | 24 | 10 | 4 |
| from_gnash/actionscript.all | 10 | 95 | - |
| from_gnash/misc-ming.all | 14 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **51** | **144** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm1 | set_target_2_swf6 | 92% |
| avm1 | set_target_2_swf7 | 92% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 621/659 (94.2%)
- **Ignored:** 41 tests
- **Duration:** 59m48s across 30 shards
- **Lines:** 104,047/111,794 matching (93.1%)
- **Avg test duration:** 5.1s — slowest: `movieclip_invalid_get_bounds_6` (26.5s)

### from_gnash/actionscript.all

- **Pass:** 132/237 (55.7%)
- **Ignored:** 6 tests
- **Duration:** 26m49s across 30 shards
- **Lines:** 29,630/31,918 matching (92.8%)
- **Avg test duration:** 6.6s — slowest: `MovieClip-v8` (65.2s)

### from_gnash/misc-ming.all

- **Pass:** 66/108 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 29m15s across 30 shards
- **Lines:** 4,012/5,179 matching (77.5%)
- **Avg test duration:** 15.8s — slowest: `matrix_test` (108.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m35s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 17.3s — slowest: `implementsOpTest` (22.3s)

### from_gnash/misc-swfc.all

- **Pass:** 9/17 (52.9%)
- **Ignored:** 2 tests
- **Duration:** 4m26s across 30 shards
- **Lines:** 411/532 matching (77.3%)
- **Avg test duration:** 13.1s — slowest: `movieclip_destruction_test1` (22.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 3m14s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 9.7s — slowest: `registers` (21.1s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m50s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.1s — slowest: `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` (21.5s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m50s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.4s — slowest: `label` (23.0s)
