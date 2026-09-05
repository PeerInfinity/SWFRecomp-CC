# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `12d2ec06b7bf`  
**Date:** 2026-09-05 05:20 UTC  
**Total duration:** 12h26m53s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 689 | 709 | 97.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1190 | 1214 | 98.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 7 | 85.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1529 | 1572 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 141 | 239 | 59.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 213 | 223 | 95.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 89 | 89 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 144 | 146 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4204** | **4464** | **94.2%** | |

*84 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 110,090 | 113,273 | 97.2% |
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
| **Total** | **374,830** | **383,776** | **97.7%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 7 | 13 | - |
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
| **Total** | **54** | **205** | **1** |

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

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.5s — slowest: `stream_incomplete_loop` (21.1s)

### avm1

- **Pass:** 689/709 (97.2%)
- **Ignored:** 21 tests
- **Duration:** 1h24m21s across 30 shards
- **Lines:** 110,090/113,273 matching (97.2%)
- **Avg test duration:** 6.8s — slowest: `strictequals_swf6` (39.9s)

### avm2

- **Pass:** 1190/1214 (98.0%)
- **Ignored:** 47 tests
- **Duration:** 3h57m07s across 30 shards
- **Lines:** 139,290/140,866 matching (98.9%)
- **Avg test duration:** 11.2s — slowest: `away3d_advanced_shallow_water_demo` (70.0s)

### fonts

- **Pass:** 6/7 (85.7%)
- **Duration:** 2m25s across 30 shards
- **Lines:** 190/346 matching (54.9%)
- **Avg test duration:** 20.8s — slowest: `device_font_kerning` (29.9s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 3h33m15s across 30 shards
- **Lines:** 85,546/85,970 matching (99.5%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_002` (54.9s)

### from_gnash/actionscript.all

- **Pass:** 141/239 (59.0%)
- **Ignored:** 4 tests
- **Duration:** 33m02s across 30 shards
- **Lines:** 29,502/31,544 matching (93.5%)
- **Avg test duration:** 8.0s — slowest: `MovieClip-v8` (60.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 35m32s across 30 shards
- **Lines:** 4,051/5,206 matching (77.8%)
- **Avg test duration:** 19.1s — slowest: `matrix_test` (111.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m38s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 10.9s — slowest: `implementsOpTest` (23.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 6m02s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 18.7s — slowest: `edittext_test1` (24.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m53s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.6s — slowest: `background` (23.1s)

### from_shumway

- **Pass:** 213/223 (95.5%)
- **Ignored:** 6 tests
- **Duration:** 48m36s across 30 shards
- **Lines:** 2,276/2,409 matching (94.5%)
- **Avg test duration:** 12.4s — slowest: `acid/acid-large` (73.5s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 3m14s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 3.7s — slowest: `text-bind` (22.2s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.3s — slowest: `avm1_non_swf_import` (23.2s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 56/79 matching (70.9%)
- **Avg test duration:** 7.7s — slowest: `avm1_sprite_sc_ignored` (21.3s)

### regression

- **Pass:** 89/89 (100%)
- **Duration:** 23m41s across 30 shards
- **Lines:** 681/681 matching (100%)
- **Avg test duration:** 15.9s — slowest: `avm2_timeline_solid` (36.0s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.5s — slowest: `unbound_texture` (11.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 54s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 7.6s — slowest: `lzma_length_too_long` (22.3s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m46s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.5s — slowest: `auto_size/return` (33.4s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 6m11s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 21.8s — slowest: `frame_script_cleanup3` (29.4s)

### visual

- **Pass:** 144/146 (98.6%)
- **Duration:** 35m29s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.5s — slowest: `definefont4` (93.4s)
