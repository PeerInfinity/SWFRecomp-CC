# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `bf93755e0cc9`  
**Date:** 2026-07-13 01:11 UTC  
**Total duration:** 4h12m54s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 801 | 1204 | 66.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 68 | 111 | 61.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **1835** | **2493** | **73.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,797 | 130,978 | 88.4% |
| avm2 | 97,905 | 149,868 | 65.3% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,048 | 5,248 | 77.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 260 | 260 | 100% |
| **Total** | **250,479** | **327,818** | **76.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 54 | - | 1 | - |
| avm2 | 376 | 4 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 15 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **479** | **4** | **1** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm2 | parse_int | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| avm2 | focusrect_property | 95% |
| avm2 | stylesheet_parse_color | 94% |
| avm2 | mouseevent_constr | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm2 | json_stringify | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | unescape | 89% |
| avm2 | perspective_projection_basic | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| avm2 | bitmap_subclass | 86% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| avm2 | indexing_delete | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 814 | - | 97581 | 465 |

**avm2 — newly passing:** `add`, `air_hidden_lookup`, `all_classes/security/swf11`, `amf_custom_obj`, `amf_dictionary`, `amf_function`, `amf_invalid_date`, `amf_missing_prop`, `amf_nondynamic_function_prop`, `amf_setter_error`, `amf_vector`, `amf_xml`, `application_domain`, `array_access`, `array_access_interpreter`, `array_access_no_pubns`, `array_concat`, `array_constr`, `array_delete`, `array_enumeration`, `array_enumeration_elements`, `array_every`, `array_filter`, `array_foreach`, `array_hasownproperty`, `array_holes`, `array_index_max`, `array_indexof`, `array_join`, `array_lastindexof`, `array_length`, `array_literal`, `array_map`, `array_pop`, `array_push`, `array_reborrow_bug`, `array_reverse`, `array_shift`, `array_slice`, `array_some`, `array_sort`, `array_sort_fun_swf12`, `array_sort_fun_swf13`, `array_sort_random`, `array_sort_swf10_32bit`, `array_sorton`, `array_sparse_ops`, `array_splice`, `array_splice2`, `array_splice_types`, `array_storage`, `array_tolocalestring`, `array_tostring`, `array_unshift`, `array_valueof`, `array_vector_null_callback`, `astype`, `astypelate`, `astypelate_propagates`, `asymmetric_key_events`, `avm2_catchup_dobj`, `away3d_advanced_shallow_water_demo`, `bitand`, `bitmap_constr`, `bitmap_data`, `bitmap_properties`, `bitmap_timeline`, `bitmapdata_accuracy`, `bitmapdata_applyfilter_blur`, `bitmapdata_applyfilter_colormatrix`, `bitmapdata_applyfilter_destpoint`, `bitmapdata_applyfilter_destpoint_edges`, `bitmapdata_clone`, `bitmapdata_colortransform`, `bitmapdata_colortransform_oob`, `bitmapdata_constr`, `bitmapdata_constructor_from_timeline`, `bitmapdata_copychannel`, `bitmapdata_copypixels`, `bitmapdata_copypixels_blend_over`, `bitmapdata_copypixelstobytearray`, `bitmapdata_dispose`, `bitmapdata_draw`, `bitmapdata_draw_colortransform`, `bitmapdata_draw_cpu_overwrite_gpu`, `bitmapdata_draw_filters`, `bitmapdata_draw_masks`, `bitmapdata_draw_rotation`, `bitmapdata_draw_self_via_graphic`, `bitmapdata_draw_stage`, `bitmapdata_drawwithquality`, `bitmapdata_embedded`, `bitmapdata_fillrect`, `bitmapdata_filter_sourcerect`, `bitmapdata_floodfill`, `bitmapdata_getpixels`, `bitmapdata_getvector`, `bitmapdata_histogram`, `bitmapdata_hittest`, `bitmapdata_hittest_threshold`, `bitmapdata_opaque`, `bitmapdata_pixeldissolve`, `bitmapdata_pixeldissolve_image`, `bitmapdata_rectangle_rounding`, `bitmapdata_setpixels`, `bitmapdata_setvector`, `bitmapdata_sync`, `bitmapdata_threshold`, `bitmapdata_zero_size`, `bitnot`, `bitor`, `bitxor`, `blend_multiply_alpha`, `blend_scroll`, `boolean_constr`, `boolean_negation`, `boolean_tostring`, `broadcast_event`, `button_nested_frame`, `bytearray`, `bytearray_compress`, `bytearray_errors`, `bytearray_method_serialization`, `bytearray_readobject_amf0`, `bytearray_readobject_amf3`, `bytearray_readutf8bytes_with_bom`, `bytearray_serialization`, `bytearray_string_null`, `bytearray_tostring`, `bytearray_utf16`, `bytearray_writeobject`, `callee_in_initializer`, `callproplex_class`, `catch_class`, `catch_scope_slot`, `checkfilter`, `class_call`, `class_cast_call`, `class_enumeration`, `class_has_own_property`, `class_init_interpreter_mode`, `class_is`, `class_methods`, `class_object_properties`, `class_singleton`, `class_supercalls_errors`, `class_supercalls_mismatched`, `class_superclass_wrong_order`, `class_to_locale_string`, `class_to_string`, `class_value_of`, `click_block`, `click_invisible`, `closures`, `coerce_property`, `coerce_return_type`, `coerce_return_type_fail`, `coerce_return_void`, `coerce_string`, `coerce_string_precision`, `coerce_to_primitive_side_effects`, `construct_errors_swf10`, `construct_frame_list`, `constructor_call`, `constructors_vs_timeline`, `constructprop_dynamic_primitive`, `control_flow_bool`, `control_flow_stricteq`, `convert_boolean`, `convert_integer`, `convert_number`, `convert_uinteger`, `cryptscore`, `declocal`, `declocal_i`, `decrement`, `decrement_i`, `default_values`, `dictionary_access`, `dictionary_access_no_pubns`, `dictionary_delete`, `dictionary_foreach`, `dictionary_hasownproperty`, `dictionary_in`, `dictionary_iter_modify`, `dictionary_namespaces`, `dictionary_primitive_keys`, `displayobject_alpha`, `displayobject_blendmode`, `displayobject_colortransform_nested`, `displayobject_from_enterframe`, `displayobject_getbounds_shape`, `displayobject_height`, `displayobject_hittestobject`, `displayobject_invalid_floats`, `displayobject_invalid_props`, `displayobject_mask`, `displayobject_mask_self_referential`, `displayobject_metaData`, `displayobject_name`, `displayobject_name_from_timeline`, `displayobject_parent`, `displayobject_root`, `displayobject_rotation`, `displayobject_set_matrix_nested`, `displayobject_subclass`, `displayobject_visible`, `displayobject_width`, `displayobject_x`, `displayobject_y`, `displayobjectcontainer_addchild`, `displayobjectcontainer_addchild_lazy_sprite`, `displayobjectcontainer_addchild_timelinepull0`, `displayobjectcontainer_addchild_timelinepull1`, `displayobjectcontainer_addchild_timelinepull2`, `displayobjectcontainer_addchildat`, `displayobjectcontainer_addchildat_timelinelock0`, `displayobjectcontainer_addchildat_timelinelock1`, `displayobjectcontainer_addchildat_timelinelock2`, `displayobjectcontainer_contains`, `displayobjectcontainer_getchildat`, `displayobjectcontainer_getchildbyname`, `displayobjectcontainer_getchildbyname_wrongcase`, `displayobjectcontainer_getchildindex`, `displayobjectcontainer_removechild`, `displayobjectcontainer_removechild_errors`, `displayobjectcontainer_removechild_timelinemanip_remove1`, `displayobjectcontainer_removechildat`, `displayobjectcontainer_removechildren`, `displayobjectcontainer_setchildindex`, `displayobjectcontainer_stopallmovieclips`, `displayobjectcontainer_swapchildren`, `displayobjectcontainer_swapchildrenat`, `displayobjectcontainer_timelineinstance`, `divide`, `doabc_is_eager`, `documentclass`, `drag_drop`, `edit_text_linkage`, `edittext_align`, `edittext_always_show_selection`, `edittext_antialiastype`, `edittext_at_point_methods_basic`, `edittext_autosize`, `edittext_autosize_align`, `edittext_autosize_height_dynamic`, `edittext_autosize_height_input`, `edittext_autosize_lazy_bounds_events`, `edittext_autosize_lazy_bounds_interactions`, `edittext_autosize_lazy_bounds_props`, `edittext_autosize_lazy_bounds_visual`, `edittext_autosize_lazy_bounds_vs_relayout`, `edittext_bottom_scroll_v_basic`, `edittext_bounds_scale`, `edittext_bullet`, `edittext_default_format`, `edittext_default_format_empty`, `edittext_empty_text_format`, `edittext_focus_selection`, `edittext_font_size`, `edittext_format_empty_font`, `edittext_get_char_index_at_point`, `edittext_get_line_index_at_point`, `edittext_get_line_index_of_char`, `edittext_getcharboundaries`, `edittext_getcharboundaries_missing_glyphs`, `edittext_getcharboundaries_scroll`, `edittext_getlinemetrics`, `edittext_html`, `edittext_html_condensewhite`, `edittext_html_entity`, `edittext_html_font_size_swf12`, `edittext_html_font_size_swf13`, `edittext_html_roundtrip`, `edittext_input_control`, `edittext_leading`, `edittext_letter_spacing`, `edittext_line_methods`, `edittext_line_metrics`, `edittext_margins`, `edittext_max_scroll_h_basic`, `edittext_max_scroll_v_basic`, `edittext_mousedown`, `edittext_mouseenabled`, `edittext_newline_character`, `edittext_newline_stripping`, `edittext_newlines`, `edittext_paragraph_methods`, `edittext_paste_events`, `edittext_paste_maxchars`, `edittext_paste_restrict`, `edittext_restrict`, `edittext_restrict_events`, `edittext_scrollh`, `edittext_selected_text`, `edittext_set_html_same`, `edittext_set_text_vs_html`, `edittext_stylesheet`, `edittext_stylesheet_custom_tag`, `edittext_stylesheet_display`, `edittext_underline`, `edittext_width_height`, `edittext_wordwrap_word`, `edittext_wrap_breaks`, `empty_bounds`, `equals`, `error_prototype`, `error_stack_trace_debug_swf17`, `error_stack_trace_debug_swf18`, `error_stack_trace_release_swf17`, `error_stack_trace_release_swf18`, `error_tostring`, `es3_inheritance`, `es4_inheritance`, `es4_interfaces`, `es4_method_binding`, `es4_oop_prototypes`, `es4_protected_inheritance`, `event_bubbles`, `event_cancelable`, `event_clone`, `event_clone_error_redispatch`, `event_clone_on_redispatch`, `event_formattostring`, `event_handler_exception`, `event_isdefaultprevented`, `event_target_getter`, `event_target_set`, `event_type`, `event_valueof_tostring`, `eventdispatcher_dispatchevent`, `eventdispatcher_dispatchevent_cancel`, `eventdispatcher_dispatchevent_handlerorder`, `eventdispatcher_dispatchevent_indirect`, `eventdispatcher_dispatchevent_this`, `eventdispatcher_haseventlistener`, `eventdispatcher_interface_invoke`, `eventdispatcher_tostring`, `eventdispatcher_willtrigger`, `falsiness`, `fast_index_access`, `finddef`, `findprop_global_prototype`, `flash_xml`, `flash_xml_cloneNode`, `flash_xml_namespace`, `flash_xml_removeNode`, `focus_events_code`, `focus_events_key_same_object`, `focus_events_mixed_key_mouse`, `focus_events_mouse_same_object`, `focus_remove`, `focus_root_movie`, `focus_stage`, `focusrect`, `font_description_clone`, `font_embedded`, `font_enumeratefonts`, `font_enumeratefonts_filter`, `font_hasglyphs`, `framelabel_constr`, `function_call`, `function_call_arguments`, `function_call_arguments_enumerate`, `function_call_coercion`, `function_call_default`, `function_call_rest`, `function_call_types`, `function_call_via_apply`, `function_call_via_call`, `function_display_anonymous`, `function_length`, `function_object`, `function_proto`, `function_proto_created`, `function_to_locale_string`, `function_to_string`, `function_type`, `function_unbound_this`, `function_value_of`, `get_definition_by_name`, `get_qualified_class_name`, `get_qualified_super_class_name`, `get_slot_edge_cases`, `getglobalslot`, `getouterscope`, `getter_different_namespace_setter`, `goto_button_nested_framescript`, `goto_in_constructframe`, `goto_in_scene_last_frame`, `goto_methods`, `goto_methods_swfver10`, `goto_nested_construct_sibling`, `goto_nested_framescript`, `goto_on_orphan`, `graphics_bitmap_fill`, `graphics_bitmaps`, `graphics_direct_commands`, `graphics_gradients`, `graphics_gradients_nulls`, `graphics_round_rects`, `graphics_simple_shapes`, `greaterequals`, `greaterthan`, `has_own_property`, `hasownproperty_namespaces`, `hittest_morph`, `if_eq`, `if_gt`, `if_gte`, `if_lt`, `if_lte`, `if_ne`, `if_stricteq`, `if_strictne`, `in`, `inclocal`, `inclocal_i`, `increment`, `increment_i`, `instanceof`, `instantiation_on_enter_frame`, `instantiation_on_enterframe_gotoandstop`, `int_constr`, `int_edge_cases`, `int_instanceof`, `int_tofixed`, `int_tostring`, `interactiveobject_enabled`, `interface_namespaces`, `is_finite`, `is_nan`, `is_prototype_of`, `issue_10221`, `issue_13780`, `issue_14901`, `issue_17675_edittext_paste_maxchars`, `issue_5292`, `issue_8630`, `issue_8630_scriptremove`, `istype`, `istypelate`, `istypelate_coerce`, `json_errors`, `json_parse`, `json_version_gated`, `key_input_80percent`, `key_input_location`, `key_input_numpad`, `lessequals`, `lessthan`, `lshift`, `mask_reapply`, `math`, `modulo`, `mouse_click_events`, `mouse_double_click_events`, `mouse_empty_parent`, `mouse_over_while_dragging`, `mouse_pick_button_mode`, `mouse_sibling`, `movieclip_addframescript`, `movieclip_child_property`, `movieclip_constr`, `movieclip_currentlabels`, `movieclip_currentlabels_dupes1`, `movieclip_currentlabels_dupes2`, `movieclip_currentlabels_dupes3`, `movieclip_currentscene`, `movieclip_dispatchevent`, `movieclip_dispatchevent_cancel`, `movieclip_dispatchevent_handlerorder`, `movieclip_dispatchevent_selfadd`, `movieclip_dispatchevent_target`, `movieclip_displayevents`, `movieclip_displayevents_clickgoto`, `movieclip_displayevents_clickgoto2`, `movieclip_displayevents_clickplay`, `movieclip_displayevents_clicksymbol`, `movieclip_displayevents_constructframegoto`, `movieclip_displayevents_constructframeplay`, `movieclip_displayevents_constructframesymbol`, `movieclip_displayevents_dblhandler`, `movieclip_displayevents_enterframegoto`, `movieclip_displayevents_enterframeplay`, `movieclip_displayevents_enterframesymbol`, `movieclip_displayevents_exitframegoto`, `movieclip_displayevents_exitframeplay`, `movieclip_displayevents_exitframesymbol`, `movieclip_displayevents_looping`, `movieclip_displayevents_stopped`, `movieclip_displayevents_swap`, `movieclip_displayevents_timeline`, `movieclip_drawrect`, `movieclip_frameconstruct_skipped`, `movieclip_goto_during_frame_script`, `movieclip_goto_overwrite`, `movieclip_goto_scene_last_frame_int`, `movieclip_goto_scene_last_frame_label`, `movieclip_gotoandplay`, `movieclip_gotoandstop`, `movieclip_gotoandstop_children`, `movieclip_gotoandstop_framescripts1`, `movieclip_gotoandstop_framescripts2`, `movieclip_gotoandstop_framescripts_self`, `movieclip_gotoandstop_queueing`, `movieclip_next_frame`, `movieclip_next_scene`, `movieclip_play`, `movieclip_prev_frame`, `movieclip_prev_scene`, `movieclip_properties`, `movieclip_queued_noop_goto_swf10`, `movieclip_queued_noop_goto_swf9`, `movieclip_scenes`, `movieclip_stop`, `movieclip_super_is_symbol`, `movieclip_symbol_constr`, `movieclip_text_mousedown`, `movieclip_willtrigger`, `multiply`, `namespace_constr`, `namespace_constr_args`, `namespace_enumeration_order`, `nan_scale`, `negate`, `negative_volume_panned`, `nested_iteration`, `net_getClassByAlias`, `newactivation_in_script_init`, `newclass_twice`, `null_void_types`, `number_autoconv`, `number_autoconv_amf`, `number_autoconv_array_sort_32bit`, `number_constr`, `number_toexponential`, `number_toexponential2`, `number_tofixed`, `number_toprecision`, `obfuscated_class_names`, `object_enumeration`, `object_prototype`, `object_to_locale_string`, `object_to_string`, `object_value_of`, `op_coerce`, `op_coerce_x`, `op_escxattr`, `op_escxelem`, `op_lookupswitch`, `optimize_coerce`, `orphan_movie_complex`, `orphan_movie_reorder`, `package_namespace`, `param_default_value_has_zero_cpool_index`, `parent_early_access_child`, `parse_float`, `pixelbender_effect_BlurredFocus`, `pixelbender_effect_glassDisplace`, `pixelbender_effect_smudge`, `pixelbender_effect_tintype`, `pixelbender_effect_twirl`, `pixelbender_images`, `place_multiple`, `place_object_replace`, `place_object_replace_2`, `place_object_same_depth_frame`, `primitive_edge_cases`, `property_priority`, `property_priority_three_level`, `propertyisenumerable_namespaces`, `prototype_set_null`, `proxy_callproperty`, `proxy_deleteproperty`, `proxy_enumeration`, `proxy_getproperty`, `proxy_hasownproperty`, `proxy_hasproperty`, `proxy_serialize`, `proxy_setproperty`, `qname_as_lazy_name_attribute_multiname`, `qname_constr`, `qname_constr_namespace`, `qname_enumeration`, `qname_indexing`, `qname_tostring`, `qname_valueof`, `regexp_constr`, `regexp_exec`, `regexp_extended`, `regexp_multiargs`, `regexp_test`, `regexp_toString`, `register_script_refresh`, `remove_child_clear_field`, `remove_dobj`, `resolve_order`, `rng`, `rootless`, `rshift`, `scene_constr`, `set_property_is_enumerable`, `shape_drawrect`, `simplebutton_added_to_stage`, `simplebutton_childevents`, `simplebutton_childevents_nested`, `simplebutton_childevents_sprite`, `simplebutton_childprops`, `simplebutton_childshuffle`, `simplebutton_constr`, `simplebutton_constr_childevents`, `simplebutton_constr_params`, `simplebutton_mouseenabled`, `simplebutton_multi_children`, `simplebutton_structure`, `simplebutton_symbolclass`, `slots_force_autoassigned`, `sprite_with_frames`, `stage3d_agal_cross_product`, `stage3d_bitmap`, `stage3d_float1_index`, `stage3d_fractal`, `stage3d_ignore_sampler_override`, `stage3d_program_constants_bytearray_be`, `stage3d_program_constants_bytearray_le`, `stage3d_raytrace`, `stage3d_rotating_cube`, `stage3d_sampler`, `stage3d_sampler_partial_upload`, `stage3d_stencil`, `stage3d_texture`, `stage3d_texture_bytearray`, `stage3d_texture_bytearray_compressed_alpha`, `stage3d_texture_bytearray_compressed_raw_alpha`, `stage3d_triangle`, `stage3d_triangle_bytes4`, `stage3d_triangle_float1`, `stage3d_triangle_index_upload`, `stage_access`, `stage_displayobject_properties`, `stage_framerate_nan`, `stage_framerate_negative`, `stage_framerate_zero`, `stage_invalidate`, `stage_mousechildren`, `stage_mouseenabled`, `stage_overriden_setters`, `stage_properties`, `static_var_with_this_in_ctor`, `stored_properties`, `strict_equality`, `string_call`, `string_case`, `string_char_at`, `string_char_code_at`, `string_concat_fromcharcode`, `string_constr`, `string_indexof_lastindexof`, `string_length`, `string_locale_compare`, `string_match`, `string_relational_compare`, `string_replace`, `string_search`, `string_slice_substr_substring`, `string_split`, `string_substr_negative`, `string_substr_weird`, `subtract`, `super_get_call`, `supercall_two_classobjects`, `swf_10_queued_goto_scripts_construct`, `swf_9_goto_in_enter_frame`, `swf_9_goto_in_enter_frame_simple`, `swf_9_queued_goto_scripts`, `swf_9_queued_goto_scripts_construct`, `swf_9_versioning`, `swf_wrong_frame_count`, `swf_wrong_frame_count_isplaying`, `symbol_class_conflict`, `symbol_class_root_not_zero`, `tab_ordering_automatic_advanced`, `tab_ordering_automatic_basic`, `tab_ordering_children`, `tab_ordering_custom_basic`, `text_engine_fontdescription`, `text_run`, `textfield_focusin_event`, `textfield_input_dead_keys_windows`, `textfield_unload`, `textformat`, `textformat_display`, `textformat_font_max_length`, `throw`, `timeline_scripts`, `trace`, `truthiness`, `try_catch`, `try_catch_typed`, `typeof`, `uint_constr`, `uint_tofixed`, `uint_tostring`, `uncaught_errors_stringified`, `unchecked_function`, `urshift`, `vector_class`, `vector_class_call`, `vector_coercion`, `vector_concat`, `vector_constr`, `vector_enumeration`, `vector_every`, `vector_filter`, `vector_holes`, `vector_indexof`, `vector_insertat`, `vector_int_access`, `vector_int_delete`, `vector_join`, `vector_lastindexof`, `vector_legacy`, `vector_map`, `vector_object_final`, `vector_object_toString`, `vector_pushpop`, `vector_reborrow_bug`, `vector_removeat`, `vector_reverse`, `vector_shiftunshift`, `vector_slice`, `vector_sort`, `vector_splice`, `vector_splice_fixed_bug_compat`, `vector_tostring`, `verify_abnormal_loop`, `verify_exception_targets_edge_case`, `verify_lookup_switch_edge_case`, `verify_unreachable_exception`, `versioned_isplaying`, `virtual_properties`, `with`, `xml_abstract_equality`, `xml_advanced`, `xml_appendchild`, `xml_as_attribute`, `xml_attribute`, `xml_attribute_name`, `xml_basic`, `xml_child`, `xml_childindex`, `xml_children`, `xml_class_call`, `xml_contains`, `xml_copy`, `xml_ctor_from_tostring`, `xml_delete`, `xml_descendants`, `xml_elements`, `xml_equals_namespace_check`, `xml_explicit_use_namespace`, `xml_getdescendants_qname`, `xml_has_property_via_in`, `xml_hasownproperty`, `xml_ignore_white`, `xml_length`, `xml_list_as_attribute`, `xml_list_concat`, `xml_list_enumerate`, `xml_methods_settings`, `xml_mismatched_tag`, `xml_namespace`, `xml_namespace_methods`, `xml_namespaced_property`, `xml_no_namespace`, `xml_nodekind`, `xml_normalize`, `xml_notification_bubbling`, `xml_parent`, `xml_set_children`, `xml_set_name`, `xml_settings`, `xml_simple_complex_content`, `xml_text`, `xml_tostring`, `xml_tostring_namespace`, `xml_unescaping`, `xml_weird_ignores`, `xml_wildcard`, `xmldocument`, `xmlnode`, `zero_frame_clip`

*Comparing `d4bd5b2fad95` → `bf93755e0cc9`*

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 1h01m19s across 30 shards
- **Lines:** 115,797/130,978 matching (88.4%)
- **Avg test duration:** 5.1s — slowest: `netstream_play_flv_screen` (37.1s)

### avm2

- **Pass:** 801/1204 (66.5%)
- **Duration:** 1h42m59s across 30 shards
- **Lines:** 97,905/149,868 matching (65.3%)
- **Avg test duration:** 5.1s — slowest: `away3d_advanced_shallow_water_demo` (70.6s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 28m13s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.9s — slowest: `MovieClip-v8` (69.9s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 25m05s across 30 shards
- **Lines:** 4,048/5,248 matching (77.1%)
- **Avg test duration:** 13.5s — slowest: `matrix_test` (106.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m14s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.9s — slowest: `exception` (24.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m07s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 15.3s — slowest: `hello` (22.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m32s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 16.6s — slowest: `dict_callframe` (23.6s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m40s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.5s — slowest: `avm1/duplicateMovieClip/dontremove` (23.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m12s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (21.9s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 5m28s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 7.9s — slowest: `coerce_cross_swf_version` (23.6s)
