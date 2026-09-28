# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `1b7a987cf4d9`  
**Date:** 2026-09-28 21:10 UTC  
**Total duration:** 12h12m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 699 | 720 | 97.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1216 | 1240 | 98.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1529 | 1572 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 141 | 240 | 58.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
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
| **Total** | **4249** | **4512** | **94.2%** | |

*72 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 111,178 | 114,193 | 97.4% |
| avm2 | 150,531 | 152,233 | 98.9% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,548 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,146 | 32,104 | 93.9% |
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
| **Total** | **388,105** | **396,728** | **97.8%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 6 | 15 | - |
| avm2 | 9 | 15 | - |
| fonts | 1 | 1 | - |
| from_avmplus | 1 | 41 | 1 |
| from_gnash/actionscript.all | 6 | 93 | - |
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
| **Total** | **44** | **218** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | textline_has_tabs | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 15.7s — slowest: `stream_incomplete_loop` (23.6s)

### avm1

- **Pass:** 699/720 (97.1%)
- **Ignored:** 18 tests
- **Duration:** 1h19m11s across 30 shards
- **Lines:** 111,178/114,193 matching (97.4%)
- **Avg test duration:** 6.4s — slowest: `define_function_case_sensitive` (36.9s)

### avm2

- **Pass:** 1216/1240 (98.1%)
- **Ignored:** 40 tests
- **Duration:** 3h56m42s across 30 shards
- **Lines:** 150,531/152,233 matching (98.9%)
- **Avg test duration:** 11.0s — slowest: `away3d_advanced_shallow_water_demo` (92.4s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m49s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 21.2s — slowest: `embed_matching/fallback_preferences` (31.8s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 3h29m35s across 30 shards
- **Lines:** 85,548/85,970 matching (99.5%)
- **Avg test duration:** 7.9s — slowest: `ecma3/Statements/eregress_74474_002` (60.3s)

### from_gnash/actionscript.all

- **Pass:** 141/240 (58.8%)
- **Ignored:** 3 tests
- **Duration:** 31m32s across 30 shards
- **Lines:** 30,146/32,104 matching (93.9%)
- **Avg test duration:** 7.8s — slowest: `MovieClip-v8` (51.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 33m19s across 30 shards
- **Lines:** 4,190/5,206 matching (80.5%)
- **Avg test duration:** 17.9s — slowest: `matrix_test` (73.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m02s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.5s — slowest: `implementsOpTest` (25.5s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m47s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 17.9s — slowest: `swf4opcode` (25.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m41s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.0s — slowest: `dict_override` (23.8s)

### from_shumway

- **Pass:** 213/223 (95.5%)
- **Ignored:** 6 tests
- **Duration:** 47m35s across 30 shards
- **Lines:** 2,348/2,409 matching (97.5%)
- **Avg test duration:** 12.0s — slowest: `acid/acid-large` (79.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m51s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.6s — slowest: `rollover` (21.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 37s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 12.3s — slowest: `empty_url` (17.8s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 7.8s — slowest: `avm1_sprite_sc_ignored` (23.5s)

### regression

- **Pass:** 96/96 (100%)
- **Duration:** 24m14s across 30 shards
- **Lines:** 764/764 matching (100%)
- **Avg test duration:** 15.1s — slowest: `avm2_parent_child_render` (37.2s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 11.0s — slowest: `unbound_texture` (12.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m09s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.8s — slowest: `swf_length_too_short_no_second_frame` (24.4s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m25s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.6s — slowest: `auto_size/height` (29.5s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 5m32s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 19.5s — slowest: `frame_script_cleanup3` (32.4s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 34m54s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.2s — slowest: `definefont4` (89.8s)
