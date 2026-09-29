# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `02df69d28006`  
**Date:** 2026-09-29 03:41 UTC  
**Total duration:** 12h45m09s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 705 | 738 | 95.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1222 | 1280 | 95.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 98 | 98 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4266** | **4586** | **93.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 121,124 | 132,376 | 91.5% |
| avm2 | 155,235 | 157,776 | 98.4% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,560 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,558 | 38,791 | 78.8% |
| from_gnash/misc-ming.all | 4,227 | 5,248 | 80.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,396 | 2,484 | 96.5% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 802 | 802 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **403,330** | **427,347** | **94.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 13 | - |
| avm2 | 17 | - |
| fonts | 1 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 7 | - |
| from_gnash/misc-ming.all | 10 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 3 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | - |
| visual | - | - |
| **Total** | **62** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
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
| avm1 | 1 | - | 4 | - |
| avm2 | 1 | - | 119 | - |
| from_gnash/actionscript.all | 2 | - | 47 | - |
| from_gnash/misc-ming.all | 1 | - | 30 | - |

**avm1 — newly passing:** `removed_clip_function_scope`

*Comparing `0341c033aff4` → `02df69d28006`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.3s — slowest: `g711_event_alaw` (21.9s)

### avm1

- **Pass:** 705/738 (95.5%)
- **Duration:** 1h25m08s across 30 shards
- **Lines:** 121,124/132,376 matching (91.5%)
- **Avg test duration:** 6.9s — slowest: `xml_has_child_nodes` (39.8s)

### avm2

- **Pass:** 1222/1280 (95.5%)
- **Duration:** 4h06m26s across 30 shards
- **Lines:** 155,235/157,776 matching (98.4%)
- **Avg test duration:** 11.5s — slowest: `away3d_advanced_shallow_water_demo` (109.7s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m41s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 20.2s — slowest: `device_font_list` (29.3s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h38m28s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 8.3s — slowest: `ecma3/Statements/eregress_74474_003` (60.3s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 33m58s across 30 shards
- **Lines:** 30,558/38,791 matching (78.8%)
- **Avg test duration:** 8.3s — slowest: `MovieClip-v8` (70.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 35m02s across 30 shards
- **Lines:** 4,227/5,248 matching (80.5%)
- **Avg test duration:** 18.9s — slowest: `matrix_test` (110.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.3s — slowest: `exception` (22.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m55s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.7s — slowest: `movieclip_destruction_test3` (24.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m47s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.3s — slowest: `trace-as2/arguments` (23.8s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 48m55s across 30 shards
- **Lines:** 2,396/2,484 matching (96.5%)
- **Avg test duration:** 12.8s — slowest: `esc` (77.6s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 3m12s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 4.0s — slowest: `moviecliploader` (23.1s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 46s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.2s — slowest: `empty_url` (22.6s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 7.1s — slowest: `avm1_sprite_sc_ignored` (16.8s)

### regression

- **Pass:** 98/98 (100%)
- **Duration:** 25m20s across 30 shards
- **Lines:** 802/802 matching (100%)
- **Avg test duration:** 15.5s — slowest: `avm2_timeline_stroke_gradient` (38.2s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 10.0s — slowest: `sampler_odd_size` (12.0s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m06s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.4s — slowest: `swf_length_too_short_no_second_frame` (21.8s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m27s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 18.8s — slowest: `text_caret_placement_leading` (30.6s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m30s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 19.4s — slowest: `swf_9_frame_script_cleanup_goto2` (31.4s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 36m41s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.9s — slowest: `definefont4` (86.0s)
