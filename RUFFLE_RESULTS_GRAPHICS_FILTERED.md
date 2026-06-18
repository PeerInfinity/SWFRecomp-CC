# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `fe0030e4fc7d`  
**Date:** 2026-06-18 22:05 UTC  
**Total duration:** 1h49m19s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 450 | 482 | 93.4% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 101 | 179 | 56.4% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 49 | 81 | 60.5% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 4 | 6 | 66.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 6 | 13 | 46.2% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 14 | 15 | 93.3% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 56 | 57 | 98.2% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 32 | 32 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **712** | **865** | **82.3%** | |

*49 tests ignored.*

### ⚠️ Incomplete Runs

- **avm1**: 22/30 shards produced results (8 missing)
- **from_gnash/actionscript.all**: 22/30 shards produced results (8 missing)
- **from_gnash/misc-ming.all**: 22/30 shards produced results (8 missing)
- **from_gnash/misc-mtasc.all**: 22/30 shards produced results (8 missing)
- **from_gnash/misc-swfc.all**: 22/30 shards produced results (8 missing)
- **from_gnash/misc-swfmill.all**: 22/30 shards produced results (8 missing)
- **from_shumway**: 22/30 shards produced results (8 missing)
- **from_shumway/avm1**: 22/30 shards produced results (8 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 86,643 | 94,354 | 91.8% |
| from_gnash/actionscript.all | 20,395 | 22,246 | 91.7% |
| from_gnash/misc-ming.all | 3,591 | 4,483 | 80.1% |
| from_gnash/misc-mtasc.all | 158 | 178 | 88.8% |
| from_gnash/misc-swfc.all | 374 | 483 | 77.4% |
| from_gnash/misc-swfmill.all | 67 | 69 | 97.1% |
| from_shumway | 529 | 530 | 99.8% |
| from_shumway/avm1 | 405 | 405 | 100% |
| **Total** | **112,162** | **122,748** | **91.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | segfault | timeout |
|-------|-----------------:|----------------:|----------:|---------:|
| avm1 | 22 | 6 | 4 | - |
| from_gnash/actionscript.all | 7 | 71 | - | - |
| from_gnash/misc-ming.all | 10 | 21 | - | 1 |
| from_gnash/misc-mtasc.all | - | 2 | - | - |
| from_gnash/misc-swfc.all | 3 | 4 | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - |
| from_shumway | - | 1 | - | - |
| from_shumway/avm1 | - | - | - | - |
| **Total** | **42** | **106** | **4** | **1** |

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
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 450/482 (93.4%)
- **Ignored:** 32 tests
- **Duration:** 43m18s across 22 shards
- **Lines:** 86,643/94,354 matching (91.8%)
- **Avg test duration:** 5.0s — slowest: `target_paths/swf4` (29.3s)

### from_gnash/actionscript.all

- **Pass:** 101/179 (56.4%)
- **Duration:** 20m01s across 22 shards
- **Lines:** 20,395/22,246 matching (91.7%)
- **Avg test duration:** 6.6s — slowest: `MovieClip-v8` (53.4s)

### from_gnash/misc-ming.all

- **Pass:** 49/81 (60.5%)
- **Ignored:** 1 tests
- **Duration:** 22m04s across 22 shards
- **Lines:** 3,591/4,483 matching (80.1%)
- **Avg test duration:** 16.2s — slowest: `matrix_test` (109.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 4/6 (66.7%)
- **Duration:** 1m30s across 22 shards
- **Lines:** 158/178 matching (88.8%)
- **Avg test duration:** 15.0s — slowest: `exception` (23.5s)

### from_gnash/misc-swfc.all

- **Pass:** 6/13 (46.2%)
- **Ignored:** 2 tests
- **Duration:** 4m15s across 22 shards
- **Lines:** 374/483 matching (77.4%)
- **Avg test duration:** 17.7s — slowest: `movieclip_destruction_test1` (24.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/15 (93.3%)
- **Duration:** 5m00s across 22 shards
- **Lines:** 67/69 matching (97.1%)
- **Avg test duration:** 20.0s — slowest: `dict_callframe` (22.8s)

### from_shumway

- **Pass:** 56/57 (98.2%)
- **Ignored:** 11 tests
- **Duration:** 10m31s across 22 shards
- **Lines:** 529/530 matching (99.8%)
- **Avg test duration:** 6.6s — slowest: `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` (27.3s)

### from_shumway/avm1

- **Pass:** 32/32 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m37s across 22 shards
- **Lines:** 405/405 matching (100%)
- **Avg test duration:** 3.0s — slowest: `rollover` (21.6s)
