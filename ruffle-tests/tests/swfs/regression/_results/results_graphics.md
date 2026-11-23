# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-23 03:52 UTC

**Git SHA**: `a18a9cc61d`

**Run Duration**: 34m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 142 |
| Passing | **142** (100.0%) |
| Failing | 0 |
| Total expected lines | 1293 |
| Matching lines | 1293 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**142 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 23.6s |  |
| 2 | `array_method_type1_args` | 7 | 1.8s |  |
| 3 | `avm1_array_generic_receivers` | 16 | 23.7s |  |
| 4 | `avm1_array_native_own_method` | 8 | 1.9s |  |
| 5 | `avm1_attach_clipevent_enterframe` | 11 | 23.9s |  |
| 6 | `avm1_attached_clip_button_click` | 13 | 19.3s |  |
| 7 | `avm1_attached_clip_color` | 2 | 21.1s |  |
| 8 | `avm1_attached_clip_goto_play` | 14 | 19.5s |  |
| 9 | `avm1_attached_clip_goto_play_nonroot` | 14 | 1.7s |  |
| 10 | `avm1_attached_clip_hidden_capture` | 6 | 19.7s |  |
| 11 | `avm1_attached_clip_natural_timeline` | 34 | 18.7s |  |
| 12 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.5s |  |
| 13 | `avm1_attached_clip_samename_child` | 32 | 19.0s |  |
| 14 | `avm1_attached_clip_tagorder` | 34 | 1.5s |  |
| 15 | `avm1_attached_clip_tagorder_nonroot` | 34 | 0.7s |  |
| 16 | `avm1_attached_clip_tagorder_po3` | 34 | 24.6s |  |
| 17 | `avm1_attached_clip_tagorder_ratio` | 34 | 2.4s |  |
| 18 | `avm1_bare_mc_method_scope` | 19 | 24.4s |  |
| 19 | `avm1_child_timeline_advance` | 23 | 24.5s |  |
| 20 | `avm1_child_timeline_frame1_stop` | 7 | 2.5s |  |
| 21 | `avm1_child_timeline_holder_stop` | 26 | 18.6s |  |
| 22 | `avm1_child_timeline_loop` | 34 | 1.7s |  |
| 23 | `avm1_closure_base_clip_root_frame` | 5 | 1.6s |  |
| 24 | `avm1_closure_method_scope` | 7 | 1.6s |  |
| 25 | `avm1_create_text_field_depth` | 9 | 18.5s |  |
| 26 | `avm1_device_edittext_xscale` | 7 | 18.9s |  |
| 27 | `avm1_display_prop_coercion` | 36 | 1.7s |  |
| 28 | `avm1_dynclip_color_transform` | 2 | 1.9s |  |
| 29 | `avm1_hittest_hairline` | 28 | 18.8s |  |
| 30 | `avm1_many_chars_registry` | 4 | 18.6s |  |
| 31 | `avm1_mcl_holder_totalframes` | 5 | 18.5s |  |
| 32 | `avm1_mcl_load_tick` | 14 | 1.6s |  |
| 33 | `avm1_nested_po3_filters` | 12 | 2.0s |  |
| 34 | `avm1_parent_as3_child_payload` | 2 | 1.6s |  |
| 35 | `avm1_parent_child_bitmap` | 5 | 1.7s |  |
| 36 | `avm1_parent_child_bitmap_fill` | 3 | 21.1s |  |
| 37 | `avm1_parent_child_modify_place` | 5 | 1.6s |  |
| 38 | `avm1_parent_child_morph` | 8 | 1.7s |  |
| 39 | `avm1_parent_child_render` | 7 | 1.7s |  |
| 40 | `avm1_parent_child_sprite_meta` | 8 | 1.7s |  |
| 41 | `avm1_parent_child_text` | 8 | 18.5s |  |
| 42 | `avm1_placed_drawing_color` | 1 | 18.6s |  |
| 43 | `avm1_root_identity_and_playhead` | 3 | 18.4s |  |
| 44 | `avm1_runtime_filters` | 3 | 19.4s |  |
| 45 | `avm1_runtime_filters_cm_bitmap` | 5 | 2.0s |  |
| 46 | `avm1_set_new_text_format_color` | 4 | 18.4s |  |
| 47 | `avm1_timer_function_form_activation` | 3 | 18.2s |  |
| 48 | `avm1_type2_mc_receiver_dispatch` | 7 | 18.2s |  |
| 49 | `avm1_xml_first_action_proto` | 2 | 1.4s |  |
| 50 | `avm1_xmlnode_first_action_proto` | 2 | 1.4s |  |
| 51 | `avm2_activation_vtable_bounded` | 5 | 41.4s |  |
| 52 | `avm2_agi_shell` | 6 | 7.0s |  |
| 53 | `avm2_array_growth_bounded` | 5 | 7.4s |  |
| 54 | `avm2_bitmapdata_draw_textfield` | 5 | 7.2s |  |
| 55 | `avm2_child_simplebutton` | 10 | 24.3s |  |
| 56 | `avm2_contextmenu_stub` | 4 | 40.5s |  |
| 57 | `avm2_e4x_parse_bounded` | 18 | 8.0s |  |
| 58 | `avm2_embed_bytearray` | 2 | 24.1s |  |
| 59 | `avm2_external_interface_unavailable` | 8 | 6.9s |  |
| 60 | `avm2_findprop_this_resolution` | 13 | 7.0s |  |
| 61 | `avm2_gc_dynprop_tombstone_purge` | 8 | 57.7s |  |
| 62 | `avm2_gc_string_concat_reclaim` | 10 | 10.6s |  |
| 63 | `avm2_gc_string_survives_collect` | 9 | 10.4s |  |
| 64 | `avm2_goto_catchup_scale` | 4 | 10.6s |  |
| 65 | `avm2_graphics_runtime` | 7 | 37.8s |  |
| 66 | `avm2_json_roundtrip_bounded` | 13 | 35.7s |  |
| 67 | `avm2_layer_group_alpha` | 0 | 10.2s |  |
| 68 | `avm2_layer_group_erase` | 0 | 1.5s |  |
| 69 | `avm2_layer_group_filtered_child` | 0 | 22.7s |  |
| 70 | `avm2_layer_group_overlap_alpha` | 0 | 21.3s |  |
| 71 | `avm2_loader_stub` | 5 | 39.0s |  |
| 72 | `avm2_localconnection_domain` | 4 | 6.6s |  |
| 73 | `avm2_morph` | 8 | 25.4s |  |
| 74 | `avm2_parent_child_render` | 11 | 8.9s |  |
| 75 | `avm2_parent_child_static_text` | 12 | 7.0s |  |
| 76 | `avm2_parent_child_symbol_stride` | 6 | 41.4s |  |
| 77 | `avm2_parent_child_symbolclass_domain` | 12 | 7.2s |  |
| 78 | `avm2_reflect_trait_hooks` | 30 | 24.5s |  |
| 79 | `avm2_sharedobject_flushstatus` | 4 | 6.9s |  |
| 80 | `avm2_simplebutton_click` | 2 | 7.1s |  |
| 81 | `avm2_slot_default_template` | 34 | 40.3s |  |
| 82 | `avm2_sound_bytes_and_group_format` | 27 | 7.2s |  |
| 83 | `avm2_static_and_store_slots` | 14 | 7.1s |  |
| 84 | `avm2_static_text` | 6 | 24.4s |  |
| 85 | `avm2_strbuf_stale_prefix` | 21 | 6.9s |  |
| 86 | `avm2_timeline_gradients` | 7 | 43.2s |  |
| 87 | `avm2_timeline_solid` | 6 | 7.9s |  |
| 88 | `avm2_timeline_stroke_gradient` | 9 | 8.0s |  |
| 89 | `avm2_timeline_text` | 4 | 24.3s |  |
| 90 | `avm2_tolerant_verify_quarantine` | 2 | 6.9s |  |
| 91 | `avm2_typed_value_ops` | 30 | 39.8s |  |
| 92 | `bitmap_pool_layer_cap` | 1 | 21.5s |  |
| 93 | `broadcast_cross_swf_version` | 4 | 18.1s |  |
| 94 | `broadcast_type1_args` | 14 | 18.3s |  |
| 95 | `coerce_cross_swf_version` | 7 | 1.5s |  |
| 96 | `coerce_recursion_guard` | 1 | 18.3s |  |
| 97 | `coerce_type1_args` | 9 | 1.4s |  |
| 98 | `convertfloat_type1_this` | 3 | 1.4s |  |
| 99 | `ctor_before_first_call_locals` | 5 | 1.4s |  |
| 100 | `ei_closure_scope_order` | 7 | 1.5s |  |
| 101 | `ei_cross_swf_version` | 2 | 18.8s |  |
| 102 | `ei_type1_args` | 7 | 1.5s |  |
| 103 | `enterframe_type1_args` | 8 | 18.6s |  |
| 104 | `fn_call_builtin_type1_args` | 10 | 1.5s |  |
| 105 | `fn_call_type1_args` | 7 | 1.5s |  |
| 106 | `fn_empty_method_type1_args` | 10 | 24.6s |  |
| 107 | `layer_group_filtered_child` | 0 | 27.9s |  |
| 108 | `layer_group_in_add_alpha` | 0 | 29.2s |  |
| 109 | `layer_group_overlap_alpha` | 0 | 2.4s |  |
| 110 | `layer_group_overlap_erase` | 0 | 1.1s |  |
| 111 | `lc_method_type1_args` | 7 | 17.9s |  |
| 112 | `lc_onstatus_type1_args` | 3 | 1.3s |  |
| 113 | `lv_cross_swf_version` | 5 | 18.0s |  |
| 114 | `lv_ondata_type1_args` | 3 | 17.7s |  |
| 115 | `mask_nested_intersect` | 1 | 21.0s |  |
| 116 | `mask_sibling_union` | 1 | 1.5s |  |
| 117 | `mc_event_cross_swf_version` | 4 | 18.7s |  |
| 118 | `mc_event_type1_args` | 3 | 18.6s |  |
| 119 | `mc_method_v5_caller_gate` | 4 | 25.3s |  |
| 120 | `mc_resolve_type1_args` | 6 | 25.0s |  |
| 121 | `method_type1_args` | 10 | 2.1s |  |
| 122 | `nc_onstatus_closure` | 2 | 25.0s |  |
| 123 | `nc_onstatus_type1_args` | 3 | 23.9s |  |
| 124 | `onconstruct_cross_swf_version` | 4 | 24.2s |  |
| 125 | `onconstruct_type1_args` | 6 | 1.9s |  |
| 126 | `onload_type1_args` | 7 | 23.9s |  |
| 127 | `onunload_type1_args` | 6 | 23.6s |  |
| 128 | `onunload_type1_local_frame` | 2 | 2.1s |  |
| 129 | `resolve_type1_args` | 13 | 2.2s |  |
| 130 | `root_enterframe_cross_swf_version` | 3 | 23.8s |  |
| 131 | `sort_comparator_captured_scope` | 2 | 18.5s |  |
| 132 | `sort_comparator_type1_args` | 5 | 18.1s |  |
| 133 | `string_prim_method_type1_args` | 19 | 1.4s |  |
| 134 | `timer_cross_swf_version` | 3 | 18.1s |  |
| 135 | `timer_type1_args` | 14 | 24.2s |  |
| 136 | `watch_cross_swf_version` | 6 | 24.3s |  |
| 137 | `watch_mc_reentrant_setmember` | 3 | 24.1s |  |
| 138 | `watch_mc_type1_args` | 7 | 2.2s |  |
| 139 | `watch_setmember_type1_args` | 7 | 18.3s |  |
| 140 | `watch_timeline_named_params` | 4 | 1.4s |  |
| 141 | `watch_timeline_reentrant` | 3 | 1.4s |  |
| 142 | `xml_onload_type1_args` | 3 | 18.4s |  |

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
