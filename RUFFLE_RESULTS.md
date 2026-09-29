# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `7755698f8329`  
**Date:** 2026-09-29 02:24 UTC  
**Total duration:** 11h20m43s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 705 | 738 | 95.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1222 | 1280 | 95.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 97 | 97 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4265** | **4585** | **93.0%** | |

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
| regression | 791 | 791 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **403,319** | **427,336** | **94.4%** |

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
| avm1 | 4 | - | 54 | - |
| avm2 | 6 | - | 336 | - |
| from_gnash/actionscript.all | 6 | - | 63 | - |
| from_gnash/misc-ming.all | 1 | - | 30 | - |
| from_shumway | 1 | - | 3 | - |
| text | 1 | - | 1 | - |
| timeline | 1 | - | 10 | - |

**avm1 — newly passing:** `bitmap_data_draw_return_value`, `bitmap_data_draw_string_target`, `hitarea_remove_owner_drag`, `removed_clip_function_scope`

**avm2 — newly passing:** `casi32`, `sound_load_multiple`, `textjustifier_locale`, `textline_has_tabs`

**from_shumway — newly passing:** `as3-loader/LoaderLoadBytesTest`

**text — newly passing:** `links_in_scrolled_text`

**timeline — newly passing:** `missing_frame_scripts`

*Comparing `fa4caf2efd89` → `7755698f8329`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.7s — slowest: `g711_event_alaw` (20.9s)

### avm1

- **Pass:** 705/738 (95.5%)
- **Duration:** 1h11m17s across 30 shards
- **Lines:** 121,124/132,376 matching (91.5%)
- **Avg test duration:** 5.7s — slowest: `define_font_glyph_table_order` (39.7s)

### avm2

- **Pass:** 1222/1280 (95.5%)
- **Duration:** 3h44m18s across 30 shards
- **Lines:** 155,235/157,776 matching (98.4%)
- **Avg test duration:** 10.5s — slowest: `away3d_advanced_shallow_water_demo` (98.2s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m27s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 18.4s — slowest: `device_font_list` (27.9s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h08m39s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 7.1s — slowest: `ecma3/Statements/eregress_74474_003` (63.8s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 30m31s across 30 shards
- **Lines:** 30,558/38,791 matching (78.8%)
- **Avg test duration:** 7.5s — slowest: `MovieClip-v8` (69.8s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 32m49s across 30 shards
- **Lines:** 4,227/5,248 matching (80.5%)
- **Avg test duration:** 17.7s — slowest: `matrix_test` (110.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.7s — slowest: `function_test` (22.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m36s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 16.8s — slowest: `edittext_test1` (23.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m28s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.4s — slowest: `missing_bitmap` (22.5s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 42m41s across 30 shards
- **Lines:** 2,396/2,484 matching (96.5%)
- **Avg test duration:** 11.1s — slowest: `esc` (79.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m36s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.3s — slowest: `rollover` (21.6s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 38s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 12.8s — slowest: `empty_url` (21.7s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 6.7s — slowest: `avm1_sprite_sc_ignored` (20.6s)

### regression

- **Pass:** 97/97 (100%)
- **Duration:** 25m21s across 30 shards
- **Lines:** 791/791 matching (100%)
- **Avg test duration:** 15.6s — slowest: `avm2_slot_default_template` (47.8s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 58s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.2s — slowest: `sampler_odd_size` (10.4s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 53s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 7.5s — slowest: `swf_length_too_short_no_second_frame` (18.6s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 3m18s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 18.0s — slowest: `text_caret_placement_scroll` (28.4s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m10s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 18.2s — slowest: `swf_9_event_goto_frame_script` (28.5s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 32m42s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.3s — slowest: `definefont4` (112.2s)
