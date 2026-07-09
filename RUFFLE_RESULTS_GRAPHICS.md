# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `d3e5747bc594`  
**Date:** 2026-07-09 19:17 UTC  
**Total duration:** 3h20m14s

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
| regression | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **1001** | **1256** | **79.7%** | |

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
| regression | 52 | 52 | 100% |
| **Total** | **152,371** | **177,742** | **85.7%** |

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

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | - | 219 | - |

*Comparing `7ff10e15752d` → `d3e5747bc594`*

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 1h28m27s across 30 shards
- **Lines:** 115,802/130,978 matching (88.4%)
- **Avg test duration:** 7.5s — slowest: `prototype_delete` (41.0s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 37m42s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 9.2s — slowest: `MovieClip-v8` (56.5s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 36m38s across 30 shards
- **Lines:** 4,048/5,248 matching (77.1%)
- **Avg test duration:** 19.7s — slowest: `matrix_test` (106.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m14s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.9s — slowest: `implementsOpTest` (21.6s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m16s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 18.7s — slowest: `sound` (23.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m55s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.7s — slowest: `trace-as2/arguments` (23.4s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m54s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.3s — slowest: `avm1/text-bind` (24.2s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 3m21s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 4.2s — slowest: `text-bind` (21.6s)

### regression

- **Pass:** 8/8 (100%)
- **Duration:** 2m43s across 30 shards
- **Lines:** 52/52 matching (100%)
- **Avg test duration:** 20.4s — slowest: `ei_type1_args` (21.2s)
