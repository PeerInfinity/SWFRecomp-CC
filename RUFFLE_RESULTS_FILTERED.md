# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `16033a154646`  
**Date:** 2026-11-25 22:59 UTC  
**Total duration:** 10h09m41s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 767 | 777 | 98.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1298 | 1316 | 98.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1549 | 1572 | 98.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 167 | 240 | 69.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 73 | 110 | 66.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 15 | 20 | 75.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 215 | 223 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 278 | 279 | 99.6% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4650** | **4837** | **96.1%** | |

*56 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 116,651 | 119,758 | 97.4% |
| avm2 | 161,295 | 162,541 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,606 | 85,970 | 99.6% |
| from_gnash/actionscript.all | 30,707 | 32,104 | 95.6% |
| from_gnash/misc-ming.all | 4,352 | 5,206 | 83.6% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 514 | 585 | 87.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,363 | 2,409 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,775 | 2,776 | 99.96% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **407,469** | **414,670** | **98.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 4 | 6 |
| avm2 | 2 | 16 |
| fonts | - | 1 |
| from_avmplus | - | 23 |
| from_gnash/actionscript.all | 5 | 68 |
| from_gnash/misc-ming.all | 8 | 29 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 5 |
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
| **Total** | **22** | **165** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | boxed_primitives | 96% |
| regression | avm1_place_occupied_depth_swf5 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

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
- **Avg test duration:** 14.4s — slowest: `stream_incomplete_loop` (21.3s)

### avm1

- **Pass:** 767/777 (98.7%)
- **Ignored:** 12 tests
- **Duration:** 55m30s across 30 shards
- **Lines:** 116,651/119,758 matching (97.4%)
- **Avg test duration:** 4.2s — slowest: `define_font_glyph_table_order` (40.3s)

### avm2

- **Pass:** 1298/1316 (98.6%)
- **Ignored:** 31 tests
- **Duration:** 3h15m46s across 30 shards
- **Lines:** 161,295/162,541 matching (99.2%)
- **Avg test duration:** 8.6s — slowest: `away3d_advanced_shallow_water_demo` (78.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m36s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.3s — slowest: `device_font_no_ink` (26.8s)

### from_avmplus

- **Pass:** 1549/1572 (98.5%)
- **Ignored:** 2 tests
- **Duration:** 2h40m40s across 30 shards
- **Lines:** 85,606/85,970 matching (99.6%)
- **Avg test duration:** 6.1s — slowest: `ecma3/Statements/eregress_74474_003` (57.2s)

### from_gnash/actionscript.all

- **Pass:** 167/240 (69.6%)
- **Ignored:** 3 tests
- **Duration:** 22m30s across 30 shards
- **Lines:** 30,707/32,104 matching (95.6%)
- **Avg test duration:** 5.6s — slowest: `MovieClip-v8` (55.4s)

### from_gnash/misc-ming.all

- **Pass:** 73/110 (66.4%)
- **Ignored:** 1 tests
- **Duration:** 27m43s across 30 shards
- **Lines:** 4,352/5,206 matching (83.6%)
- **Avg test duration:** 14.9s — slowest: `matrix_test` (80.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 9.3s — slowest: `function_test` (19.5s)

### from_gnash/misc-swfc.all

- **Pass:** 15/20 (75.0%)
- **Ignored:** 1 tests
- **Duration:** 4m19s across 30 shards
- **Lines:** 514/585 matching (87.9%)
- **Avg test duration:** 12.8s — slowest: `movieclip_destruction_test4` (23.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m11s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.5s — slowest: `jump_after_end` (23.2s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 39m50s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 10.1s — slowest: `acid/acid-large` (76.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.3s — slowest: `label` (23.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.3s — slowest: `avm1_non_swf_import` (19.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.7s — slowest: `avm1_sprite_sc_ignored` (19.1s)

### regression

- **Pass:** 278/279 (99.6%)
- **Duration:** 47m37s across 30 shards
- **Lines:** 2,775/2,776 matching (99.96%)
- **Avg test duration:** 10.2s — slowest: `avm2_findprop_this_resolution` (39.9s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.1s — slowest: `draw_to_bitmap_data_unconfigured` (19.2s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 10.9s — slowest: `swf_length_too_long` (19.3s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m17s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 16.5s — slowest: `text_caret_placement_align` (31.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m40s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 20.0s — slowest: `frame_script_construct` (30.2s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 29m13s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.6s — slowest: `definefont4` (84.4s)
