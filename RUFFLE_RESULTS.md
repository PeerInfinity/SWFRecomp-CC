# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9561027db32b`  
**Date:** 2026-11-22 07:25 UTC  
**Total duration:** 9h13m36s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 742 | 780 | 95.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1281 | 1336 | 95.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 13 | 20 | 65.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 114 | 114 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4400** | **4707** | **93.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 124,998 | 137,572 | 90.9% |
| avm2 | 161,523 | 163,949 | 98.5% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,657 | 38,791 | 79.0% |
| from_gnash/misc-ming.all | 4,252 | 5,248 | 81.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 486 | 580 | 83.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,050 | 1,050 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **414,127** | **438,991** | **94.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 16 |
| avm2 | 10 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 6 |
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
| **Total** | **49** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| avm1 | text_format_prototype_lazy | 91% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | 1 | - | 17 | - |

*Comparing `9a970370e096` → `9561027db32b`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 14.7s — slowest: `g711_event_mulaw` (22.8s)

### avm1

- **Pass:** 742/780 (95.1%)
- **Duration:** 53m10s across 30 shards
- **Lines:** 124,998/137,572 matching (90.9%)
- **Avg test duration:** 4.1s — slowest: `netstream_play_flv_screen` (38.0s)

### avm2

- **Pass:** 1281/1336 (95.9%)
- **Duration:** 3h02m42s across 30 shards
- **Lines:** 161,523/163,949 matching (98.5%)
- **Avg test duration:** 8.2s — slowest: `away3d_advanced_shallow_water_demo` (75.2s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m33s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.0s — slowest: `device_font_kerning` (28.8s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 2h45m00s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 6.3s — slowest: `ecma3/Statements/eregress_74474_002` (65.6s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 19m51s across 30 shards
- **Lines:** 30,657/38,791 matching (79.0%)
- **Avg test duration:** 4.9s — slowest: `MovieClip-v8` (52.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 21m28s across 30 shards
- **Lines:** 4,252/5,248 matching (81.0%)
- **Avg test duration:** 11.6s — slowest: `matrix_test` (79.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.7s — slowest: `function_test` (23.5s)

### from_gnash/misc-swfc.all

- **Pass:** 13/20 (65.0%)
- **Duration:** 4m26s across 30 shards
- **Lines:** 486/580 matching (83.8%)
- **Avg test duration:** 13.3s — slowest: `edittext_test1` (24.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 3m39s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 10.9s — slowest: `dict_cross` (23.5s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 39m14s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 10.2s — slowest: `acid/acid-large` (64.0s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m36s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.0s — slowest: `text-bind` (17.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 42s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.8s — slowest: `avm1_non_swf_import` (22.8s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.2s — slowest: `avm1_sprite_sc_ignored` (22.9s)

### regression

- **Pass:** 114/114 (100%)
- **Duration:** 14m38s across 30 shards
- **Lines:** 1,050/1,050 matching (100%)
- **Avg test duration:** 7.7s — slowest: `avm2_parent_child_symbol_stride` (28.8s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.4s — slowest: `draw_to_bitmap_data_unconfigured` (27.1s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m04s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.2s — slowest: `lzma_length_too_long` (22.2s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m17s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 16.4s — slowest: `text_caret_placement_scroll` (30.0s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m18s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 18.7s — slowest: `frame_script_cleanup` (30.6s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 29m14s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.6s — slowest: `definefont4` (107.5s)
