# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `6441e7d5d749`  
**Date:** 2026-11-28 01:46 UTC  
**Total duration:** 14h18m43s

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
| from_shumway | 217 | 229 | 94.8% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 346 | 346 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 16 | 17 | 94.1% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4807** | **4968** | **96.8%** | |

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
| from_shumway | 2,413 | 2,484 | 97.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,757 | 3,757 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **422,149** | **442,581** | **95.4%** |

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
| **Total** | **30** |

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
| from_gnash/actionscript.all | - | - | 252 | - |
| from_gnash/misc-ming.all | - | - | 27 | - |
| from_gnash/misc-swfmill.all | - | - | 2 | - |
| from_shumway | - | 1 | - | 1 |

**from_gnash/actionscript.all — newly passing:** `LoadVars-v6`, `LoadVars-v7`, `LoadVars-v8`, `Object-v6`, `Object-v7`, `Object-v8`, `Sound-v5`, `setProperty-v5`, `setProperty-v6`, `setProperty-v7`, `setProperty-v8`

**from_gnash/misc-ming.all — newly passing:** `EmbeddedFontTest`

**from_gnash/misc-swfmill.all — newly passing:** `zeroframe_definesprite`

**from_shumway — newly failing:** `as3-loader/bug1157243/empty`

*Comparing `9498e80c12e3` → `6441e7d5d749`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 2m01s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 24.2s — slowest: `aac` (33.0s)

### avm1

- **Pass:** 776/791 (98.1%)
- **Duration:** 1h31m29s across 30 shards
- **Lines:** 127,286/137,880 matching (92.3%)
- **Avg test duration:** 6.9s — slowest: `edittext_default_format` (39.4s)

### avm2

- **Pass:** 1322/1353 (97.7%)
- **Duration:** 4h29m05s across 30 shards
- **Lines:** 163,183/164,501 matching (99.2%)
- **Avg test duration:** 11.9s — slowest: `away3d_advanced_shallow_water_demo` (117.1s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m27s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 23.0s — slowest: `device_font_list` (33.8s)

### from_avmplus

- **Pass:** 1567/1574 (99.6%)
- **Duration:** 3h33m32s across 30 shards
- **Lines:** 85,956/85,996 matching (99.95%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_003` (61.4s)

### from_gnash/actionscript.all

- **Pass:** 193/243 (79.4%)
- **Duration:** 33m17s across 30 shards
- **Lines:** 31,367/38,791 matching (80.9%)
- **Avg test duration:** 8.2s — slowest: `MovieClip-v8` (56.5s)

### from_gnash/misc-ming.all

- **Pass:** 77/111 (69.4%)
- **Duration:** 36m35s across 30 shards
- **Lines:** 4,403/5,248 matching (83.9%)
- **Avg test duration:** 19.7s — slowest: `matrix_test` (84.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m03s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 13.6s — slowest: `exception` (26.4s)

### from_gnash/misc-swfc.all

- **Pass:** 17/21 (81.0%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 565/603 matching (93.7%)
- **Avg test duration:** 17.2s — slowest: `action_execution_order_test10` (27.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 20/20 (100%)
- **Duration:** 7m07s across 30 shards
- **Lines:** 95/95 matching (100%)
- **Avg test duration:** 21.4s — slowest: `jump_to_prev_block` (26.2s)

### from_shumway

- **Pass:** 217/229 (94.8%)
- **Duration:** 54m06s across 30 shards
- **Lines:** 2,413/2,484 matching (97.1%)
- **Avg test duration:** 14.1s — slowest: `acid/acid-large` (70.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m35s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.3s — slowest: `hitarea` (25.3s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 50s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.6s — slowest: `empty_url` (26.0s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m29s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.4s — slowest: `avm1_sprite_sc_ignored` (17.0s)

### regression

- **Pass:** 346/346 (100%)
- **Duration:** 1h16m04s across 30 shards
- **Lines:** 3,757/3,757 matching (100%)
- **Avg test duration:** 13.2s — slowest: `avm2_stroke_curve_scale_s16_w16_k0` (39.4s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 2m01s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 15.2s — slowest: `draw_to_bitmap_data_unconfigured` (33.5s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.7s — slowest: `convolution_filter_big_matrix` (26.2s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 4m13s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 21.1s — slowest: `auto_size/height` (39.0s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 6m37s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 23.3s — slowest: `missing_frame_scripts` (34.0s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 44m34s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 17.7s — slowest: `definefont4` (87.6s)
