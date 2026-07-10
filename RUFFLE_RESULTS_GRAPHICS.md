# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8a8ff17c73a3`  
**Date:** 2026-07-10 22:53 UTC  
**Total duration:** 3h14m55s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 610 | 682 | 89.4% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 128 | 235 | 54.5% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 64 | 107 | 59.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 10 | 19 | 52.6% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 70 | 89 | 78.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 44 | 45 | 97.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| regression | 20 | 20 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **971** | **1225** | **79.3%** | |

### ⚠️ Incomplete Runs

- **avm1**: 29/30 shards produced results (1 missing)
- **from_gnash/actionscript.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-ming.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-mtasc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfmill.all**: 29/30 shards produced results (1 missing)
- **from_shumway**: 29/30 shards produced results (1 missing)
- **from_shumway/avm1**: 29/30 shards produced results (1 missing)
- **regression**: 29/30 shards produced results (1 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,389 | 130,565 | 88.4% |
| from_gnash/actionscript.all | 29,161 | 37,588 | 77.6% |
| from_gnash/misc-ming.all | 3,981 | 5,181 | 76.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 414 | 556 | 74.5% |
| from_gnash/misc-swfmill.all | 92 | 94 | 97.9% |
| from_shumway | 796 | 1,190 | 66.9% |
| from_shumway/avm1 | 470 | 472 | 99.6% |
| regression | 149 | 149 | 100% |
| **Total** | **150,663** | **176,026** | **85.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 54 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 15 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| regression | - | - |
| **Total** | **103** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
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
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `1f68e0043c1b` → `8a8ff17c73a3`*

## Per-Suite Details

### avm1

- **Pass:** 610/682 (89.4%)
- **Duration:** 1h23m14s across 29 shards
- **Lines:** 115,389/130,565 matching (88.4%)
- **Avg test duration:** 7.3s — slowest: `netstream_play_flv_screen` (36.7s)

### from_gnash/actionscript.all

- **Pass:** 128/235 (54.5%)
- **Duration:** 36m18s across 29 shards
- **Lines:** 29,161/37,588 matching (77.6%)
- **Avg test duration:** 9.2s — slowest: `MovieClip-v8` (70.5s)

### from_gnash/misc-ming.all

- **Pass:** 64/107 (59.8%)
- **Duration:** 35m34s across 29 shards
- **Lines:** 3,981/5,181 matching (76.8%)
- **Avg test duration:** 19.9s — slowest: `matrix_test` (104.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m14s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `exception` (22.1s)

### from_gnash/misc-swfc.all

- **Pass:** 10/19 (52.6%)
- **Duration:** 5m42s across 29 shards
- **Lines:** 414/556 matching (74.5%)
- **Avg test duration:** 18.0s — slowest: `movieclip_destruction_test3` (23.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 6m24s across 29 shards
- **Lines:** 92/94 matching (97.9%)
- **Avg test duration:** 20.2s — slowest: `missing_bitmap` (23.0s)

### from_shumway

- **Pass:** 70/89 (78.7%)
- **Duration:** 15m35s across 29 shards
- **Lines:** 796/1,190 matching (66.9%)
- **Avg test duration:** 10.5s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (23.5s)

### from_shumway/avm1

- **Pass:** 44/45 (97.8%)
- **Duration:** 3m09s across 29 shards
- **Lines:** 470/472 matching (99.6%)
- **Avg test duration:** 4.2s — slowest: `text-bind` (21.0s)

### regression

- **Pass:** 20/20 (100%)
- **Duration:** 6m40s across 29 shards
- **Lines:** 149/149 matching (100%)
- **Avg test duration:** 20.0s — slowest: `fn_empty_method_type1_args` (21.8s)
