# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `1ca0ab117c5a`  
**Date:** 2026-07-30 17:36 UTC  
**Total duration:** 10h15m09s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 669 | 718 | 93.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 997 | 1222 | 81.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1470 | 1574 | 93.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 173 | 229 | 75.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 136 | 143 | 95.1% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **3842** | **4469** | **86.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,625 | 131,178 | 88.9% |
| avm2 | 115,508 | 151,259 | 76.4% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,228 | 85,996 | 99.1% |
| from_gnash/actionscript.all | 30,359 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,720 | 2,484 | 69.2% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 239 | 350 | 68.3% |
| **Total** | **356,955** | **418,988** | **85.2%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | runtime_error |
|-------|-----------------:|-------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 31 | - | - |
| avm2 | 196 | - | 3 |
| fonts | 3 | - | - |
| from_avmplus | 49 | - | 4 |
| from_gnash/actionscript.all | 13 | - | - |
| from_gnash/misc-ming.all | 14 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 44 | - | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 2 | - | - |
| mixed_avm | 8 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | - | - |
| text | 2 | - | - |
| timeline | 2 | - | - |
| visual | 6 | 1 | - |
| **Total** | **377** | **1** | **7** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| avm2 | font_enumeratefonts | 100% |
| avm2 | verify_illegal_opcode | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| avm2 | parse_int | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| from_avmplus | e4x/QName/e13_3_2 | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| avm2 | perspective_projection | 95% |
| from_avmplus | e4x/XML/e13_4_4_17 | 95% |
| from_avmplus | ecma3/TypeConversion/e9_3_1_3_rt | 95% |
| from_avmplus | e4x/Namespace/e13_2_5 | 94% |
| avm2 | stylesheet_parse_color | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | xml_appendchild_swf_v21 | 92% |
| avm2 | cross_api_version_call_newer | 92% |
| avm2 | invalid_utf8 | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_shumway | avm2/flash/geom/matrix3d/Matrix3DClass | 91% |
| avm2 | place_and_lookup/swf10 | 91% |
| avm2 | place_and_lookup/swf9 | 91% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| from_avmplus | ecma3/ObjectObjects/hasOwnProperty | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | e4x/Expressions/e11_1_1 | 90% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| avm2 | bitmapdata_zero_size | 88% |
| from_shumway | timeline/nav/matrix | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | displayobject_hittestpoint_root | 85% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | displayobject_opaque_background | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | flash_media_video_setter | 82% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_avmplus | e4x/XML/e13_4_4_36 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| fonts | device_font_glyph_fallback | 81% |
| from_shumway | avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 8 | 4 | 2498 | 9 |
| from_avmplus | - | - | 1 | - |
| from_shumway | - | - | 61 | - |
| visual | - | 1 | - | - |

**avm2 — newly passing:** `flash_media_video_constructor`, `loader_method`, `matrix3d`, `matrix3d_compose`, `perspective_projection_basic`, `uncaught_error_basic`, `utils3d`, `vector3d`

**avm2 — newly failing:** `away3d_advanced_shallow_water_demo`, `font_enumeratefonts`, `stage3d_raytrace`, `stage3d_texture`

**visual — newly failing:** `definefont4`

*Comparing `0612bc78e68a` → `1ca0ab117c5a`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.9s — slowest: `g711_event_mulaw` (21.8s)

### avm1

- **Pass:** 669/718 (93.2%)
- **Duration:** 59m17s across 30 shards
- **Lines:** 116,625/131,178 matching (88.9%)
- **Avg test duration:** 4.9s — slowest: `define_font_glyph_table_order` (41.5s)

### avm2

- **Pass:** 997/1222 (81.6%)
- **Duration:** 3h17m07s across 30 shards
- **Lines:** 115,508/151,259 matching (76.4%)
- **Avg test duration:** 9.6s — slowest: `away3d_advanced_shallow_water_demo` (64.5s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m53s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 18.8s — slowest: `embed_matching/fallback_preferences` (28.7s)

### from_avmplus

- **Pass:** 1470/1574 (93.4%)
- **Duration:** 3h10m55s across 30 shards
- **Lines:** 85,228/85,996 matching (99.1%)
- **Avg test duration:** 7.2s — slowest: `ecma3/Statements/eregress_74474_003` (55.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 24m30s across 30 shards
- **Lines:** 30,359/38,791 matching (78.3%)
- **Avg test duration:** 6.0s — slowest: `MovieClip-v8` (67.1s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 27m24s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 14.8s — slowest: `matrix_test` (108.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m06s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 20.7s — slowest: `levels` (23.3s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m58s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 14.9s — slowest: `movieclip_destruction_test1` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m50s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.5s — slowest: `trace-as2/this` (22.2s)

### from_shumway

- **Pass:** 173/229 (75.5%)
- **Duration:** 43m25s across 30 shards
- **Lines:** 1,720/2,484 matching (69.2%)
- **Avg test duration:** 11.3s — slowest: `acid/acid-large` (75.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m14s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (21.9s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 41s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 13.6s — slowest: `avm1_non_swf_import` (22.0s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 59s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 5.3s — slowest: `avm2_loads_avm1_loads_avm2_doabc` (7.4s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 12m18s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 10.5s — slowest: `avm2_timeline_gradients` (41.4s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 41s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.2s — slowest: `scissor_rectangle` (10.0s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 30s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 6.0s — slowest: `swf_length_too_short_no_second_frame` (22.3s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m27s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 18.8s — slowest: `text_caret_placement_align` (28.2s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 2m45s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 9.7s — slowest: `swf_9_frame_script_button_order` (26.5s)

### visual

- **Pass:** 136/143 (95.1%)
- **Duration:** 30m47s across 30 shards
- **Lines:** 239/350 matching (68.3%)
- **Avg test duration:** 12.9s — slowest: `definefont4` (87.4s)
