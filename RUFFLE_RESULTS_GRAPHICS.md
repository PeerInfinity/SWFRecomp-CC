# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `10a5b515a03a`  
**Date:** 2026-11-25 21:42 UTC  
**Total duration:** 12h45m25s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 767 | 789 | 97.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1299 | 1346 | 96.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1544 | 1574 | 98.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 167 | 243 | 68.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 71 | 111 | 64.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 15 | 21 | 71.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 262 | 262 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4629** | **4875** | **95.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,613 | 137,759 | 91.2% |
| avm2 | 162,225 | 164,338 | 98.7% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,594 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,990 | 38,791 | 79.9% |
| from_gnash/misc-ming.all | 4,318 | 5,248 | 82.3% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 529 | 603 | 87.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,102 | 2,102 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **416,991** | **440,642** | **94.6%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 13 |
| avm2 | 9 |
| fonts | - |
| from_avmplus | 3 |
| from_gnash/actionscript.all | 8 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 1 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 1 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **45** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | globals_swf5 | 97% |
| from_avmplus | ecma3/JSON/AS3Types | 96% |
| avm1 | boxed_primitives | 96% |
| avm2 | number_tostring | 84% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | 296 | 1 |
| avm2 | - | - | 192 | - |
| from_avmplus | - | 1 | 27 | 1 |
| from_gnash/actionscript.all | - | 5 | 112 | - |
| from_gnash/misc-swfc.all | 1 | - | 3 | - |
| swf | - | - | 16 | - |

**avm1 — newly passing:** `asnative_sweep`, `bitmap_data_thorough/copyPixels`, `bitmap_data_thorough/paletteMap`, `bitmap_data_thorough/perlinNoise`, `bitmapdata_custom_rectangle`, `form_loader_encoding_4`, `mcl_replace_root_swf7_to_swf5`, `mcl_replace_root_swf7_to_swf6`, `textfield_props_swf5`, `virtual_property_recursion_swf6`, `watch_recursion_double_swf6`, `watch_recursion_swf6`

**avm1 — newly failing:** `boxed_primitives`

**avm2 — newly passing:** `array_access_oob_interpreter`, `edittext_getcharboundaries_missing_embedded_font`, `encode_uri_surrogate_pair_swf10`, `graphics_draw_path`, `groupelement_text`, `vector_indexing_cutoffs`

**from_avmplus — newly passing:** `as3/RegExp/replace`, `as3/RuntimeErrors/Error1095XmlUnterminatedAttr`, `e4x/XML/bug_564468`, `e4x/XML/e13_4_4_30`, `e4x/XML/misc_errors`, `e4x/XMLList/e13_5_4_18`, `ecma3/Date/e15_9_4_2_1`, `ecma3/JSON/Classes`, `ecma3/JSON/adhoc`, `misc/bug_508617`, `regress/bug_609416_swf10`, `regress/bug_638233`

**from_avmplus — newly failing:** `ecma3/JSON/AS3Types`

**from_gnash/actionscript.all — newly passing:** `HitTest-v6`, `HitTest-v7`, `String-v6`, `String-v7`, `String-v8`, `TextField-v5`, `XML-v6`, `XML-v7`, `XMLNode-v5`, `XMLNode-v6`, `XMLNode-v7`, `XMLNode-v8`, `toString_valueOf-v6`, `toString_valueOf-v7`, `toString_valueOf-v8`, `with-v5`, `with-v6`, `with-v7`, `with-v8`

**from_gnash/misc-swfc.all — newly passing:** `action_execution_order_test12`

**swf — newly passing:** `lzma_length_too_long`, `swf_length_too_long`

*Comparing `13b40eabb012` → `10a5b515a03a`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 21.2s — slowest: `aac` (24.5s)

### avm1

- **Pass:** 767/789 (97.2%)
- **Duration:** 1h21m30s across 30 shards
- **Lines:** 125,613/137,759 matching (91.2%)
- **Avg test duration:** 6.2s — slowest: `goto_advance2` (44.1s)

### avm2

- **Pass:** 1299/1346 (96.5%)
- **Duration:** 4h06m41s across 30 shards
- **Lines:** 162,225/164,338 matching (98.7%)
- **Avg test duration:** 11.0s — slowest: `away3d_advanced_shallow_water_demo` (84.5s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m44s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 18.3s — slowest: `embed_matching/fallback_preferences` (26.2s)

### from_avmplus

- **Pass:** 1544/1574 (98.1%)
- **Duration:** 3h25m32s across 30 shards
- **Lines:** 85,594/85,996 matching (99.5%)
- **Avg test duration:** 7.8s — slowest: `ecma3/Statements/eregress_74474_002` (65.8s)

### from_gnash/actionscript.all

- **Pass:** 167/243 (68.7%)
- **Duration:** 28m41s across 30 shards
- **Lines:** 30,990/38,791 matching (79.9%)
- **Avg test duration:** 7.0s — slowest: `MovieClip-v8` (45.0s)

### from_gnash/misc-ming.all

- **Pass:** 71/111 (64.0%)
- **Duration:** 32m31s across 30 shards
- **Lines:** 4,318/5,248 matching (82.3%)
- **Avg test duration:** 17.5s — slowest: `matrix_test` (103.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.0s — slowest: `function_test` (20.4s)

### from_gnash/misc-swfc.all

- **Pass:** 15/21 (71.4%)
- **Duration:** 4m45s across 30 shards
- **Lines:** 529/603 matching (87.7%)
- **Avg test duration:** 13.5s — slowest: `soft_reference_test1` (27.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m02s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.1s — slowest: `trace-as2/shortstack` (27.3s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 47m39s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 12.5s — slowest: `esc` (88.2s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m28s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `hitarea` (25.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.2s — slowest: `empty_url` (19.2s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.1s — slowest: `avm1_sprite_sc_ignored` (19.5s)

### regression

- **Pass:** 262/262 (100%)
- **Duration:** 52m05s across 30 shards
- **Lines:** 2,102/2,102 matching (100%)
- **Avg test duration:** 11.9s — slowest: `avm2_activation_vtable_bounded` (57.4s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m32s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.6s — slowest: `draw_to_bitmap_data_unconfigured` (25.3s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.6s — slowest: `convolution_filter_big_matrix` (19.9s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m35s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.9s — slowest: `auto_size/height` (30.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.3s — slowest: `swf_9_frame_script_dynamic_goto_2` (36.2s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 36m29s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.5s — slowest: `definefont4` (93.3s)
