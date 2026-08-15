# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `aeebf9ede383`  
**Date:** 2026-08-15 10:09 UTC  
**Total duration:** 10h42m37s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 679 | 704 | 96.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1150 | 1190 | 96.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1515 | 1572 | 96.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 135 | 239 | 56.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 194 | 207 | 93.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 142 | 144 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4092** | **4394** | **93.1%** | |

*106 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 109,698 | 113,120 | 97.0% |
| avm2 | 133,578 | 135,884 | 98.3% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,406 | 85,970 | 99.3% |
| from_gnash/actionscript.all | 29,444 | 31,544 | 93.3% |
| from_gnash/misc-ming.all | 4,047 | 5,206 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
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
| **Total** | **367,412** | **377,499** | **97.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 12 | 13 | - |
| avm2 | 32 | 8 | - |
| fonts | - | - | - |
| from_avmplus | 3 | 53 | 1 |
| from_gnash/actionscript.all | 12 | 92 | - |
| from_gnash/misc-ming.all | 12 | 29 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 4 | - |
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
| **Total** | **86** | **215** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | button_nested_frame_simple | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
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
| avm2 | matrix3d_determinant | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.4s — slowest: `stream_incomplete_loop` (23.2s)

### avm1

- **Pass:** 679/704 (96.4%)
- **Ignored:** 21 tests
- **Duration:** 1h01m51s across 30 shards
- **Lines:** 109,698/113,120 matching (97.0%)
- **Avg test duration:** 5.0s — slowest: `edittext_paste_empty` (32.4s)

### avm2

- **Pass:** 1150/1190 (96.6%)
- **Ignored:** 53 tests
- **Duration:** 3h28m00s across 30 shards
- **Lines:** 133,578/135,884 matching (98.3%)
- **Avg test duration:** 9.9s — slowest: `away3d_advanced_shallow_water_demo` (94.4s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 19.1s — slowest: `device_font_list` (28.1s)

### from_avmplus

- **Pass:** 1515/1572 (96.4%)
- **Ignored:** 2 tests
- **Duration:** 3h20m57s across 30 shards
- **Lines:** 85,406/85,970 matching (99.3%)
- **Avg test duration:** 7.6s — slowest: `ecma3/Statements/eregress_74474_002` (73.5s)

### from_gnash/actionscript.all

- **Pass:** 135/239 (56.5%)
- **Ignored:** 4 tests
- **Duration:** 24m30s across 30 shards
- **Lines:** 29,444/31,544 matching (93.3%)
- **Avg test duration:** 5.9s — slowest: `MovieClip-v8` (69.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 27m17s across 30 shards
- **Lines:** 4,047/5,206 matching (77.7%)
- **Avg test duration:** 14.8s — slowest: `matrix_test` (107.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m07s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 20.8s — slowest: `levels` (23.4s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 4m56s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 15.1s — slowest: `opcode_guard_test2` (24.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m57s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.8s — slowest: `missing_bitmap` (27.1s)

### from_shumway

- **Pass:** 194/207 (93.7%)
- **Ignored:** 22 tests
- **Duration:** 44m48s across 30 shards
- **Lines:** 1,507/1,770 matching (85.1%)
- **Avg test duration:** 10.7s — slowest: `acid/acid-large` (81.7s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m33s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.8s — slowest: `label` (21.6s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 46s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.3s — slowest: `avm1_non_swf_import` (22.3s)

### mixed_avm

- **Pass:** 10/11 (90.9%)
- **Duration:** 53s across 30 shards
- **Lines:** 49/53 matching (92.5%)
- **Avg test duration:** 4.8s — slowest: `avm2_loads_avm1_v9` (8.8s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 10m50s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 9.0s — slowest: `avm2_graphics_runtime` (28.2s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.8s — slowest: `sampler_odd_size` (11.2s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 26s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 5.1s — slowest: `swf_length_too_short_no_second_frame` (17.3s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m36s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 19.6s — slowest: `text_caret_placement_align` (28.4s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 3m10s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 11.1s — slowest: `frame_script_button_order` (27.5s)

### visual

- **Pass:** 142/144 (98.6%)
- **Duration:** 33m56s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.1s — slowest: `definefont4` (105.5s)
