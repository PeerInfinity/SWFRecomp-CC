# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-26 21:04 UTC

**Git SHA**: `bfa47037b1`

**Run Duration**: 50m 45s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 292 |
| Passing | **292** (100.0%) |
| Failing | 0 |
| Total expected lines | 3005 |
| Matching lines | 3005 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**292 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 19.3s |  |
| 2 | `array_method_type1_args` | 7 | 0.9s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 1.1s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.1s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.1s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.1s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.1s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.1s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.1s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.0s |  |
| 11 | `avm1_array_native_own_method` | 8 | 0.9s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 18.8s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.1s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 1.1s |  |
| 15 | `avm1_attached_clip_color` | 2 | 18.8s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 18.9s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 0.5s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 18.8s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 0.9s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 1.3s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 2.4s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 26.7s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 27.4s |  |
| 24 | `avm1_attached_clip_selfgoto_trace` | 14 | 26.8s |  |
| 25 | `avm1_attached_clip_tagorder` | 34 | 1.9s |  |
| 26 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.4s |  |
| 27 | `avm1_attached_clip_tagorder_po3` | 34 | 1.8s |  |
| 28 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.8s |  |
| 29 | `avm1_attached_clip_timeline_child_parent` | 6 | 26.4s |  |
| 30 | `avm1_bare_depth_methods_v7_gate` | 6 | 1.6s |  |
| 31 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 23.1s |  |
| 32 | `avm1_bare_mc_method_scope` | 19 | 23.6s |  |
| 33 | `avm1_bitmap_nearest_tie_stage` | 1 | 23.4s |  |
| 34 | `avm1_bitmapdata_draw_child_color` | 5 | 23.7s |  |
| 35 | `avm1_bitmapdata_draw_edittext` | 3 | 1.3s |  |
| 36 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 23.7s |  |
| 37 | `avm1_browser_eager_init` | 10 | 24.0s |  |
| 38 | `avm1_browser_gated_color` | 3 | 1.2s |  |
| 39 | `avm1_browser_gated_depth` | 7 | 1.2s |  |
| 40 | `avm1_browser_gated_textfield` | 7 | 1.2s |  |
| 41 | `avm1_browser_parked_frame` | 7 | 20.9s |  |
| 42 | `avm1_button_pick_order` | 9 | 2.6s |  |
| 43 | `avm1_button_textfield_path_binding` | 4 | 19.8s |  |
| 44 | `avm1_child_timeline_advance` | 23 | 1.4s |  |
| 45 | `avm1_child_timeline_frame1_stop` | 7 | 1.4s |  |
| 46 | `avm1_child_timeline_holder_stop` | 26 | 1.7s |  |
| 47 | `avm1_child_timeline_loop` | 32 | 1.6s |  |
| 48 | `avm1_clipevent_root_goto_stopped` | 3 | 20.8s |  |
| 49 | `avm1_clone_depth_overflow` | 3 | 1.9s |  |
| 50 | `avm1_clone_depth_removed_reuse` | 4 | 1.2s |  |
| 51 | `avm1_closure_base_clip_root_frame` | 5 | 1.4s |  |
| 52 | `avm1_closure_method_scope` | 7 | 1.4s |  |
| 53 | `avm1_create_text_field_depth` | 9 | 23.6s |  |
| 54 | `avm1_cxform_override_overflow` | 2 | 23.9s |  |
| 55 | `avm1_definetext_matrix` | 0 | 1.2s |  |
| 56 | `avm1_device_edittext_xscale` | 7 | 23.7s |  |
| 57 | `avm1_display_filter_growth_edge_scale` | 0 | 1.3s |  |
| 58 | `avm1_display_prop_coercion` | 36 | 1.5s |  |
| 59 | `avm1_drawapi_stroke_snap` | 1 | 23.8s |  |
| 60 | `avm1_drawing_stroke_scale` | 0 | 25.6s |  |
| 61 | `avm1_dynclip_color_transform` | 2 | 1.1s |  |
| 62 | `avm1_edittext_border_subpixel` | 1 | 19.0s |  |
| 63 | `avm1_edittext_cut_copy_selection` | 9 | 18.8s |  |
| 64 | `avm1_edittext_html_delete_runs` | 4 | 18.8s |  |
| 65 | `avm1_edittext_html_typed_runs` | 3 | 1.1s |  |
| 66 | `avm1_edittext_maxchars_clips_insertion` | 4 | 18.9s |  |
| 67 | `avm1_edittext_path_variable_same_frame` | 11 | 18.7s |  |
| 68 | `avm1_edittext_path_variable_scope` | 10 | 1.1s |  |
| 69 | `avm1_edittext_placed_cxform` | 0 | 18.8s |  |
| 70 | `avm1_edittext_placed_cxform_script` | 3 | 0.9s |  |
| 71 | `avm1_edittext_restrict_onchanged` | 6 | 19.0s |  |
| 72 | `avm1_edittext_rotated_borders` | 0 | 18.8s |  |
| 73 | `avm1_edittext_rotated_glyphs` | 0 | 18.8s |  |
| 74 | `avm1_edittext_scaled_glyphs` | 0 | 0.9s |  |
| 75 | `avm1_edittext_tab_render` | 1 | 18.7s |  |
| 76 | `avm1_edittext_tabstops_metric` | 9 | 18.6s |  |
| 77 | `avm1_edittext_wordwrap_render` | 5 | 18.6s |  |
| 78 | `avm1_empty_clip_drawing_depth_order` | 1 | 1.1s |  |
| 79 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 18.9s |  |
| 80 | `avm1_enterframe_root_goto_opcode` | 7 | 18.5s |  |
| 81 | `avm1_exec_order_attached_selfremove` | 18 | 18.9s |  |
| 82 | `avm1_exec_order_dynamic_eligible` | 35 | 1.2s |  |
| 83 | `avm1_filter_list_overflow` | 2 | 1.0s |  |
| 84 | `avm1_func2_param_register_oob` | 4 | 0.9s |  |
| 85 | `avm1_gnash_flash_probes` | 63 | 1.3s |  |
| 86 | `avm1_gnash_flash_probes_v5` | 77 | 0.3s |  |
| 87 | `avm1_gnash_flash_probes_v6` | 63 | 0.3s |  |
| 88 | `avm1_goto_backward_enterframe_once` | 22 | 18.8s |  |
| 89 | `avm1_goto_skipped_init_call` | 6 | 18.9s |  |
| 90 | `avm1_goto_skipped_init_script` | 5 | 1.1s |  |
| 91 | `avm1_goto_skipped_init_timer` | 6 | 24.6s |  |
| 92 | `avm1_hairline_scaled_instances` | 1 | 24.5s |  |
| 93 | `avm1_hittest_hairline` | 28 | 24.4s |  |
| 94 | `avm1_hittest_shape_stale_matrix` | 28 | 24.6s |  |
| 95 | `avm1_holder_drawing_under_children` | 1 | 25.1s |  |
| 96 | `avm1_jpeg3_alpha_bitmap` | 0 | 23.9s |  |
| 97 | `avm1_key_isdown_protected` | 8 | 24.2s |  |
| 98 | `avm1_loaded_bare_goto` | 17 | 25.1s |  |
| 99 | `avm1_loaded_bare_goto_seq` | 4 | 2.3s |  |
| 100 | `avm1_loaded_goto_play_deferred` | 31 | 24.8s |  |
| 101 | `avm1_loaded_order_create_vs_load` | 33 | 25.0s |  |
| 102 | `avm1_loaded_shell_consumers_seq` | 12 | 24.6s |  |
| 103 | `avm1_loaded_shell_root_lookup` | 4 | 24.7s |  |
| 104 | `avm1_loaded_timeline_holder` | 7 | 1.8s |  |
| 105 | `avm1_loaded_unload_deferred` | 5 | 1.9s |  |
| 106 | `avm1_loadvars_ondata_overflow` | 23 | 1.9s |  |
| 107 | `avm1_long_text_layout` | 2 | 1.6s |  |
| 108 | `avm1_many_chars_registry` | 4 | 24.8s |  |
| 109 | `avm1_many_defs_registry` | 13 | 26.4s |  |
| 110 | `avm1_many_functions_registry` | 3 | 11.2s |  |
| 111 | `avm1_mc_button_unified_pick` | 21 | 1.3s |  |
| 112 | `avm1_mc_resolve` | 5 | 0.9s |  |
| 113 | `avm1_mcl_holder_totalframes` | 5 | 1.1s |  |
| 114 | `avm1_mcl_load_tick` | 15 | 1.1s |  |
| 115 | `avm1_morph_instances_ratio` | 2 | 14.7s |  |
| 116 | `avm1_nested_po3_filters` | 12 | 1.1s |  |
| 117 | `avm1_onunload_setvar_scope` | 5 | 1.0s |  |
| 118 | `avm1_parent_as3_child_payload` | 2 | 1.1s |  |
| 119 | `avm1_parent_child_bitmap` | 5 | 1.1s |  |
| 120 | `avm1_parent_child_bitmap_fill` | 3 | 1.1s |  |
| 121 | `avm1_parent_child_modify_place` | 5 | 1.1s |  |
| 122 | `avm1_parent_child_morph` | 8 | 1.2s |  |
| 123 | `avm1_parent_child_render` | 7 | 1.1s |  |
| 124 | `avm1_parent_child_sprite_meta` | 8 | 1.2s |  |
| 125 | `avm1_parent_child_text` | 8 | 1.2s |  |
| 126 | `avm1_pixelbounds_dynamic_child` | 1 | 18.7s |  |
| 127 | `avm1_place_occupied_depth_swf5` | 6 | 1.0s |  |
| 128 | `avm1_placed_drawing_color` | 1 | 19.1s |  |
| 129 | `avm1_po3_cm_alpha_bias_edge` | 0 | 0.9s |  |
| 130 | `avm1_po3_cm_folded_clear` | 1 | 1.0s |  |
| 131 | `avm1_po3_cm_live_under_cxform` | 0 | 23.9s |  |
| 132 | `avm1_po3_color_matrix_live` | 0 | 1.5s |  |
| 133 | `avm1_po3_color_matrix_live_clear` | 1 | 1.5s |  |
| 134 | `avm1_po3_color_matrix_live_nested` | 0 | 1.4s |  |
| 135 | `avm1_remove_same_name_other_parent` | 4 | 24.6s |  |
| 136 | `avm1_remove_unload_finalize_overflow` | 4 | 27.8s |  |
| 137 | `avm1_removed_clip_dprops_gc` | 14 | 1.8s |  |
| 138 | `avm1_resolve_dotted_getvariable` | 13 | 1.5s |  |
| 139 | `avm1_root_identity_and_playhead` | 3 | 27.1s |  |
| 140 | `avm1_root_onload_child_order` | 11 | 25.8s |  |
| 141 | `avm1_root_onload_proto` | 7 | 18.6s |  |
| 142 | `avm1_runtime_filters` | 3 | 18.9s |  |
| 143 | `avm1_runtime_filters_cm_bitmap` | 5 | 1.0s |  |
| 144 | `avm1_set_new_text_format_color` | 4 | 18.7s |  |
| 145 | `avm1_set_new_text_format_instance` | 5 | 18.8s |  |
| 146 | `avm1_set_new_text_format_paragraph` | 12 | 1.1s |  |
| 147 | `avm1_set_new_text_format_render` | 5 | 18.7s |  |
| 148 | `avm1_set_new_text_format_size` | 5 | 0.9s |  |
| 149 | `avm1_sprite_goto_script_overflow` | 65 | 18.9s |  |
| 150 | `avm1_stroke_join_cap_snap` | 0 | 20.6s |  |
| 151 | `avm1_stroke_noscale_signed` | 0 | 15.4s |  |
| 152 | `avm1_stroke_pixel_snap` | 1 | 14.9s |  |
| 153 | `avm1_stroke_pixel_snap_matrix` | 0 | 15.4s |  |
| 154 | `avm1_stroke_style_id_order` | 1 | 15.1s |  |
| 155 | `avm1_swf6_case_insensitive_builtins` | 42 | 1.1s |  |
| 156 | `avm1_swf7_case_sensitive_builtins` | 40 | 0.3s |  |
| 157 | `avm1_textfield_attached_depth_order` | 1 | 1.1s |  |
| 158 | `avm1_textfield_x_bounds_offset` | 10 | 15.3s |  |
| 159 | `avm1_timer_clock_model` | 19 | 15.6s |  |
| 160 | `avm1_timer_function_form_activation` | 3 | 15.5s |  |
| 161 | `avm1_timer_method_form` | 6 | 1.1s |  |
| 162 | `avm1_timer_native_method_play` | 3 | 1.0s |  |
| 163 | `avm1_timer_overflow` | 10 | 15.9s |  |
| 164 | `avm1_timer_root_goto_stopped_gs` | 3 | 1.0s |  |
| 165 | `avm1_timer_root_goto_stopped_nf` | 3 | 1.0s |  |
| 166 | `avm1_type2_mc_receiver_dispatch` | 7 | 1.0s |  |
| 167 | `avm1_watch_long_name` | 9 | 0.9s |  |
| 168 | `avm1_watch_overflow` | 2 | 1.4s |  |
| 169 | `avm1_wrap_giveup_mixed_runs` | 2 | 0.9s |  |
| 170 | `avm1_xml_first_action_proto` | 2 | 0.9s |  |
| 171 | `avm1_xmlnode_first_action_proto` | 2 | 1.4s |  |
| 172 | `avm1_xscale_double_readback` | 8 | 1.6s |  |
| 173 | `avm2_activation_vtable_bounded` | 5 | 32.2s |  |
| 174 | `avm2_agi_shell` | 6 | 8.4s |  |
| 175 | `avm2_applyfilter_bevel_sample` | 441 | 23.2s |  |
| 176 | `avm2_applyfilter_glow_kernels` | 23 | 8.3s |  |
| 177 | `avm2_applyfilter_gradient_opaque` | 26 | 9.3s |  |
| 178 | `avm2_array_growth_bounded` | 5 | 8.8s |  |
| 179 | `avm2_bitmapdata_draw_edittext_box` | 5 | 8.2s |  |
| 180 | `avm2_bitmapdata_draw_filtered` | 13 | 8.2s |  |
| 181 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 25.1s |  |
| 182 | `avm2_bitmapdata_draw_textfield` | 5 | 6.2s |  |
| 183 | `avm2_child_simplebutton` | 10 | 24.2s |  |
| 184 | `avm2_contextmenu_stub` | 4 | 5.8s |  |
| 185 | `avm2_definetext_matrix` | 0 | 5.9s |  |
| 186 | `avm2_drawapi_stroke_snap` | 1 | 23.6s |  |
| 187 | `avm2_e4x_parse_bounded` | 18 | 6.9s |  |
| 188 | `avm2_edittext_placed_cxform` | 0 | 23.7s |  |
| 189 | `avm2_edittext_selection_cxform` | 2 | 24.5s |  |
| 190 | `avm2_embed_bytearray` | 2 | 24.0s |  |
| 191 | `avm2_external_interface_unavailable` | 8 | 32.1s |  |
| 192 | `avm2_findprop_this_resolution` | 13 | 6.8s |  |
| 193 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.0s |  |
| 194 | `avm2_gc_string_concat_reclaim` | 10 | 7.0s |  |
| 195 | `avm2_gc_string_survives_collect` | 9 | 6.7s |  |
| 196 | `avm2_goto_catchup_scale` | 4 | 7.0s |  |
| 197 | `avm2_graphics_runtime` | 7 | 29.6s |  |
| 198 | `avm2_group_alpha_cab` | 0 | 29.7s |  |
| 199 | `avm2_group_alpha_filter_cm` | 0 | 6.8s |  |
| 200 | `avm2_group_alpha_layer_aadd` | 0 | 6.8s |  |
| 201 | `avm2_group_alpha_layer_inner` | 0 | 24.1s |  |
| 202 | `avm2_group_alpha_multiply` | 0 | 5.8s |  |
| 203 | `avm2_group_alpha_shadow_shape_a50` | 0 | 5.9s |  |
| 204 | `avm2_json_roundtrip_bounded` | 13 | 6.7s |  |
| 205 | `avm2_layer_group_alpha` | 0 | 6.2s |  |
| 206 | `avm2_layer_group_alpha_transparency` | 0 | 0.4s |  |
| 207 | `avm2_layer_group_erase` | 0 | 0.6s |  |
| 208 | `avm2_layer_group_filtered_child` | 0 | 24.6s |  |
| 209 | `avm2_layer_group_overlap_alpha` | 0 | 5.8s |  |
| 210 | `avm2_loader_stub` | 5 | 5.8s |  |
| 211 | `avm2_localconnection_domain` | 4 | 8.0s |  |
| 212 | `avm2_morph` | 8 | 30.3s |  |
| 213 | `avm2_parent_child_render` | 11 | 10.9s |  |
| 214 | `avm2_parent_child_static_text` | 12 | 8.4s |  |
| 215 | `avm2_parent_child_symbol_stride` | 6 | 31.9s |  |
| 216 | `avm2_parent_child_symbolclass_domain` | 12 | 8.5s |  |
| 217 | `avm2_reflect_trait_hooks` | 30 | 8.3s |  |
| 218 | `avm2_sharedobject_flushstatus` | 4 | 8.0s |  |
| 219 | `avm2_simplebutton_click` | 2 | 8.2s |  |
| 220 | `avm2_slot_default_template` | 34 | 8.2s |  |
| 221 | `avm2_sound_bytes_and_group_format` | 27 | 6.1s |  |
| 222 | `avm2_static_and_store_slots` | 14 | 5.9s |  |
| 223 | `avm2_static_text` | 6 | 19.2s |  |
| 224 | `avm2_strbuf_stale_prefix` | 21 | 5.8s |  |
| 225 | `avm2_timeline_gradients` | 7 | 24.1s |  |
| 226 | `avm2_timeline_solid` | 6 | 6.6s |  |
| 227 | `avm2_timeline_stroke_gradient` | 9 | 6.7s |  |
| 228 | `avm2_timeline_text` | 4 | 6.1s |  |
| 229 | `avm2_tolerant_verify_quarantine` | 2 | 5.7s |  |
| 230 | `avm2_typed_value_ops` | 30 | 24.1s |  |
| 231 | `bitmap_pool_layer_cap` | 1 | 18.8s |  |
| 232 | `broadcast_cross_swf_version` | 4 | 18.5s |  |
| 233 | `broadcast_type1_args` | 14 | 18.5s |  |
| 234 | `coerce_cross_swf_version` | 7 | 1.0s |  |
| 235 | `coerce_recursion_guard` | 1 | 0.9s |  |
| 236 | `coerce_type1_args` | 9 | 0.9s |  |
| 237 | `convertfloat_type1_this` | 3 | 0.9s |  |
| 238 | `ctor_before_first_call_locals` | 5 | 0.9s |  |
| 239 | `ei_closure_scope_order` | 7 | 24.0s |  |
| 240 | `ei_cross_swf_version` | 2 | 1.4s |  |
| 241 | `ei_mc_this_receiver` | 5 | 1.5s |  |
| 242 | `ei_type1_args` | 7 | 1.4s |  |
| 243 | `enterframe_type1_args` | 8 | 23.9s |  |
| 244 | `fn_call_builtin_type1_args` | 10 | 1.4s |  |
| 245 | `fn_call_type1_args` | 7 | 1.4s |  |
| 246 | `fn_empty_method_type1_args` | 10 | 1.4s |  |
| 247 | `group_alpha_cab` | 0 | 1.4s |  |
| 248 | `group_alpha_filter_cm` | 0 | 18.9s |  |
| 249 | `group_alpha_layer_aadd` | 0 | 0.9s |  |
| 250 | `group_alpha_layer_inner` | 0 | 0.9s |  |
| 251 | `group_alpha_multiply` | 0 | 0.9s |  |
| 252 | `group_alpha_shadow_shape_a50` | 0 | 0.9s |  |
| 253 | `layer_group_alpha_transparency` | 0 | 0.2s |  |
| 254 | `layer_group_filtered_child` | 0 | 19.0s |  |
| 255 | `layer_group_in_add_alpha` | 0 | 0.9s |  |
| 256 | `layer_group_overlap_alpha` | 0 | 0.9s |  |
| 257 | `layer_group_overlap_erase` | 0 | 1.4s |  |
| 258 | `lc_method_type1_args` | 7 | 23.6s |  |
| 259 | `lc_onstatus_type1_args` | 3 | 1.4s |  |
| 260 | `lowq_fill_edges` | 0 | 23.7s |  |
| 261 | `lowq_gradient_orient_probe` | 0 | 23.8s |  |
| 262 | `lowq_sample_point_probe` | 0 | 23.6s |  |
| 263 | `lv_cross_swf_version` | 5 | 23.8s |  |
| 264 | `lv_ondata_type1_args` | 3 | 23.6s |  |
| 265 | `mask_nested_intersect` | 1 | 1.5s |  |
| 266 | `mask_sibling_union` | 1 | 1.0s |  |
| 267 | `mc_event_cross_swf_version` | 4 | 19.8s |  |
| 268 | `mc_event_type1_args` | 3 | 19.8s |  |
| 269 | `mc_method_v5_caller_gate` | 4 | 1.1s |  |
| 270 | `mc_resolve_type1_args` | 6 | 1.0s |  |
| 271 | `method_type1_args` | 10 | 1.0s |  |
| 272 | `nc_onstatus_closure` | 2 | 19.7s |  |
| 273 | `nc_onstatus_type1_args` | 3 | 1.0s |  |
| 274 | `onconstruct_cross_swf_version` | 4 | 1.0s |  |
| 275 | `onconstruct_type1_args` | 6 | 18.7s |  |
| 276 | `onload_type1_args` | 7 | 18.6s |  |
| 277 | `onunload_type1_args` | 6 | 0.9s |  |
| 278 | `onunload_type1_local_frame` | 2 | 0.9s |  |
| 279 | `resolve_type1_args` | 13 | 0.9s |  |
| 280 | `root_enterframe_cross_swf_version` | 3 | 18.7s |  |
| 281 | `sort_comparator_captured_scope` | 2 | 1.0s |  |
| 282 | `sort_comparator_type1_args` | 5 | 0.9s |  |
| 283 | `string_prim_method_type1_args` | 19 | 0.9s |  |
| 284 | `timer_cross_swf_version` | 3 | 23.7s |  |
| 285 | `timer_type1_args` | 14 | 23.6s |  |
| 286 | `watch_cross_swf_version` | 6 | 1.4s |  |
| 287 | `watch_mc_reentrant_setmember` | 3 | 23.6s |  |
| 288 | `watch_mc_type1_args` | 7 | 1.2s |  |
| 289 | `watch_setmember_type1_args` | 7 | 1.3s |  |
| 290 | `watch_timeline_named_params` | 4 | 1.3s |  |
| 291 | `watch_timeline_reentrant` | 3 | 1.2s |  |
| 292 | `xml_onload_type1_args` | 3 | 23.6s |  |

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
