# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `079c0fefecc6`  
**Date:** 2026-06-18 00:01 UTC  
**Total duration:** 2h35m36s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 678 | 88.8% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 127 | 235 | 54.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 64 | 107 | 59.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 9 | 19 | 47.4% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 72 | 89 | 80.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
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
| avm1 | 110,215 | 125,364 | 87.9% |
| from_gnash/actionscript.all | 29,586 | 38,394 | 77.1% |
| from_gnash/misc-ming.all | 3,962 | 5,134 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 428 | 557 | 76.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 840 | 1,190 | 70.6% |
| from_shumway/avm1 | 450 | 452 | 99.6% |
| **Total** | **145,785** | **171,417** | **85.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 59 | 5 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 15 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 14 | - |
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

*Comparing `2c74f64fc3bb` → `079c0fefecc6`*

## Per-Suite Details

### avm1

- **Pass:** 602/678 (88.8%)
- **Duration:** 1h08m26s across 29 shards
- **Lines:** 110,215/125,364 matching (87.9%)
- **Avg test duration:** 6.0s — slowest: `netstream_play_flv_screen` (36.4s)

### from_gnash/actionscript.all

- **Pass:** 127/235 (54.0%)
- **Duration:** 28m36s across 29 shards
- **Lines:** 29,586/38,394 matching (77.1%)
- **Avg test duration:** 7.2s — slowest: `MovieClip-v8` (63.5s)

### from_gnash/misc-ming.all

- **Pass:** 64/107 (59.8%)
- **Duration:** 29m54s across 29 shards
- **Lines:** 3,962/5,134 matching (77.2%)
- **Avg test duration:** 16.7s — slowest: `matrix_test` (105.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m36s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 17.3s — slowest: `exception` (22.1s)

### from_gnash/misc-swfc.all

- **Pass:** 9/19 (47.4%)
- **Duration:** 4m36s across 29 shards
- **Lines:** 428/557 matching (76.8%)
- **Avg test duration:** 14.5s — slowest: `edittext_test1` (22.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 3m27s across 29 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 10.3s — slowest: `background` (22.6s)

### from_shumway

- **Pass:** 72/89 (80.9%)
- **Duration:** 14m41s across 29 shards
- **Lines:** 840/1,190 matching (70.6%)
- **Avg test duration:** 9.8s — slowest: `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` (23.4s)

### from_shumway/avm1

- **Pass:** 45/46 (97.8%)
- **Duration:** 3m16s across 29 shards
- **Lines:** 450/452 matching (99.6%)
- **Avg test duration:** 4.2s — slowest: `text-bind` (22.8s)
