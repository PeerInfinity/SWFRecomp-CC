# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 01:51 UTC

**Git SHA**: `6ee6eded7b`

**Run Duration**: 66m 58s

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
| 1 | `array_element_type1_args` | 7 | 15.4s |  |
| 2 | `array_method_type1_args` | 7 | 1.5s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 18.1s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.7s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.7s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.6s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.7s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.7s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.7s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.6s |  |
| 11 | `avm1_array_native_own_method` | 8 | 1.6s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 25.7s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 25.4s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 26.1s |  |
| 15 | `avm1_attached_clip_color` | 2 | 28.9s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 25.8s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.7s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 25.8s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 2.6s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 25.8s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 2.6s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 25.7s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 24.2s |  |
| 24 | `avm1_attached_clip_selfgoto_trace` | 14 | 21.5s |  |
| 25 | `avm1_attached_clip_tagorder` | 34 | 20.2s |  |
| 26 | `avm1_attached_clip_tagorder_nonroot` | 34 | 2.6s |  |
| 27 | `avm1_attached_clip_tagorder_po3` | 34 | 2.6s |  |
| 28 | `avm1_attached_clip_tagorder_ratio` | 34 | 2.6s |  |
| 29 | `avm1_attached_clip_timeline_child_parent` | 6 | 18.9s |  |
| 30 | `avm1_bare_depth_methods_v7_gate` | 6 | 18.2s |  |
| 31 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 1.2s |  |
| 32 | `avm1_bare_mc_method_scope` | 19 | 18.9s |  |
| 33 | `avm1_bitmap_nearest_tie_stage` | 1 | 30.4s |  |
| 34 | `avm1_bitmapdata_draw_child_color` | 5 | 25.8s |  |
| 35 | `avm1_bitmapdata_draw_edittext` | 3 | 2.5s |  |
| 36 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 26.4s |  |
| 37 | `avm1_browser_eager_init` | 10 | 26.5s |  |
| 38 | `avm1_browser_gated_color` | 3 | 25.7s |  |
| 39 | `avm1_browser_gated_depth` | 7 | 2.5s |  |
| 40 | `avm1_browser_gated_textfield` | 7 | 2.5s |  |
| 41 | `avm1_browser_parked_frame` | 7 | 26.5s |  |
| 42 | `avm1_button_pick_order` | 9 | 3.9s |  |
| 43 | `avm1_button_textfield_path_binding` | 4 | 19.5s |  |
| 44 | `avm1_child_timeline_advance` | 23 | 19.5s |  |
| 45 | `avm1_child_timeline_frame1_stop` | 7 | 1.8s |  |
| 46 | `avm1_child_timeline_holder_stop` | 26 | 1.8s |  |
| 47 | `avm1_child_timeline_loop` | 32 | 1.9s |  |
| 48 | `avm1_clipevent_root_goto_stopped` | 3 | 19.5s |  |
| 49 | `avm1_clone_depth_overflow` | 3 | 20.1s |  |
| 50 | `avm1_clone_depth_removed_reuse` | 4 | 1.6s |  |
| 51 | `avm1_closure_base_clip_root_frame` | 5 | 1.8s |  |
| 52 | `avm1_closure_method_scope` | 7 | 1.7s |  |
| 53 | `avm1_create_text_field_depth` | 9 | 19.6s |  |
| 54 | `avm1_cxform_override_overflow` | 2 | 20.0s |  |
| 55 | `avm1_definetext_matrix` | 0 | 1.7s |  |
| 56 | `avm1_device_edittext_xscale` | 7 | 19.7s |  |
| 57 | `avm1_display_filter_growth_edge_scale` | 0 | 2.0s |  |
| 58 | `avm1_display_prop_coercion` | 36 | 1.8s |  |
| 59 | `avm1_drawapi_stroke_snap` | 1 | 19.9s |  |
| 60 | `avm1_drawing_stroke_scale` | 0 | 21.4s |  |
| 61 | `avm1_dynclip_color_transform` | 2 | 2.0s |  |
| 62 | `avm1_edittext_border_subpixel` | 1 | 19.9s |  |
| 63 | `avm1_edittext_cut_copy_selection` | 9 | 19.7s |  |
| 64 | `avm1_edittext_html_delete_runs` | 4 | 19.8s |  |
| 65 | `avm1_edittext_html_typed_runs` | 3 | 1.8s |  |
| 66 | `avm1_edittext_maxchars_clips_insertion` | 4 | 19.6s |  |
| 67 | `avm1_edittext_path_variable_same_frame` | 11 | 19.8s |  |
| 68 | `avm1_edittext_path_variable_scope` | 10 | 1.8s |  |
| 69 | `avm1_edittext_placed_cxform` | 0 | 19.7s |  |
| 70 | `avm1_edittext_placed_cxform_script` | 3 | 1.6s |  |
| 71 | `avm1_edittext_restrict_onchanged` | 6 | 1.6s |  |
| 72 | `avm1_edittext_rotated_borders` | 0 | 19.7s |  |
| 73 | `avm1_edittext_rotated_color` | 0 | 28.5s |  |
| 74 | `avm1_edittext_rotated_glyphs` | 0 | 2.5s |  |
| 75 | `avm1_edittext_rotated_paragraph` | 0 | 25.2s |  |
| 76 | `avm1_edittext_scaled_glyphs` | 0 | 2.5s |  |
| 77 | `avm1_edittext_tab_render` | 1 | 25.2s |  |
| 78 | `avm1_edittext_tabstops_metric` | 9 | 25.2s |  |
| 79 | `avm1_edittext_wordwrap_render` | 5 | 25.1s |  |
| 80 | `avm1_empty_clip_drawing_depth_order` | 1 | 25.3s |  |
| 81 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 25.4s |  |
| 82 | `avm1_enterframe_root_goto_opcode` | 7 | 25.1s |  |
| 83 | `avm1_exec_order_attached_selfremove` | 18 | 20.0s |  |
| 84 | `avm1_exec_order_dynamic_eligible` | 35 | 20.1s |  |
| 85 | `avm1_filter_list_overflow` | 2 | 20.0s |  |
| 86 | `avm1_func2_param_register_oob` | 4 | 1.6s |  |
| 87 | `avm1_gnash_flash_probes` | 63 | 20.1s |  |
| 88 | `avm1_gnash_flash_probes_v5` | 77 | 0.9s |  |
| 89 | `avm1_gnash_flash_probes_v6` | 63 | 0.9s |  |
| 90 | `avm1_goto_backward_enterframe_once` | 22 | 19.9s |  |
| 91 | `avm1_goto_current_frame_clip` | 23 | 2.2s |  |
| 92 | `avm1_goto_current_frame_root` | 22 | 1.8s |  |
| 93 | `avm1_goto_skipped_init_call` | 6 | 26.8s |  |
| 94 | `avm1_goto_skipped_init_script` | 5 | 2.5s |  |
| 95 | `avm1_goto_skipped_init_timer` | 6 | 2.5s |  |
| 96 | `avm1_hairline_scaled_instances` | 1 | 30.3s |  |
| 97 | `avm1_hittest_hairline` | 28 | 28.3s |  |
| 98 | `avm1_hittest_shape_stale_matrix` | 28 | 27.5s |  |
| 99 | `avm1_holder_drawing_under_children` | 1 | 28.1s |  |
| 100 | `avm1_jpeg3_alpha_bitmap` | 0 | 27.3s |  |
| 101 | `avm1_key_isdown_protected` | 8 | 27.7s |  |
| 102 | `avm1_loaded_bare_goto` | 17 | 27.9s |  |
| 103 | `avm1_loaded_bare_goto_seq` | 4 | 20.0s |  |
| 104 | `avm1_loaded_goto_play_deferred` | 31 | 20.0s |  |
| 105 | `avm1_loaded_order_create_vs_load` | 33 | 2.1s |  |
| 106 | `avm1_loaded_shell_consumers_seq` | 12 | 20.0s |  |
| 107 | `avm1_loaded_shell_root_lookup` | 4 | 19.8s |  |
| 108 | `avm1_loaded_timeline_holder` | 7 | 1.8s |  |
| 109 | `avm1_loaded_unload_deferred` | 5 | 1.9s |  |
| 110 | `avm1_loadvars_ondata_overflow` | 23 | 19.9s |  |
| 111 | `avm1_long_text_layout` | 2 | 19.5s |  |
| 112 | `avm1_many_chars_registry` | 4 | 19.9s |  |
| 113 | `avm1_many_defs_registry` | 13 | 23.8s |  |
| 114 | `avm1_many_functions_registry` | 3 | 9.9s |  |
| 115 | `avm1_mc_button_unified_pick` | 21 | 22.4s |  |
| 116 | `avm1_mc_resolve` | 5 | 2.2s |  |
| 117 | `avm1_mcl_holder_totalframes` | 5 | 22.3s |  |
| 118 | `avm1_mcl_load_tick` | 15 | 2.4s |  |
| 119 | `avm1_morph_instances_ratio` | 2 | 24.9s |  |
| 120 | `avm1_nested_po3_filters` | 12 | 23.2s |  |
| 121 | `avm1_onunload_setvar_scope` | 5 | 22.4s |  |
| 122 | `avm1_parent_as3_child_payload` | 2 | 19.7s |  |
| 123 | `avm1_parent_child_bitmap` | 5 | 1.8s |  |
| 124 | `avm1_parent_child_bitmap_fill` | 3 | 22.4s |  |
| 125 | `avm1_parent_child_modify_place` | 5 | 1.8s |  |
| 126 | `avm1_parent_child_morph` | 8 | 1.9s |  |
| 127 | `avm1_parent_child_render` | 7 | 1.9s |  |
| 128 | `avm1_parent_child_sprite_meta` | 8 | 1.9s |  |
| 129 | `avm1_parent_child_text` | 8 | 1.9s |  |
| 130 | `avm1_pixelbounds_dynamic_child` | 1 | 19.4s |  |
| 131 | `avm1_place_occupied_depth_swf5` | 6 | 1.7s |  |
| 132 | `avm1_placed_drawing_color` | 1 | 22.0s |  |
| 133 | `avm1_po3_cm_alpha_bias_edge` | 0 | 19.0s |  |
| 134 | `avm1_po3_cm_folded_clear` | 1 | 1.6s |  |
| 135 | `avm1_po3_cm_live_under_cxform` | 0 | 1.6s |  |
| 136 | `avm1_po3_color_matrix_live` | 0 | 1.6s |  |
| 137 | `avm1_po3_color_matrix_live_clear` | 1 | 1.6s |  |
| 138 | `avm1_po3_color_matrix_live_nested` | 0 | 1.6s |  |
| 139 | `avm1_remove_same_name_other_parent` | 4 | 19.2s |  |
| 140 | `avm1_remove_unload_finalize_overflow` | 4 | 21.0s |  |
| 141 | `avm1_removed_clip_dprops_gc` | 14 | 1.7s |  |
| 142 | `avm1_resolve_dotted_getvariable` | 13 | 19.5s |  |
| 143 | `avm1_root_identity_and_playhead` | 3 | 19.3s |  |
| 144 | `avm1_root_onload_child_order` | 11 | 19.4s |  |
| 145 | `avm1_root_onload_proto` | 7 | 1.7s |  |
| 146 | `avm1_runtime_filters` | 3 | 22.3s |  |
| 147 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.3s |  |
| 148 | `avm1_set_new_text_format_color` | 4 | 19.0s |  |
| 149 | `avm1_set_new_text_format_instance` | 5 | 1.6s |  |
| 150 | `avm1_set_new_text_format_paragraph` | 12 | 1.8s |  |
| 151 | `avm1_set_new_text_format_render` | 5 | 19.4s |  |
| 152 | `avm1_set_new_text_format_size` | 5 | 26.1s |  |
| 153 | `avm1_sprite_goto_script_overflow` | 65 | 26.2s |  |
| 154 | `avm1_stroke_hinting_caps` | 1 | 6.1s |  |
| 155 | `avm1_stroke_join_cap_snap` | 0 | 28.7s |  |
| 156 | `avm1_stroke_noscale_signed` | 0 | 26.8s |  |
| 157 | `avm1_stroke_pixel_snap` | 1 | 26.1s |  |
| 158 | `avm1_stroke_pixel_snap_matrix` | 0 | 26.6s |  |
| 159 | `avm1_stroke_seam_caps` | 1 | 26.2s |  |
| 160 | `avm1_stroke_style_id_order` | 1 | 26.1s |  |
| 161 | `avm1_swf6_case_insensitive_builtins` | 42 | 2.6s |  |
| 162 | `avm1_swf7_case_sensitive_builtins` | 40 | 19.4s |  |
| 163 | `avm1_textfield_attached_depth_order` | 1 | 19.9s |  |
| 164 | `avm1_textfield_ctor_shadow_swf6` | 2 | 1.6s |  |
| 165 | `avm1_textfield_ctor_shadow_swf7` | 2 | 0.9s |  |
| 166 | `avm1_textfield_x_bounds_offset` | 10 | 19.4s |  |
| 167 | `avm1_timer_clock_model` | 19 | 19.5s |  |
| 168 | `avm1_timer_function_form_activation` | 3 | 19.1s |  |
| 169 | `avm1_timer_method_form` | 6 | 1.7s |  |
| 170 | `avm1_timer_native_method_play` | 3 | 1.6s |  |
| 171 | `avm1_timer_overflow` | 10 | 2.1s |  |
| 172 | `avm1_timer_root_goto_stopped_gs` | 3 | 20.0s |  |
| 173 | `avm1_timer_root_goto_stopped_nf` | 3 | 1.6s |  |
| 174 | `avm1_type2_mc_receiver_dispatch` | 7 | 19.9s |  |
| 175 | `avm1_watch_long_name` | 9 | 1.6s |  |
| 176 | `avm1_watch_overflow` | 2 | 2.2s |  |
| 177 | `avm1_wrap_giveup_mixed_runs` | 2 | 1.6s |  |
| 178 | `avm1_xml_first_action_proto` | 2 | 1.6s |  |
| 179 | `avm1_xmlnode_first_action_proto` | 2 | 1.6s |  |
| 180 | `avm1_xscale_double_readback` | 8 | 1.7s |  |
| 181 | `avm2_activation_vtable_bounded` | 5 | 42.1s |  |
| 182 | `avm2_agi_shell` | 6 | 40.6s |  |
| 183 | `avm2_applyfilter_bevel_sample` | 441 | 16.0s |  |
| 184 | `avm2_applyfilter_glow_kernels` | 23 | 7.3s |  |
| 185 | `avm2_applyfilter_gradient_opaque` | 26 | 7.9s |  |
| 186 | `avm2_array_growth_bounded` | 5 | 7.8s |  |
| 187 | `avm2_bitmapdata_draw_edittext_box` | 5 | 7.1s |  |
| 188 | `avm2_bitmapdata_draw_filtered` | 13 | 7.2s |  |
| 189 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 7.7s |  |
| 190 | `avm2_bitmapdata_draw_textfield` | 5 | 7.4s |  |
| 191 | `avm2_bitmapdata_palettemap_index` | 5 | 20.1s |  |
| 192 | `avm2_child_simplebutton` | 10 | 41.9s |  |
| 193 | `avm2_contextmenu_stub` | 4 | 25.4s |  |
| 194 | `avm2_definetext_matrix` | 0 | 9.8s |  |
| 195 | `avm2_drawapi_stroke_snap` | 1 | 25.6s |  |
| 196 | `avm2_e4x_parse_bounded` | 18 | 8.2s |  |
| 197 | `avm2_edittext_placed_cxform` | 0 | 26.0s |  |
| 198 | `avm2_edittext_selection_cxform` | 2 | 25.9s |  |
| 199 | `avm2_embed_bytearray` | 2 | 25.3s |  |
| 200 | `avm2_external_interface_unavailable` | 8 | 7.2s |  |
| 201 | `avm2_findprop_this_resolution` | 13 | 7.3s |  |
| 202 | `avm2_gc_dynprop_tombstone_purge` | 8 | 43.6s |  |
| 203 | `avm2_gc_string_concat_reclaim` | 10 | 7.9s |  |
| 204 | `avm2_gc_string_survives_collect` | 9 | 7.7s |  |
| 205 | `avm2_goto_catchup_scale` | 4 | 7.8s |  |
| 206 | `avm2_graphics_runtime` | 7 | 28.5s |  |
| 207 | `avm2_group_alpha_cab` | 0 | 26.6s |  |
| 208 | `avm2_group_alpha_filter_cm` | 0 | 7.6s |  |
| 209 | `avm2_group_alpha_layer_aadd` | 0 | 7.4s |  |
| 210 | `avm2_group_alpha_layer_inner` | 0 | 7.5s |  |
| 211 | `avm2_group_alpha_multiply` | 0 | 1.1s |  |
| 212 | `avm2_group_alpha_shadow_shape_a50` | 0 | 46.4s |  |
| 213 | `avm2_json_roundtrip_bounded` | 13 | 27.1s |  |
| 214 | `avm2_layer_group_alpha` | 0 | 13.0s |  |
| 215 | `avm2_layer_group_alpha_transparency` | 0 | 8.2s |  |
| 216 | `avm2_layer_group_erase` | 0 | 1.8s |  |
| 217 | `avm2_layer_group_filtered_child` | 0 | 26.4s |  |
| 218 | `avm2_layer_group_overlap_alpha` | 0 | 8.1s |  |
| 219 | `avm2_loader_stub` | 5 | 8.0s |  |
| 220 | `avm2_localconnection_domain` | 4 | 8.0s |  |
| 221 | `avm2_morph` | 8 | 26.2s |  |
| 222 | `avm2_parent_child_render` | 11 | 45.3s |  |
| 223 | `avm2_parent_child_static_text` | 12 | 7.8s |  |
| 224 | `avm2_parent_child_symbol_stride` | 6 | 26.0s |  |
| 225 | `avm2_parent_child_symbolclass_domain` | 12 | 7.9s |  |
| 226 | `avm2_reflect_trait_hooks` | 30 | 25.1s |  |
| 227 | `avm2_sharedobject_flushstatus` | 4 | 7.5s |  |
| 228 | `avm2_simplebutton_click` | 2 | 7.8s |  |
| 229 | `avm2_slot_default_template` | 34 | 7.8s |  |
| 230 | `avm2_sound_bytes_and_group_format` | 27 | 8.0s |  |
| 231 | `avm2_static_and_store_slots` | 14 | 7.5s |  |
| 232 | `avm2_static_text` | 6 | 40.8s |  |
| 233 | `avm2_strbuf_stale_prefix` | 21 | 24.6s |  |
| 234 | `avm2_timeline_gradients` | 7 | 28.2s |  |
| 235 | `avm2_timeline_solid` | 6 | 7.9s |  |
| 236 | `avm2_timeline_stroke_gradient` | 9 | 8.1s |  |
| 237 | `avm2_timeline_text` | 4 | 7.4s |  |
| 238 | `avm2_tolerant_verify_quarantine` | 2 | 7.1s |  |
| 239 | `avm2_typed_value_ops` | 30 | 7.2s |  |
| 240 | `bitmap_pool_layer_cap` | 1 | 20.8s |  |
| 241 | `broadcast_cross_swf_version` | 4 | 19.0s |  |
| 242 | `broadcast_type1_args` | 14 | 20.3s |  |
| 243 | `coerce_cross_swf_version` | 7 | 20.3s |  |
| 244 | `coerce_recursion_guard` | 1 | 1.7s |  |
| 245 | `coerce_type1_args` | 9 | 1.6s |  |
| 246 | `convertfloat_type1_this` | 3 | 1.6s |  |
| 247 | `ctor_before_first_call_locals` | 5 | 1.7s |  |
| 248 | `ei_closure_scope_order` | 7 | 1.8s |  |
| 249 | `ei_cross_swf_version` | 2 | 1.7s |  |
| 250 | `ei_mc_this_receiver` | 5 | 20.3s |  |
| 251 | `ei_type1_args` | 7 | 1.7s |  |
| 252 | `enterframe_type1_args` | 8 | 21.1s |  |
| 253 | `fn_call_builtin_type1_args` | 10 | 21.2s |  |
| 254 | `fn_call_type1_args` | 7 | 1.7s |  |
| 255 | `fn_empty_method_type1_args` | 10 | 1.8s |  |
| 256 | `group_alpha_cab` | 0 | 23.8s |  |
| 257 | `group_alpha_filter_cm` | 0 | 2.0s |  |
| 258 | `group_alpha_layer_aadd` | 0 | 1.9s |  |
| 259 | `group_alpha_layer_inner` | 0 | 1.8s |  |
| 260 | `group_alpha_multiply` | 0 | 1.0s |  |
| 261 | `group_alpha_shadow_shape_a50` | 0 | 1.9s |  |
| 262 | `layer_group_alpha_transparency` | 0 | 22.0s |  |
| 263 | `layer_group_filtered_child` | 0 | 19.4s |  |
| 264 | `layer_group_in_add_alpha` | 0 | 5.8s |  |
| 265 | `layer_group_overlap_alpha` | 0 | 1.7s |  |
| 266 | `layer_group_overlap_erase` | 0 | 0.9s |  |
| 267 | `lc_method_type1_args` | 7 | 19.2s |  |
| 268 | `lc_onstatus_type1_args` | 3 | 1.6s |  |
| 269 | `lowq_fill_edges` | 0 | 19.3s |  |
| 270 | `lowq_gradient_orient_probe` | 0 | 19.5s |  |
| 271 | `lowq_sample_point_probe` | 0 | 19.3s |  |
| 272 | `lv_cross_swf_version` | 5 | 19.7s |  |
| 273 | `lv_ondata_type1_args` | 3 | 19.4s |  |
| 274 | `mask_nested_intersect` | 1 | 22.7s |  |
| 275 | `mask_sibling_union` | 1 | 1.4s |  |
| 276 | `mc_event_cross_swf_version` | 4 | 1.4s |  |
| 277 | `mc_event_type1_args` | 3 | 19.4s |  |
| 278 | `mc_method_v5_caller_gate` | 4 | 1.5s |  |
| 279 | `mc_resolve_type1_args` | 6 | 1.3s |  |
| 280 | `method_type1_args` | 10 | 1.4s |  |
| 281 | `nc_onstatus_closure` | 2 | 1.4s |  |
| 282 | `nc_onstatus_type1_args` | 3 | 19.6s |  |
| 283 | `onconstruct_cross_swf_version` | 4 | 19.6s |  |
| 284 | `onconstruct_type1_args` | 6 | 1.3s |  |
| 285 | `onload_type1_args` | 7 | 19.5s |  |
| 286 | `onunload_type1_args` | 6 | 1.4s |  |
| 287 | `onunload_type1_local_frame` | 2 | 1.3s |  |
| 288 | `resolve_type1_args` | 13 | 1.4s |  |
| 289 | `root_enterframe_cross_swf_version` | 3 | 19.7s |  |
| 290 | `sort_comparator_captured_scope` | 2 | 1.5s |  |
| 291 | `sort_comparator_type1_args` | 5 | 1.4s |  |
| 292 | `string_prim_method_type1_args` | 19 | 19.7s |  |
| 293 | `timer_cross_swf_version` | 3 | 20.3s |  |
| 294 | `timer_type1_args` | 14 | 20.1s |  |
| 295 | `watch_cross_swf_version` | 6 | 1.8s |  |
| 296 | `watch_mc_reentrant_setmember` | 3 | 1.4s |  |
| 297 | `watch_mc_type1_args` | 7 | 1.7s |  |
| 298 | `watch_setmember_type1_args` | 7 | 1.7s |  |
| 299 | `watch_timeline_named_params` | 4 | 1.7s |  |
| 300 | `watch_timeline_reentrant` | 3 | 1.7s |  |
| 301 | `xml_onload_type1_args` | 3 | 20.4s |  |

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
