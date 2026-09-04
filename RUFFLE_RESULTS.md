# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `646796612ea6`  
**Date:** 2026-09-04 16:45 UTC  
**Total duration:** 9h24m29s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 689 | 730 | 94.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1180 | 1261 | 93.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 7 | 85.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1527 | 1574 | 97.0% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 138 | 243 | 56.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 212 | 229 | 92.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 88 | 88 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 144 | 146 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4184** | **4545** | **92.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 119,983 | 131,487 | 91.3% |
| avm2 | 151,384 | 155,033 | 97.6% |
| fonts | 190 | 346 | 54.9% |
| from_avmplus | 85,434 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,386 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,058 | 5,248 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,323 | 2,484 | 93.5% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 56 | 79 | 70.9% |
| regression | 678 | 678 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **397,637** | **423,573** | **93.9%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 23 | - |
| avm2 | 48 | - |
| fonts | 1 | - |
| from_avmplus | 5 | 1 |
| from_gnash/actionscript.all | 16 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 6 | - |
| from_shumway/avm1 | 1 | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 2 | - |
| visual | - | - |
| **Total** | **124** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | Function-v7 | 97% |
| from_gnash/actionscript.all | Function-v8 | 97% |
| from_gnash/actionscript.all | Function-v6 | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| avm2 | vector3d_near_equals | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | large_preload_from_bytes | 80% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `027418adc476` → `646796612ea6`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.7s — slowest: `g711_event_mulaw` (21.2s)

### avm1

- **Pass:** 689/730 (94.4%)
- **Duration:** 49m45s across 30 shards
- **Lines:** 119,983/131,487 matching (91.3%)
- **Avg test duration:** 4.0s — slowest: `movieclip_invalid_get_bounds_7` (28.0s)

### avm2

- **Pass:** 1180/1261 (93.6%)
- **Duration:** 2h57m34s across 30 shards
- **Lines:** 151,384/155,033 matching (97.6%)
- **Avg test duration:** 8.4s — slowest: `away3d_advanced_shallow_water_demo` (62.8s)

### fonts

- **Pass:** 6/7 (85.7%)
- **Duration:** 2m16s across 30 shards
- **Lines:** 190/346 matching (54.9%)
- **Avg test duration:** 19.4s — slowest: `embed_matching/fallback_preferences` (29.2s)

### from_avmplus

- **Pass:** 1527/1574 (97.0%)
- **Duration:** 2h56m27s across 30 shards
- **Lines:** 85,434/85,996 matching (99.3%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_002` (68.1s)

### from_gnash/actionscript.all

- **Pass:** 138/243 (56.8%)
- **Duration:** 20m44s across 30 shards
- **Lines:** 30,386/38,791 matching (78.3%)
- **Avg test duration:** 5.1s — slowest: `MovieClip-v8` (57.4s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 27m43s across 30 shards
- **Lines:** 4,058/5,248 matching (77.3%)
- **Avg test duration:** 14.9s — slowest: `matrix_test` (90.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m32s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 10.2s — slowest: `function_test` (22.2s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m21s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 16.0s — slowest: `edittext_test1` (22.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m32s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.6s — slowest: `trace-as2/root_onload` (22.0s)

### from_shumway

- **Pass:** 212/229 (92.6%)
- **Duration:** 38m30s across 30 shards
- **Lines:** 2,323/2,484 matching (93.5%)
- **Avg test duration:** 10.0s — slowest: `acid/acid-large` (62.4s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.4s — slowest: `hitarea` (20.7s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 38s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 12.6s — slowest: `avm1_non_swf_import` (20.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m01s across 30 shards
- **Lines:** 56/79 matching (70.9%)
- **Avg test duration:** 5.1s — slowest: `avm2_loads_avm1_events` (7.7s)

### regression

- **Pass:** 88/88 (100%)
- **Duration:** 14m55s across 30 shards
- **Lines:** 678/678 matching (100%)
- **Avg test duration:** 10.1s — slowest: `avm2_timeline_gradients` (27.8s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 39s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 7.7s — slowest: `scissor_rectangle` (9.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 30s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 4.2s — slowest: `convolution_filter_big_matrix` (21.8s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m27s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.8s — slowest: `auto_size/height` (28.4s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 2m40s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 9.4s — slowest: `swf_9_frame_script_button_order` (28.8s)

### visual

- **Pass:** 144/146 (98.6%)
- **Duration:** 31m06s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.7s — slowest: `definefont4` (88.1s)
