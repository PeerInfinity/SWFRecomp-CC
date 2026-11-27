# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 03:57 UTC

**Git SHA**: `dbc43c1573`

**Run Duration**: 53m 45s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 316 |
| Passing | **315** (99.7%) |
| Failing | 1 |
| Total expected lines | 3199 |
| Matching lines | 3197 (99.9%) |
| Mismatched lines | 2 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**315 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 19.6s |  |
| 2 | `array_method_type1_args` | 7 | 1.1s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 1.4s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.4s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.4s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.3s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.4s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.4s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.4s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.2s |  |
| 11 | `avm1_array_native_own_method` | 8 | 1.2s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 18.7s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 18.6s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 18.9s |  |
| 15 | `avm1_attached_clip_color` | 2 | 18.7s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 18.8s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 0.5s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 18.7s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 0.9s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 18.8s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.0s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 18.8s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 19.3s |  |
| 24 | `avm1_attached_clip_selfgoto_trace` | 14 | 19.9s |  |
| 25 | `avm1_attached_clip_tagorder` | 34 | 19.6s |  |
| 26 | `avm1_attached_clip_tagorder_nonroot` | 34 | 1.1s |  |
| 27 | `avm1_attached_clip_tagorder_po3` | 34 | 1.0s |  |
| 28 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.0s |  |
| 29 | `avm1_attached_clip_timeline_child_parent` | 6 | 19.3s |  |
| 30 | `avm1_bare_depth_methods_v7_gate` | 6 | 0.9s |  |
| 31 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 0.3s |  |
| 32 | `avm1_bare_mc_method_scope` | 19 | 1.2s |  |
| 33 | `avm1_bitmap_nearest_tie_stage` | 1 | 19.3s |  |
| 34 | `avm1_bitmapdata_draw_child_color` | 5 | 19.2s |  |
| 35 | `avm1_bitmapdata_draw_edittext` | 3 | 1.0s |  |
| 36 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 19.2s |  |
| 37 | `avm1_browser_eager_init` | 10 | 19.1s |  |
| 38 | `avm1_browser_gated_color` | 3 | 0.9s |  |
| 39 | `avm1_browser_gated_depth` | 7 | 0.9s |  |
| 40 | `avm1_browser_gated_textfield` | 7 | 0.9s |  |
| 41 | `avm1_browser_parked_frame` | 7 | 19.1s |  |
| 42 | `avm1_button_pick_order` | 9 | 1.7s |  |
| 43 | `avm1_button_textfield_path_binding` | 4 | 19.0s |  |
| 44 | `avm1_child_timeline_advance` | 23 | 1.1s |  |
| 45 | `avm1_child_timeline_frame1_stop` | 7 | 19.4s |  |
| 46 | `avm1_child_timeline_holder_stop` | 26 | 1.1s |  |
| 47 | `avm1_child_timeline_loop` | 32 | 1.2s |  |
| 48 | `avm1_clipevent_root_goto_stopped` | 3 | 19.1s |  |
| 49 | `avm1_clone_depth_overflow` | 3 | 19.4s |  |
| 50 | `avm1_clone_depth_removed_reuse` | 4 | 0.9s |  |
| 51 | `avm1_closure_base_clip_root_frame` | 5 | 1.0s |  |
| 52 | `avm1_closure_method_scope` | 7 | 1.0s |  |
| 53 | `avm1_create_text_field_depth` | 9 | 0.9s |  |
| 54 | `avm1_cxform_override_overflow` | 2 | 19.3s |  |
| 55 | `avm1_definetext_matrix` | 0 | 0.9s |  |
| 56 | `avm1_device_edittext_xscale` | 7 | 18.9s |  |
| 57 | `avm1_display_filter_growth_edge_scale` | 0 | 18.9s |  |
| 58 | `avm1_display_prop_coercion` | 36 | 1.1s |  |
| 59 | `avm1_drawapi_stroke_snap` | 1 | 19.1s |  |
| 60 | `avm1_drawing_stroke_scale` | 0 | 20.4s |  |
| 61 | `avm1_dynclip_color_transform` | 2 | 1.1s |  |
| 62 | `avm1_edittext_border_subpixel` | 1 | 18.8s |  |
| 63 | `avm1_edittext_cut_copy_selection` | 9 | 18.9s |  |
| 64 | `avm1_edittext_html_delete_runs` | 4 | 18.8s |  |
| 65 | `avm1_edittext_html_typed_runs` | 3 | 0.8s |  |
| 66 | `avm1_edittext_maxchars_clips_insertion` | 4 | 0.7s |  |
| 67 | `avm1_edittext_path_variable_same_frame` | 11 | 15.7s |  |
| 68 | `avm1_edittext_path_variable_scope` | 10 | 15.5s |  |
| 69 | `avm1_edittext_placed_cxform` | 0 | 15.0s |  |
| 70 | `avm1_edittext_placed_cxform_script` | 3 | 0.7s |  |
| 71 | `avm1_edittext_restrict_onchanged` | 6 | 14.9s |  |
| 72 | `avm1_edittext_rotated_borders` | 0 | 15.1s |  |
| 73 | `avm1_edittext_rotated_color` | 0 | 15.7s |  |
| 74 | `avm1_edittext_rotated_glyphs` | 0 | 1.1s |  |
| 75 | `avm1_edittext_rotated_paragraph` | 0 | 16.8s |  |
| 76 | `avm1_edittext_scaled_glyphs` | 0 | 1.3s |  |
| 77 | `avm1_edittext_tab_render` | 1 | 18.2s |  |
| 78 | `avm1_edittext_tabstops_metric` | 9 | 20.7s |  |
| 79 | `avm1_edittext_wordwrap_render` | 5 | 19.7s |  |
| 80 | `avm1_empty_clip_drawing_depth_order` | 1 | 19.7s |  |
| 81 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 19.8s |  |
| 82 | `avm1_enterframe_root_goto_opcode` | 7 | 19.7s |  |
| 83 | `avm1_enterframe_root_nextframe` | 22 | 20.4s |  |
| 84 | `avm1_enterframe_sprite_nextframe` | 16 | 1.5s |  |
| 85 | `avm1_exec_order_attached_selfremove` | 18 | 21.6s |  |
| 86 | `avm1_exec_order_dynamic_eligible` | 35 | 1.8s |  |
| 87 | `avm1_filter_list_overflow` | 2 | 20.4s |  |
| 88 | `avm1_func2_param_register_oob` | 4 | 1.2s |  |
| 89 | `avm1_gnash_flash_probes` | 63 | 19.5s |  |
| 90 | `avm1_gnash_flash_probes_v5` | 77 | 0.3s |  |
| 91 | `avm1_gnash_flash_probes_v6` | 63 | 0.3s |  |
| 92 | `avm1_goto_backward_enterframe_once` | 22 | 18.8s |  |
| 93 | `avm1_goto_current_frame_clip` | 23 | 19.1s |  |
| 94 | `avm1_goto_current_frame_root` | 22 | 18.8s |  |
| 95 | `avm1_goto_skipped_init_call` | 6 | 18.9s |  |
| 96 | `avm1_goto_skipped_init_script` | 5 | 1.0s |  |
| 97 | `avm1_goto_skipped_init_timer` | 6 | 1.0s |  |
| 98 | `avm1_goto_target_child_order_gotoscript` | 6 | 18.8s |  |
| 99 | `avm1_goto_target_child_order_interval` | 7 | 1.0s |  |
| 100 | `avm1_goto_target_child_order_normal` | 5 | 21.2s |  |
| 101 | `avm1_hairline_scaled_instances` | 1 | 21.1s |  |
| 102 | `avm1_hittest_hairline` | 28 | 21.4s |  |
| 103 | `avm1_hittest_shape_stale_matrix` | 28 | 21.2s |  |
| 104 | `avm1_holder_drawing_under_children` | 1 | 20.8s |  |
| 105 | `avm1_jpeg3_alpha_bitmap` | 0 | 20.7s |  |
| 106 | `avm1_key_isdown_protected` | 8 | 20.6s |  |
| 107 | `avm1_loaded_bare_goto` | 17 | 21.0s |  |
| 108 | `avm1_loaded_bare_goto_seq` | 4 | 1.9s |  |
| 109 | `avm1_loaded_goto_play_deferred` | 31 | 21.4s |  |
| 110 | `avm1_loaded_order_create_vs_load` | 33 | 1.9s |  |
| 111 | `avm1_loaded_shell_consumers_seq` | 12 | 19.8s |  |
| 112 | `avm1_loaded_shell_root_lookup` | 4 | 19.8s |  |
| 113 | `avm1_loaded_timeline_holder` | 7 | 1.4s |  |
| 114 | `avm1_loaded_unload_deferred` | 5 | 1.5s |  |
| 115 | `avm1_loadvars_ondata_overflow` | 23 | 19.9s |  |
| 116 | `avm1_long_text_layout` | 2 | 19.8s |  |
| 117 | `avm1_many_chars_registry` | 4 | 19.6s |  |
| 118 | `avm1_many_defs_registry` | 13 | 20.8s |  |
| 119 | `avm1_many_functions_registry` | 3 | 8.7s |  |
| 120 | `avm1_mc_button_unified_pick` | 21 | 19.6s |  |
| 121 | `avm1_mc_resolve` | 5 | 1.1s |  |
| 122 | `avm1_mc_super_native_probe` | 18 | 18.6s |  |
| 123 | `avm1_mcl_holder_totalframes` | 5 | 18.4s |  |
| 124 | `avm1_mcl_load_tick` | 15 | 1.0s |  |
| 125 | `avm1_morph_instances_ratio` | 2 | 18.4s |  |
| 126 | `avm1_nested_po3_filters` | 12 | 18.4s |  |
| 127 | `avm1_onunload_setvar_scope` | 5 | 18.3s |  |
| 128 | `avm1_parent_as3_child_payload` | 2 | 1.0s |  |
| 129 | `avm1_parent_child_bitmap` | 5 | 1.1s |  |
| 130 | `avm1_parent_child_bitmap_fill` | 3 | 1.1s |  |
| 131 | `avm1_parent_child_modify_place` | 5 | 1.1s |  |
| 132 | `avm1_parent_child_morph` | 8 | 19.4s |  |
| 133 | `avm1_parent_child_render` | 7 | 1.2s |  |
| 134 | `avm1_parent_child_sprite_meta` | 8 | 1.2s |  |
| 135 | `avm1_parent_child_text` | 8 | 1.2s |  |
| 136 | `avm1_pixelbounds_dynamic_child` | 1 | 18.9s |  |
| 137 | `avm1_place_occupied_depth_swf5` | 6 | 1.0s |  |
| 138 | `avm1_placed_drawing_color` | 1 | 18.9s |  |
| 139 | `avm1_po3_cm_alpha_bias_edge` | 0 | 18.7s |  |
| 140 | `avm1_po3_cm_folded_clear` | 1 | 1.0s |  |
| 141 | `avm1_po3_cm_live_under_cxform` | 0 | 0.9s |  |
| 142 | `avm1_po3_color_matrix_live` | 0 | 0.9s |  |
| 143 | `avm1_po3_color_matrix_live_clear` | 1 | 18.8s |  |
| 144 | `avm1_po3_color_matrix_live_nested` | 0 | 1.0s |  |
| 145 | `avm1_remove_same_name_other_parent` | 4 | 18.9s |  |
| 146 | `avm1_remove_unload_finalize_overflow` | 4 | 21.0s |  |
| 147 | `avm1_removed_clip_dprops_gc` | 14 | 1.1s |  |
| 148 | `avm1_resolve_dotted_getvariable` | 13 | 0.9s |  |
| 149 | `avm1_root_identity_and_playhead` | 3 | 18.6s |  |
| 150 | `avm1_root_onload_child_order` | 11 | 18.5s |  |
| 151 | `avm1_root_onload_proto` | 7 | 0.9s |  |
| 152 | `avm1_rotation_matrix_fixed` | 7 | 1.0s |  |
| 153 | `avm1_runtime_filters` | 3 | 18.4s |  |
| 154 | `avm1_runtime_filters_cm_bitmap` | 5 | 1.1s |  |
| 155 | `avm1_selfgoto_current_frame_opcode` | 8 | 19.1s |  |
| 156 | `avm1_set_new_text_format_color` | 4 | 18.8s |  |
| 157 | `avm1_set_new_text_format_instance` | 5 | 0.9s |  |
| 158 | `avm1_set_new_text_format_paragraph` | 12 | 1.1s |  |
| 159 | `avm1_set_new_text_format_render` | 5 | 1.0s |  |
| 160 | `avm1_set_new_text_format_size` | 5 | 0.9s |  |
| 161 | `avm1_sprite_goto_script_overflow` | 65 | 19.1s |  |
| 162 | `avm1_stroke_hinting_caps` | 1 | 1.1s |  |
| 163 | `avm1_stroke_join_cap_snap` | 0 | 20.9s |  |
| 164 | `avm1_stroke_noscale_signed` | 0 | 19.0s |  |
| 165 | `avm1_stroke_pixel_snap` | 1 | 19.5s |  |
| 166 | `avm1_stroke_pixel_snap_matrix` | 0 | 20.0s |  |
| 167 | `avm1_stroke_seam_caps` | 1 | 19.5s |  |
| 168 | `avm1_stroke_style_id_order` | 1 | 19.3s |  |
| 169 | `avm1_swf6_case_insensitive_builtins` | 42 | 19.4s |  |
| 170 | `avm1_swf7_case_sensitive_builtins` | 40 | 0.4s |  |
| 171 | `avm1_tabindex_fn2_root_raw` | 4 | 1.2s |  |
| 172 | `avm1_tabindex_fresh_child_coerce` | 4 | 1.1s |  |
| 173 | `avm1_tabindex_mtasc_class_main` | 6 | 1.2s |  |
| 174 | `avm1_tabindex_read_first_coerce` | 5 | 1.1s |  |
| 175 | `avm1_textfield_attached_depth_order` | 1 | 1.4s |  |
| 176 | `avm1_textfield_ctor_shadow_swf6` | 2 | 1.3s |  |
| 177 | `avm1_textfield_ctor_shadow_swf7` | 2 | 0.4s |  |
| 178 | `avm1_textfield_x_bounds_offset` | 10 | 20.4s |  |
| 179 | `avm1_timer_clock_model` | 12 | 21.7s |  |
| 180 | `avm1_timer_function_form_activation` | 3 | 21.3s |  |
| 181 | `avm1_timer_late_frame_check` | 29 | 21.5s |  |
| 182 | `avm1_timer_method_form` | 6 | 21.0s |  |
| 183 | `avm1_timer_native_method_play` | 3 | 1.4s |  |
| 184 | `avm1_timer_overflow` | 10 | 2.0s |  |
| 185 | `avm1_timer_root_goto_stopped_gs` | 3 | 1.6s |  |
| 186 | `avm1_timer_root_goto_stopped_nf` | 3 | 18.6s |  |
| 187 | `avm1_type2_mc_receiver_dispatch` | 7 | 18.9s |  |
| 188 | `avm1_watch_long_name` | 9 | 0.9s |  |
| 189 | `avm1_watch_overflow` | 2 | 1.5s |  |
| 190 | `avm1_wrap_giveup_mixed_runs` | 2 | 0.9s |  |
| 191 | `avm1_xml_first_action_proto` | 2 | 0.9s |  |
| 192 | `avm1_xmlnode_first_action_proto` | 2 | 0.8s |  |
| 193 | `avm1_xscale_double_readback` | 8 | 1.0s |  |
| 194 | `avm2_activation_vtable_bounded` | 5 | 24.6s |  |
| 195 | `avm2_agi_shell` | 6 | 5.9s |  |
| 196 | `avm2_applyfilter_bevel_sample` | 441 | 15.5s |  |
| 197 | `avm2_applyfilter_glow_kernels` | 23 | 5.7s |  |
| 198 | `avm2_applyfilter_gradient_opaque` | 26 | 6.6s |  |
| 199 | `avm2_array_growth_bounded` | 5 | 6.6s |  |
| 200 | `avm2_bitmapdata_draw_edittext_box` | 5 | 5.7s |  |
| 201 | `avm2_bitmapdata_draw_filtered` | 13 | 5.8s |  |
| 202 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 6.4s |  |
| 203 | `avm2_bitmapdata_draw_textfield` | 5 | 6.3s |  |
| 204 | `avm2_bitmapdata_palettemap_index` | 5 | 5.8s |  |
| 205 | `avm2_child_simplebutton` | 10 | 22.6s |  |
| 206 | `avm2_contextmenu_stub` | 4 | 6.6s |  |
| 207 | `avm2_definetext_matrix` | 0 | 25.0s |  |
| 208 | `avm2_drawapi_stroke_snap` | 1 | 25.0s |  |
| 209 | `avm2_e4x_parse_bounded` | 18 | 7.6s |  |
| 210 | `avm2_edittext_placed_cxform` | 0 | 24.8s |  |
| 211 | `avm2_edittext_selection_cxform` | 2 | 25.4s |  |
| 212 | `avm2_embed_bytearray` | 2 | 6.6s |  |
| 213 | `avm2_external_interface_unavailable` | 8 | 6.6s |  |
| 214 | `avm2_findprop_this_resolution` | 13 | 6.7s |  |
| 215 | `avm2_gc_dynprop_tombstone_purge` | 8 | 6.6s |  |
| 216 | `avm2_gc_string_concat_reclaim` | 10 | 24.4s |  |
| 217 | `avm2_gc_string_survives_collect` | 9 | 6.1s |  |
| 218 | `avm2_goto_catchup_scale` | 4 | 6.1s |  |
| 219 | `avm2_graphics_runtime` | 7 | 24.1s |  |
| 220 | `avm2_group_alpha_cab` | 0 | 24.4s |  |
| 221 | `avm2_group_alpha_filter_cm` | 0 | 6.0s |  |
| 222 | `avm2_group_alpha_layer_aadd` | 0 | 6.0s |  |
| 223 | `avm2_group_alpha_layer_inner` | 0 | 6.0s |  |
| 224 | `avm2_group_alpha_multiply` | 0 | 0.3s |  |
| 225 | `avm2_group_alpha_shadow_shape_a50` | 0 | 6.0s |  |
| 226 | `avm2_json_roundtrip_bounded` | 13 | 25.7s |  |
| 227 | `avm2_layer_group_alpha` | 0 | 6.5s |  |
| 228 | `avm2_layer_group_alpha_transparency` | 0 | 24.3s |  |
| 229 | `avm2_layer_group_erase` | 0 | 0.6s |  |
| 230 | `avm2_layer_group_filtered_child` | 0 | 24.5s |  |
| 231 | `avm2_layer_group_overlap_alpha` | 0 | 6.0s |  |
| 232 | `avm2_loader_stub` | 5 | 6.0s |  |
| 233 | `avm2_localconnection_domain` | 4 | 6.0s |  |
| 234 | `avm2_morph` | 8 | 24.3s |  |
| 235 | `avm2_parent_child_render` | 11 | 8.2s |  |
| 236 | `avm2_parent_child_static_text` | 12 | 25.1s |  |
| 237 | `avm2_parent_child_symbol_stride` | 6 | 26.0s |  |
| 238 | `avm2_parent_child_symbolclass_domain` | 12 | 6.3s |  |
| 239 | `avm2_reflect_trait_hooks` | 30 | 6.3s |  |
| 240 | `avm2_sharedobject_flushstatus` | 4 | 6.0s |  |
| 241 | `avm2_simplebutton_click` | 2 | 6.0s |  |
| 242 | `avm2_slot_default_template` | 34 | 6.2s |  |
| 243 | `avm2_sound_bytes_and_group_format` | 27 | 6.3s |  |
| 244 | `avm2_static_and_store_slots` | 14 | 6.2s |  |
| 245 | `avm2_static_text` | 6 | 6.1s |  |
| 246 | `avm2_strbuf_stale_prefix` | 21 | 7.0s |  |
| 247 | `avm2_timeline_gradients` | 7 | 27.9s |  |
| 248 | `avm2_timeline_solid` | 6 | 7.8s |  |
| 249 | `avm2_timeline_stroke_gradient` | 9 | 7.8s |  |
| 250 | `avm2_timeline_text` | 4 | 7.3s |  |
| 251 | `avm2_tolerant_verify_quarantine` | 2 | 6.9s |  |
| 252 | `avm2_typed_value_ops` | 30 | 7.0s |  |
| 253 | `bitmap_pool_layer_cap` | 1 | 21.1s |  |
| 254 | `broadcast_cross_swf_version` | 4 | 19.9s |  |
| 255 | `broadcast_type1_args` | 14 | 19.6s |  |
| 256 | `coerce_cross_swf_version` | 7 | 17.3s |  |
| 257 | `coerce_recursion_guard` | 1 | 16.9s |  |
| 258 | `coerce_type1_args` | 9 | 1.0s |  |
| 259 | `convertfloat_type1_this` | 3 | 1.0s |  |
| 260 | `ctor_before_first_call_locals` | 5 | 1.0s |  |
| 261 | `ei_closure_scope_order` | 7 | 1.1s |  |
| 262 | `ei_cross_swf_version` | 2 | 1.0s |  |
| 263 | `ei_mc_this_receiver` | 5 | 16.8s |  |
| 264 | `ei_type1_args` | 7 | 1.1s |  |
| 265 | `enterframe_type1_args` | 8 | 16.9s |  |
| 266 | `fn_call_builtin_type1_args` | 10 | 19.2s |  |
| 267 | `fn_call_type1_args` | 7 | 0.9s |  |
| 268 | `fn_empty_method_type1_args` | 10 | 0.9s |  |
| 269 | `group_alpha_cab` | 0 | 1.0s |  |
| 270 | `group_alpha_filter_cm` | 0 | 1.0s |  |
| 271 | `group_alpha_layer_aadd` | 0 | 0.9s |  |
| 272 | `group_alpha_layer_inner` | 0 | 0.4s |  |
| 273 | `group_alpha_multiply` | 0 | 0.2s |  |
| 274 | `group_alpha_shadow_shape_a50` | 0 | 0.9s |  |
| 275 | `layer_group_alpha_transparency` | 0 | 0.2s |  |
| 276 | `layer_group_filtered_child` | 0 | 15.2s |  |
| 277 | `layer_group_in_add_alpha` | 0 | 0.9s |  |
| 278 | `layer_group_overlap_alpha` | 0 | 0.9s |  |
| 279 | `layer_group_overlap_erase` | 0 | 0.3s |  |
| 280 | `lc_method_type1_args` | 7 | 15.1s |  |
| 281 | `lc_onstatus_type1_args` | 3 | 0.9s |  |
| 282 | `lowq_fill_edges` | 0 | 15.1s |  |
| 283 | `lowq_gradient_orient_probe` | 0 | 16.3s |  |
| 284 | `lowq_sample_point_probe` | 0 | 15.7s |  |
| 285 | `lowq_tsnap_tie_probe` | 0 | 16.0s |  |
| 286 | `lv_cross_swf_version` | 5 | 20.8s |  |
| 287 | `lv_ondata_type1_args` | 3 | 20.1s |  |
| 288 | `mask_nested_intersect` | 1 | 1.3s |  |
| 289 | `mask_sibling_union` | 1 | 1.3s |  |
| 290 | `mc_event_cross_swf_version` | 4 | 1.3s |  |
| 291 | `mc_event_type1_args` | 3 | 20.0s |  |
| 292 | `mc_method_v5_caller_gate` | 4 | 1.3s |  |
| 293 | `mc_resolve_type1_args` | 6 | 1.2s |  |
| 294 | `method_type1_args` | 10 | 1.2s |  |
| 295 | `nc_onstatus_closure` | 2 | 1.2s |  |
| 296 | `nc_onstatus_type1_args` | 3 | 18.9s |  |
| 297 | `onconstruct_cross_swf_version` | 4 | 18.9s |  |
| 298 | `onconstruct_type1_args` | 6 | 0.9s |  |
| 299 | `onload_type1_args` | 7 | 18.6s |  |
| 300 | `onunload_type1_args` | 6 | 0.9s |  |
| 301 | `onunload_type1_local_frame` | 2 | 0.9s |  |
| 302 | `resolve_type1_args` | 13 | 0.9s |  |
| 303 | `root_enterframe_cross_swf_version` | 3 | 19.0s |  |
| 304 | `sort_comparator_captured_scope` | 2 | 1.0s |  |
| 305 | `sort_comparator_type1_args` | 5 | 0.9s |  |
| 306 | `string_prim_method_type1_args` | 19 | 19.1s |  |
| 307 | `timer_cross_swf_version` | 3 | 19.3s |  |
| 308 | `timer_type1_args` | 14 | 19.0s |  |
| 309 | `watch_cross_swf_version` | 6 | 1.1s |  |
| 310 | `watch_mc_reentrant_setmember` | 3 | 0.9s |  |
| 311 | `watch_mc_type1_args` | 7 | 0.9s |  |
| 312 | `watch_setmember_type1_args` | 7 | 0.9s |  |
| 313 | `watch_timeline_named_params` | 4 | 0.9s |  |
| 314 | `watch_timeline_reentrant` | 3 | 0.9s |  |
| 315 | `xml_onload_type1_args` | 3 | 19.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `avm1_nested_child_swapdepths_remove` | 75.0% | 6 | 8 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `avm1_nested_child_swapdepths_remove` | 75.0% | 6/8 | 8 | 8 |  |
