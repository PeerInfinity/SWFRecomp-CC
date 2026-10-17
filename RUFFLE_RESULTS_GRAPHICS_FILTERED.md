# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `38cf9b1a0ab8`  
**Date:** 2026-10-17 04:05 UTC  
**Total duration:** 12h19m12s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 708 | 726 | 97.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1232 | 1254 | 98.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1531 | 1572 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 102 | 102 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4293** | **4539** | **94.6%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 114,628 | 117,593 | 97.5% |
| avm2 | 152,145 | 153,415 | 99.2% |
| fonts | 351 | 377 | 93.1% |
| from_avmplus | 85,550 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,347 | 32,104 | 94.5% |
| from_gnash/misc-ming.all | 4,229 | 5,206 | 81.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,351 | 2,409 | 97.6% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 859 | 859 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **393,680** | **401,418** | **98.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 2 | - |
| avm1 | 3 | 15 |
| avm2 | 4 | 18 |
| fonts | 1 | 1 |
| from_avmplus | - | 41 |
| from_gnash/actionscript.all | 4 | 88 |
| from_gnash/misc-ming.all | 8 | 33 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 2 | 7 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | 2 |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **27** | **219** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | edittext_html_duplicate_attributes | 98% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.6s — slowest: `stream_incomplete_loop` (23.0s)

### avm1

- **Pass:** 708/726 (97.5%)
- **Ignored:** 18 tests
- **Duration:** 1h11m41s across 30 shards
- **Lines:** 114,628/117,593 matching (97.5%)
- **Avg test duration:** 5.7s — slowest: `globals_swf8` (37.7s)

### avm2

- **Pass:** 1232/1254 (98.2%)
- **Ignored:** 38 tests
- **Duration:** 4h02m39s across 30 shards
- **Lines:** 152,145/153,415 matching (99.2%)
- **Avg test duration:** 11.2s — slowest: `away3d_advanced_shallow_water_demo` (91.7s)

### fonts

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m10s across 30 shards
- **Lines:** 351/377 matching (93.1%)
- **Avg test duration:** 21.1s — slowest: `embed_matching/fallback_preferences` (33.2s)

### from_avmplus

- **Pass:** 1531/1572 (97.4%)
- **Ignored:** 2 tests
- **Duration:** 3h40m36s across 30 shards
- **Lines:** 85,550/85,970 matching (99.5%)
- **Avg test duration:** 8.3s — slowest: `ecma3/Statements/eregress_74474_003` (49.4s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 29m09s across 30 shards
- **Lines:** 30,347/32,104 matching (94.5%)
- **Avg test duration:** 7.2s — slowest: `MovieClip-v8` (67.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 33m12s across 30 shards
- **Lines:** 4,229/5,206 matching (81.2%)
- **Avg test duration:** 18.0s — slowest: `matrix_test` (113.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.9s — slowest: `implementsOpTest` (24.4s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m28s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 16.8s — slowest: `action_execution_order_test10` (24.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m54s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 14.7s — slowest: `afunc_dict` (23.3s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 50m35s across 30 shards
- **Lines:** 2,351/2,409 matching (97.6%)
- **Avg test duration:** 12.8s — slowest: `acid/acid-large` (79.1s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m34s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.2s — slowest: `label` (22.8s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 46s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.1s — slowest: `avm1_non_swf_import` (21.7s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.3s — slowest: `avm2_loads_avm1` (9.6s)

### regression

- **Pass:** 102/102 (100%)
- **Duration:** 23m15s across 30 shards
- **Lines:** 859/859 matching (100%)
- **Avg test duration:** 13.6s — slowest: `avm2_slot_default_template` (50.6s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 11.6s — slowest: `unbound_texture` (12.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 37s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 5.2s — slowest: `convolution_filter_big_matrix` (23.4s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m42s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 20.2s — slowest: `auto_size/height` (35.7s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m46s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 16.8s — slowest: `swf_9_event_goto_frame_script` (30.7s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 35m56s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.6s — slowest: `definefont4` (78.8s)
