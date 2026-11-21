# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 19:32 UTC

**Git SHA**: `c489b84d99`

**Run Duration**: 25m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 104 |
| Passing | **104** (100.0%) |
| Failing | 0 |
| Total expected lines | 871 |
| Matching lines | 871 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**104 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 17.4s |  |
| 2 | `array_method_type1_args` | 7 | 1.4s |  |
| 3 | `avm1_attach_clipevent_enterframe` | 11 | 17.8s |  |
| 4 | `avm1_child_timeline_advance` | 23 | 17.7s |  |
| 5 | `avm1_child_timeline_frame1_stop` | 7 | 17.6s |  |
| 6 | `avm1_child_timeline_holder_stop` | 26 | 1.6s |  |
| 7 | `avm1_child_timeline_loop` | 34 | 1.6s |  |
| 8 | `avm1_closure_method_scope` | 7 | 17.4s |  |
| 9 | `avm1_display_prop_coercion` | 36 | 2.0s |  |
| 10 | `avm1_mcl_holder_totalframes` | 5 | 2.1s |  |
| 11 | `avm1_mcl_load_tick` | 14 | 2.0s |  |
| 12 | `avm1_parent_as3_child_payload` | 2 | 2.0s |  |
| 13 | `avm1_parent_child_bitmap` | 5 | 2.6s |  |
| 14 | `avm1_parent_child_bitmap_fill` | 3 | 26.0s |  |
| 15 | `avm1_parent_child_modify_place` | 5 | 2.5s |  |
| 16 | `avm1_parent_child_morph` | 8 | 2.6s |  |
| 17 | `avm1_parent_child_render` | 7 | 19.8s |  |
| 18 | `avm1_parent_child_sprite_meta` | 8 | 1.8s |  |
| 19 | `avm1_parent_child_text` | 8 | 1.8s |  |
| 20 | `avm1_root_identity_and_playhead` | 3 | 17.8s |  |
| 21 | `avm2_activation_vtable_bounded` | 5 | 25.4s |  |
| 22 | `avm2_agi_shell` | 6 | 7.9s |  |
| 23 | `avm2_array_growth_bounded` | 5 | 8.4s |  |
| 24 | `avm2_bitmapdata_draw_textfield` | 5 | 8.2s |  |
| 25 | `avm2_child_simplebutton` | 10 | 38.6s |  |
| 26 | `avm2_contextmenu_stub` | 4 | 22.9s |  |
| 27 | `avm2_e4x_parse_bounded` | 18 | 7.8s |  |
| 28 | `avm2_embed_bytearray` | 2 | 23.0s |  |
| 29 | `avm2_external_interface_unavailable` | 8 | 38.9s |  |
| 30 | `avm2_findprop_this_resolution` | 13 | 6.9s |  |
| 31 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.0s |  |
| 32 | `avm2_gc_string_concat_reclaim` | 10 | 6.8s |  |
| 33 | `avm2_gc_string_survives_collect` | 9 | 52.7s |  |
| 34 | `avm2_goto_catchup_scale` | 4 | 9.9s |  |
| 35 | `avm2_graphics_runtime` | 7 | 31.1s |  |
| 36 | `avm2_json_roundtrip_bounded` | 13 | 10.7s |  |
| 37 | `avm2_loader_stub` | 5 | 50.2s |  |
| 38 | `avm2_localconnection_domain` | 4 | 9.2s |  |
| 39 | `avm2_morph` | 8 | 31.9s |  |
| 40 | `avm2_parent_child_render` | 11 | 12.4s |  |
| 41 | `avm2_parent_child_static_text` | 12 | 39.0s |  |
| 42 | `avm2_parent_child_symbol_stride` | 6 | 24.0s |  |
| 43 | `avm2_parent_child_symbolclass_domain` | 12 | 6.9s |  |
| 44 | `avm2_reflect_trait_hooks` | 30 | 23.2s |  |
| 45 | `avm2_sharedobject_flushstatus` | 4 | 39.0s |  |
| 46 | `avm2_simplebutton_click` | 2 | 6.9s |  |
| 47 | `avm2_slot_default_template` | 34 | 6.9s |  |
| 48 | `avm2_sound_bytes_and_group_format` | 27 | 7.0s |  |
| 49 | `avm2_static_and_store_slots` | 14 | 37.4s |  |
| 50 | `avm2_static_text` | 6 | 22.1s |  |
| 51 | `avm2_strbuf_stale_prefix` | 21 | 6.6s |  |
| 52 | `avm2_timeline_gradients` | 7 | 24.8s |  |
| 53 | `avm2_timeline_solid` | 6 | 41.3s |  |
| 54 | `avm2_timeline_stroke_gradient` | 9 | 7.8s |  |
| 55 | `avm2_timeline_text` | 4 | 23.4s |  |
| 56 | `avm2_tolerant_verify_quarantine` | 2 | 6.8s |  |
| 57 | `avm2_typed_value_ops` | 30 | 40.3s |  |
| 58 | `bitmap_pool_layer_cap` | 1 | 21.5s |  |
| 59 | `broadcast_cross_swf_version` | 4 | 17.9s |  |
| 60 | `broadcast_type1_args` | 14 | 17.4s |  |
| 61 | `coerce_cross_swf_version` | 7 | 17.3s |  |
| 62 | `coerce_recursion_guard` | 1 | 1.4s |  |
| 63 | `coerce_type1_args` | 9 | 17.4s |  |
| 64 | `convertfloat_type1_this` | 3 | 1.4s |  |
| 65 | `ctor_before_first_call_locals` | 5 | 1.4s |  |
| 66 | `ei_closure_scope_order` | 7 | 22.8s |  |
| 67 | `ei_cross_swf_version` | 2 | 2.2s |  |
| 68 | `ei_type1_args` | 7 | 2.2s |  |
| 69 | `enterframe_type1_args` | 8 | 17.6s |  |
| 70 | `fn_call_builtin_type1_args` | 10 | 17.8s |  |
| 71 | `fn_call_type1_args` | 7 | 1.4s |  |
| 72 | `fn_empty_method_type1_args` | 10 | 16.9s |  |
| 73 | `lc_method_type1_args` | 7 | 1.4s |  |
| 74 | `lc_onstatus_type1_args` | 3 | 1.3s |  |
| 75 | `lv_cross_swf_version` | 5 | 16.9s |  |
| 76 | `lv_ondata_type1_args` | 3 | 16.8s |  |
| 77 | `mask_nested_intersect` | 1 | 19.1s |  |
| 78 | `mask_sibling_union` | 1 | 16.1s |  |
| 79 | `mc_event_cross_swf_version` | 4 | 14.5s |  |
| 80 | `mc_event_type1_args` | 3 | 14.2s |  |
| 81 | `mc_method_v5_caller_gate` | 4 | 16.9s |  |
| 82 | `mc_resolve_type1_args` | 6 | 16.7s |  |
| 83 | `method_type1_args` | 10 | 1.3s |  |
| 84 | `nc_onstatus_closure` | 2 | 16.5s |  |
| 85 | `nc_onstatus_type1_args` | 3 | 16.2s |  |
| 86 | `onconstruct_cross_swf_version` | 4 | 16.0s |  |
| 87 | `onconstruct_type1_args` | 6 | 17.0s |  |
| 88 | `onload_type1_args` | 7 | 17.0s |  |
| 89 | `onunload_type1_args` | 6 | 1.0s |  |
| 90 | `onunload_type1_local_frame` | 2 | 23.0s |  |
| 91 | `resolve_type1_args` | 13 | 2.2s |  |
| 92 | `root_enterframe_cross_swf_version` | 3 | 22.9s |  |
| 93 | `sort_comparator_captured_scope` | 2 | 17.2s |  |
| 94 | `sort_comparator_type1_args` | 5 | 17.1s |  |
| 95 | `string_prim_method_type1_args` | 19 | 1.4s |  |
| 96 | `timer_cross_swf_version` | 3 | 24.6s |  |
| 97 | `timer_type1_args` | 14 | 24.6s |  |
| 98 | `watch_cross_swf_version` | 6 | 2.5s |  |
| 99 | `watch_mc_reentrant_setmember` | 3 | 16.9s |  |
| 100 | `watch_mc_type1_args` | 7 | 0.9s |  |
| 101 | `watch_setmember_type1_args` | 7 | 0.9s |  |
| 102 | `watch_timeline_named_params` | 4 | 17.8s |  |
| 103 | `watch_timeline_reentrant` | 3 | 1.5s |  |
| 104 | `xml_onload_type1_args` | 3 | 17.8s |  |

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
