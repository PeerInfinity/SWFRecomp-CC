# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `bf907d0023cc`  
**Date:** 2026-09-06 08:47 UTC  
**Total duration:** 9h25m27s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 689 | 710 | 97.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1191 | 1215 | 98.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 6 | 7 | 85.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1529 | 1572 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 141 | 239 | 59.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 213 | 223 | 95.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 89 | 89 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 144 | 146 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4205** | **4466** | **94.2%** | |

*84 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 110,101 | 113,307 | 97.2% |
| avm2 | 139,290 | 140,866 | 98.9% |
| fonts | 190 | 346 | 54.9% |
| from_avmplus | 85,546 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 29,502 | 31,544 | 93.5% |
| from_gnash/misc-ming.all | 4,051 | 5,206 | 77.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,276 | 2,409 | 94.5% |
| from_shumway/avm1 | 487 | 487 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 56 | 79 | 70.9% |
| regression | 681 | 681 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **374,841** | **383,810** | **97.7%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 7 | 14 | - |
| avm2 | 12 | 12 | - |
| fonts | 1 | - | - |
| from_avmplus | 1 | 41 | 1 |
| from_gnash/actionscript.all | 9 | 89 | - |
| from_gnash/misc-ming.all | 12 | 29 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 4 | 6 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 2 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 2 | - |
| text | 1 | - | - |
| timeline | 1 | 3 | - |
| visual | - | 2 | - |
| **Total** | **54** | **206** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v6 | 97% |
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
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.8s — slowest: `stream_incomplete_loop` (21.0s)

### avm1

- **Pass:** 689/710 (97.0%)
- **Ignored:** 21 tests
- **Duration:** 55m35s across 30 shards
- **Lines:** 110,101/113,307 matching (97.2%)
- **Avg test duration:** 4.4s — slowest: `define_font_glyph_table_order` (27.2s)

### avm2

- **Pass:** 1191/1215 (98.0%)
- **Ignored:** 47 tests
- **Duration:** 3h06m27s across 30 shards
- **Lines:** 139,290/140,866 matching (98.9%)
- **Avg test duration:** 8.8s — slowest: `away3d_advanced_shallow_water_demo` (85.2s)

### fonts

- **Pass:** 6/7 (85.7%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 190/346 matching (54.9%)
- **Avg test duration:** 18.0s — slowest: `device_font_list` (27.8s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 2h51m25s across 30 shards
- **Lines:** 85,546/85,970 matching (99.5%)
- **Avg test duration:** 6.5s — slowest: `ecma3/Statements/eregress_74474_003` (55.4s)

### from_gnash/actionscript.all

- **Pass:** 141/239 (59.0%)
- **Ignored:** 4 tests
- **Duration:** 20m22s across 30 shards
- **Lines:** 29,502/31,544 matching (93.5%)
- **Avg test duration:** 4.9s — slowest: `MovieClip-v8` (54.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 20m53s across 30 shards
- **Lines:** 4,051/5,206 matching (77.8%)
- **Avg test duration:** 11.3s — slowest: `matrix_test` (108.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m34s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 10.5s — slowest: `exception` (22.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 4m36s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 14.1s — slowest: `soft_reference_test1` (22.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m32s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 7.6s — slowest: `dict_callframe` (21.4s)

### from_shumway

- **Pass:** 213/223 (95.5%)
- **Ignored:** 6 tests
- **Duration:** 40m17s across 30 shards
- **Lines:** 2,276/2,409 matching (94.5%)
- **Avg test duration:** 10.2s — slowest: `acid/acid-large` (74.6s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m35s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.9s — slowest: `label` (21.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 39s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.0s — slowest: `empty_url` (21.6s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 56/79 matching (70.9%)
- **Avg test duration:** 6.3s — slowest: `avm1_sprite_sc_ignored` (20.1s)

### regression

- **Pass:** 89/89 (100%)
- **Duration:** 12m44s across 30 shards
- **Lines:** 681/681 matching (100%)
- **Avg test duration:** 8.5s — slowest: `avm2_timeline_solid` (27.9s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 57s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.0s — slowest: `sampler_odd_size` (10.2s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 40s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 5.6s — slowest: `convolution_filter_big_matrix` (17.3s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m07s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 17.0s — slowest: `text_caret_placement_leading` (28.5s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 5m49s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 20.5s — slowest: `swf_9_frame_script_cleanup_goto2` (28.4s)

### visual

- **Pass:** 144/146 (98.6%)
- **Duration:** 30m31s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.5s — slowest: `definefont4` (80.8s)
