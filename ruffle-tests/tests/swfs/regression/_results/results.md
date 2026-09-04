# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 02:34 UTC

**Git SHA**: `1ccb87a956`

**Run Duration**: 16m 22s

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
| 1 | `array_element_type1_args` | 7 | 20.4s |  |
| 2 | `array_method_type1_args` | 7 | 1.2s |  |
| 3 | `avm1_child_timeline_advance` | 19 | 20.8s |  |
| 4 | `avm1_child_timeline_frame1_stop` | 7 | 17.0s |  |
| 5 | `avm1_child_timeline_holder_stop` | 20 | 1.1s |  |
| 6 | `avm1_parent_as3_child_payload` | 2 | 16.9s |  |
| 7 | `avm1_parent_child_bitmap` | 5 | 1.7s |  |
| 8 | `avm1_parent_child_modify_place` | 5 | 1.5s |  |
| 9 | `avm1_parent_child_sprite_meta` | 8 | 1.7s |  |
| 10 | `avm2_agi_shell` | 6 | 26.5s |  |
| 11 | `avm2_bitmapdata_draw_textfield` | 5 | 7.6s |  |
| 12 | `avm2_contextmenu_stub` | 4 | 7.1s |  |
| 13 | `avm2_embed_bytearray` | 2 | 25.0s |  |
| 14 | `avm2_external_interface_unavailable` | 8 | 25.0s |  |
| 15 | `avm2_findprop_this_resolution` | 13 | 6.6s |  |
| 16 | `avm2_gc_dynprop_tombstone_purge` | 8 | 5.7s |  |
| 17 | `avm2_gc_string_concat_reclaim` | 10 | 5.8s |  |
| 18 | `avm2_gc_string_survives_collect` | 9 | 1.8s |  |
| 19 | `avm2_goto_catchup_scale` | 4 | 6.9s |  |
| 20 | `avm2_graphics_runtime` | 7 | 25.7s |  |
| 21 | `avm2_loader_stub` | 5 | 6.9s |  |
| 22 | `avm2_localconnection_domain` | 4 | 7.3s |  |
| 23 | `avm2_morph` | 8 | 26.6s |  |
| 24 | `avm2_parent_child_symbol_stride` | 6 | 28.1s |  |
| 25 | `avm2_sharedobject_flushstatus` | 4 | 5.6s |  |
| 26 | `avm2_simplebutton_click` | 2 | 5.7s |  |
| 27 | `avm2_slot_default_template` | 34 | 5.7s |  |
| 28 | `avm2_static_and_store_slots` | 14 | 2.8s |  |
| 29 | `avm2_static_text` | 6 | 26.9s |  |
| 30 | `avm2_timeline_gradients` | 7 | 27.9s |  |
| 31 | `avm2_timeline_solid` | 6 | 27.4s |  |
| 32 | `avm2_timeline_stroke_gradient` | 9 | 8.2s |  |
| 33 | `avm2_timeline_text` | 4 | 7.6s |  |
| 34 | `avm2_tolerant_verify_quarantine` | 2 | 7.0s |  |
| 35 | `avm2_typed_value_ops` | 30 | 7.2s |  |
| 36 | `broadcast_cross_swf_version` | 4 | 1.4s |  |
| 37 | `broadcast_type1_args` | 14 | 20.8s |  |
| 38 | `coerce_cross_swf_version` | 7 | 1.4s |  |
| 39 | `coerce_recursion_guard` | 1 | 1.3s |  |
| 40 | `coerce_type1_args` | 9 | 20.1s |  |
| 41 | `convertfloat_type1_this` | 3 | 1.2s |  |
| 42 | `ei_closure_scope_order` | 7 | 1.3s |  |
| 43 | `ei_cross_swf_version` | 2 | 20.4s |  |
| 44 | `ei_type1_args` | 7 | 1.3s |  |
| 45 | `enterframe_type1_args` | 8 | 20.4s |  |
| 46 | `fn_call_builtin_type1_args` | 10 | 20.8s |  |
| 47 | `fn_call_type1_args` | 7 | 1.3s |  |
| 48 | `fn_empty_method_type1_args` | 10 | 1.3s |  |
| 49 | `lc_method_type1_args` | 7 | 20.1s |  |
| 50 | `lc_onstatus_type1_args` | 3 | 1.2s |  |
| 51 | `lv_cross_swf_version` | 5 | 20.1s |  |
| 52 | `lv_ondata_type1_args` | 3 | 18.0s |  |
| 53 | `mask_nested_intersect` | 1 | 18.1s |  |
| 54 | `mask_sibling_union` | 1 | 1.2s |  |
| 55 | `mc_event_cross_swf_version` | 4 | 1.4s |  |
| 56 | `mc_event_type1_args` | 3 | 20.6s |  |
| 57 | `mc_method_v5_caller_gate` | 4 | 1.4s |  |
| 58 | `mc_resolve_type1_args` | 6 | 15.1s |  |
| 59 | `method_type1_args` | 10 | 0.8s |  |
| 60 | `nc_onstatus_closure` | 2 | 15.0s |  |
| 61 | `nc_onstatus_type1_args` | 3 | 21.8s |  |
| 62 | `onconstruct_cross_swf_version` | 4 | 1.5s |  |
| 63 | `onconstruct_type1_args` | 6 | 20.2s |  |
| 64 | `onload_type1_args` | 7 | 20.2s |  |
| 65 | `onunload_type1_args` | 6 | 20.5s |  |
| 66 | `onunload_type1_local_frame` | 2 | 1.2s |  |
| 67 | `resolve_type1_args` | 13 | 16.7s |  |
| 68 | `root_enterframe_cross_swf_version` | 3 | 16.8s |  |
| 69 | `sort_comparator_captured_scope` | 2 | 21.2s |  |
| 70 | `sort_comparator_type1_args` | 5 | 20.2s |  |
| 71 | `string_prim_method_type1_args` | 19 | 18.6s |  |
| 72 | `timer_cross_swf_version` | 3 | 1.1s |  |
| 73 | `timer_type1_args` | 14 | 19.4s |  |
| 74 | `watch_cross_swf_version` | 6 | 19.4s |  |
| 75 | `watch_mc_reentrant_setmember` | 3 | 21.7s |  |
| 76 | `watch_mc_type1_args` | 7 | 1.3s |  |
| 77 | `watch_setmember_type1_args` | 7 | 20.4s |  |
| 78 | `watch_timeline_named_params` | 4 | 1.3s |  |
| 79 | `watch_timeline_reentrant` | 3 | 20.7s |  |
| 80 | `xml_onload_type1_args` | 3 | 20.7s |  |

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
