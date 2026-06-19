# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `db12e096cbeb`  
**Date:** 2026-06-19 04:17 UTC  
**Total duration:** 2h57m58s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 623 | 660 | 94.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 132 | 237 | 55.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 67 | 109 | 61.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 10 | 18 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **975** | **1173** | **83.1%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 104,165 | 111,805 | 93.2% |
| from_gnash/actionscript.all | 29,748 | 31,918 | 93.2% |
| from_gnash/misc-ming.all | 4,021 | 5,188 | 77.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **139,760** | **150,909** | **92.6%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | segfault |
|-------|-----------------:|----------------:|----------:|
| avm1 | 23 | 10 | 4 |
| from_gnash/actionscript.all | 10 | 95 | - |
| from_gnash/misc-ming.all | 14 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 6 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **49** | **145** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 99% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 95% |
| from_gnash/actionscript.all | MovieClip-v6 | 95% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 85% |
| from_gnash/actionscript.all | TextField-v8 | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 623/660 (94.4%)
- **Ignored:** 41 tests
- **Duration:** 1h15m06s across 30 shards
- **Lines:** 104,165/111,805 matching (93.2%)
- **Avg test duration:** 6.4s — slowest: `movieclip_invalid_get_bounds_7` (25.8s)

### from_gnash/actionscript.all

- **Pass:** 132/237 (55.7%)
- **Ignored:** 6 tests
- **Duration:** 35m36s across 30 shards
- **Lines:** 29,748/31,918 matching (93.2%)
- **Avg test duration:** 8.8s — slowest: `MovieClip-v8` (69.7s)

### from_gnash/misc-ming.all

- **Pass:** 67/109 (61.5%)
- **Ignored:** 2 tests
- **Duration:** 34m46s across 30 shards
- **Lines:** 4,021/5,188 matching (77.5%)
- **Avg test duration:** 18.7s — slowest: `matrix_test` (109.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.0s — slowest: `super_test1` (22.1s)

### from_gnash/misc-swfc.all

- **Pass:** 10/18 (55.6%)
- **Ignored:** 2 tests
- **Duration:** 5m53s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 18.6s — slowest: `movieclip_destruction_test3` (22.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m29s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.4s — slowest: `registers` (21.3s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m58s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.4s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (21.5s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m42s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.2s — slowest: `label` (21.3s)
