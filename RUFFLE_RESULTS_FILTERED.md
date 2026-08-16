# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `88ebde66534f`  
**Date:** 2026-08-16 08:44 UTC  
**Total duration:** 11h11m37s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 679 | 704 | 96.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1148 | 1198 | 95.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1515 | 1572 | 96.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 135 | 239 | 56.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 194 | 207 | 93.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 142 | 144 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4090** | **4402** | **92.9%** | |

*106 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 109,698 | 113,120 | 97.0% |
| avm2 | 133,783 | 136,522 | 98.0% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,406 | 85,970 | 99.3% |
| from_gnash/actionscript.all | 29,444 | 31,544 | 93.3% |
| from_gnash/misc-ming.all | 4,047 | 5,206 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,507 | 1,770 | 85.1% |
| from_shumway/avm1 | 487 | 487 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 49 | 53 | 92.5% |
| regression | 483 | 483 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **367,620** | **378,137** | **97.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 12 | 13 | - |
| avm2 | 42 | 8 | - |
| fonts | - | - | - |
| from_avmplus | 15 | 41 | 1 |
| from_gnash/actionscript.all | 12 | 92 | - |
| from_gnash/misc-ming.all | 12 | 29 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 6 | 7 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 1 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 1 | - |
| text | 1 | - | - |
| timeline | 2 | 3 | - |
| visual | - | 2 | - |
| **Total** | **107** | **204** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | button_nested_frame_simple | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| from_avmplus | as3/Expressions/asOperator/asOper | 99% |
| avm2 | divide | 99% |
| from_avmplus | ecma3/Number/e15_7_2 | 99% |
| from_avmplus | ecma3/String/e15_5_2 | 99% |
| from_avmplus | ecma3/Number/e15_7_4_2_4 | 98% |
| from_avmplus | ecma3/String/e15_5_1 | 98% |
| from_avmplus | ecma3/Number/toLocaleString_rt | 98% |
| from_avmplus | ecma3/Number/e15_7_1 | 98% |
| from_avmplus | ecma3/TypeConversion/e9_8_1 | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
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
| avm2 | matrix3d_determinant | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

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

- **Pass:** 679/704 (96.4%)
- **Ignored:** 21 tests
- **Duration:** 1h20m54s across 30 shards
- **Lines:** 109,698/113,120 matching (97.0%)
- **Avg test duration:** 6.6s — slowest: `define_font_glyph_table_order` (44.3s)

### avm2

- **Pass:** 1148/1198 (95.8%)
- **Ignored:** 53 tests
- **Duration:** 3h39m49s across 30 shards
- **Lines:** 133,783/136,522 matching (98.0%)
- **Avg test duration:** 10.4s — slowest: `away3d_advanced_shallow_water_demo` (86.8s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 17.7s — slowest: `device_font_list` (26.1s)

### from_avmplus

- **Pass:** 1515/1572 (96.4%)
- **Ignored:** 2 tests
- **Duration:** 2h52m31s across 30 shards
- **Lines:** 85,406/85,970 matching (99.3%)
- **Avg test duration:** 6.5s — slowest: `ecma3/Statements/eregress_74474_003` (52.9s)

### from_gnash/actionscript.all

- **Pass:** 135/239 (56.5%)
- **Ignored:** 4 tests
- **Duration:** 36m03s across 30 shards
- **Lines:** 29,444/31,544 matching (93.3%)
- **Avg test duration:** 8.7s — slowest: `MovieClip-v8` (68.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 34m09s across 30 shards
- **Lines:** 4,047/5,206 matching (77.7%)
- **Avg test duration:** 18.5s — slowest: `matrix_test` (104.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m58s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 19.8s — slowest: `levels` (22.2s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m52s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 18.4s — slowest: `movieclip_destruction_test1` (22.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m30s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.5s — slowest: `func_dict` (21.1s)

### from_shumway

- **Pass:** 194/207 (93.7%)
- **Ignored:** 22 tests
- **Duration:** 44m00s across 30 shards
- **Lines:** 1,507/1,770 matching (85.1%)
- **Avg test duration:** 10.6s — slowest: `acid/acid-large` (60.2s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m13s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.4s — slowest: `text-bind` (20.6s)

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
