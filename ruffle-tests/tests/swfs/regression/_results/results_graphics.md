# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-23 07:07 UTC

**Git SHA**: `da9b49b17a`

**Run Duration**: 28m 50s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 158 |
| Passing | **158** (100.0%) |
| Failing | 0 |
| Total expected lines | 1369 |
| Matching lines | 1369 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**158 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 18.5s |  |
| 2 | `array_method_type1_args` | 7 | 1.4s |  |
| 3 | `avm1_array_generic_receivers` | 16 | 18.7s |  |
| 4 | `avm1_array_native_own_method` | 8 | 1.5s |  |
| 5 | `avm1_attach_clipevent_enterframe` | 11 | 18.8s |  |
| 6 | `avm1_attached_clip_button_click` | 13 | 18.9s |  |
| 7 | `avm1_attached_clip_color` | 2 | 18.7s |  |
| 8 | `avm1_attached_clip_goto_play` | 14 | 19.0s |  |
| 9 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.6s |  |
| 10 | `avm1_attached_clip_hidden_capture` | 6 | 18.7s |  |
| 11 | `avm1_attached_clip_natural_timeline` | 34 | 18.8s |  |
| 12 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.6s |  |
| 13 | `avm1_attached_clip_samename_child` | 32 | 24.5s |  |
| 14 | `avm1_attached_clip_tagorder` | 34 | 24.5s |  |
| 15 | `avm1_attached_clip_tagorder_nonroot` | 34 | 2.5s |  |
| 16 | `avm1_attached_clip_tagorder_po3` | 34 | 2.4s |  |
| 17 | `avm1_attached_clip_tagorder_ratio` | 34 | 2.4s |  |
| 18 | `avm1_bare_mc_method_scope` | 19 | 24.3s |  |
| 19 | `avm1_child_timeline_advance` | 23 | 21.5s |  |
| 20 | `avm1_child_timeline_frame1_stop` | 7 | 2.4s |  |
| 21 | `avm1_child_timeline_holder_stop` | 26 | 2.3s |  |
| 22 | `avm1_child_timeline_loop` | 34 | 2.4s |  |
| 23 | `avm1_closure_base_clip_root_frame` | 5 | 2.2s |  |
| 24 | `avm1_closure_method_scope` | 7 | 2.6s |  |
| 25 | `avm1_create_text_field_depth` | 9 | 19.3s |  |
| 26 | `avm1_cxform_override_overflow` | 2 | 19.4s |  |
| 27 | `avm1_device_edittext_xscale` | 7 | 19.4s |  |
| 28 | `avm1_display_prop_coercion` | 36 | 2.0s |  |
| 29 | `avm1_dynclip_color_transform` | 2 | 2.4s |  |
| 30 | `avm1_edittext_placed_cxform_script` | 3 | 19.3s |  |
| 31 | `avm1_filter_list_overflow` | 2 | 2.4s |  |
| 32 | `avm1_func2_param_register_oob` | 4 | 1.9s |  |
| 33 | `avm1_hittest_hairline` | 28 | 24.1s |  |
| 34 | `avm1_jpeg3_alpha_bitmap` | 0 | 23.6s |  |
| 35 | `avm1_key_isdown_protected` | 8 | 2.1s |  |
| 36 | `avm1_long_text_layout` | 2 | 2.1s |  |
| 37 | `avm1_many_chars_registry` | 4 | 19.1s |  |
| 38 | `avm1_many_defs_registry` | 13 | 20.6s |  |
| 39 | `avm1_many_functions_registry` | 3 | 9.0s |  |
| 40 | `avm1_mcl_holder_totalframes` | 5 | 19.1s |  |
| 41 | `avm1_mcl_load_tick` | 14 | 1.6s |  |
| 42 | `avm1_nested_po3_filters` | 12 | 2.1s |  |
| 43 | `avm1_parent_as3_child_payload` | 2 | 2.2s |  |
| 44 | `avm1_parent_child_bitmap` | 5 | 2.2s |  |
| 45 | `avm1_parent_child_bitmap_fill` | 3 | 24.0s |  |
| 46 | `avm1_parent_child_modify_place` | 5 | 2.2s |  |
| 47 | `avm1_parent_child_morph` | 8 | 2.4s |  |
| 48 | `avm1_parent_child_render` | 7 | 2.4s |  |
| 49 | `avm1_parent_child_sprite_meta` | 8 | 21.4s |  |
| 50 | `avm1_parent_child_text` | 8 | 2.5s |  |
| 51 | `avm1_pixelbounds_dynamic_child` | 1 | 21.2s |  |
| 52 | `avm1_placed_drawing_color` | 1 | 21.2s |  |
| 53 | `avm1_po3_color_matrix_live` | 0 | 2.1s |  |
| 54 | `avm1_po3_color_matrix_live_clear` | 1 | 27.2s |  |
| 55 | `avm1_po3_color_matrix_live_nested` | 0 | 2.4s |  |
| 56 | `avm1_remove_same_name_other_parent` | 4 | 24.3s |  |
| 57 | `avm1_removed_clip_dprops_gc` | 14 | 2.5s |  |
| 58 | `avm1_root_identity_and_playhead` | 3 | 24.1s |  |
| 59 | `avm1_runtime_filters` | 3 | 19.8s |  |
| 60 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.0s |  |
| 61 | `avm1_set_new_text_format_color` | 4 | 18.9s |  |
| 62 | `avm1_timer_clock_model` | 19 | 18.9s |  |
| 63 | `avm1_timer_function_form_activation` | 3 | 18.5s |  |
| 64 | `avm1_type2_mc_receiver_dispatch` | 7 | 25.5s |  |
| 65 | `avm1_xml_first_action_proto` | 2 | 2.4s |  |
| 66 | `avm1_xmlnode_first_action_proto` | 2 | 2.3s |  |
| 67 | `avm2_activation_vtable_bounded` | 5 | 10.8s |  |
| 68 | `avm2_agi_shell` | 6 | 3.7s |  |
| 69 | `avm2_array_growth_bounded` | 5 | 7.5s |  |
| 70 | `avm2_bitmapdata_draw_textfield` | 5 | 7.4s |  |
| 71 | `avm2_child_simplebutton` | 10 | 24.0s |  |
| 72 | `avm2_contextmenu_stub` | 4 | 6.6s |  |
| 73 | `avm2_e4x_parse_bounded` | 18 | 7.4s |  |
| 74 | `avm2_embed_bytearray` | 2 | 6.7s |  |
| 75 | `avm2_external_interface_unavailable` | 8 | 6.8s |  |
| 76 | `avm2_findprop_this_resolution` | 13 | 2.3s |  |
| 77 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.0s |  |
| 78 | `avm2_gc_string_concat_reclaim` | 10 | 6.9s |  |
| 79 | `avm2_gc_string_survives_collect` | 9 | 7.4s |  |
| 80 | `avm2_goto_catchup_scale` | 4 | 7.1s |  |
| 81 | `avm2_graphics_runtime` | 7 | 24.8s |  |
| 82 | `avm2_json_roundtrip_bounded` | 13 | 7.9s |  |
| 83 | `avm2_layer_group_alpha` | 0 | 7.7s |  |
| 84 | `avm2_layer_group_erase` | 0 | 10.8s |  |
| 85 | `avm2_layer_group_filtered_child` | 0 | 32.3s |  |
| 86 | `avm2_layer_group_overlap_alpha` | 0 | 32.2s |  |
| 87 | `avm2_loader_stub` | 5 | 9.9s |  |
| 88 | `avm2_localconnection_domain` | 4 | 9.8s |  |
| 89 | `avm2_morph` | 8 | 40.1s |  |
| 90 | `avm2_parent_child_render` | 11 | 9.1s |  |
| 91 | `avm2_parent_child_static_text` | 12 | 6.9s |  |
| 92 | `avm2_parent_child_symbol_stride` | 6 | 23.2s |  |
| 93 | `avm2_parent_child_symbolclass_domain` | 12 | 7.3s |  |
| 94 | `avm2_reflect_trait_hooks` | 30 | 7.8s |  |
| 95 | `avm2_sharedobject_flushstatus` | 4 | 7.5s |  |
| 96 | `avm2_simplebutton_click` | 2 | 7.5s |  |
| 97 | `avm2_slot_default_template` | 34 | 7.8s |  |
| 98 | `avm2_sound_bytes_and_group_format` | 27 | 7.9s |  |
| 99 | `avm2_static_and_store_slots` | 14 | 7.3s |  |
| 100 | `avm2_static_text` | 6 | 24.7s |  |
| 101 | `avm2_strbuf_stale_prefix` | 21 | 7.1s |  |
| 102 | `avm2_timeline_gradients` | 7 | 26.0s |  |
| 103 | `avm2_timeline_solid` | 6 | 8.1s |  |
| 104 | `avm2_timeline_stroke_gradient` | 9 | 33.9s |  |
| 105 | `avm2_timeline_text` | 4 | 10.1s |  |
| 106 | `avm2_tolerant_verify_quarantine` | 2 | 9.7s |  |
| 107 | `avm2_typed_value_ops` | 30 | 10.0s |  |
| 108 | `bitmap_pool_layer_cap` | 1 | 27.1s |  |
| 109 | `broadcast_cross_swf_version` | 4 | 18.2s |  |
| 110 | `broadcast_type1_args` | 14 | 1.4s |  |
| 111 | `coerce_cross_swf_version` | 7 | 1.5s |  |
| 112 | `coerce_recursion_guard` | 1 | 1.4s |  |
| 113 | `coerce_type1_args` | 9 | 1.4s |  |
| 114 | `convertfloat_type1_this` | 3 | 24.2s |  |
| 115 | `ctor_before_first_call_locals` | 5 | 2.2s |  |
| 116 | `ei_closure_scope_order` | 7 | 2.3s |  |
| 117 | `ei_cross_swf_version` | 2 | 2.2s |  |
| 118 | `ei_type1_args` | 7 | 2.2s |  |
| 119 | `enterframe_type1_args` | 8 | 24.3s |  |
| 120 | `fn_call_builtin_type1_args` | 10 | 24.5s |  |
| 121 | `fn_call_type1_args` | 7 | 2.2s |  |
| 122 | `fn_empty_method_type1_args` | 10 | 2.2s |  |
| 123 | `layer_group_filtered_child` | 0 | 27.3s |  |
| 124 | `layer_group_in_add_alpha` | 0 | 1.7s |  |
| 125 | `layer_group_overlap_alpha` | 0 | 1.5s |  |
| 126 | `layer_group_overlap_erase` | 0 | 0.8s |  |
| 127 | `lc_method_type1_args` | 7 | 1.4s |  |
| 128 | `lc_onstatus_type1_args` | 3 | 1.4s |  |
| 129 | `lv_cross_swf_version` | 5 | 19.1s |  |
| 130 | `lv_ondata_type1_args` | 3 | 18.8s |  |
| 131 | `mask_nested_intersect` | 1 | 19.2s |  |
| 132 | `mask_sibling_union` | 1 | 1.6s |  |
| 133 | `mc_event_cross_swf_version` | 4 | 1.6s |  |
| 134 | `mc_event_type1_args` | 3 | 1.4s |  |
| 135 | `mc_method_v5_caller_gate` | 4 | 18.3s |  |
| 136 | `mc_resolve_type1_args` | 6 | 1.4s |  |
| 137 | `method_type1_args` | 10 | 1.4s |  |
| 138 | `nc_onstatus_closure` | 2 | 18.4s |  |
| 139 | `nc_onstatus_type1_args` | 3 | 2.1s |  |
| 140 | `onconstruct_cross_swf_version` | 4 | 21.3s |  |
| 141 | `onconstruct_type1_args` | 6 | 1.9s |  |
| 142 | `onload_type1_args` | 7 | 20.9s |  |
| 143 | `onunload_type1_args` | 6 | 2.1s |  |
| 144 | `onunload_type1_local_frame` | 2 | 17.9s |  |
| 145 | `resolve_type1_args` | 13 | 1.4s |  |
| 146 | `root_enterframe_cross_swf_version` | 3 | 18.0s |  |
| 147 | `sort_comparator_captured_scope` | 2 | 18.0s |  |
| 148 | `sort_comparator_type1_args` | 5 | 1.4s |  |
| 149 | `string_prim_method_type1_args` | 19 | 1.4s |  |
| 150 | `timer_cross_swf_version` | 3 | 18.5s |  |
| 151 | `timer_type1_args` | 14 | 18.4s |  |
| 152 | `watch_cross_swf_version` | 6 | 1.6s |  |
| 153 | `watch_mc_reentrant_setmember` | 3 | 1.4s |  |
| 154 | `watch_mc_type1_args` | 7 | 1.5s |  |
| 155 | `watch_setmember_type1_args` | 7 | 1.4s |  |
| 156 | `watch_timeline_named_params` | 4 | 1.4s |  |
| 157 | `watch_timeline_reentrant` | 3 | 1.4s |  |
| 158 | `xml_onload_type1_args` | 3 | 18.4s |  |

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
