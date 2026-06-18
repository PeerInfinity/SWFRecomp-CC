# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `fe0030e4fc7d`  
**Date:** 2026-06-18 21:40 UTC  
**Total duration:** 2h06m01s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 532 | 571 | 93.2% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 110 | 197 | 55.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 54 | 90 | 60.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 6 | 8 | 75.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 14 | 57.1% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 16 | 93.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 65 | 67 | 97.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 38 | 38 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **828** | **1001** | **82.7%** | |

*63 tests ignored.*

### ⚠️ Incomplete Runs

- **avm1**: 26/30 shards produced results (4 missing)
- **from_gnash/actionscript.all**: 25/30 shards produced results (5 missing)
- **from_gnash/misc-ming.all**: 25/30 shards produced results (5 missing)
- **from_gnash/misc-mtasc.all**: 25/30 shards produced results (5 missing)
- **from_gnash/misc-swfc.all**: 25/30 shards produced results (5 missing)
- **from_gnash/misc-swfmill.all**: 25/30 shards produced results (5 missing)
- **from_shumway**: 26/30 shards produced results (4 missing)
- **from_shumway/avm1**: 26/30 shards produced results (4 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 97,659 | 105,412 | 92.6% |
| from_gnash/actionscript.all | 22,949 | 24,452 | 93.9% |
| from_gnash/misc-ming.all | 3,732 | 4,711 | 79.2% |
| from_gnash/misc-mtasc.all | 203 | 223 | 91.0% |
| from_gnash/misc-swfc.all | 357 | 443 | 80.6% |
| from_gnash/misc-swfmill.all | 40 | 42 | 95.2% |
| from_shumway | 583 | 597 | 97.7% |
| from_shumway/avm1 | 410 | 410 | 100% |
| **Total** | **125,933** | **136,290** | **92.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | segfault |
|-------|-----------------:|----------------:|----------:|
| avm1 | 25 | 10 | 4 |
| from_gnash/actionscript.all | 3 | 84 | - |
| from_gnash/misc-ming.all | 14 | 22 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 4 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 2 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **44** | **125** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm1 | set_target_2_swf6 | 92% |
| avm1 | set_target_2_swf7 | 92% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 532/571 (93.2%)
- **Ignored:** 37 tests
- **Duration:** 52m41s across 26 shards
- **Lines:** 97,659/105,412 matching (92.6%)
- **Avg test duration:** 5.2s — slowest: `focus_remove` (39.5s)

### from_gnash/actionscript.all

- **Pass:** 110/197 (55.8%)
- **Ignored:** 6 tests
- **Duration:** 22m55s across 25 shards
- **Lines:** 22,949/24,452 matching (93.9%)
- **Avg test duration:** 6.7s — slowest: `MovieClip-v8` (66.0s)

### from_gnash/misc-ming.all

- **Pass:** 54/90 (60.0%)
- **Ignored:** 2 tests
- **Duration:** 23m02s across 25 shards
- **Lines:** 3,732/4,711 matching (79.2%)
- **Avg test duration:** 15.0s — slowest: `matrix_test` (103.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m09s across 25 shards
- **Lines:** 203/223 matching (91.0%)
- **Avg test duration:** 16.1s — slowest: `exception` (22.9s)

### from_gnash/misc-swfc.all

- **Pass:** 8/14 (57.1%)
- **Ignored:** 2 tests
- **Duration:** 4m20s across 25 shards
- **Lines:** 357/443 matching (80.6%)
- **Avg test duration:** 16.8s — slowest: `mouse_drag_test` (22.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/16 (93.8%)
- **Duration:** 5m23s across 25 shards
- **Lines:** 40/42 matching (95.2%)
- **Avg test duration:** 20.2s — slowest: `jump_after_end` (22.4s)

### from_shumway

- **Pass:** 65/67 (97.0%)
- **Ignored:** 13 tests
- **Duration:** 12m16s across 26 shards
- **Lines:** 583/597 matching (97.7%)
- **Avg test duration:** 6.6s — slowest: `invalidClipDepth` (22.2s)

### from_shumway/avm1

- **Pass:** 38/38 (100%)
- **Ignored:** 3 tests
- **Duration:** 3m12s across 26 shards
- **Lines:** 410/410 matching (100%)
- **Avg test duration:** 3.3s — slowest: `label` (22.3s)
