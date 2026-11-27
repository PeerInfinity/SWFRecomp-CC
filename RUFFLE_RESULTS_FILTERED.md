# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `6ee6eded7b66`  
**Date:** 2026-11-27 02:09 UTC  
**Total duration:** 10h37m00s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 773 | 782 | 98.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1307 | 1323 | 98.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1564 | 1572 | 99.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 177 | 240 | 73.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 73 | 110 | 66.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 15 | 20 | 75.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 215 | 223 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 301 | 302 | 99.7% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4713** | **4872** | **96.7%** | |

*51 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 117,167 | 120,273 | 97.4% |
| avm2 | 161,493 | 162,733 | 99.2% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,941 | 85,970 | 99.97% |
| from_gnash/actionscript.all | 30,812 | 32,104 | 96.0% |
| from_gnash/misc-ming.all | 4,352 | 5,206 | 83.6% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 514 | 585 | 87.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,363 | 2,409 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,067 | 3,069 | 99.9% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **408,915** | **415,670** | **98.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 3 | 6 |
| avm2 | 1 | 15 |
| fonts | - | 1 |
| from_avmplus | - | 8 |
| from_gnash/actionscript.all | - | 63 |
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
| **Total** | **15** | **144** |

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
- **Duration:** 1m12s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 14.5s — slowest: `stream_incomplete_loop` (18.9s)

### avm1

- **Pass:** 773/782 (98.8%)
- **Ignored:** 9 tests
- **Duration:** 51m42s across 30 shards
- **Lines:** 117,167/120,273 matching (97.4%)
- **Avg test duration:** 3.9s — slowest: `define_font_glyph_table_order` (40.8s)

### avm2

- **Pass:** 1307/1323 (98.8%)
- **Ignored:** 29 tests
- **Duration:** 3h23m38s across 30 shards
- **Lines:** 161,493/162,733 matching (99.2%)
- **Avg test duration:** 9.0s — slowest: `away3d_advanced_shallow_water_demo` (80.0s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m48s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 18.7s — slowest: `device_font_glyph_fallback` (31.1s)

### from_avmplus

- **Pass:** 1564/1572 (99.5%)
- **Ignored:** 2 tests
- **Duration:** 2h57m14s across 30 shards
- **Lines:** 85,941/85,970 matching (99.97%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_002` (61.1s)

### from_gnash/actionscript.all

- **Pass:** 177/240 (73.8%)
- **Ignored:** 3 tests
- **Duration:** 22m28s across 30 shards
- **Lines:** 30,812/32,104 matching (96.0%)
- **Avg test duration:** 5.6s — slowest: `MovieClip-v8` (50.1s)

### from_gnash/misc-ming.all

- **Pass:** 73/110 (66.4%)
- **Ignored:** 1 tests
- **Duration:** 30m10s across 30 shards
- **Lines:** 4,352/5,206 matching (83.6%)
- **Avg test duration:** 16.2s — slowest: `matrix_test` (81.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 8.0s — slowest: `TextFieldTest` (24.7s)

### from_gnash/misc-swfc.all

- **Pass:** 15/20 (75.0%)
- **Ignored:** 1 tests
- **Duration:** 4m29s across 30 shards
- **Lines:** 514/585 matching (87.9%)
- **Avg test duration:** 13.3s — slowest: `action_execution_order_test10` (25.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m48s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 14.4s — slowest: `jump_after_end` (24.4s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 40m29s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 10.2s — slowest: `acid/acid-large` (68.7s)

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
