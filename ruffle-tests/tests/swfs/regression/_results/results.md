# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-20 08:49 UTC

**Git SHA**: `53a188c38f`

**Run Duration**: 14m 47s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 96 |
| Passing | **96** (100.0%) |
| Failing | 0 |
| Total expected lines | 764 |
| Matching lines | 764 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**96 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 1.2s |  |
| 2 | `array_method_type1_args` | 7 | 1.2s |  |
| 3 | `avm1_child_timeline_advance` | 23 | 21.0s |  |
| 4 | `avm1_child_timeline_frame1_stop` | 7 | 1.5s |  |
| 5 | `avm1_child_timeline_holder_stop` | 26 | 20.3s |  |
| 6 | `avm1_child_timeline_loop` | 34 | 1.4s |  |
| 7 | `avm1_display_prop_coercion` | 36 | 1.3s |  |
| 8 | `avm1_mcl_holder_totalframes` | 5 | 1.3s |  |
| 9 | `avm1_mcl_load_tick` | 14 | 1.6s |  |
| 10 | `avm1_parent_as3_child_payload` | 2 | 1.5s |  |
| 11 | `avm1_parent_child_bitmap` | 5 | 1.6s |  |
| 12 | `avm1_parent_child_bitmap_fill` | 3 | 1.6s |  |
| 13 | `avm1_parent_child_modify_place` | 5 | 17.9s |  |
| 14 | `avm1_parent_child_morph` | 8 | 1.2s |  |
| 15 | `avm1_parent_child_render` | 7 | 1.2s |  |
| 16 | `avm1_parent_child_sprite_meta` | 8 | 1.2s |  |
| 17 | `avm1_parent_child_text` | 8 | 22.5s |  |
| 18 | `avm1_root_identity_and_playhead` | 3 | 22.4s |  |
| 19 | `avm2_agi_shell` | 6 | 7.6s |  |
| 20 | `avm2_bitmapdata_draw_textfield` | 5 | 8.4s |  |
| 21 | `avm2_child_simplebutton` | 10 | 27.5s |  |
| 22 | `avm2_contextmenu_stub` | 4 | 7.4s |  |
| 23 | `avm2_embed_bytearray` | 2 | 7.4s |  |
| 24 | `avm2_external_interface_unavailable` | 8 | 7.5s |  |
| 25 | `avm2_findprop_this_resolution` | 13 | 7.5s |  |
| 26 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.4s |  |
| 27 | `avm2_gc_string_concat_reclaim` | 10 | 7.6s |  |
| 28 | `avm2_gc_string_survives_collect` | 9 | 2.5s |  |
| 29 | `avm2_goto_catchup_scale` | 4 | 7.6s |  |
| 30 | `avm2_graphics_runtime` | 7 | 26.6s |  |
| 31 | `avm2_loader_stub` | 5 | 7.0s |  |
| 32 | `avm2_localconnection_domain` | 4 | 7.0s |  |
| 33 | `avm2_morph` | 8 | 26.1s |  |
| 34 | `avm2_parent_child_render` | 11 | 30.0s |  |
| 35 | `avm2_parent_child_static_text` | 12 | 7.8s |  |
| 36 | `avm2_parent_child_symbol_stride` | 6 | 28.2s |  |
| 37 | `avm2_parent_child_symbolclass_domain` | 12 | 27.2s |  |
| 38 | `avm2_reflect_trait_hooks` | 30 | 7.7s |  |
| 39 | `avm2_sharedobject_flushstatus` | 4 | 7.3s |  |
| 40 | `avm2_simplebutton_click` | 2 | 7.4s |  |
| 41 | `avm2_slot_default_template` | 34 | 7.6s |  |
| 42 | `avm2_static_and_store_slots` | 14 | 2.6s |  |
| 43 | `avm2_static_text` | 6 | 17.2s |  |
| 44 | `avm2_timeline_gradients` | 7 | 17.9s |  |
| 45 | `avm2_timeline_solid` | 6 | 5.5s |  |
| 46 | `avm2_timeline_stroke_gradient` | 9 | 28.3s |  |
| 47 | `avm2_timeline_text` | 4 | 7.8s |  |
| 48 | `avm2_tolerant_verify_quarantine` | 2 | 7.3s |  |
| 49 | `avm2_typed_value_ops` | 30 | 6.9s |  |
| 50 | `bitmap_pool_layer_cap` | 1 | 17.4s |  |
| 51 | `broadcast_cross_swf_version` | 4 | 17.0s |  |
| 52 | `broadcast_type1_args` | 14 | 1.1s |  |
| 53 | `coerce_cross_swf_version` | 7 | 20.3s |  |
| 54 | `coerce_recursion_guard` | 1 | 1.1s |  |
| 55 | `coerce_type1_args` | 9 | 0.8s |  |
| 56 | `convertfloat_type1_this` | 3 | 0.8s |  |
| 57 | `ctor_before_first_call_locals` | 5 | 0.8s |  |
| 58 | `ei_closure_scope_order` | 7 | 1.4s |  |
| 59 | `ei_cross_swf_version` | 2 | 1.3s |  |
| 60 | `ei_type1_args` | 7 | 1.3s |  |
| 61 | `enterframe_type1_args` | 8 | 20.6s |  |
| 62 | `fn_call_builtin_type1_args` | 10 | 1.2s |  |
| 63 | `fn_call_type1_args` | 7 | 1.2s |  |
| 64 | `fn_empty_method_type1_args` | 10 | 1.0s |  |
| 65 | `lc_method_type1_args` | 7 | 1.0s |  |
| 66 | `lc_onstatus_type1_args` | 3 | 1.0s |  |
| 67 | `lv_cross_swf_version` | 5 | 20.7s |  |
| 68 | `lv_ondata_type1_args` | 3 | 20.8s |  |
| 69 | `mask_nested_intersect` | 1 | 20.5s |  |
| 70 | `mask_sibling_union` | 1 | 20.6s |  |
| 71 | `mc_event_cross_swf_version` | 4 | 20.8s |  |
| 72 | `mc_event_type1_args` | 3 | 1.2s |  |
| 73 | `mc_method_v5_caller_gate` | 4 | 20.2s |  |
| 74 | `mc_resolve_type1_args` | 6 | 1.1s |  |
| 75 | `method_type1_args` | 10 | 1.1s |  |
| 76 | `nc_onstatus_closure` | 2 | 20.8s |  |
| 77 | `nc_onstatus_type1_args` | 3 | 1.2s |  |
| 78 | `onconstruct_cross_swf_version` | 4 | 20.9s |  |
| 79 | `onconstruct_type1_args` | 6 | 1.4s |  |
| 80 | `onload_type1_args` | 7 | 22.6s |  |
| 81 | `onunload_type1_args` | 6 | 1.3s |  |
| 82 | `onunload_type1_local_frame` | 2 | 1.3s |  |
| 83 | `resolve_type1_args` | 13 | 1.3s |  |
| 84 | `root_enterframe_cross_swf_version` | 3 | 21.1s |  |
| 85 | `sort_comparator_captured_scope` | 2 | 0.1s |  |
| 86 | `sort_comparator_type1_args` | 5 | 0.1s |  |
| 87 | `string_prim_method_type1_args` | 19 | 0.1s |  |
| 88 | `timer_cross_swf_version` | 3 | 20.8s |  |
| 89 | `timer_type1_args` | 14 | 20.8s |  |
| 90 | `watch_cross_swf_version` | 6 | 1.4s |  |
| 91 | `watch_mc_reentrant_setmember` | 3 | 1.4s |  |
| 92 | `watch_mc_type1_args` | 7 | 1.4s |  |
| 93 | `watch_setmember_type1_args` | 7 | 1.4s |  |
| 94 | `watch_timeline_named_params` | 4 | 1.2s |  |
| 95 | `watch_timeline_reentrant` | 3 | 1.2s |  |
| 96 | `xml_onload_type1_args` | 3 | 20.2s |  |

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
