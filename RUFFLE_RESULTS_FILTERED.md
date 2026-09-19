# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `53a188c38f4e`  
**Date:** 2026-09-19 12:56 UTC  
**Total duration:** 11h14m58s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 698 | 716 | 97.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1215 | 1235 | 98.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1529 | 1572 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 141 | 239 | 59.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 213 | 223 | 95.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 96 | 96 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
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

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.2s — slowest: `g711_event_mulaw` (20.5s)

### avm1

- **Pass:** 698/716 (97.5%)
- **Ignored:** 19 tests
- **Duration:** 1h08m19s across 30 shards
- **Lines:** 111,156/114,125 matching (97.4%)
- **Avg test duration:** 5.5s — slowest: `define_font_glyph_table_order` (36.7s)

### avm2

- **Pass:** 1215/1235 (98.4%)
- **Ignored:** 40 tests
- **Duration:** 3h42m43s across 30 shards
- **Lines:** 150,329/151,614 matching (99.2%)
- **Avg test duration:** 10.4s — slowest: `away3d_advanced_shallow_water_demo` (89.8s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m38s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 19.7s — slowest: `device_font_kerning` (27.8s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 3h07m43s across 30 shards
- **Lines:** 85,548/85,970 matching (99.5%)
- **Avg test duration:** 7.1s — slowest: `ecma3/Statements/eregress_74474_002` (59.2s)

### from_gnash/actionscript.all

- **Pass:** 141/239 (59.0%)
- **Ignored:** 4 tests
- **Duration:** 29m49s across 30 shards
- **Lines:** 29,577/31,544 matching (93.8%)
- **Avg test duration:** 7.2s — slowest: `MovieClip-v8` (69.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 32m41s across 30 shards
- **Lines:** 4,190/5,206 matching (80.5%)
- **Avg test duration:** 17.6s — slowest: `matrix_test` (84.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.3s — slowest: `function_test` (21.3s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m37s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 17.4s — slowest: `opcode_guard_test2` (24.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m31s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.5s — slowest: `tags_after_last_showframe` (23.6s)

### from_shumway

- **Pass:** 213/223 (95.5%)
- **Ignored:** 6 tests
- **Duration:** 42m58s across 30 shards
- **Lines:** 2,348/2,409 matching (97.5%)
- **Avg test duration:** 10.8s — slowest: `acid/acid-large` (62.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m28s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `rollover` (20.8s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.4s — slowest: `avm1_non_swf_import` (21.9s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m22s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 6.8s — slowest: `avm1_sprite_sc_ignored` (21.9s)

### regression

- **Pass:** 96/96 (100%)
- **Duration:** 25m23s across 30 shards
- **Lines:** 764/764 matching (100%)
- **Avg test duration:** 15.8s — slowest: `avm2_parent_child_render` (50.1s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 59s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.4s — slowest: `scissor_rectangle` (11.0s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 44s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 6.2s — slowest: `lzma_length_too_long` (21.4s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m26s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.7s — slowest: `text_caret_placement_scroll` (29.4s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 5m11s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 18.3s — slowest: `missing_frame_scripts` (29.2s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 32m42s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.3s — slowest: `definefont4` (107.9s)
