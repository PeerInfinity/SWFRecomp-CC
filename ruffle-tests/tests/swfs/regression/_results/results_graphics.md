# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-17 16:50 UTC

**Git SHA**: `aaf953dff9`

**Run Duration**: 14m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 103 |
| Passing | **103** (100.0%) |
| Failing | 0 |
| Total expected lines | 866 |
| Matching lines | 866 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**103 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 1.7s |  |
| 2 | `array_method_type1_args` | 7 | 1.7s |  |
| 3 | `avm1_attach_clipevent_enterframe` | 11 | 21.6s |  |
| 4 | `avm1_child_timeline_advance` | 23 | 2.0s |  |
| 5 | `avm1_child_timeline_frame1_stop` | 7 | 2.4s |  |
| 6 | `avm1_child_timeline_holder_stop` | 26 | 2.3s |  |
| 7 | `avm1_child_timeline_loop` | 34 | 2.5s |  |
| 8 | `avm1_closure_method_scope` | 7 | 2.3s |  |
| 9 | `avm1_display_prop_coercion` | 36 | 2.3s |  |
| 10 | `avm1_mcl_holder_totalframes` | 5 | 22.6s |  |
| 11 | `avm1_mcl_load_tick` | 14 | 2.3s |  |
| 12 | `avm1_parent_as3_child_payload` | 2 | 2.3s |  |
| 13 | `avm1_parent_child_bitmap` | 5 | 1.8s |  |
| 14 | `avm1_parent_child_bitmap_fill` | 3 | 18.2s |  |
| 15 | `avm1_parent_child_modify_place` | 5 | 1.8s |  |
| 16 | `avm1_parent_child_morph` | 8 | 1.8s |  |
| 17 | `avm1_parent_child_render` | 7 | 2.6s |  |
| 18 | `avm1_parent_child_sprite_meta` | 8 | 2.5s |  |
| 19 | `avm1_parent_child_text` | 8 | 2.5s |  |
| 20 | `avm1_root_identity_and_playhead` | 3 | 22.1s |  |
| 21 | `avm2_agi_shell` | 6 | 3.3s |  |
| 22 | `avm2_array_growth_bounded` | 5 | 9.9s |  |
| 23 | `avm2_bitmapdata_draw_textfield` | 5 | 9.5s |  |
| 24 | `avm2_child_simplebutton` | 10 | 30.6s |  |
| 25 | `avm2_contextmenu_stub` | 4 | 7.0s |  |
| 26 | `avm2_e4x_parse_bounded` | 18 | 7.5s |  |
| 27 | `avm2_embed_bytearray` | 2 | 6.4s |  |
| 28 | `avm2_external_interface_unavailable` | 8 | 6.5s |  |
| 29 | `avm2_findprop_this_resolution` | 13 | 6.2s |  |
| 30 | `avm2_gc_dynprop_tombstone_purge` | 8 | 6.5s |  |
| 31 | `avm2_gc_string_concat_reclaim` | 10 | 6.3s |  |
| 32 | `avm2_gc_string_survives_collect` | 9 | 6.0s |  |
| 33 | `avm2_goto_catchup_scale` | 4 | 6.2s |  |
| 34 | `avm2_graphics_runtime` | 7 | 16.6s |  |
| 35 | `avm2_json_roundtrip_bounded` | 13 | 6.2s |  |
| 36 | `avm2_loader_stub` | 5 | 5.7s |  |
| 37 | `avm2_localconnection_domain` | 4 | 9.1s |  |
| 38 | `avm2_morph` | 8 | 30.0s |  |
| 39 | `avm2_parent_child_render` | 11 | 12.4s |  |
| 40 | `avm2_parent_child_static_text` | 12 | 9.7s |  |
| 41 | `avm2_parent_child_symbol_stride` | 6 | 31.1s |  |
| 42 | `avm2_parent_child_symbolclass_domain` | 12 | 9.1s |  |
| 43 | `avm2_reflect_trait_hooks` | 30 | 9.0s |  |
| 44 | `avm2_sharedobject_flushstatus` | 4 | 8.7s |  |
| 45 | `avm2_simplebutton_click` | 2 | 7.2s |  |
| 46 | `avm2_slot_default_template` | 34 | 7.4s |  |
| 47 | `avm2_sound_bytes_and_group_format` | 27 | 7.4s |  |
| 48 | `avm2_static_and_store_slots` | 14 | 7.3s |  |
| 49 | `avm2_static_text` | 6 | 28.7s |  |
| 50 | `avm2_strbuf_stale_prefix` | 21 | 8.9s |  |
| 51 | `avm2_timeline_gradients` | 7 | 30.4s |  |
| 52 | `avm2_timeline_solid` | 6 | 10.0s |  |
| 53 | `avm2_timeline_stroke_gradient` | 9 | 19.4s |  |
| 54 | `avm2_timeline_text` | 4 | 6.2s |  |
| 55 | `avm2_tolerant_verify_quarantine` | 2 | 5.9s |  |
| 56 | `avm2_typed_value_ops` | 30 | 9.2s |  |
| 57 | `bitmap_pool_layer_cap` | 1 | 23.8s |  |
| 58 | `broadcast_cross_swf_version` | 4 | 21.9s |  |
| 59 | `broadcast_type1_args` | 14 | 1.8s |  |
| 60 | `coerce_cross_swf_version` | 7 | 17.8s |  |
| 61 | `coerce_recursion_guard` | 1 | 1.8s |  |
| 62 | `coerce_type1_args` | 9 | 2.0s |  |
| 63 | `convertfloat_type1_this` | 3 | 2.0s |  |
| 64 | `ctor_before_first_call_locals` | 5 | 2.1s |  |
| 65 | `ei_closure_scope_order` | 7 | 2.0s |  |
| 66 | `ei_cross_swf_version` | 2 | 1.9s |  |
| 67 | `ei_type1_args` | 7 | 1.9s |  |
| 68 | `enterframe_type1_args` | 8 | 22.4s |  |
| 69 | `fn_call_builtin_type1_args` | 10 | 1.8s |  |
| 70 | `fn_call_type1_args` | 7 | 1.8s |  |
| 71 | `fn_empty_method_type1_args` | 10 | 2.0s |  |
| 72 | `lc_method_type1_args` | 7 | 2.0s |  |
| 73 | `lc_onstatus_type1_args` | 3 | 2.0s |  |
| 74 | `lv_cross_swf_version` | 5 | 23.9s |  |
| 75 | `lv_ondata_type1_args` | 3 | 2.1s |  |
| 76 | `mask_nested_intersect` | 1 | 2.7s |  |
| 77 | `mask_sibling_union` | 1 | 2.2s |  |
| 78 | `mc_event_cross_swf_version` | 4 | 21.9s |  |
| 79 | `mc_event_type1_args` | 3 | 2.0s |  |
| 80 | `mc_method_v5_caller_gate` | 4 | 22.7s |  |
| 81 | `mc_resolve_type1_args` | 6 | 2.0s |  |
| 82 | `method_type1_args` | 10 | 2.0s |  |
| 83 | `nc_onstatus_closure` | 2 | 2.0s |  |
| 84 | `nc_onstatus_type1_args` | 3 | 2.0s |  |
| 85 | `onconstruct_cross_swf_version` | 4 | 22.2s |  |
| 86 | `onconstruct_type1_args` | 6 | 1.4s |  |
| 87 | `onload_type1_args` | 7 | 2.4s |  |
| 88 | `onunload_type1_args` | 6 | 1.3s |  |
| 89 | `onunload_type1_local_frame` | 2 | 2.1s |  |
| 90 | `resolve_type1_args` | 13 | 2.1s |  |
| 91 | `root_enterframe_cross_swf_version` | 3 | 22.8s |  |
| 92 | `sort_comparator_captured_scope` | 2 | 2.0s |  |
| 93 | `sort_comparator_type1_args` | 5 | 1.9s |  |
| 94 | `string_prim_method_type1_args` | 19 | 1.9s |  |
| 95 | `timer_cross_swf_version` | 3 | 22.6s |  |
| 96 | `timer_type1_args` | 14 | 22.4s |  |
| 97 | `watch_cross_swf_version` | 6 | 2.0s |  |
| 98 | `watch_mc_reentrant_setmember` | 3 | 2.0s |  |
| 99 | `watch_mc_type1_args` | 7 | 2.0s |  |
| 100 | `watch_setmember_type1_args` | 7 | 2.0s |  |
| 101 | `watch_timeline_named_params` | 4 | 0.8s |  |
| 102 | `watch_timeline_reentrant` | 3 | 0.9s |  |
| 103 | `xml_onload_type1_args` | 3 | 0.9s |  |

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
