# Ruffle Test Results (Unfiltered)

**Date**: 2026-02-20 00:50 UTC

**Git SHA**: `3459c6f850`

**Run Duration**: 79m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 619 |
| Passing | **182** (29.4%) |
| Failing | 437 |
| Total expected lines | 56628 |
| Matching lines | 36078 (63.7%) |
| Mismatched lines | 20550 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Runtime Segfault | 199 | 45.5% |
| Output Mismatch | 195 | 44.6% |
| Runtime Error | 41 | 9.4% |
| Timeout | 2 | 0.5% |

## Passing Tests

**182 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `access_unnamed_shape` | 1 | 7.4s |  |
| 2 | `action_to_integer` | 28 | 6.7s |  |
| 3 | `add` | 28 | 6.7s |  |
| 4 | `add2` | 354 | 6.9s | [1](ruffle-tests/_investigation/incomplete/add2.md) |
| 5 | `add_swf4` | 28 | 6.7s |  |
| 6 | `add_swf5` | 28 | 6.7s |  |
| 7 | `arguments` | 127 | 6.7s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 8 | `array_call_method` | 9 | 6.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 9 | `array_concat` | 98 | 6.7s |  |
| 10 | `array_constructor` | 30 | 6.7s |  |
| 11 | `array_enumerate` | 4 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 12 | `array_length` | 42 | 6.7s |  |
| 13 | `array_properties` | 36 | 6.7s |  |
| 14 | `array_prototyping` | 12 | 6.7s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 15 | `array_slice` | 34 | 6.7s |  |
| 16 | `array_splice` | 207 | 7.0s |  |
| 17 | `array_trivial` | 209 | 6.9s |  |
| 18 | `as1_constructor_v6` | 35 | 6.7s |  |
| 19 | `as1_constructor_v7` | 35 | 6.7s |  |
| 20 | `as2_oop` | 13 | 6.8s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 21 | `as_broadcaster_initialize` | 10 | 6.7s |  |
| 22 | `as_set_prop_flags_version` | 31 | 6.7s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 23 | `as_set_prop_flags_version_swf5` | 1 | 6.7s |  |
| 24 | `as_set_prop_flags_version_swf6` | 1 | 6.7s |  |
| 25 | `as_set_prop_flags_version_swf7` | 1 | 6.7s |  |
| 26 | `as_set_prop_flags_version_swf8` | 1 | 6.7s |  |
| 27 | `as_set_prop_flags_version_swf9` | 1 | 6.7s |  |
| 28 | `bad_swf_tag_past_eof` | 0 | 6.7s |  |
| 29 | `bitand` | 1058 | 9.3s |  |
| 30 | `bitmap_data_colortransform` | 0 | 6.9s |  |
| 31 | `bitmap_data_fillrect` | 0 | 6.8s |  |
| 32 | `bitmap_data_max_size_swf10` | 12 | 6.7s |  |
| 33 | `bitmap_data_max_size_swf9` | 10 | 6.7s |  |
| 34 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.8s |  |
| 35 | `bitor` | 1058 | 9.2s |  |
| 36 | `biturshift` | 14 | 9.8s |  |
| 37 | `biturshift_swf8` | 14 | 6.8s |  |
| 38 | `bitxor` | 1058 | 9.5s |  |
| 39 | `call_method_empty_name` | 1 | 7.0s |  |
| 40 | `capabilities_resolution` | 8 | 7.0s |  |
| 41 | `catch_references_registers` | 2 | 6.9s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 42 | `color_transform` | 48 | 6.9s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 43 | `define_function2` | 8 | 6.8s |  |
| 44 | `define_function2_preload` | 13 | 6.7s |  |
| 45 | `define_function_case_sensitive` | 2 | 6.8s |  |
| 46 | `delete` | 3 | 6.7s |  |
| 47 | `divide_swf4` | 107 | 6.8s |  |
| 48 | `enumerate` | 64 | 6.6s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 49 | `equals` | 32 | 6.6s |  |
| 50 | `equals2_swf5` | 926 | 8.4s |  |
| 51 | `equals2_swf6` | 926 | 8.4s |  |
| 52 | `equals2_swf7` | 926 | 8.4s |  |
| 53 | `equals_swf4` | 665 | 7.1s |  |
| 54 | `equals_swf4_alt` | 32 | 6.6s |  |
| 55 | `equals_swf5` | 32 | 6.6s |  |
| 56 | `error` | 58 | 6.7s |  |
| 57 | `escape` | 14 | 6.6s |  |
| 58 | `get_variable_in_scope` | 29 | 6.6s |  |
| 59 | `getproperty` | 28 | 6.7s |  |
| 60 | `getproperty_swf4` | 28 | 6.5s |  |
| 61 | `getproperty_swf5` | 28 | 6.6s |  |
| 62 | `global_array` | 3 | 6.5s |  |
| 63 | `global_is_bare` | 7 | 6.5s |  |
| 64 | `globals_swf5` | 304 | 6.8s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 65 | `globals_swf6` | 304 | 6.8s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 66 | `globals_swf7` | 304 | 6.8s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 67 | `globals_swf8` | 304 | 6.8s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 68 | `goto_execution_order` | 2 | 6.7s |  |
| 69 | `greater_swf6` | 1175 | 8.7s |  |
| 70 | `greater_swf7` | 1175 | 8.7s |  |
| 71 | `greaterthan_swf5` | 1 | 6.6s |  |
| 72 | `greaterthan_swf8` | 1 | 6.6s |  |
| 73 | `has_own_property` | 32 | 6.6s |  |
| 74 | `infinite_recursion_function` | 4 | 6.7s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 75 | `infinite_recursion_function_in_setter` | 131 | 6.7s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 76 | `infinite_recursion_virtual_property` | 67 | 6.6s | [11](ruffle-tests/_investigation/complete/infinite_recursion_function.md) |
| 77 | `init_array_invalid` | 4 | 6.6s |  |
| 78 | `init_object_invalid` | 4 | 6.6s |  |
| 79 | `is_finite` | 49 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 80 | `is_finite_swf6` | 49 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 81 | `is_prototype_of` | 89 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 82 | `issue_1086` | 1 | 6.6s |  |
| 83 | `issue_2166` | 9 | 6.7s |  |
| 84 | `issue_710` | 4 | 6.7s |  |
| 85 | `issue_768` | 3 | 6.6s | [12](ruffle-tests/_investigation/incomplete/issue_768.md) |
| 86 | `lessthan` | 41 | 6.6s |  |
| 87 | `lessthan2_swf5` | 1226 | 8.7s |  |
| 88 | `lessthan2_swf6` | 1226 | 8.8s |  |
| 89 | `lessthan2_swf7` | 1226 | 8.8s |  |
| 90 | `lessthan_swf4` | 902 | 7.3s |  |
| 91 | `lessthan_swf4_alt` | 41 | 6.6s |  |
| 92 | `lessthan_swf5` | 41 | 6.7s |  |
| 93 | `logical_ops_swf4` | 90 | 6.6s |  |
| 94 | `logical_ops_swf8` | 108 | 6.6s |  |
| 95 | `looping` | 6 | 6.6s |  |
| 96 | `math_min_max` | 101 | 6.9s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 97 | `matrix` | 171 | 7.1s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 98 | `mouse_wheel_enabled` | 2 | 6.6s |  |
| 99 | `movieclip_begin_gradient_fill` | 0 | 7.0s |  |
| 100 | `movieclip_line_gradient_style` | 0 | 7.3s |  |
| 101 | `movieclip_prototype_extension` | 5 | 7.0s |  |
| 102 | `nested_textfields_in_buttons` | 0 | 7.0s |  |
| 103 | `new_method_wrap` | 4 | 6.8s |  |
| 104 | `new_object_enumerate` | 7 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 105 | `new_object_wrap` | 4 | 6.8s |  |
| 106 | `o` | 3 | 7.1s |  |
| 107 | `object_constructor` | 33 | 6.8s |  |
| 108 | `object_function` | 32 | 6.9s |  |
| 109 | `object_properties` | 31 | 7.1s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 110 | `object_prototypes` | 74 | 7.1s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 111 | `object_string_coerce_swf5` | 62 | 7.4s | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 112 | `parse_int` | 64 | 6.8s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 113 | `point` | 175 | 7.2s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 114 | `primitive_instanceof` | 37 | 6.6s |  |
| 115 | `primitive_type_globals` | 557 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 116 | `prototype_delete` | 12 | 6.9s |  |
| 117 | `prototype_enumerate` | 5 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 118 | `prototype_properties` | 17 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 119 | `rectangle` | 745 | 7.7s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 120 | `recursive_prototypes` | 0 | 6.9s |  |
| 121 | `sandbox_type_local_file` | 1 | 6.5s |  |
| 122 | `single_frame` | 1 | 6.6s |  |
| 123 | `sound_start_load` | 0 | 6.5s |  |
| 124 | `stage_object_properties_get_var` | 5 | 6.6s |  |
| 125 | `stage_property_representation` | 586 | 6.6s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 126 | `strictequals_swf6` | 902 | 8.0s |  |
| 127 | `strictly_equals` | 7 | 6.5s |  |
| 128 | `string_coercion` | 117 | 6.8s | [25](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 129 | `string_methods` | 285 | 7.0s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 130 | `string_methods_swfv5` | 275 | 7.1s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 131 | `string_ops_swf6` | 95 | 6.5s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 132 | `string_paths_keyevents` | 0 | 6.6s |  |
| 133 | `string_paths_timer` | 0 | 6.5s |  |
| 134 | `swf4_actions_bool` | 96 | 6.7s |  |
| 135 | `swf4_bool` | 4 | 6.6s |  |
| 136 | `swf4_function_calls` | 7 | 8.9s |  |
| 137 | `swf5_encoding` | 3 | 6.7s |  |
| 138 | `tab_ordering_properties_tab_index_edge_case` | 4 | 6.7s |  |
| 139 | `text_format` | 1146 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 140 | `text_format_display` | 21 | 6.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 141 | `text_format_font_max_length` | 2 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 142 | `text_format_rounding_swf7` | 840 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 143 | `text_format_rounding_swf8` | 840 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 144 | `textfield_maxchars` | 3 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 145 | `textfield_props_swf6` | 210 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 146 | `textfield_props_swf7` | 210 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 147 | `textfield_props_swf8` | 210 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 148 | `this_swf7` | 41 | 6.7s | [29](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 149 | `timeline_function_def` | 7 | 6.7s |  |
| 150 | `try_catch_finally` | 118 | 7.2s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 151 | `try_finally_simple` | 16 | 6.8s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 152 | `typeof_globals` | 7 | 6.8s |  |
| 153 | `uncaught_exception` | 1 | 6.8s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 154 | `uncaught_exception_bubbled` | 1 | 6.8s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 155 | `undefined_to_string_swf6` | 4 | 6.7s |  |
| 156 | `unescape` | 43 | 6.8s |  |
| 157 | `watch` | 117 | 7.1s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 158 | `with_return` | 2 | 6.8s |  |
| 159 | `with_variable_scopes` | 43 | 6.9s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 160 | `xml` | 15 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 161 | `xml_append_child` | 28 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 162 | `xml_append_child_with_parent` | 20 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 163 | `xml_cdata` | 11 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 164 | `xml_child_nodes_edge_cases` | 4 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 165 | `xml_clone_expandos` | 19 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 166 | `xml_first_last_child` | 8 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 167 | `xml_has_child_nodes` | 3 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 168 | `xml_idmap` | 21 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 169 | `xml_ignore_comments` | 21 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 170 | `xml_ignore_white` | 34 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 171 | `xml_insert_before` | 20 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 172 | `xml_inspect_createmethods` | 15 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 173 | `xml_inspect_doctype` | 7 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 174 | `xml_inspect_parsexml` | 62 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 175 | `xml_inspect_xmldecl` | 7 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 176 | `xml_namespaces` | 203 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 177 | `xml_parent_and_child` | 5 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 178 | `xml_remove_node` | 22 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 179 | `xml_siblings` | 10 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 180 | `xml_to_string` | 13 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 181 | `xml_to_string_comment` | 1 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 182 | `xmlnode_proto` | 1 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**42 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `date` | 99.2% | 6284 | 6335 | 51 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `array_sort` | 98.1% | 158 | 161 | 3 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 4 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 5 | `add_property` | 73.3% | 11 | 15 | 4 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `attach_movie` | 72.9% | 43 | 59 | 16 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 8 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 9 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 10 | `register_underflow` | 69.2% | 18 | 26 | 8 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 11 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 12 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `export_assets` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 14 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 15 | `mouse_listeners` | 66.2% | 45 | 68 | 23 |  |
| 16 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 18 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 20 | `bitmap_data_threshold` | 59.1% | 104 | 176 | 72 |  |
| 21 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 22 | `parse_float` | 58.1% | 43 | 74 | 31 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 23 | `bitmapdata_channels` | 57.9% | 11 | 19 | 8 |  |
| 24 | `asnative` | 55.9% | 19 | 34 | 15 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 25 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 26 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 27 | `xml_getbytes` | 52.9% | 9 | 17 | 8 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 28 | `bitmap_data_noise` | 52.9% | 334 | 631 | 297 |  |
| 29 | `bitmap_data_compare` | 52.5% | 21 | 40 | 19 |  |
| 30 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 31 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 32 | `bad_placeobject_clipaction` | 50.0% | 1 | 2 | 1 |  |
| 33 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 35 | `loadmovie` | 50.0% | 1 | 2 | 1 |  |
| 36 | `loadmovie_method` | 50.0% | 1 | 2 | 1 |  |
| 37 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 38 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 39 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 40 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |
| 41 | `unloadmovie` | 50.0% | 2 | 4 | 2 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 42 | `xml_attributes_read` | 50.0% | 2 | 4 | 2 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Segfaults

**199 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `as_transformed_flag` | 8.5s |  |
| 2 | `asfunction` | 8.5s |  |
| 3 | `bitmap_filters` | 8.4s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 4 | `button_children` | 8.9s |  |
| 5 | `button_goto` | 9.0s |  |
| 6 | `button_key_events` | 9.2s |  |
| 7 | `button_key_events_special` | 9.9s |  |
| 8 | `button_keypress_vs_press` | 9.2s |  |
| 9 | `button_keypress_vs_tab` | 9.3s |  |
| 10 | `button_keypress_vs_textinput` | 9.2s |  |
| 11 | `button_properties_special_cases` | 9.1s |  |
| 12 | `call` | 9.3s |  |
| 13 | `click_block` | 9.0s |  |
| 14 | `clip_events` | 9.3s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 15 | `clone_sprite_edittext` | 9.3s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 16 | `clone_sprite_types` | 9.2s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 17 | `closure_scope` | 9.1s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 18 | `color` | 9.0s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 19 | `conflicting_instance_names` | 8.7s |  |
| 20 | `custom_clip_methods` | 8.8s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 21 | `default_names` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 22 | `define_function2_preload_order` | 8.7s |  |
| 23 | `device_font_spacing` | 8.8s |  |
| 24 | `display_object_properties` | 8.6s |  |
| 25 | `do_init_action` | 8.7s |  |
| 26 | `drag_drop` | 8.7s |  |
| 27 | `duplicate_movie_clip` | 8.7s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 28 | `edittext_align` | 8.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_antialiastype` | 9.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_autosize` | 8.4s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_autosize_setter` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_bullet` | 8.3s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_default_format` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_default_format_empty` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_default_format_font_style` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_drag_select` | 8.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_font_size` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_html_align_swf7` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_html_align_swf8` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_html_condensewhite_swf7` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_html_condensewhite_swf8` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_html_entity` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_html_swf6` | 8.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_html_swf7` | 9.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_html_swf8` | 9.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_input` | 8.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `edittext_input_newlines` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 48 | `edittext_leading` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `edittext_letter_spacing` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 50 | `edittext_margins` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `edittext_newline_stripping` | 13.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 52 | `edittext_newlines` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 53 | `edittext_password` | 8.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 54 | `edittext_password_copy` | 8.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `edittext_paste_empty` | 8.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 56 | `edittext_place_caret` | 8.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 57 | `edittext_programmatic_focus` | 8.0s | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 58 | `edittext_restrict` | 8.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `edittext_restrict_paste` | 8.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 60 | `edittext_scroll` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 61 | `edittext_tab_focus` | 8.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 62 | `edittext_tab_stops` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 63 | `edittext_tag_indent` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 64 | `edittext_underline` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `edittext_width_height` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `execution_order1` | 8.0s |  |
| 67 | `execution_order2` | 8.1s |  |
| 68 | `execution_order3` | 8.0s |  |
| 69 | `execution_order4` | 8.1s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 70 | `extends_native_type` | 8.1s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 71 | `focus_keyboard_press` | 8.7s |  |
| 72 | `focus_mouse` | 8.6s |  |
| 73 | `focus_mouse_rollout` | 8.7s |  |
| 74 | `focus_root_movie` | 8.7s |  |
| 75 | `focusrect_focuslost` | 8.5s |  |
| 76 | `focusrect_mouse_swf8` | 8.6s |  |
| 77 | `focusrect_mouse_swf9` | 8.6s |  |
| 78 | `focusrect_property_swf5` | 8.8s |  |
| 79 | `focusrect_property_swf6` | 8.7s |  |
| 80 | `focusrect_property_swf7` | 8.8s |  |
| 81 | `focusrect_swf5` | 8.8s |  |
| 82 | `focusrect_swf6` | 8.6s |  |
| 83 | `frame_size_translated_negative` | 8.5s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 84 | `frame_size_translated_positive` | 8.6s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 85 | `function_base_clip` | 8.6s |  |
| 86 | `function_base_clip_readded` | 8.6s |  |
| 87 | `function_base_clip_removed` | 8.6s |  |
| 88 | `funky_function_calls` | 8.7s |  |
| 89 | `get_bytes_total` | 8.6s |  |
| 90 | `goto_advance1` | 8.5s |  |
| 91 | `goto_advance2` | 8.7s |  |
| 92 | `goto_both_ways1` | 9.0s |  |
| 93 | `goto_both_ways2` | 8.9s |  |
| 94 | `goto_execution_order2` | 8.7s |  |
| 95 | `goto_frame` | 8.8s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 96 | `goto_frame2` | 9.1s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 97 | `goto_frame_number` | 8.8s |  |
| 98 | `goto_label` | 8.9s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 99 | `goto_methods` | 8.7s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 100 | `goto_rewind1` | 8.9s |  |
| 101 | `goto_rewind2` | 8.7s |  |
| 102 | `goto_rewind3` | 8.7s |  |
| 103 | `hittest_morph` | 8.7s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 104 | `hittest_morph_input` | 8.6s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 105 | `input_dead_keys_windows` | 8.8s |  |
| 106 | `issue_1104` | 8.6s |  |
| 107 | `issue_1671` | 8.7s |  |
| 108 | `issue_1906` | 8.8s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 109 | `issue_2870` | 8.7s |  |
| 110 | `issue_3446` | 8.6s |  |
| 111 | `issue_3522` | 8.6s |  |
| 112 | `issue_4377` | 8.6s |  |
| 113 | `issue_9885` | 8.7s |  |
| 114 | `loadmovie_replace_root` | 8.6s |  |
| 115 | `loadvariables_method` | 8.5s |  |
| 116 | `local_to_global` | 8.8s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 117 | `mask_reapply` | 8.6s |  |
| 118 | `mask_with_drawing` | 8.8s |  |
| 119 | `mouse_events` | 8.6s |  |
| 120 | `mouse_events_visible_enabled` | 8.7s |  |
| 121 | `mouse_pos` | 8.5s |  |
| 122 | `mouse_pos_with_scale_factor` | 8.6s |  |
| 123 | `movieclip_blend_mode_property` | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 124 | `movieclip_depth_methods` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 125 | `movieclip_get_instance_at_depth` | 8.5s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 126 | `movieclip_getbounds` | 8.8s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 127 | `movieclip_gettextsnapshot` | 8.8s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 128 | `movieclip_hittest` | 8.7s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 129 | `movieclip_hittest_shapeflag` | 9.9s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 130 | `movieclip_in_removed_button` | 8.5s |  |
| 131 | `movieclip_name_from_timeline` | 8.9s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 132 | `native_objects_swf6` | 9.3s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 133 | `native_objects_swf7` | 9.3s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 134 | `native_objects_swf8` | 9.3s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 135 | `netstream_play_flv` | 8.9s |  |
| 136 | `netstream_play_flv_screen` | 23.4s |  |
| 137 | `on_construct` | 8.9s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 138 | `path_string` | 8.8s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 139 | `place_and_lookup` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 140 | `register_and_init_order` | 9.2s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 141 | `remove_movie_clip` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 142 | `removed_base_clip_tell_target` | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 143 | `removed_clip_halts_script` | 9.3s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 144 | `rewind_depth` | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 145 | `root_global_parent` | 8.7s |  |
| 146 | `selection` | 8.7s | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 147 | `selection_handlers` | 8.6s | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 148 | `set_variable_scope` | 8.5s |  |
| 149 | `slash_syntax` | 8.7s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 150 | `sound` | 8.8s |  |
| 151 | `stage_object_children` | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 152 | `stage_object_enumerate` | 8.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 153 | `stage_object_properties` | 9.0s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 154 | `stage_object_properties_swf6` | 8.8s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 155 | `string_paths_hidden` | 8.6s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 156 | `swf5_no_closure` | 8.7s |  |
| 157 | `swf5_to_6_cross_call` | 8.8s |  |
| 158 | `swf6_case_insensitive` | 8.6s |  |
| 159 | `swf6_to_5_cross_call` | 8.6s |  |
| 160 | `swf7_case_sensitive` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 161 | `tab_ordering_automatic_basic` | 8.7s |  |
| 162 | `tab_ordering_automatic_order_grid` | 8.7s |  |
| 163 | `tab_ordering_automatic_order_same_position` | 8.7s |  |
| 164 | `tab_ordering_children` | 8.8s |  |
| 165 | `tab_ordering_custom_basic` | 8.7s |  |
| 166 | `tab_ordering_custom_duplicate_index` | 8.8s |  |
| 167 | `tab_ordering_custom_i32_vs_u32` | 8.7s |  |
| 168 | `tab_ordering_custom_m1` | 8.7s |  |
| 169 | `tab_ordering_events` | 9.1s |  |
| 170 | `tab_ordering_events_mouse` | 8.9s |  |
| 171 | `tab_ordering_movieclip_enabled_default` | 8.8s |  |
| 172 | `tab_ordering_properties` | 8.8s |  |
| 173 | `tab_ordering_reverse` | 8.7s |  |
| 174 | `tab_ordering_tabbable` | 8.8s |  |
| 175 | `target_clip_removed` | 8.8s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 176 | `target_clip_swf5` | 8.7s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 177 | `target_clip_swf6` | 8.7s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 178 | `target_path` | 8.7s |  |
| 179 | `tell_target` | 8.8s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 180 | `tell_target_invalid` | 8.9s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 181 | `tell_target_invalid_swf6` | 8.8s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 182 | `text_blocks_clicks` | 8.7s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 183 | `textfield_background_color` | 8.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 184 | `textfield_border_color` | 8.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 185 | `textfield_properties` | 8.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 186 | `textfield_text` | 8.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 187 | `textfield_variable` | 8.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 188 | `textsnapshot_available_text` | 8.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 189 | `this_scoping` | 8.7s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 190 | `transform` | 9.0s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 191 | `typeof` | 8.8s |  |
| 192 | `unload` | 9.0s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 193 | `unload_clip_event` | 9.0s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 194 | `unload_nested_child` | 9.1s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 195 | `use_hand_cursor` | 8.8s |  |
| 196 | `variable_args` | 8.9s |  |
| 197 | `waitforframe` | 8.7s |  |
| 198 | `waitforframe2` | 8.8s |  |
| 199 | `with` | 8.9s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |

## Runtime Errors

**41 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_sort_random` | exit code -6 | 8.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 2 | `asnew` | exit code -6 | 8.5s |  |
| 3 | `bitmap_data_perlinnoise` | exit code -6 | 9.0s |  |
| 4 | `bitmap_data_pixeldissolve` | exit code -6 | 9.2s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 5 | `bitmap_data_pixeldissolve_image` | exit code -6 | 8.9s |  |
| 6 | `boxed_primitives` | exit code -6 | 8.9s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 7 | `coerce_to_object_monkeypatch` | exit code -6 | 9.3s |  |
| 8 | `coerce_to_primitive_resolve` | exit code -6 | 8.9s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 9 | `drag_over_from_outside` | exit code -6 | 8.7s |  |
| 10 | `drag_over_without_startdrag` | exit code -6 | 8.7s |  |
| 11 | `file_reference_browse_cancel` | exit code -6 | 8.7s |  |
| 12 | `function_suppress_and_preload` | exit code -6 | 8.7s |  |
| 13 | `global_swf6_7_8` | exit code -6 | 8.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 14 | `hittest_lockroot` | exit code -6 | 8.8s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 15 | `hittest_winding_rule` | exit code -6 | 8.7s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 16 | `instanceof_coercions` | exit code -6 | 8.9s |  |
| 17 | `interface_implements_op` | exit code -6 | 8.9s | [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 18 | `issue_3169` | exit code -6 | 8.7s |  |
| 19 | `issue_9327` | exit code -6 | 8.6s |  |
| 20 | `loadmovie_fail` | exit code -6 | 8.6s |  |
| 21 | `loadmovienum_cross_version_prototype` | exit code -6 | 8.6s |  |
| 22 | `math_swf6` | exit code -6 | 9.0s | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 23 | `math_swf7` | exit code -6 | 9.1s | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 24 | `math_swf8` | exit code -6 | 9.1s | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 25 | `mcl_loadclip_properties` | exit code -6 | 8.6s |  |
| 26 | `mcl_loadclip_replace_root` | exit code -6 | 8.6s |  |
| 27 | `mouse_hover_events_while_dragging` | exit code -6 | 8.6s |  |
| 28 | `native_double_construct` | exit code -6 | 9.0s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 29 | `native_subclasses` | exit code -6 | 9.2s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 30 | `object_resolve` | exit code -6 | 9.4s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 31 | `register_class_return_value` | exit code -6 | 9.1s | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 32 | `register_class_with_sound` | exit code -6 | 8.9s | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 33 | `string_methods_negative_args` | exit code -6 | 8.6s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 34 | `super_edge_cases` | exit code -6 | 8.7s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 35 | `watch_virtual_property_proto` | exit code -6 | 8.8s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 36 | `xml_reparenting` | exit code -6 | 8.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 37 | `xml_socket` | exit code -6 | 8.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 38 | `xml_socket_close_in_handler` | exit code -6 | 8.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 39 | `xml_socket_on_data` | exit code -6 | 9.0s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 40 | `xml_socket_segmented` | exit code -6 | 8.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 41 | `xml_unescaping` | exit code -6 | 8.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `placeobject_occupied_depth` | runtime timeout (>10s) | 18.3s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `timeout` | runtime timeout (>10s) | 17.1s | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**195 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `date` | 99.2% | 6284/6335 | 6335 | 6335 | [5](ruffle-tests/_investigation/complete/DATE_PLAN.md) |
| 2 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 3 | `array_sort` | 98.1% | 158/161 | 161 | 161 | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 4 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 5 | `add_property` | 73.3% | 11/15 | 15 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 7 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 8 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 9 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 10 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 11 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 12 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 13 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 14 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 15 | `mouse_listeners` | 66.2% | 45/68 | 68 | 67 |  |
| 16 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 17 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 18 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 19 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 20 | `bitmap_data_threshold` | 59.1% | 104/176 | 176 | 176 |  |
| 21 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 22 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 23 | `bitmapdata_channels` | 57.9% | 11/19 | 19 | 19 |  |
| 24 | `asnative` | 55.9% | 19/34 | 31 | 34 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 25 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 26 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 27 | `xml_getbytes` | 52.9% | 9/17 | 11 | 17 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 28 | `bitmap_data_noise` | 52.9% | 334/631 | 631 | 631 |  |
| 29 | `bitmap_data_compare` | 52.5% | 21/40 | 31 | 40 |  |
| 30 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 31 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 32 | `bad_placeobject_clipaction` | 50.0% | 1/2 | 1 | 2 |  |
| 33 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 35 | `loadmovie` | 50.0% | 1/2 | 2 | 2 |  |
| 36 | `loadmovie_method` | 50.0% | 1/2 | 1 | 2 |  |
| 37 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 38 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 39 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 40 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 41 | `unloadmovie` | 50.0% | 2/4 | 4 | 4 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 42 | `xml_attributes_read` | 50.0% | 2/4 | 4 | 4 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 43 | `bitmap_data_hittest` | 47.0% | 62/132 | 131 | 132 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 44 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 45 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 47 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 48 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 49 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 50 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 51 | `load_vars` | 37.1% | 13/35 | 23 | 35 |  |
| 52 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 53 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 54 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 55 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 56 | `loadmovienum` | 33.3% | 1/3 | 3 | 3 |  |
| 57 | `unloadmovie_method` | 33.3% | 1/3 | 2 | 3 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 58 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 59 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 60 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 61 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 62 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 63 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 64 | `loadmovie_flashvars` | 25.0% | 1/4 | 2 | 4 |  |
| 65 | `moviecliploader_flashvars` | 25.0% | 1/4 | 1 | 4 |  |
| 66 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 67 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 68 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 69 | `file_reference_download_success` | 20.6% | 7/34 | 14 | 34 |  |
| 70 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 71 | `unloadmovienum` | 20.0% | 3/15 | 15 | 13 | [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 72 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 73 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 74 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 75 | `bitmap_data_copypixels` | 17.6% | 3/17 | 17 | 17 |  |
| 76 | `mcl_loadclip` | 16.8% | 25/149 | 35 | 149 |  |
| 77 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 78 | `file_reference_download_cancel` | 14.3% | 1/7 | 2 | 7 |  |
| 79 | `loading_avm2` | 14.3% | 1/7 | 5 | 7 |  |
| 80 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 81 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 82 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 83 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 84 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 85 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 86 | `external_interface` | 13.1% | 11/84 | 23 | 84 |  |
| 87 | `loadmovie_var_persistence` | 12.5% | 1/8 | 1 | 8 |  |
| 88 | `loadvariables2` | 12.5% | 1/8 | 3 | 8 |  |
| 89 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 90 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 91 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 92 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 93 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 94 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 95 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 96 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 97 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 98 | `file_reference_download_httperror_dns_error` | 7.7% | 1/13 | 2 | 13 |  |
| 99 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 100 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 101 | `netconnection_close` | 7.7% | 3/39 | 11 | 39 |  |
| 102 | `define_local` | 7.4% | 2/27 | 23 | 27 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 103 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 104 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 105 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 106 | `focus_visibility_change` | 6.7% | 3/45 | 27 | 45 |  |
| 107 | `focus_remove` | 6.1% | 2/33 | 15 | 33 |  |
| 108 | `bitmap_data` | 5.9% | 69/1174 | 1174 | 1126 |  |
| 109 | `file_reference_upload_httperror_dns_error` | 5.6% | 1/18 | 2 | 18 |  |
| 110 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 111 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 112 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 113 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 114 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 115 | `file_reference_download_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 116 | `file_reference_upload_httperror_status_code` | 4.3% | 1/23 | 2 | 23 |  |
| 117 | `file_reference_upload_success` | 4.3% | 1/23 | 2 | 23 |  |
| 118 | `register_class` | 3.0% | 2/66 | 27 | 66 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 119 | `stylesheet_load` | 2.0% | 1/49 | 2 | 49 |  |
| 120 | `mcl_replace_root_swf7_to_swf5` | 1.8% | 1/57 | 1 | 57 |  |
| 121 | `mcl_replace_root_swf7_to_swf6` | 1.8% | 1/57 | 1 | 57 |  |
| 122 | `sound_id3` | 1.7% | 11/633 | 11 | 633 |  |
| 123 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 124 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 125 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 126 | `sound_id3_prop` | 0.7% | 1/138 | 1 | 138 |  |
| 127 | `sound_duration_position_props` | 0.7% | 2/290 | 2 | 290 |  |
| 128 | `external_interface_toas_basic` | 0.3% | 1/354 | 249 | 354 |  |
| 129 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 130 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 131 | `button_keypress` | 0.0% | 0/3 | 0 | 3 |  |
| 132 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 133 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 134 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 135 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 136 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 137 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 138 | `cross_movie_root` | 0.0% | 0/10 | 8 | 10 |  |
| 139 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 140 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 141 | `edittext_focus_selection` | 0.0% | 0/2 | 2 | 2 | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 142 | `edittext_ime_focus_lost` | 0.0% | 0/7 | 0 | 7 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 143 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 144 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 145 | `external_interface_jsquotestring` | 0.0% | 0/21 | 21 | 21 |  |
| 146 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 147 | `focus_mouse_focusable` | 0.0% | 0/8 | 0 | 8 |  |
| 148 | `form_loader_encoding_1` | 0.0% | 0/1 | 1 | 1 |  |
| 149 | `form_loader_encoding_2` | 0.0% | 0/6 | 6 | 3 |  |
| 150 | `form_loader_encoding_3` | 0.0% | 0/3 | 3 | 3 |  |
| 151 | `form_loader_encoding_4` | 0.0% | 0/3 | 3 | 3 |  |
| 152 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 153 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 154 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 155 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 156 | `key_isToggled` | 0.0% | 0/9 | 0 | 9 |  |
| 157 | `loadmovie_registerclass` | 0.0% | 0/30 | 1 | 30 |  |
| 158 | `loadvariables` | 0.0% | 0/2 | 1 | 2 |  |
| 159 | `loadvariablesnum` | 0.0% | 0/2 | 1 | 2 |  |
| 160 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 161 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 162 | `mcl_as_broadcaster` | 0.0% | 0/12 | 0 | 12 |  |
| 163 | `mcl_events_swf_version` | 0.0% | 0/232 | 0 | 232 |  |
| 164 | `mcl_getprogress` | 0.0% | 0/30 | 29 | 30 |  |
| 165 | `mcl_mislabeled_target` | 0.0% | 0/6 | 0 | 6 |  |
| 166 | `mcl_target_gif87a` | 0.0% | 0/6 | 0 | 6 |  |
| 167 | `mcl_target_gif89a` | 0.0% | 0/6 | 0 | 6 |  |
| 168 | `mcl_target_jpg` | 0.0% | 0/6 | 0 | 6 |  |
| 169 | `mcl_target_png` | 0.0% | 0/6 | 0 | 6 |  |
| 170 | `mcl_unloadclip` | 0.0% | 0/5 | 0 | 5 |  |
| 171 | `mixed_avm_load_into_root` | 0.0% | 0/2 | 0 | 2 |  |
| 172 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 173 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 174 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 175 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 176 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 177 | `netstream_seek_flv` | 0.0% | 0/25 | 5 | 25 |  |
| 178 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 179 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 180 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 181 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 182 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 183 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 184 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 185 | `sound_load_start` | 0.0% | 0/3 | 0 | 3 |  |
| 186 | `sound_multiple_load` | 0.0% | 0/1 | 0 | 1 |  |
| 187 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 188 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 189 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 190 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 191 | `swf5_xml_event_handler_context` | 0.0% | 0/2 | 1 | 2 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 192 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 193 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 194 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 195 | `xml_load` | 0.0% | 0/2 | 0 | 2 | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/_investigation/incomplete/add2.md) | 1 | 1 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) | 4 | 2 | 2 |
| 3 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) | 8 | 0 | 8 |
| 4 | [COLOR_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) | 5 | 2 | 3 |
| 5 | [DATE_PLAN.md](ruffle-tests/_investigation/complete/DATE_PLAN.md) | 1 | 0 | 1 |
| 6 | [ENUMERATION_PLAN.md](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) | 14 | 11 | 3 |
| 7 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) | 4 | 0 | 4 |
| 8 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 7 | 4 | 3 |
| 9 | [GLOBALS_PLAN.md](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) | 31 | 9 | 22 |
| 10 | [HIT_TESTING_PLAN.md](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) | 17 | 0 | 17 |
| 11 | [infinite_recursion_function.md](ruffle-tests/_investigation/complete/infinite_recursion_function.md) | 3 | 3 | 0 |
| 12 | [issue_768.md](ruffle-tests/_investigation/incomplete/issue_768.md) | 1 | 1 | 0 |
| 13 | [MATH_PLAN.md](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) | 5 | 1 | 4 |
| 14 | [MOVIECLIP_PLAN.md](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) | 58 | 0 | 58 |
| 15 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) | 17 | 5 | 12 |
| 16 | [object_string_coerce.md](ruffle-tests/_investigation/incomplete/object_string_coerce.md) | 2 | 1 | 1 |
| 17 | [OBJECT_WATCH_PLAN.md](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) | 4 | 1 | 3 |
| 18 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) | 8 | 1 | 7 |
| 19 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) | 3 | 2 | 1 |
| 20 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) | 12 | 6 | 6 |
| 21 | [REGISTERCLASS_PLAN.md](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) | 15 | 0 | 15 |
| 22 | [SELECTION_PLAN.md](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) | 4 | 0 | 4 |
| 23 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) | 9 | 1 | 8 |
| 24 | [STAGE_PLAN.md](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) | 7 | 1 | 6 |
| 25 | [string_coercion.md](ruffle-tests/_investigation/incomplete/string_coercion.md) | 1 | 1 | 0 |
| 26 | [STRING_PLAN.md](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) | 13 | 3 | 10 |
| 27 | [TELLTARGET_PLAN.md](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) | 19 | 0 | 19 |
| 28 | [TEXTFIELD_PLAN.md](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) | 70 | 9 | 61 |
| 29 | [this_swf7.md](ruffle-tests/_investigation/incomplete/this_swf7.md) | 1 | 1 | 0 |
| 30 | [TIMER_PLAN.md](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) | 3 | 0 | 3 |
| 31 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) | 5 | 5 | 0 |
| 32 | [UNLOAD_PLAN.md](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) | 12 | 0 | 12 |
| 33 | [WITH_SCOPE_PLAN.md](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) | 5 | 1 | 4 |
| 34 | [XML_PLAN.md](ruffle-tests/_investigation/incomplete/XML_PLAN.md) | 33 | 23 | 10 |
| | *(tests not in any document)* | 311 | 105 | 206 |
