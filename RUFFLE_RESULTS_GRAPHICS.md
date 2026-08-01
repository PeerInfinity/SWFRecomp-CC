# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `c4496a4c8f4b`  
**Date:** 2026-08-01 19:38 UTC  
**Total duration:** 12h05m33s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 672 | 718 | 93.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1084 | 1224 | 88.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1510 | 1574 | 95.9% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 186 | 229 | 81.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 138 | 143 | 96.5% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **3988** | **4471** | **89.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,631 | 131,178 | 88.9% |
| avm2 | 118,262 | 151,515 | 78.1% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,391 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,359 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,782 | 2,484 | 71.7% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 252 | 350 | 72.0% |
| **Total** | **359,953** | **419,244** | **85.9%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 28 | - |
| avm2 | 113 | - |
| fonts | 3 | - |
| from_avmplus | 10 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 14 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 29 | - |
| from_shumway/avm1 | - | - |
| import_assets | 2 | - |
| mixed_avm | 7 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 2 | - |
| timeline | 2 | - |
| visual | 5 | - |
| **Total** | **235** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
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
| avm2 | perspective_projection | 95% |
| avm2 | bounds_mode | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | cross_api_version_call_newer | 92% |
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
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| fonts | device_font_glyph_fallback | 81% |
| from_shumway | avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 4 | - | 19 | - |
| from_avmplus | 3 | - | 7 | - |
| from_shumway | 3 | - | 20 | - |
| mixed_avm | 1 | - | - | - |
| visual | 1 | - | - | - |

**avm2 — newly passing:** `statictext_text`, `stylesheet_parse_color`, `stylesheet_transform`, `subclass_superclass_linked_symbol`

**from_avmplus — newly passing:** `as3/RuntimeErrors/Error1081ReadSealedErrorNs`, `e4x/Statements/e12_1`

**from_shumway — newly passing:** `acid/acid-text-2`, `hittesting/hittesting`

**mixed_avm — newly passing:** `avm1_loads_avm2_doaction`

**visual — newly passing:** `simple_shapes/heavy_tesselation`

*Comparing `feb8882b09e2` → `c4496a4c8f4b`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.2s — slowest: `stream_incomplete_loop` (22.4s)

### avm1

- **Pass:** 672/718 (93.6%)
- **Duration:** 1h34m41s across 30 shards
- **Lines:** 116,631/131,178 matching (88.9%)
- **Avg test duration:** 7.8s — slowest: `movieclip_invalid_get_bounds_6` (56.4s)

### avm2

- **Pass:** 1084/1224 (88.6%)
- **Duration:** 3h39m22s across 30 shards
- **Lines:** 118,262/151,515 matching (78.1%)
- **Avg test duration:** 10.7s — slowest: `away3d_advanced_shallow_water_demo` (88.3s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 20.8s — slowest: `device_font_kerning` (29.0s)

### from_avmplus

- **Pass:** 1510/1574 (95.9%)
- **Duration:** 3h17m53s across 30 shards
- **Lines:** 85,391/85,996 matching (99.3%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_003` (55.7s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 40m01s across 30 shards
- **Lines:** 30,359/38,791 matching (78.3%)
- **Avg test duration:** 9.8s — slowest: `MovieClip-v8` (69.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 37m17s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 20.1s — slowest: `matrix_test` (106.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.6s — slowest: `levels` (25.4s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m20s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 18.9s — slowest: `swf4opcode` (24.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 7m01s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 21.0s — slowest: `background` (23.4s)

### from_shumway

- **Pass:** 186/229 (81.2%)
- **Duration:** 48m19s across 30 shards
- **Lines:** 1,782/2,484 matching (71.7%)
- **Avg test duration:** 12.6s — slowest: `acid/acid-large` (80.0s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `label` (21.1s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 49s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 16.1s — slowest: `avm1_non_swf_import` (24.0s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 7.3s — slowest: `avm1_sprite_sc_ignored` (20.4s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 19m30s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 16.7s — slowest: `avm2_timeline_gradients` (50.6s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.4s — slowest: `scissor_rectangle_invalid` (10.8s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 49s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 9.6s — slowest: `swf_length_too_short_no_second_frame` (21.1s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m47s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 20.7s — slowest: `auto_size/return` (31.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.2s — slowest: `frame_script_cleanup_goto2` (29.0s)

### visual

- **Pass:** 138/143 (96.5%)
- **Duration:** 32m33s across 30 shards
- **Lines:** 252/350 matching (72.0%)
- **Avg test duration:** 13.6s — slowest: `definefont4` (94.9s)
