# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `336749f1425c`  
**Date:** 2026-11-22 02:31 UTC  
**Total duration:** 11h39m27s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 734 | 762 | 96.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1272 | 1298 | 98.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1533 | 1572 | 97.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 13 | 18 | 72.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 109 | 109 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4379** | **4632** | **94.5%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 115,770 | 119,324 | 97.0% |
| avm2 | 157,006 | 158,455 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,556 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,357 | 32,104 | 94.6% |
| from_gnash/misc-ming.all | 4,245 | 5,206 | 81.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 469 | 555 | 84.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,362 | 2,409 | 98.0% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 970 | 970 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **399,927** | **408,314** | **97.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 11 | 17 |
| avm2 | 6 | 20 |
| fonts | - | 1 |
| from_avmplus | - | 39 |
| from_gnash/actionscript.all | 4 | 88 |
| from_gnash/misc-ming.all | 8 | 33 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 1 | 8 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | 2 |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **31** | **222** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | amf0_array_matrix | 98% |
| avm1 | localconnection_serialize_sparse_array_getters | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 14.2s — slowest: `stream_incomplete_loop` (18.2s)

### avm1

- **Pass:** 734/762 (96.3%)
- **Ignored:** 18 tests
- **Duration:** 1h15m07s across 30 shards
- **Lines:** 115,770/119,324 matching (97.0%)
- **Avg test duration:** 5.7s — slowest: `equals_swf4` (31.8s)

### avm2

- **Pass:** 1272/1298 (98.0%)
- **Ignored:** 38 tests
- **Duration:** 3h47m26s across 30 shards
- **Lines:** 157,006/158,455 matching (99.1%)
- **Avg test duration:** 10.1s — slowest: `away3d_advanced_shallow_water_demo` (81.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m39s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.7s — slowest: `device_font_glyph_fallback` (30.1s)

### from_avmplus

- **Pass:** 1533/1572 (97.5%)
- **Ignored:** 2 tests
- **Duration:** 3h18m41s across 30 shards
- **Lines:** 85,556/85,970 matching (99.5%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_002` (58.0s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 30m52s across 30 shards
- **Lines:** 30,357/32,104 matching (94.6%)
- **Avg test duration:** 7.6s — slowest: `MovieClip-v8` (72.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 32m00s across 30 shards
- **Lines:** 4,245/5,206 matching (81.5%)
- **Avg test duration:** 17.2s — slowest: `matrix_test` (77.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.8s — slowest: `TextFieldTest` (23.0s)

### from_gnash/misc-swfc.all

- **Pass:** 13/18 (72.2%)
- **Ignored:** 2 tests
- **Duration:** 5m26s across 30 shards
- **Lines:** 469/555 matching (84.5%)
- **Avg test duration:** 17.0s — slowest: `movieclip_destruction_test1` (25.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m14s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.7s — slowest: `jump_to_prev_block` (24.7s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 44m59s across 30 shards
- **Lines:** 2,362/2,409 matching (98.0%)
- **Avg test duration:** 11.5s — slowest: `acid/acid-large` (69.6s)

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
