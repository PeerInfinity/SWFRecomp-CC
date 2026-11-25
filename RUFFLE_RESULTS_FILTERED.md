# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `10a5b515a03a`  
**Date:** 2026-11-25 21:10 UTC  
**Total duration:** 11h03m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 766 | 777 | 98.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1293 | 1315 | 98.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1544 | 1572 | 98.2% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 167 | 240 | 69.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 71 | 110 | 64.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 15 | 20 | 75.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 215 | 223 | 96.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 262 | 262 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4621** | **4819** | **95.9%** | |

*56 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 116,605 | 119,712 | 97.4% |
| avm2 | 160,821 | 162,518 | 99.0% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,582 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,707 | 32,104 | 95.6% |
| from_gnash/misc-ming.all | 4,311 | 5,206 | 82.8% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 514 | 585 | 87.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,363 | 2,409 | 98.1% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,102 | 2,102 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **406,211** | **413,927** | **98.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 4 | 7 |
| avm2 | 2 | 20 |
| fonts | - | 1 |
| from_avmplus | 1 | 27 |
| from_gnash/actionscript.all | 5 | 68 |
| from_gnash/misc-ming.all | 8 | 31 |
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
| **Total** | **22** | **176** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_avmplus | ecma3/JSON/AS3Types | 96% |
| avm1 | boxed_primitives | 96% |
| avm2 | number_tostring | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 14.3s — slowest: `stream_incomplete_loop` (20.1s)

### avm1

- **Pass:** 766/777 (98.6%)
- **Ignored:** 12 tests
- **Duration:** 1h11m35s across 30 shards
- **Lines:** 116,605/119,712 matching (97.4%)
- **Avg test duration:** 5.4s — slowest: `define_font_glyph_table_order` (40.1s)

### avm2

- **Pass:** 1293/1315 (98.3%)
- **Ignored:** 31 tests
- **Duration:** 3h32m38s across 30 shards
- **Lines:** 160,821/162,518 matching (99.0%)
- **Avg test duration:** 9.3s — slowest: `away3d_advanced_shallow_water_demo` (78.6s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m40s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.8s — slowest: `device_font_glyph_fallback` (29.8s)

### from_avmplus

- **Pass:** 1544/1572 (98.2%)
- **Ignored:** 2 tests
- **Duration:** 2h44m07s across 30 shards
- **Lines:** 85,582/85,970 matching (99.5%)
- **Avg test duration:** 6.2s — slowest: `ecma3/Statements/eregress_74474_002` (65.5s)

### from_gnash/actionscript.all

- **Pass:** 167/240 (69.6%)
- **Ignored:** 3 tests
- **Duration:** 27m30s across 30 shards
- **Lines:** 30,707/32,104 matching (95.6%)
- **Avg test duration:** 6.8s — slowest: `MovieClip-v8` (52.0s)

### from_gnash/misc-ming.all

- **Pass:** 71/110 (64.5%)
- **Ignored:** 1 tests
- **Duration:** 31m46s across 30 shards
- **Lines:** 4,311/5,206 matching (82.8%)
- **Avg test duration:** 17.1s — slowest: `matrix_test` (76.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m47s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 11.9s — slowest: `TextFieldTest` (23.5s)

### from_gnash/misc-swfc.all

- **Pass:** 15/20 (75.0%)
- **Ignored:** 1 tests
- **Duration:** 4m44s across 30 shards
- **Lines:** 514/585 matching (87.9%)
- **Avg test duration:** 14.1s — slowest: `action_execution_order_test10` (24.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m27s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.3s — slowest: `trace-as2/root_onload` (27.3s)

### from_shumway

- **Pass:** 215/223 (96.4%)
- **Ignored:** 6 tests
- **Duration:** 42m04s across 30 shards
- **Lines:** 2,363/2,409 matching (98.1%)
- **Avg test duration:** 10.7s — slowest: `acid/acid-large` (75.1s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m41s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.1s — slowest: `label` (19.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.3s — slowest: `avm1_non_swf_import` (19.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m09s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.7s — slowest: `avm1_sprite_sc_ignored` (18.1s)

### regression

- **Pass:** 262/262 (100%)
- **Duration:** 49m09s across 30 shards
- **Lines:** 2,102/2,102 matching (100%)
- **Avg test duration:** 11.2s — slowest: `avm2_applyfilter_gradient_opaque` (44.0s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m22s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 10.3s — slowest: `draw_to_bitmap_data_unconfigured` (29.6s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m22s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.8s — slowest: `convolution_filter_big_matrix` (23.3s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m17s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 16.4s — slowest: `auto_size/height` (30.0s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m51s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 20.7s — slowest: `swf_9_frame_script_dynamic_goto` (35.6s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m05s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.7s — slowest: `definefont4` (83.8s)
