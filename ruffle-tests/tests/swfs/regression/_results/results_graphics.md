# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-25 03:46 UTC

**Git SHA**: `8f4f6e3953`

**Run Duration**: 50m 56s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 254 |
| Passing | **254** (100.0%) |
| Failing | 0 |
| Total expected lines | 2030 |
| Matching lines | 2030 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**254 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 18.9s |  |
| 2 | `array_method_type1_args` | 7 | 1.5s |  |
| 3 | `avm1_applyfilter_bevel` | 18 | 21.9s |  |
| 4 | `avm1_applyfilter_blur` | 18 | 1.8s |  |
| 5 | `avm1_applyfilter_convolution` | 18 | 1.8s |  |
| 6 | `avm1_applyfilter_convolution_not_cm` | 10 | 1.7s |  |
| 7 | `avm1_applyfilter_glow` | 18 | 1.8s |  |
| 8 | `avm1_applyfilter_kernels` | 17 | 1.7s |  |
| 9 | `avm1_array_generic_receivers` | 16 | 1.6s |  |
| 10 | `avm1_array_native_own_method` | 8 | 18.8s |  |
| 11 | `avm1_attach_clipevent_enterframe` | 11 | 19.2s |  |
| 12 | `avm1_attach_from_stopped_root_enterframe` | 13 | 1.5s |  |
| 13 | `avm1_attached_clip_button_click` | 13 | 19.5s |  |
| 14 | `avm1_attached_clip_color` | 2 | 21.7s |  |
| 15 | `avm1_attached_clip_goto_play` | 14 | 19.1s |  |
| 16 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.1s |  |
| 17 | `avm1_attached_clip_hidden_capture` | 6 | 19.3s |  |
| 18 | `avm1_attached_clip_holder_render` | 1 | 1.3s |  |
| 19 | `avm1_attached_clip_natural_timeline` | 34 | 19.2s |  |
| 20 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.7s |  |
| 21 | `avm1_attached_clip_samename_child` | 32 | 19.0s |  |
| 22 | `avm1_attached_clip_selfgoto_child_parent` | 6 | 21.5s |  |
| 23 | `avm1_attached_clip_tagorder` | 34 | 1.7s |  |
| 24 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.8s |  |
| 25 | `avm1_attached_clip_tagorder_po3` | 34 | 1.7s |  |
| 26 | `avm1_attached_clip_tagorder_ratio` | 34 | 1.7s |  |
| 27 | `avm1_attached_clip_timeline_child_parent` | 6 | 19.0s |  |
| 28 | `avm1_bare_depth_methods_v7_gate` | 6 | 26.3s |  |
| 29 | `avm1_bare_depth_methods_v7_gate_swf7` | 6 | 1.4s |  |
| 30 | `avm1_bare_mc_method_scope` | 19 | 26.3s |  |
| 31 | `avm1_bitmap_nearest_tie_stage` | 1 | 30.5s |  |
| 32 | `avm1_bitmapdata_draw_child_color` | 5 | 26.5s |  |
| 33 | `avm1_bitmapdata_draw_edittext` | 3 | 2.6s |  |
| 34 | `avm1_bitmapdata_draw_text_glyph_cx` | 4 | 26.3s |  |
| 35 | `avm1_browser_eager_init` | 10 | 26.1s |  |
| 36 | `avm1_browser_gated_color` | 3 | 2.6s |  |
| 37 | `avm1_browser_gated_depth` | 7 | 16.9s |  |
| 38 | `avm1_browser_gated_textfield` | 7 | 1.6s |  |
| 39 | `avm1_browser_parked_frame` | 7 | 17.0s |  |
| 40 | `avm1_button_pick_order` | 9 | 2.6s |  |
| 41 | `avm1_button_textfield_path_binding` | 4 | 16.7s |  |
| 42 | `avm1_child_timeline_advance` | 23 | 17.1s |  |
| 43 | `avm1_child_timeline_frame1_stop` | 7 | 2.0s |  |
| 44 | `avm1_child_timeline_holder_stop` | 26 | 2.0s |  |
| 45 | `avm1_child_timeline_loop` | 32 | 2.1s |  |
| 46 | `avm1_clone_depth_overflow` | 3 | 19.2s |  |
| 47 | `avm1_clone_depth_removed_reuse` | 4 | 1.6s |  |
| 48 | `avm1_closure_base_clip_root_frame` | 5 | 1.7s |  |
| 49 | `avm1_closure_method_scope` | 7 | 1.7s |  |
| 50 | `avm1_create_text_field_depth` | 9 | 1.6s |  |
| 51 | `avm1_cxform_override_overflow` | 2 | 18.9s |  |
| 52 | `avm1_definetext_matrix` | 0 | 1.6s |  |
| 53 | `avm1_device_edittext_xscale` | 7 | 18.8s |  |
| 54 | `avm1_display_prop_coercion` | 36 | 1.8s |  |
| 55 | `avm1_dynclip_color_transform` | 2 | 2.2s |  |
| 56 | `avm1_edittext_border_subpixel` | 1 | 19.6s |  |
| 57 | `avm1_edittext_cut_copy_selection` | 9 | 19.7s |  |
| 58 | `avm1_edittext_html_delete_runs` | 4 | 19.6s |  |
| 59 | `avm1_edittext_html_typed_runs` | 3 | 1.8s |  |
| 60 | `avm1_edittext_maxchars_clips_insertion` | 4 | 19.3s |  |
| 61 | `avm1_edittext_path_variable_same_frame` | 11 | 19.4s |  |
| 62 | `avm1_edittext_path_variable_scope` | 10 | 1.8s |  |
| 63 | `avm1_edittext_placed_cxform` | 0 | 19.6s |  |
| 64 | `avm1_edittext_placed_cxform_script` | 3 | 18.8s |  |
| 65 | `avm1_edittext_scaled_glyphs` | 0 | 21.3s |  |
| 66 | `avm1_edittext_tab_render` | 1 | 18.9s |  |
| 67 | `avm1_edittext_tabstops_metric` | 9 | 18.8s |  |
| 68 | `avm1_edittext_wordwrap_render` | 5 | 18.7s |  |
| 69 | `avm1_empty_clip_drawing_depth_order` | 1 | 18.8s |  |
| 70 | `avm1_exec_order_attached_selfremove` | 18 | 19.1s |  |
| 71 | `avm1_exec_order_dynamic_eligible` | 35 | 18.9s |  |
| 72 | `avm1_filter_list_overflow` | 2 | 18.9s |  |
| 73 | `avm1_func2_param_register_oob` | 4 | 18.9s |  |
| 74 | `avm1_goto_backward_enterframe_once` | 22 | 19.1s |  |
| 75 | `avm1_goto_skipped_init_call` | 6 | 19.2s |  |
| 76 | `avm1_goto_skipped_init_script` | 5 | 1.7s |  |
| 77 | `avm1_goto_skipped_init_timer` | 6 | 1.8s |  |
| 78 | `avm1_hairline_scaled_instances` | 1 | 19.1s |  |
| 79 | `avm1_hittest_hairline` | 28 | 19.2s |  |
| 80 | `avm1_holder_drawing_under_children` | 1 | 19.2s |  |
| 81 | `avm1_jpeg3_alpha_bitmap` | 0 | 19.1s |  |
| 82 | `avm1_key_isdown_protected` | 8 | 19.1s |  |
| 83 | `avm1_loaded_bare_goto_seq` | 4 | 19.2s |  |
| 84 | `avm1_loaded_shell_consumers_seq` | 12 | 19.0s |  |
| 85 | `avm1_loaded_shell_root_lookup` | 4 | 19.1s |  |
| 86 | `avm1_loaded_timeline_holder` | 7 | 1.8s |  |
| 87 | `avm1_loaded_unload_deferred` | 5 | 1.9s |  |
| 88 | `avm1_long_text_layout` | 2 | 4.7s |  |
| 89 | `avm1_many_chars_registry` | 4 | 19.4s |  |
| 90 | `avm1_many_defs_registry` | 13 | 20.5s |  |
| 91 | `avm1_many_functions_registry` | 3 | 26.9s |  |
| 92 | `avm1_mc_button_unified_pick` | 21 | 19.9s |  |
| 93 | `avm1_mc_resolve` | 5 | 1.7s |  |
| 94 | `avm1_mcl_holder_totalframes` | 5 | 1.9s |  |
| 95 | `avm1_mcl_load_tick` | 14 | 1.9s |  |
| 96 | `avm1_morph_instances_ratio` | 2 | 19.4s |  |
| 97 | `avm1_nested_po3_filters` | 12 | 19.9s |  |
| 98 | `avm1_parent_as3_child_payload` | 2 | 1.8s |  |
| 99 | `avm1_parent_child_bitmap` | 5 | 1.9s |  |
| 100 | `avm1_parent_child_bitmap_fill` | 3 | 21.9s |  |
| 101 | `avm1_parent_child_modify_place` | 5 | 1.8s |  |
| 102 | `avm1_parent_child_morph` | 8 | 1.9s |  |
| 103 | `avm1_parent_child_render` | 7 | 1.9s |  |
| 104 | `avm1_parent_child_sprite_meta` | 8 | 1.9s |  |
| 105 | `avm1_parent_child_text` | 8 | 1.9s |  |
| 106 | `avm1_pixelbounds_dynamic_child` | 1 | 19.4s |  |
| 107 | `avm1_placed_drawing_color` | 1 | 19.7s |  |
| 108 | `avm1_po3_cm_alpha_bias_edge` | 0 | 1.8s |  |
| 109 | `avm1_po3_cm_folded_clear` | 1 | 27.0s |  |
| 110 | `avm1_po3_cm_live_under_cxform` | 0 | 2.4s |  |
| 111 | `avm1_po3_color_matrix_live` | 0 | 2.2s |  |
| 112 | `avm1_po3_color_matrix_live_clear` | 1 | 2.2s |  |
| 113 | `avm1_po3_color_matrix_live_nested` | 0 | 2.2s |  |
| 114 | `avm1_remove_same_name_other_parent` | 4 | 24.4s |  |
| 115 | `avm1_removed_clip_dprops_gc` | 14 | 2.3s |  |
| 116 | `avm1_resolve_dotted_getvariable` | 13 | 23.8s |  |
| 117 | `avm1_root_identity_and_playhead` | 3 | 24.1s |  |
| 118 | `avm1_runtime_filters` | 3 | 21.6s |  |
| 119 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.0s |  |
| 120 | `avm1_set_new_text_format_color` | 4 | 18.8s |  |
| 121 | `avm1_set_new_text_format_instance` | 5 | 1.6s |  |
| 122 | `avm1_set_new_text_format_render` | 5 | 19.1s |  |
| 123 | `avm1_set_new_text_format_size` | 5 | 1.6s |  |
| 124 | `avm1_stroke_style_id_order` | 1 | 18.7s |  |
| 125 | `avm1_swf6_case_insensitive_builtins` | 42 | 18.9s |  |
| 126 | `avm1_swf7_case_sensitive_builtins` | 40 | 0.9s |  |
| 127 | `avm1_textfield_attached_depth_order` | 1 | 21.9s |  |
| 128 | `avm1_textfield_x_bounds_offset` | 10 | 19.2s |  |
| 129 | `avm1_timer_clock_model` | 19 | 19.3s |  |
| 130 | `avm1_timer_function_form_activation` | 3 | 19.2s |  |
| 131 | `avm1_timer_method_form` | 6 | 19.0s |  |
| 132 | `avm1_timer_native_method_play` | 3 | 1.7s |  |
| 133 | `avm1_timer_overflow` | 10 | 2.2s |  |
| 134 | `avm1_timer_root_goto_stopped_gs` | 3 | 1.7s |  |
| 135 | `avm1_timer_root_goto_stopped_nf` | 3 | 19.6s |  |
| 136 | `avm1_type2_mc_receiver_dispatch` | 7 | 19.8s |  |
| 137 | `avm1_watch_long_name` | 9 | 1.7s |  |
| 138 | `avm1_watch_overflow` | 2 | 2.3s |  |
| 139 | `avm1_wrap_giveup_mixed_runs` | 2 | 2.0s |  |
| 140 | `avm1_xml_first_action_proto` | 2 | 1.7s |  |
| 141 | `avm1_xmlnode_first_action_proto` | 2 | 1.6s |  |
| 142 | `avm1_xscale_double_readback` | 8 | 19.6s |  |
| 143 | `avm2_activation_vtable_bounded` | 5 | 23.4s |  |
| 144 | `avm2_agi_shell` | 6 | 6.7s |  |
| 145 | `avm2_applyfilter_glow_kernels` | 17 | 6.3s |  |
| 146 | `avm2_applyfilter_gradient_opaque` | 24 | 6.8s |  |
| 147 | `avm2_array_growth_bounded` | 5 | 6.7s |  |
| 148 | `avm2_bitmapdata_draw_edittext_box` | 5 | 6.3s |  |
| 149 | `avm2_bitmapdata_draw_filtered` | 11 | 6.7s |  |
| 150 | `avm2_bitmapdata_draw_text_glyph_cx` | 16 | 6.8s |  |
| 151 | `avm2_bitmapdata_draw_textfield` | 5 | 26.8s |  |
| 152 | `avm2_child_simplebutton` | 10 | 25.0s |  |
| 153 | `avm2_contextmenu_stub` | 4 | 7.1s |  |
| 154 | `avm2_definetext_matrix` | 0 | 9.6s |  |
| 155 | `avm2_e4x_parse_bounded` | 18 | 8.1s |  |
| 156 | `avm2_edittext_placed_cxform` | 0 | 24.5s |  |
| 157 | `avm2_embed_bytearray` | 2 | 24.7s |  |
| 158 | `avm2_external_interface_unavailable` | 8 | 7.2s |  |
| 159 | `avm2_findprop_this_resolution` | 13 | 26.4s |  |
| 160 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.1s |  |
| 161 | `avm2_gc_string_concat_reclaim` | 10 | 7.1s |  |
| 162 | `avm2_gc_string_survives_collect` | 9 | 7.0s |  |
| 163 | `avm2_goto_catchup_scale` | 4 | 7.2s |  |
| 164 | `avm2_graphics_runtime` | 7 | 26.6s |  |
| 165 | `avm2_group_alpha_cab` | 0 | 24.3s |  |
| 166 | `avm2_group_alpha_filter_cm` | 0 | 7.1s |  |
| 167 | `avm2_group_alpha_layer_aadd` | 0 | 31.0s |  |
| 168 | `avm2_group_alpha_layer_inner` | 0 | 8.1s |  |
| 169 | `avm2_group_alpha_multiply` | 0 | 8.0s |  |
| 170 | `avm2_json_roundtrip_bounded` | 13 | 27.1s |  |
| 171 | `avm2_layer_group_alpha` | 0 | 8.8s |  |
| 172 | `avm2_layer_group_alpha_transparency` | 0 | 1.3s |  |
| 173 | `avm2_layer_group_erase` | 0 | 1.8s |  |
| 174 | `avm2_layer_group_filtered_child` | 0 | 26.3s |  |
| 175 | `avm2_layer_group_overlap_alpha` | 0 | 31.6s |  |
| 176 | `avm2_loader_stub` | 5 | 25.2s |  |
| 177 | `avm2_localconnection_domain` | 4 | 7.2s |  |
| 178 | `avm2_morph` | 8 | 27.6s |  |
| 179 | `avm2_parent_child_render` | 11 | 9.5s |  |
| 180 | `avm2_parent_child_static_text` | 12 | 7.5s |  |
| 181 | `avm2_parent_child_symbol_stride` | 6 | 8.4s |  |
| 182 | `avm2_parent_child_symbolclass_domain` | 12 | 7.6s |  |
| 183 | `avm2_reflect_trait_hooks` | 30 | 29.9s |  |
| 184 | `avm2_sharedobject_flushstatus` | 4 | 8.6s |  |
| 185 | `avm2_simplebutton_click` | 2 | 8.2s |  |
| 186 | `avm2_slot_default_template` | 34 | 8.7s |  |
| 187 | `avm2_sound_bytes_and_group_format` | 27 | 8.7s |  |
| 188 | `avm2_static_and_store_slots` | 14 | 8.6s |  |
| 189 | `avm2_static_text` | 6 | 29.3s |  |
| 190 | `avm2_strbuf_stale_prefix` | 21 | 8.7s |  |
| 191 | `avm2_timeline_gradients` | 7 | 39.5s |  |
| 192 | `avm2_timeline_solid` | 6 | 11.2s |  |
| 193 | `avm2_timeline_stroke_gradient` | 9 | 11.3s |  |
| 194 | `avm2_timeline_text` | 4 | 32.9s |  |
| 195 | `avm2_tolerant_verify_quarantine` | 2 | 9.8s |  |
| 196 | `avm2_typed_value_ops` | 30 | 10.0s |  |
| 197 | `bitmap_pool_layer_cap` | 1 | 26.9s |  |
| 198 | `broadcast_cross_swf_version` | 4 | 25.4s |  |
| 199 | `broadcast_type1_args` | 14 | 18.4s |  |
| 200 | `coerce_cross_swf_version` | 7 | 18.5s |  |
| 201 | `coerce_recursion_guard` | 1 | 1.5s |  |
| 202 | `coerce_type1_args` | 9 | 1.5s |  |
| 203 | `convertfloat_type1_this` | 3 | 1.5s |  |
| 204 | `ctor_before_first_call_locals` | 5 | 1.6s |  |
| 205 | `ei_closure_scope_order` | 7 | 1.6s |  |
| 206 | `ei_cross_swf_version` | 2 | 1.5s |  |
| 207 | `ei_mc_this_receiver` | 5 | 18.6s |  |
| 208 | `ei_type1_args` | 7 | 18.5s |  |
| 209 | `enterframe_type1_args` | 8 | 18.5s |  |
| 210 | `fn_call_builtin_type1_args` | 10 | 1.5s |  |
| 211 | `fn_call_type1_args` | 7 | 1.5s |  |
| 212 | `fn_empty_method_type1_args` | 10 | 1.5s |  |
| 213 | `group_alpha_cab` | 0 | 4.0s |  |
| 214 | `group_alpha_filter_cm` | 0 | 1.7s |  |
| 215 | `group_alpha_layer_aadd` | 0 | 19.0s |  |
| 216 | `group_alpha_layer_inner` | 0 | 1.8s |  |
| 217 | `group_alpha_multiply` | 0 | 1.8s |  |
| 218 | `layer_group_alpha_transparency` | 0 | 0.9s |  |
| 219 | `layer_group_filtered_child` | 0 | 16.9s |  |
| 220 | `layer_group_in_add_alpha` | 0 | 5.3s |  |
| 221 | `layer_group_overlap_alpha` | 0 | 1.9s |  |
| 222 | `layer_group_overlap_erase` | 0 | 1.0s |  |
| 223 | `lc_method_type1_args` | 7 | 24.6s |  |
| 224 | `lc_onstatus_type1_args` | 3 | 2.4s |  |
| 225 | `lv_cross_swf_version` | 5 | 24.7s |  |
| 226 | `lv_ondata_type1_args` | 3 | 24.6s |  |
| 227 | `mask_nested_intersect` | 1 | 28.1s |  |
| 228 | `mask_sibling_union` | 1 | 2.5s |  |
| 229 | `mc_event_cross_swf_version` | 4 | 2.5s |  |
| 230 | `mc_event_type1_args` | 3 | 2.4s |  |
| 231 | `mc_method_v5_caller_gate` | 4 | 27.1s |  |
| 232 | `mc_resolve_type1_args` | 6 | 26.7s |  |
| 233 | `method_type1_args` | 10 | 2.6s |  |
| 234 | `nc_onstatus_closure` | 2 | 26.6s |  |
| 235 | `nc_onstatus_type1_args` | 3 | 2.7s |  |
| 236 | `onconstruct_cross_swf_version` | 4 | 2.9s |  |
| 237 | `onconstruct_type1_args` | 6 | 2.4s |  |
| 238 | `onload_type1_args` | 7 | 2.4s |  |
| 239 | `onunload_type1_args` | 6 | 24.3s |  |
| 240 | `onunload_type1_local_frame` | 2 | 2.1s |  |
| 241 | `resolve_type1_args` | 13 | 2.1s |  |
| 242 | `root_enterframe_cross_swf_version` | 3 | 24.9s |  |
| 243 | `sort_comparator_captured_scope` | 2 | 2.5s |  |
| 244 | `sort_comparator_type1_args` | 5 | 2.3s |  |
| 245 | `string_prim_method_type1_args` | 19 | 2.4s |  |
| 246 | `timer_cross_swf_version` | 3 | 25.1s |  |
| 247 | `timer_type1_args` | 14 | 18.8s |  |
| 248 | `watch_cross_swf_version` | 6 | 18.9s |  |
| 249 | `watch_mc_reentrant_setmember` | 3 | 18.4s |  |
| 250 | `watch_mc_type1_args` | 7 | 1.5s |  |
| 251 | `watch_setmember_type1_args` | 7 | 1.5s |  |
| 252 | `watch_timeline_named_params` | 4 | 1.5s |  |
| 253 | `watch_timeline_reentrant` | 3 | 1.6s |  |
| 254 | `xml_onload_type1_args` | 3 | 18.6s |  |

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
