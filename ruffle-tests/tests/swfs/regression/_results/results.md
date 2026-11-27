# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 02:09 UTC

**Git SHA**: `6ee6eded7b`

**Run Duration**: 50m 38s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 302 |
| Passing | **301** (99.7%) |
| Failing | 1 |
| Total expected lines | 3069 |
| Matching lines | 3067 (99.9%) |
| Mismatched lines | 2 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**301 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 24.2s |  |
| 2 | `array_method_type1_args` | 7 | 1.3s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 24.2s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.7s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.6s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.6s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.6s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.6s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.6s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.5s |  |
| 11 | `avm1_array_native_own_method` | 8 | 1.4s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 18.9s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 18.7s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 18.8s |  |
| 15 | `avm1_attached_clip_color` | 2 | 18.7s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 18.8s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 0.5s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 18.8s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 0.9s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 18.8s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.0s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 18.9s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 19.1s |  |
| 24 | `avm1_attached_clip_selfgoto_trace` | 14 | 19.4s |  |
| 25 | `avm1_attached_clip_tagorder` | 34 | 19.4s |  |
| 26 | `avm1_attached_clip_tagorder_nonroot` | 34 | 1.1s |  |
| 27 | `avm1_attached_clip_tagorder_po3` | 34 | 1.0s |  |
| 28 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.0s |  |
| 29 | `avm1_attached_clip_timeline_child_parent` | 6 | 19.1s |  |
| 30 | `avm1_bare_depth_methods_v7_gate` | 6 | 0.9s |  |
| 31 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 0.3s |  |
| 32 | `avm1_bare_mc_method_scope` | 19 | 1.2s |  |
| 33 | `avm1_bitmap_nearest_tie_stage` | 1 | 18.9s |  |
| 34 | `avm1_bitmapdata_draw_child_color` | 5 | 18.6s |  |
| 35 | `avm1_bitmapdata_draw_edittext` | 3 | 0.9s |  |
| 36 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 18.7s |  |
| 37 | `avm1_browser_eager_init` | 10 | 18.9s |  |
| 38 | `avm1_browser_gated_color` | 3 | 0.9s |  |
| 39 | `avm1_browser_gated_depth` | 7 | 0.9s |  |
| 40 | `avm1_browser_gated_textfield` | 7 | 0.9s |  |
| 41 | `avm1_browser_parked_frame` | 7 | 18.6s |  |
| 42 | `avm1_button_pick_order` | 9 | 1.7s |  |
| 43 | `avm1_button_textfield_path_binding` | 4 | 18.9s |  |
| 44 | `avm1_child_timeline_advance` | 23 | 19.1s |  |
| 45 | `avm1_child_timeline_frame1_stop` | 7 | 1.1s |  |
| 46 | `avm1_child_timeline_holder_stop` | 26 | 1.1s |  |
| 47 | `avm1_child_timeline_loop` | 32 | 1.1s |  |
| 48 | `avm1_clipevent_root_goto_stopped` | 3 | 19.0s |  |
| 49 | `avm1_clone_depth_overflow` | 3 | 19.6s |  |
| 50 | `avm1_clone_depth_removed_reuse` | 4 | 0.9s |  |
| 51 | `avm1_closure_base_clip_root_frame` | 5 | 1.0s |  |
| 52 | `avm1_closure_method_scope` | 7 | 1.0s |  |
| 53 | `avm1_create_text_field_depth` | 9 | 18.8s |  |
| 54 | `avm1_cxform_override_overflow` | 2 | 19.0s |  |
| 55 | `avm1_definetext_matrix` | 0 | 0.9s |  |
| 56 | `avm1_device_edittext_xscale` | 7 | 18.8s |  |
| 57 | `avm1_display_filter_growth_edge_scale` | 0 | 0.9s |  |
| 58 | `avm1_display_prop_coercion` | 36 | 1.1s |  |
| 59 | `avm1_drawapi_stroke_snap` | 1 | 18.6s |  |
| 60 | `avm1_drawing_stroke_scale` | 0 | 20.0s |  |
| 61 | `avm1_dynclip_color_transform` | 2 | 1.1s |  |
| 62 | `avm1_edittext_border_subpixel` | 1 | 18.6s |  |
| 63 | `avm1_edittext_cut_copy_selection` | 9 | 15.9s |  |
| 64 | `avm1_edittext_html_delete_runs` | 4 | 15.8s |  |
| 65 | `avm1_edittext_html_typed_runs` | 3 | 1.1s |  |
| 66 | `avm1_edittext_maxchars_clips_insertion` | 4 | 15.5s |  |
| 67 | `avm1_edittext_path_variable_same_frame` | 11 | 17.5s |  |
| 68 | `avm1_edittext_path_variable_scope` | 10 | 1.2s |  |
| 69 | `avm1_edittext_placed_cxform` | 0 | 18.2s |  |
| 70 | `avm1_edittext_placed_cxform_script` | 3 | 1.1s |  |
| 71 | `avm1_edittext_restrict_onchanged` | 6 | 1.1s |  |
| 72 | `avm1_edittext_rotated_borders` | 0 | 17.1s |  |
| 73 | `avm1_edittext_rotated_color` | 0 | 1.5s |  |
| 74 | `avm1_edittext_rotated_glyphs` | 0 | 1.5s |  |
| 75 | `avm1_edittext_rotated_paragraph` | 0 | 24.4s |  |
| 76 | `avm1_edittext_scaled_glyphs` | 0 | 1.4s |  |
| 77 | `avm1_edittext_tab_render` | 1 | 24.1s |  |
| 78 | `avm1_edittext_tabstops_metric` | 9 | 24.6s |  |
| 79 | `avm1_edittext_wordwrap_render` | 5 | 24.1s |  |
| 80 | `avm1_empty_clip_drawing_depth_order` | 1 | 1.7s |  |
| 81 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 24.6s |  |
| 82 | `avm1_enterframe_root_goto_opcode` | 7 | 24.1s |  |
| 83 | `avm1_exec_order_attached_selfremove` | 18 | 24.9s |  |
| 84 | `avm1_exec_order_dynamic_eligible` | 35 | 24.8s |  |
| 85 | `avm1_filter_list_overflow` | 2 | 24.3s |  |
| 86 | `avm1_func2_param_register_oob` | 4 | 1.4s |  |
| 87 | `avm1_gnash_flash_probes` | 63 | 24.8s |  |
| 88 | `avm1_gnash_flash_probes_v5` | 77 | 0.5s |  |
| 89 | `avm1_gnash_flash_probes_v6` | 63 | 0.5s |  |
| 90 | `avm1_goto_backward_enterframe_once` | 22 | 25.0s |  |
| 91 | `avm1_goto_current_frame_clip` | 23 | 2.2s |  |
| 92 | `avm1_goto_current_frame_root` | 22 | 1.7s |  |
| 93 | `avm1_goto_skipped_init_call` | 6 | 18.9s |  |
| 94 | `avm1_goto_skipped_init_script` | 5 | 1.0s |  |
| 95 | `avm1_goto_skipped_init_timer` | 6 | 1.1s |  |
| 96 | `avm1_hairline_scaled_instances` | 1 | 18.7s |  |
| 97 | `avm1_hittest_hairline` | 28 | 18.9s |  |
| 98 | `avm1_hittest_shape_stale_matrix` | 28 | 18.9s |  |
| 99 | `avm1_holder_drawing_under_children` | 1 | 18.5s |  |
| 100 | `avm1_jpeg3_alpha_bitmap` | 0 | 18.4s |  |
| 101 | `avm1_key_isdown_protected` | 8 | 18.4s |  |
| 102 | `avm1_loaded_bare_goto` | 17 | 18.9s |  |
| 103 | `avm1_loaded_bare_goto_seq` | 4 | 19.4s |  |
| 104 | `avm1_loaded_goto_play_deferred` | 31 | 19.1s |  |
| 105 | `avm1_loaded_order_create_vs_load` | 33 | 1.4s |  |
| 106 | `avm1_loaded_shell_consumers_seq` | 12 | 18.9s |  |
| 107 | `avm1_loaded_shell_root_lookup` | 4 | 18.8s |  |
| 108 | `avm1_loaded_timeline_holder` | 7 | 1.1s |  |
| 109 | `avm1_loaded_unload_deferred` | 5 | 1.1s |  |
| 110 | `avm1_loadvars_ondata_overflow` | 23 | 18.8s |  |
| 111 | `avm1_long_text_layout` | 2 | 1.0s |  |
| 112 | `avm1_many_chars_registry` | 4 | 18.9s |  |
| 113 | `avm1_many_defs_registry` | 13 | 20.1s |  |
| 114 | `avm1_many_functions_registry` | 3 | 8.3s |  |
| 115 | `avm1_mc_button_unified_pick` | 21 | 1.2s |  |
| 116 | `avm1_mc_resolve` | 5 | 0.9s |  |
| 117 | `avm1_mcl_holder_totalframes` | 5 | 1.1s |  |
| 118 | `avm1_mcl_load_tick` | 15 | 1.1s |  |
| 119 | `avm1_morph_instances_ratio` | 2 | 18.6s |  |
| 120 | `avm1_nested_po3_filters` | 12 | 1.1s |  |
| 121 | `avm1_onunload_setvar_scope` | 5 | 18.6s |  |
| 122 | `avm1_parent_as3_child_payload` | 2 | 1.2s |  |
| 123 | `avm1_parent_child_bitmap` | 5 | 1.2s |  |
| 124 | `avm1_parent_child_bitmap_fill` | 3 | 1.3s |  |
| 125 | `avm1_parent_child_modify_place` | 5 | 1.3s |  |
| 126 | `avm1_parent_child_morph` | 8 | 1.3s |  |
| 127 | `avm1_parent_child_render` | 7 | 1.3s |  |
| 128 | `avm1_parent_child_sprite_meta` | 8 | 1.3s |  |
| 129 | `avm1_parent_child_text` | 8 | 1.3s |  |
| 130 | `avm1_pixelbounds_dynamic_child` | 1 | 16.6s |  |
| 131 | `avm1_place_occupied_depth_swf5` | 6 | 1.1s |  |
| 132 | `avm1_placed_drawing_color` | 1 | 19.0s |  |
| 133 | `avm1_po3_cm_alpha_bias_edge` | 0 | 0.9s |  |
| 134 | `avm1_po3_cm_folded_clear` | 1 | 1.0s |  |
| 135 | `avm1_po3_cm_live_under_cxform` | 0 | 0.9s |  |
| 136 | `avm1_po3_color_matrix_live` | 0 | 0.9s |  |
| 137 | `avm1_po3_color_matrix_live_clear` | 1 | 0.9s |  |
| 138 | `avm1_po3_color_matrix_live_nested` | 0 | 0.9s |  |
| 139 | `avm1_remove_same_name_other_parent` | 4 | 18.8s |  |
| 140 | `avm1_remove_unload_finalize_overflow` | 4 | 20.9s |  |
| 141 | `avm1_removed_clip_dprops_gc` | 14 | 1.1s |  |
| 142 | `avm1_resolve_dotted_getvariable` | 13 | 18.9s |  |
| 143 | `avm1_root_identity_and_playhead` | 3 | 19.0s |  |
| 144 | `avm1_root_onload_child_order` | 11 | 19.0s |  |
| 145 | `avm1_root_onload_proto` | 7 | 0.9s |  |
| 146 | `avm1_runtime_filters` | 3 | 18.9s |  |
| 147 | `avm1_runtime_filters_cm_bitmap` | 5 | 0.8s |  |
| 148 | `avm1_set_new_text_format_color` | 4 | 18.6s |  |
| 149 | `avm1_set_new_text_format_instance` | 5 | 0.8s |  |
| 150 | `avm1_set_new_text_format_paragraph` | 12 | 0.9s |  |
| 151 | `avm1_set_new_text_format_render` | 5 | 18.4s |  |
| 152 | `avm1_set_new_text_format_size` | 5 | 24.1s |  |
| 153 | `avm1_sprite_goto_script_overflow` | 65 | 24.3s |  |
| 154 | `avm1_stroke_hinting_caps` | 1 | 1.7s |  |
| 155 | `avm1_stroke_join_cap_snap` | 0 | 27.1s |  |
| 156 | `avm1_stroke_noscale_signed` | 0 | 24.5s |  |
| 157 | `avm1_stroke_pixel_snap` | 1 | 24.5s |  |
| 158 | `avm1_stroke_pixel_snap_matrix` | 0 | 24.8s |  |
| 159 | `avm1_stroke_seam_caps` | 1 | 25.3s |  |
| 160 | `avm1_stroke_style_id_order` | 1 | 24.3s |  |
| 161 | `avm1_swf6_case_insensitive_builtins` | 42 | 1.8s |  |
| 162 | `avm1_swf7_case_sensitive_builtins` | 40 | 24.6s |  |
| 163 | `avm1_textfield_attached_depth_order` | 1 | 24.1s |  |
| 164 | `avm1_textfield_ctor_shadow_swf6` | 2 | 1.5s |  |
| 165 | `avm1_textfield_ctor_shadow_swf7` | 2 | 0.4s |  |
| 166 | `avm1_textfield_x_bounds_offset` | 10 | 24.0s |  |
| 167 | `avm1_timer_clock_model` | 19 | 24.4s |  |
| 168 | `avm1_timer_function_form_activation` | 3 | 24.0s |  |
| 169 | `avm1_timer_method_form` | 6 | 1.6s |  |
| 170 | `avm1_timer_native_method_play` | 3 | 1.5s |  |
| 171 | `avm1_timer_overflow` | 10 | 2.2s |  |
| 172 | `avm1_timer_root_goto_stopped_gs` | 3 | 17.8s |  |
| 173 | `avm1_timer_root_goto_stopped_nf` | 3 | 1.0s |  |
| 174 | `avm1_type2_mc_receiver_dispatch` | 7 | 1.1s |  |
| 175 | `avm1_watch_long_name` | 9 | 1.1s |  |
| 176 | `avm1_watch_overflow` | 2 | 1.6s |  |
| 177 | `avm1_wrap_giveup_mixed_runs` | 2 | 1.1s |  |
| 178 | `avm1_xml_first_action_proto` | 2 | 1.1s |  |
| 179 | `avm1_xmlnode_first_action_proto` | 2 | 1.0s |  |
| 180 | `avm1_xscale_double_readback` | 8 | 1.2s |  |
| 181 | `avm2_activation_vtable_bounded` | 5 | 6.4s |  |
| 182 | `avm2_agi_shell` | 6 | 8.4s |  |
| 183 | `avm2_applyfilter_bevel_sample` | 441 | 24.1s |  |
| 184 | `avm2_applyfilter_glow_kernels` | 23 | 9.0s |  |
| 185 | `avm2_applyfilter_gradient_opaque` | 26 | 10.0s |  |
| 186 | `avm2_array_growth_bounded` | 5 | 9.5s |  |
| 187 | `avm2_bitmapdata_draw_edittext_box` | 5 | 8.5s |  |
| 188 | `avm2_bitmapdata_draw_filtered` | 13 | 8.5s |  |
| 189 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 9.3s |  |
| 190 | `avm2_bitmapdata_draw_textfield` | 5 | 8.9s |  |
| 191 | `avm2_bitmapdata_palettemap_index` | 5 | 2.8s |  |
| 192 | `avm2_child_simplebutton` | 10 | 24.0s |  |
| 193 | `avm2_contextmenu_stub` | 4 | 5.8s |  |
| 194 | `avm2_definetext_matrix` | 0 | 5.9s |  |
| 195 | `avm2_drawapi_stroke_snap` | 1 | 23.8s |  |
| 196 | `avm2_e4x_parse_bounded` | 18 | 6.8s |  |
| 197 | `avm2_edittext_placed_cxform` | 0 | 23.5s |  |
| 198 | `avm2_edittext_selection_cxform` | 2 | 23.9s |  |
| 199 | `avm2_embed_bytearray` | 2 | 5.9s |  |
| 200 | `avm2_external_interface_unavailable` | 8 | 5.9s |  |
| 201 | `avm2_findprop_this_resolution` | 13 | 5.9s |  |
| 202 | `avm2_gc_dynprop_tombstone_purge` | 8 | 6.0s |  |
| 203 | `avm2_gc_string_concat_reclaim` | 10 | 6.0s |  |
| 204 | `avm2_gc_string_survives_collect` | 9 | 5.9s |  |
| 205 | `avm2_goto_catchup_scale` | 4 | 5.9s |  |
| 206 | `avm2_graphics_runtime` | 7 | 5.8s |  |
| 207 | `avm2_group_alpha_cab` | 0 | 23.4s |  |
| 208 | `avm2_group_alpha_filter_cm` | 0 | 5.8s |  |
| 209 | `avm2_group_alpha_layer_aadd` | 0 | 5.8s |  |
| 210 | `avm2_group_alpha_layer_inner` | 0 | 5.8s |  |
| 211 | `avm2_group_alpha_multiply` | 0 | 0.3s |  |
| 212 | `avm2_group_alpha_shadow_shape_a50` | 0 | 23.8s |  |
| 213 | `avm2_json_roundtrip_bounded` | 13 | 6.7s |  |
| 214 | `avm2_layer_group_alpha` | 0 | 6.1s |  |
| 215 | `avm2_layer_group_alpha_transparency` | 0 | 6.0s |  |
| 216 | `avm2_layer_group_erase` | 0 | 0.6s |  |
| 217 | `avm2_layer_group_filtered_child` | 0 | 24.1s |  |
| 218 | `avm2_layer_group_overlap_alpha` | 0 | 6.0s |  |
| 219 | `avm2_loader_stub` | 5 | 5.9s |  |
| 220 | `avm2_localconnection_domain` | 4 | 6.0s |  |
| 221 | `avm2_morph` | 8 | 20.2s |  |
| 222 | `avm2_parent_child_render` | 11 | 26.1s |  |
| 223 | `avm2_parent_child_static_text` | 12 | 6.2s |  |
| 224 | `avm2_parent_child_symbol_stride` | 6 | 24.9s |  |
| 225 | `avm2_parent_child_symbolclass_domain` | 12 | 6.1s |  |
| 226 | `avm2_reflect_trait_hooks` | 30 | 6.2s |  |
| 227 | `avm2_sharedobject_flushstatus` | 4 | 5.9s |  |
| 228 | `avm2_simplebutton_click` | 2 | 5.9s |  |
| 229 | `avm2_slot_default_template` | 34 | 6.2s |  |
| 230 | `avm2_sound_bytes_and_group_format` | 27 | 6.2s |  |
| 231 | `avm2_static_and_store_slots` | 14 | 6.1s |  |
| 232 | `avm2_static_text` | 6 | 6.0s |  |
| 233 | `avm2_strbuf_stale_prefix` | 21 | 6.0s |  |
| 234 | `avm2_timeline_gradients` | 7 | 24.8s |  |
| 235 | `avm2_timeline_solid` | 6 | 6.8s |  |
| 236 | `avm2_timeline_stroke_gradient` | 9 | 6.8s |  |
| 237 | `avm2_timeline_text` | 4 | 6.2s |  |
| 238 | `avm2_tolerant_verify_quarantine` | 2 | 5.9s |  |
| 239 | `avm2_typed_value_ops` | 30 | 6.0s |  |
| 240 | `bitmap_pool_layer_cap` | 1 | 19.0s |  |
| 241 | `broadcast_cross_swf_version` | 4 | 18.8s |  |
| 242 | `broadcast_type1_args` | 14 | 25.2s |  |
| 243 | `coerce_cross_swf_version` | 7 | 25.2s |  |
| 244 | `coerce_recursion_guard` | 1 | 1.5s |  |
| 245 | `coerce_type1_args` | 9 | 1.5s |  |
| 246 | `convertfloat_type1_this` | 3 | 1.5s |  |
| 247 | `ctor_before_first_call_locals` | 5 | 1.5s |  |
| 248 | `ei_closure_scope_order` | 7 | 1.6s |  |
| 249 | `ei_cross_swf_version` | 2 | 1.5s |  |
| 250 | `ei_mc_this_receiver` | 5 | 1.6s |  |
| 251 | `ei_type1_args` | 7 | 1.6s |  |
| 252 | `enterframe_type1_args` | 8 | 24.3s |  |
| 253 | `fn_call_builtin_type1_args` | 10 | 23.9s |  |
| 254 | `fn_call_type1_args` | 7 | 1.4s |  |
| 255 | `fn_empty_method_type1_args` | 10 | 1.4s |  |
| 256 | `group_alpha_cab` | 0 | 1.4s |  |
| 257 | `group_alpha_filter_cm` | 0 | 1.4s |  |
| 258 | `group_alpha_layer_aadd` | 0 | 1.4s |  |
| 259 | `group_alpha_layer_inner` | 0 | 1.4s |  |
| 260 | `group_alpha_multiply` | 0 | 0.3s |  |
| 261 | `group_alpha_shadow_shape_a50` | 0 | 1.4s |  |
| 262 | `layer_group_alpha_transparency` | 0 | 0.9s |  |
| 263 | `layer_group_filtered_child` | 0 | 18.3s |  |
| 264 | `layer_group_in_add_alpha` | 0 | 0.9s |  |
| 265 | `layer_group_overlap_alpha` | 0 | 0.9s |  |
| 266 | `layer_group_overlap_erase` | 0 | 0.2s |  |
| 267 | `lc_method_type1_args` | 7 | 18.3s |  |
| 268 | `lc_onstatus_type1_args` | 3 | 0.9s |  |
| 269 | `lowq_fill_edges` | 0 | 18.2s |  |
| 270 | `lowq_gradient_orient_probe` | 0 | 18.4s |  |
| 271 | `lowq_sample_point_probe` | 0 | 18.2s |  |
| 272 | `lv_cross_swf_version` | 5 | 25.4s |  |
| 273 | `lv_ondata_type1_args` | 3 | 25.0s |  |
| 274 | `mask_nested_intersect` | 1 | 1.5s |  |
| 275 | `mask_sibling_union` | 1 | 1.4s |  |
| 276 | `mc_event_cross_swf_version` | 4 | 1.5s |  |
| 277 | `mc_event_type1_args` | 3 | 25.2s |  |
| 278 | `mc_method_v5_caller_gate` | 4 | 1.6s |  |
| 279 | `mc_resolve_type1_args` | 6 | 1.7s |  |
| 280 | `method_type1_args` | 10 | 1.3s |  |
| 281 | `nc_onstatus_closure` | 2 | 1.4s |  |
| 282 | `nc_onstatus_type1_args` | 3 | 21.3s |  |
| 283 | `onconstruct_cross_swf_version` | 4 | 21.0s |  |
| 284 | `onconstruct_type1_args` | 6 | 1.2s |  |
| 285 | `onload_type1_args` | 7 | 20.7s |  |
| 286 | `onunload_type1_args` | 6 | 1.2s |  |
| 287 | `onunload_type1_local_frame` | 2 | 1.2s |  |
| 288 | `resolve_type1_args` | 13 | 1.2s |  |
| 289 | `root_enterframe_cross_swf_version` | 3 | 20.9s |  |
| 290 | `sort_comparator_captured_scope` | 2 | 1.4s |  |
| 291 | `sort_comparator_type1_args` | 5 | 1.3s |  |
| 292 | `string_prim_method_type1_args` | 19 | 23.4s |  |
| 293 | `timer_cross_swf_version` | 3 | 23.7s |  |
| 294 | `timer_type1_args` | 14 | 23.6s |  |
| 295 | `watch_cross_swf_version` | 6 | 1.6s |  |
| 296 | `watch_mc_reentrant_setmember` | 3 | 1.4s |  |
| 297 | `watch_mc_type1_args` | 7 | 1.4s |  |
| 298 | `watch_setmember_type1_args` | 7 | 1.4s |  |
| 299 | `watch_timeline_named_params` | 4 | 1.4s |  |
| 300 | `watch_timeline_reentrant` | 3 | 1.4s |  |
| 301 | `xml_onload_type1_args` | 3 | 23.5s |  |

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
