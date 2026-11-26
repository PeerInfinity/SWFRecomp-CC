# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `ed63ce7c4399`  
**Date:** 2026-11-26 18:40 UTC  
**Total duration:** 13h34m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 769 | 778 | 98.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1304 | 1320 | 98.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1549 | 1572 | 98.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 177 | 240 | 73.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 73 | 110 | 66.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 15 | 20 | 75.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 215 | 223 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 289 | 289 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4680** | **4852** | **96.5%** | |

*56 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 116,708 | 119,814 | 97.4% |
| avm2 | 161,511 | 162,638 | 99.3% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,606 | 85,970 | 99.6% |
| from_gnash/actionscript.all | 30,812 | 32,104 | 96.0% |
| from_gnash/misc-ming.all | 4,352 | 5,206 | 83.6% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 514 | 585 | 87.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,363 | 2,409 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,991 | 2,991 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **408,069** | **415,038** | **98.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 3 | 6 |
| avm2 | - | 16 |
| fonts | - | 1 |
| from_avmplus | - | 23 |
| from_gnash/actionscript.all | - | 63 |
| from_gnash/misc-ming.all | 8 | 29 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 8 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **12** | **160** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 2m09s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 25.8s — slowest: `g711` (32.8s)

### avm1

- **Pass:** 769/778 (98.8%)
- **Ignored:** 12 tests
- **Duration:** 1h26m43s across 30 shards
- **Lines:** 116,708/119,814 matching (97.4%)
- **Avg test duration:** 6.6s — slowest: `tab_ordering_movieclip_enabled_default` (54.2s)

### avm2

- **Pass:** 1304/1320 (98.8%)
- **Ignored:** 31 tests
- **Duration:** 4h19m40s across 30 shards
- **Lines:** 161,511/162,638 matching (99.3%)
- **Avg test duration:** 11.4s — slowest: `away3d_advanced_shallow_water_demo` (118.2s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m07s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 20.8s — slowest: `device_font_kerning` (36.0s)

### from_avmplus

- **Pass:** 1549/1572 (98.5%)
- **Ignored:** 2 tests
- **Duration:** 3h36m33s across 30 shards
- **Lines:** 85,606/85,970 matching (99.6%)
- **Avg test duration:** 8.2s — slowest: `ecma3/Statements/eregress_74474_003` (57.9s)

### from_gnash/actionscript.all

- **Pass:** 177/240 (73.8%)
- **Ignored:** 3 tests
- **Duration:** 30m03s across 30 shards
- **Lines:** 30,812/32,104 matching (96.0%)
- **Avg test duration:** 7.4s — slowest: `MovieClip-v8` (58.0s)

### from_gnash/misc-ming.all

- **Pass:** 73/110 (66.4%)
- **Ignored:** 1 tests
- **Duration:** 35m21s across 30 shards
- **Lines:** 4,352/5,206 matching (83.6%)
- **Avg test duration:** 19.0s — slowest: `matrix_test` (77.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 11.5s — slowest: `exception` (27.4s)

### from_gnash/misc-swfc.all

- **Pass:** 15/20 (75.0%)
- **Ignored:** 1 tests
- **Duration:** 5m03s across 30 shards
- **Lines:** 514/585 matching (87.9%)
- **Avg test duration:** 15.0s — slowest: `movieclip_destruction_test1` (27.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m56s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 17.8s — slowest: `background` (26.9s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 49m49s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 12.8s — slowest: `acid/acid-large` (90.6s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m27s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `text-bind` (20.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 56s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 18.7s — slowest: `empty_url` (27.2s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m32s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.7s — slowest: `avm1_sprite_sc_ignored` (21.5s)

### regression

- **Pass:** 289/289 (100%)
- **Duration:** 1h02m51s across 30 shards
- **Lines:** 2,991/2,991 matching (100%)
- **Avg test duration:** 13.0s — slowest: `avm2_definetext_matrix` (37.7s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m37s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 12.2s — slowest: `draw_to_bitmap_data_unconfigured` (21.1s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.2s — slowest: `lzma_length_too_long` (26.7s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m59s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 19.9s — slowest: `auto_size/return` (41.2s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m16s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 22.1s — slowest: `frame_script_button_order` (34.1s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 36m59s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.7s — slowest: `definefont4` (115.3s)
