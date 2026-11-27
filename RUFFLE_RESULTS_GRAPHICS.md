# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `6ee6eded7b66`  
**Date:** 2026-11-27 01:51 UTC  
**Total duration:** 13h23m40s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 773 | 791 | 97.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1316 | 1352 | 97.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1564 | 1574 | 99.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 177 | 243 | 72.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 73 | 111 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 15 | 21 | 71.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 301 | 302 | 99.7% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4722** | **4923** | **95.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,757 | 137,880 | 91.2% |
| avm2 | 163,035 | 164,470 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,953 | 85,996 | 99.9% |
| from_gnash/actionscript.all | 31,095 | 38,791 | 80.2% |
| from_gnash/misc-ming.all | 4,359 | 5,248 | 83.1% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 529 | 603 | 87.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,067 | 3,069 | 99.9% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **419,414** | **441,862** | **94.9%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 10 |
| avm2 | 6 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 1 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 2 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | 1 |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **35** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | loader_load | 98% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 2 | - | 22 | - |
| avm2 | 2 | - | 231 | 5 |
| from_avmplus | - | - | 335 | - |
| from_shumway | - | 1 | - | 1 |

**avm1 — newly passing:** `globals_swf5`, `native_objects_swf6`

**avm2 — newly passing:** `dependent_strings`, `edittext_getcharboundaries_culling`, `event_handler_exception`, `freestanding_superclass`, `loader_applicationDomain`, `weird_superinterface_properties`

**from_avmplus — newly passing:** `ecma3/Date/e15_9_5_10`, `ecma3/Date/e15_9_5_10_1`, `ecma3/Date/e15_9_5_10_10`, `ecma3/Date/e15_9_5_10_11`, `ecma3/Date/e15_9_5_11`, `ecma3/Date/e15_9_5_12`, `ecma3/Date/e15_9_5_12_1`, `ecma3/Date/e15_9_5_13`, `ecma3/Date/e15_9_5_15_1`, `ecma3/Date/e15_9_5_17_1`, `ecma3/Date/e15_9_5_22_1`, `ecma3/Date/e15_9_5_28_1`, `ecma3/Date/e15_9_5_29_1`, `ecma3/Date/e15_9_5_35_1`, `ecma3/Date/e15_9_5_4`

**from_shumway — newly failing:** `as3-loader/bug1157243/empty`

*Comparing `574824001e94` → `6ee6eded7b66`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 23.7s — slowest: `g711` (33.2s)

### avm1

- **Pass:** 773/791 (97.7%)
- **Duration:** 1h27m10s across 30 shards
- **Lines:** 125,757/137,880 matching (91.2%)
- **Avg test duration:** 6.6s — slowest: `define_font_glyph_table_order` (45.1s)

### avm2

- **Pass:** 1316/1352 (97.3%)
- **Duration:** 4h17m37s across 30 shards
- **Lines:** 163,035/164,470 matching (99.1%)
- **Avg test duration:** 11.4s — slowest: `away3d_advanced_shallow_water_demo` (82.2s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m55s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.4s — slowest: `device_font_kerning` (34.5s)

### from_avmplus

- **Pass:** 1564/1574 (99.4%)
- **Duration:** 3h26m09s across 30 shards
- **Lines:** 85,953/85,996 matching (99.9%)
- **Avg test duration:** 7.8s — slowest: `ecma3/Statements/eregress_74474_003` (56.5s)

### from_gnash/actionscript.all

- **Pass:** 177/243 (72.8%)
- **Duration:** 30m44s across 30 shards
- **Lines:** 31,095/38,791 matching (80.2%)
- **Avg test duration:** 7.6s — slowest: `MovieClip-v8` (58.0s)

### from_gnash/misc-ming.all

- **Pass:** 73/111 (65.8%)
- **Duration:** 34m43s across 30 shards
- **Lines:** 4,359/5,248 matching (83.1%)
- **Avg test duration:** 18.7s — slowest: `matrix_test` (101.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.8s — slowest: `function_test` (26.3s)

### from_gnash/misc-swfc.all

- **Pass:** 15/21 (71.4%)
- **Duration:** 5m13s across 30 shards
- **Lines:** 529/603 matching (87.7%)
- **Avg test duration:** 14.9s — slowest: `edittext_test1` (28.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m40s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.0s — slowest: `trace-as2/root_onload` (26.2s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 47m11s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 12.3s — slowest: `acid/acid-large` (71.0s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m30s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.2s — slowest: `hitarea` (25.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 49s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.4s — slowest: `avm1_non_swf_import` (26.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m39s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 8.3s — slowest: `avm1_sprite_sc_ignored` (26.1s)

### regression

- **Pass:** 301/302 (99.7%)
- **Duration:** 1h06m58s across 30 shards
- **Lines:** 3,067/3,069 matching (99.9%)
- **Avg test duration:** 13.3s — slowest: `avm2_group_alpha_shadow_shape_a50` (46.4s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m38s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 12.2s — slowest: `draw_to_bitmap_data_unconfigured` (20.2s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 13.3s — slowest: `swf_length_too_long` (25.9s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m59s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 19.9s — slowest: `auto_size/return` (40.6s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m37s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 23.3s — slowest: `missing_frame_scripts` (34.7s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 35m34s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.1s — slowest: `definefont4` (84.4s)
