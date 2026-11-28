# Ruffle Test Results (Filtered)

*Tests on the [ignored list](../ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `494d7c7e06fd`  
**Date:** 2026-11-28 18:23 UTC  
**Total duration:** 10h15m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](../tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 776 | 785 | 98.9% | [details](../tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1311 | 1325 | 98.9% | [details](../tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](../tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1567 | 1572 | 99.7% | [details](../tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 193 | 240 | 80.4% | [details](../tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 77 | 110 | 70.0% | [details](../tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](../tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 17 | 20 | 85.0% | [details](../tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 20 | 20 | 100% | [details](../tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 217 | 223 | 97.3% | [details](../tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](../tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](../tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](../tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 347 | 347 | 100% | [details](../tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](../tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 7 | 7 | 100% | [details](../tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](../tests/swfs/text/_results/results_filtered.md) |
| timeline | 16 | 17 | 94.1% | [details](../tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](../tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4796** | **4922** | **97.4%** | |

*52 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 117,187 | 120,307 | 97.4% |
| avm2 | 161,647 | 162,785 | 99.3% |
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
| regression | 3,770 | 3,770 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **410,224** | **416,457** | **98.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 5 | 4 |
| avm2 | 2 | 12 |
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
| **Total** | **15** | **111** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | shared_object | 90% |

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
- **Avg test duration:** 14.4s — slowest: `stream_incomplete_loop` (20.0s)

### avm1

- **Pass:** 776/785 (98.9%)
- **Ignored:** 10 tests
- **Duration:** 48m30s across 30 shards
- **Lines:** 117,187/120,307 matching (97.4%)
- **Avg test duration:** 3.6s — slowest: `netstream_play_flv_screen` (33.2s)

### avm2

- **Pass:** 1311/1325 (98.9%)
- **Ignored:** 29 tests
- **Duration:** 3h19m06s across 30 shards
- **Lines:** 161,647/162,785 matching (99.3%)
- **Avg test duration:** 8.8s — slowest: `away3d_advanced_shallow_water_demo` (82.3s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m36s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.3s — slowest: `device_font_glyph_fallback` (25.3s)

### from_avmplus

- **Pass:** 1567/1572 (99.7%)
- **Ignored:** 2 tests
- **Duration:** 2h45m30s across 30 shards
- **Lines:** 85,944/85,970 matching (99.97%)
- **Avg test duration:** 6.3s — slowest: `ecma3/Statements/eregress_74474_003` (53.9s)

### from_gnash/actionscript.all

- **Pass:** 193/240 (80.4%)
- **Ignored:** 3 tests
- **Duration:** 19m22s across 30 shards
- **Lines:** 31,149/32,104 matching (97.0%)
- **Avg test duration:** 4.8s — slowest: `MovieClip-v8` (53.3s)

### from_gnash/misc-ming.all

- **Pass:** 77/110 (70.0%)
- **Ignored:** 1 tests
- **Duration:** 23m28s across 30 shards
- **Lines:** 4,396/5,206 matching (84.4%)
- **Avg test duration:** 12.7s — slowest: `matrix_test` (84.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 16.0s — slowest: `function_test` (25.5s)

### from_gnash/misc-swfc.all

- **Pass:** 17/20 (85.0%)
- **Ignored:** 1 tests
- **Duration:** 3m52s across 30 shards
- **Lines:** 550/585 matching (94.0%)
- **Avg test duration:** 11.5s — slowest: `edittext_test1` (26.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 20/20 (100%)
- **Duration:** 6m49s across 30 shards
- **Lines:** 95/95 matching (100%)
- **Avg test duration:** 20.4s — slowest: `dict_event` (24.7s)

### from_shumway

- **Pass:** 217/223 (97.3%)
- **Ignored:** 6 tests
- **Duration:** 40m49s across 30 shards
- **Lines:** 2,368/2,409 matching (98.3%)
- **Avg test duration:** 10.4s — slowest: `acid/acid-large` (87.2s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m00s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.5s — slowest: `label` (25.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 42s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.8s — slowest: `empty_url` (20.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m03s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.3s — slowest: `avm1_sprite_sc_ignored` (18.5s)

### regression

- **Pass:** 347/347 (100%)
- **Duration:** 55m31s across 30 shards
- **Lines:** 3,770/3,770 matching (100%)
- **Avg test duration:** 9.6s — slowest: `avm2_parent_child_symbolclass_domain` (33.9s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.1s — slowest: `draw_to_bitmap_data_unconfigured` (25.2s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.4s — slowest: `convolution_filter_big_matrix` (19.7s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m13s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 16.1s — slowest: `auto_size/height` (25.5s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 5m24s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 19.1s — slowest: `frame_script_cleanup_goto` (33.0s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 31m01s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.3s — slowest: `definefont4` (82.5s)
