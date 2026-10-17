# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `9396522982a2`  
**Date:** 2026-10-17 01:43 UTC  
**Total duration:** 13h17m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 705 | 726 | 97.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1232 | 1254 | 98.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 9 | 66.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1531 | 1572 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 144 | 240 | 60.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
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
| **Total** | **4285** | **4539** | **94.4%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 113,112 | 117,593 | 96.2% |
| avm2 | 152,145 | 153,415 | 99.2% |
| fonts | 195 | 377 | 51.7% |
| from_avmplus | 85,550 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,241 | 32,104 | 94.2% |
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
| **Total** | **391,902** | **401,418** | **97.6%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 2 | - |
| avm1 | 6 | 15 |
| avm2 | 4 | 18 |
| fonts | 2 | 1 |
| from_avmplus | - | 41 |
| from_gnash/actionscript.all | 8 | 88 |
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
| **Total** | **35** | **219** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | edittext_html_duplicate_attributes | 98% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_gnash/actionscript.all | Rectangle-v8 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/actionscript.all | Matrix-v7 | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | Matrix-v6 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 17.3s — slowest: `stream_incomplete_loop` (24.1s)

### avm1

- **Pass:** 705/726 (97.1%)
- **Ignored:** 18 tests
- **Duration:** 1h26m45s across 30 shards
- **Lines:** 113,112/117,593 matching (96.2%)
- **Avg test duration:** 7.0s — slowest: `movieclip_invalid_get_bounds_7` (56.7s)

### avm2

- **Pass:** 1232/1254 (98.2%)
- **Ignored:** 38 tests
- **Duration:** 4h24m12s across 30 shards
- **Lines:** 152,145/153,415 matching (99.2%)
- **Avg test duration:** 12.2s — slowest: `away3d_advanced_shallow_water_demo` (109.3s)

### fonts

- **Pass:** 6/9 (66.7%)
- **Duration:** 2m57s across 30 shards
- **Lines:** 195/377 matching (51.7%)
- **Avg test duration:** 19.6s — slowest: `device_font_kerning` (33.7s)

### from_avmplus

- **Pass:** 1531/1572 (97.4%)
- **Ignored:** 2 tests
- **Duration:** 3h42m05s across 30 shards
- **Lines:** 85,550/85,970 matching (99.5%)
- **Avg test duration:** 8.4s — slowest: `ecma3/Statements/eregress_74474_002` (63.4s)

### from_gnash/actionscript.all

- **Pass:** 144/240 (60.0%)
- **Ignored:** 3 tests
- **Duration:** 34m11s across 30 shards
- **Lines:** 30,241/32,104 matching (94.2%)
- **Avg test duration:** 8.4s — slowest: `MovieClip-v8` (69.1s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 35m55s across 30 shards
- **Lines:** 4,229/5,206 matching (81.2%)
- **Avg test duration:** 19.4s — slowest: `matrix_test` (99.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.1s — slowest: `inheritance` (23.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m46s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 17.8s — slowest: `movieclip_destruction_test2` (24.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m51s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.5s — slowest: `background` (24.0s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 50m43s across 30 shards
- **Lines:** 2,351/2,409 matching (97.6%)
- **Avg test duration:** 12.9s — slowest: `acid/acid-large` (82.4s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.9s — slowest: `hitarea` (21.8s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 52s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 17.2s — slowest: `avm1_non_swf_import` (24.6s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m38s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 8.2s — slowest: `avm1_sprite_sc_ignored` (23.4s)

### regression

- **Pass:** 102/102 (100%)
- **Duration:** 29m40s across 30 shards
- **Lines:** 859/859 matching (100%)
- **Avg test duration:** 17.4s — slowest: `avm2_slot_default_template` (56.0s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 11.4s — slowest: `scissor_rectangle_invalid` (12.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m09s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.9s — slowest: `lzma_length_too_long` (23.7s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m43s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 20.3s — slowest: `auto_size/return` (34.6s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m04s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.4s — slowest: `swf_9_frame_script_dynamic_goto` (31.1s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 37m52s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 15.4s — slowest: `definefont4` (112.7s)
