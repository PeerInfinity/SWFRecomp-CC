# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 18:08 UTC

**Git SHA**: `f4edebdcec`

**Run Duration**: 56m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 319 |
| Passing | **318** (99.7%) |
| Failing | 1 |
| Total expected lines | 3284 |
| Matching lines | 3282 (99.9%) |
| Mismatched lines | 2 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**318 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 1.6s |  |
| 2 | `array_method_type1_args` | 7 | 1.5s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 4.7s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.8s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.7s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.8s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.7s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.7s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.8s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.6s |  |
| 11 | `avm1_array_native_own_method` | 8 | 1.6s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 20.0s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.8s |  |
| 14 | `avm1_attach_timeline_frame_order` | 82 | 20.5s |  |
| 15 | `avm1_attached_clip_button_click` | 13 | 19.8s |  |
| 16 | `avm1_attached_clip_color` | 2 | 22.4s |  |
| 17 | `avm1_attached_clip_goto_play` | 14 | 2.0s |  |
| 18 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.1s |  |
| 19 | `avm1_attached_clip_hidden_capture` | 6 | 20.0s |  |
| 20 | `avm1_attached_clip_holder_render` | 1 | 1.7s |  |
| 21 | `avm1_attached_clip_natural_timeline` | 34 | 19.9s |  |
| 22 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.7s |  |
| 23 | `avm1_attached_clip_samename_child` | 32 | 23.1s |  |
| 24 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 26.1s |  |
| 25 | `avm1_attached_clip_selfgoto_trace` | 14 | 23.8s |  |
| 26 | `avm1_attached_clip_tagorder` | 34 | 24.3s |  |
| 27 | `avm1_attached_clip_tagorder_nonroot` | 34 | 2.5s |  |
| 28 | `avm1_attached_clip_tagorder_po3` | 34 | 2.8s |  |
| 29 | `avm1_attached_clip_tagorder_ratio` | 34 | 2.7s |  |
| 30 | `avm1_attached_clip_timeline_child_parent` | 6 | 23.2s |  |
| 31 | `avm1_bare_depth_methods_v7_gate` | 6 | 22.8s |  |
| 32 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 1.2s |  |
| 33 | `avm1_bare_mc_method_scope` | 19 | 23.3s |  |
| 34 | `avm1_bitmap_nearest_tie_stage` | 1 | 22.6s |  |
| 35 | `avm1_bitmapdata_draw_child_color` | 5 | 19.6s |  |
| 36 | `avm1_bitmapdata_draw_edittext` | 3 | 1.6s |  |
| 37 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 19.9s |  |
| 38 | `avm1_browser_eager_init` | 10 | 19.7s |  |
| 39 | `avm1_browser_gated_color` | 3 | 19.4s |  |
| 40 | `avm1_browser_gated_depth` | 7 | 1.6s |  |
| 41 | `avm1_browser_gated_textfield` | 7 | 1.6s |  |
| 42 | `avm1_browser_parked_frame` | 7 | 19.7s |  |
| 43 | `avm1_button_pick_order` | 9 | 2.4s |  |
| 44 | `avm1_button_textfield_path_binding` | 4 | 19.5s |  |
| 45 | `avm1_child_timeline_advance` | 23 | 19.2s |  |
| 46 | `avm1_child_timeline_frame1_stop` | 7 | 1.7s |  |
| 47 | `avm1_child_timeline_holder_stop` | 26 | 1.8s |  |
| 48 | `avm1_child_timeline_loop` | 32 | 1.8s |  |
| 49 | `avm1_clipevent_root_goto_stopped` | 3 | 19.1s |  |
| 50 | `avm1_clone_depth_overflow` | 3 | 19.8s |  |
| 51 | `avm1_clone_depth_removed_reuse` | 4 | 1.6s |  |
| 52 | `avm1_closure_base_clip_root_frame` | 5 | 1.7s |  |
| 53 | `avm1_closure_method_scope` | 7 | 1.7s |  |
| 54 | `avm1_create_text_field_depth` | 9 | 1.6s |  |
| 55 | `avm1_cxform_override_overflow` | 2 | 21.8s |  |
| 56 | `avm1_definetext_matrix` | 0 | 1.6s |  |
| 57 | `avm1_device_edittext_xscale` | 7 | 19.4s |  |
| 58 | `avm1_display_filter_growth_edge_scale` | 0 | 19.8s |  |
| 59 | `avm1_display_prop_coercion` | 36 | 1.8s |  |
| 60 | `avm1_drawapi_stroke_snap` | 1 | 19.7s |  |
| 61 | `avm1_drawing_stroke_scale` | 0 | 21.0s |  |
| 62 | `avm1_dynclip_color_transform` | 2 | 2.0s |  |
| 63 | `avm1_edittext_border_subpixel` | 1 | 19.5s |  |
| 64 | `avm1_edittext_cut_copy_selection` | 9 | 19.6s |  |
| 65 | `avm1_edittext_html_delete_runs` | 4 | 19.6s |  |
| 66 | `avm1_edittext_html_typed_runs` | 3 | 1.8s |  |
| 67 | `avm1_edittext_maxchars_clips_insertion` | 4 | 25.8s |  |
| 68 | `avm1_edittext_path_variable_same_frame` | 11 | 25.7s |  |
| 69 | `avm1_edittext_path_variable_scope` | 10 | 25.8s |  |
| 70 | `avm1_edittext_placed_cxform` | 0 | 25.7s |  |
| 71 | `avm1_edittext_placed_cxform_script` | 3 | 2.5s |  |
| 72 | `avm1_edittext_restrict_onchanged` | 6 | 2.5s |  |
| 73 | `avm1_edittext_rotated_borders` | 0 | 25.8s |  |
| 74 | `avm1_edittext_rotated_color` | 0 | 25.7s |  |
| 75 | `avm1_edittext_rotated_glyphs` | 0 | 2.5s |  |
| 76 | `avm1_edittext_rotated_paragraph` | 0 | 25.6s |  |
| 77 | `avm1_edittext_scaled_glyphs` | 0 | 2.5s |  |
| 78 | `avm1_edittext_tab_render` | 1 | 22.3s |  |
| 79 | `avm1_edittext_tabstops_metric` | 9 | 19.8s |  |
| 80 | `avm1_edittext_wordwrap_render` | 5 | 19.8s |  |
| 81 | `avm1_empty_clip_drawing_depth_order` | 1 | 20.0s |  |
| 82 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 20.0s |  |
| 83 | `avm1_enterframe_root_goto_opcode` | 7 | 19.7s |  |
| 84 | `avm1_enterframe_root_nextframe` | 22 | 19.9s |  |
| 85 | `avm1_enterframe_sprite_nextframe` | 16 | 1.8s |  |
| 86 | `avm1_exec_order_attached_selfremove` | 18 | 20.2s |  |
| 87 | `avm1_exec_order_dynamic_eligible` | 35 | 1.9s |  |
| 88 | `avm1_filter_list_overflow` | 2 | 2.0s |  |
| 89 | `avm1_func2_param_register_oob` | 4 | 1.6s |  |
| 90 | `avm1_gnash_flash_probes` | 63 | 16.7s |  |
| 91 | `avm1_gnash_flash_probes_v5` | 77 | 1.0s |  |
| 92 | `avm1_gnash_flash_probes_v6` | 63 | 0.9s |  |
| 93 | `avm1_goto_backward_enterframe_once` | 22 | 16.6s |  |
| 94 | `avm1_goto_current_frame_clip` | 23 | 17.1s |  |
| 95 | `avm1_goto_current_frame_root` | 22 | 16.7s |  |
| 96 | `avm1_goto_skipped_init_call` | 6 | 16.9s |  |
| 97 | `avm1_goto_skipped_init_script` | 5 | 2.0s |  |
| 98 | `avm1_goto_skipped_init_timer` | 6 | 1.9s |  |
| 99 | `avm1_goto_target_child_order_gotoscript` | 6 | 17.3s |  |
| 100 | `avm1_goto_target_child_order_interval` | 7 | 20.5s |  |
| 101 | `avm1_goto_target_child_order_normal` | 5 | 20.3s |  |
| 102 | `avm1_hairline_scaled_instances` | 1 | 23.0s |  |
| 103 | `avm1_hittest_hairline` | 28 | 20.6s |  |
| 104 | `avm1_hittest_shape_stale_matrix` | 28 | 20.6s |  |
| 105 | `avm1_holder_drawing_under_children` | 1 | 20.4s |  |
| 106 | `avm1_jpeg3_alpha_bitmap` | 0 | 20.7s |  |
| 107 | `avm1_key_isdown_protected` | 8 | 2.2s |  |
| 108 | `avm1_loaded_bare_goto` | 17 | 21.6s |  |
| 109 | `avm1_loaded_bare_goto_seq` | 4 | 2.7s |  |
| 110 | `avm1_loaded_goto_play_deferred` | 31 | 22.0s |  |
| 111 | `avm1_loaded_order_create_vs_load` | 33 | 17.0s |  |
| 112 | `avm1_loaded_shell_consumers_seq` | 12 | 16.7s |  |
| 113 | `avm1_loaded_shell_root_lookup` | 4 | 16.6s |  |
| 114 | `avm1_loaded_timeline_holder` | 7 | 1.9s |  |
| 115 | `avm1_loaded_unload_deferred` | 5 | 1.9s |  |
| 116 | `avm1_loadvars_ondata_overflow` | 23 | 16.9s |  |
| 117 | `avm1_long_text_layout` | 2 | 1.9s |  |
| 118 | `avm1_many_chars_registry` | 4 | 16.6s |  |
| 119 | `avm1_many_defs_registry` | 13 | 18.2s |  |
| 120 | `avm1_many_functions_registry` | 3 | 7.8s |  |
| 121 | `avm1_mc_button_unified_pick` | 21 | 17.1s |  |
| 122 | `avm1_mc_resolve` | 5 | 20.9s |  |
| 123 | `avm1_mc_super_native_probe` | 18 | 2.4s |  |
| 124 | `avm1_mcl_holder_totalframes` | 5 | 22.1s |  |
| 125 | `avm1_mcl_load_tick` | 15 | 2.4s |  |
| 126 | `avm1_morph_instances_ratio` | 2 | 24.8s |  |
| 127 | `avm1_nested_po3_filters` | 12 | 3.0s |  |
| 128 | `avm1_onunload_setvar_scope` | 5 | 22.5s |  |
| 129 | `avm1_parent_as3_child_payload` | 2 | 2.4s |  |
| 130 | `avm1_parent_child_bitmap` | 5 | 2.5s |  |
| 131 | `avm1_parent_child_bitmap_fill` | 3 | 2.5s |  |
| 132 | `avm1_parent_child_modify_place` | 5 | 21.1s |  |
| 133 | `avm1_parent_child_morph` | 8 | 5.2s |  |
| 134 | `avm1_parent_child_render` | 7 | 2.6s |  |
| 135 | `avm1_parent_child_sprite_meta` | 8 | 2.4s |  |
| 136 | `avm1_parent_child_text` | 8 | 2.6s |  |
| 137 | `avm1_pixelbounds_dynamic_child` | 1 | 21.3s |  |
| 138 | `avm1_place_occupied_depth_swf5` | 6 | 2.3s |  |
| 139 | `avm1_placed_drawing_color` | 1 | 22.0s |  |
| 140 | `avm1_po3_cm_alpha_bias_edge` | 0 | 3.2s |  |
| 141 | `avm1_po3_cm_folded_clear` | 1 | 2.4s |  |
| 142 | `avm1_po3_cm_live_under_cxform` | 0 | 2.2s |  |
| 143 | `avm1_po3_color_matrix_live` | 0 | 4.4s |  |
| 144 | `avm1_po3_color_matrix_live_clear` | 1 | 1.7s |  |
| 145 | `avm1_po3_color_matrix_live_nested` | 0 | 1.7s |  |
| 146 | `avm1_remove_same_name_other_parent` | 4 | 19.9s |  |
| 147 | `avm1_remove_unload_finalize_overflow` | 4 | 22.0s |  |
| 148 | `avm1_removed_clip_dprops_gc` | 14 | 1.8s |  |
| 149 | `avm1_resolve_dotted_getvariable` | 13 | 1.6s |  |
| 150 | `avm1_root_identity_and_playhead` | 3 | 19.7s |  |
| 151 | `avm1_root_onload_child_order` | 11 | 20.0s |  |
| 152 | `avm1_root_onload_proto` | 7 | 1.7s |  |
| 153 | `avm1_rotation_matrix_fixed` | 7 | 1.7s |  |
| 154 | `avm1_runtime_filters` | 3 | 22.9s |  |
| 155 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.3s |  |
| 156 | `avm1_selfgoto_current_frame_opcode` | 8 | 19.7s |  |
| 157 | `avm1_set_new_text_format_color` | 4 | 19.5s |  |
| 158 | `avm1_set_new_text_format_instance` | 5 | 19.4s |  |
| 159 | `avm1_set_new_text_format_paragraph` | 12 | 1.8s |  |
| 160 | `avm1_set_new_text_format_render` | 5 | 19.6s |  |
| 161 | `avm1_set_new_text_format_size` | 5 | 1.6s |  |
| 162 | `avm1_sprite_goto_script_overflow` | 65 | 19.9s |  |
| 163 | `avm1_stroke_hinting_caps` | 1 | 1.9s |  |
| 164 | `avm1_stroke_join_cap_snap` | 0 | 21.9s |  |
| 165 | `avm1_stroke_noscale_signed` | 0 | 24.6s |  |
| 166 | `avm1_stroke_pixel_snap` | 1 | 21.5s |  |
| 167 | `avm1_stroke_pixel_snap_matrix` | 0 | 22.4s |  |
| 168 | `avm1_stroke_seam_caps` | 1 | 21.3s |  |
| 169 | `avm1_stroke_style_id_order` | 1 | 22.1s |  |
| 170 | `avm1_swf6_case_insensitive_builtins` | 42 | 22.5s |  |
| 171 | `avm1_swf7_case_sensitive_builtins` | 40 | 1.2s |  |
| 172 | `avm1_tabindex_child_null` | 3 | 2.6s |  |
| 173 | `avm1_tabindex_fn2_root_raw` | 4 | 2.2s |  |
| 174 | `avm1_tabindex_fresh_child_coerce` | 4 | 2.1s |  |
| 175 | `avm1_tabindex_mtasc_class_main` | 6 | 2.3s |  |
| 176 | `avm1_tabindex_read_first_coerce` | 5 | 1.6s |  |
| 177 | `avm1_textfield_attached_depth_order` | 1 | 19.9s |  |
| 178 | `avm1_textfield_ctor_shadow_swf6` | 2 | 1.6s |  |
| 179 | `avm1_textfield_ctor_shadow_swf7` | 2 | 0.9s |  |
| 180 | `avm1_textfield_x_bounds_offset` | 10 | 19.4s |  |
| 181 | `avm1_timer_clock_model` | 12 | 19.6s |  |
| 182 | `avm1_timer_function_form_activation` | 3 | 19.6s |  |
| 183 | `avm1_timer_late_frame_check` | 29 | 19.6s |  |
| 184 | `avm1_timer_method_form` | 6 | 19.2s |  |
| 185 | `avm1_timer_native_method_play` | 3 | 1.6s |  |
| 186 | `avm1_timer_overflow` | 10 | 2.1s |  |
| 187 | `avm1_timer_root_goto_stopped_gs` | 3 | 20.3s |  |
| 188 | `avm1_timer_root_goto_stopped_nf` | 3 | 1.6s |  |
| 189 | `avm1_type2_mc_receiver_dispatch` | 7 | 20.2s |  |
| 190 | `avm1_watch_long_name` | 9 | 1.7s |  |
| 191 | `avm1_watch_overflow` | 2 | 2.3s |  |
| 192 | `avm1_wrap_giveup_mixed_runs` | 2 | 1.7s |  |
| 193 | `avm1_xml_first_action_proto` | 2 | 1.6s |  |
| 194 | `avm1_xmlnode_first_action_proto` | 2 | 1.6s |  |
| 195 | `avm1_xscale_double_readback` | 8 | 1.8s |  |
| 196 | `avm2_activation_vtable_bounded` | 5 | 7.9s |  |
| 197 | `avm2_agi_shell` | 6 | 7.3s |  |
| 198 | `avm2_applyfilter_bevel_sample` | 441 | 17.7s |  |
| 199 | `avm2_applyfilter_glow_kernels` | 23 | 7.5s |  |
| 200 | `avm2_applyfilter_gradient_opaque` | 26 | 8.1s |  |
| 201 | `avm2_array_growth_bounded` | 5 | 8.1s |  |
| 202 | `avm2_bitmapdata_draw_edittext_box` | 5 | 7.2s |  |
| 203 | `avm2_bitmapdata_draw_filtered` | 13 | 7.3s |  |
| 204 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 7.7s |  |
| 205 | `avm2_bitmapdata_draw_textfield` | 5 | 7.4s |  |
| 206 | `avm2_bitmapdata_palettemap_index` | 5 | 7.2s |  |
| 207 | `avm2_child_simplebutton` | 10 | 25.6s |  |
| 208 | `avm2_contextmenu_stub` | 4 | 7.2s |  |
| 209 | `avm2_definetext_matrix` | 0 | 27.7s |  |
| 210 | `avm2_drawapi_stroke_snap` | 1 | 25.4s |  |
| 211 | `avm2_e4x_parse_bounded` | 18 | 8.2s |  |
| 212 | `avm2_edittext_placed_cxform` | 0 | 25.5s |  |
| 213 | `avm2_edittext_selection_cxform` | 2 | 25.4s |  |
| 214 | `avm2_embed_bytearray` | 2 | 7.2s |  |
| 215 | `avm2_external_interface_unavailable` | 8 | 7.2s |  |
| 216 | `avm2_findprop_this_resolution` | 13 | 7.2s |  |
| 217 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.3s |  |
| 218 | `avm2_gc_string_concat_reclaim` | 10 | 7.3s |  |
| 219 | `avm2_gc_string_survives_collect` | 9 | 2.6s |  |
| 220 | `avm2_goto_catchup_scale` | 4 | 7.4s |  |
| 221 | `avm2_graphics_runtime` | 7 | 28.6s |  |
| 222 | `avm2_group_alpha_cab` | 0 | 26.0s |  |
| 223 | `avm2_group_alpha_filter_cm` | 0 | 7.5s |  |
| 224 | `avm2_group_alpha_layer_aadd` | 0 | 7.4s |  |
| 225 | `avm2_group_alpha_layer_inner` | 0 | 7.4s |  |
| 226 | `avm2_group_alpha_multiply` | 0 | 1.1s |  |
| 227 | `avm2_group_alpha_shadow_shape_a50` | 0 | 7.5s |  |
| 228 | `avm2_json_roundtrip_bounded` | 13 | 8.1s |  |
| 229 | `avm2_layer_group_alpha` | 0 | 8.2s |  |
| 230 | `avm2_layer_group_alpha_transparency` | 0 | 28.2s |  |
| 231 | `avm2_layer_group_erase` | 0 | 1.5s |  |
| 232 | `avm2_layer_group_filtered_child` | 0 | 25.6s |  |
| 233 | `avm2_layer_group_overlap_alpha` | 0 | 7.3s |  |
| 234 | `avm2_loader_stub` | 5 | 7.3s |  |
| 235 | `avm2_localconnection_domain` | 4 | 7.3s |  |
| 236 | `avm2_morph` | 8 | 25.7s |  |
| 237 | `avm2_parent_child_render` | 11 | 9.5s |  |
| 238 | `avm2_parent_child_static_text` | 12 | 7.5s |  |
| 239 | `avm2_parent_child_symbol_stride` | 6 | 37.5s |  |
| 240 | `avm2_parent_child_symbolclass_domain` | 12 | 10.4s |  |
| 241 | `avm2_reflect_trait_hooks` | 30 | 10.4s |  |
| 242 | `avm2_sharedobject_flushstatus` | 4 | 10.0s |  |
| 243 | `avm2_simplebutton_click` | 2 | 9.8s |  |
| 244 | `avm2_slot_default_template` | 34 | 10.5s |  |
| 245 | `avm2_sound_bytes_and_group_format` | 27 | 10.3s |  |
| 246 | `avm2_static_and_store_slots` | 14 | 10.2s |  |
| 247 | `avm2_static_text` | 6 | 35.0s |  |
| 248 | `avm2_strbuf_stale_prefix` | 21 | 10.5s |  |
| 249 | `avm2_timeline_gradients` | 7 | 28.7s |  |
| 250 | `avm2_timeline_solid` | 6 | 8.0s |  |
| 251 | `avm2_timeline_stroke_gradient` | 9 | 8.2s |  |
| 252 | `avm2_timeline_text` | 4 | 7.5s |  |
| 253 | `avm2_tolerant_verify_quarantine` | 2 | 7.2s |  |
| 254 | `avm2_typed_value_ops` | 30 | 7.3s |  |
| 255 | `bitmap_pool_layer_cap` | 1 | 21.4s |  |
| 256 | `broadcast_cross_swf_version` | 4 | 19.5s |  |
| 257 | `broadcast_type1_args` | 14 | 1.6s |  |
| 258 | `coerce_cross_swf_version` | 7 | 1.6s |  |
| 259 | `coerce_recursion_guard` | 1 | 1.5s |  |
| 260 | `coerce_type1_args` | 9 | 1.5s |  |
| 261 | `convertfloat_type1_this` | 3 | 1.5s |  |
| 262 | `ctor_before_first_call_locals` | 5 | 1.6s |  |
| 263 | `ei_closure_scope_order` | 7 | 1.6s |  |
| 264 | `ei_cross_swf_version` | 2 | 1.5s |  |
| 265 | `ei_mc_this_receiver` | 5 | 19.3s |  |
| 266 | `ei_type1_args` | 7 | 1.6s |  |
| 267 | `enterframe_type1_args` | 8 | 19.1s |  |
| 268 | `fn_call_builtin_type1_args` | 10 | 1.5s |  |
| 269 | `fn_call_type1_args` | 7 | 1.7s |  |
| 270 | `fn_empty_method_type1_args` | 10 | 1.6s |  |
| 271 | `group_alpha_cab` | 0 | 4.4s |  |
| 272 | `group_alpha_filter_cm` | 0 | 1.8s |  |
| 273 | `group_alpha_layer_aadd` | 0 | 1.7s |  |
| 274 | `group_alpha_layer_inner` | 0 | 1.7s |  |
| 275 | `group_alpha_multiply` | 0 | 0.9s |  |
| 276 | `group_alpha_shadow_shape_a50` | 0 | 1.8s |  |
| 277 | `layer_group_alpha_transparency` | 0 | 0.9s |  |
| 278 | `layer_group_filtered_child` | 0 | 20.0s |  |
| 279 | `layer_group_in_add_alpha` | 0 | 1.3s |  |
| 280 | `layer_group_overlap_alpha` | 0 | 0.8s |  |
| 281 | `layer_group_overlap_erase` | 0 | 0.8s |  |
| 282 | `lc_method_type1_args` | 7 | 0.7s |  |
| 283 | `lc_onstatus_type1_args` | 3 | 0.7s |  |
| 284 | `lowq_fill_edges` | 0 | 0.8s |  |
| 285 | `lowq_gradient_orient_probe` | 0 | 0.9s |  |
| 286 | `lowq_sample_point_probe` | 0 | 0.8s |  |
| 287 | `lowq_stroke_probe` | 0 | 1.0s |  |
| 288 | `lowq_tsnap_tie_probe` | 0 | 0.8s |  |
| 289 | `lv_cross_swf_version` | 5 | 18.9s |  |
| 290 | `lv_ondata_type1_args` | 3 | 18.9s |  |
| 291 | `mask_nested_intersect` | 1 | 22.2s |  |
| 292 | `mask_sibling_union` | 1 | 1.4s |  |
| 293 | `mc_event_cross_swf_version` | 4 | 1.4s |  |
| 294 | `mc_event_type1_args` | 3 | 1.3s |  |
| 295 | `mc_method_v5_caller_gate` | 4 | 1.4s |  |
| 296 | `mc_resolve_type1_args` | 6 | 1.3s |  |
| 297 | `method_type1_args` | 10 | 1.3s |  |
| 298 | `nc_onstatus_closure` | 2 | 1.3s |  |
| 299 | `nc_onstatus_type1_args` | 3 | 1.5s |  |
| 300 | `onconstruct_cross_swf_version` | 4 | 19.5s |  |
| 301 | `onconstruct_type1_args` | 6 | 1.5s |  |
| 302 | `onload_type1_args` | 7 | 19.3s |  |
| 303 | `onunload_type1_args` | 6 | 1.6s |  |
| 304 | `onunload_type1_local_frame` | 2 | 1.6s |  |
| 305 | `resolve_type1_args` | 13 | 1.6s |  |
| 306 | `root_enterframe_cross_swf_version` | 3 | 19.4s |  |
| 307 | `sort_comparator_captured_scope` | 2 | 1.7s |  |
| 308 | `sort_comparator_type1_args` | 5 | 1.5s |  |
| 309 | `string_prim_method_type1_args` | 19 | 1.6s |  |
| 310 | `timer_cross_swf_version` | 3 | 19.8s |  |
| 311 | `timer_type1_args` | 14 | 19.6s |  |
| 312 | `watch_cross_swf_version` | 6 | 1.7s |  |
| 313 | `watch_mc_reentrant_setmember` | 3 | 1.6s |  |
| 314 | `watch_mc_type1_args` | 7 | 1.6s |  |
| 315 | `watch_setmember_type1_args` | 7 | 1.6s |  |
| 316 | `watch_timeline_named_params` | 4 | 1.6s |  |
| 317 | `watch_timeline_reentrant` | 3 | 1.5s |  |
| 318 | `xml_onload_type1_args` | 3 | 19.6s |  |

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
