# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.629626+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.494624+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1123 | 0 | -1123 |
| Total | 1240 | 1240 | 0 |
| Pass rate | 90.6% | 0.0% | -90.6% |
| Mismatched lines | 31398 | 0 | -31398 |
|   Decreased | | | -31398 |

## Newly Failing (1123)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `abstract_classes` | compile_fail | 132/132 | - |
| `accessibility` | compile_fail | 1/1 | - |
| `activation_class` | compile_fail | 6/6 | - |
| `add` | compile_fail | 1058/1058 | - |
| `agal_compiler` | compile_fail | 13/13 | - |
| `air_datagram_socket` | compile_fail | 1/1 | - |
| `air_hidden_lookup` | compile_fail | 2/2 | - |
| `air_ifilepromise` | compile_fail | 1/1 | - |
| `all_classes/display3D/swf12` | compile_fail | 61/61 | - |
| `all_classes/errors/swf10` | compile_fail | 140/140 | - |
| `all_classes/errors/swf30` | compile_fail | 140/140 | - |
| `all_classes/errors/swf9` | compile_fail | 121/121 | - |
| `all_classes/security/swf11` | compile_fail | 3/3 | - |
| `all_classes/security/swf12` | compile_fail | 19/19 | - |
| `all_classes/security/swf13` | compile_fail | 53/53 | - |
| `all_classes/security/swf30` | compile_fail | 53/53 | - |
| `amf_array_serialization` | compile_fail | 17/17 | - |
| `amf_custom_obj` | compile_fail | 26/26 | - |
| `amf_dictionary` | compile_fail | 9/9 | - |
| `amf_function` | compile_fail | 46/46 | - |
| `amf_invalid_date` | compile_fail | 2/2 | - |
| `amf_missing_prop` | compile_fail | 6/6 | - |
| `amf_nondynamic_function_prop` | compile_fail | 6/6 | - |
| `amf_setter_error` | compile_fail | 8/8 | - |
| `amf_vector` | compile_fail | 40/40 | - |
| `amf_xml` | compile_fail | 6/6 | - |
| `application_domain` | compile_fail | 4/4 | - |
| `applicationdomain_getqualifieddefinitionnames` | compile_fail | 9/9 | - |
| `applicationdomain_hasdefinition_null` | compile_fail | 2/2 | - |
| `array_access` | compile_fail | 18/18 | - |
| `array_access_interpreter` | compile_fail | 4/4 | - |
| `array_access_no_pubns` | compile_fail | 2/2 | - |
| `array_concat` | compile_fail | 41/41 | - |
| `array_constr` | compile_fail | 10/10 | - |
| `array_delete` | compile_fail | 44/44 | - |
| `array_enumeration` | compile_fail | 10/10 | - |
| `array_enumeration_elements` | compile_fail | 11/11 | - |
| `array_every` | compile_fail | 8/8 | - |
| `array_filter` | compile_fail | 6/6 | - |
| `array_foreach` | compile_fail | 18/18 | - |
| `array_hasownproperty` | compile_fail | 11/11 | - |
| `array_holes` | compile_fail | 9/9 | - |
| `array_index_max` | compile_fail | 84/84 | - |
| `array_indexof` | compile_fail | 25/25 | - |
| `array_join` | compile_fail | 26/26 | - |
| `array_lastindexof` | compile_fail | 29/29 | - |
| `array_length` | compile_fail | 14/14 | - |
| `array_literal` | compile_fail | 3/3 | - |
| `array_map` | compile_fail | 8/8 | - |
| `array_pop` | compile_fail | 52/52 | - |
| `array_push` | compile_fail | 24/24 | - |
| `array_reborrow_bug` | compile_fail | 6/6 | - |
| `array_reverse` | compile_fail | 28/28 | - |
| `array_shift` | compile_fail | 51/51 | - |
| `array_slice` | compile_fail | 39/39 | - |
| `array_some` | compile_fail | 8/8 | - |
| `array_sort` | compile_fail | 297/297 | - |
| `array_sort_fun_swf12` | compile_fail | 2/2 | - |
| `array_sort_fun_swf13` | compile_fail | 2/2 | - |
| `array_sort_random` | compile_fail | 210/210 | - |
| `array_sort_swf10_32bit` | compile_fail | 1/1 | - |
| `array_sorton` | compile_fail | 545/545 | - |
| `array_sparse_ops` | compile_fail | 41/41 | - |
| `array_splice` | compile_fail | 133/133 | - |
| `array_splice2` | compile_fail | 428/428 | - |
| `array_splice_types` | compile_fail | 48/48 | - |
| `array_storage` | compile_fail | 8/8 | - |
| `array_tolocalestring` | compile_fail | 9/9 | - |
| `array_tostring` | compile_fail | 12/12 | - |
| `array_unshift` | compile_fail | 24/24 | - |
| `array_valueof` | compile_fail | 9/9 | - |
| `array_vector_null_callback` | compile_fail | 10/10 | - |
| `astype` | compile_fail | 28/28 | - |
| `astypelate` | compile_fail | 24/24 | - |
| `astypelate_propagates` | compile_fail | 1/1 | - |
| `asymmetric_key_events` | compile_fail | 11/11 | - |
| `av_classes` | compile_fail | 340/340 | - |
| `avm1movie_addcallback_call` | compile_fail | 14/14 | - |
| `avm2_catchup_dobj` | compile_fail | 158/158 | - |
| `away3d_advanced_shallow_water_demo` | compile_fail | 0/0 | - |
| `bevel_filter` | compile_fail | 187/187 | - |
| `bitand` | compile_fail | 1058/1058 | - |
| `bitmap_constr` | compile_fail | 17/17 | - |
| `bitmap_data` | compile_fail | 1000/1000 | - |
| `bitmap_pixelsnapping` | compile_fail | 2/2 | - |
| `bitmap_properties` | compile_fail | 23/23 | - |
| `bitmap_subclass` | compile_fail | 7/7 | - |
| `bitmap_subclass_properties` | compile_fail | 9/9 | - |
| `bitmap_timeline` | compile_fail | 9/9 | - |
| `bitmapdata_accuracy` | compile_fail | 1/1 | - |
| `bitmapdata_applyfilter_blur` | compile_fail | 0/0 | - |
| `bitmapdata_applyfilter_colormatrix` | compile_fail | 0/0 | - |
| `bitmapdata_applyfilter_destpoint` | compile_fail | 0/0 | - |
| `bitmapdata_applyfilter_destpoint_edges` | compile_fail | 0/0 | - |
| `bitmapdata_clone` | compile_fail | 13/13 | - |
| `bitmapdata_colortransform` | compile_fail | 0/0 | - |
| `bitmapdata_colortransform_oob` | compile_fail | 2/2 | - |
| `bitmapdata_constr` | compile_fail | 22/22 | - |
| `bitmapdata_constructor_from_timeline` | compile_fail | 1/1 | - |
| `bitmapdata_copychannel` | compile_fail | 0/0 | - |
| `bitmapdata_copypixels` | compile_fail | 23/23 | - |
| `bitmapdata_copypixels_blend_over` | compile_fail | 1/1 | - |
| `bitmapdata_copypixelstobytearray` | compile_fail | 39/39 | - |
| `bitmapdata_dispose` | compile_fail | 7/7 | - |
| `bitmapdata_draw` | compile_fail | 0/0 | - |
| `bitmapdata_draw_colortransform` | compile_fail | 0/0 | - |
| `bitmapdata_draw_cpu_overwrite_gpu` | compile_fail | 0/0 | - |
| `bitmapdata_draw_filters` | compile_fail | 0/0 | - |
| `bitmapdata_draw_masks` | compile_fail | 0/0 | - |
| `bitmapdata_draw_rotation` | compile_fail | 0/0 | - |
| `bitmapdata_draw_self_via_graphic` | compile_fail | 0/0 | - |
| `bitmapdata_draw_stage` | compile_fail | 0/0 | - |
| `bitmapdata_drawwithquality` | compile_fail | 0/0 | - |
| `bitmapdata_embedded` | compile_fail | 9/9 | - |
| `bitmapdata_fillrect` | compile_fail | 0/0 | - |
| `bitmapdata_filter_sourcerect` | compile_fail | 0/0 | - |
| `bitmapdata_floodfill` | compile_fail | 35/35 | - |
| `bitmapdata_getpixels` | compile_fail | 39/39 | - |
| `bitmapdata_getvector` | compile_fail | 27/27 | - |
| `bitmapdata_histogram` | compile_fail | 59/59 | - |
| `bitmapdata_hittest` | compile_fail | 112/112 | - |
| `bitmapdata_hittest_threshold` | compile_fail | 18/18 | - |
| `bitmapdata_opaque` | compile_fail | 0/0 | - |
| `bitmapdata_pixeldissolve` | compile_fail | 1037/1037 | - |
| `bitmapdata_pixeldissolve_image` | compile_fail | 0/0 | - |
| `bitmapdata_rectangle_rounding` | compile_fail | 16/16 | - |
| `bitmapdata_setpixels` | compile_fail | 286/286 | - |
| `bitmapdata_setvector` | compile_fail | 26/26 | - |
| `bitmapdata_sync` | compile_fail | 0/0 | - |
| `bitmapdata_threshold` | compile_fail | 176/176 | - |
| `bitmapdata_zero_size` | compile_fail | 8/8 | - |
| `bitnot` | compile_fail | 46/46 | - |
| `bitor` | compile_fail | 1058/1058 | - |
| `bitxor` | compile_fail | 1058/1058 | - |
| `blend_mode_null` | compile_fail | 1/1 | - |
| `blend_multiply_alpha` | compile_fail | 0/0 | - |
| `blend_scroll` | compile_fail | 0/0 | - |
| `blend_shader_luma_lighten` | compile_fail | 3/3 | - |
| `blur_filter` | compile_fail | 43/43 | - |
| `boolean_constr` | compile_fail | 32/32 | - |
| `boolean_negation` | compile_fail | 30/30 | - |
| `boolean_tostring` | compile_fail | 8/8 | - |
| `broadcast_event` | compile_fail | 7/7 | - |
| `button_bounds` | compile_fail | 1/1 | - |
| `button_hittest` | compile_fail | 2/2 | - |
| `button_nested_frame` | compile_fail | 48/48 | - |
| `bytearray` | compile_fail | 48/48 | - |
| `bytearray_compress` | compile_fail | 31/31 | - |
| `bytearray_errors` | compile_fail | 24/24 | - |
| `bytearray_method_serialization` | compile_fail | 1/1 | - |
| `bytearray_oom` | compile_fail | 3/3 | - |
| `bytearray_readobject_amf0` | compile_fail | 50/50 | - |
| `bytearray_readobject_amf3` | compile_fail | 53/53 | - |
| `bytearray_readutf8bytes_with_bom` | compile_fail | 16/16 | - |
| `bytearray_serialization` | compile_fail | 3/3 | - |
| `bytearray_string_null` | compile_fail | 19/19 | - |
| `bytearray_tostring` | compile_fail | 15/15 | - |
| `bytearray_utf16` | compile_fail | 8/8 | - |
| `bytearray_writeobject` | compile_fail | 24/24 | - |
| `callee_in_initializer` | compile_fail | 6/6 | - |
| `callproplex_class` | compile_fail | 1/1 | - |
| `capabilities_resolution` | compile_fail | 8/8 | - |
| `catch_class` | compile_fail | 6/6 | - |
| `catch_scope_slot` | compile_fail | 7/7 | - |
| `checkfilter` | compile_fail | 4/4 | - |
| `class_call` | compile_fail | 32/32 | - |
| `class_cast_call` | compile_fail | 14/14 | - |
| `class_enumeration` | compile_fail | 4/4 | - |
| `class_has_own_property` | compile_fail | 2/2 | - |
| `class_init_interpreter_mode` | compile_fail | 1/1 | - |
| `class_is` | compile_fail | 32/32 | - |
| `class_methods` | compile_fail | 5/5 | - |
| `class_object_properties` | compile_fail | 10/10 | - |
| `class_singleton` | compile_fail | 18/18 | - |
| `class_supercalls_errors` | compile_fail | 35/35 | - |
| `class_supercalls_mismatched` | compile_fail | 26/26 | - |
| `class_superclass_wrong_order` | compile_fail | 1/1 | - |
| `class_to_locale_string` | compile_fail | 2/2 | - |
| `class_to_string` | compile_fail | 2/2 | - |
| `class_value_of` | compile_fail | 2/2 | - |
| `click_block` | compile_fail | 5/5 | - |
| `click_invisible` | compile_fail | 3/3 | - |
| `closures` | compile_fail | 12/12 | - |
| `coerce_return_type` | compile_fail | 40/40 | - |
| `coerce_return_type_fail` | compile_fail | 2/2 | - |
| `coerce_return_void` | compile_fail | 3/3 | - |
| `coerce_string` | compile_fail | 86/86 | - |
| `coerce_string_precision` | compile_fail | 28/28 | - |
| `coerce_to_primitive_side_effects` | compile_fail | 29/29 | - |
| `color_matrix_filter` | compile_fail | 19/19 | - |
| `construct_errors_swf10` | compile_fail | 8/8 | - |
| `construct_frame_list` | compile_fail | 22/22 | - |
| `construct_interface` | compile_fail | 3/3 | - |
| `constructor_call` | compile_fail | 3/3 | - |
| `constructors_vs_timeline` | compile_fail | 5/5 | - |
| `constructprop_dynamic_primitive` | compile_fail | 7/7 | - |
| `constructprop_method` | compile_fail | 2/2 | - |
| `constructsuper_null` | compile_fail | 2/2 | - |
| `content_element_basic` | compile_fail | 50/50 | - |
| `context3d_creation` | compile_fail | 9/9 | - |
| `control_flow_bool` | compile_fail | 4/4 | - |
| `control_flow_stricteq` | compile_fail | 8/8 | - |
| `convert_boolean` | compile_fail | 30/30 | - |
| `convert_integer` | compile_fail | 90/90 | - |
| `convert_number` | compile_fail | 56/56 | - |
| `convert_uinteger` | compile_fail | 90/90 | - |
| `convolution_filter` | compile_fail | 89/89 | - |
| `core_exceptions` | compile_fail | 47/47 | - |
| `cpool_index_invalid_bytecode_1` | compile_fail | 6/6 | - |
| `cpool_index_invalid_bytecode_2` | compile_fail | 3/3 | - |
| `cpool_index_invalid_bytecode_3` | compile_fail | 1/1 | - |
| `cross_api_version_call_newer` | compile_fail | 12/12 | - |
| `cross_api_version_call_older` | compile_fail | 12/12 | - |
| `cryptscore` | compile_fail | 11/11 | - |
| `currency_parse_result` | compile_fail | 7/7 | - |
| `date` | compile_fail | 30/30 | - |
| `date_parse` | compile_fail | 36/36 | - |
| `declocal` | compile_fail | 46/46 | - |
| `declocal_i` | compile_fail | 46/46 | - |
| `decode_uri` | compile_fail | 71/71 | - |
| `decrement` | compile_fail | 46/46 | - |
| `decrement_i` | compile_fail | 46/46 | - |
| `default_values` | compile_fail | 7/7 | - |
| `describe_type_basic` | compile_fail | 152/152 | - |
| `describe_type_json` | compile_fail | 301/301 | - |
| `describe_type_metadata` | compile_fail | 125/125 | - |
| `describe_type_native` | compile_fail | 23/23 | - |
| `dictionary_access` | compile_fail | 62/62 | - |
| `dictionary_access_no_pubns` | compile_fail | 2/2 | - |
| `dictionary_delete` | compile_fail | 101/101 | - |
| `dictionary_foreach` | compile_fail | 42/42 | - |
| `dictionary_hasownproperty` | compile_fail | 63/63 | - |
| `dictionary_in` | compile_fail | 62/62 | - |
| `dictionary_iter_modify` | compile_fail | 8/8 | - |
| `dictionary_namespaces` | compile_fail | 36/36 | - |
| `dictionary_primitive_keys` | compile_fail | 29/29 | - |
| `displacement_map_filter` | compile_fail | 61/61 | - |
| `displayobject_alpha` | compile_fail | 277/277 | - |
| `displayobject_blendmode` | compile_fail | 0/0 | - |
| `displayobject_colortransform_nested` | compile_fail | 0/0 | - |
| `displayobject_filters` | compile_fail | 17/17 | - |
| `displayobject_from_enterframe` | compile_fail | 1/1 | - |
| `displayobject_getbounds_shape` | compile_fail | 0/0 | - |
| `displayobject_height` | compile_fail | 6052/6052 | - |
| `displayobject_hittestobject` | compile_fail | 32/32 | - |
| `displayobject_hittestpoint` | compile_fail | 49/49 | - |
| `displayobject_hittestpoint_root` | compile_fail | 13/13 | - |
| `displayobject_invalid_floats` | compile_fail | 60/60 | - |
| `displayobject_invalid_props` | compile_fail | 3/3 | - |
| `displayobject_mask` | compile_fail | 3/3 | - |
| `displayobject_mask_self_referential` | compile_fail | 0/0 | - |
| `displayobject_metaData` | compile_fail | 3/3 | - |
| `displayobject_name` | compile_fail | 22/22 | - |
| `displayobject_name_from_timeline` | compile_fail | 24/24 | - |
| `displayobject_opaque_background` | compile_fail | 6/6 | - |
| `displayobject_parent` | compile_fail | 12/12 | - |
| `displayobject_root` | compile_fail | 24/24 | - |
| `displayobject_rotation` | compile_fail | 1284/1284 | - |
| `displayobject_set_matrix_nested` | compile_fail | 0/0 | - |
| `displayobject_set_name_loaded` | compile_fail | 3/3 | - |
| `displayobject_subclass` | compile_fail | 2/2 | - |
| `displayobject_visible` | compile_fail | 23/23 | - |
| `displayobject_width` | compile_fail | 4852/4852 | - |
| `displayobject_x` | compile_fail | 614/614 | - |
| `displayobject_y` | compile_fail | 617/617 | - |
| `displayobjectcontainer_addchild` | compile_fail | 32/32 | - |
| `displayobjectcontainer_addchild_lazy_sprite` | compile_fail | 1/1 | - |
| `displayobjectcontainer_addchild_timelinepull0` | compile_fail | 58/58 | - |
| `displayobjectcontainer_addchild_timelinepull1` | compile_fail | 60/60 | - |
| `displayobjectcontainer_addchild_timelinepull2` | compile_fail | 62/62 | - |
| `displayobjectcontainer_addchildat` | compile_fail | 42/42 | - |
| `displayobjectcontainer_addchildat_timelinelock0` | compile_fail | 34/34 | - |
| `displayobjectcontainer_addchildat_timelinelock1` | compile_fail | 34/34 | - |
| `displayobjectcontainer_addchildat_timelinelock2` | compile_fail | 34/34 | - |
| `displayobjectcontainer_contains` | compile_fail | 66/66 | - |
| `displayobjectcontainer_getchildat` | compile_fail | 4/4 | - |
| `displayobjectcontainer_getchildbyname` | compile_fail | 9/9 | - |
| `displayobjectcontainer_getchildbyname_wrongcase` | compile_fail | 5/5 | - |
| `displayobjectcontainer_getchildindex` | compile_fail | 28/28 | - |
| `displayobjectcontainer_getobjectsunderpoint` | compile_fail | 15/15 | - |
| `displayobjectcontainer_removechild` | compile_fail | 10/10 | - |
| `displayobjectcontainer_removechild_errors` | compile_fail | 4/4 | - |
| `displayobjectcontainer_removechild_timelinemanip_remove1` | compile_fail | 38/38 | - |
| `displayobjectcontainer_removechildat` | compile_fail | 18/18 | - |
| `displayobjectcontainer_removechildren` | compile_fail | 51/51 | - |
| `displayobjectcontainer_setchildindex` | compile_fail | 42/42 | - |
| `displayobjectcontainer_stopallmovieclips` | compile_fail | 2/2 | - |
| `displayobjectcontainer_swapchildren` | compile_fail | 42/42 | - |
| `displayobjectcontainer_swapchildrenat` | compile_fail | 42/42 | - |
| `displayobjectcontainer_timelineinstance` | compile_fail | 48/48 | - |
| `divide` | compile_fail | 1058/1058 | - |
| `doabc_and_symbolclass_script_init_goto` | compile_fail | 7/7 | - |
| `doabc_and_symbolclass_script_init_normal` | compile_fail | 6/6 | - |
| `doabc_is_eager` | compile_fail | 1/1 | - |
| `documentclass` | compile_fail | 9/9 | - |
| `domain_memory` | compile_fail | 133/133 | - |
| `drag_drop` | compile_fail | 10/10 | - |
| `drop_shadow_filter` | compile_fail | 172/172 | - |
| `duplicate_defs` | compile_fail | 1/1 | - |
| `eager_init` | compile_fail | 1/1 | - |
| `east_asian_justifier_clone` | compile_fail | 8/8 | - |
| `edit_text_linkage` | compile_fail | 7/7 | - |
| `edittext_align` | compile_fail | 60/60 | - |
| `edittext_always_show_selection` | compile_fail | 0/0 | - |
| `edittext_antialiastype` | compile_fail | 296/296 | - |
| `edittext_at_point_methods_basic` | compile_fail | 16/16 | - |
| `edittext_autosize` | compile_fail | 39/39 | - |
| `edittext_autosize_align` | compile_fail | 0/0 | - |
| `edittext_autosize_height_dynamic` | compile_fail | 60/60 | - |
| `edittext_autosize_height_input` | compile_fail | 60/60 | - |
| `edittext_autosize_lazy_bounds_events` | compile_fail | 65/65 | - |
| `edittext_autosize_lazy_bounds_interactions` | compile_fail | 19/19 | - |
| `edittext_autosize_lazy_bounds_props` | compile_fail | 490/490 | - |
| `edittext_autosize_lazy_bounds_visual` | compile_fail | 0/0 | - |
| `edittext_autosize_lazy_bounds_vs_relayout` | compile_fail | 106/106 | - |
| `edittext_bottom_scroll_v_basic` | compile_fail | 210/210 | - |
| `edittext_bounds_scale` | compile_fail | 24/24 | - |
| `edittext_bullet` | compile_fail | 30/30 | - |
| `edittext_default_format` | compile_fail | 221/221 | - |
| `edittext_default_format_empty` | compile_fail | 136/136 | - |
| `edittext_empty_text_format` | compile_fail | 7/7 | - |
| `edittext_focus_selection` | compile_fail | 5/5 | - |
| `edittext_font_size` | compile_fail | 45/45 | - |
| `edittext_format_empty_font` | compile_fail | 8/8 | - |
| `edittext_get_char_index_at_point` | compile_fail | 4/4 | - |
| `edittext_get_line_index_at_point` | compile_fail | 2/2 | - |
| `edittext_get_line_index_of_char` | compile_fail | 76/76 | - |
| `edittext_getcharboundaries` | compile_fail | 172/172 | - |
| `edittext_getcharboundaries_missing_glyphs` | compile_fail | 63/63 | - |
| `edittext_getcharboundaries_scroll` | compile_fail | 85/85 | - |
| `edittext_getlinemetrics` | compile_fail | 146/146 | - |
| `edittext_html` | compile_fail | 3101/3101 | - |
| `edittext_html_condensewhite` | compile_fail | 487/487 | - |
| `edittext_html_entity` | compile_fail | 4/4 | - |
| `edittext_html_font_size_swf12` | compile_fail | 267/267 | - |
| `edittext_html_font_size_swf13` | compile_fail | 273/273 | - |
| `edittext_html_roundtrip` | compile_fail | 17/17 | - |
| `edittext_ime_focus_lost` | compile_fail | 9/9 | - |
| `edittext_input_control` | compile_fail | 12/12 | - |
| `edittext_leading` | compile_fail | 9/9 | - |
| `edittext_letter_spacing` | compile_fail | 15/15 | - |
| `edittext_line_methods` | compile_fail | 294/294 | - |
| `edittext_line_metrics` | compile_fail | 11/11 | - |
| `edittext_margins` | compile_fail | 25/25 | - |
| `edittext_max_scroll_h_basic` | compile_fail | 475/475 | - |
| `edittext_max_scroll_v_basic` | compile_fail | 1000/1000 | - |
| `edittext_mouse_selection` | compile_fail | 363/363 | - |
| `edittext_mousedown` | compile_fail | 3/3 | - |
| `edittext_mouseenabled` | compile_fail | 26/26 | - |
| `edittext_newline_character` | compile_fail | 22/22 | - |
| `edittext_newline_stripping` | compile_fail | 64/64 | - |
| `edittext_newlines` | compile_fail | 30/30 | - |
| `edittext_paragraph_methods` | compile_fail | 257/257 | - |
| `edittext_paste_events` | compile_fail | 8/8 | - |
| `edittext_paste_maxchars` | compile_fail | 4/4 | - |
| `edittext_paste_restrict` | compile_fail | 16/16 | - |
| `edittext_restrict` | compile_fail | 191/191 | - |
| `edittext_restrict_events` | compile_fail | 22/22 | - |
| `edittext_scrollh` | compile_fail | 10/10 | - |
| `edittext_selected_text` | compile_fail | 9/9 | - |
| `edittext_set_html_same` | compile_fail | 17/17 | - |
| `edittext_set_text_vs_html` | compile_fail | 9/9 | - |
| `edittext_stylesheet` | compile_fail | 536/536 | - |
| `edittext_stylesheet_custom_tag` | compile_fail | 76/76 | - |
| `edittext_stylesheet_display` | compile_fail | 272/272 | - |
| `edittext_underline` | compile_fail | 40/40 | - |
| `edittext_width_height` | compile_fail | 103/103 | - |
| `edittext_wordwrap_word` | compile_fail | 150/150 | - |
| `edittext_wrap_breaks` | compile_fail | 2375/2375 | - |
| `element_format_clone` | compile_fail | 44/44 | - |
| `element_format_constructor_order` | compile_fail | 64/64 | - |
| `element_format_properties` | compile_fail | 235/235 | - |
| `empty_bounds` | compile_fail | 1/1 | - |
| `encode_uri_surrogate_pair_invalid` | compile_fail | 8/8 | - |
| `encode_uri_surrogate_pair_swf11` | compile_fail | 15/15 | - |
| `equals` | compile_fail | 512/512 | - |
| `error_geterrormessage` | compile_fail | 779/779 | - |
| `error_prototype` | compile_fail | 15/15 | - |
| `error_stack_trace` | compile_fail | 45/45 | - |
| `error_stack_trace_debug_swf17` | compile_fail | 0/0 | - |
| `error_stack_trace_debug_swf18` | compile_fail | 0/0 | - |
| `error_stack_trace_edge_cases` | compile_fail | 6/6 | - |
| `error_stack_trace_release_swf17` | compile_fail | 0/0 | - |
| `error_stack_trace_release_swf18` | compile_fail | 0/0 | - |
| `error_throwerror` | compile_fail | 103/103 | - |
| `error_tostring` | compile_fail | 29/29 | - |
| `error_tostring_more` | compile_fail | 86/86 | - |
| `es3_inheritance` | compile_fail | 31/31 | - |
| `es4_inheritance` | compile_fail | 30/30 | - |
| `es4_interfaces` | compile_fail | 30/30 | - |
| `es4_method_binding` | compile_fail | 8/8 | - |
| `es4_oop_prototypes` | compile_fail | 14/14 | - |
| `es4_protected_inheritance` | compile_fail | 6/6 | - |
| `escape` | compile_fail | 71/71 | - |
| `escape_multi_byte` | compile_fail | 45/45 | - |
| `event_bubbles` | compile_fail | 2/2 | - |
| `event_cancelable` | compile_fail | 2/2 | - |
| `event_clone` | compile_fail | 20/20 | - |
| `event_clone_error_redispatch` | compile_fail | 3/3 | - |
| `event_clone_on_redispatch` | compile_fail | 10/10 | - |
| `event_formattostring` | compile_fail | 31/31 | - |
| `event_isdefaultprevented` | compile_fail | 12/12 | - |
| `event_target_getter` | compile_fail | 5/5 | - |
| `event_target_set` | compile_fail | 9/9 | - |
| `event_type` | compile_fail | 1/1 | - |
| `event_valueof_tostring` | compile_fail | 18/18 | - |
| `eventdispatcher_dispatchevent` | compile_fail | 12/12 | - |
| `eventdispatcher_dispatchevent_cancel` | compile_fail | 20/20 | - |
| `eventdispatcher_dispatchevent_handlerorder` | compile_fail | 22/22 | - |
| `eventdispatcher_dispatchevent_indirect` | compile_fail | 9/9 | - |
| `eventdispatcher_dispatchevent_this` | compile_fail | 5/5 | - |
| `eventdispatcher_haseventlistener` | compile_fail | 25/25 | - |
| `eventdispatcher_interface_invoke` | compile_fail | 1/1 | - |
| `eventdispatcher_tostring` | compile_fail | 10/10 | - |
| `eventdispatcher_willtrigger` | compile_fail | 25/25 | - |
| `falsiness` | compile_fail | 30/30 | - |
| `fast_index_access` | compile_fail | 12/12 | - |
| `filefilter_properties` | compile_fail | 4/4 | - |
| `filereference_browse_cancel` | compile_fail | 3/3 | - |
| `filereference_browse_select` | compile_fail | 9/9 | - |
| `filereference_load` | compile_fail | 31/31 | - |
| `filereference_save` | compile_fail | 16/16 | - |
| `filereference_save_and_browse` | compile_fail | 42/42 | - |
| `filereference_save_and_load` | compile_fail | 22/22 | - |
| `filereference_uninitialized` | compile_fail | 8/8 | - |
| `filereferencelist_browse_cancel` | compile_fail | 6/6 | - |
| `filereferencelist_browse_select` | compile_fail | 7/7 | - |
| `filter_rewind` | compile_fail | 8/8 | - |
| `filters_array_holes` | compile_fail | 25/25 | - |
| `finddef` | compile_fail | 3/3 | - |
| `findprop_global_prototype` | compile_fail | 6/6 | - |
| `flash_media_video_constructor` | compile_fail | 156/156 | - |
| `flash_media_video_rotation_probe` | compile_fail | 27/27 | - |
| `flash_media_video_setter` | compile_fail | 40/40 | - |
| `flash_trace` | compile_fail | 17/17 | - |
| `flash_xml` | compile_fail | 29/29 | - |
| `flash_xml_cloneNode` | compile_fail | 22/22 | - |
| `flash_xml_namespace` | compile_fail | 109/109 | - |
| `flash_xml_removeNode` | compile_fail | 60/60 | - |
| `focus_events_code` | compile_fail | 161/161 | - |
| `focus_events_key_basic` | compile_fail | 132/132 | - |
| `focus_events_key_navigation` | compile_fail | 53/53 | - |
| `focus_events_key_same_object` | compile_fail | 26/26 | - |
| `focus_events_mixed_key_mouse` | compile_fail | 100/100 | - |
| `focus_events_mouse_basic` | compile_fail | 260/260 | - |
| `focus_events_mouse_focusable` | compile_fail | 112/112 | - |
| `focus_events_mouse_same_object` | compile_fail | 40/40 | - |
| `focus_remove` | compile_fail | 20/20 | - |
| `focus_root_movie` | compile_fail | 4/4 | - |
| `focus_stage` | compile_fail | 1/1 | - |
| `focusrect` | compile_fail | 18/18 | - |
| `focusrect_focuslost` | compile_fail | 9/9 | - |
| `focusrect_property` | compile_fail | 110/110 | - |
| `font_description_clone` | compile_fail | 14/14 | - |
| `font_embedded` | compile_fail | 24/24 | - |
| `font_enumeratefonts` | compile_fail | 41/41 | - |
| `font_enumeratefonts_filter` | compile_fail | 4/4 | - |
| `font_enumeratefonts_order` | compile_fail | 9/9 | - |
| `font_hasglyphs` | compile_fail | 40/40 | - |
| `font_registerfont` | compile_fail | 129/129 | - |
| `framelabel_constr` | compile_fail | 5/5 | - |
| `function_call` | compile_fail | 12/12 | - |
| `function_call_arguments` | compile_fail | 46/46 | - |
| `function_call_arguments_enumerate` | compile_fail | 5/5 | - |
| `function_call_coercion` | compile_fail | 108/108 | - |
| `function_call_default` | compile_fail | 6/6 | - |
| `function_call_rest` | compile_fail | 22/22 | - |
| `function_call_types` | compile_fail | 3/3 | - |
| `function_call_via_apply` | compile_fail | 11/11 | - |
| `function_call_via_call` | compile_fail | 3/3 | - |
| `function_display_anonymous` | compile_fail | 7/7 | - |
| `function_length` | compile_fail | 6/6 | - |
| `function_object` | compile_fail | 2/2 | - |
| `function_proto` | compile_fail | 5/5 | - |
| `function_proto_created` | compile_fail | 61/61 | - |
| `function_to_locale_string` | compile_fail | 4/4 | - |
| `function_to_string` | compile_fail | 4/4 | - |
| `function_type` | compile_fail | 6/6 | - |
| `function_unbound_this` | compile_fail | 51/51 | - |
| `function_value_of` | compile_fail | 4/4 | - |
| `game_input` | compile_fail | 4/4 | - |
| `generate_random_bytes` | compile_fail | 3/3 | - |
| `get_definition_by_name` | compile_fail | 11/11 | - |
| `get_qualified_class_name` | compile_fail | 20/20 | - |
| `get_qualified_super_class_name` | compile_fail | 18/18 | - |
| `get_slot_edge_cases` | compile_fail | 1/1 | - |
| `get_timer` | compile_fail | 2/2 | - |
| `getglobalslot` | compile_fail | 1/1 | - |
| `getouterscope` | compile_fail | 8/8 | - |
| `getouterscope_two_classobjects` | compile_fail | 13/13 | - |
| `getter_different_namespace_setter` | compile_fail | 2/2 | - |
| `glow_filter` | compile_fail | 127/127 | - |
| `goto_button_nested_framescript` | compile_fail | 28/28 | - |
| `goto_in_constructframe` | compile_fail | 12/12 | - |
| `goto_in_scene_last_frame` | compile_fail | 2/2 | - |
| `goto_methods` | compile_fail | 56/56 | - |
| `goto_methods_swfver10` | compile_fail | 8/8 | - |
| `goto_nested_construct_sibling` | compile_fail | 18/18 | - |
| `goto_nested_framescript` | compile_fail | 9/9 | - |
| `goto_on_orphan` | compile_fail | 15/15 | - |
| `gradient_bevel_filter` | compile_fail | 206/206 | - |
| `gradient_glow_filter` | compile_fail | 206/206 | - |
| `graphic_linkage` | compile_fail | 9/9 | - |
| `graphics_bad_direct_commands` | compile_fail | 5/5 | - |
| `graphics_bitmap_fill` | compile_fail | 0/0 | - |
| `graphics_bitmaps` | compile_fail | 0/0 | - |
| `graphics_direct_commands` | compile_fail | 0/0 | - |
| `graphics_draw_triangles` | compile_fail | 98/98 | - |
| `graphics_gradients` | compile_fail | 0/0 | - |
| `graphics_gradients_nulls` | compile_fail | 0/0 | - |
| `graphics_path` | compile_fail | 56/56 | - |
| `graphics_round_rects` | compile_fail | 0/0 | - |
| `graphics_simple_shapes` | compile_fail | 0/0 | - |
| `greaterequals` | compile_fail | 512/512 | - |
| `greaterthan` | compile_fail | 512/512 | - |
| `has_own_property` | compile_fail | 102/102 | - |
| `hasownproperty_namespaces` | compile_fail | 2/2 | - |
| `hello_world` | compile_fail | 1/1 | - |
| `hittest_morph` | compile_fail | 30/30 | - |
| `if_eq` | compile_fail | 10/10 | - |
| `if_gt` | compile_fail | 1/1 | - |
| `if_gte` | compile_fail | 10/10 | - |
| `if_lt` | compile_fail | 1/1 | - |
| `if_lte` | compile_fail | 10/10 | - |
| `if_ne` | compile_fail | 7/7 | - |
| `if_stricteq` | compile_fail | 6/6 | - |
| `if_strictne` | compile_fail | 11/11 | - |
| `ime_linux_dead_keys` | compile_fail | 10/10 | - |
| `in` | compile_fail | 102/102 | - |
| `inclocal` | compile_fail | 46/46 | - |
| `inclocal_i` | compile_fail | 46/46 | - |
| `increment` | compile_fail | 46/46 | - |
| `increment_i` | compile_fail | 46/46 | - |
| `indexing_delete` | compile_fail | 75/75 | - |
| `instanceof` | compile_fail | 58/58 | - |
| `instantiate_root_character` | compile_fail | 4/4 | - |
| `instantiation_on_enter_frame` | compile_fail | 7/7 | - |
| `instantiation_on_enterframe_gotoandstop` | compile_fail | 8/8 | - |
| `int_constr` | compile_fail | 92/92 | - |
| `int_edge_cases` | compile_fail | 19/19 | - |
| `int_instanceof` | compile_fail | 3/3 | - |
| `int_tofixed` | compile_fail | 1215/1215 | - |
| `int_tostring` | compile_fail | 3375/3375 | - |
| `interactiveobject_enabled` | compile_fail | 25/25 | - |
| `interface_namespaces` | compile_fail | 78/78 | - |
| `invalid_utf8` | compile_fail | 12/12 | - |
| `is_finite` | compile_fail | 46/46 | - |
| `is_nan` | compile_fail | 46/46 | - |
| `is_prototype_of` | compile_fail | 12/12 | - |
| `issue_10221` | compile_fail | 2/2 | - |
| `issue_13780` | compile_fail | 12/12 | - |
| `issue_14901` | compile_fail | 1/1 | - |
| `issue_17675_edittext_paste_maxchars` | compile_fail | 1/1 | - |
| `issue_5292` | compile_fail | 5/5 | - |
| `issue_8630` | compile_fail | 2/2 | - |
| `issue_8630_placeremoveplace` | compile_fail | 15/15 | - |
| `issue_8630_placeremoveplace_scriptremove` | compile_fail | 16/16 | - |
| `issue_8630_scriptremove` | compile_fail | 11/11 | - |
| `istype` | compile_fail | 24/24 | - |
| `istypelate` | compile_fail | 58/58 | - |
| `istypelate_coerce` | compile_fail | 198/198 | - |
| `jpeg_loader_context` | compile_fail | 6/6 | - |
| `json_errors` | compile_fail | 9/9 | - |
| `json_parse` | compile_fail | 21/21 | - |
| `json_stringify` | compile_fail | 12/12 | - |
| `json_stringify_function` | compile_fail | 12/12 | - |
| `json_stringify_order` | compile_fail | 1/1 | - |
| `json_version_gated` | compile_fail | 1/1 | - |
| `key_input_80percent` | compile_fail | 1812/1812 | - |
| `key_input_location` | compile_fail | 126/126 | - |
| `key_input_numpad` | compile_fail | 384/384 | - |
| `lazyinit` | compile_fail | 17/17 | - |
| `lessequals` | compile_fail | 512/512 | - |
| `lessthan` | compile_fail | 512/512 | - |
| `loader_bitmap_transparency` | compile_fail | 14/14 | - |
| `loader_bytes_unknown_content` | compile_fail | 14/14 | - |
| `loader_child_getdefinition` | compile_fail | 5/5 | - |
| `loader_duplicate_coerce` | compile_fail | 3/3 | - |
| `loader_duplicate_coerce_new_domain` | compile_fail | 4/4 | - |
| `loader_error_in_root_ctor` | compile_fail | 4/4 | - |
| `loader_events` | compile_fail | 92/92 | - |
| `loader_image` | compile_fail | 8/8 | - |
| `loader_jpegxr` | compile_fail | 2/2 | - |
| `loader_jpegxr_alpha` | compile_fail | 1/1 | - |
| `loader_loadbytes_events` | compile_fail | 30/30 | - |
| `loader_loadbytes_invalid_png` | compile_fail | 4/4 | - |
| `loader_loadbytes_url` | compile_fail | 12/12 | - |
| `loader_loaderurl` | compile_fail | 6/6 | - |
| `loader_method` | compile_fail | 85/85 | - |
| `loader_noninteractive_try_click_root` | compile_fail | 5/5 | - |
| `loader_reuse` | compile_fail | 38/38 | - |
| `loader_unknown_content` | compile_fail | 24/24 | - |
| `loader_visibility_interactive` | compile_fail | 1/1 | - |
| `loaderinfo_events` | compile_fail | 7/7 | - |
| `loaderinfo_loadurl` | compile_fail | 12/12 | - |
| `loaderinfo_more` | compile_fail | 6/6 | - |
| `loaderinfo_properties` | compile_fail | 18/18 | - |
| `loaderinfo_properties_not_loaded` | compile_fail | 23/23 | - |
| `loaderinfo_quine` | compile_fail | 1005/1005 | - |
| `loaderinfo_root` | compile_fail | 10/10 | - |
| `loaderinfo_root_allows` | compile_fail | 2/2 | - |
| `localconnection_send` | compile_fail | 4/4 | - |
| `lshift` | compile_fail | 1058/1058 | - |
| `mask_reapply` | compile_fail | 1/1 | - |
| `math` | compile_fail | 497/497 | - |
| `matrix3d` | compile_fail | 57/57 | - |
| `matrix3d_compose` | compile_fail | 34/34 | - |
| `matrix3d_invert` | compile_fail | 18/18 | - |
| `matrix3d_position` | compile_fail | 19/19 | - |
| `matrix3d_transpose` | compile_fail | 5/5 | - |
| `method_without_body` | compile_fail | 3/3 | - |
| `missing_external_interface` | compile_fail | 10/10 | - |
| `modulo` | compile_fail | 1058/1058 | - |
| `morph_shape` | compile_fail | 2/2 | - |
| `mouse_children` | compile_fail | 192/192 | - |
| `mouse_click_events` | compile_fail | 90/90 | - |
| `mouse_double_click_events` | compile_fail | 188/188 | - |
| `mouse_empty_parent` | compile_fail | 4/4 | - |
| `mouse_over_while_dragging` | compile_fail | 3/3 | - |
| `mouse_pick_button_mode` | compile_fail | 2/2 | - |
| `mouse_pick_dobj_mask` | compile_fail | 4/4 | - |
| `mouse_pick_masking` | compile_fail | 7/7 | - |
| `mouse_pick_non_interactive_bitmap_mask` | compile_fail | 4/4 | - |
| `mouse_pick_non_interactive_dobj_mask` | compile_fail | 3/3 | - |
| `mouse_pick_text` | compile_fail | 8/8 | - |
| `mouse_sibling` | compile_fail | 8/8 | - |
| `mouse_wheel_events` | compile_fail | 36/36 | - |
| `mouseevent_constr` | compile_fail | 66/66 | - |
| `mouseevent_stagexy` | compile_fail | 35/35 | - |
| `mouseevent_valueof_tostring` | compile_fail | 28/28 | - |
| `movieclip_addframescript` | compile_fail | 3/3 | - |
| `movieclip_child_property` | compile_fail | 16/16 | - |
| `movieclip_constr` | compile_fail | 21/21 | - |
| `movieclip_currentlabels` | compile_fail | 17/17 | - |
| `movieclip_currentlabels_dupes1` | compile_fail | 46/46 | - |
| `movieclip_currentlabels_dupes2` | compile_fail | 30/30 | - |
| `movieclip_currentlabels_dupes3` | compile_fail | 67/67 | - |
| `movieclip_currentscene` | compile_fail | 12/12 | - |
| `movieclip_dispatchevent` | compile_fail | 430/430 | - |
| `movieclip_dispatchevent_cancel` | compile_fail | 102/102 | - |
| `movieclip_dispatchevent_handlerorder` | compile_fail | 251/251 | - |
| `movieclip_dispatchevent_selfadd` | compile_fail | 80/80 | - |
| `movieclip_dispatchevent_target` | compile_fail | 899/899 | - |
| `movieclip_displayevents` | compile_fail | 96/96 | - |
| `movieclip_displayevents_clickgoto` | compile_fail | 676/676 | - |
| `movieclip_displayevents_clickgoto2` | compile_fail | 2001/2001 | - |
| `movieclip_displayevents_clickplay` | compile_fail | 575/575 | - |
| `movieclip_displayevents_clicksymbol` | compile_fail | 562/562 | - |
| `movieclip_displayevents_constructframegoto` | compile_fail | 140/140 | - |
| `movieclip_displayevents_constructframeplay` | compile_fail | 50/50 | - |
| `movieclip_displayevents_constructframesymbol` | compile_fail | 144/144 | - |
| `movieclip_displayevents_dblhandler` | compile_fail | 21/21 | - |
| `movieclip_displayevents_enterframegoto` | compile_fail | 149/149 | - |
| `movieclip_displayevents_enterframeplay` | compile_fail | 48/48 | - |
| `movieclip_displayevents_enterframesymbol` | compile_fail | 149/149 | - |
| `movieclip_displayevents_exitframegoto` | compile_fail | 106/106 | - |
| `movieclip_displayevents_exitframeplay` | compile_fail | 44/44 | - |
| `movieclip_displayevents_exitframesymbol` | compile_fail | 135/135 | - |
| `movieclip_displayevents_looping` | compile_fail | 63/63 | - |
| `movieclip_displayevents_stopped` | compile_fail | 113/113 | - |
| `movieclip_displayevents_swap` | compile_fail | 96/96 | - |
| `movieclip_displayevents_timeline` | compile_fail | 128/128 | - |
| `movieclip_drawrect` | compile_fail | 54/54 | - |
| `movieclip_frameconstruct_skipped` | compile_fail | 9/9 | - |
| `movieclip_goto_during_frame_script` | compile_fail | 15/15 | - |
| `movieclip_goto_overwrite` | compile_fail | 14/14 | - |
| `movieclip_goto_scene_last_frame_int` | compile_fail | 1/1 | - |
| `movieclip_goto_scene_last_frame_label` | compile_fail | 1/1 | - |
| `movieclip_gotoandplay` | compile_fail | 15/15 | - |
| `movieclip_gotoandstop` | compile_fail | 13/13 | - |
| `movieclip_gotoandstop_children` | compile_fail | 4/4 | - |
| `movieclip_gotoandstop_framescripts1` | compile_fail | 4/4 | - |
| `movieclip_gotoandstop_framescripts2` | compile_fail | 4/4 | - |
| `movieclip_gotoandstop_framescripts_self` | compile_fail | 7/7 | - |
| `movieclip_gotoandstop_queueing` | compile_fail | 12/12 | - |
| `movieclip_hittest` | compile_fail | 67/67 | - |
| `movieclip_next_frame` | compile_fail | 2/2 | - |
| `movieclip_next_scene` | compile_fail | 6/6 | - |
| `movieclip_play` | compile_fail | 3/3 | - |
| `movieclip_prev_frame` | compile_fail | 3/3 | - |
| `movieclip_prev_scene` | compile_fail | 7/7 | - |
| `movieclip_properties` | compile_fail | 79/79 | - |
| `movieclip_queued_noop_goto_swf10` | compile_fail | 9/9 | - |
| `movieclip_queued_noop_goto_swf9` | compile_fail | 7/7 | - |
| `movieclip_scenes` | compile_fail | 11/11 | - |
| `movieclip_soundtransform` | compile_fail | 831/831 | - |
| `movieclip_stop` | compile_fail | 1/1 | - |
| `movieclip_super_is_symbol` | compile_fail | 20/20 | - |
| `movieclip_symbol_constr` | compile_fail | 8/8 | - |
| `movieclip_text_mousedown` | compile_fail | 1/1 | - |
| `movieclip_willtrigger` | compile_fail | 5/5 | - |
| `multiply` | compile_fail | 1058/1058 | - |
| `namespace_constr` | compile_fail | 253/253 | - |
| `namespace_constr_args` | compile_fail | 1/1 | - |
| `namespace_enumeration_order` | compile_fail | 7/7 | - |
| `nan_scale` | compile_fail | 9/9 | - |
| `navigateToURL_target_normalize` | compile_fail | 107/107 | - |
| `negate` | compile_fail | 30/30 | - |
| `negative_volume_panned` | compile_fail | 0/0 | - |
| `nested_iteration` | compile_fail | 11/11 | - |
| `net_getClassByAlias` | compile_fail | 3/3 | - |
| `net_navigateToURL` | compile_fail | 57/57 | - |
| `net_stream_play_options` | compile_fail | 6/6 | - |
| `netconnection_close` | compile_fail | 55/55 | - |
| `netconnection_properties` | compile_fail | 78/78 | - |
| `netconnection_send_remote` | compile_fail | 50/50 | - |
| `netconnection_serialize_arrays` | compile_fail | 6/6 | - |
| `netfilterevent` | compile_fail | 10/10 | - |
| `netstream_client` | compile_fail | 10/10 | - |
| `netstream_connect` | compile_fail | 7/7 | - |
| `netstream_flv_date` | compile_fail | 4/4 | - |
| `newactivation_in_script_init` | compile_fail | 3/3 | - |
| `newclass_mismatched` | compile_fail | 4/4 | - |
| `newclass_twice` | compile_fail | 3/3 | - |
| `nonconflicting_declarations` | compile_fail | 0/0 | - |
| `null_void_types` | compile_fail | 8/8 | - |
| `number_autoconv` | compile_fail | 21/21 | - |
| `number_autoconv_amf` | compile_fail | 132/132 | - |
| `number_autoconv_array_sort_32bit` | compile_fail | 1/1 | - |
| `number_constr` | compile_fail | 58/58 | - |
| `number_toexponential` | compile_fail | 378/378 | - |
| `number_toexponential2` | compile_fail | 35/35 | - |
| `number_tofixed` | compile_fail | 378/378 | - |
| `number_toprecision` | compile_fail | 350/350 | - |
| `obfuscated_class_names` | compile_fail | 3/3 | - |
| `object_enumeration` | compile_fail | 10/10 | - |
| `object_prototype` | compile_fail | 4/4 | - |
| `object_to_locale_string` | compile_fail | 2/2 | - |
| `object_to_string` | compile_fail | 2/2 | - |
| `object_value_of` | compile_fail | 2/2 | - |
| `op_coerce` | compile_fail | 54/54 | - |
| `op_coerce_x` | compile_fail | 54/54 | - |
| `op_escxattr` | compile_fail | 2/2 | - |
| `op_escxelem` | compile_fail | 2/2 | - |
| `op_lookupswitch` | compile_fail | 4/4 | - |
| `optimize_coerce` | compile_fail | 1/1 | - |
| `orphan_movie_complex` | compile_fail | 80/80 | - |
| `orphan_movie_reorder` | compile_fail | 111/111 | - |
| `package_namespace` | compile_fail | 7/7 | - |
| `param_default_value_has_zero_cpool_index` | compile_fail | 1/1 | - |
| `parent_early_access_child` | compile_fail | 16/16 | - |
| `parse_float` | compile_fail | 81/81 | - |
| `parse_float_swf10` | compile_fail | 81/81 | - |
| `parse_int` | compile_fail | 135/135 | - |
| `perspective_projection` | compile_fail | 1443/1443 | - |
| `perspective_projection_basic` | compile_fail | 40/40 | - |
| `pixelbender_ceil` | compile_fail | 77/77 | - |
| `pixelbender_conditional` | compile_fail | 138/138 | - |
| `pixelbender_conversions` | compile_fail | 270/270 | - |
| `pixelbender_dithering` | compile_fail | 8/8 | - |
| `pixelbender_div` | compile_fail | 36/36 | - |
| `pixelbender_effect_BlurredFocus` | compile_fail | 0/0 | - |
| `pixelbender_effect_glassDisplace` | compile_fail | 0/0 | - |
| `pixelbender_effect_glassDisplace_shaderfilter` | compile_fail | 4/4 | - |
| `pixelbender_effect_smudge` | compile_fail | 0/0 | - |
| `pixelbender_effect_tintype` | compile_fail | 0/0 | - |
| `pixelbender_effect_twirl` | compile_fail | 0/0 | - |
| `pixelbender_eof` | compile_fail | 7/7 | - |
| `pixelbender_images` | compile_fail | 0/0 | - |
| `pixelbender_input` | compile_fail | 103/103 | - |
| `pixelbender_logicalnot` | compile_fail | 20/20 | - |
| `pixelbender_malformed_data` | compile_fail | 190/190 | - |
| `pixelbender_multiple_out_params` | compile_fail | 1/1 | - |
| `pixelbender_no_out_param` | compile_fail | 6/6 | - |
| `pixelbender_outputs` | compile_fail | 13/13 | - |
| `pixelbender_padding_bytes` | compile_fail | 22/22 | - |
| `pixelbender_param_qualifier` | compile_fail | 512/512 | - |
| `pixelbender_parameters` | compile_fail | 1563/1563 | - |
| `pixelbender_parameters_bool` | compile_fail | 240/240 | - |
| `pixelbender_parameters_int_vs_bool` | compile_fail | 54/54 | - |
| `pixelbender_parse_errors` | compile_fail | 6/6 | - |
| `pixelbender_rsqrt` | compile_fail | 24/24 | - |
| `pixelbender_select_kinds` | compile_fail | 8/8 | - |
| `pixelbender_shaderdata` | compile_fail | 49/49 | - |
| `pixelbender_shaderdata_setter` | compile_fail | 99/99 | - |
| `pixelbender_sign` | compile_fail | 60/60 | - |
| `pixelbender_vector_output` | compile_fail | 11/11 | - |
| `place_and_lookup/swf10` | compile_fail | 33/33 | - |
| `place_and_lookup/swf9` | compile_fail | 33/33 | - |
| `place_multiple` | compile_fail | 17/17 | - |
| `place_object_replace` | compile_fail | 9/9 | - |
| `place_object_replace_2` | compile_fail | 24/24 | - |
| `place_object_same_depth_frame` | compile_fail | 1/1 | - |
| `point` | compile_fail | 132/132 | - |
| `primitive_edge_cases` | compile_fail | 1/1 | - |
| `primitive_toString` | compile_fail | 277/277 | - |
| `primitive_valueOf` | compile_fail | 285/285 | - |
| `print_job_options` | compile_fail | 3/3 | - |
| `property_is_enumerable` | compile_fail | 114/114 | - |
| `property_is_enumerable_reset` | compile_fail | 23/23 | - |
| `property_priority` | compile_fail | 22/22 | - |
| `property_priority_chained` | compile_fail | 4/4 | - |
| `property_priority_definition_names_order` | compile_fail | 2/2 | - |
| `property_priority_three_level` | compile_fail | 6/6 | - |
| `propertyisenumerable_namespaces` | compile_fail | 6/6 | - |
| `prototype_set_null` | compile_fail | 7/7 | - |
| `proxy_callproperty` | compile_fail | 24/24 | - |
| `proxy_deleteproperty` | compile_fail | 64/64 | - |
| `proxy_enumeration` | compile_fail | 34/34 | - |
| `proxy_getproperty` | compile_fail | 77/77 | - |
| `proxy_hasownproperty` | compile_fail | 8/8 | - |
| `proxy_hasproperty` | compile_fail | 32/32 | - |
| `proxy_not_overridden` | compile_fail | 54/54 | - |
| `proxy_serialize` | compile_fail | 9/9 | - |
| `proxy_setproperty` | compile_fail | 42/42 | - |
| `qname_as_lazy_name_attribute_multiname` | compile_fail | 1/1 | - |
| `qname_constr` | compile_fail | 32/32 | - |
| `qname_constr_namespace` | compile_fail | 24/24 | - |
| `qname_enumeration` | compile_fail | 9/9 | - |
| `qname_indexing` | compile_fail | 23/23 | - |
| `qname_tostring` | compile_fail | 25/25 | - |
| `qname_valueof` | compile_fail | 29/29 | - |
| `rectangle` | compile_fail | 1094/1094 | - |
| `regexp_constr` | compile_fail | 148/148 | - |
| `regexp_exec` | compile_fail | 19/19 | - |
| `regexp_extended` | compile_fail | 47/47 | - |
| `regexp_multiargs` | compile_fail | 1/1 | - |
| `regexp_test` | compile_fail | 27/27 | - |
| `regexp_toString` | compile_fail | 10/10 | - |
| `register_script_refresh` | compile_fail | 35/35 | - |
| `remove_child_clear_field` | compile_fail | 88/88 | - |
| `remove_dobj` | compile_fail | 3/3 | - |
| `resolve_order` | compile_fail | 4/4 | - |
| `responder_null_callbacks` | compile_fail | 1/1 | - |
| `rng` | compile_fail | 1/1 | - |
| `rootless` | compile_fail | 42/42 | - |
| `rshift` | compile_fail | 1058/1058 | - |
| `rtqname_not_namespace` | compile_fail | 12/12 | - |
| `sandbox_type_inherited` | compile_fail | 2/2 | - |
| `sandbox_type_local_file` | compile_fail | 1/1 | - |
| `sandbox_type_local_network` | compile_fail | 1/1 | - |
| `scene_constr` | compile_fail | 8/8 | - |
| `scopes_dont_cache/order-1` | compile_fail | 1/1 | - |
| `scopes_dont_cache/order-2` | compile_fail | 1/1 | - |
| `security_domain_current` | compile_fail | 2/2 | - |
| `selection` | compile_fail | 239/239 | - |
| `set_local_0` | compile_fail | 31/31 | - |
| `set_property_is_enumerable` | compile_fail | 85/85 | - |
| `shaderparameter_value` | compile_fail | 4/4 | - |
| `shape_drawrect` | compile_fail | 54/54 | - |
| `shared_object_no_root` | compile_fail | 3/3 | - |
| `simplebutton_added_to_stage` | compile_fail | 45/45 | - |
| `simplebutton_childevents` | compile_fail | 86/86 | - |
| `simplebutton_childevents_nested` | compile_fail | 54/54 | - |
| `simplebutton_childevents_sprite` | compile_fail | 13/13 | - |
| `simplebutton_childprops` | compile_fail | 144/144 | - |
| `simplebutton_childshuffle` | compile_fail | 23/23 | - |
| `simplebutton_constr` | compile_fail | 36/36 | - |
| `simplebutton_constr_childevents` | compile_fail | 48/48 | - |
| `simplebutton_constr_params` | compile_fail | 42/42 | - |
| `simplebutton_mouseenabled` | compile_fail | 26/26 | - |
| `simplebutton_multi_children` | compile_fail | 19/19 | - |
| `simplebutton_structure` | compile_fail | 27/27 | - |
| `simplebutton_symbolclass` | compile_fail | 68/68 | - |
| `slot_disp_id_shared_numbering` | compile_fail | 1/1 | - |
| `slots_force_autoassigned` | compile_fail | 1/1 | - |
| `socket_after_disconnect` | compile_fail | 1/1 | - |
| `socket_close` | compile_fail | 2/2 | - |
| `socket_connect` | compile_fail | 4/4 | - |
| `socket_errors` | compile_fail | 56/56 | - |
| `socket_read_big` | compile_fail | 48/48 | - |
| `socket_read_little` | compile_fail | 48/48 | - |
| `socket_read_write_object` | compile_fail | 8/8 | - |
| `socket_write_big` | compile_fail | 15/15 | - |
| `socket_write_little` | compile_fail | 14/14 | - |
| `sound_constructor_with_args` | compile_fail | 6/6 | - |
| `sound_embeddedprops` | compile_fail | 26/26 | - |
| `sound_play` | compile_fail | 19/19 | - |
| `sound_rootless` | compile_fail | 7/7 | - |
| `sound_valueof` | compile_fail | 33/33 | - |
| `soundchannel_soundtransform` | compile_fail | 835/835 | - |
| `soundchannel_soundtransform_exists` | compile_fail | 5/5 | - |
| `soundchannel_stop` | compile_fail | 8/8 | - |
| `soundmixer_buffertime` | compile_fail | 5/5 | - |
| `soundmixer_stopall` | compile_fail | 6/6 | - |
| `soundtransform` | compile_fail | 442/442 | - |
| `space_justifier_clone` | compile_fail | 12/12 | - |
| `sprite_with_frames` | compile_fail | 0/0 | - |
| `stage3d_agal_cross_product` | compile_fail | 0/0 | - |
| `stage3d_agal_upload_errors` | compile_fail | 66/66 | - |
| `stage3d_bitmap` | compile_fail | 0/0 | - |
| `stage3d_blend` | compile_fail | 81/81 | - |
| `stage3d_context3d_string_args` | compile_fail | 158/158 | - |
| `stage3d_errors` | compile_fail | 7/7 | - |
| `stage3d_errors_atf` | compile_fail | 3/3 | - |
| `stage3d_errors_swf_29` | compile_fail | 6/6 | - |
| `stage3d_float1_index` | compile_fail | 0/0 | - |
| `stage3d_fractal` | compile_fail | 0/0 | - |
| `stage3d_ignore_sampler_override` | compile_fail | 0/0 | - |
| `stage3d_multistage_triangle` | compile_fail | 3/3 | - |
| `stage3d_program_constants_bytearray_be` | compile_fail | 0/0 | - |
| `stage3d_program_constants_bytearray_le` | compile_fail | 0/0 | - |
| `stage3d_program_constants_invalid_input` | compile_fail | 21/21 | - |
| `stage3d_raytrace` | compile_fail | 0/0 | - |
| `stage3d_rotating_cube` | compile_fail | 0/0 | - |
| `stage3d_sampler` | compile_fail | 0/0 | - |
| `stage3d_sampler_partial_upload` | compile_fail | 0/0 | - |
| `stage3d_stencil` | compile_fail | 0/0 | - |
| `stage3d_texture` | compile_fail | 0/0 | - |
| `stage3d_texture_bytearray` | compile_fail | 0/0 | - |
| `stage3d_texture_bytearray_compressed_alpha` | compile_fail | 0/0 | - |
| `stage3d_texture_bytearray_compressed_raw_alpha` | compile_fail | 0/0 | - |
| `stage3d_triangle` | compile_fail | 0/0 | - |
| `stage3d_triangle_bytes4` | compile_fail | 0/0 | - |
| `stage3d_triangle_float1` | compile_fail | 0/0 | - |
| `stage3d_triangle_index_upload` | compile_fail | 0/0 | - |
| `stage3d_x_y` | compile_fail | 22/22 | - |
| `stage_access` | compile_fail | 10/10 | - |
| `stage_displayobject_properties` | compile_fail | 24/24 | - |
| `stage_domain_getQualifiedDefinitionNames` | compile_fail | 5/5 | - |
| `stage_framerate_nan` | compile_fail | 7/7 | - |
| `stage_framerate_negative` | compile_fail | 6/6 | - |
| `stage_framerate_zero` | compile_fail | 6/6 | - |
| `stage_invalidate` | compile_fail | 38/38 | - |
| `stage_loaderinfo_properties` | compile_fail | 24/24 | - |
| `stage_mousechildren` | compile_fail | 2/2 | - |
| `stage_mouseenabled` | compile_fail | 15/15 | - |
| `stage_overriden_setters` | compile_fail | 31/31 | - |
| `stage_properties` | compile_fail | 30/30 | - |
| `stage_properties2` | compile_fail | 213/213 | - |
| `stage_stage3Ds_vector` | compile_fail | 1/1 | - |
| `static_length` | compile_fail | 24/24 | - |
| `static_text` | compile_fail | 3/3 | - |
| `static_var_with_this_in_ctor` | compile_fail | 2/2 | - |
| `statictext_text` | compile_fail | 8/8 | - |
| `stored_properties` | compile_fail | 11/11 | - |
| `strict_equality` | compile_fail | 34/34 | - |
| `string_call` | compile_fail | 13/13 | - |
| `string_case` | compile_fail | 23/23 | - |
| `string_char_at` | compile_fail | 27/27 | - |
| `string_char_code_at` | compile_fail | 28/28 | - |
| `string_concat_fromcharcode` | compile_fail | 37/37 | - |
| `string_constr` | compile_fail | 25/25 | - |
| `string_indexof_lastindexof` | compile_fail | 87/87 | - |
| `string_length` | compile_fail | 16/16 | - |
| `string_locale_compare` | compile_fail | 39/39 | - |
| `string_match` | compile_fail | 51/51 | - |
| `string_relational_compare` | compile_fail | 4/4 | - |
| `string_replace` | compile_fail | 51/51 | - |
| `string_search` | compile_fail | 41/41 | - |
| `string_slice_substr_substring` | compile_fail | 170/170 | - |
| `string_split` | compile_fail | 29/29 | - |
| `string_substr_negative` | compile_fail | 21/21 | - |
| `string_substr_weird` | compile_fail | 182/182 | - |
| `stylesheet` | compile_fail | 221/221 | - |
| `stylesheet_parse_color` | compile_fail | 69/69 | - |
| `stylesheet_transform` | compile_fail | 307/307 | - |
| `subclass_superclass_linked_symbol` | compile_fail | 4/4 | - |
| `subtract` | compile_fail | 1058/1058 | - |
| `super_get_call` | compile_fail | 12/12 | - |
| `supercall_two_classobjects` | compile_fail | 2/2 | - |
| `supercalls_weird` | compile_fail | 2/2 | - |
| `superinterface_call` | compile_fail | 20/20 | - |
| `superinterface_instanceof` | compile_fail | 18/18 | - |
| `swf8` | compile_fail | 1/1 | - |
| `swf_10_queued_goto_scripts_construct` | compile_fail | 52/52 | - |
| `swf_9_goto_in_enter_frame` | compile_fail | 17/17 | - |
| `swf_9_goto_in_enter_frame_simple` | compile_fail | 15/15 | - |
| `swf_9_queued_goto_scripts` | compile_fail | 6/6 | - |
| `swf_9_queued_goto_scripts_construct` | compile_fail | 28/28 | - |
| `swf_9_versioning` | compile_fail | 2/2 | - |
| `swf_wrong_frame_count` | compile_fail | 38/38 | - |
| `swf_wrong_frame_count_isplaying` | compile_fail | 22/22 | - |
| `symbol_class_binary_data` | compile_fail | 8/8 | - |
| `symbol_class_conflict` | compile_fail | 4/4 | - |
| `symbol_class_root_not_zero` | compile_fail | 1/1 | - |
| `symbolclass_invalid_utf8` | compile_fail | 2/2 | - |
| `system_exit` | compile_fail | 3/3 | - |
| `system_setclipboard_null` | compile_fail | 1/1 | - |
| `tab_ordering_arrows` | compile_fail | 998/998 | - |
| `tab_ordering_automatic_advanced` | compile_fail | 184/184 | - |
| `tab_ordering_automatic_basic` | compile_fail | 45/45 | - |
| `tab_ordering_children` | compile_fail | 116/116 | - |
| `tab_ordering_custom_basic` | compile_fail | 34/34 | - |
| `tab_ordering_stage_tab_children` | compile_fail | 32/32 | - |
| `tab_ordering_stage_tab_children_remove_root` | compile_fail | 5/5 | - |
| `tab_ordering_tabbable` | compile_fail | 47/47 | - |
| `tabstop_properties` | compile_fail | 105/105 | - |
| `text_element_basic` | compile_fail | 34/34 | - |
| `text_engine_fontdescription` | compile_fail | 27/27 | - |
| `text_engine_groupelement` | compile_fail | 64/64 | - |
| `text_run` | compile_fail | 7/7 | - |
| `textblock_createline_errors` | compile_fail | 23/23 | - |
| `textblock_createline_fte` | compile_fail | 9/9 | - |
| `textblock_properties` | compile_fail | 118/118 | - |
| `textbox_click` | compile_fail | 37/37 | - |
| `textfield_event` | compile_fail | 66/66 | - |
| `textfield_focusin_event` | compile_fail | 9/9 | - |
| `textfield_input_dead_keys_windows` | compile_fail | 15/15 | - |
| `textfield_unload` | compile_fail | 39/39 | - |
| `textformat` | compile_fail | 1134/1134 | - |
| `textformat_display` | compile_fail | 14/14 | - |
| `textformat_font_max_length` | compile_fail | 4/4 | - |
| `textline_inapplicable_properties` | compile_fail | 10/10 | - |
| `textline_name` | compile_fail | 1/1 | - |
| `textline_splitting_basic` | compile_fail | 76/76 | - |
| `textline_throwerror` | compile_fail | 30/30 | - |
| `textline_validity` | compile_fail | 162/162 | - |
| `throw` | compile_fail | 3/3 | - |
| `timeline_scripts` | compile_fail | 3/3 | - |
| `timer` | compile_fail | 90/90 | - |
| `timer_events` | compile_fail | 3/3 | - |
| `timer_finished` | compile_fail | 11/11 | - |
| `timer_invalid_delay` | compile_fail | 30/30 | - |
| `timer_reset` | compile_fail | 8/8 | - |
| `timer_setdelay` | compile_fail | 5/5 | - |
| `trace` | compile_fail | 12/12 | - |
| `truthiness` | compile_fail | 30/30 | - |
| `try_catch` | compile_fail | 11/11 | - |
| `try_catch_typed` | compile_fail | 12/12 | - |
| `typeof` | compile_fail | 30/30 | - |
| `uint_constr` | compile_fail | 92/92 | - |
| `uint_tofixed` | compile_fail | 1215/1215 | - |
| `uint_tostring` | compile_fail | 3375/3375 | - |
| `uncaught_error_basic` | compile_fail | 2/2 | - |
| `unchecked_function` | compile_fail | 15/15 | - |
| `unescape` | compile_fail | 28/28 | - |
| `url_loader` | compile_fail | 25/25 | - |
| `url_vars` | compile_fail | 27/27 | - |
| `urlrequest` | compile_fail | 18/18 | - |
| `urlstream_basic` | compile_fail | 5/5 | - |
| `urshift` | compile_fail | 1058/1058 | - |
| `utils3d` | compile_fail | 7/7 | - |
| `vector3d` | compile_fail | 397/397 | - |
| `vector_class` | compile_fail | 36/36 | - |
| `vector_class_call` | compile_fail | 11/11 | - |
| `vector_coercion` | compile_fail | 66/66 | - |
| `vector_concat` | compile_fail | 90/90 | - |
| `vector_constr` | compile_fail | 107/107 | - |
| `vector_enumeration` | compile_fail | 5/5 | - |
| `vector_every` | compile_fail | 92/92 | - |
| `vector_filter` | compile_fail | 95/95 | - |
| `vector_holes` | compile_fail | 24/24 | - |
| `vector_indexof` | compile_fail | 302/302 | - |
| `vector_insertat` | compile_fail | 270/270 | - |
| `vector_int_access` | compile_fail | 4/4 | - |
| `vector_int_delete` | compile_fail | 11/11 | - |
| `vector_join` | compile_fail | 58/58 | - |
| `vector_lastindexof` | compile_fail | 302/302 | - |
| `vector_legacy` | compile_fail | 10/10 | - |
| `vector_map` | compile_fail | 85/85 | - |
| `vector_object_final` | compile_fail | 1/1 | - |
| `vector_object_toString` | compile_fail | 10/10 | - |
| `vector_pushpop` | compile_fail | 255/255 | - |
| `vector_reborrow_bug` | compile_fail | 10/10 | - |
| `vector_removeat` | compile_fail | 172/172 | - |
| `vector_reverse` | compile_fail | 232/232 | - |
| `vector_shiftunshift` | compile_fail | 252/252 | - |
| `vector_slice` | compile_fail | 331/331 | - |
| `vector_sort` | compile_fail | 905/905 | - |
| `vector_splice` | compile_fail | 693/693 | - |
| `vector_splice_fixed_bug_compat` | compile_fail | 4/4 | - |
| `vector_tostring` | compile_fail | 79/79 | - |
| `verification` | compile_fail | 8/8 | - |
| `verify_abnormal_loop` | compile_fail | 1/1 | - |
| `verify_dxns_without_flag` | compile_fail | 3/3 | - |
| `verify_exception_target_two_jumps` | compile_fail | 1/1 | - |
| `verify_exception_targets_edge_case` | compile_fail | 1/1 | - |
| `verify_illegal_opcode` | compile_fail | 1/1 | - |
| `verify_jump_to_middle_of_op` | compile_fail | 1/1 | - |
| `verify_lookup_switch_edge_case` | compile_fail | 1/1 | - |
| `verify_method_info_oob` | compile_fail | 1/1 | - |
| `verify_stack` | compile_fail | 5/5 | - |
| `verify_typecheck` | compile_fail | 4/4 | - |
| `verify_unreachable_exception` | compile_fail | 2/2 | - |
| `versioned_isplaying` | compile_fail | 2/2 | - |
| `virtual_properties` | compile_fail | 16/16 | - |
| `with` | compile_fail | 4/4 | - |
| `wrong_arg_count` | compile_fail | 7/7 | - |
| `xml_abstract_equality` | compile_fail | 36/36 | - |
| `xml_advanced` | compile_fail | 52/52 | - |
| `xml_appendchild` | compile_fail | 10/10 | - |
| `xml_appendchild_swf_v21` | compile_fail | 13/13 | - |
| `xml_as_attribute` | compile_fail | 9/9 | - |
| `xml_attribute` | compile_fail | 35/35 | - |
| `xml_attribute_name` | compile_fail | 40/40 | - |
| `xml_basic` | compile_fail | 33/33 | - |
| `xml_child` | compile_fail | 25/25 | - |
| `xml_childindex` | compile_fail | 7/7 | - |
| `xml_children` | compile_fail | 43/43 | - |
| `xml_class_call` | compile_fail | 9/9 | - |
| `xml_contains` | compile_fail | 197/197 | - |
| `xml_copy` | compile_fail | 20/20 | - |
| `xml_ctor_from_tostring` | compile_fail | 23/23 | - |
| `xml_delete` | compile_fail | 114/114 | - |
| `xml_descendants` | compile_fail | 83/83 | - |
| `xml_elements` | compile_fail | 6/6 | - |
| `xml_equals_namespace_check` | compile_fail | 2/2 | - |
| `xml_explicit_use_namespace` | compile_fail | 5/5 | - |
| `xml_getdescendants_qname` | compile_fail | 21/21 | - |
| `xml_has_property_via_in` | compile_fail | 26/26 | - |
| `xml_hasownproperty` | compile_fail | 6/6 | - |
| `xml_ignore_white` | compile_fail | 6/6 | - |
| `xml_length` | compile_fail | 2/2 | - |
| `xml_list_as_attribute` | compile_fail | 9/9 | - |
| `xml_list_concat` | compile_fail | 20/20 | - |
| `xml_list_ctor_errors` | compile_fail | 34/34 | - |
| `xml_list_delete_clear_parent` | compile_fail | 6/6 | - |
| `xml_list_enumerate` | compile_fail | 4/4 | - |
| `xml_methods_settings` | compile_fail | 3/3 | - |
| `xml_mismatched_tag` | compile_fail | 37/37 | - |
| `xml_namespace` | compile_fail | 39/39 | - |
| `xml_namespace_methods` | compile_fail | 245/245 | - |
| `xml_namespaced_property` | compile_fail | 7/7 | - |
| `xml_no_namespace` | compile_fail | 1/1 | - |
| `xml_nodekind` | compile_fail | 3/3 | - |
| `xml_normalize` | compile_fail | 35/35 | - |
| `xml_notification_bubbling` | compile_fail | 361/361 | - |
| `xml_parent` | compile_fail | 8/8 | - |
| `xml_set_children` | compile_fail | 17/17 | - |
| `xml_set_name` | compile_fail | 34/34 | - |
| `xml_settings` | compile_fail | 6/6 | - |
| `xml_simple_complex_content` | compile_fail | 47/47 | - |
| `xml_socket` | compile_fail | 11/11 | - |
| `xml_text` | compile_fail | 7/7 | - |
| `xml_tostring` | compile_fail | 6/6 | - |
| `xml_tostring_namespace` | compile_fail | 12/12 | - |
| `xml_unescaping` | compile_fail | 23/23 | - |
| `xml_weird_ignores` | compile_fail | 54/54 | - |
| `xml_wildcard` | compile_fail | 11/11 | - |
| `xmldocument` | compile_fail | 254/254 | - |
| `xmlnode` | compile_fail | 3540/3540 | - |
| `zero_frame_clip` | compile_fail | 3/3 | - |

## Status Changed (117)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `accessibilityimplementation` | output_mismatch | compile_fail | 0/18 | - |
| `all_classes/accessibility/swf10` | output_mismatch | compile_fail | 7/88 | - |
| `all_classes/accessibility/swf30` | output_mismatch | compile_fail | 7/88 | - |
| `all_classes/accessibility/swf9` | output_mismatch | compile_fail | 7/73 | - |
| `all_classes/display/swf10` | output_mismatch | compile_fail | 11/2569 | - |
| `all_classes/display/swf11` | output_mismatch | compile_fail | 19/2593 | - |
| `all_classes/display/swf12` | output_mismatch | compile_fail | 19/2593 | - |
| `all_classes/display/swf13` | output_mismatch | compile_fail | 16/2671 | - |
| `all_classes/display/swf30` | output_mismatch | compile_fail | 10/2936 | - |
| `all_classes/display/swf9` | output_mismatch | compile_fail | 9/1959 | - |
| `all_classes/display3D/swf13` | output_mismatch | compile_fail | 6/326 | - |
| `all_classes/display3D/swf30` | output_mismatch | compile_fail | 8/412 | - |
| `all_classes/events/swf10` | output_mismatch | compile_fail | 5/1638 | - |
| `all_classes/events/swf11` | output_mismatch | compile_fail | 5/1750 | - |
| `all_classes/events/swf12` | output_mismatch | compile_fail | 5/1814 | - |
| `all_classes/events/swf30` | output_mismatch | compile_fail | 17/2353 | - |
| `all_classes/events/swf9` | output_mismatch | compile_fail | 8/1030 | - |
| `all_classes/xml/swf30` | output_mismatch | compile_fail | 5/116 | - |
| `all_classes/xml/swf9` | output_mismatch | compile_fail | 5/116 | - |
| `appdomain_lookup_edge_cases` | output_mismatch | compile_fail | 7/32 | - |
| `array_access_oob_interpreter` | ruffle_matched | compile_fail | 0/1 | - |
| `array_sort_swf10_64bit` | ruffle_matched | compile_fail | 0/1 | - |
| `audio_computespectrum` | output_mismatch | compile_fail | 0/118 | - |
| `automation_classes` | output_mismatch | compile_fail | 1/122 | - |
| `avm1_root` | output_mismatch | compile_fail | 0/58 | - |
| `bitmapdata_draw_alpha_erase` | output_mismatch | compile_fail | 6/8 | - |
| `blend_transform` | ruffle_matched | compile_fail | 0/1 | - |
| `bom` | output_mismatch | compile_fail | 6/9 | - |
| `bounds_mode` | output_mismatch | compile_fail | 253/269 | - |
| `button_nested_frame_simple` | output_mismatch | compile_fail | 27/27 | - |
| `coerce_property` | ruffle_matched | compile_fail | 33/36 | - |
| `coerce_to_primitive_side_effects_with_nulls` | ruffle_matched | compile_fail | 33/37 | - |
| `delayed_symbolclass` | output_mismatch | compile_fail | 20/28 | - |
| `dependent_strings` | output_mismatch | compile_fail | 46/84 | - |
| `dictionary_weak_keys` | ruffle_matched | compile_fail | 1/2 | - |
| `displayobject_early_init` | output_mismatch | compile_fail | 1/54 | - |
| `displayobject_getrect` | output_mismatch | compile_fail | 2/16 | - |
| `displayobject_hittestpoint_boundary` | output_mismatch | compile_fail | 47/65 | - |
| `displayobject_scrollrect` | output_mismatch | compile_fail | 19/33 | - |
| `displayobject_transform` | output_mismatch | compile_fail | 67/89 | - |
| `edittext_device_transform_layout` | ruffle_matched | compile_fail | 268/288 | - |
| `edittext_getcharboundaries_culling` | ruffle_matched | compile_fail | 5/305 | - |
| `edittext_getcharboundaries_missing_embedded_font` | ruffle_matched | compile_fail | 4/7 | - |
| `edittext_tab_stops` | ruffle_matched | compile_fail | 54/60 | - |
| `edittext_tag_indent` | output_mismatch | compile_fail | 38/49 | - |
| `encode_uri_surrogate_pair_swf10` | ruffle_matched | compile_fail | 0/15 | - |
| `error_1034_debug_string` | ruffle_matched | compile_fail | 11/30 | - |
| `event_handler_exception` | output_mismatch | compile_fail | 5/11 | - |
| `external_interface` | output_mismatch | compile_fail | 3/105 | - |
| `focus_events_mixed_avm_edittext` | output_mismatch | compile_fail | 1/49 | - |
| `freestanding_superclass` | ruffle_matched | compile_fail | 2/4 | - |
| `geom_transform` | output_mismatch | compile_fail | 21/74 | - |
| `goto_framescript_queued` | ruffle_matched | compile_fail | 1/6 | - |
| `graphics_draw_path` | ruffle_matched | compile_fail | 51/101 | - |
| `groupelement_text` | ruffle_matched | compile_fail | 154/156 | - |
| `id3_info` | output_mismatch | compile_fail | 0/8 | - |
| `int_toexponential` | ruffle_matched | compile_fail | 1139/1215 | - |
| `int_toprecision` | ruffle_matched | compile_fail | 684/1125 | - |
| `large_preload_from_bytes` | output_mismatch | compile_fail | 18/51 | - |
| `large_preload_from_url` | output_mismatch | compile_fail | 16/27 | - |
| `large_preload_image_from_bytes` | output_mismatch | compile_fail | 19/25 | - |
| `loader_applicationDomain` | output_mismatch | compile_fail | 0/4 | - |
| `loader_duplicate_class` | output_mismatch | compile_fail | 23/48 | - |
| `loader_load` | output_mismatch | compile_fail | 126/128 | - |
| `loader_try_click_root` | output_mismatch | compile_fail | 0/16 | - |
| `localconnection` | output_mismatch | compile_fail | 589/890 | - |
| `matrix` | output_mismatch | compile_fail | 282/338 | - |
| `matrix3d_append` | output_mismatch | compile_fail | 0/16 | - |
| `matrix3d_append_rotation` | output_mismatch | compile_fail | 0/23 | - |
| `matrix3d_copy_column` | output_mismatch | compile_fail | 24/83 | - |
| `matrix3d_copy_raw_data_from` | output_mismatch | compile_fail | 0/55 | - |
| `matrix3d_copy_raw_data_to` | output_mismatch | compile_fail | 0/38 | - |
| `matrix3d_copy_row` | output_mismatch | compile_fail | 24/83 | - |
| `matrix3d_prepend` | output_mismatch | compile_fail | 0/16 | - |
| `matrix3d_recompose_edge_cases` | output_mismatch | compile_fail | 0/198 | - |
| `matrix3d_transform_vector` | output_mismatch | compile_fail | 36/52 | - |
| `method_association` | output_mismatch | compile_fail | 1/5 | - |
| `mouse_pick_avm1_root` | output_mismatch | compile_fail | 1/2 | - |
| `mouse_pick_loader_avm1` | output_mismatch | compile_fail | 5/42 | - |
| `native_menu_basic` | output_mismatch | compile_fail | 0/19 | - |
| `netstream_play_flv` | output_mismatch | compile_fail | 0/16 | - |
| `netstream_play_stop_replay` | output_mismatch | compile_fail | 1/11 | - |
| `netstream_seek_flv` | output_mismatch | compile_fail | 0/49 | - |
| `number_convert_edge_cases` | output_mismatch | compile_fail | 148/180 | - |
| `number_convert_errors` | output_mismatch | compile_fail | 40/871 | - |
| `number_tostring` | output_mismatch | compile_fail | 873/1050 | - |
| `orphan_removeobject` | output_mismatch | compile_fail | 340/636 | - |
| `sandbox_type_remote` | output_mismatch | compile_fail | 1/3 | - |
| `scope_optimizations` | output_mismatch | compile_fail | 3/4 | - |
| `selection_onsetfocus_mixed_avm` | output_mismatch | compile_fail | 0/5 | - |
| `simplebutton_childevents_multichild` | output_mismatch | compile_fail | 33/152 | - |
| `simplebutton_childevents_script_order` | ruffle_matched | compile_fail | 83/87 | - |
| `simplebutton_soundtransform` | output_mismatch | compile_fail | 829/887 | - |
| `slot_holes_fail` | ruffle_matched | compile_fail | 0/0 | - |
| `slot_id_exceeds_trait_count` | ruffle_matched | compile_fail | 0/0 | - |
| `sound_load_multiple` | output_mismatch | compile_fail | 3/19 | - |
| `soundchannel_position` | ruffle_matched | compile_fail | 66/140 | - |
| `soundchannel_soundcomplete` | ruffle_matched | compile_fail | 6/16 | - |
| `soundmixer_soundtransform` | output_mismatch | compile_fail | 888/900 | - |
| `sprite_dropTarget` | ruffle_matched | compile_fail | 6/19 | - |
| `stage_display_state` | output_mismatch | compile_fail | 0/6 | - |
| `stage_scale_factor` | output_mismatch | compile_fail | 6/12 | - |
| `sub_super_same_field` | output_mismatch | compile_fail | 6/12 | - |
| `supercalls_coerce` | output_mismatch | compile_fail | 1/8 | - |
| `swf_9_goto_in_construct_frame` | ruffle_matched | compile_fail | 8/20 | - |
| `swz` | output_mismatch | compile_fail | 0/2 | - |
| `tab_ordering_properties` | output_mismatch | compile_fail | 561/732 | - |
| `textblock_line_changes` | output_mismatch | compile_fail | 119/481 | - |
| `textblock_recreateline` | output_mismatch | compile_fail | 39/180 | - |
| `textblock_releaselines` | output_mismatch | compile_fail | 41/752 | - |
| `textfield_input_events` | output_mismatch | compile_fail | 9/25 | - |
| `textline_raw_text_length` | output_mismatch | compile_fail | 4/30 | - |
| `uint_toexponential` | ruffle_matched | compile_fail | 1115/1215 | - |
| `uint_toprecision` | ruffle_matched | compile_fail | 692/1125 | - |
| `uncaught_errors_stringified` | ruffle_matched | compile_fail | 3/18 | - |
| `verify_method_info_duplicate` | output_mismatch | compile_fail | 1/2 | - |
| `weird_superinterface_properties` | ruffle_matched | compile_fail | 1/2 | - |
