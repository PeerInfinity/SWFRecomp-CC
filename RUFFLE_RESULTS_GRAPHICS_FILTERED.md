# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `079c0fefecc6`  
**Date:** 2026-06-18 00:01 UTC  
**Total duration:** 2h35m36s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 638 | 94.0% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 124 | 229 | 54.1% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 63 | 106 | 59.4% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 9 | 17 | 52.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 72 | 75 | 96.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 43 | 43 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **937** | **1137** | **82.4%** | |

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
| avm1 | 99,779 | 106,229 | 93.9% |
| from_gnash/actionscript.all | 29,233 | 31,521 | 92.7% |
| from_gnash/misc-ming.all | 3,944 | 5,116 | 77.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 411 | 532 | 77.3% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 615 | 631 | 97.5% |
| from_shumway/avm1 | 441 | 441 | 100% |
| **Total** | **134,727** | **144,796** | **93.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | segfault |
|-------|-----------------:|----------------:|----------:|
| avm1 | 26 | 8 | 4 |
| from_gnash/actionscript.all | 10 | 95 | - |
| from_gnash/misc-ming.all | 15 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **54** | **142** | **4** |

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

## Per-Suite Details

### avm1

- **Pass:** 600/638 (94.0%)
- **Ignored:** 40 tests
- **Duration:** 1h08m26s across 29 shards
- **Lines:** 99,779/106,229 matching (93.9%)
- **Avg test duration:** 6.0s — slowest: `movieclip_begin_gradient_fill` (32.0s)

### from_gnash/actionscript.all

- **Pass:** 124/229 (54.1%)
- **Ignored:** 6 tests
- **Duration:** 28m36s across 29 shards
- **Lines:** 29,233/31,521 matching (92.7%)
- **Avg test duration:** 7.3s — slowest: `MovieClip-v8` (63.5s)

### from_gnash/misc-ming.all

- **Pass:** 63/106 (59.4%)
- **Ignored:** 1 tests
- **Duration:** 29m54s across 29 shards
- **Lines:** 3,944/5,116 matching (77.1%)
- **Avg test duration:** 16.7s — slowest: `matrix_test` (105.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m36s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 17.3s — slowest: `exception` (22.1s)

### from_gnash/misc-swfc.all

- **Pass:** 9/17 (52.9%)
- **Ignored:** 2 tests
- **Duration:** 4m36s across 29 shards
- **Lines:** 411/532 matching (77.3%)
- **Avg test duration:** 13.7s — slowest: `edittext_test1` (22.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 3m27s across 29 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 10.3s — slowest: `background` (22.6s)

### from_shumway

- **Pass:** 72/75 (96.0%)
- **Ignored:** 14 tests
- **Duration:** 14m41s across 29 shards
- **Lines:** 615/631 matching (97.5%)
- **Avg test duration:** 7.7s — slowest: `avm1/text-bind` (22.5s)

### from_shumway/avm1

- **Pass:** 43/43 (100%)
- **Ignored:** 3 tests
- **Duration:** 3m16s across 29 shards
- **Lines:** 441/441 matching (100%)
- **Avg test duration:** 3.1s — slowest: `rollover` (21.1s)
