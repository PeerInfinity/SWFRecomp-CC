# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `7f7a6ba36937`  
**Date:** 2026-09-05 04:40 UTC  
**Total duration:** 11h12m59s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 691 | 730 | 94.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1198 | 1261 | 95.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 7 | 85.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 213 | 229 | 93.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 89 | 89 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 144 | 146 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4215** | **4548** | **92.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 119,995 | 131,487 | 91.3% |
| avm2 | 152,158 | 155,033 | 98.1% |
| fonts | 190 | 346 | 54.9% |
| from_avmplus | 85,558 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,418 | 38,791 | 78.4% |
| from_gnash/misc-ming.all | 4,058 | 5,248 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,321 | 2,484 | 93.4% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 56 | 79 | 70.9% |
| regression | 681 | 681 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **398,604** | **423,576** | **94.1%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 21 | - |
| avm2 | 27 | - |
| fonts | 1 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 5 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 1 | - |
| visual | - | - |
| **Total** | **93** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
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
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 2 | - | 12 | - |
| avm2 | 21 | - | 774 | - |
| from_avmplus | 2 | - | 124 | - |
| from_gnash/actionscript.all | 3 | - | 32 | - |
| from_shumway | 1 | - | 2 | 4 |
| from_shumway/avm1 | 1 | - | 2 | - |
| timeline | 1 | - | 22 | - |

**avm1 — newly passing:** `hitarea_lazy_getter`, `hitarea_remove_sibling`

**avm2 — newly passing:** `bitmapdata_applyfilter_identity`, `bitmapdata_copypixels_alpha_combine`, `flash_ui_mouse_cursor`, `large_preload_from_bytes`, `loader_try_click_root`, `matrix3d_append_prepend_scale`, `matrix3d_copy_from`, `matrix3d_copy_to_matrix3d`, `matrix3d_interpolate`, `movieclip_addframescript_error`, `orphan_removeobject`, `primitive_keys`, `simplebutton_soundtransform`, `soundmixer_soundtransform`, `stage_display_state`, `stage_scale_factor`, `vector3d_near_equals`, `xml_duplicate_attribute`

**from_avmplus — newly passing:** `as3/Array/insertremove`, `e4x/Expressions/e11_1_4`

**from_gnash/actionscript.all — newly passing:** `Function-v6`, `Function-v7`, `Function-v8`

**from_shumway — newly passing:** `avm1/hitarea`

**from_shumway/avm1 — newly passing:** `hitarea`

**timeline — newly passing:** `frame_script_cleanup_goto2`

*Comparing `f0fd711c7126` → `7f7a6ba36937`*

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
- **Avg test duration:** 14.7s — slowest: `g711_event_mulaw` (20.7s)

### avm1

- **Pass:** 691/730 (94.7%)
- **Duration:** 1h11m53s across 30 shards
- **Lines:** 119,995/131,487 matching (91.3%)
- **Avg test duration:** 5.8s — slowest: `define_font_glyph_table_order` (44.7s)

### avm2

- **Pass:** 1198/1261 (95.0%)
- **Duration:** 3h39m08s across 30 shards
- **Lines:** 152,158/155,033 matching (98.1%)
- **Avg test duration:** 10.4s — slowest: `away3d_advanced_shallow_water_demo` (84.6s)

### fonts

- **Pass:** 6/7 (85.7%)
- **Duration:** 2m22s across 30 shards
- **Lines:** 190/346 matching (54.9%)
- **Avg test duration:** 20.3s — slowest: `embed_matching/fallback_preferences` (28.4s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h04m16s across 30 shards
- **Lines:** 85,558/85,996 matching (99.5%)
- **Avg test duration:** 7.0s — slowest: `ecma3/Statements/eregress_74474_002` (57.6s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 30m29s across 30 shards
- **Lines:** 30,418/38,791 matching (78.4%)
- **Avg test duration:** 7.5s — slowest: `MovieClip-v8` (67.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 33m16s across 30 shards
- **Lines:** 4,058/5,248 matching (77.3%)
- **Avg test duration:** 17.9s — slowest: `matrix_test` (110.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m35s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 10.6s — slowest: `function_test` (21.4s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m42s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.1s — slowest: `movieclip_destruction_test1` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m43s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.1s — slowest: `dict_cross` (22.3s)

### from_shumway

- **Pass:** 213/229 (93.0%)
- **Duration:** 44m24s across 30 shards
- **Lines:** 2,321/2,484 matching (93.4%)
- **Avg test duration:** 11.6s — slowest: `esc` (67.2s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m36s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.3s — slowest: `text-bind` (21.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.3s — slowest: `empty_url` (20.9s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 56/79 matching (70.9%)
- **Avg test duration:** 6.8s — slowest: `avm1_sprite_sc_ignored` (21.4s)

### regression

- **Pass:** 89/89 (100%)
- **Duration:** 24m12s across 30 shards
- **Lines:** 681/681 matching (100%)
- **Avg test duration:** 16.3s — slowest: `avm2_tolerant_verify_quarantine` (47.0s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m01s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.8s — slowest: `unbound_texture_multiple` (10.3s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 47s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 6.7s — slowest: `convolution_filter_big_matrix` (20.1s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m26s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.7s — slowest: `text_caret_placement_scroll` (28.3s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 5m57s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 21.0s — slowest: `missing_frame_scripts` (27.7s)

### visual

- **Pass:** 144/146 (98.6%)
- **Duration:** 31m45s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.0s — slowest: `definefont4` (70.8s)
