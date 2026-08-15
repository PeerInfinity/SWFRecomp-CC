# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `86434112a759`  
**Date:** 2026-08-15 09:18 UTC  
**Total duration:** 12h57m43s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 681 | 725 | 93.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1154 | 1243 | 92.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1515 | 1574 | 96.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 210 | 229 | 91.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 142 | 144 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4114** | **4500** | **91.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 119,603 | 131,334 | 91.1% |
| avm2 | 141,995 | 154,168 | 92.1% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,418 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,360 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,191 | 2,484 | 88.2% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 49 | 53 | 92.5% |
| regression | 483 | 483 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **387,371** | **422,055** | **91.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 26 | - |
| avm2 | 58 | - |
| fonts | - | - |
| from_avmplus | 5 | 1 |
| from_gnash/actionscript.all | 16 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 7 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 2 | - |
| visual | - | - |
| **Total** | **136** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | button_nested_frame_simple | 100% |
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
| avm2 | bounds_mode | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| from_gnash/actionscript.all | Sound-v6 | 93% |
| from_gnash/actionscript.all | Sound-v7 | 93% |
| from_gnash/actionscript.all | Sound-v8 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm1 | sound_load_props | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | matrix3d_raw_data | 85% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | matrix3d_determinant | 82% |
| avm2 | displayobject_scrollrect | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 12 | 1 | 15613 | 2 |
| from_gnash/actionscript.all | - | 3 | - | - |
| from_shumway | 3 | - | 15 | - |
| import_assets | 1 | - | 6 | - |
| mixed_avm | 3 | - | 9 | - |

**avm2 — newly passing:** `all_classes/display/swf10`, `all_classes/display/swf11`, `all_classes/display/swf12`, `all_classes/display/swf13`, `all_classes/display/swf30`, `all_classes/display/swf9`, `bitmapdata_draw_alpha_erase`, `delayed_symbolclass`, `edittext_tag_indent`, `geom_transform`, `localconnection`, `matrix`

**avm2 — newly failing:** `verify_method_info_oob`

**from_shumway — newly passing:** `acid/acid-morph`, `as3-loader/LoaderTest2`, `avm2/flash/geom/matrix3d/TransformBasics`

**import_assets — newly passing:** `avm1_imports_avm1`

**mixed_avm — newly passing:** `avm2_loads_avm1`, `avm2_loads_avm1_v10`, `avm2_loads_avm1_v9`

*Comparing `3db858cbc157` → `86434112a759`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.9s — slowest: `g711_event_mulaw` (23.1s)

### avm1

- **Pass:** 681/725 (93.9%)
- **Duration:** 1h36m25s across 30 shards
- **Lines:** 119,603/131,334 matching (91.1%)
- **Avg test duration:** 7.9s — slowest: `define_font_glyph_table_order` (44.6s)

### avm2

- **Pass:** 1154/1243 (92.8%)
- **Duration:** 4h10m47s across 30 shards
- **Lines:** 141,995/154,168 matching (92.1%)
- **Avg test duration:** 12.0s — slowest: `away3d_advanced_shallow_water_demo` (96.5s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 22.5s — slowest: `embed_matching/fallback_preferences` (32.3s)

### from_avmplus

- **Pass:** 1515/1574 (96.3%)
- **Duration:** 3h27m13s across 30 shards
- **Lines:** 85,418/85,996 matching (99.3%)
- **Avg test duration:** 7.8s — slowest: `ecma3/Statements/eregress_74474_003` (65.7s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 39m57s across 30 shards
- **Lines:** 30,360/38,791 matching (78.3%)
- **Avg test duration:** 9.8s — slowest: `MovieClip-v8` (67.7s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 37m10s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 20.0s — slowest: `matrix_test` (111.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m12s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.4s — slowest: `function_test` (24.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m31s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 19.5s — slowest: `stackscope` (29.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 7m03s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 21.1s — slowest: `trace-as2/super` (24.6s)

### from_shumway

- **Pass:** 210/229 (91.7%)
- **Duration:** 50m37s across 30 shards
- **Lines:** 2,191/2,484 matching (88.2%)
- **Avg test duration:** 13.2s — slowest: `acid/acid-large` (80.2s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m49s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.5s — slowest: `text-bind` (22.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 49s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.2s — slowest: `avm1_non_swf_import` (23.4s)

### mixed_avm

- **Pass:** 10/11 (90.9%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 49/53 matching (92.5%)
- **Avg test duration:** 7.6s — slowest: `avm1_sprite_sc_ignored` (23.3s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 22m27s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 18.7s — slowest: `avm2_bitmapdata_draw_textfield` (49.1s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 50s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.9s — slowest: `scissor_rectangle` (11.7s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 52s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 10.4s — slowest: `swf_length_too_short_no_second_frame` (23.7s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m44s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.4s — slowest: `auto_size/return` (32.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m50s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 24.1s — slowest: `frame_script_cleanup` (30.7s)

### visual

- **Pass:** 142/144 (98.6%)
- **Duration:** 35m18s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.7s — slowest: `definefont4` (91.0s)
