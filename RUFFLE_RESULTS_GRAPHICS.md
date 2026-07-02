# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8d1e3adef576`  
**Date:** 2026-07-02 19:32 UTC  
**Total duration:** 2h59m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 627 | 705 | 88.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 67 | 111 | 60.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **985** | **1247** | **79.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,482 | 130,975 | 88.2% |
| from_gnash/actionscript.all | 30,142 | 38,791 | 77.7% |
| from_gnash/misc-ming.all | 4,037 | 5,248 | 76.9% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **151,774** | **177,687** | **85.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 59 | 1 |
| from_gnash/actionscript.all | 14 | - |
| from_gnash/misc-ming.all | 16 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| **Total** | **110** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
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
| avm1 | string_paths_other | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/actionscript.all | Transform-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 85% |
| avm1 | bitmapdata_hittest_threshold | 83% |
| from_gnash/actionscript.all | TextField-v8 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | 2 | - | 8 |
| from_gnash/actionscript.all | - | 1 | 42 | 1 |
| from_gnash/misc-swfc.all | - | - | 3 | - |

**avm1 — newly failing:** `global_swf6_7_8`, `string_paths_other`

**from_gnash/misc-swfc.all — newly passing:** `soft_reference_test1`

*Comparing `3d2ea1b5cf7f` → `8d1e3adef576`*

## Per-Suite Details

### avm1

- **Pass:** 627/705 (88.9%)
- **Duration:** 1h18m25s across 30 shards
- **Lines:** 115,482/130,975 matching (88.2%)
- **Avg test duration:** 6.6s — slowest: `access_unnamed_shape` (47.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 34m01s across 30 shards
- **Lines:** 30,142/38,791 matching (77.7%)
- **Avg test duration:** 8.3s — slowest: `MovieClip-v8` (68.1s)

### from_gnash/misc-ming.all

- **Pass:** 67/111 (60.4%)
- **Duration:** 34m18s across 30 shards
- **Lines:** 4,037/5,248 matching (76.9%)
- **Avg test duration:** 18.5s — slowest: `matrix_test` (103.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m20s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.6s — slowest: `enum` (24.2s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m31s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 16.5s — slowest: `action_execution_order_test12` (24.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m40s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 17.0s — slowest: `background` (25.6s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m39s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.2s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (24.3s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 3m22s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 4.2s — slowest: `text-bind` (23.1s)
