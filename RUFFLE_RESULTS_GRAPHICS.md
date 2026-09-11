# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `c4a952960bca`  
**Date:** 2026-09-11 15:53 UTC  
**Total duration:** 11h14m54s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 691 | 733 | 94.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1200 | 1270 | 94.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 213 | 229 | 93.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 90 | 90 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4219** | **4563** | **92.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 120,011 | 131,677 | 91.1% |
| avm2 | 152,229 | 155,348 | 98.0% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,558 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,418 | 38,791 | 78.4% |
| from_gnash/misc-ming.all | 4,058 | 5,248 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,321 | 2,484 | 93.4% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 56 | 79 | 70.9% |
| regression | 693 | 693 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **398,707** | **424,111** | **94.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 24 | - |
| avm2 | 34 | - |
| fonts | 1 | - |
| from_avmplus | 4 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 5 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 1 | - |
| visual | - | - |
| **Total** | **104** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | geom_transform | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_avmplus | ecma3/JSON/adhoc | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | - | 128 |
| avm2 | 1 | 1 | 16 | 3 |
| from_avmplus | - | 1 | - | - |

**avm2 — newly passing:** `loader_duplicate_class`

**avm2 — newly failing:** `geom_transform`

*Comparing `12d2ec06b7bf` → `c4a952960bca`*

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 17.0s — slowest: `stream_incomplete_loop` (24.2s)

### avm1

- **Pass:** 691/733 (94.3%)
- **Duration:** 59m19s across 30 shards
- **Lines:** 120,011/131,677 matching (91.1%)
- **Avg test duration:** 4.8s — slowest: `netstream_play_flv_screen` (38.6s)

### avm2

- **Pass:** 1200/1270 (94.5%)
- **Duration:** 3h47m06s across 30 shards
- **Lines:** 152,229/155,348 matching (98.0%)
- **Avg test duration:** 10.7s — slowest: `away3d_advanced_shallow_water_demo` (101.0s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 3m00s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 22.4s — slowest: `embed_matching/fallback_preferences` (32.2s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h32m50s across 30 shards
- **Lines:** 85,558/85,996 matching (99.5%)
- **Avg test duration:** 8.0s — slowest: `ecma3/Statements/eregress_74474_003` (55.7s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 24m25s across 30 shards
- **Lines:** 30,418/38,791 matching (78.4%)
- **Avg test duration:** 6.0s — slowest: `MovieClip-v8` (68.9s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 25m08s across 30 shards
- **Lines:** 4,058/5,248 matching (77.3%)
- **Avg test duration:** 13.5s — slowest: `matrix_test` (109.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m40s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.1s — slowest: `exception` (23.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m43s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 14.1s — slowest: `movieclip_destruction_test1` (23.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m55s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.7s — slowest: `initaction_in_definesprite` (23.2s)

### from_shumway

- **Pass:** 213/229 (93.0%)
- **Duration:** 46m06s across 30 shards
- **Lines:** 2,321/2,484 matching (93.4%)
- **Avg test duration:** 12.0s — slowest: `acid/acid-large` (79.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m38s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.3s — slowest: `hitarea` (23.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.6s — slowest: `empty_url` (22.9s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m34s across 30 shards
- **Lines:** 56/79 matching (70.9%)
- **Avg test duration:** 7.8s — slowest: `avm1_sprite_sc_ignored` (20.5s)

### regression

- **Pass:** 90/90 (100%)
- **Duration:** 14m18s across 30 shards
- **Lines:** 693/693 matching (100%)
- **Avg test duration:** 9.5s — slowest: `avm2_parent_child_static_text` (38.9s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m09s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.9s — slowest: `scissor_rectangle_invalid` (11.8s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 15s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 2.1s — slowest: `lzma_length_too_short` (2.5s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m41s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 20.1s — slowest: `text_caret_placement_align` (31.5s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 2m44s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 9.6s — slowest: `frame_script_button_order` (30.7s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 35m06s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.3s — slowest: `definefont4` (75.2s)
