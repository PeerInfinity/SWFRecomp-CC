# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-03 19:03 UTC

**Git SHA**: `50fcc7f8bd`

**Run Duration**: 11m 51s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 77 |
| Passing | **77** (100.0%) |
| Failing | 0 |
| Total expected lines | 504 |
| Matching lines | 504 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**77 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 2.1s |  |
| 2 | `array_method_type1_args` | 7 | 2.1s |  |
| 3 | `avm1_parent_as3_child_payload` | 2 | 2.5s |  |
| 4 | `avm1_parent_child_bitmap` | 5 | 2.4s |  |
| 5 | `avm1_parent_child_modify_place` | 3 | 21.1s |  |
| 6 | `avm1_parent_child_sprite_meta` | 8 | 2.4s |  |
| 7 | `avm2_agi_shell` | 6 | 7.1s |  |
| 8 | `avm2_bitmapdata_draw_textfield` | 5 | 7.6s |  |
| 9 | `avm2_contextmenu_stub` | 4 | 7.2s |  |
| 10 | `avm2_embed_bytearray` | 2 | 8.3s |  |
| 11 | `avm2_external_interface_unavailable` | 8 | 8.2s |  |
| 12 | `avm2_findprop_this_resolution` | 13 | 7.9s |  |
| 13 | `avm2_gc_dynprop_tombstone_purge` | 8 | 4.0s |  |
| 14 | `avm2_gc_string_concat_reclaim` | 10 | 8.8s |  |
| 15 | `avm2_gc_string_survives_collect` | 9 | 8.6s |  |
| 16 | `avm2_goto_catchup_scale` | 4 | 6.8s |  |
| 17 | `avm2_graphics_runtime` | 7 | 22.2s |  |
| 18 | `avm2_loader_stub` | 5 | 6.6s |  |
| 19 | `avm2_localconnection_domain` | 4 | 8.2s |  |
| 20 | `avm2_morph` | 8 | 27.0s |  |
| 21 | `avm2_parent_child_symbol_stride` | 3 | 28.4s |  |
| 22 | `avm2_sharedobject_flushstatus` | 4 | 8.6s |  |
| 23 | `avm2_simplebutton_click` | 2 | 3.4s |  |
| 24 | `avm2_slot_default_template` | 34 | 8.6s |  |
| 25 | `avm2_static_and_store_slots` | 14 | 6.8s |  |
| 26 | `avm2_static_text` | 6 | 21.7s |  |
| 27 | `avm2_timeline_gradients` | 7 | 22.7s |  |
| 28 | `avm2_timeline_solid` | 6 | 28.5s |  |
| 29 | `avm2_timeline_stroke_gradient` | 9 | 9.6s |  |
| 30 | `avm2_timeline_text` | 4 | 8.8s |  |
| 31 | `avm2_tolerant_verify_quarantine` | 2 | 6.7s |  |
| 32 | `avm2_typed_value_ops` | 30 | 6.8s |  |
| 33 | `broadcast_cross_swf_version` | 4 | 18.1s |  |
| 34 | `broadcast_type1_args` | 14 | 1.5s |  |
| 35 | `coerce_cross_swf_version` | 7 | 17.4s |  |
| 36 | `coerce_recursion_guard` | 1 | 1.3s |  |
| 37 | `coerce_type1_args` | 9 | 1.7s |  |
| 38 | `convertfloat_type1_this` | 3 | 1.2s |  |
| 39 | `ei_closure_scope_order` | 7 | 2.2s |  |
| 40 | `ei_cross_swf_version` | 2 | 2.0s |  |
| 41 | `ei_type1_args` | 7 | 2.0s |  |
| 42 | `enterframe_type1_args` | 8 | 21.1s |  |
| 43 | `fn_call_builtin_type1_args` | 10 | 1.8s |  |
| 44 | `fn_call_type1_args` | 7 | 1.8s |  |
| 45 | `fn_empty_method_type1_args` | 10 | 1.8s |  |
| 46 | `lc_method_type1_args` | 7 | 1.8s |  |
| 47 | `lc_onstatus_type1_args` | 3 | 1.8s |  |
| 48 | `lv_cross_swf_version` | 5 | 21.6s |  |
| 49 | `lv_ondata_type1_args` | 3 | 21.8s |  |
| 50 | `mask_nested_intersect` | 1 | 22.2s |  |
| 51 | `mask_sibling_union` | 1 | 2.2s |  |
| 52 | `mc_event_cross_swf_version` | 4 | 21.0s |  |
| 53 | `mc_event_type1_args` | 3 | 2.0s |  |
| 54 | `mc_method_v5_caller_gate` | 4 | 22.1s |  |
| 55 | `mc_resolve_type1_args` | 6 | 2.1s |  |
| 56 | `method_type1_args` | 10 | 2.1s |  |
| 57 | `nc_onstatus_closure` | 2 | 21.4s |  |
| 58 | `nc_onstatus_type1_args` | 3 | 2.2s |  |
| 59 | `onconstruct_cross_swf_version` | 4 | 22.6s |  |
| 60 | `onconstruct_type1_args` | 6 | 2.2s |  |
| 61 | `onload_type1_args` | 7 | 22.6s |  |
| 62 | `onunload_type1_args` | 6 | 1.9s |  |
| 63 | `onunload_type1_local_frame` | 2 | 1.9s |  |
| 64 | `resolve_type1_args` | 13 | 1.6s |  |
| 65 | `root_enterframe_cross_swf_version` | 3 | 14.1s |  |
| 66 | `sort_comparator_captured_scope` | 2 | 1.7s |  |
| 67 | `sort_comparator_type1_args` | 5 | 1.6s |  |
| 68 | `string_prim_method_type1_args` | 19 | 1.3s |  |
| 69 | `timer_cross_swf_version` | 3 | 16.0s |  |
| 70 | `timer_type1_args` | 14 | 20.6s |  |
| 71 | `watch_cross_swf_version` | 6 | 20.6s |  |
| 72 | `watch_mc_reentrant_setmember` | 3 | 1.9s |  |
| 73 | `watch_mc_type1_args` | 7 | 1.9s |  |
| 74 | `watch_setmember_type1_args` | 7 | 0.8s |  |
| 75 | `watch_timeline_named_params` | 4 | 0.7s |  |
| 76 | `watch_timeline_reentrant` | 3 | 2.0s |  |
| 77 | `xml_onload_type1_args` | 3 | 20.8s |  |

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
