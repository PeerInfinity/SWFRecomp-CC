# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `cbb390273734`  
**Date:** 2026-07-11 06:50 UTC  
**Total duration:** 3h48m50s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 631 | 661 | 95.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 8 | 973 | 0.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 68 | 109 | 62.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| regression | 38 | 38 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| **Total** | **1031** | **2184** | **47.2%** | |

*300 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 104,035 | 107,545 | 96.7% |
| avm2 | 272 | 125,429 | 0.2% |
| from_gnash/actionscript.all | 29,253 | 31,358 | 93.3% |
| from_gnash/misc-ming.all | 4,029 | 5,188 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| regression | 252 | 252 | 100% |
| **Total** | **139,670** | **271,770** | **51.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| avm1 | 18 | 12 | - |
| avm2 | 23 | - | 942 |
| from_gnash/actionscript.all | 9 | 95 | - |
| from_gnash/misc-ming.all | 13 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| regression | - | - | - |
| **Total** | **65** | **146** | **942** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 631/661 (95.5%)
- **Ignored:** 45 tests
- **Duration:** 1h01m17s across 30 shards
- **Lines:** 104,035/107,545 matching (96.7%)
- **Avg test duration:** 5.2s — slowest: `movieclip_invalid_get_bounds_6` (25.8s)

### avm2

- **Pass:** 8/973 (0.8%)
- **Ignored:** 225 tests
- **Duration:** 1h15m05s across 30 shards
- **Lines:** 272/125,429 matching (0.2%)
- **Avg test duration:** 3.1s — slowest: `issue_13780` (21.4s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 27m51s across 30 shards
- **Lines:** 29,253/31,358 matching (93.3%)
- **Avg test duration:** 6.8s — slowest: `MovieClip-v8` (52.7s)

### from_gnash/misc-ming.all

- **Pass:** 68/109 (62.4%)
- **Ignored:** 2 tests
- **Duration:** 30m36s across 30 shards
- **Lines:** 4,029/5,188 matching (77.7%)
- **Avg test duration:** 16.4s — slowest: `matrix_test` (105.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m02s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.6s — slowest: `implementsOpTest` (21.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m09s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 16.0s — slowest: `soft_reference_test1` (22.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m24s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 13.2s — slowest: `trace-as2/root_onload` (21.1s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m03s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 6.8s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (21.6s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m44s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.8s — slowest: `label` (19.9s)

### regression

- **Pass:** 38/38 (100%)
- **Duration:** 6m34s across 30 shards
- **Lines:** 252/252 matching (100%)
- **Avg test duration:** 10.3s — slowest: `onconstruct_cross_swf_version` (21.1s)
