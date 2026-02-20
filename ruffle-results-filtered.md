# Ruffle Test Results (Filtered)

**Date**: 2026-02-20 00:50 UTC

**Git SHA**: `3459c6f850`

**Run Duration**: 79m 31s

**Filtered**: 140 tests ignored out of 619 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 479 |
| Passing | **181** (37.8%) |
| Failing | 298 |
| Total expected lines | 45241 |
| Matching lines | 28872 (63.8%) |
| Mismatched lines | 16369 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Segfault | 146 | 49.0% |
| Output Mismatch | 122 | 40.9% |
| Runtime Error | 28 | 9.4% |
| Timeout | 2 | 0.7% |

## Passing Tests

**181 tests passing**

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
| 98 | `movieclip_begin_gradient_fill` | 0 | 7.0s |  |
| 99 | `movieclip_line_gradient_style` | 0 | 7.3s |  |
| 100 | `movieclip_prototype_extension` | 5 | 7.0s |  |
| 101 | `nested_textfields_in_buttons` | 0 | 7.0s |  |
| 102 | `new_method_wrap` | 4 | 6.8s |  |
| 103 | `new_object_enumerate` | 7 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) |
| 104 | `new_object_wrap` | 4 | 6.8s |  |
| 105 | `o` | 3 | 7.1s |  |
| 106 | `object_constructor` | 33 | 6.8s |  |
| 107 | `object_function` | 32 | 6.9s |  |
| 108 | `object_properties` | 31 | 7.1s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 109 | `object_prototypes` | 74 | 7.1s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 110 | `object_string_coerce_swf5` | 62 | 7.4s | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 111 | `parse_int` | 64 | 6.8s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 112 | `point` | 175 | 7.2s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 113 | `primitive_instanceof` | 37 | 6.6s |  |
| 114 | `primitive_type_globals` | 557 | 6.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 115 | `prototype_delete` | 12 | 6.9s |  |
| 116 | `prototype_enumerate` | 5 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 117 | `prototype_properties` | 17 | 6.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 118 | `rectangle` | 745 | 7.7s | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) |
| 119 | `recursive_prototypes` | 0 | 6.9s |  |
| 120 | `sandbox_type_local_file` | 1 | 6.5s |  |
| 121 | `single_frame` | 1 | 6.6s |  |
| 122 | `sound_start_load` | 0 | 6.5s |  |
| 123 | `stage_object_properties_get_var` | 5 | 6.6s |  |
| 124 | `stage_property_representation` | 586 | 6.6s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 125 | `strictequals_swf6` | 902 | 8.0s |  |
| 126 | `strictly_equals` | 7 | 6.5s |  |
| 127 | `string_coercion` | 117 | 6.8s | [25](ruffle-tests/_investigation/incomplete/string_coercion.md) |
| 128 | `string_methods` | 285 | 7.0s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 129 | `string_methods_swfv5` | 275 | 7.1s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 130 | `string_ops_swf6` | 95 | 6.5s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 131 | `string_paths_keyevents` | 0 | 6.6s |  |
| 132 | `string_paths_timer` | 0 | 6.5s |  |
| 133 | `swf4_actions_bool` | 96 | 6.7s |  |
| 134 | `swf4_bool` | 4 | 6.6s |  |
| 135 | `swf4_function_calls` | 7 | 8.9s |  |
| 136 | `swf5_encoding` | 3 | 6.7s |  |
| 137 | `tab_ordering_properties_tab_index_edge_case` | 4 | 6.7s |  |
| 138 | `text_format` | 1146 | 6.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 139 | `text_format_display` | 21 | 6.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 140 | `text_format_font_max_length` | 2 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 141 | `text_format_rounding_swf7` | 840 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 142 | `text_format_rounding_swf8` | 840 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 143 | `textfield_maxchars` | 3 | 6.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 144 | `textfield_props_swf6` | 210 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 145 | `textfield_props_swf7` | 210 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 146 | `textfield_props_swf8` | 210 | 6.8s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 147 | `this_swf7` | 41 | 6.7s | [29](ruffle-tests/_investigation/incomplete/this_swf7.md) |
| 148 | `timeline_function_def` | 7 | 6.7s |  |
| 149 | `try_catch_finally` | 118 | 7.2s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 150 | `try_finally_simple` | 16 | 6.8s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 151 | `typeof_globals` | 7 | 6.8s |  |
| 152 | `uncaught_exception` | 1 | 6.8s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 153 | `uncaught_exception_bubbled` | 1 | 6.8s | [31](ruffle-tests/_investigation/incomplete/TRY_CATCH_FINALLY_PLAN.md) |
| 154 | `undefined_to_string_swf6` | 4 | 6.7s |  |
| 155 | `unescape` | 43 | 6.8s |  |
| 156 | `watch` | 117 | 7.1s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 157 | `with_return` | 2 | 6.8s |  |
| 158 | `with_variable_scopes` | 43 | 6.9s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 159 | `xml` | 15 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 160 | `xml_append_child` | 28 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 161 | `xml_append_child_with_parent` | 20 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 162 | `xml_cdata` | 11 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 163 | `xml_child_nodes_edge_cases` | 4 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 164 | `xml_clone_expandos` | 19 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 165 | `xml_first_last_child` | 8 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 166 | `xml_has_child_nodes` | 3 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 167 | `xml_idmap` | 21 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 168 | `xml_ignore_comments` | 21 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 169 | `xml_ignore_white` | 34 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 170 | `xml_insert_before` | 20 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 171 | `xml_inspect_createmethods` | 15 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 172 | `xml_inspect_doctype` | 7 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 173 | `xml_inspect_parsexml` | 62 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 174 | `xml_inspect_xmldecl` | 7 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 175 | `xml_namespaces` | 203 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 176 | `xml_parent_and_child` | 5 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 177 | `xml_remove_node` | 22 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 178 | `xml_siblings` | 10 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 179 | `xml_to_string` | 13 | 6.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 180 | `xml_to_string_comment` | 1 | 6.7s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 181 | `xmlnode_proto` | 1 | 6.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**30 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_default_state` | 98.6% | 68 | 69 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `as_set_prop_flags` | 78.5% | 62 | 79 | 17 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 3 | `add_property` | 73.3% | 11 | 15 | 4 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 4 | `attach_movie` | 72.9% | 43 | 59 | 16 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 5 | `empty_movieclip_can_attach_movies` | 72.7% | 8 | 11 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 6 | `sound_props_swf5` | 72.1% | 49 | 68 | 19 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 7 | `movieclip_focusenabled` | 71.7% | 71 | 99 | 28 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `register_underflow` | 69.2% | 18 | 26 | 8 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 9 | `object_string_coerce_swf6` | 67.6% | 46 | 68 | 22 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 10 | `create_empty_movie_clip` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `export_assets` | 66.7% | 2 | 3 | 1 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 12 | `mutable_this` | 66.7% | 12 | 18 | 6 |  |
| 13 | `edittext_html_roundtrip` | 64.7% | 11 | 17 | 6 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `named_shapes` | 64.3% | 9 | 14 | 5 |  |
| 15 | `edittext_hscroll` | 63.0% | 17 | 27 | 10 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `this_swf5` | 61.0% | 25 | 41 | 16 |  |
| 17 | `clone_sprite_edittext_dynamic` | 58.1% | 50 | 86 | 36 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `parse_float` | 58.1% | 43 | 74 | 31 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 19 | `asnative` | 55.9% | 19 | 34 | 15 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 20 | `nan_scale` | 55.6% | 5 | 9 | 4 |  |
| 21 | `gettextextent` | 55.4% | 31 | 56 | 25 |  |
| 22 | `movieclip_lockroot` | 51.7% | 15 | 29 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 23 | `sound_props_swf6` | 51.5% | 35 | 68 | 33 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 24 | `bad_placeobject_clipaction` | 50.0% | 1 | 2 | 1 |  |
| 25 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288 | 576 | 288 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `issue_2030` | 50.0% | 2 | 4 | 2 |  |
| 27 | `localconnection_properties` | 50.0% | 4 | 8 | 4 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 28 | `string_paths_basic` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 29 | `string_paths_variable_alias` | 50.0% | 2 | 4 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 30 | `stylesheet_transform` | 50.0% | 375 | 750 | 375 |  |

## Segfaults

**146 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `as_transformed_flag` | 8.5s |  |
| 2 | `asfunction` | 8.5s |  |
| 3 | `button_children` | 8.9s |  |
| 4 | `button_goto` | 9.0s |  |
| 5 | `button_properties_special_cases` | 9.1s |  |
| 6 | `call` | 9.3s |  |
| 7 | `clip_events` | 9.3s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 8 | `clone_sprite_edittext` | 9.3s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 9 | `clone_sprite_types` | 9.2s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 10 | `closure_scope` | 9.1s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 11 | `color` | 9.0s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 12 | `conflicting_instance_names` | 8.7s |  |
| 13 | `custom_clip_methods` | 8.8s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 14 | `default_names` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 15 | `define_function2_preload_order` | 8.7s |  |
| 16 | `device_font_spacing` | 8.8s |  |
| 17 | `display_object_properties` | 8.6s |  |
| 18 | `do_init_action` | 8.7s |  |
| 19 | `duplicate_movie_clip` | 8.7s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 20 | `edittext_align` | 8.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 21 | `edittext_antialiastype` | 9.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 22 | `edittext_autosize` | 8.4s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 23 | `edittext_autosize_setter` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 24 | `edittext_bullet` | 8.3s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 25 | `edittext_default_format` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `edittext_default_format_empty` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 27 | `edittext_default_format_font_style` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 28 | `edittext_font_size` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 29 | `edittext_html_align_swf7` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 30 | `edittext_html_align_swf8` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 31 | `edittext_html_condensewhite_swf7` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 32 | `edittext_html_condensewhite_swf8` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `edittext_html_entity` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 34 | `edittext_html_swf6` | 8.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 35 | `edittext_html_swf7` | 9.0s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 36 | `edittext_html_swf8` | 9.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 37 | `edittext_leading` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 38 | `edittext_letter_spacing` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 39 | `edittext_margins` | 8.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 40 | `edittext_newline_stripping` | 13.2s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `edittext_newlines` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 42 | `edittext_programmatic_focus` | 8.0s | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `edittext_scroll` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 44 | `edittext_tag_indent` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 45 | `edittext_underline` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 46 | `edittext_width_height` | 8.1s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 47 | `execution_order1` | 8.0s |  |
| 48 | `execution_order2` | 8.1s |  |
| 49 | `execution_order3` | 8.0s |  |
| 50 | `execution_order4` | 8.1s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 51 | `extends_native_type` | 8.1s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 52 | `focusrect_mouse_swf8` | 8.6s |  |
| 53 | `focusrect_mouse_swf9` | 8.6s |  |
| 54 | `focusrect_swf5` | 8.8s |  |
| 55 | `frame_size_translated_negative` | 8.5s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 56 | `frame_size_translated_positive` | 8.6s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) |
| 57 | `function_base_clip` | 8.6s |  |
| 58 | `function_base_clip_readded` | 8.6s |  |
| 59 | `function_base_clip_removed` | 8.6s |  |
| 60 | `funky_function_calls` | 8.7s |  |
| 61 | `get_bytes_total` | 8.6s |  |
| 62 | `goto_advance1` | 8.5s |  |
| 63 | `goto_advance2` | 8.7s |  |
| 64 | `goto_both_ways1` | 9.0s |  |
| 65 | `goto_both_ways2` | 8.9s |  |
| 66 | `goto_execution_order2` | 8.7s |  |
| 67 | `goto_frame` | 8.8s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 68 | `goto_frame2` | 9.1s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 69 | `goto_frame_number` | 8.8s |  |
| 70 | `goto_label` | 8.9s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 71 | `goto_methods` | 8.7s | [7](ruffle-tests/_investigation/incomplete/FRAME_NAVIGATION_PLAN.md) |
| 72 | `goto_rewind1` | 8.9s |  |
| 73 | `goto_rewind2` | 8.7s |  |
| 74 | `goto_rewind3` | 8.7s |  |
| 75 | `hittest_morph` | 8.7s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 76 | `hittest_morph_input` | 8.6s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 77 | `issue_1104` | 8.6s |  |
| 78 | `issue_1671` | 8.7s |  |
| 79 | `issue_1906` | 8.8s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 80 | `issue_2870` | 8.7s |  |
| 81 | `issue_3446` | 8.6s |  |
| 82 | `issue_3522` | 8.6s |  |
| 83 | `issue_4377` | 8.6s |  |
| 84 | `issue_9885` | 8.7s |  |
| 85 | `local_to_global` | 8.8s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 86 | `mask_reapply` | 8.6s |  |
| 87 | `mask_with_drawing` | 8.8s |  |
| 88 | `movieclip_blend_mode_property` | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 89 | `movieclip_depth_methods` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 90 | `movieclip_get_instance_at_depth` | 8.5s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 91 | `movieclip_getbounds` | 8.8s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 92 | `movieclip_gettextsnapshot` | 8.8s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 93 | `movieclip_hittest` | 8.7s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 94 | `movieclip_hittest_shapeflag` | 9.9s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 95 | `movieclip_in_removed_button` | 8.5s |  |
| 96 | `movieclip_name_from_timeline` | 8.9s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 97 | `native_objects_swf6` | 9.3s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 98 | `native_objects_swf7` | 9.3s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 99 | `native_objects_swf8` | 9.3s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 100 | `netstream_play_flv_screen` | 23.4s |  |
| 101 | `on_construct` | 8.9s | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 102 | `path_string` | 8.8s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 103 | `place_and_lookup` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 104 | `register_and_init_order` | 9.2s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 105 | `remove_movie_clip` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 106 | `removed_base_clip_tell_target` | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 107 | `removed_clip_halts_script` | 9.3s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 108 | `rewind_depth` | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 109 | `root_global_parent` | 8.7s |  |
| 110 | `selection` | 8.7s | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 111 | `selection_handlers` | 8.6s | [22](ruffle-tests/_investigation/incomplete/SELECTION_PLAN.md) |
| 112 | `set_variable_scope` | 8.5s |  |
| 113 | `slash_syntax` | 8.7s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 114 | `sound` | 8.8s |  |
| 115 | `stage_object_children` | 8.6s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 116 | `stage_object_enumerate` | 8.7s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 117 | `stage_object_properties` | 9.0s | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 118 | `stage_object_properties_swf6` | 8.8s | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 119 | `string_paths_hidden` | 8.6s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 120 | `swf5_no_closure` | 8.7s |  |
| 121 | `swf6_case_insensitive` | 8.6s |  |
| 122 | `swf7_case_sensitive` | 8.7s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 123 | `target_clip_removed` | 8.8s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 124 | `target_clip_swf5` | 8.7s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 125 | `target_clip_swf6` | 8.7s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 126 | `target_path` | 8.7s |  |
| 127 | `tell_target` | 8.8s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 128 | `tell_target_invalid` | 8.9s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 129 | `tell_target_invalid_swf6` | 8.8s | [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 130 | `textfield_background_color` | 8.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 131 | `textfield_border_color` | 8.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 132 | `textfield_properties` | 8.7s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 133 | `textfield_text` | 8.6s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 134 | `textfield_variable` | 8.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 135 | `textsnapshot_available_text` | 8.9s | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 136 | `this_scoping` | 8.7s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 137 | `transform` | 9.0s | [4](ruffle-tests/_investigation/incomplete/COLOR_OBJECT_PLAN.md) |
| 138 | `typeof` | 8.8s |  |
| 139 | `unload` | 9.0s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 140 | `unload_clip_event` | 9.0s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 141 | `unload_nested_child` | 9.1s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 142 | `use_hand_cursor` | 8.8s |  |
| 143 | `variable_args` | 8.9s |  |
| 144 | `waitforframe` | 8.7s |  |
| 145 | `waitforframe2` | 8.8s |  |
| 146 | `with` | 8.9s | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |

## Runtime Errors

**28 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `array_sort_random` | exit code -6 | 8.6s | [2](ruffle-tests/_investigation/complete/ARRAY_METHODS_PLAN.md) |
| 2 | `asnew` | exit code -6 | 8.5s |  |
| 3 | `bitmap_data_perlinnoise` | exit code -6 | 9.0s |  |
| 4 | `bitmap_data_pixeldissolve_image` | exit code -6 | 8.9s |  |
| 5 | `boxed_primitives` | exit code -6 | 8.9s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 6 | `coerce_to_object_monkeypatch` | exit code -6 | 9.3s |  |
| 7 | `coerce_to_primitive_resolve` | exit code -6 | 8.9s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 8 | `function_suppress_and_preload` | exit code -6 | 8.7s |  |
| 9 | `global_swf6_7_8` | exit code -6 | 8.7s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 10 | `hittest_lockroot` | exit code -6 | 8.8s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 11 | `hittest_winding_rule` | exit code -6 | 8.7s | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) |
| 12 | `instanceof_coercions` | exit code -6 | 8.9s |  |
| 13 | `interface_implements_op` | exit code -6 | 8.9s | [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 14 | `issue_3169` | exit code -6 | 8.7s |  |
| 15 | `issue_9327` | exit code -6 | 8.6s |  |
| 16 | `math_swf6` | exit code -6 | 9.0s | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 17 | `math_swf7` | exit code -6 | 9.1s | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 18 | `math_swf8` | exit code -6 | 9.1s | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 19 | `native_double_construct` | exit code -6 | 9.0s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 20 | `native_subclasses` | exit code -6 | 9.2s | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) |
| 21 | `object_resolve` | exit code -6 | 9.4s | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 22 | `register_class_return_value` | exit code -6 | 9.1s | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 23 | `register_class_with_sound` | exit code -6 | 8.9s | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 24 | `string_methods_negative_args` | exit code -6 | 8.6s | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) |
| 25 | `super_edge_cases` | exit code -6 | 8.7s | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 26 | `watch_virtual_property_proto` | exit code -6 | 8.8s | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 27 | `xml_reparenting` | exit code -6 | 8.9s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |
| 28 | `xml_unescaping` | exit code -6 | 8.8s | [34](ruffle-tests/_investigation/incomplete/XML_PLAN.md) |

## Timeouts

**2 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `placeobject_occupied_depth` | runtime timeout (>10s) | 18.3s | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `timeout` | runtime timeout (>10s) | 17.1s | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |

## All Output Mismatches

**122 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_default_state` | 98.6% | 68/69 | 69 | 69 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 2 | `as_set_prop_flags` | 78.5% | 62/79 | 76 | 79 | [6](ruffle-tests/_investigation/complete/ENUMERATION_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 3 | `add_property` | 73.3% | 11/15 | 15 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 4 | `attach_movie` | 72.9% | 43/59 | 54 | 59 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 5 | `empty_movieclip_can_attach_movies` | 72.7% | 8/11 | 11 | 11 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 6 | `sound_props_swf5` | 72.1% | 49/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 7 | `movieclip_focusenabled` | 71.7% | 71/99 | 99 | 99 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 8 | `register_underflow` | 69.2% | 18/26 | 26 | 26 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 9 | `object_string_coerce_swf6` | 67.6% | 46/68 | 64 | 68 | [16](ruffle-tests/_investigation/incomplete/object_string_coerce.md) |
| 10 | `create_empty_movie_clip` | 66.7% | 2/3 | 2 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 11 | `export_assets` | 66.7% | 2/3 | 3 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 12 | `mutable_this` | 66.7% | 12/18 | 18 | 18 |  |
| 13 | `edittext_html_roundtrip` | 64.7% | 11/17 | 17 | 17 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 14 | `named_shapes` | 64.3% | 9/14 | 14 | 14 |  |
| 15 | `edittext_hscroll` | 63.0% | 17/27 | 27 | 27 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 16 | `this_swf5` | 61.0% | 25/41 | 41 | 41 |  |
| 17 | `clone_sprite_edittext_dynamic` | 58.1% | 50/86 | 86 | 86 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 18 | `parse_float` | 58.1% | 43/74 | 74 | 74 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) [19](ruffle-tests/_investigation/incomplete/PARSING_FUNCTIONS_PLAN.md) |
| 19 | `asnative` | 55.9% | 19/34 | 31 | 34 | [13](ruffle-tests/_investigation/incomplete/MATH_PLAN.md) |
| 20 | `nan_scale` | 55.6% | 5/9 | 9 | 9 |  |
| 21 | `gettextextent` | 55.4% | 31/56 | 56 | 56 |  |
| 22 | `movieclip_lockroot` | 51.7% | 15/29 | 16 | 29 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 23 | `sound_props_swf6` | 51.5% | 35/68 | 68 | 68 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 24 | `bad_placeobject_clipaction` | 50.0% | 1/2 | 1 | 2 |  |
| 25 | `edittext_align_trailing_spaces_swf8` | 50.0% | 288/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 26 | `issue_2030` | 50.0% | 2/4 | 4 | 4 |  |
| 27 | `localconnection_properties` | 50.0% | 4/8 | 8 | 8 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 28 | `string_paths_basic` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 29 | `string_paths_variable_alias` | 50.0% | 2/4 | 4 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 30 | `stylesheet_transform` | 50.0% | 375/750 | 750 | 750 |  |
| 31 | `stage_scale_mode` | 46.2% | 18/39 | 38 | 39 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 32 | `edittext_align_trailing_spaces_swf7` | 45.8% | 264/576 | 576 | 576 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 33 | `string_paths_other` | 44.4% | 16/36 | 28 | 36 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 34 | `this_swf6` | 43.9% | 18/41 | 41 | 41 |  |
| 35 | `register_globals_across_frames` | 43.8% | 7/16 | 16 | 15 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 36 | `as_broadcaster_undef` | 39.3% | 35/89 | 81 | 89 |  |
| 37 | `function_as_function` | 37.1% | 13/35 | 32 | 35 |  |
| 38 | `define_local_with_paths` | 35.2% | 19/54 | 34 | 54 |  |
| 39 | `attach_movie_stop` | 33.3% | 1/3 | 1 | 3 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 40 | `edittext_html_color` | 33.3% | 38/114 | 114 | 114 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 41 | `init_object_order` | 33.3% | 5/15 | 5 | 15 | [20](ruffle-tests/_investigation/incomplete/PROTOTYPE_OBJECT_PLAN.md) |
| 42 | `edittext_stylesheet` | 32.9% | 107/325 | 325 | 325 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 43 | `swf7_global_funcs` | 32.8% | 76/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 44 | `property_invalid_base_clip` | 30.6% | 11/36 | 35 | 36 |  |
| 45 | `as2_super_via_manual_prototype` | 27.5% | 11/40 | 28 | 40 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 46 | `swf6_global_funcs` | 25.9% | 60/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 47 | `do_init_action_child` | 25.0% | 3/12 | 3 | 12 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 48 | `textfield_props_swf5` | 24.6% | 43/175 | 140 | 175 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 49 | `swf5_global_funcs` | 24.6% | 57/232 | 232 | 232 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 50 | `textsnapshot_props_swf5` | 23.2% | 13/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 51 | `external_interface_toxml_array` | 20.0% | 5/25 | 25 | 25 |  |
| 52 | `external_interface_toxml_basic` | 19.6% | 35/179 | 179 | 179 |  |
| 53 | `as_broadcaster` | 19.5% | 8/41 | 25 | 41 |  |
| 54 | `set_interval` | 18.5% | 5/27 | 17 | 27 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 55 | `watch_textfield` | 16.7% | 2/12 | 3 | 12 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 56 | `movieclip_setmask` | 14.3% | 2/14 | 14 | 14 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 57 | `string_paths_eval2` | 14.3% | 1/7 | 1 | 7 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 58 | `printjob_props_swf5` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 59 | `printjob_props_swf6` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 60 | `printjob_props_swf7` | 13.3% | 6/45 | 35 | 45 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 61 | `watch_virtual_property` | 13.3% | 8/60 | 52 | 60 | [17](ruffle-tests/_investigation/incomplete/OBJECT_WATCH_PLAN.md) |
| 62 | `stage_display_state` | 12.5% | 2/16 | 12 | 16 | [23](ruffle-tests/_investigation/incomplete/STAGE_FRAME_PROPS_PLAN.md) [24](ruffle-tests/_investigation/incomplete/STAGE_PLAN.md) |
| 63 | `trace` | 12.5% | 1/8 | 6 | 8 |  |
| 64 | `textsnapshot_findtext` | 11.4% | 5/44 | 44 | 44 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 65 | `textsnapshot_props_swf6` | 10.7% | 6/56 | 38 | 56 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 66 | `movieclip_invalid_get_bounds_6` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 67 | `movieclip_invalid_get_bounds_7` | 10.0% | 1/10 | 1 | 10 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 68 | `movieclip_invalid_get_bounds_5` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 69 | `movieclip_invalid_get_bounds_8` | 9.1% | 1/11 | 1 | 11 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 70 | `extends_chain` | 9.0% | 12/134 | 122 | 134 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 71 | `movieclip_invalid_get_bounds_3` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 72 | `movieclip_invalid_get_bounds_4` | 7.7% | 1/13 | 1 | 13 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 73 | `define_local` | 7.4% | 2/27 | 23 | 27 | [33](ruffle-tests/_investigation/incomplete/WITH_SCOPE_PLAN.md) |
| 74 | `textsnapshot_gettext` | 7.3% | 4/55 | 55 | 55 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 75 | `as2_super_and_this_v6` | 7.2% | 7/97 | 29 | 97 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 76 | `swf4_actions_coercion_order` | 7.0% | 11/158 | 95 | 158 |  |
| 77 | `timer_run_actions` | 5.6% | 1/18 | 1 | 18 | [30](ruffle-tests/_investigation/incomplete/TIMER_PLAN.md) |
| 78 | `stylesheet` | 5.3% | 15/283 | 132 | 283 |  |
| 79 | `context_menu` | 5.1% | 2/39 | 11 | 39 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 80 | `context_menu_item` | 4.9% | 2/41 | 7 | 41 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 81 | `as2_super_and_this_v8` | 4.7% | 4/85 | 21 | 85 | [15](ruffle-tests/_investigation/incomplete/NATIVE_INTROSPECTION_PLAN.md) [18](ruffle-tests/_investigation/incomplete/OOP_SUPER_EXTENDS_PLAN.md) |
| 82 | `register_class` | 3.0% | 2/66 | 27 | 66 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 83 | `movieclip_invalid_get_bounds_1` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 84 | `movieclip_invalid_get_bounds_2` | 1.3% | 1/75 | 1 | 75 | [10](ruffle-tests/_investigation/incomplete/HIT_TESTING_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 85 | `movieclip_state_values` | 0.9% | 1/114 | 4 | 114 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 86 | `global_proto_decls` | 0.2% | 8/4497 | 372 | 4497 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 87 | `global_instance_decls` | 0.1% | 1/758 | 319 | 758 | [8](ruffle-tests/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 88 | `button_order` | 0.0% | 0/2 | 0 | 2 |  |
| 89 | `button_v5` | 0.0% | 0/18 | 0 | 18 |  |
| 90 | `button_v6` | 0.0% | 0/18 | 0 | 18 |  |
| 91 | `clip_constructors` | 0.0% | 0/8 | 0 | 8 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 92 | `clip_event_propagation_order` | 0.0% | 0/17 | 0 | 17 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [32](ruffle-tests/_investigation/incomplete/UNLOAD_PLAN.md) |
| 93 | `constructor_function` | 0.0% | 0/2 | 2 | 2 |  |
| 94 | `displacementmapfilter_mappoint_throw_error` | 0.0% | 0/13 | 13 | 13 |  |
| 95 | `duplicate_movie_clip_drawing` | 0.0% | 0/2 | 2 | 2 | [3](ruffle-tests/_investigation/incomplete/CLONE_DUPLICATE_PLAN.md) [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 96 | `edittext_text_height_leading` | 0.0% | 0/20 | 20 | 20 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 97 | `external_interface_escapexml` | 0.0% | 0/26 | 26 | 26 |  |
| 98 | `external_interface_unescapexml` | 0.0% | 0/40 | 40 | 40 |  |
| 99 | `geturl` | 0.0% | 0/7 | 1 | 7 |  |
| 100 | `global_proto_decls_delete` | 0.0% | 0/4158 | 118 | 4158 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 101 | `global_swf5_6_7_8_9` | 0.0% | 0/1145 | 0 | 1145 | [9](ruffle-tests/_investigation/incomplete/GLOBALS_PLAN.md) |
| 102 | `issue_2084` | 0.0% | 0/16 | 0 | 16 |  |
| 103 | `localconnection` | 0.0% | 0/579 | 2 | 579 |  |
| 104 | `lock_root` | 0.0% | 0/1 | 0 | 1 |  |
| 105 | `movieclip_create_text_field` | 0.0% | 0/90 | 90 | 90 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 106 | `movieclip_init_object` | 0.0% | 0/5 | 2 | 5 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 107 | `movieclip_library_state_values` | 0.0% | 0/78 | 0 | 78 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 108 | `movieclip_methods_with_loaded_image` | 0.0% | 0/4 | 0 | 4 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) |
| 109 | `register_class_swf6` | 0.0% | 0/37 | 0 | 37 | [21](ruffle-tests/_investigation/incomplete/REGISTERCLASS_PLAN.md) |
| 110 | `removed_target_clip_scope` | 0.0% | 0/35 | 0 | 35 | [14](ruffle-tests/_investigation/incomplete/MOVIECLIP_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 111 | `resolve_different_root` | 0.0% | 0/2 | 0 | 2 |  |
| 112 | `root_button_mode` | 0.0% | 0/10 | 1 | 10 |  |
| 113 | `root_onload` | 0.0% | 0/1 | 0 | 1 |  |
| 114 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 115 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 116 | `string_paths_eval` | 0.0% | 0/4 | 0 | 4 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 117 | `string_paths_reference_launder` | 0.0% | 0/2 | 2 | 2 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 118 | `string_paths_unload` | 0.0% | 0/1 | 0 | 1 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 119 | `string_paths_variable_scopes` | 0.0% | 0/5 | 0 | 5 | [26](ruffle-tests/_investigation/incomplete/STRING_PLAN.md) [27](ruffle-tests/_investigation/incomplete/TELLTARGET_PLAN.md) |
| 120 | `swf6_string_as_bool` | 0.0% | 0/23 | 23 | 15 |  |
| 121 | `textfield_cache_as_bitmap` | 0.0% | 0/1 | 0 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |
| 122 | `textsnapshot_text_order` | 0.0% | 0/1 | 1 | 1 | [28](ruffle-tests/_investigation/incomplete/TEXTFIELD_PLAN.md) |

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
| | *(tests not in any document)* | 201 | 104 | 97 |
