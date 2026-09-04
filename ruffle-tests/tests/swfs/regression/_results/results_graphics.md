# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 04:04 UTC

**Git SHA**: `82f27e5f90`

**Run Duration**: 21m 21s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 81 |
| Passing | **81** (100.0%) |
| Failing | 0 |
| Total expected lines | 599 |
| Matching lines | 599 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**81 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 15.4s |  |
| 2 | `array_method_type1_args` | 7 | 1.4s |  |
| 3 | `avm1_child_timeline_advance` | 23 | 15.4s |  |
| 4 | `avm1_child_timeline_frame1_stop` | 7 | 21.4s |  |
| 5 | `avm1_child_timeline_holder_stop` | 26 | 2.3s |  |
| 6 | `avm1_child_timeline_loop` | 34 | 2.4s |  |
| 7 | `avm1_parent_as3_child_payload` | 2 | 2.4s |  |
| 8 | `avm1_parent_child_bitmap` | 5 | 2.3s |  |
| 9 | `avm1_parent_child_modify_place` | 5 | 2.3s |  |
| 10 | `avm1_parent_child_sprite_meta` | 8 | 22.0s |  |
| 11 | `avm2_agi_shell` | 6 | 29.2s |  |
| 12 | `avm2_bitmapdata_draw_textfield` | 5 | 8.9s |  |
| 13 | `avm2_contextmenu_stub` | 4 | 29.5s |  |
| 14 | `avm2_embed_bytearray` | 2 | 28.1s |  |
| 15 | `avm2_external_interface_unavailable` | 8 | 8.5s |  |
| 16 | `avm2_findprop_this_resolution` | 13 | 29.2s |  |
| 17 | `avm2_gc_dynprop_tombstone_purge` | 8 | 8.7s |  |
| 18 | `avm2_gc_string_concat_reclaim` | 10 | 8.6s |  |
| 19 | `avm2_gc_string_survives_collect` | 9 | 30.4s |  |
| 20 | `avm2_goto_catchup_scale` | 4 | 8.7s |  |
| 21 | `avm2_graphics_runtime` | 7 | 28.7s |  |
| 22 | `avm2_loader_stub` | 5 | 30.4s |  |
| 23 | `avm2_localconnection_domain` | 4 | 8.5s |  |
| 24 | `avm2_morph` | 8 | 31.1s |  |
| 25 | `avm2_parent_child_symbol_stride` | 6 | 30.9s |  |
| 26 | `avm2_sharedobject_flushstatus` | 4 | 27.9s |  |
| 27 | `avm2_simplebutton_click` | 2 | 8.6s |  |
| 28 | `avm2_slot_default_template` | 34 | 28.7s |  |
| 29 | `avm2_static_and_store_slots` | 14 | 8.3s |  |
| 30 | `avm2_static_text` | 6 | 27.2s |  |
| 31 | `avm2_timeline_gradients` | 7 | 30.1s |  |
| 32 | `avm2_timeline_solid` | 6 | 9.3s |  |
| 33 | `avm2_timeline_stroke_gradient` | 9 | 9.5s |  |
| 34 | `avm2_timeline_text` | 4 | 23.3s |  |
| 35 | `avm2_tolerant_verify_quarantine` | 2 | 6.7s |  |
| 36 | `avm2_typed_value_ops` | 30 | 6.8s |  |
| 37 | `broadcast_cross_swf_version` | 4 | 21.1s |  |
| 38 | `broadcast_type1_args` | 14 | 21.1s |  |
| 39 | `coerce_cross_swf_version` | 7 | 2.1s |  |
| 40 | `coerce_recursion_guard` | 1 | 21.1s |  |
| 41 | `coerce_type1_args` | 9 | 2.0s |  |
| 42 | `convertfloat_type1_this` | 3 | 2.0s |  |
| 43 | `ei_closure_scope_order` | 7 | 14.8s |  |
| 44 | `ei_cross_swf_version` | 2 | 1.6s |  |
| 45 | `ei_type1_args` | 7 | 1.5s |  |
| 46 | `enterframe_type1_args` | 8 | 21.1s |  |
| 47 | `fn_call_builtin_type1_args` | 10 | 20.7s |  |
| 48 | `fn_call_type1_args` | 7 | 1.8s |  |
| 49 | `fn_empty_method_type1_args` | 10 | 21.3s |  |
| 50 | `lc_method_type1_args` | 7 | 2.1s |  |
| 51 | `lc_onstatus_type1_args` | 3 | 2.0s |  |
| 52 | `lv_cross_swf_version` | 5 | 17.1s |  |
| 53 | `lv_ondata_type1_args` | 3 | 17.2s |  |
| 54 | `mask_nested_intersect` | 1 | 17.5s |  |
| 55 | `mask_sibling_union` | 1 | 21.2s |  |
| 56 | `mc_event_cross_swf_version` | 4 | 20.9s |  |
| 57 | `mc_event_type1_args` | 3 | 20.8s |  |
| 58 | `mc_method_v5_caller_gate` | 4 | 21.5s |  |
| 59 | `mc_resolve_type1_args` | 6 | 21.3s |  |
| 60 | `method_type1_args` | 10 | 2.0s |  |
| 61 | `nc_onstatus_closure` | 2 | 21.3s |  |
| 62 | `nc_onstatus_type1_args` | 3 | 21.2s |  |
| 63 | `onconstruct_cross_swf_version` | 4 | 21.4s |  |
| 64 | `onconstruct_type1_args` | 6 | 21.2s |  |
| 65 | `onload_type1_args` | 7 | 21.2s |  |
| 66 | `onunload_type1_args` | 6 | 21.5s |  |
| 67 | `onunload_type1_local_frame` | 2 | 2.0s |  |
| 68 | `resolve_type1_args` | 13 | 21.8s |  |
| 69 | `root_enterframe_cross_swf_version` | 3 | 21.8s |  |
| 70 | `sort_comparator_captured_scope` | 2 | 17.4s |  |
| 71 | `sort_comparator_type1_args` | 5 | 17.4s |  |
| 72 | `string_prim_method_type1_args` | 19 | 21.0s |  |
| 73 | `timer_cross_swf_version` | 3 | 21.2s |  |
| 74 | `timer_type1_args` | 14 | 17.1s |  |
| 75 | `watch_cross_swf_version` | 6 | 17.3s |  |
| 76 | `watch_mc_reentrant_setmember` | 3 | 22.2s |  |
| 77 | `watch_mc_type1_args` | 7 | 1.9s |  |
| 78 | `watch_setmember_type1_args` | 7 | 21.3s |  |
| 79 | `watch_timeline_named_params` | 4 | 2.0s |  |
| 80 | `watch_timeline_reentrant` | 3 | 17.3s |  |
| 81 | `xml_onload_type1_args` | 3 | 17.3s |  |

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
