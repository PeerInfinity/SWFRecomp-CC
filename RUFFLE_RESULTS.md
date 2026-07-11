# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `f1d27c50cbbf`  
**Date:** 2026-07-11 19:59 UTC  
**Total duration:** 3h25m45s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 475 | 1201 | 39.6% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1510** | **2490** | **60.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,797 | 130,978 | 88.4% |
| avm2 | 51,414 | 149,021 | 34.5% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 260 | 260 | 100% |
| **Total** | **203,997** | **326,971** | **62.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 54 | - | 1 | - |
| avm2 | 699 | 14 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **800** | **14** | **1** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | place_object_same_depth_frame | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm2 | displayobject_rotation | 100% |
| avm2 | displayobject_alpha | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm2 | parse_int | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm2 | json_stringify | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | unescape | 89% |
| avm2 | interactiveobject_enabled | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | eventdispatcher_tostring | 80% |
| avm2 | indexing_delete | 80% |
| avm2 | issue_5292 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 64 | - | 5750 | - |

**avm2 — newly passing:** `amf_xml`, `bitmapdata_draw_cpu_overwrite_gpu`, `checkfilter`, `doabc_is_eager`, `edittext_always_show_selection`, `edittext_autosize_align`, `edittext_autosize_lazy_bounds_visual`, `flash_xml`, `flash_xml_cloneNode`, `flash_xml_namespace`, `flash_xml_removeNode`, `function_proto_created`, `issue_13780`, `number_autoconv`, `qname_as_lazy_name_attribute_multiname`, `xml_abstract_equality`, `xml_advanced`, `xml_appendchild`, `xml_as_attribute`, `xml_attribute`, `xml_attribute_name`, `xml_basic`, `xml_child`, `xml_childindex`, `xml_children`, `xml_class_call`, `xml_contains`, `xml_copy`, `xml_ctor_from_tostring`, `xml_delete`, `xml_descendants`, `xml_elements`, `xml_equals_namespace_check`, `xml_explicit_use_namespace`, `xml_getdescendants_qname`, `xml_has_property_via_in`, `xml_hasownproperty`, `xml_ignore_white`, `xml_length`, `xml_list_as_attribute`, `xml_list_concat`, `xml_list_enumerate`, `xml_methods_settings`, `xml_mismatched_tag`, `xml_namespace`, `xml_namespace_methods`, `xml_namespaced_property`, `xml_no_namespace`, `xml_nodekind`, `xml_normalize`, `xml_notification_bubbling`, `xml_parent`, `xml_set_children`, `xml_set_name`, `xml_settings`, `xml_simple_complex_content`, `xml_text`, `xml_tostring`, `xml_tostring_namespace`, `xml_unescaping`, `xml_weird_ignores`, `xml_wildcard`, `xmldocument`, `xmlnode`

*Comparing `241a84401c59` → `f1d27c50cbbf`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 49m12s across 30 shards
- **Lines:** 115,797/130,978 matching (88.4%)
- **Avg test duration:** 4.1s — slowest: `netstream_play_flv_screen` (35.6s)

### avm2

- **Pass:** 475/1201 (39.6%)
- **Duration:** 1h22m46s across 30 shards
- **Lines:** 51,414/149,021 matching (34.5%)
- **Avg test duration:** 4.1s — slowest: `away3d_advanced_shallow_water_demo` (63.0s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 26m06s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.4s — slowest: `MovieClip-v8` (68.6s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 18m50s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 10.1s — slowest: `matrix_test` (101.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.6s — slowest: `exception` (20.5s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m09s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 12.4s — slowest: `movieclip_destruction_test1` (21.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m47s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.3s — slowest: `tags_after_last_showframe` (21.0s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m28s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.7s — slowest: `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` (22.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.2s — slowest: `text-bind` (20.4s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 4m53s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 7.1s — slowest: `mc_event_cross_swf_version` (20.3s)
