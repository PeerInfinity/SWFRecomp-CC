# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8b69f982f7ab`  
**Date:** 2026-10-11 08:51 UTC  
**Total duration:** 9h09m15s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 701 | 746 | 94.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1222 | 1288 | 94.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 9 | 66.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 101 | 101 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4265** | **4606** | **92.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 122,067 | 135,581 | 90.0% |
| avm2 | 155,581 | 158,827 | 98.0% |
| fonts | 195 | 377 | 51.7% |
| from_avmplus | 85,560 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,558 | 38,791 | 78.8% |
| from_gnash/misc-ming.all | 4,227 | 5,248 | 80.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,396 | 2,484 | 96.5% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 838 | 838 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **404,656** | **431,652** | **93.7%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 25 | - |
| avm2 | 25 | - |
| fonts | 2 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 11 | - |
| from_gnash/misc-ming.all | 10 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 3 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | - |
| visual | - | - |
| **Total** | **87** | **1** |

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
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | Rectangle-v8 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/actionscript.all | Matrix-v7 | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | Matrix-v6 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | 3 | 17 | 1121 |
| avm2 | - | - | 2 | 205 |
| from_gnash/actionscript.all | - | 3 | - | - |

**avm1 — newly passing:** `html_text_img_parsing_swf6`

**avm1 — newly failing:** `context_menu`, `context_menu_item`, `matrix`

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.0s — slowest: `stream_incomplete_loop` (21.3s)

### avm1

- **Pass:** 701/746 (94.0%)
- **Duration:** 38m45s across 30 shards
- **Lines:** 122,067/135,581 matching (90.0%)
- **Avg test duration:** 3.1s — slowest: `netstream_play_flv_screen` (37.8s)

### avm2

- **Pass:** 1222/1288 (94.9%)
- **Duration:** 3h02m07s across 30 shards
- **Lines:** 155,581/158,827 matching (98.0%)
- **Avg test duration:** 8.4s — slowest: `away3d_advanced_shallow_water_demo` (99.9s)

### fonts

- **Pass:** 6/9 (66.7%)
- **Duration:** 2m39s across 30 shards
- **Lines:** 195/377 matching (51.7%)
- **Avg test duration:** 17.7s — slowest: `device_font_glyph_fallback` (27.8s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 2h57m40s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_003` (55.9s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 17m49s across 30 shards
- **Lines:** 30,558/38,791 matching (78.8%)
- **Avg test duration:** 4.3s — slowest: `array-v7` (28.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 20m04s across 30 shards
- **Lines:** 4,227/5,248 matching (80.5%)
- **Avg test duration:** 10.8s — slowest: `matrix_test` (75.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.0s — slowest: `exception` (23.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m14s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 12.7s — slowest: `stackscope` (22.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m12s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.6s — slowest: `trace-as2/super` (22.3s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 41m35s across 30 shards
- **Lines:** 2,396/2,484 matching (96.5%)
- **Avg test duration:** 10.8s — slowest: `acid/acid-large` (76.4s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m40s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.1s — slowest: `label` (20.7s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.4s — slowest: `empty_url` (21.6s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 48s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 4.0s — slowest: `avm2_loads_avm1_loads_avm2_doabc` (7.6s)

### regression

- **Pass:** 101/101 (100%)
- **Duration:** 18m12s across 30 shards
- **Lines:** 838/838 matching (100%)
- **Avg test duration:** 10.8s — slowest: `avm2_timeline_stroke_gradient` (29.0s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m01s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.8s — slowest: `sampler_odd_size` (10.8s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 9s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 1.3s — slowest: `lzma_length_too_short` (1.6s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m18s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 18.0s — slowest: `auto_size/width` (29.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 1m38s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 5.7s — slowest: `frame_script_cleanup_goto` (8.2s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 27m29s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.2s — slowest: `definefont4` (107.0s)
