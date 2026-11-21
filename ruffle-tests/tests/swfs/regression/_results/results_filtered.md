# Ruffle Test Results (Filtered)

**Date**: 2026-11-21 19:30 UTC

**Git SHA**: `bc91565cea`

**Run Duration**: 19m 19s

**Filtered**: 0 tests ignored out of 104 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 100 |
| Passing | **100** (100.0%) |
| Failing | 0 |
| Total expected lines | 804 |
| Matching lines | 804 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**100 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 16.4s |  |
| 2 | `array_method_type1_args` | 7 | 0.8s |  |
| 3 | `avm1_attach_clipevent_enterframe` | 11 | 16.9s |  |
| 4 | `avm1_child_timeline_advance` | 23 | 16.8s |  |
| 5 | `avm1_child_timeline_frame1_stop` | 7 | 17.0s |  |
| 6 | `avm1_child_timeline_holder_stop` | 26 | 1.0s |  |
| 7 | `avm1_child_timeline_loop` | 34 | 1.1s |  |
| 8 | `avm1_closure_method_scope` | 7 | 16.9s |  |
| 9 | `avm1_display_prop_coercion` | 36 | 1.3s |  |
| 10 | `avm1_mcl_holder_totalframes` | 5 | 1.7s |  |
| 11 | `avm1_mcl_load_tick` | 14 | 1.5s |  |
| 12 | `avm1_parent_as3_child_payload` | 2 | 1.3s |  |
| 13 | `avm1_parent_child_bitmap` | 5 | 1.1s |  |
| 14 | `avm1_parent_child_bitmap_fill` | 3 | 17.1s |  |
| 15 | `avm1_parent_child_modify_place` | 5 | 1.0s |  |
| 16 | `avm1_parent_child_morph` | 8 | 1.1s |  |
| 17 | `avm1_parent_child_render` | 7 | 16.6s |  |
| 18 | `avm1_parent_child_sprite_meta` | 8 | 1.1s |  |
| 19 | `avm1_parent_child_text` | 8 | 1.1s |  |
| 20 | `avm1_root_identity_and_playhead` | 3 | 16.5s |  |
| 21 | `avm2_activation_vtable_bounded` | 5 | 6.1s |  |
| 22 | `avm2_agi_shell` | 6 | 5.7s |  |
| 23 | `avm2_array_growth_bounded` | 5 | 6.2s |  |
| 24 | `avm2_bitmapdata_draw_textfield` | 5 | 6.1s |  |
| 25 | `avm2_child_simplebutton` | 10 | 22.0s |  |
| 26 | `avm2_contextmenu_stub` | 4 | 5.6s |  |
| 27 | `avm2_e4x_parse_bounded` | 18 | 6.7s |  |
| 28 | `avm2_embed_bytearray` | 2 | 5.7s |  |
| 29 | `avm2_external_interface_unavailable` | 8 | 21.5s |  |
| 30 | `avm2_findprop_this_resolution` | 13 | 5.7s |  |
| 31 | `avm2_gc_dynprop_tombstone_purge` | 8 | 5.6s |  |
| 32 | `avm2_gc_string_concat_reclaim` | 10 | 5.7s |  |
| 33 | `avm2_gc_string_survives_collect` | 9 | 5.7s |  |
| 34 | `avm2_goto_catchup_scale` | 4 | 5.7s |  |
| 35 | `avm2_graphics_runtime` | 7 | 5.5s |  |
| 36 | `avm2_json_roundtrip_bounded` | 13 | 6.4s |  |
| 37 | `avm2_loader_stub` | 5 | 5.6s |  |
| 38 | `avm2_localconnection_domain` | 4 | 5.6s |  |
| 39 | `avm2_morph` | 8 | 21.7s |  |
| 40 | `avm2_parent_child_render` | 11 | 7.7s |  |
| 41 | `avm2_parent_child_static_text` | 12 | 28.5s |  |
| 42 | `avm2_parent_child_symbol_stride` | 6 | 29.7s |  |
| 43 | `avm2_parent_child_symbolclass_domain` | 12 | 7.9s |  |
| 44 | `avm2_reflect_trait_hooks` | 30 | 7.8s |  |
| 45 | `avm2_static_and_store_slots` | 14 | 21.7s |  |
| 46 | `avm2_static_text` | 6 | 21.5s |  |
| 47 | `avm2_strbuf_stale_prefix` | 21 | 5.6s |  |
| 48 | `avm2_timeline_gradients` | 7 | 22.5s |  |
| 49 | `avm2_timeline_solid` | 6 | 22.6s |  |
| 50 | `avm2_timeline_stroke_gradient` | 9 | 6.6s |  |
| 51 | `avm2_timeline_text` | 4 | 22.0s |  |
| 52 | `avm2_tolerant_verify_quarantine` | 2 | 5.7s |  |
| 53 | `avm2_typed_value_ops` | 30 | 28.8s |  |
| 54 | `bitmap_pool_layer_cap` | 1 | 22.2s |  |
| 55 | `broadcast_cross_swf_version` | 4 | 22.4s |  |
| 56 | `broadcast_type1_args` | 14 | 22.6s |  |
| 57 | `coerce_cross_swf_version` | 7 | 22.8s |  |
| 58 | `coerce_recursion_guard` | 1 | 1.4s |  |
| 59 | `coerce_type1_args` | 9 | 17.3s |  |
| 60 | `convertfloat_type1_this` | 3 | 0.8s |  |
| 61 | `ctor_before_first_call_locals` | 5 | 0.9s |  |
| 62 | `ei_closure_scope_order` | 7 | 17.1s |  |
| 63 | `ei_cross_swf_version` | 2 | 0.9s |  |
| 64 | `ei_type1_args` | 7 | 0.9s |  |
| 65 | `enterframe_type1_args` | 8 | 16.8s |  |
| 66 | `fn_call_builtin_type1_args` | 10 | 16.6s |  |
| 67 | `fn_call_type1_args` | 7 | 0.8s |  |
| 68 | `fn_empty_method_type1_args` | 10 | 17.0s |  |
| 69 | `lc_method_type1_args` | 7 | 0.9s |  |
| 70 | `lc_onstatus_type1_args` | 3 | 0.9s |  |
| 71 | `lv_cross_swf_version` | 5 | 16.9s |  |
| 72 | `lv_ondata_type1_args` | 3 | 16.9s |  |
| 73 | `mask_nested_intersect` | 1 | 16.9s |  |
| 74 | `mask_sibling_union` | 1 | 23.0s |  |
| 75 | `mc_event_cross_swf_version` | 4 | 23.3s |  |
| 76 | `mc_event_type1_args` | 3 | 22.7s |  |
| 77 | `mc_method_v5_caller_gate` | 4 | 16.9s |  |
| 78 | `mc_resolve_type1_args` | 6 | 16.6s |  |
| 79 | `method_type1_args` | 10 | 0.8s |  |
| 80 | `nc_onstatus_closure` | 2 | 22.2s |  |
| 81 | `nc_onstatus_type1_args` | 3 | 22.2s |  |
| 82 | `onconstruct_cross_swf_version` | 4 | 22.5s |  |
| 83 | `onconstruct_type1_args` | 6 | 22.6s |  |
| 84 | `onload_type1_args` | 7 | 22.6s |  |
| 85 | `onunload_type1_args` | 6 | 1.4s |  |
| 86 | `onunload_type1_local_frame` | 2 | 16.8s |  |
| 87 | `resolve_type1_args` | 13 | 0.9s |  |
| 88 | `root_enterframe_cross_swf_version` | 3 | 17.0s |  |
| 89 | `sort_comparator_captured_scope` | 2 | 20.9s |  |
| 90 | `sort_comparator_type1_args` | 5 | 20.8s |  |
| 91 | `string_prim_method_type1_args` | 19 | 0.4s |  |
| 92 | `timer_cross_swf_version` | 3 | 16.9s |  |
| 93 | `timer_type1_args` | 14 | 17.1s |  |
| 94 | `watch_cross_swf_version` | 6 | 1.0s |  |
| 95 | `watch_mc_reentrant_setmember` | 3 | 13.0s |  |
| 96 | `watch_mc_type1_args` | 7 | 0.8s |  |
| 97 | `watch_setmember_type1_args` | 7 | 0.8s |  |
| 98 | `watch_timeline_named_params` | 4 | 16.7s |  |
| 99 | `watch_timeline_reentrant` | 3 | 0.8s |  |
| 100 | `xml_onload_type1_args` | 3 | 16.7s |  |

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
