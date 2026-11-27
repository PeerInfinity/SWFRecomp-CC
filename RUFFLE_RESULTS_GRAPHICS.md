# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `dbc43c157352`  
**Date:** 2026-11-27 03:35 UTC  
**Total duration:** 13h36m58s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 776 | 791 | 98.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1316 | 1352 | 97.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1564 | 1574 | 99.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 181 | 243 | 74.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 74 | 111 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 17 | 21 | 81.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 315 | 316 | 99.7% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4747** | **4937** | **96.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,761 | 137,880 | 91.2% |
| avm2 | 163,035 | 164,470 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,953 | 85,996 | 99.9% |
| from_gnash/actionscript.all | 31,177 | 38,791 | 80.4% |
| from_gnash/misc-ming.all | 4,364 | 5,248 | 83.2% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 565 | 603 | 93.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,197 | 3,199 | 99.9% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **419,672** | **441,992** | **95.0%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 10 |
| avm2 | 6 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 1 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 1 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | 1 |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **34** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | loader_load | 98% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | 4 | - |
| from_gnash/actionscript.all | - | - | 82 | - |
| from_gnash/misc-ming.all | - | - | 5 | - |
| from_gnash/misc-swfc.all | - | - | 36 | - |
| from_shumway | 1 | - | 1 | - |

**avm1 — newly passing:** `attach_movie_export_not_yet_run`, `load_cancel_via_unloadclip`, `tab_ordering_properties_tab_index_edge_case`

**from_gnash/actionscript.all — newly passing:** `MovieClip-v5`, `MovieClip-v6`, `MovieClip-v7`, `MovieClip-v8`

**from_gnash/misc-ming.all — newly passing:** `matrix_test`

**from_gnash/misc-swfc.all — newly passing:** `gotoFrameFromInterval`, `gotoFrameFromInterval2`

**from_shumway — newly passing:** `as3-loader/bug1157243/empty`

*Comparing `6ee6eded7b66` → `dbc43c157352`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 2m02s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 24.6s — slowest: `g711` (32.5s)

### avm1

- **Pass:** 776/791 (98.1%)
- **Duration:** 1h28m08s across 30 shards
- **Lines:** 125,761/137,880 matching (91.2%)
- **Avg test duration:** 6.6s — slowest: `define_function2_preload` (49.4s)

### avm2

- **Pass:** 1316/1352 (97.3%)
- **Duration:** 4h18m16s across 30 shards
- **Lines:** 163,035/164,470 matching (99.1%)
- **Avg test duration:** 11.4s — slowest: `away3d_advanced_shallow_water_demo` (117.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m02s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 20.3s — slowest: `device_font_kerning` (34.0s)

### from_avmplus

- **Pass:** 1564/1574 (99.4%)
- **Duration:** 3h29m29s across 30 shards
- **Lines:** 85,953/85,996 matching (99.9%)
- **Avg test duration:** 7.9s — slowest: `ecma3/Statements/eregress_74474_003` (59.6s)

### from_gnash/actionscript.all

- **Pass:** 181/243 (74.5%)
- **Duration:** 32m39s across 30 shards
- **Lines:** 31,177/38,791 matching (80.4%)
- **Avg test duration:** 8.0s — slowest: `MovieClip-v8` (71.3s)

### from_gnash/misc-ming.all

- **Pass:** 74/111 (66.7%)
- **Duration:** 34m43s across 30 shards
- **Lines:** 4,364/5,248 matching (83.2%)
- **Avg test duration:** 18.7s — slowest: `matrix_test` (79.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m02s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 13.6s — slowest: `exception` (26.4s)

### from_gnash/misc-swfc.all

- **Pass:** 17/21 (81.0%)
- **Duration:** 5m43s across 30 shards
- **Lines:** 565/603 matching (93.7%)
- **Avg test duration:** 16.3s — slowest: `movieclip_destruction_test4` (26.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m39s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.9s — slowest: `dict_callframe` (25.4s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 49m06s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 12.8s — slowest: `acid/acid-large` (69.9s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m21s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.0s — slowest: `text-bind` (20.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 54s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 18.1s — slowest: `empty_url` (26.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m30s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.5s — slowest: `avm1_sprite_sc_ignored` (19.8s)

### regression

- **Pass:** 315/316 (99.7%)
- **Duration:** 1h09m47s across 30 shards
- **Lines:** 3,197/3,199 matching (99.9%)
- **Avg test duration:** 13.2s — slowest: `avm2_applyfilter_bevel_sample` (45.5s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m38s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 12.3s — slowest: `draw_to_bitmap_data_unconfigured` (24.8s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m30s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.9s — slowest: `lzma_length_too_long` (25.0s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m53s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 19.5s — slowest: `auto_size/return` (38.3s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m34s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 23.2s — slowest: `frame_script_button_order` (33.4s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 36m50s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.6s — slowest: `definefont4` (90.8s)
