# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `c1fa89bc20be`  
**Date:** 2026-10-19 20:20 UTC  
**Total duration:** 9h56m09s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 710 | 748 | 94.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1234 | 1300 | 94.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1531 | 1574 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 104 | 104 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 147 | 149 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4301** | **4625** | **93.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 124,739 | 136,457 | 91.4% |
| avm2 | 156,721 | 160,133 | 97.9% |
| fonts | 351 | 377 | 93.1% |
| from_avmplus | 85,562 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,712 | 38,791 | 79.2% |
| from_gnash/misc-ming.all | 4,236 | 5,248 | 80.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,396 | 2,484 | 96.5% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 871 | 871 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **408,825** | **433,867** | **94.2%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 2 |
| avm1 | 18 |
| avm2 | 24 |
| fonts | 1 |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 7 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 3 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **71** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | edittext_html_duplicate_attributes | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | array_join_reentrant | 85% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | - | 4 |

*Comparing `38cf9b1a0ab8` → `c1fa89bc20be`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.4s — slowest: `g711_event_alaw` (19.4s)

### avm1

- **Pass:** 710/748 (94.9%)
- **Duration:** 47m58s across 30 shards
- **Lines:** 124,739/136,457 matching (91.4%)
- **Avg test duration:** 3.8s — slowest: `hitarea_sweep` (36.0s)

### avm2

- **Pass:** 1234/1300 (94.9%)
- **Duration:** 3h25m15s across 30 shards
- **Lines:** 156,721/160,133 matching (97.9%)
- **Avg test duration:** 9.4s — slowest: `away3d_advanced_shallow_water_demo` (90.8s)

### fonts

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m50s across 30 shards
- **Lines:** 351/377 matching (93.1%)
- **Avg test duration:** 18.9s — slowest: `device_font_kerning` (30.4s)

### from_avmplus

- **Pass:** 1531/1574 (97.3%)
- **Duration:** 3h17m30s across 30 shards
- **Lines:** 85,562/85,996 matching (99.5%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_002` (59.0s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 22m07s across 30 shards
- **Lines:** 30,712/38,791 matching (79.2%)
- **Avg test duration:** 5.4s — slowest: `MovieClip-v8` (72.8s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 19m01s across 30 shards
- **Lines:** 4,236/5,248 matching (80.7%)
- **Avg test duration:** 10.2s — slowest: `matrix_test` (98.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 23s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 2.6s — slowest: `levels` (4.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 2m41s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 8.0s — slowest: `movieclip_destruction_test3` (24.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 1m19s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 3.9s — slowest: `mixed-bytecode-as2` (23.5s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 39m16s across 30 shards
- **Lines:** 2,396/2,484 matching (96.5%)
- **Avg test duration:** 10.2s — slowest: `esc` (63.0s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m25s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `hitarea` (22.8s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 45s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.9s — slowest: `avm1_non_swf_import` (22.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.8s — slowest: `avm2_loads_avm1_v9` (9.7s)

### regression

- **Pass:** 104/104 (100%)
- **Duration:** 13m15s across 30 shards
- **Lines:** 871/871 matching (100%)
- **Avg test duration:** 7.6s — slowest: `avm2_timeline_solid` (32.1s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m04s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.2s — slowest: `unbound_texture_multiple` (12.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 15s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 2.0s — slowest: `convolution_filter_big_matrix` (2.5s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m35s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 19.5s — slowest: `auto_size/height` (31.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 2m32s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 8.9s — slowest: `frame_script_button_order` (25.5s)

### visual

- **Pass:** 147/149 (98.7%)
- **Duration:** 31m31s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.7s — slowest: `simple_shapes/heavy_tesselation` (70.3s)
