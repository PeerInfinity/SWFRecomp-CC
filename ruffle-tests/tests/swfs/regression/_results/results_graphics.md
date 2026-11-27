# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 21:14 UTC

**Git SHA**: `a18a0e0334`

**Run Duration**: 76m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 338 |
| Passing | **338** (100.0%) |
| Failing | 0 |
| Total expected lines | 3530 |
| Matching lines | 3530 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**338 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 20.0s |  |
| 2 | `array_method_type1_args` | 7 | 1.6s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 23.2s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.8s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.8s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.8s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.8s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.8s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.8s |  |
| 10 | `avm1_array_forin_proto_swf5` | 14 | 1.8s |  |
| 11 | `avm1_array_forin_proto_swf6` | 14 | 1.7s |  |
| 12 | `avm1_array_forin_proto_swf8` | 14 | 1.6s |  |
| 13 | `avm1_array_generic_receivers` | 16 | 16.8s |  |
| 14 | `avm1_array_native_own_method` | 8 | 1.7s |  |
| 15 | `avm1_attach_clipevent_enterframe` | 11 | 17.0s |  |
| 16 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.9s |  |
| 17 | `avm1_attach_timeline_frame_order` | 82 | 17.7s |  |
| 18 | `avm1_attached_clip_button_click` | 13 | 16.9s |  |
| 19 | `avm1_attached_clip_color` | 2 | 19.3s |  |
| 20 | `avm1_attached_clip_goto_play` | 14 | 2.0s |  |
| 21 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.2s |  |
| 22 | `avm1_attached_clip_hidden_capture` | 6 | 17.0s |  |
| 23 | `avm1_attached_clip_holder_render` | 1 | 1.8s |  |
| 24 | `avm1_attached_clip_natural_timeline` | 34 | 16.9s |  |
| 25 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 22.2s |  |
| 26 | `avm1_attached_clip_samename_child` | 32 | 22.3s |  |
| 27 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 25.0s |  |
| 28 | `avm1_attached_clip_selfgoto_trace` | 14 | 22.3s |  |
| 29 | `avm1_attached_clip_tagorder` | 34 | 2.1s |  |
| 30 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.9s |  |
| 31 | `avm1_attached_clip_tagorder_po3` | 34 | 2.0s |  |
| 32 | `avm1_attached_clip_tagorder_ratio` | 34 | 2.0s |  |
| 33 | `avm1_attached_clip_timeline_child_parent` | 6 | 22.0s |  |
| 34 | `avm1_bare_depth_methods_v7_gate` | 6 | 21.9s |  |
| 35 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 1.1s |  |
| 36 | `avm1_bare_mc_method_scope` | 19 | 22.2s |  |
| 37 | `avm1_bitmap_nearest_tie_stage` | 1 | 24.3s |  |
| 38 | `avm1_bitmapdata_draw_child_color` | 5 | 22.1s |  |
| 39 | `avm1_bitmapdata_draw_edittext` | 3 | 2.1s |  |
| 40 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 22.1s |  |
| 41 | `avm1_browser_eager_init` | 10 | 22.1s |  |
| 42 | `avm1_browser_gated_color` | 3 | 21.7s |  |
| 43 | `avm1_browser_gated_depth` | 7 | 2.2s |  |
| 44 | `avm1_browser_gated_textfield` | 7 | 2.2s |  |
| 45 | `avm1_browser_parked_frame` | 7 | 21.6s |  |
| 46 | `avm1_button_pick_order` | 9 | 3.4s |  |
| 47 | `avm1_button_textfield_path_binding` | 4 | 21.8s |  |
| 48 | `avm1_child_timeline_advance` | 23 | 22.1s |  |
| 49 | `avm1_child_timeline_frame1_stop` | 7 | 26.2s |  |
| 50 | `avm1_child_timeline_holder_stop` | 26 | 2.8s |  |
| 51 | `avm1_child_timeline_loop` | 32 | 2.9s |  |
| 52 | `avm1_clipevent_root_goto_stopped` | 3 | 26.1s |  |
| 53 | `avm1_clone_depth_overflow` | 3 | 26.6s |  |
| 54 | `avm1_clone_depth_removed_reuse` | 4 | 2.5s |  |
| 55 | `avm1_closure_base_clip_root_frame` | 5 | 2.6s |  |
| 56 | `avm1_closure_method_scope` | 7 | 2.6s |  |
| 57 | `avm1_create_text_field_depth` | 9 | 2.5s |  |
| 58 | `avm1_cxform_override_overflow` | 2 | 29.8s |  |
| 59 | `avm1_definetext_matrix` | 0 | 2.6s |  |
| 60 | `avm1_device_edittext_xscale` | 7 | 26.8s |  |
| 61 | `avm1_display_filter_growth_edge_scale` | 0 | 20.2s |  |
| 62 | `avm1_display_prop_coercion` | 36 | 1.8s |  |
| 63 | `avm1_drawapi_stroke_snap` | 1 | 20.1s |  |
| 64 | `avm1_drawing_stroke_scale` | 0 | 21.4s |  |
| 65 | `avm1_dynclip_color_transform` | 2 | 2.0s |  |
| 66 | `avm1_edittext_border_subpixel` | 1 | 20.2s |  |
| 67 | `avm1_edittext_cut_copy_selection` | 9 | 20.2s |  |
| 68 | `avm1_edittext_html_delete_runs` | 4 | 20.2s |  |
| 69 | `avm1_edittext_html_typed_runs` | 3 | 1.8s |  |
| 70 | `avm1_edittext_maxchars_clips_insertion` | 4 | 1.7s |  |
| 71 | `avm1_edittext_path_variable_same_frame` | 11 | 20.0s |  |
| 72 | `avm1_edittext_path_variable_scope` | 10 | 1.8s |  |
| 73 | `avm1_edittext_placed_cxform` | 0 | 19.9s |  |
| 74 | `avm1_edittext_placed_cxform_script` | 3 | 1.7s |  |
| 75 | `avm1_edittext_restrict_onchanged` | 6 | 19.9s |  |
| 76 | `avm1_edittext_rotated_borders` | 0 | 19.9s |  |
| 77 | `avm1_edittext_rotated_color` | 0 | 19.8s |  |
| 78 | `avm1_edittext_rotated_glyphs` | 0 | 1.7s |  |
| 79 | `avm1_edittext_rotated_paragraph` | 0 | 19.9s |  |
| 80 | `avm1_edittext_scaled_glyphs` | 0 | 1.7s |  |
| 81 | `avm1_edittext_tab_render` | 1 | 20.0s |  |
| 82 | `avm1_edittext_tabstops_metric` | 9 | 20.3s |  |
| 83 | `avm1_edittext_wordwrap_render` | 5 | 20.2s |  |
| 84 | `avm1_empty_clip_drawing_depth_order` | 1 | 1.9s |  |
| 85 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 21.4s |  |
| 86 | `avm1_enterframe_root_goto_opcode` | 7 | 21.1s |  |
| 87 | `avm1_enterframe_root_nextframe` | 22 | 21.2s |  |
| 88 | `avm1_enterframe_sprite_nextframe` | 16 | 21.2s |  |
| 89 | `avm1_exec_order_attached_selfremove` | 18 | 22.1s |  |
| 90 | `avm1_exec_order_dynamic_eligible` | 35 | 2.5s |  |
| 91 | `avm1_exec_order_sibling_interleave` | 38 | 2.7s |  |
| 92 | `avm1_filter_list_overflow` | 2 | 21.0s |  |
| 93 | `avm1_func2_param_register_oob` | 4 | 2.0s |  |
| 94 | `avm1_gnash_flash_probes` | 63 | 2.5s |  |
| 95 | `avm1_gnash_flash_probes_v5` | 77 | 1.2s |  |
| 96 | `avm1_gnash_flash_probes_v6` | 63 | 1.1s |  |
| 97 | `avm1_goto_backward_enterframe_once` | 22 | 19.5s |  |
| 98 | `avm1_goto_current_frame_clip` | 23 | 19.9s |  |
| 99 | `avm1_goto_current_frame_root` | 22 | 19.3s |  |
| 100 | `avm1_goto_skipped_init_call` | 6 | 19.3s |  |
| 101 | `avm1_goto_skipped_init_script` | 5 | 1.7s |  |
| 102 | `avm1_goto_skipped_init_timer` | 6 | 1.7s |  |
| 103 | `avm1_goto_target_child_order_gotoscript` | 6 | 19.3s |  |
| 104 | `avm1_goto_target_child_order_interval` | 7 | 1.7s |  |
| 105 | `avm1_goto_target_child_order_normal` | 5 | 19.4s |  |
| 106 | `avm1_hairline_scaled_instances` | 1 | 1.7s |  |
| 107 | `avm1_hittest_hairline` | 28 | 19.9s |  |
| 108 | `avm1_hittest_shape_stale_matrix` | 28 | 19.8s |  |
| 109 | `avm1_holder_drawing_under_children` | 1 | 22.2s |  |
| 110 | `avm1_jpeg3_alpha_bitmap` | 0 | 19.6s |  |
| 111 | `avm1_key_isdown_protected` | 8 | 19.5s |  |
| 112 | `avm1_loaded_bare_goto` | 17 | 20.2s |  |
| 113 | `avm1_loaded_bare_goto_seq` | 4 | 2.1s |  |
| 114 | `avm1_loaded_goto_play_deferred` | 31 | 19.9s |  |
| 115 | `avm1_loaded_order_create_vs_load` | 33 | 2.1s |  |
| 116 | `avm1_loaded_shell_consumers_seq` | 12 | 19.9s |  |
| 117 | `avm1_loaded_shell_root_lookup` | 4 | 19.6s |  |
| 118 | `avm1_loaded_timeline_holder` | 7 | 1.8s |  |
| 119 | `avm1_loaded_unload_deferred` | 5 | 21.2s |  |
| 120 | `avm1_loadvars_ondata_overflow` | 23 | 21.2s |  |
| 121 | `avm1_long_text_layout` | 2 | 22.2s |  |
| 122 | `avm1_many_chars_registry` | 4 | 21.3s |  |
| 123 | `avm1_many_defs_registry` | 13 | 22.5s |  |
| 124 | `avm1_many_functions_registry` | 3 | 9.8s |  |
| 125 | `avm1_mc_button_unified_pick` | 21 | 21.2s |  |
| 126 | `avm1_mc_resolve` | 5 | 2.3s |  |
| 127 | `avm1_mc_super_native_probe` | 18 | 2.4s |  |
| 128 | `avm1_mcl_holder_totalframes` | 5 | 2.4s |  |
| 129 | `avm1_mcl_load_tick` | 15 | 2.3s |  |
| 130 | `avm1_morph_instances_ratio` | 2 | 29.2s |  |
| 131 | `avm1_nested_child_swapdepths_remove` | 8 | 25.7s |  |
| 132 | `avm1_nested_po3_filters` | 12 | 26.8s |  |
| 133 | `avm1_onunload_setvar_scope` | 5 | 26.0s |  |
| 134 | `avm1_parent_as3_child_payload` | 2 | 2.7s |  |
| 135 | `avm1_parent_child_bitmap` | 5 | 2.8s |  |
| 136 | `avm1_parent_child_bitmap_fill` | 3 | 26.1s |  |
| 137 | `avm1_parent_child_modify_place` | 5 | 2.7s |  |
| 138 | `avm1_parent_child_morph` | 8 | 2.8s |  |
| 139 | `avm1_parent_child_render` | 7 | 2.9s |  |
| 140 | `avm1_parent_child_sprite_meta` | 8 | 2.9s |  |
| 141 | `avm1_parent_child_text` | 8 | 22.9s |  |
| 142 | `avm1_pixelbounds_dynamic_child` | 1 | 19.9s |  |
| 143 | `avm1_place_occupied_depth_swf5` | 6 | 1.7s |  |
| 144 | `avm1_placed_drawing_color` | 1 | 20.0s |  |
| 145 | `avm1_po3_cm_alpha_bias_edge` | 0 | 19.8s |  |
| 146 | `avm1_po3_cm_folded_clear` | 1 | 1.7s |  |
| 147 | `avm1_po3_cm_live_under_cxform` | 0 | 1.7s |  |
| 148 | `avm1_po3_color_matrix_live` | 0 | 1.7s |  |
| 149 | `avm1_po3_color_matrix_live_clear` | 1 | 1.7s |  |
| 150 | `avm1_po3_color_matrix_live_nested` | 0 | 1.7s |  |
| 151 | `avm1_remove_same_name_other_parent` | 4 | 20.1s |  |
| 152 | `avm1_remove_unload_finalize_overflow` | 4 | 22.1s |  |
| 153 | `avm1_removed_clip_dprops_gc` | 14 | 19.9s |  |
| 154 | `avm1_resolve_dotted_getvariable` | 13 | 1.6s |  |
| 155 | `avm1_root_identity_and_playhead` | 3 | 19.8s |  |
| 156 | `avm1_root_onload_child_order` | 11 | 20.0s |  |
| 157 | `avm1_root_onload_proto` | 7 | 1.8s |  |
| 158 | `avm1_rotation_matrix_fixed` | 7 | 1.7s |  |
| 159 | `avm1_runtime_filters` | 3 | 23.1s |  |
| 160 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.0s |  |
| 161 | `avm1_selfgoto_current_frame_opcode` | 8 | 20.1s |  |
| 162 | `avm1_set_new_text_format_color` | 4 | 20.0s |  |
| 163 | `avm1_set_new_text_format_instance` | 5 | 26.3s |  |
| 164 | `avm1_set_new_text_format_paragraph` | 12 | 2.8s |  |
| 165 | `avm1_set_new_text_format_render` | 5 | 29.9s |  |
| 166 | `avm1_set_new_text_format_size` | 5 | 2.6s |  |
| 167 | `avm1_sprite_goto_script_overflow` | 65 | 26.7s |  |
| 168 | `avm1_stroke_hinting_caps` | 1 | 3.0s |  |
| 169 | `avm1_stroke_join_cap_snap` | 0 | 29.7s |  |
| 170 | `avm1_stroke_noscale_signed` | 0 | 27.3s |  |
| 171 | `avm1_stroke_pixel_snap` | 1 | 26.2s |  |
| 172 | `avm1_stroke_pixel_snap_matrix` | 0 | 26.7s |  |
| 173 | `avm1_stroke_seam_caps` | 1 | 26.5s |  |
| 174 | `avm1_stroke_style_id_order` | 1 | 22.9s |  |
| 175 | `avm1_swf6_case_insensitive_builtins` | 42 | 20.6s |  |
| 176 | `avm1_swf7_case_sensitive_builtins` | 40 | 1.0s |  |
| 177 | `avm1_tabindex_child_null` | 3 | 1.7s |  |
| 178 | `avm1_tabindex_clip_button_v6` | 28 | 1.8s |  |
| 179 | `avm1_tabindex_clip_button_v8` | 28 | 1.6s |  |
| 180 | `avm1_tabindex_fn2_root_raw` | 4 | 1.7s |  |
| 181 | `avm1_tabindex_fresh_child_coerce` | 4 | 1.6s |  |
| 182 | `avm1_tabindex_mtasc_class_main` | 6 | 1.8s |  |
| 183 | `avm1_tabindex_read_first_coerce` | 5 | 1.6s |  |
| 184 | `avm1_tabindex_textfield_v6` | 13 | 1.8s |  |
| 185 | `avm1_tabindex_textfield_v8` | 13 | 1.7s |  |
| 186 | `avm1_textfield_attached_depth_order` | 1 | 20.1s |  |
| 187 | `avm1_textfield_ctor_shadow_swf6` | 2 | 1.6s |  |
| 188 | `avm1_textfield_ctor_shadow_swf7` | 2 | 0.9s |  |
| 189 | `avm1_textfield_x_bounds_offset` | 10 | 19.6s |  |
| 190 | `avm1_timer_clock_model` | 12 | 20.0s |  |
| 191 | `avm1_timer_function_form_activation` | 3 | 19.7s |  |
| 192 | `avm1_timer_late_frame_check` | 29 | 20.0s |  |
| 193 | `avm1_timer_method_form` | 6 | 19.6s |  |
| 194 | `avm1_timer_native_method_play` | 3 | 1.7s |  |
| 195 | `avm1_timer_overflow` | 10 | 2.2s |  |
| 196 | `avm1_timer_root_goto_stopped_gs` | 3 | 17.9s |  |
| 197 | `avm1_timer_root_goto_stopped_nf` | 3 | 1.8s |  |
| 198 | `avm1_type2_mc_receiver_dispatch` | 7 | 18.3s |  |
| 199 | `avm1_watch_long_name` | 9 | 1.8s |  |
| 200 | `avm1_watch_overflow` | 2 | 2.3s |  |
| 201 | `avm1_wrap_giveup_mixed_runs` | 2 | 1.8s |  |
| 202 | `avm1_xml_first_action_proto` | 2 | 1.8s |  |
| 203 | `avm1_xmlnode_first_action_proto` | 2 | 1.7s |  |
| 204 | `avm1_xscale_double_readback` | 8 | 17.7s |  |
| 205 | `avm2_activation_vtable_bounded` | 5 | 28.8s |  |
| 206 | `avm2_agi_shell` | 6 | 7.1s |  |
| 207 | `avm2_applyfilter_bevel_sample` | 441 | 45.1s |  |
| 208 | `avm2_applyfilter_glow_kernels` | 23 | 8.3s |  |
| 209 | `avm2_applyfilter_gradient_opaque` | 26 | 9.2s |  |
| 210 | `avm2_array_growth_bounded` | 5 | 9.0s |  |
| 211 | `avm2_bitmapdata_draw_edittext_box` | 5 | 8.2s |  |
| 212 | `avm2_bitmapdata_draw_filtered` | 13 | 8.2s |  |
| 213 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 8.9s |  |
| 214 | `avm2_bitmapdata_draw_textfield` | 5 | 8.5s |  |
| 215 | `avm2_bitmapdata_palettemap_index` | 5 | 26.9s |  |
| 216 | `avm2_child_simplebutton` | 10 | 27.0s |  |
| 217 | `avm2_contextmenu_stub` | 4 | 8.2s |  |
| 218 | `avm2_definetext_matrix` | 0 | 33.9s |  |
| 219 | `avm2_drawapi_stroke_snap` | 1 | 25.4s |  |
| 220 | `avm2_e4x_parse_bounded` | 18 | 26.4s |  |
| 221 | `avm2_edittext_placed_cxform` | 0 | 26.2s |  |
| 222 | `avm2_edittext_selection_cxform` | 2 | 26.2s |  |
| 223 | `avm2_embed_bytearray` | 2 | 26.3s |  |
| 224 | `avm2_external_interface_unavailable` | 8 | 7.5s |  |
| 225 | `avm2_findprop_this_resolution` | 13 | 7.5s |  |
| 226 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.8s |  |
| 227 | `avm2_gc_string_concat_reclaim` | 10 | 7.6s |  |
| 228 | `avm2_gc_string_survives_collect` | 9 | 7.5s |  |
| 229 | `avm2_goto_catchup_scale` | 4 | 41.8s |  |
| 230 | `avm2_graphics_runtime` | 7 | 37.6s |  |
| 231 | `avm2_group_alpha_cab` | 0 | 33.7s |  |
| 232 | `avm2_group_alpha_filter_cm` | 0 | 10.4s |  |
| 233 | `avm2_group_alpha_layer_aadd` | 0 | 10.3s |  |
| 234 | `avm2_group_alpha_layer_inner` | 0 | 10.3s |  |
| 235 | `avm2_group_alpha_multiply` | 0 | 1.6s |  |
| 236 | `avm2_group_alpha_shadow_shape_a50` | 0 | 10.4s |  |
| 237 | `avm2_html_img_loadcount` | 39 | 36.1s |  |
| 238 | `avm2_json_roundtrip_bounded` | 13 | 11.2s |  |
| 239 | `avm2_layer_group_alpha` | 0 | 40.7s |  |
| 240 | `avm2_layer_group_alpha_transparency` | 0 | 34.7s |  |
| 241 | `avm2_layer_group_erase` | 0 | 30.5s |  |
| 242 | `avm2_layer_group_filtered_child` | 0 | 26.1s |  |
| 243 | `avm2_layer_group_overlap_alpha` | 0 | 26.3s |  |
| 244 | `avm2_loader_stub` | 5 | 26.3s |  |
| 245 | `avm2_localconnection_domain` | 4 | 7.4s |  |
| 246 | `avm2_mask_removal_script` | 6 | 26.2s |  |
| 247 | `avm2_morph` | 8 | 26.0s |  |
| 248 | `avm2_parent_child_render` | 11 | 9.4s |  |
| 249 | `avm2_parent_child_static_text` | 12 | 7.7s |  |
| 250 | `avm2_parent_child_symbol_stride` | 6 | 8.5s |  |
| 251 | `avm2_parent_child_symbolclass_domain` | 12 | 31.2s |  |
| 252 | `avm2_pixelbounds_offlist` | 13 | 25.1s |  |
| 253 | `avm2_reflect_trait_hooks` | 30 | 25.3s |  |
| 254 | `avm2_sharedobject_flushstatus` | 4 | 7.1s |  |
| 255 | `avm2_simplebutton_click` | 2 | 7.3s |  |
| 256 | `avm2_slot_default_template` | 34 | 7.3s |  |
| 257 | `avm2_sound_bytes_and_group_format` | 27 | 7.4s |  |
| 258 | `avm2_static_and_store_slots` | 14 | 7.3s |  |
| 259 | `avm2_static_text` | 6 | 25.1s |  |
| 260 | `avm2_strbuf_stale_prefix` | 21 | 7.2s |  |
| 261 | `avm2_stroke_curve_scale_s16_w16_k0` | 2 | 28.5s |  |
| 262 | `avm2_stroke_curve_scale_s16_w16_k1` | 2 | 46.9s |  |
| 263 | `avm2_stroke_curve_scale_s16_w4_k0` | 2 | 34.8s |  |
| 264 | `avm2_stroke_curve_scale_s16_w4_k1` | 2 | 2.3s |  |
| 265 | `avm2_stroke_curve_scale_s1s4` | 17 | 35.1s |  |
| 266 | `avm2_stroke_translucent_round` | 1 | 34.6s |  |
| 267 | `avm2_timeline_gradients` | 7 | 35.0s |  |
| 268 | `avm2_timeline_solid` | 6 | 11.4s |  |
| 269 | `avm2_timeline_stroke_gradient` | 9 | 11.5s |  |
| 270 | `avm2_timeline_text` | 4 | 34.0s |  |
| 271 | `avm2_tolerant_verify_quarantine` | 2 | 10.0s |  |
| 272 | `avm2_typed_value_ops` | 30 | 10.3s |  |
| 273 | `bitmap_pool_layer_cap` | 1 | 27.6s |  |
| 274 | `broadcast_cross_swf_version` | 4 | 22.1s |  |
| 275 | `broadcast_type1_args` | 14 | 21.6s |  |
| 276 | `coerce_cross_swf_version` | 7 | 2.3s |  |
| 277 | `coerce_recursion_guard` | 1 | 2.1s |  |
| 278 | `coerce_type1_args` | 9 | 2.3s |  |
| 279 | `convertfloat_type1_this` | 3 | 2.1s |  |
| 280 | `ctor_before_first_call_locals` | 5 | 2.2s |  |
| 281 | `ei_closure_scope_order` | 7 | 2.5s |  |
| 282 | `ei_cross_swf_version` | 2 | 2.1s |  |
| 283 | `ei_mc_this_receiver` | 5 | 22.6s |  |
| 284 | `ei_type1_args` | 7 | 19.8s |  |
| 285 | `enterframe_type1_args` | 8 | 19.9s |  |
| 286 | `fn_call_builtin_type1_args` | 10 | 1.6s |  |
| 287 | `fn_call_type1_args` | 7 | 1.6s |  |
| 288 | `fn_empty_method_type1_args` | 10 | 1.6s |  |
| 289 | `group_alpha_cab` | 0 | 22.7s |  |
| 290 | `group_alpha_filter_cm` | 0 | 1.8s |  |
| 291 | `group_alpha_layer_aadd` | 0 | 1.7s |  |
| 292 | `group_alpha_layer_inner` | 0 | 1.7s |  |
| 293 | `group_alpha_multiply` | 0 | 0.9s |  |
| 294 | `group_alpha_shadow_shape_a50` | 0 | 1.8s |  |
| 295 | `layer_group_alpha_transparency` | 0 | 30.1s |  |
| 296 | `layer_group_filtered_child` | 0 | 26.5s |  |
| 297 | `layer_group_in_add_alpha` | 0 | 31.8s |  |
| 298 | `layer_group_overlap_alpha` | 0 | 2.0s |  |
| 299 | `layer_group_overlap_erase` | 0 | 1.3s |  |
| 300 | `lc_method_type1_args` | 7 | 25.7s |  |
| 301 | `lc_onstatus_type1_args` | 3 | 1.9s |  |
| 302 | `lowq_fill_edges` | 0 | 25.4s |  |
| 303 | `lowq_glyph_probe_df2` | 0 | 27.5s |  |
| 304 | `lowq_glyph_probe_df3` | 0 | 2.9s |  |
| 305 | `lowq_gradient_orient_probe` | 0 | 25.6s |  |
| 306 | `lowq_sample_point_probe` | 0 | 22.3s |  |
| 307 | `lowq_stroke_probe` | 0 | 20.1s |  |
| 308 | `lowq_tsnap_tie_probe` | 0 | 19.7s |  |
| 309 | `lv_cross_swf_version` | 5 | 19.7s |  |
| 310 | `lv_ondata_type1_args` | 3 | 19.7s |  |
| 311 | `mask_nested_intersect` | 1 | 23.0s |  |
| 312 | `mask_sibling_union` | 1 | 1.4s |  |
| 313 | `mc_event_cross_swf_version` | 4 | 1.5s |  |
| 314 | `mc_event_type1_args` | 3 | 19.8s |  |
| 315 | `mc_method_v5_caller_gate` | 4 | 1.5s |  |
| 316 | `mc_resolve_type1_args` | 6 | 1.4s |  |
| 317 | `method_type1_args` | 10 | 19.5s |  |
| 318 | `nc_onstatus_closure` | 2 | 19.5s |  |
| 319 | `nc_onstatus_type1_args` | 3 | 1.6s |  |
| 320 | `onconstruct_cross_swf_version` | 4 | 20.0s |  |
| 321 | `onconstruct_type1_args` | 6 | 1.6s |  |
| 322 | `onload_type1_args` | 7 | 1.6s |  |
| 323 | `onunload_type1_args` | 6 | 1.6s |  |
| 324 | `onunload_type1_local_frame` | 2 | 1.6s |  |
| 325 | `resolve_type1_args` | 13 | 1.6s |  |
| 326 | `root_enterframe_cross_swf_version` | 3 | 20.0s |  |
| 327 | `sort_comparator_captured_scope` | 2 | 1.7s |  |
| 328 | `sort_comparator_type1_args` | 5 | 21.2s |  |
| 329 | `string_prim_method_type1_args` | 19 | 2.1s |  |
| 330 | `timer_cross_swf_version` | 3 | 21.5s |  |
| 331 | `timer_type1_args` | 14 | 21.4s |  |
| 332 | `watch_cross_swf_version` | 6 | 2.2s |  |
| 333 | `watch_mc_reentrant_setmember` | 3 | 2.1s |  |
| 334 | `watch_mc_type1_args` | 7 | 2.1s |  |
| 335 | `watch_setmember_type1_args` | 7 | 2.2s |  |
| 336 | `watch_timeline_named_params` | 4 | 2.5s |  |
| 337 | `watch_timeline_reentrant` | 3 | 2.2s |  |
| 338 | `xml_onload_type1_args` | 3 | 21.6s |  |

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
