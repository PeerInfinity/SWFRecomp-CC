# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8c576d3e5451`  
**Date:** 2026-07-10 21:14 UTC  
**Total duration:** 2h51m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 68 | 111 | 61.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| regression | 19 | 19 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **1012** | **1267** | **79.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,802 | 130,978 | 88.4% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,048 | 5,248 | 77.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 128 | 128 | 100% |
| **Total** | **152,447** | **177,818** | **85.7%** |

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

*Comparing `ea3647e8d139` → `8c576d3e5451`*

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 1h13m20s across 30 shards
- **Lines:** 115,802/130,978 matching (88.4%)
- **Avg test duration:** 6.2s — slowest: `netstream_play_flv_screen` (36.9s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 31m04s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 7.6s — slowest: `MovieClip-v8` (69.9s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 32m15s across 30 shards
- **Lines:** 4,048/5,248 matching (77.1%)
- **Avg test duration:** 17.4s — slowest: `matrix_test` (104.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.7s — slowest: `enum` (21.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m46s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 17.3s — slowest: `movieclip_destruction_test3` (23.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m27s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 13.3s — slowest: `background` (22.0s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m16s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.9s — slowest: `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` (25.1s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 3m08s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.9s — slowest: `moviecliploader` (21.6s)

### regression

- **Pass:** 19/19 (100%)
- **Duration:** 3m46s across 30 shards
- **Lines:** 128/128 matching (100%)
- **Avg test duration:** 11.9s — slowest: `timer_cross_swf_version` (21.1s)
