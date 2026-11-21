# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9a970370e096`  
**Date:** 2026-11-21 21:08 UTC  
**Total duration:** 9h06m02s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 734 | 777 | 94.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1273 | 1335 | 95.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
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
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4374** | **4693** | **93.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 18 | 24 | 75.0% |
| avm1 | 124,876 | 137,510 | 90.8% |
| avm2 | 161,238 | 163,943 | 98.4% |
| fonts | 363 | 377 | 96.3% |
| from_avmplus | 85,568 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,712 | 38,791 | 79.2% |
| from_gnash/misc-ming.all | 4,252 | 5,248 | 81.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 486 | 580 | 83.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,407 | 2,484 | 96.9% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 57 | 79 | 72.2% |
| regression | 871 | 871 | 100% |
| stage3d | 216 | 216 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 979 | 979 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **413,596** | **438,744** | **94.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | 1 |
| avm1 | 21 |
| avm2 | 18 |
| fonts | - |
| from_avmplus | 2 |
| from_gnash/actionscript.all | 7 |
| from_gnash/misc-ming.all | 9 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 2 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 2 |
| from_shumway/avm1 | - |
| import_assets | - |
| mixed_avm | 1 |
| regression | - |
| stage3d | - |
| swf | - |
| text | - |
| timeline | - |
| visual | - |
| **Total** | **63** |

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
| avm1 | video_prototype_lazy | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 7 | - | 84 | - |
| avm2 | 21 | - | 3039 | - |
| fonts | 1 | - | 12 | - |
| from_gnash/misc-ming.all | 1 | - | 16 | - |
| from_shumway | 1 | - | 11 | - |
| stage3d | 1 | - | 5 | - |

**avm1 — newly passing:** `edittext_asfunction_case_insensitive`, `file_reference_listeners_per_instance`, `localconnection_reference_identity`, `localconnection_serialize_inherited_array_indices`, `shared_object_members_swf5`, `video_width_height`, `xml_status_mismatched_tags`

**avm2 — newly passing:** `amf_xmllist`, `array_constructor`, `array_join_reentrant`, `array_sort_arguments`, `context3d_draw_to_bitmap_data`, `displayobjectcontainer_remove_reentrant`, `displayobjectcontainer_remove_reparent`, `displayobjectcontainer_removechildren_events`, `edittext_set_text_same`, `error_stack_trace_class_names`, `error_stack_trace_limit`, `hit_test_scroll_rect`, `loaderinfo_root_progress`, `loaderinfo_root_progress_goto`, `shared_object_get_local_error`, `stage3d_missing_vertex_stream`, `textfield_get_text_format_args`, `textfield_set_text_format_args`, `vector_join_reentrant`, `vector_sort_arguments`

**fonts — newly passing:** `device_font_name_case`

**stage3d — newly passing:** `draw_to_bitmap_data_unconfigured`

*Comparing `c489b84d9946` → `9a970370e096`*

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

- **Pass:** 734/777 (94.5%)
- **Duration:** 50m44s across 30 shards
- **Lines:** 124,876/137,510 matching (90.8%)
- **Avg test duration:** 3.9s — slowest: `define_font_glyph_table_order` (37.0s)

### avm2

- **Pass:** 1273/1335 (95.4%)
- **Duration:** 3h02m50s across 30 shards
- **Lines:** 161,238/163,943 matching (98.4%)
- **Avg test duration:** 8.2s — slowest: `stage3d_raytrace` (80.9s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 2m23s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 15.9s — slowest: `device_font_glyph_fallback` (29.4s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 2h34m41s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 5.9s — slowest: `ecma3/Statements/eregress_74474_003` (68.3s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 21m05s across 30 shards
- **Lines:** 30,712/38,791 matching (79.2%)
- **Avg test duration:** 5.2s — slowest: `MovieClip-v8` (52.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 25m58s across 30 shards
- **Lines:** 4,252/5,248 matching (81.0%)
- **Avg test duration:** 14.0s — slowest: `matrix_test` (73.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 8.2s — slowest: `function_test` (17.9s)

### from_gnash/misc-swfc.all

- **Pass:** 13/20 (65.0%)
- **Duration:** 4m46s across 30 shards
- **Lines:** 486/580 matching (83.8%)
- **Avg test duration:** 14.3s — slowest: `action_execution_order_test10` (24.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m31s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 16.5s — slowest: `afunc_dict` (22.4s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 37m19s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 9.7s — slowest: `esc` (64.2s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 1.8s — slowest: `label` (16.7s)

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

- **Pass:** 104/104 (100%)
- **Duration:** 18m26s across 30 shards
- **Lines:** 871/871 matching (100%)
- **Avg test duration:** 10.6s — slowest: `avm2_typed_value_ops` (37.8s)

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
