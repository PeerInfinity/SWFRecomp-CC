# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9396522982a2`  
**Date:** 2026-10-17 01:43 UTC  
**Total duration:** 13h17m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 707 | 744 | 95.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1233 | 1292 | 95.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 9 | 66.7% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1531 | 1574 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 144 | 243 | 59.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 102 | 102 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4288** | **4609** | **93.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 123,004 | 135,776 | 90.6% |
| avm2 | 156,379 | 158,909 | 98.4% |
| fonts | 195 | 377 | 51.7% |
| from_avmplus | 85,562 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,606 | 38,791 | 78.9% |
| from_gnash/misc-ming.all | 4,236 | 5,248 | 80.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,396 | 2,484 | 96.5% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 859 | 859 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **406,474** | **431,950** | **94.1%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 2 |
| avm1 | 17 |
| avm2 | 17 |
| fonts | 2 |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 11 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 3 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **68** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | edittext_html_duplicate_attributes | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
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
| avm1 | 9 | - | 946 | - |
| avm2 | 6 | - | 337 | - |
| from_avmplus | 2 | - | 2 | - |
| from_gnash/actionscript.all | 3 | - | 21 | - |
| from_gnash/misc-ming.all | 1 | - | 19 | 10 |
| mixed_avm | 1 | - | 3 | - |

**avm1 — newly passing:** `as_broadcaster`, `as_setup_error`, `context_menu`, `context_menu_item`, `context_menu_swf6`, `html_text_img_numeric_attributes`, `html_text_img_parsing_swf5`, `html_text_img_parsing_swf7`, `html_text_img_parsing_swf8`

**avm2 — newly passing:** `external_interface`, `mouse_pick_loader_avm1`, `mouse_pick_scroll_rect`, `mouse_pick_scroll_rect_button`, `mouse_pick_scroll_rect_loader`

**from_avmplus — newly passing:** `recursion/pcre_find_fixedlength`, `regress/bug_483783`

**from_gnash/actionscript.all — newly passing:** `AsBroadcaster-v6`, `AsBroadcaster-v7`, `AsBroadcaster-v8`

*Comparing `bdf127c35cca` → `9396522982a2`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 17.3s — slowest: `stream_incomplete_loop` (24.1s)

### avm1

- **Pass:** 707/744 (95.0%)
- **Duration:** 1h26m45s across 30 shards
- **Lines:** 123,004/135,776 matching (90.6%)
- **Avg test duration:** 6.9s — slowest: `movieclip_invalid_get_bounds_7` (56.7s)

### avm2

- **Pass:** 1233/1292 (95.4%)
- **Duration:** 4h24m12s across 30 shards
- **Lines:** 156,379/158,909 matching (98.4%)
- **Avg test duration:** 12.2s — slowest: `away3d_advanced_shallow_water_demo` (109.3s)

### fonts

- **Pass:** 6/9 (66.7%)
- **Duration:** 2m57s across 30 shards
- **Lines:** 195/377 matching (51.7%)
- **Avg test duration:** 19.6s — slowest: `device_font_kerning` (33.7s)

### from_avmplus

- **Pass:** 1531/1574 (97.3%)
- **Duration:** 3h42m05s across 30 shards
- **Lines:** 85,562/85,996 matching (99.5%)
- **Avg test duration:** 8.4s — slowest: `ecma3/Statements/eregress_74474_002` (63.4s)

### from_gnash/actionscript.all

- **Pass:** 144/243 (59.3%)
- **Duration:** 34m11s across 30 shards
- **Lines:** 30,606/38,791 matching (78.9%)
- **Avg test duration:** 8.4s — slowest: `MovieClip-v8` (69.1s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 35m55s across 30 shards
- **Lines:** 4,236/5,248 matching (80.7%)
- **Avg test duration:** 19.4s — slowest: `matrix_test` (99.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m58s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.1s — slowest: `inheritance` (23.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m46s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 17.3s — slowest: `movieclip_destruction_test2` (24.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m51s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.5s — slowest: `background` (24.0s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 50m43s across 30 shards
- **Lines:** 2,396/2,484 matching (96.5%)
- **Avg test duration:** 13.2s — slowest: `acid/acid-large` (82.4s)

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
