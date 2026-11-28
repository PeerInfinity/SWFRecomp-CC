# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `9498e80c12e3`  
**Date:** 2026-11-28 00:52 UTC  
**Total duration:** 14h11m12s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 776 | 783 | 99.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1312 | 1324 | 99.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1567 | 1572 | 99.7% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 182 | 240 | 75.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 76 | 110 | 69.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 17 | 20 | 85.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 217 | 223 | 97.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 344 | 344 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 16 | 17 | 94.1% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4782** | **4916** | **97.3%** | |

*50 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 117,172 | 120,277 | 97.4% |
| avm2 | 161,747 | 162,765 | 99.4% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,944 | 85,970 | 99.97% |
| from_gnash/actionscript.all | 30,897 | 32,104 | 96.2% |
| from_gnash/misc-ming.all | 4,369 | 5,206 | 83.9% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 550 | 585 | 94.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,368 | 2,409 | 98.3% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,741 | 3,741 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **410,005** | **416,378** | **98.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 3 | 4 |
| avm2 | - | 12 |
| fonts | - | 1 |
| from_avmplus | - | 5 |
| from_gnash/actionscript.all | - | 58 |
| from_gnash/misc-ming.all | 6 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 3 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 6 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | 1 |
| visual | - | 2 |
| **Total** | **10** | **124** |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 22.0s — slowest: `g711` (24.2s)

### avm1

- **Pass:** 776/783 (99.1%)
- **Ignored:** 8 tests
- **Duration:** 1h32m22s across 30 shards
- **Lines:** 117,172/120,277 matching (97.4%)
- **Avg test duration:** 7.0s — slowest: `virtual_property_recursion_swf6` (46.6s)

### avm2

- **Pass:** 1312/1324 (99.1%)
- **Ignored:** 29 tests
- **Duration:** 4h25m17s across 30 shards
- **Lines:** 161,747/162,765 matching (99.4%)
- **Avg test duration:** 11.7s — slowest: `away3d_advanced_shallow_water_demo` (94.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m09s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 21.0s — slowest: `device_font_no_ink` (27.8s)

### from_avmplus

- **Pass:** 1567/1572 (99.7%)
- **Ignored:** 2 tests
- **Duration:** 3h33m25s across 30 shards
- **Lines:** 85,944/85,970 matching (99.97%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_003` (59.6s)

### from_gnash/actionscript.all

- **Pass:** 182/240 (75.8%)
- **Ignored:** 3 tests
- **Duration:** 32m33s across 30 shards
- **Lines:** 30,897/32,104 matching (96.2%)
- **Avg test duration:** 8.1s — slowest: `array-v5` (53.4s)

### from_gnash/misc-ming.all

- **Pass:** 76/110 (69.1%)
- **Ignored:** 1 tests
- **Duration:** 36m09s across 30 shards
- **Lines:** 4,369/5,206 matching (83.9%)
- **Avg test duration:** 19.4s — slowest: `matrix_test` (124.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m52s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.4s — slowest: `exception` (21.3s)

### from_gnash/misc-swfc.all

- **Pass:** 17/20 (85.0%)
- **Ignored:** 1 tests
- **Duration:** 5m55s across 30 shards
- **Lines:** 550/585 matching (94.0%)
- **Avg test duration:** 17.6s — slowest: `opcode_guard_test2` (26.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m51s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.6s — slowest: `trace-as2/arguments` (25.6s)

### from_shumway

- **Pass:** 217/223 (97.3%)
- **Ignored:** 6 tests
- **Duration:** 53m28s across 30 shards
- **Lines:** 2,368/2,409 matching (98.3%)
- **Avg test duration:** 13.6s — slowest: `acid/acid-large` (76.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m35s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.3s — slowest: `text-bind` (26.7s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.5s — slowest: `empty_url` (21.0s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.4s — slowest: `avm1_sprite_sc_ignored` (20.8s)

### regression

- **Pass:** 344/344 (100%)
- **Duration:** 1h15m46s across 30 shards
- **Lines:** 3,741/3,741 matching (100%)
- **Avg test duration:** 13.2s — slowest: `avm2_layer_group_erase` (41.0s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 13.6s — slowest: `request_matching_profiles` (27.9s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.1s — slowest: `swf_length_too_long` (21.4s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m43s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.6s — slowest: `auto_size/return` (30.4s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 6m30s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 22.9s — slowest: `swf_9_frame_script_cleanup_goto2` (34.0s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 44m14s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 17.5s — slowest: `definefont4` (91.0s)
