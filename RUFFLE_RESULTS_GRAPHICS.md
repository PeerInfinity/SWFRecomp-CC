# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `bdf127c35cca`  
**Date:** 2026-10-17 00:59 UTC  
**Total duration:** 12h17m18s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 698 | 744 | 93.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1228 | 1291 | 95.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 9 | 66.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
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
| regression | 101 | 101 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4268** | **4607** | **92.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 122,058 | 135,776 | 89.9% |
| avm2 | 156,013 | 158,864 | 98.2% |
| fonts | 195 | 377 | 51.7% |
| from_avmplus | 85,560 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,585 | 38,791 | 78.8% |
| from_gnash/misc-ming.all | 4,227 | 5,248 | 80.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,396 | 2,484 | 96.5% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 838 | 838 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **405,106** | **431,884** | **93.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 26 | - |
| avm2 | 22 | - |
| fonts | 2 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 14 | - |
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
| **Total** | **88** | **1** |

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
| from_gnash/actionscript.all | AsBroadcaster-v6 | 94% |
| from_gnash/actionscript.all | AsBroadcaster-v7 | 94% |
| from_gnash/actionscript.all | AsBroadcaster-v8 | 94% |
| from_gnash/actionscript.all | Rectangle-v8 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| from_gnash/actionscript.all | Matrix-v7 | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | Matrix-v6 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | 4 | 19 | 1327 |
| avm2 | 3 | - | 105 | 205 |
| from_gnash/actionscript.all | - | 6 | 27 | - |

**avm1 — newly passing:** `html_text_img_parsing_swf6`

**avm1 — newly failing:** `as_broadcaster`, `context_menu`, `context_menu_item`, `matrix`

**avm2 — newly passing:** `goto_queued_invalid/swf10`, `goto_queued_invalid/swf11`, `goto_queued_invalid/swf9`

*Comparing `4c450f076e82` → `bdf127c35cca`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m27s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 17.4s — slowest: `stream_incomplete_loop` (22.8s)

### avm1

- **Pass:** 698/744 (93.8%)
- **Duration:** 1h19m20s across 30 shards
- **Lines:** 122,058/135,776 matching (89.9%)
- **Avg test duration:** 6.3s — slowest: `netstream_play_flv_screen` (43.4s)

### avm2

- **Pass:** 1228/1291 (95.1%)
- **Duration:** 3h57m06s across 30 shards
- **Lines:** 156,013/158,864 matching (98.2%)
- **Avg test duration:** 11.0s — slowest: `away3d_advanced_shallow_water_demo` (113.0s)

### fonts

- **Pass:** 6/9 (66.7%)
- **Duration:** 3m05s across 30 shards
- **Lines:** 195/377 matching (51.7%)
- **Avg test duration:** 20.6s — slowest: `embed_matching/fallback_preferences` (30.8s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h36m31s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 8.2s — slowest: `ecma3/Statements/eregress_74474_002` (58.7s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 30m45s across 30 shards
- **Lines:** 30,585/38,791 matching (78.8%)
- **Avg test duration:** 7.5s — slowest: `MovieClip-v8` (66.5s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 30m52s across 30 shards
- **Lines:** 4,227/5,248 matching (80.5%)
- **Avg test duration:** 16.6s — slowest: `matrix_test` (112.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m03s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.6s — slowest: `exception` (23.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m50s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.5s — slowest: `action_execution_order_test10` (23.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m39s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 16.9s — slowest: `missing_bitmap` (23.2s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 48m10s across 30 shards
- **Lines:** 2,396/2,484 matching (96.5%)
- **Avg test duration:** 12.6s — slowest: `acid/acid-large` (80.5s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m12s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (22.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 50s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.5s — slowest: `empty_url` (22.2s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m37s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 8.0s — slowest: `avm1_sprite_sc_ignored` (22.3s)

### regression

- **Pass:** 101/101 (100%)
- **Duration:** 24m23s across 30 shards
- **Lines:** 838/838 matching (100%)
- **Avg test duration:** 14.4s — slowest: `avm2_parent_child_symbolclass_domain` (34.5s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 11.4s — slowest: `scissor_rectangle_invalid` (12.3s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 10.7s — slowest: `convolution_filter_big_matrix` (23.1s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m53s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 21.2s — slowest: `auto_size/height` (34.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m58s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.0s — slowest: `frame_script_cleanup` (30.1s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 34m55s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.2s — slowest: `definefont4` (113.9s)
