# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9a970370e096`  
**Date:** 2026-11-21 20:48 UTC  
**Total duration:** 12h05m53s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics.md) |
| avm1 | 734 | 777 | 94.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 1273 | 1335 | 95.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| fonts | 8 | 9 | 88.9% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics.md) |
| from_avmplus | 1533 | 1574 | 97.4% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics.md) |
| from_gnash/actionscript.all | 148 | 243 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 13 | 20 | 65.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 214 | 229 | 93.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics.md) |
| regression | 104 | 104 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| stage3d | 8 | 8 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics.md) |
| text | 12 | 12 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics.md) |
| visual | 149 | 151 | 98.7% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics.md) |
| **Total** | **4375** | **4693** | **93.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 24 | 24 | 100% |
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
| **Total** | **413,602** | **438,744** | **94.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| audio | - |
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
| **Total** | **62** |

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

## Per-Suite Details

### audio

- **Pass:** 5/5 (100%)
- **Duration:** 1m19s across 30 shards
- **Lines:** 24/24 matching (100%)
- **Avg test duration:** 15.8s — slowest: `stream_incomplete_loop` (23.4s)

### avm1

- **Pass:** 734/777 (94.5%)
- **Duration:** 1h19m08s across 30 shards
- **Lines:** 124,876/137,510 matching (90.8%)
- **Avg test duration:** 6.1s — slowest: `define_font_glyph_table_order` (40.7s)

### avm2

- **Pass:** 1273/1335 (95.4%)
- **Duration:** 4h00m49s across 30 shards
- **Lines:** 161,238/163,943 matching (98.4%)
- **Avg test duration:** 10.8s — slowest: `away3d_advanced_shallow_water_demo` (84.1s)

### fonts

- **Pass:** 8/9 (88.9%)
- **Duration:** 3m06s across 30 shards
- **Lines:** 363/377 matching (96.3%)
- **Avg test duration:** 20.6s — slowest: `device_font_kerning` (33.8s)

### from_avmplus

- **Pass:** 1533/1574 (97.4%)
- **Duration:** 3h20m23s across 30 shards
- **Lines:** 85,568/85,996 matching (99.5%)
- **Avg test duration:** 7.6s — slowest: `ecma3/Statements/eregress_74474_003` (56.6s)

### from_gnash/actionscript.all

- **Pass:** 148/243 (60.9%)
- **Duration:** 30m14s across 30 shards
- **Lines:** 30,712/38,791 matching (79.2%)
- **Avg test duration:** 7.4s — slowest: `MovieClip-v8` (53.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 32m18s across 30 shards
- **Lines:** 4,252/5,248 matching (81.0%)
- **Avg test duration:** 17.4s — slowest: `matrix_test` (83.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.8s — slowest: `inheritance` (23.8s)

### from_gnash/misc-swfc.all

- **Pass:** 13/20 (65.0%)
- **Duration:** 5m30s across 30 shards
- **Lines:** 486/580 matching (83.8%)
- **Avg test duration:** 16.5s — slowest: `action_execution_order_test10` (24.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m35s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.7s — slowest: `func_dict` (23.2s)

### from_shumway

- **Pass:** 214/229 (93.4%)
- **Duration:** 46m55s across 30 shards
- **Lines:** 2,407/2,484 matching (96.9%)
- **Avg test duration:** 12.3s — slowest: `acid/acid-large` (87.4s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m19s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.9s — slowest: `hitarea` (23.2s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 15.8s — slowest: `avm1_non_swf_import` (23.8s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m30s across 30 shards
- **Lines:** 57/79 matching (72.2%)
- **Avg test duration:** 7.5s — slowest: `avm1_sprite_sc_ignored` (17.3s)

### regression

- **Pass:** 104/104 (100%)
- **Duration:** 26m37s across 30 shards
- **Lines:** 871/871 matching (100%)
- **Avg test duration:** 15.3s — slowest: `avm2_external_interface_unavailable` (54.4s)

### stage3d

- **Pass:** 8/8 (100%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 216/216 matching (100%)
- **Avg test duration:** 13.1s — slowest: `draw_to_bitmap_data_unconfigured` (29.9s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 10.1s — slowest: `lzma_length_too_long` (23.1s)

### text

- **Pass:** 12/12 (100%)
- **Duration:** 3m47s across 30 shards
- **Lines:** 979/979 matching (100%)
- **Avg test duration:** 18.9s — slowest: `auto_size/return` (34.1s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 5m57s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 21.0s — slowest: `frame_script_cleanup_goto` (31.3s)

### visual

- **Pass:** 149/151 (98.7%)
- **Duration:** 33m40s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 13.3s — slowest: `definefont4` (89.8s)
