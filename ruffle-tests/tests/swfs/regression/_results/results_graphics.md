# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-22 01:00 UTC

**Git SHA**: `ff2e2e9d60`

**Run Duration**: 23m 47s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 109 |
| Passing | **109** (100.0%) |
| Failing | 0 |
| Total expected lines | 970 |
| Matching lines | 970 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**109 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 17.6s |  |
| 2 | `array_method_type1_args` | 7 | 1.3s |  |
| 3 | `avm1_attach_clipevent_enterframe` | 11 | 17.6s |  |
| 4 | `avm1_attached_clip_goto_play` | 14 | 17.7s |  |
| 5 | `avm1_attached_clip_goto_play_nonroot` | 14 | 22.9s |  |
| 6 | `avm1_attached_clip_natural_timeline` | 34 | 22.8s |  |
| 7 | `avm1_attached_clip_natural_timeline_nonroot` | 34 | 2.1s |  |
| 8 | `avm1_child_timeline_advance` | 23 | 22.5s |  |
| 9 | `avm1_child_timeline_frame1_stop` | 7 | 1.6s |  |
| 10 | `avm1_child_timeline_holder_stop` | 26 | 1.5s |  |
| 11 | `avm1_child_timeline_loop` | 34 | 1.6s |  |
| 12 | `avm1_closure_method_scope` | 7 | 1.5s |  |
| 13 | `avm1_display_prop_coercion` | 36 | 1.6s |  |
| 14 | `avm1_mcl_holder_totalframes` | 5 | 18.3s |  |
| 15 | `avm1_mcl_load_tick` | 14 | 1.6s |  |
| 16 | `avm1_parent_as3_child_payload` | 2 | 1.6s |  |
| 17 | `avm1_parent_child_bitmap` | 5 | 1.7s |  |
| 18 | `avm1_parent_child_bitmap_fill` | 3 | 19.8s |  |
| 19 | `avm1_parent_child_modify_place` | 5 | 1.6s |  |
| 20 | `avm1_parent_child_morph` | 8 | 1.7s |  |
| 21 | `avm1_parent_child_render` | 7 | 17.7s |  |
| 22 | `avm1_parent_child_sprite_meta` | 8 | 1.7s |  |
| 23 | `avm1_parent_child_text` | 8 | 1.7s |  |
| 24 | `avm1_root_identity_and_playhead` | 3 | 17.7s |  |
| 25 | `avm1_runtime_filters` | 3 | 18.0s |  |
| 26 | `avm2_activation_vtable_bounded` | 5 | 23.4s |  |
| 27 | `avm2_agi_shell` | 6 | 6.5s |  |
| 28 | `avm2_array_growth_bounded` | 5 | 7.2s |  |
| 29 | `avm2_bitmapdata_draw_textfield` | 5 | 23.8s |  |
| 30 | `avm2_child_simplebutton` | 10 | 23.9s |  |
| 31 | `avm2_contextmenu_stub` | 4 | 6.9s |  |
| 32 | `avm2_e4x_parse_bounded` | 18 | 7.9s |  |
| 33 | `avm2_embed_bytearray` | 2 | 22.9s |  |
| 34 | `avm2_external_interface_unavailable` | 8 | 23.0s |  |
| 35 | `avm2_findprop_this_resolution` | 13 | 6.8s |  |
| 36 | `avm2_gc_dynprop_tombstone_purge` | 8 | 6.9s |  |
| 37 | `avm2_gc_string_concat_reclaim` | 10 | 24.1s |  |
| 38 | `avm2_gc_string_survives_collect` | 9 | 7.7s |  |
| 39 | `avm2_goto_catchup_scale` | 4 | 7.8s |  |
| 40 | `avm2_graphics_runtime` | 7 | 25.8s |  |
| 41 | `avm2_json_roundtrip_bounded` | 13 | 24.0s |  |
| 42 | `avm2_loader_stub` | 5 | 6.7s |  |
| 43 | `avm2_localconnection_domain` | 4 | 6.7s |  |
| 44 | `avm2_morph` | 8 | 24.7s |  |
| 45 | `avm2_parent_child_render` | 11 | 24.4s |  |
| 46 | `avm2_parent_child_static_text` | 12 | 6.8s |  |
| 47 | `avm2_parent_child_symbol_stride` | 6 | 23.3s |  |
| 48 | `avm2_parent_child_symbolclass_domain` | 12 | 6.6s |  |
| 49 | `avm2_reflect_trait_hooks` | 30 | 23.4s |  |
| 50 | `avm2_sharedobject_flushstatus` | 4 | 6.7s |  |
| 51 | `avm2_simplebutton_click` | 2 | 6.8s |  |
| 52 | `avm2_slot_default_template` | 34 | 6.9s |  |
| 53 | `avm2_sound_bytes_and_group_format` | 27 | 29.9s |  |
| 54 | `avm2_static_and_store_slots` | 14 | 9.0s |  |
| 55 | `avm2_static_text` | 6 | 29.6s |  |
| 56 | `avm2_strbuf_stale_prefix` | 21 | 8.9s |  |
| 57 | `avm2_timeline_gradients` | 7 | 27.8s |  |
| 58 | `avm2_timeline_solid` | 6 | 8.7s |  |
| 59 | `avm2_timeline_stroke_gradient` | 9 | 8.9s |  |
| 60 | `avm2_timeline_text` | 4 | 25.6s |  |
| 61 | `avm2_tolerant_verify_quarantine` | 2 | 23.3s |  |
| 62 | `avm2_typed_value_ops` | 30 | 6.9s |  |
| 63 | `bitmap_pool_layer_cap` | 1 | 21.2s |  |
| 64 | `broadcast_cross_swf_version` | 4 | 17.8s |  |
| 65 | `broadcast_type1_args` | 14 | 17.3s |  |
| 66 | `coerce_cross_swf_version` | 7 | 17.5s |  |
| 67 | `coerce_recursion_guard` | 1 | 1.4s |  |
| 68 | `coerce_type1_args` | 9 | 1.3s |  |
| 69 | `convertfloat_type1_this` | 3 | 23.1s |  |
| 70 | `ctor_before_first_call_locals` | 5 | 2.2s |  |
| 71 | `ei_closure_scope_order` | 7 | 2.3s |  |
| 72 | `ei_cross_swf_version` | 2 | 2.2s |  |
| 73 | `ei_type1_args` | 7 | 17.1s |  |
| 74 | `enterframe_type1_args` | 8 | 17.0s |  |
| 75 | `fn_call_builtin_type1_args` | 10 | 1.3s |  |
| 76 | `fn_call_type1_args` | 7 | 1.3s |  |
| 77 | `fn_empty_method_type1_args` | 10 | 17.1s |  |
| 78 | `lc_method_type1_args` | 7 | 1.4s |  |
| 79 | `lc_onstatus_type1_args` | 3 | 1.3s |  |
| 80 | `lv_cross_swf_version` | 5 | 17.4s |  |
| 81 | `lv_ondata_type1_args` | 3 | 17.4s |  |
| 82 | `mask_nested_intersect` | 1 | 19.8s |  |
| 83 | `mask_sibling_union` | 1 | 27.5s |  |
| 84 | `mc_event_cross_swf_version` | 4 | 25.1s |  |
| 85 | `mc_event_type1_args` | 3 | 24.5s |  |
| 86 | `mc_method_v5_caller_gate` | 4 | 17.0s |  |
| 87 | `mc_resolve_type1_args` | 6 | 17.0s |  |
| 88 | `method_type1_args` | 10 | 1.3s |  |
| 89 | `nc_onstatus_closure` | 2 | 17.7s |  |
| 90 | `nc_onstatus_type1_args` | 3 | 17.6s |  |
| 91 | `onconstruct_cross_swf_version` | 4 | 17.7s |  |
| 92 | `onconstruct_type1_args` | 6 | 25.1s |  |
| 93 | `onload_type1_args` | 7 | 25.2s |  |
| 94 | `onunload_type1_args` | 6 | 1.9s |  |
| 95 | `onunload_type1_local_frame` | 2 | 16.9s |  |
| 96 | `resolve_type1_args` | 13 | 1.4s |  |
| 97 | `root_enterframe_cross_swf_version` | 3 | 17.3s |  |
| 98 | `sort_comparator_captured_scope` | 2 | 18.2s |  |
| 99 | `sort_comparator_type1_args` | 5 | 18.0s |  |
| 100 | `string_prim_method_type1_args` | 19 | 1.8s |  |
| 101 | `timer_cross_swf_version` | 3 | 17.1s |  |
| 102 | `timer_type1_args` | 14 | 17.2s |  |
| 103 | `watch_cross_swf_version` | 6 | 1.4s |  |
| 104 | `watch_mc_reentrant_setmember` | 3 | 22.0s |  |
| 105 | `watch_mc_type1_args` | 7 | 1.6s |  |
| 106 | `watch_setmember_type1_args` | 7 | 1.6s |  |
| 107 | `watch_timeline_named_params` | 4 | 23.3s |  |
| 108 | `watch_timeline_reentrant` | 3 | 2.0s |  |
| 109 | `xml_onload_type1_args` | 3 | 23.3s |  |

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
