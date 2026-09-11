# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-11 21:09 UTC

**Git SHA**: `0ccafbc4eb`

**Run Duration**: 16m 52s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 92 |
| Passing | **92** (100.0%) |
| Failing | 0 |
| Total expected lines | 699 |
| Matching lines | 699 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**92 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 17.9s |  |
| 2 | `array_method_type1_args` | 7 | 1.5s |  |
| 3 | `avm1_child_timeline_advance` | 23 | 18.3s |  |
| 4 | `avm1_child_timeline_frame1_stop` | 7 | 1.7s |  |
| 5 | `avm1_child_timeline_holder_stop` | 26 | 18.4s |  |
| 6 | `avm1_child_timeline_loop` | 34 | 1.8s |  |
| 7 | `avm1_mcl_holder_totalframes` | 5 | 1.7s |  |
| 8 | `avm1_parent_as3_child_payload` | 2 | 18.1s |  |
| 9 | `avm1_parent_child_bitmap` | 5 | 2.5s |  |
| 10 | `avm1_parent_child_bitmap_fill` | 3 | 2.5s |  |
| 11 | `avm1_parent_child_modify_place` | 5 | 2.4s |  |
| 12 | `avm1_parent_child_morph` | 8 | 16.3s |  |
| 13 | `avm1_parent_child_render` | 7 | 1.8s |  |
| 14 | `avm1_parent_child_sprite_meta` | 8 | 1.6s |  |
| 15 | `avm1_parent_child_text` | 8 | 21.0s |  |
| 16 | `avm1_root_identity_and_playhead` | 3 | 18.6s |  |
| 17 | `avm2_agi_shell` | 6 | 3.0s |  |
| 18 | `avm2_bitmapdata_draw_textfield` | 5 | 7.1s |  |
| 19 | `avm2_contextmenu_stub` | 4 | 6.7s |  |
| 20 | `avm2_embed_bytearray` | 2 | 7.0s |  |
| 21 | `avm2_external_interface_unavailable` | 8 | 6.2s |  |
| 22 | `avm2_findprop_this_resolution` | 13 | 2.5s |  |
| 23 | `avm2_gc_dynprop_tombstone_purge` | 8 | 6.2s |  |
| 24 | `avm2_gc_string_concat_reclaim` | 10 | 8.7s |  |
| 25 | `avm2_gc_string_survives_collect` | 9 | 8.7s |  |
| 26 | `avm2_goto_catchup_scale` | 4 | 8.6s |  |
| 27 | `avm2_graphics_runtime` | 7 | 28.0s |  |
| 28 | `avm2_loader_stub` | 5 | 8.5s |  |
| 29 | `avm2_localconnection_domain` | 4 | 8.4s |  |
| 30 | `avm2_morph` | 8 | 31.2s |  |
| 31 | `avm2_parent_child_render` | 11 | 10.7s |  |
| 32 | `avm2_parent_child_static_text` | 12 | 8.6s |  |
| 33 | `avm2_parent_child_symbol_stride` | 6 | 28.9s |  |
| 34 | `avm2_parent_child_symbolclass_domain` | 12 | 8.7s |  |
| 35 | `avm2_reflect_trait_hooks` | 30 | 8.7s |  |
| 36 | `avm2_sharedobject_flushstatus` | 4 | 8.6s |  |
| 37 | `avm2_simplebutton_click` | 2 | 8.6s |  |
| 38 | `avm2_slot_default_template` | 34 | 8.7s |  |
| 39 | `avm2_static_and_store_slots` | 14 | 9.2s |  |
| 40 | `avm2_static_text` | 6 | 28.5s |  |
| 41 | `avm2_timeline_gradients` | 7 | 32.3s |  |
| 42 | `avm2_timeline_solid` | 6 | 30.8s |  |
| 43 | `avm2_timeline_stroke_gradient` | 9 | 9.6s |  |
| 44 | `avm2_timeline_text` | 4 | 8.9s |  |
| 45 | `avm2_tolerant_verify_quarantine` | 2 | 7.0s |  |
| 46 | `avm2_typed_value_ops` | 30 | 7.0s |  |
| 47 | `bitmap_pool_layer_cap` | 1 | 20.5s |  |
| 48 | `broadcast_cross_swf_version` | 4 | 1.8s |  |
| 49 | `broadcast_type1_args` | 14 | 20.1s |  |
| 50 | `coerce_cross_swf_version` | 7 | 1.8s |  |
| 51 | `coerce_recursion_guard` | 1 | 22.4s |  |
| 52 | `coerce_type1_args` | 9 | 2.0s |  |
| 53 | `convertfloat_type1_this` | 3 | 2.0s |  |
| 54 | `ei_closure_scope_order` | 7 | 18.5s |  |
| 55 | `ei_cross_swf_version` | 2 | 1.8s |  |
| 56 | `ei_type1_args` | 7 | 1.8s |  |
| 57 | `enterframe_type1_args` | 8 | 2.2s |  |
| 58 | `fn_call_builtin_type1_args` | 10 | 21.5s |  |
| 59 | `fn_call_type1_args` | 7 | 2.1s |  |
| 60 | `fn_empty_method_type1_args` | 10 | 19.0s |  |
| 61 | `lc_method_type1_args` | 7 | 1.8s |  |
| 62 | `lc_onstatus_type1_args` | 3 | 1.5s |  |
| 63 | `lv_cross_swf_version` | 5 | 2.4s |  |
| 64 | `lv_ondata_type1_args` | 3 | 22.3s |  |
| 65 | `mask_nested_intersect` | 1 | 24.9s |  |
| 66 | `mask_sibling_union` | 1 | 23.2s |  |
| 67 | `mc_event_cross_swf_version` | 4 | 2.1s |  |
| 68 | `mc_event_type1_args` | 3 | 21.1s |  |
| 69 | `mc_method_v5_caller_gate` | 4 | 2.2s |  |
| 70 | `mc_resolve_type1_args` | 6 | 21.7s |  |
| 71 | `method_type1_args` | 10 | 2.0s |  |
| 72 | `nc_onstatus_closure` | 2 | 21.3s |  |
| 73 | `nc_onstatus_type1_args` | 3 | 21.1s |  |
| 74 | `onconstruct_cross_swf_version` | 4 | 2.1s |  |
| 75 | `onconstruct_type1_args` | 6 | 20.0s |  |
| 76 | `onload_type1_args` | 7 | 19.8s |  |
| 77 | `onunload_type1_args` | 6 | 1.2s |  |
| 78 | `onunload_type1_local_frame` | 2 | 21.0s |  |
| 79 | `resolve_type1_args` | 13 | 2.0s |  |
| 80 | `root_enterframe_cross_swf_version` | 3 | 21.0s |  |
| 81 | `sort_comparator_captured_scope` | 2 | 18.1s |  |
| 82 | `sort_comparator_type1_args` | 5 | 17.6s |  |
| 83 | `string_prim_method_type1_args` | 19 | 1.8s |  |
| 84 | `timer_cross_swf_version` | 3 | 1.9s |  |
| 85 | `timer_type1_args` | 14 | 2.5s |  |
| 86 | `watch_cross_swf_version` | 6 | 0.6s |  |
| 87 | `watch_mc_reentrant_setmember` | 3 | 20.8s |  |
| 88 | `watch_mc_type1_args` | 7 | 1.8s |  |
| 89 | `watch_setmember_type1_args` | 7 | 2.0s |  |
| 90 | `watch_timeline_named_params` | 4 | 17.0s |  |
| 91 | `watch_timeline_reentrant` | 3 | 1.7s |  |
| 92 | `xml_onload_type1_args` | 3 | 17.0s |  |

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
