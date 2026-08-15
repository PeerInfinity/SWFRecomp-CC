# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `86434112a759`  
**Date:** 2026-08-15 09:18 UTC  
**Total duration:** 12h57m43s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 679 | 704 | 96.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1149 | 1190 | 96.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1515 | 1572 | 96.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 135 | 239 | 56.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 194 | 207 | 93.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 142 | 144 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4091** | **4394** | **93.1%** | |

*106 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 109,698 | 113,120 | 97.0% |
| avm2 | 133,577 | 135,884 | 98.3% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,406 | 85,970 | 99.3% |
| from_gnash/actionscript.all | 29,444 | 31,544 | 93.3% |
| from_gnash/misc-ming.all | 4,047 | 5,206 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,507 | 1,770 | 85.1% |
| from_shumway/avm1 | 487 | 487 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 49 | 53 | 92.5% |
| regression | 483 | 483 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **367,411** | **377,499** | **97.3%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 12 | 13 | - |
| avm2 | 33 | 8 | - |
| fonts | - | - | - |
| from_avmplus | 3 | 53 | 1 |
| from_gnash/actionscript.all | 12 | 92 | - |
| from_gnash/misc-ming.all | 12 | 29 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 4 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 6 | 7 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 1 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 1 | - |
| text | 1 | - | - |
| timeline | 2 | 3 | - |
| visual | - | 2 | - |
| **Total** | **87** | **215** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | button_nested_frame_simple | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| from_gnash/actionscript.all | Sound-v6 | 93% |
| from_gnash/actionscript.all | Sound-v7 | 93% |
| from_gnash/actionscript.all | Sound-v8 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm1 | sound_load_props | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | matrix3d_raw_data | 85% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix3d_determinant | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.9s — slowest: `g711_event_mulaw` (23.1s)

### avm1

- **Pass:** 679/704 (96.4%)
- **Ignored:** 21 tests
- **Duration:** 1h36m25s across 30 shards
- **Lines:** 109,698/113,120 matching (97.0%)
- **Avg test duration:** 7.9s — slowest: `define_font_glyph_table_order` (44.6s)

### avm2

- **Pass:** 1149/1190 (96.6%)
- **Ignored:** 53 tests
- **Duration:** 4h10m47s across 30 shards
- **Lines:** 133,577/135,884 matching (98.3%)
- **Avg test duration:** 12.0s — slowest: `away3d_advanced_shallow_water_demo` (96.5s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 22.5s — slowest: `embed_matching/fallback_preferences` (32.3s)

### from_avmplus

- **Pass:** 1515/1572 (96.4%)
- **Ignored:** 2 tests
- **Duration:** 3h27m13s across 30 shards
- **Lines:** 85,406/85,970 matching (99.3%)
- **Avg test duration:** 7.8s — slowest: `ecma3/Statements/eregress_74474_003` (65.7s)

### from_gnash/actionscript.all

- **Pass:** 135/239 (56.5%)
- **Ignored:** 4 tests
- **Duration:** 39m57s across 30 shards
- **Lines:** 29,444/31,544 matching (93.3%)
- **Avg test duration:** 9.6s — slowest: `MovieClip-v8` (67.7s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 37m10s across 30 shards
- **Lines:** 4,047/5,206 matching (77.7%)
- **Avg test duration:** 20.0s — slowest: `matrix_test` (111.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m12s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.4s — slowest: `function_test` (24.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 6m31s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 20.4s — slowest: `stackscope` (29.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 7m03s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 21.1s — slowest: `trace-as2/super` (24.6s)

### from_shumway

- **Pass:** 194/207 (93.7%)
- **Ignored:** 22 tests
- **Duration:** 50m37s across 30 shards
- **Lines:** 1,507/1,770 matching (85.1%)
- **Avg test duration:** 12.3s — slowest: `acid/acid-large` (80.2s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m49s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 3.3s — slowest: `text-bind` (22.5s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 49s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.2s — slowest: `avm1_non_swf_import` (23.4s)

### mixed_avm

- **Pass:** 10/11 (90.9%)
- **Duration:** 1m23s across 30 shards
- **Lines:** 49/53 matching (92.5%)
- **Avg test duration:** 7.6s — slowest: `avm1_sprite_sc_ignored` (23.3s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 22m27s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 18.7s — slowest: `avm2_bitmapdata_draw_textfield` (49.1s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 50s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.9s — slowest: `scissor_rectangle` (11.7s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 52s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 10.4s — slowest: `swf_length_too_short_no_second_frame` (23.7s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m44s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.4s — slowest: `auto_size/return` (32.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m50s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 24.1s — slowest: `frame_script_cleanup` (30.7s)

### visual

- **Pass:** 142/144 (98.6%)
- **Duration:** 35m18s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.7s — slowest: `definefont4` (91.0s)
