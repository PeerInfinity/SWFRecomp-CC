# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `bc91565cea8e`  
**Date:** 2026-11-21 18:24 UTC  
**Total duration:** 11h46m54s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 711 | 757 | 93.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1241 | 1296 | 95.8% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1531 | 1572 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
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
| **Total** | **4312** | **4620** | **93.3%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 115,266 | 119,254 | 96.7% |
| avm2 | 153,759 | 158,377 | 97.1% |
| fonts | 351 | 377 | 93.1% |
| from_avmplus | 85,550 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,347 | 32,104 | 94.5% |
| from_gnash/misc-ming.all | 4,229 | 5,206 | 81.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
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
| **Total** | **395,953** | **408,067** | **97.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 2 | - |
| avm1 | 29 | 17 |
| avm2 | 37 | 18 |
| fonts | 1 | 1 |
| from_avmplus | 4 | 37 |
| from_gnash/actionscript.all | 4 | 88 |
| from_gnash/misc-ming.all | 9 | 32 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 5 |
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
| **Total** | **92** | **216** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | edittext_html_duplicate_attributes | 98% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| avm1 | shared_object_secure | 95% |
| avm2 | error_stack_trace_class_names | 94% |
| from_avmplus | e4x/XML/misc_errors | 94% |
| avm1 | amf0_utf8_probe | 93% |
| avm1 | localconnection_serialize_inherited_array_indices | 92% |
| avm2 | error_stack_trace_limit | 89% |
| avm1 | localconnection_serialize_sparse_array_getters | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | array_join_reentrant | 85% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | netconnection_serialize_arrays | 83% |
| avm1 | sparse_array_truncation_non_canonical_keys | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | edittext_set_text_same | 80% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m22s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.5s — slowest: `stream_incomplete_loop` (23.4s)

### avm1

- **Pass:** 711/757 (93.9%)
- **Ignored:** 18 tests
- **Duration:** 1h16m21s across 30 shards
- **Lines:** 115,266/119,254 matching (96.7%)
- **Avg test duration:** 5.8s — slowest: `movieclip_invalid_get_bounds_6` (43.1s)

### avm2

- **Pass:** 1241/1296 (95.8%)
- **Ignored:** 38 tests
- **Duration:** 3h54m30s across 30 shards
- **Lines:** 153,759/158,377 matching (97.1%)
- **Avg test duration:** 10.5s — slowest: `away3d_advanced_shallow_water_demo` (115.1s)

### fonts

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m04s across 30 shards
- **Lines:** 351/377 matching (93.1%)
- **Avg test duration:** 20.5s — slowest: `device_font_kerning` (32.7s)

### from_avmplus

- **Pass:** 1531/1572 (97.4%)
- **Ignored:** 2 tests
- **Duration:** 3h16m33s across 30 shards
- **Lines:** 85,550/85,970 matching (99.5%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Date/e15_9_5_36_1` (23.9s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 29m45s across 30 shards
- **Lines:** 30,347/32,104 matching (94.5%)
- **Avg test duration:** 7.4s — slowest: `MovieClip-v8` (56.2s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 32m07s across 30 shards
- **Lines:** 4,229/5,206 matching (81.2%)
- **Avg test duration:** 17.3s — slowest: `matrix_test` (81.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.3s — slowest: `exception` (24.0s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m27s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 16.8s — slowest: `mouse_drag_test` (25.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m29s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.5s — slowest: `jump_after_end` (23.4s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 44m43s across 30 shards
- **Lines:** 2,351/2,409 matching (97.6%)
- **Avg test duration:** 11.4s — slowest: `acid/acid-large` (88.4s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m21s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.0s — slowest: `label` (23.8s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 51s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 17.0s — slowest: `empty_url` (23.7s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m30s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.5s — slowest: `avm1_sprite_sc_ignored` (18.7s)

### regression

- **Pass:** 104/104 (100%)
- **Duration:** 23m53s across 30 shards
- **Lines:** 871/871 matching (100%)
- **Avg test duration:** 13.7s — slowest: `avm2_graphics_runtime` (32.8s)

### stage3d

- **Pass:** 7/8 (87.5%)
- **Duration:** 1m38s across 30 shards
- **Lines:** 211/216 matching (97.7%)
- **Avg test duration:** 12.3s — slowest: `draw_to_bitmap_data_unconfigured` (23.4s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m07s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.5s — slowest: `lzma_length_too_long` (22.9s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m55s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 19.6s — slowest: `auto_size/return` (33.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m43s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 20.2s — slowest: `frame_script_construct` (32.9s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 33m35s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.3s — slowest: `definefont4` (84.0s)
