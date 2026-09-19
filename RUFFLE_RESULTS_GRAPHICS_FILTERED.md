# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `d6bcfa56c4c0`  
**Date:** 2026-09-19 05:45 UTC  
**Total duration:** 10h49m00s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 698 | 716 | 97.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1215 | 1235 | 98.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1529 | 1572 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 141 | 239 | 59.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 213 | 223 | 95.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 96 | 96 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4247** | **4502** | **94.3%** | |

*74 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 111,156 | 114,125 | 97.4% |
| avm2 | 150,329 | 151,614 | 99.2% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,548 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 29,577 | 31,544 | 93.8% |
| from_gnash/misc-ming.all | 4,190 | 5,206 | 80.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,348 | 2,409 | 97.5% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 764 | 764 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **387,312** | **395,481** | **97.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 3 | 15 | - |
| avm2 | 5 | 15 | - |
| fonts | 1 | 1 | - |
| from_avmplus | 1 | 41 | 1 |
| from_gnash/actionscript.all | 9 | 89 | - |
| from_gnash/misc-ming.all | 10 | 31 | - |
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
| **Total** | **40** | **214** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | array-v7 | 97% |
| from_gnash/actionscript.all | array-v8 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
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
- **Duration:** 1m16s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.3s — slowest: `g711_event_mulaw` (21.9s)

### avm1

- **Pass:** 698/716 (97.5%)
- **Ignored:** 19 tests
- **Duration:** 56m27s across 30 shards
- **Lines:** 111,156/114,125 matching (97.4%)
- **Avg test duration:** 4.5s — slowest: `goto_both_ways1` (28.2s)

### avm2

- **Pass:** 1215/1235 (98.4%)
- **Ignored:** 40 tests
- **Duration:** 3h28m05s across 30 shards
- **Lines:** 150,329/151,614 matching (99.2%)
- **Avg test duration:** 9.7s — slowest: `away3d_advanced_shallow_water_demo` (93.8s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m51s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 21.3s — slowest: `device_font_kerning` (30.7s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 3h28m34s across 30 shards
- **Lines:** 85,548/85,970 matching (99.5%)
- **Avg test duration:** 7.9s — slowest: `ecma3/Statements/eregress_74474_002` (54.3s)

### from_gnash/actionscript.all

- **Pass:** 141/239 (59.0%)
- **Ignored:** 4 tests
- **Duration:** 22m33s across 30 shards
- **Lines:** 29,577/31,544 matching (93.8%)
- **Avg test duration:** 5.5s — slowest: `MovieClip-v8` (63.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 29m19s across 30 shards
- **Lines:** 4,190/5,206 matching (80.5%)
- **Avg test duration:** 15.9s — slowest: `matrix_test` (107.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m47s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.9s — slowest: `TextFieldTest` (23.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m39s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 17.4s — slowest: `stackscope` (24.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m43s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.1s — slowest: `trace-as2/super` (24.3s)

### from_shumway

- **Pass:** 213/223 (95.5%)
- **Ignored:** 6 tests
- **Duration:** 42m27s across 30 shards
- **Lines:** 2,348/2,409 matching (97.5%)
- **Avg test duration:** 10.7s — slowest: `acid/acid-large` (58.5s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m30s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.2s — slowest: `hitarea` (21.9s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.7s — slowest: `avm1_non_swf_import` (22.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 5.8s — slowest: `avm2_loads_avm1_events` (9.4s)

### regression

- **Pass:** 96/96 (100%)
- **Duration:** 16m48s across 30 shards
- **Lines:** 764/764 matching (100%)
- **Avg test duration:** 10.4s — slowest: `avm2_parent_child_render` (39.8s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.7s — slowest: `scissor_rectangle` (11.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 14s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 1.9s — slowest: `lzma_length_too_long` (2.4s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m39s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 19.9s — slowest: `auto_size/height` (30.3s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 2m39s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 9.3s — slowest: `missing_frame_scripts` (28.4s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 34m15s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.9s — slowest: `definefont4` (112.4s)
