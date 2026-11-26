# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b030ed745d4f`  
**Date:** 2026-11-25 23:59 UTC  
**Total duration:** 11h50m22s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 769 | 789 | 97.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1304 | 1348 | 96.7% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1549 | 1574 | 98.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 177 | 243 | 72.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 73 | 111 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 15 | 21 | 71.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 215 | 229 | 93.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 282 | 282 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4672** | **4897** | **95.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 125,660 | 137,805 | 91.2% |
| avm2 | 162,590 | 164,377 | 98.9% |
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
| **Total** | **418,444** | **441,604** | **94.8%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 12 |
| avm2 | 10 |
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
| **Total** | **40** |

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

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 14.7s — slowest: `stream_incomplete_loop` (18.6s)

### avm1

- **Pass:** 769/789 (97.5%)
- **Duration:** 1h17m23s across 30 shards
- **Lines:** 125,660/137,805 matching (91.2%)
- **Avg test duration:** 5.8s — slowest: `netstream_play_flv_screen` (40.7s)

### avm2

- **Pass:** 1304/1348 (96.7%)
- **Duration:** 3h41m02s across 30 shards
- **Lines:** 162,590/164,377 matching (98.9%)
- **Avg test duration:** 9.8s — slowest: `away3d_advanced_shallow_water_demo` (79.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m56s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.6s — slowest: `device_font_kerning` (33.3s)

### from_avmplus

- **Pass:** 1549/1574 (98.4%)
- **Duration:** 2h55m33s across 30 shards
- **Lines:** 85,618/85,996 matching (99.6%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_003` (64.0s)

### from_gnash/actionscript.all

- **Pass:** 177/243 (72.8%)
- **Duration:** 29m58s across 30 shards
- **Lines:** 31,095/38,791 matching (80.2%)
- **Avg test duration:** 7.4s — slowest: `array-v5` (55.5s)

### from_gnash/misc-ming.all

- **Pass:** 73/111 (65.8%)
- **Duration:** 35m22s across 30 shards
- **Lines:** 4,359/5,248 matching (83.1%)
- **Avg test duration:** 19.1s — slowest: `matrix_test` (109.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 12.3s — slowest: `TextFieldTest` (24.4s)

### from_gnash/misc-swfc.all

- **Pass:** 15/21 (71.4%)
- **Duration:** 5m38s across 30 shards
- **Lines:** 529/603 matching (87.7%)
- **Avg test duration:** 16.1s — slowest: `action_execution_order_test12` (26.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m55s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.8s — slowest: `background` (25.6s)

### from_shumway

- **Pass:** 215/229 (93.9%)
- **Duration:** 46m22s across 30 shards
- **Lines:** 2,408/2,484 matching (96.9%)
- **Avg test duration:** 12.1s — slowest: `esc` (87.3s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.6s — slowest: `text-bind` (25.2s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.7s — slowest: `avm1_non_swf_import` (26.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m10s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.8s — slowest: `avm1_sprite_sc_ignored` (18.6s)

### regression

- **Pass:** 282/282 (100%)
- **Duration:** 55m05s across 30 shards
- **Lines:** 2,979/2,979 matching (100%)
- **Avg test duration:** 11.7s — slowest: `avm2_json_roundtrip_bounded` (34.2s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m27s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.0s — slowest: `draw_to_bitmap_data_unconfigured` (30.5s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m30s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.9s — slowest: `lzma_length_too_long` (25.8s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m57s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 19.7s — slowest: `auto_size/return` (33.5s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 6m18s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 22.2s — slowest: `swf_9_frame_script_dynamic_goto_2` (32.6s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 33m41s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.3s — slowest: `definefont4` (112.0s)
