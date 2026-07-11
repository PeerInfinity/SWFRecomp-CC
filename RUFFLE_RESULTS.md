# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `241a84401c59`  
**Date:** 2026-07-11 15:53 UTC  
**Total duration:** 3h30m45s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 411 | 1200 | 34.2% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1446** | **2489** | **58.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,797 | 130,978 | 88.4% |
| avm2 | 45,664 | 148,991 | 30.6% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 260 | 260 | 100% |
| **Total** | **198,247** | **326,941** | **60.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 54 | - | 1 | - |
| avm2 | 714 | 62 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 14 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **815** | **62** | **1** | **1** |

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
| avm2 | xml_has_property_via_in | 88% |
| avm2 | interactiveobject_enabled | 88% |
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
| avm2 | 58 | - | 1876 | - |

**avm2 — newly passing:** `amf_custom_obj`, `amf_dictionary`, `amf_function`, `amf_invalid_date`, `amf_missing_prop`, `amf_nondynamic_function_prop`, `amf_setter_error`, `amf_vector`, `bytearray`, `bytearray_compress`, `bytearray_errors`, `bytearray_method_serialization`, `bytearray_readobject_amf0`, `bytearray_readobject_amf3`, `bytearray_readutf8bytes_with_bom`, `bytearray_serialization`, `bytearray_string_null`, `bytearray_tostring`, `bytearray_utf16`, `bytearray_writeobject`, `class_call`, `coerce_to_primitive_side_effects`, `dictionary_access`, `dictionary_access_no_pubns`, `dictionary_delete`, `dictionary_foreach`, `dictionary_hasownproperty`, `dictionary_in`, `dictionary_iter_modify`, `dictionary_namespaces`, `dictionary_primitive_keys`, `error_tostring`, `fast_index_access`, `get_definition_by_name`, `get_qualified_class_name`, `namespace_constr`, `namespace_constr_args`, `namespace_enumeration_order`, `nested_iteration`, `net_getClassByAlias`, `number_autoconv_amf`, `proxy_callproperty`, `proxy_deleteproperty`, `proxy_enumeration`, `proxy_getproperty`, `proxy_hasownproperty`, `proxy_hasproperty`, `proxy_serialize`, `proxy_setproperty`, `qname_constr`, `qname_constr_namespace`, `qname_enumeration`, `qname_indexing`, `qname_tostring`, `qname_valueof`, `stage3d_sampler`, `stage3d_sampler_partial_upload`

*Comparing `9a21db62588e` → `241a84401c59`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 51m07s across 30 shards
- **Lines:** 115,797/130,978 matching (88.4%)
- **Avg test duration:** 4.3s — slowest: `netstream_play_flv_screen` (36.5s)

### avm2

- **Pass:** 411/1200 (34.2%)
- **Duration:** 1h23m43s across 30 shards
- **Lines:** 45,664/148,991 matching (30.6%)
- **Avg test duration:** 4.1s — slowest: `away3d_advanced_shallow_water_demo` (62.4s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 26m34s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.5s — slowest: `MovieClip-v8` (70.4s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 19m24s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 10.4s — slowest: `matrix_test` (107.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.0s — slowest: `implementsOpTest` (21.5s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m21s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 13.0s — slowest: `movieclip_destruction_test1` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m51s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.5s — slowest: `mixed-bytecode-as2` (20.9s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m58s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.1s — slowest: `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` (21.9s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.3s — slowest: `text-bind` (21.0s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 5m05s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 7.4s — slowest: `lv_cross_swf_version` (20.6s)
