# Ruffle Test Results Diff

**Previous:** `9a21db62588e` (2026-07-11T13:35:09.837402+00:00)
**Current:** `241a84401c59` (2026-07-11T15:53:02.565276+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 354 | 411 | +57 |
| Total | 1200 | 1200 | 0 |
| Pass rate | 29.5% | 34.2% | +4.7% |
| Mismatched lines | 105203 | 103327 | -1876 |
|   Decreased | | | -1876 |

## Newly Passing (57)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `amf_custom_obj` | output_mismatch | 1/26 | 26/26 |
| `amf_dictionary` | output_mismatch | 1/9 | 9/9 |
| `amf_function` | output_mismatch | 1/46 | 46/46 |
| `amf_invalid_date` | output_mismatch | 0/2 | 2/2 |
| `amf_missing_prop` | output_mismatch | 0/6 | 6/6 |
| `amf_nondynamic_function_prop` | output_mismatch | 0/6 | 6/6 |
| `amf_setter_error` | output_mismatch | 0/8 | 8/8 |
| `amf_vector` | output_mismatch | 0/40 | 40/40 |
| `bytearray` | output_mismatch | 0/48 | 48/48 |
| `bytearray_compress` | output_mismatch | 0/31 | 31/31 |
| `bytearray_errors` | output_mismatch | 0/24 | 24/24 |
| `bytearray_method_serialization` | output_mismatch | 0/1 | 1/1 |
| `bytearray_readobject_amf0` | output_mismatch | 0/50 | 50/50 |
| `bytearray_readobject_amf3` | output_mismatch | 0/53 | 53/53 |
| `bytearray_readutf8bytes_with_bom` | output_mismatch | 0/16 | 16/16 |
| `bytearray_serialization` | output_mismatch | 0/3 | 3/3 |
| `bytearray_string_null` | output_mismatch | 0/19 | 19/19 |
| `bytearray_tostring` | output_mismatch | 0/15 | 15/15 |
| `bytearray_utf16` | output_mismatch | 0/8 | 8/8 |
| `bytearray_writeobject` | output_mismatch | 1/24 | 24/24 |
| `class_call` | output_mismatch | 5/32 | 32/32 |
| `coerce_to_primitive_side_effects` | output_mismatch | 0/29 | 29/29 |
| `dictionary_access` | output_mismatch | 1/62 | 62/62 |
| `dictionary_access_no_pubns` | runtime_error | 0/2 | 2/2 |
| `dictionary_delete` | output_mismatch | 1/101 | 101/101 |
| `dictionary_foreach` | output_mismatch | 1/42 | 42/42 |
| `dictionary_hasownproperty` | output_mismatch | 1/63 | 63/63 |
| `dictionary_in` | output_mismatch | 1/62 | 62/62 |
| `dictionary_iter_modify` | output_mismatch | 3/8 | 8/8 |
| `dictionary_namespaces` | output_mismatch | 0/36 | 36/36 |
| `dictionary_primitive_keys` | output_mismatch | 1/29 | 29/29 |
| `error_tostring` | output_mismatch | 27/29 | 29/29 |
| `fast_index_access` | output_mismatch | 8/12 | 12/12 |
| `get_definition_by_name` | output_mismatch | 5/11 | 11/11 |
| `get_qualified_class_name` | output_mismatch | 1/20 | 20/20 |
| `namespace_constr` | runtime_error | 0/253 | 253/253 |
| `namespace_constr_args` | output_mismatch | 0/1 | 1/1 |
| `namespace_enumeration_order` | output_mismatch | 0/7 | 7/7 |
| `nested_iteration` | output_mismatch | 7/11 | 11/11 |
| `net_getClassByAlias` | output_mismatch | 0/3 | 3/3 |
| `number_autoconv_amf` | output_mismatch | 0/132 | 132/132 |
| `proxy_callproperty` | output_mismatch | 0/24 | 24/24 |
| `proxy_deleteproperty` | output_mismatch | 0/64 | 64/64 |
| `proxy_enumeration` | output_mismatch | 0/34 | 34/34 |
| `proxy_getproperty` | output_mismatch | 0/77 | 77/77 |
| `proxy_hasownproperty` | output_mismatch | 0/8 | 8/8 |
| `proxy_hasproperty` | output_mismatch | 0/32 | 32/32 |
| `proxy_serialize` | output_mismatch | 0/9 | 9/9 |
| `proxy_setproperty` | output_mismatch | 0/42 | 42/42 |
| `qname_constr` | output_mismatch | 1/32 | 32/32 |
| `qname_constr_namespace` | output_mismatch | 2/24 | 24/24 |
| `qname_enumeration` | output_mismatch | 1/9 | 9/9 |
| `qname_indexing` | output_mismatch | 0/23 | 23/23 |
| `qname_tostring` | output_mismatch | 1/25 | 25/25 |
| `qname_valueof` | output_mismatch | 1/29 | 29/29 |
| `stage3d_sampler` | runtime_error | 0/0 | 0/0 |
| `stage3d_sampler_partial_upload` | runtime_error | 0/0 | 0/0 |

## Status Changed (9)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `applicationdomain_getqualifieddefinitionnames` | runtime_error | output_mismatch | 0/8 | 0/8 |
| `bytearray_oom` | output_mismatch | timeout | 0/3 | - |
| `coerce_to_primitive_side_effects_with_nulls` | output_mismatch | ruffle_matched | 0/37 | 33/37 |
| `error_stack_trace` | runtime_error | output_mismatch | 9/45 | 13/45 |
| `large_preload_from_bytes` | runtime_error | output_mismatch | 0/51 | 0/51 |
| `large_preload_image_from_bytes` | runtime_error | output_mismatch | 0/25 | 0/25 |
| `qname_as_lazy_name_attribute_multiname` | output_mismatch | runtime_error | 0/1 | 0/1 |
| `stage3d_blend` | runtime_error | output_mismatch | 0/81 | 0/81 |
| `symbol_class_binary_data` | runtime_error | output_mismatch | 0/8 | 6/8 |

## Line Count Changed (14)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `indexing_delete` | output_mismatch | 0/75 | 60/75 | -60 |
| `error_tostring_more` | output_mismatch | 72/86 | 84/86 | -12 |
| `amf_array_serialization` | output_mismatch | 1/17 | 4/17 | -3 |
| `bom` | output_mismatch | 0/9 | 3/9 | -3 |
| `invalid_utf8` | output_mismatch | 0/12 | 3/12 | -3 |
| `xml_ctor_from_tostring` | output_mismatch | 0/23 | 3/23 | -3 |
| `amf_xml` | output_mismatch | 0/6 | 2/6 | -2 |
| `pixelbender_ceil` | output_mismatch | 0/77 | 1/77 | -1 |
| `pixelbender_eof` | output_mismatch | 0/7 | 1/7 | -1 |
| `pixelbender_sign` | output_mismatch | 0/60 | 1/60 | -1 |
| `static_length` | output_mismatch | 0/24 | 1/24 | -1 |
| `pixelbender_no_out_param` | output_mismatch | 0/6 | 0/6 | 0 |
| `pixelbender_parse_errors` | output_mismatch | 0/6 | 0/6 | 0 |
| `xml_methods_settings` | output_mismatch | 0/3 | 0/3 | 0 |
