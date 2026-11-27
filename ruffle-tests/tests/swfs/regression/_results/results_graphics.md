# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 01:02 UTC

**Git SHA**: `574824001e`

**Run Duration**: 50m 22s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 295 |
| Passing | **295** (100.0%) |
| Failing | 0 |
| Total expected lines | 3010 |
| Matching lines | 3010 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**295 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 1.6s |  |
| 2 | `array_method_type1_args` | 7 | 1.6s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 4.9s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.8s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.8s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.8s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.8s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.8s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.8s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.7s |  |
| 11 | `avm1_array_native_own_method` | 8 | 1.6s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 19.2s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.7s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 19.4s |  |
| 15 | `avm1_attached_clip_color` | 2 | 22.1s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 19.6s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.1s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 19.3s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 1.6s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 19.1s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 19.8s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 19.8s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 22.2s |  |
| 24 | `avm1_attached_clip_selfgoto_trace` | 14 | 20.0s |  |
| 25 | `avm1_attached_clip_tagorder` | 34 | 1.8s |  |
| 26 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.8s |  |
| 27 | `avm1_attached_clip_tagorder_po3` | 34 | 1.7s |  |
| 28 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.7s |  |
| 29 | `avm1_attached_clip_timeline_child_parent` | 6 | 19.8s |  |
| 30 | `avm1_bare_depth_methods_v7_gate` | 6 | 19.6s |  |
| 31 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 19.0s |  |
| 32 | `avm1_bare_mc_method_scope` | 19 | 19.4s |  |
| 33 | `avm1_bitmap_nearest_tie_stage` | 1 | 22.3s |  |
| 34 | `avm1_bitmapdata_draw_child_color` | 5 | 18.9s |  |
| 35 | `avm1_bitmapdata_draw_edittext` | 3 | 1.6s |  |
| 36 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 19.4s |  |
| 37 | `avm1_browser_eager_init` | 10 | 19.3s |  |
| 38 | `avm1_browser_gated_color` | 3 | 1.6s |  |
| 39 | `avm1_browser_gated_depth` | 7 | 1.6s |  |
| 40 | `avm1_browser_gated_textfield` | 7 | 1.6s |  |
| 41 | `avm1_browser_parked_frame` | 7 | 25.7s |  |
| 42 | `avm1_button_pick_order` | 9 | 26.4s |  |
| 43 | `avm1_button_textfield_path_binding` | 4 | 25.3s |  |
| 44 | `avm1_child_timeline_advance` | 23 | 2.7s |  |
| 45 | `avm1_child_timeline_frame1_stop` | 7 | 2.7s |  |
| 46 | `avm1_child_timeline_holder_stop` | 26 | 2.8s |  |
| 47 | `avm1_child_timeline_loop` | 32 | 2.9s |  |
| 48 | `avm1_clipevent_root_goto_stopped` | 3 | 25.2s |  |
| 49 | `avm1_clone_depth_overflow` | 3 | 3.2s |  |
| 50 | `avm1_clone_depth_removed_reuse` | 4 | 2.4s |  |
| 51 | `avm1_closure_base_clip_root_frame` | 5 | 2.3s |  |
| 52 | `avm1_closure_method_scope` | 7 | 2.3s |  |
| 53 | `avm1_create_text_field_depth` | 9 | 21.0s |  |
| 54 | `avm1_cxform_override_overflow` | 2 | 20.5s |  |
| 55 | `avm1_definetext_matrix` | 0 | 2.0s |  |
| 56 | `avm1_device_edittext_xscale` | 7 | 19.9s |  |
| 57 | `avm1_display_filter_growth_edge_scale` | 0 | 2.4s |  |
| 58 | `avm1_display_prop_coercion` | 36 | 2.2s |  |
| 59 | `avm1_drawapi_stroke_snap` | 1 | 20.7s |  |
| 60 | `avm1_drawing_stroke_scale` | 0 | 22.6s |  |
| 61 | `avm1_dynclip_color_transform` | 2 | 2.1s |  |
| 62 | `avm1_edittext_border_subpixel` | 1 | 19.7s |  |
| 63 | `avm1_edittext_cut_copy_selection` | 9 | 19.8s |  |
| 64 | `avm1_edittext_html_delete_runs` | 4 | 19.5s |  |
| 65 | `avm1_edittext_html_typed_runs` | 3 | 1.8s |  |
| 66 | `avm1_edittext_maxchars_clips_insertion` | 4 | 19.5s |  |
| 67 | `avm1_edittext_path_variable_same_frame` | 11 | 19.3s |  |
| 68 | `avm1_edittext_path_variable_scope` | 10 | 1.8s |  |
| 69 | `avm1_edittext_placed_cxform` | 0 | 19.6s |  |
| 70 | `avm1_edittext_placed_cxform_script` | 3 | 1.6s |  |
| 71 | `avm1_edittext_restrict_onchanged` | 6 | 19.1s |  |
| 72 | `avm1_edittext_rotated_borders` | 0 | 22.1s |  |
| 73 | `avm1_edittext_rotated_color` | 0 | 1.7s |  |
| 74 | `avm1_edittext_rotated_glyphs` | 0 | 1.7s |  |
| 75 | `avm1_edittext_rotated_paragraph` | 0 | 19.5s |  |
| 76 | `avm1_edittext_scaled_glyphs` | 0 | 1.6s |  |
| 77 | `avm1_edittext_tab_render` | 1 | 19.6s |  |
| 78 | `avm1_edittext_tabstops_metric` | 9 | 19.2s |  |
| 79 | `avm1_edittext_wordwrap_render` | 5 | 19.0s |  |
| 80 | `avm1_empty_clip_drawing_depth_order` | 1 | 1.7s |  |
| 81 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 20.4s |  |
| 82 | `avm1_enterframe_root_goto_opcode` | 7 | 20.3s |  |
| 83 | `avm1_exec_order_attached_selfremove` | 18 | 20.5s |  |
| 84 | `avm1_exec_order_dynamic_eligible` | 35 | 1.9s |  |
| 85 | `avm1_filter_list_overflow` | 2 | 2.0s |  |
| 86 | `avm1_func2_param_register_oob` | 4 | 1.6s |  |
| 87 | `avm1_gnash_flash_probes` | 63 | 20.4s |  |
| 88 | `avm1_gnash_flash_probes_v5` | 77 | 1.0s |  |
| 89 | `avm1_gnash_flash_probes_v6` | 63 | 1.0s |  |
| 90 | `avm1_goto_backward_enterframe_once` | 22 | 20.0s |  |
| 91 | `avm1_goto_skipped_init_call` | 6 | 25.0s |  |
| 92 | `avm1_goto_skipped_init_script` | 5 | 2.4s |  |
| 93 | `avm1_goto_skipped_init_timer` | 6 | 2.4s |  |
| 94 | `avm1_hairline_scaled_instances` | 1 | 28.5s |  |
| 95 | `avm1_hittest_hairline` | 28 | 25.4s |  |
| 96 | `avm1_hittest_shape_stale_matrix` | 28 | 25.2s |  |
| 97 | `avm1_holder_drawing_under_children` | 1 | 25.1s |  |
| 98 | `avm1_jpeg3_alpha_bitmap` | 0 | 25.1s |  |
| 99 | `avm1_key_isdown_protected` | 8 | 2.3s |  |
| 100 | `avm1_loaded_bare_goto` | 17 | 25.7s |  |
| 101 | `avm1_loaded_bare_goto_seq` | 4 | 20.1s |  |
| 102 | `avm1_loaded_goto_play_deferred` | 31 | 20.1s |  |
| 103 | `avm1_loaded_order_create_vs_load` | 33 | 2.2s |  |
| 104 | `avm1_loaded_shell_consumers_seq` | 12 | 19.9s |  |
| 105 | `avm1_loaded_shell_root_lookup` | 4 | 19.9s |  |
| 106 | `avm1_loaded_timeline_holder` | 7 | 1.8s |  |
| 107 | `avm1_loaded_unload_deferred` | 5 | 1.9s |  |
| 108 | `avm1_loadvars_ondata_overflow` | 23 | 1.9s |  |
| 109 | `avm1_long_text_layout` | 2 | 1.8s |  |
| 110 | `avm1_many_chars_registry` | 4 | 20.0s |  |
| 111 | `avm1_many_defs_registry` | 13 | 20.8s |  |
| 112 | `avm1_many_functions_registry` | 3 | 9.0s |  |
| 113 | `avm1_mc_button_unified_pick` | 21 | 19.4s |  |
| 114 | `avm1_mc_resolve` | 5 | 1.6s |  |
| 115 | `avm1_mcl_holder_totalframes` | 5 | 1.8s |  |
| 116 | `avm1_mcl_load_tick` | 15 | 1.7s |  |
| 117 | `avm1_morph_instances_ratio` | 2 | 21.8s |  |
| 118 | `avm1_nested_po3_filters` | 12 | 2.2s |  |
| 119 | `avm1_onunload_setvar_scope` | 5 | 1.7s |  |
| 120 | `avm1_parent_as3_child_payload` | 2 | 1.7s |  |
| 121 | `avm1_parent_child_bitmap` | 5 | 2.4s |  |
| 122 | `avm1_parent_child_bitmap_fill` | 3 | 5.5s |  |
| 123 | `avm1_parent_child_modify_place` | 5 | 2.4s |  |
| 124 | `avm1_parent_child_morph` | 8 | 2.6s |  |
| 125 | `avm1_parent_child_render` | 7 | 2.6s |  |
| 126 | `avm1_parent_child_sprite_meta` | 8 | 2.5s |  |
| 127 | `avm1_parent_child_text` | 8 | 2.5s |  |
| 128 | `avm1_pixelbounds_dynamic_child` | 1 | 22.1s |  |
| 129 | `avm1_place_occupied_depth_swf5` | 6 | 2.4s |  |
| 130 | `avm1_placed_drawing_color` | 1 | 22.0s |  |
| 131 | `avm1_po3_cm_alpha_bias_edge` | 0 | 6.2s |  |
| 132 | `avm1_po3_cm_folded_clear` | 1 | 2.6s |  |
| 133 | `avm1_po3_cm_live_under_cxform` | 0 | 2.6s |  |
| 134 | `avm1_po3_color_matrix_live` | 0 | 2.6s |  |
| 135 | `avm1_po3_color_matrix_live_clear` | 1 | 2.6s |  |
| 136 | `avm1_po3_color_matrix_live_nested` | 0 | 2.5s |  |
| 137 | `avm1_remove_same_name_other_parent` | 4 | 25.6s |  |
| 138 | `avm1_remove_unload_finalize_overflow` | 4 | 5.4s |  |
| 139 | `avm1_removed_clip_dprops_gc` | 14 | 2.7s |  |
| 140 | `avm1_resolve_dotted_getvariable` | 13 | 2.5s |  |
| 141 | `avm1_root_identity_and_playhead` | 3 | 26.2s |  |
| 142 | `avm1_root_onload_child_order` | 11 | 26.3s |  |
| 143 | `avm1_root_onload_proto` | 7 | 2.7s |  |
| 144 | `avm1_runtime_filters` | 3 | 29.8s |  |
| 145 | `avm1_runtime_filters_cm_bitmap` | 5 | 3.7s |  |
| 146 | `avm1_set_new_text_format_color` | 4 | 25.4s |  |
| 147 | `avm1_set_new_text_format_instance` | 5 | 25.2s |  |
| 148 | `avm1_set_new_text_format_paragraph` | 12 | 2.7s |  |
| 149 | `avm1_set_new_text_format_render` | 5 | 25.5s |  |
| 150 | `avm1_set_new_text_format_size` | 5 | 2.4s |  |
| 151 | `avm1_sprite_goto_script_overflow` | 65 | 2.1s |  |
| 152 | `avm1_stroke_join_cap_snap` | 0 | 24.4s |  |
| 153 | `avm1_stroke_noscale_signed` | 0 | 20.4s |  |
| 154 | `avm1_stroke_pixel_snap` | 1 | 19.6s |  |
| 155 | `avm1_stroke_pixel_snap_matrix` | 0 | 19.7s |  |
| 156 | `avm1_stroke_style_id_order` | 1 | 19.4s |  |
| 157 | `avm1_swf6_case_insensitive_builtins` | 42 | 2.1s |  |
| 158 | `avm1_swf7_case_sensitive_builtins` | 40 | 0.9s |  |
| 159 | `avm1_textfield_attached_depth_order` | 1 | 19.7s |  |
| 160 | `avm1_textfield_x_bounds_offset` | 10 | 19.4s |  |
| 161 | `avm1_timer_clock_model` | 19 | 25.8s |  |
| 162 | `avm1_timer_function_form_activation` | 3 | 25.4s |  |
| 163 | `avm1_timer_method_form` | 6 | 2.6s |  |
| 164 | `avm1_timer_native_method_play` | 3 | 2.5s |  |
| 165 | `avm1_timer_overflow` | 10 | 3.3s |  |
| 166 | `avm1_timer_root_goto_stopped_gs` | 3 | 2.6s |  |
| 167 | `avm1_timer_root_goto_stopped_nf` | 3 | 2.4s |  |
| 168 | `avm1_type2_mc_receiver_dispatch` | 7 | 25.5s |  |
| 169 | `avm1_watch_long_name` | 9 | 2.5s |  |
| 170 | `avm1_watch_overflow` | 2 | 3.2s |  |
| 171 | `avm1_wrap_giveup_mixed_runs` | 2 | 27.2s |  |
| 172 | `avm1_xml_first_action_proto` | 2 | 2.6s |  |
| 173 | `avm1_xmlnode_first_action_proto` | 2 | 2.5s |  |
| 174 | `avm1_xscale_double_readback` | 8 | 2.8s |  |
| 175 | `avm2_activation_vtable_bounded` | 5 | 13.5s |  |
| 176 | `avm2_agi_shell` | 6 | 10.5s |  |
| 177 | `avm2_applyfilter_bevel_sample` | 441 | 25.1s |  |
| 178 | `avm2_applyfilter_glow_kernels` | 23 | 10.6s |  |
| 179 | `avm2_applyfilter_gradient_opaque` | 26 | 11.6s |  |
| 180 | `avm2_array_growth_bounded` | 5 | 11.3s |  |
| 181 | `avm2_bitmapdata_draw_edittext_box` | 5 | 9.7s |  |
| 182 | `avm2_bitmapdata_draw_filtered` | 13 | 8.2s |  |
| 183 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 8.5s |  |
| 184 | `avm2_bitmapdata_draw_textfield` | 5 | 8.2s |  |
| 185 | `avm2_bitmapdata_palettemap_index` | 5 | 27.4s |  |
| 186 | `avm2_child_simplebutton` | 10 | 27.6s |  |
| 187 | `avm2_contextmenu_stub` | 4 | 7.9s |  |
| 188 | `avm2_definetext_matrix` | 0 | 10.8s |  |
| 189 | `avm2_drawapi_stroke_snap` | 1 | 27.3s |  |
| 190 | `avm2_e4x_parse_bounded` | 18 | 9.2s |  |
| 191 | `avm2_edittext_placed_cxform` | 0 | 37.5s |  |
| 192 | `avm2_edittext_selection_cxform` | 2 | 31.8s |  |
| 193 | `avm2_embed_bytearray` | 2 | 9.1s |  |
| 194 | `avm2_external_interface_unavailable` | 8 | 9.1s |  |
| 195 | `avm2_findprop_this_resolution` | 13 | 9.2s |  |
| 196 | `avm2_gc_dynprop_tombstone_purge` | 8 | 9.3s |  |
| 197 | `avm2_gc_string_concat_reclaim` | 10 | 9.2s |  |
| 198 | `avm2_gc_string_survives_collect` | 9 | 9.2s |  |
| 199 | `avm2_goto_catchup_scale` | 4 | 9.2s |  |
| 200 | `avm2_graphics_runtime` | 7 | 9.1s |  |
| 201 | `avm2_group_alpha_cab` | 0 | 29.5s |  |
| 202 | `avm2_group_alpha_filter_cm` | 0 | 7.2s |  |
| 203 | `avm2_group_alpha_layer_aadd` | 0 | 7.2s |  |
| 204 | `avm2_group_alpha_layer_inner` | 0 | 7.1s |  |
| 205 | `avm2_group_alpha_multiply` | 0 | 1.1s |  |
| 206 | `avm2_group_alpha_shadow_shape_a50` | 0 | 7.2s |  |
| 207 | `avm2_json_roundtrip_bounded` | 13 | 7.9s |  |
| 208 | `avm2_layer_group_alpha` | 0 | 11.7s |  |
| 209 | `avm2_layer_group_alpha_transparency` | 0 | 1.0s |  |
| 210 | `avm2_layer_group_erase` | 0 | 1.4s |  |
| 211 | `avm2_layer_group_filtered_child` | 0 | 34.4s |  |
| 212 | `avm2_layer_group_overlap_alpha` | 0 | 33.7s |  |
| 213 | `avm2_loader_stub` | 5 | 8.8s |  |
| 214 | `avm2_localconnection_domain` | 4 | 9.2s |  |
| 215 | `avm2_morph` | 8 | 28.3s |  |
| 216 | `avm2_parent_child_render` | 11 | 10.8s |  |
| 217 | `avm2_parent_child_static_text` | 12 | 9.0s |  |
| 218 | `avm2_parent_child_symbol_stride` | 6 | 9.9s |  |
| 219 | `avm2_parent_child_symbolclass_domain` | 12 | 9.2s |  |
| 220 | `avm2_reflect_trait_hooks` | 30 | 8.8s |  |
| 221 | `avm2_sharedobject_flushstatus` | 4 | 11.9s |  |
| 222 | `avm2_simplebutton_click` | 2 | 9.8s |  |
| 223 | `avm2_slot_default_template` | 34 | 10.1s |  |
| 224 | `avm2_sound_bytes_and_group_format` | 27 | 10.2s |  |
| 225 | `avm2_static_and_store_slots` | 14 | 10.0s |  |
| 226 | `avm2_static_text` | 6 | 9.9s |  |
| 227 | `avm2_strbuf_stale_prefix` | 21 | 9.9s |  |
| 228 | `avm2_timeline_gradients` | 7 | 37.6s |  |
| 229 | `avm2_timeline_solid` | 6 | 11.1s |  |
| 230 | `avm2_timeline_stroke_gradient` | 9 | 11.3s |  |
| 231 | `avm2_timeline_text` | 4 | 7.7s |  |
| 232 | `avm2_tolerant_verify_quarantine` | 2 | 7.3s |  |
| 233 | `avm2_typed_value_ops` | 30 | 7.3s |  |
| 234 | `bitmap_pool_layer_cap` | 1 | 24.3s |  |
| 235 | `broadcast_cross_swf_version` | 4 | 1.5s |  |
| 236 | `broadcast_type1_args` | 14 | 1.6s |  |
| 237 | `coerce_cross_swf_version` | 7 | 1.7s |  |
| 238 | `coerce_recursion_guard` | 1 | 1.6s |  |
| 239 | `coerce_type1_args` | 9 | 1.6s |  |
| 240 | `convertfloat_type1_this` | 3 | 1.5s |  |
| 241 | `ctor_before_first_call_locals` | 5 | 1.0s |  |
| 242 | `ei_closure_scope_order` | 7 | 1.7s |  |
| 243 | `ei_cross_swf_version` | 2 | 1.6s |  |
| 244 | `ei_mc_this_receiver` | 5 | 19.7s |  |
| 245 | `ei_type1_args` | 7 | 1.6s |  |
| 246 | `enterframe_type1_args` | 8 | 19.5s |  |
| 247 | `fn_call_builtin_type1_args` | 10 | 1.6s |  |
| 248 | `fn_call_type1_args` | 7 | 1.6s |  |
| 249 | `fn_empty_method_type1_args` | 10 | 1.6s |  |
| 250 | `group_alpha_cab` | 0 | 4.3s |  |
| 251 | `group_alpha_filter_cm` | 0 | 6.0s |  |
| 252 | `group_alpha_layer_aadd` | 0 | 2.5s |  |
| 253 | `group_alpha_layer_inner` | 0 | 2.5s |  |
| 254 | `group_alpha_multiply` | 0 | 2.5s |  |
| 255 | `group_alpha_shadow_shape_a50` | 0 | 2.7s |  |
| 256 | `layer_group_alpha_transparency` | 0 | 1.2s |  |
| 257 | `layer_group_filtered_child` | 0 | 25.0s |  |
| 258 | `layer_group_in_add_alpha` | 0 | 3.4s |  |
| 259 | `layer_group_overlap_alpha` | 0 | 2.6s |  |
| 260 | `layer_group_overlap_erase` | 0 | 6.6s |  |
| 261 | `lc_method_type1_args` | 7 | 2.0s |  |
| 262 | `lc_onstatus_type1_args` | 3 | 2.0s |  |
| 263 | `lowq_fill_edges` | 0 | 20.6s |  |
| 264 | `lowq_gradient_orient_probe` | 0 | 21.4s |  |
| 265 | `lowq_sample_point_probe` | 0 | 22.3s |  |
| 266 | `lv_cross_swf_version` | 5 | 2.4s |  |
| 267 | `lv_ondata_type1_args` | 3 | 2.2s |  |
| 268 | `mask_nested_intersect` | 1 | 5.2s |  |
| 269 | `mask_sibling_union` | 1 | 4.9s |  |
| 270 | `mc_event_cross_swf_version` | 4 | 1.2s |  |
| 271 | `mc_event_type1_args` | 3 | 1.2s |  |
| 272 | `mc_method_v5_caller_gate` | 4 | 1.2s |  |
| 273 | `mc_resolve_type1_args` | 6 | 1.1s |  |
| 274 | `method_type1_args` | 10 | 1.1s |  |
| 275 | `nc_onstatus_closure` | 2 | 1.1s |  |
| 276 | `nc_onstatus_type1_args` | 3 | 1.1s |  |
| 277 | `onconstruct_cross_swf_version` | 4 | 1.2s |  |
| 278 | `onconstruct_type1_args` | 6 | 2.0s |  |
| 279 | `onload_type1_args` | 7 | 2.0s |  |
| 280 | `onunload_type1_args` | 6 | 2.1s |  |
| 281 | `onunload_type1_local_frame` | 2 | 2.0s |  |
| 282 | `resolve_type1_args` | 13 | 2.0s |  |
| 283 | `root_enterframe_cross_swf_version` | 3 | 20.3s |  |
| 284 | `sort_comparator_captured_scope` | 2 | 2.1s |  |
| 285 | `sort_comparator_type1_args` | 5 | 2.0s |  |
| 286 | `string_prim_method_type1_args` | 19 | 2.0s |  |
| 287 | `timer_cross_swf_version` | 3 | 1.6s |  |
| 288 | `timer_type1_args` | 14 | 19.2s |  |
| 289 | `watch_cross_swf_version` | 6 | 1.7s |  |
| 290 | `watch_mc_reentrant_setmember` | 3 | 1.5s |  |
| 291 | `watch_mc_type1_args` | 7 | 1.6s |  |
| 292 | `watch_setmember_type1_args` | 7 | 1.6s |  |
| 293 | `watch_timeline_named_params` | 4 | 1.5s |  |
| 294 | `watch_timeline_reentrant` | 3 | 1.6s |  |
| 295 | `xml_onload_type1_args` | 3 | 1.6s |  |

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
