# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `08709f65842a`  
**Date:** 2026-11-21 17:00 UTC  
**Total duration:** 10h30m18s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 711 | 757 | 93.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1239 | 1296 | 95.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1531 | 1572 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 148 | 240 | 61.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 104 | 104 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 7 | 8 | 87.5% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 148 | 150 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4309** | **4619** | **93.3%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 115,266 | 119,254 | 96.7% |
| avm2 | 153,717 | 158,377 | 97.1% |
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
| **Total** | **395,911** | **408,067** | **97.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| audio | 2 | - |
| avm1 | 29 | 17 |
| avm2 | 39 | 18 |
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
| **Total** | **94** | **216** |

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

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 13.6s — slowest: `g711_event_mulaw` (22.0s)

### avm1

- **Pass:** 711/757 (93.9%)
- **Ignored:** 18 tests
- **Duration:** 1h08m04s across 30 shards
- **Lines:** 115,266/119,254 matching (96.7%)
- **Avg test duration:** 5.2s — slowest: `movieclip_invalid_get_bounds_6` (59.6s)

### avm2

- **Pass:** 1239/1296 (95.6%)
- **Ignored:** 38 tests
- **Duration:** 3h27m31s across 30 shards
- **Lines:** 153,717/158,377 matching (97.1%)
- **Avg test duration:** 9.3s — slowest: `away3d_advanced_shallow_water_demo` (73.8s)

### fonts

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m30s across 30 shards
- **Lines:** 351/377 matching (93.1%)
- **Avg test duration:** 16.7s — slowest: `embed_matching/fallback_preferences` (33.9s)

### from_avmplus

- **Pass:** 1531/1572 (97.4%)
- **Ignored:** 2 tests
- **Duration:** 2h49m05s across 30 shards
- **Lines:** 85,550/85,970 matching (99.5%)
- **Avg test duration:** 6.4s — slowest: `ecma3/Statements/eregress_74474_003` (65.0s)

### from_gnash/actionscript.all

- **Pass:** 148/240 (61.7%)
- **Ignored:** 3 tests
- **Duration:** 27m38s across 30 shards
- **Lines:** 30,347/32,104 matching (94.5%)
- **Avg test duration:** 6.9s — slowest: `MovieClip-v8` (52.1s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 30m56s across 30 shards
- **Lines:** 4,229/5,206 matching (81.2%)
- **Avg test duration:** 16.7s — slowest: `matrix_test` (116.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m47s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.9s — slowest: `implementsOpTest` (26.7s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 5m19s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 16.7s — slowest: `gotoFrameLabelAsFunction` (26.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m05s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.3s — slowest: `dict_override` (25.2s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 41m39s across 30 shards
- **Lines:** 2,351/2,409 matching (97.6%)
- **Avg test duration:** 10.6s — slowest: `acid/acid-large` (65.0s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.1s — slowest: `text-bind` (22.3s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 38s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 12.5s — slowest: `avm1_non_swf_import` (18.4s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m13s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 6.1s — slowest: `avm1_sprite_sc_ignored` (21.9s)

### regression

- **Pass:** 104/104 (100%)
- **Duration:** 22m31s across 30 shards
- **Lines:** 871/871 matching (100%)
- **Avg test duration:** 13.0s — slowest: `avm2_typed_value_ops` (36.8s)

### stage3d

- **Pass:** 7/8 (87.5%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 211/216 matching (97.7%)
- **Avg test duration:** 10.0s — slowest: `draw_to_bitmap_data_unconfigured` (22.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m05s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 9.3s — slowest: `swf_length_too_short_no_second_frame` (25.1s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 2m57s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 14.8s — slowest: `auto_size/width` (23.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m05s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 17.9s — slowest: `frame_script_cleanup3` (33.1s)

### visual

- **Pass:** 148/150 (98.7%)
- **Duration:** 31m56s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.7s — slowest: `definefont4` (80.3s)
