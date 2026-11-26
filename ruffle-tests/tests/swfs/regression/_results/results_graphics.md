# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-26 00:30 UTC

**Git SHA**: `b030ed745d`

**Run Duration**: 57m 50s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 282 |
| Passing | **282** (100.0%) |
| Failing | 0 |
| Total expected lines | 2979 |
| Matching lines | 2979 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**282 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 20.2s |  |
| 2 | `array_method_type1_args` | 7 | 1.7s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 23.4s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.9s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.9s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.9s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.9s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.9s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.9s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.8s |  |
| 11 | `avm1_array_native_own_method` | 8 | 19.7s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 19.9s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.9s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 20.1s |  |
| 15 | `avm1_attached_clip_color` | 2 | 22.3s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 19.9s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.2s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 19.8s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 1.7s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 19.7s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 20.4s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 20.2s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 22.6s |  |
| 24 | `avm1_attached_clip_tagorder` | 34 | 1.8s |  |
| 25 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.9s |  |
| 26 | `avm1_attached_clip_tagorder_po3` | 34 | 1.8s |  |
| 27 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.8s |  |
| 28 | `avm1_attached_clip_timeline_child_parent` | 6 | 20.0s |  |
| 29 | `avm1_bare_depth_methods_v7_gate` | 6 | 19.9s |  |
| 30 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 1.0s |  |
| 31 | `avm1_bare_mc_method_scope` | 19 | 20.3s |  |
| 32 | `avm1_bitmap_nearest_tie_stage` | 1 | 22.9s |  |
| 33 | `avm1_bitmapdata_draw_child_color` | 5 | 20.4s |  |
| 34 | `avm1_bitmapdata_draw_edittext` | 3 | 2.1s |  |
| 35 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 22.1s |  |
| 36 | `avm1_browser_eager_init` | 10 | 21.7s |  |
| 37 | `avm1_browser_gated_color` | 3 | 21.2s |  |
| 38 | `avm1_browser_gated_depth` | 7 | 2.0s |  |
| 39 | `avm1_browser_gated_textfield` | 7 | 2.0s |  |
| 40 | `avm1_browser_parked_frame` | 7 | 20.5s |  |
| 41 | `avm1_button_pick_order` | 9 | 21.1s |  |
| 42 | `avm1_button_textfield_path_binding` | 4 | 20.2s |  |
| 43 | `avm1_child_timeline_advance` | 23 | 20.4s |  |
| 44 | `avm1_child_timeline_frame1_stop` | 7 | 1.9s |  |
| 45 | `avm1_child_timeline_holder_stop` | 26 | 1.9s |  |
| 46 | `avm1_child_timeline_loop` | 32 | 1.9s |  |
| 47 | `avm1_clone_depth_overflow` | 3 | 2.3s |  |
| 48 | `avm1_clone_depth_removed_reuse` | 4 | 1.7s |  |
| 49 | `avm1_closure_base_clip_root_frame` | 5 | 1.9s |  |
| 50 | `avm1_closure_method_scope` | 7 | 1.8s |  |
| 51 | `avm1_create_text_field_depth` | 9 | 19.1s |  |
| 52 | `avm1_cxform_override_overflow` | 2 | 19.2s |  |
| 53 | `avm1_definetext_matrix` | 0 | 1.6s |  |
| 54 | `avm1_device_edittext_xscale` | 7 | 19.2s |  |
| 55 | `avm1_display_filter_growth_edge_scale` | 0 | 2.0s |  |
| 56 | `avm1_display_prop_coercion` | 36 | 1.8s |  |
| 57 | `avm1_dynclip_color_transform` | 2 | 2.0s |  |
| 58 | `avm1_edittext_border_subpixel` | 1 | 19.1s |  |
| 59 | `avm1_edittext_cut_copy_selection` | 9 | 19.2s |  |
| 60 | `avm1_edittext_html_delete_runs` | 4 | 19.0s |  |
| 61 | `avm1_edittext_html_typed_runs` | 3 | 25.4s |  |
| 62 | `avm1_edittext_maxchars_clips_insertion` | 4 | 25.1s |  |
| 63 | `avm1_edittext_path_variable_same_frame` | 11 | 25.3s |  |
| 64 | `avm1_edittext_path_variable_scope` | 10 | 2.7s |  |
| 65 | `avm1_edittext_placed_cxform` | 0 | 25.5s |  |
| 66 | `avm1_edittext_placed_cxform_script` | 3 | 2.5s |  |
| 67 | `avm1_edittext_restrict_onchanged` | 6 | 2.5s |  |
| 68 | `avm1_edittext_rotated_borders` | 0 | 26.0s |  |
| 69 | `avm1_edittext_rotated_glyphs` | 0 | 25.9s |  |
| 70 | `avm1_edittext_scaled_glyphs` | 0 | 2.6s |  |
| 71 | `avm1_edittext_tab_render` | 1 | 20.7s |  |
| 72 | `avm1_edittext_tabstops_metric` | 9 | 18.6s |  |
| 73 | `avm1_edittext_wordwrap_render` | 5 | 18.4s |  |
| 74 | `avm1_empty_clip_drawing_depth_order` | 1 | 18.7s |  |
| 75 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 18.8s |  |
| 76 | `avm1_exec_order_attached_selfremove` | 18 | 19.6s |  |
| 77 | `avm1_exec_order_dynamic_eligible` | 35 | 19.2s |  |
| 78 | `avm1_filter_list_overflow` | 2 | 19.3s |  |
| 79 | `avm1_func2_param_register_oob` | 4 | 2.0s |  |
| 80 | `avm1_gnash_flash_probes` | 63 | 2.3s |  |
| 81 | `avm1_gnash_flash_probes_v5` | 77 | 20.5s |  |
| 82 | `avm1_gnash_flash_probes_v6` | 63 | 1.0s |  |
| 83 | `avm1_goto_backward_enterframe_once` | 22 | 19.8s |  |
| 84 | `avm1_goto_skipped_init_call` | 6 | 20.2s |  |
| 85 | `avm1_goto_skipped_init_script` | 5 | 1.8s |  |
| 86 | `avm1_goto_skipped_init_timer` | 6 | 1.9s |  |
| 87 | `avm1_hairline_scaled_instances` | 1 | 19.9s |  |
| 88 | `avm1_hittest_hairline` | 28 | 19.4s |  |
| 89 | `avm1_hittest_shape_stale_matrix` | 28 | 19.6s |  |
| 90 | `avm1_holder_drawing_under_children` | 1 | 1.7s |  |
| 91 | `avm1_jpeg3_alpha_bitmap` | 0 | 22.3s |  |
| 92 | `avm1_key_isdown_protected` | 8 | 19.8s |  |
| 93 | `avm1_loaded_bare_goto` | 17 | 20.6s |  |
| 94 | `avm1_loaded_bare_goto_seq` | 4 | 2.1s |  |
| 95 | `avm1_loaded_goto_play_deferred` | 31 | 20.4s |  |
| 96 | `avm1_loaded_order_create_vs_load` | 33 | 2.2s |  |
| 97 | `avm1_loaded_shell_consumers_seq` | 12 | 20.0s |  |
| 98 | `avm1_loaded_shell_root_lookup` | 4 | 20.0s |  |
| 99 | `avm1_loaded_timeline_holder` | 7 | 1.8s |  |
| 100 | `avm1_loaded_unload_deferred` | 5 | 1.9s |  |
| 101 | `avm1_loadvars_ondata_overflow` | 23 | 16.6s |  |
| 102 | `avm1_long_text_layout` | 2 | 16.4s |  |
| 103 | `avm1_many_chars_registry` | 4 | 16.6s |  |
| 104 | `avm1_many_defs_registry` | 13 | 17.6s |  |
| 105 | `avm1_many_functions_registry` | 3 | 7.8s |  |
| 106 | `avm1_mc_button_unified_pick` | 21 | 16.6s |  |
| 107 | `avm1_mc_resolve` | 5 | 1.7s |  |
| 108 | `avm1_mcl_holder_totalframes` | 5 | 1.9s |  |
| 109 | `avm1_mcl_load_tick` | 15 | 1.8s |  |
| 110 | `avm1_morph_instances_ratio` | 2 | 16.4s |  |
| 111 | `avm1_nested_po3_filters` | 12 | 22.1s |  |
| 112 | `avm1_onunload_setvar_scope` | 5 | 19.1s |  |
| 113 | `avm1_parent_as3_child_payload` | 2 | 1.7s |  |
| 114 | `avm1_parent_child_bitmap` | 5 | 1.8s |  |
| 115 | `avm1_parent_child_bitmap_fill` | 3 | 19.2s |  |
| 116 | `avm1_parent_child_modify_place` | 5 | 1.7s |  |
| 117 | `avm1_parent_child_morph` | 8 | 1.8s |  |
| 118 | `avm1_parent_child_render` | 7 | 1.8s |  |
| 119 | `avm1_parent_child_sprite_meta` | 8 | 1.9s |  |
| 120 | `avm1_parent_child_text` | 8 | 1.8s |  |
| 121 | `avm1_pixelbounds_dynamic_child` | 1 | 19.4s |  |
| 122 | `avm1_place_occupied_depth_swf5` | 6 | 4.2s |  |
| 123 | `avm1_placed_drawing_color` | 1 | 20.0s |  |
| 124 | `avm1_po3_cm_alpha_bias_edge` | 0 | 19.6s |  |
| 125 | `avm1_po3_cm_folded_clear` | 1 | 1.7s |  |
| 126 | `avm1_po3_cm_live_under_cxform` | 0 | 1.7s |  |
| 127 | `avm1_po3_color_matrix_live` | 0 | 1.7s |  |
| 128 | `avm1_po3_color_matrix_live_clear` | 1 | 1.7s |  |
| 129 | `avm1_po3_color_matrix_live_nested` | 0 | 1.7s |  |
| 130 | `avm1_remove_same_name_other_parent` | 4 | 20.4s |  |
| 131 | `avm1_remove_unload_finalize_overflow` | 4 | 22.4s |  |
| 132 | `avm1_removed_clip_dprops_gc` | 14 | 20.1s |  |
| 133 | `avm1_resolve_dotted_getvariable` | 13 | 1.7s |  |
| 134 | `avm1_root_identity_and_playhead` | 3 | 20.2s |  |
| 135 | `avm1_root_onload_child_order` | 11 | 20.7s |  |
| 136 | `avm1_root_onload_proto` | 7 | 1.9s |  |
| 137 | `avm1_runtime_filters` | 3 | 23.3s |  |
| 138 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.1s |  |
| 139 | `avm1_set_new_text_format_color` | 4 | 19.9s |  |
| 140 | `avm1_set_new_text_format_instance` | 5 | 1.7s |  |
| 141 | `avm1_set_new_text_format_paragraph` | 12 | 1.9s |  |
| 142 | `avm1_set_new_text_format_render` | 5 | 20.1s |  |
| 143 | `avm1_set_new_text_format_size` | 5 | 1.7s |  |
| 144 | `avm1_sprite_goto_script_overflow` | 65 | 19.9s |  |
| 145 | `avm1_stroke_pixel_snap` | 1 | 19.6s |  |
| 146 | `avm1_stroke_pixel_snap_matrix` | 0 | 20.0s |  |
| 147 | `avm1_stroke_style_id_order` | 1 | 19.9s |  |
| 148 | `avm1_swf6_case_insensitive_builtins` | 42 | 16.1s |  |
| 149 | `avm1_swf7_case_sensitive_builtins` | 40 | 0.9s |  |
| 150 | `avm1_textfield_attached_depth_order` | 1 | 18.1s |  |
| 151 | `avm1_textfield_x_bounds_offset` | 10 | 16.5s |  |
| 152 | `avm1_timer_clock_model` | 19 | 16.9s |  |
| 153 | `avm1_timer_function_form_activation` | 3 | 16.3s |  |
| 154 | `avm1_timer_method_form` | 6 | 1.8s |  |
| 155 | `avm1_timer_native_method_play` | 3 | 1.7s |  |
| 156 | `avm1_timer_overflow` | 10 | 2.2s |  |
| 157 | `avm1_timer_root_goto_stopped_gs` | 3 | 19.3s |  |
| 158 | `avm1_timer_root_goto_stopped_nf` | 3 | 1.6s |  |
| 159 | `avm1_type2_mc_receiver_dispatch` | 7 | 19.4s |  |
| 160 | `avm1_watch_long_name` | 9 | 1.6s |  |
| 161 | `avm1_watch_overflow` | 2 | 2.2s |  |
| 162 | `avm1_wrap_giveup_mixed_runs` | 2 | 1.6s |  |
| 163 | `avm1_xml_first_action_proto` | 2 | 1.6s |  |
| 164 | `avm1_xmlnode_first_action_proto` | 2 | 1.5s |  |
| 165 | `avm1_xscale_double_readback` | 8 | 19.3s |  |
| 166 | `avm2_activation_vtable_bounded` | 5 | 32.2s |  |
| 167 | `avm2_agi_shell` | 6 | 3.2s |  |
| 168 | `avm2_applyfilter_bevel_sample` | 441 | 21.1s |  |
| 169 | `avm2_applyfilter_glow_kernels` | 23 | 9.3s |  |
| 170 | `avm2_applyfilter_gradient_opaque` | 26 | 10.2s |  |
| 171 | `avm2_array_growth_bounded` | 5 | 9.9s |  |
| 172 | `avm2_bitmapdata_draw_edittext_box` | 5 | 9.1s |  |
| 173 | `avm2_bitmapdata_draw_filtered` | 13 | 9.3s |  |
| 174 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 9.9s |  |
| 175 | `avm2_bitmapdata_draw_textfield` | 5 | 34.4s |  |
| 176 | `avm2_child_simplebutton` | 10 | 34.3s |  |
| 177 | `avm2_contextmenu_stub` | 4 | 9.9s |  |
| 178 | `avm2_definetext_matrix` | 0 | 13.4s |  |
| 179 | `avm2_e4x_parse_bounded` | 18 | 11.1s |  |
| 180 | `avm2_edittext_placed_cxform` | 0 | 32.5s |  |
| 181 | `avm2_edittext_selection_cxform` | 2 | 33.4s |  |
| 182 | `avm2_embed_bytearray` | 2 | 32.5s |  |
| 183 | `avm2_external_interface_unavailable` | 8 | 10.0s |  |
| 184 | `avm2_findprop_this_resolution` | 13 | 30.7s |  |
| 185 | `avm2_gc_dynprop_tombstone_purge` | 8 | 11.1s |  |
| 186 | `avm2_gc_string_concat_reclaim` | 10 | 11.4s |  |
| 187 | `avm2_gc_string_survives_collect` | 9 | 11.3s |  |
| 188 | `avm2_goto_catchup_scale` | 4 | 11.3s |  |
| 189 | `avm2_graphics_runtime` | 7 | 42.7s |  |
| 190 | `avm2_group_alpha_cab` | 0 | 39.1s |  |
| 191 | `avm2_group_alpha_filter_cm` | 0 | 11.4s |  |
| 192 | `avm2_group_alpha_layer_aadd` | 0 | 11.1s |  |
| 193 | `avm2_group_alpha_layer_inner` | 0 | 27.7s |  |
| 194 | `avm2_group_alpha_multiply` | 0 | 7.2s |  |
| 195 | `avm2_group_alpha_shadow_shape_a50` | 0 | 7.2s |  |
| 196 | `avm2_json_roundtrip_bounded` | 13 | 25.8s |  |
| 197 | `avm2_layer_group_alpha` | 0 | 11.4s |  |
| 198 | `avm2_layer_group_alpha_transparency` | 0 | 1.1s |  |
| 199 | `avm2_layer_group_erase` | 0 | 1.4s |  |
| 200 | `avm2_layer_group_filtered_child` | 0 | 25.1s |  |
| 201 | `avm2_layer_group_overlap_alpha` | 0 | 7.1s |  |
| 202 | `avm2_loader_stub` | 5 | 34.8s |  |
| 203 | `avm2_localconnection_domain` | 4 | 10.2s |  |
| 204 | `avm2_morph` | 8 | 38.4s |  |
| 205 | `avm2_parent_child_render` | 11 | 13.6s |  |
| 206 | `avm2_parent_child_static_text` | 12 | 10.8s |  |
| 207 | `avm2_parent_child_symbol_stride` | 6 | 36.4s |  |
| 208 | `avm2_parent_child_symbolclass_domain` | 12 | 10.6s |  |
| 209 | `avm2_reflect_trait_hooks` | 30 | 10.6s |  |
| 210 | `avm2_sharedobject_flushstatus` | 4 | 10.1s |  |
| 211 | `avm2_simplebutton_click` | 2 | 25.0s |  |
| 212 | `avm2_slot_default_template` | 34 | 7.2s |  |
| 213 | `avm2_sound_bytes_and_group_format` | 27 | 7.4s |  |
| 214 | `avm2_static_and_store_slots` | 14 | 7.1s |  |
| 215 | `avm2_static_text` | 6 | 24.9s |  |
| 216 | `avm2_strbuf_stale_prefix` | 21 | 7.1s |  |
| 217 | `avm2_timeline_gradients` | 7 | 28.6s |  |
| 218 | `avm2_timeline_solid` | 6 | 8.0s |  |
| 219 | `avm2_timeline_stroke_gradient` | 9 | 8.2s |  |
| 220 | `avm2_timeline_text` | 4 | 23.6s |  |
| 221 | `avm2_tolerant_verify_quarantine` | 2 | 6.9s |  |
| 222 | `avm2_typed_value_ops` | 30 | 7.0s |  |
| 223 | `bitmap_pool_layer_cap` | 1 | 21.3s |  |
| 224 | `broadcast_cross_swf_version` | 4 | 19.1s |  |
| 225 | `broadcast_type1_args` | 14 | 18.0s |  |
| 226 | `coerce_cross_swf_version` | 7 | 1.9s |  |
| 227 | `coerce_recursion_guard` | 1 | 1.8s |  |
| 228 | `coerce_type1_args` | 9 | 1.8s |  |
| 229 | `convertfloat_type1_this` | 3 | 25.0s |  |
| 230 | `ctor_before_first_call_locals` | 5 | 2.5s |  |
| 231 | `ei_closure_scope_order` | 7 | 2.5s |  |
| 232 | `ei_cross_swf_version` | 2 | 2.4s |  |
| 233 | `ei_mc_this_receiver` | 5 | 25.1s |  |
| 234 | `ei_type1_args` | 7 | 2.5s |  |
| 235 | `enterframe_type1_args` | 8 | 25.4s |  |
| 236 | `fn_call_builtin_type1_args` | 10 | 2.4s |  |
| 237 | `fn_call_type1_args` | 7 | 2.4s |  |
| 238 | `fn_empty_method_type1_args` | 10 | 19.0s |  |
| 239 | `group_alpha_cab` | 0 | 21.7s |  |
| 240 | `group_alpha_filter_cm` | 0 | 1.7s |  |
| 241 | `group_alpha_layer_aadd` | 0 | 1.6s |  |
| 242 | `group_alpha_layer_inner` | 0 | 1.6s |  |
| 243 | `group_alpha_multiply` | 0 | 0.9s |  |
| 244 | `group_alpha_shadow_shape_a50` | 0 | 1.8s |  |
| 245 | `layer_group_alpha_transparency` | 0 | 0.9s |  |
| 246 | `layer_group_filtered_child` | 0 | 19.2s |  |
| 247 | `layer_group_in_add_alpha` | 0 | 23.2s |  |
| 248 | `layer_group_overlap_alpha` | 0 | 1.6s |  |
| 249 | `layer_group_overlap_erase` | 0 | 0.9s |  |
| 250 | `lc_method_type1_args` | 7 | 19.1s |  |
| 251 | `lc_onstatus_type1_args` | 3 | 1.5s |  |
| 252 | `lowq_fill_edges` | 0 | 18.9s |  |
| 253 | `lv_cross_swf_version` | 5 | 19.1s |  |
| 254 | `lv_ondata_type1_args` | 3 | 19.0s |  |
| 255 | `mask_nested_intersect` | 1 | 21.8s |  |
| 256 | `mask_sibling_union` | 1 | 22.6s |  |
| 257 | `mc_event_cross_swf_version` | 4 | 19.5s |  |
| 258 | `mc_event_type1_args` | 3 | 19.2s |  |
| 259 | `mc_method_v5_caller_gate` | 4 | 1.5s |  |
| 260 | `mc_resolve_type1_args` | 6 | 1.3s |  |
| 261 | `method_type1_args` | 10 | 1.3s |  |
| 262 | `nc_onstatus_closure` | 2 | 19.3s |  |
| 263 | `nc_onstatus_type1_args` | 3 | 1.3s |  |
| 264 | `onconstruct_cross_swf_version` | 4 | 1.4s |  |
| 265 | `onconstruct_type1_args` | 6 | 17.7s |  |
| 266 | `onload_type1_args` | 7 | 17.5s |  |
| 267 | `onunload_type1_args` | 6 | 1.7s |  |
| 268 | `onunload_type1_local_frame` | 2 | 1.7s |  |
| 269 | `resolve_type1_args` | 13 | 1.7s |  |
| 270 | `root_enterframe_cross_swf_version` | 3 | 18.0s |  |
| 271 | `sort_comparator_captured_scope` | 2 | 1.9s |  |
| 272 | `sort_comparator_type1_args` | 5 | 1.8s |  |
| 273 | `string_prim_method_type1_args` | 19 | 1.7s |  |
| 274 | `timer_cross_swf_version` | 3 | 19.5s |  |
| 275 | `timer_type1_args` | 14 | 19.4s |  |
| 276 | `watch_cross_swf_version` | 6 | 1.7s |  |
| 277 | `watch_mc_reentrant_setmember` | 3 | 19.6s |  |
| 278 | `watch_mc_type1_args` | 7 | 1.6s |  |
| 279 | `watch_setmember_type1_args` | 7 | 1.6s |  |
| 280 | `watch_timeline_named_params` | 4 | 1.6s |  |
| 281 | `watch_timeline_reentrant` | 3 | 1.6s |  |
| 282 | `xml_onload_type1_args` | 3 | 19.6s |  |

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
