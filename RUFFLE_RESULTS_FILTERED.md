# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `802674fd5caa`  
**Date:** 2026-05-02 19:29 UTC  
**Total duration:** 1h53m16s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 567 | 607 | 93.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 121 | 190 | 63.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **889** | **1079** | **82.4%** | |

*42 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,260 | 95,859 | 98.3% |
| from_gnash/actionscript.all | 15,318 | 16,957 | 90.3% |
| from_gnash/misc-ming.all | 2,779 | 4,577 | 60.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 333 | 499 | 66.7% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **114,096** | **119,930** | **95.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 36 | 4 |
| from_gnash/actionscript.all | 8 | 61 |
| from_gnash/misc-ming.all | 25 | 16 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 6 | 4 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 25 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **100** | **90** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | edittext_stylesheet | 100% |
| avm1 | selection | 100% |
| avm1 | movieclip_get_instance_at_depth | 96% |
| from_gnash/actionscript.all | Global-v7 | 96% |
| from_gnash/actionscript.all | Global-v8 | 96% |
| from_gnash/actionscript.all | Global-v6 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | textfield_properties | 84% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 567/607 (93.4%)
- **Ignored:** 40 tests
- **Duration:** 53m20s across 30 shards
- **Lines:** 94,260/95,859 matching (98.3%)
- **Avg test duration:** 4.9s — slowest: `register_class_swf6` (20.1s)

### from_gnash/actionscript.all

- **Pass:** 121/190 (63.7%)
- **Duration:** 11m32s across 30 shards
- **Lines:** 15,318/16,957 matching (90.3%)
- **Avg test duration:** 3.6s — slowest: `Sound-v5` (18.4s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 23m16s across 30 shards
- **Lines:** 2,779/4,577 matching (60.7%)
- **Avg test duration:** 13.6s — slowest: `matrix_test` (21.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m01s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.4s — slowest: `function_test` (17.7s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 3m57s across 30 shards
- **Lines:** 333/499 matching (66.7%)
- **Avg test duration:** 14.8s — slowest: `movieclip_destruction_test4` (18.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m05s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 16.9s — slowest: `zeroframe_definesprite` (18.0s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 12m38s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.2s — slowest: `avm1/moviecliploader` (17.8s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m24s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.4s — slowest: `text-bind` (17.9s)
