# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-26 18:40 UTC

**Git SHA**: `ed63ce7c43`

**Run Duration**: 62m 51s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 289 |
| Passing | **289** (100.0%) |
| Failing | 0 |
| Total expected lines | 2991 |
| Matching lines | 2991 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**289 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 15.8s |  |
| 2 | `array_method_type1_args` | 7 | 1.6s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 2.1s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.8s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.8s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.8s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.8s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.7s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.7s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.6s |  |
| 11 | `avm1_array_native_own_method` | 8 | 26.8s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 26.0s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 2.8s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 27.7s |  |
| 15 | `avm1_attached_clip_color` | 2 | 29.4s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 25.8s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.7s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 25.9s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 2.6s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 27.3s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 27.2s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 27.2s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 30.3s |  |
| 24 | `avm1_attached_clip_tagorder` | 34 | 2.7s |  |
| 25 | `avm1_attached_clip_tagorder_nonroot` | 34 | 1.2s |  |
| 26 | `avm1_attached_clip_tagorder_po3` | 34 | 2.5s |  |
| 27 | `avm1_attached_clip_tagorder_ratio` | 34 | 2.5s |  |
| 28 | `avm1_attached_clip_timeline_child_parent` | 6 | 26.8s |  |
| 29 | `avm1_bare_depth_methods_v7_gate` | 6 | 26.6s |  |
| 30 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 1.4s |  |
| 31 | `avm1_bare_mc_method_scope` | 19 | 21.2s |  |
| 32 | `avm1_bitmap_nearest_tie_stage` | 1 | 24.0s |  |
| 33 | `avm1_bitmapdata_draw_child_color` | 5 | 21.6s |  |
| 34 | `avm1_bitmapdata_draw_edittext` | 3 | 2.2s |  |
| 35 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 22.1s |  |
| 36 | `avm1_browser_eager_init` | 10 | 22.3s |  |
| 37 | `avm1_browser_gated_color` | 3 | 21.3s |  |
| 38 | `avm1_browser_gated_depth` | 7 | 2.1s |  |
| 39 | `avm1_browser_gated_textfield` | 7 | 2.1s |  |
| 40 | `avm1_browser_parked_frame` | 7 | 21.8s |  |
| 41 | `avm1_button_pick_order` | 9 | 26.2s |  |
| 42 | `avm1_button_textfield_path_binding` | 4 | 25.0s |  |
| 43 | `avm1_child_timeline_advance` | 23 | 25.4s |  |
| 44 | `avm1_child_timeline_frame1_stop` | 7 | 2.7s |  |
| 45 | `avm1_child_timeline_holder_stop` | 26 | 2.7s |  |
| 46 | `avm1_child_timeline_loop` | 32 | 2.8s |  |
| 47 | `avm1_clipevent_root_goto_stopped` | 3 | 25.2s |  |
| 48 | `avm1_clone_depth_overflow` | 3 | 3.2s |  |
| 49 | `avm1_clone_depth_removed_reuse` | 4 | 2.4s |  |
| 50 | `avm1_closure_base_clip_root_frame` | 5 | 2.6s |  |
| 51 | `avm1_closure_method_scope` | 7 | 1.8s |  |
| 52 | `avm1_create_text_field_depth` | 9 | 19.7s |  |
| 53 | `avm1_cxform_override_overflow` | 2 | 19.7s |  |
| 54 | `avm1_definetext_matrix` | 0 | 1.5s |  |
| 55 | `avm1_device_edittext_xscale` | 7 | 19.8s |  |
| 56 | `avm1_display_filter_growth_edge_scale` | 0 | 2.0s |  |
| 57 | `avm1_display_prop_coercion` | 36 | 1.7s |  |
| 58 | `avm1_drawapi_stroke_snap` | 1 | 20.2s |  |
| 59 | `avm1_drawing_stroke_scale` | 0 | 21.4s |  |
| 60 | `avm1_dynclip_color_transform` | 2 | 1.9s |  |
| 61 | `avm1_edittext_border_subpixel` | 1 | 19.2s |  |
| 62 | `avm1_edittext_cut_copy_selection` | 9 | 19.4s |  |
| 63 | `avm1_edittext_html_delete_runs` | 4 | 19.2s |  |
| 64 | `avm1_edittext_html_typed_runs` | 3 | 1.8s |  |
| 65 | `avm1_edittext_maxchars_clips_insertion` | 4 | 19.3s |  |
| 66 | `avm1_edittext_path_variable_same_frame` | 11 | 19.4s |  |
| 67 | `avm1_edittext_path_variable_scope` | 10 | 1.8s |  |
| 68 | `avm1_edittext_placed_cxform` | 0 | 19.3s |  |
| 69 | `avm1_edittext_placed_cxform_script` | 3 | 1.6s |  |
| 70 | `avm1_edittext_restrict_onchanged` | 6 | 1.6s |  |
| 71 | `avm1_edittext_rotated_borders` | 0 | 21.8s |  |
| 72 | `avm1_edittext_rotated_glyphs` | 0 | 19.2s |  |
| 73 | `avm1_edittext_scaled_glyphs` | 0 | 1.6s |  |
| 74 | `avm1_edittext_tab_render` | 1 | 19.3s |  |
| 75 | `avm1_edittext_tabstops_metric` | 9 | 19.3s |  |
| 76 | `avm1_edittext_wordwrap_render` | 5 | 19.4s |  |
| 77 | `avm1_empty_clip_drawing_depth_order` | 1 | 19.4s |  |
| 78 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 19.4s |  |
| 79 | `avm1_enterframe_root_goto_opcode` | 7 | 19.1s |  |
| 80 | `avm1_exec_order_attached_selfremove` | 18 | 19.5s |  |
| 81 | `avm1_exec_order_dynamic_eligible` | 35 | 18.0s |  |
| 82 | `avm1_filter_list_overflow` | 2 | 17.4s |  |
| 83 | `avm1_func2_param_register_oob` | 4 | 1.7s |  |
| 84 | `avm1_gnash_flash_probes` | 63 | 18.5s |  |
| 85 | `avm1_gnash_flash_probes_v5` | 77 | 1.0s |  |
| 86 | `avm1_gnash_flash_probes_v6` | 63 | 1.0s |  |
| 87 | `avm1_goto_backward_enterframe_once` | 22 | 18.2s |  |
| 88 | `avm1_goto_skipped_init_call` | 6 | 18.2s |  |
| 89 | `avm1_goto_skipped_init_script` | 5 | 2.2s |  |
| 90 | `avm1_goto_skipped_init_timer` | 6 | 2.0s |  |
| 91 | `avm1_hairline_scaled_instances` | 1 | 22.5s |  |
| 92 | `avm1_hittest_hairline` | 28 | 20.1s |  |
| 93 | `avm1_hittest_shape_stale_matrix` | 28 | 20.3s |  |
| 94 | `avm1_holder_drawing_under_children` | 1 | 20.1s |  |
| 95 | `avm1_jpeg3_alpha_bitmap` | 0 | 19.8s |  |
| 96 | `avm1_key_isdown_protected` | 8 | 20.1s |  |
| 97 | `avm1_loaded_bare_goto` | 17 | 20.1s |  |
| 98 | `avm1_loaded_bare_goto_seq` | 4 | 2.2s |  |
| 99 | `avm1_loaded_goto_play_deferred` | 31 | 20.2s |  |
| 100 | `avm1_loaded_order_create_vs_load` | 33 | 2.2s |  |
| 101 | `avm1_loaded_shell_consumers_seq` | 12 | 26.4s |  |
| 102 | `avm1_loaded_shell_root_lookup` | 4 | 26.0s |  |
| 103 | `avm1_loaded_timeline_holder` | 7 | 2.5s |  |
| 104 | `avm1_loaded_unload_deferred` | 5 | 2.6s |  |
| 105 | `avm1_loadvars_ondata_overflow` | 23 | 26.1s |  |
| 106 | `avm1_long_text_layout` | 2 | 26.0s |  |
| 107 | `avm1_many_chars_registry` | 4 | 26.8s |  |
| 108 | `avm1_many_defs_registry` | 13 | 28.3s |  |
| 109 | `avm1_many_functions_registry` | 3 | 11.8s |  |
| 110 | `avm1_mc_button_unified_pick` | 21 | 26.3s |  |
| 111 | `avm1_mc_resolve` | 5 | 21.6s |  |
| 112 | `avm1_mcl_holder_totalframes` | 5 | 22.1s |  |
| 113 | `avm1_mcl_load_tick` | 15 | 2.5s |  |
| 114 | `avm1_morph_instances_ratio` | 2 | 24.6s |  |
| 115 | `avm1_nested_po3_filters` | 12 | 22.6s |  |
| 116 | `avm1_onunload_setvar_scope` | 5 | 21.7s |  |
| 117 | `avm1_parent_as3_child_payload` | 2 | 2.7s |  |
| 118 | `avm1_parent_child_bitmap` | 5 | 2.5s |  |
| 119 | `avm1_parent_child_bitmap_fill` | 3 | 2.7s |  |
| 120 | `avm1_parent_child_modify_place` | 5 | 2.4s |  |
| 121 | `avm1_parent_child_morph` | 8 | 20.6s |  |
| 122 | `avm1_parent_child_render` | 7 | 2.9s |  |
| 123 | `avm1_parent_child_sprite_meta` | 8 | 2.4s |  |
| 124 | `avm1_parent_child_text` | 8 | 2.4s |  |
| 125 | `avm1_pixelbounds_dynamic_child` | 1 | 20.1s |  |
| 126 | `avm1_place_occupied_depth_swf5` | 6 | 2.1s |  |
| 127 | `avm1_placed_drawing_color` | 1 | 20.7s |  |
| 128 | `avm1_po3_cm_alpha_bias_edge` | 0 | 2.1s |  |
| 129 | `avm1_po3_cm_folded_clear` | 1 | 2.1s |  |
| 130 | `avm1_po3_cm_live_under_cxform` | 0 | 2.1s |  |
| 131 | `avm1_po3_color_matrix_live` | 0 | 2.3s |  |
| 132 | `avm1_po3_color_matrix_live_clear` | 1 | 2.3s |  |
| 133 | `avm1_po3_color_matrix_live_nested` | 0 | 2.1s |  |
| 134 | `avm1_remove_same_name_other_parent` | 4 | 20.2s |  |
| 135 | `avm1_remove_unload_finalize_overflow` | 4 | 22.3s |  |
| 136 | `avm1_removed_clip_dprops_gc` | 14 | 2.2s |  |
| 137 | `avm1_resolve_dotted_getvariable` | 13 | 2.0s |  |
| 138 | `avm1_root_identity_and_playhead` | 3 | 20.0s |  |
| 139 | `avm1_root_onload_child_order` | 11 | 2.3s |  |
| 140 | `avm1_root_onload_proto` | 7 | 2.2s |  |
| 141 | `avm1_runtime_filters` | 3 | 23.3s |  |
| 142 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.4s |  |
| 143 | `avm1_set_new_text_format_color` | 4 | 19.9s |  |
| 144 | `avm1_set_new_text_format_instance` | 5 | 19.9s |  |
| 145 | `avm1_set_new_text_format_paragraph` | 12 | 1.9s |  |
| 146 | `avm1_set_new_text_format_render` | 5 | 19.9s |  |
| 147 | `avm1_set_new_text_format_size` | 5 | 1.7s |  |
| 148 | `avm1_sprite_goto_script_overflow` | 65 | 20.1s |  |
| 149 | `avm1_stroke_pixel_snap` | 1 | 19.8s |  |
| 150 | `avm1_stroke_pixel_snap_matrix` | 0 | 20.0s |  |
| 151 | `avm1_stroke_style_id_order` | 1 | 28.9s |  |
| 152 | `avm1_swf6_case_insensitive_builtins` | 42 | 26.0s |  |
| 153 | `avm1_swf7_case_sensitive_builtins` | 40 | 1.4s |  |
| 154 | `avm1_textfield_attached_depth_order` | 1 | 25.5s |  |
| 155 | `avm1_textfield_x_bounds_offset` | 10 | 25.4s |  |
| 156 | `avm1_timer_clock_model` | 19 | 25.8s |  |
| 157 | `avm1_timer_function_form_activation` | 3 | 25.5s |  |
| 158 | `avm1_timer_method_form` | 6 | 2.6s |  |
| 159 | `avm1_timer_native_method_play` | 3 | 2.5s |  |
| 160 | `avm1_timer_overflow` | 10 | 3.3s |  |
| 161 | `avm1_timer_root_goto_stopped_gs` | 3 | 19.8s |  |
| 162 | `avm1_timer_root_goto_stopped_nf` | 3 | 1.6s |  |
| 163 | `avm1_type2_mc_receiver_dispatch` | 7 | 1.7s |  |
| 164 | `avm1_watch_long_name` | 9 | 1.6s |  |
| 165 | `avm1_watch_overflow` | 2 | 2.3s |  |
| 166 | `avm1_wrap_giveup_mixed_runs` | 2 | 1.7s |  |
| 167 | `avm1_xml_first_action_proto` | 2 | 1.6s |  |
| 168 | `avm1_xmlnode_first_action_proto` | 2 | 1.6s |  |
| 169 | `avm1_xscale_double_readback` | 8 | 19.9s |  |
| 170 | `avm2_activation_vtable_bounded` | 5 | 7.8s |  |
| 171 | `avm2_agi_shell` | 6 | 23.7s |  |
| 172 | `avm2_applyfilter_bevel_sample` | 441 | 17.0s |  |
| 173 | `avm2_applyfilter_glow_kernels` | 23 | 7.0s |  |
| 174 | `avm2_applyfilter_gradient_opaque` | 26 | 7.7s |  |
| 175 | `avm2_array_growth_bounded` | 5 | 7.4s |  |
| 176 | `avm2_bitmapdata_draw_edittext_box` | 5 | 7.3s |  |
| 177 | `avm2_bitmapdata_draw_filtered` | 13 | 7.6s |  |
| 178 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 7.4s |  |
| 179 | `avm2_bitmapdata_draw_textfield` | 5 | 7.2s |  |
| 180 | `avm2_child_simplebutton` | 10 | 23.6s |  |
| 181 | `avm2_contextmenu_stub` | 4 | 34.0s |  |
| 182 | `avm2_definetext_matrix` | 0 | 37.7s |  |
| 183 | `avm2_drawapi_stroke_snap` | 1 | 34.9s |  |
| 184 | `avm2_e4x_parse_bounded` | 18 | 11.8s |  |
| 185 | `avm2_edittext_placed_cxform` | 0 | 34.0s |  |
| 186 | `avm2_edittext_selection_cxform` | 2 | 34.7s |  |
| 187 | `avm2_embed_bytearray` | 2 | 33.9s |  |
| 188 | `avm2_external_interface_unavailable` | 8 | 10.3s |  |
| 189 | `avm2_findprop_this_resolution` | 13 | 10.4s |  |
| 190 | `avm2_gc_dynprop_tombstone_purge` | 8 | 10.3s |  |
| 191 | `avm2_gc_string_concat_reclaim` | 10 | 25.5s |  |
| 192 | `avm2_gc_string_survives_collect` | 9 | 7.3s |  |
| 193 | `avm2_goto_catchup_scale` | 4 | 7.2s |  |
| 194 | `avm2_graphics_runtime` | 7 | 28.1s |  |
| 195 | `avm2_group_alpha_cab` | 0 | 26.0s |  |
| 196 | `avm2_group_alpha_filter_cm` | 0 | 7.5s |  |
| 197 | `avm2_group_alpha_layer_aadd` | 0 | 7.5s |  |
| 198 | `avm2_group_alpha_layer_inner` | 0 | 7.4s |  |
| 199 | `avm2_group_alpha_multiply` | 0 | 1.1s |  |
| 200 | `avm2_group_alpha_shadow_shape_a50` | 0 | 28.7s |  |
| 201 | `avm2_json_roundtrip_bounded` | 13 | 26.6s |  |
| 202 | `avm2_layer_group_alpha` | 0 | 12.1s |  |
| 203 | `avm2_layer_group_alpha_transparency` | 0 | 7.5s |  |
| 204 | `avm2_layer_group_erase` | 0 | 1.5s |  |
| 205 | `avm2_layer_group_filtered_child` | 0 | 25.9s |  |
| 206 | `avm2_layer_group_overlap_alpha` | 0 | 7.4s |  |
| 207 | `avm2_loader_stub` | 5 | 7.2s |  |
| 208 | `avm2_localconnection_domain` | 4 | 7.2s |  |
| 209 | `avm2_morph` | 8 | 7.2s |  |
| 210 | `avm2_parent_child_render` | 11 | 9.2s |  |
| 211 | `avm2_parent_child_static_text` | 12 | 7.3s |  |
| 212 | `avm2_parent_child_symbol_stride` | 6 | 26.1s |  |
| 213 | `avm2_parent_child_symbolclass_domain` | 12 | 7.4s |  |
| 214 | `avm2_reflect_trait_hooks` | 30 | 7.4s |  |
| 215 | `avm2_sharedobject_flushstatus` | 4 | 7.1s |  |
| 216 | `avm2_simplebutton_click` | 2 | 6.5s |  |
| 217 | `avm2_slot_default_template` | 34 | 6.8s |  |
| 218 | `avm2_sound_bytes_and_group_format` | 27 | 26.4s |  |
| 219 | `avm2_static_and_store_slots` | 14 | 6.7s |  |
| 220 | `avm2_static_text` | 6 | 26.4s |  |
| 221 | `avm2_strbuf_stale_prefix` | 21 | 6.7s |  |
| 222 | `avm2_timeline_gradients` | 7 | 29.7s |  |
| 223 | `avm2_timeline_solid` | 6 | 6.7s |  |
| 224 | `avm2_timeline_stroke_gradient` | 9 | 6.9s |  |
| 225 | `avm2_timeline_text` | 4 | 8.6s |  |
| 226 | `avm2_tolerant_verify_quarantine` | 2 | 8.1s |  |
| 227 | `avm2_typed_value_ops` | 30 | 33.2s |  |
| 228 | `bitmap_pool_layer_cap` | 1 | 31.0s |  |
| 229 | `broadcast_cross_swf_version` | 4 | 25.6s |  |
| 230 | `broadcast_type1_args` | 14 | 25.2s |  |
| 231 | `coerce_cross_swf_version` | 7 | 2.5s |  |
| 232 | `coerce_recursion_guard` | 1 | 2.4s |  |
| 233 | `coerce_type1_args` | 9 | 2.4s |  |
| 234 | `convertfloat_type1_this` | 3 | 2.4s |  |
| 235 | `ctor_before_first_call_locals` | 5 | 2.4s |  |
| 236 | `ei_closure_scope_order` | 7 | 19.6s |  |
| 237 | `ei_cross_swf_version` | 2 | 1.7s |  |
| 238 | `ei_mc_this_receiver` | 5 | 1.8s |  |
| 239 | `ei_type1_args` | 7 | 1.7s |  |
| 240 | `enterframe_type1_args` | 8 | 19.6s |  |
| 241 | `fn_call_builtin_type1_args` | 10 | 1.6s |  |
| 242 | `fn_call_type1_args` | 7 | 1.6s |  |
| 243 | `fn_empty_method_type1_args` | 10 | 1.6s |  |
| 244 | `group_alpha_cab` | 0 | 1.7s |  |
| 245 | `group_alpha_filter_cm` | 0 | 28.7s |  |
| 246 | `group_alpha_layer_aadd` | 0 | 2.6s |  |
| 247 | `group_alpha_layer_inner` | 0 | 2.5s |  |
| 248 | `group_alpha_multiply` | 0 | 2.5s |  |
| 249 | `group_alpha_shadow_shape_a50` | 0 | 2.7s |  |
| 250 | `layer_group_alpha_transparency` | 0 | 1.3s |  |
| 251 | `layer_group_filtered_child` | 0 | 25.5s |  |
| 252 | `layer_group_in_add_alpha` | 0 | 8.3s |  |
| 253 | `layer_group_overlap_alpha` | 0 | 2.6s |  |
| 254 | `layer_group_overlap_erase` | 0 | 30.5s |  |
| 255 | `lc_method_type1_args` | 7 | 24.5s |  |
| 256 | `lc_onstatus_type1_args` | 3 | 2.3s |  |
| 257 | `lowq_fill_edges` | 0 | 24.6s |  |
| 258 | `lowq_gradient_orient_probe` | 0 | 24.8s |  |
| 259 | `lowq_sample_point_probe` | 0 | 24.8s |  |
| 260 | `lv_cross_swf_version` | 5 | 25.2s |  |
| 261 | `lv_ondata_type1_args` | 3 | 24.9s |  |
| 262 | `mask_nested_intersect` | 1 | 28.1s |  |
| 263 | `mask_sibling_union` | 1 | 29.2s |  |
| 264 | `mc_event_cross_swf_version` | 4 | 25.4s |  |
| 265 | `mc_event_type1_args` | 3 | 26.1s |  |
| 266 | `mc_method_v5_caller_gate` | 4 | 2.6s |  |
| 267 | `mc_resolve_type1_args` | 6 | 2.5s |  |
| 268 | `method_type1_args` | 10 | 2.5s |  |
| 269 | `nc_onstatus_closure` | 2 | 25.8s |  |
| 270 | `nc_onstatus_type1_args` | 3 | 2.5s |  |
| 271 | `onconstruct_cross_swf_version` | 4 | 2.5s |  |
| 272 | `onconstruct_type1_args` | 6 | 26.2s |  |
| 273 | `onload_type1_args` | 7 | 26.3s |  |
| 274 | `onunload_type1_args` | 6 | 2.5s |  |
| 275 | `onunload_type1_local_frame` | 2 | 2.5s |  |
| 276 | `resolve_type1_args` | 13 | 2.6s |  |
| 277 | `root_enterframe_cross_swf_version` | 3 | 26.4s |  |
| 278 | `sort_comparator_captured_scope` | 2 | 2.7s |  |
| 279 | `sort_comparator_type1_args` | 5 | 2.5s |  |
| 280 | `string_prim_method_type1_args` | 19 | 2.5s |  |
| 281 | `timer_cross_swf_version` | 3 | 15.9s |  |
| 282 | `timer_type1_args` | 14 | 16.0s |  |
| 283 | `watch_cross_swf_version` | 6 | 1.8s |  |
| 284 | `watch_mc_reentrant_setmember` | 3 | 15.5s |  |
| 285 | `watch_mc_type1_args` | 7 | 1.6s |  |
| 286 | `watch_setmember_type1_args` | 7 | 1.6s |  |
| 287 | `watch_timeline_named_params` | 4 | 1.6s |  |
| 288 | `watch_timeline_reentrant` | 3 | 1.6s |  |
| 289 | `xml_onload_type1_args` | 3 | 15.8s |  |

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
