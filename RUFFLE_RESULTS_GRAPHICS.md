# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `2c07e01a5a02`  
**Date:** 2026-06-26 19:50 UTC  
**Total duration:** 2h47m43s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 629 | 704 | 89.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 128 | 235 | 54.5% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 63 | 107 | 58.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 10 | 19 | 52.6% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **974** | **1232** | **79.1%** | |

### ⚠️ Incomplete Runs

- **from_gnash/actionscript.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-ming.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-mtasc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfmill.all**: 29/30 shards produced results (1 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,485 | 130,968 | 88.2% |
| from_gnash/actionscript.all | 29,815 | 38,484 | 77.5% |
| from_gnash/misc-ming.all | 3,972 | 5,183 | 76.6% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 393 | 535 | 73.5% |
| from_gnash/misc-swfmill.all | 89 | 91 | 97.8% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **151,336** | **177,259** | **85.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 57 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 16 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| **Total** | **107** | **1** |

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

*No changes since last run.*

*Comparing `1af043d3e7c7` → `2c07e01a5a02`*

## Per-Suite Details

### avm1

- **Pass:** 629/704 (89.3%)
- **Duration:** 1h11m51s across 30 shards
- **Lines:** 115,485/130,968 matching (88.2%)
- **Avg test duration:** 6.1s — slowest: `netstream_play_flv_screen` (37.2s)

### from_gnash/actionscript.all

- **Pass:** 128/235 (54.5%)
- **Duration:** 32m08s across 29 shards
- **Lines:** 29,815/38,484 matching (77.5%)
- **Avg test duration:** 8.1s — slowest: `MovieClip-v8` (75.2s)

### from_gnash/misc-ming.all

- **Pass:** 63/107 (58.9%)
- **Duration:** 32m18s across 29 shards
- **Lines:** 3,972/5,183 matching (76.6%)
- **Avg test duration:** 18.1s — slowest: `matrix_test` (107.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m21s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.7s — slowest: `TextFieldTest` (23.8s)

### from_gnash/misc-swfc.all

- **Pass:** 10/19 (52.6%)
- **Duration:** 4m51s across 29 shards
- **Lines:** 393/535 matching (73.5%)
- **Avg test duration:** 15.3s — slowest: `movieclip_destruction_test3` (24.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 5m00s across 29 shards
- **Lines:** 89/91 matching (97.8%)
- **Avg test duration:** 15.7s — slowest: `mixed-bytecode-as2` (23.4s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 16m07s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.5s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (23.8s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 3m03s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.8s — slowest: `text-bind` (23.4s)
