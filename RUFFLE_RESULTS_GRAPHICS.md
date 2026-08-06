# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `6de65043250d`  
**Date:** 2026-08-06 06:23 UTC  
**Total duration:** 11h48m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 673 | 718 | 93.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1088 | 1226 | 88.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1511 | 1574 | 96.0% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 189 | 229 | 82.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 71 | 71 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 139 | 143 | 97.2% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4002** | **4474** | **89.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,631 | 131,178 | 88.9% |
| avm2 | 118,453 | 152,155 | 77.9% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,392 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,359 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,788 | 2,484 | 72.0% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 482 | 482 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 295 | 350 | 84.3% |
| **Total** | **360,264** | **419,885** | **85.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 27 | - |
| avm2 | 111 | - |
| fonts | - | - |
| from_avmplus | 9 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 14 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 26 | - |
| from_shumway/avm1 | - | - |
| import_assets | 2 | - |
| mixed_avm | 7 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 2 | - |
| timeline | 2 | - |
| visual | 2 | - |
| **Total** | **222** | **1** |

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
| avm2 | perspective_projection | 99% |
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
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | edittext_device_transform_layout | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | - | - |
| avm2 | 6 | - | 160 | 83 |
| fonts | 3 | - | 69 | - |
| from_avmplus | 1 | - | 1 | - |
| from_shumway | 3 | - | 6 | - |
| visual | 3 | - | 43 | - |

**avm1 — newly passing:** `load_cancel_via_removemovieclip`

**avm2 — newly passing:** `constructsuper_null`, `cross_api_version_call_newer`, `doabc_and_symbolclass_script_init_goto`, `doabc_and_symbolclass_script_init_normal`, `graphic_linkage`, `system_exit`

**fonts — newly passing:** `device_font_glyph_fallback`, `device_font_kerning`, `device_font_list`

**from_avmplus — newly passing:** `regress/bug_550958`

**from_shumway — newly passing:** `as3-loader/bug1157243/empty`, `as3-loader/bug1157243/invalid`, `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`

**visual — newly passing:** `edittext/edittext_device_transform_basic`

*Comparing `c4496a4c8f4b` → `6de65043250d`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 17.0s — slowest: `stream_incomplete_loop` (23.9s)

### avm1

- **Pass:** 673/718 (93.7%)
- **Duration:** 1h29m51s across 30 shards
- **Lines:** 116,631/131,178 matching (88.9%)
- **Avg test duration:** 7.4s — slowest: `movieclip_invalid_get_bounds_6` (50.0s)

### avm2

- **Pass:** 1088/1226 (88.7%)
- **Duration:** 3h33m32s across 30 shards
- **Lines:** 118,453/152,155 matching (77.9%)
- **Avg test duration:** 10.4s — slowest: `away3d_advanced_shallow_water_demo` (89.1s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m08s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 21.4s — slowest: `embed_matching/fallback_preferences` (29.8s)

### from_avmplus

- **Pass:** 1511/1574 (96.0%)
- **Duration:** 3h15m47s across 30 shards
- **Lines:** 85,392/85,996 matching (99.3%)
- **Avg test duration:** 7.4s — slowest: `ecma3/Statements/eregress_74474_003` (55.6s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 37m57s across 30 shards
- **Lines:** 30,359/38,791 matching (78.3%)
- **Avg test duration:** 9.3s — slowest: `array-v6` (51.8s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 36m25s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 19.6s — slowest: `matrix_test` (112.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m20s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 22.2s — slowest: `levels` (24.3s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m04s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 18.2s — slowest: `movieclip_destruction_test1` (24.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m48s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.4s — slowest: `dict_event` (23.1s)

### from_shumway

- **Pass:** 189/229 (82.5%)
- **Duration:** 47m56s across 30 shards
- **Lines:** 1,788/2,484 matching (72.0%)
- **Avg test duration:** 12.5s — slowest: `acid/acid-large` (82.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m16s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (22.2s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 48s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 16.0s — slowest: `avm1_non_swf_import` (23.0s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 7.3s — slowest: `avm1_sprite_sc_ignored` (21.6s)

### regression

- **Pass:** 71/71 (100%)
- **Duration:** 19m04s across 30 shards
- **Lines:** 482/482 matching (100%)
- **Avg test duration:** 16.1s — slowest: `avm2_timeline_gradients` (46.6s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 48s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.6s — slowest: `scissor_rectangle_invalid` (10.9s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 50s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 10.0s — slowest: `swf_length_too_short_no_second_frame` (21.9s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m45s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 20.4s — slowest: `auto_size/return` (31.1s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.2s — slowest: `frame_script_cleanup2` (29.6s)

### visual

- **Pass:** 139/143 (97.2%)
- **Duration:** 31m58s across 30 shards
- **Lines:** 295/350 matching (84.3%)
- **Avg test duration:** 13.4s — slowest: `simple_shapes/heavy_tesselation` (76.0s)
