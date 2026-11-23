# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `da9b49b17a0a`  
**Date:** 2026-11-23 07:07 UTC  
**Total duration:** 11h39m54s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 747 | 781 | 95.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1285 | 1339 | 96.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 70 | 111 | 63.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 14 | 21 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 158 | 158 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4456** | **4756** | **93.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,291 | 137,730 | 91.0% |
| avm2 | 161,692 | 164,000 | 98.6% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,884 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,283 | 5,248 | 81.6% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 491 | 603 | 81.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,369 | 1,369 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **415,177** | **439,542** | **94.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 12 |
| avm2 | 9 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 8 |
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
| **Total** | **38** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | globals_swf5 | 97% |
| avm2 | number_tostring | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | - | - | 25 | - |

**from_gnash/misc-ming.all — newly passing:** `BitmapDataDraw`

*Comparing `a18a9cc61d54` → `da9b49b17a0a`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 22.3s — slowest: `g711` (23.9s)

### avm1

- **Pass:** 747/781 (95.6%)
- **Duration:** 1h03m32s across 30 shards
- **Lines:** 125,291/137,730 matching (91.0%)
- **Avg test duration:** 4.8s — slowest: `define_font_glyph_table_order` (57.3s)

### avm2

- **Pass:** 1285/1339 (96.0%)
- **Duration:** 3h55m06s across 30 shards
- **Lines:** 161,692/164,000 matching (98.6%)
- **Avg test duration:** 10.5s — slowest: `away3d_advanced_shallow_water_demo` (115.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m57s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.7s — slowest: `embed_matching/fallback_preferences` (33.1s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h27m29s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.9s — slowest: `ecma3/Statements/eregress_74474_003` (63.3s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 25m11s across 30 shards
- **Lines:** 30,884/38,791 matching (79.6%)
- **Avg test duration:** 6.2s — slowest: `MovieClip-v8` (74.2s)

### from_gnash/misc-ming.all

- **Pass:** 70/111 (63.1%)
- **Duration:** 26m37s across 30 shards
- **Lines:** 4,283/5,248 matching (81.6%)
- **Avg test duration:** 14.4s — slowest: `matrix_test` (122.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m00s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.4s — slowest: `exception` (25.5s)

### from_gnash/misc-swfc.all

- **Pass:** 14/21 (66.7%)
- **Duration:** 4m33s across 30 shards
- **Lines:** 491/603 matching (81.4%)
- **Avg test duration:** 13.0s — slowest: `gotoFrameFromInterval` (26.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m34s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.7s — slowest: `jump_to_prev_block` (25.8s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 45m00s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 11.8s — slowest: `acid/acid-large` (73.5s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m29s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `text-bind` (24.6s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 48s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.9s — slowest: `empty_url` (24.7s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.9s — slowest: `avm2_loads_avm1_v9` (10.1s)

### regression

- **Pass:** 158/158 (100%)
- **Duration:** 28m49s across 30 shards
- **Lines:** 1,369/1,369 matching (100%)
- **Avg test duration:** 10.9s — slowest: `avm2_morph` (40.1s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m34s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.8s — slowest: `draw_to_bitmap_data_unconfigured` (23.6s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 52s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 7.4s — slowest: `swf_length_too_short_no_second_frame` (23.7s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m51s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 19.3s — slowest: `text_caret_placement_leading` (33.0s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 3m45s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 13.2s — slowest: `missing_frame_scripts` (32.0s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 35m37s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.1s — slowest: `definefont4` (85.1s)
