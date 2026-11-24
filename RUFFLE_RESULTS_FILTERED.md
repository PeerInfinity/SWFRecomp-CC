# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `cceb5133a189`  
**Date:** 2026-11-24 07:00 UTC  
**Total duration:** 11h15m09s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 750 | 770 | 97.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1287 | 1309 | 98.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1533 | 1572 | 97.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 71 | 110 | 64.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 14 | 20 | 70.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 214 | 222 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 204 | 204 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4507** | **4747** | **94.9%** | |

*63 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 116,183 | 119,574 | 97.2% |
| avm2 | 157,607 | 158,966 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,556 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,595 | 32,104 | 95.3% |
| from_gnash/misc-ming.all | 4,306 | 5,206 | 82.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 512 | 585 | 87.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,361 | 2,407 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 1,557 | 1,557 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **401,863** | **409,690** | **98.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 3 | 17 |
| avm2 | 1 | 21 |
| fonts | - | 1 |
| from_avmplus | - | 39 |
| from_gnash/actionscript.all | - | 92 |
| from_gnash/misc-ming.all | 7 | 32 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 6 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 8 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | 2 |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **13** | **227** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

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
- **Avg test duration:** 13.9s — slowest: `g711_event_mulaw` (18.6s)

### avm1

- **Pass:** 750/770 (97.4%)
- **Ignored:** 15 tests
- **Duration:** 1h13m11s across 30 shards
- **Lines:** 116,183/119,574 matching (97.2%)
- **Avg test duration:** 5.6s — slowest: `netstream_play_flv_screen` (39.6s)

### avm2

- **Pass:** 1287/1309 (98.3%)
- **Ignored:** 34 tests
- **Duration:** 3h41m02s across 30 shards
- **Lines:** 157,607/158,966 matching (99.1%)
- **Avg test duration:** 9.8s — slowest: `away3d_advanced_shallow_water_demo` (81.3s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m34s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.2s — slowest: `device_font_glyph_fallback` (29.8s)

### from_avmplus

- **Pass:** 1533/1572 (97.5%)
- **Ignored:** 2 tests
- **Duration:** 2h51m52s across 30 shards
- **Lines:** 85,556/85,970 matching (99.5%)
- **Avg test duration:** 6.5s — slowest: `ecma3/Statements/eregress_74474_002` (60.1s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 28m37s across 30 shards
- **Lines:** 30,595/32,104 matching (95.3%)
- **Avg test duration:** 7.1s — slowest: `MovieClip-v8` (72.0s)

### from_gnash/misc-ming.all

- **Pass:** 71/110 (64.5%)
- **Ignored:** 1 tests
- **Duration:** 31m38s across 30 shards
- **Lines:** 4,306/5,206 matching (82.7%)
- **Avg test duration:** 17.1s — slowest: `matrix_test` (75.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.6s — slowest: `inheritance` (27.4s)

### from_gnash/misc-swfc.all

- **Pass:** 14/20 (70.0%)
- **Ignored:** 1 tests
- **Duration:** 5m35s across 30 shards
- **Lines:** 512/585 matching (87.5%)
- **Avg test duration:** 16.7s — slowest: `movieclip_destruction_test3` (27.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m42s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.1s — slowest: `registers` (25.8s)

### from_shumway

- **Pass:** 214/222 (96.4%)
- **Ignored:** 7 tests
- **Duration:** 42m50s across 30 shards
- **Lines:** 2,361/2,407 matching (98.1%)
- **Avg test duration:** 10.8s — slowest: `acid/acid-large` (65.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.3s — slowest: `hitarea` (23.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 36s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 11.9s — slowest: `empty_url` (18.8s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.4s — slowest: `avm1_sprite_sc_ignored` (18.7s)

### regression

- **Pass:** 204/204 (100%)
- **Duration:** 41m30s across 30 shards
- **Lines:** 1,557/1,557 matching (100%)
- **Avg test duration:** 12.2s — slowest: `avm2_parent_child_render` (54.2s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m27s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.8s — slowest: `draw_to_bitmap_data_unconfigured` (29.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 58s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 8.3s — slowest: `convolution_filter_big_matrix` (23.1s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m25s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.1s — slowest: `auto_size/height` (30.2s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m05s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.5s — slowest: `swf_9_event_goto_frame_script` (31.9s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 30m49s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.2s — slowest: `definefont4` (82.6s)
