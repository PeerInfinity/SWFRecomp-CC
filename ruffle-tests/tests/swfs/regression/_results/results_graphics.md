# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 02:19 UTC

**Git SHA**: `1ccb87a956`

**Run Duration**: 21m 11s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 80 |
| Passing | **80** (100.0%) |
| Failing | 0 |
| Total expected lines | 555 |
| Matching lines | 555 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**80 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 17.1s |  |
| 2 | `array_method_type1_args` | 7 | 1.6s |  |
| 3 | `avm1_child_timeline_advance` | 19 | 17.2s |  |
| 4 | `avm1_child_timeline_frame1_stop` | 7 | 21.8s |  |
| 5 | `avm1_child_timeline_holder_stop` | 20 | 2.4s |  |
| 6 | `avm1_parent_as3_child_payload` | 2 | 22.0s |  |
| 7 | `avm1_parent_child_bitmap` | 5 | 2.4s |  |
| 8 | `avm1_parent_child_modify_place` | 5 | 2.2s |  |
| 9 | `avm1_parent_child_sprite_meta` | 8 | 2.4s |  |
| 10 | `avm2_agi_shell` | 6 | 19.1s |  |
| 11 | `avm2_bitmapdata_draw_textfield` | 5 | 7.2s |  |
| 12 | `avm2_contextmenu_stub` | 4 | 6.7s |  |
| 13 | `avm2_embed_bytearray` | 2 | 26.8s |  |
| 14 | `avm2_external_interface_unavailable` | 8 | 26.3s |  |
| 15 | `avm2_findprop_this_resolution` | 13 | 2.8s |  |
| 16 | `avm2_gc_dynprop_tombstone_purge` | 8 | 22.4s |  |
| 17 | `avm2_gc_string_concat_reclaim` | 10 | 6.7s |  |
| 18 | `avm2_gc_string_survives_collect` | 9 | 6.6s |  |
| 19 | `avm2_goto_catchup_scale` | 4 | 26.4s |  |
| 20 | `avm2_graphics_runtime` | 7 | 26.3s |  |
| 21 | `avm2_loader_stub` | 5 | 7.6s |  |
| 22 | `avm2_localconnection_domain` | 4 | 24.5s |  |
| 23 | `avm2_morph` | 8 | 24.7s |  |
| 24 | `avm2_parent_child_symbol_stride` | 6 | 25.6s |  |
| 25 | `avm2_sharedobject_flushstatus` | 4 | 27.7s |  |
| 26 | `avm2_simplebutton_click` | 2 | 8.2s |  |
| 27 | `avm2_slot_default_template` | 34 | 8.5s |  |
| 28 | `avm2_static_and_store_slots` | 14 | 28.1s |  |
| 29 | `avm2_static_text` | 6 | 23.0s |  |
| 30 | `avm2_timeline_gradients` | 7 | 29.6s |  |
| 31 | `avm2_timeline_solid` | 6 | 28.6s |  |
| 32 | `avm2_timeline_stroke_gradient` | 9 | 9.4s |  |
| 33 | `avm2_timeline_text` | 4 | 28.0s |  |
| 34 | `avm2_tolerant_verify_quarantine` | 2 | 28.0s |  |
| 35 | `avm2_typed_value_ops` | 30 | 8.8s |  |
| 36 | `broadcast_cross_swf_version` | 4 | 21.8s |  |
| 37 | `broadcast_type1_args` | 14 | 20.6s |  |
| 38 | `coerce_cross_swf_version` | 7 | 20.6s |  |
| 39 | `coerce_recursion_guard` | 1 | 1.9s |  |
| 40 | `coerce_type1_args` | 9 | 22.8s |  |
| 41 | `convertfloat_type1_this` | 3 | 2.2s |  |
| 42 | `ei_closure_scope_order` | 7 | 2.3s |  |
| 43 | `ei_cross_swf_version` | 2 | 19.8s |  |
| 44 | `ei_type1_args` | 7 | 0.9s |  |
| 45 | `enterframe_type1_args` | 8 | 19.6s |  |
| 46 | `fn_call_builtin_type1_args` | 10 | 20.0s |  |
| 47 | `fn_call_type1_args` | 7 | 0.9s |  |
| 48 | `fn_empty_method_type1_args` | 10 | 0.9s |  |
| 49 | `lc_method_type1_args` | 7 | 20.8s |  |
| 50 | `lc_onstatus_type1_args` | 3 | 1.9s |  |
| 51 | `lv_cross_swf_version` | 5 | 21.0s |  |
| 52 | `lv_ondata_type1_args` | 3 | 21.7s |  |
| 53 | `mask_nested_intersect` | 1 | 21.9s |  |
| 54 | `mask_sibling_union` | 1 | 2.2s |  |
| 55 | `mc_event_cross_swf_version` | 4 | 21.1s |  |
| 56 | `mc_event_type1_args` | 3 | 20.8s |  |
| 57 | `mc_method_v5_caller_gate` | 4 | 2.1s |  |
| 58 | `mc_resolve_type1_args` | 6 | 21.2s |  |
| 59 | `method_type1_args` | 10 | 2.0s |  |
| 60 | `nc_onstatus_closure` | 2 | 21.3s |  |
| 61 | `nc_onstatus_type1_args` | 3 | 20.7s |  |
| 62 | `onconstruct_cross_swf_version` | 4 | 20.9s |  |
| 63 | `onconstruct_type1_args` | 6 | 20.8s |  |
| 64 | `onload_type1_args` | 7 | 21.0s |  |
| 65 | `onunload_type1_args` | 6 | 21.3s |  |
| 66 | `onunload_type1_local_frame` | 2 | 2.0s |  |
| 67 | `resolve_type1_args` | 13 | 21.2s |  |
| 68 | `root_enterframe_cross_swf_version` | 3 | 21.5s |  |
| 69 | `sort_comparator_captured_scope` | 2 | 17.5s |  |
| 70 | `sort_comparator_type1_args` | 5 | 17.3s |  |
| 71 | `string_prim_method_type1_args` | 19 | 22.1s |  |
| 72 | `timer_cross_swf_version` | 3 | 22.0s |  |
| 73 | `timer_type1_args` | 14 | 21.2s |  |
| 74 | `watch_cross_swf_version` | 6 | 21.4s |  |
| 75 | `watch_mc_reentrant_setmember` | 3 | 20.2s |  |
| 76 | `watch_mc_type1_args` | 7 | 0.9s |  |
| 77 | `watch_setmember_type1_args` | 7 | 21.2s |  |
| 78 | `watch_timeline_named_params` | 4 | 2.0s |  |
| 79 | `watch_timeline_reentrant` | 3 | 21.0s |  |
| 80 | `xml_onload_type1_args` | 3 | 21.2s |  |

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
