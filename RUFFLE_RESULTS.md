# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `06f3d87d295b`  
**Date:** 2026-08-30 08:49 UTC  
**Total duration:** 9h31m01s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 689 | 726 | 94.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1180 | 1259 | 93.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
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
| mixed_avm | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 144 | 146 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4168** | **4522** | **92.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 119,976 | 131,434 | 91.3% |
| avm2 | 151,402 | 154,963 | 97.7% |
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
| mixed_avm | 49 | 53 | 92.5% |
| regression | 483 | 483 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **397,446** | **423,229** | **93.9%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 19 | - |
| avm2 | 46 | - |
| fonts | 1 | - |
| from_avmplus | 5 | 1 |
| from_gnash/actionscript.all | 16 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 5 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 2 | - |
| visual | - | - |
| **Total** | **115** | **1** |

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

## Changes Since Last Run

*No changes since last run.*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.3s — slowest: `stream_incomplete_loop` (22.0s)

### avm1

- **Pass:** 689/726 (94.9%)
- **Duration:** 51m14s across 30 shards
- **Lines:** 119,976/131,434 matching (91.3%)
- **Avg test duration:** 4.2s — slowest: `netstream_play_flv_screen` (36.3s)

### avm2

- **Pass:** 1180/1259 (93.7%)
- **Duration:** 3h02m10s across 30 shards
- **Lines:** 151,402/154,963 matching (97.7%)
- **Avg test duration:** 8.6s — slowest: `away3d_advanced_shallow_water_demo` (86.3s)

### fonts

- **Pass:** 6/7 (85.7%)
- **Duration:** 2m17s across 30 shards
- **Lines:** 190/346 matching (54.9%)
- **Avg test duration:** 19.5s — slowest: `embed_matching/fallback_preferences` (27.4s)

### from_avmplus

- **Pass:** 1527/1574 (97.0%)
- **Duration:** 2h54m11s across 30 shards
- **Lines:** 85,434/85,996 matching (99.3%)
- **Avg test duration:** 6.6s — slowest: `ecma3/Statements/eregress_74474_003` (66.6s)

### from_gnash/actionscript.all

- **Pass:** 138/243 (56.8%)
- **Duration:** 21m02s across 30 shards
- **Lines:** 30,386/38,791 matching (78.3%)
- **Avg test duration:** 5.1s — slowest: `MovieClip-v8` (65.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 28m59s across 30 shards
- **Lines:** 4,058/5,248 matching (77.3%)
- **Avg test duration:** 15.6s — slowest: `matrix_test` (89.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m01s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 20.1s — slowest: `levels` (22.6s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m27s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 16.3s — slowest: `movieclip_destruction_test3` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m28s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.4s — slowest: `dict_event` (21.9s)

### from_shumway

- **Pass:** 212/229 (92.6%)
- **Duration:** 38m42s across 30 shards
- **Lines:** 2,323/2,484 matching (93.5%)
- **Avg test duration:** 10.1s — slowest: `acid/acid-large` (78.2s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.3s — slowest: `hitarea` (20.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 45s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.8s — slowest: `avm1_non_swf_import` (22.0s)

### mixed_avm

- **Pass:** 10/11 (90.9%)
- **Duration:** 48s across 30 shards
- **Lines:** 49/53 matching (92.5%)
- **Avg test duration:** 4.3s — slowest: `avm2_loads_avm1_v9` (7.5s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 13m01s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 10.8s — slowest: `avm2_graphics_runtime` (28.2s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.5s — slowest: `scissor_rectangle_invalid` (10.0s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 45s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 6.4s — slowest: `lzma_length_too_long` (21.4s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m21s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.3s — slowest: `auto_size/return` (27.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 3m12s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 11.3s — slowest: `frame_script_button_order` (27.5s)

### visual

- **Pass:** 144/146 (98.6%)
- **Duration:** 31m42s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.0s — slowest: `definefont4` (95.8s)
