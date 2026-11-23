# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `1396f1e10b65`  
**Date:** 2026-11-23 19:23 UTC  
**Total duration:** 11h48m30s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 746 | 781 | 95.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1284 | 1339 | 95.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 70 | 111 | 63.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 14 | 21 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 170 | 170 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4465** | **4768** | **93.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 125,287 | 137,730 | 91.0% |
| avm2 | 161,574 | 164,000 | 98.5% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,884 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,284 | 5,237 | 81.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 491 | 603 | 81.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,445 | 1,445 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **415,126** | **439,607** | **94.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| audio | 1 | - |
| avm1 | 13 | - |
| avm2 | 10 | - |
| fonts | - | - |
| from_avmplus | 2 | - |
| from_gnash/actionscript.all | 3 | - |
| from_gnash/misc-ming.all | 8 | 1 |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 1 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 2 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | - |
| visual | - | - |
| **Total** | **41** | **1** |

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
| avm1 | 1 | 1 | 4 | 4 |
| from_gnash/misc-ming.all | - | 1 | 33 | 1 |

**avm1 — newly passing:** `video_prototype_lazy_swf6_child`

**avm1 — newly failing:** `hitarea_remove_owner_drag`

**from_gnash/misc-ming.all — newly passing:** `BitmapDataDraw`

*Comparing `876e6670414e` → `1396f1e10b65`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 15.2s — slowest: `g711_event_alaw` (24.4s)

### avm1

- **Pass:** 746/781 (95.5%)
- **Duration:** 1h17m02s across 30 shards
- **Lines:** 125,287/137,730 matching (91.0%)
- **Avg test duration:** 5.9s — slowest: `define_font_glyph_table_order` (54.2s)

### avm2

- **Pass:** 1284/1339 (95.9%)
- **Duration:** 3h52m34s across 30 shards
- **Lines:** 161,574/164,000 matching (98.5%)
- **Avg test duration:** 10.4s — slowest: `away3d_advanced_shallow_water_demo` (107.1s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m54s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.3s — slowest: `device_font_list` (32.6s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h02m57s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 6.9s — slowest: `ecma3/Statements/eregress_74474_003` (64.2s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 30m17s across 30 shards
- **Lines:** 30,884/38,791 matching (79.6%)
- **Avg test duration:** 7.4s — slowest: `MovieClip-v8` (67.3s)

### from_gnash/misc-ming.all

- **Pass:** 70/111 (63.1%)
- **Duration:** 34m21s across 30 shards
- **Lines:** 4,284/5,237 matching (81.8%)
- **Avg test duration:** 18.5s — slowest: `matrix_test` (119.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m59s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.3s — slowest: `exception` (26.7s)

### from_gnash/misc-swfc.all

- **Pass:** 14/21 (66.7%)
- **Duration:** 5m12s across 30 shards
- **Lines:** 491/603 matching (81.4%)
- **Avg test duration:** 14.8s — slowest: `movieclip_destruction_test4` (25.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m47s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.3s — slowest: `dict_callframe` (26.2s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 44m59s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 11.8s — slowest: `acid/acid-large` (65.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.3s — slowest: `text-bind` (23.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 52s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 17.3s — slowest: `empty_url` (25.7s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.4s — slowest: `avm1_sprite_sc_ignored` (17.6s)

### regression

- **Pass:** 170/170 (100%)
- **Duration:** 38m21s across 30 shards
- **Lines:** 1,445/1,445 matching (100%)
- **Avg test duration:** 13.5s — slowest: `avm2_parent_child_symbol_stride` (56.3s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.6s — slowest: `draw_to_bitmap_data_unconfigured` (23.2s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 10.1s — slowest: `lzma_length_too_long` (24.1s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m29s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.4s — slowest: `auto_size/width` (32.2s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m37s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 19.8s — slowest: `frame_script_button_order` (32.2s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 34m03s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.5s — slowest: `definefont4` (91.8s)
