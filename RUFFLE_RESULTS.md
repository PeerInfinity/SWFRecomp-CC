# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9d038c750eaf`  
**Date:** 2026-08-19 13:28 UTC  
**Total duration:** 9h59m27s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 689 | 725 | 95.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1179 | 1251 | 94.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
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
| visual | 142 | 144 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4165** | **4510** | **92.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 119,938 | 131,334 | 91.3% |
| avm2 | 151,316 | 154,806 | 97.7% |
| fonts | 104 | 104 | 100% |
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
| **Total** | **397,236** | **422,730** | **94.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 18 | - |
| avm2 | 39 | - |
| fonts | - | - |
| from_avmplus | 5 | 1 |
| from_gnash/actionscript.all | 13 | - |
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
| **Total** | **103** | **1** |

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

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 8 | - | 335 | - |
| avm2 | 28 | - | 9118 | 4 |
| from_avmplus | 12 | - | 16 | - |
| from_gnash/actionscript.all | 3 | - | 26 | - |
| from_gnash/misc-ming.all | - | - | 4 | - |
| from_shumway | 2 | - | 132 | - |

**avm1 — newly passing:** `looping_child_swf32`, `looping_child_swf5`, `looping_child_swf9`, `shared_stack`, `sound_load_multiple_remote`, `sound_load_props`, `sound_load_start_remote`, `sound_load_streaming_stop_remote`

**avm2 — newly passing:** `all_classes/events/swf10`, `all_classes/events/swf11`, `all_classes/events/swf12`, `all_classes/events/swf30`, `all_classes/events/swf9`, `appdomain_lookup_edge_cases`, `automation_classes`, `button_nested_frame_simple`, `coerce_string_precision`, `displayobject_early_init`, `displayobject_hittestpoint_boundary`, `displayobject_scrollrect`, `displayobject_transform`, `divide`, `large_preload_from_url`, `large_preload_image_from_bytes`, `matrix3d_append_prepend_translation`, `matrix3d_constructor_clone`, `matrix3d_determinant`, `matrix3d_precision`, `matrix3d_raw_data`, `method_association`, `mouse_pick_avm1_root`, `native_menu_basic`, `scope_optimizations`, `supercalls_coerce`, `textfield_input_events`

**avm2 — newly failing:** `getouterscope_two_classobjects`

**from_avmplus — newly passing:** `as3/Expressions/asOperator/asOper`, `ecma3/Array/e15_4_4_5`, `ecma3/Array/toLocaleString`, `ecma3/Number/e15_7_1`, `ecma3/Number/e15_7_2`, `ecma3/Number/e15_7_4_2_4`, `ecma3/Number/toLocaleString_rt`, `ecma3/Number/tostring_001`, `ecma3/String/e15_5_1`, `ecma3/String/e15_5_2`, `ecma3/TypeConversion/e9_8_1`, `ecma3/Types/e8_5`

**from_gnash/actionscript.all — newly passing:** `Sound-v6`, `Sound-v7`, `Sound-v8`

**from_shumway — newly passing:** `acid/acid-shapes`, `as3-loader/loaderinfo/loaded-content-properties`

*Comparing `88ebde66534f` → `9d038c750eaf`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.5s — slowest: `g711_event_alaw` (21.6s)

### avm1

- **Pass:** 689/725 (95.0%)
- **Duration:** 52m12s across 30 shards
- **Lines:** 119,938/131,334 matching (91.3%)
- **Avg test duration:** 4.3s — slowest: `netstream_play_flv_screen` (36.4s)

### avm2

- **Pass:** 1179/1251 (94.2%)
- **Duration:** 3h18m06s across 30 shards
- **Lines:** 151,316/154,806 matching (97.7%)
- **Avg test duration:** 9.4s — slowest: `away3d_advanced_shallow_water_demo` (88.9s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 1m59s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 19.9s — slowest: `embed_matching/fallback_preferences` (28.5s)

### from_avmplus

- **Pass:** 1527/1574 (97.0%)
- **Duration:** 3h00m13s across 30 shards
- **Lines:** 85,434/85,996 matching (99.3%)
- **Avg test duration:** 6.8s — slowest: `ecma3/Statements/eregress_74474_003` (55.9s)

### from_gnash/actionscript.all

- **Pass:** 138/243 (56.8%)
- **Duration:** 21m19s across 30 shards
- **Lines:** 30,386/38,791 matching (78.3%)
- **Avg test duration:** 5.2s — slowest: `MovieClip-v8` (64.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 30m25s across 30 shards
- **Lines:** 4,058/5,248 matching (77.3%)
- **Avg test duration:** 16.4s — slowest: `matrix_test` (109.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m07s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 20.8s — slowest: `levels` (23.6s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m23s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 16.1s — slowest: `movieclip_destruction_test1` (22.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m24s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.1s — slowest: `trace-as2/shortstack` (21.7s)

### from_shumway

- **Pass:** 212/229 (92.6%)
- **Duration:** 40m55s across 30 shards
- **Lines:** 2,323/2,484 matching (93.5%)
- **Avg test duration:** 10.7s — slowest: `acid/acid-large` (77.2s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.5s — slowest: `hitarea` (21.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 46s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.3s — slowest: `avm1_non_swf_import` (22.6s)

### mixed_avm

- **Pass:** 10/11 (90.9%)
- **Duration:** 53s across 30 shards
- **Lines:** 49/53 matching (92.5%)
- **Avg test duration:** 4.8s — slowest: `avm2_loads_avm1_doabc` (7.5s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 15m48s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 13.1s — slowest: `avm2_timeline_gradients` (46.4s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.5s — slowest: `sampler_odd_size` (10.0s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 45s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 6.4s — slowest: `lzma_length_too_long` (21.9s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m30s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 19.0s — slowest: `text_caret_placement_align` (28.7s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 3m03s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 10.7s — slowest: `frame_script_button_order` (28.1s)

### visual

- **Pass:** 142/144 (98.6%)
- **Duration:** 30m35s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.7s — slowest: `simple_shapes/heavy_tesselation` (71.3s)
