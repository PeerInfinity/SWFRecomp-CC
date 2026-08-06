# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `1f8396f5799f`  
**Date:** 2026-08-06 10:26 UTC  
**Total duration:** 12h10m00s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 673 | 718 | 93.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1105 | 1226 | 90.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1514 | 1574 | 96.2% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
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
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 140 | 143 | 97.9% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4024** | **4474** | **89.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 116,618 | 131,178 | 88.9% |
| avm2 | 120,144 | 152,155 | 79.0% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,410 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,359 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,789 | 2,484 | 72.0% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 26 | 53 | 49.1% |
| regression | 482 | 482 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **362,088** | **419,885** | **86.2%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 27 | - |
| avm2 | 91 | - |
| fonts | - | - |
| from_avmplus | 6 | 1 |
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
| text | 1 | - |
| timeline | 2 | - |
| visual | 1 | - |
| **Total** | **197** | **1** |

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
| avm2 | error_stack_trace | 84% |
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
| avm1 | - | - | - | 13 |
| avm2 | 20 | - | 1694 | 3 |
| from_avmplus | 3 | - | 18 | - |
| from_shumway | - | - | 1 | - |
| mixed_avm | - | - | 7 | - |
| text | 1 | - | 114 | - |
| visual | 1 | - | 6 | - |

**avm2 — newly passing:** `av_classes`, `avm1movie_addcallback_call`, `currency_parse_result`, `error_stack_trace_edge_cases`, `error_throwerror`, `flash_trace`, `json_stringify_function`, `netfilterevent`, `perspective_projection`, `primitive_toString`, `primitive_valueOf`, `property_is_enumerable`, `proxy_not_overridden`, `stage_properties2`, `static_length`, `timer_invalid_delay`, `xml_list_ctor_errors`

**from_avmplus — newly passing:** `as3/String/localeCompare_585791/v9`, `ecma3/Expressions/e11_6_1_3`, `ecma3/String/e15_5_4_8_2`

**text — newly passing:** `html_entity_parsing`

**visual — newly passing:** `define_bits_jpeg2_huge`

*Comparing `6de65043250d` → `1f8396f5799f`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m22s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.5s — slowest: `stream_incomplete_loop` (22.6s)

### avm1

- **Pass:** 673/718 (93.7%)
- **Duration:** 1h33m19s across 30 shards
- **Lines:** 116,618/131,178 matching (88.9%)
- **Avg test duration:** 7.7s — slowest: `define_font_glyph_table_order` (43.5s)

### avm2

- **Pass:** 1105/1226 (90.1%)
- **Duration:** 3h43m09s across 30 shards
- **Lines:** 120,144/152,155 matching (79.0%)
- **Avg test duration:** 10.9s — slowest: `away3d_advanced_shallow_water_demo` (87.7s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m07s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 21.2s — slowest: `embed_matching/fallback_preferences` (30.8s)

### from_avmplus

- **Pass:** 1514/1574 (96.2%)
- **Duration:** 3h20m25s across 30 shards
- **Lines:** 85,410/85,996 matching (99.3%)
- **Avg test duration:** 7.6s — slowest: `ecma3/Statements/eregress_74474_002` (67.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 39m51s across 30 shards
- **Lines:** 30,359/38,791 matching (78.3%)
- **Avg test duration:** 9.8s — slowest: `MovieClip-v8` (73.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 37m10s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 20.0s — slowest: `matrix_test` (106.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m20s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 22.2s — slowest: `levels` (24.6s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m12s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 18.6s — slowest: `movieclip_destruction_test3` (24.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m55s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.7s — slowest: `registers` (22.4s)

### from_shumway

- **Pass:** 189/229 (82.5%)
- **Duration:** 47m57s across 30 shards
- **Lines:** 1,789/2,484 matching (72.0%)
- **Avg test duration:** 12.5s — slowest: `acid/acid-large` (78.8s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m17s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.9s — slowest: `label` (21.9s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 46s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 15.3s — slowest: `avm1_non_swf_import` (21.7s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 26/53 matching (49.1%)
- **Avg test duration:** 7.6s — slowest: `avm1_sprite_sc_ignored` (22.1s)

### regression

- **Pass:** 71/71 (100%)
- **Duration:** 19m23s across 30 shards
- **Lines:** 482/482 matching (100%)
- **Avg test duration:** 16.3s — slowest: `avm2_timeline_gradients` (47.6s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 48s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.6s — slowest: `scissor_rectangle_invalid` (10.8s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 51s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 10.1s — slowest: `convolution_filter_big_matrix` (22.2s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m50s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.9s — slowest: `auto_size/height` (30.7s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m10s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.7s — slowest: `swf_9_frame_script_button_order` (28.9s)

### visual

- **Pass:** 140/143 (97.9%)
- **Duration:** 32m35s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.6s — slowest: `definefont4` (89.9s)
