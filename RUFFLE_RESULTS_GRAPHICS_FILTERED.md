# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `0341c033aff4`  
**Date:** 2026-09-28 23:17 UTC  
**Total duration:** 12h50m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 702 | 720 | 97.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1220 | 1241 | 98.3% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1529 | 1572 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 141 | 240 | 58.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 97 | 97 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4260** | **4514** | **94.4%** | |

*71 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 111,228 | 114,193 | 97.4% |
| avm2 | 150,852 | 152,252 | 99.1% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,548 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,146 | 32,104 | 93.9% |
| from_gnash/misc-ming.all | 4,190 | 5,206 | 80.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,351 | 2,409 | 97.6% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 791 | 791 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **388,517** | **396,774** | **97.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 3 | 15 | - |
| avm2 | 5 | 16 | - |
| fonts | 1 | 1 | - |
| from_avmplus | 1 | 41 | 1 |
| from_gnash/actionscript.all | 6 | 93 | - |
| from_gnash/misc-ming.all | 10 | 31 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 2 | 7 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 2 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 2 | - |
| text | - | - | - |
| timeline | - | 3 | - |
| visual | - | 2 | - |
| **Total** | **34** | **219** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
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
- **Duration:** 1m10s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.1s — slowest: `g711_event_alaw` (22.1s)

### avm1

- **Pass:** 702/720 (97.5%)
- **Ignored:** 18 tests
- **Duration:** 1h23m49s across 30 shards
- **Lines:** 111,228/114,193 matching (97.4%)
- **Avg test duration:** 6.8s — slowest: `define_font_glyph_table_order` (42.2s)

### avm2

- **Pass:** 1220/1241 (98.3%)
- **Ignored:** 39 tests
- **Duration:** 4h11m38s across 30 shards
- **Lines:** 150,852/152,252 matching (99.1%)
- **Avg test duration:** 11.7s — slowest: `away3d_advanced_shallow_water_demo` (111.0s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m44s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 20.6s — slowest: `device_font_kerning` (32.8s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 3h39m26s across 30 shards
- **Lines:** 85,548/85,970 matching (99.5%)
- **Avg test duration:** 8.3s — slowest: `ecma3/Statements/eregress_74474_002` (58.5s)

### from_gnash/actionscript.all

- **Pass:** 141/240 (58.8%)
- **Ignored:** 3 tests
- **Duration:** 34m16s across 30 shards
- **Lines:** 30,146/32,104 matching (93.9%)
- **Avg test duration:** 8.5s — slowest: `MovieClip-v8` (73.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 34m49s across 30 shards
- **Lines:** 4,190/5,206 matching (80.5%)
- **Avg test duration:** 18.8s — slowest: `matrix_test` (79.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m41s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.2s — slowest: `exception` (22.7s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m54s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 18.2s — slowest: `movieclip_destruction_test3` (25.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m50s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.5s — slowest: `trace-as2/root_onload` (24.3s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 48m17s across 30 shards
- **Lines:** 2,351/2,409 matching (97.6%)
- **Avg test duration:** 12.2s — slowest: `acid/acid-large` (65.9s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 3m03s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.9s — slowest: `moviecliploader` (23.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 51s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.8s — slowest: `avm1_non_swf_import` (24.3s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 7.0s — slowest: `avm1_sprite_sc_ignored` (14.1s)

### regression

- **Pass:** 97/97 (100%)
- **Duration:** 27m07s across 30 shards
- **Lines:** 791/791 matching (100%)
- **Avg test duration:** 16.7s — slowest: `avm2_timeline_stroke_gradient` (51.2s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.6s — slowest: `sampler_odd_size` (12.2s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m04s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.1s — slowest: `lzma_length_too_long` (23.4s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m36s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 19.6s — slowest: `auto_size/return` (33.2s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m18s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 18.7s — slowest: `swf_9_event_goto_frame_script` (30.3s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 36m10s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.7s — slowest: `definefont4` (109.5s)
