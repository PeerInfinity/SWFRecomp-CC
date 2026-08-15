# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `0a99be1a92de`  
**Date:** 2026-08-09 08:51 UTC  
**Total duration:** 10h43m19s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 672 | 697 | 96.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1107 | 1174 | 94.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1514 | 1572 | 96.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 135 | 239 | 56.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 189 | 207 | 91.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 2 | 3 | 66.7% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 71 | 71 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 140 | 143 | 97.9% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4026** | **4369** | **92.1%** | |

*106 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 106,727 | 112,964 | 94.5% |
| avm2 | 114,578 | 133,993 | 85.5% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,403 | 85,970 | 99.3% |
| from_gnash/actionscript.all | 29,443 | 31,544 | 93.3% |
| from_gnash/misc-ming.all | 4,047 | 5,206 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,478 | 1,770 | 83.5% |
| from_shumway/avm1 | 487 | 487 | 100% |
| import_assets | 8 | 14 | 57.1% |
| mixed_avm | 26 | 53 | 49.1% |
| regression | 482 | 482 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **345,381** | **375,451** | **92.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 12 | 13 | - |
| avm2 | 62 | 5 | - |
| fonts | - | - | - |
| from_avmplus | 3 | 54 | 1 |
| from_gnash/actionscript.all | 9 | 95 | - |
| from_gnash/misc-ming.all | 12 | 29 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 9 | 9 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 1 | - | - |
| mixed_avm | 7 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 1 | - |
| text | 1 | - | - |
| timeline | 2 | 3 | - |
| visual | 1 | 2 | - |
| **Total** | **123** | **219** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | button_nested_frame_simple | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm1 | watch_recursion_swf7 | 99% |
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
| mixed_avm | avm2_loads_avm1_v9 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
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
- **Avg test duration:** 14.7s — slowest: `stream_incomplete_loop` (19.9s)

### avm1

- **Pass:** 672/697 (96.4%)
- **Ignored:** 21 tests
- **Duration:** 1h21m36s across 30 shards
- **Lines:** 106,727/112,964 matching (94.5%)
- **Avg test duration:** 6.7s — slowest: `define_font_glyph_table_order` (42.0s)

### avm2

- **Pass:** 1107/1174 (94.3%)
- **Ignored:** 53 tests
- **Duration:** 3h16m15s across 30 shards
- **Lines:** 114,578/133,993 matching (85.5%)
- **Avg test duration:** 9.4s — slowest: `away3d_advanced_shallow_water_demo` (83.7s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 1m57s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 19.6s — slowest: `embed_matching/fallback_preferences` (27.1s)

### from_avmplus

- **Pass:** 1514/1572 (96.3%)
- **Ignored:** 2 tests
- **Duration:** 2h51m01s across 30 shards
- **Lines:** 85,403/85,970 matching (99.3%)
- **Avg test duration:** 6.5s — slowest: `ecma3/Statements/eregress_74474_002` (57.0s)

### from_gnash/actionscript.all

- **Pass:** 135/239 (56.5%)
- **Ignored:** 4 tests
- **Duration:** 36m17s across 30 shards
- **Lines:** 29,443/31,544 matching (93.3%)
- **Avg test duration:** 8.7s — slowest: `MovieClip-v8` (67.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 35m02s across 30 shards
- **Lines:** 4,047/5,206 matching (77.7%)
- **Avg test duration:** 18.9s — slowest: `matrix_test` (107.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m06s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 20.6s — slowest: `levels` (23.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m45s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 17.9s — slowest: `swf4opcode` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m28s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.3s — slowest: `initaction_in_definesprite` (21.3s)

### from_shumway

- **Pass:** 189/207 (91.3%)
- **Ignored:** 22 tests
- **Duration:** 43m21s across 30 shards
- **Lines:** 1,478/1,770 matching (83.5%)
- **Avg test duration:** 10.4s — slowest: `acid/acid-large` (76.0s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 1m40s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.1s — slowest: `label` (20.8s)

### import_assets

- **Pass:** 2/3 (66.7%)
- **Duration:** 44s across 30 shards
- **Lines:** 8/14 matching (57.1%)
- **Avg test duration:** 14.5s — slowest: `avm1_non_swf_import` (21.4s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 26/53 matching (49.1%)
- **Avg test duration:** 6.2s — slowest: `avm1_sprite_sc_ignored` (19.8s)

### regression

- **Pass:** 71/71 (100%)
- **Duration:** 18m11s across 30 shards
- **Lines:** 482/482 matching (100%)
- **Avg test duration:** 15.3s — slowest: `avm2_timeline_gradients` (43.1s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.0s — slowest: `sampler_odd_size` (9.0s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 44s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 8.8s — slowest: `swf_length_too_short_no_second_frame` (20.0s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m21s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.3s — slowest: `text_caret_placement_align` (28.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 5m33s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 19.5s — slowest: `frame_script_cleanup_goto2` (27.4s)

### visual

- **Pass:** 140/143 (97.9%)
- **Duration:** 29m08s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.2s — slowest: `definefont4` (87.7s)
