# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `2f7be1710fed`  
**Date:** 2026-11-22 20:05 UTC  
**Total duration:** 10h25m11s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 742 | 780 | 95.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
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
| regression | 114 | 114 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4405** | **4710** | **93.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 124,998 | 137,572 | 90.9% |
| avm2 | 161,692 | 164,000 | 98.6% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,657 | 38,791 | 79.0% |
| from_gnash/misc-ming.all | 4,252 | 5,248 | 81.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 486 | 580 | 83.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,050 | 1,050 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **414,302** | **439,042** | **94.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 16 |
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
| **Total** | **47** |

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
| avm1 | text_format_prototype_lazy | 91% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 2 | - | 11 | - |

**avm2 — newly passing:** `pixelbender_shaderjob_output_channels`, `textblock_recreate_text_line_width`

*Comparing `746c394898ff` → `2f7be1710fed`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 21.6s — slowest: `aac` (31.5s)

### avm1

- **Pass:** 742/780 (95.1%)
- **Duration:** 52m10s across 30 shards
- **Lines:** 124,998/137,572 matching (90.9%)
- **Avg test duration:** 4.0s — slowest: `define_font_glyph_table_order` (41.0s)

### avm2

- **Pass:** 1285/1339 (96.0%)
- **Duration:** 3h39m14s across 30 shards
- **Lines:** 161,692/164,000 matching (98.6%)
- **Avg test duration:** 9.8s — slowest: `away3d_advanced_shallow_water_demo` (87.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m51s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.0s — slowest: `device_font_glyph_fallback` (30.5s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h18m34s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_002` (61.4s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 20m24s across 30 shards
- **Lines:** 30,657/38,791 matching (79.0%)
- **Avg test duration:** 5.0s — slowest: `MovieClip-v8` (55.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 18m14s across 30 shards
- **Lines:** 4,252/5,248 matching (81.0%)
- **Avg test duration:** 9.8s — slowest: `matrix_test` (81.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.7s — slowest: `TextFieldTest` (23.3s)

### from_gnash/misc-swfc.all

- **Pass:** 13/20 (65.0%)
- **Duration:** 3m54s across 30 shards
- **Lines:** 486/580 matching (83.8%)
- **Avg test duration:** 11.7s — slowest: `opcode_guard_test2` (24.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m19s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 7.0s — slowest: `zeroframe_definesprite` (23.6s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 41m56s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 11.0s — slowest: `acid/acid-large` (66.4s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.9s — slowest: `hitarea` (23.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.7s — slowest: `avm1_non_swf_import` (20.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.7s — slowest: `avm2_loads_avm1_events` (10.1s)

### regression

- **Pass:** 114/114 (100%)
- **Duration:** 20m36s across 30 shards
- **Lines:** 1,050/1,050 matching (100%)
- **Avg test duration:** 10.8s — slowest: `avm2_parent_child_symbolclass_domain` (51.6s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m35s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.9s — slowest: `draw_to_bitmap_data_unconfigured` (30.0s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 13s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 1.8s — slowest: `convolution_filter_big_matrix` (2.5s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m41s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.4s — slowest: `auto_size/height` (35.0s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 2m27s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 8.6s — slowest: `missing_frame_scripts` (23.8s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 29m10s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.6s — slowest: `definefont4` (84.0s)
