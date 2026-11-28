# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `3dfab12779f5`  
**Date:** 2026-11-28 08:08 UTC  
**Total duration:** 10h42m54s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 776 | 791 | 98.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1321 | 1353 | 97.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1567 | 1574 | 99.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 193 | 243 | 79.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 77 | 111 | 69.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 17 | 21 | 81.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 20 | 20 | 100% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 218 | 229 | 95.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 347 | 347 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 16 | 17 | 94.1% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4807** | **4969** | **96.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 127,286 | 137,880 | 92.3% |
| avm2 | 163,065 | 164,501 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,956 | 85,996 | 99.95% |
| from_gnash/actionscript.all | 31,367 | 38,791 | 80.9% |
| from_gnash/misc-ming.all | 4,403 | 5,248 | 83.9% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 565 | 603 | 93.7% |
| from_gnash/misc-swfmill.all | 95 | 95 | 100% |
| from_shumway | 2,414 | 2,484 | 97.2% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,770 | 3,770 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **422,039** | **442,594** | **95.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 9 |
| avm2 | 6 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 7 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 1 |
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
| **Total** | **31** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | movieclip_hittest_shapeflag | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm2 | loader_load | 98% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `b8671fd2f516` → `3dfab12779f5`*

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

- **Pass:** 776/791 (98.1%)
- **Duration:** 1h01m12s across 30 shards
- **Lines:** 127,286/137,880 matching (92.3%)
- **Avg test duration:** 4.6s — slowest: `netstream_play_flv_screen` (42.7s)

### avm2

- **Pass:** 1321/1353 (97.6%)
- **Duration:** 3h20m53s across 30 shards
- **Lines:** 163,065/164,501 matching (99.1%)
- **Avg test duration:** 8.9s — slowest: `away3d_advanced_shallow_water_demo` (80.7s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m36s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.3s — slowest: `device_font_glyph_fallback` (25.3s)

### from_avmplus

- **Pass:** 1567/1574 (99.6%)
- **Duration:** 2h45m30s across 30 shards
- **Lines:** 85,956/85,996 matching (99.95%)
- **Avg test duration:** 6.3s — slowest: `ecma3/Statements/eregress_74474_003` (53.9s)

### from_gnash/actionscript.all

- **Pass:** 193/243 (79.4%)
- **Duration:** 23m19s across 30 shards
- **Lines:** 31,367/38,791 matching (80.9%)
- **Avg test duration:** 5.7s — slowest: `MovieClip-v8` (50.5s)

### from_gnash/misc-ming.all

- **Pass:** 77/111 (69.4%)
- **Duration:** 27m53s across 30 shards
- **Lines:** 4,403/5,248 matching (83.9%)
- **Avg test duration:** 15.0s — slowest: `matrix_test` (87.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.4s — slowest: `inheritance` (25.3s)

### from_gnash/misc-swfc.all

- **Pass:** 17/21 (81.0%)
- **Duration:** 4m59s across 30 shards
- **Lines:** 565/603 matching (93.7%)
- **Avg test duration:** 14.2s — slowest: `movieclip_destruction_test3` (25.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 20/20 (100%)
- **Duration:** 6m36s across 30 shards
- **Lines:** 95/95 matching (100%)
- **Avg test duration:** 19.8s — slowest: `registers` (25.1s)

### from_shumway

- **Pass:** 218/229 (95.2%)
- **Duration:** 41m45s across 30 shards
- **Lines:** 2,414/2,484 matching (97.2%)
- **Avg test duration:** 10.9s — slowest: `esc` (69.9s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m37s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.0s — slowest: `hitarea` (19.2s)

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
- **Duration:** 59m17s across 30 shards
- **Lines:** 3,770/3,770 matching (100%)
- **Avg test duration:** 10.2s — slowest: `avm2_definetext_matrix` (32.9s)

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
