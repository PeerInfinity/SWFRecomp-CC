# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 18:23 UTC

**Git SHA**: `494d7c7e06`

**Run Duration**: 55m 31s

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
| 1 | `array_element_type1_args` | 7 | 0.9s |  |
| 2 | `array_method_type1_args` | 7 | 0.9s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 19.8s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.1s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.1s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.1s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.1s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.1s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.1s |  |
| 10 | `avm1_array_forin_proto_swf5` | 14 | 1.1s |  |
| 11 | `avm1_array_forin_proto_swf6` | 14 | 1.0s |  |
| 12 | `avm1_array_forin_proto_swf8` | 14 | 0.8s |  |
| 13 | `avm1_array_generic_receivers` | 16 | 24.5s |  |
| 14 | `avm1_array_native_own_method` | 8 | 1.2s |  |
| 15 | `avm1_asnative_mc_probe_swf5` | 8 | 1.3s |  |
| 16 | `avm1_asnative_mc_probe_swf6` | 8 | 0.4s |  |
| 17 | `avm1_attach_clipevent_enterframe` | 11 | 24.5s |  |
| 18 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.5s |  |
| 19 | `avm1_attach_timeline_frame_order` | 82 | 24.8s |  |
| 20 | `avm1_attached_clip_button_click` | 13 | 24.4s |  |
| 21 | `avm1_attached_clip_color` | 2 | 24.5s |  |
| 22 | `avm1_attached_clip_goto_play` | 14 | 1.7s |  |
| 23 | `avm1_attached_clip_goto_play_nonroot` | 14 | 0.7s |  |
| 24 | `avm1_attached_clip_hidden_capture` | 6 | 24.6s |  |
| 25 | `avm1_attached_clip_holder_render` | 1 | 20.5s |  |
| 26 | `avm1_attached_clip_natural_timeline` | 34 | 20.6s |  |
| 27 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.1s |  |
| 28 | `avm1_attached_clip_samename_child` | 32 | 20.4s |  |
| 29 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 20.3s |  |
| 30 | `avm1_attached_clip_selfgoto_trace` | 14 | 20.4s |  |
| 31 | `avm1_attached_clip_tagorder` | 34 | 1.1s |  |
| 32 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.2s |  |
| 33 | `avm1_attached_clip_tagorder_po3` | 34 | 1.1s |  |
| 34 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.1s |  |
| 35 | `avm1_attached_clip_timeline_child_parent` | 6 | 19.9s |  |
| 36 | `avm1_bare_depth_methods_v7_gate` | 6 | 1.0s |  |
| 37 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 24.9s |  |
| 38 | `avm1_bare_mc_method_scope` | 19 | 25.2s |  |
| 39 | `avm1_bitmap_nearest_tie_stage` | 1 | 24.8s |  |
| 40 | `avm1_bitmapdata_draw_child_color` | 5 | 25.0s |  |
| 41 | `avm1_bitmapdata_draw_edittext` | 3 | 1.5s |  |
| 42 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 24.9s |  |
| 43 | `avm1_browser_eager_init` | 10 | 25.3s |  |
| 44 | `avm1_browser_gated_color` | 3 | 1.2s |  |
| 45 | `avm1_browser_gated_depth` | 7 | 1.4s |  |
| 46 | `avm1_browser_gated_textfield` | 7 | 1.4s |  |
| 47 | `avm1_browser_parked_frame` | 7 | 25.2s |  |
| 48 | `avm1_button_pick_order` | 9 | 2.7s |  |
| 49 | `avm1_button_textfield_path_binding` | 4 | 24.7s |  |
| 50 | `avm1_child_timeline_advance` | 23 | 1.7s |  |
| 51 | `avm1_child_timeline_frame1_stop` | 7 | 1.6s |  |
| 52 | `avm1_child_timeline_holder_stop` | 26 | 1.7s |  |
| 53 | `avm1_child_timeline_loop` | 32 | 1.8s |  |
| 54 | `avm1_clipevent_root_goto_stopped` | 3 | 24.8s |  |
| 55 | `avm1_clone_depth_overflow` | 3 | 25.5s |  |
| 56 | `avm1_clone_depth_removed_reuse` | 4 | 1.4s |  |
| 57 | `avm1_closure_base_clip_root_frame` | 5 | 1.6s |  |
| 58 | `avm1_closure_method_scope` | 7 | 1.6s |  |
| 59 | `avm1_create_text_field_depth` | 9 | 1.5s |  |
| 60 | `avm1_cxform_override_overflow` | 2 | 24.9s |  |
| 61 | `avm1_definetext_matrix` | 0 | 1.2s |  |
| 62 | `avm1_device_edittext_xscale` | 7 | 20.8s |  |
| 63 | `avm1_display_filter_growth_edge_scale` | 0 | 21.4s |  |
| 64 | `avm1_display_prop_coercion` | 36 | 2.1s |  |
| 65 | `avm1_drawapi_stroke_snap` | 1 | 22.4s |  |
| 66 | `avm1_drawing_stroke_scale` | 0 | 23.7s |  |
| 67 | `avm1_dynclip_color_transform` | 2 | 1.5s |  |
| 68 | `avm1_edittext_border_subpixel` | 1 | 22.8s |  |
| 69 | `avm1_edittext_cut_copy_selection` | 9 | 23.5s |  |
| 70 | `avm1_edittext_html_delete_runs` | 4 | 22.1s |  |
| 71 | `avm1_edittext_html_typed_runs` | 3 | 1.5s |  |
| 72 | `avm1_edittext_maxchars_clips_insertion` | 4 | 1.3s |  |
| 73 | `avm1_edittext_path_variable_same_frame` | 11 | 21.1s |  |
| 74 | `avm1_edittext_path_variable_scope` | 10 | 21.4s |  |
| 75 | `avm1_edittext_placed_cxform` | 0 | 21.6s |  |
| 76 | `avm1_edittext_placed_cxform_script` | 3 | 1.3s |  |
| 77 | `avm1_edittext_restrict_onchanged` | 6 | 21.0s |  |
| 78 | `avm1_edittext_rotated_borders` | 0 | 20.5s |  |
| 79 | `avm1_edittext_rotated_color` | 0 | 1.2s |  |
| 80 | `avm1_edittext_rotated_glyphs` | 0 | 1.4s |  |
| 81 | `avm1_edittext_rotated_paragraph` | 0 | 20.8s |  |
| 82 | `avm1_edittext_scaled_glyphs` | 0 | 1.2s |  |
| 83 | `avm1_edittext_tab_render` | 1 | 21.3s |  |
| 84 | `avm1_edittext_tabstops_metric` | 9 | 21.4s |  |
| 85 | `avm1_edittext_wordwrap_render` | 5 | 24.6s |  |
| 86 | `avm1_empty_clip_drawing_depth_order` | 1 | 24.6s |  |
| 87 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 24.9s |  |
| 88 | `avm1_enterframe_root_goto_opcode` | 7 | 24.5s |  |
| 89 | `avm1_enterframe_root_nextframe` | 22 | 24.7s |  |
| 90 | `avm1_enterframe_sprite_nextframe` | 16 | 1.7s |  |
| 91 | `avm1_exec_order_attached_selfremove` | 18 | 25.0s |  |
| 92 | `avm1_exec_order_dynamic_eligible` | 35 | 1.9s |  |
| 93 | `avm1_exec_order_sibling_interleave` | 38 | 2.1s |  |
| 94 | `avm1_filter_list_overflow` | 2 | 24.6s |  |
| 95 | `avm1_func2_param_register_oob` | 4 | 1.4s |  |
| 96 | `avm1_gnash_flash_probes` | 63 | 1.9s |  |
| 97 | `avm1_gnash_flash_probes_v5` | 77 | 25.5s |  |
| 98 | `avm1_gnash_flash_probes_v6` | 63 | 0.5s |  |
| 99 | `avm1_goto_backward_enterframe_once` | 22 | 24.7s |  |
| 100 | `avm1_goto_current_frame_clip` | 23 | 25.4s |  |
| 101 | `avm1_goto_current_frame_root` | 22 | 24.5s |  |
| 102 | `avm1_goto_skipped_init_call` | 6 | 24.5s |  |
| 103 | `avm1_goto_skipped_init_script` | 5 | 1.6s |  |
| 104 | `avm1_goto_skipped_init_timer` | 6 | 1.6s |  |
| 105 | `avm1_goto_target_child_order_gotoscript` | 6 | 1.6s |  |
| 106 | `avm1_goto_target_child_order_interval` | 7 | 1.6s |  |
| 107 | `avm1_goto_target_child_order_normal` | 5 | 24.4s |  |
| 108 | `avm1_hairline_scaled_instances` | 1 | 1.6s |  |
| 109 | `avm1_hittest_hairline` | 28 | 19.4s |  |
| 110 | `avm1_hittest_shape_stale_matrix` | 28 | 19.6s |  |
| 111 | `avm1_holder_drawing_under_children` | 1 | 19.3s |  |
| 112 | `avm1_jpeg3_alpha_bitmap` | 0 | 19.3s |  |
| 113 | `avm1_key_isdown_protected` | 8 | 19.4s |  |
| 114 | `avm1_loaded_bare_goto` | 17 | 19.9s |  |
| 115 | `avm1_loaded_bare_goto_seq` | 4 | 1.4s |  |
| 116 | `avm1_loaded_goto_play_deferred` | 31 | 19.7s |  |
| 117 | `avm1_loaded_order_create_vs_load` | 33 | 1.4s |  |
| 118 | `avm1_loaded_shell_consumers_seq` | 12 | 19.5s |  |
| 119 | `avm1_loaded_shell_root_lookup` | 4 | 19.4s |  |
| 120 | `avm1_loaded_timeline_holder` | 7 | 1.1s |  |
| 121 | `avm1_loaded_unload_deferred` | 5 | 16.8s |  |
| 122 | `avm1_loadvars_ondata_overflow` | 23 | 1.2s |  |
| 123 | `avm1_long_text_layout` | 2 | 16.4s |  |
| 124 | `avm1_many_chars_registry` | 4 | 16.9s |  |
| 125 | `avm1_many_defs_registry` | 13 | 17.8s |  |
| 126 | `avm1_many_functions_registry` | 3 | 7.0s |  |
| 127 | `avm1_mc_button_unified_pick` | 21 | 16.3s |  |
| 128 | `avm1_mc_resolve` | 5 | 1.0s |  |
| 129 | `avm1_mc_super_native_probe` | 18 | 1.3s |  |
| 130 | `avm1_mcl_holder_totalframes` | 5 | 1.2s |  |
| 131 | `avm1_mcl_load_tick` | 15 | 1.1s |  |
| 132 | `avm1_morph_instances_ratio` | 2 | 16.6s |  |
| 133 | `avm1_native_identity_probe_swf5` | 43 | 1.1s |  |
| 134 | `avm1_native_identity_probe_swf6` | 43 | 0.3s |  |
| 135 | `avm1_native_identity_probe_swf7` | 43 | 0.3s |  |
| 136 | `avm1_native_identity_probe_swf8` | 43 | 0.3s |  |
| 137 | `avm1_native_instance_layout` | 12 | 0.9s |  |
| 138 | `avm1_nested_child_swapdepths_remove` | 8 | 19.7s |  |
| 139 | `avm1_nested_po3_filters` | 12 | 1.1s |  |
| 140 | `avm1_onunload_setvar_scope` | 5 | 1.1s |  |
| 141 | `avm1_parent_as3_child_payload` | 2 | 1.1s |  |
| 142 | `avm1_parent_child_bitmap` | 5 | 1.1s |  |
| 143 | `avm1_parent_child_bitmap_fill` | 3 | 1.2s |  |
| 144 | `avm1_parent_child_modify_place` | 5 | 1.1s |  |
| 145 | `avm1_parent_child_morph` | 8 | 1.4s |  |
| 146 | `avm1_parent_child_render` | 7 | 1.3s |  |
| 147 | `avm1_parent_child_sprite_meta` | 8 | 1.4s |  |
| 148 | `avm1_parent_child_text` | 8 | 1.4s |  |
| 149 | `avm1_pixelbounds_dynamic_child` | 1 | 17.0s |  |
| 150 | `avm1_place_occupied_depth_swf5` | 6 | 1.1s |  |
| 151 | `avm1_placed_drawing_color` | 1 | 17.2s |  |
| 152 | `avm1_po3_cm_alpha_bias_edge` | 0 | 16.7s |  |
| 153 | `avm1_po3_cm_folded_clear` | 1 | 1.1s |  |
| 154 | `avm1_po3_cm_live_under_cxform` | 0 | 1.0s |  |
| 155 | `avm1_po3_color_matrix_live` | 0 | 1.0s |  |
| 156 | `avm1_po3_color_matrix_live_clear` | 1 | 1.0s |  |
| 157 | `avm1_po3_color_matrix_live_nested` | 0 | 20.1s |  |
| 158 | `avm1_remove_same_name_other_parent` | 4 | 20.1s |  |
| 159 | `avm1_remove_unload_finalize_overflow` | 4 | 3.3s |  |
| 160 | `avm1_removed_clip_dprops_gc` | 14 | 1.1s |  |
| 161 | `avm1_resolve_dotted_getvariable` | 13 | 1.0s |  |
| 162 | `avm1_root_identity_and_playhead` | 3 | 19.6s |  |
| 163 | `avm1_root_onload_child_order` | 11 | 19.8s |  |
| 164 | `avm1_root_onload_proto` | 7 | 1.1s |  |
| 165 | `avm1_rotation_matrix_fixed` | 7 | 1.1s |  |
| 166 | `avm1_runtime_filters` | 3 | 19.6s |  |
| 167 | `avm1_runtime_filters_cm_bitmap` | 5 | 1.1s |  |
| 168 | `avm1_selfgoto_current_frame_opcode` | 8 | 19.6s |  |
| 169 | `avm1_set_new_text_format_color` | 4 | 19.4s |  |
| 170 | `avm1_set_new_text_format_instance` | 5 | 19.4s |  |
| 171 | `avm1_set_new_text_format_paragraph` | 12 | 1.1s |  |
| 172 | `avm1_set_new_text_format_render` | 5 | 19.2s |  |
| 173 | `avm1_set_new_text_format_size` | 5 | 0.9s |  |
| 174 | `avm1_sprite_goto_script_overflow` | 65 | 1.3s |  |
| 175 | `avm1_stroke_hinting_caps` | 1 | 1.1s |  |
| 176 | `avm1_stroke_join_cap_snap` | 0 | 21.3s |  |
| 177 | `avm1_stroke_noscale_signed` | 0 | 19.5s |  |
| 178 | `avm1_stroke_pixel_snap` | 1 | 19.5s |  |
| 179 | `avm1_stroke_pixel_snap_matrix` | 0 | 20.0s |  |
| 180 | `avm1_stroke_seam_caps` | 1 | 19.7s |  |
| 181 | `avm1_stroke_style_id_order` | 1 | 21.7s |  |
| 182 | `avm1_swapdepths_remove_clipevent_unload` | 13 | 21.9s |  |
| 183 | `avm1_swf6_case_insensitive_builtins` | 42 | 1.4s |  |
| 184 | `avm1_swf7_case_sensitive_builtins` | 40 | 0.4s |  |
| 185 | `avm1_tabindex_child_null` | 3 | 1.1s |  |
| 186 | `avm1_tabindex_clip_button_v6` | 28 | 1.2s |  |
| 187 | `avm1_tabindex_clip_button_v8` | 28 | 1.0s |  |
| 188 | `avm1_tabindex_fn2_root_raw` | 4 | 1.1s |  |
| 189 | `avm1_tabindex_fresh_child_coerce` | 4 | 1.1s |  |
| 190 | `avm1_tabindex_mtasc_class_main` | 6 | 21.6s |  |
| 191 | `avm1_tabindex_read_first_coerce` | 5 | 1.0s |  |
| 192 | `avm1_tabindex_textfield_v6` | 13 | 1.2s |  |
| 193 | `avm1_tabindex_textfield_v8` | 13 | 1.0s |  |
| 194 | `avm1_textfield_attached_depth_order` | 1 | 18.6s |  |
| 195 | `avm1_textfield_ctor_shadow_swf6` | 2 | 0.9s |  |
| 196 | `avm1_textfield_ctor_shadow_swf7` | 2 | 0.3s |  |
| 197 | `avm1_textfield_x_bounds_offset` | 10 | 18.6s |  |
| 198 | `avm1_timeline_selfgoto_child_replace` | 27 | 18.9s |  |
| 199 | `avm1_timer_clock_model` | 12 | 18.9s |  |
| 200 | `avm1_timer_function_form_activation` | 3 | 18.7s |  |
| 201 | `avm1_timer_late_frame_check` | 29 | 19.1s |  |
| 202 | `avm1_timer_method_form` | 6 | 1.0s |  |
| 203 | `avm1_timer_native_method_play` | 3 | 0.9s |  |
| 204 | `avm1_timer_overflow` | 10 | 1.4s |  |
| 205 | `avm1_timer_root_goto_stopped_gs` | 3 | 1.0s |  |
| 206 | `avm1_timer_root_goto_stopped_nf` | 3 | 0.9s |  |
| 207 | `avm1_type2_mc_receiver_dispatch` | 7 | 19.3s |  |
| 208 | `avm1_watch_long_name` | 9 | 0.9s |  |
| 209 | `avm1_watch_overflow` | 2 | 1.5s |  |
| 210 | `avm1_wrap_giveup_mixed_runs` | 2 | 0.9s |  |
| 211 | `avm1_xml_first_action_proto` | 2 | 0.9s |  |
| 212 | `avm1_xmlnode_first_action_proto` | 2 | 0.8s |  |
| 213 | `avm1_xscale_double_readback` | 8 | 1.0s |  |
| 214 | `avm2_activation_vtable_bounded` | 5 | 6.5s |  |
| 215 | `avm2_agi_shell` | 6 | 1.7s |  |
| 216 | `avm2_applyfilter_bevel_sample` | 441 | 18.3s |  |
| 217 | `avm2_applyfilter_glow_kernels` | 23 | 6.8s |  |
| 218 | `avm2_applyfilter_gradient_opaque` | 26 | 7.6s |  |
| 219 | `avm2_array_growth_bounded` | 5 | 7.4s |  |
| 220 | `avm2_bitmapdata_draw_edittext_box` | 5 | 6.6s |  |
| 221 | `avm2_bitmapdata_draw_filtered` | 13 | 6.7s |  |
| 222 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 7.3s |  |
| 223 | `avm2_bitmapdata_draw_textfield` | 5 | 7.0s |  |
| 224 | `avm2_bitmapdata_palettemap_index` | 5 | 21.0s |  |
| 225 | `avm2_child_simplebutton` | 10 | 25.8s |  |
| 226 | `avm2_contextmenu_stub` | 4 | 6.6s |  |
| 227 | `avm2_definetext_matrix` | 0 | 20.3s |  |
| 228 | `avm2_drawapi_stroke_snap` | 1 | 20.8s |  |
| 229 | `avm2_e4x_parse_bounded` | 18 | 6.4s |  |
| 230 | `avm2_edittext_placed_cxform` | 0 | 21.1s |  |
| 231 | `avm2_edittext_selection_cxform` | 2 | 20.7s |  |
| 232 | `avm2_embed_bytearray` | 2 | 5.4s |  |
| 233 | `avm2_external_interface_unavailable` | 8 | 5.3s |  |
| 234 | `avm2_findprop_this_resolution` | 13 | 1.8s |  |
| 235 | `avm2_gc_dynprop_tombstone_purge` | 8 | 5.4s |  |
| 236 | `avm2_gc_string_concat_reclaim` | 10 | 5.4s |  |
| 237 | `avm2_gc_string_survives_collect` | 9 | 5.4s |  |
| 238 | `avm2_goto_catchup_scale` | 4 | 5.8s |  |
| 239 | `avm2_graphics_runtime` | 7 | 23.2s |  |
| 240 | `avm2_group_alpha_cab` | 0 | 23.4s |  |
| 241 | `avm2_group_alpha_filter_cm` | 0 | 5.9s |  |
| 242 | `avm2_group_alpha_layer_aadd` | 0 | 6.4s |  |
| 243 | `avm2_group_alpha_layer_inner` | 0 | 5.7s |  |
| 244 | `avm2_group_alpha_multiply` | 0 | 0.4s |  |
| 245 | `avm2_group_alpha_shadow_shape_a50` | 0 | 5.7s |  |
| 246 | `avm2_html_img_loadcount` | 39 | 5.9s |  |
| 247 | `avm2_json_roundtrip_bounded` | 13 | 6.6s |  |
| 248 | `avm2_layer_group_alpha` | 0 | 6.0s |  |
| 249 | `avm2_layer_group_alpha_transparency` | 0 | 25.4s |  |
| 250 | `avm2_layer_group_erase` | 0 | 6.4s |  |
| 251 | `avm2_layer_group_filtered_child` | 0 | 25.1s |  |
| 252 | `avm2_layer_group_overlap_alpha` | 0 | 6.1s |  |
| 253 | `avm2_loader_stub` | 5 | 6.1s |  |
| 254 | `avm2_localconnection_domain` | 4 | 6.1s |  |
| 255 | `avm2_mask_removal_script` | 6 | 25.4s |  |
| 256 | `avm2_morph` | 8 | 25.5s |  |
| 257 | `avm2_parent_child_render` | 11 | 8.3s |  |
| 258 | `avm2_parent_child_static_text` | 12 | 6.4s |  |
| 259 | `avm2_parent_child_symbol_stride` | 6 | 7.4s |  |
| 260 | `avm2_parent_child_symbolclass_domain` | 12 | 33.9s |  |
| 261 | `avm2_pixelbounds_offlist` | 13 | 32.6s |  |
| 262 | `avm2_reflect_trait_hooks` | 30 | 8.8s |  |
| 263 | `avm2_sharedobject_flushstatus` | 4 | 8.4s |  |
| 264 | `avm2_simplebutton_click` | 2 | 8.5s |  |
| 265 | `avm2_slot_default_template` | 34 | 8.7s |  |
| 266 | `avm2_sound_bytes_and_group_format` | 27 | 8.8s |  |
| 267 | `avm2_static_and_store_slots` | 14 | 8.6s |  |
| 268 | `avm2_static_text` | 6 | 32.5s |  |
| 269 | `avm2_strbuf_stale_prefix` | 21 | 8.4s |  |
| 270 | `avm2_stroke_curve_scale_s16_w16_k0` | 2 | 32.6s |  |
| 271 | `avm2_stroke_curve_scale_s16_w16_k1` | 2 | 28.0s |  |
| 272 | `avm2_stroke_curve_scale_s16_w4_k0` | 2 | 23.5s |  |
| 273 | `avm2_stroke_curve_scale_s16_w4_k1` | 2 | 0.7s |  |
| 274 | `avm2_stroke_curve_scale_s1s4` | 17 | 28.2s |  |
| 275 | `avm2_stroke_translucent_round` | 1 | 28.6s |  |
| 276 | `avm2_timeline_gradients` | 7 | 29.7s |  |
| 277 | `avm2_timeline_solid` | 6 | 8.2s |  |
| 278 | `avm2_timeline_stroke_gradient` | 9 | 8.5s |  |
| 279 | `avm2_timeline_text` | 4 | 7.7s |  |
| 280 | `avm2_tolerant_verify_quarantine` | 2 | 7.2s |  |
| 281 | `avm2_typed_value_ops` | 30 | 7.1s |  |
| 282 | `bitmap_pool_layer_cap` | 1 | 26.3s |  |
| 283 | `broadcast_cross_swf_version` | 4 | 1.7s |  |
| 284 | `broadcast_type1_args` | 14 | 1.5s |  |
| 285 | `coerce_cross_swf_version` | 7 | 1.7s |  |
| 286 | `coerce_recursion_guard` | 1 | 1.5s |  |
| 287 | `coerce_type1_args` | 9 | 1.5s |  |
| 288 | `convertfloat_type1_this` | 3 | 1.5s |  |
| 289 | `ctor_before_first_call_locals` | 5 | 1.5s |  |
| 290 | `ei_closure_scope_order` | 7 | 1.6s |  |
| 291 | `ei_cross_swf_version` | 2 | 1.5s |  |
| 292 | `ei_mc_this_receiver` | 5 | 25.7s |  |
| 293 | `ei_type1_args` | 7 | 1.4s |  |
| 294 | `enterframe_type1_args` | 8 | 19.7s |  |
| 295 | `fn_call_builtin_type1_args` | 10 | 1.1s |  |
| 296 | `fn_call_type1_args` | 7 | 1.1s |  |
| 297 | `fn_empty_method_type1_args` | 10 | 1.1s |  |
| 298 | `group_alpha_cab` | 0 | 19.5s |  |
| 299 | `group_alpha_filter_cm` | 0 | 1.2s |  |
| 300 | `group_alpha_layer_aadd` | 0 | 1.1s |  |
| 301 | `group_alpha_layer_inner` | 0 | 1.1s |  |
| 302 | `group_alpha_multiply` | 0 | 0.3s |  |
| 303 | `group_alpha_shadow_shape_a50` | 0 | 1.2s |  |
| 304 | `layer_group_alpha_transparency` | 0 | 19.3s |  |
| 305 | `layer_group_filtered_child` | 0 | 19.1s |  |
| 306 | `layer_group_in_add_alpha` | 0 | 0.9s |  |
| 307 | `layer_group_overlap_alpha` | 0 | 0.9s |  |
| 308 | `layer_group_overlap_erase` | 0 | 0.2s |  |
| 309 | `lc_method_type1_args` | 7 | 0.9s |  |
| 310 | `lc_onstatus_type1_args` | 3 | 0.9s |  |
| 311 | `lowq_fill_edges` | 0 | 19.0s |  |
| 312 | `lowq_glyph_probe_df2` | 0 | 19.2s |  |
| 313 | `lowq_glyph_probe_df3` | 0 | 1.0s |  |
| 314 | `lowq_gradient_orient_probe` | 0 | 19.2s |  |
| 315 | `lowq_sample_point_probe` | 0 | 0.5s |  |
| 316 | `lowq_stroke_probe` | 0 | 0.5s |  |
| 317 | `lowq_tsnap_tie_probe` | 0 | 0.5s |  |
| 318 | `lv_cross_swf_version` | 5 | 0.6s |  |
| 319 | `lv_ondata_type1_args` | 3 | 0.5s |  |
| 320 | `mask_nested_intersect` | 1 | 0.5s |  |
| 321 | `mask_sibling_union` | 1 | 0.5s |  |
| 322 | `mc_event_cross_swf_version` | 4 | 0.6s |  |
| 323 | `mc_event_type1_args` | 3 | 0.5s |  |
| 324 | `mc_method_v5_caller_gate` | 4 | 0.6s |  |
| 325 | `mc_resolve_type1_args` | 6 | 0.5s |  |
| 326 | `method_type1_args` | 10 | 0.9s |  |
| 327 | `nc_onstatus_closure` | 2 | 0.9s |  |
| 328 | `nc_onstatus_type1_args` | 3 | 0.9s |  |
| 329 | `onconstruct_cross_swf_version` | 4 | 1.0s |  |
| 330 | `onconstruct_type1_args` | 6 | 0.9s |  |
| 331 | `onload_type1_args` | 7 | 0.9s |  |
| 332 | `onunload_type1_args` | 6 | 0.9s |  |
| 333 | `onunload_type1_local_frame` | 2 | 0.9s |  |
| 334 | `resolve_type1_args` | 13 | 0.9s |  |
| 335 | `root_enterframe_cross_swf_version` | 3 | 19.4s |  |
| 336 | `sort_comparator_captured_scope` | 2 | 1.0s |  |
| 337 | `sort_comparator_type1_args` | 5 | 0.9s |  |
| 338 | `string_prim_method_type1_args` | 19 | 0.9s |  |
| 339 | `timer_cross_swf_version` | 3 | 1.1s |  |
| 340 | `timer_type1_args` | 14 | 19.0s |  |
| 341 | `watch_cross_swf_version` | 6 | 1.0s |  |
| 342 | `watch_mc_reentrant_setmember` | 3 | 0.9s |  |
| 343 | `watch_mc_type1_args` | 7 | 0.9s |  |
| 344 | `watch_setmember_type1_args` | 7 | 0.9s |  |
| 345 | `watch_timeline_named_params` | 4 | 0.9s |  |
| 346 | `watch_timeline_reentrant` | 3 | 0.9s |  |
| 347 | `xml_onload_type1_args` | 3 | 0.9s |  |

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
