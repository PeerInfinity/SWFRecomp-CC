# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `bf585e4486b6`  
**Date:** 2026-08-12 23:11 UTC  
**Total duration:** 12h10m44s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 676 | 718 | 94.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1123 | 1240 | 90.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1514 | 1574 | 96.2% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 206 | 229 | 90.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 2 | 3 | 66.7% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 141 | 144 | 97.9% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4065** | **4490** | **90.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 119,403 | 131,178 | 91.0% |
| avm2 | 122,530 | 153,928 | 79.6% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,415 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,360 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,053 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,169 | 2,484 | 87.3% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 8 | 14 | 57.1% |
| mixed_avm | 26 | 53 | 49.1% |
| regression | 483 | 483 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **367,652** | **421,659** | **87.2%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 24 | - |
| avm2 | 88 | - |
| fonts | - | - |
| from_avmplus | 5 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 11 | - |
| from_shumway/avm1 | - | - |
| import_assets | 1 | - |
| mixed_avm | 7 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 2 | - |
| visual | 1 | - |
| **Total** | **173** | **1** |

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
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| mixed_avm | avm2_loads_avm1_v9 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
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
| avm1 | 2 | - | 2771 | - |
| avm2 | 12 | 1 | 766 | 442 |
| from_gnash/actionscript.all | - | - | 1 | - |
| from_shumway | 15 | - | 380 | - |

**avm1 — newly passing:** `watch_recursion_double_swf7`, `watch_recursion_swf7`

**avm2 — newly passing:** `all_classes/display3D/swf12`, `all_classes/errors/swf10`, `all_classes/errors/swf30`, `all_classes/errors/swf9`, `all_classes/security/swf12`, `all_classes/security/swf13`, `all_classes/security/swf30`, `describe_type_metadata`, `describe_type_native`, `netstream_flv_date`, `sound_constructor_with_args`, `sound_rootless`

**from_shumway — newly passing:** `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82`, `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096`, `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77`, `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3`, `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49`, `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822`, `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd`, `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121`, `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61`, `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af`, `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580`, `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b`, `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75`, `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b`, `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897`, `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052`, `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b`

*Comparing `fb36ba11005c` → `bf585e4486b6`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.1s — slowest: `stream_incomplete_loop` (21.7s)

### avm1

- **Pass:** 676/718 (94.2%)
- **Duration:** 1h35m11s across 30 shards
- **Lines:** 119,403/131,178 matching (91.0%)
- **Avg test duration:** 7.9s — slowest: `define_font_glyph_table_order` (48.2s)

### avm2

- **Pass:** 1123/1240 (90.6%)
- **Duration:** 3h41m53s across 30 shards
- **Lines:** 122,530/153,928 matching (79.6%)
- **Avg test duration:** 10.7s — slowest: `away3d_advanced_shallow_water_demo` (89.3s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 21.1s — slowest: `embed_matching/fallback_preferences` (29.0s)

### from_avmplus

- **Pass:** 1514/1574 (96.2%)
- **Duration:** 3h20m37s across 30 shards
- **Lines:** 85,415/85,996 matching (99.3%)
- **Avg test duration:** 7.6s — slowest: `ecma3/Statements/eregress_74474_002` (58.1s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 39m41s across 30 shards
- **Lines:** 30,360/38,791 matching (78.3%)
- **Avg test duration:** 9.7s — slowest: `MovieClip-v8` (65.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 37m05s across 30 shards
- **Lines:** 4,053/5,248 matching (77.2%)
- **Avg test duration:** 20.0s — slowest: `matrix_test` (111.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m14s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.6s — slowest: `levels` (23.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m22s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 19.1s — slowest: `gotoFrameLabelAsFunction` (25.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m58s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.9s — slowest: `missing_bitmap` (22.6s)

### from_shumway

- **Pass:** 206/229 (90.0%)
- **Duration:** 48m19s across 30 shards
- **Lines:** 2,169/2,484 matching (87.3%)
- **Avg test duration:** 12.6s — slowest: `acid/acid-large` (76.8s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m14s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (22.1s)

### import_assets

- **Pass:** 2/3 (66.7%)
- **Duration:** 46s across 30 shards
- **Lines:** 8/14 matching (57.1%)
- **Avg test duration:** 15.4s — slowest: `avm1_non_swf_import` (22.2s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 26/53 matching (49.1%)
- **Avg test duration:** 7.4s — slowest: `avm1_sprite_sc_ignored` (20.8s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 19m10s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 15.9s — slowest: `avm2_timeline_gradients` (47.8s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.3s — slowest: `scissor_rectangle_invalid` (10.4s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 49s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 9.6s — slowest: `convolution_filter_big_matrix` (21.0s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m46s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.5s — slowest: `auto_size/return` (31.0s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m10s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.7s — slowest: `frame_script_cleanup3` (29.0s)

### visual

- **Pass:** 141/144 (97.9%)
- **Duration:** 32m48s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.6s — slowest: `definefont4` (92.4s)
