# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `88ebde66534f`  
**Date:** 2026-08-16 08:44 UTC  
**Total duration:** 11h11m37s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 681 | 725 | 93.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1153 | 1251 | 92.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1515 | 1574 | 96.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 210 | 229 | 91.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 142 | 144 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4113** | **4508** | **91.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 119,603 | 131,334 | 91.1% |
| avm2 | 142,202 | 154,806 | 91.9% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,418 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,360 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
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
| **Total** | **387,582** | **422,693** | **91.7%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 26 | - |
| avm2 | 67 | - |
| fonts | - | - |
| from_avmplus | 17 | 1 |
| from_gnash/actionscript.all | 16 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
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
| **Total** | **156** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| from_avmplus | as3/Expressions/asOperator/asOper | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | divide | 99% |
| from_avmplus | ecma3/Number/e15_7_2 | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| from_avmplus | ecma3/String/e15_5_2 | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| from_avmplus | ecma3/Number/e15_7_4_2_4 | 98% |
| from_avmplus | ecma3/String/e15_5_1 | 98% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 98% |
| from_avmplus | ecma3/Number/e15_7_1 | 98% |
| from_avmplus | ecma3/TypeConversion/e9_8_1 | 97% |
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
| avm2 | matrix3d_constructor_clone | 93% |
| from_avmplus | ecma3/Array/e15_4_4_5 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_avmplus | ecma3/Array/toLocaleString | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | coerce_string_precision | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm1 | sound_load_props | 86% |
| from_avmplus | ecma3/Types/e8_5 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | matrix3d_raw_data | 85% |
| avm2 | vector3d_near_equals | 84% |
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
| avm1 | 4 | - | 2836 | - |
| avm2 | 34 | 2 | 18565 | 96 |
| from_avmplus | - | 12 | 3 | - |
| from_gnash/actionscript.all | - | 3 | 1 | - |
| from_shumway | 19 | - | 407 | 5 |
| import_assets | 1 | - | 6 | - |
| mixed_avm | 6 | - | 23 | - |
| visual | 1 | - | - | - |

**avm1 — newly passing:** `textfield_asbroadcaster`, `watch_recursion_double_swf7`, `watch_recursion_swf7`, `watch_virtual_property`

**avm2 — newly passing:** `accessibilityimplementation`, `all_classes/accessibility/swf10`, `all_classes/accessibility/swf30`, `all_classes/accessibility/swf9`, `all_classes/display/swf10`, `all_classes/display/swf11`, `all_classes/display/swf12`, `all_classes/display/swf13`, `all_classes/display/swf30`, `all_classes/display/swf9`, `all_classes/display3D/swf12`, `all_classes/display3D/swf13`, `all_classes/display3D/swf30`, `all_classes/errors/swf10`, `all_classes/errors/swf30`, `all_classes/errors/swf9`, `all_classes/security/swf12`, `all_classes/security/swf13`, `all_classes/security/swf30`, `all_classes/xml/swf30`, `all_classes/xml/swf9`, `bitmapdata_draw_alpha_erase`, `delayed_symbolclass`, `describe_type_metadata`, `describe_type_native`, `edittext_tag_indent`, `geom_transform`, `int_toprecision`, `localconnection`, `matrix`, `netstream_flv_date`, `number_convert_edge_cases`, `sound_constructor_with_args`, `sound_rootless`, `sub_super_same_field`, `uint_toprecision`

**avm2 — newly failing:** `coerce_string_precision`, `divide`

**from_avmplus — newly passing:** `ecma3/Number/e15_7_4_7_1`

**from_shumway — newly passing:** `acid/acid-morph`, `as3-loader/LoaderTest2`, `avm2/flash/geom/matrix3d/TransformBasics`, `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82`, `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096`, `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77`, `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3`, `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49`, `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822`, `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd`, `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121`, `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61`, `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af`, `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580`, `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b`, `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75`, `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b`, `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e`, `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897`, `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052`, `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b`

**import_assets — newly passing:** `avm1_imports_avm1`

**mixed_avm — newly passing:** `avm2_loads_avm1`, `avm2_loads_avm1_doabc`, `avm2_loads_avm1_loads_avm2_doabc`, `avm2_loads_avm1_loads_into_root`, `avm2_loads_avm1_v10`, `avm2_loads_avm1_v9`

**visual — newly passing:** `definefont4`

*Comparing `0a99be1a92de` → `88ebde66534f`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m03s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 12.7s — slowest: `g711_event_alaw` (20.0s)

### avm1

- **Pass:** 681/725 (93.9%)
- **Duration:** 1h20m54s across 30 shards
- **Lines:** 119,603/131,334 matching (91.1%)
- **Avg test duration:** 6.6s — slowest: `define_font_glyph_table_order` (44.3s)

### avm2

- **Pass:** 1153/1251 (92.2%)
- **Duration:** 3h39m49s across 30 shards
- **Lines:** 142,202/154,806 matching (91.9%)
- **Avg test duration:** 10.5s — slowest: `away3d_advanced_shallow_water_demo` (86.8s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 17.7s — slowest: `device_font_list` (26.1s)

### from_avmplus

- **Pass:** 1515/1574 (96.3%)
- **Duration:** 2h52m31s across 30 shards
- **Lines:** 85,418/85,996 matching (99.3%)
- **Avg test duration:** 6.5s — slowest: `ecma3/Statements/eregress_74474_003` (52.9s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 36m03s across 30 shards
- **Lines:** 30,360/38,791 matching (78.3%)
- **Avg test duration:** 8.8s — slowest: `MovieClip-v8` (68.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 34m09s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 18.4s — slowest: `matrix_test` (104.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m58s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 19.8s — slowest: `levels` (22.2s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m52s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.6s — slowest: `movieclip_destruction_test1` (22.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m30s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.5s — slowest: `func_dict` (21.1s)

### from_shumway

- **Pass:** 210/229 (91.7%)
- **Duration:** 44m00s across 30 shards
- **Lines:** 2,191/2,484 matching (88.2%)
- **Avg test duration:** 11.5s — slowest: `acid/acid-large` (60.2s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (20.6s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.2s — slowest: `avm1_non_swf_import` (20.5s)

### mixed_avm

- **Pass:** 10/11 (90.9%)
- **Duration:** 1m04s across 30 shards
- **Lines:** 49/53 matching (92.5%)
- **Avg test duration:** 5.8s — slowest: `avm1_sprite_sc_ignored` (12.7s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 20m35s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 17.1s — slowest: `avm2_slot_default_template` (47.1s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 36s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 7.1s — slowest: `sampler_odd_size` (9.3s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 40s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 8.0s — slowest: `convolution_filter_big_matrix` (20.0s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m28s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.9s — slowest: `text_caret_placement_scroll` (27.7s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m13s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.9s — slowest: `frame_script_cleanup_goto` (27.4s)

### visual

- **Pass:** 142/144 (98.6%)
- **Duration:** 30m21s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.6s — slowest: `definefont4` (88.7s)
