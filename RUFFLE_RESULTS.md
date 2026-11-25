# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8f4f6e395305`  
**Date:** 2026-11-25 03:59 UTC  
**Total duration:** 10h02m15s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 754 | 788 | 95.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1292 | 1346 | 96.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 71 | 111 | 64.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 14 | 21 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 254 | 254 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4567** | **4866** | **93.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 125,316 | 137,755 | 91.0% |
| avm2 | 161,915 | 164,338 | 98.5% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,878 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,318 | 5,248 | 82.3% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 526 | 603 | 87.2% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,030 | 2,030 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **416,149** | **440,566** | **94.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 12 |
| avm2 | 10 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 8 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
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
| **Total** | **40** |

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
| from_gnash/misc-swfc.all | action_execution_order_test12 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 3 | - | 18 | - |
| avm2 | - | - | 44 | - |
| from_gnash/misc-ming.all | - | - | 1 | - |
| from_shumway | 1 | - | 1 | - |

**avm1 — newly passing:** `malformed_actions/constant_pool_overlong`, `malformed_actions/constant_pool_overspill`, `malformed_actions/push_overspill`

**avm2 — newly passing:** `goto_framescript_queued/swf13`, `goto_framescript_queued_next_prev`, `goto_isplaying`, `goto_scene_isplaying`

**from_shumway — newly passing:** `bitmapdata/getpixel-from-embedded`

*Comparing `78fee9e13f85` → `8f4f6e395305`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m09s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 13.8s — slowest: `g711_event_mulaw` (18.6s)

### avm1

- **Pass:** 754/788 (95.7%)
- **Duration:** 52m53s across 30 shards
- **Lines:** 125,316/137,755 matching (91.0%)
- **Avg test duration:** 4.0s — slowest: `file_reference_upload_httperror_dns_error` (31.6s)

### avm2

- **Pass:** 1292/1346 (96.0%)
- **Duration:** 3h14m54s across 30 shards
- **Lines:** 161,915/164,338 matching (98.5%)
- **Avg test duration:** 8.6s — slowest: `away3d_advanced_shallow_water_demo` (77.8s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m31s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 16.8s — slowest: `device_font_kerning` (24.9s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 2h47m58s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 6.4s — slowest: `ecma3/Statements/eregress_74474_002` (66.2s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 22m41s across 30 shards
- **Lines:** 30,878/38,791 matching (79.6%)
- **Avg test duration:** 5.6s — slowest: `MovieClip-v8` (51.5s)

### from_gnash/misc-ming.all

- **Pass:** 71/111 (64.0%)
- **Duration:** 23m39s across 30 shards
- **Lines:** 4,318/5,248 matching (82.3%)
- **Avg test duration:** 12.8s — slowest: `matrix_test` (77.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m44s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 11.5s — slowest: `inheritance` (19.7s)

### from_gnash/misc-swfc.all

- **Pass:** 14/21 (66.7%)
- **Duration:** 4m36s across 30 shards
- **Lines:** 526/603 matching (87.2%)
- **Avg test duration:** 13.1s — slowest: `movieclip_destruction_test1` (26.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m24s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.2s — slowest: `trace-as2/arguments` (24.3s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 42m12s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 11.0s — slowest: `acid/acid-large` (66.9s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.2s — slowest: `label` (23.2s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 39s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.1s — slowest: `avm1_non_swf_import` (19.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.2s — slowest: `avm1_sprite_sc_ignored` (19.3s)

### regression

- **Pass:** 254/254 (100%)
- **Duration:** 39m50s across 30 shards
- **Lines:** 2,030/2,030 matching (100%)
- **Avg test duration:** 9.4s — slowest: `avm1_many_functions_registry` (33.0s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.6s — slowest: `draw_to_bitmap_data_unconfigured` (23.2s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 25s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 3.6s — slowest: `swf_length_too_short_no_second_frame` (18.0s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m27s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.2s — slowest: `text_caret_placement_scroll` (33.8s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 3m42s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 13.1s — slowest: `frame_script_construct` (30.0s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 29m06s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.5s — slowest: `definefont4` (116.1s)
