# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `1d87c1cfba93`  
**Date:** 2026-09-05 06:00 UTC  
**Total duration:** 10h44m04s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 689 | 709 | 97.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1190 | 1214 | 98.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
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

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.6s — slowest: `g711_event_mulaw` (20.0s)

### avm1

- **Pass:** 689/709 (97.2%)
- **Ignored:** 21 tests
- **Duration:** 1h09m53s across 30 shards
- **Lines:** 110,090/113,273 matching (97.2%)
- **Avg test duration:** 5.6s — slowest: `define_font_glyph_table_order` (28.5s)

### avm2

- **Pass:** 1190/1214 (98.0%)
- **Ignored:** 47 tests
- **Duration:** 3h27m42s across 30 shards
- **Lines:** 139,290/140,866 matching (98.9%)
- **Avg test duration:** 9.8s — slowest: `away3d_advanced_shallow_water_demo` (80.5s)

### fonts

- **Pass:** 6/7 (85.7%)
- **Duration:** 2m17s across 30 shards
- **Lines:** 190/346 matching (54.9%)
- **Avg test duration:** 19.6s — slowest: `device_font_glyph_fallback` (27.6s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 2h56m40s across 30 shards
- **Lines:** 85,546/85,970 matching (99.5%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_002` (53.9s)

### from_gnash/actionscript.all

- **Pass:** 141/239 (59.0%)
- **Ignored:** 4 tests
- **Duration:** 29m47s across 30 shards
- **Lines:** 29,502/31,544 matching (93.5%)
- **Avg test duration:** 7.2s — slowest: `MovieClip-v8` (66.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 32m35s across 30 shards
- **Lines:** 4,051/5,206 matching (77.8%)
- **Avg test duration:** 17.5s — slowest: `matrix_test` (110.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m34s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 10.4s — slowest: `implementsOpTest` (21.6s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m30s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 17.2s — slowest: `movieclip_destruction_test1` (22.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m24s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.2s — slowest: `afunc_dict` (21.2s)

### from_shumway

- **Pass:** 213/223 (95.5%)
- **Ignored:** 6 tests
- **Duration:** 42m59s across 30 shards
- **Lines:** 2,276/2,409 matching (94.5%)
- **Avg test duration:** 10.9s — slowest: `acid/acid-large` (64.8s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m26s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.7s — slowest: `text-bind` (21.2s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.4s — slowest: `avm1_non_swf_import` (21.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 56/79 matching (70.9%)
- **Avg test duration:** 6.5s — slowest: `avm1_sprite_sc_ignored` (20.1s)

### regression

- **Pass:** 89/89 (100%)
- **Duration:** 21m09s across 30 shards
- **Lines:** 681/681 matching (100%)
- **Avg test duration:** 14.2s — slowest: `avm2_gc_dynprop_tombstone_purge` (30.4s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 59s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.4s — slowest: `unbound_texture` (9.7s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 48s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 6.9s — slowest: `convolution_filter_big_matrix` (21.0s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m19s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.1s — slowest: `text_caret_placement_scroll` (28.0s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 5m31s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 19.5s — slowest: `missing_frame_scripts` (27.4s)

### visual

- **Pass:** 144/146 (98.6%)
- **Duration:** 31m08s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.7s — slowest: `definefont4` (90.6s)
