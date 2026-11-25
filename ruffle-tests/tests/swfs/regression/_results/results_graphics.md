# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-25 21:42 UTC

**Git SHA**: `10a5b515a0`

**Run Duration**: 52m 6s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 262 |
| Passing | **262** (100.0%) |
| Failing | 0 |
| Total expected lines | 2102 |
| Matching lines | 2102 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**262 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 19.1s |  |
| 2 | `array_method_type1_args` | 7 | 1.5s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 21.9s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.7s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.7s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.7s |  |
| 7 | `avm1_applyfilter_glow` | 18 | 1.7s |  |
| 8 | `avm1_applyfilter_kernels` | 17 | 1.7s |  |
| 9 | `avm1_array_generic_receivers` | 16 | 1.6s |  |
| 10 | `avm1_array_native_own_method` | 8 | 18.9s |  |
| 11 | `avm1_attach_clipevent_enterframe` | 11 | 18.3s |  |
| 12 | `avm1_attach_from_stopped_root_enterframe` | 13 | 2.1s |  |
| 13 | `avm1_attached_clip_button_click` | 13 | 18.8s |  |
| 14 | `avm1_attached_clip_color` | 2 | 20.7s |  |
| 15 | `avm1_attached_clip_goto_play` | 14 | 18.0s |  |
| 16 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.3s |  |
| 17 | `avm1_attached_clip_hidden_capture` | 6 | 17.9s |  |
| 18 | `avm1_attached_clip_holder_render` | 1 | 1.8s |  |
| 19 | `avm1_attached_clip_natural_timeline` | 34 | 19.4s |  |
| 20 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.7s |  |
| 21 | `avm1_attached_clip_samename_child` | 32 | 19.2s |  |
| 22 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 19.2s |  |
| 23 | `avm1_attached_clip_tagorder` | 34 | 1.7s |  |
| 24 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.8s |  |
| 25 | `avm1_attached_clip_tagorder_po3` | 34 | 1.7s |  |
| 26 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.7s |  |
| 27 | `avm1_attached_clip_timeline_child_parent` | 6 | 18.9s |  |
| 28 | `avm1_bare_depth_methods_v7_gate` | 6 | 19.4s |  |
| 29 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 0.9s |  |
| 30 | `avm1_bare_mc_method_scope` | 19 | 19.5s |  |
| 31 | `avm1_bitmap_nearest_tie_stage` | 1 | 22.2s |  |
| 32 | `avm1_bitmapdata_draw_child_color` | 5 | 19.6s |  |
| 33 | `avm1_bitmapdata_draw_edittext` | 3 | 1.7s |  |
| 34 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 19.9s |  |
| 35 | `avm1_browser_eager_init` | 10 | 19.6s |  |
| 36 | `avm1_browser_gated_color` | 3 | 1.6s |  |
| 37 | `avm1_browser_gated_depth` | 7 | 18.7s |  |
| 38 | `avm1_browser_gated_textfield` | 7 | 1.6s |  |
| 39 | `avm1_browser_parked_frame` | 7 | 18.9s |  |
| 40 | `avm1_button_pick_order` | 9 | 2.4s |  |
| 41 | `avm1_button_textfield_path_binding` | 4 | 18.7s |  |
| 42 | `avm1_child_timeline_advance` | 23 | 19.3s |  |
| 43 | `avm1_child_timeline_frame1_stop` | 7 | 1.7s |  |
| 44 | `avm1_child_timeline_holder_stop` | 26 | 1.8s |  |
| 45 | `avm1_child_timeline_loop` | 32 | 1.8s |  |
| 46 | `avm1_clone_depth_overflow` | 3 | 19.6s |  |
| 47 | `avm1_clone_depth_removed_reuse` | 4 | 1.6s |  |
| 48 | `avm1_closure_base_clip_root_frame` | 5 | 1.7s |  |
| 49 | `avm1_closure_method_scope` | 7 | 1.7s |  |
| 50 | `avm1_create_text_field_depth` | 9 | 1.6s |  |
| 51 | `avm1_cxform_override_overflow` | 2 | 19.1s |  |
| 52 | `avm1_definetext_matrix` | 0 | 1.6s |  |
| 53 | `avm1_device_edittext_xscale` | 7 | 19.0s |  |
| 54 | `avm1_display_prop_coercion` | 36 | 1.8s |  |
| 55 | `avm1_dynclip_color_transform` | 2 | 2.1s |  |
| 56 | `avm1_edittext_border_subpixel` | 1 | 15.5s |  |
| 57 | `avm1_edittext_cut_copy_selection` | 9 | 15.9s |  |
| 58 | `avm1_edittext_html_delete_runs` | 4 | 15.6s |  |
| 59 | `avm1_edittext_html_typed_runs` | 3 | 1.8s |  |
| 60 | `avm1_edittext_maxchars_clips_insertion` | 4 | 1.6s |  |
| 61 | `avm1_edittext_path_variable_same_frame` | 11 | 15.6s |  |
| 62 | `avm1_edittext_path_variable_scope` | 10 | 1.8s |  |
| 63 | `avm1_edittext_placed_cxform` | 0 | 15.6s |  |
| 64 | `avm1_edittext_placed_cxform_script` | 3 | 24.9s |  |
| 65 | `avm1_edittext_rotated_borders` | 0 | 28.2s |  |
| 66 | `avm1_edittext_rotated_glyphs` | 0 | 25.1s |  |
| 67 | `avm1_edittext_scaled_glyphs` | 0 | 2.4s |  |
| 68 | `avm1_edittext_tab_render` | 1 | 24.9s |  |
| 69 | `avm1_edittext_tabstops_metric` | 9 | 24.9s |  |
| 70 | `avm1_edittext_wordwrap_render` | 5 | 25.1s |  |
| 71 | `avm1_empty_clip_drawing_depth_order` | 1 | 25.1s |  |
| 72 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 25.2s |  |
| 73 | `avm1_exec_order_attached_selfremove` | 18 | 19.4s |  |
| 74 | `avm1_exec_order_dynamic_eligible` | 35 | 19.4s |  |
| 75 | `avm1_filter_list_overflow` | 2 | 19.3s |  |
| 76 | `avm1_func2_param_register_oob` | 4 | 1.6s |  |
| 77 | `avm1_goto_backward_enterframe_once` | 22 | 19.2s |  |
| 78 | `avm1_goto_skipped_init_call` | 6 | 19.2s |  |
| 79 | `avm1_goto_skipped_init_script` | 5 | 1.8s |  |
| 80 | `avm1_goto_skipped_init_timer` | 6 | 1.8s |  |
| 81 | `avm1_hairline_scaled_instances` | 1 | 1.8s |  |
| 82 | `avm1_hittest_hairline` | 28 | 19.4s |  |
| 83 | `avm1_hittest_shape_stale_matrix` | 28 | 19.7s |  |
| 84 | `avm1_holder_drawing_under_children` | 1 | 21.8s |  |
| 85 | `avm1_jpeg3_alpha_bitmap` | 0 | 19.1s |  |
| 86 | `avm1_key_isdown_protected` | 8 | 19.1s |  |
| 87 | `avm1_loaded_bare_goto_seq` | 4 | 19.5s |  |
| 88 | `avm1_loaded_shell_consumers_seq` | 12 | 19.3s |  |
| 89 | `avm1_loaded_shell_root_lookup` | 4 | 19.2s |  |
| 90 | `avm1_loaded_timeline_holder` | 7 | 1.8s |  |
| 91 | `avm1_loaded_unload_deferred` | 5 | 21.3s |  |
| 92 | `avm1_long_text_layout` | 2 | 21.2s |  |
| 93 | `avm1_many_chars_registry` | 4 | 21.2s |  |
| 94 | `avm1_many_defs_registry` | 13 | 23.3s |  |
| 95 | `avm1_many_functions_registry` | 3 | 9.9s |  |
| 96 | `avm1_mc_button_unified_pick` | 21 | 21.6s |  |
| 97 | `avm1_mc_resolve` | 5 | 2.3s |  |
| 98 | `avm1_mcl_holder_totalframes` | 5 | 2.5s |  |
| 99 | `avm1_mcl_load_tick` | 14 | 2.4s |  |
| 100 | `avm1_morph_instances_ratio` | 2 | 16.9s |  |
| 101 | `avm1_nested_po3_filters` | 12 | 2.3s |  |
| 102 | `avm1_parent_as3_child_payload` | 2 | 1.8s |  |
| 103 | `avm1_parent_child_bitmap` | 5 | 1.9s |  |
| 104 | `avm1_parent_child_bitmap_fill` | 3 | 17.0s |  |
| 105 | `avm1_parent_child_modify_place` | 5 | 1.9s |  |
| 106 | `avm1_parent_child_morph` | 8 | 1.9s |  |
| 107 | `avm1_parent_child_render` | 7 | 2.0s |  |
| 108 | `avm1_parent_child_sprite_meta` | 8 | 2.1s |  |
| 109 | `avm1_parent_child_text` | 8 | 29.1s |  |
| 110 | `avm1_pixelbounds_dynamic_child` | 1 | 25.2s |  |
| 111 | `avm1_placed_drawing_color` | 1 | 25.6s |  |
| 112 | `avm1_po3_cm_alpha_bias_edge` | 0 | 25.4s |  |
| 113 | `avm1_po3_cm_folded_clear` | 1 | 2.6s |  |
| 114 | `avm1_po3_cm_live_under_cxform` | 0 | 2.6s |  |
| 115 | `avm1_po3_color_matrix_live` | 0 | 2.6s |  |
| 116 | `avm1_po3_color_matrix_live_clear` | 1 | 2.6s |  |
| 117 | `avm1_po3_color_matrix_live_nested` | 0 | 2.5s |  |
| 118 | `avm1_remove_same_name_other_parent` | 4 | 19.4s |  |
| 119 | `avm1_removed_clip_dprops_gc` | 14 | 19.4s |  |
| 120 | `avm1_resolve_dotted_getvariable` | 13 | 1.6s |  |
| 121 | `avm1_root_identity_and_playhead` | 3 | 19.2s |  |
| 122 | `avm1_root_onload_child_order` | 11 | 19.4s |  |
| 123 | `avm1_root_onload_proto` | 7 | 1.7s |  |
| 124 | `avm1_runtime_filters` | 3 | 22.3s |  |
| 125 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.0s |  |
| 126 | `avm1_set_new_text_format_color` | 4 | 19.4s |  |
| 127 | `avm1_set_new_text_format_instance` | 5 | 19.3s |  |
| 128 | `avm1_set_new_text_format_render` | 5 | 21.9s |  |
| 129 | `avm1_set_new_text_format_size` | 5 | 1.6s |  |
| 130 | `avm1_stroke_pixel_snap` | 1 | 19.4s |  |
| 131 | `avm1_stroke_pixel_snap_matrix` | 0 | 19.5s |  |
| 132 | `avm1_stroke_style_id_order` | 1 | 19.3s |  |
| 133 | `avm1_swf6_case_insensitive_builtins` | 42 | 19.5s |  |
| 134 | `avm1_swf7_case_sensitive_builtins` | 40 | 0.9s |  |
| 135 | `avm1_textfield_attached_depth_order` | 1 | 1.8s |  |
| 136 | `avm1_textfield_x_bounds_offset` | 10 | 24.6s |  |
| 137 | `avm1_timer_clock_model` | 19 | 25.2s |  |
| 138 | `avm1_timer_function_form_activation` | 3 | 24.7s |  |
| 139 | `avm1_timer_method_form` | 6 | 25.0s |  |
| 140 | `avm1_timer_native_method_play` | 3 | 2.5s |  |
| 141 | `avm1_timer_overflow` | 10 | 3.3s |  |
| 142 | `avm1_timer_root_goto_stopped_gs` | 3 | 2.5s |  |
| 143 | `avm1_timer_root_goto_stopped_nf` | 3 | 2.4s |  |
| 144 | `avm1_type2_mc_receiver_dispatch` | 7 | 2.5s |  |
| 145 | `avm1_watch_long_name` | 9 | 26.6s |  |
| 146 | `avm1_watch_overflow` | 2 | 3.6s |  |
| 147 | `avm1_wrap_giveup_mixed_runs` | 2 | 2.8s |  |
| 148 | `avm1_xml_first_action_proto` | 2 | 2.7s |  |
| 149 | `avm1_xmlnode_first_action_proto` | 2 | 2.6s |  |
| 150 | `avm1_xscale_double_readback` | 8 | 26.8s |  |
| 151 | `avm2_activation_vtable_bounded` | 5 | 57.4s |  |
| 152 | `avm2_agi_shell` | 6 | 10.6s |  |
| 153 | `avm2_applyfilter_glow_kernels` | 17 | 10.6s |  |
| 154 | `avm2_applyfilter_gradient_opaque` | 24 | 54.3s |  |
| 155 | `avm2_array_growth_bounded` | 5 | 10.6s |  |
| 156 | `avm2_bitmapdata_draw_edittext_box` | 5 | 9.6s |  |
| 157 | `avm2_bitmapdata_draw_filtered` | 11 | 9.7s |  |
| 158 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 10.5s |  |
| 159 | `avm2_bitmapdata_draw_textfield` | 5 | 10.3s |  |
| 160 | `avm2_child_simplebutton` | 10 | 32.5s |  |
| 161 | `avm2_contextmenu_stub` | 4 | 9.6s |  |
| 162 | `avm2_definetext_matrix` | 0 | 13.0s |  |
| 163 | `avm2_e4x_parse_bounded` | 18 | 41.2s |  |
| 164 | `avm2_edittext_placed_cxform` | 0 | 27.0s |  |
| 165 | `avm2_embed_bytearray` | 2 | 24.4s |  |
| 166 | `avm2_external_interface_unavailable` | 8 | 7.0s |  |
| 167 | `avm2_findprop_this_resolution` | 13 | 7.0s |  |
| 168 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.2s |  |
| 169 | `avm2_gc_string_concat_reclaim` | 10 | 7.1s |  |
| 170 | `avm2_gc_string_survives_collect` | 9 | 7.0s |  |
| 171 | `avm2_goto_catchup_scale` | 4 | 7.1s |  |
| 172 | `avm2_graphics_runtime` | 7 | 26.3s |  |
| 173 | `avm2_group_alpha_cab` | 0 | 26.0s |  |
| 174 | `avm2_group_alpha_filter_cm` | 0 | 8.3s |  |
| 175 | `avm2_group_alpha_layer_aadd` | 0 | 8.0s |  |
| 176 | `avm2_group_alpha_layer_inner` | 0 | 8.0s |  |
| 177 | `avm2_group_alpha_multiply` | 0 | 1.4s |  |
| 178 | `avm2_json_roundtrip_bounded` | 13 | 8.9s |  |
| 179 | `avm2_layer_group_alpha` | 0 | 8.8s |  |
| 180 | `avm2_layer_group_alpha_transparency` | 0 | 1.3s |  |
| 181 | `avm2_layer_group_erase` | 0 | 10.3s |  |
| 182 | `avm2_layer_group_filtered_child` | 0 | 31.5s |  |
| 183 | `avm2_layer_group_overlap_alpha` | 0 | 31.3s |  |
| 184 | `avm2_loader_stub` | 5 | 9.1s |  |
| 185 | `avm2_localconnection_domain` | 4 | 9.1s |  |
| 186 | `avm2_morph` | 8 | 9.1s |  |
| 187 | `avm2_parent_child_render` | 11 | 12.0s |  |
| 188 | `avm2_parent_child_static_text` | 12 | 9.4s |  |
| 189 | `avm2_parent_child_symbol_stride` | 6 | 10.6s |  |
| 190 | `avm2_parent_child_symbolclass_domain` | 12 | 44.2s |  |
| 191 | `avm2_reflect_trait_hooks` | 30 | 26.6s |  |
| 192 | `avm2_sharedobject_flushstatus` | 4 | 8.2s |  |
| 193 | `avm2_simplebutton_click` | 2 | 8.2s |  |
| 194 | `avm2_slot_default_template` | 34 | 8.2s |  |
| 195 | `avm2_sound_bytes_and_group_format` | 27 | 8.4s |  |
| 196 | `avm2_static_and_store_slots` | 14 | 8.4s |  |
| 197 | `avm2_static_text` | 6 | 27.4s |  |
| 198 | `avm2_strbuf_stale_prefix` | 21 | 8.3s |  |
| 199 | `avm2_timeline_gradients` | 7 | 8.1s |  |
| 200 | `avm2_timeline_solid` | 6 | 8.0s |  |
| 201 | `avm2_timeline_stroke_gradient` | 9 | 8.1s |  |
| 202 | `avm2_timeline_text` | 4 | 7.4s |  |
| 203 | `avm2_tolerant_verify_quarantine` | 2 | 7.1s |  |
| 204 | `avm2_typed_value_ops` | 30 | 7.2s |  |
| 205 | `bitmap_pool_layer_cap` | 1 | 20.8s |  |
| 206 | `broadcast_cross_swf_version` | 4 | 19.4s |  |
| 207 | `broadcast_type1_args` | 14 | 19.6s |  |
| 208 | `coerce_cross_swf_version` | 7 | 19.7s |  |
| 209 | `coerce_recursion_guard` | 1 | 1.6s |  |
| 210 | `coerce_type1_args` | 9 | 1.6s |  |
| 211 | `convertfloat_type1_this` | 3 | 1.6s |  |
| 212 | `ctor_before_first_call_locals` | 5 | 1.6s |  |
| 213 | `ei_closure_scope_order` | 7 | 1.7s |  |
| 214 | `ei_cross_swf_version` | 2 | 1.6s |  |
| 215 | `ei_mc_this_receiver` | 5 | 18.8s |  |
| 216 | `ei_type1_args` | 7 | 18.8s |  |
| 217 | `enterframe_type1_args` | 8 | 18.9s |  |
| 218 | `fn_call_builtin_type1_args` | 10 | 1.6s |  |
| 219 | `fn_call_type1_args` | 7 | 1.5s |  |
| 220 | `fn_empty_method_type1_args` | 10 | 1.5s |  |
| 221 | `group_alpha_cab` | 0 | 3.8s |  |
| 222 | `group_alpha_filter_cm` | 0 | 1.7s |  |
| 223 | `group_alpha_layer_aadd` | 0 | 21.0s |  |
| 224 | `group_alpha_layer_inner` | 0 | 1.4s |  |
| 225 | `group_alpha_multiply` | 0 | 1.4s |  |
| 226 | `layer_group_alpha_transparency` | 0 | 0.8s |  |
| 227 | `layer_group_filtered_child` | 0 | 18.6s |  |
| 228 | `layer_group_in_add_alpha` | 0 | 5.2s |  |
| 229 | `layer_group_overlap_alpha` | 0 | 1.4s |  |
| 230 | `layer_group_overlap_erase` | 0 | 0.9s |  |
| 231 | `lc_method_type1_args` | 7 | 18.9s |  |
| 232 | `lc_onstatus_type1_args` | 3 | 1.5s |  |
| 233 | `lv_cross_swf_version` | 5 | 19.0s |  |
| 234 | `lv_ondata_type1_args` | 3 | 18.8s |  |
| 235 | `mask_nested_intersect` | 1 | 21.3s |  |
| 236 | `mask_sibling_union` | 1 | 1.6s |  |
| 237 | `mc_event_cross_swf_version` | 4 | 1.6s |  |
| 238 | `mc_event_type1_args` | 3 | 1.6s |  |
| 239 | `mc_method_v5_caller_gate` | 4 | 19.1s |  |
| 240 | `mc_resolve_type1_args` | 6 | 19.0s |  |
| 241 | `method_type1_args` | 10 | 1.6s |  |
| 242 | `nc_onstatus_closure` | 2 | 19.1s |  |
| 243 | `nc_onstatus_type1_args` | 3 | 1.6s |  |
| 244 | `onconstruct_cross_swf_version` | 4 | 1.7s |  |
| 245 | `onconstruct_type1_args` | 6 | 1.6s |  |
| 246 | `onload_type1_args` | 7 | 1.6s |  |
| 247 | `onunload_type1_args` | 6 | 20.4s |  |
| 248 | `onunload_type1_local_frame` | 2 | 2.0s |  |
| 249 | `resolve_type1_args` | 13 | 2.0s |  |
| 250 | `root_enterframe_cross_swf_version` | 3 | 20.4s |  |
| 251 | `sort_comparator_captured_scope` | 2 | 2.2s |  |
| 252 | `sort_comparator_type1_args` | 5 | 2.1s |  |
| 253 | `string_prim_method_type1_args` | 19 | 2.0s |  |
| 254 | `timer_cross_swf_version` | 3 | 20.5s |  |
| 255 | `timer_type1_args` | 14 | 20.5s |  |
| 256 | `watch_cross_swf_version` | 6 | 20.4s |  |
| 257 | `watch_mc_reentrant_setmember` | 3 | 20.1s |  |
| 258 | `watch_mc_type1_args` | 7 | 2.0s |  |
| 259 | `watch_setmember_type1_args` | 7 | 2.0s |  |
| 260 | `watch_timeline_named_params` | 4 | 2.0s |  |
| 261 | `watch_timeline_reentrant` | 3 | 2.0s |  |
| 262 | `xml_onload_type1_args` | 3 | 20.2s |  |

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
