# Ruffle Test Results Diff

**Previous:** `241a84401c59` (2026-07-11T15:53:02.565276+00:00)
**Current:** `f1d27c50cbbf` (2026-07-11T19:59:15.839872+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 411 | 475 | +64 |
| Total | 1200 | 1201 | +1 |
| Pass rate | 34.2% | 39.6% | +5.4% |
| Mismatched lines | 103327 | 97607 | -5720 |
|   Decreased | | | -5750 |

## Newly Passing (64)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `amf_xml` | output_mismatch | 2/6 | 6/6 |
| `bitmapdata_draw_cpu_overwrite_gpu` | runtime_error | 0/0 | 0/0 |
| `checkfilter` | runtime_error | 0/4 | 4/4 |
| `doabc_is_eager` | runtime_error | 0/1 | 1/1 |
| `edittext_always_show_selection` | runtime_error | 0/0 | 0/0 |
| `edittext_autosize_align` | runtime_error | 0/0 | 0/0 |
| `edittext_autosize_lazy_bounds_visual` | runtime_error | 0/0 | 0/0 |
| `flash_xml` | output_mismatch | 0/29 | 29/29 |
| `flash_xml_cloneNode` | output_mismatch | 0/22 | 22/22 |
| `flash_xml_namespace` | output_mismatch | 0/109 | 109/109 |
| `flash_xml_removeNode` | output_mismatch | 1/60 | 60/60 |
| `function_proto_created` | output_mismatch | 19/61 | 61/61 |
| `issue_13780` | output_mismatch | 0/12 | 12/12 |
| `number_autoconv` | output_mismatch | 15/21 | 21/21 |
| `qname_as_lazy_name_attribute_multiname` | runtime_error | 0/1 | 1/1 |
| `xml_abstract_equality` | output_mismatch | 0/36 | 36/36 |
| `xml_advanced` | output_mismatch | 0/52 | 52/52 |
| `xml_appendchild` | output_mismatch | 0/10 | 10/10 |
| `xml_as_attribute` | output_mismatch | 0/9 | 9/9 |
| `xml_attribute` | output_mismatch | 0/35 | 35/35 |
| `xml_attribute_name` | output_mismatch | 0/40 | 40/40 |
| `xml_basic` | output_mismatch | 0/32 | 32/32 |
| `xml_child` | output_mismatch | 0/25 | 25/25 |
| `xml_childindex` | output_mismatch | 0/7 | 7/7 |
| `xml_children` | output_mismatch | 0/43 | 43/43 |
| `xml_class_call` | output_mismatch | 0/9 | 9/9 |
| `xml_contains` | output_mismatch | 131/197 | 197/197 |
| `xml_copy` | output_mismatch | 0/20 | 20/20 |
| `xml_ctor_from_tostring` | output_mismatch | 3/23 | 23/23 |
| `xml_delete` | output_mismatch | 0/114 | 114/114 |
| `xml_descendants` | runtime_error | 0/83 | 83/83 |
| `xml_elements` | output_mismatch | 0/6 | 6/6 |
| `xml_equals_namespace_check` | output_mismatch | 1/2 | 2/2 |
| `xml_explicit_use_namespace` | runtime_error | 0/5 | 5/5 |
| `xml_getdescendants_qname` | runtime_error | 1/21 | 21/21 |
| `xml_has_property_via_in` | output_mismatch | 23/26 | 26/26 |
| `xml_hasownproperty` | output_mismatch | 4/6 | 6/6 |
| `xml_ignore_white` | output_mismatch | 0/6 | 6/6 |
| `xml_length` | output_mismatch | 0/2 | 2/2 |
| `xml_list_as_attribute` | output_mismatch | 0/9 | 9/9 |
| `xml_list_concat` | output_mismatch | 1/20 | 20/20 |
| `xml_list_enumerate` | output_mismatch | 0/4 | 4/4 |
| `xml_methods_settings` | output_mismatch | 0/3 | 3/3 |
| `xml_mismatched_tag` | output_mismatch | 17/37 | 37/37 |
| `xml_namespace` | output_mismatch | 0/39 | 39/39 |
| `xml_namespace_methods` | output_mismatch | 0/245 | 245/245 |
| `xml_namespaced_property` | output_mismatch | 0/7 | 7/7 |
| `xml_no_namespace` | output_mismatch | 0/1 | 1/1 |
| `xml_nodekind` | output_mismatch | 0/3 | 3/3 |
| `xml_normalize` | output_mismatch | 0/35 | 35/35 |
| `xml_notification_bubbling` | output_mismatch | 0/361 | 361/361 |
| `xml_parent` | output_mismatch | 0/8 | 8/8 |
| `xml_set_children` | output_mismatch | 0/17 | 17/17 |
| `xml_set_name` | output_mismatch | 0/34 | 34/34 |
| `xml_settings` | output_mismatch | 0/6 | 6/6 |
| `xml_simple_complex_content` | output_mismatch | 0/47 | 47/47 |
| `xml_text` | output_mismatch | 0/7 | 7/7 |
| `xml_tostring` | output_mismatch | 0/6 | 6/6 |
| `xml_tostring_namespace` | output_mismatch | 1/12 | 12/12 |
| `xml_unescaping` | output_mismatch | 0/23 | 23/23 |
| `xml_weird_ignores` | output_mismatch | 0/54 | 54/54 |
| `xml_wildcard` | output_mismatch | 0/11 | 11/11 |
| `xmldocument` | output_mismatch | 0/254 | 254/254 |
| `xmlnode` | output_mismatch | 0/3540 | 3540/3540 |

## Status Changed (40)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `core_exceptions` | runtime_error | output_mismatch | 9/47 | 41/47 |
| `edittext_at_point_methods_basic` | runtime_error | output_mismatch | 0/16 | 0/16 |
| `edittext_autosize_height_dynamic` | runtime_error | output_mismatch | 0/60 | 0/60 |
| `edittext_autosize_height_input` | runtime_error | output_mismatch | 0/60 | 0/60 |
| `edittext_autosize_lazy_bounds_props` | runtime_error | output_mismatch | 0/490 | 0/490 |
| `edittext_autosize_lazy_bounds_vs_relayout` | runtime_error | output_mismatch | 0/106 | 0/106 |
| `edittext_bottom_scroll_v_basic` | runtime_error | output_mismatch | 0/210 | 0/210 |
| `edittext_device_transform_layout` | runtime_error | output_mismatch | 0/288 | 0/288 |
| `edittext_empty_text_format` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `edittext_get_char_index_at_point` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `edittext_get_line_index_at_point` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `edittext_get_line_index_of_char` | runtime_error | output_mismatch | 0/76 | 0/76 |
| `edittext_getcharboundaries` | runtime_error | output_mismatch | 0/172 | 0/172 |
| `edittext_getcharboundaries_culling` | runtime_error | output_mismatch | 0/305 | 0/305 |
| `edittext_getcharboundaries_missing_glyphs` | runtime_error | output_mismatch | 0/63 | 0/63 |
| `edittext_getcharboundaries_scroll` | runtime_error | output_mismatch | 0/85 | 0/85 |
| `edittext_line_methods` | runtime_error | output_mismatch | 0/294 | 0/294 |
| `edittext_line_metrics` | runtime_error | output_mismatch | 0/11 | 0/11 |
| `edittext_max_scroll_h_basic` | runtime_error | output_mismatch | 0/475 | 0/475 |
| `edittext_max_scroll_v_basic` | runtime_error | output_mismatch | 0/1000 | 0/1000 |
| `edittext_mouse_selection` | runtime_error | output_mismatch | 0/363 | 0/363 |
| `edittext_wordwrap_word` | runtime_error | output_mismatch | 0/150 | 0/150 |
| `edittext_wrap_breaks` | runtime_error | output_mismatch | 0/2375 | 0/2375 |
| `font_enumeratefonts_filter` | runtime_error | output_mismatch | 0/4 | 0/4 |
| `font_enumeratefonts_order` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `mouse_wheel_events` | runtime_error | output_mismatch | 0/36 | 0/36 |
| `null_void_types` | output_mismatch | runtime_error | 0/8 | 0/8 |
| `pixelbender_conversions` | runtime_error | output_mismatch | 0/270 | 1/270 |
| `pixelbender_div` | runtime_error | output_mismatch | 0/36 | 1/36 |
| `pixelbender_input` | runtime_error | output_mismatch | 0/103 | 0/103 |
| `pixelbender_malformed_data` | runtime_error | output_mismatch | 0/190 | 0/190 |
| `pixelbender_parameters` | runtime_error | output_mismatch | 0/1563 | 1/1563 |
| `pixelbender_parameters_bool` | runtime_error | output_mismatch | 0/240 | 0/240 |
| `pixelbender_parameters_int_vs_bool` | runtime_error | output_mismatch | 0/54 | 0/54 |
| `pixelbender_rsqrt` | runtime_error | output_mismatch | 0/24 | 1/24 |
| `pixelbender_shaderdata_setter` | runtime_error | output_mismatch | 0/99 | 3/99 |
| `pixelbender_vector_output` | runtime_error | output_mismatch | 0/11 | 1/11 |
| `property_priority_scope_cache_order` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `sound_load_multiple` | runtime_error | output_mismatch | 0/19 | 0/19 |
| `textline_splitting_basic` | runtime_error | output_mismatch | 0/76 | 0/76 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `textline_throwerror` | output_mismatch | 0/30 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `xml_appendchild_swf_v21` | output_mismatch | 0/13 | 7/13 | -7 |
| `static_length` | output_mismatch | 1/24 | 3/24 | -2 |
| `describe_type_basic` | output_mismatch | 0/152 | 1/152 | -1 |
| `describe_type_json` | output_mismatch | 0/301 | 1/301 | -1 |
| `describe_type_metadata` | output_mismatch | 0/125 | 0/125 | 0 |
| `describe_type_native` | output_mismatch | 0/23 | 0/23 | 0 |
