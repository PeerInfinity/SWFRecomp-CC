# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `0973204c3999`  
**Date:** 2026-06-01 01:10 UTC  
**Total duration:** 3h11m40s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 616 | 673 | 91.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 132 | 243 | 54.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 110 | 59.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **966** | **1213** | **79.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,864 | 116,485 | 91.7% |
| from_gnash/actionscript.all | 29,831 | 38,791 | 76.9% |
| from_gnash/misc-ming.all | 4,014 | 5,239 | 76.6% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,808** | **163,165** | **87.5%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 46 | 1 |
| from_gnash/actionscript.all | 14 | - |
| from_gnash/misc-ming.all | 17 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| **Total** | **97** | **1** |

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
| avm1 | movieclip_library_state_values | 96% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| from_gnash/actionscript.all | MovieClip-v5 | 93% |
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

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 1 |
| from_gnash/actionscript.all | - | 1 | - | 8 |

*Comparing `24cbf0ff5bc6` → `0973204c3999`*

## Per-Suite Details

### avm1

- **Pass:** 616/673 (91.5%)
- **Duration:** 1h22m17s across 30 shards
- **Lines:** 106,864/116,485 matching (91.7%)
- **Avg test duration:** 7.3s — slowest: `clone_sprite_edittext_dynamic` (39.4s)

### from_gnash/actionscript.all

- **Pass:** 132/243 (54.3%)
- **Duration:** 38m33s across 30 shards
- **Lines:** 29,831/38,791 matching (76.9%)
- **Avg test duration:** 9.5s — slowest: `MovieClip-v8` (65.3s)

### from_gnash/misc-ming.all

- **Pass:** 65/110 (59.1%)
- **Duration:** 36m41s across 30 shards
- **Lines:** 4,014/5,239 matching (76.6%)
- **Avg test duration:** 19.9s — slowest: `matrix_test` (106.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m35s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 17.2s — slowest: `enum` (21.9s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 5m32s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 17.4s — slowest: `matrix_accuracy_test1` (23.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m50s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.5s — slowest: `background` (23.3s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 16m37s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.8s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (23.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m32s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.2s — slowest: `text-bind` (21.1s)
