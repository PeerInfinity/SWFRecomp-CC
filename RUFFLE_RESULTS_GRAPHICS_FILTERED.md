# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `c489b84d9946`  
**Date:** 2026-11-21 19:32 UTC  
**Total duration:** 11h36m17s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 725 | 759 | 95.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1252 | 1297 | 96.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1533 | 1572 | 97.5% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 13 | 18 | 72.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 104 | 104 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 7 | 8 | 87.5% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **4343** | **4623** | **93.9%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
| avm1 | 115,651 | 119,262 | 97.0% |
| avm2 | 153,965 | 158,449 | 97.2% |
| fonts | 351 | 377 | 93.1% |
| from_avmplus | 85,556 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,347 | 32,104 | 94.5% |
| from_gnash/misc-ming.all | 4,229 | 5,206 | 81.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 469 | 555 | 84.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,351 | 2,409 | 97.6% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 871 | 871 | 100% |
| stage3d | 211 | 216 | 97.7% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **396,614** | **408,147** | **97.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | - | - |
| avm1 | 17 | 17 |
| avm2 | 26 | 19 |
| fonts | 1 | 1 |
| from_avmplus | - | 39 |
| from_gnash/actionscript.all | 4 | 88 |
| from_gnash/misc-ming.all | 9 | 32 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | - | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | 2 | 7 |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 1 | 1 |
| regression | - | - |
| stage3d | 1 | - |
| swf | - | 2 |
| text | - | - |
| timeline | - | 3 |
| visual | - | 2 |
| **Total** | **61** | **219** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | amf0_array_matrix | 98% |
| avm1 | localconnection_serialize_sparse_array_getters | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| avm2 | error_stack_trace_class_names | 94% |
| avm2 | error_stack_trace_limit | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | array_join_reentrant | 85% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | localconnection_serialize_inherited_array_indices | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | edittext_set_text_same | 80% |

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 14.7s — slowest: `g711_event_mulaw` (22.9s)

### avm1

- **Pass:** 725/759 (95.5%)
- **Ignored:** 18 tests
- **Duration:** 1h16m02s across 30 shards
- **Lines:** 115,651/119,262 matching (97.0%)
- **Avg test duration:** 5.8s — slowest: `define_font_glyph_table_order` (42.8s)

### avm2

- **Pass:** 1252/1297 (96.5%)
- **Ignored:** 38 tests
- **Duration:** 3h53m39s across 30 shards
- **Lines:** 153,965/158,449 matching (97.2%)
- **Avg test duration:** 10.5s — slowest: `away3d_advanced_shallow_water_demo` (89.7s)

### fonts

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m41s across 30 shards
- **Lines:** 351/377 matching (93.1%)
- **Avg test duration:** 17.9s — slowest: `embed_matching/fallback_preferences` (27.2s)

### from_avmplus

- **Pass:** 1533/1572 (97.5%)
- **Ignored:** 2 tests
- **Duration:** 3h11m06s across 30 shards
- **Lines:** 85,556/85,970 matching (99.5%)
- **Avg test duration:** 7.2s — slowest: `ecma3/Date/e15_9_5_36_1` (32.4s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 29m08s across 30 shards
- **Lines:** 30,347/32,104 matching (94.5%)
- **Avg test duration:** 7.2s — slowest: `MovieClip-v8` (53.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 31m00s across 30 shards
- **Lines:** 4,229/5,206 matching (81.2%)
- **Avg test duration:** 16.6s — slowest: `matrix_test` (81.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.1s — slowest: `function_test` (23.8s)

### from_gnash/misc-swfc.all

- **Pass:** 13/18 (72.2%)
- **Ignored:** 2 tests
- **Duration:** 5m24s across 30 shards
- **Lines:** 469/555 matching (84.5%)
- **Avg test duration:** 16.9s — slowest: `movieclip_destruction_test1` (24.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m16s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.8s — slowest: `trace-as2/super` (23.8s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 43m45s across 30 shards
- **Lines:** 2,351/2,409 matching (97.6%)
- **Avg test duration:** 11.1s — slowest: `acid/acid-large` (65.4s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m09s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.7s — slowest: `label` (23.4s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 40s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.4s — slowest: `empty_url` (18.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m29s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.4s — slowest: `avm1_sprite_sc_ignored` (23.0s)

### regression

- **Pass:** 104/104 (100%)
- **Duration:** 25m38s across 30 shards
- **Lines:** 871/871 matching (100%)
- **Avg test duration:** 14.8s — slowest: `avm2_gc_string_survives_collect` (52.7s)

### stage3d

- **Pass:** 7/8 (87.5%)
- **Duration:** 1m29s across 30 shards
- **Lines:** 211/216 matching (97.7%)
- **Avg test duration:** 11.2s — slowest: `draw_to_bitmap_data_unconfigured` (22.6s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m01s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 8.7s — slowest: `swf_length_too_short_no_second_frame` (18.7s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m31s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 17.6s — slowest: `text_caret_placement_align` (31.8s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m39s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 19.9s — slowest: `frame_script_cleanup` (30.9s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 32m29s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.9s — slowest: `definefont4` (82.7s)
