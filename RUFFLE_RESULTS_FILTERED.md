# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `b8671fd2f516`  
**Date:** 2026-11-28 02:31 UTC  
**Total duration:** 11h34m16s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 776 | 783 | 99.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1311 | 1324 | 99.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1567 | 1572 | 99.7% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 193 | 240 | 80.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 77 | 110 | 70.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 17 | 20 | 85.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 20 | 20 | 100% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 217 | 223 | 97.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 346 | 346 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 16 | 17 | 94.1% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4795** | **4918** | **97.5%** | |

*50 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 117,172 | 120,277 | 97.4% |
| avm2 | 161,629 | 162,765 | 99.3% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,944 | 85,970 | 99.97% |
| from_gnash/actionscript.all | 31,149 | 32,104 | 97.0% |
| from_gnash/misc-ming.all | 4,396 | 5,206 | 84.4% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 550 | 585 | 94.0% |
| from_gnash/misc-swfmill.all | 95 | 95 | 100% |
| from_shumway | 2,368 | 2,409 | 98.3% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,757 | 3,757 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **410,178** | **416,394** | **98.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 3 | 4 |
| avm2 | 1 | 12 |
| fonts | - | 1 |
| from_avmplus | - | 5 |
| from_gnash/actionscript.all | - | 47 |
| from_gnash/misc-ming.all | 6 | 27 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 3 |
| from_gnash/misc-swfmill.all | - | - |
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
| **Total** | **12** | **111** |

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
- **Avg test duration:** 14.5s — slowest: `stream_incomplete_loop` (19.6s)

### avm1

- **Pass:** 776/783 (99.1%)
- **Ignored:** 8 tests
- **Duration:** 1h13m08s across 30 shards
- **Lines:** 117,172/120,277 matching (97.4%)
- **Avg test duration:** 5.5s — slowest: `textfield_border_color` (31.9s)

### avm2

- **Pass:** 1311/1324 (99.0%)
- **Ignored:** 29 tests
- **Duration:** 3h37m12s across 30 shards
- **Lines:** 161,629/162,765 matching (99.3%)
- **Avg test duration:** 9.6s — slowest: `away3d_advanced_shallow_water_demo` (85.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m41s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.9s — slowest: `device_font_kerning` (25.4s)

### from_avmplus

- **Pass:** 1567/1572 (99.7%)
- **Ignored:** 2 tests
- **Duration:** 2h48m43s across 30 shards
- **Lines:** 85,944/85,970 matching (99.97%)
- **Avg test duration:** 6.4s — slowest: `ecma3/Statements/eregress_74474_003` (65.8s)

### from_gnash/actionscript.all

- **Pass:** 193/240 (80.4%)
- **Ignored:** 3 tests
- **Duration:** 27m48s across 30 shards
- **Lines:** 31,149/32,104 matching (97.0%)
- **Avg test duration:** 6.9s — slowest: `MovieClip-v8` (52.7s)

### from_gnash/misc-ming.all

- **Pass:** 77/110 (70.0%)
- **Ignored:** 1 tests
- **Duration:** 32m39s across 30 shards
- **Lines:** 4,396/5,206 matching (84.4%)
- **Avg test duration:** 17.6s — slowest: `matrix_test` (78.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m47s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 11.9s — slowest: `exception` (20.3s)

### from_gnash/misc-swfc.all

- **Pass:** 17/20 (85.0%)
- **Ignored:** 1 tests
- **Duration:** 5m19s across 30 shards
- **Lines:** 550/585 matching (94.0%)
- **Avg test duration:** 15.9s — slowest: `movieclip_destruction_test3` (26.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 20/20 (100%)
- **Duration:** 6m42s across 30 shards
- **Lines:** 95/95 matching (100%)
- **Avg test duration:** 20.1s — slowest: `registers` (26.3s)

### from_shumway

- **Pass:** 217/223 (97.3%)
- **Ignored:** 6 tests
- **Duration:** 42m49s across 30 shards
- **Lines:** 2,368/2,409 matching (98.3%)
- **Avg test duration:** 10.9s — slowest: `acid/acid-large` (68.4s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.2s — slowest: `label` (21.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 42s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.1s — slowest: `avm1_non_swf_import` (20.8s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.2s — slowest: `avm1_sprite_sc_ignored` (20.3s)

### regression

- **Pass:** 346/346 (100%)
- **Duration:** 1h05m26s across 30 shards
- **Lines:** 3,757/3,757 matching (100%)
- **Avg test duration:** 11.3s — slowest: `avm2_applyfilter_bevel_sample` (39.7s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.8s — slowest: `draw_to_bitmap_data_unconfigured` (24.9s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.7s — slowest: `lzma_length_too_long` (20.2s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m29s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.4s — slowest: `text_caret_placement_leading` (33.0s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 6m09s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 21.7s — slowest: `swf_9_frame_script_button_order` (33.9s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m39s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.9s — slowest: `definefont4` (86.9s)
