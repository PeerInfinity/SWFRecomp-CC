# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9e24c763ca3a`  
**Date:** 2026-11-22 20:56 UTC  
**Total duration:** 11h28m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 743 | 780 | 95.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
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
| regression | 124 | 124 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4416** | **4720** | **93.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,001 | 137,572 | 90.9% |
| avm2 | 161,692 | 164,000 | 98.6% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,657 | 38,791 | 79.0% |
| from_gnash/misc-ming.all | 4,259 | 5,248 | 81.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 486 | 580 | 83.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,139 | 1,139 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **414,401** | **439,131** | **94.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 15 |
| avm2 | 9 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 6 |
| from_gnash/misc-ming.all | 9 |
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
| **Total** | **46** |

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
| from_gnash/misc-ming.all | DrawingApiTest | 95% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 3 | - |
| from_gnash/misc-ming.all | - | - | 7 | - |

**avm1 — newly passing:** `text_format_prototype_lazy`

*Comparing `2f7be1710fed` → `9e24c763ca3a`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m40s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 20.1s — slowest: `aac` (23.9s)

### avm1

- **Pass:** 743/780 (95.3%)
- **Duration:** 1h15m20s across 30 shards
- **Lines:** 125,001/137,572 matching (90.9%)
- **Avg test duration:** 5.8s — slowest: `stage_object_properties_get_var` (36.1s)

### avm2

- **Pass:** 1285/1339 (96.0%)
- **Duration:** 3h47m36s across 30 shards
- **Lines:** 161,692/164,000 matching (98.6%)
- **Avg test duration:** 10.2s — slowest: `away3d_advanced_shallow_water_demo` (84.5s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m37s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.4s — slowest: `embed_matching/fallback_preferences` (26.5s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h12m04s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.3s — slowest: `ecma3/Statements/eregress_74474_002` (59.0s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 28m23s across 30 shards
- **Lines:** 30,657/38,791 matching (79.0%)
- **Avg test duration:** 7.0s — slowest: `MovieClip-v8` (57.7s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 30m43s across 30 shards
- **Lines:** 4,259/5,248 matching (81.2%)
- **Avg test duration:** 16.6s — slowest: `matrix_test` (81.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.4s — slowest: `implementsOpTest` (19.3s)

### from_gnash/misc-swfc.all

- **Pass:** 13/20 (65.0%)
- **Duration:** 5m01s across 30 shards
- **Lines:** 486/580 matching (83.8%)
- **Avg test duration:** 15.1s — slowest: `movieclip_destruction_test2` (20.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m58s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 17.9s — slowest: `missing_bitmap` (21.6s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 43m22s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 11.3s — slowest: `acid/acid-large` (66.6s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m08s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.7s — slowest: `label` (18.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 41s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.5s — slowest: `empty_url` (18.3s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.9s — slowest: `avm1_sprite_sc_ignored` (17.8s)

### regression

- **Pass:** 124/124 (100%)
- **Duration:** 25m08s across 30 shards
- **Lines:** 1,139/1,139 matching (100%)
- **Avg test duration:** 12.1s — slowest: `avm2_layer_group_overlap_alpha` (28.3s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.8s — slowest: `draw_to_bitmap_data_unconfigured` (23.8s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m01s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 8.7s — slowest: `convolution_filter_big_matrix` (18.6s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m26s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.2s — slowest: `text_caret_placement_scroll` (29.6s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m23s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 19.0s — slowest: `swf_9_event_goto_frame_script` (25.5s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m59s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.1s — slowest: `definefont4` (101.4s)
