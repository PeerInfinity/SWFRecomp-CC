# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `6308c4a03e34`  
**Date:** 2026-06-18 03:34 UTC  
**Total duration:** 3h16m03s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 598 | 637 | 93.9% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 127 | 232 | 54.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 64 | 105 | 61.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 9 | 17 | 52.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 43 | 43 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **940** | **1139** | **82.5%** | |

*64 tests ignored.*

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
| avm1 | 102,599 | 110,355 | 93.0% |
| from_gnash/actionscript.all | 29,495 | 31,783 | 92.8% |
| from_gnash/misc-ming.all | 3,933 | 5,094 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 411 | 532 | 77.3% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 478 | 478 | 100% |
| **Total** | **137,841** | **149,205** | **92.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | segfault |
|-------|-----------------:|----------------:|----------:|
| avm1 | 26 | 9 | 4 |
| from_gnash/actionscript.all | 10 | 95 | - |
| from_gnash/misc-ming.all | 15 | 26 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **54** | **141** | **4** |

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

- **Pass:** 598/637 (93.9%)
- **Ignored:** 41 tests
- **Duration:** 1h28m16s across 29 shards
- **Lines:** 102,599/110,355 matching (93.0%)
- **Avg test duration:** 7.8s — slowest: `sound_load_start` (50.3s)

### from_gnash/actionscript.all

- **Pass:** 127/232 (54.7%)
- **Ignored:** 3 tests
- **Duration:** 37m58s across 29 shards
- **Lines:** 29,495/31,783 matching (92.8%)
- **Avg test duration:** 9.6s — slowest: `MovieClip-v8` (67.6s)

### from_gnash/misc-ming.all

- **Pass:** 64/105 (61.0%)
- **Ignored:** 2 tests
- **Duration:** 35m48s across 29 shards
- **Lines:** 3,933/5,094 matching (77.2%)
- **Avg test duration:** 20.0s — slowest: `matrix_test` (95.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m38s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 17.5s — slowest: `super_test1` (22.5s)

### from_gnash/misc-swfc.all

- **Pass:** 9/17 (52.9%)
- **Ignored:** 2 tests
- **Duration:** 5m34s across 29 shards
- **Lines:** 411/532 matching (77.3%)
- **Avg test duration:** 17.1s — slowest: `mouse_drag_test` (23.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m57s across 29 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.8s — slowest: `initaction_in_definesprite` (22.4s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 13 tests
- **Duration:** 15m23s across 29 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 8.4s — slowest: `avm1/text-bind` (23.1s)

### from_shumway/avm1

- **Pass:** 43/43 (100%)
- **Ignored:** 3 tests
- **Duration:** 3m26s across 29 shards
- **Lines:** 478/478 matching (100%)
- **Avg test duration:** 3.2s — slowest: `label` (22.5s)
