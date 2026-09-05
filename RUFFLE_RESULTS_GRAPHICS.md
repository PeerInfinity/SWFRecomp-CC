# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `12d2ec06b7bf`  
**Date:** 2026-09-05 05:20 UTC  
**Total duration:** 12h26m53s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 691 | 730 | 94.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1198 | 1261 | 95.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 7 | 85.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
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
| regression | 89 | 89 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 144 | 146 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4215** | **4548** | **92.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 119,995 | 131,487 | 91.3% |
| avm2 | 152,158 | 155,033 | 98.1% |
| fonts | 190 | 346 | 54.9% |
| from_avmplus | 85,558 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,418 | 38,791 | 78.4% |
| from_gnash/misc-ming.all | 4,058 | 5,248 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,321 | 2,484 | 93.4% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 56 | 79 | 70.9% |
| regression | 681 | 681 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **398,604** | **423,576** | **94.1%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 21 | - |
| avm2 | 27 | - |
| fonts | 1 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 5 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 1 | - |
| visual | - | - |
| **Total** | **93** | **1** |

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
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
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
| from_gnash/actionscript.all | 1 | - | 3 | 3 |

*Comparing `cdafe1be9c22` → `12d2ec06b7bf`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.5s — slowest: `stream_incomplete_loop` (21.1s)

### avm1

- **Pass:** 691/730 (94.7%)
- **Duration:** 1h24m21s across 30 shards
- **Lines:** 119,995/131,487 matching (91.3%)
- **Avg test duration:** 6.9s — slowest: `strictequals_swf6` (39.9s)

### avm2

- **Pass:** 1198/1261 (95.0%)
- **Duration:** 3h57m07s across 30 shards
- **Lines:** 152,158/155,033 matching (98.1%)
- **Avg test duration:** 11.2s — slowest: `away3d_advanced_shallow_water_demo` (70.0s)

### fonts

- **Pass:** 6/7 (85.7%)
- **Duration:** 2m25s across 30 shards
- **Lines:** 190/346 matching (54.9%)
- **Avg test duration:** 20.8s — slowest: `device_font_kerning` (29.9s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h33m15s across 30 shards
- **Lines:** 85,558/85,996 matching (99.5%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_002` (54.9s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 33m02s across 30 shards
- **Lines:** 30,418/38,791 matching (78.4%)
- **Avg test duration:** 8.1s — slowest: `MovieClip-v8` (60.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 35m32s across 30 shards
- **Lines:** 4,058/5,248 matching (77.3%)
- **Avg test duration:** 19.2s — slowest: `matrix_test` (111.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m38s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 10.9s — slowest: `implementsOpTest` (23.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m02s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 18.0s — slowest: `edittext_test1` (24.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m53s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.6s — slowest: `background` (23.1s)

### from_shumway

- **Pass:** 213/229 (93.0%)
- **Duration:** 48m36s across 30 shards
- **Lines:** 2,321/2,484 matching (93.4%)
- **Avg test duration:** 12.7s — slowest: `acid/acid-large` (73.5s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 3m14s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 4.1s — slowest: `hitarea` (22.3s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.3s — slowest: `avm1_non_swf_import` (23.2s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 56/79 matching (70.9%)
- **Avg test duration:** 7.7s — slowest: `avm1_sprite_sc_ignored` (21.3s)

### regression

- **Pass:** 89/89 (100%)
- **Duration:** 23m41s across 30 shards
- **Lines:** 681/681 matching (100%)
- **Avg test duration:** 15.9s — slowest: `avm2_timeline_solid` (36.0s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.5s — slowest: `unbound_texture` (11.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 54s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 7.6s — slowest: `lzma_length_too_long` (22.3s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m46s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.5s — slowest: `auto_size/return` (33.4s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 6m11s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 21.8s — slowest: `frame_script_cleanup3` (29.4s)

### visual

- **Pass:** 144/146 (98.6%)
- **Duration:** 35m29s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.5s — slowest: `definefont4` (93.4s)
