# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `fb36ba11005c`  
**Date:** 2026-08-06 23:55 UTC  
**Total duration:** 12h12m33s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 674 | 718 | 93.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1109 | 1226 | 90.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1514 | 1574 | 96.2% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 189 | 229 | 82.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 2 | 3 | 66.7% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 71 | 71 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 140 | 143 | 97.9% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4030** | **4474** | **90.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,632 | 131,178 | 88.9% |
| avm2 | 121,771 | 152,155 | 80.0% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,415 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,359 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,789 | 2,484 | 72.0% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 8 | 14 | 57.1% |
| mixed_avm | 26 | 53 | 49.1% |
| regression | 482 | 482 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **363,740** | **419,885** | **86.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 26 | - |
| avm2 | 87 | - |
| fonts | - | - |
| from_avmplus | 5 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 26 | - |
| from_shumway/avm1 | - | - |
| import_assets | 1 | - |
| mixed_avm | 7 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 2 | - |
| visual | 1 | - |
| **Total** | **189** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| avm2 | bounds_mode | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| mixed_avm | avm2_loads_avm1_v9 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | number_convert_edge_cases | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 14 | - |
| avm2 | 4 | - | 1627 | - |
| from_avmplus | 1 | - | 5 | - |
| from_gnash/misc-ming.all | 1 | - | - | - |
| import_assets | 1 | - | 6 | - |

**avm1 — newly passing:** `remove_different_level`

**avm2 — newly passing:** `describe_type_basic`, `describe_type_json`, `error_stack_trace`, `loaderinfo_quine`

**import_assets — newly passing:** `avm1_non_swf_import`

*Comparing `1f8396f5799f` → `fb36ba11005c`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m19s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.9s — slowest: `g711_event_mulaw` (21.2s)

### avm1

- **Pass:** 674/718 (93.9%)
- **Duration:** 1h39m42s across 30 shards
- **Lines:** 116,632/131,178 matching (88.9%)
- **Avg test duration:** 8.3s — slowest: `movieclip_invalid_get_bounds_6` (67.5s)

### avm2

- **Pass:** 1109/1226 (90.5%)
- **Duration:** 3h40m48s across 30 shards
- **Lines:** 121,771/152,155 matching (80.0%)
- **Avg test duration:** 10.7s — slowest: `away3d_advanced_shallow_water_demo` (85.7s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 20.9s — slowest: `embed_matching/fallback_preferences` (30.1s)

### from_avmplus

- **Pass:** 1514/1574 (96.2%)
- **Duration:** 3h20m15s across 30 shards
- **Lines:** 85,415/85,996 matching (99.3%)
- **Avg test duration:** 7.6s — slowest: `ecma3/Statements/eregress_74474_003` (55.1s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 39m33s across 30 shards
- **Lines:** 30,359/38,791 matching (78.3%)
- **Avg test duration:** 9.7s — slowest: `MovieClip-v8` (66.1s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 36m46s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 19.8s — slowest: `matrix_test` (105.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m10s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.1s — slowest: `TextFieldTest` (22.2s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m20s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 19.0s — slowest: `swf4opcode` (23.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m58s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.9s — slowest: `missing_bitmap` (23.7s)

### from_shumway

- **Pass:** 189/229 (82.5%)
- **Duration:** 47m53s across 30 shards
- **Lines:** 1,789/2,484 matching (72.0%)
- **Avg test duration:** 12.5s — slowest: `acid/acid-large` (74.7s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m16s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `label` (21.2s)

### import_assets

- **Pass:** 2/3 (66.7%)
- **Duration:** 46s across 30 shards
- **Lines:** 8/14 matching (57.1%)
- **Avg test duration:** 15.2s — slowest: `avm1_non_swf_import` (21.8s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 26/53 matching (49.1%)
- **Avg test duration:** 7.3s — slowest: `avm1_sprite_sc_ignored` (21.2s)

### regression

- **Pass:** 71/71 (100%)
- **Duration:** 19m22s across 30 shards
- **Lines:** 482/482 matching (100%)
- **Avg test duration:** 16.3s — slowest: `avm2_graphics_runtime` (42.4s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.3s — slowest: `scissor_rectangle` (10.6s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 49s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 9.8s — slowest: `convolution_filter_big_matrix` (21.4s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m40s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.0s — slowest: `auto_size/height` (29.7s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.2s — slowest: `frame_script_cleanup` (27.7s)

### visual

- **Pass:** 140/143 (97.9%)
- **Duration:** 32m34s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.6s — slowest: `definefont4` (95.0s)
