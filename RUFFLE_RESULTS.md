# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `7e3a3a01481a`  
**Date:** 2026-07-11 13:16 UTC  
**Total duration:** 3h23m16s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 353 | 1199 | 29.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| **Total** | **1388** | **2488** | **55.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,797 | 130,978 | 88.4% |
| avm2 | 43,788 | 148,891 | 29.4% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,054 | 5,248 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 260 | 260 | 100% |
| **Total** | **196,371** | **326,841** | **60.1%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 54 | - | 1 |
| avm2 | 763 | 72 | - |
| from_gnash/actionscript.all | 13 | - | - |
| from_gnash/misc-ming.all | 14 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| regression | - | - | - |
| **Total** | **864** | **72** | **1** |

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
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | error_tostring | 93% |
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
| avm2 | error_tostring_more | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | eventdispatcher_tostring | 80% |
| avm2 | issue_5292 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 58 | 1 | 5234 | - |

**avm2 — newly passing:** `application_domain`, `array_vector_null_callback`, `constructprop_dynamic_primitive`, `error_prototype`, `event_bubbles`, `event_cancelable`, `event_type`, `eventdispatcher_dispatchevent_this`, `eventdispatcher_haseventlistener`, `findprop_global_prototype`, `function_unbound_this`, `json_errors`, `json_parse`, `primitive_edge_cases`, `prototype_set_null`, `regexp_constr`, `regexp_exec`, `regexp_extended`, `regexp_multiargs`, `regexp_test`, `regexp_toString`, `resolve_order`, `rng`, `string_match`, `string_replace`, `string_search`, `string_split`, `symbol_class_root_not_zero`, `try_catch`, `vector_class`, `vector_class_call`, `vector_coercion`, `vector_concat`, `vector_constr`, `vector_enumeration`, `vector_every`, `vector_filter`, `vector_holes`, `vector_indexof`, `vector_insertat`, `vector_int_access`, `vector_int_delete`, `vector_join`, `vector_lastindexof`, `vector_legacy`, `vector_map`, `vector_object_final`, `vector_object_toString`, `vector_pushpop`, `vector_reborrow_bug`, `vector_removeat`, `vector_reverse`, `vector_shiftunshift`, `vector_slice`, `vector_sort`, `vector_splice`, `vector_splice_fixed_bug_compat`, `vector_tostring`

**avm2 — newly failing:** `negative_volume_panned`

*Comparing `2ceede96204b` → `7e3a3a01481a`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 49m53s across 30 shards
- **Lines:** 115,797/130,978 matching (88.4%)
- **Avg test duration:** 4.2s — slowest: `netstream_play_flv_screen` (36.2s)

### avm2

- **Pass:** 353/1199 (29.4%)
- **Duration:** 1h19m31s across 30 shards
- **Lines:** 43,788/148,891 matching (29.4%)
- **Avg test duration:** 3.9s — slowest: `away3d_advanced_shallow_water_demo` (64.3s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 26m05s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.4s — slowest: `MovieClip-v8` (65.8s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 18m50s across 30 shards
- **Lines:** 4,054/5,248 matching (77.2%)
- **Avg test duration:** 10.1s — slowest: `matrix_test` (97.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.8s — slowest: `exception` (20.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m11s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 12.5s — slowest: `movieclip_destruction_test1` (21.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m41s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.0s — slowest: `registers` (20.6s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m47s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.9s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (22.1s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m39s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.1s — slowest: `text-bind` (18.1s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 4m48s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 7.0s — slowest: `coerce_cross_swf_version` (20.2s)
