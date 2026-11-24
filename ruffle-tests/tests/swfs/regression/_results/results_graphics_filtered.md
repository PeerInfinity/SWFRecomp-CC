# Ruffle Test Results (Filtered)

**Date**: 2026-11-24 17:26 UTC

**Git SHA**: `78fee9e13f`

**Run Duration**: 49m 47s

**Filtered**: 0 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **243** (100.0%) |
| Failing | 0 |
| Total expected lines | 1965 |
| Matching lines | 1965 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**243 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 18.8s |  |
| 2 | `array_method_type1_args` | 7 | 1.5s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 21.6s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.7s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.7s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.7s |  |
| 7 | `avm1_applyfilter_glow` | 18 | 1.7s |  |
| 8 | `avm1_applyfilter_kernels` | 17 | 1.7s |  |
| 9 | `avm1_array_generic_receivers` | 16 | 1.6s |  |
| 10 | `avm1_array_native_own_method` | 8 | 18.9s |  |
| 11 | `avm1_attach_clipevent_enterframe` | 11 | 19.0s |  |
| 12 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.7s |  |
| 13 | `avm1_attached_clip_button_click` | 13 | 19.4s |  |
| 14 | `avm1_attached_clip_color` | 2 | 21.6s |  |
| 15 | `avm1_attached_clip_goto_play` | 14 | 19.1s |  |
| 16 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.1s |  |
| 17 | `avm1_attached_clip_hidden_capture` | 6 | 19.4s |  |
| 18 | `avm1_attached_clip_holder_render` | 1 | 1.7s |  |
| 19 | `avm1_attached_clip_natural_timeline` | 34 | 19.3s |  |
| 20 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.7s |  |
| 21 | `avm1_attached_clip_samename_child` | 32 | 19.8s |  |
| 22 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 21.7s |  |
| 23 | `avm1_attached_clip_tagorder` | 34 | 1.7s |  |
| 24 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.8s |  |
| 25 | `avm1_attached_clip_tagorder_po3` | 34 | 1.7s |  |
| 26 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.7s |  |
| 27 | `avm1_attached_clip_timeline_child_parent` | 6 | 19.0s |  |
| 28 | `avm1_bare_mc_method_scope` | 19 | 25.3s |  |
| 29 | `avm1_bitmapdata_draw_edittext` | 3 | 25.5s |  |
| 30 | `avm1_browser_eager_init` | 9 | 25.5s |  |
| 31 | `avm1_browser_gated_color` | 3 | 24.8s |  |
| 32 | `avm1_browser_gated_depth` | 7 | 2.5s |  |
| 33 | `avm1_browser_gated_textfield` | 7 | 2.6s |  |
| 34 | `avm1_button_pick_order` | 9 | 3.9s |  |
| 35 | `avm1_button_textfield_path_binding` | 4 | 25.8s |  |
| 36 | `avm1_child_timeline_advance` | 23 | 24.4s |  |
| 37 | `avm1_child_timeline_frame1_stop` | 7 | 2.2s |  |
| 38 | `avm1_child_timeline_holder_stop` | 26 | 2.2s |  |
| 39 | `avm1_child_timeline_loop` | 32 | 2.3s |  |
| 40 | `avm1_clone_depth_overflow` | 3 | 24.7s |  |
| 41 | `avm1_clone_depth_removed_reuse` | 4 | 2.0s |  |
| 42 | `avm1_closure_base_clip_root_frame` | 5 | 2.2s |  |
| 43 | `avm1_closure_method_scope` | 7 | 2.1s |  |
| 44 | `avm1_create_text_field_depth` | 9 | 18.7s |  |
| 45 | `avm1_cxform_override_overflow` | 2 | 18.9s |  |
| 46 | `avm1_definetext_matrix` | 0 | 1.6s |  |
| 47 | `avm1_device_edittext_xscale` | 7 | 18.7s |  |
| 48 | `avm1_display_prop_coercion` | 36 | 1.7s |  |
| 49 | `avm1_dynclip_color_transform` | 2 | 1.9s |  |
| 50 | `avm1_edittext_cut_copy_selection` | 9 | 18.9s |  |
| 51 | `avm1_edittext_html_delete_runs` | 4 | 18.9s |  |
| 52 | `avm1_edittext_html_typed_runs` | 3 | 19.2s |  |
| 53 | `avm1_edittext_path_variable_same_frame` | 11 | 19.6s |  |
| 54 | `avm1_edittext_path_variable_scope` | 10 | 1.8s |  |
| 55 | `avm1_edittext_placed_cxform` | 0 | 19.6s |  |
| 56 | `avm1_edittext_placed_cxform_script` | 3 | 1.6s |  |
| 57 | `avm1_edittext_scaled_glyphs` | 0 | 19.4s |  |
| 58 | `avm1_edittext_tab_render` | 1 | 19.5s |  |
| 59 | `avm1_edittext_wordwrap_render` | 5 | 19.5s |  |
| 60 | `avm1_empty_clip_drawing_depth_order` | 1 | 21.7s |  |
| 61 | `avm1_exec_order_attached_selfremove` | 18 | 19.3s |  |
| 62 | `avm1_exec_order_dynamic_eligible` | 35 | 19.0s |  |
| 63 | `avm1_filter_list_overflow` | 2 | 19.1s |  |
| 64 | `avm1_func2_param_register_oob` | 4 | 1.5s |  |
| 65 | `avm1_goto_backward_enterframe_once` | 22 | 18.9s |  |
| 66 | `avm1_goto_skipped_init_call` | 6 | 19.1s |  |
| 67 | `avm1_goto_skipped_init_script` | 5 | 1.7s |  |
| 68 | `avm1_goto_skipped_init_timer` | 6 | 18.9s |  |
| 69 | `avm1_hairline_scaled_instances` | 1 | 18.8s |  |
| 70 | `avm1_hittest_hairline` | 28 | 19.1s |  |
| 71 | `avm1_holder_drawing_under_children` | 1 | 18.8s |  |
| 72 | `avm1_jpeg3_alpha_bitmap` | 0 | 18.6s |  |
| 73 | `avm1_key_isdown_protected` | 8 | 18.8s |  |
| 74 | `avm1_loaded_bare_goto_seq` | 4 | 19.1s |  |
| 75 | `avm1_loaded_shell_consumers_seq` | 12 | 18.9s |  |
| 76 | `avm1_loaded_shell_root_lookup` | 4 | 20.5s |  |
| 77 | `avm1_loaded_timeline_holder` | 7 | 2.3s |  |
| 78 | `avm1_loaded_unload_deferred` | 5 | 20.4s |  |
| 79 | `avm1_long_text_layout` | 2 | 22.7s |  |
| 80 | `avm1_many_chars_registry` | 4 | 19.8s |  |
| 81 | `avm1_many_defs_registry` | 13 | 21.2s |  |
| 82 | `avm1_many_functions_registry` | 3 | 9.7s |  |
| 83 | `avm1_mc_button_unified_pick` | 21 | 20.1s |  |
| 84 | `avm1_mc_resolve` | 5 | 24.4s |  |
| 85 | `avm1_mcl_holder_totalframes` | 5 | 2.8s |  |
| 86 | `avm1_mcl_load_tick` | 14 | 24.6s |  |
| 87 | `avm1_morph_instances_ratio` | 2 | 24.9s |  |
| 88 | `avm1_nested_po3_filters` | 12 | 25.6s |  |
| 89 | `avm1_parent_as3_child_payload` | 2 | 2.6s |  |
| 90 | `avm1_parent_child_bitmap` | 5 | 2.7s |  |
| 91 | `avm1_parent_child_bitmap_fill` | 3 | 2.8s |  |
| 92 | `avm1_parent_child_modify_place` | 5 | 16.0s |  |
| 93 | `avm1_parent_child_morph` | 8 | 4.0s |  |
| 94 | `avm1_parent_child_render` | 7 | 2.3s |  |
| 95 | `avm1_parent_child_sprite_meta` | 8 | 1.9s |  |
| 96 | `avm1_parent_child_text` | 8 | 1.9s |  |
| 97 | `avm1_pixelbounds_dynamic_child` | 1 | 15.9s |  |
| 98 | `avm1_placed_drawing_color` | 1 | 16.1s |  |
| 99 | `avm1_po3_cm_alpha_bias_edge` | 0 | 1.7s |  |
| 100 | `avm1_po3_cm_folded_clear` | 1 | 29.2s |  |
| 101 | `avm1_po3_cm_live_under_cxform` | 0 | 2.9s |  |
| 102 | `avm1_po3_color_matrix_live` | 0 | 2.8s |  |
| 103 | `avm1_po3_color_matrix_live_clear` | 1 | 2.8s |  |
| 104 | `avm1_po3_color_matrix_live_nested` | 0 | 2.7s |  |
| 105 | `avm1_remove_same_name_other_parent` | 4 | 26.1s |  |
| 106 | `avm1_removed_clip_dprops_gc` | 14 | 2.8s |  |
| 107 | `avm1_resolve_dotted_getvariable` | 13 | 25.8s |  |
| 108 | `avm1_root_identity_and_playhead` | 3 | 17.6s |  |
| 109 | `avm1_runtime_filters` | 3 | 21.9s |  |
| 110 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.3s |  |
| 111 | `avm1_set_new_text_format_color` | 4 | 18.8s |  |
| 112 | `avm1_set_new_text_format_render` | 5 | 18.8s |  |
| 113 | `avm1_set_new_text_format_size` | 5 | 1.9s |  |
| 114 | `avm1_stroke_style_id_order` | 1 | 18.6s |  |
| 115 | `avm1_swf6_case_insensitive_builtins` | 42 | 19.0s |  |
| 116 | `avm1_swf7_case_sensitive_builtins` | 40 | 18.7s |  |
| 117 | `avm1_textfield_attached_depth_order` | 1 | 21.0s |  |
| 118 | `avm1_textfield_x_bounds_offset` | 10 | 18.4s |  |
| 119 | `avm1_timer_clock_model` | 19 | 18.7s |  |
| 120 | `avm1_timer_function_form_activation` | 3 | 18.5s |  |
| 121 | `avm1_timer_method_form` | 6 | 1.6s |  |
| 122 | `avm1_timer_native_method_play` | 3 | 1.6s |  |
| 123 | `avm1_timer_overflow` | 10 | 2.1s |  |
| 124 | `avm1_timer_root_goto_stopped_gs` | 3 | 21.3s |  |
| 125 | `avm1_timer_root_goto_stopped_nf` | 3 | 2.0s |  |
| 126 | `avm1_type2_mc_receiver_dispatch` | 7 | 20.6s |  |
| 127 | `avm1_watch_long_name` | 9 | 2.1s |  |
| 128 | `avm1_watch_overflow` | 2 | 2.8s |  |
| 129 | `avm1_wrap_giveup_mixed_runs` | 2 | 2.4s |  |
| 130 | `avm1_xml_first_action_proto` | 2 | 2.0s |  |
| 131 | `avm1_xmlnode_first_action_proto` | 2 | 2.0s |  |
| 132 | `avm1_xscale_double_readback` | 8 | 20.6s |  |
| 133 | `avm2_activation_vtable_bounded` | 5 | 29.3s |  |
| 134 | `avm2_agi_shell` | 6 | 7.7s |  |
| 135 | `avm2_applyfilter_glow_kernels` | 17 | 7.9s |  |
| 136 | `avm2_applyfilter_gradient_opaque` | 24 | 8.5s |  |
| 137 | `avm2_array_growth_bounded` | 5 | 8.3s |  |
| 138 | `avm2_bitmapdata_draw_edittext_box` | 5 | 7.7s |  |
| 139 | `avm2_bitmapdata_draw_filtered` | 11 | 7.8s |  |
| 140 | `avm2_bitmapdata_draw_textfield` | 5 | 26.6s |  |
| 141 | `avm2_child_simplebutton` | 10 | 24.7s |  |
| 142 | `avm2_contextmenu_stub` | 4 | 6.9s |  |
| 143 | `avm2_definetext_matrix` | 0 | 9.4s |  |
| 144 | `avm2_e4x_parse_bounded` | 18 | 7.9s |  |
| 145 | `avm2_edittext_placed_cxform` | 0 | 24.1s |  |
| 146 | `avm2_embed_bytearray` | 2 | 24.2s |  |
| 147 | `avm2_external_interface_unavailable` | 8 | 7.0s |  |
| 148 | `avm2_findprop_this_resolution` | 13 | 34.6s |  |
| 149 | `avm2_gc_dynprop_tombstone_purge` | 8 | 9.5s |  |
| 150 | `avm2_gc_string_concat_reclaim` | 10 | 9.3s |  |
| 151 | `avm2_gc_string_survives_collect` | 9 | 9.2s |  |
| 152 | `avm2_goto_catchup_scale` | 4 | 9.3s |  |
| 153 | `avm2_graphics_runtime` | 7 | 35.1s |  |
| 154 | `avm2_group_alpha_cab` | 0 | 31.3s |  |
| 155 | `avm2_group_alpha_filter_cm` | 0 | 9.3s |  |
| 156 | `avm2_group_alpha_layer_aadd` | 0 | 26.4s |  |
| 157 | `avm2_group_alpha_layer_inner` | 0 | 7.2s |  |
| 158 | `avm2_group_alpha_multiply` | 0 | 7.1s |  |
| 159 | `avm2_json_roundtrip_bounded` | 13 | 23.5s |  |
| 160 | `avm2_layer_group_alpha` | 0 | 7.8s |  |
| 161 | `avm2_layer_group_alpha_transparency` | 0 | 1.2s |  |
| 162 | `avm2_layer_group_erase` | 0 | 1.7s |  |
| 163 | `avm2_layer_group_filtered_child` | 0 | 22.3s |  |
| 164 | `avm2_layer_group_overlap_alpha` | 0 | 40.4s |  |
| 165 | `avm2_loader_stub` | 5 | 33.1s |  |
| 166 | `avm2_localconnection_domain` | 4 | 9.5s |  |
| 167 | `avm2_morph` | 8 | 36.4s |  |
| 168 | `avm2_parent_child_render` | 11 | 12.7s |  |
| 169 | `avm2_parent_child_static_text` | 12 | 10.0s |  |
| 170 | `avm2_parent_child_symbol_stride` | 6 | 11.4s |  |
| 171 | `avm2_parent_child_symbolclass_domain` | 12 | 10.1s |  |
| 172 | `avm2_reflect_trait_hooks` | 30 | 26.3s |  |
| 173 | `avm2_sharedobject_flushstatus` | 4 | 6.8s |  |
| 174 | `avm2_simplebutton_click` | 2 | 6.9s |  |
| 175 | `avm2_slot_default_template` | 34 | 7.1s |  |
| 176 | `avm2_sound_bytes_and_group_format` | 27 | 7.2s |  |
| 177 | `avm2_static_and_store_slots` | 14 | 7.0s |  |
| 178 | `avm2_static_text` | 6 | 24.1s |  |
| 179 | `avm2_strbuf_stale_prefix` | 21 | 6.9s |  |
| 180 | `avm2_timeline_gradients` | 7 | 29.6s |  |
| 181 | `avm2_timeline_solid` | 6 | 7.8s |  |
| 182 | `avm2_timeline_stroke_gradient` | 9 | 8.0s |  |
| 183 | `avm2_timeline_text` | 4 | 24.4s |  |
| 184 | `avm2_tolerant_verify_quarantine` | 2 | 6.9s |  |
| 185 | `avm2_typed_value_ops` | 30 | 7.1s |  |
| 186 | `bitmap_pool_layer_cap` | 1 | 20.2s |  |
| 187 | `broadcast_cross_swf_version` | 4 | 18.8s |  |
| 188 | `broadcast_type1_args` | 14 | 18.9s |  |
| 189 | `coerce_cross_swf_version` | 7 | 18.8s |  |
| 190 | `coerce_recursion_guard` | 1 | 1.5s |  |
| 191 | `coerce_type1_args` | 9 | 1.5s |  |
| 192 | `convertfloat_type1_this` | 3 | 1.5s |  |
| 193 | `ctor_before_first_call_locals` | 5 | 1.6s |  |
| 194 | `ei_closure_scope_order` | 7 | 1.6s |  |
| 195 | `ei_cross_swf_version` | 2 | 1.6s |  |
| 196 | `ei_mc_this_receiver` | 5 | 24.8s |  |
| 197 | `ei_type1_args` | 7 | 24.8s |  |
| 198 | `enterframe_type1_args` | 8 | 24.8s |  |
| 199 | `fn_call_builtin_type1_args` | 10 | 2.4s |  |
| 200 | `fn_call_type1_args` | 7 | 2.3s |  |
| 201 | `fn_empty_method_type1_args` | 10 | 2.3s |  |
| 202 | `group_alpha_cab` | 0 | 5.8s |  |
| 203 | `group_alpha_filter_cm` | 0 | 2.6s |  |
| 204 | `group_alpha_layer_aadd` | 0 | 18.3s |  |
| 205 | `group_alpha_layer_inner` | 0 | 1.7s |  |
| 206 | `group_alpha_multiply` | 0 | 1.7s |  |
| 207 | `layer_group_alpha_transparency` | 0 | 0.9s |  |
| 208 | `layer_group_filtered_child` | 0 | 15.9s |  |
| 209 | `layer_group_in_add_alpha` | 0 | 5.0s |  |
| 210 | `layer_group_overlap_alpha` | 0 | 1.8s |  |
| 211 | `layer_group_overlap_erase` | 0 | 0.9s |  |
| 212 | `lc_method_type1_args` | 7 | 19.2s |  |
| 213 | `lc_onstatus_type1_args` | 3 | 1.5s |  |
| 214 | `lv_cross_swf_version` | 5 | 19.2s |  |
| 215 | `lv_ondata_type1_args` | 3 | 19.2s |  |
| 216 | `mask_nested_intersect` | 1 | 21.9s |  |
| 217 | `mask_sibling_union` | 1 | 1.7s |  |
| 218 | `mc_event_cross_swf_version` | 4 | 1.7s |  |
| 219 | `mc_event_type1_args` | 3 | 1.6s |  |
| 220 | `mc_method_v5_caller_gate` | 4 | 18.9s |  |
| 221 | `mc_resolve_type1_args` | 6 | 19.0s |  |
| 222 | `method_type1_args` | 10 | 1.5s |  |
| 223 | `nc_onstatus_closure` | 2 | 19.0s |  |
| 224 | `nc_onstatus_type1_args` | 3 | 1.6s |  |
| 225 | `onconstruct_cross_swf_version` | 4 | 1.7s |  |
| 226 | `onconstruct_type1_args` | 6 | 1.3s |  |
| 227 | `onload_type1_args` | 7 | 1.4s |  |
| 228 | `onunload_type1_args` | 6 | 24.4s |  |
| 229 | `onunload_type1_local_frame` | 2 | 2.0s |  |
| 230 | `resolve_type1_args` | 13 | 2.1s |  |
| 231 | `root_enterframe_cross_swf_version` | 3 | 24.7s |  |
| 232 | `sort_comparator_captured_scope` | 2 | 2.4s |  |
| 233 | `sort_comparator_type1_args` | 5 | 2.2s |  |
| 234 | `string_prim_method_type1_args` | 19 | 2.4s |  |
| 235 | `timer_cross_swf_version` | 3 | 24.9s |  |
| 236 | `timer_type1_args` | 14 | 18.8s |  |
| 237 | `watch_cross_swf_version` | 6 | 19.3s |  |
| 238 | `watch_mc_reentrant_setmember` | 3 | 18.5s |  |
| 239 | `watch_mc_type1_args` | 7 | 1.5s |  |
| 240 | `watch_setmember_type1_args` | 7 | 1.5s |  |
| 241 | `watch_timeline_named_params` | 4 | 1.5s |  |
| 242 | `watch_timeline_reentrant` | 3 | 1.6s |  |
| 243 | `xml_onload_type1_args` | 3 | 18.7s |  |

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
