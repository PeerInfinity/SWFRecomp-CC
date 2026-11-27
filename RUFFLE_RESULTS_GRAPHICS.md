# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `2d40d37996b8`  
**Date:** 2026-11-27 16:16 UTC  
**Total duration:** 12h23m43s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 776 | 791 | 98.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1317 | 1352 | 97.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1564 | 1574 | 99.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 181 | 243 | 74.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 74 | 111 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 17 | 21 | 81.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 318 | 319 | 99.7% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4751** | **4940** | **96.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,761 | 137,880 | 91.2% |
| avm2 | 163,036 | 164,470 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,953 | 85,996 | 99.9% |
| from_gnash/actionscript.all | 31,177 | 38,791 | 80.4% |
| from_gnash/misc-ming.all | 4,365 | 5,248 | 83.2% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 565 | 603 | 93.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,282 | 3,284 | 99.9% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **419,759** | **442,077** | **95.0%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 10 |
| avm2 | 5 |
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
| **Total** | **33** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | loader_load | 98% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 84% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |

## Changes Since Last Run

*No changes since last run.*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 22.1s — slowest: `aac` (24.5s)

### avm1

- **Pass:** 776/791 (98.1%)
- **Duration:** 1h05m47s across 30 shards
- **Lines:** 125,761/137,880 matching (91.2%)
- **Avg test duration:** 5.0s — slowest: `define_font_glyph_table_order` (37.1s)

### avm2

- **Pass:** 1317/1352 (97.4%)
- **Duration:** 3h55m15s across 30 shards
- **Lines:** 163,036/164,470 matching (99.1%)
- **Avg test duration:** 10.4s — slowest: `away3d_advanced_shallow_water_demo` (90.1s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m58s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.9s — slowest: `embed_matching/fallback_preferences` (36.4s)

### from_avmplus

- **Pass:** 1564/1574 (99.4%)
- **Duration:** 3h30m19s across 30 shards
- **Lines:** 85,953/85,996 matching (99.9%)
- **Avg test duration:** 8.0s — slowest: `ecma3/Statements/eregress_74474_002` (66.9s)

### from_gnash/actionscript.all

- **Pass:** 181/243 (74.5%)
- **Duration:** 23m39s across 30 shards
- **Lines:** 31,177/38,791 matching (80.4%)
- **Avg test duration:** 5.8s — slowest: `MovieClip-v8` (47.4s)

### from_gnash/misc-ming.all

- **Pass:** 74/111 (66.7%)
- **Duration:** 30m53s across 30 shards
- **Lines:** 4,365/5,248 matching (83.2%)
- **Avg test duration:** 16.7s — slowest: `matrix_test` (81.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m00s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 13.3s — slowest: `implementsOpTest` (26.6s)

### from_gnash/misc-swfc.all

- **Pass:** 17/21 (81.0%)
- **Duration:** 5m19s across 30 shards
- **Lines:** 565/603 matching (93.7%)
- **Avg test duration:** 15.2s — slowest: `hello` (26.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m45s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.3s — slowest: `initaction_in_definesprite` (25.8s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 44m53s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 11.7s — slowest: `acid/acid-large` (68.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m31s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.2s — slowest: `hitarea` (26.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.3s — slowest: `empty_url` (20.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.1s — slowest: `avm2_loads_avm1_events` (10.4s)

### regression

- **Pass:** 318/319 (99.7%)
- **Duration:** 1h02m45s across 30 shards
- **Lines:** 3,282/3,284 matching (99.9%)
- **Avg test duration:** 11.8s — slowest: `avm2_timeline_gradients` (29.9s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m39s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 12.4s — slowest: `draw_to_bitmap_data_unconfigured` (25.8s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 10.4s — slowest: `swf_length_too_short_no_second_frame` (25.6s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m42s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.5s — slowest: `text_caret_placement_leading` (34.0s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 3m29s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 12.3s — slowest: `frame_script_cleanup3` (34.0s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 36m41s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.5s — slowest: `definefont4` (83.7s)
