# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `59ad901e3299`  
**Date:** 2026-05-23 20:04 UTC  
**Total duration:** 2h08m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 606 | 620 | 97.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 128 | 240 | 53.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 65 | 108 | 60.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **950** | **1134** | **83.8%** | |

*67 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,233 | 96,675 | 99.5% |
| from_gnash/actionscript.all | 29,234 | 32,100 | 91.1% |
| from_gnash/misc-ming.all | 3,996 | 5,179 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **131,275** | **135,929** | **96.6%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 8 | 6 |
| from_gnash/actionscript.all | 13 | 99 |
| from_gnash/misc-ming.all | 16 | 27 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 7 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **39** | **145** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | getvariable-v7 | 95% |
| from_gnash/actionscript.all | getvariable-v8 | 95% |
| from_gnash/actionscript.all | getvariable-v5 | 95% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | MovieClip-v6 | 87% |
| from_gnash/actionscript.all | MovieClip-v7 | 86% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | MovieClip-v8 | 85% |
| from_gnash/actionscript.all | TextField-v6 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 606/620 (97.7%)
- **Ignored:** 41 tests
- **Duration:** 57m38s across 30 shards
- **Lines:** 96,233/96,675 matching (99.5%)
- **Avg test duration:** 5.2s — slowest: `object_string_coerce_swf5` (21.8s)

### from_gnash/actionscript.all

- **Pass:** 128/240 (53.3%)
- **Ignored:** 3 tests
- **Duration:** 16m02s across 30 shards
- **Lines:** 29,234/32,100 matching (91.1%)
- **Avg test duration:** 3.9s — slowest: `Try-v5` (20.8s)

### from_gnash/misc-ming.all

- **Pass:** 65/108 (60.2%)
- **Ignored:** 2 tests
- **Duration:** 27m05s across 30 shards
- **Lines:** 3,996/5,179 matching (77.2%)
- **Avg test duration:** 14.7s — slowest: `matrix_test` (27.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.1s — slowest: `TextFieldTest` (18.7s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 4m25s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 13.6s — slowest: `registerclass_test3` (19.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m58s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 17.9s — slowest: `tags_after_last_showframe` (20.1s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 13m32s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 6.8s — slowest: `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` (20.0s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m31s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.1s — slowest: `label` (18.8s)
