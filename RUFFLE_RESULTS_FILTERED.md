# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `06f3d87d295b`  
**Date:** 2026-08-30 08:49 UTC  
**Total duration:** 9h31m01s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 687 | 705 | 97.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1172 | 1210 | 96.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 6 | 7 | 85.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1527 | 1572 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 138 | 239 | 57.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 212 | 223 | 95.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 144 | 146 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4158** | **4436** | **93.7%** | |

*86 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 110,071 | 113,220 | 97.2% |
| avm2 | 137,640 | 139,884 | 98.4% |
| fonts | 190 | 346 | 54.9% |
| from_avmplus | 85,422 | 85,970 | 99.4% |
| from_gnash/actionscript.all | 29,470 | 31,544 | 93.4% |
| from_gnash/misc-ming.all | 4,051 | 5,206 | 77.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,278 | 2,409 | 94.6% |
| from_shumway/avm1 | 487 | 487 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 49 | 53 | 92.5% |
| regression | 483 | 483 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **372,780** | **382,517** | **97.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 5 | 13 | - |
| avm2 | 29 | 9 | - |
| fonts | 1 | - | - |
| from_avmplus | 3 | 41 | 1 |
| from_gnash/actionscript.all | 12 | 89 | - |
| from_gnash/misc-ming.all | 12 | 29 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 4 | 7 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 1 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 2 | - |
| text | 1 | - | - |
| timeline | 2 | 3 | - |
| visual | - | 2 | - |
| **Total** | **74** | **203** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_avmplus | as3/Array/insertremove | 100% |
| from_gnash/actionscript.all | Function-v7 | 97% |
| from_gnash/actionscript.all | Function-v8 | 97% |
| from_gnash/actionscript.all | Function-v6 | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | vector3d_near_equals | 84% |
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
- **Duration:** 1m16s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.3s — slowest: `stream_incomplete_loop` (22.0s)

### avm1

- **Pass:** 687/705 (97.4%)
- **Ignored:** 21 tests
- **Duration:** 51m14s across 30 shards
- **Lines:** 110,071/113,220 matching (97.2%)
- **Avg test duration:** 4.1s — slowest: `movieclip_invalid_get_bounds_7` (26.5s)

### avm2

- **Pass:** 1172/1210 (96.9%)
- **Ignored:** 49 tests
- **Duration:** 3h02m10s across 30 shards
- **Lines:** 137,640/139,884 matching (98.4%)
- **Avg test duration:** 8.6s — slowest: `away3d_advanced_shallow_water_demo` (86.3s)

### fonts

- **Pass:** 6/7 (85.7%)
- **Duration:** 2m17s across 30 shards
- **Lines:** 190/346 matching (54.9%)
- **Avg test duration:** 19.5s — slowest: `embed_matching/fallback_preferences` (27.4s)

### from_avmplus

- **Pass:** 1527/1572 (97.1%)
- **Ignored:** 2 tests
- **Duration:** 2h54m11s across 30 shards
- **Lines:** 85,422/85,970 matching (99.4%)
- **Avg test duration:** 6.6s — slowest: `ecma3/Statements/eregress_74474_003` (66.6s)

### from_gnash/actionscript.all

- **Pass:** 138/239 (57.7%)
- **Ignored:** 4 tests
- **Duration:** 21m02s across 30 shards
- **Lines:** 29,470/31,544 matching (93.4%)
- **Avg test duration:** 5.1s — slowest: `MovieClip-v8` (65.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 28m59s across 30 shards
- **Lines:** 4,051/5,206 matching (77.8%)
- **Avg test duration:** 15.7s — slowest: `matrix_test` (89.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m01s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 20.1s — slowest: `levels` (22.6s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m27s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 17.2s — slowest: `movieclip_destruction_test3` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m28s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.4s — slowest: `dict_event` (21.9s)

### from_shumway

- **Pass:** 212/223 (95.1%)
- **Ignored:** 6 tests
- **Duration:** 38m42s across 30 shards
- **Lines:** 2,278/2,409 matching (94.6%)
- **Avg test duration:** 9.9s — slowest: `acid/acid-large` (78.2s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 1m49s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 1.9s — slowest: `label` (17.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 45s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.8s — slowest: `avm1_non_swf_import` (22.0s)

### mixed_avm

- **Pass:** 10/11 (90.9%)
- **Duration:** 48s across 30 shards
- **Lines:** 49/53 matching (92.5%)
- **Avg test duration:** 4.3s — slowest: `avm2_loads_avm1_v9` (7.5s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 13m01s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 10.8s — slowest: `avm2_graphics_runtime` (28.2s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.5s — slowest: `scissor_rectangle_invalid` (10.0s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 45s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 6.4s — slowest: `lzma_length_too_long` (21.4s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m21s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.3s — slowest: `auto_size/return` (27.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 3m12s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 11.3s — slowest: `frame_script_button_order` (27.5s)

### visual

- **Pass:** 144/146 (98.6%)
- **Duration:** 31m42s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.0s — slowest: `definefont4` (95.8s)
