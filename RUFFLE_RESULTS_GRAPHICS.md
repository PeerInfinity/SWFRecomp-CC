# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `3c5a3c75e1cf`  
**Date:** 2026-06-22 18:02 UTC  
**Total duration:** 3h12m23s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 629 | 703 | 89.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 128 | 235 | 54.5% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 63 | 107 | 58.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 10 | 19 | 52.6% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **974** | **1231** | **79.1%** | |

### ⚠️ Incomplete Runs

- **from_gnash/actionscript.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-ming.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-mtasc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfmill.all**: 29/30 shards produced results (1 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,471 | 130,961 | 88.2% |
| from_gnash/actionscript.all | 29,815 | 38,484 | 77.5% |
| from_gnash/misc-ming.all | 3,972 | 5,183 | 76.6% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 393 | 535 | 73.5% |
| from_gnash/misc-swfmill.all | 89 | 91 | 97.8% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **151,322** | **177,252** | **85.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 56 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 16 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| **Total** | **106** | **1** |

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
| from_gnash/actionscript.all | MovieClip-v7 | 95% |
| from_gnash/actionscript.all | MovieClip-v6 | 95% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
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
| avm1 | - | - | - | 13 |

*Comparing `96e9660aefe6` → `3c5a3c75e1cf`*

## Per-Suite Details

### avm1

- **Pass:** 629/703 (89.5%)
- **Duration:** 1h27m37s across 30 shards
- **Lines:** 115,471/130,961 matching (88.2%)
- **Avg test duration:** 7.4s — slowest: `edittext_html_align_swf7` (39.5s)

### from_gnash/actionscript.all

- **Pass:** 128/235 (54.5%)
- **Duration:** 37m07s across 29 shards
- **Lines:** 29,815/38,484 matching (77.5%)
- **Avg test duration:** 9.4s — slowest: `MovieClip-v8` (56.5s)

### from_gnash/misc-ming.all

- **Pass:** 63/107 (58.9%)
- **Duration:** 34m18s across 29 shards
- **Lines:** 3,972/5,183 matching (76.6%)
- **Avg test duration:** 19.2s — slowest: `matrix_test` (108.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m48s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.1s — slowest: `implementsOpTest` (23.1s)

### from_gnash/misc-swfc.all

- **Pass:** 10/19 (52.6%)
- **Duration:** 5m30s across 29 shards
- **Lines:** 393/535 matching (73.5%)
- **Avg test duration:** 17.4s — slowest: `gotoFrameLabelAsFunction` (23.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 6m13s across 29 shards
- **Lines:** 89/91 matching (97.8%)
- **Avg test duration:** 19.6s — slowest: `background` (23.4s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 16m28s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.7s — slowest: `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` (24.1s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 3m19s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 4.2s — slowest: `text-bind` (24.6s)
