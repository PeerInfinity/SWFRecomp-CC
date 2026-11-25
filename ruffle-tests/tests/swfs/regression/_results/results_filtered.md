# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 22:59 UTC

**Git SHA**: `16033a1546`

**Run Duration**: 47m 38s

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
| 1 | `array_element_type1_args` | 7 | 15.1s |  |
| 2 | `array_method_type1_args` | 7 | 1.3s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 15.0s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.3s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.3s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.3s |  |
| 7 | `avm1_applyfilter_dropshadow` | 18 | 1.4s |  |
| 8 | `avm1_applyfilter_glow` | 18 | 1.4s |  |
| 9 | `avm1_applyfilter_kernels` | 17 | 1.3s |  |
| 10 | `avm1_array_generic_receivers` | 16 | 1.2s |  |
| 11 | `avm1_array_native_own_method` | 8 | 18.4s |  |
| 12 | `avm1_attach_clipevent_enterframe` | 11 | 18.5s |  |
| 13 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.1s |  |
| 14 | `avm1_attached_clip_button_click` | 13 | 18.3s |  |
| 15 | `avm1_attached_clip_color` | 2 | 18.4s |  |
| 16 | `avm1_attached_clip_goto_play` | 14 | 18.7s |  |
| 17 | `avm1_attached_clip_goto_play_nonroot` | 14 | 0.5s |  |
| 18 | `avm1_attached_clip_hidden_capture` | 6 | 18.8s |  |
| 19 | `avm1_attached_clip_holder_render` | 1 | 0.9s |  |
| 20 | `avm1_attached_clip_natural_timeline` | 34 | 18.7s |  |
| 21 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 18.6s |  |
| 22 | `avm1_attached_clip_samename_child` | 32 | 18.6s |  |
| 23 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 18.2s |  |
| 24 | `avm1_attached_clip_tagorder` | 34 | 1.0s |  |
| 25 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.2s |  |
| 26 | `avm1_attached_clip_tagorder_po3` | 34 | 1.0s |  |
| 27 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.0s |  |
| 28 | `avm1_attached_clip_timeline_child_parent` | 6 | 18.6s |  |
| 29 | `avm1_bare_depth_methods_v7_gate` | 6 | 18.4s |  |
| 30 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 0.3s |  |
| 31 | `avm1_bare_mc_method_scope` | 19 | 19.5s |  |
| 32 | `avm1_bitmap_nearest_tie_stage` | 1 | 19.2s |  |
| 33 | `avm1_bitmapdata_draw_child_color` | 5 | 19.4s |  |
| 34 | `avm1_bitmapdata_draw_edittext` | 3 | 1.2s |  |
| 35 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 19.3s |  |
| 36 | `avm1_browser_eager_init` | 10 | 19.4s |  |
| 37 | `avm1_browser_gated_color` | 3 | 19.0s |  |
| 38 | `avm1_browser_gated_depth` | 7 | 1.1s |  |
| 39 | `avm1_browser_gated_textfield` | 7 | 1.2s |  |
| 40 | `avm1_browser_parked_frame` | 7 | 19.4s |  |
| 41 | `avm1_button_pick_order` | 9 | 20.3s |  |
| 42 | `avm1_button_textfield_path_binding` | 4 | 19.8s |  |
| 43 | `avm1_child_timeline_advance` | 23 | 21.7s |  |
| 44 | `avm1_child_timeline_frame1_stop` | 7 | 1.5s |  |
| 45 | `avm1_child_timeline_holder_stop` | 26 | 1.6s |  |
| 46 | `avm1_child_timeline_loop` | 32 | 1.6s |  |
| 47 | `avm1_clone_depth_overflow` | 3 | 1.9s |  |
| 48 | `avm1_clone_depth_removed_reuse` | 4 | 1.5s |  |
| 49 | `avm1_closure_base_clip_root_frame` | 5 | 1.9s |  |
| 50 | `avm1_closure_method_scope` | 7 | 1.9s |  |
| 51 | `avm1_create_text_field_depth` | 9 | 18.2s |  |
| 52 | `avm1_cxform_override_overflow` | 2 | 18.5s |  |
| 53 | `avm1_definetext_matrix` | 0 | 0.9s |  |
| 54 | `avm1_device_edittext_xscale` | 7 | 18.4s |  |
| 55 | `avm1_display_filter_growth_edge_scale` | 0 | 0.9s |  |
| 56 | `avm1_display_prop_coercion` | 36 | 1.1s |  |
| 57 | `avm1_dynclip_color_transform` | 2 | 1.1s |  |
| 58 | `avm1_edittext_border_subpixel` | 1 | 18.4s |  |
| 59 | `avm1_edittext_cut_copy_selection` | 9 | 18.5s |  |
| 60 | `avm1_edittext_html_delete_runs` | 4 | 18.5s |  |
| 61 | `avm1_edittext_html_typed_runs` | 3 | 18.8s |  |
| 62 | `avm1_edittext_maxchars_clips_insertion` | 4 | 18.4s |  |
| 63 | `avm1_edittext_path_variable_same_frame` | 11 | 18.8s |  |
| 64 | `avm1_edittext_path_variable_scope` | 10 | 1.1s |  |
| 65 | `avm1_edittext_placed_cxform` | 0 | 18.4s |  |
| 66 | `avm1_edittext_placed_cxform_script` | 3 | 0.9s |  |
| 67 | `avm1_edittext_restrict_onchanged` | 6 | 0.9s |  |
| 68 | `avm1_edittext_rotated_borders` | 0 | 0.9s |  |
| 69 | `avm1_edittext_rotated_glyphs` | 0 | 18.6s |  |
| 70 | `avm1_edittext_scaled_glyphs` | 0 | 0.9s |  |
| 71 | `avm1_edittext_tab_render` | 1 | 18.3s |  |
| 72 | `avm1_edittext_tabstops_metric` | 9 | 18.4s |  |
| 73 | `avm1_edittext_wordwrap_render` | 5 | 18.4s |  |
| 74 | `avm1_empty_clip_drawing_depth_order` | 1 | 18.6s |  |
| 75 | `avm1_enterframe_removed_same_tick_noprobe` | 25 | 18.6s |  |
| 76 | `avm1_exec_order_attached_selfremove` | 18 | 18.8s |  |
| 77 | `avm1_exec_order_dynamic_eligible` | 35 | 18.6s |  |
| 78 | `avm1_filter_list_overflow` | 2 | 1.0s |  |
| 79 | `avm1_func2_param_register_oob` | 4 | 0.9s |  |
| 80 | `avm1_goto_backward_enterframe_once` | 22 | 18.5s |  |
| 81 | `avm1_goto_skipped_init_call` | 6 | 23.5s |  |
| 82 | `avm1_goto_skipped_init_script` | 5 | 1.4s |  |
| 83 | `avm1_goto_skipped_init_timer` | 6 | 1.4s |  |
| 84 | `avm1_hairline_scaled_instances` | 1 | 23.3s |  |
| 85 | `avm1_hittest_hairline` | 28 | 23.4s |  |
| 86 | `avm1_hittest_shape_stale_matrix` | 28 | 23.6s |  |
| 87 | `avm1_holder_drawing_under_children` | 1 | 23.3s |  |
| 88 | `avm1_jpeg3_alpha_bitmap` | 0 | 23.2s |  |
| 89 | `avm1_key_isdown_protected` | 8 | 23.4s |  |
| 90 | `avm1_loaded_bare_goto` | 17 | 23.9s |  |
| 91 | `avm1_loaded_bare_goto_seq` | 4 | 18.5s |  |
| 92 | `avm1_loaded_goto_play_deferred` | 31 | 18.6s |  |
| 93 | `avm1_loaded_order_create_vs_load` | 33 | 1.4s |  |
| 94 | `avm1_loaded_shell_consumers_seq` | 12 | 18.5s |  |
| 95 | `avm1_loaded_shell_root_lookup` | 4 | 18.2s |  |
| 96 | `avm1_loaded_timeline_holder` | 7 | 1.1s |  |
| 97 | `avm1_loaded_unload_deferred` | 5 | 1.1s |  |
| 98 | `avm1_loadvars_ondata_overflow` | 23 | 18.5s |  |
| 99 | `avm1_long_text_layout` | 2 | 18.5s |  |
| 100 | `avm1_many_chars_registry` | 4 | 19.2s |  |
| 101 | `avm1_many_defs_registry` | 13 | 20.3s |  |
| 102 | `avm1_many_functions_registry` | 3 | 26.2s |  |
| 103 | `avm1_mc_button_unified_pick` | 21 | 19.3s |  |
| 104 | `avm1_mc_resolve` | 5 | 0.9s |  |
| 105 | `avm1_mcl_holder_totalframes` | 5 | 1.2s |  |
| 106 | `avm1_mcl_load_tick` | 15 | 1.1s |  |
| 107 | `avm1_morph_instances_ratio` | 2 | 18.9s |  |
| 108 | `avm1_nested_po3_filters` | 12 | 1.1s |  |
| 109 | `avm1_onunload_setvar_scope` | 5 | 18.6s |  |
| 110 | `avm1_parent_as3_child_payload` | 2 | 1.1s |  |
| 111 | `avm1_parent_child_bitmap` | 5 | 1.1s |  |
| 112 | `avm1_parent_child_bitmap_fill` | 3 | 18.8s |  |
| 113 | `avm1_parent_child_modify_place` | 5 | 1.1s |  |
| 114 | `avm1_parent_child_morph` | 8 | 1.1s |  |
| 115 | `avm1_parent_child_render` | 7 | 1.1s |  |
| 116 | `avm1_parent_child_sprite_meta` | 8 | 1.2s |  |
| 117 | `avm1_parent_child_text` | 8 | 1.1s |  |
| 118 | `avm1_pixelbounds_dynamic_child` | 1 | 14.3s |  |
| 119 | `avm1_placed_drawing_color` | 1 | 14.7s |  |
| 120 | `avm1_po3_cm_alpha_bias_edge` | 0 | 14.5s |  |
| 121 | `avm1_po3_cm_folded_clear` | 1 | 1.0s |  |
| 122 | `avm1_po3_cm_live_under_cxform` | 0 | 0.9s |  |
| 123 | `avm1_po3_color_matrix_live` | 0 | 0.9s |  |
| 124 | `avm1_po3_color_matrix_live_clear` | 1 | 0.9s |  |
| 125 | `avm1_po3_color_matrix_live_nested` | 0 | 0.9s |  |
| 126 | `avm1_remove_same_name_other_parent` | 4 | 19.1s |  |
| 127 | `avm1_remove_unload_finalize_overflow` | 4 | 21.3s |  |
| 128 | `avm1_removed_clip_dprops_gc` | 14 | 1.3s |  |
| 129 | `avm1_resolve_dotted_getvariable` | 13 | 1.2s |  |
| 130 | `avm1_root_identity_and_playhead` | 3 | 19.0s |  |
| 131 | `avm1_root_onload_child_order` | 11 | 19.2s |  |
| 132 | `avm1_root_onload_proto` | 7 | 1.3s |  |
| 133 | `avm1_runtime_filters` | 3 | 19.2s |  |
| 134 | `avm1_runtime_filters_cm_bitmap` | 5 | 1.3s |  |
| 135 | `avm1_set_new_text_format_color` | 4 | 15.9s |  |
| 136 | `avm1_set_new_text_format_instance` | 5 | 16.3s |  |
| 137 | `avm1_set_new_text_format_paragraph` | 12 | 1.3s |  |
| 138 | `avm1_set_new_text_format_render` | 5 | 17.0s |  |
| 139 | `avm1_set_new_text_format_size` | 5 | 1.0s |  |
| 140 | `avm1_sprite_goto_script_overflow` | 65 | 17.0s |  |
| 141 | `avm1_stroke_pixel_snap` | 1 | 16.3s |  |
| 142 | `avm1_stroke_pixel_snap_matrix` | 0 | 17.1s |  |
| 143 | `avm1_stroke_style_id_order` | 1 | 16.0s |  |
| 144 | `avm1_swf6_case_insensitive_builtins` | 42 | 19.1s |  |
| 145 | `avm1_swf7_case_sensitive_builtins` | 40 | 0.3s |  |
| 146 | `avm1_textfield_attached_depth_order` | 1 | 19.0s |  |
| 147 | `avm1_textfield_x_bounds_offset` | 10 | 18.9s |  |
| 148 | `avm1_timer_clock_model` | 19 | 19.2s |  |
| 149 | `avm1_timer_function_form_activation` | 3 | 18.6s |  |
| 150 | `avm1_timer_method_form` | 6 | 1.0s |  |
| 151 | `avm1_timer_native_method_play` | 3 | 1.0s |  |
| 152 | `avm1_timer_overflow` | 10 | 1.5s |  |
| 153 | `avm1_timer_root_goto_stopped_gs` | 3 | 18.9s |  |
| 154 | `avm1_timer_root_goto_stopped_nf` | 3 | 0.9s |  |
| 155 | `avm1_type2_mc_receiver_dispatch` | 7 | 18.8s |  |
| 156 | `avm1_watch_long_name` | 9 | 0.9s |  |
| 157 | `avm1_watch_overflow` | 2 | 1.5s |  |
| 158 | `avm1_wrap_giveup_mixed_runs` | 2 | 0.9s |  |
| 159 | `avm1_xml_first_action_proto` | 2 | 0.9s |  |
| 160 | `avm1_xmlnode_first_action_proto` | 2 | 0.8s |  |
| 161 | `avm1_xscale_double_readback` | 8 | 18.8s |  |
| 162 | `avm2_activation_vtable_bounded` | 5 | 2.6s |  |
| 163 | `avm2_agi_shell` | 6 | 6.0s |  |
| 164 | `avm2_applyfilter_bevel_sample` | 441 | 17.6s |  |
| 165 | `avm2_applyfilter_glow_kernels` | 23 | 6.2s |  |
| 166 | `avm2_applyfilter_gradient_opaque` | 26 | 6.6s |  |
| 167 | `avm2_array_growth_bounded` | 5 | 6.5s |  |
| 168 | `avm2_bitmapdata_draw_edittext_box` | 5 | 6.0s |  |
| 169 | `avm2_bitmapdata_draw_filtered` | 13 | 6.4s |  |
| 170 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 6.5s |  |
| 171 | `avm2_bitmapdata_draw_textfield` | 5 | 37.0s |  |
| 172 | `avm2_child_simplebutton` | 10 | 21.4s |  |
| 173 | `avm2_contextmenu_stub` | 4 | 5.7s |  |
| 174 | `avm2_definetext_matrix` | 0 | 5.7s |  |
| 175 | `avm2_e4x_parse_bounded` | 18 | 6.5s |  |
| 176 | `avm2_edittext_placed_cxform` | 0 | 20.7s |  |
| 177 | `avm2_edittext_selection_cxform` | 2 | 20.9s |  |
| 178 | `avm2_embed_bytearray` | 2 | 20.7s |  |
| 179 | `avm2_external_interface_unavailable` | 8 | 5.7s |  |
| 180 | `avm2_findprop_this_resolution` | 13 | 39.9s |  |
| 181 | `avm2_gc_dynprop_tombstone_purge` | 8 | 5.9s |  |
| 182 | `avm2_gc_string_concat_reclaim` | 10 | 5.8s |  |
| 183 | `avm2_gc_string_survives_collect` | 9 | 5.8s |  |
| 184 | `avm2_goto_catchup_scale` | 4 | 5.9s |  |
| 185 | `avm2_graphics_runtime` | 7 | 23.3s |  |
| 186 | `avm2_group_alpha_cab` | 0 | 23.4s |  |
| 187 | `avm2_group_alpha_filter_cm` | 0 | 5.7s |  |
| 188 | `avm2_group_alpha_layer_aadd` | 0 | 5.7s |  |
| 189 | `avm2_group_alpha_layer_inner` | 0 | 39.4s |  |
| 190 | `avm2_group_alpha_multiply` | 0 | 5.6s |  |
| 191 | `avm2_group_alpha_shadow_shape_a50` | 0 | 5.6s |  |
| 192 | `avm2_json_roundtrip_bounded` | 13 | 23.7s |  |
| 193 | `avm2_layer_group_alpha` | 0 | 5.9s |  |
| 194 | `avm2_layer_group_alpha_transparency` | 0 | 0.4s |  |
| 195 | `avm2_layer_group_erase` | 0 | 0.6s |  |
| 196 | `avm2_layer_group_filtered_child` | 0 | 23.0s |  |
| 197 | `avm2_layer_group_overlap_alpha` | 0 | 5.6s |  |
| 198 | `avm2_loader_stub` | 5 | 5.7s |  |
| 199 | `avm2_localconnection_domain` | 4 | 5.8s |  |
| 200 | `avm2_morph` | 8 | 23.5s |  |
| 201 | `avm2_parent_child_render` | 11 | 7.8s |  |
| 202 | `avm2_parent_child_static_text` | 12 | 6.1s |  |
| 203 | `avm2_parent_child_symbol_stride` | 6 | 6.9s |  |
| 204 | `avm2_parent_child_symbolclass_domain` | 12 | 6.0s |  |
| 205 | `avm2_reflect_trait_hooks` | 30 | 6.0s |  |
| 206 | `avm2_sharedobject_flushstatus` | 4 | 5.7s |  |
| 207 | `avm2_simplebutton_click` | 2 | 5.8s |  |
| 208 | `avm2_slot_default_template` | 34 | 5.9s |  |
| 209 | `avm2_sound_bytes_and_group_format` | 27 | 6.0s |  |
| 210 | `avm2_static_and_store_slots` | 14 | 5.9s |  |
| 211 | `avm2_static_text` | 6 | 5.8s |  |
| 212 | `avm2_strbuf_stale_prefix` | 21 | 5.7s |  |
| 213 | `avm2_timeline_gradients` | 7 | 24.1s |  |
| 214 | `avm2_timeline_solid` | 6 | 6.5s |  |
| 215 | `avm2_timeline_stroke_gradient` | 9 | 6.6s |  |
| 216 | `avm2_timeline_text` | 4 | 6.8s |  |
| 217 | `avm2_tolerant_verify_quarantine` | 2 | 6.3s |  |
| 218 | `avm2_typed_value_ops` | 30 | 6.6s |  |
| 219 | `bitmap_pool_layer_cap` | 1 | 19.3s |  |
| 220 | `broadcast_cross_swf_version` | 4 | 19.0s |  |
| 221 | `broadcast_type1_args` | 14 | 18.8s |  |
| 222 | `coerce_cross_swf_version` | 7 | 1.3s |  |
| 223 | `coerce_recursion_guard` | 1 | 1.1s |  |
| 224 | `coerce_type1_args` | 9 | 1.1s |  |
| 225 | `convertfloat_type1_this` | 3 | 18.8s |  |
| 226 | `ctor_before_first_call_locals` | 5 | 0.9s |  |
| 227 | `ei_closure_scope_order` | 7 | 1.0s |  |
| 228 | `ei_cross_swf_version` | 2 | 0.9s |  |
| 229 | `ei_mc_this_receiver` | 5 | 18.6s |  |
| 230 | `ei_type1_args` | 7 | 0.9s |  |
| 231 | `enterframe_type1_args` | 8 | 18.7s |  |
| 232 | `fn_call_builtin_type1_args` | 10 | 0.9s |  |
| 233 | `fn_call_type1_args` | 7 | 0.9s |  |
| 234 | `fn_empty_method_type1_args` | 10 | 23.5s |  |
| 235 | `group_alpha_cab` | 0 | 1.1s |  |
| 236 | `group_alpha_filter_cm` | 0 | 1.1s |  |
| 237 | `group_alpha_layer_aadd` | 0 | 1.1s |  |
| 238 | `group_alpha_layer_inner` | 0 | 1.2s |  |
| 239 | `group_alpha_multiply` | 0 | 0.2s |  |
| 240 | `group_alpha_shadow_shape_a50` | 0 | 1.2s |  |
| 241 | `layer_group_alpha_transparency` | 0 | 0.3s |  |
| 242 | `layer_group_filtered_child` | 0 | 23.7s |  |
| 243 | `layer_group_in_add_alpha` | 0 | 1.5s |  |
| 244 | `layer_group_overlap_alpha` | 0 | 1.6s |  |
| 245 | `layer_group_overlap_erase` | 0 | 0.3s |  |
| 246 | `lc_method_type1_args` | 7 | 20.8s |  |
| 247 | `lc_onstatus_type1_args` | 3 | 1.4s |  |
| 248 | `lowq_fill_edges` | 0 | 20.6s |  |
| 249 | `lv_cross_swf_version` | 5 | 20.7s |  |
| 250 | `lv_ondata_type1_args` | 3 | 21.2s |  |
| 251 | `mask_nested_intersect` | 1 | 20.5s |  |
| 252 | `mask_sibling_union` | 1 | 18.6s |  |
| 253 | `mc_event_cross_swf_version` | 4 | 18.9s |  |
| 254 | `mc_event_type1_args` | 3 | 18.6s |  |
| 255 | `mc_method_v5_caller_gate` | 4 | 1.0s |  |
| 256 | `mc_resolve_type1_args` | 6 | 0.9s |  |
| 257 | `method_type1_args` | 10 | 0.9s |  |
| 258 | `nc_onstatus_closure` | 2 | 18.7s |  |
| 259 | `nc_onstatus_type1_args` | 3 | 0.9s |  |
| 260 | `onconstruct_cross_swf_version` | 4 | 1.0s |  |
| 261 | `onconstruct_type1_args` | 6 | 20.8s |  |
| 262 | `onload_type1_args` | 7 | 21.2s |  |
| 263 | `onunload_type1_args` | 6 | 1.1s |  |
| 264 | `onunload_type1_local_frame` | 2 | 1.1s |  |
| 265 | `resolve_type1_args` | 13 | 1.1s |  |
| 266 | `root_enterframe_cross_swf_version` | 3 | 21.3s |  |
| 267 | `sort_comparator_captured_scope` | 2 | 1.4s |  |
| 268 | `sort_comparator_type1_args` | 5 | 1.2s |  |
| 269 | `string_prim_method_type1_args` | 19 | 1.1s |  |
| 270 | `timer_cross_swf_version` | 3 | 18.2s |  |
| 271 | `timer_type1_args` | 14 | 18.3s |  |
| 272 | `watch_cross_swf_version` | 6 | 1.0s |  |
| 273 | `watch_mc_reentrant_setmember` | 3 | 18.0s |  |
| 274 | `watch_mc_type1_args` | 7 | 0.9s |  |
| 275 | `watch_setmember_type1_args` | 7 | 0.9s |  |
| 276 | `watch_timeline_named_params` | 4 | 0.9s |  |
| 277 | `watch_timeline_reentrant` | 3 | 0.9s |  |
| 278 | `xml_onload_type1_args` | 3 | 18.2s |  |

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
