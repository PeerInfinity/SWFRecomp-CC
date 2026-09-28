# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `0341c033aff4`  
**Date:** 2026-09-28 23:17 UTC  
**Total duration:** 12h50m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 704 | 738 | 95.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
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
| regression | 97 | 97 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4264** | **4585** | **93.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 121,120 | 132,376 | 91.5% |
| avm2 | 155,116 | 157,776 | 98.3% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,560 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,511 | 38,791 | 78.7% |
| from_gnash/misc-ming.all | 4,197 | 5,248 | 80.0% |
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
| **Total** | **403,119** | **427,336** | **94.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 14 | - |
| avm2 | 18 | - |
| fonts | 1 | - |
| from_avmplus | 3 | 1 |
| from_gnash/actionscript.all | 9 | - |
| from_gnash/misc-ming.all | 11 | - |
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
| **Total** | **67** | **1** |

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
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
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
| avm1 | 3 | - | 50 | - |
| avm2 | 6 | - | 336 | - |
| from_shumway | 1 | - | 3 | - |
| text | 1 | - | 1 | - |
| timeline | 1 | - | 10 | - |

**avm1 — newly passing:** `bitmap_data_draw_return_value`, `bitmap_data_draw_string_target`, `hitarea_remove_owner_drag`

**avm2 — newly passing:** `casi32`, `sound_load_multiple`, `textjustifier_locale`, `textline_has_tabs`

**from_shumway — newly passing:** `as3-loader/LoaderLoadBytesTest`

**text — newly passing:** `links_in_scrolled_text`

**timeline — newly passing:** `missing_frame_scripts`

*Comparing `1b7a987cf4d9` → `0341c033aff4`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.1s — slowest: `g711_event_alaw` (22.1s)

### avm1

- **Pass:** 704/738 (95.4%)
- **Duration:** 1h23m49s across 30 shards
- **Lines:** 121,120/132,376 matching (91.5%)
- **Avg test duration:** 6.8s — slowest: `define_font_glyph_table_order` (42.2s)

### avm2

- **Pass:** 1222/1280 (95.5%)
- **Duration:** 4h11m38s across 30 shards
- **Lines:** 155,116/157,776 matching (98.3%)
- **Avg test duration:** 11.7s — slowest: `away3d_advanced_shallow_water_demo` (111.0s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m44s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 20.6s — slowest: `device_font_kerning` (32.8s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h39m26s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 8.3s — slowest: `ecma3/Statements/eregress_74474_002` (58.5s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 34m16s across 30 shards
- **Lines:** 30,511/38,791 matching (78.7%)
- **Avg test duration:** 8.4s — slowest: `MovieClip-v8` (73.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 34m49s across 30 shards
- **Lines:** 4,197/5,248 matching (80.0%)
- **Avg test duration:** 18.8s — slowest: `matrix_test` (79.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m41s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.2s — slowest: `exception` (22.7s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m54s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.7s — slowest: `movieclip_destruction_test3` (25.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m50s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.5s — slowest: `trace-as2/root_onload` (24.3s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 48m17s across 30 shards
- **Lines:** 2,396/2,484 matching (96.5%)
- **Avg test duration:** 12.6s — slowest: `esc` (78.4s)

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
