# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `a9900a478651`  
**Date:** 2026-07-27 04:25 UTC  
**Total duration:** 10h24m34s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 640 | 717 | 89.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 820 | 1221 | 67.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1458 | 1574 | 92.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 150 | 229 | 65.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 0 | 5 | 0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 5 | 11 | 45.5% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 121 | 142 | 85.2% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **3577** | **4466** | **80.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 4 | 24 | 16.7% |
| avm1 | 116,025 | 131,176 | 88.4% |
| avm2 | 105,247 | 151,253 | 69.6% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,215 | 85,996 | 99.1% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,603 | 2,484 | 64.5% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 705 | 973 | 72.5% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **345,598** | **418,980** | **82.5%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | runtime_error |
|-------|-----------------:|-------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 60 | - | - |
| avm2 | 372 | - | 3 |
| fonts | 3 | - | - |
| from_avmplus | 61 | - | 4 |
| from_gnash/actionscript.all | 13 | - | - |
| from_gnash/misc-ming.all | 14 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 67 | - | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 2 | - | - |
| mixed_avm | 8 | - | - |
| regression | - | - | - |
| stage3d | 5 | - | - |
| swf | - | - | - |
| text | 6 | - | - |
| timeline | 2 | - | - |
| visual | 19 | 1 | 1 |
| **Total** | **639** | **1** | **8** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | font_enumeratefonts | 100% |
| avm2 | mouse_over_while_dragging | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| from_shumway | encoding1 | 100% |
| from_shumway | flash_events_Event | 100% |
| from_shumway | hitTestStyleChange | 100% |
| from_shumway | image-loading | 100% |
| from_shumway | local2global | 100% |
| from_shumway | lzma | 100% |
| from_shumway | lzma_bytes | 100% |
| from_shumway | timeline/scene/EncodedU32 | 100% |
| from_shumway | timeline/scene/Scene_1_MainTimeline | 100% |
| from_shumway | timeline/scene/Scene_2_MovieClipTimeline | 100% |
| from_shumway | timeline/scene/Scene_6_GotoAndPlay_FrameScene | 100% |
| from_shumway | timeline/scene/Scene_7_NextPrevScene | 100% |
| from_shumway | timeline/timeline_loop | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_avmplus | as3/AMF/AMFSerializer | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| avm2 | parse_int | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | focus_events_mouse_focusable | 98% |
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
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| text | text_caret_placement_translated_bounds | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_avmplus | e4x/XML/e13_4_4_17 | 95% |
| from_avmplus | ecma3/TypeConversion/e9_3_1_3_rt | 95% |
| avm2 | focusrect_property | 95% |
| from_avmplus | e4x/Namespace/e13_2_5 | 94% |
| visual | filters/avm1_convolution_initialization | 94% |
| avm2 | stylesheet_parse_color | 94% |
| from_avmplus | as3/Definitions/Variable/ConstVariables_custom1 | 94% |
| avm2 | mouseevent_constr | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_avmplus | ecma3/Function/e15_3_4_3_1 | 93% |
| from_avmplus | e4x/XML/e13_4_4_28 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | edittext_mouse_selection | 92% |
| avm2 | invalid_utf8 | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| from_avmplus | e4x/XMLList/e13_5_4_17 | 90% |
| from_avmplus | ecma3/Function/e15_3_4_4_1_rt | 90% |
| from_avmplus | ecma3/ObjectObjects/hasOwnProperty | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | e4x/Expressions/e11_1_1 | 90% |
| avm2 | button_nested_frame_simple | 89% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| avm2 | place_and_lookup/swf10 | 88% |
| avm2 | place_and_lookup/swf9 | 88% |
| avm2 | bitmapdata_zero_size | 88% |
| avm2 | perspective_projection_basic | 88% |
| from_shumway | timeline/nav/matrix | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm2 | matrix | 83% |
| avm1 | load_vars | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_avmplus | e4x/XML/e13_4_4_36 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| fonts | device_font_glyph_fallback | 81% |
| avm2 | loader_noninteractive_try_click_root | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| audio | - | - | - | 1 |
| avm1 | 2 | - | 134 | - |
| avm2 | 4 | 44 | 353 | 102 |
| from_avmplus | - | - | 1 | - |
| from_shumway | - | 13 | - | - |
| stage3d | - | 1 | - | - |
| visual | - | 13 | - | - |

**avm1 — newly passing:** `geturl_opcode_target_normalize`, `geturl_target_normalize`

**avm2 — newly passing:** `loader_method`, `navigateToURL_target_normalize`, `net_navigateToURL`, `uncaught_error_basic`

**avm2 — newly failing:** `away3d_advanced_shallow_water_demo`, `bitmapdata_applyfilter_blur`, `bitmapdata_applyfilter_colormatrix`, `bitmapdata_applyfilter_destpoint`, `bitmapdata_applyfilter_destpoint_edges`, `bitmapdata_colortransform`, `bitmapdata_copychannel`, `bitmapdata_draw_filters`, `bitmapdata_filter_sourcerect`, `displayobject_colortransform_nested`, `font_enumeratefonts`, `graphics_bitmap_fill`, `graphics_bitmaps`, `graphics_direct_commands`, `graphics_gradients`, `graphics_round_rects`, `mouse_over_while_dragging`, `pixelbender_effect_BlurredFocus`, `pixelbender_effect_glassDisplace`, `pixelbender_effect_smudge`, `pixelbender_effect_tintype`, `pixelbender_effect_twirl`, `pixelbender_images`, `remove_child_clear_field`, `stage3d_agal_cross_product`, `stage3d_bitmap`, `stage3d_float1_index`, `stage3d_fractal`, `stage3d_ignore_sampler_override`, `stage3d_program_constants_bytearray_be`, `stage3d_program_constants_bytearray_le`, `stage3d_raytrace`, `stage3d_rotating_cube`, `stage3d_sampler`, `stage3d_sampler_partial_upload`, `stage3d_stencil`, `stage3d_texture`, `stage3d_texture_bytearray`, `stage3d_texture_bytearray_compressed_alpha`, `stage3d_texture_bytearray_compressed_raw_alpha`, `stage3d_triangle`, `stage3d_triangle_bytes4`, `stage3d_triangle_float1`, `stage3d_triangle_index_upload`

**from_shumway — newly failing:** `encoding1`, `flash_events_Event`, `hitTestStyleChange`, `image-loading`, `local2global`, `lzma`, `lzma_bytes`, `timeline/scene/EncodedU32`, `timeline/scene/Scene_1_MainTimeline`, `timeline/scene/Scene_2_MovieClipTimeline`, `timeline/scene/Scene_6_GotoAndPlay_FrameScene`, `timeline/scene/Scene_7_NextPrevScene`, `timeline/timeline_loop`

**stage3d — newly failing:** `scissor_rectangle`

**visual — newly failing:** `blend_modes/shader_as_mask`, `cache_as_bitmap/bitmap_changed`, `cache_as_bitmap/cab_mask_filters`, `definefont4`, `filters/blur_fractional`, `filters/blur_pass_scaling`, `filters/blur_quality`, `filters/displacement_map`, `filters/displacement_map_scales_with_screen`, `filters/displacement_map_through_applyFilter`, `filters/displacement_map_through_filters`, `filters/glow_pass_scaling`, `video/h264`

*Comparing `28577da2aa5c` → `a9900a478651`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 4/24 matching (16.7%)
- **Avg test duration:** 13.4s — slowest: `stream_incomplete_loop` (20.8s)

### avm1

- **Pass:** 640/717 (89.3%)
- **Duration:** 1h28m14s across 30 shards
- **Lines:** 116,025/131,176 matching (88.4%)
- **Avg test duration:** 7.3s — slowest: `movieclip_invalid_get_bounds_7` (54.6s)

### avm2

- **Pass:** 820/1221 (67.2%)
- **Duration:** 3h01m43s across 30 shards
- **Lines:** 105,247/151,253 matching (69.6%)
- **Avg test duration:** 8.9s — slowest: `away3d_advanced_shallow_water_demo` (59.4s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 17.3s — slowest: `embed_matching/fallback_preferences` (27.2s)

### from_avmplus

- **Pass:** 1458/1574 (92.6%)
- **Duration:** 2h38m30s across 30 shards
- **Lines:** 85,215/85,996 matching (99.1%)
- **Avg test duration:** 6.0s — slowest: `ecma3/Statements/eregress_74474_003` (57.1s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 38m22s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 9.4s — slowest: `MovieClip-v8` (65.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 36m05s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 19.5s — slowest: `matrix_test` (101.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m25s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.1s — slowest: `inheritance` (21.4s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m06s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 18.3s — slowest: `swf4opcode` (25.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m43s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.1s — slowest: `tags_after_last_showframe` (23.2s)

### from_shumway

- **Pass:** 150/229 (65.5%)
- **Duration:** 45m18s across 30 shards
- **Lines:** 1,603/2,484 matching (64.5%)
- **Avg test duration:** 11.8s — slowest: `acid/acid-large` (77.7s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m04s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.6s — slowest: `text-bind` (20.4s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 35s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 11.7s — slowest: `avm1_non_swf_import` (18.0s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 48s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 4.3s — slowest: `avm2_loads_avm1_loads_avm2_doabc` (6.5s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 16m20s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 13.9s — slowest: `avm2_timeline_gradients` (31.0s)

### stage3d

- **Pass:** 0/5 (0%)
- **Duration:** 35s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 6.9s — slowest: `scissor_rectangle` (9.2s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 47s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 9.3s — slowest: `swf_length_too_short_no_second_frame` (21.3s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 3m11s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 17.3s — slowest: `text_caret_placement_align` (28.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 3m46s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 13.3s — slowest: `frame_script_cleanup` (25.7s)

### visual

- **Pass:** 121/142 (85.2%)
- **Duration:** 30m05s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 12.7s — slowest: `definefont4` (88.2s)
