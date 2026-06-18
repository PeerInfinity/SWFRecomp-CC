# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `6308c4a03e34`  
**Date:** 2026-06-18 03:34 UTC  
**Total duration:** 3h16m03s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 678 | 88.5% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 127 | 235 | 54.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 107 | 60.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 9 | 19 | 47.4% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 89 | 82.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 45 | 46 | 97.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **945** | **1203** | **78.6%** | |

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
| avm1 | 113,036 | 129,494 | 87.3% |
| from_gnash/actionscript.all | 29,662 | 38,470 | 77.1% |
| from_gnash/misc-ming.all | 3,954 | 5,154 | 76.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 428 | 557 | 76.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 842 | 1,211 | 69.5% |
| from_shumway/avm1 | 487 | 489 | 99.6% |
| **Total** | **148,713** | **175,701** | **84.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 59 | 5 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 16 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 13 | - |
| from_shumway/avm1 | - | - |
| **Total** | **106** | **5** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
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
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `485cab11544b` → `6308c4a03e34`*

## Per-Suite Details

### avm1

- **Pass:** 600/678 (88.5%)
- **Duration:** 1h28m16s across 29 shards
- **Lines:** 113,036/129,494 matching (87.3%)
- **Avg test duration:** 7.7s — slowest: `sound_load_start` (50.3s)

### from_gnash/actionscript.all

- **Pass:** 127/235 (54.0%)
- **Duration:** 37m58s across 29 shards
- **Lines:** 29,662/38,470 matching (77.1%)
- **Avg test duration:** 9.6s — slowest: `MovieClip-v8` (67.6s)

### from_gnash/misc-ming.all

- **Pass:** 65/107 (60.7%)
- **Duration:** 35m48s across 29 shards
- **Lines:** 3,954/5,154 matching (76.7%)
- **Avg test duration:** 20.0s — slowest: `matrix_test` (95.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m38s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 17.5s — slowest: `super_test1` (22.5s)

### from_gnash/misc-swfc.all

- **Pass:** 9/19 (47.4%)
- **Duration:** 5m34s across 29 shards
- **Lines:** 428/557 matching (76.8%)
- **Avg test duration:** 17.6s — slowest: `mouse_drag_test` (23.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m57s across 29 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.8s — slowest: `initaction_in_definesprite` (22.4s)

### from_shumway

- **Pass:** 73/89 (82.0%)
- **Duration:** 15m23s across 29 shards
- **Lines:** 842/1,211 matching (69.5%)
- **Avg test duration:** 10.3s — slowest: `avm1/text-bind` (23.1s)

### from_shumway/avm1

- **Pass:** 45/46 (97.8%)
- **Duration:** 3m26s across 29 shards
- **Lines:** 487/489 matching (99.6%)
- **Avg test duration:** 4.4s — slowest: `label` (22.5s)
