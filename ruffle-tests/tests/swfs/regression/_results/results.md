# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 06:19 UTC

**Git SHA**: `b20dff160b`

**Run Duration**: 17m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 82 |
| Passing | **82** (100.0%) |
| Failing | 0 |
| Total expected lines | 629 |
| Matching lines | 629 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**82 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 20.3s |  |
| 2 | `array_method_type1_args` | 7 | 1.2s |  |
| 3 | `avm1_child_timeline_advance` | 23 | 20.9s |  |
| 4 | `avm1_child_timeline_frame1_stop` | 7 | 20.8s |  |
| 5 | `avm1_child_timeline_holder_stop` | 26 | 1.5s |  |
| 6 | `avm1_child_timeline_loop` | 34 | 1.6s |  |
| 7 | `avm1_parent_as3_child_payload` | 2 | 1.5s |  |
| 8 | `avm1_parent_child_bitmap` | 5 | 1.5s |  |
| 9 | `avm1_parent_child_modify_place` | 5 | 1.4s |  |
| 10 | `avm1_parent_child_sprite_meta` | 8 | 21.3s |  |
| 11 | `avm2_agi_shell` | 6 | 25.6s |  |
| 12 | `avm2_bitmapdata_draw_textfield` | 5 | 7.7s |  |
| 13 | `avm2_contextmenu_stub` | 4 | 23.9s |  |
| 14 | `avm2_embed_bytearray` | 2 | 6.6s |  |
| 15 | `avm2_external_interface_unavailable` | 8 | 6.6s |  |
| 16 | `avm2_findprop_this_resolution` | 13 | 7.1s |  |
| 17 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.3s |  |
| 18 | `avm2_gc_string_concat_reclaim` | 10 | 7.2s |  |
| 19 | `avm2_gc_string_survives_collect` | 9 | 25.4s |  |
| 20 | `avm2_goto_catchup_scale` | 4 | 7.5s |  |
| 21 | `avm2_graphics_runtime` | 7 | 26.5s |  |
| 22 | `avm2_loader_stub` | 5 | 24.5s |  |
| 23 | `avm2_localconnection_domain` | 4 | 6.9s |  |
| 24 | `avm2_morph` | 8 | 25.7s |  |
| 25 | `avm2_parent_child_symbol_stride` | 6 | 44.8s |  |
| 26 | `avm2_reflect_trait_hooks` | 30 | 7.4s |  |
| 27 | `avm2_sharedobject_flushstatus` | 4 | 6.9s |  |
| 28 | `avm2_simplebutton_click` | 2 | 24.9s |  |
| 29 | `avm2_slot_default_template` | 34 | 6.8s |  |
| 30 | `avm2_static_and_store_slots` | 14 | 6.8s |  |
| 31 | `avm2_static_text` | 6 | 44.7s |  |
| 32 | `avm2_timeline_gradients` | 7 | 27.5s |  |
| 33 | `avm2_timeline_solid` | 6 | 8.2s |  |
| 34 | `avm2_timeline_stroke_gradient` | 9 | 48.6s |  |
| 35 | `avm2_timeline_text` | 4 | 7.8s |  |
| 36 | `avm2_tolerant_verify_quarantine` | 2 | 7.5s |  |
| 37 | `avm2_typed_value_ops` | 30 | 25.5s |  |
| 38 | `broadcast_cross_swf_version` | 4 | 1.4s |  |
| 39 | `broadcast_type1_args` | 14 | 20.9s |  |
| 40 | `coerce_cross_swf_version` | 7 | 1.2s |  |
| 41 | `coerce_recursion_guard` | 1 | 17.6s |  |
| 42 | `coerce_type1_args` | 9 | 1.1s |  |
| 43 | `convertfloat_type1_this` | 3 | 20.7s |  |
| 44 | `ei_closure_scope_order` | 7 | 1.2s |  |
| 45 | `ei_cross_swf_version` | 2 | 1.1s |  |
| 46 | `ei_type1_args` | 7 | 20.4s |  |
| 47 | `enterframe_type1_args` | 8 | 1.3s |  |
| 48 | `fn_call_builtin_type1_args` | 10 | 1.2s |  |
| 49 | `fn_call_type1_args` | 7 | 21.0s |  |
| 50 | `fn_empty_method_type1_args` | 10 | 1.3s |  |
| 51 | `lc_method_type1_args` | 7 | 1.3s |  |
| 52 | `lc_onstatus_type1_args` | 3 | 16.0s |  |
| 53 | `lv_cross_swf_version` | 5 | 1.2s |  |
| 54 | `lv_ondata_type1_args` | 3 | 16.1s |  |
| 55 | `mask_nested_intersect` | 1 | 20.3s |  |
| 56 | `mask_sibling_union` | 1 | 1.3s |  |
| 57 | `mc_event_cross_swf_version` | 4 | 1.4s |  |
| 58 | `mc_event_type1_args` | 3 | 19.9s |  |
| 59 | `mc_method_v5_caller_gate` | 4 | 1.4s |  |
| 60 | `mc_resolve_type1_args` | 6 | 1.2s |  |
| 61 | `method_type1_args` | 10 | 20.3s |  |
| 62 | `nc_onstatus_closure` | 2 | 20.4s |  |
| 63 | `nc_onstatus_type1_args` | 3 | 1.2s |  |
| 64 | `onconstruct_cross_swf_version` | 4 | 1.1s |  |
| 65 | `onconstruct_type1_args` | 6 | 16.5s |  |
| 66 | `onload_type1_args` | 7 | 16.2s |  |
| 67 | `onunload_type1_args` | 6 | 21.0s |  |
| 68 | `onunload_type1_local_frame` | 2 | 1.3s |  |
| 69 | `resolve_type1_args` | 13 | 20.7s |  |
| 70 | `root_enterframe_cross_swf_version` | 3 | 20.8s |  |
| 71 | `sort_comparator_captured_scope` | 2 | 21.4s |  |
| 72 | `sort_comparator_type1_args` | 5 | 20.8s |  |
| 73 | `string_prim_method_type1_args` | 19 | 20.4s |  |
| 74 | `timer_cross_swf_version` | 3 | 1.4s |  |
| 75 | `timer_type1_args` | 14 | 0.2s |  |
| 76 | `watch_cross_swf_version` | 6 | 0.2s |  |
| 77 | `watch_mc_reentrant_setmember` | 3 | 20.5s |  |
| 78 | `watch_mc_type1_args` | 7 | 1.3s |  |
| 79 | `watch_setmember_type1_args` | 7 | 20.9s |  |
| 80 | `watch_timeline_named_params` | 4 | 1.2s |  |
| 81 | `watch_timeline_reentrant` | 3 | 19.8s |  |
| 82 | `xml_onload_type1_args` | 3 | 20.0s |  |

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
