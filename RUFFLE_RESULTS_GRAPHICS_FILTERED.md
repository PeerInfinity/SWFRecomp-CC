# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `9b6bbcb5757f`  
**Date:** 2026-07-25 20:09 UTC  
**Total duration:** 8h17m33s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 635 | 672 | 94.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 742 | 991 | 74.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1406 | 1574 | 89.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 68 | 109 | 62.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 144 | 183 | 78.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 3 | 11 | 27.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 1 | 5 | 20.0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 5 | 11 | 45.5% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 134 | 142 | 94.4% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **3444** | **4131** | **83.4%** | |

*332 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 104,066 | 107,743 | 96.6% |
| avm2 | 95,706 | 126,648 | 75.6% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 84,018 | 85,932 | 97.8% |
| from_gnash/actionscript.all | 29,253 | 31,358 | 93.3% |
| from_gnash/misc-ming.all | 4,029 | 5,188 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,168 | 1,624 | 71.9% |
| from_shumway/avm1 | 480 | 480 | 100% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 16 | 53 | 30.2% |
| regression | 481 | 481 | 100% |
| stage3d | 0 | 208 | 0% |
| swf | 51 | 57 | 89.5% |
| text | 705 | 973 | 72.5% |
| timeline | 333 | 371 | 89.8% |
| visual | 238 | 350 | 68.0% |
| **Total** | **321,311** | **362,489** | **88.6%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | recomp_fail | ruffle_matched | runtime_error | segfault | timeout |
|-------|--------------:|-----------------:|-------------:|----------------:|---------------:|----------:|---------:|
| audio | - | 2 | - | - | - | - | - |
| avm1 | - | 25 | - | 12 | - | - | - |
| avm2 | - | 243 | - | 2 | 4 | - | - |
| fonts | - | 3 | - | - | - | - | - |
| from_avmplus | 1 | 97 | - | 49 | 16 | 2 | 3 |
| from_gnash/actionscript.all | - | 9 | - | 95 | - | - | - |
| from_gnash/misc-ming.all | - | 13 | - | 28 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | 2 | - | - | - |
| from_gnash/misc-swfc.all | - | 3 | - | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | 1 | - | - | - |
| from_shumway | - | 31 | - | 8 | - | - | - |
| from_shumway/avm1 | - | - | - | - | - | - | - |
| import_assets | - | 2 | - | - | - | - | - |
| mixed_avm | - | 8 | - | - | - | - | - |
| regression | - | - | - | - | - | - | - |
| stage3d | - | 4 | - | - | - | - | - |
| swf | - | - | - | 1 | - | - | - |
| text | - | 6 | - | - | - | - | - |
| timeline | - | 2 | - | 3 | - | - | - |
| visual | - | 6 | 1 | - | 1 | - | - |
| **Total** | **1** | **454** | **1** | **205** | **21** | **2** | **3** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | as3/ByteArray/ByteArray | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| from_avmplus | as3/Vector/vectorIndexRangeExceptions | 99% |
| avm2 | stylesheet_transform | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| avm2 | parse_int | 99% |
| avm2 | focus_events_mouse_focusable | 98% |
| from_avmplus | e4x/QName/e13_3_2 | 98% |
| avm2 | error_tostring_more | 98% |
| from_avmplus | as3/Vector/initializer_expressions | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| text | text_caret_placement_translated_bounds | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| from_avmplus | e4x/XML/e13_4_4_17 | 95% |
| from_avmplus | ecma3/TypeConversion/e9_3_1_3_rt | 95% |
| avm2 | focusrect_property | 95% |
| from_avmplus | e4x/Namespace/e13_2_5 | 94% |
| visual | filters/avm1_convolution_initialization | 94% |
| avm2 | stylesheet_parse_color | 94% |
| from_avmplus | as3/Definitions/Variable/ConstVariables_custom1 | 94% |
| avm2 | mouseevent_constr | 94% |
| from_avmplus | ecma3/JSON/e15_12_3 | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_avmplus | ecma3/Function/e15_3_4_3_1 | 93% |
| from_avmplus | as3/Vector/some | 92% |
| from_avmplus | e4x/XML/e13_4_4_28 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | edittext_mouse_selection | 92% |
| avm2 | invalid_utf8 | 92% |
| avm2 | stage_loaderinfo_properties | 92% |
| from_avmplus | as3/Vector/map | 92% |
| from_avmplus | ecma3/JSON/e15_12_2 | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_avmplus | as3/ShellClasses/DictionarySubclass | 91% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| from_avmplus | e4x/XMLList/e13_5_4_17 | 90% |
| from_avmplus | ecma3/Function/e15_3_4_4_1_rt | 90% |
| from_avmplus | ecma3/ObjectObjects/hasOwnProperty | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | e4x/Expressions/e11_1_1 | 90% |
| from_avmplus | as3/Vector/filter | 89% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| avm2 | place_and_lookup/swf10 | 88% |
| avm2 | place_and_lookup/swf9 | 88% |
| avm2 | perspective_projection_basic | 88% |
| from_avmplus | as3/Vector/nested | 88% |
| from_shumway | timeline/nav/matrix | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| from_avmplus | as3/Vector/nonindexproperty/v10 | 86% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_avmplus | as3/Vector/map_initializers | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_avmplus | as3/Vector/foreach | 83% |
| from_avmplus | as3/Vector/some_initializers | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_avmplus | e4x/XML/e13_4_4_36 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| fonts | device_font_glyph_fallback | 81% |
| avm2 | indexing_delete | 80% |
| from_avmplus | as3/Vector/filter_initializers | 80% |
| from_avmplus | as3/Vector/foreach_initializers | 80% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m09s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.9s — slowest: `stream_incomplete_loop` (21.1s)

### avm1

- **Pass:** 635/672 (94.5%)
- **Ignored:** 45 tests
- **Duration:** 46m13s across 30 shards
- **Lines:** 104,066/107,743 matching (96.6%)
- **Avg test duration:** 3.8s — slowest: `define_font_glyph_table_order` (37.6s)

### avm2

- **Pass:** 742/991 (74.9%)
- **Ignored:** 227 tests
- **Duration:** 2h39m02s across 30 shards
- **Lines:** 95,706/126,648 matching (75.6%)
- **Avg test duration:** 7.1s — slowest: `bitmapdata_accuracy` (43.5s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 11.8s — slowest: `device_font_kerning` (24.9s)

### from_avmplus

- **Pass:** 1406/1574 (89.3%)
- **Duration:** 2h36m47s across 30 shards
- **Lines:** 84,018/85,932 matching (97.8%)
- **Avg test duration:** 5.9s — slowest: `as3/Vector/initializer_large_vector` (304.8s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 23m18s across 30 shards
- **Lines:** 29,253/31,358 matching (93.3%)
- **Avg test duration:** 5.6s — slowest: `MovieClip-v8` (71.0s)

### from_gnash/misc-ming.all

- **Pass:** 68/109 (62.4%)
- **Ignored:** 2 tests
- **Duration:** 23m36s across 30 shards
- **Lines:** 4,029/5,188 matching (77.7%)
- **Avg test duration:** 12.7s — slowest: `matrix_test` (102.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m08s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.2s — slowest: `implementsOpTest` (21.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 3m49s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 11.3s — slowest: `movieclip_destruction_test1` (24.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m40s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.0s — slowest: `background` (21.0s)

### from_shumway

- **Pass:** 144/183 (78.7%)
- **Ignored:** 46 tests
- **Duration:** 36m24s across 30 shards
- **Lines:** 1,168/1,624 matching (71.9%)
- **Avg test duration:** 8.5s — slowest: `acid/acid-large` (75.6s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m04s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.2s — slowest: `label` (21.1s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 23s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 7.7s — slowest: `empty_url` (20.0s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 46s across 30 shards
- **Lines:** 16/53 matching (30.2%)
- **Avg test duration:** 4.1s — slowest: `avm2_loads_avm1_loads_avm2_doabc` (6.1s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 7m38s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 6.5s — slowest: `avm2_timeline_gradients` (39.3s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 34s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 6.8s — slowest: `scissor_rectangle_invalid` (8.5s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 9s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 1.7s — slowest: `swf_length_too_short_no_end` (2.1s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 3m00s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 16.3s — slowest: `text_caret_placement_align` (28.2s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 1m27s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 5.1s — slowest: `frame_script_cleanup_goto2` (6.5s)

### visual

- **Pass:** 134/142 (94.4%)
- **Duration:** 25m08s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 10.6s — slowest: `definefont4` (74.6s)
