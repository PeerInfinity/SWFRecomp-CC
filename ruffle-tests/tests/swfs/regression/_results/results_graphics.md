# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-22 03:10 UTC

**Git SHA**: `6b2054090f`

**Run Duration**: 22m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 111 |
| Passing | **111** (100.0%) |
| Failing | 0 |
| Total expected lines | 974 |
| Matching lines | 974 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**111 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 18.5s |  |
| 2 | `array_method_type1_args` | 7 | 1.7s |  |
| 3 | `avm1_attach_clipevent_enterframe` | 11 | 18.6s |  |
| 4 | `avm1_attached_clip_goto_play` | 14 | 18.9s |  |
| 5 | `avm1_attached_clip_goto_play_nonroot` | 14 | 18.4s |  |
| 6 | `avm1_attached_clip_natural_timeline` | 34 | 18.4s |  |
| 7 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 1.6s |  |
| 8 | `avm1_child_timeline_advance` | 23 | 18.3s |  |
| 9 | `avm1_child_timeline_frame1_stop` | 7 | 1.7s |  |
| 10 | `avm1_child_timeline_holder_stop` | 26 | 1.6s |  |
| 11 | `avm1_child_timeline_loop` | 34 | 1.7s |  |
| 12 | `avm1_closure_method_scope` | 7 | 1.6s |  |
| 13 | `avm1_display_prop_coercion` | 36 | 1.5s |  |
| 14 | `avm1_mcl_holder_totalframes` | 5 | 17.1s |  |
| 15 | `avm1_mcl_load_tick` | 14 | 1.5s |  |
| 16 | `avm1_parent_as3_child_payload` | 2 | 1.5s |  |
| 17 | `avm1_parent_child_bitmap` | 5 | 1.7s |  |
| 18 | `avm1_parent_child_bitmap_fill` | 3 | 18.2s |  |
| 19 | `avm1_parent_child_modify_place` | 5 | 1.7s |  |
| 20 | `avm1_parent_child_morph` | 8 | 1.7s |  |
| 21 | `avm1_parent_child_render` | 7 | 18.2s |  |
| 22 | `avm1_parent_child_sprite_meta` | 8 | 1.8s |  |
| 23 | `avm1_parent_child_text` | 8 | 1.8s |  |
| 24 | `avm1_root_identity_and_playhead` | 3 | 18.1s |  |
| 25 | `avm1_runtime_filters` | 3 | 18.0s |  |
| 26 | `avm1_xml_first_action_proto` | 2 | 1.4s |  |
| 27 | `avm1_xmlnode_first_action_proto` | 2 | 1.3s |  |
| 28 | `avm2_activation_vtable_bounded` | 5 | 23.7s |  |
| 29 | `avm2_agi_shell` | 6 | 16.6s |  |
| 30 | `avm2_array_growth_bounded` | 5 | 7.3s |  |
| 31 | `avm2_bitmapdata_draw_textfield` | 5 | 7.3s |  |
| 32 | `avm2_child_simplebutton` | 10 | 22.1s |  |
| 33 | `avm2_contextmenu_stub` | 4 | 27.4s |  |
| 34 | `avm2_e4x_parse_bounded` | 18 | 9.7s |  |
| 35 | `avm2_embed_bytearray` | 2 | 26.1s |  |
| 36 | `avm2_external_interface_unavailable` | 8 | 8.3s |  |
| 37 | `avm2_findprop_this_resolution` | 13 | 18.5s |  |
| 38 | `avm2_gc_dynprop_tombstone_purge` | 8 | 6.8s |  |
| 39 | `avm2_gc_string_concat_reclaim` | 10 | 6.7s |  |
| 40 | `avm2_gc_string_survives_collect` | 9 | 6.6s |  |
| 41 | `avm2_goto_catchup_scale` | 4 | 23.2s |  |
| 42 | `avm2_graphics_runtime` | 7 | 23.1s |  |
| 43 | `avm2_json_roundtrip_bounded` | 13 | 7.5s |  |
| 44 | `avm2_loader_stub` | 5 | 6.7s |  |
| 45 | `avm2_localconnection_domain` | 4 | 22.8s |  |
| 46 | `avm2_morph` | 8 | 23.0s |  |
| 47 | `avm2_parent_child_render` | 11 | 9.0s |  |
| 48 | `avm2_parent_child_static_text` | 12 | 7.1s |  |
| 49 | `avm2_parent_child_symbol_stride` | 6 | 25.6s |  |
| 50 | `avm2_parent_child_symbolclass_domain` | 12 | 7.9s |  |
| 51 | `avm2_reflect_trait_hooks` | 30 | 24.2s |  |
| 52 | `avm2_sharedobject_flushstatus` | 4 | 7.4s |  |
| 53 | `avm2_simplebutton_click` | 2 | 22.6s |  |
| 54 | `avm2_slot_default_template` | 34 | 6.8s |  |
| 55 | `avm2_sound_bytes_and_group_format` | 27 | 6.9s |  |
| 56 | `avm2_static_and_store_slots` | 14 | 6.7s |  |
| 57 | `avm2_static_text` | 6 | 23.4s |  |
| 58 | `avm2_strbuf_stale_prefix` | 21 | 23.3s |  |
| 59 | `avm2_timeline_gradients` | 7 | 24.5s |  |
| 60 | `avm2_timeline_solid` | 6 | 7.7s |  |
| 61 | `avm2_timeline_stroke_gradient` | 9 | 25.1s |  |
| 62 | `avm2_timeline_text` | 4 | 24.2s |  |
| 63 | `avm2_tolerant_verify_quarantine` | 2 | 7.5s |  |
| 64 | `avm2_typed_value_ops` | 30 | 7.6s |  |
| 65 | `bitmap_pool_layer_cap` | 1 | 19.7s |  |
| 66 | `broadcast_cross_swf_version` | 4 | 18.1s |  |
| 67 | `broadcast_type1_args` | 14 | 18.0s |  |
| 68 | `coerce_cross_swf_version` | 7 | 1.5s |  |
| 69 | `coerce_recursion_guard` | 1 | 17.3s |  |
| 70 | `coerce_type1_args` | 9 | 1.4s |  |
| 71 | `convertfloat_type1_this` | 3 | 1.3s |  |
| 72 | `ctor_before_first_call_locals` | 5 | 1.4s |  |
| 73 | `ei_closure_scope_order` | 7 | 17.6s |  |
| 74 | `ei_cross_swf_version` | 2 | 1.4s |  |
| 75 | `ei_type1_args` | 7 | 1.4s |  |
| 76 | `enterframe_type1_args` | 8 | 17.4s |  |
| 77 | `fn_call_builtin_type1_args` | 10 | 19.2s |  |
| 78 | `fn_call_type1_args` | 7 | 1.6s |  |
| 79 | `fn_empty_method_type1_args` | 10 | 1.5s |  |
| 80 | `lc_method_type1_args` | 7 | 1.6s |  |
| 81 | `lc_onstatus_type1_args` | 3 | 18.0s |  |
| 82 | `lv_cross_swf_version` | 5 | 18.0s |  |
| 83 | `lv_ondata_type1_args` | 3 | 17.9s |  |
| 84 | `mask_nested_intersect` | 1 | 18.2s |  |
| 85 | `mask_sibling_union` | 1 | 19.3s |  |
| 86 | `mc_event_cross_swf_version` | 4 | 19.4s |  |
| 87 | `mc_event_type1_args` | 3 | 19.4s |  |
| 88 | `mc_method_v5_caller_gate` | 4 | 14.1s |  |
| 89 | `mc_resolve_type1_args` | 6 | 13.8s |  |
| 90 | `method_type1_args` | 10 | 1.4s |  |
| 91 | `nc_onstatus_closure` | 2 | 17.4s |  |
| 92 | `nc_onstatus_type1_args` | 3 | 17.5s |  |
| 93 | `onconstruct_cross_swf_version` | 4 | 17.4s |  |
| 94 | `onconstruct_type1_args` | 6 | 17.5s |  |
| 95 | `onload_type1_args` | 7 | 17.4s |  |
| 96 | `onunload_type1_args` | 6 | 1.1s |  |
| 97 | `onunload_type1_local_frame` | 2 | 17.7s |  |
| 98 | `resolve_type1_args` | 13 | 1.4s |  |
| 99 | `root_enterframe_cross_swf_version` | 3 | 17.9s |  |
| 100 | `sort_comparator_captured_scope` | 2 | 17.2s |  |
| 101 | `sort_comparator_type1_args` | 5 | 17.1s |  |
| 102 | `string_prim_method_type1_args` | 19 | 1.3s |  |
| 103 | `timer_cross_swf_version` | 3 | 14.2s |  |
| 104 | `timer_type1_args` | 14 | 13.8s |  |
| 105 | `watch_cross_swf_version` | 6 | 0.7s |  |
| 106 | `watch_mc_reentrant_setmember` | 3 | 17.8s |  |
| 107 | `watch_mc_type1_args` | 7 | 1.2s |  |
| 108 | `watch_setmember_type1_args` | 7 | 1.2s |  |
| 109 | `watch_timeline_named_params` | 4 | 18.1s |  |
| 110 | `watch_timeline_reentrant` | 3 | 1.5s |  |
| 111 | `xml_onload_type1_args` | 3 | 18.1s |  |

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
