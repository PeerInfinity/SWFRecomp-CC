# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `cceb5133a189`  
**Date:** 2026-11-24 07:25 UTC  
**Total duration:** 11h36m32s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 751 | 785 | 95.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1289 | 1343 | 96.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 71 | 111 | 64.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 14 | 21 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 204 | 204 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4511** | **4810** | **93.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,299 | 137,738 | 91.0% |
| avm2 | 161,958 | 164,266 | 98.6% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,878 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,313 | 5,248 | 82.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 524 | 603 | 86.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,557 | 1,557 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **415,696** | **440,004** | **94.5%** |

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
| from_gnash/actionscript.all | - | - | - | 6 |
| from_gnash/misc-ming.all | - | - | 24 | - |
| from_gnash/misc-swfc.all | - | - | 33 | - |

**from_gnash/misc-ming.all — newly passing:** `init_action/InitActionTest2`

*Comparing `b8d3b736aaef` → `cceb5133a189`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 21.7s — slowest: `aac` (24.3s)

### avm1

- **Pass:** 751/785 (95.7%)
- **Duration:** 1h09m43s across 30 shards
- **Lines:** 125,299/137,738 matching (91.0%)
- **Avg test duration:** 5.3s — slowest: `define_font_glyph_table_order` (42.7s)

### avm2

- **Pass:** 1289/1343 (96.0%)
- **Duration:** 3h49m30s across 30 shards
- **Lines:** 161,958/164,266 matching (98.6%)
- **Avg test duration:** 10.2s — slowest: `away3d_advanced_shallow_water_demo` (98.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m44s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 18.2s — slowest: `device_font_list` (28.6s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h16m40s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_003` (63.4s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 25m52s across 30 shards
- **Lines:** 30,878/38,791 matching (79.6%)
- **Avg test duration:** 6.4s — slowest: `MovieClip-v8` (75.2s)

### from_gnash/misc-ming.all

- **Pass:** 71/111 (64.0%)
- **Duration:** 28m04s across 30 shards
- **Lines:** 4,313/5,248 matching (82.2%)
- **Avg test duration:** 15.1s — slowest: `matrix_test` (82.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.2s — slowest: `exception` (22.5s)

### from_gnash/misc-swfc.all

- **Pass:** 14/21 (66.7%)
- **Duration:** 4m44s across 30 shards
- **Lines:** 524/603 matching (86.9%)
- **Avg test duration:** 13.5s — slowest: `sound` (24.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m32s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.6s — slowest: `mixed-bytecode-as2` (25.2s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 44m28s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 11.6s — slowest: `esc` (77.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.9s — slowest: `text-bind` (19.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 46s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.5s — slowest: `empty_url` (21.8s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m19s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.6s — slowest: `avm1_sprite_sc_ignored` (18.2s)

### regression

- **Pass:** 204/204 (100%)
- **Duration:** 37m05s across 30 shards
- **Lines:** 1,557/1,557 matching (100%)
- **Avg test duration:** 10.9s — slowest: `avm2_gc_dynprop_tombstone_purge` (53.7s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.8s — slowest: `draw_to_bitmap_data_unconfigured` (24.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 48s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 6.8s — slowest: `convolution_filter_big_matrix` (19.5s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m33s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.8s — slowest: `auto_size/height` (29.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m10s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 14.7s — slowest: `frame_script_button_order` (26.5s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 33m08s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.1s — slowest: `definefont4` (83.4s)
