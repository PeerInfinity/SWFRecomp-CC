# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b030ed745d4f`  
**Date:** 2026-11-26 00:30 UTC  
**Total duration:** 12h45m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 769 | 789 | 97.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1305 | 1348 | 96.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1549 | 1574 | 98.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 177 | 243 | 72.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 73 | 111 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 15 | 21 | 71.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 282 | 282 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4674** | **4897** | **95.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 125,660 | 137,805 | 91.2% |
| avm2 | 162,708 | 164,377 | 99.0% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,618 | 85,996 | 99.6% |
| from_gnash/actionscript.all | 31,095 | 38,791 | 80.2% |
| from_gnash/misc-ming.all | 4,359 | 5,248 | 83.1% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 529 | 603 | 87.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,408 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 2,979 | 2,979 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **418,568** | **441,604** | **94.8%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
| avm1 | 12 |
| avm2 | 9 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
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
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 1 | - |
| from_gnash/actionscript.all | 5 | - | 105 | - |
| regression | 1 | - | 1 | - |

**avm1 — newly passing:** `boxed_primitives`

**from_gnash/actionscript.all — newly passing:** `Global-v6`, `Number-v5`, `Object-v5`, `Selection-v6`, `Selection-v7`, `Selection-v8`, `ops-v5`, `ops-v6`, `ops-v7`, `ops-v8`

**regression — newly passing:** `avm1_place_occupied_depth_swf5`

*Comparing `16033a154646` → `b030ed745d4f`*

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 21.9s — slowest: `aac` (24.8s)

### avm1

- **Pass:** 769/789 (97.5%)
- **Duration:** 1h27m36s across 30 shards
- **Lines:** 125,660/137,805 matching (91.2%)
- **Avg test duration:** 6.6s — slowest: `netstream_play_flv_screen` (49.5s)

### avm2

- **Pass:** 1305/1348 (96.8%)
- **Duration:** 3h58m27s across 30 shards
- **Lines:** 162,708/164,377 matching (99.0%)
- **Avg test duration:** 10.6s — slowest: `away3d_advanced_shallow_water_demo` (90.3s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m49s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 18.8s — slowest: `embed_matching/fallback_preferences` (26.3s)

### from_avmplus

- **Pass:** 1549/1574 (98.4%)
- **Duration:** 3h19m22s across 30 shards
- **Lines:** 85,618/85,996 matching (99.6%)
- **Avg test duration:** 7.6s — slowest: `ecma3/Statements/eregress_74474_003` (53.0s)

### from_gnash/actionscript.all

- **Pass:** 177/243 (72.8%)
- **Duration:** 31m05s across 30 shards
- **Lines:** 31,095/38,791 matching (80.2%)
- **Avg test duration:** 7.6s — slowest: `array-v5` (54.6s)

### from_gnash/misc-ming.all

- **Pass:** 73/111 (65.8%)
- **Duration:** 33m43s across 30 shards
- **Lines:** 4,359/5,248 matching (83.1%)
- **Avg test duration:** 18.2s — slowest: `matrix_test` (119.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m56s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.9s — slowest: `inheritance` (25.8s)

### from_gnash/misc-swfc.all

- **Pass:** 15/21 (71.4%)
- **Duration:** 5m35s across 30 shards
- **Lines:** 529/603 matching (87.7%)
- **Avg test duration:** 15.9s — slowest: `submoviegetvar` (31.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m36s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.8s — slowest: `zeroframe_definesprite` (31.2s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 46m56s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 12.3s — slowest: `acid/acid-large` (69.2s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m22s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.0s — slowest: `text-bind` (25.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 43s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.2s — slowest: `empty_url` (20.5s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.2s — slowest: `avm1_sprite_sc_ignored` (19.9s)

### regression

- **Pass:** 282/282 (100%)
- **Duration:** 57m50s across 30 shards
- **Lines:** 2,979/2,979 matching (100%)
- **Avg test duration:** 12.3s — slowest: `avm2_graphics_runtime` (42.7s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.6s — slowest: `draw_to_bitmap_data_unconfigured` (25.3s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.2s — slowest: `swf_length_too_long` (20.9s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m32s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.7s — slowest: `auto_size/height` (30.5s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m49s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 20.6s — slowest: `frame_script_cleanup_goto` (33.3s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 34m41s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.8s — slowest: `definefont4` (72.8s)
