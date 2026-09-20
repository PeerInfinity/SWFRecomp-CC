# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `53a188c38f4e`  
**Date:** 2026-09-20 08:49 UTC  
**Total duration:** 9h48m27s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 700 | 735 | 95.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1217 | 1275 | 95.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 213 | 229 | 93.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 96 | 96 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4251** | **4576** | **92.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 121,054 | 132,315 | 91.5% |
| avm2 | 154,578 | 157,157 | 98.4% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,560 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,495 | 38,791 | 78.6% |
| from_gnash/misc-ming.all | 4,197 | 5,248 | 80.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,393 | 2,484 | 96.3% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 764 | 764 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **402,458** | **426,629** | **94.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 15 | - |
| avm2 | 20 | - |
| fonts | 1 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 11 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 4 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 1 | - |
| visual | - | - |
| **Total** | **77** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | array-v7 | 97% |
| from_gnash/actionscript.all | array-v8 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm1 | geturl | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

*No changes since last run.*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.4s — slowest: `stream_incomplete_loop` (22.9s)

### avm1

- **Pass:** 700/735 (95.2%)
- **Duration:** 45m29s across 30 shards
- **Lines:** 121,054/132,315 matching (91.5%)
- **Avg test duration:** 3.7s — slowest: `netstream_play_flv_screen` (36.4s)

### avm2

- **Pass:** 1217/1275 (95.5%)
- **Duration:** 3h09m47s across 30 shards
- **Lines:** 154,578/157,157 matching (98.4%)
- **Avg test duration:** 8.9s — slowest: `away3d_advanced_shallow_water_demo` (98.4s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m51s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 21.4s — slowest: `embed_matching/fallback_preferences` (30.4s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h07m31s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 7.1s — slowest: `ecma3/Statements/eregress_74474_003` (57.1s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 21m04s across 30 shards
- **Lines:** 30,495/38,791 matching (78.6%)
- **Avg test duration:** 5.1s — slowest: `MovieClip-v8` (67.4s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 28m25s across 30 shards
- **Lines:** 4,197/5,248 matching (80.0%)
- **Avg test duration:** 15.3s — slowest: `matrix_test` (105.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.6s — slowest: `implementsOpTest` (22.4s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m14s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 15.6s — slowest: `movieclip_destruction_test1` (24.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m32s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.6s — slowest: `dict_event` (22.2s)

### from_shumway

- **Pass:** 213/229 (93.0%)
- **Duration:** 40m04s across 30 shards
- **Lines:** 2,393/2,484 matching (96.3%)
- **Avg test duration:** 10.4s — slowest: `acid/acid-large` (78.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.4s — slowest: `text-bind` (20.8s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.7s — slowest: `empty_url` (21.6s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m06s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 5.5s — slowest: `avm2_loads_avm1_v10` (8.1s)

### regression

- **Pass:** 96/96 (100%)
- **Duration:** 14m47s across 30 shards
- **Lines:** 764/764 matching (100%)
- **Avg test duration:** 9.2s — slowest: `avm2_parent_child_render` (30.0s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m06s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.4s — slowest: `scissor_rectangle_invalid` (10.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 10s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 1.4s — slowest: `swf_length_too_short_no_end` (1.6s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m40s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.0s — slowest: `text_caret_placement_scroll` (28.1s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 2m27s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 8.6s — slowest: `frame_script_button_order` (27.3s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 32m17s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.1s — slowest: `definefont4` (114.8s)
