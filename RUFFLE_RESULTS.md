# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `0224aaf25632`  
**Date:** 2026-11-27 22:24 UTC  
**Total duration:** 11h25m03s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 776 | 791 | 98.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1321 | 1353 | 97.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1567 | 1574 | 99.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 181 | 243 | 74.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 76 | 111 | 68.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 17 | 21 | 81.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 218 | 229 | 95.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 338 | 338 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 16 | 17 | 94.1% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4784** | **4960** | **96.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 127,426 | 137,880 | 92.4% |
| avm2 | 163,065 | 164,501 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,956 | 85,996 | 99.95% |
| from_gnash/actionscript.all | 31,241 | 38,791 | 80.5% |
| from_gnash/misc-ming.all | 4,168 | 5,248 | 79.4% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 565 | 603 | 93.7% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,414 | 2,484 | 97.2% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,530 | 3,530 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **421,576** | **442,354** | **95.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 9 |
| avm2 | 6 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 8 |
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
| **Total** | **32** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | movieclip_hittest_shapeflag | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 99% |
| avm2 | loader_load | 98% |
| from_gnash/misc-swfc.all | matrix_accuracy_test1 | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 1665 | - |
| avm2 | - | - | 116 | - |
| from_avmplus | - | - | 3 | - |
| from_gnash/actionscript.all | - | - | 64 | - |
| from_gnash/misc-ming.all | 2 | 1 | 12 | 209 |
| from_shumway | - | - | 6 | - |
| regression | 1 | - | 2 | - |
| timeline | - | - | 5 | - |

**avm2 — newly passing:** `html_text_img_parsing`, `swf_9_goto_in_construct_frame`, `textblock_releaselines`, `textline_atom_index_at_char_index`

**from_avmplus — newly passing:** `as3/Math/e15_1_2_2`, `regress/bug_479786`, `regress/bug_558863_swf10`

**from_gnash/misc-ming.all — newly passing:** `action_order/action_execution_order_test11`, `action_order/action_execution_order_test4`

**from_shumway — newly passing:** `MaskTest-3`, `avm2/flash/geom/transform/pixelBounds`, `timeline/nav/clipDepth`

**regression — newly passing:** `avm1_nested_child_swapdepths_remove`

**timeline — newly passing:** `swf_9_event_goto_frame_script`, `swf_9_frame_script_dynamic_goto`

*Comparing `2d40d37996b8` → `0224aaf25632`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 15.4s — slowest: `g711_event_mulaw` (24.1s)

### avm1

- **Pass:** 776/791 (98.1%)
- **Duration:** 1h05m44s across 30 shards
- **Lines:** 127,426/137,880 matching (92.4%)
- **Avg test duration:** 4.9s — slowest: `netstream_play_flv_screen` (32.9s)

### avm2

- **Pass:** 1321/1353 (97.6%)
- **Duration:** 3h34m58s across 30 shards
- **Lines:** 163,065/164,501 matching (99.1%)
- **Avg test duration:** 9.5s — slowest: `away3d_advanced_shallow_water_demo` (83.8s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m53s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 19.3s — slowest: `embed_matching/fallback_preferences` (33.8s)

### from_avmplus

- **Pass:** 1567/1574 (99.6%)
- **Duration:** 2h56m28s across 30 shards
- **Lines:** 85,956/85,996 matching (99.95%)
- **Avg test duration:** 6.7s — slowest: `ecma3/Statements/eregress_74474_003` (70.0s)

### from_gnash/actionscript.all

- **Pass:** 181/243 (74.5%)
- **Duration:** 25m32s across 30 shards
- **Lines:** 31,241/38,791 matching (80.5%)
- **Avg test duration:** 6.3s — slowest: `MovieClip-v8` (56.4s)

### from_gnash/misc-ming.all

- **Pass:** 76/111 (68.5%)
- **Duration:** 30m32s across 30 shards
- **Lines:** 4,168/5,248 matching (79.4%)
- **Avg test duration:** 16.5s — slowest: `matrix_test` (103.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m04s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 13.8s — slowest: `TextFieldTest` (27.2s)

### from_gnash/misc-swfc.all

- **Pass:** 17/21 (81.0%)
- **Duration:** 4m48s across 30 shards
- **Lines:** 565/603 matching (93.7%)
- **Avg test duration:** 13.7s — slowest: `action_execution_order_test10` (26.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m54s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.7s — slowest: `afunc_dict` (24.7s)

### from_shumway

- **Pass:** 218/229 (95.2%)
- **Duration:** 42m44s across 30 shards
- **Lines:** 2,414/2,484 matching (97.2%)
- **Avg test duration:** 11.2s — slowest: `esc` (64.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m47s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.2s — slowest: `text-bind` (20.9s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.7s — slowest: `avm1_non_swf_import` (25.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 58s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 4.8s — slowest: `avm2_loads_avm1` (8.7s)

### regression

- **Pass:** 338/338 (100%)
- **Duration:** 1h03m13s across 30 shards
- **Lines:** 3,530/3,530 matching (100%)
- **Avg test duration:** 11.2s — slowest: `avm2_goto_catchup_scale` (33.9s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m32s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 11.5s — slowest: `draw_to_bitmap_data_unconfigured` (31.5s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.1s — slowest: `lzma_length_too_long` (24.4s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m38s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.1s — slowest: `text_caret_placement_leading` (32.4s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 4m58s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 17.5s — slowest: `missing_frame_scripts` (31.5s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m53s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.0s — slowest: `definefont4` (84.9s)
