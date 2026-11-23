# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-23 23:04 UTC

**Git SHA**: `7e14f54dd9`

**Run Duration**: 31m 28s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 171 |
| Passing | **171** (100.0%) |
| Failing | 0 |
| Total expected lines | 1447 |
| Matching lines | 1447 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**171 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 17.8s |  |
| 2 | `array_method_type1_args` | 7 | 0.8s |  |
| 3 | `avm1_array_generic_receivers` | 16 | 17.8s |  |
| 4 | `avm1_array_native_own_method` | 8 | 0.9s |  |
| 5 | `avm1_attach_clipevent_enterframe` | 11 | 18.0s |  |
| 6 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.1s |  |
| 7 | `avm1_attached_clip_button_click` | 13 | 18.1s |  |
| 8 | `avm1_attached_clip_color` | 2 | 17.9s |  |
| 9 | `avm1_attached_clip_goto_play` | 14 | 18.2s |  |
| 10 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.0s |  |
| 11 | `avm1_attached_clip_hidden_capture` | 6 | 18.3s |  |
| 12 | `avm1_attached_clip_holder_render` | 1 | 0.9s |  |
| 13 | `avm1_attached_clip_natural_timeline` | 34 | 18.6s |  |
| 14 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.0s |  |
| 15 | `avm1_attached_clip_samename_child` | 32 | 18.4s |  |
| 16 | `avm1_attached_clip_tagorder` | 34 | 1.0s |  |
| 17 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.2s |  |
| 18 | `avm1_attached_clip_tagorder_po3` | 34 | 1.0s |  |
| 19 | `avm1_attached_clip_tagorder_ratio` | 34 | 16.3s |  |
| 20 | `avm1_bare_mc_method_scope` | 19 | 16.1s |  |
| 21 | `avm1_button_pick_order` | 9 | 17.0s |  |
| 22 | `avm1_button_textfield_path_binding` | 4 | 16.2s |  |
| 23 | `avm1_child_timeline_advance` | 23 | 15.2s |  |
| 24 | `avm1_child_timeline_frame1_stop` | 7 | 1.1s |  |
| 25 | `avm1_child_timeline_holder_stop` | 26 | 18.7s |  |
| 26 | `avm1_child_timeline_loop` | 34 | 1.2s |  |
| 27 | `avm1_closure_base_clip_root_frame` | 5 | 1.0s |  |
| 28 | `avm1_closure_method_scope` | 7 | 1.1s |  |
| 29 | `avm1_create_text_field_depth` | 9 | 18.5s |  |
| 30 | `avm1_cxform_override_overflow` | 2 | 18.7s |  |
| 31 | `avm1_device_edittext_xscale` | 7 | 18.1s |  |
| 32 | `avm1_display_prop_coercion` | 36 | 1.1s |  |
| 33 | `avm1_dynclip_color_transform` | 2 | 1.1s |  |
| 34 | `avm1_edittext_html_delete_runs` | 4 | 18.3s |  |
| 35 | `avm1_edittext_placed_cxform` | 0 | 18.4s |  |
| 36 | `avm1_edittext_placed_cxform_script` | 3 | 0.9s |  |
| 37 | `avm1_exec_order_attached_selfremove` | 18 | 24.8s |  |
| 38 | `avm1_filter_list_overflow` | 2 | 1.6s |  |
| 39 | `avm1_func2_param_register_oob` | 4 | 1.4s |  |
| 40 | `avm1_hittest_hairline` | 28 | 24.3s |  |
| 41 | `avm1_jpeg3_alpha_bitmap` | 0 | 23.9s |  |
| 42 | `avm1_key_isdown_protected` | 8 | 1.6s |  |
| 43 | `avm1_long_text_layout` | 2 | 18.6s |  |
| 44 | `avm1_many_chars_registry` | 4 | 19.1s |  |
| 45 | `avm1_many_defs_registry` | 13 | 21.3s |  |
| 46 | `avm1_many_functions_registry` | 3 | 8.9s |  |
| 47 | `avm1_mc_resolve` | 5 | 19.5s |  |
| 48 | `avm1_mcl_holder_totalframes` | 5 | 19.5s |  |
| 49 | `avm1_mcl_load_tick` | 14 | 18.5s |  |
| 50 | `avm1_morph_instances_ratio` | 2 | 18.3s |  |
| 51 | `avm1_nested_po3_filters` | 12 | 1.3s |  |
| 52 | `avm1_parent_as3_child_payload` | 2 | 1.3s |  |
| 53 | `avm1_parent_child_bitmap` | 5 | 1.5s |  |
| 54 | `avm1_parent_child_bitmap_fill` | 3 | 18.5s |  |
| 55 | `avm1_parent_child_modify_place` | 5 | 19.1s |  |
| 56 | `avm1_parent_child_morph` | 8 | 1.2s |  |
| 57 | `avm1_parent_child_render` | 7 | 1.1s |  |
| 58 | `avm1_parent_child_sprite_meta` | 8 | 1.2s |  |
| 59 | `avm1_parent_child_text` | 8 | 1.1s |  |
| 60 | `avm1_pixelbounds_dynamic_child` | 1 | 18.0s |  |
| 61 | `avm1_placed_drawing_color` | 1 | 18.0s |  |
| 62 | `avm1_po3_color_matrix_live` | 0 | 17.8s |  |
| 63 | `avm1_po3_color_matrix_live_clear` | 1 | 0.9s |  |
| 64 | `avm1_po3_color_matrix_live_nested` | 0 | 0.9s |  |
| 65 | `avm1_remove_same_name_other_parent` | 4 | 18.1s |  |
| 66 | `avm1_removed_clip_dprops_gc` | 14 | 1.0s |  |
| 67 | `avm1_root_identity_and_playhead` | 3 | 18.7s |  |
| 68 | `avm1_runtime_filters` | 3 | 18.6s |  |
| 69 | `avm1_runtime_filters_cm_bitmap` | 5 | 1.3s |  |
| 70 | `avm1_set_new_text_format_color` | 4 | 18.5s |  |
| 71 | `avm1_set_new_text_format_render` | 5 | 18.3s |  |
| 72 | `avm1_textfield_x_bounds_offset` | 10 | 18.3s |  |
| 73 | `avm1_timer_clock_model` | 19 | 18.1s |  |
| 74 | `avm1_timer_function_form_activation` | 3 | 17.8s |  |
| 75 | `avm1_type2_mc_receiver_dispatch` | 7 | 17.8s |  |
| 76 | `avm1_wrap_giveup_mixed_runs` | 2 | 0.9s |  |
| 77 | `avm1_xml_first_action_proto` | 2 | 0.8s |  |
| 78 | `avm1_xmlnode_first_action_proto` | 2 | 0.8s |  |
| 79 | `avm2_activation_vtable_bounded` | 5 | 19.4s |  |
| 80 | `avm2_agi_shell` | 6 | 1.8s |  |
| 81 | `avm2_array_growth_bounded` | 5 | 5.8s |  |
| 82 | `avm2_bitmapdata_draw_textfield` | 5 | 5.5s |  |
| 83 | `avm2_child_simplebutton` | 10 | 19.7s |  |
| 84 | `avm2_contextmenu_stub` | 4 | 5.2s |  |
| 85 | `avm2_e4x_parse_bounded` | 18 | 31.9s |  |
| 86 | `avm2_embed_bytearray` | 2 | 30.4s |  |
| 87 | `avm2_external_interface_unavailable` | 8 | 8.2s |  |
| 88 | `avm2_findprop_this_resolution` | 13 | 2.9s |  |
| 89 | `avm2_gc_dynprop_tombstone_purge` | 8 | 8.3s |  |
| 90 | `avm2_gc_string_concat_reclaim` | 10 | 8.3s |  |
| 91 | `avm2_gc_string_survives_collect` | 9 | 19.0s |  |
| 92 | `avm2_goto_catchup_scale` | 4 | 5.4s |  |
| 93 | `avm2_graphics_runtime` | 7 | 19.2s |  |
| 94 | `avm2_json_roundtrip_bounded` | 13 | 5.9s |  |
| 95 | `avm2_layer_group_alpha` | 0 | 5.6s |  |
| 96 | `avm2_layer_group_erase` | 0 | 0.7s |  |
| 97 | `avm2_layer_group_filtered_child` | 0 | 23.4s |  |
| 98 | `avm2_layer_group_overlap_alpha` | 0 | 23.4s |  |
| 99 | `avm2_loader_stub` | 5 | 23.2s |  |
| 100 | `avm2_localconnection_domain` | 4 | 5.8s |  |
| 101 | `avm2_morph` | 8 | 23.2s |  |
| 102 | `avm2_parent_child_render` | 11 | 8.0s |  |
| 103 | `avm2_parent_child_static_text` | 12 | 23.1s |  |
| 104 | `avm2_parent_child_symbol_stride` | 6 | 23.8s |  |
| 105 | `avm2_parent_child_symbolclass_domain` | 12 | 5.9s |  |
| 106 | `avm2_reflect_trait_hooks` | 30 | 23.0s |  |
| 107 | `avm2_sharedobject_flushstatus` | 4 | 5.7s |  |
| 108 | `avm2_simplebutton_click` | 2 | 5.7s |  |
| 109 | `avm2_slot_default_template` | 34 | 8.8s |  |
| 110 | `avm2_sound_bytes_and_group_format` | 27 | 8.9s |  |
| 111 | `avm2_static_and_store_slots` | 14 | 8.7s |  |
| 112 | `avm2_static_text` | 6 | 8.6s |  |
| 113 | `avm2_strbuf_stale_prefix` | 21 | 2.9s |  |
| 114 | `avm2_timeline_gradients` | 7 | 33.1s |  |
| 115 | `avm2_timeline_solid` | 6 | 24.2s |  |
| 116 | `avm2_timeline_stroke_gradient` | 9 | 6.7s |  |
| 117 | `avm2_timeline_text` | 4 | 5.9s |  |
| 118 | `avm2_tolerant_verify_quarantine` | 2 | 5.7s |  |
| 119 | `avm2_typed_value_ops` | 30 | 5.9s |  |
| 120 | `bitmap_pool_layer_cap` | 1 | 18.4s |  |
| 121 | `broadcast_cross_swf_version` | 4 | 17.8s |  |
| 122 | `broadcast_type1_args` | 14 | 17.5s |  |
| 123 | `coerce_cross_swf_version` | 7 | 0.9s |  |
| 124 | `coerce_recursion_guard` | 1 | 0.8s |  |
| 125 | `coerce_type1_args` | 9 | 0.8s |  |
| 126 | `convertfloat_type1_this` | 3 | 0.8s |  |
| 127 | `ctor_before_first_call_locals` | 5 | 0.9s |  |
| 128 | `ei_closure_scope_order` | 7 | 17.9s |  |
| 129 | `ei_cross_swf_version` | 2 | 0.9s |  |
| 130 | `ei_mc_this_receiver` | 5 | 18.1s |  |
| 131 | `ei_type1_args` | 7 | 0.9s |  |
| 132 | `enterframe_type1_args` | 8 | 19.0s |  |
| 133 | `fn_call_builtin_type1_args` | 10 | 18.9s |  |
| 134 | `fn_call_type1_args` | 7 | 1.1s |  |
| 135 | `fn_empty_method_type1_args` | 10 | 1.1s |  |
| 136 | `layer_group_filtered_child` | 0 | 18.7s |  |
| 137 | `layer_group_in_add_alpha` | 0 | 1.0s |  |
| 138 | `layer_group_overlap_alpha` | 0 | 1.1s |  |
| 139 | `layer_group_overlap_erase` | 0 | 0.3s |  |
| 140 | `lc_method_type1_args` | 7 | 16.5s |  |
| 141 | `lc_onstatus_type1_args` | 3 | 0.9s |  |
| 142 | `lv_cross_swf_version` | 5 | 18.5s |  |
| 143 | `lv_ondata_type1_args` | 3 | 18.2s |  |
| 144 | `mask_nested_intersect` | 1 | 18.2s |  |
| 145 | `mask_sibling_union` | 1 | 0.9s |  |
| 146 | `mc_event_cross_swf_version` | 4 | 1.0s |  |
| 147 | `mc_event_type1_args` | 3 | 16.0s |  |
| 148 | `mc_method_v5_caller_gate` | 4 | 15.8s |  |
| 149 | `mc_resolve_type1_args` | 6 | 1.0s |  |
| 150 | `method_type1_args` | 10 | 1.0s |  |
| 151 | `nc_onstatus_closure` | 2 | 16.1s |  |
| 152 | `nc_onstatus_type1_args` | 3 | 17.9s |  |
| 153 | `onconstruct_cross_swf_version` | 4 | 18.1s |  |
| 154 | `onconstruct_type1_args` | 6 | 0.9s |  |
| 155 | `onload_type1_args` | 7 | 18.0s |  |
| 156 | `onunload_type1_args` | 6 | 0.9s |  |
| 157 | `onunload_type1_local_frame` | 2 | 22.5s |  |
| 158 | `resolve_type1_args` | 13 | 0.4s |  |
| 159 | `root_enterframe_cross_swf_version` | 3 | 22.2s |  |
| 160 | `sort_comparator_captured_scope` | 2 | 22.4s |  |
| 161 | `sort_comparator_type1_args` | 5 | 0.4s |  |
| 162 | `string_prim_method_type1_args` | 19 | 17.4s |  |
| 163 | `timer_cross_swf_version` | 3 | 17.6s |  |
| 164 | `timer_type1_args` | 14 | 17.6s |  |
| 165 | `watch_cross_swf_version` | 6 | 1.0s |  |
| 166 | `watch_mc_reentrant_setmember` | 3 | 0.8s |  |
| 167 | `watch_mc_type1_args` | 7 | 20.9s |  |
| 168 | `watch_setmember_type1_args` | 7 | 1.1s |  |
| 169 | `watch_timeline_named_params` | 4 | 1.0s |  |
| 170 | `watch_timeline_reentrant` | 3 | 1.0s |  |
| 171 | `xml_onload_type1_args` | 3 | 20.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.
