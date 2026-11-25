# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `16033a154646`  
**Date:** 2026-11-25 22:36 UTC  
**Total duration:** 13h14m36s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 768 | 789 | 97.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1304 | 1347 | 96.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1549 | 1574 | 98.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 167 | 243 | 68.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 73 | 111 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 15 | 21 | 71.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 278 | 279 | 99.6% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4658** | **4893** | **95.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,659 | 137,805 | 91.2% |
| avm2 | 162,692 | 164,361 | 99.0% |
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
| **Total** | **418,242** | **441,385** | **94.8%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 13 |
| avm2 | 9 |
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

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 22.4s — slowest: `g711` (27.0s)

### avm1

- **Pass:** 768/789 (97.3%)
- **Duration:** 1h29m36s across 30 shards
- **Lines:** 125,659/137,805 matching (91.2%)
- **Avg test duration:** 6.8s — slowest: `define_font_glyph_table_order` (47.0s)

### avm2

- **Pass:** 1304/1347 (96.8%)
- **Duration:** 4h12m56s across 30 shards
- **Lines:** 162,692/164,361 matching (99.0%)
- **Avg test duration:** 11.2s — slowest: `away3d_advanced_shallow_water_demo` (85.7s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m54s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.3s — slowest: `embed_matching/fallback_preferences` (31.8s)

### from_avmplus

- **Pass:** 1549/1574 (98.4%)
- **Duration:** 3h24m42s across 30 shards
- **Lines:** 85,618/85,996 matching (99.6%)
- **Avg test duration:** 7.8s — slowest: `ecma3/Statements/eregress_74474_003` (58.1s)

### from_gnash/actionscript.all

- **Pass:** 167/243 (68.7%)
- **Duration:** 31m45s across 30 shards
- **Lines:** 30,990/38,791 matching (79.9%)
- **Avg test duration:** 7.8s — slowest: `MovieClip-v8` (59.2s)

### from_gnash/misc-ming.all

- **Pass:** 73/111 (65.8%)
- **Duration:** 34m31s across 30 shards
- **Lines:** 4,359/5,248 matching (83.1%)
- **Avg test duration:** 18.6s — slowest: `matrix_test` (107.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.3s — slowest: `implementsOpTest` (23.0s)

### from_gnash/misc-swfc.all

- **Pass:** 15/21 (71.4%)
- **Duration:** 5m30s across 30 shards
- **Lines:** 529/603 matching (87.7%)
- **Avg test duration:** 15.7s — slowest: `soft_reference_test1` (26.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m49s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.4s — slowest: `trace-as2/shortstack` (25.3s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 48m09s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 12.6s — slowest: `esc` (78.9s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m45s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.5s — slowest: `moviecliploader` (22.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 45s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.8s — slowest: `avm1_non_swf_import` (22.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m26s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.2s — slowest: `avm1_sprite_sc_ignored` (19.8s)

### regression

- **Pass:** 278/279 (99.6%)
- **Duration:** 59m46s across 30 shards
- **Lines:** 2,775/2,776 matching (99.96%)
- **Avg test duration:** 12.8s — slowest: `avm2_bitmapdata_draw_textfield` (54.8s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.7s — slowest: `draw_to_bitmap_data_unconfigured` (25.1s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m29s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.7s — slowest: `swf_length_too_short_no_second_frame` (22.8s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m42s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.5s — slowest: `auto_size/return` (33.2s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m19s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 22.3s — slowest: `swf_9_frame_script_dynamic_goto_2` (32.9s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 36m10s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.3s — slowest: `definefont4` (84.9s)
