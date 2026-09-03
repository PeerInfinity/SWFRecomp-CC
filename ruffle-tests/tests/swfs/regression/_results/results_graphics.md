# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-03 20:58 UTC

**Git SHA**: `92ee912f3f`

**Run Duration**: 17m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 77 |
| Passing | **77** (100.0%) |
| Failing | 0 |
| Total expected lines | 506 |
| Matching lines | 506 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**77 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 21.2s |  |
| 2 | `array_method_type1_args` | 7 | 1.9s |  |
| 3 | `avm1_parent_as3_child_payload` | 2 | 21.4s |  |
| 4 | `avm1_parent_child_bitmap` | 5 | 2.1s |  |
| 5 | `avm1_parent_child_modify_place` | 5 | 2.0s |  |
| 6 | `avm1_parent_child_sprite_meta` | 8 | 2.2s |  |
| 7 | `avm2_agi_shell` | 6 | 7.7s |  |
| 8 | `avm2_bitmapdata_draw_textfield` | 5 | 7.5s |  |
| 9 | `avm2_contextmenu_stub` | 4 | 7.0s |  |
| 10 | `avm2_embed_bytearray` | 2 | 30.4s |  |
| 11 | `avm2_external_interface_unavailable` | 8 | 28.5s |  |
| 12 | `avm2_findprop_this_resolution` | 13 | 8.4s |  |
| 13 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.0s |  |
| 14 | `avm2_gc_string_concat_reclaim` | 10 | 6.8s |  |
| 15 | `avm2_gc_string_survives_collect` | 9 | 6.9s |  |
| 16 | `avm2_goto_catchup_scale` | 4 | 8.5s |  |
| 17 | `avm2_graphics_runtime` | 7 | 28.4s |  |
| 18 | `avm2_loader_stub` | 5 | 8.4s |  |
| 19 | `avm2_localconnection_domain` | 4 | 29.3s |  |
| 20 | `avm2_morph` | 8 | 27.5s |  |
| 21 | `avm2_parent_child_symbol_stride` | 3 | 28.9s |  |
| 22 | `avm2_sharedobject_flushstatus` | 4 | 6.0s |  |
| 23 | `avm2_simplebutton_click` | 2 | 6.0s |  |
| 24 | `avm2_slot_default_template` | 34 | 5.9s |  |
| 25 | `avm2_static_and_store_slots` | 14 | 30.9s |  |
| 26 | `avm2_static_text` | 6 | 29.3s |  |
| 27 | `avm2_timeline_gradients` | 7 | 30.5s |  |
| 28 | `avm2_timeline_solid` | 6 | 29.9s |  |
| 29 | `avm2_timeline_stroke_gradient` | 9 | 10.0s |  |
| 30 | `avm2_timeline_text` | 4 | 9.2s |  |
| 31 | `avm2_tolerant_verify_quarantine` | 2 | 29.0s |  |
| 32 | `avm2_typed_value_ops` | 30 | 8.6s |  |
| 33 | `broadcast_cross_swf_version` | 4 | 21.4s |  |
| 34 | `broadcast_type1_args` | 14 | 21.9s |  |
| 35 | `coerce_cross_swf_version` | 7 | 21.8s |  |
| 36 | `coerce_recursion_guard` | 1 | 1.9s |  |
| 37 | `coerce_type1_args` | 9 | 1.3s |  |
| 38 | `convertfloat_type1_this` | 3 | 0.8s |  |
| 39 | `ei_closure_scope_order` | 7 | 1.5s |  |
| 40 | `ei_cross_swf_version` | 2 | 2.5s |  |
| 41 | `ei_type1_args` | 7 | 2.4s |  |
| 42 | `enterframe_type1_args` | 8 | 23.5s |  |
| 43 | `fn_call_builtin_type1_args` | 10 | 16.6s |  |
| 44 | `fn_call_type1_args` | 7 | 1.6s |  |
| 45 | `fn_empty_method_type1_args` | 10 | 1.6s |  |
| 46 | `lc_method_type1_args` | 7 | 21.7s |  |
| 47 | `lc_onstatus_type1_args` | 3 | 2.1s |  |
| 48 | `lv_cross_swf_version` | 5 | 21.9s |  |
| 49 | `lv_ondata_type1_args` | 3 | 15.6s |  |
| 50 | `mask_nested_intersect` | 1 | 15.5s |  |
| 51 | `mask_sibling_union` | 1 | 1.3s |  |
| 52 | `mc_event_cross_swf_version` | 4 | 18.2s |  |
| 53 | `mc_event_type1_args` | 3 | 1.7s |  |
| 54 | `mc_method_v5_caller_gate` | 4 | 21.0s |  |
| 55 | `mc_resolve_type1_args` | 6 | 20.9s |  |
| 56 | `method_type1_args` | 10 | 2.2s |  |
| 57 | `nc_onstatus_closure` | 2 | 22.2s |  |
| 58 | `nc_onstatus_type1_args` | 3 | 21.2s |  |
| 59 | `onconstruct_cross_swf_version` | 4 | 21.1s |  |
| 60 | `onconstruct_type1_args` | 6 | 22.0s |  |
| 61 | `onload_type1_args` | 7 | 22.1s |  |
| 62 | `onunload_type1_args` | 6 | 21.5s |  |
| 63 | `onunload_type1_local_frame` | 2 | 2.0s |  |
| 64 | `resolve_type1_args` | 13 | 2.2s |  |
| 65 | `root_enterframe_cross_swf_version` | 3 | 23.9s |  |
| 66 | `sort_comparator_captured_scope` | 2 | 21.6s |  |
| 67 | `sort_comparator_type1_args` | 5 | 21.2s |  |
| 68 | `string_prim_method_type1_args` | 19 | 1.3s |  |
| 69 | `timer_cross_swf_version` | 3 | 15.9s |  |
| 70 | `timer_type1_args` | 14 | 22.1s |  |
| 71 | `watch_cross_swf_version` | 6 | 22.1s |  |
| 72 | `watch_mc_reentrant_setmember` | 3 | 2.1s |  |
| 73 | `watch_mc_type1_args` | 7 | 2.2s |  |
| 74 | `watch_setmember_type1_args` | 7 | 15.4s |  |
| 75 | `watch_timeline_named_params` | 4 | 1.2s |  |
| 76 | `watch_timeline_reentrant` | 3 | 1.4s |  |
| 77 | `xml_onload_type1_args` | 3 | 14.1s |  |

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
