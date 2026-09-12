# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-12 01:30 UTC

**Git SHA**: `521a537828`

**Run Duration**: 26m 22s

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
| 1 | `array_element_type1_args` | 7 | 21.8s |  |
| 2 | `array_method_type1_args` | 7 | 2.0s |  |
| 3 | `avm1_child_timeline_advance` | 23 | 22.2s |  |
| 4 | `avm1_child_timeline_frame1_stop` | 7 | 2.4s |  |
| 5 | `avm1_child_timeline_holder_stop` | 26 | 17.4s |  |
| 6 | `avm1_child_timeline_loop` | 34 | 2.0s |  |
| 7 | `avm1_mcl_holder_totalframes` | 5 | 1.9s |  |
| 8 | `avm1_mcl_load_tick` | 14 | 17.4s |  |
| 9 | `avm1_parent_as3_child_payload` | 2 | 2.2s |  |
| 10 | `avm1_parent_child_bitmap` | 5 | 2.3s |  |
| 11 | `avm1_parent_child_bitmap_fill` | 3 | 2.4s |  |
| 12 | `avm1_parent_child_modify_place` | 5 | 2.3s |  |
| 13 | `avm1_parent_child_morph` | 8 | 23.9s |  |
| 14 | `avm1_parent_child_render` | 7 | 2.8s |  |
| 15 | `avm1_parent_child_sprite_meta` | 8 | 2.7s |  |
| 16 | `avm1_parent_child_text` | 8 | 2.7s |  |
| 17 | `avm1_root_identity_and_playhead` | 3 | 21.4s |  |
| 18 | `avm2_agi_shell` | 6 | 46.1s |  |
| 19 | `avm2_bitmapdata_draw_textfield` | 5 | 9.0s |  |
| 20 | `avm2_child_simplebutton` | 10 | 28.2s |  |
| 21 | `avm2_contextmenu_stub` | 4 | 27.5s |  |
| 22 | `avm2_embed_bytearray` | 2 | 27.2s |  |
| 23 | `avm2_external_interface_unavailable` | 8 | 8.4s |  |
| 24 | `avm2_findprop_this_resolution` | 13 | 36.8s |  |
| 25 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.0s |  |
| 26 | `avm2_gc_string_concat_reclaim` | 10 | 6.9s |  |
| 27 | `avm2_gc_string_survives_collect` | 9 | 46.9s |  |
| 28 | `avm2_goto_catchup_scale` | 4 | 8.8s |  |
| 29 | `avm2_graphics_runtime` | 7 | 28.5s |  |
| 30 | `avm2_loader_stub` | 5 | 36.9s |  |
| 31 | `avm2_localconnection_domain` | 4 | 6.8s |  |
| 32 | `avm2_morph` | 8 | 22.3s |  |
| 33 | `avm2_parent_child_render` | 11 | 49.4s |  |
| 34 | `avm2_parent_child_static_text` | 12 | 9.1s |  |
| 35 | `avm2_parent_child_symbol_stride` | 6 | 29.5s |  |
| 36 | `avm2_parent_child_symbolclass_domain` | 12 | 43.6s |  |
| 37 | `avm2_reflect_trait_hooks` | 30 | 26.2s |  |
| 38 | `avm2_sharedobject_flushstatus` | 4 | 7.7s |  |
| 39 | `avm2_simplebutton_click` | 2 | 46.5s |  |
| 40 | `avm2_slot_default_template` | 34 | 8.9s |  |
| 41 | `avm2_static_and_store_slots` | 14 | 8.8s |  |
| 42 | `avm2_static_text` | 6 | 47.5s |  |
| 43 | `avm2_timeline_gradients` | 7 | 30.4s |  |
| 44 | `avm2_timeline_solid` | 6 | 9.9s |  |
| 45 | `avm2_timeline_stroke_gradient` | 9 | 33.3s |  |
| 46 | `avm2_timeline_text` | 4 | 19.7s |  |
| 47 | `avm2_tolerant_verify_quarantine` | 2 | 5.7s |  |
| 48 | `avm2_typed_value_ops` | 30 | 46.0s |  |
| 49 | `bitmap_pool_layer_cap` | 1 | 22.8s |  |
| 50 | `broadcast_cross_swf_version` | 4 | 21.1s |  |
| 51 | `broadcast_type1_args` | 14 | 21.4s |  |
| 52 | `coerce_cross_swf_version` | 7 | 21.6s |  |
| 53 | `coerce_recursion_guard` | 1 | 2.0s |  |
| 54 | `coerce_type1_args` | 9 | 18.6s |  |
| 55 | `convertfloat_type1_this` | 3 | 1.6s |  |
| 56 | `ctor_before_first_call_locals` | 5 | 1.5s |  |
| 57 | `ei_closure_scope_order` | 7 | 13.9s |  |
| 58 | `ei_cross_swf_version` | 2 | 1.4s |  |
| 59 | `ei_type1_args` | 7 | 1.5s |  |
| 60 | `enterframe_type1_args` | 8 | 21.0s |  |
| 61 | `fn_call_builtin_type1_args` | 10 | 20.9s |  |
| 62 | `fn_call_type1_args` | 7 | 1.9s |  |
| 63 | `fn_empty_method_type1_args` | 10 | 21.6s |  |
| 64 | `lc_method_type1_args` | 7 | 2.1s |  |
| 65 | `lc_onstatus_type1_args` | 3 | 2.0s |  |
| 66 | `lv_cross_swf_version` | 5 | 22.1s |  |
| 67 | `lv_ondata_type1_args` | 3 | 21.8s |  |
| 68 | `mask_nested_intersect` | 1 | 22.1s |  |
| 69 | `mask_sibling_union` | 1 | 15.4s |  |
| 70 | `mc_event_cross_swf_version` | 4 | 15.5s |  |
| 71 | `mc_event_type1_args` | 3 | 15.4s |  |
| 72 | `mc_method_v5_caller_gate` | 4 | 22.6s |  |
| 73 | `mc_resolve_type1_args` | 6 | 21.9s |  |
| 74 | `method_type1_args` | 10 | 2.1s |  |
| 75 | `nc_onstatus_closure` | 2 | 20.9s |  |
| 76 | `nc_onstatus_type1_args` | 3 | 20.9s |  |
| 77 | `onconstruct_cross_swf_version` | 4 | 21.2s |  |
| 78 | `onconstruct_type1_args` | 6 | 21.4s |  |
| 79 | `onload_type1_args` | 7 | 21.4s |  |
| 80 | `onunload_type1_args` | 6 | 1.6s |  |
| 81 | `onunload_type1_local_frame` | 2 | 21.5s |  |
| 82 | `resolve_type1_args` | 13 | 1.8s |  |
| 83 | `root_enterframe_cross_swf_version` | 3 | 25.4s |  |
| 84 | `sort_comparator_captured_scope` | 2 | 17.8s |  |
| 85 | `sort_comparator_type1_args` | 5 | 17.8s |  |
| 86 | `string_prim_method_type1_args` | 19 | 1.7s |  |
| 87 | `timer_cross_swf_version` | 3 | 19.7s |  |
| 88 | `timer_type1_args` | 14 | 19.6s |  |
| 89 | `watch_cross_swf_version` | 6 | 0.9s |  |
| 90 | `watch_mc_reentrant_setmember` | 3 | 20.6s |  |
| 91 | `watch_mc_type1_args` | 7 | 1.8s |  |
| 92 | `watch_setmember_type1_args` | 7 | 1.9s |  |
| 93 | `watch_timeline_named_params` | 4 | 20.7s |  |
| 94 | `watch_timeline_reentrant` | 3 | 1.7s |  |
| 95 | `xml_onload_type1_args` | 3 | 20.7s |  |

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
