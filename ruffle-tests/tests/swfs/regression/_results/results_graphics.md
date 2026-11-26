# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-26 20:41 UTC

**Git SHA**: `bfa47037b1`

**Run Duration**: 59m 18s

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
| 1 | `array_element_type1_args` | 7 | 25.2s |  |
| 2 | `array_method_type1_args` | 7 | 2.2s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 29.6s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 2.5s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 2.5s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 2.8s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 2.4s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 2.4s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 2.4s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 2.6s |  |
| 11 | `avm1_array_native_own_method` | 8 | 19.3s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 19.4s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.8s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 19.8s |  |
| 15 | `avm1_attached_clip_color` | 2 | 22.1s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 19.7s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.1s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 19.6s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 1.6s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 19.6s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 21.3s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 20.9s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 24.0s |  |
| 24 | `avm1_attached_clip_selfgoto_trace` | 14 | 21.4s |  |
| 25 | `avm1_attached_clip_tagorder` | 34 | 2.5s |  |
| 26 | `avm1_attached_clip_tagorder_nonroot` | 34 | 1.0s |  |
| 27 | `avm1_attached_clip_tagorder_po3` | 34 | 2.2s |  |
| 28 | `avm1_attached_clip_tagorder_ratio` | 34 | 2.2s |  |
| 29 | `avm1_attached_clip_timeline_child_parent` | 6 | 21.2s |  |
| 30 | `avm1_bare_depth_methods_v7_gate` | 6 | 21.1s |  |
| 31 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 19.6s |  |
| 32 | `avm1_bare_mc_method_scope` | 19 | 19.8s |  |
| 33 | `avm1_bitmap_nearest_tie_stage` | 1 | 22.5s |  |
| 34 | `avm1_bitmapdata_draw_child_color` | 5 | 19.8s |  |
| 35 | `avm1_bitmapdata_draw_edittext` | 3 | 1.7s |  |
| 36 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 20.2s |  |
| 37 | `avm1_browser_eager_init` | 10 | 19.8s |  |
| 38 | `avm1_browser_gated_color` | 3 | 1.7s |  |
| 39 | `avm1_browser_gated_depth` | 7 | 1.6s |  |
| 40 | `avm1_browser_gated_textfield` | 7 | 1.6s |  |
| 41 | `avm1_browser_parked_frame` | 7 | 20.0s |  |
| 42 | `avm1_button_pick_order` | 9 | 20.3s |  |
| 43 | `avm1_button_textfield_path_binding` | 4 | 19.7s |  |
| 44 | `avm1_child_timeline_advance` | 23 | 19.8s |  |
| 45 | `avm1_child_timeline_frame1_stop` | 7 | 1.8s |  |
| 46 | `avm1_child_timeline_holder_stop` | 26 | 1.8s |  |
| 47 | `avm1_child_timeline_loop` | 32 | 1.9s |  |
| 48 | `avm1_clipevent_root_goto_stopped` | 3 | 19.8s |  |
| 49 | `avm1_clone_depth_overflow` | 3 | 2.2s |  |
| 50 | `avm1_clone_depth_removed_reuse` | 4 | 1.6s |  |
| 51 | `avm1_closure_base_clip_root_frame` | 5 | 2.9s |  |
| 52 | `avm1_closure_method_scope` | 7 | 2.8s |  |
| 53 | `avm1_create_text_field_depth` | 9 | 27.3s |  |
| 54 | `avm1_cxform_override_overflow` | 2 | 27.5s |  |
| 55 | `avm1_definetext_matrix` | 0 | 2.7s |  |
| 56 | `avm1_device_edittext_xscale` | 7 | 27.1s |  |
| 57 | `avm1_display_filter_growth_edge_scale` | 0 | 3.4s |  |
| 58 | `avm1_display_prop_coercion` | 36 | 2.9s |  |
| 59 | `avm1_drawapi_stroke_snap` | 1 | 27.6s |  |
| 60 | `avm1_drawing_stroke_scale` | 0 | 29.9s |  |
| 61 | `avm1_dynclip_color_transform` | 2 | 2.1s |  |
| 62 | `avm1_edittext_border_subpixel` | 1 | 19.1s |  |
| 63 | `avm1_edittext_cut_copy_selection` | 9 | 19.3s |  |
| 64 | `avm1_edittext_html_delete_runs` | 4 | 19.1s |  |
| 65 | `avm1_edittext_html_typed_runs` | 3 | 1.7s |  |
| 66 | `avm1_edittext_maxchars_clips_insertion` | 4 | 18.9s |  |
| 67 | `avm1_edittext_path_variable_same_frame` | 11 | 19.1s |  |
| 68 | `avm1_edittext_path_variable_scope` | 10 | 1.7s |  |
| 69 | `avm1_edittext_placed_cxform` | 0 | 19.2s |  |
| 70 | `avm1_edittext_placed_cxform_script` | 3 | 1.6s |  |
| 71 | `avm1_edittext_restrict_onchanged` | 6 | 26.7s |  |
| 72 | `avm1_edittext_rotated_borders` | 0 | 30.0s |  |
| 73 | `avm1_edittext_rotated_glyphs` | 0 | 26.8s |  |
| 74 | `avm1_edittext_scaled_glyphs` | 0 | 2.6s |  |
| 75 | `avm1_edittext_tab_render` | 1 | 26.8s |  |
| 76 | `avm1_edittext_tabstops_metric` | 9 | 26.5s |  |
| 77 | `avm1_edittext_wordwrap_render` | 5 | 26.6s |  |
| 78 | `avm1_empty_clip_drawing_depth_order` | 1 | 2.9s |  |
| 79 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 26.8s |  |
| 80 | `avm1_enterframe_root_goto_opcode` | 7 | 26.9s |  |
| 81 | `avm1_exec_order_attached_selfremove` | 18 | 25.8s |  |
| 82 | `avm1_exec_order_dynamic_eligible` | 35 | 25.2s |  |
| 83 | `avm1_filter_list_overflow` | 2 | 2.8s |  |
| 84 | `avm1_func2_param_register_oob` | 4 | 2.1s |  |
| 85 | `avm1_gnash_flash_probes` | 63 | 25.4s |  |
| 86 | `avm1_gnash_flash_probes_v5` | 77 | 1.3s |  |
| 87 | `avm1_gnash_flash_probes_v6` | 63 | 1.3s |  |
| 88 | `avm1_goto_backward_enterframe_once` | 22 | 25.0s |  |
| 89 | `avm1_goto_skipped_init_call` | 6 | 25.1s |  |
| 90 | `avm1_goto_skipped_init_script` | 5 | 2.3s |  |
| 91 | `avm1_goto_skipped_init_timer` | 6 | 18.3s |  |
| 92 | `avm1_hairline_scaled_instances` | 1 | 20.9s |  |
| 93 | `avm1_hittest_hairline` | 28 | 18.8s |  |
| 94 | `avm1_hittest_shape_stale_matrix` | 28 | 18.7s |  |
| 95 | `avm1_holder_drawing_under_children` | 1 | 18.8s |  |
| 96 | `avm1_jpeg3_alpha_bitmap` | 0 | 18.5s |  |
| 97 | `avm1_key_isdown_protected` | 8 | 18.8s |  |
| 98 | `avm1_loaded_bare_goto` | 17 | 19.3s |  |
| 99 | `avm1_loaded_bare_goto_seq` | 4 | 2.0s |  |
| 100 | `avm1_loaded_goto_play_deferred` | 31 | 19.1s |  |
| 101 | `avm1_loaded_order_create_vs_load` | 33 | 21.2s |  |
| 102 | `avm1_loaded_shell_consumers_seq` | 12 | 20.6s |  |
| 103 | `avm1_loaded_shell_root_lookup` | 4 | 20.3s |  |
| 104 | `avm1_loaded_timeline_holder` | 7 | 2.3s |  |
| 105 | `avm1_loaded_unload_deferred` | 5 | 2.4s |  |
| 106 | `avm1_loadvars_ondata_overflow` | 23 | 20.3s |  |
| 107 | `avm1_long_text_layout` | 2 | 20.3s |  |
| 108 | `avm1_many_chars_registry` | 4 | 20.3s |  |
| 109 | `avm1_many_defs_registry` | 13 | 22.0s |  |
| 110 | `avm1_many_functions_registry` | 3 | 9.9s |  |
| 111 | `avm1_mc_button_unified_pick` | 21 | 19.1s |  |
| 112 | `avm1_mc_resolve` | 5 | 1.8s |  |
| 113 | `avm1_mcl_holder_totalframes` | 5 | 19.0s |  |
| 114 | `avm1_mcl_load_tick` | 15 | 1.7s |  |
| 115 | `avm1_morph_instances_ratio` | 2 | 20.7s |  |
| 116 | `avm1_nested_po3_filters` | 12 | 19.3s |  |
| 117 | `avm1_onunload_setvar_scope` | 5 | 18.3s |  |
| 118 | `avm1_parent_as3_child_payload` | 2 | 1.7s |  |
| 119 | `avm1_parent_child_bitmap` | 5 | 1.7s |  |
| 120 | `avm1_parent_child_bitmap_fill` | 3 | 1.8s |  |
| 121 | `avm1_parent_child_modify_place` | 5 | 18.2s |  |
| 122 | `avm1_parent_child_morph` | 8 | 4.4s |  |
| 123 | `avm1_parent_child_render` | 7 | 2.1s |  |
| 124 | `avm1_parent_child_sprite_meta` | 8 | 2.0s |  |
| 125 | `avm1_parent_child_text` | 8 | 2.0s |  |
| 126 | `avm1_pixelbounds_dynamic_child` | 1 | 16.8s |  |
| 127 | `avm1_place_occupied_depth_swf5` | 6 | 1.8s |  |
| 128 | `avm1_placed_drawing_color` | 1 | 16.8s |  |
| 129 | `avm1_po3_cm_alpha_bias_edge` | 0 | 16.6s |  |
| 130 | `avm1_po3_cm_folded_clear` | 1 | 1.9s |  |
| 131 | `avm1_po3_cm_live_under_cxform` | 0 | 1.9s |  |
| 132 | `avm1_po3_color_matrix_live` | 0 | 1.8s |  |
| 133 | `avm1_po3_color_matrix_live_clear` | 1 | 1.8s |  |
| 134 | `avm1_po3_color_matrix_live_nested` | 0 | 1.8s |  |
| 135 | `avm1_remove_same_name_other_parent` | 4 | 16.5s |  |
| 136 | `avm1_remove_unload_finalize_overflow` | 4 | 18.3s |  |
| 137 | `avm1_removed_clip_dprops_gc` | 14 | 1.8s |  |
| 138 | `avm1_resolve_dotted_getvariable` | 13 | 1.7s |  |
| 139 | `avm1_root_identity_and_playhead` | 3 | 16.8s |  |
| 140 | `avm1_root_onload_child_order` | 11 | 17.0s |  |
| 141 | `avm1_root_onload_proto` | 7 | 21.4s |  |
| 142 | `avm1_runtime_filters` | 3 | 25.6s |  |
| 143 | `avm1_runtime_filters_cm_bitmap` | 5 | 3.1s |  |
| 144 | `avm1_set_new_text_format_color` | 4 | 22.4s |  |
| 145 | `avm1_set_new_text_format_instance` | 5 | 22.1s |  |
| 146 | `avm1_set_new_text_format_paragraph` | 12 | 2.3s |  |
| 147 | `avm1_set_new_text_format_render` | 5 | 22.0s |  |
| 148 | `avm1_set_new_text_format_size` | 5 | 2.2s |  |
| 149 | `avm1_sprite_goto_script_overflow` | 65 | 21.2s |  |
| 150 | `avm1_stroke_join_cap_snap` | 0 | 23.6s |  |
| 151 | `avm1_stroke_noscale_signed` | 0 | 26.0s |  |
| 152 | `avm1_stroke_pixel_snap` | 1 | 24.8s |  |
| 153 | `avm1_stroke_pixel_snap_matrix` | 0 | 25.3s |  |
| 154 | `avm1_stroke_style_id_order` | 1 | 24.7s |  |
| 155 | `avm1_swf6_case_insensitive_builtins` | 42 | 25.5s |  |
| 156 | `avm1_swf7_case_sensitive_builtins` | 40 | 1.3s |  |
| 157 | `avm1_textfield_attached_depth_order` | 1 | 25.0s |  |
| 158 | `avm1_textfield_x_bounds_offset` | 10 | 24.7s |  |
| 159 | `avm1_timer_clock_model` | 19 | 25.3s |  |
| 160 | `avm1_timer_function_form_activation` | 3 | 24.8s |  |
| 161 | `avm1_timer_method_form` | 6 | 25.4s |  |
| 162 | `avm1_timer_native_method_play` | 3 | 2.6s |  |
| 163 | `avm1_timer_overflow` | 10 | 27.7s |  |
| 164 | `avm1_timer_root_goto_stopped_gs` | 3 | 2.7s |  |
| 165 | `avm1_timer_root_goto_stopped_nf` | 3 | 2.5s |  |
| 166 | `avm1_type2_mc_receiver_dispatch` | 7 | 26.8s |  |
| 167 | `avm1_watch_long_name` | 9 | 2.6s |  |
| 168 | `avm1_watch_overflow` | 2 | 3.4s |  |
| 169 | `avm1_wrap_giveup_mixed_runs` | 2 | 2.7s |  |
| 170 | `avm1_xml_first_action_proto` | 2 | 2.6s |  |
| 171 | `avm1_xmlnode_first_action_proto` | 2 | 2.0s |  |
| 172 | `avm1_xscale_double_readback` | 8 | 2.1s |  |
| 173 | `avm2_activation_vtable_bounded` | 5 | 26.7s |  |
| 174 | `avm2_agi_shell` | 6 | 7.8s |  |
| 175 | `avm2_applyfilter_bevel_sample` | 441 | 19.0s |  |
| 176 | `avm2_applyfilter_glow_kernels` | 23 | 7.9s |  |
| 177 | `avm2_applyfilter_gradient_opaque` | 26 | 8.6s |  |
| 178 | `avm2_array_growth_bounded` | 5 | 8.3s |  |
| 179 | `avm2_bitmapdata_draw_edittext_box` | 5 | 7.5s |  |
| 180 | `avm2_bitmapdata_draw_filtered` | 13 | 7.7s |  |
| 181 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 25.6s |  |
| 182 | `avm2_bitmapdata_draw_textfield` | 5 | 7.2s |  |
| 183 | `avm2_child_simplebutton` | 10 | 24.7s |  |
| 184 | `avm2_contextmenu_stub` | 4 | 7.0s |  |
| 185 | `avm2_definetext_matrix` | 0 | 9.4s |  |
| 186 | `avm2_drawapi_stroke_snap` | 1 | 24.6s |  |
| 187 | `avm2_e4x_parse_bounded` | 18 | 7.9s |  |
| 188 | `avm2_edittext_placed_cxform` | 0 | 24.5s |  |
| 189 | `avm2_edittext_selection_cxform` | 2 | 24.9s |  |
| 190 | `avm2_embed_bytearray` | 2 | 24.4s |  |
| 191 | `avm2_external_interface_unavailable` | 8 | 7.3s |  |
| 192 | `avm2_findprop_this_resolution` | 13 | 7.3s |  |
| 193 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.3s |  |
| 194 | `avm2_gc_string_concat_reclaim` | 10 | 7.3s |  |
| 195 | `avm2_gc_string_survives_collect` | 9 | 7.3s |  |
| 196 | `avm2_goto_catchup_scale` | 4 | 7.3s |  |
| 197 | `avm2_graphics_runtime` | 7 | 7.3s |  |
| 198 | `avm2_group_alpha_cab` | 0 | 25.2s |  |
| 199 | `avm2_group_alpha_filter_cm` | 0 | 7.4s |  |
| 200 | `avm2_group_alpha_layer_aadd` | 0 | 7.2s |  |
| 201 | `avm2_group_alpha_layer_inner` | 0 | 36.3s |  |
| 202 | `avm2_group_alpha_multiply` | 0 | 9.3s |  |
| 203 | `avm2_group_alpha_shadow_shape_a50` | 0 | 9.5s |  |
| 204 | `avm2_json_roundtrip_bounded` | 13 | 33.9s |  |
| 205 | `avm2_layer_group_alpha` | 0 | 15.3s |  |
| 206 | `avm2_layer_group_alpha_transparency` | 0 | 1.3s |  |
| 207 | `avm2_layer_group_erase` | 0 | 1.9s |  |
| 208 | `avm2_layer_group_filtered_child` | 0 | 32.4s |  |
| 209 | `avm2_layer_group_overlap_alpha` | 0 | 9.6s |  |
| 210 | `avm2_loader_stub` | 5 | 9.4s |  |
| 211 | `avm2_localconnection_domain` | 4 | 25.5s |  |
| 212 | `avm2_morph` | 8 | 27.6s |  |
| 213 | `avm2_parent_child_render` | 11 | 9.5s |  |
| 214 | `avm2_parent_child_static_text` | 12 | 7.5s |  |
| 215 | `avm2_parent_child_symbol_stride` | 6 | 26.4s |  |
| 216 | `avm2_parent_child_symbolclass_domain` | 12 | 7.4s |  |
| 217 | `avm2_reflect_trait_hooks` | 30 | 7.4s |  |
| 218 | `avm2_sharedobject_flushstatus` | 4 | 7.1s |  |
| 219 | `avm2_simplebutton_click` | 2 | 6.7s |  |
| 220 | `avm2_slot_default_template` | 34 | 6.8s |  |
| 221 | `avm2_sound_bytes_and_group_format` | 27 | 6.9s |  |
| 222 | `avm2_static_and_store_slots` | 14 | 6.7s |  |
| 223 | `avm2_static_text` | 6 | 6.8s |  |
| 224 | `avm2_strbuf_stale_prefix` | 21 | 6.7s |  |
| 225 | `avm2_timeline_gradients` | 7 | 22.8s |  |
| 226 | `avm2_timeline_solid` | 6 | 8.3s |  |
| 227 | `avm2_timeline_stroke_gradient` | 9 | 7.3s |  |
| 228 | `avm2_timeline_text` | 4 | 6.6s |  |
| 229 | `avm2_tolerant_verify_quarantine` | 2 | 6.4s |  |
| 230 | `avm2_typed_value_ops` | 30 | 27.7s |  |
| 231 | `bitmap_pool_layer_cap` | 1 | 25.1s |  |
| 232 | `broadcast_cross_swf_version` | 4 | 20.7s |  |
| 233 | `broadcast_type1_args` | 14 | 20.6s |  |
| 234 | `coerce_cross_swf_version` | 7 | 2.2s |  |
| 235 | `coerce_recursion_guard` | 1 | 2.0s |  |
| 236 | `coerce_type1_args` | 9 | 2.0s |  |
| 237 | `convertfloat_type1_this` | 3 | 2.0s |  |
| 238 | `ctor_before_first_call_locals` | 5 | 2.1s |  |
| 239 | `ei_closure_scope_order` | 7 | 2.6s |  |
| 240 | `ei_cross_swf_version` | 2 | 2.5s |  |
| 241 | `ei_mc_this_receiver` | 5 | 25.4s |  |
| 242 | `ei_type1_args` | 7 | 2.4s |  |
| 243 | `enterframe_type1_args` | 8 | 25.1s |  |
| 244 | `fn_call_builtin_type1_args` | 10 | 2.4s |  |
| 245 | `fn_call_type1_args` | 7 | 2.4s |  |
| 246 | `fn_empty_method_type1_args` | 10 | 2.4s |  |
| 247 | `group_alpha_cab` | 0 | 2.5s |  |
| 248 | `group_alpha_filter_cm` | 0 | 29.0s |  |
| 249 | `group_alpha_layer_aadd` | 0 | 2.6s |  |
| 250 | `group_alpha_layer_inner` | 0 | 2.6s |  |
| 251 | `group_alpha_multiply` | 0 | 2.5s |  |
| 252 | `group_alpha_shadow_shape_a50` | 0 | 2.7s |  |
| 253 | `layer_group_alpha_transparency` | 0 | 1.3s |  |
| 254 | `layer_group_filtered_child` | 0 | 25.6s |  |
| 255 | `layer_group_in_add_alpha` | 0 | 8.4s |  |
| 256 | `layer_group_overlap_alpha` | 0 | 2.7s |  |
| 257 | `layer_group_overlap_erase` | 0 | 2.0s |  |
| 258 | `lc_method_type1_args` | 7 | 1.5s |  |
| 259 | `lc_onstatus_type1_args` | 3 | 1.5s |  |
| 260 | `lowq_fill_edges` | 0 | 15.3s |  |
| 261 | `lowq_gradient_orient_probe` | 0 | 15.8s |  |
| 262 | `lowq_sample_point_probe` | 0 | 15.4s |  |
| 263 | `lv_cross_swf_version` | 5 | 1.8s |  |
| 264 | `lv_ondata_type1_args` | 3 | 15.5s |  |
| 265 | `mask_nested_intersect` | 1 | 15.4s |  |
| 266 | `mask_sibling_union` | 1 | 18.8s |  |
| 267 | `mc_event_cross_swf_version` | 4 | 1.6s |  |
| 268 | `mc_event_type1_args` | 3 | 1.5s |  |
| 269 | `mc_method_v5_caller_gate` | 4 | 1.6s |  |
| 270 | `mc_resolve_type1_args` | 6 | 1.5s |  |
| 271 | `method_type1_args` | 10 | 1.5s |  |
| 272 | `nc_onstatus_closure` | 2 | 18.0s |  |
| 273 | `nc_onstatus_type1_args` | 3 | 1.7s |  |
| 274 | `onconstruct_cross_swf_version` | 4 | 1.5s |  |
| 275 | `onconstruct_type1_args` | 6 | 2.2s |  |
| 276 | `onload_type1_args` | 7 | 21.8s |  |
| 277 | `onunload_type1_args` | 6 | 2.1s |  |
| 278 | `onunload_type1_local_frame` | 2 | 2.1s |  |
| 279 | `resolve_type1_args` | 13 | 2.1s |  |
| 280 | `root_enterframe_cross_swf_version` | 3 | 21.5s |  |
| 281 | `sort_comparator_captured_scope` | 2 | 2.5s |  |
| 282 | `sort_comparator_type1_args` | 5 | 2.1s |  |
| 283 | `string_prim_method_type1_args` | 19 | 2.3s |  |
| 284 | `timer_cross_swf_version` | 3 | 1.6s |  |
| 285 | `timer_type1_args` | 14 | 19.0s |  |
| 286 | `watch_cross_swf_version` | 6 | 1.6s |  |
| 287 | `watch_mc_reentrant_setmember` | 3 | 1.5s |  |
| 288 | `watch_mc_type1_args` | 7 | 1.5s |  |
| 289 | `watch_setmember_type1_args` | 7 | 1.5s |  |
| 290 | `watch_timeline_named_params` | 4 | 1.6s |  |
| 291 | `watch_timeline_reentrant` | 3 | 1.6s |  |
| 292 | `xml_onload_type1_args` | 3 | 19.0s |  |

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
