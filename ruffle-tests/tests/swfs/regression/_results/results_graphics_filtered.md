# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 22:36 UTC

**Git SHA**: `16033a1546`

**Run Duration**: 59m 47s

**Filtered**: 0 tests ignored out of 279 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 279 |
| Passing | **278** (99.6%) |
| Failing | 1 |
| Total expected lines | 2776 |
| Matching lines | 2775 (100.0%) |
| Mismatched lines | 1 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**278 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 19.2s |  |
| 2 | `array_method_type1_args` | 7 | 1.5s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 22.4s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.8s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.8s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.8s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.8s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.8s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.8s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.6s |  |
| 11 | `avm1_array_native_own_method` | 8 | 20.4s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 20.6s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 2.5s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 22.1s |  |
| 15 | `avm1_attached_clip_color` | 2 | 23.6s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 21.8s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.5s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 20.9s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 2.2s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 21.2s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 19.4s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 19.3s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 21.7s |  |
| 24 | `avm1_attached_clip_tagorder` | 34 | 1.7s |  |
| 25 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.8s |  |
| 26 | `avm1_attached_clip_tagorder_po3` | 34 | 1.7s |  |
| 27 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.7s |  |
| 28 | `avm1_attached_clip_timeline_child_parent` | 6 | 19.1s |  |
| 29 | `avm1_bare_depth_methods_v7_gate` | 6 | 19.1s |  |
| 30 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 0.9s |  |
| 31 | `avm1_bare_mc_method_scope` | 19 | 19.5s |  |
| 32 | `avm1_bitmap_nearest_tie_stage` | 1 | 22.3s |  |
| 33 | `avm1_bitmapdata_draw_child_color` | 5 | 19.7s |  |
| 34 | `avm1_bitmapdata_draw_edittext` | 3 | 1.7s |  |
| 35 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 20.0s |  |
| 36 | `avm1_browser_eager_init` | 10 | 19.9s |  |
| 37 | `avm1_browser_gated_color` | 3 | 19.9s |  |
| 38 | `avm1_browser_gated_depth` | 7 | 1.6s |  |
| 39 | `avm1_browser_gated_textfield` | 7 | 1.7s |  |
| 40 | `avm1_browser_parked_frame` | 7 | 19.9s |  |
| 41 | `avm1_button_pick_order` | 9 | 20.8s |  |
| 42 | `avm1_button_textfield_path_binding` | 4 | 19.9s |  |
| 43 | `avm1_child_timeline_advance` | 23 | 20.2s |  |
| 44 | `avm1_child_timeline_frame1_stop` | 7 | 1.9s |  |
| 45 | `avm1_child_timeline_holder_stop` | 26 | 1.9s |  |
| 46 | `avm1_child_timeline_loop` | 32 | 1.9s |  |
| 47 | `avm1_clone_depth_overflow` | 3 | 2.2s |  |
| 48 | `avm1_clone_depth_removed_reuse` | 4 | 1.7s |  |
| 49 | `avm1_closure_base_clip_root_frame` | 5 | 1.8s |  |
| 50 | `avm1_closure_method_scope` | 7 | 1.8s |  |
| 51 | `avm1_create_text_field_depth` | 9 | 20.0s |  |
| 52 | `avm1_cxform_override_overflow` | 2 | 20.6s |  |
| 53 | `avm1_definetext_matrix` | 0 | 2.1s |  |
| 54 | `avm1_device_edittext_xscale` | 7 | 20.5s |  |
| 55 | `avm1_display_filter_growth_edge_scale` | 0 | 2.6s |  |
| 56 | `avm1_display_prop_coercion` | 36 | 2.3s |  |
| 57 | `avm1_dynclip_color_transform` | 2 | 2.5s |  |
| 58 | `avm1_edittext_border_subpixel` | 1 | 20.0s |  |
| 59 | `avm1_edittext_cut_copy_selection` | 9 | 20.4s |  |
| 60 | `avm1_edittext_html_delete_runs` | 4 | 21.1s |  |
| 61 | `avm1_edittext_html_typed_runs` | 3 | 16.1s |  |
| 62 | `avm1_edittext_maxchars_clips_insertion` | 4 | 15.5s |  |
| 63 | `avm1_edittext_path_variable_same_frame` | 11 | 15.9s |  |
| 64 | `avm1_edittext_path_variable_scope` | 10 | 1.8s |  |
| 65 | `avm1_edittext_placed_cxform` | 0 | 15.7s |  |
| 66 | `avm1_edittext_placed_cxform_script` | 3 | 1.6s |  |
| 67 | `avm1_edittext_restrict_onchanged` | 6 | 1.7s |  |
| 68 | `avm1_edittext_rotated_borders` | 0 | 15.7s |  |
| 69 | `avm1_edittext_rotated_glyphs` | 0 | 15.5s |  |
| 70 | `avm1_edittext_scaled_glyphs` | 0 | 1.6s |  |
| 71 | `avm1_edittext_tab_render` | 1 | 24.6s |  |
| 72 | `avm1_edittext_tabstops_metric` | 9 | 22.0s |  |
| 73 | `avm1_edittext_wordwrap_render` | 5 | 21.1s |  |
| 74 | `avm1_empty_clip_drawing_depth_order` | 1 | 20.3s |  |
| 75 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 20.7s |  |
| 76 | `avm1_exec_order_attached_selfremove` | 18 | 21.1s |  |
| 77 | `avm1_exec_order_dynamic_eligible` | 35 | 20.9s |  |
| 78 | `avm1_filter_list_overflow` | 2 | 20.4s |  |
| 79 | `avm1_func2_param_register_oob` | 4 | 2.0s |  |
| 80 | `avm1_goto_backward_enterframe_once` | 22 | 20.4s |  |
| 81 | `avm1_goto_skipped_init_call` | 6 | 18.9s |  |
| 82 | `avm1_goto_skipped_init_script` | 5 | 1.7s |  |
| 83 | `avm1_goto_skipped_init_timer` | 6 | 1.7s |  |
| 84 | `avm1_hairline_scaled_instances` | 1 | 19.0s |  |
| 85 | `avm1_hittest_hairline` | 28 | 19.0s |  |
| 86 | `avm1_hittest_shape_stale_matrix` | 28 | 19.1s |  |
| 87 | `avm1_holder_drawing_under_children` | 1 | 19.0s |  |
| 88 | `avm1_jpeg3_alpha_bitmap` | 0 | 18.8s |  |
| 89 | `avm1_key_isdown_protected` | 8 | 18.8s |  |
| 90 | `avm1_loaded_bare_goto` | 17 | 19.6s |  |
| 91 | `avm1_loaded_bare_goto_seq` | 4 | 20.0s |  |
| 92 | `avm1_loaded_goto_play_deferred` | 31 | 20.0s |  |
| 93 | `avm1_loaded_order_create_vs_load` | 33 | 2.4s |  |
| 94 | `avm1_loaded_shell_consumers_seq` | 12 | 20.6s |  |
| 95 | `avm1_loaded_shell_root_lookup` | 4 | 20.1s |  |
| 96 | `avm1_loaded_timeline_holder` | 7 | 1.9s |  |
| 97 | `avm1_loaded_unload_deferred` | 5 | 2.0s |  |
| 98 | `avm1_loadvars_ondata_overflow` | 23 | 20.5s |  |
| 99 | `avm1_long_text_layout` | 2 | 23.8s |  |
| 100 | `avm1_many_chars_registry` | 4 | 19.4s |  |
| 101 | `avm1_many_defs_registry` | 13 | 20.7s |  |
| 102 | `avm1_many_functions_registry` | 3 | 26.5s |  |
| 103 | `avm1_mc_button_unified_pick` | 21 | 19.5s |  |
| 104 | `avm1_mc_resolve` | 5 | 1.6s |  |
| 105 | `avm1_mcl_holder_totalframes` | 5 | 1.9s |  |
| 106 | `avm1_mcl_load_tick` | 15 | 1.8s |  |
| 107 | `avm1_morph_instances_ratio` | 2 | 19.3s |  |
| 108 | `avm1_nested_po3_filters` | 12 | 2.3s |  |
| 109 | `avm1_onunload_setvar_scope` | 5 | 22.0s |  |
| 110 | `avm1_parent_as3_child_payload` | 2 | 2.5s |  |
| 111 | `avm1_parent_child_bitmap` | 5 | 2.4s |  |
| 112 | `avm1_parent_child_bitmap_fill` | 3 | 25.1s |  |
| 113 | `avm1_parent_child_modify_place` | 5 | 2.4s |  |
| 114 | `avm1_parent_child_morph` | 8 | 2.6s |  |
| 115 | `avm1_parent_child_render` | 7 | 2.5s |  |
| 116 | `avm1_parent_child_sprite_meta` | 8 | 2.5s |  |
| 117 | `avm1_parent_child_text` | 8 | 2.7s |  |
| 118 | `avm1_pixelbounds_dynamic_child` | 1 | 20.2s |  |
| 119 | `avm1_placed_drawing_color` | 1 | 20.9s |  |
| 120 | `avm1_po3_cm_alpha_bias_edge` | 0 | 20.5s |  |
| 121 | `avm1_po3_cm_folded_clear` | 1 | 2.2s |  |
| 122 | `avm1_po3_cm_live_under_cxform` | 0 | 2.2s |  |
| 123 | `avm1_po3_color_matrix_live` | 0 | 2.2s |  |
| 124 | `avm1_po3_color_matrix_live_clear` | 1 | 2.2s |  |
| 125 | `avm1_po3_color_matrix_live_nested` | 0 | 2.2s |  |
| 126 | `avm1_remove_same_name_other_parent` | 4 | 19.6s |  |
| 127 | `avm1_remove_unload_finalize_overflow` | 4 | 21.7s |  |
| 128 | `avm1_removed_clip_dprops_gc` | 14 | 19.7s |  |
| 129 | `avm1_resolve_dotted_getvariable` | 13 | 1.7s |  |
| 130 | `avm1_root_identity_and_playhead` | 3 | 19.8s |  |
| 131 | `avm1_root_onload_child_order` | 11 | 19.7s |  |
| 132 | `avm1_root_onload_proto` | 7 | 1.8s |  |
| 133 | `avm1_runtime_filters` | 3 | 22.6s |  |
| 134 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.0s |  |
| 135 | `avm1_set_new_text_format_color` | 4 | 18.8s |  |
| 136 | `avm1_set_new_text_format_instance` | 5 | 18.9s |  |
| 137 | `avm1_set_new_text_format_paragraph` | 12 | 1.7s |  |
| 138 | `avm1_set_new_text_format_render` | 5 | 21.5s |  |
| 139 | `avm1_set_new_text_format_size` | 5 | 1.6s |  |
| 140 | `avm1_sprite_goto_script_overflow` | 65 | 19.1s |  |
| 141 | `avm1_stroke_pixel_snap` | 1 | 19.0s |  |
| 142 | `avm1_stroke_pixel_snap_matrix` | 0 | 19.4s |  |
| 143 | `avm1_stroke_style_id_order` | 1 | 19.1s |  |
| 144 | `avm1_swf6_case_insensitive_builtins` | 42 | 21.2s |  |
| 145 | `avm1_swf7_case_sensitive_builtins` | 40 | 1.2s |  |
| 146 | `avm1_textfield_attached_depth_order` | 1 | 23.3s |  |
| 147 | `avm1_textfield_x_bounds_offset` | 10 | 20.7s |  |
| 148 | `avm1_timer_clock_model` | 19 | 21.1s |  |
| 149 | `avm1_timer_function_form_activation` | 3 | 21.1s |  |
| 150 | `avm1_timer_method_form` | 6 | 2.3s |  |
| 151 | `avm1_timer_native_method_play` | 3 | 2.3s |  |
| 152 | `avm1_timer_overflow` | 10 | 3.0s |  |
| 153 | `avm1_timer_root_goto_stopped_gs` | 3 | 26.2s |  |
| 154 | `avm1_timer_root_goto_stopped_nf` | 3 | 2.3s |  |
| 155 | `avm1_type2_mc_receiver_dispatch` | 7 | 26.0s |  |
| 156 | `avm1_watch_long_name` | 9 | 2.3s |  |
| 157 | `avm1_watch_overflow` | 2 | 3.2s |  |
| 158 | `avm1_wrap_giveup_mixed_runs` | 2 | 2.3s |  |
| 159 | `avm1_xml_first_action_proto` | 2 | 2.3s |  |
| 160 | `avm1_xmlnode_first_action_proto` | 2 | 2.2s |  |
| 161 | `avm1_xscale_double_readback` | 8 | 26.2s |  |
| 162 | `avm2_activation_vtable_bounded` | 5 | 42.3s |  |
| 163 | `avm2_agi_shell` | 6 | 7.2s |  |
| 164 | `avm2_applyfilter_bevel_sample` | 441 | 17.0s |  |
| 165 | `avm2_applyfilter_glow_kernels` | 23 | 7.2s |  |
| 166 | `avm2_applyfilter_gradient_opaque` | 26 | 7.8s |  |
| 167 | `avm2_array_growth_bounded` | 5 | 7.5s |  |
| 168 | `avm2_bitmapdata_draw_edittext_box` | 5 | 7.0s |  |
| 169 | `avm2_bitmapdata_draw_filtered` | 13 | 7.1s |  |
| 170 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 7.6s |  |
| 171 | `avm2_bitmapdata_draw_textfield` | 5 | 54.8s |  |
| 172 | `avm2_child_simplebutton` | 10 | 32.7s |  |
| 173 | `avm2_contextmenu_stub` | 4 | 9.6s |  |
| 174 | `avm2_definetext_matrix` | 0 | 13.0s |  |
| 175 | `avm2_e4x_parse_bounded` | 18 | 11.0s |  |
| 176 | `avm2_edittext_placed_cxform` | 0 | 32.1s |  |
| 177 | `avm2_edittext_selection_cxform` | 2 | 32.8s |  |
| 178 | `avm2_embed_bytearray` | 2 | 32.0s |  |
| 179 | `avm2_external_interface_unavailable` | 8 | 9.8s |  |
| 180 | `avm2_findprop_this_resolution` | 13 | 44.0s |  |
| 181 | `avm2_gc_dynprop_tombstone_purge` | 8 | 8.2s |  |
| 182 | `avm2_gc_string_concat_reclaim` | 10 | 8.3s |  |
| 183 | `avm2_gc_string_survives_collect` | 9 | 8.1s |  |
| 184 | `avm2_goto_catchup_scale` | 4 | 8.2s |  |
| 185 | `avm2_graphics_runtime` | 7 | 29.1s |  |
| 186 | `avm2_group_alpha_cab` | 0 | 26.5s |  |
| 187 | `avm2_group_alpha_filter_cm` | 0 | 8.3s |  |
| 188 | `avm2_group_alpha_layer_aadd` | 0 | 8.2s |  |
| 189 | `avm2_group_alpha_layer_inner` | 0 | 46.4s |  |
| 190 | `avm2_group_alpha_multiply` | 0 | 7.3s |  |
| 191 | `avm2_group_alpha_shadow_shape_a50` | 0 | 7.4s |  |
| 192 | `avm2_json_roundtrip_bounded` | 13 | 27.1s |  |
| 193 | `avm2_layer_group_alpha` | 0 | 12.0s |  |
| 194 | `avm2_layer_group_alpha_transparency` | 0 | 1.1s |  |
| 195 | `avm2_layer_group_erase` | 0 | 1.5s |  |
| 196 | `avm2_layer_group_filtered_child` | 0 | 25.9s |  |
| 197 | `avm2_layer_group_overlap_alpha` | 0 | 7.3s |  |
| 198 | `avm2_loader_stub` | 5 | 43.6s |  |
| 199 | `avm2_localconnection_domain` | 4 | 7.8s |  |
| 200 | `avm2_morph` | 8 | 29.0s |  |
| 201 | `avm2_parent_child_render` | 11 | 10.6s |  |
| 202 | `avm2_parent_child_static_text` | 12 | 8.5s |  |
| 203 | `avm2_parent_child_symbol_stride` | 6 | 28.5s |  |
| 204 | `avm2_parent_child_symbolclass_domain` | 12 | 8.6s |  |
| 205 | `avm2_reflect_trait_hooks` | 30 | 8.6s |  |
| 206 | `avm2_sharedobject_flushstatus` | 4 | 8.2s |  |
| 207 | `avm2_simplebutton_click` | 2 | 41.0s |  |
| 208 | `avm2_slot_default_template` | 34 | 7.3s |  |
| 209 | `avm2_sound_bytes_and_group_format` | 27 | 7.3s |  |
| 210 | `avm2_static_and_store_slots` | 14 | 7.1s |  |
| 211 | `avm2_static_text` | 6 | 24.4s |  |
| 212 | `avm2_strbuf_stale_prefix` | 21 | 7.0s |  |
| 213 | `avm2_timeline_gradients` | 7 | 28.3s |  |
| 214 | `avm2_timeline_solid` | 6 | 7.9s |  |
| 215 | `avm2_timeline_stroke_gradient` | 9 | 8.1s |  |
| 216 | `avm2_timeline_text` | 4 | 45.0s |  |
| 217 | `avm2_tolerant_verify_quarantine` | 2 | 8.1s |  |
| 218 | `avm2_typed_value_ops` | 30 | 8.3s |  |
| 219 | `bitmap_pool_layer_cap` | 1 | 25.3s |  |
| 220 | `broadcast_cross_swf_version` | 4 | 20.8s |  |
| 221 | `broadcast_type1_args` | 14 | 20.8s |  |
| 222 | `coerce_cross_swf_version` | 7 | 2.2s |  |
| 223 | `coerce_recursion_guard` | 1 | 2.1s |  |
| 224 | `coerce_type1_args` | 9 | 2.0s |  |
| 225 | `convertfloat_type1_this` | 3 | 20.0s |  |
| 226 | `ctor_before_first_call_locals` | 5 | 1.7s |  |
| 227 | `ei_closure_scope_order` | 7 | 1.8s |  |
| 228 | `ei_cross_swf_version` | 2 | 1.7s |  |
| 229 | `ei_mc_this_receiver` | 5 | 20.1s |  |
| 230 | `ei_type1_args` | 7 | 1.7s |  |
| 231 | `enterframe_type1_args` | 8 | 19.9s |  |
| 232 | `fn_call_builtin_type1_args` | 10 | 1.7s |  |
| 233 | `fn_call_type1_args` | 7 | 1.6s |  |
| 234 | `fn_empty_method_type1_args` | 10 | 19.4s |  |
| 235 | `group_alpha_cab` | 0 | 21.8s |  |
| 236 | `group_alpha_filter_cm` | 0 | 1.7s |  |
| 237 | `group_alpha_layer_aadd` | 0 | 1.6s |  |
| 238 | `group_alpha_layer_inner` | 0 | 1.6s |  |
| 239 | `group_alpha_multiply` | 0 | 0.9s |  |
| 240 | `group_alpha_shadow_shape_a50` | 0 | 1.8s |  |
| 241 | `layer_group_alpha_transparency` | 0 | 0.9s |  |
| 242 | `layer_group_filtered_child` | 0 | 19.5s |  |
| 243 | `layer_group_in_add_alpha` | 0 | 23.3s |  |
| 244 | `layer_group_overlap_alpha` | 0 | 1.6s |  |
| 245 | `layer_group_overlap_erase` | 0 | 0.9s |  |
| 246 | `lc_method_type1_args` | 7 | 19.1s |  |
| 247 | `lc_onstatus_type1_args` | 3 | 1.6s |  |
| 248 | `lowq_fill_edges` | 0 | 19.1s |  |
| 249 | `lv_cross_swf_version` | 5 | 19.2s |  |
| 250 | `lv_ondata_type1_args` | 3 | 19.1s |  |
| 251 | `mask_nested_intersect` | 1 | 21.7s |  |
| 252 | `mask_sibling_union` | 1 | 23.3s |  |
| 253 | `mc_event_cross_swf_version` | 4 | 19.9s |  |
| 254 | `mc_event_type1_args` | 3 | 20.1s |  |
| 255 | `mc_method_v5_caller_gate` | 4 | 2.2s |  |
| 256 | `mc_resolve_type1_args` | 6 | 2.0s |  |
| 257 | `method_type1_args` | 10 | 2.0s |  |
| 258 | `nc_onstatus_closure` | 2 | 19.9s |  |
| 259 | `nc_onstatus_type1_args` | 3 | 2.0s |  |
| 260 | `onconstruct_cross_swf_version` | 4 | 2.0s |  |
| 261 | `onconstruct_type1_args` | 6 | 19.3s |  |
| 262 | `onload_type1_args` | 7 | 19.1s |  |
| 263 | `onunload_type1_args` | 6 | 1.6s |  |
| 264 | `onunload_type1_local_frame` | 2 | 1.6s |  |
| 265 | `resolve_type1_args` | 13 | 1.6s |  |
| 266 | `root_enterframe_cross_swf_version` | 3 | 19.6s |  |
| 267 | `sort_comparator_captured_scope` | 2 | 1.7s |  |
| 268 | `sort_comparator_type1_args` | 5 | 1.6s |  |
| 269 | `string_prim_method_type1_args` | 19 | 1.6s |  |
| 270 | `timer_cross_swf_version` | 3 | 26.5s |  |
| 271 | `timer_type1_args` | 14 | 26.3s |  |
| 272 | `watch_cross_swf_version` | 6 | 2.8s |  |
| 273 | `watch_mc_reentrant_setmember` | 3 | 26.1s |  |
| 274 | `watch_mc_type1_args` | 7 | 2.6s |  |
| 275 | `watch_setmember_type1_args` | 7 | 2.6s |  |
| 276 | `watch_timeline_named_params` | 4 | 2.6s |  |
| 277 | `watch_timeline_reentrant` | 3 | 2.6s |  |
| 278 | `xml_onload_type1_args` | 3 | 25.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `avm1_place_occupied_depth_swf5` | 83.3% | 5 | 6 | 1 |  |

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
| 1 | `avm1_place_occupied_depth_swf5` | 83.3% | 5/6 | 6 | 6 |  |
