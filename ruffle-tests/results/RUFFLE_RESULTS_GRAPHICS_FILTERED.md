# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](../ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `d387fcee5b88`  
**Date:** 2026-11-28 17:54 UTC  
**Total duration:** 12h09m30s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](../tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 776 | 785 | 98.9% | [details](../tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1312 | 1325 | 99.0% | [details](../tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](../tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1567 | 1572 | 99.7% | [details](../tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 193 | 240 | 80.4% | [details](../tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 77 | 110 | 70.0% | [details](../tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](../tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 17 | 20 | 85.0% | [details](../tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 20 | 20 | 100% | [details](../tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 217 | 223 | 97.3% | [details](../tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](../tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](../tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](../tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 347 | 347 | 100% | [details](../tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](../tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 7 | 7 | 100% | [details](../tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](../tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 16 | 17 | 94.1% | [details](../tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](../tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4798** | **4922** | **97.5%** | |

*52 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 117,187 | 120,307 | 97.4% |
| avm2 | 161,765 | 162,785 | 99.4% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,944 | 85,970 | 99.97% |
| from_gnash/actionscript.all | 31,149 | 32,104 | 97.0% |
| from_gnash/misc-ming.all | 4,396 | 5,206 | 84.4% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 550 | 585 | 94.0% |
| from_gnash/misc-swfmill.all | 95 | 95 | 100% |
| from_shumway | 2,368 | 2,409 | 98.3% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,770 | 3,770 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **410,348** | **416,457** | **98.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 5 | 4 |
| avm2 | 1 | 12 |
| fonts | - | 1 |
| from_avmplus | - | 5 |
| from_gnash/actionscript.all | - | 47 |
| from_gnash/misc-ming.all | 6 | 27 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 3 |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | - | 6 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | - | - |
| timeline | - | 1 |
| visual | - | 2 |
| **Total** | **13** | **111** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm2 | shared_object | 90% |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 22.8s — slowest: `aac` (25.6s)

### avm1

- **Pass:** 776/785 (98.9%)
- **Ignored:** 10 tests
- **Duration:** 1h03m28s across 30 shards
- **Lines:** 117,187/120,307 matching (97.4%)
- **Avg test duration:** 4.7s — slowest: `mouse_hover_events_while_dragging` (34.0s)

### avm2

- **Pass:** 1312/1325 (99.0%)
- **Ignored:** 29 tests
- **Duration:** 3h51m02s across 30 shards
- **Lines:** 161,765/162,785 matching (99.4%)
- **Avg test duration:** 10.2s — slowest: `away3d_advanced_shallow_water_demo` (120.3s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 21.7s — slowest: `device_font_no_ink` (29.7s)

### from_avmplus

- **Pass:** 1567/1572 (99.7%)
- **Ignored:** 2 tests
- **Duration:** 3h19m54s across 30 shards
- **Lines:** 85,944/85,970 matching (99.97%)
- **Avg test duration:** 7.6s — slowest: `ecma3/Statements/eregress_74474_003` (66.1s)

### from_gnash/actionscript.all

- **Pass:** 193/240 (80.4%)
- **Ignored:** 3 tests
- **Duration:** 21m56s across 30 shards
- **Lines:** 31,149/32,104 matching (97.0%)
- **Avg test duration:** 5.4s — slowest: `MovieClip-v8` (55.0s)

### from_gnash/misc-ming.all

- **Pass:** 77/110 (70.0%)
- **Ignored:** 1 tests
- **Duration:** 26m06s across 30 shards
- **Lines:** 4,396/5,206 matching (84.4%)
- **Avg test duration:** 14.2s — slowest: `matrix_test` (89.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m17s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 15.3s — slowest: `exception` (27.4s)

### from_gnash/misc-swfc.all

- **Pass:** 17/20 (85.0%)
- **Ignored:** 1 tests
- **Duration:** 4m41s across 30 shards
- **Lines:** 550/585 matching (94.0%)
- **Avg test duration:** 13.9s — slowest: `action_execution_order_test12` (27.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 20/20 (100%)
- **Duration:** 7m21s across 30 shards
- **Lines:** 95/95 matching (100%)
- **Avg test duration:** 22.1s — slowest: `dict_callframe` (26.6s)

### from_shumway

- **Pass:** 217/223 (97.3%)
- **Ignored:** 6 tests
- **Duration:** 48m45s across 30 shards
- **Lines:** 2,368/2,409 matching (98.3%)
- **Avg test duration:** 12.3s — slowest: `acid/acid-large` (72.7s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.1s — slowest: `label` (20.3s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 44s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.7s — slowest: `avm1_non_swf_import` (21.0s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.6s — slowest: `avm2_loads_avm1_v10` (10.3s)

### regression

- **Pass:** 347/347 (100%)
- **Duration:** 1h01m35s across 30 shards
- **Lines:** 3,770/3,770 matching (100%)
- **Avg test duration:** 10.6s — slowest: `avm1_attached_clip_selfgoto_trace` (27.4s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m53s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 14.1s — slowest: `request_matching_profiles` (28.5s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 12.6s — slowest: `convolution_filter_big_matrix` (21.2s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m54s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 19.5s — slowest: `text_caret_placement_scroll` (35.2s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 5m25s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 19.1s — slowest: `swf_9_frame_script_dynamic_goto` (29.7s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 40m13s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 15.9s — slowest: `definefont4` (115.0s)
