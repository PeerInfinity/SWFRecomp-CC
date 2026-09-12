# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-12 02:42 UTC

**Git SHA**: `d8da5a18c3`

**Run Duration**: 23m 17s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 95 |
| Passing | **95** (100.0%) |
| Failing | 0 |
| Total expected lines | 728 |
| Matching lines | 728 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**95 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 21.5s |  |
| 2 | `array_method_type1_args` | 7 | 2.0s |  |
| 3 | `avm1_child_timeline_advance` | 23 | 22.0s |  |
| 4 | `avm1_child_timeline_frame1_stop` | 7 | 2.4s |  |
| 5 | `avm1_child_timeline_holder_stop` | 26 | 22.8s |  |
| 6 | `avm1_child_timeline_loop` | 34 | 2.2s |  |
| 7 | `avm1_mcl_holder_totalframes` | 5 | 2.2s |  |
| 8 | `avm1_mcl_load_tick` | 14 | 22.6s |  |
| 9 | `avm1_parent_as3_child_payload` | 2 | 1.7s |  |
| 10 | `avm1_parent_child_bitmap` | 5 | 1.7s |  |
| 11 | `avm1_parent_child_bitmap_fill` | 3 | 1.7s |  |
| 12 | `avm1_parent_child_modify_place` | 5 | 1.6s |  |
| 13 | `avm1_parent_child_morph` | 8 | 22.3s |  |
| 14 | `avm1_parent_child_render` | 7 | 2.5s |  |
| 15 | `avm1_parent_child_sprite_meta` | 8 | 2.5s |  |
| 16 | `avm1_parent_child_text` | 8 | 2.5s |  |
| 17 | `avm1_root_identity_and_playhead` | 3 | 21.7s |  |
| 18 | `avm2_agi_shell` | 6 | 28.1s |  |
| 19 | `avm2_bitmapdata_draw_textfield` | 5 | 9.0s |  |
| 20 | `avm2_child_simplebutton` | 10 | 28.4s |  |
| 21 | `avm2_contextmenu_stub` | 4 | 28.3s |  |
| 22 | `avm2_embed_bytearray` | 2 | 28.3s |  |
| 23 | `avm2_external_interface_unavailable` | 8 | 8.8s |  |
| 24 | `avm2_findprop_this_resolution` | 13 | 24.7s |  |
| 25 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.3s |  |
| 26 | `avm2_gc_string_concat_reclaim` | 10 | 7.2s |  |
| 27 | `avm2_gc_string_survives_collect` | 9 | 23.6s |  |
| 28 | `avm2_goto_catchup_scale` | 4 | 8.9s |  |
| 29 | `avm2_graphics_runtime` | 7 | 29.3s |  |
| 30 | `avm2_loader_stub` | 5 | 29.2s |  |
| 31 | `avm2_localconnection_domain` | 4 | 8.8s |  |
| 32 | `avm2_morph` | 8 | 29.0s |  |
| 33 | `avm2_parent_child_render` | 11 | 31.3s |  |
| 34 | `avm2_parent_child_static_text` | 12 | 9.0s |  |
| 35 | `avm2_parent_child_symbol_stride` | 6 | 29.8s |  |
| 36 | `avm2_parent_child_symbolclass_domain` | 12 | 20.5s |  |
| 37 | `avm2_reflect_trait_hooks` | 30 | 20.4s |  |
| 38 | `avm2_sharedobject_flushstatus` | 4 | 5.9s |  |
| 39 | `avm2_simplebutton_click` | 2 | 22.4s |  |
| 40 | `avm2_slot_default_template` | 34 | 7.2s |  |
| 41 | `avm2_static_and_store_slots` | 14 | 2.8s |  |
| 42 | `avm2_static_text` | 6 | 26.9s |  |
| 43 | `avm2_timeline_gradients` | 7 | 27.8s |  |
| 44 | `avm2_timeline_solid` | 6 | 9.0s |  |
| 45 | `avm2_timeline_stroke_gradient` | 9 | 28.6s |  |
| 46 | `avm2_timeline_text` | 4 | 28.6s |  |
| 47 | `avm2_tolerant_verify_quarantine` | 2 | 8.8s |  |
| 48 | `avm2_typed_value_ops` | 30 | 29.7s |  |
| 49 | `bitmap_pool_layer_cap` | 1 | 23.7s |  |
| 50 | `broadcast_cross_swf_version` | 4 | 21.9s |  |
| 51 | `broadcast_type1_args` | 14 | 12.8s |  |
| 52 | `coerce_cross_swf_version` | 7 | 12.9s |  |
| 53 | `coerce_recursion_guard` | 1 | 1.3s |  |
| 54 | `coerce_type1_args` | 9 | 15.2s |  |
| 55 | `convertfloat_type1_this` | 3 | 1.5s |  |
| 56 | `ctor_before_first_call_locals` | 5 | 1.6s |  |
| 57 | `ei_closure_scope_order` | 7 | 21.0s |  |
| 58 | `ei_cross_swf_version` | 2 | 2.0s |  |
| 59 | `ei_type1_args` | 7 | 2.0s |  |
| 60 | `enterframe_type1_args` | 8 | 17.7s |  |
| 61 | `fn_call_builtin_type1_args` | 10 | 17.2s |  |
| 62 | `fn_call_type1_args` | 7 | 1.8s |  |
| 63 | `fn_empty_method_type1_args` | 10 | 21.8s |  |
| 64 | `lc_method_type1_args` | 7 | 2.1s |  |
| 65 | `lc_onstatus_type1_args` | 3 | 2.1s |  |
| 66 | `lv_cross_swf_version` | 5 | 21.6s |  |
| 67 | `lv_ondata_type1_args` | 3 | 21.1s |  |
| 68 | `mask_nested_intersect` | 1 | 21.6s |  |
| 69 | `mask_sibling_union` | 1 | 21.8s |  |
| 70 | `mc_event_cross_swf_version` | 4 | 21.7s |  |
| 71 | `mc_event_type1_args` | 3 | 21.5s |  |
| 72 | `mc_method_v5_caller_gate` | 4 | 21.4s |  |
| 73 | `mc_resolve_type1_args` | 6 | 21.1s |  |
| 74 | `method_type1_args` | 10 | 2.0s |  |
| 75 | `nc_onstatus_closure` | 2 | 21.4s |  |
| 76 | `nc_onstatus_type1_args` | 3 | 21.4s |  |
| 77 | `onconstruct_cross_swf_version` | 4 | 21.9s |  |
| 78 | `onconstruct_type1_args` | 6 | 15.6s |  |
| 79 | `onload_type1_args` | 7 | 15.8s |  |
| 80 | `onunload_type1_args` | 6 | 1.1s |  |
| 81 | `onunload_type1_local_frame` | 2 | 21.2s |  |
| 82 | `resolve_type1_args` | 13 | 2.0s |  |
| 83 | `root_enterframe_cross_swf_version` | 3 | 21.6s |  |
| 84 | `sort_comparator_captured_scope` | 2 | 20.1s |  |
| 85 | `sort_comparator_type1_args` | 5 | 20.0s |  |
| 86 | `string_prim_method_type1_args` | 19 | 0.9s |  |
| 87 | `timer_cross_swf_version` | 3 | 16.2s |  |
| 88 | `timer_type1_args` | 14 | 16.3s |  |
| 89 | `watch_cross_swf_version` | 6 | 0.9s |  |
| 90 | `watch_mc_reentrant_setmember` | 3 | 21.4s |  |
| 91 | `watch_mc_type1_args` | 7 | 1.9s |  |
| 92 | `watch_setmember_type1_args` | 7 | 2.0s |  |
| 93 | `watch_timeline_named_params` | 4 | 16.5s |  |
| 94 | `watch_timeline_reentrant` | 3 | 1.6s |  |
| 95 | `xml_onload_type1_args` | 3 | 16.5s |  |

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
