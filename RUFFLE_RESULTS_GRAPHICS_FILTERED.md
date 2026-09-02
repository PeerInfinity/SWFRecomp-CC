# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `0a56091cfce2`  
**Date:** 2026-09-02 18:22 UTC  
**Total duration:** 12h57m26s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 687 | 709 | 96.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1172 | 1212 | 96.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1527 | 1572 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 138 | 239 | 57.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 212 | 223 | 95.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 142 | 144 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4156** | **4439** | **93.6%** | |

*86 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 110,078 | 113,273 | 97.2% |
| avm2 | 137,643 | 139,941 | 98.4% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,422 | 85,970 | 99.4% |
| from_gnash/actionscript.all | 29,470 | 31,544 | 93.4% |
| from_gnash/misc-ming.all | 4,051 | 5,206 | 77.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
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
| **Total** | **372,701** | **382,385** | **97.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 9 | 13 | - |
| avm2 | 31 | 9 | - |
| fonts | - | - | - |
| from_avmplus | 3 | 41 | 1 |
| from_gnash/actionscript.all | 12 | 89 | - |
| from_gnash/misc-ming.all | 12 | 29 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 4 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 5 | 6 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 1 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 2 | - |
| text | 1 | - | - |
| timeline | 2 | 3 | - |
| visual | - | 2 | - |
| **Total** | **81** | **201** | **1** |

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

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.5s — slowest: `g711_event_mulaw` (22.5s)

### avm1

- **Pass:** 687/709 (96.9%)
- **Ignored:** 21 tests
- **Duration:** 1h38m41s across 30 shards
- **Lines:** 110,078/113,273 matching (97.2%)
- **Avg test duration:** 8.0s — slowest: `issue_710` (46.4s)

### avm2

- **Pass:** 1172/1212 (96.7%)
- **Ignored:** 49 tests
- **Duration:** 4h13m14s across 30 shards
- **Lines:** 137,643/139,941 matching (98.4%)
- **Avg test duration:** 11.9s — slowest: `away3d_advanced_shallow_water_demo` (102.8s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m08s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 21.4s — slowest: `embed_matching/fallback_preferences` (31.5s)

### from_avmplus

- **Pass:** 1527/1572 (97.1%)
- **Ignored:** 2 tests
- **Duration:** 3h27m19s across 30 shards
- **Lines:** 85,422/85,970 matching (99.4%)
- **Avg test duration:** 7.8s — slowest: `ecma3/Statements/eregress_74474_003` (56.0s)

### from_gnash/actionscript.all

- **Pass:** 138/239 (57.7%)
- **Ignored:** 4 tests
- **Duration:** 39m07s across 30 shards
- **Lines:** 29,470/31,544 matching (93.4%)
- **Avg test duration:** 9.5s — slowest: `MovieClip-v8` (67.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 35m59s across 30 shards
- **Lines:** 4,051/5,206 matching (77.8%)
- **Avg test duration:** 19.4s — slowest: `matrix_test` (89.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.7s — slowest: `inheritance` (25.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 6m10s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 19.2s — slowest: `hello` (25.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m52s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.6s — slowest: `func_dict` (23.0s)

### from_shumway

- **Pass:** 212/223 (95.1%)
- **Ignored:** 6 tests
- **Duration:** 50m30s across 30 shards
- **Lines:** 2,278/2,409 matching (94.6%)
- **Avg test duration:** 12.9s — slowest: `acid/acid-large` (84.3s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 3m27s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 4.0s — slowest: `moviecliploader` (21.8s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 45s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.9s — slowest: `avm1_non_swf_import` (23.0s)

### mixed_avm

- **Pass:** 10/11 (90.9%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 49/53 matching (92.5%)
- **Avg test duration:** 7.5s — slowest: `avm1_sprite_sc_ignored` (22.2s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 20m26s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 17.0s — slowest: `avm2_slot_default_template` (35.8s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.3s — slowest: `scissor_rectangle` (11.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 10.6s — slowest: `lzma_length_too_long` (22.5s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m39s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 19.9s — slowest: `auto_size/return` (31.4s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m40s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 23.5s — slowest: `swf_9_frame_script_dynamic_goto_2` (30.8s)

### visual

- **Pass:** 142/144 (98.6%)
- **Duration:** 34m25s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.3s — slowest: `definefont4` (97.6s)
