# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `2d40d37996b8`  
**Date:** 2026-11-27 16:16 UTC  
**Total duration:** 12h23m43s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 776 | 783 | 99.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1308 | 1323 | 98.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1564 | 1572 | 99.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 181 | 240 | 75.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 74 | 110 | 67.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 17 | 20 | 85.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 215 | 223 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 318 | 319 | 99.7% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4742** | **4890** | **97.0%** | |

*50 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 117,172 | 120,277 | 97.4% |
| avm2 | 161,611 | 162,733 | 99.3% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,941 | 85,970 | 99.97% |
| from_gnash/actionscript.all | 30,894 | 32,104 | 96.2% |
| from_gnash/misc-ming.all | 4,358 | 5,206 | 83.7% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 550 | 585 | 94.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,363 | 2,409 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,282 | 3,284 | 99.9% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **409,383** | **415,889** | **98.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 3 | 4 |
| avm2 | - | 15 |
| fonts | - | 1 |
| from_avmplus | - | 8 |
| from_gnash/actionscript.all | - | 59 |
| from_gnash/misc-ming.all | 8 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 3 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 8 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | 1 | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **13** | **135** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 84% |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 22.1s — slowest: `aac` (24.5s)

### avm1

- **Pass:** 776/783 (99.1%)
- **Ignored:** 8 tests
- **Duration:** 1h05m47s across 30 shards
- **Lines:** 117,172/120,277 matching (97.4%)
- **Avg test duration:** 4.9s — slowest: `define_font_glyph_table_order` (37.1s)

### avm2

- **Pass:** 1308/1323 (98.9%)
- **Ignored:** 29 tests
- **Duration:** 3h55m15s across 30 shards
- **Lines:** 161,611/162,733 matching (99.3%)
- **Avg test duration:** 10.4s — slowest: `away3d_advanced_shallow_water_demo` (90.1s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m58s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.9s — slowest: `embed_matching/fallback_preferences` (36.4s)

### from_avmplus

- **Pass:** 1564/1572 (99.5%)
- **Ignored:** 2 tests
- **Duration:** 3h30m19s across 30 shards
- **Lines:** 85,941/85,970 matching (99.97%)
- **Avg test duration:** 8.0s — slowest: `ecma3/Statements/eregress_74474_002` (66.9s)

### from_gnash/actionscript.all

- **Pass:** 181/240 (75.4%)
- **Ignored:** 3 tests
- **Duration:** 23m39s across 30 shards
- **Lines:** 30,894/32,104 matching (96.2%)
- **Avg test duration:** 5.9s — slowest: `MovieClip-v8` (47.4s)

### from_gnash/misc-ming.all

- **Pass:** 74/110 (67.3%)
- **Ignored:** 1 tests
- **Duration:** 30m53s across 30 shards
- **Lines:** 4,358/5,206 matching (83.7%)
- **Avg test duration:** 16.8s — slowest: `matrix_test` (81.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m00s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 13.3s — slowest: `implementsOpTest` (26.6s)

### from_gnash/misc-swfc.all

- **Pass:** 17/20 (85.0%)
- **Ignored:** 1 tests
- **Duration:** 5m19s across 30 shards
- **Lines:** 550/585 matching (94.0%)
- **Avg test duration:** 15.8s — slowest: `hello` (26.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m45s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.3s — slowest: `initaction_in_definesprite` (25.8s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 44m53s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 11.5s — slowest: `acid/acid-large` (68.7s)

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
