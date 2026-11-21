# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `c489b84d9946`  
**Date:** 2026-11-21 19:49 UTC  
**Total duration:** 9h06m23s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 727 | 777 | 93.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1253 | 1335 | 93.9% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 13 | 20 | 65.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 104 | 104 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 7 | 8 | 87.5% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4345** | **4693** | **92.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 124,792 | 137,510 | 90.8% |
| avm2 | 158,199 | 163,943 | 96.5% |
| fonts | 351 | 377 | 93.1% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,712 | 38,791 | 79.2% |
| from_gnash/misc-ming.all | 4,236 | 5,248 | 80.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 486 | 580 | 83.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,396 | 2,484 | 96.5% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 871 | 871 | 100% |
| stage3d | 211 | 216 | 97.7% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **410,429** | **438,744** | **93.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 28 |
| avm2 | 39 |
| fonts | 1 |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 7 |
| from_gnash/misc-ming.all | 10 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 3 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | 1 |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **95** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | amf0_array_matrix | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| avm1 | localconnection_serialize_sparse_array_getters | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| avm2 | error_stack_trace_class_names | 94% |
| avm2 | error_stack_trace_limit | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | array_join_reentrant | 85% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | localconnection_serialize_inherited_array_indices | 83% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | edittext_set_text_same | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| audio | 1 | - | 13 | - |
| avm1 | 12 | - | 378 | 1 |
| avm2 | 10 | - | 132 | - |
| from_avmplus | 3 | - | 3 | - |
| from_gnash/misc-swfc.all | 1 | - | 32 | - |

**audio — newly passing:** `g711`

**avm1 — newly passing:** `amf0_utf8_probe`, `amf_array_indices`, `array_truncation_non_canonical_keys`, `edittext_html_duplicate_attributes`, `localconnection_serialize_function_array_elements`, `netconnection_serialize_arrays`, `shared_object_secure`, `sparse_array_truncation_non_canonical_keys`, `textfield_get_text_format_args`, `textfield_set_text_format_args`, `textfield_set_text_format_text_change`, `xml_stringify_utf16`

**avm2 — newly passing:** `bitmapdata_encode_jpeg_visual`, `bitmapdata_encode_png_roundtrip`, `bitmapdata_encode_png_visual`, `dictionary_qname_keys`, `edittext_event_link_case_insensitive`, `perspective_projection_center`, `textfield_default_text_format_null`, `xml_many_namespace_declarations`, `xml_unescaping_nul_char_ref`

**from_avmplus — newly passing:** `as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl`, `regress/bug_478501`

**from_gnash/misc-swfc.all — newly passing:** `movieclip_destruction_test4`

*Comparing `bc91565cea8e` → `c489b84d9946`*

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
- **Avg test duration:** 14.6s — slowest: `stream_incomplete_loop` (22.6s)

### avm1

- **Pass:** 727/777 (93.6%)
- **Duration:** 44m22s across 30 shards
- **Lines:** 124,792/137,510 matching (90.8%)
- **Avg test duration:** 3.4s — slowest: `define_font_glyph_table_order` (37.0s)

### avm2

- **Pass:** 1253/1335 (93.9%)
- **Duration:** 3h06m45s across 30 shards
- **Lines:** 158,199/163,943 matching (96.5%)
- **Avg test duration:** 8.4s — slowest: `away3d_advanced_shallow_water_demo` (77.3s)

### fonts

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m07s across 30 shards
- **Lines:** 351/377 matching (93.1%)
- **Avg test duration:** 14.1s — slowest: `embed_matching/fallback_preferences` (22.6s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 2h41m21s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 6.1s — slowest: `ecma3/Statements/eregress_74474_003` (63.5s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 19m40s across 30 shards
- **Lines:** 30,712/38,791 matching (79.2%)
- **Avg test duration:** 4.8s — slowest: `MovieClip-v8` (54.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 22m27s across 30 shards
- **Lines:** 4,236/5,248 matching (80.7%)
- **Avg test duration:** 12.1s — slowest: `matrix_test` (105.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 60s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 6.6s — slowest: `implementsOpTest` (17.3s)

### from_gnash/misc-swfc.all

- **Pass:** 13/20 (65.0%)
- **Duration:** 3m43s across 30 shards
- **Lines:** 486/580 matching (83.8%)
- **Avg test duration:** 11.2s — slowest: `movieclip_destruction_test1` (23.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m44s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 14.2s — slowest: `dict_event` (22.6s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 38m02s across 30 shards
- **Lines:** 2,396/2,484 matching (96.5%)
- **Avg test duration:** 9.9s — slowest: `acid/acid-large` (87.1s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m41s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.1s — slowest: `hitarea` (21.7s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 35s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 11.6s — slowest: `avm1_non_swf_import` (17.1s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 56s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 4.6s — slowest: `avm2_doaction` (8.2s)

### regression

- **Pass:** 104/104 (100%)
- **Duration:** 18m50s across 30 shards
- **Lines:** 871/871 matching (100%)
- **Avg test duration:** 10.8s — slowest: `avm2_static_and_store_slots` (42.9s)

### stage3d

- **Pass:** 7/8 (87.5%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 211/216 matching (97.7%)
- **Avg test duration:** 9.6s — slowest: `draw_to_bitmap_data_unconfigured` (21.5s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 55s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 7.8s — slowest: `convolution_filter_big_matrix` (16.7s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m06s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 15.5s — slowest: `text_caret_placement_leading` (30.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m10s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 18.2s — slowest: `frame_script_cleanup2` (29.2s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 28m22s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.2s — slowest: `definefont4` (68.7s)
