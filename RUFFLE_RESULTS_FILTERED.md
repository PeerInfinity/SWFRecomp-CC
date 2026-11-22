# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `161ecf124012`  
**Date:** 2026-11-21 23:52 UTC  
**Total duration:** 9h53m04s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 732 | 764 | 95.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1272 | 1297 | 98.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1533 | 1572 | 97.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 13 | 18 | 72.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 108 | 108 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4375** | **4632** | **94.5%** | |

*68 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 115,787 | 119,408 | 97.0% |
| avm2 | 157,004 | 158,449 | 99.1% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,556 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,347 | 32,104 | 94.5% |
| from_gnash/misc-ming.all | 4,245 | 5,206 | 81.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 469 | 555 | 84.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,362 | 2,409 | 98.0% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 967 | 967 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **399,923** | **408,389** | **97.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 1 | - |
| avm1 | 15 | 17 |
| avm2 | 5 | 20 |
| fonts | - | 1 |
| from_avmplus | - | 39 |
| from_gnash/actionscript.all | 4 | 88 |
| from_gnash/misc-ming.all | 8 | 33 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 1 | 8 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | - | - |
| swf | - | 2 |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **35** | **222** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | amf0_array_matrix | 98% |
| avm1 | localconnection_serialize_sparse_array_getters | 96% |
| avm1 | video_prototype_lazy | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 4/5 (80.0%)
- **Duration:** 1m05s across 30 shards
- **Lines:** 18/24 matching (75.0%)
- **Avg test duration:** 13.0s — slowest: `g711_event_mulaw` (17.6s)

### avm1

- **Pass:** 732/764 (95.8%)
- **Ignored:** 16 tests
- **Duration:** 1h02m25s across 30 shards
- **Lines:** 115,787/119,408 matching (97.0%)
- **Avg test duration:** 4.8s — slowest: `define_font_glyph_table_order` (35.7s)

### avm2

- **Pass:** 1272/1297 (98.1%)
- **Ignored:** 38 tests
- **Duration:** 3h21m11s across 30 shards
- **Lines:** 157,004/158,449 matching (99.1%)
- **Avg test duration:** 9.0s — slowest: `away3d_advanced_shallow_water_demo` (94.8s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m23s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 15.9s — slowest: `device_font_glyph_fallback` (29.4s)

### from_avmplus

- **Pass:** 1533/1572 (97.5%)
- **Ignored:** 2 tests
- **Duration:** 2h34m41s across 30 shards
- **Lines:** 85,556/85,970 matching (99.5%)
- **Avg test duration:** 5.9s — slowest: `ecma3/Statements/eregress_74474_003` (68.3s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 25m23s across 30 shards
- **Lines:** 30,347/32,104 matching (94.5%)
- **Avg test duration:** 6.3s — slowest: `MovieClip-v8` (52.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 29m01s across 30 shards
- **Lines:** 4,245/5,206 matching (81.5%)
- **Avg test duration:** 15.6s — slowest: `matrix_test` (73.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m04s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.8s — slowest: `implementsOpTest` (26.8s)

### from_gnash/misc-swfc.all

- **Pass:** 13/18 (72.2%)
- **Ignored:** 2 tests
- **Duration:** 5m31s across 30 shards
- **Lines:** 469/555 matching (84.5%)
- **Avg test duration:** 17.3s — slowest: `soft_reference_test1` (29.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m12s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.6s — slowest: `trace-as2/root_onload` (28.0s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 40m28s across 30 shards
- **Lines:** 2,362/2,409 matching (98.0%)
- **Avg test duration:** 10.3s — slowest: `acid/acid-large` (64.0s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.4s — slowest: `hitarea` (22.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 36s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 11.9s — slowest: `empty_url` (17.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m00s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 5.0s — slowest: `avm1_sprite_sc_ignored` (17.4s)

### regression

- **Pass:** 108/108 (100%)
- **Duration:** 22m09s across 30 shards
- **Lines:** 967/967 matching (100%)
- **Avg test duration:** 12.3s — slowest: `avm2_child_simplebutton` (30.6s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 9.6s — slowest: `draw_to_bitmap_data_unconfigured` (29.3s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 39s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 5.5s — slowest: `swf_length_too_short_no_second_frame` (16.8s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 2m55s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 14.6s — slowest: `auto_size/height` (29.4s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 4m35s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 16.2s — slowest: `swf_9_frame_script_dynamic_goto_2` (23.4s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 27m27s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 10.9s — slowest: `definefont4` (72.5s)
