# Ruffle Test Results (Filtered)

**Date**: 2026-10-03 17:31 UTC

**Git SHA**: `c6be20a884`

**Run Duration**: 21m 37s

**Filtered**: 0 tests ignored out of 101 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 101 |
| Passing | **101** (100.0%) |
| Failing | 0 |
| Total expected lines | 838 |
| Matching lines | 838 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**101 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 22.5s |  |
| 2 | `array_method_type1_args` | 7 | 1.3s |  |
| 3 | `avm1_attach_clipevent_enterframe` | 11 | 22.4s |  |
| 4 | `avm1_child_timeline_advance` | 23 | 22.3s |  |
| 5 | `avm1_child_timeline_frame1_stop` | 7 | 13.3s |  |
| 6 | `avm1_child_timeline_holder_stop` | 26 | 1.0s |  |
| 7 | `avm1_child_timeline_loop` | 34 | 1.0s |  |
| 8 | `avm1_display_prop_coercion` | 36 | 13.2s |  |
| 9 | `avm1_mcl_holder_totalframes` | 5 | 1.6s |  |
| 10 | `avm1_mcl_load_tick` | 14 | 1.5s |  |
| 11 | `avm1_parent_as3_child_payload` | 2 | 1.5s |  |
| 12 | `avm1_parent_child_bitmap` | 5 | 1.6s |  |
| 13 | `avm1_parent_child_bitmap_fill` | 3 | 21.6s |  |
| 14 | `avm1_parent_child_modify_place` | 5 | 1.6s |  |
| 15 | `avm1_parent_child_morph` | 8 | 1.6s |  |
| 16 | `avm1_parent_child_render` | 7 | 1.7s |  |
| 17 | `avm1_parent_child_sprite_meta` | 8 | 21.7s |  |
| 18 | `avm1_parent_child_text` | 8 | 1.7s |  |
| 19 | `avm1_root_identity_and_playhead` | 3 | 21.3s |  |
| 20 | `avm2_agi_shell` | 6 | 45.5s |  |
| 21 | `avm2_array_growth_bounded` | 5 | 8.9s |  |
| 22 | `avm2_bitmapdata_draw_textfield` | 5 | 8.4s |  |
| 23 | `avm2_child_simplebutton` | 10 | 30.2s |  |
| 24 | `avm2_contextmenu_stub` | 4 | 7.8s |  |
| 25 | `avm2_e4x_parse_bounded` | 18 | 8.7s |  |
| 26 | `avm2_embed_bytearray` | 2 | 7.5s |  |
| 27 | `avm2_external_interface_unavailable` | 8 | 7.4s |  |
| 28 | `avm2_findprop_this_resolution` | 13 | 2.5s |  |
| 29 | `avm2_gc_dynprop_tombstone_purge` | 8 | 6.5s |  |
| 30 | `avm2_gc_string_concat_reclaim` | 10 | 6.3s |  |
| 31 | `avm2_gc_string_survives_collect` | 9 | 6.0s |  |
| 32 | `avm2_goto_catchup_scale` | 4 | 6.1s |  |
| 33 | `avm2_graphics_runtime` | 7 | 7.6s |  |
| 34 | `avm2_json_roundtrip_bounded` | 13 | 8.6s |  |
| 35 | `avm2_loader_stub` | 5 | 7.5s |  |
| 36 | `avm2_localconnection_domain` | 4 | 7.6s |  |
| 37 | `avm2_morph` | 8 | 46.8s |  |
| 38 | `avm2_parent_child_render` | 11 | 10.7s |  |
| 39 | `avm2_parent_child_static_text` | 12 | 8.3s |  |
| 40 | `avm2_parent_child_symbol_stride` | 6 | 30.3s |  |
| 41 | `avm2_parent_child_symbolclass_domain` | 12 | 32.5s |  |
| 42 | `avm2_reflect_trait_hooks` | 30 | 8.8s |  |
| 43 | `avm2_sharedobject_flushstatus` | 4 | 8.5s |  |
| 44 | `avm2_simplebutton_click` | 2 | 8.6s |  |
| 45 | `avm2_slot_default_template` | 34 | 30.3s |  |
| 46 | `avm2_sound_bytes_and_group_format` | 27 | 5.3s |  |
| 47 | `avm2_static_and_store_slots` | 14 | 5.1s |  |
| 48 | `avm2_static_text` | 6 | 36.8s |  |
| 49 | `avm2_timeline_gradients` | 7 | 23.1s |  |
| 50 | `avm2_timeline_solid` | 6 | 7.1s |  |
| 51 | `avm2_timeline_stroke_gradient` | 9 | 17.9s |  |
| 52 | `avm2_timeline_text` | 4 | 5.1s |  |
| 53 | `avm2_tolerant_verify_quarantine` | 2 | 4.9s |  |
| 54 | `avm2_typed_value_ops` | 30 | 47.0s |  |
| 55 | `bitmap_pool_layer_cap` | 1 | 23.1s |  |
| 56 | `broadcast_cross_swf_version` | 4 | 21.5s |  |
| 57 | `broadcast_type1_args` | 14 | 21.1s |  |
| 58 | `coerce_cross_swf_version` | 7 | 21.2s |  |
| 59 | `coerce_recursion_guard` | 1 | 1.3s |  |
| 60 | `coerce_type1_args` | 9 | 12.9s |  |
| 61 | `convertfloat_type1_this` | 3 | 0.8s |  |
| 62 | `ctor_before_first_call_locals` | 5 | 0.8s |  |
| 63 | `ei_closure_scope_order` | 7 | 22.8s |  |
| 64 | `ei_cross_swf_version` | 2 | 1.4s |  |
| 65 | `ei_type1_args` | 7 | 1.4s |  |
| 66 | `enterframe_type1_args` | 8 | 16.6s |  |
| 67 | `fn_call_builtin_type1_args` | 10 | 16.5s |  |
| 68 | `fn_call_type1_args` | 7 | 1.0s |  |
| 69 | `fn_empty_method_type1_args` | 10 | 21.9s |  |
| 70 | `lc_method_type1_args` | 7 | 1.3s |  |
| 71 | `lc_onstatus_type1_args` | 3 | 1.3s |  |
| 72 | `lv_cross_swf_version` | 5 | 18.3s |  |
| 73 | `lv_ondata_type1_args` | 3 | 18.1s |  |
| 74 | `mask_nested_intersect` | 1 | 18.1s |  |
| 75 | `mask_sibling_union` | 1 | 16.0s |  |
| 76 | `mc_event_cross_swf_version` | 4 | 15.9s |  |
| 77 | `mc_event_type1_args` | 3 | 16.0s |  |
| 78 | `mc_method_v5_caller_gate` | 4 | 21.4s |  |
| 79 | `mc_resolve_type1_args` | 6 | 21.0s |  |
| 80 | `method_type1_args` | 10 | 1.2s |  |
| 81 | `nc_onstatus_closure` | 2 | 20.8s |  |
| 82 | `nc_onstatus_type1_args` | 3 | 20.7s |  |
| 83 | `onconstruct_cross_swf_version` | 4 | 20.9s |  |
| 84 | `onconstruct_type1_args` | 6 | 21.4s |  |
| 85 | `onload_type1_args` | 7 | 21.7s |  |
| 86 | `onunload_type1_args` | 6 | 1.3s |  |
| 87 | `onunload_type1_local_frame` | 2 | 13.8s |  |
| 88 | `resolve_type1_args` | 13 | 0.9s |  |
| 89 | `root_enterframe_cross_swf_version` | 3 | 14.2s |  |
| 90 | `sort_comparator_captured_scope` | 2 | 1.3s |  |
| 91 | `sort_comparator_type1_args` | 5 | 21.6s |  |
| 92 | `string_prim_method_type1_args` | 19 | 1.1s |  |
| 93 | `timer_cross_swf_version` | 3 | 17.3s |  |
| 94 | `timer_type1_args` | 14 | 16.9s |  |
| 95 | `watch_cross_swf_version` | 6 | 1.2s |  |
| 96 | `watch_mc_reentrant_setmember` | 3 | 21.8s |  |
| 97 | `watch_mc_type1_args` | 7 | 1.3s |  |
| 98 | `watch_setmember_type1_args` | 7 | 1.3s |  |
| 99 | `watch_timeline_named_params` | 4 | 21.7s |  |
| 100 | `watch_timeline_reentrant` | 3 | 1.2s |  |
| 101 | `xml_onload_type1_args` | 3 | 21.9s |  |

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
