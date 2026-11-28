# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 08:08 UTC

**Git SHA**: `3dfab12779`

**Run Duration**: 59m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 347 |
| Passing | **347** (100.0%) |
| Failing | 0 |
| Total expected lines | 3770 |
| Matching lines | 3770 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**347 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 19.5s |  |
| 2 | `array_method_type1_args` | 7 | 1.1s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 19.8s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.3s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.3s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.3s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.4s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.3s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.3s |  |
| 10 | `avm1_array_forin_proto_swf5` | 14 | 1.3s |  |
| 11 | `avm1_array_forin_proto_swf6` | 14 | 1.2s |  |
| 12 | `avm1_array_forin_proto_swf8` | 14 | 1.1s |  |
| 13 | `avm1_array_generic_receivers` | 16 | 19.0s |  |
| 14 | `avm1_array_native_own_method` | 8 | 0.9s |  |
| 15 | `avm1_asnative_mc_probe_swf5` | 8 | 1.0s |  |
| 16 | `avm1_asnative_mc_probe_swf6` | 8 | 0.3s |  |
| 17 | `avm1_attach_clipevent_enterframe` | 11 | 19.1s |  |
| 18 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.1s |  |
| 19 | `avm1_attach_timeline_frame_order` | 82 | 19.2s |  |
| 20 | `avm1_attached_clip_button_click` | 13 | 19.1s |  |
| 21 | `avm1_attached_clip_color` | 2 | 19.4s |  |
| 22 | `avm1_attached_clip_goto_play` | 14 | 1.3s |  |
| 23 | `avm1_attached_clip_goto_play_nonroot` | 14 | 0.5s |  |
| 24 | `avm1_attached_clip_hidden_capture` | 6 | 19.6s |  |
| 25 | `avm1_attached_clip_holder_render` | 1 | 19.6s |  |
| 26 | `avm1_attached_clip_natural_timeline` | 34 | 19.8s |  |
| 27 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.1s |  |
| 28 | `avm1_attached_clip_samename_child` | 32 | 19.6s |  |
| 29 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 19.7s |  |
| 30 | `avm1_attached_clip_selfgoto_trace` | 14 | 19.9s |  |
| 31 | `avm1_attached_clip_tagorder` | 34 | 1.1s |  |
| 32 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.2s |  |
| 33 | `avm1_attached_clip_tagorder_po3` | 34 | 1.0s |  |
| 34 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.0s |  |
| 35 | `avm1_attached_clip_timeline_child_parent` | 6 | 19.5s |  |
| 36 | `avm1_bare_depth_methods_v7_gate` | 6 | 0.9s |  |
| 37 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 18.3s |  |
| 38 | `avm1_bare_mc_method_scope` | 19 | 18.5s |  |
| 39 | `avm1_bitmap_nearest_tie_stage` | 1 | 18.1s |  |
| 40 | `avm1_bitmapdata_draw_child_color` | 5 | 19.3s |  |
| 41 | `avm1_bitmapdata_draw_edittext` | 3 | 1.0s |  |
| 42 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 18.6s |  |
| 43 | `avm1_browser_eager_init` | 10 | 18.5s |  |
| 44 | `avm1_browser_gated_color` | 3 | 0.8s |  |
| 45 | `avm1_browser_gated_depth` | 7 | 0.9s |  |
| 46 | `avm1_browser_gated_textfield` | 7 | 1.0s |  |
| 47 | `avm1_browser_parked_frame` | 7 | 18.5s |  |
| 48 | `avm1_button_pick_order` | 9 | 1.8s |  |
| 49 | `avm1_button_textfield_path_binding` | 4 | 19.2s |  |
| 50 | `avm1_child_timeline_advance` | 23 | 19.4s |  |
| 51 | `avm1_child_timeline_frame1_stop` | 7 | 1.1s |  |
| 52 | `avm1_child_timeline_holder_stop` | 26 | 1.1s |  |
| 53 | `avm1_child_timeline_loop` | 32 | 1.1s |  |
| 54 | `avm1_clipevent_root_goto_stopped` | 3 | 19.1s |  |
| 55 | `avm1_clone_depth_overflow` | 3 | 19.5s |  |
| 56 | `avm1_clone_depth_removed_reuse` | 4 | 0.9s |  |
| 57 | `avm1_closure_base_clip_root_frame` | 5 | 1.0s |  |
| 58 | `avm1_closure_method_scope` | 7 | 1.0s |  |
| 59 | `avm1_create_text_field_depth` | 9 | 1.0s |  |
| 60 | `avm1_cxform_override_overflow` | 2 | 19.2s |  |
| 61 | `avm1_definetext_matrix` | 0 | 0.9s |  |
| 62 | `avm1_device_edittext_xscale` | 7 | 19.3s |  |
| 63 | `avm1_display_filter_growth_edge_scale` | 0 | 19.1s |  |
| 64 | `avm1_display_prop_coercion` | 36 | 1.1s |  |
| 65 | `avm1_drawapi_stroke_snap` | 1 | 19.3s |  |
| 66 | `avm1_drawing_stroke_scale` | 0 | 20.6s |  |
| 67 | `avm1_dynclip_color_transform` | 2 | 1.1s |  |
| 68 | `avm1_edittext_border_subpixel` | 1 | 19.1s |  |
| 69 | `avm1_edittext_cut_copy_selection` | 9 | 19.5s |  |
| 70 | `avm1_edittext_html_delete_runs` | 4 | 19.5s |  |
| 71 | `avm1_edittext_html_typed_runs` | 3 | 1.1s |  |
| 72 | `avm1_edittext_maxchars_clips_insertion` | 4 | 0.9s |  |
| 73 | `avm1_edittext_path_variable_same_frame` | 11 | 24.8s |  |
| 74 | `avm1_edittext_path_variable_scope` | 10 | 24.7s |  |
| 75 | `avm1_edittext_placed_cxform` | 0 | 24.5s |  |
| 76 | `avm1_edittext_placed_cxform_script` | 3 | 1.3s |  |
| 77 | `avm1_edittext_restrict_onchanged` | 6 | 24.5s |  |
| 78 | `avm1_edittext_rotated_borders` | 0 | 24.6s |  |
| 79 | `avm1_edittext_rotated_color` | 0 | 24.4s |  |
| 80 | `avm1_edittext_rotated_glyphs` | 0 | 1.2s |  |
| 81 | `avm1_edittext_rotated_paragraph` | 0 | 24.6s |  |
| 82 | `avm1_edittext_scaled_glyphs` | 0 | 1.2s |  |
| 83 | `avm1_edittext_tab_render` | 1 | 24.8s |  |
| 84 | `avm1_edittext_tabstops_metric` | 9 | 25.8s |  |
| 85 | `avm1_edittext_wordwrap_render` | 5 | 19.6s |  |
| 86 | `avm1_empty_clip_drawing_depth_order` | 1 | 19.8s |  |
| 87 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 19.8s |  |
| 88 | `avm1_enterframe_root_goto_opcode` | 7 | 19.6s |  |
| 89 | `avm1_enterframe_root_nextframe` | 22 | 19.5s |  |
| 90 | `avm1_enterframe_sprite_nextframe` | 16 | 1.1s |  |
| 91 | `avm1_exec_order_attached_selfremove` | 18 | 19.6s |  |
| 92 | `avm1_exec_order_dynamic_eligible` | 35 | 1.2s |  |
| 93 | `avm1_exec_order_sibling_interleave` | 38 | 1.3s |  |
| 94 | `avm1_filter_list_overflow` | 2 | 19.3s |  |
| 95 | `avm1_func2_param_register_oob` | 4 | 0.9s |  |
| 96 | `avm1_gnash_flash_probes` | 63 | 1.3s |  |
| 97 | `avm1_gnash_flash_probes_v5` | 77 | 15.3s |  |
| 98 | `avm1_gnash_flash_probes_v6` | 63 | 0.3s |  |
| 99 | `avm1_goto_backward_enterframe_once` | 22 | 15.2s |  |
| 100 | `avm1_goto_current_frame_clip` | 23 | 15.4s |  |
| 101 | `avm1_goto_current_frame_root` | 22 | 15.1s |  |
| 102 | `avm1_goto_skipped_init_call` | 6 | 15.1s |  |
| 103 | `avm1_goto_skipped_init_script` | 5 | 1.0s |  |
| 104 | `avm1_goto_skipped_init_timer` | 6 | 1.0s |  |
| 105 | `avm1_goto_target_child_order_gotoscript` | 6 | 14.8s |  |
| 106 | `avm1_goto_target_child_order_interval` | 7 | 1.0s |  |
| 107 | `avm1_goto_target_child_order_normal` | 5 | 15.2s |  |
| 108 | `avm1_hairline_scaled_instances` | 1 | 1.1s |  |
| 109 | `avm1_hittest_hairline` | 28 | 19.3s |  |
| 110 | `avm1_hittest_shape_stale_matrix` | 28 | 19.1s |  |
| 111 | `avm1_holder_drawing_under_children` | 1 | 18.9s |  |
| 112 | `avm1_jpeg3_alpha_bitmap` | 0 | 18.8s |  |
| 113 | `avm1_key_isdown_protected` | 8 | 18.9s |  |
| 114 | `avm1_loaded_bare_goto` | 17 | 19.3s |  |
| 115 | `avm1_loaded_bare_goto_seq` | 4 | 1.4s |  |
| 116 | `avm1_loaded_goto_play_deferred` | 31 | 19.3s |  |
| 117 | `avm1_loaded_order_create_vs_load` | 33 | 1.4s |  |
| 118 | `avm1_loaded_shell_consumers_seq` | 12 | 19.2s |  |
| 119 | `avm1_loaded_shell_root_lookup` | 4 | 19.1s |  |
| 120 | `avm1_loaded_timeline_holder` | 7 | 1.1s |  |
| 121 | `avm1_loaded_unload_deferred` | 5 | 18.9s |  |
| 122 | `avm1_loadvars_ondata_overflow` | 23 | 19.0s |  |
| 123 | `avm1_long_text_layout` | 2 | 18.6s |  |
| 124 | `avm1_many_chars_registry` | 4 | 19.1s |  |
| 125 | `avm1_many_defs_registry` | 13 | 20.1s |  |
| 126 | `avm1_many_functions_registry` | 3 | 8.2s |  |
| 127 | `avm1_mc_button_unified_pick` | 21 | 18.9s |  |
| 128 | `avm1_mc_resolve` | 5 | 0.9s |  |
| 129 | `avm1_mc_super_native_probe` | 18 | 1.2s |  |
| 130 | `avm1_mcl_holder_totalframes` | 5 | 1.1s |  |
| 131 | `avm1_mcl_load_tick` | 15 | 1.0s |  |
| 132 | `avm1_morph_instances_ratio` | 2 | 18.7s |  |
| 133 | `avm1_native_identity_probe_swf5` | 43 | 18.8s |  |
| 134 | `avm1_native_identity_probe_swf6` | 43 | 0.3s |  |
| 135 | `avm1_native_identity_probe_swf7` | 43 | 0.3s |  |
| 136 | `avm1_native_identity_probe_swf8` | 43 | 0.3s |  |
| 137 | `avm1_native_instance_layout` | 12 | 0.9s |  |
| 138 | `avm1_nested_child_swapdepths_remove` | 8 | 18.8s |  |
| 139 | `avm1_nested_po3_filters` | 12 | 18.8s |  |
| 140 | `avm1_onunload_setvar_scope` | 5 | 18.8s |  |
| 141 | `avm1_parent_as3_child_payload` | 2 | 1.0s |  |
| 142 | `avm1_parent_child_bitmap` | 5 | 1.1s |  |
| 143 | `avm1_parent_child_bitmap_fill` | 3 | 1.1s |  |
| 144 | `avm1_parent_child_modify_place` | 5 | 1.1s |  |
| 145 | `avm1_parent_child_morph` | 8 | 1.9s |  |
| 146 | `avm1_parent_child_render` | 7 | 1.8s |  |
| 147 | `avm1_parent_child_sprite_meta` | 8 | 1.9s |  |
| 148 | `avm1_parent_child_text` | 8 | 1.8s |  |
| 149 | `avm1_pixelbounds_dynamic_child` | 1 | 24.7s |  |
| 150 | `avm1_place_occupied_depth_swf5` | 6 | 1.6s |  |
| 151 | `avm1_placed_drawing_color` | 1 | 25.1s |  |
| 152 | `avm1_po3_cm_alpha_bias_edge` | 0 | 24.8s |  |
| 153 | `avm1_po3_cm_folded_clear` | 1 | 1.6s |  |
| 154 | `avm1_po3_cm_live_under_cxform` | 0 | 1.5s |  |
| 155 | `avm1_po3_color_matrix_live` | 0 | 1.5s |  |
| 156 | `avm1_po3_color_matrix_live_clear` | 1 | 1.5s |  |
| 157 | `avm1_po3_color_matrix_live_nested` | 0 | 19.0s |  |
| 158 | `avm1_remove_same_name_other_parent` | 4 | 19.4s |  |
| 159 | `avm1_remove_unload_finalize_overflow` | 4 | 21.3s |  |
| 160 | `avm1_removed_clip_dprops_gc` | 14 | 1.1s |  |
| 161 | `avm1_resolve_dotted_getvariable` | 13 | 0.9s |  |
| 162 | `avm1_root_identity_and_playhead` | 3 | 19.2s |  |
| 163 | `avm1_root_onload_child_order` | 11 | 19.1s |  |
| 164 | `avm1_root_onload_proto` | 7 | 1.1s |  |
| 165 | `avm1_rotation_matrix_fixed` | 7 | 1.0s |  |
| 166 | `avm1_runtime_filters` | 3 | 19.6s |  |
| 167 | `avm1_runtime_filters_cm_bitmap` | 5 | 1.1s |  |
| 168 | `avm1_selfgoto_current_frame_opcode` | 8 | 19.5s |  |
| 169 | `avm1_set_new_text_format_color` | 4 | 15.4s |  |
| 170 | `avm1_set_new_text_format_instance` | 5 | 15.2s |  |
| 171 | `avm1_set_new_text_format_paragraph` | 12 | 1.1s |  |
| 172 | `avm1_set_new_text_format_render` | 5 | 15.3s |  |
| 173 | `avm1_set_new_text_format_size` | 5 | 0.9s |  |
| 174 | `avm1_sprite_goto_script_overflow` | 65 | 1.3s |  |
| 175 | `avm1_stroke_hinting_caps` | 1 | 1.1s |  |
| 176 | `avm1_stroke_join_cap_snap` | 0 | 16.6s |  |
| 177 | `avm1_stroke_noscale_signed` | 0 | 15.2s |  |
| 178 | `avm1_stroke_pixel_snap` | 1 | 15.2s |  |
| 179 | `avm1_stroke_pixel_snap_matrix` | 0 | 15.5s |  |
| 180 | `avm1_stroke_seam_caps` | 1 | 15.3s |  |
| 181 | `avm1_stroke_style_id_order` | 1 | 20.7s |  |
| 182 | `avm1_swapdepths_remove_clipevent_unload` | 13 | 21.0s |  |
| 183 | `avm1_swf6_case_insensitive_builtins` | 42 | 20.3s |  |
| 184 | `avm1_swf7_case_sensitive_builtins` | 40 | 0.4s |  |
| 185 | `avm1_tabindex_child_null` | 3 | 1.2s |  |
| 186 | `avm1_tabindex_clip_button_v6` | 28 | 1.3s |  |
| 187 | `avm1_tabindex_clip_button_v8` | 28 | 1.1s |  |
| 188 | `avm1_tabindex_fn2_root_raw` | 4 | 1.2s |  |
| 189 | `avm1_tabindex_fresh_child_coerce` | 4 | 1.3s |  |
| 190 | `avm1_tabindex_mtasc_class_main` | 6 | 1.3s |  |
| 191 | `avm1_tabindex_read_first_coerce` | 5 | 1.1s |  |
| 192 | `avm1_tabindex_textfield_v6` | 13 | 1.3s |  |
| 193 | `avm1_tabindex_textfield_v8` | 13 | 1.2s |  |
| 194 | `avm1_textfield_attached_depth_order` | 1 | 21.7s |  |
| 195 | `avm1_textfield_ctor_shadow_swf6` | 2 | 1.1s |  |
| 196 | `avm1_textfield_ctor_shadow_swf7` | 2 | 0.3s |  |
| 197 | `avm1_textfield_x_bounds_offset` | 10 | 21.3s |  |
| 198 | `avm1_timeline_selfgoto_child_replace` | 27 | 21.9s |  |
| 199 | `avm1_timer_clock_model` | 12 | 21.6s |  |
| 200 | `avm1_timer_function_form_activation` | 3 | 21.1s |  |
| 201 | `avm1_timer_late_frame_check` | 29 | 21.9s |  |
| 202 | `avm1_timer_method_form` | 6 | 1.2s |  |
| 203 | `avm1_timer_native_method_play` | 3 | 1.1s |  |
| 204 | `avm1_timer_overflow` | 10 | 1.7s |  |
| 205 | `avm1_timer_root_goto_stopped_gs` | 3 | 19.7s |  |
| 206 | `avm1_timer_root_goto_stopped_nf` | 3 | 0.9s |  |
| 207 | `avm1_type2_mc_receiver_dispatch` | 7 | 20.1s |  |
| 208 | `avm1_watch_long_name` | 9 | 1.0s |  |
| 209 | `avm1_watch_overflow` | 2 | 1.6s |  |
| 210 | `avm1_wrap_giveup_mixed_runs` | 2 | 1.0s |  |
| 211 | `avm1_xml_first_action_proto` | 2 | 0.9s |  |
| 212 | `avm1_xmlnode_first_action_proto` | 2 | 0.9s |  |
| 213 | `avm1_xscale_double_readback` | 8 | 1.1s |  |
| 214 | `avm2_activation_vtable_bounded` | 5 | 25.7s |  |
| 215 | `avm2_agi_shell` | 6 | 1.7s |  |
| 216 | `avm2_applyfilter_bevel_sample` | 441 | 16.3s |  |
| 217 | `avm2_applyfilter_glow_kernels` | 23 | 6.4s |  |
| 218 | `avm2_applyfilter_gradient_opaque` | 26 | 7.1s |  |
| 219 | `avm2_array_growth_bounded` | 5 | 6.9s |  |
| 220 | `avm2_bitmapdata_draw_edittext_box` | 5 | 6.0s |  |
| 221 | `avm2_bitmapdata_draw_filtered` | 13 | 6.1s |  |
| 222 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 6.6s |  |
| 223 | `avm2_bitmapdata_draw_textfield` | 5 | 6.4s |  |
| 224 | `avm2_bitmapdata_palettemap_index` | 5 | 20.8s |  |
| 225 | `avm2_child_simplebutton` | 10 | 25.4s |  |
| 226 | `avm2_contextmenu_stub` | 4 | 6.0s |  |
| 227 | `avm2_definetext_matrix` | 0 | 32.9s |  |
| 228 | `avm2_drawapi_stroke_snap` | 1 | 32.5s |  |
| 229 | `avm2_e4x_parse_bounded` | 18 | 9.7s |  |
| 230 | `avm2_edittext_placed_cxform` | 0 | 32.6s |  |
| 231 | `avm2_edittext_selection_cxform` | 2 | 32.8s |  |
| 232 | `avm2_embed_bytearray` | 2 | 8.0s |  |
| 233 | `avm2_external_interface_unavailable` | 8 | 8.0s |  |
| 234 | `avm2_findprop_this_resolution` | 13 | 2.5s |  |
| 235 | `avm2_gc_dynprop_tombstone_purge` | 8 | 8.4s |  |
| 236 | `avm2_gc_string_concat_reclaim` | 10 | 8.4s |  |
| 237 | `avm2_gc_string_survives_collect` | 9 | 8.2s |  |
| 238 | `avm2_goto_catchup_scale` | 4 | 8.6s |  |
| 239 | `avm2_graphics_runtime` | 7 | 31.6s |  |
| 240 | `avm2_group_alpha_cab` | 0 | 31.8s |  |
| 241 | `avm2_group_alpha_filter_cm` | 0 | 8.4s |  |
| 242 | `avm2_group_alpha_layer_aadd` | 0 | 8.2s |  |
| 243 | `avm2_group_alpha_layer_inner` | 0 | 8.4s |  |
| 244 | `avm2_group_alpha_multiply` | 0 | 0.6s |  |
| 245 | `avm2_group_alpha_shadow_shape_a50` | 0 | 8.5s |  |
| 246 | `avm2_html_img_loadcount` | 39 | 8.6s |  |
| 247 | `avm2_json_roundtrip_bounded` | 13 | 9.5s |  |
| 248 | `avm2_layer_group_alpha` | 0 | 8.8s |  |
| 249 | `avm2_layer_group_alpha_transparency` | 0 | 21.3s |  |
| 250 | `avm2_layer_group_erase` | 0 | 21.5s |  |
| 251 | `avm2_layer_group_filtered_child` | 0 | 21.6s |  |
| 252 | `avm2_layer_group_overlap_alpha` | 0 | 5.6s |  |
| 253 | `avm2_loader_stub` | 5 | 5.8s |  |
| 254 | `avm2_localconnection_domain` | 4 | 5.7s |  |
| 255 | `avm2_mask_removal_script` | 6 | 21.6s |  |
| 256 | `avm2_morph` | 8 | 21.1s |  |
| 257 | `avm2_parent_child_render` | 11 | 7.5s |  |
| 258 | `avm2_parent_child_static_text` | 12 | 6.0s |  |
| 259 | `avm2_parent_child_symbol_stride` | 6 | 6.7s |  |
| 260 | `avm2_parent_child_symbolclass_domain` | 12 | 25.0s |  |
| 261 | `avm2_pixelbounds_offlist` | 13 | 24.5s |  |
| 262 | `avm2_reflect_trait_hooks` | 30 | 24.6s |  |
| 263 | `avm2_sharedobject_flushstatus` | 4 | 5.9s |  |
| 264 | `avm2_simplebutton_click` | 2 | 6.0s |  |
| 265 | `avm2_slot_default_template` | 34 | 6.1s |  |
| 266 | `avm2_sound_bytes_and_group_format` | 27 | 6.2s |  |
| 267 | `avm2_static_and_store_slots` | 14 | 6.1s |  |
| 268 | `avm2_static_text` | 6 | 24.2s |  |
| 269 | `avm2_strbuf_stale_prefix` | 21 | 5.9s |  |
| 270 | `avm2_stroke_curve_scale_s16_w16_k0` | 2 | 24.2s |  |
| 271 | `avm2_stroke_curve_scale_s16_w16_k1` | 2 | 22.6s |  |
| 272 | `avm2_stroke_curve_scale_s16_w4_k0` | 2 | 18.1s |  |
| 273 | `avm2_stroke_curve_scale_s16_w4_k1` | 2 | 0.6s |  |
| 274 | `avm2_stroke_curve_scale_s1s4` | 17 | 22.7s |  |
| 275 | `avm2_stroke_translucent_round` | 1 | 22.7s |  |
| 276 | `avm2_timeline_gradients` | 7 | 22.1s |  |
| 277 | `avm2_timeline_solid` | 6 | 6.4s |  |
| 278 | `avm2_timeline_stroke_gradient` | 9 | 6.6s |  |
| 279 | `avm2_timeline_text` | 4 | 21.2s |  |
| 280 | `avm2_tolerant_verify_quarantine` | 2 | 5.5s |  |
| 281 | `avm2_typed_value_ops` | 30 | 6.0s |  |
| 282 | `bitmap_pool_layer_cap` | 1 | 19.8s |  |
| 283 | `broadcast_cross_swf_version` | 4 | 19.5s |  |
| 284 | `broadcast_type1_args` | 14 | 19.4s |  |
| 285 | `coerce_cross_swf_version` | 7 | 1.0s |  |
| 286 | `coerce_recursion_guard` | 1 | 0.9s |  |
| 287 | `coerce_type1_args` | 9 | 0.9s |  |
| 288 | `convertfloat_type1_this` | 3 | 0.9s |  |
| 289 | `ctor_before_first_call_locals` | 5 | 0.9s |  |
| 290 | `ei_closure_scope_order` | 7 | 1.0s |  |
| 291 | `ei_cross_swf_version` | 2 | 0.9s |  |
| 292 | `ei_mc_this_receiver` | 5 | 19.2s |  |
| 293 | `ei_type1_args` | 7 | 1.0s |  |
| 294 | `enterframe_type1_args` | 8 | 19.6s |  |
| 295 | `fn_call_builtin_type1_args` | 10 | 0.9s |  |
| 296 | `fn_call_type1_args` | 7 | 0.9s |  |
| 297 | `fn_empty_method_type1_args` | 10 | 0.9s |  |
| 298 | `group_alpha_cab` | 0 | 19.5s |  |
| 299 | `group_alpha_filter_cm` | 0 | 0.9s |  |
| 300 | `group_alpha_layer_aadd` | 0 | 0.9s |  |
| 301 | `group_alpha_layer_inner` | 0 | 0.9s |  |
| 302 | `group_alpha_multiply` | 0 | 0.2s |  |
| 303 | `group_alpha_shadow_shape_a50` | 0 | 0.9s |  |
| 304 | `layer_group_alpha_transparency` | 0 | 18.7s |  |
| 305 | `layer_group_filtered_child` | 0 | 18.9s |  |
| 306 | `layer_group_in_add_alpha` | 0 | 0.9s |  |
| 307 | `layer_group_overlap_alpha` | 0 | 0.9s |  |
| 308 | `layer_group_overlap_erase` | 0 | 0.2s |  |
| 309 | `lc_method_type1_args` | 7 | 0.9s |  |
| 310 | `lc_onstatus_type1_args` | 3 | 0.9s |  |
| 311 | `lowq_fill_edges` | 0 | 18.9s |  |
| 312 | `lowq_glyph_probe_df2` | 0 | 19.0s |  |
| 313 | `lowq_glyph_probe_df3` | 0 | 0.9s |  |
| 314 | `lowq_gradient_orient_probe` | 0 | 18.9s |  |
| 315 | `lowq_sample_point_probe` | 0 | 16.5s |  |
| 316 | `lowq_stroke_probe` | 0 | 15.9s |  |
| 317 | `lowq_tsnap_tie_probe` | 0 | 15.8s |  |
| 318 | `lv_cross_swf_version` | 5 | 15.8s |  |
| 319 | `lv_ondata_type1_args` | 3 | 16.1s |  |
| 320 | `mask_nested_intersect` | 1 | 16.1s |  |
| 321 | `mask_sibling_union` | 1 | 0.3s |  |
| 322 | `mc_event_cross_swf_version` | 4 | 0.3s |  |
| 323 | `mc_event_type1_args` | 3 | 15.9s |  |
| 324 | `mc_method_v5_caller_gate` | 4 | 0.3s |  |
| 325 | `mc_resolve_type1_args` | 6 | 0.3s |  |
| 326 | `method_type1_args` | 10 | 0.9s |  |
| 327 | `nc_onstatus_closure` | 2 | 0.9s |  |
| 328 | `nc_onstatus_type1_args` | 3 | 0.9s |  |
| 329 | `onconstruct_cross_swf_version` | 4 | 1.0s |  |
| 330 | `onconstruct_type1_args` | 6 | 0.9s |  |
| 331 | `onload_type1_args` | 7 | 1.0s |  |
| 332 | `onunload_type1_args` | 6 | 0.9s |  |
| 333 | `onunload_type1_local_frame` | 2 | 0.9s |  |
| 334 | `resolve_type1_args` | 13 | 0.9s |  |
| 335 | `root_enterframe_cross_swf_version` | 3 | 19.2s |  |
| 336 | `sort_comparator_captured_scope` | 2 | 1.0s |  |
| 337 | `sort_comparator_type1_args` | 5 | 19.6s |  |
| 338 | `string_prim_method_type1_args` | 19 | 0.9s |  |
| 339 | `timer_cross_swf_version` | 3 | 19.5s |  |
| 340 | `timer_type1_args` | 14 | 19.6s |  |
| 341 | `watch_cross_swf_version` | 6 | 1.0s |  |
| 342 | `watch_mc_reentrant_setmember` | 3 | 0.9s |  |
| 343 | `watch_mc_type1_args` | 7 | 0.9s |  |
| 344 | `watch_setmember_type1_args` | 7 | 0.9s |  |
| 345 | `watch_timeline_named_params` | 4 | 0.9s |  |
| 346 | `watch_timeline_reentrant` | 3 | 0.9s |  |
| 347 | `xml_onload_type1_args` | 3 | 19.7s |  |

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
