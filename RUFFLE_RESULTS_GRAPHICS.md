# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `f48c532bf170`  
**Date:** 2026-09-12 00:02 UTC  
**Total duration:** 12h36m43s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 691 | 734 | 94.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1205 | 1274 | 94.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 213 | 229 | 93.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 94 | 94 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4228** | **4572** | **92.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 120,611 | 132,289 | 91.2% |
| avm2 | 153,109 | 157,153 | 97.4% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,560 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,418 | 38,791 | 78.4% |
| from_gnash/misc-ming.all | 4,058 | 5,248 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,393 | 2,484 | 96.3% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 723 | 723 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **400,289** | **426,558** | **93.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 25 | - |
| avm2 | 33 | - |
| fonts | 1 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 4 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 1 | - |
| visual | - | - |
| **Total** | **102** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmapdata_copypixels_self | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | geom_transform | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | bitmapdata_copypixels_self | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 6 | - | 267 | - |
| from_avmplus | 1 | - | 2 | - |
| from_shumway | 1 | - | 72 | - |
| mixed_avm | - | - | - | 2 |

**avm2 — newly passing:** `bitmap_filter_abstract`, `bytearray_bad_symbol_class`, `bytearray_bad_symbol_class_other_movie`, `json_parse_errors`, `matrix3d_append_rotation`

*Comparing `c4a952960bca` → `f48c532bf170`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 17.2s — slowest: `stream_incomplete_loop` (22.8s)

### avm1

- **Pass:** 691/734 (94.1%)
- **Duration:** 1h22m53s across 30 shards
- **Lines:** 120,611/132,289 matching (91.2%)
- **Avg test duration:** 6.7s — slowest: `array_slice` (39.6s)

### avm2

- **Pass:** 1205/1274 (94.6%)
- **Duration:** 4h03m42s across 30 shards
- **Lines:** 153,109/157,153 matching (97.4%)
- **Avg test duration:** 11.4s — slowest: `away3d_advanced_shallow_water_demo` (96.9s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 3m07s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 23.3s — slowest: `embed_matching/fallback_preferences` (34.9s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h34m45s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_002` (67.7s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 33m32s across 30 shards
- **Lines:** 30,418/38,791 matching (78.4%)
- **Avg test duration:** 8.2s — slowest: `MovieClip-v8` (52.2s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 35m26s across 30 shards
- **Lines:** 4,058/5,248 matching (77.3%)
- **Avg test duration:** 19.1s — slowest: `matrix_test` (110.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m59s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.2s — slowest: `function_test` (22.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m42s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.1s — slowest: `action_execution_order_test12` (24.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m43s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.1s — slowest: `trace-as2/arguments` (23.0s)

### from_shumway

- **Pass:** 213/229 (93.0%)
- **Duration:** 50m15s across 30 shards
- **Lines:** 2,393/2,484 matching (96.3%)
- **Avg test duration:** 13.1s — slowest: `acid/acid-large` (81.3s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 3m05s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.9s — slowest: `rollover` (22.6s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 48s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.1s — slowest: `avm1_non_swf_import` (23.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m31s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 7.6s — slowest: `avm1_sprite_sc_ignored` (23.3s)

### regression

- **Pass:** 94/94 (100%)
- **Duration:** 23m42s across 30 shards
- **Lines:** 723/723 matching (100%)
- **Avg test duration:** 15.1s — slowest: `avm2_timeline_solid` (33.5s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 10.3s — slowest: `scissor_rectangle` (12.4s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 56s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 7.9s — slowest: `lzma_length_too_long` (22.9s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m44s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.3s — slowest: `auto_size/return` (34.4s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 5m40s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 20.0s — slowest: `swf_9_frame_script_cleanup_goto2` (31.6s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 36m25s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.8s — slowest: `definefont4` (77.6s)
