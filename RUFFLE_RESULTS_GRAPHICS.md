# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `c0ce53c7286f`  
**Date:** 2026-07-11 05:47 UTC  
**Total duration:** 4h58m29s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 8 | 1198 | 0.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 68 | 111 | 61.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| regression | 36 | 36 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **1037** | **2482** | **41.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,790 | 130,978 | 88.4% |
| avm2 | 289 | 148,815 | 0.2% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,048 | 5,248 | 77.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 245 | 245 | 100% |
| **Total** | **152,841** | **326,750** | **46.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 55 | - | 1 |
| avm2 | 26 | 1163 | - |
| from_gnash/actionscript.all | 13 | - | - |
| from_gnash/misc-ming.all | 15 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| regression | - | - | - |
| **Total** | **130** | **1163** | **1** |

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
| avm1 | mcl_replace_root_swf7_to_swf5 | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 12 |
| from_gnash/misc-swfmill.all | 1 | - | 1 | - |

**from_gnash/misc-swfmill.all — newly passing:** `mixed-bytecode-as2`

*Comparing `83bef14d7e8b` → `c0ce53c7286f`*

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 1h26m16s across 30 shards
- **Lines:** 115,790/130,978 matching (88.4%)
- **Avg test duration:** 7.3s — slowest: `netstream_play_flv_screen` (36.0s)

### avm2

- **Pass:** 8/1198 (0.7%)
- **Duration:** 1h36m27s across 30 shards
- **Lines:** 289/148,815 matching (0.2%)
- **Avg test duration:** 4.8s — slowest: `away3d_advanced_shallow_water_demo` (38.6s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 36m38s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 9.0s — slowest: `MovieClip-v8` (64.6s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 35m37s across 30 shards
- **Lines:** 4,048/5,248 matching (77.1%)
- **Avg test duration:** 19.2s — slowest: `matrix_test` (108.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `implementsOpTest` (21.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m06s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 18.3s — slowest: `registerclass_test3` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m46s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.2s — slowest: `missing_bitmap` (22.3s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m57s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.7s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (22.4s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.9s — slowest: `text-bind` (21.5s)

### regression

- **Pass:** 36/36 (100%)
- **Duration:** 11m06s across 30 shards
- **Lines:** 245/245 matching (100%)
- **Avg test duration:** 18.5s — slowest: `timer_type1_args` (22.3s)
