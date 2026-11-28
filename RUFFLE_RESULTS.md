# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b8671fd2f516`  
**Date:** 2026-11-28 02:31 UTC  
**Total duration:** 11h34m16s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 776 | 791 | 98.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1321 | 1353 | 97.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1567 | 1574 | 99.6% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 193 | 243 | 79.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 77 | 111 | 69.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 17 | 21 | 81.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 20 | 20 | 100% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 218 | 229 | 95.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 346 | 346 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 16 | 17 | 94.1% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4806** | **4968** | **96.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 127,286 | 137,880 | 92.3% |
| avm2 | 163,065 | 164,501 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,956 | 85,996 | 99.95% |
| from_gnash/actionscript.all | 31,367 | 38,791 | 80.9% |
| from_gnash/misc-ming.all | 4,403 | 5,248 | 83.9% |
| from_gnash/misc-mtasc.all | 215 | 231 | 93.1% |
| from_gnash/misc-swfc.all | 565 | 603 | 93.7% |
| from_gnash/misc-swfmill.all | 95 | 95 | 100% |
| from_shumway | 2,414 | 2,484 | 97.2% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 3,757 | 3,757 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 94 | 94 | 100% |
| text | 979 | 979 | 100% |
| timeline | 370 | 371 | 99.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **422,026** | **442,581** | **95.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 9 |
| avm2 | 6 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 3 |
| from_gnash/misc-ming.all | 7 |
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
| **Total** | **31** |

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
| avm1 | - | - | 19 | 159 |
| from_gnash/actionscript.all | - | - | 255 | 129 |
| from_gnash/misc-ming.all | 1 | - | 235 | - |
| from_gnash/misc-swfmill.all | - | - | 2 | - |

**from_gnash/actionscript.all — newly passing:** `ExternalInterface-v8`, `LoadVars-v6`, `LoadVars-v7`, `LoadVars-v8`, `Object-v6`, `Object-v7`, `Object-v8`, `Sound-v5`, `setProperty-v5`, `setProperty-v6`, `setProperty-v7`, `setProperty-v8`

**from_gnash/misc-ming.all — newly passing:** `EmbeddedFontTest`

**from_gnash/misc-swfmill.all — newly passing:** `zeroframe_definesprite`

*Comparing `0224aaf25632` → `b8671fd2f516`*

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
- **Avg test duration:** 14.5s — slowest: `stream_incomplete_loop` (19.6s)

### avm1

- **Pass:** 776/791 (98.1%)
- **Duration:** 1h13m08s across 30 shards
- **Lines:** 127,286/137,880 matching (92.3%)
- **Avg test duration:** 5.5s — slowest: `textfield_border_color` (31.9s)

### avm2

- **Pass:** 1321/1353 (97.6%)
- **Duration:** 3h37m12s across 30 shards
- **Lines:** 163,065/164,501 matching (99.1%)
- **Avg test duration:** 9.6s — slowest: `away3d_advanced_shallow_water_demo` (85.4s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m41s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 17.9s — slowest: `device_font_kerning` (25.4s)

### from_avmplus

- **Pass:** 1567/1574 (99.6%)
- **Duration:** 2h48m43s across 30 shards
- **Lines:** 85,956/85,996 matching (99.95%)
- **Avg test duration:** 6.4s — slowest: `ecma3/Statements/eregress_74474_003` (65.8s)

### from_gnash/actionscript.all

- **Pass:** 193/243 (79.4%)
- **Duration:** 27m48s across 30 shards
- **Lines:** 31,367/38,791 matching (80.9%)
- **Avg test duration:** 6.8s — slowest: `MovieClip-v8` (52.7s)

### from_gnash/misc-ming.all

- **Pass:** 77/111 (69.4%)
- **Duration:** 32m39s across 30 shards
- **Lines:** 4,403/5,248 matching (83.9%)
- **Avg test duration:** 17.6s — slowest: `matrix_test` (78.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m47s across 30 shards
- **Lines:** 215/231 matching (93.1%)
- **Avg test duration:** 11.9s — slowest: `exception` (20.3s)

### from_gnash/misc-swfc.all

- **Pass:** 17/21 (81.0%)
- **Duration:** 5m19s across 30 shards
- **Lines:** 565/603 matching (93.7%)
- **Avg test duration:** 15.2s — slowest: `movieclip_destruction_test3` (26.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 20/20 (100%)
- **Duration:** 6m42s across 30 shards
- **Lines:** 95/95 matching (100%)
- **Avg test duration:** 20.1s — slowest: `registers` (26.3s)

### from_shumway

- **Pass:** 218/229 (95.2%)
- **Duration:** 42m49s across 30 shards
- **Lines:** 2,414/2,484 matching (97.2%)
- **Avg test duration:** 11.2s — slowest: `acid/acid-large` (68.4s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.2s — slowest: `label` (21.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 42s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 14.1s — slowest: `avm1_non_swf_import` (20.8s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.2s — slowest: `avm1_sprite_sc_ignored` (20.3s)

### regression

- **Pass:** 346/346 (100%)
- **Duration:** 1h05m26s across 30 shards
- **Lines:** 3,757/3,757 matching (100%)
- **Avg test duration:** 11.3s — slowest: `avm2_applyfilter_bevel_sample` (39.7s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.8s — slowest: `draw_to_bitmap_data_unconfigured` (24.9s)

### swf

- **Pass:** 7/7 (100%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 94/94 matching (100%)
- **Avg test duration:** 11.7s — slowest: `lzma_length_too_long` (20.2s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m29s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.4s — slowest: `text_caret_placement_leading` (33.0s)

### timeline

- **Pass:** 16/17 (94.1%)
- **Duration:** 6m09s across 30 shards
- **Lines:** 370/371 matching (99.7%)
- **Avg test duration:** 21.7s — slowest: `swf_9_frame_script_button_order` (33.9s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m39s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.9s — slowest: `definefont4` (86.9s)
