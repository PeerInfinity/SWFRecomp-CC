# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `eb3bc573d2da`  
**Date:** 2026-06-13 20:01 UTC  
**Total duration:** 2h48m46s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 598 | 624 | 95.8% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 124 | 229 | 54.1% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 64 | 106 | 60.4% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 9 | 17 | 52.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 72 | 75 | 96.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 43 | 43 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **936** | **1123** | **83.3%** | |

*66 tests ignored.*

### ⚠️ Incomplete Runs

- **avm1**: 29/30 shards produced results (1 missing)
- **from_gnash/actionscript.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-ming.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-mtasc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfmill.all**: 29/30 shards produced results (1 missing)
- **from_shumway**: 29/30 shards produced results (1 missing)
- **from_shumway/avm1**: 29/30 shards produced results (1 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 99,316 | 101,825 | 97.5% |
| from_gnash/actionscript.all | 29,233 | 31,521 | 92.7% |
| from_gnash/misc-ming.all | 3,949 | 5,116 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 411 | 532 | 77.3% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 615 | 631 | 97.5% |
| from_shumway/avm1 | 441 | 441 | 100% |
| **Total** | **134,269** | **140,392** | **95.6%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 19 | 7 |
| from_gnash/actionscript.all | 10 | 95 |
| from_gnash/misc-ming.all | 14 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 3 | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **46** | **141** |

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

- **Pass:** 598/624 (95.8%)
- **Ignored:** 40 tests
- **Duration:** 1h10m57s across 29 shards
- **Lines:** 99,316/101,825 matching (97.5%)
- **Avg test duration:** 6.4s — slowest: `function_as_function` (26.7s)

### from_gnash/actionscript.all

- **Pass:** 124/229 (54.1%)
- **Ignored:** 6 tests
- **Duration:** 34m35s across 29 shards
- **Lines:** 29,233/31,521 matching (92.7%)
- **Avg test duration:** 8.8s — slowest: `MovieClip-v8` (64.3s)

### from_gnash/misc-ming.all

- **Pass:** 64/106 (60.4%)
- **Ignored:** 1 tests
- **Duration:** 32m58s across 29 shards
- **Lines:** 3,949/5,116 matching (77.2%)
- **Avg test duration:** 18.4s — slowest: `matrix_test` (102.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m28s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.5s — slowest: `exception` (21.5s)

### from_gnash/misc-swfc.all

- **Pass:** 9/17 (52.9%)
- **Ignored:** 2 tests
- **Duration:** 5m05s across 29 shards
- **Lines:** 411/532 matching (77.3%)
- **Avg test duration:** 15.8s — slowest: `movieclip_destruction_test4` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m24s across 29 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.2s — slowest: `mixed-bytecode-as2` (20.5s)

### from_shumway

- **Pass:** 72/75 (96.0%)
- **Ignored:** 14 tests
- **Duration:** 14m14s across 29 shards
- **Lines:** 615/631 matching (97.5%)
- **Avg test duration:** 7.4s — slowest: `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` (21.5s)

### from_shumway/avm1

- **Pass:** 43/43 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m03s across 29 shards
- **Lines:** 441/441 matching (100%)
- **Avg test duration:** 1.9s — slowest: `duplicateMovieClip/dontremove` (20.1s)
