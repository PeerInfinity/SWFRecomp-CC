# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 18:24 UTC

**Git SHA**: `bc91565cea`

**Run Duration**: 23m 53s

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
| 1 | `array_element_type1_args` | 7 | 17.1s |  |
| 2 | `array_method_type1_args` | 7 | 1.3s |  |
| 3 | `avm1_attach_clipevent_enterframe` | 11 | 17.2s |  |
| 4 | `avm1_child_timeline_advance` | 23 | 17.2s |  |
| 5 | `avm1_child_timeline_frame1_stop` | 7 | 22.2s |  |
| 6 | `avm1_child_timeline_holder_stop` | 26 | 1.8s |  |
| 7 | `avm1_child_timeline_loop` | 34 | 1.8s |  |
| 8 | `avm1_closure_method_scope` | 7 | 21.8s |  |
| 9 | `avm1_display_prop_coercion` | 36 | 2.4s |  |
| 10 | `avm1_mcl_holder_totalframes` | 5 | 2.5s |  |
| 11 | `avm1_mcl_load_tick` | 14 | 2.5s |  |
| 12 | `avm1_parent_as3_child_payload` | 2 | 2.4s |  |
| 13 | `avm1_parent_child_bitmap` | 5 | 2.2s |  |
| 14 | `avm1_parent_child_bitmap_fill` | 3 | 22.3s |  |
| 15 | `avm1_parent_child_modify_place` | 5 | 2.2s |  |
| 16 | `avm1_parent_child_morph` | 8 | 2.3s |  |
| 17 | `avm1_parent_child_render` | 7 | 26.2s |  |
| 18 | `avm1_parent_child_sprite_meta` | 8 | 2.6s |  |
| 19 | `avm1_parent_child_text` | 8 | 2.6s |  |
| 20 | `avm1_root_identity_and_playhead` | 3 | 24.8s |  |
| 21 | `avm2_activation_vtable_bounded` | 5 | 23.2s |  |
| 22 | `avm2_agi_shell` | 6 | 6.5s |  |
| 23 | `avm2_array_growth_bounded` | 5 | 7.1s |  |
| 24 | `avm2_bitmapdata_draw_textfield` | 5 | 7.0s |  |
| 25 | `avm2_child_simplebutton` | 10 | 23.4s |  |
| 26 | `avm2_contextmenu_stub` | 4 | 22.6s |  |
| 27 | `avm2_e4x_parse_bounded` | 18 | 7.6s |  |
| 28 | `avm2_embed_bytearray` | 2 | 22.7s |  |
| 29 | `avm2_external_interface_unavailable` | 8 | 31.2s |  |
| 30 | `avm2_findprop_this_resolution` | 13 | 10.0s |  |
| 31 | `avm2_gc_dynprop_tombstone_purge` | 8 | 9.7s |  |
| 32 | `avm2_gc_string_concat_reclaim` | 10 | 9.7s |  |
| 33 | `avm2_gc_string_survives_collect` | 9 | 32.2s |  |
| 34 | `avm2_goto_catchup_scale` | 4 | 10.0s |  |
| 35 | `avm2_graphics_runtime` | 7 | 32.8s |  |
| 36 | `avm2_json_roundtrip_bounded` | 13 | 11.4s |  |
| 37 | `avm2_loader_stub` | 5 | 30.0s |  |
| 38 | `avm2_localconnection_domain` | 4 | 9.2s |  |
| 39 | `avm2_morph` | 8 | 32.3s |  |
| 40 | `avm2_parent_child_render` | 11 | 12.2s |  |
| 41 | `avm2_parent_child_static_text` | 12 | 22.8s |  |
| 42 | `avm2_parent_child_symbol_stride` | 6 | 23.6s |  |
| 43 | `avm2_parent_child_symbolclass_domain` | 12 | 6.7s |  |
| 44 | `avm2_reflect_trait_hooks` | 30 | 22.5s |  |
| 45 | `avm2_sharedobject_flushstatus` | 4 | 26.4s |  |
| 46 | `avm2_simplebutton_click` | 2 | 8.3s |  |
| 47 | `avm2_slot_default_template` | 34 | 8.6s |  |
| 48 | `avm2_sound_bytes_and_group_format` | 27 | 8.7s |  |
| 49 | `avm2_static_and_store_slots` | 14 | 22.6s |  |
| 50 | `avm2_static_text` | 6 | 22.6s |  |
| 51 | `avm2_strbuf_stale_prefix` | 21 | 6.6s |  |
| 52 | `avm2_timeline_gradients` | 7 | 25.4s |  |
| 53 | `avm2_timeline_solid` | 6 | 25.8s |  |
| 54 | `avm2_timeline_stroke_gradient` | 9 | 7.8s |  |
| 55 | `avm2_timeline_text` | 4 | 23.5s |  |
| 56 | `avm2_tolerant_verify_quarantine` | 2 | 6.6s |  |
| 57 | `avm2_typed_value_ops` | 30 | 23.4s |  |
| 58 | `bitmap_pool_layer_cap` | 1 | 21.1s |  |
| 59 | `broadcast_cross_swf_version` | 4 | 17.8s |  |
| 60 | `broadcast_type1_args` | 14 | 17.4s |  |
| 61 | `coerce_cross_swf_version` | 7 | 17.8s |  |
| 62 | `coerce_recursion_guard` | 1 | 1.5s |  |
| 63 | `coerce_type1_args` | 9 | 18.2s |  |
| 64 | `convertfloat_type1_this` | 3 | 1.7s |  |
| 65 | `ctor_before_first_call_locals` | 5 | 1.8s |  |
| 66 | `ei_closure_scope_order` | 7 | 17.1s |  |
| 67 | `ei_cross_swf_version` | 2 | 1.3s |  |
| 68 | `ei_type1_args` | 7 | 1.3s |  |
| 69 | `enterframe_type1_args` | 8 | 17.2s |  |
| 70 | `fn_call_builtin_type1_args` | 10 | 17.1s |  |
| 71 | `fn_call_type1_args` | 7 | 1.3s |  |
| 72 | `fn_empty_method_type1_args` | 10 | 17.6s |  |
| 73 | `lc_method_type1_args` | 7 | 1.4s |  |
| 74 | `lc_onstatus_type1_args` | 3 | 1.4s |  |
| 75 | `lv_cross_swf_version` | 5 | 16.4s |  |
| 76 | `lv_ondata_type1_args` | 3 | 16.5s |  |
| 77 | `mask_nested_intersect` | 1 | 18.8s |  |
| 78 | `mask_sibling_union` | 1 | 19.4s |  |
| 79 | `mc_event_cross_swf_version` | 4 | 17.4s |  |
| 80 | `mc_event_type1_args` | 3 | 17.4s |  |
| 81 | `mc_method_v5_caller_gate` | 4 | 23.7s |  |
| 82 | `mc_resolve_type1_args` | 6 | 24.0s |  |
| 83 | `method_type1_args` | 10 | 2.2s |  |
| 84 | `nc_onstatus_closure` | 2 | 16.7s |  |
| 85 | `nc_onstatus_type1_args` | 3 | 16.5s |  |
| 86 | `onconstruct_cross_swf_version` | 4 | 16.6s |  |
| 87 | `onconstruct_type1_args` | 6 | 17.2s |  |
| 88 | `onload_type1_args` | 7 | 17.4s |  |
| 89 | `onunload_type1_args` | 6 | 1.4s |  |
| 90 | `onunload_type1_local_frame` | 2 | 17.3s |  |
| 91 | `resolve_type1_args` | 13 | 1.4s |  |
| 92 | `root_enterframe_cross_swf_version` | 3 | 17.4s |  |
| 93 | `sort_comparator_captured_scope` | 2 | 23.3s |  |
| 94 | `sort_comparator_type1_args` | 5 | 23.1s |  |
| 95 | `string_prim_method_type1_args` | 19 | 1.9s |  |
| 96 | `timer_cross_swf_version` | 3 | 17.6s |  |
| 97 | `timer_type1_args` | 14 | 17.5s |  |
| 98 | `watch_cross_swf_version` | 6 | 1.5s |  |
| 99 | `watch_mc_reentrant_setmember` | 3 | 16.9s |  |
| 100 | `watch_mc_type1_args` | 7 | 1.3s |  |
| 101 | `watch_setmember_type1_args` | 7 | 1.3s |  |
| 102 | `watch_timeline_named_params` | 4 | 17.2s |  |
| 103 | `watch_timeline_reentrant` | 3 | 1.4s |  |
| 104 | `xml_onload_type1_args` | 3 | 17.1s |  |

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
