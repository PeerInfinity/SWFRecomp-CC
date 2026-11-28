# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `3dfab12779f5`  
**Date:** 2026-11-28 07:02 UTC  
**Total duration:** 12h31m19s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 776 | 791 | 98.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1322 | 1353 | 97.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1567 | 1574 | 99.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 193 | 243 | 79.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 77 | 111 | 69.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 17 | 21 | 81.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 20 | 20 | 100% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 218 | 229 | 95.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 347 | 347 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 16 | 17 | 94.1% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4809** | **4969** | **96.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 127,286 | 137,880 | 92.3% |
| avm2 | 163,183 | 164,501 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,956 | 85,996 | 99.95% |
| from_gnash/actionscript.all | 31,367 | 38,791 | 80.9% |
| from_gnash/misc-ming.all | 4,403 | 5,248 | 83.9% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 565 | 603 | 93.7% |
| from_gnash/misc-swfmill.all | 95 | 95 | 100% |
| from_shumway | 2,414 | 2,484 | 97.2% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,770 | 3,770 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **422,163** | **442,594** | **95.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 9 |
| avm2 | 5 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 7 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 1 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 1 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **29** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | movieclip_hittest_shapeflag | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm2 | loader_load | 98% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_shumway | 1 | - | 1 | - |

**from_shumway — newly passing:** `as3-loader/bug1157243/empty`

*Comparing `6441e7d5d749` → `3dfab12779f5`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 22.8s — slowest: `aac` (25.6s)

### avm1

- **Pass:** 776/791 (98.1%)
- **Duration:** 1h12m30s across 30 shards
- **Lines:** 127,286/137,880 matching (92.3%)
- **Avg test duration:** 5.5s — slowest: `tab_ordering_movieclip_enabled_default` (33.7s)

### avm2

- **Pass:** 1322/1353 (97.7%)
- **Duration:** 3h52m56s across 30 shards
- **Lines:** 163,183/164,501 matching (99.2%)
- **Avg test duration:** 10.3s — slowest: `away3d_advanced_shallow_water_demo` (87.8s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 21.7s — slowest: `device_font_no_ink` (29.7s)

### from_avmplus

- **Pass:** 1567/1574 (99.6%)
- **Duration:** 3h19m54s across 30 shards
- **Lines:** 85,956/85,996 matching (99.95%)
- **Avg test duration:** 7.6s — slowest: `ecma3/Statements/eregress_74474_003` (66.1s)

### from_gnash/actionscript.all

- **Pass:** 193/243 (79.4%)
- **Duration:** 25m59s across 30 shards
- **Lines:** 31,367/38,791 matching (80.9%)
- **Avg test duration:** 6.4s — slowest: `MovieClip-v8` (59.6s)

### from_gnash/misc-ming.all

- **Pass:** 77/111 (69.4%)
- **Duration:** 30m08s across 30 shards
- **Lines:** 4,403/5,248 matching (83.9%)
- **Avg test duration:** 16.3s — slowest: `matrix_test` (84.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.8s — slowest: `TextFieldTest` (21.8s)

### from_gnash/misc-swfc.all

- **Pass:** 17/21 (81.0%)
- **Duration:** 5m17s across 30 shards
- **Lines:** 565/603 matching (93.7%)
- **Avg test duration:** 15.1s — slowest: `movieclip_destruction_test1` (27.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 20/20 (100%)
- **Duration:** 6m54s across 30 shards
- **Lines:** 95/95 matching (100%)
- **Avg test duration:** 20.7s — slowest: `missing_bitmap` (26.3s)

### from_shumway

- **Pass:** 218/229 (95.2%)
- **Duration:** 48m14s across 30 shards
- **Lines:** 2,414/2,484 matching (97.2%)
- **Avg test duration:** 12.6s — slowest: `acid/acid-large` (77.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m23s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.0s — slowest: `hitarea` (20.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.7s — slowest: `avm1_non_swf_import` (21.0s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.6s — slowest: `avm2_loads_avm1_v10` (10.3s)

### regression

- **Pass:** 347/347 (100%)
- **Duration:** 1h05m07s across 30 shards
- **Lines:** 3,770/3,770 matching (100%)
- **Avg test duration:** 11.2s — slowest: `avm2_stroke_curve_scale_s16_w16_k0` (37.8s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m53s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 14.1s — slowest: `request_matching_profiles` (28.5s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.6s — slowest: `convolution_filter_big_matrix` (21.2s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m54s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 19.5s — slowest: `text_caret_placement_scroll` (35.2s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 5m25s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 19.1s — slowest: `swf_9_frame_script_dynamic_goto` (29.7s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 40m13s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 15.9s — slowest: `definefont4` (115.0s)
