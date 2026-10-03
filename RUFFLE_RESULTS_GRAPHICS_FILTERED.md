# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `4c450f076e82`  
**Date:** 2026-10-03 20:48 UTC  
**Total duration:** 11h00m26s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 701 | 725 | 96.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1220 | 1245 | 98.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
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
| regression | 101 | 101 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4263** | **4527** | **94.2%** | |

*71 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 110,888 | 114,780 | 96.6% |
| avm2 | 151,095 | 152,536 | 99.1% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,548 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,193 | 32,104 | 94.0% |
| from_gnash/misc-ming.all | 4,220 | 5,206 | 81.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,351 | 2,409 | 97.6% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 838 | 838 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **388,544** | **397,692** | **97.7%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 9 | 15 | - |
| avm2 | 8 | 17 | - |
| fonts | 1 | 1 | - |
| from_avmplus | 1 | 41 | 1 |
| from_gnash/actionscript.all | 5 | 94 | - |
| from_gnash/misc-ming.all | 9 | 32 | - |
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
| **Total** | **41** | **222** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | Rectangle-v8 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | html_text_img_parsing_swf6 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 17.3s — slowest: `stream_incomplete_loop` (23.3s)

### avm1

- **Pass:** 701/725 (96.7%)
- **Ignored:** 18 tests
- **Duration:** 53m37s across 30 shards
- **Lines:** 110,888/114,780 matching (96.6%)
- **Avg test duration:** 4.2s — slowest: `define_font_glyph_table_order` (41.6s)

### avm2

- **Pass:** 1220/1245 (98.0%)
- **Ignored:** 39 tests
- **Duration:** 3h40m57s across 30 shards
- **Lines:** 151,095/152,536 matching (99.1%)
- **Avg test duration:** 10.2s — slowest: `away3d_advanced_shallow_water_demo` (107.2s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 3m07s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 23.3s — slowest: `embed_matching/fallback_preferences` (31.5s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 3h34m08s across 30 shards
- **Lines:** 85,548/85,970 matching (99.5%)
- **Avg test duration:** 8.1s — slowest: `ecma3/Statements/eregress_74474_002` (59.8s)

### from_gnash/actionscript.all

- **Pass:** 141/240 (58.8%)
- **Ignored:** 3 tests
- **Duration:** 23m26s across 30 shards
- **Lines:** 30,193/32,104 matching (94.0%)
- **Avg test duration:** 5.8s — slowest: `MovieClip-v8` (68.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 26m25s across 30 shards
- **Lines:** 4,220/5,206 matching (81.1%)
- **Avg test duration:** 14.3s — slowest: `matrix_test` (111.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m01s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.4s — slowest: `implementsOpTest` (24.2s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 4m35s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 14.1s — slowest: `movieclip_destruction_test1` (23.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m49s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.4s — slowest: `zeroframe_definesprite` (23.0s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 45m31s across 30 shards
- **Lines:** 2,351/2,409 matching (97.6%)
- **Avg test duration:** 11.7s — slowest: `acid/acid-large` (81.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m34s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.2s — slowest: `label` (23.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.8s — slowest: `avm1_non_swf_import` (22.2s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 6.2s — slowest: `avm2_loads_avm1_loads_avm2_doabc` (9.3s)

### regression

- **Pass:** 101/101 (100%)
- **Duration:** 16m58s across 30 shards
- **Lines:** 838/838 matching (100%)
- **Avg test duration:** 10.0s — slowest: `avm2_morph` (36.8s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m19s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 11.3s — slowest: `unbound_texture` (12.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 16s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 2.2s — slowest: `swf_length_too_short_no_second_frame` (2.5s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m45s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 20.4s — slowest: `text_caret_placement_leading` (31.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 2m46s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 9.8s — slowest: `frame_script_button_order` (28.9s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 32m37s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.3s — slowest: `simple_shapes/heavy_tesselation` (71.6s)
