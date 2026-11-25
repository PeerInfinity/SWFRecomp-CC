# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `16033a154646`  
**Date:** 2026-11-25 22:59 UTC  
**Total duration:** 10h09m41s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 768 | 789 | 97.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1303 | 1347 | 96.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1549 | 1574 | 98.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 167 | 243 | 68.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 73 | 111 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 15 | 21 | 71.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 278 | 279 | 99.6% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4656** | **4893** | **95.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 125,659 | 137,805 | 91.2% |
| avm2 | 162,574 | 164,361 | 98.9% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,618 | 85,996 | 99.6% |
| from_gnash/actionscript.all | 30,990 | 38,791 | 79.9% |
| from_gnash/misc-ming.all | 4,359 | 5,248 | 83.1% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 529 | 603 | 87.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,775 | 2,776 | 99.96% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **418,118** | **441,385** | **94.7%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 13 |
| avm2 | 10 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 8 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 1 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 1 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | 1 |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **47** |

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
| avm1 | boxed_primitives | 96% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| regression | avm1_place_occupied_depth_swf5 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 1 | 1 | 452 | 8 |
| from_avmplus | 1 | - | 24 | - |
| from_gnash/misc-ming.all | - | - | 51 | 10 |

**avm1 — newly passing:** `load_cancel_via_unloadmovie`

**avm2 — newly passing:** `int_toexponential`, `json_parse_numbers`, `number_to_string`, `number_tostring`, `uint_toexponential`

**avm2 — newly failing:** `mouse_pick_avm1_root`

**from_avmplus — newly passing:** `as3/Types/Number/e15_7_4_6_1/swf14`, `as3/Types/Number/e15_7_4_6_1/swf15`, `ecma3/JSON/AS3Types`, `ecma3/Number/eregress_121952`, `ecma3/Number/toStringLimits`

**from_gnash/misc-ming.all — newly passing:** `place_object_test`, `place_object_test2`

*Comparing `10a5b515a03a` → `16033a154646`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 14.4s — slowest: `stream_incomplete_loop` (21.3s)

### avm1

- **Pass:** 768/789 (97.3%)
- **Duration:** 55m30s across 30 shards
- **Lines:** 125,659/137,805 matching (91.2%)
- **Avg test duration:** 4.2s — slowest: `define_font_glyph_table_order` (40.3s)

### avm2

- **Pass:** 1303/1347 (96.7%)
- **Duration:** 3h15m46s across 30 shards
- **Lines:** 162,574/164,361 matching (98.9%)
- **Avg test duration:** 8.7s — slowest: `away3d_advanced_shallow_water_demo` (78.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m36s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.3s — slowest: `device_font_no_ink` (26.8s)

### from_avmplus

- **Pass:** 1549/1574 (98.4%)
- **Duration:** 2h40m40s across 30 shards
- **Lines:** 85,618/85,996 matching (99.6%)
- **Avg test duration:** 6.1s — slowest: `ecma3/Statements/eregress_74474_003` (57.2s)

### from_gnash/actionscript.all

- **Pass:** 167/243 (68.7%)
- **Duration:** 22m30s across 30 shards
- **Lines:** 30,990/38,791 matching (79.9%)
- **Avg test duration:** 5.5s — slowest: `MovieClip-v8` (55.4s)

### from_gnash/misc-ming.all

- **Pass:** 73/111 (65.8%)
- **Duration:** 27m43s across 30 shards
- **Lines:** 4,359/5,248 matching (83.1%)
- **Avg test duration:** 15.0s — slowest: `matrix_test` (80.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 9.3s — slowest: `function_test` (19.5s)

### from_gnash/misc-swfc.all

- **Pass:** 15/21 (71.4%)
- **Duration:** 4m19s across 30 shards
- **Lines:** 529/603 matching (87.7%)
- **Avg test duration:** 12.3s — slowest: `movieclip_destruction_test4` (23.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m11s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.5s — slowest: `jump_after_end` (23.2s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 39m50s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 10.4s — slowest: `acid/acid-large` (76.8s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.3s — slowest: `label` (23.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.3s — slowest: `avm1_non_swf_import` (19.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.7s — slowest: `avm1_sprite_sc_ignored` (19.1s)

### regression

- **Pass:** 278/279 (99.6%)
- **Duration:** 47m37s across 30 shards
- **Lines:** 2,775/2,776 matching (99.96%)
- **Avg test duration:** 10.2s — slowest: `avm2_findprop_this_resolution` (39.9s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.1s — slowest: `draw_to_bitmap_data_unconfigured` (19.2s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m16s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 10.9s — slowest: `swf_length_too_long` (19.3s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m17s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 16.5s — slowest: `text_caret_placement_align` (31.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m40s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 20.0s — slowest: `frame_script_construct` (30.2s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 29m13s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.6s — slowest: `definefont4` (84.4s)
