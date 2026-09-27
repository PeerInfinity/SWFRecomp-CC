# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `fa4caf2efd89`  
**Date:** 2026-09-27 08:50 UTC  
**Total duration:** 11h18m53s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 701 | 738 | 95.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1218 | 1279 | 95.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 213 | 229 | 93.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 96 | 96 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4253** | **4583** | **92.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 121,070 | 132,376 | 91.5% |
| avm2 | 154,699 | 157,564 | 98.2% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,560 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,495 | 38,791 | 78.6% |
| from_gnash/misc-ming.all | 4,197 | 5,248 | 80.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,393 | 2,484 | 96.3% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 764 | 764 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **402,595** | **427,097** | **94.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 17 | - |
| avm2 | 23 | - |
| fonts | 1 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 11 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 4 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 1 | - |
| visual | - | - |
| **Total** | **82** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | array-v7 | 97% |
| from_gnash/actionscript.all | array-v8 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | textline_has_tabs | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 1 | - |

**avm1 — newly passing:** `geturl`

*Comparing `53a188c38f4e` → `fa4caf2efd89`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.6s — slowest: `stream_incomplete_loop` (21.1s)

### avm1

- **Pass:** 701/738 (95.0%)
- **Duration:** 1h09m48s across 30 shards
- **Lines:** 121,070/132,376 matching (91.5%)
- **Avg test duration:** 5.6s — slowest: `netstream_play_flv_screen` (37.5s)

### avm2

- **Pass:** 1218/1279 (95.2%)
- **Duration:** 3h36m31s across 30 shards
- **Lines:** 154,699/157,564 matching (98.2%)
- **Avg test duration:** 10.1s — slowest: `away3d_advanced_shallow_water_demo` (70.6s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m49s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 21.1s — slowest: `embed_matching/fallback_preferences` (28.1s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h10m06s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 7.2s — slowest: `ecma3/Statements/eregress_74474_002` (57.7s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 30m59s across 30 shards
- **Lines:** 30,495/38,791 matching (78.6%)
- **Avg test duration:** 7.6s — slowest: `MovieClip-v8` (68.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 33m57s across 30 shards
- **Lines:** 4,197/5,248 matching (80.0%)
- **Avg test duration:** 18.3s — slowest: `matrix_test` (106.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m53s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.5s — slowest: `implementsOpTest` (23.4s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m47s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.3s — slowest: `swf4opcode` (24.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m44s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.2s — slowest: `dict_override` (22.3s)

### from_shumway

- **Pass:** 213/229 (93.0%)
- **Duration:** 45m54s across 30 shards
- **Lines:** 2,393/2,484 matching (96.3%)
- **Avg test duration:** 12.0s — slowest: `esc` (76.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m30s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `text-bind` (22.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.4s — slowest: `avm1_non_swf_import` (22.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 7.0s — slowest: `avm1_sprite_sc_ignored` (20.7s)

### regression

- **Pass:** 96/96 (100%)
- **Duration:** 23m43s across 30 shards
- **Lines:** 764/764 matching (100%)
- **Avg test duration:** 14.8s — slowest: `avm2_parent_child_render` (30.9s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m06s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.4s — slowest: `unbound_texture` (11.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 10.0s — slowest: `swf_length_too_short_no_second_frame` (21.9s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m26s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.7s — slowest: `text_caret_placement_align` (28.9s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 5m09s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 18.1s — slowest: `frame_script_cleanup3` (29.6s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 33m57s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.8s — slowest: `definefont4` (110.8s)
