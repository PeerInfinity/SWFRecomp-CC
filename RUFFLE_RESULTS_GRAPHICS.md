# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `336749f1425c`  
**Date:** 2026-11-22 02:31 UTC  
**Total duration:** 11h39m27s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 736 | 780 | 94.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1273 | 1336 | 95.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 13 | 20 | 65.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 109 | 109 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4382** | **4702** | **93.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 124,903 | 137,572 | 90.8% |
| avm2 | 161,240 | 163,949 | 98.3% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,640 | 38,791 | 79.0% |
| from_gnash/misc-ming.all | 4,252 | 5,248 | 81.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 486 | 580 | 83.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 970 | 970 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **413,658** | **438,911** | **94.2%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 22 |
| avm2 | 19 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 7 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 2 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **64** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | amf0_array_matrix | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| avm1 | localconnection_serialize_sparse_array_getters | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 96% |
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
| avm1 | 2 | - | 14 | 9 |
| from_gnash/actionscript.all | - | - | 4 | 86 |

**avm1 — newly passing:** `lazy_prototype_shared`, `video_prototype_lazy`

*Comparing `ff2e2e9d6056` → `336749f1425c`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 14.2s — slowest: `stream_incomplete_loop` (18.2s)

### avm1

- **Pass:** 736/780 (94.4%)
- **Duration:** 1h15m07s across 30 shards
- **Lines:** 124,903/137,572 matching (90.8%)
- **Avg test duration:** 5.7s — slowest: `netstream_play_flv_screen` (40.5s)

### avm2

- **Pass:** 1273/1336 (95.3%)
- **Duration:** 3h47m26s across 30 shards
- **Lines:** 161,240/163,949 matching (98.3%)
- **Avg test duration:** 10.2s — slowest: `away3d_advanced_shallow_water_demo` (81.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m39s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.7s — slowest: `device_font_glyph_fallback` (30.1s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h18m41s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_002` (58.0s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 30m52s across 30 shards
- **Lines:** 30,640/38,791 matching (79.0%)
- **Avg test duration:** 7.6s — slowest: `MovieClip-v8` (72.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 32m00s across 30 shards
- **Lines:** 4,252/5,248 matching (81.0%)
- **Avg test duration:** 17.3s — slowest: `matrix_test` (77.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.8s — slowest: `TextFieldTest` (23.0s)

### from_gnash/misc-swfc.all

- **Pass:** 13/20 (65.0%)
- **Duration:** 5m26s across 30 shards
- **Lines:** 486/580 matching (83.8%)
- **Avg test duration:** 16.3s — slowest: `movieclip_destruction_test1` (25.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m14s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.7s — slowest: `jump_to_prev_block` (24.7s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 44m59s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 11.8s — slowest: `acid/acid-large` (69.6s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.7s — slowest: `hitarea` (18.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 39s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.0s — slowest: `avm1_non_swf_import` (18.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.2s — slowest: `avm1_sprite_sc_ignored` (18.0s)

### regression

- **Pass:** 109/109 (100%)
- **Duration:** 23m40s across 30 shards
- **Lines:** 970/970 matching (100%)
- **Avg test duration:** 13.0s — slowest: `avm2_parent_child_render` (33.2s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m30s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.3s — slowest: `draw_to_bitmap_data_unconfigured` (30.0s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m05s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.3s — slowest: `convolution_filter_big_matrix` (22.6s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m31s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.6s — slowest: `text_caret_placement_leading` (32.8s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m38s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 19.9s — slowest: `missing_frame_scripts` (31.7s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 33m30s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.3s — slowest: `definefont4` (81.7s)
