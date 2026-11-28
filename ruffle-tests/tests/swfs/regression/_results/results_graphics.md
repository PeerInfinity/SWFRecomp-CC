# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 17:54 UTC

**Git SHA**: `d387fcee5b`

**Run Duration**: 61m 35s

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
| 1 | `array_element_type1_args` | 7 | 1.6s |  |
| 2 | `array_method_type1_args` | 7 | 1.5s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 20.2s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.8s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.8s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.7s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.8s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.7s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.7s |  |
| 10 | `avm1_array_forin_proto_swf5` | 14 | 1.7s |  |
| 11 | `avm1_array_forin_proto_swf6` | 14 | 1.6s |  |
| 12 | `avm1_array_forin_proto_swf8` | 14 | 1.5s |  |
| 13 | `avm1_array_generic_receivers` | 16 | 26.2s |  |
| 14 | `avm1_array_native_own_method` | 8 | 2.4s |  |
| 15 | `avm1_asnative_mc_probe_swf5` | 8 | 2.5s |  |
| 16 | `avm1_asnative_mc_probe_swf6` | 8 | 1.4s |  |
| 17 | `avm1_attach_clipevent_enterframe` | 11 | 26.3s |  |
| 18 | `avm1_attach_from_stopped_root_enterframe` | 13 | 2.8s |  |
| 19 | `avm1_attach_timeline_frame_order` | 82 | 27.4s |  |
| 20 | `avm1_attached_clip_button_click` | 13 | 26.1s |  |
| 21 | `avm1_attached_clip_color` | 2 | 26.1s |  |
| 22 | `avm1_attached_clip_goto_play` | 14 | 3.0s |  |
| 23 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.8s |  |
| 24 | `avm1_attached_clip_hidden_capture` | 6 | 26.5s |  |
| 25 | `avm1_attached_clip_holder_render` | 1 | 26.8s |  |
| 26 | `avm1_attached_clip_natural_timeline` | 34 | 27.1s |  |
| 27 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 2.7s |  |
| 28 | `avm1_attached_clip_samename_child` | 32 | 27.1s |  |
| 29 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 26.9s |  |
| 30 | `avm1_attached_clip_selfgoto_trace` | 14 | 27.4s |  |
| 31 | `avm1_attached_clip_tagorder` | 34 | 2.7s |  |
| 32 | `avm1_attached_clip_tagorder_nonroot` | 34 | 1.2s |  |
| 33 | `avm1_attached_clip_tagorder_po3` | 34 | 2.6s |  |
| 34 | `avm1_attached_clip_tagorder_ratio` | 34 | 2.7s |  |
| 35 | `avm1_attached_clip_timeline_child_parent` | 6 | 27.1s |  |
| 36 | `avm1_bare_depth_methods_v7_gate` | 6 | 2.5s |  |
| 37 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 20.7s |  |
| 38 | `avm1_bare_mc_method_scope` | 19 | 20.9s |  |
| 39 | `avm1_bitmap_nearest_tie_stage` | 1 | 18.1s |  |
| 40 | `avm1_bitmapdata_draw_child_color` | 5 | 18.0s |  |
| 41 | `avm1_bitmapdata_draw_edittext` | 3 | 1.9s |  |
| 42 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 19.0s |  |
| 43 | `avm1_browser_eager_init` | 10 | 18.4s |  |
| 44 | `avm1_browser_gated_color` | 3 | 2.0s |  |
| 45 | `avm1_browser_gated_depth` | 7 | 2.3s |  |
| 46 | `avm1_browser_gated_textfield` | 7 | 1.9s |  |
| 47 | `avm1_browser_parked_frame` | 7 | 17.4s |  |
| 48 | `avm1_button_pick_order` | 9 | 2.7s |  |
| 49 | `avm1_button_textfield_path_binding` | 4 | 20.9s |  |
| 50 | `avm1_child_timeline_advance` | 23 | 1.9s |  |
| 51 | `avm1_child_timeline_frame1_stop` | 7 | 1.9s |  |
| 52 | `avm1_child_timeline_holder_stop` | 26 | 1.9s |  |
| 53 | `avm1_child_timeline_loop` | 32 | 2.0s |  |
| 54 | `avm1_clipevent_root_goto_stopped` | 3 | 20.9s |  |
| 55 | `avm1_clone_depth_overflow` | 3 | 21.5s |  |
| 56 | `avm1_clone_depth_removed_reuse` | 4 | 1.7s |  |
| 57 | `avm1_closure_base_clip_root_frame` | 5 | 1.9s |  |
| 58 | `avm1_closure_method_scope` | 7 | 1.9s |  |
| 59 | `avm1_create_text_field_depth` | 9 | 1.8s |  |
| 60 | `avm1_cxform_override_overflow` | 2 | 21.1s |  |
| 61 | `avm1_definetext_matrix` | 0 | 1.7s |  |
| 62 | `avm1_device_edittext_xscale` | 7 | 20.0s |  |
| 63 | `avm1_display_filter_growth_edge_scale` | 0 | 20.5s |  |
| 64 | `avm1_display_prop_coercion` | 36 | 1.8s |  |
| 65 | `avm1_drawapi_stroke_snap` | 1 | 20.0s |  |
| 66 | `avm1_drawing_stroke_scale` | 0 | 21.5s |  |
| 67 | `avm1_dynclip_color_transform` | 2 | 2.0s |  |
| 68 | `avm1_edittext_border_subpixel` | 1 | 20.1s |  |
| 69 | `avm1_edittext_cut_copy_selection` | 9 | 20.1s |  |
| 70 | `avm1_edittext_html_delete_runs` | 4 | 20.2s |  |
| 71 | `avm1_edittext_html_typed_runs` | 3 | 1.8s |  |
| 72 | `avm1_edittext_maxchars_clips_insertion` | 4 | 1.7s |  |
| 73 | `avm1_edittext_path_variable_same_frame` | 11 | 20.2s |  |
| 74 | `avm1_edittext_path_variable_scope` | 10 | 20.1s |  |
| 75 | `avm1_edittext_placed_cxform` | 0 | 20.1s |  |
| 76 | `avm1_edittext_placed_cxform_script` | 3 | 1.6s |  |
| 77 | `avm1_edittext_restrict_onchanged` | 6 | 19.9s |  |
| 78 | `avm1_edittext_rotated_borders` | 0 | 19.8s |  |
| 79 | `avm1_edittext_rotated_color` | 0 | 1.6s |  |
| 80 | `avm1_edittext_rotated_glyphs` | 0 | 1.7s |  |
| 81 | `avm1_edittext_rotated_paragraph` | 0 | 20.1s |  |
| 82 | `avm1_edittext_scaled_glyphs` | 0 | 1.6s |  |
| 83 | `avm1_edittext_tab_render` | 1 | 20.5s |  |
| 84 | `avm1_edittext_tabstops_metric` | 9 | 20.5s |  |
| 85 | `avm1_edittext_wordwrap_render` | 5 | 19.6s |  |
| 86 | `avm1_empty_clip_drawing_depth_order` | 1 | 20.0s |  |
| 87 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 19.9s |  |
| 88 | `avm1_enterframe_root_goto_opcode` | 7 | 19.6s |  |
| 89 | `avm1_enterframe_root_nextframe` | 22 | 19.7s |  |
| 90 | `avm1_enterframe_sprite_nextframe` | 16 | 1.7s |  |
| 91 | `avm1_exec_order_attached_selfremove` | 18 | 19.8s |  |
| 92 | `avm1_exec_order_dynamic_eligible` | 35 | 1.8s |  |
| 93 | `avm1_exec_order_sibling_interleave` | 38 | 1.9s |  |
| 94 | `avm1_filter_list_overflow` | 2 | 19.7s |  |
| 95 | `avm1_func2_param_register_oob` | 4 | 1.6s |  |
| 96 | `avm1_gnash_flash_probes` | 63 | 2.0s |  |
| 97 | `avm1_gnash_flash_probes_v5` | 77 | 20.5s |  |
| 98 | `avm1_gnash_flash_probes_v6` | 63 | 0.9s |  |
| 99 | `avm1_goto_backward_enterframe_once` | 22 | 20.2s |  |
| 100 | `avm1_goto_current_frame_clip` | 23 | 20.7s |  |
| 101 | `avm1_goto_current_frame_root` | 22 | 20.4s |  |
| 102 | `avm1_goto_skipped_init_call` | 6 | 20.5s |  |
| 103 | `avm1_goto_skipped_init_script` | 5 | 1.8s |  |
| 104 | `avm1_goto_skipped_init_timer` | 6 | 1.8s |  |
| 105 | `avm1_goto_target_child_order_gotoscript` | 6 | 1.8s |  |
| 106 | `avm1_goto_target_child_order_interval` | 7 | 1.8s |  |
| 107 | `avm1_goto_target_child_order_normal` | 5 | 20.4s |  |
| 108 | `avm1_hairline_scaled_instances` | 1 | 1.8s |  |
| 109 | `avm1_hittest_hairline` | 28 | 20.6s |  |
| 110 | `avm1_hittest_shape_stale_matrix` | 28 | 20.6s |  |
| 111 | `avm1_holder_drawing_under_children` | 1 | 20.4s |  |
| 112 | `avm1_jpeg3_alpha_bitmap` | 0 | 20.2s |  |
| 113 | `avm1_key_isdown_protected` | 8 | 20.2s |  |
| 114 | `avm1_loaded_bare_goto` | 17 | 20.7s |  |
| 115 | `avm1_loaded_bare_goto_seq` | 4 | 2.1s |  |
| 116 | `avm1_loaded_goto_play_deferred` | 31 | 20.5s |  |
| 117 | `avm1_loaded_order_create_vs_load` | 33 | 2.2s |  |
| 118 | `avm1_loaded_shell_consumers_seq` | 12 | 20.8s |  |
| 119 | `avm1_loaded_shell_root_lookup` | 4 | 20.4s |  |
| 120 | `avm1_loaded_timeline_holder` | 7 | 1.8s |  |
| 121 | `avm1_loaded_unload_deferred` | 5 | 21.7s |  |
| 122 | `avm1_loadvars_ondata_overflow` | 23 | 2.4s |  |
| 123 | `avm1_long_text_layout` | 2 | 21.4s |  |
| 124 | `avm1_many_chars_registry` | 4 | 22.4s |  |
| 125 | `avm1_many_defs_registry` | 13 | 24.7s |  |
| 126 | `avm1_many_functions_registry` | 3 | 10.2s |  |
| 127 | `avm1_mc_button_unified_pick` | 21 | 23.2s |  |
| 128 | `avm1_mc_resolve` | 5 | 2.2s |  |
| 129 | `avm1_mc_super_native_probe` | 18 | 2.7s |  |
| 130 | `avm1_mcl_holder_totalframes` | 5 | 2.6s |  |
| 131 | `avm1_mcl_load_tick` | 15 | 2.5s |  |
| 132 | `avm1_morph_instances_ratio` | 2 | 23.8s |  |
| 133 | `avm1_native_identity_probe_swf5` | 43 | 1.8s |  |
| 134 | `avm1_native_identity_probe_swf6` | 43 | 0.9s |  |
| 135 | `avm1_native_identity_probe_swf7` | 43 | 0.9s |  |
| 136 | `avm1_native_identity_probe_swf8` | 43 | 0.9s |  |
| 137 | `avm1_native_instance_layout` | 12 | 1.6s |  |
| 138 | `avm1_nested_child_swapdepths_remove` | 8 | 20.0s |  |
| 139 | `avm1_nested_po3_filters` | 12 | 2.3s |  |
| 140 | `avm1_onunload_setvar_scope` | 5 | 1.7s |  |
| 141 | `avm1_parent_as3_child_payload` | 2 | 1.8s |  |
| 142 | `avm1_parent_child_bitmap` | 5 | 1.8s |  |
| 143 | `avm1_parent_child_bitmap_fill` | 3 | 1.9s |  |
| 144 | `avm1_parent_child_modify_place` | 5 | 1.8s |  |
| 145 | `avm1_parent_child_morph` | 8 | 2.7s |  |
| 146 | `avm1_parent_child_render` | 7 | 2.6s |  |
| 147 | `avm1_parent_child_sprite_meta` | 8 | 2.6s |  |
| 148 | `avm1_parent_child_text` | 8 | 2.6s |  |
| 149 | `avm1_pixelbounds_dynamic_child` | 1 | 25.4s |  |
| 150 | `avm1_place_occupied_depth_swf5` | 6 | 2.3s |  |
| 151 | `avm1_placed_drawing_color` | 1 | 25.9s |  |
| 152 | `avm1_po3_cm_alpha_bias_edge` | 0 | 25.6s |  |
| 153 | `avm1_po3_cm_folded_clear` | 1 | 2.3s |  |
| 154 | `avm1_po3_cm_live_under_cxform` | 0 | 2.3s |  |
| 155 | `avm1_po3_color_matrix_live` | 0 | 2.4s |  |
| 156 | `avm1_po3_color_matrix_live_clear` | 1 | 2.4s |  |
| 157 | `avm1_po3_color_matrix_live_nested` | 0 | 19.9s |  |
| 158 | `avm1_remove_same_name_other_parent` | 4 | 20.2s |  |
| 159 | `avm1_remove_unload_finalize_overflow` | 4 | 3.9s |  |
| 160 | `avm1_removed_clip_dprops_gc` | 14 | 1.9s |  |
| 161 | `avm1_resolve_dotted_getvariable` | 13 | 1.7s |  |
| 162 | `avm1_root_identity_and_playhead` | 3 | 20.1s |  |
| 163 | `avm1_root_onload_child_order` | 11 | 20.1s |  |
| 164 | `avm1_root_onload_proto` | 7 | 1.8s |  |
| 165 | `avm1_rotation_matrix_fixed` | 7 | 1.7s |  |
| 166 | `avm1_runtime_filters` | 3 | 20.4s |  |
| 167 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.0s |  |
| 168 | `avm1_selfgoto_current_frame_opcode` | 8 | 19.9s |  |
| 169 | `avm1_set_new_text_format_color` | 4 | 21.6s |  |
| 170 | `avm1_set_new_text_format_instance` | 5 | 21.5s |  |
| 171 | `avm1_set_new_text_format_paragraph` | 12 | 2.0s |  |
| 172 | `avm1_set_new_text_format_render` | 5 | 21.9s |  |
| 173 | `avm1_set_new_text_format_size` | 5 | 1.7s |  |
| 174 | `avm1_sprite_goto_script_overflow` | 65 | 2.2s |  |
| 175 | `avm1_stroke_hinting_caps` | 1 | 2.1s |  |
| 176 | `avm1_stroke_join_cap_snap` | 0 | 23.7s |  |
| 177 | `avm1_stroke_noscale_signed` | 0 | 22.0s |  |
| 178 | `avm1_stroke_pixel_snap` | 1 | 21.3s |  |
| 179 | `avm1_stroke_pixel_snap_matrix` | 0 | 21.5s |  |
| 180 | `avm1_stroke_seam_caps` | 1 | 21.6s |  |
| 181 | `avm1_stroke_style_id_order` | 1 | 26.0s |  |
| 182 | `avm1_swapdepths_remove_clipevent_unload` | 13 | 26.1s |  |
| 183 | `avm1_swf6_case_insensitive_builtins` | 42 | 2.9s |  |
| 184 | `avm1_swf7_case_sensitive_builtins` | 40 | 1.3s |  |
| 185 | `avm1_tabindex_child_null` | 3 | 2.3s |  |
| 186 | `avm1_tabindex_clip_button_v6` | 28 | 2.4s |  |
| 187 | `avm1_tabindex_clip_button_v8` | 28 | 2.2s |  |
| 188 | `avm1_tabindex_fn2_root_raw` | 4 | 2.3s |  |
| 189 | `avm1_tabindex_fresh_child_coerce` | 4 | 2.2s |  |
| 190 | `avm1_tabindex_mtasc_class_main` | 6 | 25.9s |  |
| 191 | `avm1_tabindex_read_first_coerce` | 5 | 2.1s |  |
| 192 | `avm1_tabindex_textfield_v6` | 13 | 2.4s |  |
| 193 | `avm1_tabindex_textfield_v8` | 13 | 2.6s |  |
| 194 | `avm1_textfield_attached_depth_order` | 1 | 26.3s |  |
| 195 | `avm1_textfield_ctor_shadow_swf6` | 2 | 2.5s |  |
| 196 | `avm1_textfield_ctor_shadow_swf7` | 2 | 1.3s |  |
| 197 | `avm1_textfield_x_bounds_offset` | 10 | 26.0s |  |
| 198 | `avm1_timeline_selfgoto_child_replace` | 27 | 26.6s |  |
| 199 | `avm1_timer_clock_model` | 12 | 26.5s |  |
| 200 | `avm1_timer_function_form_activation` | 3 | 26.1s |  |
| 201 | `avm1_timer_late_frame_check` | 29 | 26.6s |  |
| 202 | `avm1_timer_method_form` | 6 | 2.6s |  |
| 203 | `avm1_timer_native_method_play` | 3 | 2.5s |  |
| 204 | `avm1_timer_overflow` | 10 | 3.3s |  |
| 205 | `avm1_timer_root_goto_stopped_gs` | 3 | 2.7s |  |
| 206 | `avm1_timer_root_goto_stopped_nf` | 3 | 2.5s |  |
| 207 | `avm1_type2_mc_receiver_dispatch` | 7 | 26.5s |  |
| 208 | `avm1_watch_long_name` | 9 | 2.5s |  |
| 209 | `avm1_watch_overflow` | 2 | 3.3s |  |
| 210 | `avm1_wrap_giveup_mixed_runs` | 2 | 2.5s |  |
| 211 | `avm1_xml_first_action_proto` | 2 | 2.5s |  |
| 212 | `avm1_xmlnode_first_action_proto` | 2 | 2.4s |  |
| 213 | `avm1_xscale_double_readback` | 8 | 26.2s |  |
| 214 | `avm2_activation_vtable_bounded` | 5 | 11.0s |  |
| 215 | `avm2_agi_shell` | 6 | 3.8s |  |
| 216 | `avm2_applyfilter_bevel_sample` | 441 | 18.2s |  |
| 217 | `avm2_applyfilter_glow_kernels` | 23 | 7.7s |  |
| 218 | `avm2_applyfilter_gradient_opaque` | 26 | 8.3s |  |
| 219 | `avm2_array_growth_bounded` | 5 | 8.2s |  |
| 220 | `avm2_bitmapdata_draw_edittext_box` | 5 | 7.4s |  |
| 221 | `avm2_bitmapdata_draw_filtered` | 13 | 7.5s |  |
| 222 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 8.0s |  |
| 223 | `avm2_bitmapdata_draw_textfield` | 5 | 7.7s |  |
| 224 | `avm2_bitmapdata_palettemap_index` | 5 | 21.3s |  |
| 225 | `avm2_child_simplebutton` | 10 | 26.9s |  |
| 226 | `avm2_contextmenu_stub` | 4 | 7.4s |  |
| 227 | `avm2_definetext_matrix` | 0 | 26.2s |  |
| 228 | `avm2_drawapi_stroke_snap` | 1 | 26.0s |  |
| 229 | `avm2_e4x_parse_bounded` | 18 | 8.3s |  |
| 230 | `avm2_edittext_placed_cxform` | 0 | 26.4s |  |
| 231 | `avm2_edittext_selection_cxform` | 2 | 26.4s |  |
| 232 | `avm2_embed_bytearray` | 2 | 7.3s |  |
| 233 | `avm2_external_interface_unavailable` | 8 | 7.4s |  |
| 234 | `avm2_findprop_this_resolution` | 13 | 2.5s |  |
| 235 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.5s |  |
| 236 | `avm2_gc_string_concat_reclaim` | 10 | 7.5s |  |
| 237 | `avm2_gc_string_survives_collect` | 9 | 7.5s |  |
| 238 | `avm2_goto_catchup_scale` | 4 | 7.2s |  |
| 239 | `avm2_graphics_runtime` | 7 | 25.0s |  |
| 240 | `avm2_group_alpha_cab` | 0 | 25.1s |  |
| 241 | `avm2_group_alpha_filter_cm` | 0 | 7.2s |  |
| 242 | `avm2_group_alpha_layer_aadd` | 0 | 7.1s |  |
| 243 | `avm2_group_alpha_layer_inner` | 0 | 7.1s |  |
| 244 | `avm2_group_alpha_multiply` | 0 | 1.0s |  |
| 245 | `avm2_group_alpha_shadow_shape_a50` | 0 | 7.2s |  |
| 246 | `avm2_html_img_loadcount` | 39 | 9.1s |  |
| 247 | `avm2_json_roundtrip_bounded` | 13 | 7.9s |  |
| 248 | `avm2_layer_group_alpha` | 0 | 25.9s |  |
| 249 | `avm2_layer_group_alpha_transparency` | 0 | 22.7s |  |
| 250 | `avm2_layer_group_erase` | 0 | 23.1s |  |
| 251 | `avm2_layer_group_filtered_child` | 0 | 22.9s |  |
| 252 | `avm2_layer_group_overlap_alpha` | 0 | 24.1s |  |
| 253 | `avm2_loader_stub` | 5 | 7.5s |  |
| 254 | `avm2_localconnection_domain` | 4 | 7.3s |  |
| 255 | `avm2_mask_removal_script` | 6 | 23.9s |  |
| 256 | `avm2_morph` | 8 | 24.7s |  |
| 257 | `avm2_parent_child_render` | 11 | 9.1s |  |
| 258 | `avm2_parent_child_static_text` | 12 | 7.6s |  |
| 259 | `avm2_parent_child_symbol_stride` | 6 | 8.6s |  |
| 260 | `avm2_parent_child_symbolclass_domain` | 12 | 26.9s |  |
| 261 | `avm2_pixelbounds_offlist` | 13 | 26.5s |  |
| 262 | `avm2_reflect_trait_hooks` | 30 | 7.7s |  |
| 263 | `avm2_sharedobject_flushstatus` | 4 | 7.4s |  |
| 264 | `avm2_simplebutton_click` | 2 | 7.4s |  |
| 265 | `avm2_slot_default_template` | 34 | 7.5s |  |
| 266 | `avm2_sound_bytes_and_group_format` | 27 | 7.8s |  |
| 267 | `avm2_static_and_store_slots` | 14 | 7.5s |  |
| 268 | `avm2_static_text` | 6 | 26.4s |  |
| 269 | `avm2_strbuf_stale_prefix` | 21 | 7.5s |  |
| 270 | `avm2_stroke_curve_scale_s16_w16_k0` | 2 | 27.1s |  |
| 271 | `avm2_stroke_curve_scale_s16_w16_k1` | 2 | 26.1s |  |
| 272 | `avm2_stroke_curve_scale_s16_w4_k0` | 2 | 21.2s |  |
| 273 | `avm2_stroke_curve_scale_s16_w4_k1` | 2 | 1.5s |  |
| 274 | `avm2_stroke_curve_scale_s1s4` | 17 | 26.6s |  |
| 275 | `avm2_stroke_translucent_round` | 1 | 25.9s |  |
| 276 | `avm2_timeline_gradients` | 7 | 26.4s |  |
| 277 | `avm2_timeline_solid` | 6 | 8.1s |  |
| 278 | `avm2_timeline_stroke_gradient` | 9 | 8.3s |  |
| 279 | `avm2_timeline_text` | 4 | 7.5s |  |
| 280 | `avm2_tolerant_verify_quarantine` | 2 | 7.2s |  |
| 281 | `avm2_typed_value_ops` | 30 | 7.4s |  |
| 282 | `bitmap_pool_layer_cap` | 1 | 21.4s |  |
| 283 | `broadcast_cross_swf_version` | 4 | 1.7s |  |
| 284 | `broadcast_type1_args` | 14 | 1.6s |  |
| 285 | `coerce_cross_swf_version` | 7 | 1.7s |  |
| 286 | `coerce_recursion_guard` | 1 | 1.6s |  |
| 287 | `coerce_type1_args` | 9 | 1.5s |  |
| 288 | `convertfloat_type1_this` | 3 | 1.5s |  |
| 289 | `ctor_before_first_call_locals` | 5 | 1.6s |  |
| 290 | `ei_closure_scope_order` | 7 | 1.6s |  |
| 291 | `ei_cross_swf_version` | 2 | 1.6s |  |
| 292 | `ei_mc_this_receiver` | 5 | 19.9s |  |
| 293 | `ei_type1_args` | 7 | 2.5s |  |
| 294 | `enterframe_type1_args` | 8 | 25.8s |  |
| 295 | `fn_call_builtin_type1_args` | 10 | 2.4s |  |
| 296 | `fn_call_type1_args` | 7 | 2.4s |  |
| 297 | `fn_empty_method_type1_args` | 10 | 2.4s |  |
| 298 | `group_alpha_cab` | 0 | 25.4s |  |
| 299 | `group_alpha_filter_cm` | 0 | 2.6s |  |
| 300 | `group_alpha_layer_aadd` | 0 | 2.5s |  |
| 301 | `group_alpha_layer_inner` | 0 | 2.5s |  |
| 302 | `group_alpha_multiply` | 0 | 1.2s |  |
| 303 | `group_alpha_shadow_shape_a50` | 0 | 2.7s |  |
| 304 | `layer_group_alpha_transparency` | 0 | 24.7s |  |
| 305 | `layer_group_filtered_child` | 0 | 24.8s |  |
| 306 | `layer_group_in_add_alpha` | 0 | 25.4s |  |
| 307 | `layer_group_overlap_alpha` | 0 | 1.9s |  |
| 308 | `layer_group_overlap_erase` | 0 | 1.2s |  |
| 309 | `lc_method_type1_args` | 7 | 1.7s |  |
| 310 | `lc_onstatus_type1_args` | 3 | 1.7s |  |
| 311 | `lowq_fill_edges` | 0 | 25.0s |  |
| 312 | `lowq_glyph_probe_df2` | 0 | 26.4s |  |
| 313 | `lowq_glyph_probe_df3` | 0 | 2.1s |  |
| 314 | `lowq_gradient_orient_probe` | 0 | 25.4s |  |
| 315 | `lowq_sample_point_probe` | 0 | 1.7s |  |
| 316 | `lowq_stroke_probe` | 0 | 3.0s |  |
| 317 | `lowq_tsnap_tie_probe` | 0 | 1.0s |  |
| 318 | `lv_cross_swf_version` | 5 | 1.0s |  |
| 319 | `lv_ondata_type1_args` | 3 | 0.9s |  |
| 320 | `mask_nested_intersect` | 1 | 1.4s |  |
| 321 | `mask_sibling_union` | 1 | 1.0s |  |
| 322 | `mc_event_cross_swf_version` | 4 | 0.9s |  |
| 323 | `mc_event_type1_args` | 3 | 0.9s |  |
| 324 | `mc_method_v5_caller_gate` | 4 | 0.9s |  |
| 325 | `mc_resolve_type1_args` | 6 | 0.9s |  |
| 326 | `method_type1_args` | 10 | 1.6s |  |
| 327 | `nc_onstatus_closure` | 2 | 1.6s |  |
| 328 | `nc_onstatus_type1_args` | 3 | 1.6s |  |
| 329 | `onconstruct_cross_swf_version` | 4 | 1.7s |  |
| 330 | `onconstruct_type1_args` | 6 | 1.6s |  |
| 331 | `onload_type1_args` | 7 | 1.6s |  |
| 332 | `onunload_type1_args` | 6 | 1.6s |  |
| 333 | `onunload_type1_local_frame` | 2 | 1.6s |  |
| 334 | `resolve_type1_args` | 13 | 1.6s |  |
| 335 | `root_enterframe_cross_swf_version` | 3 | 20.2s |  |
| 336 | `sort_comparator_captured_scope` | 2 | 1.7s |  |
| 337 | `sort_comparator_type1_args` | 5 | 1.6s |  |
| 338 | `string_prim_method_type1_args` | 19 | 1.6s |  |
| 339 | `timer_cross_swf_version` | 3 | 1.7s |  |
| 340 | `timer_type1_args` | 14 | 19.6s |  |
| 341 | `watch_cross_swf_version` | 6 | 1.6s |  |
| 342 | `watch_mc_reentrant_setmember` | 3 | 1.5s |  |
| 343 | `watch_mc_type1_args` | 7 | 1.6s |  |
| 344 | `watch_setmember_type1_args` | 7 | 1.6s |  |
| 345 | `watch_timeline_named_params` | 4 | 1.5s |  |
| 346 | `watch_timeline_reentrant` | 3 | 1.5s |  |
| 347 | `xml_onload_type1_args` | 3 | 1.5s |  |

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
