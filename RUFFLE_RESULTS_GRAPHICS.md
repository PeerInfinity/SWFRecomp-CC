# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `697669e5f98f`  
**Date:** 2026-11-22 23:56 UTC  
**Total duration:** 11h56m37s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 745 | 781 | 95.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1285 | 1339 | 96.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 13 | 20 | 65.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 130 | 130 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4424** | **4727** | **93.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,116 | 137,730 | 90.8% |
| avm2 | 161,692 | 164,000 | 98.6% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,884 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,263 | 5,248 | 81.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 486 | 580 | 83.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,170 | 1,170 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **414,778** | **439,320** | **94.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 14 |
| avm2 | 9 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 8 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 2 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **41** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| avm2 | number_tostring | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | 10 | - |
| from_gnash/actionscript.all | 3 | - | 203 | - |
| from_gnash/misc-ming.all | 1 | - | 4 | - |

*Comparing `485eb555c3f9` → `697669e5f98f`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m09s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 13.8s — slowest: `g711_event_alaw` (23.3s)

### avm1

- **Pass:** 745/781 (95.4%)
- **Duration:** 1h17m32s across 30 shards
- **Lines:** 125,116/137,730 matching (90.8%)
- **Avg test duration:** 5.9s — slowest: `asfunction` (38.5s)

### avm2

- **Pass:** 1285/1339 (96.0%)
- **Duration:** 3h58m30s across 30 shards
- **Lines:** 161,692/164,000 matching (98.6%)
- **Avg test duration:** 10.6s — slowest: `away3d_advanced_shallow_water_demo` (115.1s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m23s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 15.9s — slowest: `device_font_list` (31.4s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h18m49s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_003` (59.1s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 29m30s across 30 shards
- **Lines:** 30,884/38,791 matching (79.6%)
- **Avg test duration:** 7.2s — slowest: `MovieClip-v8` (72.8s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 31m02s across 30 shards
- **Lines:** 4,263/5,248 matching (81.2%)
- **Avg test duration:** 16.7s — slowest: `matrix_test` (101.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.3s — slowest: `exception` (24.6s)

### from_gnash/misc-swfc.all

- **Pass:** 13/20 (65.0%)
- **Duration:** 5m34s across 30 shards
- **Lines:** 486/580 matching (83.8%)
- **Avg test duration:** 16.7s — slowest: `movieclip_destruction_test4` (25.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m18s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.9s — slowest: `mixed-bytecode-as2` (25.1s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 45m15s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 11.8s — slowest: `esc` (60.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.0s — slowest: `hitarea` (23.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 45s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.0s — slowest: `empty_url` (24.0s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.2s — slowest: `avm1_sprite_sc_ignored` (18.2s)

### regression

- **Pass:** 130/130 (100%)
- **Duration:** 27m51s across 30 shards
- **Lines:** 1,170/1,170 matching (100%)
- **Avg test duration:** 12.8s — slowest: `avm2_layer_group_overlap_alpha` (39.6s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.5s — slowest: `draw_to_bitmap_data_unconfigured` (24.1s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 44s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 6.3s — slowest: `convolution_filter_big_matrix` (18.5s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m35s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.9s — slowest: `auto_size/width` (31.4s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m39s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 19.9s — slowest: `swf_9_event_goto_frame_script` (33.3s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 34m47s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.8s — slowest: `definefont4` (84.0s)
