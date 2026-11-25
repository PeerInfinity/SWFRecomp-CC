# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8f4f6e395305`  
**Date:** 2026-11-25 03:46 UTC  
**Total duration:** 12h36m42s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 754 | 788 | 95.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1293 | 1346 | 96.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 71 | 111 | 64.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 14 | 21 | 66.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 254 | 254 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4569** | **4866** | **93.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,316 | 137,755 | 91.0% |
| avm2 | 162,033 | 164,338 | 98.6% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,878 | 38,791 | 79.6% |
| from_gnash/misc-ming.all | 4,318 | 5,248 | 82.3% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 526 | 603 | 87.2% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,030 | 2,030 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **416,273** | **440,566** | **94.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 12 |
| avm2 | 9 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 8 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
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
| **Total** | **38** |

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
| from_gnash/misc-swfc.all | action_execution_order_test12 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 3 | - | 18 | - |
| avm2 | - | - | 44 | - |
| from_gnash/misc-ming.all | - | - | 1 | - |
| from_shumway | 1 | - | 1 | - |

**avm1 — newly passing:** `malformed_actions/constant_pool_overlong`, `malformed_actions/constant_pool_overspill`, `malformed_actions/push_overspill`

**avm2 — newly passing:** `goto_framescript_queued/swf13`, `goto_framescript_queued_next_prev`, `goto_isplaying`, `goto_scene_isplaying`

**from_shumway — newly passing:** `bitmapdata/getpixel-from-embedded`

*Comparing `78fee9e13f85` → `8f4f6e395305`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 16.0s — slowest: `g711_event_mulaw` (24.7s)

### avm1

- **Pass:** 754/788 (95.7%)
- **Duration:** 1h25m25s across 30 shards
- **Lines:** 125,316/137,755 matching (91.0%)
- **Avg test duration:** 6.5s — slowest: `timer_run_actions` (39.8s)

### avm2

- **Pass:** 1293/1346 (96.1%)
- **Duration:** 4h02m51s across 30 shards
- **Lines:** 162,033/164,338 matching (98.6%)
- **Avg test duration:** 10.8s — slowest: `away3d_advanced_shallow_water_demo` (84.8s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m39s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.7s — slowest: `embed_matching/fallback_preferences` (26.6s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h17m35s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_003` (61.1s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 30m42s across 30 shards
- **Lines:** 30,878/38,791 matching (79.6%)
- **Avg test duration:** 7.5s — slowest: `MovieClip-v8` (56.1s)

### from_gnash/misc-ming.all

- **Pass:** 71/111 (64.0%)
- **Duration:** 33m31s across 30 shards
- **Lines:** 4,318/5,248 matching (82.3%)
- **Avg test duration:** 18.1s — slowest: `matrix_test` (105.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.7s — slowest: `function_test` (25.2s)

### from_gnash/misc-swfc.all

- **Pass:** 14/21 (66.7%)
- **Duration:** 5m01s across 30 shards
- **Lines:** 526/603 matching (87.2%)
- **Avg test duration:** 14.3s — slowest: `edittext_test1` (26.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m31s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.5s — slowest: `registers` (24.9s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 45m59s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 12.0s — slowest: `acid/acid-large` (65.4s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m21s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.0s — slowest: `text-bind` (20.7s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 41s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.5s — slowest: `avm1_non_swf_import` (19.2s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.4s — slowest: `avm1_sprite_sc_ignored` (25.7s)

### regression

- **Pass:** 254/254 (100%)
- **Duration:** 50m55s across 30 shards
- **Lines:** 2,030/2,030 matching (100%)
- **Avg test duration:** 12.0s — slowest: `avm2_timeline_gradients` (39.5s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m30s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.3s — slowest: `draw_to_bitmap_data_unconfigured` (24.4s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m06s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.4s — slowest: `lzma_length_too_long` (19.4s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m33s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.8s — slowest: `auto_size/return` (29.4s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m05s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.5s — slowest: `frame_script_cleanup` (32.6s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 35m27s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 14.1s — slowest: `definefont4` (88.5s)
