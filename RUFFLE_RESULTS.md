# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `6ee6eded7b66`  
**Date:** 2026-11-27 02:09 UTC  
**Total duration:** 10h37m00s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 773 | 791 | 97.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1315 | 1352 | 97.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1564 | 1574 | 99.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 177 | 243 | 72.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 73 | 111 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 15 | 21 | 71.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 301 | 302 | 99.7% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4721** | **4923** | **95.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 125,757 | 137,880 | 91.2% |
| avm2 | 162,917 | 164,470 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,953 | 85,996 | 99.9% |
| from_gnash/actionscript.all | 31,095 | 38,791 | 80.2% |
| from_gnash/misc-ming.all | 4,359 | 5,248 | 83.1% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 529 | 603 | 87.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,067 | 3,069 | 99.9% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **419,291** | **441,862** | **94.9%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 10 |
| avm2 | 7 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 1 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 1 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | 1 |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **36** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | loader_load | 98% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 2 | - | 22 | - |
| avm2 | 2 | - | 231 | 5 |
| from_avmplus | - | - | 335 | - |

**avm1 — newly passing:** `globals_swf5`, `native_objects_swf6`

**avm2 — newly passing:** `dependent_strings`, `edittext_getcharboundaries_culling`, `event_handler_exception`, `freestanding_superclass`, `loader_applicationDomain`, `weird_superinterface_properties`

**from_avmplus — newly passing:** `ecma3/Date/e15_9_5_10`, `ecma3/Date/e15_9_5_10_1`, `ecma3/Date/e15_9_5_10_10`, `ecma3/Date/e15_9_5_10_11`, `ecma3/Date/e15_9_5_11`, `ecma3/Date/e15_9_5_12`, `ecma3/Date/e15_9_5_12_1`, `ecma3/Date/e15_9_5_13`, `ecma3/Date/e15_9_5_15_1`, `ecma3/Date/e15_9_5_17_1`, `ecma3/Date/e15_9_5_22_1`, `ecma3/Date/e15_9_5_28_1`, `ecma3/Date/e15_9_5_29_1`, `ecma3/Date/e15_9_5_35_1`, `ecma3/Date/e15_9_5_4`

*Comparing `bfa47037b19e` → `6ee6eded7b66`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 14.5s — slowest: `stream_incomplete_loop` (18.9s)

### avm1

- **Pass:** 773/791 (97.7%)
- **Duration:** 51m42s across 30 shards
- **Lines:** 125,757/137,880 matching (91.2%)
- **Avg test duration:** 3.9s — slowest: `define_font_glyph_table_order` (40.8s)

### avm2

- **Pass:** 1315/1352 (97.3%)
- **Duration:** 3h23m38s across 30 shards
- **Lines:** 162,917/164,470 matching (99.1%)
- **Avg test duration:** 9.0s — slowest: `away3d_advanced_shallow_water_demo` (80.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m48s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 18.7s — slowest: `device_font_glyph_fallback` (31.1s)

### from_avmplus

- **Pass:** 1564/1574 (99.4%)
- **Duration:** 2h57m14s across 30 shards
- **Lines:** 85,953/85,996 matching (99.9%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_002` (61.1s)

### from_gnash/actionscript.all

- **Pass:** 177/243 (72.8%)
- **Duration:** 22m28s across 30 shards
- **Lines:** 31,095/38,791 matching (80.2%)
- **Avg test duration:** 5.5s — slowest: `MovieClip-v8` (50.1s)

### from_gnash/misc-ming.all

- **Pass:** 73/111 (65.8%)
- **Duration:** 30m10s across 30 shards
- **Lines:** 4,359/5,248 matching (83.1%)
- **Avg test duration:** 16.3s — slowest: `matrix_test` (81.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 8.0s — slowest: `TextFieldTest` (24.7s)

### from_gnash/misc-swfc.all

- **Pass:** 15/21 (71.4%)
- **Duration:** 4m29s across 30 shards
- **Lines:** 529/603 matching (87.7%)
- **Avg test duration:** 12.8s — slowest: `action_execution_order_test10` (25.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m48s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 14.4s — slowest: `jump_after_end` (24.4s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 40m29s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 10.6s — slowest: `esc` (84.1s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m59s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.5s — slowest: `label` (24.6s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 41s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.6s — slowest: `empty_url` (19.8s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 49s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 4.1s — slowest: `avm2_loads_avm1_events` (8.8s)

### regression

- **Pass:** 301/302 (99.7%)
- **Duration:** 50m38s across 30 shards
- **Lines:** 3,067/3,069 matching (99.9%)
- **Avg test duration:** 10.0s — slowest: `avm1_stroke_join_cap_snap` (27.1s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.8s — slowest: `draw_to_bitmap_data_unconfigured` (31.0s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.0s — slowest: `convolution_filter_big_matrix` (24.1s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m34s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.9s — slowest: `text_caret_placement_align` (32.6s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m52s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 17.2s — slowest: `swf_9_frame_script_dynamic_goto` (32.4s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 31m18s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.4s — slowest: `definefont4` (84.8s)
