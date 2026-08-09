# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `0a99be1a92de`  
**Date:** 2026-08-09 08:51 UTC  
**Total duration:** 10h43m19s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 674 | 718 | 93.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1109 | 1227 | 90.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1514 | 1574 | 96.2% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 189 | 229 | 82.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 2 | 3 | 66.7% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 71 | 71 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 140 | 143 | 97.9% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4030** | **4475** | **90.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,632 | 131,178 | 88.9% |
| avm2 | 121,772 | 152,277 | 80.0% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,415 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,359 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
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
| **Total** | **363,745** | **420,007** | **86.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 26 | - |
| avm2 | 88 | - |
| fonts | - | - |
| from_avmplus | 5 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
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
| avm1 | 2 | - | 1 | - |
| avm2 | 27 | - | 3036 | 11 |
| fonts | 3 | - | 69 | - |
| from_avmplus | 5 | - | 24 | - |
| from_gnash/misc-ming.all | 1 | - | - | - |
| from_shumway | 3 | - | 7 | - |
| import_assets | 1 | - | 6 | - |
| mixed_avm | - | - | 7 | - |
| text | 1 | - | 114 | - |
| visual | 4 | - | 49 | - |

**avm1 — newly passing:** `load_cancel_via_removemovieclip`, `remove_different_level`

**avm2 — newly passing:** `constructsuper_null`, `cross_api_version_call_newer`, `currency_parse_result`, `describe_type_basic`, `describe_type_json`, `doabc_and_symbolclass_script_init_goto`, `doabc_and_symbolclass_script_init_normal`, `error_stack_trace`, `error_stack_trace_edge_cases`, `error_throwerror`, `graphic_linkage`, `json_stringify_function`, `loaderinfo_quine`, `netfilterevent`, `perspective_projection`, `primitive_toString`, `primitive_valueOf`, `property_is_enumerable`, `proxy_not_overridden`, `stage_properties2`, `static_length`, `system_exit`, `timer_invalid_delay`, `xml_list_ctor_errors`

**fonts — newly passing:** `device_font_glyph_fallback`, `device_font_kerning`, `device_font_list`

**from_avmplus — newly passing:** `as3/String/localeCompare_585791/v9`, `ecma3/Expressions/e11_6_1_3`, `ecma3/String/e15_5_4_8_2`, `regress/bug_550958`

**from_shumway — newly passing:** `as3-loader/bug1157243/empty`, `as3-loader/bug1157243/invalid`, `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`

**import_assets — newly passing:** `avm1_non_swf_import`

**text — newly passing:** `html_entity_parsing`

**visual — newly passing:** `define_bits_jpeg2_huge`, `edittext/edittext_device_transform_basic`

*Comparing `b4c983ea4c3d` → `0a99be1a92de`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.7s — slowest: `stream_incomplete_loop` (19.9s)

### avm1

- **Pass:** 674/718 (93.9%)
- **Duration:** 1h21m36s across 30 shards
- **Lines:** 116,632/131,178 matching (88.9%)
- **Avg test duration:** 6.8s — slowest: `define_font_glyph_table_order` (42.0s)

### avm2

- **Pass:** 1109/1227 (90.4%)
- **Duration:** 3h16m15s across 30 shards
- **Lines:** 121,772/152,277 matching (80.0%)
- **Avg test duration:** 9.5s — slowest: `away3d_advanced_shallow_water_demo` (83.7s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 1m57s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 19.6s — slowest: `embed_matching/fallback_preferences` (27.1s)

### from_avmplus

- **Pass:** 1514/1574 (96.2%)
- **Duration:** 2h51m01s across 30 shards
- **Lines:** 85,415/85,996 matching (99.3%)
- **Avg test duration:** 6.5s — slowest: `ecma3/Statements/eregress_74474_002` (57.0s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 36m17s across 30 shards
- **Lines:** 30,359/38,791 matching (78.3%)
- **Avg test duration:** 8.9s — slowest: `MovieClip-v8` (67.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 35m02s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 18.9s — slowest: `matrix_test` (107.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m06s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 20.6s — slowest: `levels` (23.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m45s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.2s — slowest: `swf4opcode` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m28s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.3s — slowest: `initaction_in_definesprite` (21.3s)

### from_shumway

- **Pass:** 189/229 (82.5%)
- **Duration:** 43m21s across 30 shards
- **Lines:** 1,789/2,484 matching (72.0%)
- **Avg test duration:** 11.3s — slowest: `acid/acid-large` (76.0s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m40s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.1s — slowest: `label` (20.8s)

### import_assets

- **Pass:** 2/3 (66.7%)
- **Duration:** 44s across 30 shards
- **Lines:** 8/14 matching (57.1%)
- **Avg test duration:** 14.5s — slowest: `avm1_non_swf_import` (21.4s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 26/53 matching (49.1%)
- **Avg test duration:** 6.2s — slowest: `avm1_sprite_sc_ignored` (19.8s)

### regression

- **Pass:** 71/71 (100%)
- **Duration:** 18m11s across 30 shards
- **Lines:** 482/482 matching (100%)
- **Avg test duration:** 15.3s — slowest: `avm2_timeline_gradients` (43.1s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.0s — slowest: `sampler_odd_size` (9.0s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 44s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 8.8s — slowest: `swf_length_too_short_no_second_frame` (20.0s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m21s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.3s — slowest: `text_caret_placement_align` (28.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 5m33s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 19.5s — slowest: `frame_script_cleanup_goto2` (27.4s)

### visual

- **Pass:** 140/143 (97.9%)
- **Duration:** 29m08s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.2s — slowest: `definefont4` (87.7s)
