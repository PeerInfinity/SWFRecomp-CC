# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `add3e60cef2f`  
**Date:** 2026-07-26 19:38 UTC  
**Total duration:** 9h58m54s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 635 | 672 | 94.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 744 | 994 | 74.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1457 | 1574 | 92.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
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
| **Total** | **3497** | **4134** | **84.6%** | |

*332 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 104,066 | 107,743 | 96.6% |
| avm2 | 95,855 | 126,695 | 75.7% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,107 | 85,995 | 99.0% |
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
| **Total** | **322,549** | **362,599** | **89.0%** |

## Failure Breakdown

| Suite | output_mismatch | recomp_fail | ruffle_matched | runtime_error | segfault |
|-------|-----------------:|-------------:|----------------:|---------------:|----------:|
| audio | 2 | - | - | - | - |
| avm1 | 25 | - | 12 | - | - |
| avm2 | 245 | - | 2 | 3 | - |
| fonts | 3 | - | - | - | - |
| from_avmplus | 60 | - | 51 | 4 | 2 |
| from_gnash/actionscript.all | 9 | - | 95 | - | - |
| from_gnash/misc-ming.all | 13 | - | 28 | - | - |
| from_gnash/misc-mtasc.all | - | - | 2 | - | - |
| from_gnash/misc-swfc.all | 3 | - | 4 | - | - |
| from_gnash/misc-swfmill.all | - | - | 1 | - | - |
| from_shumway | 31 | - | 8 | - | - |
| from_shumway/avm1 | - | - | - | - | - |
| import_assets | 2 | - | - | - | - |
| mixed_avm | 8 | - | - | - | - |
| regression | - | - | - | - | - |
| stage3d | 4 | - | - | - | - |
| swf | - | - | 1 | - | - |
| text | 6 | - | - | - | - |
| timeline | 2 | - | 3 | - | - |
| visual | 6 | 1 | - | 1 | - |
| **Total** | **419** | **1** | **207** | **8** | **2** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| mixed_avm | avm1_loads_avm2_doaction | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | stylesheet | 100% |
| from_avmplus | ecma3/String/e15_5_4_5_4 | 99% |
| avm2 | stylesheet_transform | 99% |
| from_avmplus | ecma3/String/e15_5_3_2_3 | 99% |
| avm2 | parse_int | 99% |
| avm2 | focus_events_mouse_focusable | 98% |
| from_avmplus | e4x/QName/e13_3_2 | 98% |
| avm2 | error_tostring_more | 98% |
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
| avm2 | stage_loaderinfo_properties | 92% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 92% |
| from_avmplus | ecma3/GlobalObject/e15_1_2_2_2 | 90% |
| from_avmplus | e4x/XMLList/e13_5_4_17 | 90% |
| from_avmplus | ecma3/Function/e15_3_4_4_1_rt | 90% |
| from_avmplus | ecma3/ObjectObjects/hasOwnProperty | 90% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_avmplus | e4x/Expressions/e11_1_1 | 90% |
| from_avmplus | e4x/XML/e13_4_4_32/v9 | 89% |
| avm2 | place_and_lookup/swf10 | 88% |
| avm2 | place_and_lookup/swf9 | 88% |
| avm2 | perspective_projection_basic | 88% |
| from_shumway | timeline/nav/matrix | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_avmplus | e4x/XML/e13_4_4_36 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| fonts | device_font_glyph_fallback | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.8s — slowest: `stream_incomplete_loop` (21.6s)

### avm1

- **Pass:** 635/672 (94.5%)
- **Ignored:** 45 tests
- **Duration:** 1h24m45s across 30 shards
- **Lines:** 104,066/107,743 matching (96.6%)
- **Avg test duration:** 7.0s — slowest: `movieclip_invalid_get_bounds_7` (52.5s)

### avm2

- **Pass:** 744/994 (74.8%)
- **Ignored:** 227 tests
- **Duration:** 2h50m44s across 30 shards
- **Lines:** 95,855/126,695 matching (75.7%)
- **Avg test duration:** 7.6s — slowest: `bitmapdata_accuracy` (41.2s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 1m52s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 18.7s — slowest: `embed_matching/fallback_preferences` (27.1s)

### from_avmplus

- **Pass:** 1457/1574 (92.6%)
- **Duration:** 2h30m58s across 30 shards
- **Lines:** 85,107/85,995 matching (99.0%)
- **Avg test duration:** 5.7s — slowest: `ecma3/Statements/eregress_74474_002` (54.8s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 38m45s across 30 shards
- **Lines:** 29,253/31,358 matching (93.3%)
- **Avg test duration:** 9.4s — slowest: `MovieClip-v8` (71.4s)

### from_gnash/misc-ming.all

- **Pass:** 68/109 (62.4%)
- **Ignored:** 2 tests
- **Duration:** 35m36s across 30 shards
- **Lines:** 4,029/5,188 matching (77.7%)
- **Avg test duration:** 19.1s — slowest: `matrix_test` (96.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m30s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.7s — slowest: `hello` (22.3s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m51s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 18.4s — slowest: `movieclip_destruction_test4` (22.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m13s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.6s — slowest: `mixed-bytecode-as2` (22.4s)

### from_shumway

- **Pass:** 144/183 (78.7%)
- **Ignored:** 46 tests
- **Duration:** 43m28s across 30 shards
- **Lines:** 1,168/1,624 matching (71.9%)
- **Avg test duration:** 10.4s — slowest: `acid/acid-large` (78.6s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m10s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.3s — slowest: `label` (21.1s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 44s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 14.6s — slowest: `avm1_non_swf_import` (21.8s)

### mixed_avm

- **Pass:** 3/11 (27.3%)
- **Duration:** 44s across 30 shards
- **Lines:** 16/53 matching (30.2%)
- **Avg test duration:** 3.9s — slowest: `avm2_doaction` (6.1s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 15m40s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 13.4s — slowest: `avm2_graphics_runtime` (26.1s)

### stage3d

- **Pass:** 1/5 (20.0%)
- **Duration:** 37s across 30 shards
- **Lines:** 0/208 matching (0%)
- **Avg test duration:** 7.4s — slowest: `scissor_rectangle_invalid` (8.7s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 48s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 9.5s — slowest: `swf_length_too_short_no_second_frame` (21.4s)

### text

- **Pass:** 5/11 (45.5%)
- **Duration:** 3m21s across 30 shards
- **Lines:** 705/973 matching (72.5%)
- **Avg test duration:** 18.2s — slowest: `auto_size/return` (27.8s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 3m51s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 13.6s — slowest: `frame_script_cleanup2` (25.2s)

### visual

- **Pass:** 134/142 (94.4%)
- **Duration:** 28m56s across 30 shards
- **Lines:** 238/350 matching (68.0%)
- **Avg test duration:** 12.2s — slowest: `definefont4` (84.1s)
