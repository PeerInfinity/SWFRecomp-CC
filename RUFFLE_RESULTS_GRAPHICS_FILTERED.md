# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `2973513c457e`  
**Date:** 2026-09-17 00:25 UTC  
**Total duration:** 11h04m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 697 | 714 | 97.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1205 | 1229 | 98.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1529 | 1572 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 141 | 239 | 59.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 213 | 223 | 95.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 95 | 95 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4234** | **4492** | **94.3%** | |

*82 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 111,132 | 114,100 | 97.4% |
| avm2 | 141,401 | 142,996 | 98.9% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,548 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 29,565 | 31,544 | 93.7% |
| from_gnash/misc-ming.all | 4,156 | 5,206 | 79.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,348 | 2,409 | 97.5% |
| from_shumway/avm1 | 487 | 487 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 728 | 728 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **378,274** | **386,798** | **97.8%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 4 | 13 | - |
| avm2 | 12 | 12 | - |
| fonts | 1 | 1 | - |
| from_avmplus | 1 | 41 | 1 |
| from_gnash/actionscript.all | 9 | 89 | - |
| from_gnash/misc-ming.all | 11 | 30 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 3 | 7 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 2 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 2 | - |
| text | 1 | - | - |
| timeline | 1 | 3 | - |
| visual | - | 2 | - |
| **Total** | **49** | **208** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | array-v7 | 96% |
| from_gnash/actionscript.all | array-v8 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m22s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.5s — slowest: `g711_event_mulaw` (22.9s)

### avm1

- **Pass:** 697/714 (97.6%)
- **Ignored:** 20 tests
- **Duration:** 54m57s across 30 shards
- **Lines:** 111,132/114,100 matching (97.4%)
- **Avg test duration:** 4.4s — slowest: `define_font_glyph_table_order` (41.7s)

### avm2

- **Pass:** 1205/1229 (98.0%)
- **Ignored:** 46 tests
- **Duration:** 3h38m24s across 30 shards
- **Lines:** 141,401/142,996 matching (98.9%)
- **Avg test duration:** 10.2s — slowest: `away3d_advanced_shallow_water_demo` (108.9s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m52s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 21.5s — slowest: `device_font_no_ink` (30.5s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 3h33m41s across 30 shards
- **Lines:** 85,548/85,970 matching (99.5%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_002` (63.2s)

### from_gnash/actionscript.all

- **Pass:** 141/239 (59.0%)
- **Ignored:** 4 tests
- **Duration:** 22m28s across 30 shards
- **Lines:** 29,565/31,544 matching (93.7%)
- **Avg test duration:** 5.4s — slowest: `MovieClip-v8` (53.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 29m13s across 30 shards
- **Lines:** 4,156/5,206 matching (79.8%)
- **Avg test duration:** 15.9s — slowest: `matrix_test` (111.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.1s — slowest: `function_test` (23.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m25s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 16.7s — slowest: `edittext_test1` (25.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m30s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.4s — slowest: `dict_cross` (23.7s)

### from_shumway

- **Pass:** 213/223 (95.5%)
- **Ignored:** 6 tests
- **Duration:** 43m50s across 30 shards
- **Lines:** 2,348/2,409 matching (97.5%)
- **Avg test duration:** 11.1s — slowest: `acid/acid-large` (65.6s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m18s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.7s — slowest: `text-bind` (22.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 48s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.0s — slowest: `empty_url` (22.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 5.6s — slowest: `avm2_loads_avm1_v10` (9.4s)

### regression

- **Pass:** 95/95 (100%)
- **Duration:** 17m21s across 30 shards
- **Lines:** 728/728 matching (100%)
- **Avg test duration:** 10.9s — slowest: `avm2_timeline_stroke_gradient` (44.3s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 10.2s — slowest: `scissor_rectangle` (12.3s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 15s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 2.1s — slowest: `convolution_filter_big_matrix` (2.5s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m25s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.7s — slowest: `auto_size/height` (29.7s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 2m37s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 9.2s — slowest: `frame_script_button_order` (28.5s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 34m18s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.9s — slowest: `definefont4` (111.8s)
