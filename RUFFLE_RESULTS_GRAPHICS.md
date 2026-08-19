# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9d038c750eaf`  
**Date:** 2026-08-19 14:26 UTC  
**Total duration:** 13h24m26s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 689 | 725 | 95.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1179 | 1251 | 94.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 6 | 100% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1527 | 1574 | 97.0% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 138 | 243 | 56.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 212 | 229 | 92.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 72 | 72 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 142 | 144 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4165** | **4510** | **92.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 119,938 | 131,334 | 91.3% |
| avm2 | 151,316 | 154,806 | 97.7% |
| fonts | 104 | 104 | 100% |
| from_avmplus | 85,434 | 85,996 | 99.3% |
| from_gnash/actionscript.all | 30,386 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,057 | 5,248 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,323 | 2,484 | 93.5% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 49 | 53 | 92.5% |
| regression | 483 | 483 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 333 | 371 | 89.8% |
| visual | 301 | 350 | 86.0% |
| **Total** | **397,232** | **422,730** | **94.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 18 | - |
| avm2 | 39 | - |
| fonts | - | - |
| from_avmplus | 5 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 5 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 2 | - |
| visual | - | - |
| **Total** | **104** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| avm2 | vector3d_near_equals | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

*No changes since last run.*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 17.2s — slowest: `g711_event_mulaw` (22.4s)

### avm1

- **Pass:** 689/725 (95.0%)
- **Duration:** 1h36m19s across 30 shards
- **Lines:** 119,938/131,334 matching (91.3%)
- **Avg test duration:** 7.9s — slowest: `define_font_glyph_table_order` (44.6s)

### avm2

- **Pass:** 1179/1251 (94.2%)
- **Duration:** 4h22m24s across 30 shards
- **Lines:** 151,316/154,806 matching (97.7%)
- **Avg test duration:** 12.5s — slowest: `away3d_advanced_shallow_water_demo` (96.7s)

### fonts

- **Pass:** 6/6 (100%)
- **Duration:** 2m17s across 30 shards
- **Lines:** 104/104 matching (100%)
- **Avg test duration:** 22.8s — slowest: `embed_matching/fallback_preferences` (31.5s)

### from_avmplus

- **Pass:** 1527/1574 (97.0%)
- **Duration:** 3h39m04s across 30 shards
- **Lines:** 85,434/85,996 matching (99.3%)
- **Avg test duration:** 8.3s — slowest: `ecma3/Statements/eregress_74474_003` (58.7s)

### from_gnash/actionscript.all

- **Pass:** 138/243 (56.8%)
- **Duration:** 39m57s across 30 shards
- **Lines:** 30,386/38,791 matching (78.3%)
- **Avg test duration:** 9.8s — slowest: `MovieClip-v8` (65.2s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 36m37s across 30 shards
- **Lines:** 4,057/5,248 matching (77.3%)
- **Avg test duration:** 19.7s — slowest: `matrix_test` (111.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m18s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.9s — slowest: `levels` (23.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 6m22s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 19.1s — slowest: `edittext_test1` (24.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 7m06s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 21.3s — slowest: `trace-as2/super` (23.2s)

### from_shumway

- **Pass:** 212/229 (92.6%)
- **Duration:** 52m35s across 30 shards
- **Lines:** 2,323/2,484 matching (93.5%)
- **Avg test duration:** 13.7s — slowest: `acid/acid-large` (81.8s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m53s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.6s — slowest: `text-bind` (21.9s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 49s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 16.4s — slowest: `avm1_non_swf_import` (23.6s)

### mixed_avm

- **Pass:** 10/11 (90.9%)
- **Duration:** 1m27s across 30 shards
- **Lines:** 49/53 matching (92.5%)
- **Avg test duration:** 7.9s — slowest: `avm1_sprite_sc_ignored` (22.5s)

### regression

- **Pass:** 72/72 (100%)
- **Duration:** 22m44s across 30 shards
- **Lines:** 483/483 matching (100%)
- **Avg test duration:** 18.9s — slowest: `avm2_graphics_runtime` (48.6s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 52s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 10.4s — slowest: `scissor_rectangle` (11.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 10.8s — slowest: `lzma_length_too_long` (22.8s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m53s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 21.2s — slowest: `auto_size/return` (33.0s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m38s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 23.4s — slowest: `swf_9_frame_script_cleanup_goto` (30.9s)

### visual

- **Pass:** 142/144 (98.6%)
- **Duration:** 36m21s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 15.1s — slowest: `definefont4` (93.5s)
