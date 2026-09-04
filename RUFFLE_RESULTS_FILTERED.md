# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `4a8e7476d975`  
**Date:** 2026-09-04 19:03 UTC  
**Total duration:** 9h23m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 687 | 709 | 96.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1172 | 1212 | 96.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
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
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 88 | 88 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 144 | 146 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4174** | **4459** | **93.6%** | |

*86 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 110,078 | 113,273 | 97.2% |
| avm2 | 137,622 | 139,954 | 98.3% |
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
| mixed_avm | 56 | 79 | 70.9% |
| regression | 678 | 678 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **372,971** | **382,861** | **97.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 9 | 13 | - |
| avm2 | 31 | 9 | - |
| fonts | 1 | - | - |
| from_avmplus | 3 | 41 | 1 |
| from_gnash/actionscript.all | 12 | 89 | - |
| from_gnash/misc-ming.all | 12 | 29 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 5 | 6 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 2 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 2 | - |
| text | 1 | - | - |
| timeline | 2 | 3 | - |
| visual | - | 2 | - |
| **Total** | **82** | **202** | **1** |

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
| avm2 | large_preload_from_bytes | 80% |

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
- **Avg test duration:** 15.3s — slowest: `stream_incomplete_loop` (21.6s)

### avm1

- **Pass:** 687/709 (96.9%)
- **Ignored:** 21 tests
- **Duration:** 51m39s across 30 shards
- **Lines:** 110,078/113,273 matching (97.2%)
- **Avg test duration:** 4.1s — slowest: `define_font_glyph_table_order` (26.7s)

### avm2

- **Pass:** 1172/1212 (96.7%)
- **Ignored:** 49 tests
- **Duration:** 2h58m00s across 30 shards
- **Lines:** 137,622/139,954 matching (98.3%)
- **Avg test duration:** 8.4s — slowest: `away3d_advanced_shallow_water_demo` (85.4s)

### fonts

- **Pass:** 6/7 (85.7%)
- **Duration:** 2m20s across 30 shards
- **Lines:** 190/346 matching (54.9%)
- **Avg test duration:** 20.0s — slowest: `device_font_kerning` (27.7s)

### from_avmplus

- **Pass:** 1527/1572 (97.1%)
- **Ignored:** 2 tests
- **Duration:** 2h56m39s across 30 shards
- **Lines:** 85,422/85,970 matching (99.4%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_003` (62.8s)

### from_gnash/actionscript.all

- **Pass:** 138/239 (57.7%)
- **Ignored:** 4 tests
- **Duration:** 21m00s across 30 shards
- **Lines:** 29,470/31,544 matching (93.4%)
- **Avg test duration:** 5.1s — slowest: `MovieClip-v8` (70.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 28m10s across 30 shards
- **Lines:** 4,051/5,206 matching (77.8%)
- **Avg test duration:** 15.3s — slowest: `matrix_test` (109.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 10.3s — slowest: `implementsOpTest` (21.6s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m30s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 17.0s — slowest: `action_execution_order_test12` (23.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m42s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.1s — slowest: `trace-as2/this` (21.4s)

### from_shumway

- **Pass:** 212/223 (95.1%)
- **Ignored:** 6 tests
- **Duration:** 38m25s across 30 shards
- **Lines:** 2,278/2,409 matching (94.6%)
- **Avg test duration:** 9.7s — slowest: `acid/acid-large` (75.2s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m18s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.5s — slowest: `moviecliploader` (21.3s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 46s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.2s — slowest: `avm1_non_swf_import` (22.9s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m04s across 30 shards
- **Lines:** 56/79 matching (70.9%)
- **Avg test duration:** 5.3s — slowest: `avm2_loads_avm1_events` (7.6s)

### regression

- **Pass:** 88/88 (100%)
- **Duration:** 9m47s across 30 shards
- **Lines:** 678/678 matching (100%)
- **Avg test duration:** 6.6s — slowest: `avm2_parent_child_symbol_stride` (29.1s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 42s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.4s — slowest: `scissor_rectangle_invalid` (9.6s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 27s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 3.8s — slowest: `convolution_filter_big_matrix` (17.9s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m35s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 19.5s — slowest: `text_caret_placement_align` (29.1s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 2m46s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 9.8s — slowest: `missing_frame_scripts` (27.2s)

### visual

- **Pass:** 144/146 (98.6%)
- **Duration:** 30m51s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.6s — slowest: `definefont4` (92.5s)
