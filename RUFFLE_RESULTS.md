# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `53a188c38f4e`  
**Date:** 2026-09-19 12:56 UTC  
**Total duration:** 11h14m58s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 700 | 735 | 95.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1217 | 1275 | 95.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
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
| **Total** | **4251** | **4576** | **92.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 121,054 | 132,315 | 91.5% |
| avm2 | 154,578 | 157,157 | 98.4% |
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
| **Total** | **402,458** | **426,629** | **94.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 15 | - |
| avm2 | 20 | - |
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
| **Total** | **77** | **1** |

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
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm1 | geturl | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 2 | - | 10 | - |
| avm2 | 7 | - | 310 | - |
| from_gnash/actionscript.all | - | - | 14 | - |
| from_gnash/misc-ming.all | 1 | - | 34 | - |

**avm1 — newly passing:** `xml_getbytes`

**avm2 — newly passing:** `goto_framescript_queued/swf10`, `goto_framescript_queued/swf9`, `goto_framescript_queued_same_frame`, `tab_ordering_properties`

*Comparing `317ac43cffd3` → `53a188c38f4e`*

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

- **Pass:** 700/735 (95.2%)
- **Duration:** 1h08m19s across 30 shards
- **Lines:** 121,054/132,315 matching (91.5%)
- **Avg test duration:** 5.5s — slowest: `define_font_glyph_table_order` (36.7s)

### avm2

- **Pass:** 1217/1275 (95.5%)
- **Duration:** 3h42m43s across 30 shards
- **Lines:** 154,578/157,157 matching (98.4%)
- **Avg test duration:** 10.4s — slowest: `away3d_advanced_shallow_water_demo` (89.8s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m38s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 19.7s — slowest: `device_font_kerning` (27.8s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h07m43s across 30 shards
- **Lines:** 85,560/85,996 matching (99.5%)
- **Avg test duration:** 7.1s — slowest: `ecma3/Statements/eregress_74474_002` (59.2s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 29m49s across 30 shards
- **Lines:** 30,495/38,791 matching (78.6%)
- **Avg test duration:** 7.3s — slowest: `MovieClip-v8` (69.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 32m41s across 30 shards
- **Lines:** 4,197/5,248 matching (80.0%)
- **Avg test duration:** 17.6s — slowest: `matrix_test` (84.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.3s — slowest: `function_test` (21.3s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m37s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 16.8s — slowest: `opcode_guard_test2` (24.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m31s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.5s — slowest: `tags_after_last_showframe` (23.6s)

### from_shumway

- **Pass:** 213/229 (93.0%)
- **Duration:** 42m58s across 30 shards
- **Lines:** 2,393/2,484 matching (96.3%)
- **Avg test duration:** 11.2s — slowest: `esc` (76.5s)

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
