# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `aaf953dff9e1`  
**Date:** 2026-10-17 16:50 UTC  
**Total duration:** 10h54m01s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 710 | 744 | 95.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1233 | 1292 | 95.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
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
| regression | 103 | 103 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4297** | **4610** | **93.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 124,520 | 135,776 | 91.7% |
| avm2 | 156,379 | 158,909 | 98.4% |
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
| regression | 866 | 866 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **408,259** | **431,957** | **94.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 2 |
| avm1 | 14 |
| avm2 | 17 |
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
| **Total** | **60** |

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
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `38cf9b1a0ab8` → `aaf953dff9e1`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.6s — slowest: `stream_incomplete_loop` (23.0s)

### avm1

- **Pass:** 710/744 (95.4%)
- **Duration:** 52m07s across 30 shards
- **Lines:** 124,520/135,776 matching (91.7%)
- **Avg test duration:** 4.1s — slowest: `netstream_play_flv_screen` (39.4s)

### avm2

- **Pass:** 1233/1292 (95.4%)
- **Duration:** 3h33m37s across 30 shards
- **Lines:** 156,379/158,909 matching (98.4%)
- **Avg test duration:** 9.9s — slowest: `away3d_advanced_shallow_water_demo` (113.2s)

### fonts

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m10s across 30 shards
- **Lines:** 351/377 matching (93.1%)
- **Avg test duration:** 21.1s — slowest: `embed_matching/fallback_preferences` (33.2s)

### from_avmplus

- **Pass:** 1531/1574 (97.3%)
- **Duration:** 3h40m36s across 30 shards
- **Lines:** 85,562/85,996 matching (99.5%)
- **Avg test duration:** 8.3s — slowest: `ecma3/Statements/eregress_74474_003` (49.4s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 22m33s across 30 shards
- **Lines:** 30,712/38,791 matching (79.2%)
- **Avg test duration:** 5.5s — slowest: `MovieClip-v8` (52.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 23m04s across 30 shards
- **Lines:** 4,236/5,248 matching (80.7%)
- **Avg test duration:** 12.4s — slowest: `matrix_test` (111.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 8.9s — slowest: `implementsOpTest` (23.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 3m40s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 10.9s — slowest: `movieclip_destruction_test1` (24.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m22s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 7.1s — slowest: `background` (22.4s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 45m19s across 30 shards
- **Lines:** 2,396/2,484 matching (96.5%)
- **Avg test duration:** 11.8s — slowest: `acid/acid-large` (79.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (22.3s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 46s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.1s — slowest: `avm1_non_swf_import` (21.7s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.3s — slowest: `avm2_loads_avm1` (9.6s)

### regression

- **Pass:** 103/103 (100%)
- **Duration:** 14m04s across 30 shards
- **Lines:** 866/866 matching (100%)
- **Avg test duration:** 8.1s — slowest: `avm2_parent_child_symbol_stride` (31.1s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 11.6s — slowest: `unbound_texture` (12.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 37s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 5.2s — slowest: `convolution_filter_big_matrix` (23.4s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m42s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 20.2s — slowest: `auto_size/height` (35.7s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m46s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 16.8s — slowest: `swf_9_event_goto_frame_script` (30.7s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 35m56s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.6s — slowest: `definefont4` (78.8s)
